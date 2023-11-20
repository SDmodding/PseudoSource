// File Line: 25
// RVA: 0x13095E0
_BOOL8 __fastcall hkcdTriangleUtil::isDegenerate(hkVector4f *a, hkVector4f *b, hkVector4f *c, hkSimdFloat32 *tolerance)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm6
  __m128 v6; // xmm0
  __m128 v7; // xmm5
  __m128 v8; // xmm1
  __m128 v9; // xmm5
  __m128 v10; // xmm0
  __m128 v11; // xmm5
  __m128 v12; // xmm5
  __m128 v13; // xmm4
  __m128 v14; // xmm4
  __m128 v15; // xmm4
  __m128 v16; // ST10_16
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm6_4
  __m128 v20; // ST00_16
  float v21; // xmm2_4
  _BOOL8 result; // rax

  v4 = _mm_sub_ps(a->m_quad, c->m_quad);
  v5 = _mm_sub_ps(a->m_quad, b->m_quad);
  v6 = _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v4);
  v7 = _mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v5);
  v8 = _mm_sub_ps(b->m_quad, a->m_quad);
  v9 = _mm_sub_ps(v7, v6);
  v10 = _mm_sub_ps(b->m_quad, c->m_quad);
  v11 = _mm_shuffle_ps(v9, v9, 201);
  v12 = _mm_mul_ps(v11, v11);
  v13 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v10));
  v14 = _mm_shuffle_ps(v13, v13, 201);
  v15 = _mm_mul_ps(v14, v14);
  result = 1;
  if ( _mm_movemask_ps(
         _mm_or_ps(
           _mm_cmpltps(
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
               _mm_shuffle_ps(v15, v15, 170)),
             tolerance->m_real),
           _mm_cmpltps(
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
               _mm_shuffle_ps(v12, v12, 170)),
             tolerance->m_real))) != 15 )
  {
    v16 = v5;
    v17 = v5.m128_f32[0] * v5.m128_f32[0];
    LODWORD(v18) = (unsigned __int128)_mm_shuffle_ps(v5, v5, 85);
    LODWORD(v19) = (unsigned __int128)_mm_shuffle_ps(v5, v5, 170);
    v20 = _mm_sub_ps(c->m_quad, b->m_quad);
    v21 = (float)((float)(v20.m128_f32[1] * v16.m128_f32[1]) + (float)(v20.m128_f32[0] * v16.m128_f32[0]))
        + (float)(v20.m128_f32[2] * v16.m128_f32[2]);
    if ( (float)((float)((float)((float)((float)(v20.m128_f32[1] * v20.m128_f32[1])
                                       + (float)(v20.m128_f32[0] * v20.m128_f32[0]))
                               + (float)(v20.m128_f32[2] * v20.m128_f32[2]))
                       * (float)((float)((float)(v18 * v18) + v17) + (float)(v19 * v19)))
               - (float)(v21 * v21)) != 0.0 )
      result = 0;
  }
  return result;
}

// File Line: 29
// RVA: 0x130A1C0
float __fastcall hkcdTriangleUtil::isDegenerate_::_2_::LocalUtilities::dot3fpu(hkVector4f *aa, hkVector4f *bb)
{
  return (float)((float)(aa->m_quad.m128_f32[1] * bb->m_quad.m128_f32[1])
               + (float)(aa->m_quad.m128_f32[0] * bb->m_quad.m128_f32[0]))
       + (float)(aa->m_quad.m128_f32[2] * bb->m_quad.m128_f32[2]);
}

// File Line: 79
// RVA: 0x13097E0
void __fastcall hkcdTriangleUtil::calcBarycentricCoordinates(hkVector4f *vP, hkVector4f *vA, hkVector4f *vB, hkVector4f *vC, hkVector4f *result)
{
  __m128 v5; // xmm10
  __m128 v6; // xmm11
  __m128 v7; // xmm12
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm7
  __m128 v11; // xmm5
  __m128 v12; // xmm6
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm5
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  __m128 v18; // xmm5
  __m128 v19; // xmm9
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm9
  __m128 v23; // xmm6
  __m128 v24; // xmm2
  __m128 v25; // xmm9
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm0
  __m128 v30; // xmm5
  __m128 v31; // xmm7
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  __m128 v34; // xmm8
  __m128 v35; // xmm2
  __m128 v36; // xmm4
  __m128 v37; // xmm3
  __m128 v38; // xmm2
  __m128 v39; // xmm1
  __m128 v40; // xmm5
  __m128 v41; // xmm2
  __m128 v42; // xmm7
  __m128 v43; // xmm4
  int v44; // eax
  signed int v45; // ecx
  __m128 v46; // xmm7
  __m128 v47; // xmm0
  __m128 v48; // xmm1
  __m128 v49; // xmm3
  __m128 v50; // xmm0
  __m128 v51; // xmm3
  __m128i v52; // xmm2
  __m128 v53; // xmm1
  __m128 v54; // xmm1
  __int128 v55; // [rsp+0h] [rbp-A8h]
  __int128 v56; // [rsp+10h] [rbp-98h]
  __int128 v57; // [rsp+20h] [rbp-88h]

  v5 = vC->m_quad;
  v6 = vA->m_quad;
  v7 = vB->m_quad;
  v8 = _mm_sub_ps(vC->m_quad, vA->m_quad);
  v9 = _mm_sub_ps(vA->m_quad, vP->m_quad);
  v10 = _mm_sub_ps(vB->m_quad, vA->m_quad);
  v11 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v10);
  v12 = _mm_sub_ps(vB->m_quad, vP->m_quad);
  v13 = _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v8);
  v14 = _mm_sub_ps(vC->m_quad, vP->m_quad);
  v15 = _mm_sub_ps(v11, v13);
  v16 = _mm_shuffle_ps(v15, v15, 201);
  v17 = _mm_shuffle_ps(v16, v16, 210);
  v18 = v16;
  v19 = _mm_mul_ps(
          _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v17), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 210), v18)),
          v12);
  v20 = _mm_mul_ps(
          _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v17), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 210), v18)),
          v14);
  v21 = _mm_unpacklo_ps(v19, v20);
  v22 = _mm_unpackhi_ps(v19, v20);
  v23 = _mm_mul_ps(
          _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v17), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 210), v18)),
          v9);
  v24 = _mm_movelh_ps(v21, v23);
  v25 = _mm_add_ps(_mm_shuffle_ps(v22, v23, 228), _mm_add_ps(v24, _mm_shuffle_ps(_mm_movehl_ps(v24, v21), v23, 212)));
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)), _mm_shuffle_ps(v25, v25, 170));
  if ( v26.m128_f32[0] == 0.0 )
  {
    v28 = _mm_sub_ps(v5, v7);
    v29 = _mm_mul_ps(_mm_sub_ps(vP->m_quad, v7), v28);
    v30 = _mm_mul_ps(_mm_sub_ps(vP->m_quad, v6), v10);
    v31 = _mm_mul_ps(v10, v10);
    v32 = _mm_sub_ps(v6, v5);
    v33 = _mm_unpacklo_ps(v30, v29);
    v34 = _mm_mul_ps(_mm_sub_ps(vP->m_quad, v5), v32);
    v35 = _mm_movelh_ps(v33, v34);
    v36 = _mm_mul_ps(v32, v32);
    v37 = _mm_mul_ps(v28, v28);
    v38 = _mm_add_ps(v35, _mm_shuffle_ps(_mm_movehl_ps(v35, v33), v34, 212));
    v39 = _mm_unpacklo_ps(v31, v37);
    v40 = _mm_add_ps(_mm_shuffle_ps(_mm_unpackhi_ps(v30, v29), v34, 228), v38);
    v41 = _mm_movelh_ps(v39, v36);
    v42 = _mm_add_ps(
            _mm_shuffle_ps(_mm_unpackhi_ps(v31, v37), v36, 228),
            _mm_add_ps(v41, _mm_shuffle_ps(_mm_movehl_ps(v41, v39), v36, 212)));
    v43 = _mm_max_ps(
            _mm_shuffle_ps(v42, v42, 170),
            _mm_max_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)));
    v44 = _mm_movemask_ps(_mm_cmpeqps(v42, v43));
    if ( v44 & 7 )
      v45 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v44];
    else
      v45 = -1;
    v46 = _mm_max_ps(v42, *(__m128 *)&epsilon);
    v47 = _mm_rcp_ps(v46);
    v48 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v46, v47)), v47), v40);
    v49 = _mm_sub_ps(query.m_quad, v48);
    v50 = _mm_unpacklo_ps(v49, v48);
    v51 = _mm_shuffle_ps(_mm_unpackhi_ps(v49, v48), (__m128)0i64, 228);
    v52 = (__m128i)_mm_movelh_ps(v50, (__m128)0i64);
    _mm_store_si128((__m128i *)&v55, v52);
    v53 = _mm_shuffle_ps(_mm_movehl_ps((__m128)v52, v50), (__m128)0i64, 212);
    _mm_store_si128((__m128i *)&v57, (__m128i)_mm_shuffle_ps(v51, v51, 137));
    _mm_store_si128((__m128i *)&v56, (__m128i)_mm_shuffle_ps(v53, v53, 146));
    v54 = _mm_cmpltps((__m128)0i64, v43);
    result->m_quad = _mm_or_ps(_mm_and_ps((__m128)*(&v55 + v45), v54), _mm_andnot_ps(v54, (__m128)0i64));
  }
  else
  {
    v27 = _mm_rcp_ps(v26);
    result->m_quad = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v27, v26)), v27), v25);
  }
}

// File Line: 163
// RVA: 0x1309AB0
void __fastcall hkcdTriangleUtil::calcBarycentricCoordinatesDeprecated(hkVector4f *pos, hkVector4f *t0, hkVector4f *t1, hkVector4f *t2, hkVector4f *result)
{
  __m128 v5; // xmm4
  __m128 v6; // xmm8
  __m128 v7; // xmm10
  __m128 v8; // xmm1
  __m128 v9; // xmm5
  float v10; // xmm7_4
  __m128 v11; // xmm1
  float v12; // xmm6_4
  __m128 v13; // xmm1
  float v14; // xmm12_4
  float v15; // xmm9_4
  __m128 v16; // xmm8
  __m128 v17; // xmm1
  __m128 v18; // xmm5
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  float v24; // xmm3_4
  __m128 v25; // xmm1
  __m128 v26; // xmm1
  float v27; // xmm2_4
  __m128 v28; // xmm1
  __m128 v29; // xmm1
  float v30; // xmm2_4
  __m128 v31; // xmm1
  __m128 v32; // xmm1
  float v33; // xmm2_4

  v5 = t2->m_quad;
  v6 = t1->m_quad;
  v7 = _mm_sub_ps(t0->m_quad, t1->m_quad);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_sub_ps(t2->m_quad, t1->m_quad);
  v10 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 170));
  v11 = _mm_mul_ps(v9, v9);
  v12 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_mul_ps(v9, v7);
  v14 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170));
  v15 = (float)(v12 * v10) - (float)(v14 * v14);
  if ( v15 > 0.0 )
  {
    v16 = _mm_sub_ps(v6, pos->m_quad);
    v17 = _mm_mul_ps(v16, v7);
    v18 = _mm_mul_ps(v9, v16);
    v19 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 170));
    v20 = v19 * v12;
    v17.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 0)))
                    + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 170));
    v21 = (float)(v19 * v14) - (float)(v17.m128_f32[0] * v10);
    v17.m128_f32[0] = (float)(v17.m128_f32[0] * v14) - v20;
    result->m_quad.m128_f32[0] = v17.m128_f32[0] * (float)(1.0 / v15);
    result->m_quad.m128_f32[2] = v21 * (float)(1.0 / v15);
    result->m_quad.m128_f32[1] = (float)((float)(v15 - v17.m128_f32[0]) - v21) * (float)(1.0 / v15);
    return;
  }
  v22 = _mm_sub_ps(t0->m_quad, v5);
  v23 = _mm_mul_ps(v22, v22);
  v24 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 170));
  if ( v10 < v12 )
  {
    v31 = pos->m_quad;
    if ( v24 >= v12 )
    {
      v25 = _mm_sub_ps(v31, v5);
      result->m_quad.m128_i32[1] = 0;
      goto LABEL_7;
    }
    v32 = _mm_mul_ps(_mm_sub_ps(v31, v6), v9);
    v33 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 0)) + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 85)))
                + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 170)))
        / v12;
    result->m_quad.m128_f32[2] = v33;
    result->m_quad.m128_f32[1] = 1.0 - v33;
  }
  else
  {
    if ( v24 < v10 )
    {
      v28 = pos->m_quad;
      result->m_quad.m128_i32[2] = 0;
      v29 = _mm_mul_ps(_mm_sub_ps(v28, v6), v7);
      v30 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)))
                  + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 170)))
          / v10;
      result->m_quad.m128_f32[0] = v30;
      result->m_quad.m128_f32[1] = 1.0 - v30;
      return;
    }
    result->m_quad.m128_i32[1] = 0;
    if ( v24 > 0.0 )
    {
      v25 = _mm_sub_ps(pos->m_quad, t2->m_quad);
LABEL_7:
      v26 = _mm_mul_ps(v25, v22);
      v27 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 0)))
                  + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 170)))
          / v24;
      result->m_quad.m128_f32[0] = v27;
      result->m_quad.m128_f32[2] = 1.0 - v27;
      return;
    }
    result->m_quad.m128_i32[2] = 0;
  }
  result->m_quad.m128_i32[0] = 0;
} 1

// File Line: 307
// RVA: 0x1309D80
signed __int64 __fastcall hkcdTriangleUtil::clipWithPlane(hkVector4f *a, hkVector4f *b, hkVector4f *c, hkVector4f *plane, hkSimdFloat32 *tolerance, hkVector4f *edgesOut)
{
  __m128 v6; // xmm5
  hkVector4f *v7; // rbx
  hkVector4f *v8; // r10
  __m128 v9; // xmm6
  __m128 v10; // xmm1
  __m128 v11; // xmm7
  __m128 v12; // xmm1
  __m128 v13; // xmm4
  __m128 v14; // xmm1
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128i v21; // xmm2
  __m128 v22; // xmm3
  char v23; // r8
  int v24; // ecx
  int v25; // eax
  signed __int64 result; // rax
  __m128 v27; // xmm2
  __int64 v28; // rcx
  __int64 v29; // rax
  __m128 v30; // xmm0
  __m128 v31; // xmm4
  __m128 v32; // xmm1
  __m128 v33; // xmm0
  __m128 v34; // xmm3
  __m128 v35; // [rsp+0h] [rbp-88h]
  __m128 v36; // [rsp+10h] [rbp-78h]
  __m128 v37; // [rsp+20h] [rbp-68h]
  __m128 v38; // [rsp+30h] [rbp-58h]
  __m128 v39; // [rsp+40h] [rbp-48h]
  __m128 v40; // [rsp+50h] [rbp-38h]

  v6 = a->m_quad;
  v7 = a;
  v8 = c;
  v9 = c->m_quad;
  v10 = _mm_mul_ps(plane->m_quad, a->m_quad);
  v11 = b->m_quad;
  v12 = _mm_shuffle_ps(v10, _mm_unpackhi_ps(v10, plane->m_quad), 196);
  v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
  v14 = _mm_mul_ps(b->m_quad, plane->m_quad);
  v15 = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, plane->m_quad), 196);
  v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
  v17 = _mm_mul_ps(c->m_quad, plane->m_quad);
  v18 = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, plane->m_quad), 196);
  v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
  v21 = (__m128i)_mm_movelh_ps(
                   _mm_unpacklo_ps(
                     _mm_add_ps(_mm_shuffle_ps(v13, v13, 177), v13),
                     _mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16)),
                   _mm_unpacklo_ps(v20, v20));
  v22 = _mm_andnot_ps(_mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32(v21, 1u), 1u), tolerance->m_real), (__m128)v21);
  v23 = _mm_movemask_ps(_mm_cmpltps((__m128)0i64, v22));
  v24 = _mm_movemask_ps(_mm_cmpltps(v22, (__m128)0i64));
  v25 = ((v23 & 4 | (v24 >> 1) & 2) >> 1) + 3 * ((v23 & 2 | (v24 >> 1) & 1) + 3 * (v24 & 1 | 2 * (v23 & 1)));
  if ( v25 )
  {
    if ( v25 == 13 || v25 == 26 )
    {
      result = 0i64;
    }
    else
    {
      v37 = v9;
      v27 = _mm_unpacklo_ps(v22, v22);
      v35 = v6;
      v36 = v11;
      v28 = s_planeIntersectEdgeTable[v25] & 0xF;
      v29 = s_planeIntersectEdgeTable[v25] & 0xF0;
      v30 = _mm_sub_ps(v27, _mm_shuffle_ps(v22, v22, 166));
      v31 = _mm_cmpeqps((__m128)0i64, v30);
      v32 = _mm_or_ps(_mm_andnot_ps(v31, v30), _mm_and_ps(v31, *(__m128 *)&epsilon));
      v33 = _mm_rcp_ps(v32);
      v34 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v32, v33)), v33), v27);
      v38 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), _mm_sub_ps(v11, v6)), v6);
      v39 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), _mm_sub_ps(v9, v6)), v6);
      v40 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), _mm_sub_ps(v9, v11)), v11);
      *edgesOut = *(hkVector4f *)((char *)&v35 + v29);
      edgesOut[1] = *((hkVector4f *)&v35 + v28);
      result = 1i64;
    }
  }
  else
  {
    *edgesOut = (hkVector4f)v6;
    edgesOut[1] = (hkVector4f)b->m_quad;
    edgesOut[2] = (hkVector4f)b->m_quad;
    edgesOut[3] = (hkVector4f)v8->m_quad;
    edgesOut[4] = (hkVector4f)v8->m_quad;
    edgesOut[5] = (hkVector4f)v7->m_quad;
    result = 3i64;
  }
  return result;
}

// File Line: 396
// RVA: 0x1309FE0
signed __int64 __fastcall hkcdTriangleUtil::checkForFlatConvexQuad(hkVector4f *a, hkVector4f *b, hkVector4f *c, hkVector4f *d, float tolerance)
{
  float v5; // xmm8_4
  __m128 v6; // xmm4
  __m128 v7; // xmm6
  __m128 v8; // xmm7
  __m128 v9; // xmm4
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm5
  __m128 v15; // xmm2
  signed __int64 result; // rax
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm4
  __m128 v22; // xmm3
  __m128 v23; // xmm4
  __m128 v24; // xmm2
  __m128 v25; // xmm3
  __m128 v26; // xmm3
  __m128 v27; // xmm0
  __m128 v28; // xmm2
  __m128 v29; // xmm4
  __m128 v30; // xmm3

  LODWORD(v5) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0);
  v6 = _mm_sub_ps(c->m_quad, a->m_quad);
  v7 = _mm_sub_ps(b->m_quad, a->m_quad);
  v8 = _mm_sub_ps(a->m_quad, d->m_quad);
  v9 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v7), _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v6));
  v10 = _mm_shuffle_ps(v9, v9, 201);
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  v14 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v12, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
              _mm_mul_ps(*(__m128 *)_xmm, v13))),
          v10);
  v15 = _mm_mul_ps(v8, v14);
  if ( COERCE_FLOAT((unsigned int)(2
                                 * COERCE_SIGNED_INT(
                                     (float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 170)))) >> 1) > v5 )
    return 0i64;
  result = 0i64;
  v17 = _mm_shuffle_ps(v14, v14, 201);
  v18 = _mm_sub_ps(c->m_quad, b->m_quad);
  v19 = v17;
  v20 = _mm_mul_ps(v17, v18);
  v21 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v14), _mm_mul_ps(v19, v7));
  v22 = _mm_shuffle_ps(v18, v18, 201);
  v23 = _mm_shuffle_ps(v21, v21, 201);
  v24 = _mm_mul_ps(v23, v23);
  v25 = _mm_sub_ps(_mm_mul_ps(v22, v14), v20);
  v26 = _mm_shuffle_ps(v25, v25, 201);
  v27 = _mm_rsqrt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
            _mm_shuffle_ps(v24, v24, 170)));
  v28 = _mm_mul_ps(v26, v26);
  v29 = _mm_mul_ps(_mm_mul_ps(v23, v27), v8);
  v30 = _mm_mul_ps(
          _mm_mul_ps(
            v26,
            _mm_rsqrt_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                _mm_shuffle_ps(v28, v28, 170)))),
          _mm_sub_ps(c->m_quad, d->m_quad));
  if ( fmax(
         (float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)))
       + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 170)),
         (float)(COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 0)))
       + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 170))) < v5 )
    result = 1i64;
  return result;
}


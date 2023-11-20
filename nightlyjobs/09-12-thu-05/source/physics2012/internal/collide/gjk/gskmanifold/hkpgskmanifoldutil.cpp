// File Line: 96
// RVA: 0xDBCB60
signed __int64 __fastcall hkGskManifold_convertPointPoint(hkpGskManifoldWork *work, hkpGskManifold::ContactPoint *feature, hkGskManifoldConvertOut *out)
{
  __int64 v3; // r9
  hkVector4f v4; // xmm3
  __m128 v5; // xmm1
  signed __int64 result; // rax

  v3 = (unsigned __int8)feature->m_vert[0];
  v4.m_quad = _mm_sub_ps(
                *(__m128 *)((char *)&work->m_vertices[0].m_quad + v3),
                *(__m128 *)((char *)&work->m_vertices[0].m_quad + (unsigned __int8)feature->m_vert[1]));
  v5 = _mm_mul_ps(v4.m_quad, v4.m_quad);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 170))) > COERCE_FLOAT(
                                                              _mm_shuffle_ps(
                                                                (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                0)) )
    return 10i64;
  out->m_AminusB = (hkVector4f)v4.m_quad;
  result = 5i64;
  out->m_normal = work->m_masterNormal;
  out->m_pointOnA = *(hkVector4f *)((char *)work->m_vertices + v3);
  return result;
}

// File Line: 118
// RVA: 0xDBCBD0
signed __int64 __fastcall hkGskManifold_convertPointEdge(hkpGskManifoldWork *work, hkpGskManifold::ContactPoint *feature, hkGskManifoldConvertOut *out)
{
  __int64 v3; // r10
  __int64 v4; // r9
  __int64 v5; // rax
  __m128 v6; // xmm4
  __m128 v7; // xmm6
  __m128 v8; // xmm5
  __m128 v9; // xmm4
  __m128 v10; // xmm5
  __m128 v11; // xmm3
  __m128 v12; // xmm0
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm3
  __m128 v16; // xmm3
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm4
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  signed __int64 result; // rax
  __m128 v25; // xmm3
  __m128 v26; // xmm4
  __m128 v27; // xmm1

  v3 = (unsigned __int8)feature->m_vert[0];
  v4 = (unsigned __int8)feature->m_vert[1];
  v5 = (unsigned __int8)feature->m_vert[2];
  out->m_pointOnA = *(hkVector4f *)((char *)work->m_vertices + v3);
  out->m_normal = work->m_masterNormal;
  v6 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v5);
  v7 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v3);
  v8 = v6;
  v9 = _mm_sub_ps(v6, v7);
  v10 = _mm_sub_ps(v8, *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4));
  v11 = _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v10);
  v12 = _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v9);
  v13 = _mm_mul_ps(v9, v10);
  v14 = _mm_sub_ps(v11, v12);
  v15 = _mm_shuffle_ps(v14, v14, 201);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_mul_ps(
          _mm_sub_ps(
            *(__m128 *)((char *)&work->m_vertices[0].m_quad + v3),
            *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4)),
          v10);
  v18 = _mm_unpacklo_ps(v13, v17);
  v19 = _mm_movelh_ps(v18, v16);
  v20 = _mm_shuffle_ps(_mm_unpackhi_ps(v13, v17), v16, 228);
  v21 = _mm_shuffle_ps(_mm_movehl_ps(v19, v18), v16, 212);
  v22 = _mm_mul_ps(v10, v10);
  v23 = _mm_add_ps(v20, _mm_add_ps(v19, v21));
  if ( COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 170)) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 85))
                                                                           + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 0)))
                                                                   + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 170)))
                                                           * COERCE_FLOAT(
                                                               _mm_shuffle_ps(
                                                                 (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                 (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                 0))) )
    return 10i64;
  if ( _mm_movemask_ps(_mm_cmpltps(v23, (__m128)0i64)) & 3 )
    return 6i64;
  result = 5i64;
  v25 = _mm_shuffle_ps(v23, v23, 0);
  v26 = _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), v25);
  v27 = _mm_rcp_ps(v26);
  out->m_AminusB.m_quad = _mm_sub_ps(
                            v7,
                            _mm_add_ps(
                              _mm_mul_ps(
                                v10,
                                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v27, v26)), v27), v25)),
                              *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4)));
  return result;
}

// File Line: 154
// RVA: 0xDBCD10
signed __int64 __fastcall hkGskManifold_convertEdgePoint(hkpGskManifoldWork *work, hkpGskManifold::ContactPoint *feature, hkGskManifoldConvertOut *out)
{
  __int64 v3; // rax
  __int64 v4; // r9
  __int64 v5; // r10
  __m128 v6; // xmm7
  __m128 v7; // xmm6
  __m128 v8; // xmm2
  __m128 v9; // xmm4
  __m128 v10; // xmm5
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm3
  __m128 v20; // xmm5
  __m128 v21; // xmm2
  __m128 v22; // xmm5
  signed __int64 result; // rax
  __m128 v24; // xmm3
  __m128 v25; // xmm5
  __m128 v26; // xmm1
  hkVector4f v27; // xmm6

  v3 = (unsigned __int8)feature->m_vert[1];
  v4 = (unsigned __int8)feature->m_vert[0];
  v5 = (unsigned __int8)feature->m_vert[2];
  out->m_normal = work->m_masterNormal;
  v6 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v3);
  v7 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4);
  v8 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v5);
  v9 = _mm_sub_ps(v6, v7);
  v10 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v3), v8);
  v11 = _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v10);
  v12 = _mm_mul_ps(_mm_sub_ps(v8, v7), v9);
  v13 = _mm_shuffle_ps(v10, v10, 201);
  v14 = _mm_mul_ps(v10, v9);
  v15 = _mm_unpacklo_ps(v14, v12);
  v16 = _mm_sub_ps(_mm_mul_ps(v13, v9), v11);
  v17 = _mm_mul_ps(v9, v9);
  v18 = _mm_shuffle_ps(v16, v16, 201);
  v19 = _mm_mul_ps(v18, v18);
  v20 = _mm_shuffle_ps(_mm_unpackhi_ps(v14, v12), v19, 228);
  v21 = _mm_movelh_ps(v15, v19);
  v22 = _mm_add_ps(v20, _mm_add_ps(v21, _mm_shuffle_ps(_mm_movehl_ps(v21, v15), v19, 212)));
  if ( COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 170)) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 85))
                                                                           + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 0)))
                                                                   + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 170)))
                                                           * COERCE_FLOAT(
                                                               _mm_shuffle_ps(
                                                                 (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                 (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                 0))) )
    return 10i64;
  if ( _mm_movemask_ps(_mm_cmpltps(v22, (__m128)0i64)) & 3 )
    return 6i64;
  result = 5i64;
  v24 = _mm_shuffle_ps(v22, v22, 0);
  v25 = _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), v24);
  v26 = _mm_rcp_ps(v25);
  v27.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(v7, v6),
                   _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v26, v25)), v26), v24)),
                 v6);
  out->m_pointOnA = (hkVector4f)v27.m_quad;
  out->m_AminusB.m_quad = _mm_sub_ps(v27.m_quad, *(__m128 *)((char *)&work->m_vertices[0].m_quad + v5));
  return result;
}

// File Line: 197
// RVA: 0xDBCE60
__int64 __fastcall hkGskManifold_convertPointFace(hkpGskManifoldWork *work, hkpGskManifold::ContactPoint *feature, hkGskManifoldConvertOut *out)
{
  __int64 v3; // r11
  __int64 v4; // r10
  __int64 v5; // r9
  __int64 v6; // rax
  __m128 v7; // xmm6
  __m128 v8; // xmm5
  __m128 v9; // xmm4
  __m128 v10; // xmm3
  __m128 v11; // xmm7
  __m128 v12; // xmm8
  __m128 v13; // xmm13
  __m128 v14; // xmm15
  __m128 v15; // xmm11
  __m128 v16; // xmm14
  __m128 v17; // xmm14
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm10
  __m128 v22; // xmm0
  __m128 v23; // xmm2
  __m128 v24; // xmm9
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm9
  __m128 v29; // xmm1
  __m128 v30; // xmm15
  __m128 v31; // xmm11
  __m128 v32; // xmm13
  __m128 v33; // xmm0
  __m128 v34; // xmm15
  __m128 v35; // xmm13
  __m128 v36; // xmm1
  __m128 v37; // xmm11
  __m128 v38; // xmm2
  __m128 v39; // xmm15
  __int64 result; // rax

  v3 = (unsigned __int8)feature->m_vert[0];
  v4 = (unsigned __int8)feature->m_vert[1];
  v5 = (unsigned __int8)feature->m_vert[2];
  v6 = (unsigned __int8)feature->m_vert[3];
  out->m_pointOnA = *(hkVector4f *)((char *)work->m_vertices + v3);
  out->m_AminusB.m_quad = _mm_sub_ps(
                            *(__m128 *)((char *)&work->m_vertices[0].m_quad + v3),
                            *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4));
  v7 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v6);
  v8 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4);
  v9 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v5);
  v10 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v3);
  v11 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v6), v9);
  v12 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v4), v7);
  v13 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v5), v8);
  v14 = _mm_shuffle_ps(v11, v11, 201);
  v15 = _mm_shuffle_ps(v12, v12, 201);
  v16 = _mm_sub_ps(_mm_mul_ps(v15, v11), _mm_mul_ps(v14, v12));
  v17 = _mm_shuffle_ps(v16, v16, 201);
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v20 = _mm_rsqrt_ps(v19);
  v21 = _mm_cmpleps(v19, (__m128)0i64);
  v22 = _mm_mul_ps(_mm_mul_ps(v20, v19), v20);
  v23 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v3), v7);
  v24 = _mm_sub_ps((__m128)_xmm, v22);
  v25 = _mm_mul_ps(*(__m128 *)_xmm, v20);
  v26 = v10;
  v27 = _mm_sub_ps(v10, v8);
  v28 = _mm_mul_ps(v24, v25);
  v29 = _mm_sub_ps(v26, v9);
  v30 = _mm_sub_ps(_mm_mul_ps(v14, v29), _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v11));
  v31 = _mm_sub_ps(_mm_mul_ps(v15, v23), _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v12));
  v32 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v27), _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v13));
  v33 = _mm_mul_ps(work->m_masterNormal.m_quad, v17);
  v34 = _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v17);
  v35 = _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v17);
  v36 = _mm_shuffle_ps(v35, v33, 68);
  v37 = _mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v17);
  v38 = _mm_shuffle_ps(v34, v37, 68);
  v39 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v34, v37, 238), _mm_shuffle_ps(v35, v33, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v38, v36, 221), _mm_shuffle_ps(v38, v36, 136)));
  result = (unsigned int)((~(unsigned __int8)_mm_movemask_ps(_mm_cmpltps(v39, (__m128)0i64)) & 7) != 0) + 17;
  out->m_normal.m_quad = _mm_xor_ps(
                           (__m128)_mm_slli_epi32(
                                     _mm_srli_epi32(
                                       (__m128i)_mm_cmpltps(_mm_shuffle_ps(v39, v39, 255), (__m128)0i64),
                                       0x1Fu),
                                     0x1Fu),
                           _mm_mul_ps(_mm_andnot_ps(v21, v28), v17));
  return result;
}

// File Line: 239
// RVA: 0xDBD0A0
__int64 __fastcall hkGskManifold_convertFacePoint(hkpGskManifoldWork *work, hkpGskManifold::ContactPoint *feature, hkGskManifoldConvertOut *out)
{
  __int64 v3; // r11
  __int64 v4; // r10
  __int64 v5; // r9
  __int64 v6; // rax
  hkVector4f v7; // xmm15
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  __m128 v10; // xmm7
  __m128 v11; // xmm13
  __m128 v12; // xmm9
  __m128 v13; // xmm8
  __m128 v14; // xmm12
  __m128 v15; // xmm0
  __m128 v16; // xmm10
  __m128 v17; // xmm10
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm11
  __m128 v22; // xmm4
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm3
  __m128 v26; // xmm5
  __m128 v27; // xmm12
  __m128 v28; // xmm15
  __m128 v29; // xmm5
  __m128 v30; // xmm13
  __m128 v31; // xmm0
  __m128 v32; // xmm12
  __m128 v33; // xmm2
  __m128 v34; // xmm13
  __m128 v35; // xmm1
  __m128 v36; // xmm5
  __int64 result; // rax

  v3 = (unsigned __int8)feature->m_vert[3];
  v4 = (unsigned __int8)feature->m_vert[0];
  v5 = (unsigned __int8)feature->m_vert[1];
  v6 = (unsigned __int8)feature->m_vert[2];
  out->m_pointOnA = *(hkVector4f *)((char *)work->m_vertices + v3);
  v7.m_quad = _mm_sub_ps(
                *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4),
                *(__m128 *)((char *)&work->m_vertices[0].m_quad + v3));
  out->m_AminusB = (hkVector4f)v7.m_quad;
  v8 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v5);
  v9 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4);
  v10 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v6);
  v11 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v5), v9);
  v12 = _mm_sub_ps(v9, v10);
  v13 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v6), v8);
  v14 = _mm_shuffle_ps(v12, v12, 201);
  v15 = _mm_shuffle_ps(v13, v13, 201);
  v16 = _mm_sub_ps(_mm_mul_ps(v14, v13), _mm_mul_ps(v15, v12));
  v17 = _mm_shuffle_ps(v16, v16, 201);
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v20 = _mm_rsqrt_ps(v19);
  v21 = _mm_mul_ps(
          v17,
          _mm_andnot_ps(
            _mm_cmpleps(v19, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
              _mm_mul_ps(*(__m128 *)_xmm, v20))));
  v22 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v3);
  v23 = _mm_sub_ps(v22, v8);
  v24 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v3), v10);
  v25 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v3), v9);
  v26 = _mm_sub_ps(_mm_mul_ps(v15, v23), _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v13));
  v27 = _mm_sub_ps(_mm_mul_ps(v14, v24), _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v12));
  v28 = _mm_mul_ps(v7.m_quad, v21);
  v29 = _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v17);
  v30 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v25), _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v11));
  v31 = _mm_mul_ps(work->m_masterNormal.m_quad, v17);
  v32 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v17);
  v33 = _mm_shuffle_ps(v29, v32, 68);
  v34 = _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v17);
  v35 = _mm_shuffle_ps(v34, v31, 68);
  v36 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v29, v32, 238), _mm_shuffle_ps(v34, v31, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v33, v35, 221), _mm_shuffle_ps(v33, v35, 136)));
  result = (unsigned int)((~(unsigned __int8)_mm_movemask_ps(_mm_cmpltps(v36, (__m128)0i64)) & 7) != 0) + 17;
  out->m_normal.m_quad = _mm_xor_ps(
                           (__m128)_mm_slli_epi32(
                                     _mm_srli_epi32(
                                       (__m128i)_mm_cmpltps(_mm_shuffle_ps(v36, v36, 255), (__m128)0i64),
                                       0x1Fu),
                                     0x1Fu),
                           v21);
  out->m_pointOnA.m_quad = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                                 _mm_shuffle_ps(v28, v28, 170)),
                               v21),
                             v22);
  return result;
}

// File Line: 284
// RVA: 0xDBD310
signed __int64 __fastcall hkGskManifold_convertEdgeEdge(hkpGskManifoldWork *work, hkpGskManifold::ContactPoint *feature, hkGskManifoldConvertOut *out)
{
  __int64 v3; // r10
  __int64 v4; // r9
  __int64 v5; // r11
  __int64 v6; // rdx
  __m128 *v7; // r11
  __m128 v8; // xmm8
  __m128 v9; // xmm9
  __m128 v10; // xmm4
  __m128 v11; // xmm9
  __m128 v12; // xmm6
  __m128 v13; // xmm4
  __m128 v14; // xmm8
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  __m128 v20; // xmm7
  __m128 v21; // xmm3
  __m128 v22; // xmm7
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm6
  __m128 v26; // xmm7
  __m128 v27; // xmm0
  __m128 v28; // xmm7
  __m128 v29; // xmm3
  __m128 v30; // xmm1
  __m128 v31; // xmm6
  int v32; // eax
  signed __int64 result; // rax
  __m128 v34; // xmm4
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  hkVector4f v38; // xmm4
  __m128 v39; // xmm1
  __m128 v40; // xmm2

  v3 = (unsigned __int8)feature->m_vert[1];
  v4 = (unsigned __int8)feature->m_vert[0];
  v5 = (unsigned __int8)feature->m_vert[2];
  v6 = (unsigned __int8)feature->m_vert[3];
  v7 = (__m128 *)((char *)work + v5);
  v8 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4);
  v9 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v3);
  v10 = v9;
  v11 = _mm_sub_ps(v9, *(__m128 *)((char *)&work->m_vertices[0].m_quad + v6));
  v12 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v6), *v7);
  v13 = _mm_sub_ps(v10, v8);
  v14 = _mm_sub_ps(v8, *v7);
  v15 = _mm_shuffle_ps(v13, v13, 201);
  v16 = _mm_shuffle_ps(v12, v12, 201);
  v17 = _mm_sub_ps(_mm_mul_ps(v16, v13), _mm_mul_ps(v15, v12));
  out->m_normal = work->m_masterNormal;
  v18 = _mm_shuffle_ps(v17, v17, 201);
  v19 = v18;
  v20 = v19;
  v21 = _mm_sub_ps(_mm_mul_ps(v19, v12), _mm_mul_ps(v16, v18));
  v22 = _mm_sub_ps(_mm_mul_ps(v20, v13), _mm_mul_ps(v15, v18));
  v23 = _mm_shuffle_ps(v21, v21, 201);
  v24 = _mm_mul_ps(v11, v23);
  v25 = _mm_mul_ps(v23, v14);
  v26 = _mm_shuffle_ps(v22, v22, 201);
  v27 = _mm_mul_ps(v26, v14);
  v28 = _mm_mul_ps(v26, v11);
  v29 = _mm_shuffle_ps(v25, v27, 68);
  v30 = _mm_shuffle_ps(v24, v28, 68);
  v31 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v25, v27, 238), _mm_shuffle_ps(v24, v28, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v29, v30, 221), _mm_shuffle_ps(v29, v30, 136)));
  v32 = _mm_movemask_ps(_mm_cmpltps(v31, (__m128)0i64));
  if ( v32 != 3 && v32 != 12 )
    return 18i64;
  result = 17i64;
  v34 = _mm_shuffle_ps(v31, v31, 0);
  v35 = _mm_sub_ps(v34, _mm_shuffle_ps(v31, v31, 170));
  v36 = _mm_rcp_ps(v35);
  v37 = _mm_shuffle_ps(v31, v31, 85);
  v38.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(
                     *(__m128 *)((char *)&work->m_vertices[0].m_quad + v3),
                     *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4)),
                   _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v36, v35)), v36), v34)),
                 *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4));
  v39 = _mm_sub_ps(v37, _mm_shuffle_ps(v31, v31, 255));
  out->m_pointOnA = (hkVector4f)v38.m_quad;
  v40 = _mm_rcp_ps(v39);
  out->m_AminusB.m_quad = _mm_sub_ps(
                            v38.m_quad,
                            _mm_add_ps(
                              _mm_mul_ps(
                                _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v6), *v7),
                                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v40, v39)), v40), v37)),
                              *v7));
  return result;
}

// File Line: 323
// RVA: 0xDBD4C0
signed __int64 __fastcall hkGskManifold_convertFeature(hkpGskManifoldWork *work, hkpGskManifold::ContactPoint *feature, hkGskManifoldConvertOut *out)
{
  hkVector4f *v3; // r10
  hkGskManifoldConvertOut *v4; // rbx
  hkpGskManifold::ContactPoint *v5; // r11
  int v6; // ecx
  __int64 v7; // rcx
  hkVector4f v8; // xmm3
  __m128 v9; // xmm1
  signed __int64 result; // rax
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // rax
  __m128 v14; // xmm7
  __m128 v15; // xmm6
  __m128 v16; // xmm5
  __m128 v17; // xmm2
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // xmm3
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm4
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  __m128 v28; // xmm4
  __m128 v29; // xmm3
  __m128 v30; // xmm4
  __m128 v31; // xmm1
  __int64 v32; // r8
  __int64 v33; // rdx
  __int64 v34; // rcx
  __int64 v35; // rax
  __m128 v36; // xmm6
  __m128 v37; // xmm5
  __m128 v38; // xmm4
  __m128 v39; // xmm3
  __m128 v40; // xmm7
  __m128 v41; // xmm15
  __m128 v42; // xmm8
  __m128 v43; // xmm13
  __m128 v44; // xmm11
  __m128 v45; // xmm14
  __m128 v46; // xmm14
  __m128 v47; // xmm1
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  __m128 v50; // xmm10
  __m128 v51; // xmm0
  __m128 v52; // xmm2
  __m128 v53; // xmm9
  __m128 v54; // xmm0
  __m128 v55; // xmm1
  __m128 v56; // xmm3
  __m128 v57; // xmm9
  __m128 v58; // xmm1
  __m128 v59; // xmm15
  __m128 v60; // xmm11
  __m128 v61; // xmm15
  __m128 v62; // xmm11
  __m128 v63; // xmm13
  __m128 v64; // xmm0
  __m128 v65; // xmm2
  __m128 v66; // xmm13
  __m128 v67; // xmm1
  __m128 v68; // xmm15
  __int64 v69; // rax
  __int64 v70; // rcx
  __int64 v71; // rdx
  __m128 v72; // xmm7
  __m128 v73; // xmm6
  __m128 v74; // xmm2
  __m128 v75; // xmm4
  __m128 v76; // xmm5
  __m128 v77; // xmm0
  __m128 v78; // xmm2
  __m128 v79; // xmm3
  __m128 v80; // xmm5
  __m128 v81; // xmm1
  __m128 v82; // xmm3
  __m128 v83; // xmm4
  __m128 v84; // xmm3
  __m128 v85; // xmm3
  __m128 v86; // xmm5
  __m128 v87; // xmm2
  __m128 v88; // xmm5
  __m128 v89; // xmm3
  __m128 v90; // xmm5
  __m128 v91; // xmm1
  hkVector4f v92; // xmm6
  __int64 v93; // rcx
  __int64 v94; // rax
  __int64 v95; // r8
  __m128 v96; // xmm6
  __m128 v97; // xmm5
  __m128 *v98; // rdx
  __m128 v99; // xmm8
  __m128 v100; // xmm6
  __m128 v101; // xmm7
  __m128 v102; // xmm8
  __m128 v103; // xmm5
  __m128 v104; // xmm2
  __m128 v105; // xmm4
  __m128 v106; // xmm3
  __m128 v107; // xmm3
  __m128 v108; // xmm1
  __m128 v109; // xmm8
  __m128 v110; // xmm7
  __m128 v111; // xmm7
  __m128 v112; // xmm8
  __m128 v113; // xmm0
  __m128 v114; // xmm9
  __m128 v115; // xmm7
  __m128 v116; // xmm2
  __m128 v117; // xmm8
  __m128 v118; // xmm1
  __m128 v119; // xmm9
  int v120; // er9
  __m128 v121; // xmm4
  __m128 v122; // xmm1
  __m128 v123; // xmm2
  __m128 v124; // xmm3
  __m128 v125; // xmm2
  __m128 v126; // xmm1
  __m128 v127; // xmm0
  __m128 v128; // xmm4
  __int64 v129; // r8
  __int64 v130; // rdx
  __int64 v131; // rcx
  __int64 v132; // rax
  __m128 v133; // xmm0
  __m128 v134; // xmm8
  __m128 v135; // xmm7
  __m128 v136; // xmm5
  __m128 v137; // ST00_16
  __m128 v138; // xmm9
  __m128 v139; // xmm11
  __m128 v140; // xmm6
  __m128 v141; // xmm10
  __m128 v142; // xmm15
  __m128 v143; // xmm12
  __m128 v144; // xmm12
  __m128 v145; // xmm1
  __m128 v146; // xmm3
  __m128 v147; // xmm2
  __m128 v148; // xmm13
  __m128 v149; // xmm4
  __m128 v150; // xmm14
  __m128 v151; // xmm3
  __m128 v152; // xmm1
  __m128 v153; // xmm14
  __m128 v154; // xmm3
  __m128 v155; // xmm14
  __m128 v156; // xmm3
  __m128 v157; // xmm15
  __m128 v158; // xmm0
  __m128 v159; // xmm2
  __m128 v160; // xmm15
  __m128 v161; // xmm1
  __m128 v162; // xmm14
  __m128 v163; // xmm1

  v3 = (hkVector4f *)work;
  v4 = out;
  v5 = feature;
  v6 = (unsigned __int8)feature->m_dimB + 4 * (unsigned __int8)feature->m_dimA;
  switch ( 0x40000000 )
  {
    case 5:
      v7 = (unsigned __int8)feature->m_vert[0];
      v8.m_quad = _mm_sub_ps(
                    *(__m128 *)((char *)&v3->m_quad + v7),
                    *(__m128 *)((char *)&v3->m_quad + (unsigned __int8)feature->m_vert[1]));
      v9 = _mm_mul_ps(v8.m_quad, v8.m_quad);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 170))) > COERCE_FLOAT(
                                                                  _mm_shuffle_ps(
                                                                    (__m128)v3[17].m_quad.m128_u32[3],
                                                                    (__m128)v3[17].m_quad.m128_u32[3],
                                                                    0)) )
        goto $LN1_62;
      out->m_AminusB = (hkVector4f)v8.m_quad;
      result = 5i64;
      out->m_normal = (hkVector4f)v3[16].m_quad;
      out->m_pointOnA = *(hkVector4f *)((char *)v3 + v7);
      break;
    case 6:
      v11 = (unsigned __int8)feature->m_vert[0];
      v12 = (unsigned __int8)v5->m_vert[1];
      v13 = (unsigned __int8)v5->m_vert[2];
      out->m_pointOnA = *(hkVector4f *)((char *)v3 + v11);
      out->m_normal = (hkVector4f)v3[16].m_quad;
      v14 = *(__m128 *)((char *)&v3->m_quad + v12);
      v15 = *(__m128 *)((char *)&v3->m_quad + v11);
      v16 = _mm_sub_ps(*(__m128 *)((char *)&v3->m_quad + v13), v14);
      v17 = _mm_sub_ps(*(__m128 *)((char *)&v3->m_quad + v13), v15);
      v18 = _mm_mul_ps(v16, v17);
      v19 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v16), _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v17));
      v20 = _mm_shuffle_ps(v19, v19, 201);
      v21 = _mm_mul_ps(v20, v20);
      v22 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)&v3->m_quad + v11), v14), v16);
      v23 = _mm_unpacklo_ps(v18, v22);
      v24 = _mm_movelh_ps(v23, v21);
      v25 = _mm_shuffle_ps(_mm_unpackhi_ps(v18, v22), v21, 228);
      v26 = _mm_shuffle_ps(_mm_movehl_ps(v24, v23), v21, 212);
      v27 = _mm_mul_ps(v16, v16);
      v28 = _mm_add_ps(v25, _mm_add_ps(v24, v26));
      if ( COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 170)) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 85))
                                                                               + COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 0)))
                                                                       + COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 170)))
                                                               * COERCE_FLOAT(
                                                                   _mm_shuffle_ps(
                                                                     (__m128)v3[17].m_quad.m128_u32[3],
                                                                     (__m128)v3[17].m_quad.m128_u32[3],
                                                                     0))) )
        goto $LN1_62;
      if ( _mm_movemask_ps(_mm_cmpltps(v28, (__m128)0i64)) & 3 )
        goto LABEL_6;
      result = 5i64;
      v29 = _mm_shuffle_ps(v28, v28, 0);
      v30 = _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), v29);
      v31 = _mm_rcp_ps(v30);
      out->m_AminusB.m_quad = _mm_sub_ps(
                                v15,
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    v16,
                                    _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v31, v30)), v31), v29)),
                                  v14));
      break;
    case 7:
      v32 = (unsigned __int8)feature->m_vert[0];
      v33 = (unsigned __int8)feature->m_vert[1];
      v34 = (unsigned __int8)v5->m_vert[2];
      v35 = (unsigned __int8)v5->m_vert[3];
      v4->m_pointOnA = *(hkVector4f *)((char *)v3 + v32);
      v4->m_AminusB.m_quad = _mm_sub_ps(*(__m128 *)((char *)&v3->m_quad + v32), *(__m128 *)((char *)&v3->m_quad + v33));
      v36 = *(__m128 *)((char *)&v3->m_quad + v35);
      v37 = *(__m128 *)((char *)&v3->m_quad + v33);
      v38 = *(__m128 *)((char *)&v3->m_quad + v34);
      v39 = *(__m128 *)((char *)&v3->m_quad + v32);
      v40 = _mm_sub_ps(*(__m128 *)((char *)&v3->m_quad + v35), v38);
      v41 = _mm_shuffle_ps(v40, v40, 201);
      v42 = _mm_sub_ps(*(__m128 *)((char *)&v3->m_quad + v33), v36);
      v43 = _mm_sub_ps(*(__m128 *)((char *)&v3->m_quad + v34), v37);
      v44 = _mm_shuffle_ps(v42, v42, 201);
      v45 = _mm_sub_ps(_mm_mul_ps(v44, v40), _mm_mul_ps(v41, v42));
      v46 = _mm_shuffle_ps(v45, v45, 201);
      v47 = _mm_mul_ps(v46, v46);
      v48 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
              _mm_shuffle_ps(v47, v47, 170));
      v49 = _mm_rsqrt_ps(v48);
      v50 = _mm_cmpleps(v48, (__m128)0i64);
      v51 = _mm_mul_ps(_mm_mul_ps(v49, v48), v49);
      v52 = _mm_sub_ps(*(__m128 *)((char *)&v3->m_quad + v32), v36);
      v53 = _mm_sub_ps((__m128)_xmm, v51);
      v54 = _mm_mul_ps(*(__m128 *)_xmm, v49);
      v55 = v39;
      v56 = _mm_sub_ps(v39, v37);
      v57 = _mm_mul_ps(v53, v54);
      v58 = _mm_sub_ps(v55, v38);
      v59 = _mm_sub_ps(_mm_mul_ps(v41, v58), _mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), v40));
      v60 = _mm_sub_ps(_mm_mul_ps(v44, v52), _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v42));
      v61 = _mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v46);
      v62 = _mm_mul_ps(_mm_shuffle_ps(v60, v60, 201), v46);
      v63 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v56), _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v43));
      v64 = _mm_mul_ps(v3[16].m_quad, v46);
      v65 = _mm_shuffle_ps(v61, v62, 68);
      v66 = _mm_mul_ps(_mm_shuffle_ps(v63, v63, 201), v46);
      v67 = _mm_shuffle_ps(v66, v64, 68);
      v68 = _mm_add_ps(
              _mm_shuffle_ps(_mm_shuffle_ps(v61, v62, 238), _mm_shuffle_ps(v66, v64, 238), 136),
              _mm_add_ps(_mm_shuffle_ps(v65, v67, 221), _mm_shuffle_ps(v65, v67, 136)));
      result = (unsigned int)((~(unsigned __int8)_mm_movemask_ps(_mm_cmpltps(v68, (__m128)0i64)) & 7) != 0) + 17;
      v4->m_normal.m_quad = _mm_xor_ps(
                              (__m128)_mm_slli_epi32(
                                        _mm_srli_epi32(
                                          (__m128i)_mm_cmpltps(_mm_shuffle_ps(v68, v68, 255), (__m128)0i64),
                                          0x1Fu),
                                        0x1Fu),
                              _mm_mul_ps(_mm_andnot_ps(v50, v57), v46));
      break;
    case 9:
      v69 = (unsigned __int8)feature->m_vert[1];
      v70 = (unsigned __int8)feature->m_vert[0];
      v71 = (unsigned __int8)feature->m_vert[2];
      out->m_normal = (hkVector4f)v3[16].m_quad;
      v72 = *(__m128 *)((char *)&v3->m_quad + v69);
      v73 = *(__m128 *)((char *)&v3->m_quad + v70);
      v74 = *(__m128 *)((char *)&v3->m_quad + v71);
      v75 = _mm_sub_ps(v72, v73);
      v76 = _mm_sub_ps(*(__m128 *)((char *)&v3->m_quad + v69), v74);
      v77 = _mm_mul_ps(_mm_shuffle_ps(v75, v75, 201), v76);
      v78 = _mm_mul_ps(_mm_sub_ps(v74, v73), v75);
      v79 = _mm_shuffle_ps(v76, v76, 201);
      v80 = _mm_mul_ps(v76, v75);
      v81 = _mm_unpacklo_ps(v80, v78);
      v82 = _mm_sub_ps(_mm_mul_ps(v79, v75), v77);
      v83 = _mm_mul_ps(v75, v75);
      v84 = _mm_shuffle_ps(v82, v82, 201);
      v85 = _mm_mul_ps(v84, v84);
      v86 = _mm_shuffle_ps(_mm_unpackhi_ps(v80, v78), v85, 228);
      v87 = _mm_movelh_ps(v81, v85);
      v88 = _mm_add_ps(v86, _mm_add_ps(v87, _mm_shuffle_ps(_mm_movehl_ps(v87, v81), v85, 212)));
      if ( COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 170)) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v83, v83, 85))
                                                                               + COERCE_FLOAT(_mm_shuffle_ps(v83, v83, 0)))
                                                                       + COERCE_FLOAT(_mm_shuffle_ps(v83, v83, 170)))
                                                               * COERCE_FLOAT(
                                                                   _mm_shuffle_ps(
                                                                     (__m128)v3[17].m_quad.m128_u32[3],
                                                                     (__m128)v3[17].m_quad.m128_u32[3],
                                                                     0))) )
        goto $LN1_62;
      if ( _mm_movemask_ps(_mm_cmpltps(v88, (__m128)0i64)) & 3 )
      {
LABEL_6:
        result = 6i64;
      }
      else
      {
        result = 5i64;
        v89 = _mm_shuffle_ps(v88, v88, 0);
        v90 = _mm_add_ps(_mm_shuffle_ps(v88, v88, 85), v89);
        v91 = _mm_rcp_ps(v90);
        v92.m_quad = _mm_add_ps(
                       _mm_mul_ps(
                         _mm_sub_ps(v73, v72),
                         _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v91, v90)), v91), v89)),
                       v72);
        out->m_pointOnA = (hkVector4f)v92.m_quad;
        out->m_AminusB.m_quad = _mm_sub_ps(v92.m_quad, *(__m128 *)((char *)&v3->m_quad + v71));
      }
      break;
    case 10:
      v93 = (unsigned __int8)feature->m_vert[1];
      v94 = (unsigned __int8)feature->m_vert[0];
      v95 = (unsigned __int8)feature->m_vert[3];
      v96 = *(__m128 *)((char *)&v3->m_quad + v93);
      v97 = *(__m128 *)((char *)&v3->m_quad + v94);
      v98 = (__m128 *)((char *)&v3->m_quad + (unsigned __int8)feature->m_vert[2]);
      v99 = v96;
      v100 = _mm_sub_ps(v96, *(__m128 *)((char *)&v3->m_quad + v95));
      v101 = _mm_sub_ps(*(__m128 *)((char *)&v3->m_quad + v95), *v98);
      v102 = _mm_sub_ps(v99, v97);
      v103 = _mm_sub_ps(v97, *v98);
      v104 = _mm_shuffle_ps(v102, v102, 201);
      v105 = _mm_shuffle_ps(v101, v101, 201);
      v106 = _mm_sub_ps(_mm_mul_ps(v102, v105), _mm_mul_ps(v101, v104));
      v107 = _mm_shuffle_ps(v106, v106, 201);
      v108 = v107;
      v109 = _mm_sub_ps(_mm_mul_ps(v102, v108), _mm_mul_ps(v107, v104));
      v110 = _mm_sub_ps(_mm_mul_ps(v101, v108), _mm_mul_ps(v107, v105));
      v4->m_normal = (hkVector4f)v3[16].m_quad;
      v111 = _mm_shuffle_ps(v110, v110, 201);
      v112 = _mm_shuffle_ps(v109, v109, 201);
      v113 = _mm_mul_ps(v112, v103);
      v114 = _mm_mul_ps(v111, v103);
      v115 = _mm_mul_ps(v111, v100);
      v116 = _mm_shuffle_ps(v114, v113, 68);
      v117 = _mm_mul_ps(v112, v100);
      v118 = _mm_shuffle_ps(v115, v117, 68);
      v119 = _mm_add_ps(
               _mm_shuffle_ps(_mm_shuffle_ps(v114, v113, 238), _mm_shuffle_ps(v115, v117, 238), 136),
               _mm_add_ps(_mm_shuffle_ps(v116, v118, 221), _mm_shuffle_ps(v116, v118, 136)));
      v120 = _mm_movemask_ps(_mm_cmpltps(v119, (__m128)0i64));
      if ( v120 == 3 || v120 == 12 )
      {
        v121 = _mm_shuffle_ps(v119, v119, 0);
        v122 = _mm_sub_ps(v121, _mm_shuffle_ps(v119, v119, 170));
        v123 = _mm_rcp_ps(v122);
        v124 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v123, v122)), v123), v121);
        v125 = _mm_shuffle_ps(v119, v119, 85);
        v126 = _mm_sub_ps(v125, _mm_shuffle_ps(v119, v119, 255));
        v127 = _mm_rcp_ps(v126);
        v128 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(*(__m128 *)((char *)&v3->m_quad + v93), *(__m128 *)((char *)&v3->m_quad + v94)),
                   v124),
                 *(__m128 *)((char *)&v3->m_quad + v94));
        result = 17i64;
        v4->m_pointOnA.m_quad = v128;
        v4->m_AminusB.m_quad = _mm_sub_ps(
                                 v128,
                                 _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_sub_ps(*(__m128 *)((char *)&v3->m_quad + v95), *v98),
                                     _mm_mul_ps(
                                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v126, v127)), v127),
                                       v125)),
                                   *v98));
      }
      else
      {
        result = 18i64;
      }
      break;
    case 13:
      v129 = (unsigned __int8)feature->m_vert[3];
      v130 = (unsigned __int8)feature->m_vert[0];
      v131 = (unsigned __int8)v5->m_vert[1];
      v132 = (unsigned __int8)v5->m_vert[2];
      v4->m_pointOnA = *(hkVector4f *)((char *)v3 + v129);
      v133 = _mm_sub_ps(*(__m128 *)((char *)&v3->m_quad + v130), *(__m128 *)((char *)&v3->m_quad + v129));
      v4->m_AminusB.m_quad = v133;
      v134 = *(__m128 *)((char *)&v3->m_quad + v132);
      v135 = *(__m128 *)((char *)&v3->m_quad + v130);
      v136 = *(__m128 *)((char *)&v3->m_quad + v131);
      v137 = v133;
      v138 = _mm_sub_ps(v134, v136);
      v139 = _mm_sub_ps(v135, v134);
      v140 = _mm_shuffle_ps(v138, v138, 201);
      v141 = _mm_shuffle_ps(v139, v139, 201);
      v142 = _mm_sub_ps(v136, v135);
      v143 = _mm_sub_ps(_mm_mul_ps(v138, v141), _mm_mul_ps(v139, v140));
      v144 = _mm_shuffle_ps(v143, v143, 201);
      v145 = _mm_mul_ps(v144, v144);
      v146 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v145, v145, 85), _mm_shuffle_ps(v145, v145, 0)),
               _mm_shuffle_ps(v145, v145, 170));
      v147 = _mm_rsqrt_ps(v146);
      v148 = _mm_mul_ps(
               v144,
               _mm_andnot_ps(
                 _mm_cmpleps(v146, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v147, v146), v147)),
                   _mm_mul_ps(*(__m128 *)_xmm, v147))));
      v149 = *(__m128 *)((char *)&v3->m_quad + v129);
      v150 = _mm_sub_ps(v149, v136);
      v151 = _mm_sub_ps(*(__m128 *)((char *)&v3->m_quad + v129), v134);
      v152 = _mm_sub_ps(*(__m128 *)((char *)&v3->m_quad + v129), v135);
      v153 = _mm_sub_ps(_mm_mul_ps(v150, v140), _mm_mul_ps(_mm_shuffle_ps(v150, v150, 201), v138));
      v154 = _mm_sub_ps(_mm_mul_ps(v151, v141), _mm_mul_ps(_mm_shuffle_ps(v151, v151, 201), v139));
      v155 = _mm_mul_ps(_mm_shuffle_ps(v153, v153, 201), v144);
      v156 = _mm_mul_ps(_mm_shuffle_ps(v154, v154, 201), v144);
      v157 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v142, v142, 201), v152),
               _mm_mul_ps(_mm_shuffle_ps(v152, v152, 201), v142));
      v158 = _mm_mul_ps(v3[16].m_quad, v144);
      v159 = _mm_shuffle_ps(v155, v156, 68);
      v160 = _mm_mul_ps(_mm_shuffle_ps(v157, v157, 201), v144);
      v161 = _mm_shuffle_ps(v160, v158, 68);
      v162 = _mm_add_ps(
               _mm_shuffle_ps(_mm_shuffle_ps(v155, v156, 238), _mm_shuffle_ps(v160, v158, 238), 136),
               _mm_add_ps(_mm_shuffle_ps(v159, v161, 221), _mm_shuffle_ps(v159, v161, 136)));
      v163 = _mm_mul_ps(v148, v137);
      result = (unsigned int)((~(unsigned __int8)_mm_movemask_ps(_mm_cmpltps(v162, (__m128)0i64)) & 7) != 0) + 17;
      v4->m_pointOnA.m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v163, v163, 85), _mm_shuffle_ps(v163, v163, 0)),
                                    _mm_shuffle_ps(v163, v163, 170)),
                                  v148),
                                v149);
      v4->m_normal.m_quad = _mm_xor_ps(
                              (__m128)_mm_slli_epi32(
                                        _mm_srli_epi32(
                                          (__m128i)_mm_cmpltps(_mm_shuffle_ps(v162, v162, 255), (__m128)0i64),
                                          0x1Fu),
                                        0x1Fu),
                              v148);
      break;
    default:
$LN1_62:
      result = 10i64;
      break;
  }
  return result;
}efault:
$LN1_62:
      result = 10i64;
      break;
  }
  return result;
}

// File Line: 338
// RVA: 0xDBDD90
void __fastcall hkGskManifold_garbageCollect(hkpGskManifold *manifold)
{
  __int64 v1; // r9
  hkpGskManifold *v2; // r10
  unsigned __int8 *v3; // rax
  __int64 v4; // r8
  int v5; // edx
  unsigned int v6; // ebx
  int v7; // ecx
  signed __int64 v8; // r11
  int v9; // er8
  int v10; // er9
  __int64 v11; // rdx
  __int64 v12; // rdi
  __int64 v13; // rcx
  unsigned int v14; // ecx
  __int64 v15; // rax
  char *v16; // rcx
  __m128 v17; // [rsp+0h] [rbp-58h]
  int v18[18]; // [rsp+10h] [rbp-48h]

  v1 = (unsigned __int8)manifold->m_numContactPoints;
  v2 = manifold;
  v17 = aabbOut.m_quad;
  if ( (_DWORD)v1 )
  {
    v3 = (unsigned __int8 *)&manifold->m_contactPoints[0].4;
    v4 = (unsigned int)v1;
    do
    {
      v5 = *(v3 - 3) + *(v3 - 4);
      v17.m128_i8[(unsigned __int64)*v3 >> 4] = 1;
      v17.m128_i8[(unsigned __int64)v3[1] >> 4] = 1;
      if ( v5 >= 3 )
        v17.m128_i8[(unsigned __int64)v3[2] >> 4] = 1;
      if ( v5 == 4 )
        v17.m128_i8[(unsigned __int64)v3[3] >> 4] = 1;
      v3 += 8;
      --v4;
    }
    while ( v4 );
  }
  v6 = 0;
  v7 = (unsigned __int8)manifold->m_numVertsA + (unsigned __int8)manifold->m_numVertsB;
  v8 = (signed __int64)v2 + 8 * v1;
  v9 = 0;
  v10 = 0;
  v11 = 0i64;
  v12 = v7;
  if ( v7 > 0 )
  {
    do
    {
      v18[v11] = v10;
      if ( v17.m128_i8[v11] )
      {
        v13 = v9++;
        *(_WORD *)(v8 + 2 * v13 + 4) = *(_WORD *)(v8 + 2 * v11 + 4);
        v10 += 16;
      }
      ++v11;
    }
    while ( v11 < v12 );
  }
  v14 = (unsigned int)v18[(unsigned __int8)v2->m_numVertsA] >> 4;
  v2->m_numVertsA = v14;
  v2->m_numVertsB = v9 - v14;
  if ( v2->m_numContactPoints > 0u )
  {
    do
    {
      v15 = v6++;
      v16 = &v2->m_numVertsA + 8 * v15;
      v16[8] = v18[(unsigned __int64)(unsigned __int8)v2->m_contactPoints[v15].m_vert[0] >> 4];
      v16[9] = v18[(unsigned __int64)(unsigned __int8)v16[9] >> 4];
      v16[10] = v18[(unsigned __int64)(unsigned __int8)v16[10] >> 4];
      v16[11] = v18[(unsigned __int64)(unsigned __int8)v16[11] >> 4];
    }
    while ( v6 < (unsigned __int8)v2->m_numContactPoints );
  }
}

// File Line: 440
// RVA: 0xDBCA70
void __fastcall hkGskManifold_removePoint(hkpGskManifold *manifold, int index)
{
  int v2; // er9
  hkpGskManifold *v3; // r10
  __int64 v4; // r8
  hkpGskManifold::ContactPoint *v5; // r9
  hkpGskManifold::ContactPoint *v6; // rax
  int v7; // er8
  signed __int64 v8; // r9
  unsigned int v9; // ecx

  v2 = (unsigned __int8)manifold->m_numContactPoints;
  v3 = manifold;
  v4 = (unsigned int)(v2 - 1);
  manifold->m_numContactPoints = v2 - 1;
  manifold->m_contactPoints[index] = manifold->m_contactPoints[v4];
  v5 = &manifold->m_contactPoints[v2];
  v6 = &manifold->m_contactPoints[(signed int)v4];
  v7 = ((unsigned __int8)manifold->m_numVertsB + (unsigned __int8)manifold->m_numVertsA - 1) >> 1;
  if ( v7 >= 0 )
  {
    v8 = (char *)v5 - (char *)v6;
    do
    {
      --v7;
      v9 = *(_DWORD *)(&v6->m_dimA + v8);
      v6 = (hkpGskManifold::ContactPoint *)((char *)v6 + 4);
      v6[-1].m_allVerts = v9;
    }
    while ( v7 >= 0 );
  }
  hkGskManifold_garbageCollect(v3);
}

// File Line: 462
// RVA: 0xDBBB20
__int64 __fastcall hkGskManifold_verifyAndGetPoints(hkpGskManifold *manifold, hkpGskManifoldWork *work, int firstPointIndex, hkpProcessCollisionOutput *processOut, hkpContactMgr *contactMgr)
{
  unsigned int v5; // er14
  hkpProcessCollisionOutput *v6; // r12
  unsigned int v7; // ebp
  __m128 *v8; // rdi
  hkpGskManifold *v9; // rbx
  __int64 v10; // r15
  __m128 v11; // xmm9
  __m128 *v12; // r9
  __int64 v13; // rsi
  __m128 v14; // xmm1
  __m128 v15; // xmm12
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  char v18; // al
  __int64 v19; // rcx
  __m128 v20; // xmm4
  __m128 v21; // xmm5
  __m128 *v22; // rdx
  __m128 v23; // xmm6
  __m128 v24; // xmm4
  __m128 v25; // xmm6
  __m128 v26; // xmm3
  __m128 v27; // xmm0
  __m128 v28; // xmm4
  __m128 v29; // xmm3
  __m128 v30; // xmm3
  __m128 v31; // xmm3
  __m128 v32; // xmm0
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm4
  __m128 v36; // xmm0
  __m128 v37; // xmm1
  __m128 v38; // xmm4
  __m128 v39; // xmm3
  __m128 v40; // xmm4
  __m128 v41; // xmm1
  __m128 v42; // xmm0
  __m128 v43; // xmm4
  __m128 v44; // xmm5
  __m128 *v45; // rdx
  __m128 v46; // xmm12
  __m128 v47; // xmm6
  __m128 v48; // xmm8
  __m128 v49; // xmm7
  __m128 v50; // xmm3
  __m128 v51; // xmm10
  __m128 v52; // xmm4
  __m128 v53; // ST20_16
  __m128 v54; // xmm13
  __m128 v55; // xmm13
  __m128 v56; // xmm1
  __m128 v57; // xmm2
  __m128 v58; // xmm1
  __m128 v59; // xmm11
  __m128 v60; // xmm9
  __m128 v61; // xmm10
  __m128 v62; // xmm4
  __m128 v63; // xmm10
  __m128 v64; // xmm4
  __m128 v65; // xmm12
  __m128 v66; // xmm0
  __m128 v67; // xmm2
  __m128 v68; // xmm12
  __m128 v69; // xmm1
  __m128 v70; // xmm10
  __m128 v71; // xmm0
  __m128 v72; // xmm2
  __m128 v73; // xmm10
  __m128 v74; // xmm11
  __int64 v75; // rcx
  __m128 v76; // xmm6
  __m128 v77; // xmm7
  __m128 *v78; // rdx
  __m128 v79; // xmm5
  __m128 v80; // xmm4
  __m128 v81; // xmm3
  __m128 v82; // xmm0
  __m128 v83; // xmm5
  __m128 v84; // xmm3
  __m128 v85; // xmm3
  __m128 v86; // xmm3
  __m128 v87; // xmm0
  __m128 v88; // xmm4
  __m128 v89; // xmm1
  __m128 v90; // xmm2
  __m128 v91; // xmm5
  __m128 v92; // xmm3
  __m128 v93; // xmm5
  __m128 v94; // xmm1
  __int64 v95; // rcx
  __m128 v96; // xmm8
  __m128 v97; // xmm11
  __m128 v98; // xmm14
  __m128 v99; // xmm8
  __m128 v100; // xmm15
  __m128 v101; // xmm11
  __m128 v102; // xmm13
  __m128 v103; // xmm7
  __m128 v104; // xmm2
  __m128 v105; // xmm4
  __m128 v106; // xmm3
  __m128 v107; // xmm3
  __m128 v108; // xmm1
  __m128 v109; // xmm6
  __m128 v110; // xmm5
  __m128 v111; // xmm5
  __m128 v112; // xmm6
  __m128 v113; // xmm0
  __m128 v114; // xmm10
  __m128 v115; // xmm5
  __m128 v116; // xmm2
  __m128 v117; // xmm6
  __m128 v118; // xmm1
  __m128 v119; // xmm10
  int v120; // eax
  __m128 v121; // xmm3
  __m128 v122; // xmm1
  __m128 v123; // xmm2
  __m128 v124; // xmm5
  __m128 v125; // xmm3
  __m128 v126; // xmm1
  __m128 v127; // xmm2
  __m128 v128; // xmm9
  __m128 v129; // xmm5
  __m128 v130; // xmm14
  __m128 v131; // xmm15
  __m128 v132; // xmm7
  __m128 v133; // xmm11
  __m128 v134; // ST20_16
  __m128 v135; // xmm8
  __m128 v136; // xmm10
  __m128 v137; // xmm6
  __m128 v138; // xmm12
  __m128 v139; // xmm12
  __m128 v140; // xmm1
  __m128 v141; // xmm3
  __m128 v142; // xmm2
  __m128 v143; // xmm4
  __m128 v144; // xmm0
  __m128 v145; // xmm3
  __m128 v146; // xmm13
  __m128 v147; // xmm1
  __m128 v148; // xmm4
  __m128 v149; // xmm4
  __m128 v150; // xmm3
  __m128 v151; // xmm4
  __m128 v152; // xmm3
  __m128 v153; // xmm14
  __m128 v154; // xmm14
  __m128 v155; // xmm0
  __m128 v156; // xmm1
  __m128 v157; // xmm2
  __m128 v158; // xmm4
  __m128 v159; // xmm1
  __m128 v160; // xmm5
  __m128 v161; // xmm1
  __m128 v162; // xmm2
  __m128 v163; // xmm1
  __m128 v164; // xmm3
  __m128 v165; // xmm2
  __m128 v166; // xmm1
  __int64 v167; // rdx
  int v168; // er8
  hkpGskManifold::ContactPoint *v169; // rdx
  int i; // er8
  int v171; // ecx
  __m128 v173; // [rsp+30h] [rbp-D8h]
  unsigned int v174; // [rsp+120h] [rbp+18h]

  v5 = 0;
  v6 = processOut;
  v7 = firstPointIndex;
  v8 = (__m128 *)work;
  v9 = manifold;
  v174 = (unsigned __int8)manifold->m_numContactPoints;
  LODWORD(v10) = (unsigned __int8)manifold->m_numContactPoints;
  if ( firstPointIndex < v174 )
  {
    v11 = 0i64;
    while ( 2 )
    {
      v12 = &v6->m_firstFreeContactPoint.m_storage->m_contact.m_position.m_quad;
      v13 = v7;
      v14 = v11;
      v173 = v11;
      v15 = v11;
      switch ( (unsigned __int8)v9->m_contactPoints[v7].m_dimB + 4 * (unsigned __int8)v9->m_contactPoints[v7].m_dimA )
      {
        case 5:
          v16 = _mm_sub_ps(
                  *(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[0]),
                  *(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[1]));
          v17 = _mm_mul_ps(v16, v16);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 170))) > COERCE_FLOAT(
                                                                        _mm_shuffle_ps(
                                                                          (__m128)v8[17].m128_u32[3],
                                                                          (__m128)v8[17].m128_u32[3],
                                                                          0)) )
            goto LABEL_21;
          v15 = v8[16];
          v14 = v16;
          v173 = *(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[0]);
          v18 = 5;
          goto LABEL_23;
        case 6:
          v19 = (unsigned __int8)v9->m_contactPoints[v7].m_vert[0];
          v15 = v8[16];
          v20 = *(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[2]);
          v21 = *(__m128 *)((char *)v8 + v19);
          v22 = (__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[1]);
          v23 = v20;
          v24 = _mm_sub_ps(v20, v21);
          v25 = _mm_sub_ps(v23, *v22);
          v26 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v25);
          v27 = _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v24);
          v28 = _mm_mul_ps(v24, v25);
          v29 = _mm_sub_ps(v26, v27);
          v30 = _mm_shuffle_ps(v29, v29, 201);
          v31 = _mm_mul_ps(v30, v30);
          v32 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v8 + v19), *v22), v25);
          v33 = _mm_unpacklo_ps(v28, v32);
          v34 = _mm_movelh_ps(v33, v31);
          v35 = _mm_shuffle_ps(_mm_unpackhi_ps(v28, v32), v31, 228);
          v36 = _mm_shuffle_ps(_mm_movehl_ps(v34, v33), v31, 212);
          v37 = _mm_mul_ps(v25, v25);
          v38 = _mm_add_ps(v35, _mm_add_ps(v34, v36));
          if ( COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 170)) <= (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 85))
                                                                                    + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 0)))
                                                                            + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 170)))
                                                                    * COERCE_FLOAT(
                                                                        _mm_shuffle_ps(
                                                                          (__m128)v8[17].m128_u32[3],
                                                                          (__m128)v8[17].m128_u32[3],
                                                                          0))) )
          {
            if ( _mm_movemask_ps(_mm_cmpltps(v38, v11)) & 3 )
            {
              v14 = v11;
              v18 = 6;
            }
            else
            {
              v18 = 5;
              v39 = _mm_shuffle_ps(v38, v38, 0);
              v40 = _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), v39);
              v41 = _mm_rcp_ps(v40);
              v14 = _mm_sub_ps(
                      v21,
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v41, v40)), v41), v39),
                          v25),
                        *v22));
            }
          }
          else
          {
            v14 = v11;
            v18 = 10;
          }
          goto LABEL_24;
        case 7:
          v42 = *(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[1]);
          v43 = *(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[2]);
          v44 = *(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[3]);
          v45 = (__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[0]);
          v46 = _mm_sub_ps(*(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[2]), v42);
          v47 = _mm_sub_ps(v44, v43);
          v48 = _mm_sub_ps(v42, v44);
          v49 = _mm_shuffle_ps(v48, v48, 201);
          v50 = _mm_shuffle_ps(v47, v47, 201);
          v51 = _mm_sub_ps(*v45, v43);
          v173 = *v45;
          v52 = _mm_sub_ps(*v45, v44);
          v53 = _mm_sub_ps(*v45, v42);
          v54 = _mm_sub_ps(_mm_mul_ps(v47, v49), _mm_mul_ps(v48, v50));
          v55 = _mm_shuffle_ps(v54, v54, 201);
          v56 = _mm_mul_ps(v55, v55);
          v57 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                  _mm_shuffle_ps(v56, v56, 170));
          v58 = _mm_rsqrt_ps(v57);
          v59 = _mm_cmpleps(v57, v11);
          v60 = _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v58, v57), v58)),
                  _mm_mul_ps(*(__m128 *)_xmm, v58));
          v61 = _mm_sub_ps(_mm_mul_ps(v51, v50), _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v47));
          v62 = _mm_sub_ps(_mm_mul_ps(v52, v49), _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v48));
          v63 = _mm_mul_ps(_mm_shuffle_ps(v61, v61, 201), v55);
          v64 = _mm_mul_ps(_mm_shuffle_ps(v62, v62, 201), v55);
          v65 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v53),
                  _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v46));
          v66 = _mm_mul_ps(v8[16], v55);
          v67 = _mm_shuffle_ps(v63, v64, 68);
          v68 = _mm_mul_ps(_mm_shuffle_ps(v65, v65, 201), v55);
          v69 = _mm_shuffle_ps(v68, v66, 68);
          v70 = _mm_shuffle_ps(_mm_shuffle_ps(v63, v64, 238), _mm_shuffle_ps(v68, v66, 238), 136);
          v71 = _mm_shuffle_ps(v67, v69, 221);
          v72 = _mm_shuffle_ps(v67, v69, 136);
          v14 = v53;
          v73 = _mm_add_ps(v70, _mm_add_ps(v71, v72));
          v74 = _mm_andnot_ps(v59, v60);
          v11 = 0i64;
          v18 = ((~(unsigned __int8)_mm_movemask_ps(_mm_cmpltps(v73, (__m128)0i64)) & 7) != 0) + 17;
          v15 = _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32((__m128i)_mm_cmpltps(_mm_shuffle_ps(v73, v73, 255), (__m128)0i64), 0x1Fu),
                            0x1Fu),
                  _mm_mul_ps(v74, v55));
          goto LABEL_23;
        case 9:
          v75 = (unsigned __int8)v9->m_contactPoints[v7].m_vert[2];
          v15 = v8[16];
          v76 = *(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[1]);
          v77 = *(__m128 *)((char *)v8 + v75);
          v78 = (__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[0]);
          v79 = _mm_sub_ps(v76, v77);
          v80 = _mm_sub_ps(v76, *v78);
          v81 = _mm_mul_ps(_mm_shuffle_ps(v79, v79, 201), v80);
          v82 = _mm_mul_ps(_mm_shuffle_ps(v80, v80, 201), v79);
          v83 = _mm_mul_ps(v79, v80);
          v84 = _mm_sub_ps(v81, v82);
          v85 = _mm_shuffle_ps(v84, v84, 201);
          v86 = _mm_mul_ps(v85, v85);
          v87 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v8 + v75), *v78), v80);
          v88 = _mm_mul_ps(v80, v80);
          v89 = _mm_unpacklo_ps(v83, v87);
          v90 = _mm_movelh_ps(v89, v86);
          v91 = _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v83, v87), v86, 228),
                  _mm_add_ps(v90, _mm_shuffle_ps(_mm_movehl_ps(v90, v89), v86, 212)));
          if ( COERCE_FLOAT(_mm_shuffle_ps(v91, v91, 170)) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 85))
                                                                                   + COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 0)))
                                                                           + COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 170)))
                                                                   * COERCE_FLOAT(
                                                                       _mm_shuffle_ps(
                                                                         (__m128)v8[17].m128_u32[3],
                                                                         (__m128)v8[17].m128_u32[3],
                                                                         0))) )
          {
LABEL_21:
            v14 = v11;
LABEL_22:
            v18 = 10;
          }
          else if ( _mm_movemask_ps(_mm_cmpltps(v91, v11)) & 3 )
          {
            v14 = v11;
            v18 = 6;
          }
          else
          {
            v18 = 5;
            v92 = _mm_shuffle_ps(v91, v91, 0);
            v93 = _mm_add_ps(_mm_shuffle_ps(v91, v91, 85), v92);
            v94 = _mm_rcp_ps(v93);
            v173 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(*v78, v76),
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v94, v93)), v94), v92)),
                     v76);
            v14 = _mm_sub_ps(v173, v77);
          }
LABEL_23:
          v21 = v173;
LABEL_24:
          if ( v18 & 1 )
          {
            v161 = _mm_mul_ps(v14, v15);
            v162 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v161, v161, 85), _mm_shuffle_ps(v161, v161, 0)),
                     _mm_shuffle_ps(v161, v161, 170));
            v163 = _mm_shuffle_ps((__m128)v8[17].m128_u32[1], (__m128)v8[17].m128_u32[1], 0);
            v164 = _mm_sub_ps(v163, v162);
            v165 = _mm_sub_ps(
                     v162,
                     _mm_add_ps(_mm_shuffle_ps((__m128)v8[17].m128_u32[0], (__m128)v8[17].m128_u32[0], 0), v163));
            if ( v165.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)v8[17].m128_u32[2], (__m128)v8[17].m128_u32[2], 0)) )
            {
              *v12 = _mm_add_ps(_mm_mul_ps(v164, v15), v21);
              v12[1] = _mm_shuffle_ps(v15, _mm_unpackhi_ps(v15, v165), 196);
              v12[2].m128_i32[0] = v9->m_contactPoints[v7].m_id;
              ++v6->m_firstFreeContactPoint.m_storage;
              goto LABEL_35;
            }
          }
          else if ( v18 & 0x10 )
          {
            v166 = _mm_mul_ps(v14, v15);
            if ( (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v166, v166, 85))
                                       + COERCE_FLOAT(_mm_shuffle_ps(v166, v166, 0)))
                               + COERCE_FLOAT(_mm_shuffle_ps(v166, v166, 170)))
                       - (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)v8[17].m128_u32[1], (__m128)v8[17].m128_u32[1], 0))
                               + COERCE_FLOAT(_mm_shuffle_ps((__m128)v8[17].m128_u32[0], (__m128)v8[17].m128_u32[0], 0)))) < COERCE_FLOAT(_mm_shuffle_ps((__m128)v8[17].m128_u32[2], (__m128)v8[17].m128_u32[2], 0)) )
              v5 = 1;
          }
          else if ( v18 & 4 )
          {
            v5 = 1;
          }
          v167 = v9->m_contactPoints[v7].m_id;
          if ( (_WORD)v167 != -1 )
            ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *, __m128 *))contactMgr->vfptr[2].__first_virtual_table_function__)(
              contactMgr,
              v167,
              v6->m_constraintOwner.m_storage,
              v12);
          v10 = (unsigned int)(v10 - 1);
          --v7;
          v9->m_contactPoints[v13] = v9->m_contactPoints[v10];
LABEL_35:
          if ( ++v7 < (unsigned int)v10 )
            continue;
          if ( v174 > (unsigned int)v10 )
          {
            v168 = (unsigned __int8)v9->m_numVertsB + (unsigned __int8)v9->m_numVertsA - 1;
            v169 = &v9->m_contactPoints[v174];
            v9->m_numContactPoints = v10;
            for ( i = v168 >> 1;
                  i >= 0;
                  *(_DWORD *)((char *)v169 + 8i64 * (signed int)v10 - 8i64 * (signed int)v174 - 4) = v171 )
            {
              --i;
              v171 = *(_DWORD *)&v169->m_dimA;
              v169 = (hkpGskManifold::ContactPoint *)((char *)v169 + 4);
            }
            hkGskManifold_garbageCollect(v9);
          }
          break;
        case 0xA:
          v95 = (unsigned __int8)v9->m_contactPoints[v7].m_vert[3];
          v15 = v8[16];
          v96 = *(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[1]);
          v97 = v96;
          v98 = *(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[0]);
          v99 = _mm_sub_ps(v96, *(__m128 *)((char *)v8 + v95));
          v100 = *(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[2]);
          v101 = _mm_sub_ps(v97, v98);
          v102 = _mm_sub_ps(*(__m128 *)((char *)v8 + v95), v100);
          v103 = _mm_sub_ps(v98, v100);
          v104 = _mm_shuffle_ps(v101, v101, 201);
          v105 = _mm_shuffle_ps(v102, v102, 201);
          v106 = _mm_sub_ps(_mm_mul_ps(v101, v105), _mm_mul_ps(v102, v104));
          v107 = _mm_shuffle_ps(v106, v106, 201);
          v108 = v107;
          v109 = _mm_sub_ps(_mm_mul_ps(v101, v108), _mm_mul_ps(v107, v104));
          v110 = _mm_sub_ps(_mm_mul_ps(v102, v108), _mm_mul_ps(v107, v105));
          v111 = _mm_shuffle_ps(v110, v110, 201);
          v112 = _mm_shuffle_ps(v109, v109, 201);
          v113 = _mm_mul_ps(v112, v103);
          v114 = _mm_mul_ps(v111, v103);
          v115 = _mm_mul_ps(v111, v99);
          v116 = _mm_shuffle_ps(v114, v113, 68);
          v117 = _mm_mul_ps(v112, v99);
          v118 = _mm_shuffle_ps(v115, v117, 68);
          v119 = _mm_add_ps(
                   _mm_shuffle_ps(_mm_shuffle_ps(v114, v113, 238), _mm_shuffle_ps(v115, v117, 238), 136),
                   _mm_add_ps(_mm_shuffle_ps(v116, v118, 221), _mm_shuffle_ps(v116, v118, 136)));
          v120 = _mm_movemask_ps(_mm_cmpltps(v119, v11));
          if ( v120 == 3 || v120 == 12 )
          {
            v18 = 17;
            v121 = _mm_shuffle_ps(v119, v119, 0);
            v122 = _mm_sub_ps(v121, _mm_shuffle_ps(v119, v119, 170));
            v123 = _mm_rcp_ps(v122);
            v124 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v123, v122)), v123), v121);
            v125 = _mm_shuffle_ps(v119, v119, 85);
            v21 = _mm_add_ps(_mm_mul_ps(v124, v101), v98);
            v126 = _mm_sub_ps(v125, _mm_shuffle_ps(v119, v119, 255));
            v127 = _mm_rcp_ps(v126);
            v14 = _mm_sub_ps(
                    v21,
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v127, v126)), v127), v125),
                        v102),
                      v100));
          }
          else
          {
            v14 = v11;
            v21 = v11;
            v18 = 18;
          }
          goto LABEL_24;
        case 0xD:
          v128 = *(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[0]);
          v129 = *(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[1]);
          v130 = _mm_sub_ps(*(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[1]), v128);
          v131 = *(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[3]);
          v132 = *(__m128 *)((char *)v8 + (unsigned __int8)v9->m_contactPoints[v7].m_vert[2]);
          v133 = _mm_sub_ps(v128, v132);
          v134 = _mm_sub_ps(v128, v131);
          v135 = _mm_sub_ps(v132, v129);
          v136 = _mm_shuffle_ps(v133, v133, 201);
          v137 = _mm_shuffle_ps(v135, v135, 201);
          v138 = _mm_sub_ps(_mm_mul_ps(v135, v136), _mm_mul_ps(v133, v137));
          v139 = _mm_shuffle_ps(v138, v138, 201);
          v140 = _mm_mul_ps(v139, v139);
          v141 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v140, v140, 85), _mm_shuffle_ps(v140, v140, 0)),
                   _mm_shuffle_ps(v140, v140, 170));
          v142 = _mm_rsqrt_ps(v141);
          v143 = _mm_cmpleps(v141, (__m128)0i64);
          v144 = _mm_mul_ps(_mm_mul_ps(v142, v141), v142);
          v145 = _mm_sub_ps(v131, v132);
          v146 = _mm_mul_ps(
                   v139,
                   _mm_andnot_ps(v143, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v144), _mm_mul_ps(*(__m128 *)_xmm, v142))));
          v147 = _mm_sub_ps(v131, v128);
          v148 = _mm_sub_ps(v131, v129);
          v149 = _mm_sub_ps(_mm_mul_ps(v148, v137), _mm_mul_ps(_mm_shuffle_ps(v148, v148, 201), v135));
          v150 = _mm_sub_ps(_mm_mul_ps(v145, v136), _mm_mul_ps(_mm_shuffle_ps(v145, v145, 201), v133));
          v151 = _mm_mul_ps(_mm_shuffle_ps(v149, v149, 201), v139);
          v152 = _mm_mul_ps(_mm_shuffle_ps(v150, v150, 201), v139);
          v153 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v130, v130, 201), v147),
                   _mm_mul_ps(_mm_shuffle_ps(v147, v147, 201), v130));
          v154 = _mm_mul_ps(_mm_shuffle_ps(v153, v153, 201), v139);
          v155 = _mm_mul_ps(v8[16], v139);
          v156 = _mm_shuffle_ps(v154, v155, 68);
          v157 = _mm_shuffle_ps(v151, v152, 68);
          v158 = _mm_add_ps(
                   _mm_shuffle_ps(_mm_shuffle_ps(v151, v152, 238), _mm_shuffle_ps(v154, v155, 238), 136),
                   _mm_add_ps(_mm_shuffle_ps(v157, v156, 221), _mm_shuffle_ps(v157, v156, 136)));
          v159 = _mm_mul_ps(v146, v134);
          v11 = 0i64;
          v18 = ((~(unsigned __int8)_mm_movemask_ps(_mm_cmpltps(v158, (__m128)0i64)) & 7) != 0) + 17;
          v15 = _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32((__m128i)_mm_cmpltps(_mm_shuffle_ps(v158, v158, 255), (__m128)0i64), 0x1Fu),
                            0x1Fu),
                  v146);
          v160 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v159, v159, 85), _mm_shuffle_ps(v159, v159, 0)),
                   _mm_shuffle_ps(v159, v159, 170));
          v14 = v134;
          v21 = _mm_add_ps(_mm_mul_ps(v160, v146), v131);
          goto LABEL_24;
        default:
          goto LABEL_22;
      }
      break;
    }
  }
  return v5;
}

// File Line: 579
// RVA: 0xDBB960
signed __int64 __fastcall hkGskManifold_doesPointExistAndResort(hkpGskManifold *manifold, hkpGskCache *newPoint)
{
  signed __int64 v2; // rbx
  unsigned int v3; // edi
  hkpGskCache *v4; // r10
  hkpGskManifold *v5; // r11
  unsigned int v6; // edx
  unsigned __int8 v7; // si
  unsigned __int8 *v8; // r8
  unsigned __int8 v9; // al
  int v10; // er9
  signed __int64 v11; // rcx
  unsigned __int8 v12; // si
  hkpGskManifold::ContactPoint *v13; // rax
  signed __int64 result; // rax
  __int64 v15; // rax
  signed __int64 v16; // rdx
  hkpGskManifold::ContactPoint v17; // rax

  v2 = (unsigned __int8)manifold->m_numContactPoints;
  v3 = 0;
  v4 = newPoint;
  v5 = manifold;
  v6 = 0;
  if ( manifold->m_numContactPoints )
  {
    v7 = v4->m_dimA;
    v8 = (unsigned __int8 *)&manifold->m_contactPoints[0].4;
    while ( 1 )
    {
      if ( v7 == *(v8 - 4) )
      {
        v9 = v4->m_dimB;
        if ( v9 == *(v8 - 3) )
        {
          v10 = v7 + v9;
          v11 = v2;
          if ( v4->m_vertices[0] == *(_WORD *)(&v5->m_contactPoints[v2].m_dimA + ((unsigned __int64)*v8 >> 3))
            && v4->m_vertices[1] == *(_WORD *)(&v5->m_contactPoints[v11].m_dimA + ((unsigned __int64)v8[1] >> 3))
            && (v10 <= 2
             || v4->m_vertices[2] == *(_WORD *)(&v5->m_contactPoints[v11].m_dimA + ((unsigned __int64)v8[2] >> 3)))
            && (v10 <= 3
             || v4->m_vertices[3] == *(_WORD *)(&v5->m_contactPoints[v11].m_dimA + ((unsigned __int64)v8[3] >> 3))) )
          {
            break;
          }
        }
      }
      ++v6;
      v8 += 8;
      if ( v6 >= (unsigned int)v2 )
        goto LABEL_12;
    }
    if ( v6 )
    {
      v15 = v6;
      v16 = (signed __int64)v5 + 8 * v15;
      v17 = v5->m_contactPoints[v15];
      *(hkpGskManifold::ContactPoint *)(v16 + 4) = v5->m_contactPoints[0];
      v5->m_contactPoints[0] = v17;
    }
    result = 1i64;
  }
  else
  {
LABEL_12:
    v12 = v4->m_dimA;
    if ( (v12 == 1 || v4->m_dimB == 1) && (_DWORD)v2 )
    {
      v13 = v5->m_contactPoints;
      while ( (v12 != 1
            || v13->m_dimA != 1
            || *(_WORD *)(&v5->m_contactPoints[v2].m_dimA + ((unsigned __int64)(unsigned __int8)v13->m_vert[0] >> 3)) != v4->m_vertices[0])
           && (v4->m_dimB != 1
            || v13->m_dimB != 1
            || *(_WORD *)(&v5->m_contactPoints[v2].m_dimA
                        + ((unsigned __int64)(unsigned __int8)v13->m_vert[(unsigned __int8)v13->m_dimA] >> 3)) != v4->m_vertices[v12]) )
      {
        ++v3;
        ++v13;
        if ( v3 >= (unsigned int)v2 )
          goto LABEL_23;
      }
      *(_WORD *)&v13->m_dimA = 0;
      result = 2i64;
    }
    else
    {
LABEL_23:
      result = 0i64;
    }
  }
  return result;
}

// File Line: 647
// RVA: 0xDBDF10
__int64 __fastcall hkGskManifold_findRedundant5thPoint(hkpProcessCdPoint *resultPointArray)
{
  unsigned int v1; // er8
  __m128i v2; // xmm6
  signed __int64 v3; // r11
  hkpProcessCdPoint *v4; // r9
  __m128 v5; // xmm9
  signed __int64 v6; // rdx
  __m128i v7; // xmm10
  __m128 *v8; // rax
  hkVector4f v9; // xmm12
  __m128 v10; // xmm5
  __m128i v11; // xmm4
  __m128i v12; // xmm7
  __m128i v13; // xmm8
  __m128 v14; // xmm1
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128i v17; // xmm2
  __m128i v18; // xmm1
  __m128i v19; // xmm0
  __m128i v20; // xmm2
  __m128i v21; // xmm1
  signed __int64 v22; // rax
  __m128i v23; // xmm7
  __m128 v24; // xmm14
  signed __int64 v25; // rcx
  signed __int64 v26; // rax
  __m128 v27; // xmm0
  __m128 *v28; // rcx
  float v29; // xmm12_4
  __m128 v30; // xmm4
  __m128i v31; // xmm5
  __m128 v32; // xmm1
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128i v35; // xmm1
  __m128i v36; // xmm2
  __m128 v37; // xmm13
  __m128 v38; // xmm5
  signed __int64 v39; // rax
  __m128 *v40; // rcx
  __m128i v41; // xmm7
  __m128i v42; // xmm8
  __m128 v43; // xmm4
  signed __int64 v44; // rax
  __m128 v45; // xmm1
  __m128 v46; // xmm2
  __m128 v47; // xmm0
  __m128i v48; // xmm1
  __m128 v49; // xmm2
  __m128 v50; // xmm2
  __m128 v51; // xmm2
  __m128 v52; // xmm3
  __m128i v53; // xmm2
  __m128 v54; // xmm4
  __m128i v55; // xmm5
  __m128i v56; // xmm7
  signed __int64 v57; // rax
  __m128 *v58; // rcx
  __m128 v59; // xmm1
  __m128 v60; // xmm1
  __m128 v61; // xmm3
  __m128i v62; // xmm1
  __m128i v63; // xmm2
  __m128i v64; // xmm8
  __m128 *v65; // rax
  __m128 *v66; // r9
  __m128 v67; // xmm7
  __m128 v68; // xmm9
  __m128 v69; // xmm1
  __m128 v70; // xmm4
  __m128 v71; // xmm2
  __m128 v72; // xmm4
  __m128 v73; // xmm4
  __m128i v74; // xmm5
  __m128 v75; // xmm3
  __m128i v76; // xmm1
  __int64 result; // rax
  signed __int64 v78; // rax
  __int64 v79; // [rsp+0h] [rbp-91h]
  __int64 v80; // [rsp+8h] [rbp-89h]
  int v81; // [rsp+10h] [rbp-81h]
  char v82; // [rsp+18h] [rbp-79h]
  __int64 v83; // [rsp+20h] [rbp-71h]
  float retaddr; // [rsp+F8h] [rbp+67h]

  v1 = 0;
  v2 = 0i64;
  v3 = 4i64;
  v4 = resultPointArray;
  v79 = 0i64;
  v80 = 0i64;
  v81 = 0;
  retaddr = 0.0;
  v5 = (__m128)xmmword_141A712A0;
  v6 = 4i64;
  v7 = _mm_load_si128((const __m128i *)&xmmword_141A72090);
  v8 = (__m128 *)&v83;
  v9.m_quad = (__m128)resultPointArray[4].m_contact.m_position;
  v10 = 0i64;
  v11 = 0i64;
  v12 = 0i64;
  v13 = 0i64;
  do
  {
    ++resultPointArray;
    ++v8;
    v14 = _mm_sub_ps(v9.m_quad, resultPointArray[-1].m_contact.m_position.m_quad);
    v15 = _mm_mul_ps(v14, v14);
    v16 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170));
    v17 = (__m128i)_mm_cmpltps(v10, v16);
    v10 = _mm_max_ps(v10, v16);
    v8[-1] = v16;
    v18 = _mm_and_si128(v11, v17);
    v19 = _mm_andnot_si128(v17, v13);
    v20 = (__m128i)_mm_cmpltps(v16, v5);
    v13 = _mm_or_si128(v19, v18);
    v21 = _mm_and_si128(v11, v20);
    v11 = _mm_add_epi32(v11, v7);
    v5 = _mm_min_ps(v5, v16);
    v12 = _mm_or_si128(_mm_andnot_si128(v20, v12), v21);
    --v6;
  }
  while ( v6 );
  v22 = v12.m128i_i32[0];
  v23 = 0i64;
  v24 = _mm_shuffle_ps(v4[4].m_contact.m_separatingNormal.m_quad, v4[4].m_contact.m_separatingNormal.m_quad, 255);
  v25 = v22;
  *((_DWORD *)&v79 + v13.m128i_i32[0]) = 1;
  v26 = 0i64;
  v27 = v4[v25].m_contact.m_separatingNormal.m_quad;
  v28 = &v4->m_contact.m_position.m_quad;
  v29 = v24.m128_f32[0] - COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 255));
  retaddr = FLOAT_1_05;
  v30 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_1_05), (__m128)LODWORD(FLOAT_1_05), 0), v10);
  v31 = 0i64;
  do
  {
    if ( !*((_DWORD *)&v79 + v26) )
    {
      v32 = _mm_sub_ps(v4[v13.m128i_i32[0]].m_contact.m_position.m_quad, *v28);
      v33 = _mm_mul_ps(v32, v32);
      v34 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
              _mm_shuffle_ps(v33, v33, 170));
      v35 = v31;
      v36 = (__m128i)_mm_cmpltps(v30, v34);
      v31 = _mm_add_epi32(v31, v7);
      v30 = _mm_max_ps(v30, v34);
      v23 = _mm_or_si128(_mm_andnot_si128(v36, v23), _mm_and_si128(v35, v36));
    }
    ++v26;
    v28 += 3;
  }
  while ( v26 < 5 );
  v37 = v4[v13.m128i_i32[0]].m_contact.m_position.m_quad;
  retaddr = 0.0;
  v38 = 0i64;
  *((_DWORD *)&v79 + v23.m128i_i32[0]) = 1;
  v39 = v23.m128i_i32[0];
  v40 = &v4->m_contact.m_position.m_quad;
  v41 = 0i64;
  v42 = 0i64;
  v43 = _mm_sub_ps(v37, v4[v39].m_contact.m_position.m_quad);
  v44 = 0i64;
  do
  {
    if ( !*((_DWORD *)&v79 + v44) )
    {
      v45 = _mm_sub_ps(*v40, v37);
      v46 = _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v45);
      v47 = _mm_shuffle_ps(v45, v45, 201);
      v48 = v41;
      v41 = _mm_add_epi32(v41, v7);
      v49 = _mm_sub_ps(v46, _mm_mul_ps(v47, v43));
      v50 = _mm_shuffle_ps(v49, v49, 201);
      v51 = _mm_mul_ps(v50, v50);
      v52 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
              _mm_shuffle_ps(v51, v51, 170));
      v53 = (__m128i)_mm_cmpltps(v38, v52);
      v38 = _mm_max_ps(v38, v52);
      v42 = _mm_or_si128(_mm_andnot_si128(v53, v42), _mm_and_si128(v48, v53));
    }
    ++v44;
    v40 += 3;
  }
  while ( v44 < 5 );
  v54 = 0i64;
  retaddr = 0.0;
  v55 = 0i64;
  v56 = 0i64;
  *((_DWORD *)&v79 + v42.m128i_i32[0]) = 1;
  v57 = 0i64;
  v58 = &v4->m_contact.m_position.m_quad;
  do
  {
    if ( !*((_DWORD *)&v79 + v57) )
    {
      v59 = _mm_sub_ps(v4[v42.m128i_i32[0]].m_contact.m_position.m_quad, *v58);
      v60 = _mm_mul_ps(v59, v59);
      v61 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v60, v60, 85), _mm_shuffle_ps(v60, v60, 0)),
              _mm_shuffle_ps(v60, v60, 170));
      v62 = v55;
      v63 = (__m128i)_mm_cmpltps(v54, v61);
      v55 = _mm_add_epi32(v55, v7);
      v54 = _mm_max_ps(v54, v61);
      v56 = _mm_or_si128(_mm_andnot_si128(v63, v56), _mm_and_si128(v62, v63));
    }
    ++v57;
    v58 += 3;
  }
  while ( v57 < 5 );
  retaddr = FLOAT_526_0;
  *((_DWORD *)&v79 + v56.m128i_i32[0]) = 1;
  if ( v81
    || v29 >= 0.0
    || v5.m128_f32[0] >= (float)((float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_526_0), (__m128)LODWORD(FLOAT_526_0), 0))
                                       * v29)
                               * v29) )
  {
    v78 = 0i64;
    while ( *((_DWORD *)&v79 + v78) )
    {
      ++v78;
      ++v1;
      if ( v78 >= 5 )
        return 0i64;
    }
    result = v1;
  }
  else
  {
    v64 = _mm_load_si128((const __m128i *)&_xmm);
    v65 = (__m128 *)&v82;
    v66 = &v4->m_contact.m_separatingNormal.m_quad;
    v67 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_030461743), (__m128)LODWORD(FLOAT_0_030461743), 0);
    retaddr = FLOAT_9_9999997eN10;
    v68 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_9_9999997eN10), (__m128)LODWORD(FLOAT_9_9999997eN10), 0);
    do
    {
      v69 = *v65;
      v70 = *v66;
      v66 += 3;
      ++v65;
      v71 = _mm_rcp_ps(v69);
      v72 = _mm_sub_ps(_mm_shuffle_ps(v70, v70, 255), v24);
      v73 = _mm_add_ps(_mm_mul_ps(v72, v72), v68);
      v74 = (__m128i)_mm_cmpltps(_mm_mul_ps(v67, v69), v73);
      v75 = _mm_andnot_ps(
              _mm_cmpeqps((__m128)0i64, v69),
              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v71, v69)), v71), v73));
      v76 = v2;
      v2 = _mm_add_epi32(v2, v7);
      v67 = _mm_or_ps(_mm_and_ps(v75, (__m128)v74), _mm_andnot_ps((__m128)v74, v67));
      v64 = _mm_or_si128(_mm_andnot_si128(v74, v64), _mm_and_si128(v76, v74));
      --v3;
    }
    while ( v3 );
    result = v64.m128i_u32[0];
  }
  return result;
}

// File Line: 928
// RVA: 0xDBC650
signed __int64 __fastcall hkGskManifold_addPoint(hkpGskManifold *manifold, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *output, hkpGskCache *newPoint, hkpProcessCdPoint *newCdPointInResultArray, hkpProcessCdPoint *resultPointArray, hkpContactMgr *mgr, hkpGskManifoldUtilMgrHandling mgrHandling)
{
  hkpProcessCollisionInput *v10; // r12
  hkpCdBody *v11; // r13
  hkpGskManifold *v12; // rbx
  int v13; // eax
  __int64 v14; // rsi
  __int64 v16; // r14
  hkpGskManifold::ContactPoint v17; // rax
  unsigned __int16 v18; // r10
  __int64 v19; // rcx
  int v20; // eax
  int v21; // er8
  signed __int64 v22; // r9
  signed __int64 v23; // rdx
  int v24; // er8
  signed __int64 v25; // r9
  int v26; // eax
  hkpProcessCdPoint *v27; // rcx
  hkpProcessCdPoint *v28; // rcx
  hkpGskCache *v29; // rsi
  __int64 v30; // r11
  int v31; // er9
  signed __int64 v32; // r8
  char *i; // rdx
  signed int v34; // er12
  $E9208155A816D87A00BF14BF7053E465 *v35; // r15
  char v36; // al
  int v37; // edi
  signed int v38; // ebp
  signed __int64 v39; // r9
  hkpGskCache *v40; // r14
  unsigned int v41; // ecx
  unsigned __int16 v42; // r11
  unsigned int v43; // edx
  __int64 v44; // r8
  signed __int64 v45; // r10
  unsigned int v46; // er10
  hkpGskManifold::ContactPoint *v47; // r8
  __int64 v48; // rdx
  __int64 v49; // r10
  int v50; // ecx
  int v51; // edx
  unsigned __int16 v52; // r8
  __int64 v53; // rdx
  unsigned int v54; // [rsp+80h] [rbp+8h]
  hkpCdBody *v55; // [rsp+88h] [rbp+10h]

  v55 = bodyA;
  v10 = input;
  v11 = bodyB;
  v12 = manifold;
  v54 = 4;
  if ( manifold->m_numContactPoints == 4 )
  {
    v13 = hkGskManifold_findRedundant5thPoint(resultPointArray);
    v14 = v13;
    v54 = v13;
    if ( v13 == 4 )
      return 5i64;
    v16 = v13;
    ((void (__fastcall *)(hkpContactMgr *, _QWORD, hkpConstraintOwner *))mgr->vfptr[2].__first_virtual_table_function__)(
      mgr,
      v12->m_contactPoints[v13].m_id,
      output->m_constraintOwner.m_storage);
    if ( (_DWORD)v14 )
      v17 = v12->m_contactPoints[0];
    else
      v17 = v12->m_contactPoints[1];
    v12->m_contactPoints[v14] = v17;
    hkGskManifold_garbageCollect(v12);
    v18 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, hkpGskCache *, hkpProcessCdPoint *))mgr->vfptr[1].__first_virtual_table_function__)(
            mgr,
            v55,
            v11,
            v10,
            output,
            newPoint,
            newCdPointInResultArray);
    if ( v18 == -1 )
    {
      v12->m_contactPoints[0] = v12->m_contactPoints[3];
      v19 = (unsigned __int8)v12->m_numContactPoints;
      v20 = v19 - 1;
      v21 = (unsigned __int8)v12->m_numVertsA - 1;
      v22 = (signed __int64)&v12->m_contactPoints[v19];
      LODWORD(v19) = (unsigned __int8)v12->m_numVertsB;
      v12->m_numContactPoints = v20;
      v23 = (signed __int64)&v12->m_contactPoints[v20];
      v24 = ((signed int)v19 + v21) >> 1;
      if ( v24 >= 0 )
      {
        v25 = v22 - v23;
        do
        {
          --v24;
          v26 = *(_DWORD *)(v25 + v23);
          v23 += 4i64;
          *(_DWORD *)(v23 - 4) = v26;
        }
        while ( v24 >= 0 );
      }
      v27 = &resultPointArray[v16];
      v27->m_contact.m_position = resultPointArray[3].m_contact.m_position;
      v27->m_contact.m_separatingNormal = resultPointArray[3].m_contact.m_separatingNormal;
      v27->m_contactPointId = resultPointArray[3].m_contactPointId;
      v27->m_padding[0] = resultPointArray[3].m_padding[0];
      v27->m_padding[1] = resultPointArray[3].m_padding[1];
      v27->m_padding[2] = resultPointArray[3].m_padding[2];
      return 6i64;
    }
    newCdPointInResultArray->m_contactPointId = v18;
    v28 = &resultPointArray[v16];
    v28->m_contact.m_position = newCdPointInResultArray->m_contact.m_position;
    v28->m_contact.m_separatingNormal = newCdPointInResultArray->m_contact.m_separatingNormal;
    v28->m_contactPointId = newCdPointInResultArray->m_contactPointId;
    v28->m_padding[0] = newCdPointInResultArray->m_padding[0];
    v28->m_padding[1] = newCdPointInResultArray->m_padding[1];
    v29 = newPoint;
    v28->m_padding[2] = newCdPointInResultArray->m_padding[2];
  }
  else
  {
    v29 = newPoint;
    if ( mgrHandling && newPoint->m_dimB != 3 )
    {
      v18 = -1;
    }
    else
    {
      v18 = ((__int64 (__cdecl *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *))mgr->vfptr[1].__first_virtual_table_function__)(
              mgr,
              bodyA,
              bodyB);
      if ( v18 == -1 )
        return 5i64;
    }
    newCdPointInResultArray->m_contactPointId = v18;
    v30 = (unsigned __int8)v12->m_numContactPoints;
    v31 = ((unsigned __int8)v12->m_numVertsB + (unsigned __int8)v12->m_numVertsA - 1) >> 1;
    v32 = (signed __int64)v12 + 4 * (2i64 * ((signed int)v30 + 1) + 1 + v31);
    for ( i = &v12->m_numVertsA + 4 * (v31 + 2 * v30 + 1); v31 >= 0; i -= 4 )
    {
      v32 -= 4i64;
      --v31;
      *(_DWORD *)(v32 + 4) = *(_DWORD *)i;
    }
    v12->m_contactPoints[v30] = v12->m_contactPoints[0];
    v12->m_numContactPoints = v30 + 1;
  }
  v34 = 0;
  v35 = &v12->m_contactPoints[0].4;
  v12->m_contactPoints[0].m_dimA = v29->m_dimA;
  v36 = v29->m_dimB;
  v12->m_contactPoints[0].m_allVerts = 0;
  v12->m_contactPoints[0].m_id = v18;
  v12->m_contactPoints[0].m_dimB = v36;
  v37 = 0;
  v38 = 0;
  v39 = (signed __int64)&v12->m_contactPoints[(unsigned __int8)v12->m_numContactPoints];
  if ( v29->m_dimA )
  {
    v40 = v29;
    do
    {
      v41 = (unsigned __int8)v12->m_numVertsA;
      v42 = v40->m_vertices[0];
      v43 = 0;
      if ( v12->m_numVertsA )
      {
        while ( *(_WORD *)(v39 + 2i64 * v43) != v42 )
        {
          if ( ++v43 >= v41 )
            goto LABEL_25;
        }
      }
      else
      {
LABEL_25:
        v44 = v41 + (unsigned __int8)v12->m_numVertsB;
        if ( (unsigned int)v44 > v43 )
        {
          v45 = v39 + 2 * v44;
          do
          {
            v44 = (unsigned int)(v44 - 1);
            v45 -= 2i64;
            *(_WORD *)(v45 + 2) = *(_WORD *)(v39 + 2 * v44);
          }
          while ( (unsigned int)v44 > v43 );
        }
        *(_WORD *)(v39 + 2i64 * v43) = v42;
        ++v12->m_numVertsA;
        v37 += 16;
      }
      ++v38;
      v40 = (hkpGskCache *)((char *)v40 + 2);
      v35->m_vert[0] = 16 * v43;
      v35 = ($E9208155A816D87A00BF14BF7053E465 *)((char *)v35 + 1);
    }
    while ( v38 < (unsigned __int8)v29->m_dimA );
    if ( v37 )
    {
      v46 = 1;
      v47 = &v12->m_contactPoints[1];
      if ( v12->m_numContactPoints > 1u )
      {
        do
        {
          v48 = (unsigned __int8)v47->m_dimA;
          if ( (unsigned int)v48 < (unsigned int)v48 + (unsigned __int8)v47->m_dimB )
          {
            do
            {
              v47->m_vert[v48] += v37;
              v48 = (unsigned int)(v48 + 1);
            }
            while ( (unsigned int)v48 < (unsigned __int8)v47->m_dimA + (unsigned int)(unsigned __int8)v47->m_dimB );
          }
          ++v46;
          ++v47;
        }
        while ( v46 < (unsigned __int8)v12->m_numContactPoints );
      }
    }
  }
  v49 = 0i64;
  if ( v29->m_dimB > 0u )
  {
    do
    {
      v50 = (unsigned __int8)v12->m_numVertsA;
      v51 = v50 + (unsigned __int8)v12->m_numVertsB;
      v52 = v29->m_vertices[v49 + (unsigned __int8)v29->m_dimA];
      if ( v50 >= v51 )
      {
LABEL_39:
        *(_WORD *)(v39 + 2i64 * v50) = v52;
        ++v12->m_numVertsB;
      }
      else
      {
        while ( *(_WORD *)(v39 + 2i64 * v50) != v52 )
        {
          if ( ++v50 >= v51 )
            goto LABEL_39;
        }
      }
      ++v34;
      v53 = v49++ + (unsigned __int8)v29->m_dimA;
      v12->m_contactPoints[0].m_vert[v53] = 16 * v50;
    }
    while ( v34 < (unsigned __int8)v29->m_dimB );
  }
  return v54;
} v51 )
            goto LABEL_39;
        }
      }
      ++v34;
      v53 = v49++ + (unsigned __int8)v29->m_dimA;
      v12->m_contactPoints[0].m_vert[v53] = 16 * v50;
    }
    while ( v34 < (unsigned __int8)v29->m_dimB );
  }
  return v5

// File Line: 1138
// RVA: 0xDBCAE0
void __fastcall hkGskManifold_cleanup(hkpGskManifold *manifold, hkpContactMgr *mgr, hkpConstraintOwner *constraintOwner)
{
  __int64 v3; // rbx
  hkpConstraintOwner *v4; // rbp
  hkpContactMgr *v5; // rsi
  hkpGskManifold *v6; // rdi
  __int64 v7; // rdx

  v3 = 0i64;
  v4 = constraintOwner;
  v5 = mgr;
  v6 = manifold;
  if ( manifold->m_numContactPoints )
  {
    do
    {
      v7 = v6->m_contactPoints[v3].m_id;
      if ( (_WORD)v7 != -1 )
        ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))v5->vfptr[2].__first_virtual_table_function__)(
          v5,
          v7,
          v4);
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < (unsigned __int8)v6->m_numContactPoints );
  }
  *(_WORD *)&v6->m_numVertsB = 0;
  v6->m_numVertsA = 0;
}


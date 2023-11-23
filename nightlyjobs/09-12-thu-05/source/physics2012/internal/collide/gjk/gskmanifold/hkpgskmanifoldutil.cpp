// File Line: 96
// RVA: 0xDBCB60
__int64 __fastcall hkGskManifold_convertPointPoint(
        hkpGskManifoldWork *work,
        hkpGskManifold::ContactPoint *feature,
        hkGskManifoldConvertOut *out)
{
  __int64 v3; // r9
  hkVector4f v4; // xmm3
  __m128 v5; // xmm1
  __int64 result; // rax

  v3 = (unsigned __int8)feature->m_vert[0];
  v4.m_quad = _mm_sub_ps(
                *(__m128 *)((char *)&work->m_vertices[0].m_quad + v3),
                *(__m128 *)((char *)&work->m_vertices[0].m_quad + (unsigned __int8)feature->m_vert[1]));
  v5 = _mm_mul_ps(v4.m_quad, v4.m_quad);
  if ( (float)((float)(_mm_shuffle_ps(v5, v5, 85).m128_f32[0] + _mm_shuffle_ps(v5, v5, 0).m128_f32[0])
             + _mm_shuffle_ps(v5, v5, 170).m128_f32[0]) > _mm_shuffle_ps(
                                                            (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                            (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                            0).m128_f32[0] )
    return 10i64;
  out->m_AminusB = (hkVector4f)v4.m_quad;
  result = 5i64;
  out->m_normal = work->m_masterNormal;
  out->m_pointOnA = *(hkVector4f *)((char *)work->m_vertices + v3);
  return result;
}

// File Line: 118
// RVA: 0xDBCBD0
__int64 __fastcall hkGskManifold_convertPointEdge(
        hkpGskManifoldWork *work,
        hkpGskManifold::ContactPoint *feature,
        hkGskManifoldConvertOut *out)
{
  __int64 v3; // r10
  __int64 v4; // r9
  __int64 v5; // rax
  __m128 v6; // xmm6
  __m128 v7; // xmm5
  __m128 v8; // xmm4
  __m128 v9; // xmm5
  __m128 v10; // xmm3
  __m128 v11; // xmm0
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm3
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm4
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __int64 result; // rax
  __m128 v24; // xmm3
  __m128 v25; // xmm4
  __m128 v26; // xmm1

  v3 = (unsigned __int8)feature->m_vert[0];
  v4 = (unsigned __int8)feature->m_vert[1];
  v5 = (unsigned __int8)feature->m_vert[2];
  out->m_pointOnA = *(hkVector4f *)((char *)work->m_vertices + v3);
  out->m_normal = work->m_masterNormal;
  v6 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v3);
  v7 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v5);
  v8 = _mm_sub_ps(v7, v6);
  v9 = _mm_sub_ps(v7, *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4));
  v10 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v9);
  v11 = _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v8);
  v12 = _mm_mul_ps(v8, v9);
  v13 = _mm_sub_ps(v10, v11);
  v14 = _mm_shuffle_ps(v13, v13, 201);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_mul_ps(_mm_sub_ps(v6, *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4)), v9);
  v17 = _mm_unpacklo_ps(v12, v16);
  v18 = _mm_movelh_ps(v17, v15);
  v19 = _mm_shuffle_ps(_mm_unpackhi_ps(v12, v16), v15, 228);
  v20 = _mm_shuffle_ps(_mm_movehl_ps(v18, v17), v15, 212);
  v21 = _mm_mul_ps(v9, v9);
  v22 = _mm_add_ps(v19, _mm_add_ps(v18, v20));
  if ( _mm_shuffle_ps(v22, v22, 170).m128_f32[0] > (float)((float)((float)(_mm_shuffle_ps(v21, v21, 85).m128_f32[0]
                                                                         + _mm_shuffle_ps(v21, v21, 0).m128_f32[0])
                                                                 + _mm_shuffle_ps(v21, v21, 170).m128_f32[0])
                                                         * _mm_shuffle_ps(
                                                             (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                             (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                             0).m128_f32[0]) )
    return 10i64;
  if ( (_mm_movemask_ps(_mm_cmplt_ps(v22, (__m128)0i64)) & 3) != 0 )
    return 6i64;
  result = 5i64;
  v24 = _mm_shuffle_ps(v22, v22, 0);
  v25 = _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), v24);
  v26 = _mm_rcp_ps(v25);
  out->m_AminusB.m_quad = _mm_sub_ps(
                            v6,
                            _mm_add_ps(
                              _mm_mul_ps(
                                v9,
                                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v26, v25)), v26), v24)),
                              *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4)));
  return result;
}

// File Line: 154
// RVA: 0xDBCD10
__int64 __fastcall hkGskManifold_convertEdgePoint(
        hkpGskManifoldWork *work,
        hkpGskManifold::ContactPoint *feature,
        hkGskManifoldConvertOut *out)
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
  __int64 result; // rax
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
  v10 = _mm_sub_ps(v6, v8);
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
  if ( _mm_shuffle_ps(v22, v22, 170).m128_f32[0] > (float)((float)((float)(_mm_shuffle_ps(v17, v17, 85).m128_f32[0]
                                                                         + _mm_shuffle_ps(v17, v17, 0).m128_f32[0])
                                                                 + _mm_shuffle_ps(v17, v17, 170).m128_f32[0])
                                                         * _mm_shuffle_ps(
                                                             (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                             (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                             0).m128_f32[0]) )
    return 10i64;
  if ( (_mm_movemask_ps(_mm_cmplt_ps(v22, (__m128)0i64)) & 3) != 0 )
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
__int64 __fastcall hkGskManifold_convertPointFace(
        hkpGskManifoldWork *work,
        hkpGskManifold::ContactPoint *feature,
        hkGskManifoldConvertOut *out)
{
  __int64 v3; // r11
  __int64 v4; // r10
  __int64 v5; // r9
  __int64 v6; // rax
  __m128 v7; // xmm6
  __m128 v8; // xmm5
  __m128 v9; // xmm4
  __m128 v10; // xmm7
  __m128 v11; // xmm8
  __m128 v12; // xmm13
  __m128 v13; // xmm15
  __m128 v14; // xmm11
  __m128 v15; // xmm14
  __m128 v16; // xmm14
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm10
  __m128 v21; // xmm0
  __m128 v22; // xmm2
  __m128 v23; // xmm9
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __m128 v26; // xmm3
  __m128 v27; // xmm9
  __m128 v28; // xmm1
  __m128 v29; // xmm15
  __m128 v30; // xmm11
  __m128 v31; // xmm13
  __m128 v32; // xmm0
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm13
  __m128 v36; // xmm1
  __m128 v37; // xmm11
  __m128 v38; // xmm15
  __m128 v39; // xmm2
  __m128 v40; // xmm15
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
  v10 = _mm_sub_ps(v7, v9);
  v11 = _mm_sub_ps(v8, v7);
  v12 = _mm_sub_ps(v9, v8);
  v13 = _mm_shuffle_ps(v10, v10, 201);
  v14 = _mm_shuffle_ps(v11, v11, 201);
  v15 = _mm_sub_ps(_mm_mul_ps(v14, v10), _mm_mul_ps(v13, v11));
  v16 = _mm_shuffle_ps(v15, v15, 201);
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  v20 = _mm_cmple_ps(v18, (__m128)0i64);
  v21 = _mm_mul_ps(_mm_mul_ps(v19, v18), v19);
  v22 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v3), v7);
  v23 = _mm_sub_ps((__m128)_xmm, v21);
  v24 = _mm_mul_ps(*(__m128 *)_xmm, v19);
  v25 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v3);
  v26 = _mm_sub_ps(v25, v8);
  v27 = _mm_mul_ps(v23, v24);
  v28 = _mm_sub_ps(v25, v9);
  v29 = _mm_sub_ps(_mm_mul_ps(v13, v28), _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v10));
  v30 = _mm_sub_ps(_mm_mul_ps(v14, v22), _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v11));
  v31 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v26), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v12));
  v32 = _mm_mul_ps(work->m_masterNormal.m_quad, v16);
  v33 = _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v16);
  v34 = _mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v16);
  v35 = _mm_shuffle_ps(v34, v32, 238);
  v36 = _mm_shuffle_ps(v34, v32, 68);
  v37 = _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v16);
  v38 = _mm_shuffle_ps(v33, v37, 238);
  v39 = _mm_shuffle_ps(v33, v37, 68);
  v40 = _mm_add_ps(
          _mm_shuffle_ps(v38, v35, 136),
          _mm_add_ps(_mm_shuffle_ps(v39, v36, 221), _mm_shuffle_ps(v39, v36, 136)));
  result = (unsigned int)((~(unsigned __int8)_mm_movemask_ps(_mm_cmplt_ps(v40, (__m128)0i64)) & 7) != 0) + 17;
  out->m_normal.m_quad = _mm_xor_ps(
                           (__m128)_mm_slli_epi32(
                                     _mm_srli_epi32(
                                       (__m128i)_mm_cmplt_ps(_mm_shuffle_ps(v40, v40, 255), (__m128)0i64),
                                       0x1Fu),
                                     0x1Fu),
                           _mm_mul_ps(_mm_andnot_ps(v20, v27), v16));
  return result;
}

// File Line: 239
// RVA: 0xDBD0A0
__int64 __fastcall hkGskManifold_convertFacePoint(
        hkpGskManifoldWork *work,
        hkpGskManifold::ContactPoint *feature,
        hkGskManifoldConvertOut *out)
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
  __m128 v15; // xmm10
  __m128 v16; // xmm10
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm11
  __m128 v21; // xmm4
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  __m128 v25; // xmm5
  __m128 v26; // xmm12
  __m128 v27; // xmm15
  __m128 v28; // xmm2
  __m128 v29; // xmm13
  __m128 v30; // xmm0
  __m128 v31; // xmm12
  __m128 v32; // xmm5
  __m128 v33; // xmm2
  __m128 v34; // xmm13
  __m128 v35; // xmm1
  __m128 v36; // xmm5
  __int64 result; // rax
  __m128 v38; // [rsp+0h] [rbp-B8h]

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
  v11 = _mm_sub_ps(v8, v9);
  v12 = _mm_sub_ps(v9, v10);
  v13 = _mm_sub_ps(v10, v8);
  v14 = _mm_shuffle_ps(v12, v12, 201);
  v38 = _mm_shuffle_ps(v13, v13, 201);
  v15 = _mm_sub_ps(_mm_mul_ps(v14, v13), _mm_mul_ps(v38, v12));
  v16 = _mm_shuffle_ps(v15, v15, 201);
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  v20 = _mm_mul_ps(
          v16,
          _mm_andnot_ps(
            _mm_cmple_ps(v18, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
              _mm_mul_ps(*(__m128 *)_xmm, v19))));
  v21 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v3);
  v22 = _mm_sub_ps(v21, v8);
  v23 = _mm_sub_ps(v21, v10);
  v24 = _mm_sub_ps(v21, v9);
  v25 = _mm_sub_ps(_mm_mul_ps(v38, v22), _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v13));
  v26 = _mm_sub_ps(_mm_mul_ps(v14, v23), _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v12));
  v27 = _mm_mul_ps(v7.m_quad, v20);
  v28 = _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v16);
  v29 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v24), _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v11));
  v30 = _mm_mul_ps(work->m_masterNormal.m_quad, v16);
  v31 = _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v16);
  v32 = _mm_shuffle_ps(v28, v31, 238);
  v33 = _mm_shuffle_ps(v28, v31, 68);
  v34 = _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v16);
  v35 = _mm_shuffle_ps(v34, v30, 68);
  v36 = _mm_add_ps(
          _mm_shuffle_ps(v32, _mm_shuffle_ps(v34, v30, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v33, v35, 221), _mm_shuffle_ps(v33, v35, 136)));
  result = (unsigned int)((~(unsigned __int8)_mm_movemask_ps(_mm_cmplt_ps(v36, (__m128)0i64)) & 7) != 0) + 17;
  out->m_normal.m_quad = _mm_xor_ps(
                           (__m128)_mm_slli_epi32(
                                     _mm_srli_epi32(
                                       (__m128i)_mm_cmplt_ps(_mm_shuffle_ps(v36, v36, 255), (__m128)0i64),
                                       0x1Fu),
                                     0x1Fu),
                           v20);
  out->m_pointOnA.m_quad = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                                 _mm_shuffle_ps(v27, v27, 170)),
                               v20),
                             v21);
  return result;
}

// File Line: 284
// RVA: 0xDBD310
__int64 __fastcall hkGskManifold_convertEdgeEdge(
        hkpGskManifoldWork *work,
        hkpGskManifold::ContactPoint *feature,
        hkGskManifoldConvertOut *out)
{
  __int64 v3; // r10
  __int64 v4; // r9
  __int64 v5; // r11
  __int64 v6; // rdx
  __m128 *v7; // r11
  __m128 v8; // xmm8
  __m128 v9; // xmm4
  __m128 v10; // xmm9
  __m128 v11; // xmm6
  __m128 v12; // xmm4
  __m128 v13; // xmm8
  __m128 v14; // xmm1
  __m128 v15; // xmm5
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  __m128 v18; // xmm7
  __m128 v19; // xmm3
  __m128 v20; // xmm7
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm7
  __m128 v24; // xmm3
  __m128 v25; // xmm0
  __m128 v26; // xmm7
  __m128 v27; // xmm6
  __m128 v28; // xmm3
  __m128 v29; // xmm1
  __m128 v30; // xmm6
  int v31; // eax
  __int64 result; // rax
  __m128 v33; // xmm4
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm3
  hkVector4f v37; // xmm4
  __m128 v38; // xmm1
  __m128 v39; // xmm2

  v3 = (unsigned __int8)feature->m_vert[1];
  v4 = (unsigned __int8)feature->m_vert[0];
  v5 = (unsigned __int8)feature->m_vert[2];
  v6 = (unsigned __int8)feature->m_vert[3];
  v7 = (__m128 *)((char *)work + v5);
  v8 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4);
  v9 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v3);
  v10 = _mm_sub_ps(v9, *(__m128 *)((char *)&work->m_vertices[0].m_quad + v6));
  v11 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v6), *v7);
  v12 = _mm_sub_ps(v9, v8);
  v13 = _mm_sub_ps(v8, *v7);
  v14 = _mm_shuffle_ps(v12, v12, 201);
  v15 = _mm_shuffle_ps(v11, v11, 201);
  v16 = _mm_sub_ps(_mm_mul_ps(v15, v12), _mm_mul_ps(v14, v11));
  out->m_normal = work->m_masterNormal;
  v17 = _mm_shuffle_ps(v16, v16, 201);
  v18 = _mm_shuffle_ps(v17, v17, 201);
  v19 = _mm_sub_ps(_mm_mul_ps(v18, v11), _mm_mul_ps(v15, v17));
  v20 = _mm_sub_ps(_mm_mul_ps(v18, v12), _mm_mul_ps(v14, v17));
  v21 = _mm_shuffle_ps(v19, v19, 201);
  v22 = _mm_mul_ps(v10, v21);
  v23 = _mm_shuffle_ps(v20, v20, 201);
  v24 = _mm_mul_ps(v21, v13);
  v25 = _mm_mul_ps(v23, v13);
  v26 = _mm_mul_ps(v23, v10);
  v27 = _mm_shuffle_ps(v24, v25, 238);
  v28 = _mm_shuffle_ps(v24, v25, 68);
  v29 = _mm_shuffle_ps(v22, v26, 68);
  v30 = _mm_add_ps(
          _mm_shuffle_ps(v27, _mm_shuffle_ps(v22, v26, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v28, v29, 221), _mm_shuffle_ps(v28, v29, 136)));
  v31 = _mm_movemask_ps(_mm_cmplt_ps(v30, (__m128)0i64));
  if ( v31 != 3 && v31 != 12 )
    return 18i64;
  result = 17i64;
  v33 = _mm_shuffle_ps(v30, v30, 0);
  v34 = _mm_sub_ps(v33, _mm_shuffle_ps(v30, v30, 170));
  v35 = _mm_rcp_ps(v34);
  v36 = _mm_shuffle_ps(v30, v30, 85);
  v37.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(
                     *(__m128 *)((char *)&work->m_vertices[0].m_quad + v3),
                     *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4)),
                   _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v35, v34)), v35), v33)),
                 *(__m128 *)((char *)&work->m_vertices[0].m_quad + v4));
  v38 = _mm_sub_ps(v36, _mm_shuffle_ps(v30, v30, 255));
  out->m_pointOnA = (hkVector4f)v37.m_quad;
  v39 = _mm_rcp_ps(v38);
  out->m_AminusB.m_quad = _mm_sub_ps(
                            v37.m_quad,
                            _mm_add_ps(
                              _mm_mul_ps(
                                _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v6), *v7),
                                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v39, v38)), v39), v36)),
                              *v7));
  return result;
}

// File Line: 323
// RVA: 0xDBD4C0
__int64 __fastcall hkGskManifold_convertFeature(
        hkpGskManifoldWork *work,
        hkpGskManifold::ContactPoint *feature,
        hkGskManifoldConvertOut *out)
{
  __int64 v6; // rcx
  hkVector4f v7; // xmm3
  __m128 v8; // xmm1
  __int64 result; // rax
  __int64 v10; // rdx
  __int64 v11; // rcx
  __int64 v12; // rax
  __m128 v13; // xmm7
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  __m128 v16; // xmm2
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm3
  __m128 v20; // xmm3
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm4
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm1
  __int64 v31; // r8
  __int64 v32; // rdx
  __int64 v33; // rcx
  __int64 v34; // rax
  __m128 v35; // xmm6
  __m128 v36; // xmm5
  __m128 v37; // xmm4
  __m128 v38; // xmm7
  __m128 v39; // xmm15
  __m128 v40; // xmm8
  __m128 v41; // xmm13
  __m128 v42; // xmm11
  __m128 v43; // xmm14
  __m128 v44; // xmm14
  __m128 v45; // xmm1
  __m128 v46; // xmm2
  __m128 v47; // xmm1
  __m128 v48; // xmm10
  __m128 v49; // xmm0
  __m128 v50; // xmm2
  __m128 v51; // xmm9
  __m128 v52; // xmm0
  __m128 v53; // xmm1
  __m128 v54; // xmm3
  __m128 v55; // xmm9
  __m128 v56; // xmm1
  __m128 v57; // xmm15
  __m128 v58; // xmm11
  __m128 v59; // xmm15
  __m128 v60; // xmm11
  __m128 v61; // xmm13
  __m128 v62; // xmm0
  __m128 v63; // xmm2
  __m128 v64; // xmm1
  __m128 v65; // xmm13
  __m128 v66; // xmm1
  __m128 v67; // xmm15
  __int64 v68; // rax
  __int64 v69; // rcx
  __int64 v70; // rdx
  __m128 v71; // xmm7
  __m128 v72; // xmm6
  __m128 v73; // xmm2
  __m128 v74; // xmm4
  __m128 v75; // xmm5
  __m128 v76; // xmm0
  __m128 v77; // xmm2
  __m128 v78; // xmm3
  __m128 v79; // xmm5
  __m128 v80; // xmm1
  __m128 v81; // xmm3
  __m128 v82; // xmm4
  __m128 v83; // xmm3
  __m128 v84; // xmm3
  __m128 v85; // xmm5
  __m128 v86; // xmm2
  __m128 v87; // xmm5
  __m128 v88; // xmm3
  __m128 v89; // xmm5
  __m128 v90; // xmm1
  hkVector4f v91; // xmm6
  __int64 v92; // rcx
  __int64 v93; // rax
  __int64 v94; // r8
  __m128 v95; // xmm5
  __m128 *v96; // rdx
  __m128 v97; // xmm8
  __m128 v98; // xmm6
  __m128 v99; // xmm7
  __m128 v100; // xmm8
  __m128 v101; // xmm5
  __m128 v102; // xmm2
  __m128 v103; // xmm4
  __m128 v104; // xmm3
  __m128 v105; // xmm3
  __m128 v106; // xmm1
  __m128 v107; // xmm8
  __m128 v108; // xmm7
  __m128 v109; // xmm7
  __m128 v110; // xmm8
  __m128 v111; // xmm0
  __m128 v112; // xmm9
  __m128 v113; // xmm7
  __m128 v114; // xmm2
  __m128 v115; // xmm8
  __m128 v116; // xmm1
  __m128 v117; // xmm9
  int v118; // r9d
  __m128 v119; // xmm4
  __m128 v120; // xmm1
  __m128 v121; // xmm2
  __m128 v122; // xmm3
  __m128 v123; // xmm2
  __m128 v124; // xmm1
  __m128 v125; // xmm0
  hkVector4f v126; // xmm4
  __int64 v127; // r8
  __int64 v128; // rdx
  __int64 v129; // rcx
  __int64 v130; // rax
  hkVector4f v131; // xmm0
  __m128 v132; // xmm8
  __m128 v133; // xmm7
  __m128 v134; // xmm5
  __m128 v135; // xmm9
  __m128 v136; // xmm11
  __m128 v137; // xmm6
  __m128 v138; // xmm10
  __m128 v139; // xmm15
  __m128 v140; // xmm12
  __m128 v141; // xmm12
  __m128 v142; // xmm1
  __m128 v143; // xmm3
  __m128 v144; // xmm2
  __m128 v145; // xmm13
  __m128 v146; // xmm4
  __m128 v147; // xmm14
  __m128 v148; // xmm3
  __m128 v149; // xmm1
  __m128 v150; // xmm14
  __m128 v151; // xmm3
  __m128 v152; // xmm3
  __m128 v153; // xmm15
  __m128 v154; // xmm2
  __m128 v155; // xmm14
  __m128 v156; // xmm0
  __m128 v157; // xmm2
  __m128 v158; // xmm15
  __m128 v159; // xmm1
  __m128 v160; // xmm14
  __m128 v161; // xmm1
  __m128 m_quad; // [rsp+0h] [rbp-B8h]

  switch ( (unsigned __int8)feature->m_dimB + 4 * (unsigned __int8)feature->m_dimA )
  {
    case 5:
      v6 = (unsigned __int8)feature->m_vert[0];
      v7.m_quad = _mm_sub_ps(
                    *(__m128 *)((char *)&work->m_vertices[0].m_quad + v6),
                    *(__m128 *)((char *)&work->m_vertices[0].m_quad + (unsigned __int8)feature->m_vert[1]));
      v8 = _mm_mul_ps(v7.m_quad, v7.m_quad);
      if ( (float)((float)(_mm_shuffle_ps(v8, v8, 85).m128_f32[0] + _mm_shuffle_ps(v8, v8, 0).m128_f32[0])
                 + _mm_shuffle_ps(v8, v8, 170).m128_f32[0]) > _mm_shuffle_ps(
                                                                (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                0).m128_f32[0] )
        goto $LN1_62;
      out->m_AminusB = (hkVector4f)v7.m_quad;
      result = 5i64;
      out->m_normal = work->m_masterNormal;
      out->m_pointOnA = *(hkVector4f *)((char *)work->m_vertices + v6);
      break;
    case 6:
      v10 = (unsigned __int8)feature->m_vert[0];
      v11 = (unsigned __int8)feature->m_vert[1];
      v12 = (unsigned __int8)feature->m_vert[2];
      out->m_pointOnA = *(hkVector4f *)((char *)work->m_vertices + v10);
      out->m_normal = work->m_masterNormal;
      v13 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v11);
      v14 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v10);
      v15 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v12), v13);
      v16 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v12), v14);
      v17 = _mm_mul_ps(v15, v16);
      v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v16));
      v19 = _mm_shuffle_ps(v18, v18, 201);
      v20 = _mm_mul_ps(v19, v19);
      v21 = _mm_mul_ps(_mm_sub_ps(v14, v13), v15);
      v22 = _mm_unpacklo_ps(v17, v21);
      v23 = _mm_movelh_ps(v22, v20);
      v24 = _mm_shuffle_ps(_mm_unpackhi_ps(v17, v21), v20, 228);
      v25 = _mm_shuffle_ps(_mm_movehl_ps(v23, v22), v20, 212);
      v26 = _mm_mul_ps(v15, v15);
      v27 = _mm_add_ps(v24, _mm_add_ps(v23, v25));
      if ( _mm_shuffle_ps(v27, v27, 170).m128_f32[0] > (float)((float)((float)(_mm_shuffle_ps(v26, v26, 85).m128_f32[0]
                                                                             + _mm_shuffle_ps(v26, v26, 0).m128_f32[0])
                                                                     + _mm_shuffle_ps(v26, v26, 170).m128_f32[0])
                                                             * _mm_shuffle_ps(
                                                                 (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                 (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                 0).m128_f32[0]) )
        goto $LN1_62;
      if ( (_mm_movemask_ps(_mm_cmplt_ps(v27, (__m128)0i64)) & 3) != 0 )
        goto LABEL_6;
      result = 5i64;
      v28 = _mm_shuffle_ps(v27, v27, 0);
      v29 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), v28);
      v30 = _mm_rcp_ps(v29);
      out->m_AminusB.m_quad = _mm_sub_ps(
                                v14,
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    v15,
                                    _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v30, v29)), v30), v28)),
                                  v13));
      break;
    case 7:
      v31 = (unsigned __int8)feature->m_vert[0];
      v32 = (unsigned __int8)feature->m_vert[1];
      v33 = (unsigned __int8)feature->m_vert[2];
      v34 = (unsigned __int8)feature->m_vert[3];
      out->m_pointOnA = *(hkVector4f *)((char *)work->m_vertices + v31);
      out->m_AminusB.m_quad = _mm_sub_ps(
                                *(__m128 *)((char *)&work->m_vertices[0].m_quad + v31),
                                *(__m128 *)((char *)&work->m_vertices[0].m_quad + v32));
      v35 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v34);
      v36 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v32);
      v37 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v33);
      v38 = _mm_sub_ps(v35, v37);
      v39 = _mm_shuffle_ps(v38, v38, 201);
      v40 = _mm_sub_ps(v36, v35);
      v41 = _mm_sub_ps(v37, v36);
      v42 = _mm_shuffle_ps(v40, v40, 201);
      v43 = _mm_sub_ps(_mm_mul_ps(v42, v38), _mm_mul_ps(v39, v40));
      v44 = _mm_shuffle_ps(v43, v43, 201);
      v45 = _mm_mul_ps(v44, v44);
      v46 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
              _mm_shuffle_ps(v45, v45, 170));
      v47 = _mm_rsqrt_ps(v46);
      v48 = _mm_cmple_ps(v46, (__m128)0i64);
      v49 = _mm_mul_ps(_mm_mul_ps(v47, v46), v47);
      v50 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v31), v35);
      v51 = _mm_sub_ps((__m128)_xmm, v49);
      v52 = _mm_mul_ps(*(__m128 *)_xmm, v47);
      v53 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v31);
      v54 = _mm_sub_ps(v53, v36);
      v55 = _mm_mul_ps(v51, v52);
      v56 = _mm_sub_ps(v53, v37);
      v57 = _mm_sub_ps(_mm_mul_ps(v39, v56), _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v38));
      v58 = _mm_sub_ps(_mm_mul_ps(v42, v50), _mm_mul_ps(_mm_shuffle_ps(v50, v50, 201), v40));
      v59 = _mm_mul_ps(_mm_shuffle_ps(v57, v57, 201), v44);
      v60 = _mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), v44);
      v61 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v54), _mm_mul_ps(_mm_shuffle_ps(v54, v54, 201), v41));
      v62 = _mm_mul_ps(work->m_masterNormal.m_quad, v44);
      v63 = _mm_shuffle_ps(v59, v60, 68);
      v64 = _mm_mul_ps(_mm_shuffle_ps(v61, v61, 201), v44);
      v65 = _mm_shuffle_ps(v64, v62, 238);
      v66 = _mm_shuffle_ps(v64, v62, 68);
      v67 = _mm_add_ps(
              _mm_shuffle_ps(_mm_shuffle_ps(v59, v60, 238), v65, 136),
              _mm_add_ps(_mm_shuffle_ps(v63, v66, 221), _mm_shuffle_ps(v63, v66, 136)));
      result = (unsigned int)((~(unsigned __int8)_mm_movemask_ps(_mm_cmplt_ps(v67, (__m128)0i64)) & 7) != 0) + 17;
      out->m_normal.m_quad = _mm_xor_ps(
                               (__m128)_mm_slli_epi32(
                                         _mm_srli_epi32(
                                           (__m128i)_mm_cmplt_ps(_mm_shuffle_ps(v67, v67, 255), (__m128)0i64),
                                           0x1Fu),
                                         0x1Fu),
                               _mm_mul_ps(_mm_andnot_ps(v48, v55), v44));
      break;
    case 9:
      v68 = (unsigned __int8)feature->m_vert[1];
      v69 = (unsigned __int8)feature->m_vert[0];
      v70 = (unsigned __int8)feature->m_vert[2];
      out->m_normal = work->m_masterNormal;
      v71 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v68);
      v72 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v69);
      v73 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v70);
      v74 = _mm_sub_ps(v71, v72);
      v75 = _mm_sub_ps(v71, v73);
      v76 = _mm_mul_ps(_mm_shuffle_ps(v74, v74, 201), v75);
      v77 = _mm_mul_ps(_mm_sub_ps(v73, v72), v74);
      v78 = _mm_shuffle_ps(v75, v75, 201);
      v79 = _mm_mul_ps(v75, v74);
      v80 = _mm_unpacklo_ps(v79, v77);
      v81 = _mm_sub_ps(_mm_mul_ps(v78, v74), v76);
      v82 = _mm_mul_ps(v74, v74);
      v83 = _mm_shuffle_ps(v81, v81, 201);
      v84 = _mm_mul_ps(v83, v83);
      v85 = _mm_shuffle_ps(_mm_unpackhi_ps(v79, v77), v84, 228);
      v86 = _mm_movelh_ps(v80, v84);
      v87 = _mm_add_ps(v85, _mm_add_ps(v86, _mm_shuffle_ps(_mm_movehl_ps(v86, v80), v84, 212)));
      if ( _mm_shuffle_ps(v87, v87, 170).m128_f32[0] > (float)((float)((float)(_mm_shuffle_ps(v82, v82, 85).m128_f32[0]
                                                                             + _mm_shuffle_ps(v82, v82, 0).m128_f32[0])
                                                                     + _mm_shuffle_ps(v82, v82, 170).m128_f32[0])
                                                             * _mm_shuffle_ps(
                                                                 (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                 (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                 0).m128_f32[0]) )
        goto $LN1_62;
      if ( (_mm_movemask_ps(_mm_cmplt_ps(v87, (__m128)0i64)) & 3) != 0 )
      {
LABEL_6:
        result = 6i64;
      }
      else
      {
        result = 5i64;
        v88 = _mm_shuffle_ps(v87, v87, 0);
        v89 = _mm_add_ps(_mm_shuffle_ps(v87, v87, 85), v88);
        v90 = _mm_rcp_ps(v89);
        v91.m_quad = _mm_add_ps(
                       _mm_mul_ps(
                         _mm_sub_ps(v72, v71),
                         _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v90, v89)), v90), v88)),
                       v71);
        out->m_pointOnA = (hkVector4f)v91.m_quad;
        out->m_AminusB.m_quad = _mm_sub_ps(v91.m_quad, *(__m128 *)((char *)&work->m_vertices[0].m_quad + v70));
      }
      break;
    case 0xA:
      v92 = (unsigned __int8)feature->m_vert[1];
      v93 = (unsigned __int8)feature->m_vert[0];
      v94 = (unsigned __int8)feature->m_vert[3];
      v95 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v93);
      v96 = (__m128 *)((char *)work + (unsigned __int8)feature->m_vert[2]);
      v97 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v92);
      v98 = _mm_sub_ps(v97, *(__m128 *)((char *)&work->m_vertices[0].m_quad + v94));
      v99 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v94), *v96);
      v100 = _mm_sub_ps(v97, v95);
      v101 = _mm_sub_ps(v95, *v96);
      v102 = _mm_shuffle_ps(v100, v100, 201);
      v103 = _mm_shuffle_ps(v99, v99, 201);
      v104 = _mm_sub_ps(_mm_mul_ps(v100, v103), _mm_mul_ps(v99, v102));
      v105 = _mm_shuffle_ps(v104, v104, 201);
      v106 = _mm_shuffle_ps(v105, v105, 201);
      v107 = _mm_sub_ps(_mm_mul_ps(v100, v106), _mm_mul_ps(v105, v102));
      v108 = _mm_sub_ps(_mm_mul_ps(v99, v106), _mm_mul_ps(v105, v103));
      out->m_normal = work->m_masterNormal;
      v109 = _mm_shuffle_ps(v108, v108, 201);
      v110 = _mm_shuffle_ps(v107, v107, 201);
      v111 = _mm_mul_ps(v110, v101);
      v112 = _mm_mul_ps(v109, v101);
      v113 = _mm_mul_ps(v109, v98);
      v114 = _mm_shuffle_ps(v112, v111, 68);
      v115 = _mm_mul_ps(v110, v98);
      v116 = _mm_shuffle_ps(v113, v115, 68);
      v117 = _mm_add_ps(
               _mm_shuffle_ps(_mm_shuffle_ps(v112, v111, 238), _mm_shuffle_ps(v113, v115, 238), 136),
               _mm_add_ps(_mm_shuffle_ps(v114, v116, 221), _mm_shuffle_ps(v114, v116, 136)));
      v118 = _mm_movemask_ps(_mm_cmplt_ps(v117, (__m128)0i64));
      if ( v118 == 3 || v118 == 12 )
      {
        v119 = _mm_shuffle_ps(v117, v117, 0);
        v120 = _mm_sub_ps(v119, _mm_shuffle_ps(v117, v117, 170));
        v121 = _mm_rcp_ps(v120);
        v122 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v121, v120)), v121), v119);
        v123 = _mm_shuffle_ps(v117, v117, 85);
        v124 = _mm_sub_ps(v123, _mm_shuffle_ps(v117, v117, 255));
        v125 = _mm_rcp_ps(v124);
        v126.m_quad = _mm_add_ps(
                        _mm_mul_ps(
                          _mm_sub_ps(
                            *(__m128 *)((char *)&work->m_vertices[0].m_quad + v92),
                            *(__m128 *)((char *)&work->m_vertices[0].m_quad + v93)),
                          v122),
                        *(__m128 *)((char *)&work->m_vertices[0].m_quad + v93));
        result = 17i64;
        out->m_pointOnA = (hkVector4f)v126.m_quad;
        out->m_AminusB.m_quad = _mm_sub_ps(
                                  v126.m_quad,
                                  _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v94), *v96),
                                      _mm_mul_ps(
                                        _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v124, v125)), v125),
                                        v123)),
                                    *v96));
      }
      else
      {
        result = 18i64;
      }
      break;
    case 0xD:
      v127 = (unsigned __int8)feature->m_vert[3];
      v128 = (unsigned __int8)feature->m_vert[0];
      v129 = (unsigned __int8)feature->m_vert[1];
      v130 = (unsigned __int8)feature->m_vert[2];
      out->m_pointOnA = *(hkVector4f *)((char *)work->m_vertices + v127);
      v131.m_quad = _mm_sub_ps(
                      *(__m128 *)((char *)&work->m_vertices[0].m_quad + v128),
                      *(__m128 *)((char *)&work->m_vertices[0].m_quad + v127));
      out->m_AminusB = (hkVector4f)v131.m_quad;
      v132 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v130);
      v133 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v128);
      v134 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v129);
      m_quad = v131.m_quad;
      v135 = _mm_sub_ps(v132, v134);
      v136 = _mm_sub_ps(v133, v132);
      v137 = _mm_shuffle_ps(v135, v135, 201);
      v138 = _mm_shuffle_ps(v136, v136, 201);
      v139 = _mm_sub_ps(v134, v133);
      v140 = _mm_sub_ps(_mm_mul_ps(v135, v138), _mm_mul_ps(v136, v137));
      v141 = _mm_shuffle_ps(v140, v140, 201);
      v142 = _mm_mul_ps(v141, v141);
      v143 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v142, v142, 85), _mm_shuffle_ps(v142, v142, 0)),
               _mm_shuffle_ps(v142, v142, 170));
      v144 = _mm_rsqrt_ps(v143);
      v145 = _mm_mul_ps(
               v141,
               _mm_andnot_ps(
                 _mm_cmple_ps(v143, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v144, v143), v144)),
                   _mm_mul_ps(*(__m128 *)_xmm, v144))));
      v146 = *(__m128 *)((char *)&work->m_vertices[0].m_quad + v127);
      v147 = _mm_sub_ps(v146, v134);
      v148 = _mm_sub_ps(v146, v132);
      v149 = _mm_sub_ps(v146, v133);
      v150 = _mm_sub_ps(_mm_mul_ps(v147, v137), _mm_mul_ps(_mm_shuffle_ps(v147, v147, 201), v135));
      v151 = _mm_sub_ps(_mm_mul_ps(v148, v138), _mm_mul_ps(_mm_shuffle_ps(v148, v148, 201), v136));
      v152 = _mm_mul_ps(_mm_shuffle_ps(v151, v151, 201), v141);
      v153 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v139, v139, 201), v149),
               _mm_mul_ps(_mm_shuffle_ps(v149, v149, 201), v139));
      v154 = _mm_mul_ps(_mm_shuffle_ps(v150, v150, 201), v141);
      v155 = _mm_shuffle_ps(v154, v152, 238);
      v156 = _mm_mul_ps(work->m_masterNormal.m_quad, v141);
      v157 = _mm_shuffle_ps(v154, v152, 68);
      v158 = _mm_mul_ps(_mm_shuffle_ps(v153, v153, 201), v141);
      v159 = _mm_shuffle_ps(v158, v156, 68);
      v160 = _mm_add_ps(
               _mm_shuffle_ps(v155, _mm_shuffle_ps(v158, v156, 238), 136),
               _mm_add_ps(_mm_shuffle_ps(v157, v159, 221), _mm_shuffle_ps(v157, v159, 136)));
      v161 = _mm_mul_ps(v145, m_quad);
      result = (unsigned int)((~(unsigned __int8)_mm_movemask_ps(_mm_cmplt_ps(v160, (__m128)0i64)) & 7) != 0) + 17;
      out->m_pointOnA.m_quad = _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_add_ps(
                                     _mm_add_ps(_mm_shuffle_ps(v161, v161, 85), _mm_shuffle_ps(v161, v161, 0)),
                                     _mm_shuffle_ps(v161, v161, 170)),
                                   v145),
                                 v146);
      out->m_normal.m_quad = _mm_xor_ps(
                               (__m128)_mm_slli_epi32(
                                         _mm_srli_epi32(
                                           (__m128i)_mm_cmplt_ps(_mm_shuffle_ps(v160, v160, 255), (__m128)0i64),
                                           0x1Fu),
                                         0x1Fu),
                               v145);
      break;
    default:
$LN1_62:
      result = 10i64;
      break;
  }
  return result;
}
                               (__m128)_mm_slli_epi32(
                                         _mm_srli_epi32(
                                           (__m128i)_mm_cmplt_ps(_mm_shuffle_ps(v160, v160, 255), (__m128)0i64),
                                           0x1Fu),
                                         0x1Fu),
                               v145);
      break;
    default:
$LN1_62:
      result = 10i64;
      

// File Line: 338
// RVA: 0xDBDD90
void __fastcall hkGskManifold_garbageCollect(hkpGskManifold *manifold)
{
  __int64 m_numContactPoints; // r9
  $E9208155A816D87A00BF14BF7053E465 *v3; // rax
  __int64 v4; // r8
  int v5; // edx
  unsigned int v6; // ebx
  int v7; // ecx
  char *v8; // r11
  int v9; // r8d
  int v10; // r9d
  __int64 v11; // rdx
  __int64 i; // rdi
  __int64 v13; // rcx
  unsigned int v14; // ecx
  __int64 v15; // rax
  char *v16; // rcx
  int v17[22]; // [rsp+0h] [rbp-58h]

  m_numContactPoints = (unsigned __int8)manifold->m_numContactPoints;
  v17[0] = 0;
  v17[1] = 0;
  v17[2] = 0;
  v17[3] = 0;
  if ( (_DWORD)m_numContactPoints )
  {
    v3 = &manifold->m_contactPoints[0].4;
    v4 = (unsigned int)m_numContactPoints;
    do
    {
      v5 = (unsigned __int8)v3[-1].m_vert[1] + (unsigned __int8)v3[-1].m_vert[0];
      *((_BYTE *)v17 + ((unsigned __int64)(unsigned __int8)v3->m_vert[0] >> 4)) = 1;
      *((_BYTE *)v17 + ((unsigned __int64)(unsigned __int8)v3->m_vert[1] >> 4)) = 1;
      if ( v5 >= 3 )
        *((_BYTE *)v17 + ((unsigned __int64)(unsigned __int8)v3->m_vert[2] >> 4)) = 1;
      if ( v5 == 4 )
        *((_BYTE *)v17 + ((unsigned __int64)(unsigned __int8)v3->m_vert[3] >> 4)) = 1;
      v3 += 2;
      --v4;
    }
    while ( v4 );
  }
  v6 = 0;
  v7 = (unsigned __int8)manifold->m_numVertsA + (unsigned __int8)manifold->m_numVertsB;
  v8 = &manifold->m_numVertsA + 8 * m_numContactPoints;
  v9 = 0;
  v10 = 0;
  v11 = 0i64;
  for ( i = v7; v11 < i; ++v11 )
  {
    v17[v11 + 4] = v10;
    if ( *((_BYTE *)v17 + v11) )
    {
      v13 = v9++;
      *(_WORD *)&v8[2 * v13 + 4] = *(_WORD *)&v8[2 * v11 + 4];
      v10 += 16;
    }
  }
  v14 = (unsigned int)v17[(unsigned __int8)manifold->m_numVertsA + 4] >> 4;
  manifold->m_numVertsA = v14;
  manifold->m_numVertsB = v9 - v14;
  if ( manifold->m_numContactPoints )
  {
    do
    {
      v15 = v6++;
      v16 = &manifold->m_numVertsA + 8 * v15;
      v16[8] = v17[((unsigned __int64)(unsigned __int8)v16[8] >> 4) + 4];
      v16[9] = v17[((unsigned __int64)(unsigned __int8)v16[9] >> 4) + 4];
      v16[10] = v17[((unsigned __int64)(unsigned __int8)v16[10] >> 4) + 4];
      v16[11] = v17[((unsigned __int64)(unsigned __int8)v16[11] >> 4) + 4];
    }
    while ( v6 < (unsigned __int8)manifold->m_numContactPoints );
  }
}

// File Line: 440
// RVA: 0xDBCA70
void __fastcall hkGskManifold_removePoint(hkpGskManifold *manifold, int index)
{
  int m_numContactPoints; // r9d
  __int64 v4; // r8
  hkpGskManifold::ContactPoint *v5; // r9
  hkpGskManifold::ContactPoint *v6; // rax
  int v7; // r8d
  signed __int64 v8; // r9
  unsigned int v9; // ecx

  m_numContactPoints = (unsigned __int8)manifold->m_numContactPoints;
  v4 = (unsigned int)(m_numContactPoints - 1);
  manifold->m_numContactPoints = m_numContactPoints - 1;
  manifold->m_contactPoints[index] = manifold->m_contactPoints[v4];
  v5 = &manifold->m_contactPoints[m_numContactPoints];
  v6 = &manifold->m_contactPoints[(int)v4];
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
  hkGskManifold_garbageCollect(manifold);
}

// File Line: 462
// RVA: 0xDBBB20
__int64 __fastcall hkGskManifold_verifyAndGetPoints(
        hkpGskManifold *manifold,
        hkpGskManifoldWork *work,
        unsigned int firstPointIndex,
        hkpProcessCollisionOutput *processOut,
        hkpContactMgr *contactMgr)
{
  unsigned int v5; // r14d
  unsigned int v7; // ebp
  __int64 v10; // r15
  __m128 v11; // xmm9
  hkpProcessCdPoint *m_storage; // r9
  __int64 v13; // rsi
  __m128 v14; // xmm1
  hkVector4f v15; // xmm12
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  char v18; // al
  __m128 v19; // xmm5
  __m128 *v20; // rdx
  __m128 v21; // xmm6
  __m128 v22; // xmm4
  __m128 v23; // xmm6
  __m128 v24; // xmm3
  __m128 v25; // xmm0
  __m128 v26; // xmm4
  __m128 v27; // xmm3
  __m128 v28; // xmm3
  __m128 v29; // xmm3
  __m128 v30; // xmm0
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm4
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  __m128 v36; // xmm4
  __m128 v37; // xmm3
  __m128 v38; // xmm4
  __m128 v39; // xmm1
  __m128 v40; // xmm0
  __m128 v41; // xmm4
  __m128 v42; // xmm5
  __m128 *v43; // rdx
  __m128 v44; // xmm12
  __m128 v45; // xmm6
  __m128 v46; // xmm8
  __m128 v47; // xmm7
  __m128 v48; // xmm3
  __m128 v49; // xmm10
  __m128 v50; // xmm4
  __m128 v51; // xmm13
  __m128 v52; // xmm13
  __m128 v53; // xmm1
  __m128 v54; // xmm2
  __m128 v55; // xmm1
  __m128 v56; // xmm11
  __m128 v57; // xmm9
  __m128 v58; // xmm10
  __m128 v59; // xmm4
  __m128 v60; // xmm10
  __m128 v61; // xmm4
  __m128 v62; // xmm12
  __m128 v63; // xmm0
  __m128 v64; // xmm2
  __m128 v65; // xmm12
  __m128 v66; // xmm1
  __m128 v67; // xmm10
  __m128 v68; // xmm0
  __m128 v69; // xmm2
  __m128 v70; // xmm10
  __m128 v71; // xmm11
  __m128 v72; // xmm6
  __m128 v73; // xmm7
  __m128 *v74; // rdx
  __m128 v75; // xmm5
  __m128 v76; // xmm4
  __m128 v77; // xmm3
  __m128 v78; // xmm0
  __m128 v79; // xmm5
  __m128 v80; // xmm3
  __m128 v81; // xmm3
  __m128 v82; // xmm3
  __m128 v83; // xmm0
  __m128 v84; // xmm4
  __m128 v85; // xmm1
  __m128 v86; // xmm2
  __m128 v87; // xmm5
  __m128 v88; // xmm3
  __m128 v89; // xmm5
  __m128 v90; // xmm1
  __int64 v91; // rcx
  __m128 v92; // xmm11
  __m128 v93; // xmm14
  __m128 v94; // xmm8
  __m128 v95; // xmm15
  __m128 v96; // xmm11
  __m128 v97; // xmm13
  __m128 v98; // xmm7
  __m128 v99; // xmm2
  __m128 v100; // xmm4
  __m128 v101; // xmm3
  __m128 v102; // xmm3
  __m128 v103; // xmm1
  __m128 v104; // xmm6
  __m128 v105; // xmm5
  __m128 v106; // xmm5
  __m128 v107; // xmm6
  __m128 v108; // xmm0
  __m128 v109; // xmm10
  __m128 v110; // xmm5
  __m128 v111; // xmm2
  __m128 v112; // xmm6
  __m128 v113; // xmm1
  __m128 v114; // xmm10
  int v115; // eax
  __m128 v116; // xmm3
  __m128 v117; // xmm1
  __m128 v118; // xmm2
  __m128 v119; // xmm5
  __m128 v120; // xmm3
  __m128 v121; // xmm1
  __m128 v122; // xmm2
  __m128 v123; // xmm9
  __m128 v124; // xmm5
  __m128 v125; // xmm14
  __m128 v126; // xmm15
  __m128 v127; // xmm7
  __m128 v128; // xmm11
  __m128 v129; // xmm8
  __m128 v130; // xmm10
  __m128 v131; // xmm6
  __m128 v132; // xmm12
  __m128 v133; // xmm12
  __m128 v134; // xmm1
  __m128 v135; // xmm3
  __m128 v136; // xmm2
  __m128 v137; // xmm4
  __m128 v138; // xmm0
  __m128 v139; // xmm3
  __m128 v140; // xmm13
  __m128 v141; // xmm1
  __m128 v142; // xmm4
  __m128 v143; // xmm4
  __m128 v144; // xmm3
  __m128 v145; // xmm3
  __m128 v146; // xmm14
  __m128 v147; // xmm14
  __m128 v148; // xmm0
  __m128 v149; // xmm2
  __m128 v150; // xmm4
  __m128 v151; // xmm1
  __m128 v152; // xmm2
  __m128 v153; // xmm4
  __m128 v154; // xmm1
  __m128 v155; // xmm5
  __m128 v156; // xmm1
  __m128 v157; // xmm2
  __m128 v158; // xmm1
  __m128 v159; // xmm3
  __m128 v160; // xmm2
  __m128 v161; // xmm1
  __int64 m_id; // rdx
  int v163; // r8d
  hkpGskManifold::ContactPoint *v164; // rdx
  int i; // r8d
  int v166; // ecx
  __m128 v168; // [rsp+20h] [rbp-E8h]
  __m128 v169; // [rsp+20h] [rbp-E8h]
  __m128 v170; // [rsp+30h] [rbp-D8h]
  unsigned int m_numContactPoints; // [rsp+120h] [rbp+18h]

  v5 = 0;
  v7 = firstPointIndex;
  m_numContactPoints = (unsigned __int8)manifold->m_numContactPoints;
  LODWORD(v10) = m_numContactPoints;
  if ( firstPointIndex < m_numContactPoints )
  {
    v11 = 0i64;
    while ( 2 )
    {
      m_storage = processOut->m_firstFreeContactPoint.m_storage;
      v13 = v7;
      v14 = v11;
      v170 = v11;
      v15.m_quad = v11;
      switch ( (unsigned __int8)manifold->m_contactPoints[v7].m_dimB
             + 4 * (unsigned __int8)manifold->m_contactPoints[v7].m_dimA )
      {
        case 5:
          v16 = _mm_sub_ps(
                  *(__m128 *)((char *)&work->m_vertices[0].m_quad
                            + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[0]),
                  *(__m128 *)((char *)&work->m_vertices[0].m_quad
                            + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[1]));
          v17 = _mm_mul_ps(v16, v16);
          if ( (float)((float)(_mm_shuffle_ps(v17, v17, 85).m128_f32[0] + _mm_shuffle_ps(v17, v17, 0).m128_f32[0])
                     + _mm_shuffle_ps(v17, v17, 170).m128_f32[0]) > _mm_shuffle_ps(
                                                                      (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                      (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                      0).m128_f32[0] )
            goto LABEL_21;
          v15.m_quad = (__m128)work->m_masterNormal;
          v14 = v16;
          v170 = *(__m128 *)((char *)&work->m_vertices[0].m_quad
                           + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[0]);
          v18 = 5;
          goto LABEL_23;
        case 6:
          v15.m_quad = (__m128)work->m_masterNormal;
          v19 = *(__m128 *)((char *)&work->m_vertices[0].m_quad
                          + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[0]);
          v20 = (__m128 *)((char *)work + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[1]);
          v21 = *(__m128 *)((char *)&work->m_vertices[0].m_quad
                          + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[2]);
          v22 = _mm_sub_ps(v21, v19);
          v23 = _mm_sub_ps(v21, *v20);
          v24 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v23);
          v25 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v22);
          v26 = _mm_mul_ps(v22, v23);
          v27 = _mm_sub_ps(v24, v25);
          v28 = _mm_shuffle_ps(v27, v27, 201);
          v29 = _mm_mul_ps(v28, v28);
          v30 = _mm_mul_ps(_mm_sub_ps(v19, *v20), v23);
          v31 = _mm_unpacklo_ps(v26, v30);
          v32 = _mm_movelh_ps(v31, v29);
          v33 = _mm_shuffle_ps(_mm_unpackhi_ps(v26, v30), v29, 228);
          v34 = _mm_shuffle_ps(_mm_movehl_ps(v32, v31), v29, 212);
          v35 = _mm_mul_ps(v23, v23);
          v36 = _mm_add_ps(v33, _mm_add_ps(v32, v34));
          if ( _mm_shuffle_ps(v36, v36, 170).m128_f32[0] <= (float)((float)((float)(_mm_shuffle_ps(v35, v35, 85).m128_f32[0]
                                                                                  + _mm_shuffle_ps(v35, v35, 0).m128_f32[0])
                                                                          + _mm_shuffle_ps(v35, v35, 170).m128_f32[0])
                                                                  * _mm_shuffle_ps(
                                                                      (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                      (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                      0).m128_f32[0]) )
          {
            if ( (_mm_movemask_ps(_mm_cmplt_ps(v36, v11)) & 3) != 0 )
            {
              v14 = v11;
              v18 = 6;
            }
            else
            {
              v18 = 5;
              v37 = _mm_shuffle_ps(v36, v36, 0);
              v38 = _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), v37);
              v39 = _mm_rcp_ps(v38);
              v14 = _mm_sub_ps(
                      v19,
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v39, v38)), v39), v37),
                          v23),
                        *v20));
            }
          }
          else
          {
            v14 = v11;
            v18 = 10;
          }
          goto LABEL_24;
        case 7:
          v40 = *(__m128 *)((char *)&work->m_vertices[0].m_quad
                          + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[1]);
          v41 = *(__m128 *)((char *)&work->m_vertices[0].m_quad
                          + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[2]);
          v42 = *(__m128 *)((char *)&work->m_vertices[0].m_quad
                          + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[3]);
          v43 = (__m128 *)((char *)work + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[0]);
          v44 = _mm_sub_ps(v41, v40);
          v45 = _mm_sub_ps(v42, v41);
          v46 = _mm_sub_ps(v40, v42);
          v47 = _mm_shuffle_ps(v46, v46, 201);
          v48 = _mm_shuffle_ps(v45, v45, 201);
          v49 = _mm_sub_ps(*v43, v41);
          v170 = *v43;
          v50 = _mm_sub_ps(*v43, v42);
          v168 = _mm_sub_ps(*v43, v40);
          v51 = _mm_sub_ps(_mm_mul_ps(v45, v47), _mm_mul_ps(v46, v48));
          v52 = _mm_shuffle_ps(v51, v51, 201);
          v53 = _mm_mul_ps(v52, v52);
          v54 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)),
                  _mm_shuffle_ps(v53, v53, 170));
          v55 = _mm_rsqrt_ps(v54);
          v56 = _mm_cmple_ps(v54, v11);
          v57 = _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v55, v54), v55)),
                  _mm_mul_ps(*(__m128 *)_xmm, v55));
          v58 = _mm_sub_ps(_mm_mul_ps(v49, v48), _mm_mul_ps(_mm_shuffle_ps(v49, v49, 201), v45));
          v59 = _mm_sub_ps(_mm_mul_ps(v50, v47), _mm_mul_ps(_mm_shuffle_ps(v50, v50, 201), v46));
          v60 = _mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), v52);
          v61 = _mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v52);
          v62 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v168),
                  _mm_mul_ps(_mm_shuffle_ps(v168, v168, 201), v44));
          v63 = _mm_mul_ps(work->m_masterNormal.m_quad, v52);
          v64 = _mm_shuffle_ps(v60, v61, 68);
          v65 = _mm_mul_ps(_mm_shuffle_ps(v62, v62, 201), v52);
          v66 = _mm_shuffle_ps(v65, v63, 68);
          v67 = _mm_shuffle_ps(_mm_shuffle_ps(v60, v61, 238), _mm_shuffle_ps(v65, v63, 238), 136);
          v68 = _mm_shuffle_ps(v64, v66, 221);
          v69 = _mm_shuffle_ps(v64, v66, 136);
          v14 = v168;
          v70 = _mm_add_ps(v67, _mm_add_ps(v68, v69));
          v71 = _mm_andnot_ps(v56, v57);
          v11 = 0i64;
          v18 = ((~(unsigned __int8)_mm_movemask_ps(_mm_cmplt_ps(v70, (__m128)0i64)) & 7) != 0) + 17;
          v15.m_quad = _mm_xor_ps(
                         (__m128)_mm_slli_epi32(
                                   _mm_srli_epi32(
                                     (__m128i)_mm_cmplt_ps(_mm_shuffle_ps(v70, v70, 255), (__m128)0i64),
                                     0x1Fu),
                                   0x1Fu),
                         _mm_mul_ps(v71, v52));
          goto LABEL_23;
        case 9:
          v15.m_quad = (__m128)work->m_masterNormal;
          v72 = *(__m128 *)((char *)&work->m_vertices[0].m_quad
                          + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[1]);
          v73 = *(__m128 *)((char *)&work->m_vertices[0].m_quad
                          + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[2]);
          v74 = (__m128 *)((char *)work + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[0]);
          v75 = _mm_sub_ps(v72, v73);
          v76 = _mm_sub_ps(v72, *v74);
          v77 = _mm_mul_ps(_mm_shuffle_ps(v75, v75, 201), v76);
          v78 = _mm_mul_ps(_mm_shuffle_ps(v76, v76, 201), v75);
          v79 = _mm_mul_ps(v75, v76);
          v80 = _mm_sub_ps(v77, v78);
          v81 = _mm_shuffle_ps(v80, v80, 201);
          v82 = _mm_mul_ps(v81, v81);
          v83 = _mm_mul_ps(_mm_sub_ps(v73, *v74), v76);
          v84 = _mm_mul_ps(v76, v76);
          v85 = _mm_unpacklo_ps(v79, v83);
          v86 = _mm_movelh_ps(v85, v82);
          v87 = _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v79, v83), v82, 228),
                  _mm_add_ps(v86, _mm_shuffle_ps(_mm_movehl_ps(v86, v85), v82, 212)));
          if ( _mm_shuffle_ps(v87, v87, 170).m128_f32[0] > (float)((float)((float)(_mm_shuffle_ps(v84, v84, 85).m128_f32[0]
                                                                                 + _mm_shuffle_ps(v84, v84, 0).m128_f32[0])
                                                                         + _mm_shuffle_ps(v84, v84, 170).m128_f32[0])
                                                                 * _mm_shuffle_ps(
                                                                     (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                     (__m128)LODWORD(work->m_radiusSumSqrd.m_storage),
                                                                     0).m128_f32[0]) )
          {
LABEL_21:
            v14 = v11;
LABEL_22:
            v18 = 10;
          }
          else if ( (_mm_movemask_ps(_mm_cmplt_ps(v87, v11)) & 3) != 0 )
          {
            v14 = v11;
            v18 = 6;
          }
          else
          {
            v18 = 5;
            v88 = _mm_shuffle_ps(v87, v87, 0);
            v89 = _mm_add_ps(_mm_shuffle_ps(v87, v87, 85), v88);
            v90 = _mm_rcp_ps(v89);
            v170 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(*v74, v72),
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v90, v89)), v90), v88)),
                     v72);
            v14 = _mm_sub_ps(v170, v73);
          }
LABEL_23:
          v19 = v170;
LABEL_24:
          if ( (v18 & 1) != 0 )
          {
            v156 = _mm_mul_ps(v14, v15.m_quad);
            v157 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v156, v156, 85), _mm_shuffle_ps(v156, v156, 0)),
                     _mm_shuffle_ps(v156, v156, 170));
            v158 = _mm_shuffle_ps(
                     (__m128)LODWORD(work->m_radiusB.m_storage),
                     (__m128)LODWORD(work->m_radiusB.m_storage),
                     0);
            v159 = _mm_sub_ps(v158, v157);
            v160 = _mm_sub_ps(
                     v157,
                     _mm_add_ps(
                       _mm_shuffle_ps(
                         (__m128)LODWORD(work->m_radiusA.m_storage),
                         (__m128)LODWORD(work->m_radiusA.m_storage),
                         0),
                       v158));
            if ( v160.m128_f32[0] < _mm_shuffle_ps(
                                      (__m128)LODWORD(work->m_keepContact.m_storage),
                                      (__m128)LODWORD(work->m_keepContact.m_storage),
                                      0).m128_f32[0] )
            {
              m_storage->m_contact.m_position.m_quad = _mm_add_ps(_mm_mul_ps(v159, v15.m_quad), v19);
              m_storage->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(
                                                                 v15.m_quad,
                                                                 _mm_unpackhi_ps(v15.m_quad, v160),
                                                                 196);
              m_storage->m_contactPointId = manifold->m_contactPoints[v7].m_id;
              ++processOut->m_firstFreeContactPoint.m_storage;
              goto LABEL_35;
            }
          }
          else if ( (v18 & 0x10) != 0 )
          {
            v161 = _mm_mul_ps(v14, v15.m_quad);
            if ( (float)((float)((float)(_mm_shuffle_ps(v161, v161, 85).m128_f32[0]
                                       + _mm_shuffle_ps(v161, v161, 0).m128_f32[0])
                               + _mm_shuffle_ps(v161, v161, 170).m128_f32[0])
                       - (float)(_mm_shuffle_ps(
                                   (__m128)LODWORD(work->m_radiusB.m_storage),
                                   (__m128)LODWORD(work->m_radiusB.m_storage),
                                   0).m128_f32[0]
                               + _mm_shuffle_ps(
                                   (__m128)LODWORD(work->m_radiusA.m_storage),
                                   (__m128)LODWORD(work->m_radiusA.m_storage),
                                   0).m128_f32[0])) < _mm_shuffle_ps(
                                                        (__m128)LODWORD(work->m_keepContact.m_storage),
                                                        (__m128)LODWORD(work->m_keepContact.m_storage),
                                                        0).m128_f32[0] )
              v5 = 1;
          }
          else if ( (v18 & 4) != 0 )
          {
            v5 = 1;
          }
          m_id = manifold->m_contactPoints[v7].m_id;
          if ( (_WORD)m_id != 0xFFFF )
            ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *, hkpProcessCdPoint *))contactMgr->vfptr[2].__first_virtual_table_function__)(
              contactMgr,
              m_id,
              processOut->m_constraintOwner.m_storage,
              m_storage);
          v10 = (unsigned int)(v10 - 1);
          --v7;
          manifold->m_contactPoints[v13] = manifold->m_contactPoints[v10];
LABEL_35:
          if ( ++v7 < (unsigned int)v10 )
            continue;
          if ( m_numContactPoints > (unsigned int)v10 )
          {
            v163 = (unsigned __int8)manifold->m_numVertsB + (unsigned __int8)manifold->m_numVertsA - 1;
            v164 = &manifold->m_contactPoints[m_numContactPoints];
            manifold->m_numContactPoints = v10;
            for ( i = v163 >> 1;
                  i >= 0;
                  *(_DWORD *)((char *)v164 + 8i64 * (int)v10 - 8i64 * (int)m_numContactPoints - 4) = v166 )
            {
              --i;
              v166 = *(_DWORD *)&v164->m_dimA;
              v164 = (hkpGskManifold::ContactPoint *)((char *)v164 + 4);
            }
            hkGskManifold_garbageCollect(manifold);
          }
          break;
        case 0xA:
          v91 = (unsigned __int8)manifold->m_contactPoints[v7].m_vert[3];
          v15.m_quad = (__m128)work->m_masterNormal;
          v92 = *(__m128 *)((char *)&work->m_vertices[0].m_quad
                          + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[1]);
          v93 = *(__m128 *)((char *)&work->m_vertices[0].m_quad
                          + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[0]);
          v94 = _mm_sub_ps(v92, *(__m128 *)((char *)&work->m_vertices[0].m_quad + v91));
          v95 = *(__m128 *)((char *)&work->m_vertices[0].m_quad
                          + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[2]);
          v96 = _mm_sub_ps(v92, v93);
          v97 = _mm_sub_ps(*(__m128 *)((char *)&work->m_vertices[0].m_quad + v91), v95);
          v98 = _mm_sub_ps(v93, v95);
          v99 = _mm_shuffle_ps(v96, v96, 201);
          v100 = _mm_shuffle_ps(v97, v97, 201);
          v101 = _mm_sub_ps(_mm_mul_ps(v96, v100), _mm_mul_ps(v97, v99));
          v102 = _mm_shuffle_ps(v101, v101, 201);
          v103 = _mm_shuffle_ps(v102, v102, 201);
          v104 = _mm_sub_ps(_mm_mul_ps(v96, v103), _mm_mul_ps(v102, v99));
          v105 = _mm_sub_ps(_mm_mul_ps(v97, v103), _mm_mul_ps(v102, v100));
          v106 = _mm_shuffle_ps(v105, v105, 201);
          v107 = _mm_shuffle_ps(v104, v104, 201);
          v108 = _mm_mul_ps(v107, v98);
          v109 = _mm_mul_ps(v106, v98);
          v110 = _mm_mul_ps(v106, v94);
          v111 = _mm_shuffle_ps(v109, v108, 68);
          v112 = _mm_mul_ps(v107, v94);
          v113 = _mm_shuffle_ps(v110, v112, 68);
          v114 = _mm_add_ps(
                   _mm_shuffle_ps(_mm_shuffle_ps(v109, v108, 238), _mm_shuffle_ps(v110, v112, 238), 136),
                   _mm_add_ps(_mm_shuffle_ps(v111, v113, 221), _mm_shuffle_ps(v111, v113, 136)));
          v115 = _mm_movemask_ps(_mm_cmplt_ps(v114, v11));
          if ( v115 == 3 || v115 == 12 )
          {
            v18 = 17;
            v116 = _mm_shuffle_ps(v114, v114, 0);
            v117 = _mm_sub_ps(v116, _mm_shuffle_ps(v114, v114, 170));
            v118 = _mm_rcp_ps(v117);
            v119 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v118, v117)), v118), v116);
            v120 = _mm_shuffle_ps(v114, v114, 85);
            v19 = _mm_add_ps(_mm_mul_ps(v119, v96), v93);
            v121 = _mm_sub_ps(v120, _mm_shuffle_ps(v114, v114, 255));
            v122 = _mm_rcp_ps(v121);
            v14 = _mm_sub_ps(
                    v19,
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v122, v121)), v122), v120),
                        v97),
                      v95));
          }
          else
          {
            v14 = v11;
            v19 = v11;
            v18 = 18;
          }
          goto LABEL_24;
        case 0xD:
          v123 = *(__m128 *)((char *)&work->m_vertices[0].m_quad
                           + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[0]);
          v124 = *(__m128 *)((char *)&work->m_vertices[0].m_quad
                           + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[1]);
          v125 = _mm_sub_ps(v124, v123);
          v126 = *(__m128 *)((char *)&work->m_vertices[0].m_quad
                           + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[3]);
          v127 = *(__m128 *)((char *)&work->m_vertices[0].m_quad
                           + (unsigned __int8)manifold->m_contactPoints[v7].m_vert[2]);
          v128 = _mm_sub_ps(v123, v127);
          v169 = _mm_sub_ps(v123, v126);
          v129 = _mm_sub_ps(v127, v124);
          v130 = _mm_shuffle_ps(v128, v128, 201);
          v131 = _mm_shuffle_ps(v129, v129, 201);
          v132 = _mm_sub_ps(_mm_mul_ps(v129, v130), _mm_mul_ps(v128, v131));
          v133 = _mm_shuffle_ps(v132, v132, 201);
          v134 = _mm_mul_ps(v133, v133);
          v135 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v134, v134, 85), _mm_shuffle_ps(v134, v134, 0)),
                   _mm_shuffle_ps(v134, v134, 170));
          v136 = _mm_rsqrt_ps(v135);
          v137 = _mm_cmple_ps(v135, (__m128)0i64);
          v138 = _mm_mul_ps(_mm_mul_ps(v136, v135), v136);
          v139 = _mm_sub_ps(v126, v127);
          v140 = _mm_mul_ps(
                   v133,
                   _mm_andnot_ps(v137, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v138), _mm_mul_ps(*(__m128 *)_xmm, v136))));
          v141 = _mm_sub_ps(v126, v123);
          v142 = _mm_sub_ps(v126, v124);
          v143 = _mm_sub_ps(_mm_mul_ps(v142, v131), _mm_mul_ps(_mm_shuffle_ps(v142, v142, 201), v129));
          v144 = _mm_sub_ps(_mm_mul_ps(v139, v130), _mm_mul_ps(_mm_shuffle_ps(v139, v139, 201), v128));
          v145 = _mm_mul_ps(_mm_shuffle_ps(v144, v144, 201), v133);
          v146 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v125, v125, 201), v141),
                   _mm_mul_ps(_mm_shuffle_ps(v141, v141, 201), v125));
          v147 = _mm_mul_ps(_mm_shuffle_ps(v146, v146, 201), v133);
          v148 = _mm_mul_ps(work->m_masterNormal.m_quad, v133);
          v149 = _mm_mul_ps(_mm_shuffle_ps(v143, v143, 201), v133);
          v150 = _mm_shuffle_ps(v149, v145, 238);
          v151 = _mm_shuffle_ps(v147, v148, 68);
          v152 = _mm_shuffle_ps(v149, v145, 68);
          v153 = _mm_add_ps(
                   _mm_shuffle_ps(v150, _mm_shuffle_ps(v147, v148, 238), 136),
                   _mm_add_ps(_mm_shuffle_ps(v152, v151, 221), _mm_shuffle_ps(v152, v151, 136)));
          v154 = _mm_mul_ps(v140, v169);
          v11 = 0i64;
          v18 = ((~(unsigned __int8)_mm_movemask_ps(_mm_cmplt_ps(v153, (__m128)0i64)) & 7) != 0) + 17;
          v15.m_quad = _mm_xor_ps(
                         (__m128)_mm_slli_epi32(
                                   _mm_srli_epi32(
                                     (__m128i)_mm_cmplt_ps(_mm_shuffle_ps(v153, v153, 255), (__m128)0i64),
                                     0x1Fu),
                                   0x1Fu),
                         v140);
          v155 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v154, v154, 85), _mm_shuffle_ps(v154, v154, 0)),
                   _mm_shuffle_ps(v154, v154, 170));
          v14 = v169;
          v19 = _mm_add_ps(_mm_mul_ps(v155, v140), v126);
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
__int64 __fastcall hkGskManifold_doesPointExistAndResort(hkpGskManifold *manifold, hkpGskCache *newPoint)
{
  __int64 m_numContactPoints; // rbx
  int v3; // edi
  unsigned int v6; // edx
  unsigned __int8 m_dimA; // si
  $E9208155A816D87A00BF14BF7053E465 *v8; // r8
  unsigned __int8 m_dimB; // al
  int v10; // r9d
  __int64 v11; // rcx
  unsigned __int8 v12; // si
  hkpGskManifold::ContactPoint *i; // rax
  char *v15; // rdx
  hkpGskManifold::ContactPoint v16; // rax

  m_numContactPoints = (unsigned __int8)manifold->m_numContactPoints;
  v3 = 0;
  v6 = 0;
  if ( manifold->m_numContactPoints )
  {
    m_dimA = newPoint->m_dimA;
    v8 = &manifold->m_contactPoints[0].4;
    while ( 1 )
    {
      if ( m_dimA == v8[-1].m_vert[0] )
      {
        m_dimB = newPoint->m_dimB;
        if ( m_dimB == v8[-1].m_vert[1] )
        {
          v10 = m_dimA + m_dimB;
          v11 = m_numContactPoints;
          if ( newPoint->m_vertices[0] == *(_WORD *)(&manifold->m_contactPoints[m_numContactPoints].m_dimA
                                                   + ((unsigned __int64)(unsigned __int8)v8->m_vert[0] >> 3))
            && newPoint->m_vertices[1] == *(_WORD *)(&manifold->m_contactPoints[v11].m_dimA
                                                   + ((unsigned __int64)(unsigned __int8)v8->m_vert[1] >> 3))
            && (v10 <= 2
             || newPoint->m_vertices[2] == *(_WORD *)(&manifold->m_contactPoints[v11].m_dimA
                                                    + ((unsigned __int64)(unsigned __int8)v8->m_vert[2] >> 3)))
            && (v10 <= 3
             || newPoint->m_vertices[3] == *(_WORD *)(&manifold->m_contactPoints[v11].m_dimA
                                                    + ((unsigned __int64)(unsigned __int8)v8->m_vert[3] >> 3))) )
          {
            break;
          }
        }
      }
      ++v6;
      v8 += 2;
      if ( v6 >= (unsigned int)m_numContactPoints )
        goto LABEL_12;
    }
    if ( v6 )
    {
      v15 = &manifold->m_numVertsA + 8 * v6;
      v16 = *(hkpGskManifold::ContactPoint *)(v15 + 4);
      *(hkpGskManifold::ContactPoint *)(v15 + 4) = manifold->m_contactPoints[0];
      manifold->m_contactPoints[0] = v16;
    }
    return 1i64;
  }
  else
  {
LABEL_12:
    v12 = newPoint->m_dimA;
    if ( (v12 == 1 || newPoint->m_dimB == 1) && (_DWORD)m_numContactPoints )
    {
      for ( i = manifold->m_contactPoints;
            (v12 != 1
          || i->m_dimA != 1
          || *(_WORD *)(&manifold->m_contactPoints[m_numContactPoints].m_dimA
                      + ((unsigned __int64)(unsigned __int8)i->m_vert[0] >> 3)) != newPoint->m_vertices[0])
         && (newPoint->m_dimB != 1
          || i->m_dimB != 1
          || *(_WORD *)(&manifold->m_contactPoints[m_numContactPoints].m_dimA
                      + ((unsigned __int64)(unsigned __int8)i->m_vert[(unsigned __int8)i->m_dimA] >> 3)) != newPoint->m_vertices[v12]);
            ++i )
      {
        if ( ++v3 >= (unsigned int)m_numContactPoints )
          return 0i64;
      }
      *(_WORD *)&i->m_dimA = 0;
      return 2i64;
    }
    else
    {
      return 0i64;
    }
  }
}

// File Line: 647
// RVA: 0xDBDF10
__int64 __fastcall hkGskManifold_findRedundant5thPoint(hkpProcessCdPoint *resultPointArray)
{
  unsigned int v1; // r8d
  __m128i v2; // xmm6
  __int64 v3; // r11
  hkpProcessCdPoint *v4; // r9
  __m128 v5; // xmm9
  __int64 v6; // rdx
  __m128i si128; // xmm10
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
  __int64 v22; // rax
  __m128i v23; // xmm7
  __m128 v24; // xmm14
  __int64 v25; // rcx
  __int64 v26; // rax
  __m128 m_quad; // xmm0
  __m128 *p_m_quad; // rcx
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
  __int64 v39; // rax
  __m128 *v40; // rcx
  __m128i v41; // xmm7
  __m128i v42; // xmm8
  __m128 v43; // xmm4
  __int64 i; // rax
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
  __int64 v57; // rax
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
  __int64 v78; // rax
  __int64 v79[2]; // [rsp+0h] [rbp-91h]
  int v80; // [rsp+10h] [rbp-81h]
  char v81; // [rsp+18h] [rbp-79h] BYREF
  __int64 v82; // [rsp+20h] [rbp-71h] BYREF
  void *retaddr; // [rsp+F8h] [rbp+67h]

  v1 = 0;
  v2 = 0i64;
  v3 = 4i64;
  v4 = resultPointArray;
  v79[0] = 0i64;
  v79[1] = 0i64;
  v80 = 0;
  LODWORD(retaddr) = 0;
  v5 = (__m128)xmmword_141A712A0;
  v6 = 4i64;
  si128 = _mm_load_si128((const __m128i *)&xmmword_141A72090);
  v8 = (__m128 *)&v82;
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
    v17 = (__m128i)_mm_cmplt_ps(v10, v16);
    v10 = _mm_max_ps(v10, v16);
    v8[-1] = v16;
    v18 = _mm_and_si128(v11, v17);
    v19 = _mm_andnot_si128(v17, v13);
    v20 = (__m128i)_mm_cmplt_ps(v16, v5);
    v13 = _mm_or_si128(v19, v18);
    v21 = _mm_and_si128(v11, v20);
    v11 = _mm_add_epi32(v11, si128);
    v5 = _mm_min_ps(v5, v16);
    v12 = _mm_or_si128(_mm_andnot_si128(v20, v12), v21);
    --v6;
  }
  while ( v6 );
  v22 = v12.m128i_i32[0];
  v23 = 0i64;
  v24 = _mm_shuffle_ps(v4[4].m_contact.m_separatingNormal.m_quad, v4[4].m_contact.m_separatingNormal.m_quad, 255);
  v25 = v22;
  *((_DWORD *)v79 + v13.m128i_i32[0]) = 1;
  v26 = 0i64;
  m_quad = v4[v25].m_contact.m_separatingNormal.m_quad;
  p_m_quad = &v4->m_contact.m_position.m_quad;
  v29 = v24.m128_f32[0] - _mm_shuffle_ps(m_quad, m_quad, 255).m128_f32[0];
  *(float *)&retaddr = FLOAT_1_05;
  v30 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_1_05), (__m128)LODWORD(FLOAT_1_05), 0), v10);
  v31 = 0i64;
  do
  {
    if ( !*((_DWORD *)v79 + v26) )
    {
      v32 = _mm_sub_ps(v4[v13.m128i_i32[0]].m_contact.m_position.m_quad, *p_m_quad);
      v33 = _mm_mul_ps(v32, v32);
      v34 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
              _mm_shuffle_ps(v33, v33, 170));
      v35 = v31;
      v36 = (__m128i)_mm_cmplt_ps(v30, v34);
      v31 = _mm_add_epi32(v31, si128);
      v30 = _mm_max_ps(v30, v34);
      v23 = _mm_or_si128(_mm_andnot_si128(v36, v23), _mm_and_si128(v35, v36));
    }
    ++v26;
    p_m_quad += 3;
  }
  while ( v26 < 5 );
  v37 = v4[v13.m128i_i32[0]].m_contact.m_position.m_quad;
  LODWORD(retaddr) = 0;
  v38 = 0i64;
  *((_DWORD *)v79 + v23.m128i_i32[0]) = 1;
  v39 = v23.m128i_i32[0];
  v40 = &v4->m_contact.m_position.m_quad;
  v41 = 0i64;
  v42 = 0i64;
  v43 = _mm_sub_ps(v37, v4[v39].m_contact.m_position.m_quad);
  for ( i = 0i64; i < 5; ++i )
  {
    if ( !*((_DWORD *)v79 + i) )
    {
      v45 = _mm_sub_ps(*v40, v37);
      v46 = _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v45);
      v47 = _mm_shuffle_ps(v45, v45, 201);
      v48 = v41;
      v41 = _mm_add_epi32(v41, si128);
      v49 = _mm_sub_ps(v46, _mm_mul_ps(v47, v43));
      v50 = _mm_shuffle_ps(v49, v49, 201);
      v51 = _mm_mul_ps(v50, v50);
      v52 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
              _mm_shuffle_ps(v51, v51, 170));
      v53 = (__m128i)_mm_cmplt_ps(v38, v52);
      v38 = _mm_max_ps(v38, v52);
      v42 = _mm_or_si128(_mm_andnot_si128(v53, v42), _mm_and_si128(v48, v53));
    }
    v40 += 3;
  }
  v54 = 0i64;
  LODWORD(retaddr) = 0;
  v55 = 0i64;
  v56 = 0i64;
  *((_DWORD *)v79 + v42.m128i_i32[0]) = 1;
  v57 = 0i64;
  v58 = &v4->m_contact.m_position.m_quad;
  do
  {
    if ( !*((_DWORD *)v79 + v57) )
    {
      v59 = _mm_sub_ps(v4[v42.m128i_i32[0]].m_contact.m_position.m_quad, *v58);
      v60 = _mm_mul_ps(v59, v59);
      v61 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v60, v60, 85), _mm_shuffle_ps(v60, v60, 0)),
              _mm_shuffle_ps(v60, v60, 170));
      v62 = v55;
      v63 = (__m128i)_mm_cmplt_ps(v54, v61);
      v55 = _mm_add_epi32(v55, si128);
      v54 = _mm_max_ps(v54, v61);
      v56 = _mm_or_si128(_mm_andnot_si128(v63, v56), _mm_and_si128(v62, v63));
    }
    ++v57;
    v58 += 3;
  }
  while ( v57 < 5 );
  *(float *)&retaddr = FLOAT_526_0;
  *((_DWORD *)v79 + v56.m128i_i32[0]) = 1;
  if ( v80
    || v29 >= 0.0
    || v5.m128_f32[0] >= (float)((float)(_mm_shuffle_ps((__m128)LODWORD(FLOAT_526_0), (__m128)LODWORD(FLOAT_526_0), 0).m128_f32[0]
                                       * v29)
                               * v29) )
  {
    v78 = 0i64;
    while ( *((_DWORD *)v79 + v78) )
    {
      ++v78;
      ++v1;
      if ( v78 >= 5 )
        return 0i64;
    }
    return v1;
  }
  else
  {
    v64 = _mm_load_si128((const __m128i *)&_xmm);
    v65 = (__m128 *)&v81;
    v66 = &v4->m_contact.m_separatingNormal.m_quad;
    v67 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_030461743), (__m128)LODWORD(FLOAT_0_030461743), 0);
    *(float *)&retaddr = FLOAT_9_9999997eN10;
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
      v74 = (__m128i)_mm_cmplt_ps(_mm_mul_ps(v67, v69), v73);
      v75 = _mm_andnot_ps(
              _mm_cmpeq_ps((__m128)0i64, v69),
              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v71, v69)), v71), v73));
      v76 = v2;
      v2 = _mm_add_epi32(v2, si128);
      v67 = _mm_or_ps(_mm_and_ps(v75, (__m128)v74), _mm_andnot_ps((__m128)v74, v67));
      v64 = _mm_or_si128(_mm_andnot_si128(v74, v64), _mm_and_si128(v76, v74));
      --v3;
    }
    while ( v3 );
    return v64.m128i_u32[0];
  }
}

// File Line: 928
// RVA: 0xDBC650
__int64 __fastcall hkGskManifold_addPoint(
        hkpGskManifold *manifold,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *output,
        hkpGskCache *newPoint,
        hkpProcessCdPoint *newCdPointInResultArray,
        hkpProcessCdPoint *resultPointArray,
        hkpContactMgr *mgr,
        hkpGskManifoldUtilMgrHandling mgrHandling)
{
  int Redundant5thPoint; // eax
  __int64 v14; // rsi
  __int64 v16; // r14
  hkpGskManifold::ContactPoint v17; // rax
  unsigned __int16 v18; // r10
  __int64 m_numContactPoints; // rcx
  int v20; // eax
  int v21; // r8d
  hkpGskManifold::ContactPoint *v22; // r9
  hkpGskManifold::ContactPoint *v23; // rdx
  int v24; // r8d
  signed __int64 v25; // r9
  unsigned int v26; // eax
  hkpGskCache *v27; // rsi
  __int64 v28; // r11
  int v29; // r9d
  char *v30; // r8
  _DWORD *i; // rdx
  int v32; // r12d
  $E9208155A816D87A00BF14BF7053E465 *v33; // r15
  char m_dimB; // al
  int v35; // edi
  int v36; // ebp
  hkpGskManifold::ContactPoint *v37; // r9
  hkpGskCache *v38; // r14
  unsigned int m_numVertsA; // ecx
  unsigned __int16 v40; // r11
  unsigned int v41; // edx
  __int64 v42; // r8
  char *v43; // r10
  unsigned int v44; // r10d
  hkpGskManifold::ContactPoint *j; // r8
  __int64 m_dimA; // rdx
  __int64 v47; // r10
  int v48; // ecx
  int v49; // edx
  unsigned __int16 v50; // r8
  __int64 v51; // rdx
  unsigned int v52; // [rsp+80h] [rbp+8h]

  v52 = 4;
  if ( manifold->m_numContactPoints == 4 )
  {
    Redundant5thPoint = hkGskManifold_findRedundant5thPoint(resultPointArray);
    v14 = Redundant5thPoint;
    v52 = Redundant5thPoint;
    if ( Redundant5thPoint == 4 )
      return 5i64;
    v16 = Redundant5thPoint;
    ((void (__fastcall *)(hkpContactMgr *, _QWORD, hkpConstraintOwner *))mgr->vfptr[2].__first_virtual_table_function__)(
      mgr,
      manifold->m_contactPoints[Redundant5thPoint].m_id,
      output->m_constraintOwner.m_storage);
    if ( (_DWORD)v14 )
      v17 = manifold->m_contactPoints[0];
    else
      v17 = manifold->m_contactPoints[1];
    manifold->m_contactPoints[v14] = v17;
    hkGskManifold_garbageCollect(manifold);
    v18 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, hkpGskCache *, hkpProcessCdPoint *))mgr->vfptr[1].__first_virtual_table_function__)(
            mgr,
            bodyA,
            bodyB,
            input,
            output,
            newPoint,
            newCdPointInResultArray);
    if ( v18 == 0xFFFF )
    {
      manifold->m_contactPoints[0] = manifold->m_contactPoints[3];
      m_numContactPoints = (unsigned __int8)manifold->m_numContactPoints;
      v20 = m_numContactPoints - 1;
      v21 = (unsigned __int8)manifold->m_numVertsA - 1;
      v22 = &manifold->m_contactPoints[m_numContactPoints];
      LODWORD(m_numContactPoints) = (unsigned __int8)manifold->m_numVertsB;
      manifold->m_numContactPoints = v20;
      v23 = &manifold->m_contactPoints[v20];
      v24 = ((int)m_numContactPoints + v21) >> 1;
      if ( v24 >= 0 )
      {
        v25 = (char *)v22 - (char *)v23;
        do
        {
          --v24;
          v26 = *(_DWORD *)(&v23->m_dimA + v25);
          v23 = (hkpGskManifold::ContactPoint *)((char *)v23 + 4);
          v23[-1].m_allVerts = v26;
        }
        while ( v24 >= 0 );
      }
      resultPointArray[v16] = resultPointArray[3];
      return 6i64;
    }
    newCdPointInResultArray->m_contactPointId = v18;
    resultPointArray[v16] = *newCdPointInResultArray;
    v27 = newPoint;
  }
  else
  {
    v27 = newPoint;
    if ( mgrHandling == HK_GSK_MANIFOLD_CREATE_ID_ALWAYS || newPoint->m_dimB == 3 )
    {
      v18 = ((__int64 (__fastcall *)(hkpContactMgr *))mgr->vfptr[1].__first_virtual_table_function__)(mgr);
      if ( v18 == 0xFFFF )
        return 5i64;
    }
    else
    {
      v18 = -1;
    }
    newCdPointInResultArray->m_contactPointId = v18;
    v28 = (unsigned __int8)manifold->m_numContactPoints;
    v29 = ((unsigned __int8)manifold->m_numVertsB + (unsigned __int8)manifold->m_numVertsA - 1) >> 1;
    v30 = (char *)&manifold->m_contactPoints[(int)v28 + 1] + 4 * v29;
    for ( i = (_DWORD *)&manifold->m_contactPoints[v28] + v29; v29 >= 0; --i )
    {
      v30 -= 4;
      --v29;
      *((_DWORD *)v30 + 1) = *i;
    }
    manifold->m_contactPoints[v28] = manifold->m_contactPoints[0];
    manifold->m_numContactPoints = v28 + 1;
  }
  v32 = 0;
  v33 = &manifold->m_contactPoints[0].4;
  manifold->m_contactPoints[0].m_dimA = v27->m_dimA;
  m_dimB = v27->m_dimB;
  manifold->m_contactPoints[0].m_allVerts = 0;
  manifold->m_contactPoints[0].m_id = v18;
  manifold->m_contactPoints[0].m_dimB = m_dimB;
  v35 = 0;
  v36 = 0;
  v37 = &manifold->m_contactPoints[(unsigned __int8)manifold->m_numContactPoints];
  if ( v27->m_dimA )
  {
    v38 = v27;
    do
    {
      m_numVertsA = (unsigned __int8)manifold->m_numVertsA;
      v40 = v38->m_vertices[0];
      v41 = 0;
      if ( manifold->m_numVertsA )
      {
        while ( *((_WORD *)&v37->m_dimA + v41) != v40 )
        {
          if ( ++v41 >= m_numVertsA )
            goto LABEL_25;
        }
      }
      else
      {
LABEL_25:
        v42 = m_numVertsA + (unsigned __int8)manifold->m_numVertsB;
        if ( (unsigned int)v42 > v41 )
        {
          v43 = (char *)v37 + 2 * v42;
          do
          {
            v42 = (unsigned int)(v42 - 1);
            v43 -= 2;
            *((_WORD *)v43 + 1) = *((_WORD *)&v37->m_dimA + v42);
          }
          while ( (unsigned int)v42 > v41 );
        }
        *((_WORD *)&v37->m_dimA + v41) = v40;
        ++manifold->m_numVertsA;
        v35 += 16;
      }
      ++v36;
      v38 = (hkpGskCache *)((char *)v38 + 2);
      v33->m_vert[0] = 16 * v41;
      v33 = ($E9208155A816D87A00BF14BF7053E465 *)((char *)v33 + 1);
    }
    while ( v36 < (unsigned __int8)v27->m_dimA );
    if ( v35 )
    {
      v44 = 1;
      for ( j = &manifold->m_contactPoints[1]; v44 < (unsigned __int8)manifold->m_numContactPoints; ++j )
      {
        m_dimA = (unsigned __int8)j->m_dimA;
        if ( (unsigned int)m_dimA < (unsigned int)m_dimA + (unsigned __int8)j->m_dimB )
        {
          do
          {
            j->m_vert[m_dimA] += v35;
            m_dimA = (unsigned int)(m_dimA + 1);
          }
          while ( (unsigned int)m_dimA < (unsigned __int8)j->m_dimA + (unsigned int)(unsigned __int8)j->m_dimB );
        }
        ++v44;
      }
    }
  }
  v47 = 0i64;
  if ( v27->m_dimB )
  {
    do
    {
      v48 = (unsigned __int8)manifold->m_numVertsA;
      v49 = v48 + (unsigned __int8)manifold->m_numVertsB;
      v50 = v27->m_vertices[v47 + (unsigned __int8)v27->m_dimA];
      if ( v48 >= v49 )
      {
LABEL_39:
        *((_WORD *)&v37->m_dimA + v48) = v50;
        ++manifold->m_numVertsB;
      }
      else
      {
        while ( *((_WORD *)&v37->m_dimA + v48) != v50 )
        {
          if ( ++v48 >= v49 )
            goto LABEL_39;
        }
      }
      ++v32;
      v51 = v47 + (unsigned __int8)v27->m_dimA;
      ++v47;
      manifold->m_contactPoints[0].m_vert[v51] = 16 * v48;
    }
    while ( v32 < (unsigned __int8)v27->m_dimB );
  }
  return v52;
}

// File Line: 1138
// RVA: 0xDBCAE0
void __fastcall hkGskManifold_cleanup(
        hkpGskManifold *manifold,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner)
{
  __int64 i; // rbx
  __int64 m_id; // rdx

  for ( i = 0i64; (unsigned int)i < (unsigned __int8)manifold->m_numContactPoints; i = (unsigned int)(i + 1) )
  {
    m_id = manifold->m_contactPoints[i].m_id;
    if ( (_WORD)m_id != 0xFFFF )
      ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))mgr->vfptr[2].__first_virtual_table_function__)(
        mgr,
        m_id,
        constraintOwner);
  }
  *(_WORD *)&manifold->m_numVertsB = 0;
  manifold->m_numVertsA = 0;
}


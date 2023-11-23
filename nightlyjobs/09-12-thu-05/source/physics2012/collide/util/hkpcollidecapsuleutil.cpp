// File Line: 20
// RVA: 0xD3F720
hkResult *__fastcall hkCollideCapsuleUtilClostestPointCapsVsCaps(
        hkResult *result,
        hkVector4f *capsA,
        const float *capsARadius,
        hkVector4f *capsB,
        const float *capsBRadius,
        float collisionTolerance,
        hkContactPoint *cpoint)
{
  __m128 v7; // xmm3
  __m128 m_quad; // xmm14
  __m128 v9; // xmm15
  __m128 v10; // xmm1
  __m128 v11; // xmm10
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm9
  __m128 v16; // xmm1
  __m128 v17; // xmm8
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm6
  __m128 v21; // xmm5
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  __m128 v27; // xmm7
  __m128 v28; // xmm6
  __m128 v29; // xmm1
  __m128 v30; // xmm0
  __m128 v31; // xmm3
  __m128 v32; // xmm3
  __m128 v33; // xmm0
  __m128 v34; // xmm4
  __m128 v35; // xmm2
  __m128 v36; // xmm0
  __m128 v37; // xmm10
  __m128 v38; // xmm1
  __m128 v39; // xmm12
  __m128 v40; // xmm11
  __m128 v41; // xmm3
  float v42; // xmm13_4
  __m128 v43; // xmm0
  __m128 v44; // xmm2
  __m128 v45; // xmm6
  __m128 v46; // xmm14
  __m128 v47; // xmm3
  __m128 v48; // xmm3
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  __m128 v51; // xmm15
  __m128 v52; // xmm5
  __m128 v53; // xmm15
  __m128 v54; // xmm1
  __m128 v55; // xmm4
  __m128 v56; // xmm2
  __m128 v57; // xmm1
  __m128 v58; // xmm2
  __m128 v59; // xmm1
  __m128 v60; // xmm14
  hkResult *v61; // rax
  __m128 v62; // [rsp+0h] [rbp-F8h]
  __m128 v63; // [rsp+40h] [rbp-B8h]

  v7 = _mm_sub_ps(capsB[1].m_quad, capsB->m_quad);
  m_quad = cpoint->m_separatingNormal.m_quad;
  v9 = _mm_sub_ps(capsA[1].m_quad, capsA->m_quad);
  v10 = _mm_mul_ps(v7, v9);
  v62 = v7;
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_sub_ps(capsB->m_quad, capsA->m_quad);
  v13 = _mm_mul_ps(v12, v7);
  v14 = _mm_mul_ps(v12, v9);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_mul_ps(v9, v9);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v19 = _mm_mul_ps(v7, v7);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v20, v18), _mm_mul_ps(v11, v11)), *(__m128 *)&epsilon);
  v22 = _mm_rcp_ps(v21);
  v23 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v21)), v22);
  v24 = _mm_rcp_ps(v20);
  v25 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v24, v20)), v24);
  v26 = _mm_rcp_ps(v18);
  v27 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v26, v18)), v26);
  v28 = _mm_sub_ps(_mm_mul_ps(v20, v15), _mm_mul_ps(v17, v11));
  v29 = _mm_cmplt_ps(v28, v21);
  v30 = _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v29, v28), _mm_andnot_ps(v29, v21))), v23);
  v31 = _mm_cmple_ps(v21, *(__m128 *)&epsilon);
  v32 = _mm_sub_ps(
          _mm_mul_ps(_mm_or_ps(_mm_andnot_ps(v31, v30), _mm_and_ps(v31, query.m_quad)), _mm_mul_ps(v25, v11)),
          _mm_mul_ps(v25, v17));
  v33 = _mm_cmplt_ps(v32, query.m_quad);
  v34 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v33, query.m_quad), _mm_and_ps(v32, v33)));
  v35 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v27, v11), v34), _mm_mul_ps(v27, v15));
  v36 = _mm_cmplt_ps(v35, query.m_quad);
  v63 = _mm_add_ps(
          _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v36, query.m_quad), _mm_and_ps(v36, v35))), v9),
          capsA->m_quad);
  v37 = _mm_sub_ps(v63, _mm_add_ps(_mm_mul_ps(v34, v62), capsB->m_quad));
  v38 = _mm_mul_ps(v37, v37);
  v39 = _mm_shuffle_ps((__m128)*(unsigned int *)capsBRadius, (__m128)*(unsigned int *)capsBRadius, 0);
  v40 = _mm_add_ps(_mm_shuffle_ps((__m128)*(unsigned int *)capsARadius, (__m128)*(unsigned int *)capsARadius, 0), v39);
  v41 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)), _mm_shuffle_ps(v38, v38, 170));
  v42 = _mm_shuffle_ps((__m128)LODWORD(collisionTolerance), (__m128)LODWORD(collisionTolerance), 0).m128_f32[0]
      + v40.m128_f32[0];
  if ( v41.m128_f32[0] <= (float)(v42 * v42) )
  {
    v44 = _mm_rsqrt_ps(v41);
    v45 = _mm_andnot_ps(
            _mm_cmple_ps(v41, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v44), v44)),
                _mm_mul_ps(*(__m128 *)_xmm, v44)),
              v41));
    if ( v41.m128_f32[0] <= 0.0 )
    {
      v47 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v62, v62, 201), v9), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v62));
      v48 = _mm_shuffle_ps(v47, v47, 201);
      v49 = _mm_mul_ps(v48, v48);
      if ( (float)((float)(_mm_shuffle_ps(v49, v49, 85).m128_f32[0] + _mm_shuffle_ps(v49, v49, 0).m128_f32[0])
                 + _mm_shuffle_ps(v49, v49, 170).m128_f32[0]) <= 0.00000011920929 )
      {
        v51 = _mm_shuffle_ps(v9, _mm_unpackhi_ps(v9, (__m128)0i64), 196);
        v52 = _mm_shuffle_ps(v51, v51, 241);
        v53 = _mm_shuffle_ps(v51, v51, 206);
        v54 = _mm_mul_ps(v53, v53);
        v55 = _mm_mul_ps(v52, v52);
        v56 = _mm_cmplt_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                  _mm_shuffle_ps(v55, v55, 170)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
                  _mm_shuffle_ps(v54, v54, 170)));
        v46 = _mm_xor_ps(
                _mm_or_ps(_mm_andnot_ps(v56, v52), _mm_and_ps(v53, v56)),
                (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
      }
      else
      {
        v50 = _mm_mul_ps(v48, v37);
        v46 = _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32(
                            (__m128i)_mm_cmplt_ps(
                                       _mm_add_ps(
                                         _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
                                         _mm_shuffle_ps(v50, v50, 170)),
                                       (__m128)0i64),
                            0x1Fu),
                          0x1Fu),
                v48);
      }
    }
    else
    {
      v46 = v37;
    }
    result->m_enum = HK_SUCCESS;
    v57 = _mm_mul_ps(v46, v46);
    v58 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
            _mm_shuffle_ps(v57, v57, 170));
    v59 = _mm_rsqrt_ps(v58);
    v60 = _mm_mul_ps(
            v46,
            _mm_andnot_ps(
              _mm_cmple_ps(v58, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v59, v58), v59)),
                _mm_mul_ps(v59, *(__m128 *)_xmm))));
    m_quad = _mm_shuffle_ps(v60, _mm_unpackhi_ps(v60, _mm_sub_ps(v45, v40)), 196);
    v43 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v39, v45), m_quad), v63);
  }
  else
  {
    v43 = cpoint->m_position.m_quad;
    result->m_enum = HK_FAILURE;
  }
  v61 = result;
  cpoint->m_separatingNormal.m_quad = m_quad;
  cpoint->m_position.m_quad = v43;
  return v61;
}

// File Line: 32
// RVA: 0xD408D0
void __fastcall hkCollideCapsuleUtil_calcTrianglePlaneDirections(
        hkVector4f *tri,
        hkpCollideTriangleUtil::PointTriangleDistanceCache *cache,
        hkTransformf *planeEquationsOut,
        hkVector4f *normalOut)
{
  __m128 v4; // xmm2
  __m128 v5; // xmm4
  __m128 v6; // xmm6
  __m128 m_quad; // xmm7
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm3
  float v12; // xmm8_4
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm7
  hkVector4f v16; // xmm5
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm4
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  hkVector4f v25; // xmm0
  hkVector4f v26; // xmm3
  hkVector4f v27; // xmm1

  v4 = *(__m128 *)cache->m_invEdgeLen;
  v5 = _mm_sub_ps(tri->m_quad, tri[2].m_quad);
  v6 = _mm_shuffle_ps(*(__m128 *)cache->m_invEdgeLen, *(__m128 *)cache->m_invEdgeLen, 0);
  m_quad = tri[1].m_quad;
  v8 = _mm_sub_ps(tri[2].m_quad, m_quad);
  v9 = _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v8);
  v10 = _mm_shuffle_ps(v8, v8, 201);
  v11 = _mm_mul_ps(v8, v6);
  v12 = _mm_shuffle_ps((__m128)LODWORD(cache->m_normalLen), (__m128)LODWORD(cache->m_normalLen), 0).m128_f32[0];
  v13 = _mm_sub_ps(v9, _mm_mul_ps(v10, v5));
  v14 = _mm_mul_ps(v5, _mm_shuffle_ps(*(__m128 *)cache->m_invEdgeLen, *(__m128 *)cache->m_invEdgeLen, 85));
  v15 = _mm_mul_ps(_mm_sub_ps(m_quad, tri->m_quad), _mm_shuffle_ps(v4, v4, 170));
  v16.m_quad = _mm_mul_ps(_mm_shuffle_ps(v4, v4, 255), _mm_shuffle_ps(v13, v13, 201));
  *normalOut = (hkVector4f)v16.m_quad;
  v17 = _mm_shuffle_ps(v16.m_quad, v16.m_quad, 201);
  v18 = _mm_sub_ps(_mm_mul_ps(v17, v11), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v16.m_quad));
  planeEquationsOut->m_rotation.m_col0.m_quad = _mm_shuffle_ps(v18, v18, 201);
  v19 = _mm_sub_ps(_mm_mul_ps(v17, v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v16.m_quad));
  planeEquationsOut->m_rotation.m_col1.m_quad = _mm_shuffle_ps(v19, v19, 201);
  v20 = _mm_sub_ps(_mm_mul_ps(v17, v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v16.m_quad));
  planeEquationsOut->m_rotation.m_col2.m_quad = _mm_shuffle_ps(v20, v20, 201);
  planeEquationsOut->m_translation = (hkVector4f)v16.m_quad;
  v21 = _mm_shuffle_ps(planeEquationsOut->m_rotation.m_col0.m_quad, planeEquationsOut->m_rotation.m_col1.m_quad, 238);
  v22 = _mm_shuffle_ps(planeEquationsOut->m_rotation.m_col0.m_quad, planeEquationsOut->m_rotation.m_col1.m_quad, 68);
  v23 = _mm_shuffle_ps(planeEquationsOut->m_rotation.m_col2.m_quad, v16.m_quad, 68);
  v24 = _mm_shuffle_ps(planeEquationsOut->m_rotation.m_col2.m_quad, v16.m_quad, 238);
  v25.m_quad = _mm_shuffle_ps(v22, v23, 136);
  v26.m_quad = _mm_shuffle_ps(v22, v23, 221);
  v27.m_quad = 0i64;
  planeEquationsOut->m_rotation.m_col0 = (hkVector4f)v25.m_quad;
  planeEquationsOut->m_rotation.m_col1 = (hkVector4f)v26.m_quad;
  planeEquationsOut->m_rotation.m_col2.m_quad = _mm_shuffle_ps(v21, v24, 136);
  v27.m_quad.m128_f32[0] = (float)(0.0 - v6.m128_f32[0]) * v12;
  planeEquationsOut->m_translation = (hkVector4f)v27.m_quad;
}

// File Line: 68
// RVA: 0xD3FBE0
void __fastcall hkCollideCapsuleUtilCapsVsTri(
        hkVector4f *capsAPoints,
        float capsARadius,
        hkVector4f *triVertices,
        float triBRadius,
        hkpCollideTriangleUtil::PointTriangleDistanceCache *cache,
        float collisionTolerance,
        int searchManifold,
        hkContactPoint *points,
        hkpFeatureOutput *featuresOut)
{
  hkpCollideTriangleUtil::PointTriangleDistanceCache *v9; // rbx
  hkVector4f *v10; // r11
  hkVector4f *v11; // rdx
  __m128 m_quad; // xmm6
  __m128 v15; // xmm2
  int v16; // r13d
  __m128 v17; // xmm5
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  __m128 v21; // xmm11
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm11
  __m128 v25; // xmm11
  __m128 v26; // xmm3
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 v29; // xmm7
  __m128 v30; // xmm7
  __m128 v31; // xmm1
  __m128 v32; // xmm1
  __m128 v33; // xmm5
  __m128 v34; // xmm3
  __m128 v35; // xmm7
  __m128 v36; // xmm0
  __m128 v37; // xmm5
  __m128 v38; // xmm0
  __m128 v39; // xmm7
  __m128 v40; // xmm9
  __m128 v41; // xmm3
  __m128 v42; // xmm0
  __m128 *v43; // rax
  __m128 v44; // xmm4
  __m128 v45; // xmm1
  __int64 v46; // rcx
  __m128 v47; // xmm1
  hkContactPoint *v48; // rdi
  __m128 v49; // xmm14
  __m128 v50; // xmm6
  hkVector4f v51; // xmm1
  __m128 v52; // xmm9
  __m128 v53; // xmm3
  __m128 v54; // xmm2
  __m128 v55; // xmm2
  __m128 v56; // xmm4
  int v57; // eax
  __m128 v58; // xmm5
  __m128 v59; // xmm2
  int v60; // r10d
  int v61; // ecx
  __m128 v62; // xmm7
  __m128 v63; // xmm0
  __m128 v64; // xmm15
  __m128 v65; // xmm14
  __m128 v66; // xmm1
  __m128 v67; // xmm2
  __m128 *p_m_quad; // rcx
  hkContactPoint **v69; // r8
  __int64 v70; // r11
  float v71; // xmm1_4
  __m128i v72; // xmm2
  __m128 v73; // xmm3
  __m128 v74; // xmm0
  __m128 v75; // xmm0
  __m128 v76; // xmm1
  __m128 *v77; // rax
  __int128 *v78; // rcx
  __int64 v79; // r8
  __m128 v80; // xmm13
  __m128 v81; // xmm4
  __m128 v82; // xmm0
  __m128 v83; // xmm1
  __m128 v84; // xmm5
  __m128 v85; // xmm2
  __m128 v86; // xmm1
  __m128 v87; // xmm0
  __m128 v88; // xmm2
  __m128 v89; // xmm4
  __m128 v90; // xmm0
  __m128 v91; // xmm10
  __m128 v92; // xmm10
  __m128 v93; // xmm0
  __m128 v94; // xmm8
  __m128 v95; // xmm0
  __m128 v96; // xmm7
  __m128 v97; // xmm1
  __m128 v98; // xmm3
  __m128 v99; // xmm2
  __m128 v100; // xmm1
  __m128 v101; // xmm6
  __m128 v102; // xmm3
  __m128 v103; // xmm2
  float v104; // xmm7_4
  __int64 v105; // r14
  int v106; // r12d
  char v107; // r9
  __m128 v108; // xmm0
  int v109; // r8d
  __m128 v110; // xmm3
  __m128 v111; // xmm7
  __m128 v112; // xmm6
  __int16 v113; // r12
  __int64 v114; // r15
  char v115; // al
  int v116; // eax
  int v117; // r12d
  __int64 v118; // rsi
  __int128 *v119; // r15
  bool v120; // zf
  __int64 v121; // rcx
  __m128 v122; // xmm2
  __m128 v123; // xmm1
  __m128 v124; // xmm0
  hkVector4f *v125; // r8
  int v126; // eax
  float v127; // xmm1_4
  hkVector4f v128; // xmm6
  __m128 v129; // xmm5
  __m128 v130; // xmm5
  __m128 v131; // xmm5
  __m128 v132; // xmm2
  __m128 v133; // xmm1
  __m128 v134; // xmm2
  __m128 v135; // xmm3
  __m128 v136; // xmm5
  __m128 v137; // xmm6
  __m128i v138; // xmm1
  __m128 v139; // xmm0
  __m128 v140; // xmm5
  __m128 v141; // xmm1
  hkVector4f capsBPoints; // [rsp+30h] [rbp-B0h] BYREF
  __m128 v143; // [rsp+40h] [rbp-A0h] BYREF
  hkVector4f dA; // [rsp+50h] [rbp-90h] BYREF
  hkVector4f dB; // [rsp+60h] [rbp-80h] BYREF
  __int128 v146[2]; // [rsp+70h] [rbp-70h] BYREF
  hkLineSegmentUtil::ClosestLineSegLineSegResult result; // [rsp+90h] [rbp-50h] BYREF
  hkVector4f *A; // [rsp+1D0h] [rbp+F0h]
  int v149; // [rsp+1D8h] [rbp+F8h]
  hkVector4f *vars0; // [rsp+1E0h] [rbp+100h]
  void *retaddr; // [rsp+1E8h] [rbp+108h]
  int v152; // [rsp+1F0h] [rbp+110h]
  __int16 v153; // [rsp+1F0h] [rbp+110h]
  float v154; // [rsp+1F8h] [rbp+118h]
  __int16 v155; // [rsp+1F8h] [rbp+118h]
  int v156; // [rsp+200h] [rbp+120h]
  hkContactPoint *v157; // [rsp+208h] [rbp+128h] BYREF

  *(float *)&v157 = triBRadius;
  v156 = (int)triVertices;
  v9 = cache;
  v10 = triVertices;
  v11 = capsAPoints;
  if ( cache )
  {
    LOBYTE(cache->m_invEdgeLen[0]) = 0;
    LOBYTE(v9->m_invEdgeLen[2]) = 0;
    LOBYTE(v9->m_normalLen) = 0;
  }
  m_quad = triVertices->m_quad;
  v15 = triVertices[1].m_quad;
  v16 = 1;
  v17 = capsAPoints->m_quad;
  v18 = _mm_sub_ps(triVertices->m_quad, triVertices[2].m_quad);
  v19 = _mm_sub_ps(triVertices[2].m_quad, v15);
  v20 = _mm_shuffle_ps(v17, v17, 0);
  v21 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v19);
  v22 = _mm_shuffle_ps(v19, v19, 201);
  v23 = _mm_mul_ps(v19, v20);
  v24 = _mm_sub_ps(v21, _mm_mul_ps(v22, v18));
  v25 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), _mm_shuffle_ps(capsAPoints->m_quad, capsAPoints->m_quad, 255));
  v26 = _mm_mul_ps(v18, _mm_shuffle_ps(capsAPoints->m_quad, capsAPoints->m_quad, 85));
  v27 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), _mm_sub_ps(v15, triVertices->m_quad));
  v28 = _mm_shuffle_ps(v25, v25, 201);
  v29 = _mm_sub_ps(_mm_mul_ps(v28, v23), _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v25));
  v30 = _mm_shuffle_ps(v29, v29, 201);
  v31 = _mm_sub_ps(_mm_mul_ps(v28, v26), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v25));
  v32 = _mm_shuffle_ps(v31, v31, 201);
  v33 = _mm_sub_ps(_mm_mul_ps(v27, v28), _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v25));
  v34 = _mm_shuffle_ps(v30, v32, 68);
  v35 = _mm_shuffle_ps(v30, v32, 238);
  v32.m128_f32[0] = 0.0 - v20.m128_f32[0];
  v44 = 0i64;
  v36 = _mm_shuffle_ps(v33, v33, 201);
  v37 = _mm_shuffle_ps(v36, v25, 238);
  v38 = _mm_shuffle_ps(v36, v25, 68);
  v39 = _mm_shuffle_ps(v35, v37, 136);
  v146[0] = (__int128)v39;
  v40 = _mm_shuffle_ps(v34, v38, 136);
  v41 = _mm_shuffle_ps(v34, v38, 221);
  v42 = (__m128)capsAPoints[1].m_quad.m128_u32[0];
  v43 = &v143;
  v146[0] = (__int128)v40;
  dB.m_quad = v41;
  v44.m128_f32[0] = v32.m128_f32[0] * _mm_shuffle_ps(v42, v42, 0).m128_f32[0];
  v45 = capsAPoints[1].m_quad;
  capsBPoints.m_quad = _mm_sub_ps(capsAPoints->m_quad, m_quad);
  v46 = 1i64;
  v146[1] = (__int128)v44;
  v143 = _mm_sub_ps(v45, m_quad);
  do
  {
    v47 = *v43--;
    --v46;
    v43[1] = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v47, v47, 85), v41), _mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), v40)),
                 _mm_mul_ps(_mm_shuffle_ps(v47, v47, 170), v39)),
               v44);
  }
  while ( v46 >= 0 );
  v48 = v157;
  v49 = v143;
  v50 = capsBPoints.m_quad;
  v51.m_quad = (__m128)v157->m_separatingNormal;
  v149 = LODWORD(FLOAT_1_8446726e19);
  v52 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT(capsARadius + triBRadius),
          (__m128)COERCE_UNSIGNED_INT(capsARadius + triBRadius),
          0);
  v53 = _mm_sub_ps(
          _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_8446726e19), (__m128)LODWORD(FLOAT_1_8446726e19), 0),
          _mm_add_ps(v52, v52));
  v157->m_separatingNormal.m_quad = _mm_shuffle_ps(v51.m_quad, _mm_unpackhi_ps(v51.m_quad, v53), 196);
  v54 = _mm_shuffle_ps(v48[1].m_separatingNormal.m_quad, _mm_unpackhi_ps(v48[1].m_separatingNormal.m_quad, v53), 196);
  v48[1].m_separatingNormal.m_quad = v54;
  v54.m128_f32[0] = (float)(capsARadius + triBRadius) + v154;
  v55 = _mm_shuffle_ps(v54, v54, 0);
  v56 = _mm_cmplt_ps(v55, v49);
  v48[2].m_separatingNormal.m_quad = _mm_shuffle_ps(
                                       v48[2].m_separatingNormal.m_quad,
                                       _mm_unpackhi_ps(v48[2].m_separatingNormal.m_quad, v53),
                                       196);
  v57 = _mm_movemask_ps(_mm_and_ps(_mm_cmplt_ps(v55, v50), v56));
  v58 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  v59 = _mm_xor_ps(v55, v58);
  if ( v57 | _mm_movemask_ps(_mm_and_ps(_mm_cmplt_ps(v49, v59), _mm_cmplt_ps(v50, v59))) & 8 )
    return;
  v60 = _mm_movemask_ps(_mm_cmplt_ps(v49, (__m128)0i64));
  v61 = _mm_movemask_ps(_mm_cmplt_ps(v50, (__m128)0i64));
  v157 = (hkContactPoint *)__PAIR64__(v60, v61);
  if ( (((unsigned __int8)v61 ^ (unsigned __int8)v60) & 8) != 0 )
  {
    v62 = (__m128)_xmm;
    v63 = _mm_shuffle_ps(v49, v49, 255);
    v64 = _mm_shuffle_ps(v50, v50, 255);
    v65 = _mm_sub_ps(v49, v50);
    v66 = _mm_sub_ps(v64, v63);
    v67 = _mm_rcp_ps(v66);
    if ( (_mm_movemask_ps(
            _mm_cmplt_ps(
              _mm_add_ps(
                _mm_mul_ps(v65, _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v67, v66)), v67), v64)),
                v50),
              (__m128)0i64)) & 7) == 7 )
    {
      p_m_quad = &v11->m_quad;
      v69 = &v157;
      v70 = 2i64;
      v48[1].m_separatingNormal.m_quad = _mm_shuffle_ps(
                                           v48[1].m_separatingNormal.m_quad,
                                           _mm_unpackhi_ps(v48[1].m_separatingNormal.m_quad, (__m128)xmmword_141A712F0),
                                           196);
      v71 = *(float *)&retaddr;
      do
      {
        if ( (*(_BYTE *)v69 & 7) == 7 )
        {
          v72 = (__m128i)_mm_shuffle_ps(
                           *(__m128 *)((char *)p_m_quad + (char *)&capsBPoints - (char *)v11),
                           *(__m128 *)((char *)p_m_quad + (char *)&capsBPoints - (char *)v11),
                           255);
          v73 = _mm_sub_ps(_mm_sub_ps((__m128)0i64, (__m128)_mm_srli_epi32(_mm_slli_epi32(v72, 1u), 1u)), v52);
          v74 = _mm_shuffle_ps(v48[1].m_separatingNormal.m_quad, v48[1].m_separatingNormal.m_quad, 255);
          if ( v73.m128_f32[0] > v74.m128_f32[0] )
          {
            v74.m128_f32[0] = v71;
            v75 = _mm_shuffle_ps(v74, v74, 0);
            if ( (*(_DWORD *)v69 & 8) != 0 )
            {
              v48[1].m_separatingNormal.m_quad = v25;
              v48[1].m_position.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v75, (__m128)v72), v25), *p_m_quad);
            }
            else
            {
              v76 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_sub_ps((__m128)0i64, v75), (__m128)v72), v25), *p_m_quad);
              v48[1].m_separatingNormal.m_quad = _mm_xor_ps(v25, v58);
              v48[1].m_position.m_quad = v76;
            }
            v48[1].m_separatingNormal.m_quad = _mm_shuffle_ps(
                                                 v48[1].m_separatingNormal.m_quad,
                                                 _mm_unpackhi_ps(v48[1].m_separatingNormal.m_quad, v73),
                                                 196);
            v71 = *(float *)&retaddr;
          }
        }
        v69 = (hkContactPoint **)((char *)v69 + 4);
        ++p_m_quad;
        --v70;
      }
      while ( v70 );
      v77 = (__m128 *)`hkVector4f::getComponent::`2::indexToMask;
      v78 = v146;
      v79 = 3i64;
      v80 = _mm_shuffle_ps(v65, v65, 255);
      v81 = _mm_mul_ps(v80, v80);
      dA.m_quad = v81;
      do
      {
        v82 = _mm_and_ps(v65, *v77);
        v83 = _mm_or_ps(_mm_shuffle_ps(v82, v82, 78), v82);
        v84 = _mm_or_ps(_mm_shuffle_ps(v83, v83, 177), v83);
        v85 = _mm_add_ps(_mm_mul_ps(v84, v84), v81);
        v86 = _mm_rcp_ps(v85);
        v87 = _mm_mul_ps(v86, v85);
        v88 = _mm_and_ps(v50, *v77);
        v89 = _mm_mul_ps(_mm_sub_ps(v62, v87), v86);
        v90 = _mm_or_ps(_mm_shuffle_ps(v88, v88, 78), v88);
        v91 = _mm_sub_ps(_mm_mul_ps(v64, v84), _mm_mul_ps(_mm_or_ps(_mm_shuffle_ps(v90, v90, 177), v90), v80));
        v90.m128_f32[0] = _mm_shuffle_ps(v48[1].m_separatingNormal.m_quad, v48[1].m_separatingNormal.m_quad, 255).m128_f32[0]
                        + v52.m128_f32[0];
        v92 = _mm_mul_ps(_mm_mul_ps(v91, v91), v89);
        if ( v92.m128_f32[0] < (float)(v90.m128_f32[0] * v90.m128_f32[0]) )
        {
          v93 = _mm_or_ps(_mm_shuffle_ps(v88, v88, 78), v88);
          v94 = _mm_mul_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_or_ps(_mm_shuffle_ps(v93, v93, 177), v93), v84), _mm_mul_ps(v64, v80)),
                  _mm_sub_ps((__m128)0i64, v89));
          if ( v94.m128_f32[0] > _mm_shuffle_ps((__m128)0xB8D1B717, (__m128)0xB8D1B717, 0).m128_f32[0] )
          {
            v149 = 1065354055;
            if ( v94.m128_f32[0] < _mm_shuffle_ps((__m128)0x3F800347u, (__m128)0x3F800347u, 0).m128_f32[0] )
            {
              v95 = (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmplt_ps(v80, (__m128)0i64), 0x1Fu), 0x1Fu);
              v96 = _mm_add_ps(
                      _mm_mul_ps(_mm_sub_ps((__m128)0i64, _mm_xor_ps(v95, v84)), v25),
                      _mm_mul_ps(
                        _mm_unpacklo_ps(
                          _mm_unpacklo_ps((__m128)*((unsigned int *)v78 - 8), (__m128)*(unsigned int *)v78),
                          _mm_unpacklo_ps((__m128)*((unsigned int *)v78 - 4), (__m128)0i64)),
                        _mm_xor_ps(v95, v80)));
              v97 = _mm_mul_ps(v96, v96);
              v98 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v97, v97, 85), _mm_shuffle_ps(v97, v97, 0)),
                      _mm_shuffle_ps(v97, v97, 170));
              v99 = _mm_rsqrt_ps(v98);
              v100 = _mm_rsqrt_ps(v92);
              v101 = _mm_mul_ps(
                       _mm_andnot_ps(
                         _mm_cmple_ps(v98, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v99, v98), v99)),
                           _mm_mul_ps(*(__m128 *)_xmm, v99))),
                       v96);
              v62 = (__m128)_xmm;
              v48[1].m_separatingNormal.m_quad = v101;
              v102 = _mm_sub_ps(
                       (__m128)0i64,
                       _mm_andnot_ps(
                         _mm_cmple_ps(v92, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v100, v92), v100)),
                             _mm_mul_ps(*(__m128 *)_xmm, v100)),
                           v92)));
              v103 = _mm_mul_ps(
                       _mm_sub_ps(_mm_shuffle_ps((__m128)(unsigned int)retaddr, (__m128)(unsigned int)retaddr, 0), v102),
                       v101);
              v50 = capsBPoints.m_quad;
              v48[1].m_position.m_quad = _mm_add_ps(
                                           v103,
                                           _mm_add_ps(
                                             _mm_mul_ps(_mm_sub_ps(v11[1].m_quad, v11->m_quad), v94),
                                             v11->m_quad));
              v48[1].m_separatingNormal.m_quad = _mm_shuffle_ps(
                                                   v48[1].m_separatingNormal.m_quad,
                                                   _mm_unpackhi_ps(
                                                     v48[1].m_separatingNormal.m_quad,
                                                     _mm_sub_ps(v102, v52)),
                                                   196);
            }
          }
        }
        v81 = dA.m_quad;
        ++v77;
        v78 = (__int128 *)((char *)v78 + 4);
        --v79;
      }
      while ( v79 );
      if ( v9 )
      {
        LOBYTE(v9->m_invEdgeLen[0]) = 3;
        *(_DWORD *)((char *)v9->m_invEdgeLen + 2) = 0x10000;
        HIWORD(v9->m_invEdgeLen[1]) = 2;
        LOBYTE(v9->m_invEdgeLen[2]) = 3;
        *(_DWORD *)((char *)&v9->m_invEdgeLen[2] + 2) = 0x10000;
        HIWORD(v9->m_invNormalLen) = 2;
        LOBYTE(v9->m_normalLen) = 3;
        *(_DWORD *)((char *)&v9->m_normalLen + 2) = 0x10000;
        HIWORD(v9[1].m_invEdgeLen[0]) = 2;
      }
      return;
    }
  }
  v104 = *(float *)&retaddr;
  v105 = 0i64;
  v106 = v61 | v60;
  v107 = 0;
  v108 = _mm_sub_ps(v11[1].m_quad, v11->m_quad);
  v109 = 0;
  LODWORD(cache) = 0;
  dA.m_quad = v108;
  LOBYTE(v149) = 0;
  v152 = v61 | v60;
  if ( (((unsigned __int8)v61 | (unsigned __int8)v60) & 7) == 7 )
    goto LABEL_47;
  if ( v156 )
  {
    v110 = _mm_shuffle_ps((__m128)LODWORD(v154), (__m128)LODWORD(v154), 0);
    v48->m_separatingNormal.m_quad = _mm_shuffle_ps(
                                       v48->m_separatingNormal.m_quad,
                                       _mm_unpackhi_ps(v48->m_separatingNormal.m_quad, v110),
                                       196);
    v48[1].m_separatingNormal.m_quad = _mm_shuffle_ps(
                                         v48[1].m_separatingNormal.m_quad,
                                         _mm_unpackhi_ps(v48[1].m_separatingNormal.m_quad, v110),
                                         196);
    v48[2].m_separatingNormal.m_quad = _mm_shuffle_ps(
                                         v48[2].m_separatingNormal.m_quad,
                                         _mm_unpackhi_ps(v48[2].m_separatingNormal.m_quad, v110),
                                         196);
    v111 = aabbOut.m_quad;
    v112 = _mm_shuffle_ps(aabbOut.m_quad, _mm_unpackhi_ps(aabbOut.m_quad, (__m128)xmmword_141A712A0), 196);
    do
    {
      if ( (v16 & v106) == 0 )
      {
        v113 = hkpCollideTriangleUtil::vertexToEdgeLut[v105 + 2];
        v114 = hkpCollideTriangleUtil::vertexToEdgeLut[v105];
        capsBPoints.m_quad = (__m128)v10[hkpCollideTriangleUtil::vertexToEdgeLut[v105 + 2]];
        v143 = v10[v114].m_quad;
        v115 = hkLineSegmentUtil::capsuleCapsuleManifold(v11, capsARadius, &capsBPoints, triBRadius, v48);
        if ( v9 )
        {
          HIWORD(v9->m_invEdgeLen[0]) = v113;
          v116 = v115 & 0xC;
          if ( v116 )
          {
            LOBYTE(v9->m_invEdgeLen[0]) = 1;
          }
          else
          {
            LOBYTE(v9->m_invEdgeLen[0]) = 2;
            LOWORD(v9->m_invEdgeLen[1]) = v114;
          }
          HIWORD(v9->m_invEdgeLen[2]) = v113;
          if ( v116 )
          {
            LOBYTE(v9->m_invEdgeLen[2]) = 1;
          }
          else
          {
            LOBYTE(v9->m_invEdgeLen[2]) = 2;
            LOWORD(v9->m_invNormalLen) = v114;
          }
          HIWORD(v9->m_normalLen) = v113;
          if ( v116 )
          {
            LOBYTE(v9->m_normalLen) = 1;
          }
          else
          {
            LOBYTE(v9->m_normalLen) = 2;
            LOWORD(v9[1].m_invEdgeLen[0]) = v114;
          }
        }
        v10 = vars0;
        v11 = A;
        v106 = v152;
        if ( _mm_shuffle_ps(v48->m_separatingNormal.m_quad, v48->m_separatingNormal.m_quad, 255).m128_f32[0] <= _mm_shuffle_ps(v112, v112, 255).m128_f32[0] )
        {
          v111 = v48->m_position.m_quad;
          v112 = v48->m_separatingNormal.m_quad;
        }
        else
        {
          v48->m_position.m_quad = v111;
          v48->m_separatingNormal.m_quad = v112;
        }
      }
      ++v105;
      v16 *= 2;
    }
    while ( v105 < 3 );
    return;
  }
  v107 = 1;
  LOBYTE(v149) = 1;
$checkSingleSecondPoint:
  v117 = 1;
  v118 = v109;
  v119 = v146;
  LODWORD(retaddr) = __ROL4__(1, v109);
  do
  {
    if ( v107 )
      v120 = ((unsigned int)v157 & HIDWORD(v157) & v117) == 0;
    else
      v120 = (v117 & *((_DWORD *)&v157 + v118)) == 0;
    if ( v120 )
    {
      v155 = hkpCollideTriangleUtil::vertexToEdgeLut[v105 + 2];
      v153 = hkpCollideTriangleUtil::vertexToEdgeLut[v105];
      v125 = &v10[hkpCollideTriangleUtil::vertexToEdgeLut[v105 + 2]];
      dB.m_quad = _mm_sub_ps(v10[hkpCollideTriangleUtil::vertexToEdgeLut[v105]].m_quad, v125->m_quad);
      v126 = hkLineSegmentUtil::closestLineSegLineSeg(A, &dA, v125, &dB, &result);
      if ( v9 )
      {
        HIWORD(v9->m_invEdgeLen[2 * v118]) = v155;
        if ( (v126 & 0xC) != 0 )
        {
          LOBYTE(v9->m_invEdgeLen[2 * v118]) = 1;
        }
        else
        {
          LOBYTE(v9->m_invEdgeLen[2 * v118]) = 2;
          LOWORD(v9->m_invEdgeLen[2 * v118 + 1]) = v153;
        }
      }
      v107 = v149;
      v108 = _mm_shuffle_ps(
               (__m128)LODWORD(result.m_distanceSquared.m_storage),
               (__m128)LODWORD(result.m_distanceSquared.m_storage),
               0);
      v127 = _mm_shuffle_ps(v48->m_separatingNormal.m_quad, v48->m_separatingNormal.m_quad, 255).m128_f32[0]
           + v52.m128_f32[0];
      if ( v108.m128_f32[0] < (float)(v127 * v127) )
      {
        if ( (v126 & (unsigned int)retaddr) == 0 )
        {
          v109 = (int)cache;
LABEL_65:
          if ( !v126 )
          {
            v128.m_quad = (__m128)result.m_closestAminusClosestB;
            v129 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(dB.m_quad, dB.m_quad, 201), dA.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(dA.m_quad, dA.m_quad, 201), dB.m_quad));
            v130 = _mm_shuffle_ps(v129, v129, 201);
LABEL_72:
            v133 = _mm_mul_ps(v130, v130);
            v134 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v133, v133, 85), _mm_shuffle_ps(v133, v133, 0)),
                     _mm_shuffle_ps(v133, v133, 170));
            v135 = _mm_rsqrt_ps(v134);
            v56 = _mm_andnot_ps(
                    _mm_cmple_ps(v134, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v135, v134), v135)),
                      _mm_mul_ps(*(__m128 *)_xmm, v135)));
            v136 = _mm_mul_ps(v130, v56);
            v137 = _mm_mul_ps(v128.m_quad, v136);
            v138 = (__m128i)_mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v137, v137, 85), _mm_shuffle_ps(v137, v137, 0)),
                              _mm_shuffle_ps(v137, v137, 170));
            v139 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v138, 0x1Fu), 0x1Fu);
            v140 = _mm_xor_ps(v136, v139);
            v141 = _mm_xor_ps((__m128)v138, v139);
            v139.m128_f32[0] = v104;
            v48->m_position.m_quad = _mm_add_ps(
                                       _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v139, v139, 0), v141), v140),
                                       result.m_closestPointA.m_quad);
            v108 = _mm_unpackhi_ps(v140, _mm_sub_ps(v141, v52));
            v48->m_separatingNormal.m_quad = _mm_shuffle_ps(v140, v108, 196);
LABEL_74:
            v10 = vars0;
            goto LABEL_75;
          }
          if ( _mm_shuffle_ps(
                 (__m128)LODWORD(result.m_distanceSquared.m_storage),
                 (__m128)LODWORD(result.m_distanceSquared.m_storage),
                 0).m128_f32[0] > 1.4210855e-14 )
          {
            v128.m_quad = (__m128)result.m_closestAminusClosestB;
          }
          else
          {
            v128.m_quad = _mm_unpacklo_ps(
                            _mm_unpacklo_ps((__m128)*((unsigned int *)v119 - 8), (__m128)*(unsigned int *)v119),
                            _mm_unpacklo_ps((__m128)*((unsigned int *)v119 - 4), (__m128)0i64));
            v131 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(dB.m_quad, dB.m_quad, 201), dA.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(dA.m_quad, dA.m_quad, 201), dB.m_quad));
            v130 = _mm_shuffle_ps(v131, v131, 201);
            v132 = _mm_mul_ps(v130, v130);
            if ( (float)((float)(_mm_shuffle_ps(v132, v132, 85).m128_f32[0] + _mm_shuffle_ps(v132, v132, 0).m128_f32[0])
                       + _mm_shuffle_ps(v132, v132, 170).m128_f32[0]) > 1.4210855e-14 )
              goto LABEL_72;
          }
          v130 = v128.m_quad;
          goto LABEL_72;
        }
        if ( (_BYTE)v149 )
        {
          v109 = 1;
          LODWORD(cache) = 1;
          LODWORD(retaddr) = 2;
          v118 = 1i64;
          goto LABEL_65;
        }
      }
      v109 = (int)cache;
      goto LABEL_74;
    }
LABEL_75:
    ++v105;
    v117 *= 2;
    v119 = (__int128 *)((char *)v119 + 4);
  }
  while ( v105 < 3 );
  if ( !v107 )
  {
    v11 = A;
    v105 = 0i64;
LABEL_78:
    ++v48;
    LODWORD(cache) = ++v109;
LABEL_47:
    while ( v109 < 2 )
    {
      v121 = v109;
      if ( (*((_BYTE *)&v157 + 4 * v109) & 7) != 7 )
        goto $checkSingleSecondPoint;
      if ( (*((_DWORD *)&v157 + v109) & 8) != 0 )
      {
        v108.m128_f32[0] = v104;
        v122 = _mm_shuffle_ps(*(&capsBPoints.m_quad + v109), *(&capsBPoints.m_quad + v109), 255);
        v56 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(_mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v108, v108, 0)), v122), v25),
                v11[v109].m_quad);
        v123 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v25);
        v108 = _mm_unpackhi_ps(v123, _mm_sub_ps(_mm_sub_ps((__m128)0i64, v122), v52));
        v48->m_separatingNormal.m_quad = _mm_shuffle_ps(v123, v108, 196);
      }
      else
      {
        v56.m128_f32[0] = v104;
        v124 = _mm_shuffle_ps(*(&capsBPoints.m_quad + v109), *(&capsBPoints.m_quad + v109), 255);
        v56 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v56, v56, 0), v124), v25), v11[v109].m_quad);
        v108 = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, _mm_sub_ps(v124, v52)), 196);
        v48->m_separatingNormal.m_quad = v108;
      }
      v48->m_position.m_quad = v56;
      if ( !v9 )
        goto LABEL_78;
      LOBYTE(v9->m_invEdgeLen[2 * v109]) = 3;
      ++v48;
      ++v109;
      *(_DWORD *)((char *)&v9->m_invEdgeLen[2 * v121] + 2) = 0x10000;
      HIWORD(v9->m_invEdgeLen[2 * v121 + 1]) = 2;
      LODWORD(cache) = v109;
    }
  }
}


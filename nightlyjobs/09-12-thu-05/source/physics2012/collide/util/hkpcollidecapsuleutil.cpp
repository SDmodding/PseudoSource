// File Line: 20
// RVA: 0xD3F720
hkResult *__fastcall hkCollideCapsuleUtilClostestPointCapsVsCaps(hkResult *result, hkVector4f *capsA, const float *capsARadius, hkVector4f *capsB, const float *capsBRadius, float collisionTolerance, hkContactPoint *cpoint)
{
  __m128 v7; // xmm3
  __m128 v8; // xmm14
  __m128 v9; // xmm15
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm10
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm9
  __m128 v17; // xmm1
  __m128 v18; // xmm8
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm6
  __m128 v22; // xmm5
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm2
  __m128 v30; // xmm7
  __m128 v31; // xmm6
  __m128 v32; // xmm0
  __m128 v33; // xmm3
  __m128 v34; // xmm0
  __m128 v35; // xmm4
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm10
  __m128 v39; // xmm1
  __m128 v40; // xmm12
  __m128 v41; // xmm11
  __m128 v42; // xmm3
  float v43; // xmm13_4
  __m128 v44; // xmm0
  __m128 v45; // xmm2
  __m128 v46; // xmm6
  __m128 v47; // xmm14
  __m128 v48; // xmm3
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  __m128 v52; // xmm15
  __m128 v53; // xmm5
  __m128 v54; // xmm15
  __m128 v55; // xmm1
  __m128 v56; // xmm4
  __m128 v57; // xmm2
  __m128 v58; // xmm1
  __m128 v59; // xmm2
  __m128 v60; // xmm1
  __m128 v61; // xmm14
  hkResult *v62; // rax
  __m128 v63; // [rsp+0h] [rbp-F8h]
  __m128 v64; // [rsp+40h] [rbp-B8h]

  v7 = _mm_sub_ps(capsB[1].m_quad, capsB->m_quad);
  v8 = cpoint->m_separatingNormal.m_quad;
  v9 = _mm_sub_ps(capsA[1].m_quad, capsA->m_quad);
  v10 = _mm_sub_ps(capsB->m_quad, capsA->m_quad);
  v11 = _mm_mul_ps(v7, v9);
  v63 = v7;
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = v10;
  v14 = _mm_mul_ps(v10, v7);
  v15 = _mm_mul_ps(v13, v9);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_mul_ps(v9, v9);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v20 = _mm_mul_ps(v7, v7);
  v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)), _mm_shuffle_ps(v20, v20, 170));
  v22 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v21, v19), _mm_mul_ps(v12, v12)), *(__m128 *)&epsilon);
  v23 = _mm_rcp_ps(v22);
  v24 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v22)), v23);
  v25 = _mm_rcp_ps(v21);
  v26 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v25, v21)), v25);
  v27 = _mm_rcp_ps(v19);
  v28 = _mm_mul_ps(v27, v19);
  v29 = _mm_cmpleps(v22, *(__m128 *)&epsilon);
  v30 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v28), v27);
  v31 = _mm_sub_ps(_mm_mul_ps(v21, v16), _mm_mul_ps(v18, v12));
  v32 = _mm_cmpltps(v31, v22);
  v33 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_or_ps(
              _mm_andnot_ps(
                v29,
                _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v32, v31), _mm_andnot_ps(v32, v22))), v24)),
              _mm_and_ps(v29, query.m_quad)),
            _mm_mul_ps(v26, v12)),
          _mm_mul_ps(v26, v18));
  v34 = _mm_cmpltps(v33, query.m_quad);
  v35 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v34, query.m_quad), _mm_and_ps(v33, v34)));
  v36 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v30, v12), v35), _mm_mul_ps(v30, v16));
  v37 = _mm_cmpltps(v36, query.m_quad);
  v64 = _mm_add_ps(
          _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v37, query.m_quad), _mm_and_ps(v37, v36))), v9),
          capsA->m_quad);
  v38 = _mm_sub_ps(v64, _mm_add_ps(_mm_mul_ps(v35, v63), capsB->m_quad));
  v39 = _mm_mul_ps(v38, v38);
  v40 = _mm_shuffle_ps((__m128)*(unsigned int *)capsBRadius, (__m128)*(unsigned int *)capsBRadius, 0);
  v41 = _mm_add_ps(_mm_shuffle_ps((__m128)*(unsigned int *)capsARadius, (__m128)*(unsigned int *)capsARadius, 0), v40);
  v42 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)), _mm_shuffle_ps(v39, v39, 170));
  v43 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(collisionTolerance), (__m128)LODWORD(collisionTolerance), 0))
      + v41.m128_f32[0];
  if ( v42.m128_f32[0] <= (float)(v43 * v43) )
  {
    v45 = _mm_rsqrt_ps(v42);
    v46 = _mm_andnot_ps(
            _mm_cmpleps(v42, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v42, v45), v45)),
                _mm_mul_ps(*(__m128 *)_xmm, v45)),
              v42));
    if ( v42.m128_f32[0] <= 0.0 )
    {
      v48 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v63, v63, 201), v9), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v63));
      v49 = _mm_shuffle_ps(v48, v48, 201);
      v50 = _mm_mul_ps(v49, v49);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 170))) <= 0.00000011920929 )
      {
        v52 = _mm_shuffle_ps(v9, _mm_unpackhi_ps(v9, (__m128)0i64), 196);
        v53 = _mm_shuffle_ps(v52, v52, 241);
        v54 = _mm_shuffle_ps(v52, v52, 206);
        v55 = _mm_mul_ps(v54, v54);
        v56 = _mm_mul_ps(v53, v53);
        v57 = _mm_cmpltps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                  _mm_shuffle_ps(v56, v56, 170)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                  _mm_shuffle_ps(v55, v55, 170)));
        v47 = _mm_xor_ps(
                _mm_or_ps(_mm_andnot_ps(v57, v53), _mm_and_ps(v54, v57)),
                (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
      }
      else
      {
        v51 = _mm_mul_ps(v49, v38);
        v47 = _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32(
                            (__m128i)_mm_cmpltps(
                                       _mm_add_ps(
                                         _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
                                         _mm_shuffle_ps(v51, v51, 170)),
                                       (__m128)0i64),
                            0x1Fu),
                          0x1Fu),
                v49);
      }
    }
    else
    {
      v47 = v38;
    }
    result->m_enum = 0;
    v58 = _mm_mul_ps(v47, v47);
    v59 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)),
            _mm_shuffle_ps(v58, v58, 170));
    v60 = _mm_rsqrt_ps(v59);
    v61 = _mm_mul_ps(
            v47,
            _mm_andnot_ps(
              _mm_cmpleps(v59, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v60, v59), v60)),
                _mm_mul_ps(v60, *(__m128 *)_xmm))));
    v8 = _mm_shuffle_ps(v61, _mm_unpackhi_ps(v61, _mm_sub_ps(v46, v41)), 196);
    v44 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v40, v46), v8), v64);
  }
  else
  {
    v44 = cpoint->m_position.m_quad;
    result->m_enum = 1;
  }
  v62 = result;
  cpoint->m_separatingNormal.m_quad = v8;
  cpoint->m_position.m_quad = v44;
  return v62;
}

// File Line: 32
// RVA: 0xD408D0
void __fastcall hkCollideCapsuleUtil_calcTrianglePlaneDirections(hkVector4f *tri, hkpCollideTriangleUtil::PointTriangleDistanceCache *cache, hkTransformf *planeEquationsOut, hkVector4f *normalOut)
{
  __m128 v4; // xmm2
  __m128 v5; // xmm4
  __m128 v6; // xmm6
  __m128 v7; // xmm7
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
  v7 = tri[1].m_quad;
  v8 = _mm_sub_ps(tri[2].m_quad, v7);
  v9 = _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v8);
  v10 = _mm_shuffle_ps(v8, v8, 201);
  v11 = _mm_mul_ps(v8, v6);
  LODWORD(v12) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(cache->m_normalLen),
                                      (__m128)LODWORD(cache->m_normalLen),
                                      0);
  v13 = _mm_sub_ps(v9, _mm_mul_ps(v10, v5));
  v14 = _mm_mul_ps(v5, _mm_shuffle_ps(*(__m128 *)cache->m_invEdgeLen, *(__m128 *)cache->m_invEdgeLen, 85));
  v15 = _mm_mul_ps(_mm_sub_ps(v7, tri->m_quad), _mm_shuffle_ps(v4, v4, 170));
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
void __fastcall hkCollideCapsuleUtilCapsVsTri(hkVector4f *capsAPoints, float capsARadius, hkVector4f *triVertices, float triBRadius, hkpCollideTriangleUtil::PointTriangleDistanceCache *cache, float collisionTolerance, int searchManifold, hkContactPoint *points, hkpFeatureOutput *featuresOut)
{
  hkpCollideTriangleUtil::PointTriangleDistanceCache *v9; // rbx
  hkVector4f *v10; // r11
  hkVector4f *v11; // rdx
  float v12; // xmm8_4
  float v13; // xmm10_4
  __m128 v14; // xmm6
  __m128 v15; // xmm2
  signed int v16; // er13
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
  __m128 v36; // xmm5
  __m128 v37; // xmm0
  __m128 v38; // xmm7
  __m128 v39; // xmm9
  __m128 v40; // xmm3
  __m128 v41; // xmm0
  __m128 *v42; // rax
  __m128 v43; // xmm4
  __m128 v44; // xmm1
  signed __int64 v45; // rcx
  __m128 v46; // xmm1
  hkContactPoint *v47; // rdi
  __m128 v48; // xmm14
  __m128 v49; // xmm6
  hkVector4f v50; // xmm1
  __m128 v51; // xmm9
  __m128 v52; // xmm3
  __m128 v53; // xmm2
  __m128 v54; // xmm2
  __m128 v55; // xmm4
  int v56; // eax
  __m128 v57; // xmm5
  __m128 v58; // xmm2
  int v59; // er10
  int v60; // ecx
  __m128 v61; // xmm7
  __m128 v62; // xmm0
  __m128 v63; // xmm15
  __m128 v64; // xmm14
  __m128 v65; // xmm1
  __m128 v66; // xmm2
  __m128 *v67; // rcx
  hkContactPoint **v68; // r8
  signed __int64 v69; // r11
  float v70; // xmm1_4
  __m128i v71; // xmm2
  __m128 v72; // xmm3
  __m128 v73; // xmm0
  __m128 v74; // xmm0
  __m128 v75; // xmm1
  __m128 *v76; // rax
  __int128 *v77; // rcx
  signed __int64 v78; // r8
  __m128 v79; // xmm13
  __m128 v80; // xmm4
  __m128 v81; // xmm0
  __m128 v82; // xmm1
  __m128 v83; // xmm5
  __m128 v84; // xmm2
  __m128 v85; // xmm1
  __m128 v86; // xmm0
  __m128 v87; // xmm2
  __m128 v88; // xmm4
  __m128 v89; // xmm0
  __m128 v90; // xmm10
  __m128 v91; // xmm10
  __m128 v92; // xmm0
  __m128 v93; // xmm8
  __m128 v94; // xmm4
  __m128 v95; // xmm7
  __m128 v96; // xmm1
  __m128 v97; // xmm3
  __m128 v98; // xmm2
  __m128 v99; // xmm1
  __m128 v100; // xmm6
  __m128 v101; // xmm3
  __m128 v102; // xmm2
  float v103; // xmm7_4
  signed __int64 v104; // r14
  int v105; // er12
  char v106; // r9
  __m128 v107; // xmm0
  signed int v108; // er8
  __m128 v109; // xmm3
  __m128 v110; // xmm7
  __m128 v111; // xmm6
  __int16 v112; // r12
  __int64 v113; // r15
  char v114; // al
  int v115; // eax
  signed int v116; // er12
  signed __int64 v117; // rsi
  __int128 *v118; // r15
  bool v119; // zf
  __int64 v120; // rcx
  __m128 v121; // xmm2
  __m128 v122; // xmm1
  __m128 v123; // xmm0
  hkVector4f *v124; // r8
  int v125; // eax
  float v126; // xmm1_4
  hkVector4f v127; // xmm6
  __m128 v128; // xmm5
  __m128 v129; // xmm5
  __m128 v130; // xmm5
  __m128 v131; // xmm2
  __m128 v132; // xmm1
  __m128 v133; // xmm2
  __m128 v134; // xmm3
  __m128 v135; // xmm5
  __m128 v136; // xmm6
  __m128i v137; // xmm1
  __m128 v138; // xmm0
  __m128 v139; // xmm5
  __m128 v140; // xmm1
  hkVector4f capsBPoints; // [rsp+30h] [rbp-B0h]
  __m128 v142; // [rsp+40h] [rbp-A0h]
  hkVector4f dA; // [rsp+50h] [rbp-90h]
  hkVector4f dB; // [rsp+60h] [rbp-80h]
  __m128 v145; // [rsp+70h] [rbp-70h]
  __m128 v146; // [rsp+80h] [rbp-60h]
  hkLineSegmentUtil::ClosestLineSegLineSegResult result; // [rsp+90h] [rbp-50h]
  hkVector4f *A; // [rsp+1D0h] [rbp+F0h]
  int v149; // [rsp+1D8h] [rbp+F8h]
  hkVector4f *vars0; // [rsp+1E0h] [rbp+100h]
  void *retaddr; // [rsp+1E8h] [rbp+108h]
  int v152; // [rsp+1F0h] [rbp+110h]
  int v153; // [rsp+1F0h] [rbp+110h]
  float v154; // [rsp+1F8h] [rbp+118h]
  int v155; // [rsp+1F8h] [rbp+118h]
  hkVector4f *v156; // [rsp+200h] [rbp+120h]
  hkContactPoint *v157; // [rsp+208h] [rbp+128h]

  *(float *)&v157 = triBRadius;
  v156 = triVertices;
  v9 = cache;
  v10 = triVertices;
  v11 = capsAPoints;
  v12 = triBRadius;
  v13 = capsARadius;
  if ( cache )
  {
    LOBYTE(cache->m_invEdgeLen[0]) = 0;
    LOBYTE(v9->m_invEdgeLen[2]) = 0;
    LOBYTE(v9->m_normalLen) = 0;
  }
  v14 = triVertices->m_quad;
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
  v43 = 0i64;
  v36 = _mm_shuffle_ps(v33, v33, 201);
  v37 = _mm_shuffle_ps(v36, v25, 68);
  v38 = _mm_shuffle_ps(v35, _mm_shuffle_ps(v36, v25, 238), 136);
  v145 = v38;
  v39 = _mm_shuffle_ps(v34, v37, 136);
  v40 = _mm_shuffle_ps(v34, v37, 221);
  v41 = (__m128)capsAPoints[1].m_quad.m128_u32[0];
  v42 = &v142;
  v145 = v39;
  dB.m_quad = v40;
  v43.m128_f32[0] = v32.m128_f32[0] * COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 0));
  v44 = capsAPoints[1].m_quad;
  capsBPoints.m_quad = _mm_sub_ps(capsAPoints->m_quad, v14);
  v45 = 1i64;
  v146 = v43;
  v142 = _mm_sub_ps(v44, v14);
  do
  {
    v46 = *v42;
    --v42;
    --v45;
    v42[1] = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v46, v46, 85), v40), _mm_mul_ps(_mm_shuffle_ps(v46, v46, 0), v39)),
                 _mm_mul_ps(_mm_shuffle_ps(v46, v46, 170), v38)),
               v43);
  }
  while ( v45 >= 0 );
  v47 = v157;
  v48 = v142;
  v49 = capsBPoints.m_quad;
  v50.m_quad = (__m128)v157->m_separatingNormal;
  v149 = LODWORD(FLOAT_1_8446726e19);
  v51 = _mm_shuffle_ps((__m128)COERCE_UNSIGNED_INT(v13 + v12), (__m128)COERCE_UNSIGNED_INT(v13 + v12), 0);
  v52 = _mm_sub_ps(
          _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_8446726e19), (__m128)LODWORD(FLOAT_1_8446726e19), 0),
          _mm_add_ps(v51, v51));
  v157->m_separatingNormal.m_quad = _mm_shuffle_ps(v50.m_quad, _mm_unpackhi_ps(v50.m_quad, v52), 196);
  v53 = _mm_shuffle_ps(v47[1].m_separatingNormal.m_quad, _mm_unpackhi_ps(v47[1].m_separatingNormal.m_quad, v52), 196);
  v47[1].m_separatingNormal.m_quad = v53;
  v53.m128_f32[0] = (float)(v13 + v12) + v154;
  v54 = _mm_shuffle_ps(v53, v53, 0);
  v55 = _mm_cmpltps(v54, v48);
  v47[2].m_separatingNormal.m_quad = _mm_shuffle_ps(
                                       v47[2].m_separatingNormal.m_quad,
                                       _mm_unpackhi_ps(v47[2].m_separatingNormal.m_quad, v52),
                                       196);
  v56 = _mm_movemask_ps(_mm_and_ps(_mm_cmpltps(v54, v49), v55));
  v57 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  v58 = _mm_xor_ps(v54, v57);
  if ( v56 | _mm_movemask_ps(_mm_and_ps(_mm_cmpltps(v48, v58), _mm_cmpltps(v49, v58))) & 8 )
    return;
  v59 = _mm_movemask_ps(_mm_cmpltps(v48, (__m128)0i64));
  v60 = _mm_movemask_ps(_mm_cmpltps(v49, (__m128)0i64));
  v157 = (hkContactPoint *)__PAIR__(v59, v60);
  if ( ((unsigned __int8)v60 ^ (unsigned __int8)v59) & 8 )
  {
    v61 = (__m128)_xmm;
    v62 = _mm_shuffle_ps(v48, v48, 255);
    v63 = _mm_shuffle_ps(v49, v49, 255);
    v64 = _mm_sub_ps(v48, v49);
    v65 = _mm_sub_ps(v63, v62);
    v66 = _mm_rcp_ps(v65);
    if ( (_mm_movemask_ps(
            _mm_cmpltps(
              _mm_add_ps(
                _mm_mul_ps(v64, _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v66, v65)), v66), v63)),
                v49),
              (__m128)0i64)) & 7) == 7 )
    {
      v67 = &v11->m_quad;
      v68 = &v157;
      v69 = 2i64;
      v47[1].m_separatingNormal.m_quad = _mm_shuffle_ps(
                                           v47[1].m_separatingNormal.m_quad,
                                           _mm_unpackhi_ps(v47[1].m_separatingNormal.m_quad, (__m128)xmmword_141A712F0),
                                           196);
      v70 = *(float *)&retaddr;
      do
      {
        if ( (*(_BYTE *)v68 & 7) == 7 )
        {
          v71 = (__m128i)_mm_shuffle_ps(
                           *(__m128 *)((char *)v67 + (char *)&capsBPoints - (char *)v11),
                           *(__m128 *)((char *)v67 + (char *)&capsBPoints - (char *)v11),
                           255);
          v72 = _mm_sub_ps(_mm_sub_ps((__m128)0i64, (__m128)_mm_srli_epi32(_mm_slli_epi32(v71, 1u), 1u)), v51);
          v73 = _mm_shuffle_ps(v47[1].m_separatingNormal.m_quad, v47[1].m_separatingNormal.m_quad, 255);
          if ( v72.m128_f32[0] > v73.m128_f32[0] )
          {
            v73.m128_f32[0] = v70;
            v74 = _mm_shuffle_ps(v73, v73, 0);
            if ( *(_DWORD *)v68 & 8 )
            {
              v47[1].m_separatingNormal.m_quad = v25;
              v47[1].m_position.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v74, (__m128)v71), v25), *v67);
            }
            else
            {
              v75 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_sub_ps((__m128)0i64, v74), (__m128)v71), v25), *v67);
              v47[1].m_separatingNormal.m_quad = _mm_xor_ps(v25, v57);
              v47[1].m_position.m_quad = v75;
            }
            v47[1].m_separatingNormal.m_quad = _mm_shuffle_ps(
                                                 v47[1].m_separatingNormal.m_quad,
                                                 _mm_unpackhi_ps(v47[1].m_separatingNormal.m_quad, v72),
                                                 196);
            v70 = *(float *)&retaddr;
          }
        }
        v68 = (hkContactPoint **)((char *)v68 + 4);
        ++v67;
        --v69;
      }
      while ( v69 );
      v76 = (__m128 *)`hkVector4f::getComponent'::`2'::indexToMask;
      v77 = (__int128 *)&v145;
      v78 = 3i64;
      v79 = _mm_shuffle_ps(v64, v64, 255);
      v80 = _mm_mul_ps(v79, v79);
      dA.m_quad = v80;
      do
      {
        v81 = _mm_and_ps(v64, *v76);
        v82 = _mm_or_ps(_mm_shuffle_ps(v81, v81, 78), v81);
        v83 = _mm_or_ps(_mm_shuffle_ps(v82, v82, 177), v82);
        v84 = _mm_add_ps(_mm_mul_ps(v83, v83), v80);
        v85 = _mm_rcp_ps(v84);
        v86 = _mm_mul_ps(v85, v84);
        v87 = _mm_and_ps(v49, *v76);
        v88 = _mm_mul_ps(_mm_sub_ps(v61, v86), v85);
        v89 = _mm_or_ps(_mm_shuffle_ps(v87, v87, 78), v87);
        v90 = _mm_sub_ps(_mm_mul_ps(v63, v83), _mm_mul_ps(_mm_or_ps(_mm_shuffle_ps(v89, v89, 177), v89), v79));
        v89.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v47[1].m_separatingNormal.m_quad, v47[1].m_separatingNormal.m_quad, 255))
                        + v51.m128_f32[0];
        v91 = _mm_mul_ps(_mm_mul_ps(v90, v90), v88);
        if ( v91.m128_f32[0] < (float)(v89.m128_f32[0] * v89.m128_f32[0]) )
        {
          v92 = _mm_or_ps(_mm_shuffle_ps(v87, v87, 78), v87);
          v93 = _mm_mul_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_or_ps(_mm_shuffle_ps(v92, v92, 177), v92), v83), _mm_mul_ps(v63, v79)),
                  _mm_sub_ps((__m128)0i64, v88));
          if ( v93.m128_f32[0] > COERCE_FLOAT(_mm_shuffle_ps((__m128)0xB8D1B717, (__m128)0xB8D1B717, 0)) )
          {
            v149 = 1065354055;
            if ( v93.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3F800347u, (__m128)0x3F800347u, 0)) )
            {
              v94 = (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmpltps(v79, (__m128)0i64), 0x1Fu), 0x1Fu);
              v95 = _mm_add_ps(
                      _mm_mul_ps(_mm_sub_ps((__m128)0i64, _mm_xor_ps(v94, v83)), v25),
                      _mm_mul_ps(
                        _mm_unpacklo_ps(
                          _mm_unpacklo_ps((__m128)*((unsigned int *)v77 - 8), (__m128)*(unsigned int *)v77),
                          _mm_unpacklo_ps((__m128)*((unsigned int *)v77 - 4), (__m128)0i64)),
                        _mm_xor_ps(v94, v79)));
              v96 = _mm_mul_ps(v95, v95);
              v97 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)),
                      _mm_shuffle_ps(v96, v96, 170));
              v98 = _mm_rsqrt_ps(v97);
              v99 = _mm_rsqrt_ps(v91);
              v100 = _mm_mul_ps(
                       _mm_andnot_ps(
                         _mm_cmpleps(v97, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v98, v97), v98)),
                           _mm_mul_ps(*(__m128 *)_xmm, v98))),
                       v95);
              v61 = (__m128)_xmm;
              v47[1].m_separatingNormal.m_quad = v100;
              v101 = _mm_sub_ps(
                       (__m128)0i64,
                       _mm_andnot_ps(
                         _mm_cmpleps(v91, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v99, v91), v99)),
                             _mm_mul_ps(*(__m128 *)_xmm, v99)),
                           v91)));
              v102 = _mm_mul_ps(
                       _mm_sub_ps(_mm_shuffle_ps((__m128)(unsigned int)retaddr, (__m128)(unsigned int)retaddr, 0), v101),
                       v100);
              v49 = capsBPoints.m_quad;
              v47[1].m_position.m_quad = _mm_add_ps(
                                           v102,
                                           _mm_add_ps(
                                             _mm_mul_ps(_mm_sub_ps(v11[1].m_quad, v11->m_quad), v93),
                                             v11->m_quad));
              v47[1].m_separatingNormal.m_quad = _mm_shuffle_ps(
                                                   v47[1].m_separatingNormal.m_quad,
                                                   _mm_unpackhi_ps(
                                                     v47[1].m_separatingNormal.m_quad,
                                                     _mm_sub_ps(v101, v51)),
                                                   196);
            }
          }
        }
        v80 = dA.m_quad;
        ++v76;
        v77 = (__int128 *)((char *)v77 + 4);
        --v78;
      }
      while ( v78 );
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
  v103 = *(float *)&retaddr;
  v104 = 0i64;
  v105 = v60 | v59;
  v106 = 0;
  v107 = _mm_sub_ps(v11[1].m_quad, v11->m_quad);
  v108 = 0;
  LODWORD(cache) = 0;
  dA.m_quad = v107;
  LOBYTE(v149) = 0;
  v152 = v60 | v59;
  if ( (((unsigned __int8)v60 | (unsigned __int8)v59) & 7) == 7 )
    goto LABEL_47;
  if ( (_DWORD)v156 )
  {
    v109 = _mm_shuffle_ps((__m128)LODWORD(v154), (__m128)LODWORD(v154), 0);
    v47->m_separatingNormal.m_quad = _mm_shuffle_ps(
                                       v47->m_separatingNormal.m_quad,
                                       _mm_unpackhi_ps(v47->m_separatingNormal.m_quad, v109),
                                       196);
    v47[1].m_separatingNormal.m_quad = _mm_shuffle_ps(
                                         v47[1].m_separatingNormal.m_quad,
                                         _mm_unpackhi_ps(v47[1].m_separatingNormal.m_quad, v109),
                                         196);
    v47[2].m_separatingNormal.m_quad = _mm_shuffle_ps(
                                         v47[2].m_separatingNormal.m_quad,
                                         _mm_unpackhi_ps(v47[2].m_separatingNormal.m_quad, v109),
                                         196);
    v110 = aabbOut.m_quad;
    v111 = _mm_shuffle_ps(aabbOut.m_quad, _mm_unpackhi_ps(aabbOut.m_quad, (__m128)xmmword_141A712A0), 196);
    do
    {
      if ( !(v16 & v105) )
      {
        v112 = hkpCollideTriangleUtil::vertexToEdgeLut[v104 + 2];
        v113 = hkpCollideTriangleUtil::vertexToEdgeLut[v104];
        capsBPoints.m_quad = (__m128)v10[hkpCollideTriangleUtil::vertexToEdgeLut[v104 + 2]];
        v142 = v10[v113].m_quad;
        v114 = hkLineSegmentUtil::capsuleCapsuleManifold(v11, v13, &capsBPoints, v12, v47);
        if ( v9 )
        {
          HIWORD(v9->m_invEdgeLen[0]) = v112;
          v115 = v114 & 0xC;
          if ( v115 )
          {
            LOBYTE(v9->m_invEdgeLen[0]) = 1;
          }
          else
          {
            LOBYTE(v9->m_invEdgeLen[0]) = 2;
            LOWORD(v9->m_invEdgeLen[1]) = v113;
          }
          HIWORD(v9->m_invEdgeLen[2]) = v112;
          if ( v115 )
          {
            LOBYTE(v9->m_invEdgeLen[2]) = 1;
          }
          else
          {
            LOBYTE(v9->m_invEdgeLen[2]) = 2;
            LOWORD(v9->m_invNormalLen) = v113;
          }
          HIWORD(v9->m_normalLen) = v112;
          if ( v115 )
          {
            LOBYTE(v9->m_normalLen) = 1;
          }
          else
          {
            LOBYTE(v9->m_normalLen) = 2;
            LOWORD(v9[1].m_invEdgeLen[0]) = v113;
          }
        }
        v10 = vars0;
        v11 = A;
        v105 = v152;
        if ( COERCE_FLOAT(_mm_shuffle_ps(v47->m_separatingNormal.m_quad, v47->m_separatingNormal.m_quad, 255)) <= COERCE_FLOAT(_mm_shuffle_ps(v111, v111, 255)) )
        {
          v110 = v47->m_position.m_quad;
          v111 = v47->m_separatingNormal.m_quad;
        }
        else
        {
          v47->m_position.m_quad = v110;
          v47->m_separatingNormal.m_quad = v111;
        }
      }
      ++v104;
      v16 *= 2;
    }
    while ( v104 < 3 );
    return;
  }
  v106 = 1;
  LOBYTE(v149) = 1;
$checkSingleSecondPoint:
  v116 = 1;
  v117 = v108;
  v118 = (__int128 *)&v145;
  LODWORD(retaddr) = __ROL4__(1, v108);
  do
  {
    if ( v106 )
      v119 = ((unsigned int)v157 & HIDWORD(v157) & v116) == 0;
    else
      v119 = (v116 & *((_DWORD *)&v157 + v117)) == 0;
    if ( v119 )
    {
      v155 = hkpCollideTriangleUtil::vertexToEdgeLut[v104 + 2];
      v153 = hkpCollideTriangleUtil::vertexToEdgeLut[v104];
      v124 = &v10[hkpCollideTriangleUtil::vertexToEdgeLut[v104 + 2]];
      dB.m_quad = _mm_sub_ps(v10[hkpCollideTriangleUtil::vertexToEdgeLut[v104]].m_quad, v124->m_quad);
      v125 = hkLineSegmentUtil::closestLineSegLineSeg(A, &dA, v124, &dB, &result);
      if ( v9 )
      {
        HIWORD(v9->m_invEdgeLen[2 * v117]) = v155;
        if ( v125 & 0xC )
        {
          LOBYTE(v9->m_invEdgeLen[2 * v117]) = 1;
        }
        else
        {
          LOBYTE(v9->m_invEdgeLen[2 * v117]) = 2;
          LOWORD(v9->m_invEdgeLen[2 * v117 + 1]) = v153;
        }
      }
      v106 = v149;
      v107 = _mm_shuffle_ps(
               (__m128)LODWORD(result.m_distanceSquared.m_storage),
               (__m128)LODWORD(result.m_distanceSquared.m_storage),
               0);
      v126 = COERCE_FLOAT(_mm_shuffle_ps(v47->m_separatingNormal.m_quad, v47->m_separatingNormal.m_quad, 255))
           + v51.m128_f32[0];
      if ( v107.m128_f32[0] < (float)(v126 * v126) )
      {
        if ( !(v125 & (unsigned int)retaddr) )
        {
          v108 = (signed int)cache;
LABEL_65:
          if ( !v125 )
          {
            v127.m_quad = (__m128)result.m_closestAminusClosestB;
            v128 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(dB.m_quad, dB.m_quad, 201), dA.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(dA.m_quad, dA.m_quad, 201), dB.m_quad));
            v129 = _mm_shuffle_ps(v128, v128, 201);
LABEL_72:
            v132 = _mm_mul_ps(v129, v129);
            v133 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v132, v132, 85), _mm_shuffle_ps(v132, v132, 0)),
                     _mm_shuffle_ps(v132, v132, 170));
            v134 = _mm_rsqrt_ps(v133);
            v55 = _mm_andnot_ps(
                    _mm_cmpleps(v133, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v134, v133), v134)),
                      _mm_mul_ps(*(__m128 *)_xmm, v134)));
            v135 = _mm_mul_ps(v129, v55);
            v136 = _mm_mul_ps(v127.m_quad, v135);
            v137 = (__m128i)_mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v136, v136, 85), _mm_shuffle_ps(v136, v136, 0)),
                              _mm_shuffle_ps(v136, v136, 170));
            v138 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v137, 0x1Fu), 0x1Fu);
            v139 = _mm_xor_ps(v135, v138);
            v140 = _mm_xor_ps((__m128)v137, v138);
            v138.m128_f32[0] = v103;
            v47->m_position.m_quad = _mm_add_ps(
                                       _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v138, v138, 0), v140), v139),
                                       result.m_closestPointA.m_quad);
            v107 = _mm_unpackhi_ps(v139, _mm_sub_ps(v140, v51));
            v47->m_separatingNormal.m_quad = _mm_shuffle_ps(v139, v107, 196);
LABEL_74:
            v10 = vars0;
            goto LABEL_75;
          }
          if ( COERCE_FLOAT(
                 _mm_shuffle_ps(
                   (__m128)LODWORD(result.m_distanceSquared.m_storage),
                   (__m128)LODWORD(result.m_distanceSquared.m_storage),
                   0)) > 1.4210855e-14 )
          {
            v127.m_quad = (__m128)result.m_closestAminusClosestB;
          }
          else
          {
            v127.m_quad = _mm_unpacklo_ps(
                            _mm_unpacklo_ps((__m128)*((unsigned int *)v118 - 8), (__m128)*(unsigned int *)v118),
                            _mm_unpacklo_ps((__m128)*((unsigned int *)v118 - 4), (__m128)0i64));
            v130 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(dB.m_quad, dB.m_quad, 201), dA.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(dA.m_quad, dA.m_quad, 201), dB.m_quad));
            v129 = _mm_shuffle_ps(v130, v130, 201);
            v131 = _mm_mul_ps(v129, v129);
            if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v131, v131, 85))
                               + COERCE_FLOAT(_mm_shuffle_ps(v131, v131, 0)))
                       + COERCE_FLOAT(_mm_shuffle_ps(v131, v131, 170))) > 1.4210855e-14 )
              goto LABEL_72;
          }
          v129 = v127.m_quad;
          goto LABEL_72;
        }
        if ( (_BYTE)v149 )
        {
          v108 = 1;
          LODWORD(cache) = 1;
          LODWORD(retaddr) = 2;
          v117 = 1i64;
          goto LABEL_65;
        }
      }
      v108 = (signed int)cache;
      goto LABEL_74;
    }
LABEL_75:
    ++v104;
    v116 *= 2;
    v118 = (__int128 *)((char *)v118 + 4);
  }
  while ( v104 < 3 );
  if ( !v106 )
  {
    v11 = A;
    v104 = 0i64;
LABEL_78:
    ++v47;
    LODWORD(cache) = ++v108;
LABEL_47:
    while ( v108 < 2 )
    {
      v120 = v108;
      if ( (*((_BYTE *)&v157 + 4 * v108) & 7) != 7 )
        goto $checkSingleSecondPoint;
      if ( *((_DWORD *)&v157 + v108) & 8 )
      {
        v107.m128_f32[0] = v103;
        v121 = _mm_shuffle_ps(*(&capsBPoints.m_quad + v108), *(&capsBPoints.m_quad + v108), 255);
        v55 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(_mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v107, v107, 0)), v121), v25),
                v11[v108].m_quad);
        v122 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v25);
        v107 = _mm_unpackhi_ps(v122, _mm_sub_ps(_mm_sub_ps((__m128)0i64, v121), v51));
        v47->m_separatingNormal.m_quad = _mm_shuffle_ps(v122, v107, 196);
      }
      else
      {
        v55.m128_f32[0] = v103;
        v123 = _mm_shuffle_ps(*(&capsBPoints.m_quad + v108), *(&capsBPoints.m_quad + v108), 255);
        v55 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v55, v55, 0), v123), v25), v11[v108].m_quad);
        v107 = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, _mm_sub_ps(v123, v51)), 196);
        v47->m_separatingNormal.m_quad = v107;
      }
      v47->m_position.m_quad = v55;
      if ( !v9 )
        goto LABEL_78;
      LOBYTE(v9->m_invEdgeLen[2 * v108]) = 3;
      ++v47;
      ++v108;
      *(_DWORD *)((char *)&v9->m_invEdgeLen[2 * v120] + 2) = 0x10000;
      HIWORD(v9->m_invEdgeLen[2 * v120 + 1]) = 2;
      LODWORD(cache) = v108;
    }
  }
}


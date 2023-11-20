// File Line: 17
// RVA: 0xD3EE10
void __fastcall hkpCollideTriangleUtil::setupClosestPointTriangleCache(hkVector4f *tri, hkpCollideTriangleUtil::ClosestPointTriangleCache *cache)
{
  __m128 v2; // ST00_16
  __m128 v3; // ST10_16
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm6_4
  float v7; // xmm5_4
  float v8; // xmm4_4
  float v9; // xmm3_4
  __m128 v10; // xmm2
  __m128 v11; // xmm2
  __m128 v12; // xmm2

  v2 = _mm_sub_ps(tri[2].m_quad, tri[1].m_quad);
  v3 = _mm_sub_ps(tri->m_quad, tri[1].m_quad);
  LODWORD(v4) = (unsigned __int128)_mm_shuffle_ps(v3, v3, 85);
  LODWORD(v5) = (unsigned __int128)_mm_shuffle_ps(v3, v3, 170);
  v6 = (float)((float)(v4 * v4) + (float)(v3.m128_f32[0] * v3.m128_f32[0])) + (float)(v5 * v5);
  v7 = (float)((float)(v2.m128_f32[1] * v2.m128_f32[1]) + (float)(v2.m128_f32[0] * v2.m128_f32[0]))
     + (float)(v2.m128_f32[2] * v2.m128_f32[2]);
  v8 = (float)((float)(v2.m128_f32[1] * v3.m128_f32[1]) + (float)(v2.m128_f32[0] * v3.m128_f32[0]))
     + (float)(v2.m128_f32[2] * v3.m128_f32[2]);
  v9 = 1.0 / (float)((float)(v7 * v6) - (float)(v8 * v8));
  cache->m_QR = v9 * v8;
  cache->m_RR = (float)(1.0 / (float)((float)(v7 * v6) - (float)(v8 * v8))) * v7;
  cache->m_QQ = v9 * v6;
  v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v2, v2, 201), v3), _mm_mul_ps(_mm_shuffle_ps(v3, v3, 201), v2));
  v11 = _mm_shuffle_ps(v10, v10, 201);
  v12 = _mm_mul_ps(v11, v11);
  cache->m_invTriNormal = 1.0
                        / COERCE_FLOAT(
                            _mm_sqrt_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                                _mm_shuffle_ps(v12, v12, 170))));
}

// File Line: 62
// RVA: 0xD3F490
void __fastcall hkpCollideTriangleUtil::setupPointTriangleDistanceCache(hkVector4f *tri, hkpCollideTriangleUtil::PointTriangleDistanceCache *cache)
{
  __m128 v2; // xmm5
  __m128 v3; // xmm4
  __m128 v4; // xmm6
  __m128 v5; // xmm5
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __m128 v8; // xmm6
  __m128 v9; // xmm5
  __m128 v10; // xmm0
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm6
  __m128 v18; // xmm1
  __m128 v19; // xmm2

  v2 = tri[1].m_quad;
  v3 = _mm_sub_ps(tri->m_quad, tri[2].m_quad);
  v4 = _mm_sub_ps(tri[2].m_quad, v2);
  v5 = _mm_sub_ps(v2, tri->m_quad);
  v6 = _mm_mul_ps(_mm_shuffle_ps(v3, v3, 201), v4);
  v7 = _mm_shuffle_ps(v4, v4, 201);
  v8 = _mm_mul_ps(v4, v4);
  v9 = _mm_mul_ps(v5, v5);
  v10 = _mm_mul_ps(v7, v3);
  v11 = _mm_mul_ps(v3, v3);
  v12 = _mm_sub_ps(v6, v10);
  v13 = _mm_shuffle_ps(v8, v11, 68);
  v14 = _mm_shuffle_ps(v12, v12, 201);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_shuffle_ps(v9, v15, 68);
  v17 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v8, v11, 238), _mm_shuffle_ps(v9, v15, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v13, v16, 221), _mm_shuffle_ps(v13, v16, 136)));
  v18 = _mm_rsqrt_ps(v17);
  v19 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v18), v18)), _mm_mul_ps(*(__m128 *)_xmm, v18));
  *(__m128 *)cache->m_invEdgeLen = v19;
  cache->m_normalLen = COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 255)) * COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 255));
}

// File Line: 95
// RVA: 0xD3F550
void __fastcall hkpCollideTriangleUtil::calcTrianglePlaneDirections(hkVector4f *tri, hkpCollideTriangleUtil::PointTriangleDistanceCache *cache, hkTransformf *planeEquationsOut, hkVector4f *normalOut)
{
  __m128 v4; // xmm2
  __m128 v5; // xmm4
  __m128 v6; // xmm6
  __m128 v7; // xmm7
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm3
  __m128 v12; // xmm8
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm7
  hkVector4f v16; // xmm5
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  hkVector4f v21; // xmm2
  __m128 v22; // xmm4
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm1

  v4 = *(__m128 *)cache->m_invEdgeLen;
  v5 = _mm_sub_ps(tri->m_quad, tri[2].m_quad);
  v6 = _mm_shuffle_ps(*(__m128 *)cache->m_invEdgeLen, *(__m128 *)cache->m_invEdgeLen, 0);
  v7 = tri[1].m_quad;
  v8 = _mm_sub_ps(tri[2].m_quad, v7);
  v9 = _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v8);
  v10 = _mm_shuffle_ps(v8, v8, 201);
  v11 = _mm_mul_ps(v8, v6);
  v12 = _mm_shuffle_ps((__m128)LODWORD(cache->m_normalLen), (__m128)LODWORD(cache->m_normalLen), 0);
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
  v21.m_quad = (__m128)planeEquationsOut->m_rotation.m_col2;
  v22 = _mm_shuffle_ps(planeEquationsOut->m_rotation.m_col0.m_quad, planeEquationsOut->m_rotation.m_col1.m_quad, 238);
  v23 = _mm_shuffle_ps(planeEquationsOut->m_rotation.m_col0.m_quad, planeEquationsOut->m_rotation.m_col1.m_quad, 68);
  v24 = v21.m_quad;
  v25 = _mm_shuffle_ps(v21.m_quad, v16.m_quad, 238);
  v26 = _mm_shuffle_ps(v24, v16.m_quad, 68);
  planeEquationsOut->m_rotation.m_col0.m_quad = _mm_shuffle_ps(v23, v26, 136);
  planeEquationsOut->m_rotation.m_col1.m_quad = _mm_shuffle_ps(v23, v26, 221);
  planeEquationsOut->m_rotation.m_col2.m_quad = _mm_shuffle_ps(v22, v25, 136);
  planeEquationsOut->m_translation.m_quad = _mm_shuffle_ps(v22, v25, 221);
  planeEquationsOut->m_translation.m_quad = _mm_shuffle_ps(
                                              aabbOut.m_quad,
                                              _mm_unpackhi_ps(
                                                aabbOut.m_quad,
                                                _mm_mul_ps(_mm_sub_ps((__m128)0i64, v6), v12)),
                                              196);
}

// File Line: 132
// RVA: 0xD3EFC0
signed __int64 __fastcall hkpCollideTriangleUtil::closestPointTriangle(hkVector4f *position, hkVector4f *tri, hkpCollideTriangleUtil::ClosestPointTriangleCache *cache, hkpCollideTriangleUtil::ClosestPointTriangleResult *result, hkpFeatureOutput *featureOutput)
{
  hkpCollideTriangleUtil::ClosestPointTriangleResult *v5; // rsi
  hkVector4f *v6; // r15
  hkVector4f *v7; // r12
  __m128 v8; // xmm2
  __m128 v9; // xmm4
  __m128 v10; // xmm7
  __m128 v11; // xmm5
  __m128 v12; // xmm8
  __m128 v13; // xmm1
  float v14; // xmm3_4
  __m128 v15; // xmm1
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  char v19; // cl
  __m128 v20; // xmm0
  hkVector4f v21; // xmm0
  hkVector4f v22; // xmm2
  __m128 v23; // xmm5
  float v24; // xmm1_4
  __int64 v26; // rbp
  int v27; // ebp
  int v28; // eax
  __m128 v29; // xmm5
  __m128 v30; // xmm1
  __m128 v31; // xmm4
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  hkVector4f *v34; // rbx
  int v35; // er13
  int v36; // eax
  __m128 v37; // xmm7
  __m128 v38; // xmm8
  __m128 v39; // xmm1
  __m128 v40; // xmm4
  __m128 v41; // xmm1
  __m128 v42; // xmm5
  __m128 v43; // xmm2
  __m128 v44; // xmm3
  float v45; // xmm0_4
  __m128 v46; // xmm2
  __m128 v47; // xmm3
  hkLineSegmentUtil::ClosestPointLineSegResult resulta; // [rsp+20h] [rbp-78h]
  hkLineSegmentUtil::ClosestPointLineSegResult v49; // [rsp+30h] [rbp-68h]

  v5 = result;
  v6 = tri;
  v7 = position;
  if ( featureOutput )
    featureOutput->numFeatures = 0;
  v8 = tri[1].m_quad;
  v9 = (__m128)LODWORD(cache->m_QR);
  v10 = _mm_sub_ps(tri->m_quad, v8);
  v11 = _mm_sub_ps(tri[1].m_quad, position->m_quad);
  v12 = _mm_sub_ps(tri[2].m_quad, v8);
  v13 = _mm_mul_ps(v11, v10);
  v14 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_mul_ps(v11, v12);
  v8.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 170));
  v16 = (__m128)LODWORD(cache->m_QR);
  v16.m128_f32[0] = (float)(v16.m128_f32[0] * v8.m128_f32[0]) - (float)(v14 * cache->m_RR);
  v9.m128_f32[0] = (float)(v9.m128_f32[0] * v14) - (float)(v8.m128_f32[0] * cache->m_QQ);
  v17 = (__m128)LODWORD(FLOAT_1_001);
  v18 = v16;
  v18.m128_f32[0] = v16.m128_f32[0] + 0.001;
  v17.m128_f32[0] = (float)(1.001 - v16.m128_f32[0]) - v9.m128_f32[0];
  v9.m128_f32[0] = v9.m128_f32[0] + 0.001;
  v19 = _mm_movemask_ps(
          _mm_cmpltps(
            (__m128)0i64,
            _mm_unpacklo_ps(_mm_unpacklo_ps(v18, v9), _mm_unpacklo_ps(v17, (__m128)LODWORD(FLOAT_0_001)))));
  if ( (v19 & 7) != 7 )
  {
    v26 = hkpCollideTriangleUtil::maskToIndex[v19 & 7];
    if ( (signed int)v26 < 0 )
    {
      v27 = v26 + 8;
      v28 = hkLineSegmentUtil::closestPointLineSeg(
              v7,
              &tri[hkpCollideTriangleUtil::vertexToEdgeLut[v27 + 2]],
              &tri[hkpCollideTriangleUtil::vertexToEdgeLut[v27]],
              &resulta);
      if ( featureOutput )
      {
        if ( v28 == 4 )
        {
          featureOutput->featureIds[0] = hkpCollideTriangleUtil::vertexToEdgeLut[v27];
          featureOutput->numFeatures = 1;
        }
        else if ( v28 == 8 )
        {
          featureOutput->featureIds[0] = hkpCollideTriangleUtil::vertexToEdgeLut[v27 + 2];
          featureOutput->numFeatures = 1;
        }
        else
        {
          featureOutput->featureIds[0] = hkpCollideTriangleUtil::vertexToEdgeLut[v27];
          featureOutput->featureIds[1] = hkpCollideTriangleUtil::vertexToEdgeLut[v27 + 2];
          featureOutput->numFeatures = 2;
        }
      }
      v29 = _mm_sub_ps(v7->m_quad, resulta.m_pointOnEdge.m_quad);
      v30 = _mm_mul_ps(v29, v29);
      v31 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
              _mm_shuffle_ps(v30, v30, 170));
      v32 = _mm_rsqrt_ps(v31);
      v33 = _mm_andnot_ps(
              _mm_cmpleps(v31, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
                _mm_mul_ps(*(__m128 *)_xmm, v32)));
      v5->distance = v33.m128_f32[0] * v31.m128_f32[0];
      v5->hitDirection.m_quad = _mm_mul_ps(v33, v29);
      return 1i64;
    }
    v34 = &tri[v26];
    v35 = hkLineSegmentUtil::closestPointLineSeg(
            v7,
            &tri[hkpCollideTriangleUtil::maskToIndex[v19 & 7]],
            &tri[hkpCollideTriangleUtil::vertexToEdgeLut[hkpCollideTriangleUtil::maskToIndex[v19 & 7] + 2]],
            &resulta);
    v36 = hkLineSegmentUtil::closestPointLineSeg(v7, &v6[*(char *)(v26 + 5396521352i64)], v34, &v49);
    v37 = _mm_sub_ps(v7->m_quad, v49.m_pointOnEdge.m_quad);
    v38 = _mm_sub_ps(v7->m_quad, resulta.m_pointOnEdge.m_quad);
    v39 = _mm_mul_ps(v38, v38);
    v40 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
            _mm_shuffle_ps(v39, v39, 170));
    v41 = _mm_mul_ps(v37, v37);
    v42 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
            _mm_shuffle_ps(v41, v41, 170));
    if ( v40.m128_f32[0] >= v42.m128_f32[0] )
    {
      v46 = _mm_rsqrt_ps(v42);
      v47 = _mm_andnot_ps(
              _mm_cmpleps(v42, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v46, v42), v46)),
                _mm_mul_ps(*(__m128 *)_xmm, v46)));
      if ( featureOutput )
      {
        if ( v36 == 4 )
        {
          featureOutput->numFeatures = 1;
          featureOutput->featureIds[0] = v26;
        }
        else if ( v36 == 8 )
        {
          featureOutput->numFeatures = 1;
          featureOutput->featureIds[0] = *(char *)(v26 + 5396521352i64);
        }
        else
        {
          featureOutput->numFeatures = 2;
          featureOutput->featureIds[0] = v26;
          featureOutput->featureIds[1] = *(char *)(v26 + 5396521352i64);
        }
      }
      v45 = v47.m128_f32[0] * v42.m128_f32[0];
      v5->hitDirection.m_quad = _mm_mul_ps(v37, v47);
      goto LABEL_33;
    }
    v43 = _mm_rsqrt_ps(v40);
    v44 = _mm_andnot_ps(
            _mm_cmpleps(v40, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v40), v43)),
              _mm_mul_ps(*(__m128 *)_xmm, v43)));
    if ( featureOutput )
    {
      if ( v35 == 4 )
      {
        featureOutput->numFeatures = 1;
        featureOutput->featureIds[0] = v26;
        v45 = v44.m128_f32[0] * v40.m128_f32[0];
        v5->hitDirection.m_quad = _mm_mul_ps(v38, v44);
LABEL_33:
        v5->distance = v45;
        return 1i64;
      }
      if ( v35 == 8 )
      {
        featureOutput->numFeatures = 1;
        featureOutput->featureIds[0] = *(char *)(v26 + 5396521354i64);
        v45 = v44.m128_f32[0] * v40.m128_f32[0];
        v5->hitDirection.m_quad = _mm_mul_ps(v38, v44);
        goto LABEL_33;
      }
      featureOutput->numFeatures = 2;
      featureOutput->featureIds[0] = v26;
      featureOutput->featureIds[1] = *(char *)(v26 + 5396521354i64);
    }
    v45 = v44.m128_f32[0] * v40.m128_f32[0];
    v5->hitDirection.m_quad = _mm_mul_ps(v38, v44);
    goto LABEL_33;
  }
  v20 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v12));
  v21.m_quad = _mm_shuffle_ps(v20, v20, 201);
  result->hitDirection = (hkVector4f)v21.m_quad;
  v22.m_quad = _mm_mul_ps(
                 _mm_shuffle_ps((__m128)LODWORD(cache->m_invTriNormal), (__m128)LODWORD(cache->m_invTriNormal), 0),
                 v21.m_quad);
  v23 = _mm_mul_ps(v11, v22.m_quad);
  result->hitDirection = (hkVector4f)v22.m_quad;
  v24 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 170));
  if ( v24 <= 0.0 )
    v24 = 0.0 - v24;
  else
    result->hitDirection.m_quad = _mm_xor_ps(
                                    (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                    v22.m_quad);
  result->distance = v24;
  if ( featureOutput )
  {
    featureOutput->numFeatures = 3;
    *(_DWORD *)featureOutput->featureIds = 0x10000;
    featureOutput->featureIds[2] = 2;
  }
  return 0i64;
}


// File Line: 15
// RVA: 0xC68EC0
__int64 __fastcall hkLineSegmentUtil::closestLineSegLineSeg(
        hkVector4f *A,
        hkVector4f *dA,
        hkVector4f *B,
        hkVector4f *dB,
        hkLineSegmentUtil::ClosestLineSegLineSegResult *result)
{
  __m128 v5; // xmm2
  __m128 v6; // xmm1
  __m128 v7; // xmm9
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm11
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm10
  __m128 v14; // xmm8
  __m128 v15; // xmm7
  __m128 v16; // xmm4
  __m128 v17; // xmm12
  __m128 v18; // xmm5
  __m128 v19; // xmm2
  __m128 m_quad; // xmm3
  __int64 v21; // rax
  __m128 v22; // xmm1
  __m128 v23; // xmm5
  __m128 v24; // xmm4
  __m128 v25; // xmm5
  __m128 v26; // xmm2
  __m128 v27; // xmm2
  __m128 v28; // xmm4
  hkVector4f v29; // xmm0
  hkVector4f v30; // xmm2
  __m128 v31; // xmm2

  v5 = _mm_sub_ps(B->m_quad, A->m_quad);
  v6 = _mm_mul_ps(dB->m_quad, dA->m_quad);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_mul_ps(dA->m_quad, dA->m_quad);
  v9 = _mm_mul_ps(dA->m_quad, v5);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_mul_ps(dB->m_quad, v5);
  v12 = _mm_mul_ps(dB->m_quad, dB->m_quad);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v16 = _mm_mul_ps(v7, v7);
  v17 = _mm_mul_ps(v15, v14);
  v18 = _mm_sub_ps(_mm_mul_ps(v15, v10), _mm_mul_ps(v13, v7));
  v19 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v17, v16), 1u), 1u);
  if ( (float)(v18.m128_f32[0] * v19.m128_f32[0]) >= (float)(v19.m128_f32[0] * v19.m128_f32[0]) )
    goto LABEL_6;
  m_quad = 0i64;
  if ( v18.m128_f32[0] <= 0.0 )
  {
    v21 = 2i64;
    goto LABEL_7;
  }
  if ( v19.m128_f32[0] <= (float)((float)(v16.m128_f32[0] + v17.m128_f32[0]) * (float)(0.00000011920929 * 8.0)) )
  {
LABEL_6:
    v21 = 1i64;
    m_quad = query.m_quad;
  }
  else
  {
    v22 = _mm_rcp_ps(v19);
    v21 = 0i64;
    m_quad = _mm_mul_ps(v18, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v19, v22)), v22));
  }
LABEL_7:
  v23 = _mm_sub_ps(_mm_mul_ps(m_quad, v7), v13);
  if ( v23.m128_f32[0] < v15.m128_f32[0] )
  {
    v24 = 0i64;
    if ( v23.m128_f32[0] > 0.0 )
    {
      v27 = _mm_rcp_ps(v15);
      v24 = _mm_mul_ps(v23, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v27, v15)), v27));
      goto $end_2;
    }
    v21 = 8i64;
  }
  else
  {
    v24 = query.m_quad;
    v21 = 4i64;
  }
  m_quad = 0i64;
  v25 = _mm_add_ps(_mm_mul_ps(v24, v7), v10);
  if ( v25.m128_f32[0] > 0.0 )
  {
    if ( v25.m128_f32[0] < v14.m128_f32[0] )
    {
      v26 = _mm_rcp_ps(v14);
      m_quad = _mm_mul_ps(v25, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v26, v14)), v26));
    }
    else
    {
      m_quad = query.m_quad;
      v21 = (unsigned int)v21 | 1;
    }
  }
  else
  {
    v21 = (unsigned int)v21 | 2;
  }
$end_2:
  result->m_t.m_real = m_quad;
  result->m_u.m_real = v24;
  v28 = _mm_add_ps(_mm_mul_ps(v24, dB->m_quad), B->m_quad);
  v29.m_quad = _mm_add_ps(_mm_mul_ps(dA->m_quad, m_quad), A->m_quad);
  result->m_closestPointA = (hkVector4f)v29.m_quad;
  v30.m_quad = _mm_sub_ps(v29.m_quad, v28);
  result->m_closestAminusClosestB = (hkVector4f)v30.m_quad;
  v31 = _mm_mul_ps(v30.m_quad, v30.m_quad);
  result->m_distanceSquared.m_storage = (float)(_mm_shuffle_ps(v31, v31, 85).m128_f32[0]
                                              + _mm_shuffle_ps(v31, v31, 0).m128_f32[0])
                                      + _mm_shuffle_ps(v31, v31, 170).m128_f32[0];
  return v21;
}

// File Line: 122
// RVA: 0xC69140
__int64 __fastcall hkLineSegmentUtil::capsuleCapsuleManifold(
        hkVector4f *capsAPointsIn,
        float capsARadius,
        hkVector4f *capsBPoints,
        float capsBRadius,
        hkContactPoint *points)
{
  __m128 m_quad; // xmm4
  __m128 v7; // xmm10
  __m128 v8; // xmm14
  __m128 v9; // xmm1
  __m128 v10; // xmm15
  __m128 v11; // xmm8
  int v12; // r8d
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm13
  __m128 v17; // xmm7
  __m128 v18; // xmm6
  __m128 v19; // xmm1
  __m128 v20; // xmm11
  __m128 v21; // xmm1
  __m128 v22; // xmm12
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  __m128 v25; // xmm4
  unsigned int v26; // ecx
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm4
  __m128 v30; // xmm2
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __m128 v33; // xmm2
  hkVector4f v34; // xmm6
  __m128 v35; // xmm1
  hkVector4f v36; // xmm0
  __m128 v37; // xmm3
  __m128 v38; // xmm2
  __m128 v39; // xmm4
  __m128 v40; // xmm3
  __m128 v41; // xmm6
  __m128 v42; // xmm5
  __m128 v43; // xmm6
  __m128 v44; // xmm1
  __m128 v45; // xmm4
  __m128 v46; // xmm13
  __m128 v47; // xmm13
  __m128 v48; // xmm1
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  __m128 v51; // xmm4
  __m128 v52; // xmm0
  hkVector4f v53; // xmm13
  __m128 v54; // xmm1
  __m128 v55; // xmm1
  __m128 v56; // xmm2
  hkContactPoint *v57; // rax
  int v58; // edx
  __m128 v59; // xmm5
  __m128 v60; // xmm3
  __m128 v61; // xmm13
  __m128 v62; // xmm3
  __m128 v63; // xmm12
  __m128 v64; // xmm11
  __m128 v65; // xmm3
  float v66; // xmm2_4
  __m128 v67; // xmm4
  __m128 v68; // xmm1
  __m128 v69; // xmm6
  __m128 v70; // xmm1
  __m128 v71; // xmm2
  hkVector4f v72; // xmm3
  __m128 v73; // xmm1
  __m128 v74; // xmm1
  __m128 v75; // xmm1
  __m128 v77; // [rsp+0h] [rbp-128h]
  __m128 v78; // [rsp+0h] [rbp-128h]
  __m128 v79; // [rsp+10h] [rbp-118h]
  __m128 v80; // [rsp+20h] [rbp-108h]
  __m128 v81; // [rsp+30h] [rbp-F8h]
  __m128 v82; // [rsp+40h] [rbp-E8h]
  float v83; // [rsp+50h] [rbp-D8h]
  __m128 v84; // [rsp+60h] [rbp-C8h]
  __m128 v85; // [rsp+70h] [rbp-B8h]
  float v87; // [rsp+138h] [rbp+10h]

  m_quad = capsBPoints->m_quad;
  v7 = _mm_sub_ps(capsAPointsIn[1].m_quad, capsAPointsIn->m_quad);
  v8 = _mm_sub_ps(capsBPoints[1].m_quad, capsBPoints->m_quad);
  v81 = capsAPointsIn->m_quad;
  v9 = _mm_mul_ps(v7, v8);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  if ( v10.m128_f32[0] >= 0.0 )
  {
    v11 = capsAPointsIn->m_quad;
    v81 = capsAPointsIn[1].m_quad;
  }
  else
  {
    v11 = capsAPointsIn[1].m_quad;
    v10 = _mm_sub_ps((__m128)0i64, v10);
    v7 = _mm_xor_ps(v7, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
  }
  v12 = 0;
  v13 = _mm_sub_ps(m_quad, v11);
  v14 = _mm_mul_ps(v7, v13);
  v15 = _mm_mul_ps(v13, v8);
  v16 = _mm_mul_ps(v10, v10);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v19 = _mm_mul_ps(v7, v7);
  v85 = v18;
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_mul_ps(v8, v8);
  v79 = v20;
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_mul_ps(v22, v20);
  v80 = v22;
  v84 = v23;
  v24 = _mm_sub_ps(_mm_mul_ps(v22, v17), _mm_mul_ps(v10, v18));
  v25 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v23, v16), 1u), 1u);
  v83 = v25.m128_f32[0];
  if ( (float)(v24.m128_f32[0] * v25.m128_f32[0]) >= (float)(v25.m128_f32[0] * v25.m128_f32[0]) )
    goto LABEL_5;
  if ( v24.m128_f32[0] > 0.0 )
  {
    if ( v25.m128_f32[0] <= (float)((float)(COERCE_FLOAT((unsigned int)(2 * v23.m128_i32[0]) >> 1) + v16.m128_f32[0])
                                  * (float)(0.00000011920929 * 8.0)) )
    {
LABEL_5:
      v26 = 1;
      v27 = query.m_quad;
      goto LABEL_6;
    }
    v30 = _mm_rcp_ps(v25);
    v26 = 0;
    v27 = _mm_mul_ps(v24, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v30, v25)), v30));
  }
  else
  {
    v27 = 0i64;
    v26 = 2;
  }
LABEL_6:
  v28 = _mm_sub_ps(_mm_mul_ps(v10, v27), v18);
  if ( v28.m128_f32[0] < v22.m128_f32[0] )
  {
    if ( v28.m128_f32[0] > 0.0 )
    {
      v33 = _mm_rcp_ps(v22);
      v29 = _mm_mul_ps(v28, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v33, v22)), v33));
      goto $end_3;
    }
    v29 = 0i64;
    v26 = 8;
  }
  else
  {
    v29 = query.m_quad;
    v26 = 4;
  }
  v31 = _mm_add_ps(_mm_mul_ps(v10, v29), v17);
  if ( v31.m128_f32[0] > 0.0 )
  {
    if ( v31.m128_f32[0] < v20.m128_f32[0] )
    {
      v32 = _mm_rcp_ps(v20);
      v27 = _mm_mul_ps(v31, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v32, v20)), v32));
    }
    else
    {
      v27 = query.m_quad;
      v26 |= 1u;
    }
  }
  else
  {
    v27 = 0i64;
    v26 |= 2u;
  }
$end_3:
  v82 = _mm_add_ps(_mm_mul_ps(v7, v27), v11);
  v34.m_quad = _mm_sub_ps(v82, _mm_add_ps(_mm_mul_ps(v29, v8), capsBPoints->m_quad));
  v87 = capsARadius + capsBRadius;
  v35 = _mm_mul_ps(v34.m_quad, v34.m_quad);
  v36.m_quad = (__m128)points->m_separatingNormal;
  points->m_separatingNormal = (hkVector4f)v34.m_quad;
  v37 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)), _mm_shuffle_ps(v35, v35, 170));
  v38 = _mm_rsqrt_ps(v37);
  v39 = _mm_andnot_ps(
          _mm_cmple_ps(v37, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v38, v37), v38)),
              _mm_mul_ps(v38, *(__m128 *)_xmm)),
            v37));
  v40 = _mm_sub_ps(v39, _mm_shuffle_ps((__m128)LODWORD(v87), (__m128)LODWORD(v87), 0));
  v77 = v40;
  if ( v40.m128_f32[0] >= fmax(0.00000011920929, _mm_shuffle_ps(v36.m_quad, v36.m_quad, 255).m128_f32[0]) )
  {
    v74 = _mm_rcp_ps(v39);
    v75 = _mm_mul_ps(points->m_separatingNormal.m_quad, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v74, v39)), v74));
    points->m_separatingNormal.m_quad = _mm_shuffle_ps(v75, _mm_unpackhi_ps(v75, v40), 196);
  }
  else
  {
    if ( v39.m128_f32[0] >= 0.00000011920929 )
    {
      v54 = _mm_rcp_ps(v39);
      v53.m_quad = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v54, v39)), v54), v34.m_quad);
    }
    else
    {
      v41 = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, (__m128)0i64), 196);
      v42 = _mm_shuffle_ps(v41, v41, 241);
      v43 = _mm_shuffle_ps(v41, v41, 206);
      v44 = _mm_mul_ps(v43, v43);
      v45 = _mm_mul_ps(v42, v42);
      v46 = _mm_cmplt_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
                _mm_shuffle_ps(v45, v45, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
                _mm_shuffle_ps(v44, v44, 170)));
      v47 = _mm_xor_ps(
              _mm_or_ps(_mm_and_ps(v46, v43), _mm_andnot_ps(v46, v42)),
              (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
      v48 = _mm_mul_ps(v47, v47);
      v49 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)),
              _mm_shuffle_ps(v48, v48, 170));
      v50 = _mm_rsqrt_ps(v49);
      v51 = _mm_cmple_ps(v49, (__m128)0i64);
      v52 = _mm_mul_ps(v50, v49);
      v40 = v77;
      v53.m_quad = _mm_mul_ps(
                     v47,
                     _mm_andnot_ps(
                       v51,
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v52, v50)), _mm_mul_ps(v50, *(__m128 *)_xmm))));
      v39 = 0i64;
    }
    points->m_separatingNormal = (hkVector4f)v53.m_quad;
    points->m_position.m_quad = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_sub_ps(
                                      _mm_shuffle_ps((__m128)LODWORD(capsBRadius), (__m128)LODWORD(capsBRadius), 0),
                                      v39),
                                    v53.m_quad),
                                  v82);
    points->m_separatingNormal.m_quad = _mm_shuffle_ps(v53.m_quad, _mm_unpackhi_ps(v53.m_quad, v40), 196);
    if ( v83 <= (float)((float)(v20.m128_f32[0] * 0.2) * v22.m128_f32[0]) )
    {
      v55 = _mm_rcp_ps(v84);
      v56 = capsBPoints->m_quad;
      v57 = points + 1;
      v58 = 10;
      v59 = _mm_sub_ps((__m128)0i64, v85);
      v60 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v55, v84)), v55);
      v61 = _mm_mul_ps(v60, v20);
      v62 = _mm_mul_ps(v60, v22);
      v78 = v62;
      while ( 1 )
      {
        if ( (v58 & v26) != 0 )
          goto $nextPoint;
        if ( v59.m128_f32[0] <= 0.0 )
        {
          if ( v17.m128_f32[0] > 0.0 )
          {
            if ( v17.m128_f32[0] > v20.m128_f32[0] )
              goto $nextPoint;
LABEL_35:
            v11 = _mm_add_ps(v11, _mm_mul_ps(_mm_mul_ps(v62, v17), v7));
          }
        }
        else
        {
          if ( v59.m128_f32[0] > v22.m128_f32[0] )
            goto $nextPoint;
          if ( v17.m128_f32[0] > 0.0 )
          {
            if ( v17.m128_f32[0] > v20.m128_f32[0] )
              goto $nextPoint;
            if ( (float)((float)(v59.m128_f32[0] * v59.m128_f32[0]) * v61.m128_f32[0]) > (float)((float)(v17.m128_f32[0] * v17.m128_f32[0])
                                                                                               * v62.m128_f32[0]) )
              goto LABEL_35;
          }
          v56 = _mm_add_ps(v56, _mm_mul_ps(_mm_mul_ps(v59, v61), v8));
        }
        v63 = _mm_sub_ps(v11, v56);
        v64 = _mm_shuffle_ps((__m128)LODWORD(v87), (__m128)LODWORD(v87), 0);
        v65 = _mm_mul_ps(v63, v63);
        v66 = _mm_shuffle_ps(v57->m_separatingNormal.m_quad, v57->m_separatingNormal.m_quad, 255).m128_f32[0]
            + v64.m128_f32[0];
        v67 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
                _mm_shuffle_ps(v65, v65, 170));
        if ( v67.m128_f32[0] < (float)(v66 * v66) )
        {
          v68 = _mm_rsqrt_ps(v67);
          v69 = _mm_andnot_ps(
                  _mm_cmple_ps(v67, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v68, v67), v68)),
                      _mm_mul_ps(*(__m128 *)_xmm, v68)),
                    v67));
          if ( v67.m128_f32[0] <= 0.00000011920929 )
          {
            v72.m_quad = (__m128)points->m_separatingNormal;
          }
          else
          {
            v70 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
                    _mm_shuffle_ps(v65, v65, 170));
            v71 = _mm_rsqrt_ps(v70);
            v72.m_quad = _mm_mul_ps(
                           _mm_andnot_ps(
                             _mm_cmple_ps(v70, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v71, v70), v71)),
                               _mm_mul_ps(*(__m128 *)_xmm, v71))),
                           v63);
          }
          v57->m_separatingNormal = (hkVector4f)v72.m_quad;
          v57->m_position.m_quad = _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_sub_ps(
                                         _mm_shuffle_ps((__m128)LODWORD(capsBRadius), (__m128)LODWORD(capsBRadius), 0),
                                         v69),
                                       v72.m_quad),
                                     v11);
          v57->m_separatingNormal.m_quad = _mm_shuffle_ps(
                                             v57->m_separatingNormal.m_quad,
                                             _mm_unpackhi_ps(v57->m_separatingNormal.m_quad, _mm_sub_ps(v69, v64)),
                                             196);
        }
        v22 = v80;
        v62 = v78;
        v20 = v79;
$nextPoint:
        if ( v12 == 1 )
          return v26;
        v11 = v81;
        v56 = capsBPoints[1].m_quad;
        ++v57;
        v58 = 5;
        ++v12;
        v59 = _mm_sub_ps(_mm_sub_ps(v22, v59), v10);
        v17 = _mm_sub_ps(_mm_sub_ps(v20, v17), v10);
        v73 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
        v7 = _mm_xor_ps(v7, v73);
        v8 = _mm_xor_ps(v8, v73);
      }
    }
  }
  return v26;
}

// File Line: 438
// RVA: 0xC698E0
__int64 __fastcall hkLineSegmentUtil::closestPointLineSeg(
        hkVector4f *A,
        hkVector4f *B,
        hkVector4f *B2,
        hkLineSegmentUtil::ClosestPointLineSegResult *result)
{
  __m128 m_quad; // xmm6
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm5
  __int64 v10; // rax
  __m128 v11; // xmm2

  m_quad = B->m_quad;
  v5 = _mm_sub_ps(B2->m_quad, B->m_quad);
  v6 = _mm_mul_ps(_mm_sub_ps(A->m_quad, B->m_quad), v5);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_mul_ps(v5, v5);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  if ( v7.m128_f32[0] > 0.0 )
  {
    if ( v7.m128_f32[0] < v9.m128_f32[0] )
    {
      v11 = _mm_rcp_ps(v9);
      v10 = 0i64;
      result->m_pointOnEdge.m_quad = _mm_add_ps(
                                       _mm_mul_ps(
                                         v5,
                                         _mm_mul_ps(v7, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11, v9)), v11))),
                                       m_quad);
    }
    else
    {
      *result = (hkLineSegmentUtil::ClosestPointLineSegResult)B2->m_quad;
      return 4i64;
    }
  }
  else
  {
    *result = (hkLineSegmentUtil::ClosestPointLineSegResult)m_quad;
    return 8i64;
  }
  return v10;
}

// File Line: 469
// RVA: 0xC699A0
hkResult *__fastcall hkLineSegmentUtil::closestPointInfLineInfLine(
        hkResult *result,
        hkVector4f *A,
        hkVector4f *dA,
        hkVector4f *B,
        hkVector4f *dB,
        hkLineSegmentUtil::ClosestPointInfLineInfLineResult *resulta)
{
  __m128 m_quad; // xmm5
  __m128 v7; // xmm6
  __m128 v8; // xmm1
  __m128 v9; // xmm11
  __m128 v10; // xmm2
  __m128 v11; // xmm8
  __m128 v12; // xmm1
  __m128 v13; // xmm4
  __m128 v14; // xmm9
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm7
  __m128 v19; // xmm0
  __m128 v20; // xmm3
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  hkVector4f v25; // xmm5
  __m128 v26; // xmm3
  hkVector4f v27; // xmm6
  __m128 v28; // xmm2
  __m128 v29; // xmm2

  m_quad = dA->m_quad;
  v7 = dB->m_quad;
  v8 = _mm_mul_ps(dB->m_quad, dA->m_quad);
  v9 = B->m_quad;
  v10 = _mm_sub_ps(B->m_quad, A->m_quad);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v12 = _mm_mul_ps(dB->m_quad, v10);
  v13 = _mm_mul_ps(dA->m_quad, v10);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v15 = _mm_mul_ps(m_quad, m_quad);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_mul_ps(v7, v7);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_mul_ps(v11, v11);
  v20 = _mm_mul_ps(v18, v16);
  v10.m128_i32[0] = 2 * v20.m128_i32[0];
  v21 = _mm_sub_ps(v20, v19);
  if ( COERCE_FLOAT((unsigned int)(2 * v21.m128_i32[0]) >> 1) <= (float)((float)(COERCE_FLOAT((unsigned int)v10.m128_i32[0] >> 1)
                                                                               + v19.m128_f32[0])
                                                                       * (float)(0.00000011920929 * 8.0)) )
  {
    v23 = 0i64;
    result->m_enum = HK_FAILURE;
  }
  else
  {
    v22 = _mm_rcp_ps(v21);
    result->m_enum = HK_SUCCESS;
    v23 = _mm_mul_ps(
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v21)), v22),
            _mm_sub_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                  _mm_shuffle_ps(v13, v13, 170)),
                v18),
              _mm_mul_ps(v14, v11)));
  }
  v24 = _mm_rcp_ps(v18);
  v25.m_quad = _mm_add_ps(_mm_mul_ps(m_quad, v23), A->m_quad);
  resulta->m_closestPointA = (hkVector4f)v25.m_quad;
  v26 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v24, v18)), v24),
          _mm_sub_ps(_mm_mul_ps(v23, v11), v14));
  v27.m_quad = _mm_add_ps(_mm_mul_ps(v7, v26), v9);
  v28 = _mm_sub_ps(v25.m_quad, v27.m_quad);
  resulta->m_closestPointB = (hkVector4f)v27.m_quad;
  v29 = _mm_mul_ps(v28, v28);
  resulta->m_distanceSquared.m_storage = (float)(_mm_shuffle_ps(v29, v29, 85).m128_f32[0]
                                               + _mm_shuffle_ps(v29, v29, 0).m128_f32[0])
                                       + _mm_shuffle_ps(v29, v29, 170).m128_f32[0];
  LODWORD(resulta->m_fractionA.m_storage) = v23.m128_i32[0];
  LODWORD(resulta->m_fractionB.m_storage) = v26.m128_i32[0];
  return result;
}

// File Line: 521
// RVA: 0xC69B90
hkResult *__fastcall hkLineSegmentUtil::intersectionInfLinePlane(
        hkResult *result,
        hkVector4f *A,
        hkVector4f *dA,
        hkVector4f *planeEquation,
        hkLineSegmentUtil::IntersectionInfLinePlaneResult *resulta)
{
  __m128 m_quad; // xmm5
  __m128 v6; // xmm7
  __m128 v7; // xmm1
  __m128i v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm6
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm0

  m_quad = planeEquation->m_quad;
  v6 = dA->m_quad;
  v7 = _mm_mul_ps(planeEquation->m_quad, dA->m_quad);
  v8 = (__m128i)_mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)),
                  _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rcp_ps((__m128)v8);
  v10 = _mm_cmplt_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v8, 1u), 1u), *(__m128 *)&epsilon);
  v11 = _mm_mul_ps(v9, (__m128)v8);
  v12 = _mm_mul_ps(A->m_quad, planeEquation->m_quad);
  v13 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v11), v9);
  result->m_enum = _mm_movemask_ps(v10) != 0;
  v14 = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, m_quad), 196);
  v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
  v16 = _mm_andnot_ps(v10, _mm_mul_ps(_mm_sub_ps((__m128)0i64, _mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15)), v13));
  resulta->m_pointOnPlane.m_quad = _mm_add_ps(_mm_mul_ps(v6, v16), A->m_quad);
  LODWORD(resulta->m_fractionA.m_storage) = v16.m128_i32[0];
  return result;
}


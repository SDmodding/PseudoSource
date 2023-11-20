// File Line: 15
// RVA: 0xC68EC0
signed __int64 __fastcall hkLineSegmentUtil::closestLineSegLineSeg(hkVector4f *A, hkVector4f *dA, hkVector4f *B, hkVector4f *dB, hkLineSegmentUtil::ClosestLineSegLineSegResult *result)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm2
  __m128 v7; // xmm1
  __m128 v8; // xmm9
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm11
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm10
  __m128 v16; // xmm8
  __m128 v17; // xmm7
  __m128 v18; // xmm4
  __m128 v19; // xmm12
  __m128 v20; // xmm5
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  signed __int64 v23; // rax
  __m128 v24; // xmm1
  __m128 v25; // xmm5
  __m128 v26; // xmm4
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 v29; // xmm2
  __m128 v30; // xmm4
  hkVector4f v31; // xmm0
  hkVector4f v32; // xmm2
  __m128 v33; // xmm2

  v5 = dA->m_quad;
  v6 = _mm_sub_ps(B->m_quad, A->m_quad);
  v7 = _mm_mul_ps(dB->m_quad, dA->m_quad);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = v5;
  v10 = _mm_mul_ps(v5, v5);
  v11 = _mm_mul_ps(v9, v6);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_mul_ps(dB->m_quad, v6);
  v14 = _mm_mul_ps(dB->m_quad, dB->m_quad);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v18 = _mm_mul_ps(v8, v8);
  v19 = _mm_mul_ps(v17, v16);
  v20 = _mm_sub_ps(_mm_mul_ps(v17, v12), _mm_mul_ps(v15, v8));
  v21 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v19, v18), 1u), 1u);
  if ( (float)(v20.m128_f32[0] * v21.m128_f32[0]) >= (float)(v21.m128_f32[0] * v21.m128_f32[0]) )
    goto LABEL_20;
  v22 = 0i64;
  if ( v20.m128_f32[0] <= 0.0 )
  {
    v23 = 2i64;
    goto LABEL_7;
  }
  if ( v21.m128_f32[0] <= (float)((float)(v18.m128_f32[0] + v19.m128_f32[0]) * (float)(0.00000011920929 * 8.0)) )
  {
LABEL_20:
    v23 = 1i64;
    v22 = query.m_quad;
  }
  else
  {
    v24 = _mm_rcp_ps(v21);
    v23 = 0i64;
    v22 = _mm_mul_ps(v20, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v21, v24)), v24));
  }
LABEL_7:
  v25 = _mm_sub_ps(_mm_mul_ps(v22, v8), v15);
  if ( v25.m128_f32[0] < v17.m128_f32[0] )
  {
    v26 = 0i64;
    if ( v25.m128_f32[0] > 0.0 )
    {
      v29 = _mm_rcp_ps(v17);
      v26 = _mm_mul_ps(v25, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v29, v17)), v29));
      goto $end_2;
    }
    v23 = 8i64;
  }
  else
  {
    v26 = query.m_quad;
    v23 = 4i64;
  }
  v22 = 0i64;
  v27 = _mm_add_ps(_mm_mul_ps(v26, v8), v12);
  if ( v27.m128_f32[0] > 0.0 )
  {
    if ( v27.m128_f32[0] < v16.m128_f32[0] )
    {
      v28 = _mm_rcp_ps(v16);
      v22 = _mm_mul_ps(v27, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v16)), v28));
    }
    else
    {
      v22 = query.m_quad;
      v23 = (unsigned int)v23 | 1;
    }
  }
  else
  {
    v23 = (unsigned int)v23 | 2;
  }
$end_2:
  result->m_t.m_real = v22;
  result->m_u.m_real = v26;
  v30 = _mm_add_ps(_mm_mul_ps(v26, dB->m_quad), B->m_quad);
  v31.m_quad = _mm_add_ps(_mm_mul_ps(dA->m_quad, v22), A->m_quad);
  result->m_closestPointA = (hkVector4f)v31.m_quad;
  v32.m_quad = _mm_sub_ps(v31.m_quad, v30);
  result->m_closestAminusClosestB = (hkVector4f)v32.m_quad;
  v33 = _mm_mul_ps(v32.m_quad, v32.m_quad);
  result->m_distanceSquared.m_storage = (float)(COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 85))
                                              + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 0)))
                                      + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 170));
  return v23;
}

// File Line: 122
// RVA: 0xC69140
__int64 __fastcall hkLineSegmentUtil::capsuleCapsuleManifold(hkVector4f *capsAPointsIn, float capsARadius, hkVector4f *capsBPoints, float capsBRadius, hkContactPoint *points)
{
  __m128 v5; // xmm4
  hkVector4f *v6; // r10
  __m128 v7; // xmm10
  __m128 v8; // xmm14
  __m128 v9; // xmm1
  __m128 v10; // xmm15
  __m128 v11; // xmm8
  int v12; // er8
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
  float v26; // xmm13_4
  unsigned int v27; // ecx
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm4
  float v31; // xmm1_4
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // xmm2
  __m128 v36; // xmm6
  hkVector4f v37; // xmm6
  __m128 v38; // xmm1
  hkVector4f v39; // xmm0
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm4
  __m128 v43; // xmm3
  __m128 v44; // xmm6
  __m128 v45; // xmm5
  __m128 v46; // xmm6
  __m128 v47; // xmm1
  __m128 v48; // xmm4
  __m128 v49; // xmm2
  __m128 v50; // xmm13
  __m128 v51; // xmm1
  __m128 v52; // xmm3
  __m128 v53; // xmm2
  __m128 v54; // xmm4
  __m128 v55; // xmm0
  hkVector4f v56; // xmm13
  __m128 v57; // xmm1
  __m128 v58; // xmm1
  __m128 v59; // xmm2
  hkContactPoint *v60; // rax
  signed int v61; // edx
  __m128 v62; // xmm5
  __m128 v63; // xmm3
  __m128 v64; // xmm13
  __m128 v65; // xmm3
  __m128 v66; // xmm12
  __m128 v67; // xmm11
  __m128 v68; // xmm3
  float v69; // xmm2_4
  __m128 v70; // xmm4
  __m128 v71; // xmm1
  __m128 v72; // xmm6
  __m128 v73; // xmm1
  __m128 v74; // xmm2
  hkVector4f v75; // xmm3
  __m128 v76; // xmm1
  __m128 v77; // xmm1
  __m128 v78; // xmm1
  __m128 v80; // [rsp+0h] [rbp-128h]
  __m128 v81; // [rsp+0h] [rbp-128h]
  __m128 v82; // [rsp+10h] [rbp-118h]
  __m128 v83; // [rsp+20h] [rbp-108h]
  __m128 v84; // [rsp+30h] [rbp-F8h]
  __m128 v85; // [rsp+40h] [rbp-E8h]
  float v86; // [rsp+50h] [rbp-D8h]
  __m128 v87; // [rsp+60h] [rbp-C8h]
  __m128 v88; // [rsp+70h] [rbp-B8h]
  float v89; // [rsp+138h] [rbp+10h]
  float v90; // [rsp+138h] [rbp+10h]
  float v91; // [rsp+148h] [rbp+20h]

  v91 = capsBRadius;
  v89 = capsARadius;
  v5 = capsBPoints->m_quad;
  v6 = capsBPoints;
  v7 = _mm_sub_ps(capsAPointsIn[1].m_quad, capsAPointsIn->m_quad);
  v8 = _mm_sub_ps(capsBPoints[1].m_quad, capsBPoints->m_quad);
  v84 = capsAPointsIn->m_quad;
  v9 = _mm_mul_ps(v7, v8);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  if ( v10.m128_f32[0] >= 0.0 )
  {
    v11 = capsAPointsIn->m_quad;
    v84 = capsAPointsIn[1].m_quad;
  }
  else
  {
    v11 = capsAPointsIn[1].m_quad;
    v10 = _mm_sub_ps((__m128)0i64, v10);
    v7 = _mm_xor_ps(v7, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
  }
  v12 = 0;
  v13 = _mm_sub_ps(v5, v11);
  v14 = _mm_mul_ps(v7, v13);
  v15 = _mm_mul_ps(v13, v8);
  v16 = _mm_mul_ps(v10, v10);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v19 = _mm_mul_ps(v7, v7);
  v88 = v18;
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_mul_ps(v8, v8);
  v82 = v20;
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_mul_ps(v22, v20);
  v83 = v22;
  v87 = v23;
  v24 = _mm_sub_ps(_mm_mul_ps(v22, v17), _mm_mul_ps(v10, v18));
  v25 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v23, v16), 1u), 1u);
  v86 = v25.m128_f32[0];
  if ( (float)(v24.m128_f32[0] * v25.m128_f32[0]) >= (float)(v25.m128_f32[0] * v25.m128_f32[0]) )
  {
    v26 = epsilon;
LABEL_6:
    v27 = 1;
    v28 = query.m_quad;
    goto LABEL_7;
  }
  if ( v24.m128_f32[0] > 0.0 )
  {
    v31 = COERCE_FLOAT((unsigned int)(2 * v23.m128_i32[0]) >> 1) + v16.m128_f32[0];
    v26 = epsilon;
    if ( v25.m128_f32[0] <= (float)(v31 * (float)(0.00000011920929 * 8.0)) )
      goto LABEL_6;
    v32 = _mm_rcp_ps(v25);
    v27 = 0;
    v28 = _mm_mul_ps(v24, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v32, v25)), v32));
  }
  else
  {
    v26 = epsilon;
    v28 = 0i64;
    v27 = 2;
  }
LABEL_7:
  v29 = _mm_sub_ps(_mm_mul_ps(v10, v28), v18);
  if ( v29.m128_f32[0] < v22.m128_f32[0] )
  {
    if ( v29.m128_f32[0] > 0.0 )
    {
      v35 = _mm_rcp_ps(v22);
      v30 = _mm_mul_ps(v29, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v35, v22)), v35));
      goto $end_3;
    }
    v30 = 0i64;
    v27 = 8;
  }
  else
  {
    v30 = query.m_quad;
    v27 = 4;
  }
  v33 = _mm_add_ps(_mm_mul_ps(v10, v30), v17);
  if ( v33.m128_f32[0] > 0.0 )
  {
    if ( v33.m128_f32[0] < v20.m128_f32[0] )
    {
      v34 = _mm_rcp_ps(v20);
      v28 = _mm_mul_ps(v33, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v34, v20)), v34));
    }
    else
    {
      v28 = query.m_quad;
      v27 |= 1u;
    }
  }
  else
  {
    v28 = 0i64;
    v27 |= 2u;
  }
$end_3:
  v36 = _mm_add_ps(_mm_mul_ps(v7, v28), v11);
  v85 = v36;
  v37.m_quad = _mm_sub_ps(v36, _mm_add_ps(_mm_mul_ps(v30, v8), v6->m_quad));
  v90 = v89 + v91;
  v38 = _mm_mul_ps(v37.m_quad, v37.m_quad);
  v39.m_quad = (__m128)points->m_separatingNormal;
  points->m_separatingNormal = (hkVector4f)v37.m_quad;
  v40 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)), _mm_shuffle_ps(v38, v38, 170));
  v41 = _mm_rsqrt_ps(v40);
  v42 = _mm_andnot_ps(
          _mm_cmpleps(v40, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v40), v41)),
              _mm_mul_ps(v41, *(__m128 *)_xmm)),
            v40));
  v43 = _mm_sub_ps(v42, _mm_shuffle_ps((__m128)LODWORD(v90), (__m128)LODWORD(v90), 0));
  v80 = v43;
  if ( v43.m128_f32[0] >= fmax(v26, COERCE_FLOAT(_mm_shuffle_ps(v39.m_quad, v39.m_quad, 255))) )
  {
    v77 = _mm_rcp_ps(v42);
    v78 = _mm_mul_ps(points->m_separatingNormal.m_quad, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v77, v42)), v77));
    points->m_separatingNormal.m_quad = _mm_shuffle_ps(v78, _mm_unpackhi_ps(v78, v43), 196);
  }
  else
  {
    if ( v42.m128_f32[0] >= 0.00000011920929 )
    {
      v57 = _mm_rcp_ps(v42);
      v56.m_quad = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v57, v42)), v57), v37.m_quad);
    }
    else
    {
      v44 = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, (__m128)0i64), 196);
      v45 = _mm_shuffle_ps(v44, v44, 241);
      v46 = _mm_shuffle_ps(v44, v44, 206);
      v47 = _mm_mul_ps(v46, v46);
      v48 = _mm_mul_ps(v45, v45);
      v49 = _mm_cmpltps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)),
                _mm_shuffle_ps(v48, v48, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
                _mm_shuffle_ps(v47, v47, 170)));
      v50 = _mm_xor_ps(
              _mm_or_ps(_mm_and_ps(v49, v46), _mm_andnot_ps(v49, v45)),
              (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
      v51 = _mm_mul_ps(v50, v50);
      v52 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
              _mm_shuffle_ps(v51, v51, 170));
      v53 = _mm_rsqrt_ps(v52);
      v54 = _mm_cmpleps(v52, (__m128)0i64);
      v55 = _mm_mul_ps(v53, v52);
      v43 = v80;
      v56.m_quad = _mm_mul_ps(
                     v50,
                     _mm_andnot_ps(
                       v54,
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v55, v53)), _mm_mul_ps(v53, *(__m128 *)_xmm))));
      v42 = 0i64;
    }
    points->m_separatingNormal = (hkVector4f)v56.m_quad;
    points->m_position.m_quad = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_sub_ps(_mm_shuffle_ps((__m128)LODWORD(v91), (__m128)LODWORD(v91), 0), v42),
                                    v56.m_quad),
                                  v85);
    points->m_separatingNormal.m_quad = _mm_shuffle_ps(v56.m_quad, _mm_unpackhi_ps(v56.m_quad, v43), 196);
    if ( v86 <= (float)((float)(v20.m128_f32[0] * 0.2) * v22.m128_f32[0]) )
    {
      v58 = _mm_rcp_ps(v87);
      v59 = v6->m_quad;
      v60 = points + 1;
      v61 = 10;
      v62 = _mm_sub_ps((__m128)0i64, v88);
      v63 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v58, v87)), v58);
      v64 = _mm_mul_ps(v63, v20);
      v65 = _mm_mul_ps(v63, v22);
      v81 = v65;
      while ( 1 )
      {
        if ( v61 & v27 )
          goto $nextPoint;
        if ( v62.m128_f32[0] <= 0.0 )
        {
          if ( v17.m128_f32[0] > 0.0 )
          {
            if ( v17.m128_f32[0] > v20.m128_f32[0] )
              goto $nextPoint;
LABEL_36:
            v11 = _mm_add_ps(v11, _mm_mul_ps(_mm_mul_ps(v65, v17), v7));
            goto LABEL_37;
          }
        }
        else
        {
          if ( v62.m128_f32[0] > v22.m128_f32[0] )
            goto $nextPoint;
          if ( v17.m128_f32[0] > 0.0 )
          {
            if ( v17.m128_f32[0] > v20.m128_f32[0] )
              goto $nextPoint;
            if ( (float)((float)(v62.m128_f32[0] * v62.m128_f32[0]) * v64.m128_f32[0]) > (float)((float)(v17.m128_f32[0] * v17.m128_f32[0])
                                                                                               * v65.m128_f32[0]) )
              goto LABEL_36;
          }
          v59 = _mm_add_ps(v59, _mm_mul_ps(_mm_mul_ps(v62, v64), v8));
        }
LABEL_37:
        v66 = _mm_sub_ps(v11, v59);
        v67 = _mm_shuffle_ps((__m128)LODWORD(v90), (__m128)LODWORD(v90), 0);
        v68 = _mm_mul_ps(v66, v66);
        v69 = COERCE_FLOAT(_mm_shuffle_ps(v60->m_separatingNormal.m_quad, v60->m_separatingNormal.m_quad, 255))
            + v67.m128_f32[0];
        v70 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
                _mm_shuffle_ps(v68, v68, 170));
        if ( v70.m128_f32[0] < (float)(v69 * v69) )
        {
          v71 = _mm_rsqrt_ps(v70);
          v72 = _mm_andnot_ps(
                  _mm_cmpleps(v70, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v71, v70), v71)),
                      _mm_mul_ps(*(__m128 *)_xmm, v71)),
                    v70));
          if ( v70.m128_f32[0] <= 0.00000011920929 )
          {
            v75.m_quad = (__m128)points->m_separatingNormal;
          }
          else
          {
            v73 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
                    _mm_shuffle_ps(v68, v68, 170));
            v74 = _mm_rsqrt_ps(v73);
            v75.m_quad = _mm_mul_ps(
                           _mm_andnot_ps(
                             _mm_cmpleps(v73, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v74, v73), v74)),
                               _mm_mul_ps(*(__m128 *)_xmm, v74))),
                           v66);
          }
          v60->m_separatingNormal = (hkVector4f)v75.m_quad;
          v60->m_position.m_quad = _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_sub_ps(_mm_shuffle_ps((__m128)LODWORD(v91), (__m128)LODWORD(v91), 0), v72),
                                       v75.m_quad),
                                     v11);
          v60->m_separatingNormal.m_quad = _mm_shuffle_ps(
                                             v60->m_separatingNormal.m_quad,
                                             _mm_unpackhi_ps(v60->m_separatingNormal.m_quad, _mm_sub_ps(v72, v67)),
                                             196);
        }
        v22 = v83;
        v65 = v81;
        v20 = v82;
$nextPoint:
        if ( v12 == 1 )
          return v27;
        v11 = v84;
        v59 = v6[1].m_quad;
        ++v60;
        v61 = 5;
        ++v12;
        v62 = _mm_sub_ps(_mm_sub_ps(v22, v62), v10);
        v17 = _mm_sub_ps(_mm_sub_ps(v20, v17), v10);
        v76 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
        v7 = _mm_xor_ps(v7, v76);
        v8 = _mm_xor_ps(v8, v76);
      }
    }
  }
  return v27;
}

// File Line: 438
// RVA: 0xC698E0
signed __int64 __fastcall hkLineSegmentUtil::closestPointLineSeg(hkVector4f *A, hkVector4f *B, hkVector4f *B2, hkLineSegmentUtil::ClosestPointLineSegResult *result)
{
  __m128 v4; // xmm6
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm5
  signed __int64 v10; // rax
  __m128 v11; // xmm2

  v4 = B->m_quad;
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
                                       v4);
    }
    else
    {
      *result = (hkLineSegmentUtil::ClosestPointLineSegResult)B2->m_quad;
      v10 = 4i64;
    }
  }
  else
  {
    *result = (hkLineSegmentUtil::ClosestPointLineSegResult)v4;
    v10 = 8i64;
  }
  return v10;
}

// File Line: 469
// RVA: 0xC699A0
hkResult *__fastcall hkLineSegmentUtil::closestPointInfLineInfLine(hkResult *result, hkVector4f *A, hkVector4f *dA, hkVector4f *B, hkVector4f *dB, hkLineSegmentUtil::ClosestPointInfLineInfLineResult *resulta)
{
  __m128 v6; // xmm5
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
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  hkVector4f v25; // xmm5
  __m128 v26; // xmm3
  hkVector4f v27; // xmm6
  __m128 v28; // xmm2
  __m128 v29; // xmm2

  v6 = dA->m_quad;
  v7 = dB->m_quad;
  v8 = _mm_mul_ps(dB->m_quad, dA->m_quad);
  v9 = B->m_quad;
  v10 = _mm_sub_ps(B->m_quad, A->m_quad);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v12 = _mm_mul_ps(dB->m_quad, v10);
  v13 = _mm_mul_ps(dA->m_quad, v10);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v15 = _mm_mul_ps(v6, v6);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_mul_ps(v7, v7);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_mul_ps(v11, v11);
  v20 = _mm_mul_ps(v18, v16);
  v21 = _mm_sub_ps(v20, v19);
  if ( COERCE_FLOAT((unsigned int)(2 * v21.m128_i32[0]) >> 1) <= (float)((float)(COERCE_FLOAT((unsigned int)(2 * v20.m128_i32[0]) >> 1)
                                                                               + v19.m128_f32[0])
                                                                       * (float)(0.00000011920929 * 8.0)) )
  {
    v23 = 0i64;
    result->m_enum = 1;
  }
  else
  {
    v22 = _mm_rcp_ps(v21);
    result->m_enum = 0;
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
  v25.m_quad = _mm_add_ps(_mm_mul_ps(v6, v23), A->m_quad);
  resulta->m_closestPointA = (hkVector4f)v25.m_quad;
  v26 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v24, v18)), v24),
          _mm_sub_ps(_mm_mul_ps(v23, v11), v14));
  v27.m_quad = _mm_add_ps(_mm_mul_ps(v7, v26), v9);
  v28 = _mm_sub_ps(v25.m_quad, v27.m_quad);
  resulta->m_closestPointB = (hkVector4f)v27.m_quad;
  v29 = _mm_mul_ps(v28, v28);
  resulta->m_distanceSquared.m_storage = (float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)))
                                       + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 170));
  LODWORD(resulta->m_fractionA.m_storage) = v23.m128_i32[0];
  LODWORD(resulta->m_fractionB.m_storage) = v26.m128_i32[0];
  return result;
}

// File Line: 521
// RVA: 0xC69B90
hkResult *__fastcall hkLineSegmentUtil::intersectionInfLinePlane(hkResult *result, hkVector4f *A, hkVector4f *dA, hkVector4f *planeEquation, hkLineSegmentUtil::IntersectionInfLinePlaneResult *resulta)
{
  __m128 v5; // xmm5
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

  v5 = planeEquation->m_quad;
  v6 = dA->m_quad;
  v7 = _mm_mul_ps(planeEquation->m_quad, dA->m_quad);
  v8 = (__m128i)_mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)),
                  _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rcp_ps((__m128)v8);
  v10 = _mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32(v8, 1u), 1u), *(__m128 *)&epsilon);
  v11 = _mm_mul_ps(v9, (__m128)v8);
  v12 = _mm_mul_ps(A->m_quad, planeEquation->m_quad);
  v13 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v11), v9);
  result->m_enum = _mm_movemask_ps(v10) != 0;
  v14 = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, v5), 196);
  v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
  v16 = _mm_andnot_ps(v10, _mm_mul_ps(_mm_sub_ps((__m128)0i64, _mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15)), v13));
  resulta->m_pointOnPlane.m_quad = _mm_add_ps(_mm_mul_ps(v6, v16), A->m_quad);
  LODWORD(resulta->m_fractionA.m_storage) = v16.m128_i32[0];
  return result;
}


// File Line: 28
// RVA: 0xC94AF0
_BOOL8 __fastcall hkcdLineTriangleIntersect(hkcdRay *ray, hkVector4f *vA, hkVector4f *vB, hkVector4f *vC, hkSimdFloat32 *tolerance, hkSimdFloat32 *fractionOut)
{
  hkVector4f v6; // xmm4
  __m128 v7; // xmm3
  __m128 v8; // xmm7
  __m128 v9; // xmm2
  __m128 v10; // xmm9
  __m128 v11; // xmm12
  __m128 v12; // xmm5
  __m128 v13; // xmm10
  __m128 v14; // xmm6
  __m128 v15; // xmm7
  __m128 v16; // xmm11
  __m128 v17; // xmm11
  __m128 v18; // xmm8
  __m128 v19; // xmm9
  __m128 v20; // xmm13
  __m128 v21; // xmm10
  __m128 v22; // xmm3
  __m128 v23; // xmm4
  __m128 v24; // xmm11
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm13
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm3

  v6.m_quad = (__m128)ray->m_direction;
  v7 = _mm_sub_ps(vB->m_quad, vA->m_quad);
  v8 = _mm_sub_ps(vB->m_quad, ray->m_origin.m_quad);
  v9 = _mm_sub_ps(vC->m_quad, vA->m_quad);
  v10 = _mm_sub_ps(vC->m_quad, ray->m_origin.m_quad);
  v11 = _mm_sub_ps(vA->m_quad, ray->m_origin.m_quad);
  v12 = _mm_shuffle_ps(v8, v8, 210);
  v13 = _mm_shuffle_ps(v11, v11, 210);
  v14 = _mm_shuffle_ps(v10, v10, 201);
  v15 = _mm_shuffle_ps(v8, v8, 201);
  v16 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v7), _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v9));
  v17 = _mm_shuffle_ps(v16, v16, 201);
  v18 = _mm_shuffle_ps(v11, v11, 201);
  v19 = _mm_shuffle_ps(v10, v10, 210);
  v20 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v18), _mm_mul_ps(v15, v13)), v6.m_quad);
  v21 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v14), _mm_mul_ps(v19, v18)), v6.m_quad);
  v22 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v19, v15), _mm_mul_ps(v14, v12)), v6.m_quad);
  v23 = _mm_mul_ps(v6.m_quad, v17);
  v24 = _mm_mul_ps(v17, v11);
  v25 = _mm_shuffle_ps(v20, v22, 68);
  v26 = _mm_shuffle_ps(v21, v23, 68);
  v27 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v20, v22, 238), _mm_shuffle_ps(v21, v23, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v25, v26, 221), _mm_shuffle_ps(v25, v26, 136)));
  v28 = _mm_shuffle_ps(v27, v27, 255);
  v29 = _mm_rcp_ps(v28);
  fractionOut->m_real = _mm_mul_ps(
                          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v29, v28)), v29),
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                            _mm_shuffle_ps(v24, v24, 170)));
  v30 = _mm_or_ps(_mm_cmpltps(v28, _mm_sub_ps((__m128)0i64, tolerance->m_real)), _mm_cmpltps(tolerance->m_real, v28));
  return (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v27, (__m128)0i64), v30)) & 7) == 7
      || (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps((__m128)0i64, v27), v30)) & 7) == 7;
}

// File Line: 65
// RVA: 0xC94CF0
signed __int64 __fastcall hkcdSphereCastTriangle(hkcdRay *ray, hkSimdFloat32 *radius, hkVector4f *vA, hkVector4f *vB, hkVector4f *vC, hkSimdFloat32 *fractionOut, hkVector4f *planeOut)
{
  __m128 v7; // xmm4
  hkVector4f v8; // xmm8
  __m128 v9; // xmm10
  __m128 v10; // xmm12
  __m128 v11; // xmm14
  __m128 v12; // xmm15
  hkSimdFloat32 v13; // xmm13
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm6
  __m128 v18; // xmm6
  __m128 v19; // xmm7
  __m128 v20; // xmm9
  __m128 v21; // xmm10
  __m128 v22; // xmm4
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  __m128 v35; // xmm5
  __m128 v36; // xmm5
  __m128 v37; // xmm4
  __m128 v38; // xmm0
  __m128 v39; // xmm3
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm5
  __m128 v43; // xmm3
  __m128 v44; // xmm0
  __m128 v45; // xmm1
  __m128 v46; // xmm2
  __m128 v47; // xmm1
  __m128 v48; // xmm0
  __m128 v49; // xmm2
  __m128 v50; // xmm7
  __m128 v51; // xmm1
  __m128 v52; // xmm9
  __m128 v53; // xmm10
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm2
  __m128 v57; // xmm7
  __m128 v58; // xmm1
  __m128 v59; // xmm3
  __m128 v60; // xmm7
  __m128 v61; // xmm1
  __m128 v62; // xmm3
  __m128 v63; // xmm2
  __m128 v64; // xmm7
  __m128 v65; // xmm5
  __m128 v66; // xmm1
  hkVector4f v67; // xmm5
  hkVector4f v68; // xmm7
  __m128 v69; // xmm1
  __m128 v70; // xmm1
  __m128 v71; // xmm0
  __m128 v72; // xmm1
  __m128 v73; // xmm4
  __m128 v74; // xmm3
  __m128 v75; // xmm0
  __m128 v76; // xmm2
  __m128 v77; // xmm1
  __m128 v78; // xmm1
  __m128 v80; // [rsp+0h] [rbp-128h]
  __m128 v81; // [rsp+10h] [rbp-118h]
  __m128 v82; // [rsp+20h] [rbp-108h]
  __m128 v83; // [rsp+30h] [rbp-F8h]
  __m128 v84; // [rsp+40h] [rbp-E8h]
  __m128 v85; // [rsp+50h] [rbp-D8h]

  v7 = vA->m_quad;
  v8.m_quad = (__m128)ray->m_origin;
  v9 = vB->m_quad;
  v10 = (__m128)xmmword_141A712A0;
  v81 = _mm_shuffle_ps(aabbOut.m_quad, _mm_unpackhi_ps(aabbOut.m_quad, (__m128)xmmword_141A712F0), 196);
  v11 = _mm_sub_ps(vB->m_quad, vA->m_quad);
  v12 = _mm_sub_ps(vC->m_quad, vB->m_quad);
  v13.m_real = 0i64;
  v14 = _mm_shuffle_ps(v11, v11, 201);
  v83 = _mm_shuffle_ps(query.m_quad, _mm_unpackhi_ps(query.m_quad, (__m128)xmmword_141A712A0), 196);
  v15 = _mm_sub_ps(vA->m_quad, vC->m_quad);
  v16 = _mm_shuffle_ps(v12, v12, 201);
  v80 = v15;
  v84 = v16;
  v85 = v14;
  v17 = _mm_sub_ps(_mm_mul_ps(v11, v16), _mm_mul_ps(v12, v14));
  v18 = _mm_shuffle_ps(v17, v17, 201);
  v82 = _mm_shuffle_ps(v15, v15, 201);
  do
  {
    v19 = _mm_sub_ps(v8.m_quad, v7);
    v20 = _mm_sub_ps(v8.m_quad, v9);
    v21 = _mm_sub_ps(v8.m_quad, vC->m_quad);
    v22 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v11), _mm_mul_ps(v19, v14));
    v23 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v12), _mm_mul_ps(v20, v16));
    v24 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v18);
    v25 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v15), _mm_mul_ps(v21, v82));
    v26 = v24;
    v27 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v18);
    v28 = _mm_unpackhi_ps(v24, v27);
    v29 = _mm_unpacklo_ps(v26, v27);
    v30 = _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v18);
    v31 = _mm_movelh_ps(v29, v30);
    if ( (_mm_movemask_ps(
            _mm_cmpltps(
              v81,
              _mm_add_ps(
                _mm_shuffle_ps(v28, v30, 228),
                _mm_add_ps(v31, _mm_shuffle_ps(_mm_movehl_ps(v31, v29), v30, 212))))) & 7) == 7 )
    {
      v32 = _mm_mul_ps(v18, v18);
      v33 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
              _mm_shuffle_ps(v32, v32, 170));
      v34 = _mm_mul_ps(v18, v19);
      v35 = _mm_sub_ps(
              v8.m_quad,
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpeqps(v33, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_rcp_ps(v33),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                      _mm_shuffle_ps(v34, v34, 170)))),
                v18));
    }
    else
    {
      v36 = _mm_mul_ps(v11, v11);
      v37 = _mm_mul_ps(v19, v11);
      v38 = _mm_mul_ps(v12, v12);
      v39 = _mm_mul_ps(v80, v80);
      v40 = _mm_unpacklo_ps(v36, v38);
      v41 = _mm_movelh_ps(v40, v39);
      v42 = _mm_add_ps(
              _mm_shuffle_ps(_mm_unpackhi_ps(v36, v38), v39, 228),
              _mm_add_ps(v41, _mm_shuffle_ps(_mm_movehl_ps(v41, v40), v39, 212)));
      v43 = _mm_mul_ps(v21, v80);
      v44 = _mm_mul_ps(v20, v12);
      v45 = _mm_unpacklo_ps(v37, v44);
      v46 = _mm_movelh_ps(v45, v43);
      v47 = _mm_andnot_ps(
              _mm_cmpeqps(v42, (__m128)0i64),
              _mm_mul_ps(
                _mm_rcp_ps(v42),
                _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v37, v44), v43, 228),
                  _mm_add_ps(v46, _mm_shuffle_ps(_mm_movehl_ps(v46, v45), v43, 212)))));
      v48 = _mm_cmpltps(v47, v83);
      v49 = _mm_max_ps(v81, _mm_or_ps(_mm_and_ps(v47, v48), _mm_andnot_ps(v48, v83)));
      v50 = _mm_sub_ps(v19, _mm_mul_ps(_mm_shuffle_ps(v49, v49, 0), v11));
      v51 = _mm_mul_ps(v50, v50);
      v52 = _mm_sub_ps(v20, _mm_mul_ps(_mm_shuffle_ps(v49, v49, 85), v12));
      v53 = _mm_sub_ps(v21, _mm_mul_ps(_mm_shuffle_ps(v49, v49, 170), v80));
      v54 = _mm_mul_ps(v52, v52);
      v55 = _mm_cmpltps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
                _mm_shuffle_ps(v51, v51, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
                _mm_shuffle_ps(v54, v54, 170)));
      v56 = _mm_mul_ps(v53, v53);
      v57 = _mm_or_ps(_mm_and_ps(v50, v55), _mm_andnot_ps(v55, v52));
      v58 = _mm_mul_ps(v57, v57);
      v59 = _mm_cmpltps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)),
                _mm_shuffle_ps(v58, v58, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                _mm_shuffle_ps(v56, v56, 170)));
      v35 = _mm_sub_ps(v8.m_quad, _mm_or_ps(_mm_and_ps(v57, v59), _mm_andnot_ps(v59, v53)));
    }
    v60 = _mm_sub_ps(v8.m_quad, v35);
    v61 = _mm_mul_ps(v60, v60);
    v62 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v61, v61, 85), _mm_shuffle_ps(v61, v61, 0)),
            _mm_shuffle_ps(v61, v61, 170));
    v63 = _mm_rsqrt_ps(v62);
    v64 = _mm_mul_ps(
            v60,
            _mm_andnot_ps(
              _mm_cmpleps(v62, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v63, v62), v63)),
                _mm_mul_ps(*(__m128 *)_xmm, v63))));
    v65 = _mm_mul_ps(v35, v64);
    v66 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
            _mm_shuffle_ps(v65, v65, 170));
    v67.m_quad = (__m128)ray->m_direction;
    v68.m_quad = _mm_shuffle_ps(v64, _mm_unpackhi_ps(v64, _mm_sub_ps((__m128)0i64, v66)), 196);
    v69 = _mm_mul_ps(v8.m_quad, v68.m_quad);
    v70 = _mm_shuffle_ps(v69, _mm_unpackhi_ps(v69, v68.m_quad), 196);
    v71 = _mm_add_ps(_mm_shuffle_ps(v70, v70, 78), v70);
    v72 = _mm_mul_ps(ray->m_direction.m_quad, v68.m_quad);
    v73 = _mm_sub_ps(_mm_add_ps(_mm_shuffle_ps(v71, v71, 177), v71), radius->m_real);
    v74 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v72, v72, 0)),
            _mm_shuffle_ps(v72, v72, 170));
    v75 = _mm_rcp_ps(v74);
    v76 = v74;
    v77 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v74, v75));
    v16 = v84;
    v78 = _mm_max_ps(
            aabbOut.m_quad,
            _mm_mul_ps(
              _mm_sub_ps((__m128)0i64, v73),
              _mm_andnot_ps(_mm_cmpeqps(v76, (__m128)0i64), _mm_mul_ps(v77, v75))));
    v75.m128_i32[0] = v10.m128_i32[0];
    v10 = _mm_min_ps(v10, v73);
    v13.m_real = _mm_add_ps(v13.m_real, v78);
    v75.m128_f32[0] = v75.m128_f32[0] - v73.m128_f32[0];
    v8.m_quad = _mm_add_ps(v8.m_quad, _mm_mul_ps(v78, v67.m_quad));
    v15 = v80;
    v14 = v85;
    v7 = vA->m_quad;
    v9 = vB->m_quad;
  }
  while ( v75.m128_f32[0] >= 0.00000011920929 );
  if ( v13.m_real.m128_f32[0] > COERCE_FLOAT(_mm_shuffle_ps(v67.m_quad, v67.m_quad, 255))
    || v10.m128_f32[0] >= COERCE_FLOAT(
                            _mm_shuffle_ps(
                              (__m128)LODWORD(FLOAT_0_000099999997),
                              (__m128)LODWORD(FLOAT_0_000099999997),
                              0)) )
  {
    return 0i64;
  }
  *fractionOut = (hkSimdFloat32)v13.m_real;
  if ( planeOut )
    *planeOut = (hkVector4f)v68.m_quad;
  return 1i64;
}


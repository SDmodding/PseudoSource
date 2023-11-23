// File Line: 28
// RVA: 0xC94AF0
_BOOL8 __fastcall hkcdLineTriangleIntersect(
        hkcdRay *ray,
        hkVector4f *vA,
        hkVector4f *vB,
        hkVector4f *vC,
        hkSimdFloat32 *tolerance,
        hkSimdFloat32 *fractionOut)
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
  v30 = _mm_or_ps(_mm_cmplt_ps(v28, _mm_sub_ps((__m128)0i64, tolerance->m_real)), _mm_cmplt_ps(tolerance->m_real, v28));
  return (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v27, (__m128)0i64), v30)) & 7) == 7
      || (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps((__m128)0i64, v27), v30)) & 7) == 7;
}

// File Line: 65
// RVA: 0xC94CF0
__int64 __fastcall hkcdSphereCastTriangle(
        hkcdRay *ray,
        hkSimdFloat32 *radius,
        hkVector4f *vA,
        hkVector4f *vB,
        hkVector4f *vC,
        hkSimdFloat32 *fractionOut,
        hkVector4f *planeOut)
{
  __m128 m_quad; // xmm4
  hkVector4f v8; // xmm8
  __m128 v9; // xmm10
  __m128 v10; // xmm12
  __m128 v11; // xmm14
  __m128 v12; // xmm15
  __m128 v13; // xmm13
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
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  __m128 v34; // xmm5
  __m128 v35; // xmm5
  __m128 v36; // xmm4
  __m128 v37; // xmm0
  __m128 v38; // xmm3
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  __m128 v41; // xmm5
  __m128 v42; // xmm3
  __m128 v43; // xmm0
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  __m128 v48; // xmm2
  __m128 v49; // xmm7
  __m128 v50; // xmm1
  __m128 v51; // xmm9
  __m128 v52; // xmm10
  __m128 v53; // xmm2
  __m128 v54; // xmm3
  __m128 v55; // xmm2
  __m128 v56; // xmm7
  __m128 v57; // xmm1
  __m128 v58; // xmm3
  __m128 v59; // xmm7
  __m128 v60; // xmm1
  __m128 v61; // xmm3
  __m128 v62; // xmm2
  __m128 v63; // xmm7
  __m128 v64; // xmm5
  __m128 v65; // xmm1
  hkVector4f v66; // xmm5
  __m128 v67; // xmm7
  __m128 v68; // xmm1
  __m128 v69; // xmm1
  __m128 v70; // xmm0
  __m128 v71; // xmm1
  __m128 v72; // xmm4
  __m128 v73; // xmm3
  __m128 v74; // xmm0
  __m128 v75; // xmm2
  __m128 v76; // xmm1
  __m128 v77; // xmm1
  __m128 v79; // [rsp+0h] [rbp-128h]
  __m128 v80; // [rsp+10h] [rbp-118h]
  __m128 v81; // [rsp+20h] [rbp-108h]
  __m128 v82; // [rsp+30h] [rbp-F8h]
  __m128 v83; // [rsp+40h] [rbp-E8h]
  __m128 v84; // [rsp+50h] [rbp-D8h]

  m_quad = vA->m_quad;
  v8.m_quad = (__m128)ray->m_origin;
  v9 = vB->m_quad;
  v10 = (__m128)xmmword_141A712A0;
  v80 = _mm_shuffle_ps(aabbOut.m_quad, _mm_unpackhi_ps(aabbOut.m_quad, (__m128)xmmword_141A712F0), 196);
  v11 = _mm_sub_ps(vB->m_quad, vA->m_quad);
  v12 = _mm_sub_ps(vC->m_quad, vB->m_quad);
  v13 = 0i64;
  v14 = _mm_shuffle_ps(v11, v11, 201);
  v82 = _mm_shuffle_ps(query.m_quad, _mm_unpackhi_ps(query.m_quad, (__m128)xmmword_141A712A0), 196);
  v15 = _mm_sub_ps(vA->m_quad, vC->m_quad);
  v16 = _mm_shuffle_ps(v12, v12, 201);
  v79 = v15;
  v83 = v16;
  v84 = v14;
  v17 = _mm_sub_ps(_mm_mul_ps(v11, v16), _mm_mul_ps(v12, v14));
  v18 = _mm_shuffle_ps(v17, v17, 201);
  v81 = _mm_shuffle_ps(v15, v15, 201);
  do
  {
    v19 = _mm_sub_ps(v8.m_quad, m_quad);
    v20 = _mm_sub_ps(v8.m_quad, v9);
    v21 = _mm_sub_ps(v8.m_quad, vC->m_quad);
    v22 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v11), _mm_mul_ps(v19, v14));
    v23 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v12), _mm_mul_ps(v20, v16));
    v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v15), _mm_mul_ps(v21, v81));
    v25 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v18);
    v26 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v18);
    v27 = _mm_unpackhi_ps(v25, v26);
    v28 = _mm_unpacklo_ps(v25, v26);
    v29 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v18);
    v30 = _mm_movelh_ps(v28, v29);
    if ( (_mm_movemask_ps(
            _mm_cmplt_ps(
              v80,
              _mm_add_ps(
                _mm_shuffle_ps(v27, v29, 228),
                _mm_add_ps(v30, _mm_shuffle_ps(_mm_movehl_ps(v30, v28), v29, 212))))) & 7) == 7 )
    {
      v31 = _mm_mul_ps(v18, v18);
      v32 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
              _mm_shuffle_ps(v31, v31, 170));
      v33 = _mm_mul_ps(v18, v19);
      v34 = _mm_sub_ps(
              v8.m_quad,
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpeq_ps(v32, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_rcp_ps(v32),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                      _mm_shuffle_ps(v33, v33, 170)))),
                v18));
    }
    else
    {
      v35 = _mm_mul_ps(v11, v11);
      v36 = _mm_mul_ps(v19, v11);
      v37 = _mm_mul_ps(v12, v12);
      v38 = _mm_mul_ps(v79, v79);
      v39 = _mm_unpacklo_ps(v35, v37);
      v40 = _mm_movelh_ps(v39, v38);
      v41 = _mm_add_ps(
              _mm_shuffle_ps(_mm_unpackhi_ps(v35, v37), v38, 228),
              _mm_add_ps(v40, _mm_shuffle_ps(_mm_movehl_ps(v40, v39), v38, 212)));
      v42 = _mm_mul_ps(v21, v79);
      v43 = _mm_mul_ps(v20, v12);
      v44 = _mm_unpacklo_ps(v36, v43);
      v45 = _mm_movelh_ps(v44, v42);
      v46 = _mm_andnot_ps(
              _mm_cmpeq_ps(v41, (__m128)0i64),
              _mm_mul_ps(
                _mm_rcp_ps(v41),
                _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v36, v43), v42, 228),
                  _mm_add_ps(v45, _mm_shuffle_ps(_mm_movehl_ps(v45, v44), v42, 212)))));
      v47 = _mm_cmplt_ps(v46, v82);
      v48 = _mm_max_ps(v80, _mm_or_ps(_mm_and_ps(v46, v47), _mm_andnot_ps(v47, v82)));
      v49 = _mm_sub_ps(v19, _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), v11));
      v50 = _mm_mul_ps(v49, v49);
      v51 = _mm_sub_ps(v20, _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), v12));
      v52 = _mm_sub_ps(v21, _mm_mul_ps(_mm_shuffle_ps(v48, v48, 170), v79));
      v53 = _mm_mul_ps(v51, v51);
      v54 = _mm_cmplt_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
                _mm_shuffle_ps(v50, v50, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)),
                _mm_shuffle_ps(v53, v53, 170)));
      v55 = _mm_mul_ps(v52, v52);
      v56 = _mm_or_ps(_mm_and_ps(v49, v54), _mm_andnot_ps(v54, v51));
      v57 = _mm_mul_ps(v56, v56);
      v58 = _mm_cmplt_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
                _mm_shuffle_ps(v57, v57, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                _mm_shuffle_ps(v55, v55, 170)));
      v34 = _mm_sub_ps(v8.m_quad, _mm_or_ps(_mm_and_ps(v56, v58), _mm_andnot_ps(v58, v52)));
    }
    v59 = _mm_sub_ps(v8.m_quad, v34);
    v60 = _mm_mul_ps(v59, v59);
    v61 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v60, v60, 85), _mm_shuffle_ps(v60, v60, 0)),
            _mm_shuffle_ps(v60, v60, 170));
    v62 = _mm_rsqrt_ps(v61);
    v63 = _mm_mul_ps(
            v59,
            _mm_andnot_ps(
              _mm_cmple_ps(v61, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v62, v61), v62)),
                _mm_mul_ps(*(__m128 *)_xmm, v62))));
    v64 = _mm_mul_ps(v34, v63);
    v65 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
            _mm_shuffle_ps(v64, v64, 170));
    v66.m_quad = (__m128)ray->m_direction;
    v67 = _mm_shuffle_ps(v63, _mm_unpackhi_ps(v63, _mm_sub_ps((__m128)0i64, v65)), 196);
    v68 = _mm_mul_ps(v8.m_quad, v67);
    v69 = _mm_shuffle_ps(v68, _mm_unpackhi_ps(v68, v67), 196);
    v70 = _mm_add_ps(_mm_shuffle_ps(v69, v69, 78), v69);
    v71 = _mm_mul_ps(v66.m_quad, v67);
    v72 = _mm_sub_ps(_mm_add_ps(_mm_shuffle_ps(v70, v70, 177), v70), radius->m_real);
    v73 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v71, v71, 85), _mm_shuffle_ps(v71, v71, 0)),
            _mm_shuffle_ps(v71, v71, 170));
    v74 = _mm_rcp_ps(v73);
    v75 = v73;
    v76 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v73, v74));
    v16 = v83;
    v77 = _mm_max_ps(
            aabbOut.m_quad,
            _mm_mul_ps(
              _mm_sub_ps((__m128)0i64, v72),
              _mm_andnot_ps(_mm_cmpeq_ps(v75, (__m128)0i64), _mm_mul_ps(v76, v74))));
    v74.m128_i32[0] = v10.m128_i32[0];
    v10 = _mm_min_ps(v10, v72);
    v13 = _mm_add_ps(v13, v77);
    v74.m128_f32[0] = v74.m128_f32[0] - v72.m128_f32[0];
    v8.m_quad = _mm_add_ps(v8.m_quad, _mm_mul_ps(v77, v66.m_quad));
    v15 = v79;
    v14 = v84;
    m_quad = vA->m_quad;
    v9 = vB->m_quad;
  }
  while ( v74.m128_f32[0] >= 0.00000011920929 );
  if ( v13.m128_f32[0] > _mm_shuffle_ps(v66.m_quad, v66.m_quad, 255).m128_f32[0]
    || v10.m128_f32[0] >= _mm_shuffle_ps(
                            (__m128)LODWORD(FLOAT_0_000099999997),
                            (__m128)LODWORD(FLOAT_0_000099999997),
                            0).m128_f32[0] )
  {
    return 0i64;
  }
  *fractionOut = (hkSimdFloat32)v13;
  if ( planeOut )
    *planeOut = (hkVector4f)v67;
  return 1i64;
}


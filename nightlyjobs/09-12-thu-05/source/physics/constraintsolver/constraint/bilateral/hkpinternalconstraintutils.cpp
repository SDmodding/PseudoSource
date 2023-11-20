// File Line: 15
// RVA: 0xD4E480
void __fastcall hkInternalConstraintUtils_calcRelativeAngle(hkVector4f *twistAxisAinWorld, hkVector4f *twistAxisBinWorld, hkVector4f *planeAxisAinWorld, hkVector4f *planeAxisBinWorld, hkVector4f *axisOut, hkPadSpu<float> *angleOut)
{
  __m128 v6; // xmm8
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm2
  __m128 v12; // xmm8
  __m128 v13; // xmm4
  __m128 v14; // xmm2
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm7
  __m128 v19; // xmm3
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm4
  __m128 v23; // xmm6
  __m128 v24; // xmm3
  __m128 v25; // xmm2
  __m128 v26; // xmm0
  __m128 v27; // xmm6

  v6 = _mm_add_ps(twistAxisAinWorld->m_quad, twistAxisBinWorld->m_quad);
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  v10 = _mm_andnot_ps(
          _mm_cmpleps(v8, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)), _mm_mul_ps(*(__m128 *)_xmm, v9)),
            v8));
  if ( v10.m128_f32[0] <= COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_1_0eN16), (__m128)LODWORD(FLOAT_1_0eN16), 0)) )
  {
    v12 = twistAxisBinWorld->m_quad;
  }
  else
  {
    v11 = _mm_rcp_ps(v10);
    v12 = _mm_mul_ps(v6, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11, v10)), v11));
  }
  v13 = _mm_shuffle_ps(v12, v12, 201);
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(planeAxisBinWorld->m_quad, planeAxisBinWorld->m_quad, 201), v12),
          _mm_mul_ps(planeAxisBinWorld->m_quad, v13));
  v15 = _mm_shuffle_ps(v14, v14, 201);
  v16 = _mm_mul_ps(planeAxisAinWorld->m_quad, v15);
  v17 = _mm_sub_ps(_mm_mul_ps(v13, v15), _mm_mul_ps(v15, v12));
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v19 = _mm_mul_ps(planeAxisAinWorld->m_quad, _mm_shuffle_ps(v17, v17, 201));
  v20 = _mm_rcp_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
            _mm_shuffle_ps(v19, v19, 170)));
  v21 = _mm_mul_ps(v20, v18);
  v22 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v21), _mm_cmpltps(*(__m128 *)_xmm, v21));
  v23 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v21), v22), _mm_andnot_ps(v22, v21));
  v24 = _mm_mul_ps(v23, v23);
  v25 = _mm_mul_ps(
          _mm_rcp_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_rcp_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_rcp_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v24, *(__m128 *)s0)), *(__m128 *)t0),
                          _mm_add_ps(v24, *(__m128 *)s1))),
                      *(__m128 *)t1),
                    _mm_add_ps(v24, *(__m128 *)s2))),
                *(__m128 *)t2),
              _mm_add_ps(v24, *(__m128 *)s3))),
          _mm_mul_ps(v23, *(__m128 *)t3));
  v26 = _mm_cmpleps((__m128)0i64, v20);
  v27 = _mm_or_ps(
          _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v23, *(__m128 *)_xmm), *(__m128 *)_xmm), v25), v22),
          _mm_andnot_ps(v22, v25));
  LODWORD(angleOut->m_storage) = *(unsigned __int128 *)&_mm_andnot_ps(
                                                          v26,
                                                          _mm_add_ps(
                                                            _mm_or_ps(_mm_and_ps(v18, *(__m128 *)_xmm), *(__m128 *)_xmm),
                                                            v27)) | v27.m128_i32[0] & v26.m128_i32[0];
  *axisOut = (hkVector4f)v12;
}


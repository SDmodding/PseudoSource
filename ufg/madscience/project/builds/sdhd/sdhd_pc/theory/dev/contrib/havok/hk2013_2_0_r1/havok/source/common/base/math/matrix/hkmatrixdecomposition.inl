// File Line: 26
// RVA: 0xB72D0
void __fastcall hkMatrixDecompositionImpl<float>::decomposeMatrix(
        hkMatrix4f *matrixIn,
        hkMatrixDecompositionImpl<float>::Decomposition *decompOut)
{
  int v3; // ebx
  hkVector4f v4; // xmm11
  hkVector4f v5; // xmm12
  hkVector4f v6; // xmm13
  hkVector4f v7; // xmm1
  hkVector4f v8; // xmm2
  hkVector4f v9; // xmm14
  hkVector4f v10; // xmm0
  __m128 m_quad; // xmm3
  hkVector4f v12; // xmm1
  __m128 v13; // xmm2
  hkVector4f v14; // xmm6
  hkVector4f v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm7
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm6
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  __m128 v25; // xmm2
  __m128 v26; // xmm2
  __m128 v27; // xmm2
  __m128i v28; // xmm1
  hkQuaternionf v29; // xmm3
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm6
  __m128 v35; // xmm4
  __m128 v36; // xmm7
  __m128 v37; // xmm5
  __m128 v38; // xmm2
  hkVector4f v39; // xmm0
  hkVector4f v40; // xmm1
  hkVector4f v41; // xmm0
  __m128 v42; // xmm1
  hkVector4f v43; // xmm1
  __m128 v44; // xmm2
  hkVector4f v45; // xmm11
  hkVector4f v46; // xmm13
  hkVector4f v47; // xmm15
  __m128 v48; // xmm14
  hkVector4f v49; // xmm2
  __m128 v50; // xmm14
  __m128 v51; // xmm8
  __m128 v52; // xmm0
  __m128 v53; // xmm14
  __m128 v54; // xmm1
  hkVector4f v55; // xmm3
  __m128 v56; // xmm2
  __m128 v57; // xmm3
  hkVector4f v58; // xmm1
  hkVector4f v59; // xmm2
  hkVector4f v60; // xmm0
  hkVector4f v61; // xmm3
  hkSimdFloat32 scale; // [rsp+20h] [rbp-D8h] BYREF
  hkMatrix3f v63; // [rsp+30h] [rbp-C8h] BYREF
  char v64[56]; // [rsp+60h] [rbp-98h] BYREF
  hkMatrix3f m; // [rsp+98h] [rbp-60h] BYREF
  hkTransformf a; // [rsp+C8h] [rbp-30h] BYREF
  __m128 v67; // [rsp+108h] [rbp+10h]
  __m128 v68; // [rsp+118h] [rbp+20h]
  __m128 v69; // [rsp+128h] [rbp+30h]
  void *retaddr; // [rsp+1E8h] [rbp+F0h] BYREF

  v3 = 0;
  v4.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)matrixIn->m_col0.m_quad, 4), 4);
  v5.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)matrixIn->m_col1.m_quad, 4), 4);
  v6.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)matrixIn->m_col2.m_quad, 4), 4);
  v7.m_quad = v5.m_quad;
  v8.m_quad = v6.m_quad;
  v9.m_quad = _mm_shuffle_ps(matrixIn->m_col3.m_quad, _mm_unpackhi_ps(matrixIn->m_col3.m_quad, query.m_quad), 196);
  v10.m_quad = v4.m_quad;
  v63.m_col1 = (hkVector4f)v5.m_quad;
  v63.m_col2 = (hkVector4f)v6.m_quad;
  decompOut->m_translation = (hkVector4f)v9.m_quad;
  for ( v63.m_col0 = (hkVector4f)v4.m_quad; ; v10.m_quad = (__m128)v63.m_col0 )
  {
    m.m_col2 = (hkVector4f)v8.m_quad;
    a.m_rotation.m_col2 = (hkVector4f)v8.m_quad;
    m.m_col0 = (hkVector4f)v10.m_quad;
    m.m_col1 = (hkVector4f)v7.m_quad;
    a.m_rotation.m_col0 = (hkVector4f)v10.m_quad;
    a.m_rotation.m_col1 = (hkVector4f)v7.m_quad;
    hkMatrix3f::invert(&a.m_rotation, (hkResult *)&retaddr, 0.00000011920929);
    hkMatrix3f::transpose(&a.m_rotation);
    *(hkVector4f *)v64 = m.m_col0;
    *(_QWORD *)&v64[16] = m.m_col1.m_quad.m128_u64[0];
    *(hkVector4f *)&v64[24] = m.m_col2;
    hkMatrix3f::add((hkMatrix3f *)v64, &a.m_rotation);
    scale.m_real = (__m128)xmmword_141A711B0;
    hkMatrix3f::setMul(&v63, &scale, (hkMatrix3f *)v64);
    if ( ++v3 >= 30 || hkMatrix3f::isApproximatelyEqual(&v63, &m, 0.00000011920929) )
      break;
    v8.m_quad = (__m128)v63.m_col2;
    v7.m_quad = (__m128)v63.m_col1;
  }
  m_quad = v63.m_col0.m_quad;
  v12.m_quad = (__m128)v63.m_col2;
  decompOut->m_basis.m_col1 = v63.m_col1;
  decompOut->m_basis.m_col2 = (hkVector4f)v12.m_quad;
  decompOut->m_basis.m_col0.m_quad = m_quad;
  v13 = _mm_mul_ps(m_quad, m_quad);
  v14.m_quad = (__m128)decompOut->m_basis.m_col1;
  v15.m_quad = (__m128)decompOut->m_basis.m_col2;
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v17 = _mm_rsqrt_ps(v16);
  v18 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v16, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
              _mm_mul_ps(*(__m128 *)_xmm, v17))),
          m_quad);
  v19 = _mm_mul_ps(v14.m_quad, v14.m_quad);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  v22 = _mm_mul_ps(
          v14.m_quad,
          _mm_andnot_ps(
            _mm_cmple_ps(v20, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
              _mm_mul_ps(*(__m128 *)_xmm, v21))));
  v23 = _mm_mul_ps(v15.m_quad, v15.m_quad);
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)), _mm_shuffle_ps(v23, v23, 170));
  v25 = _mm_rsqrt_ps(v24);
  *(_QWORD *)&v64[16] = v22.m128_u64[0];
  *(__m128 *)&v64[24] = _mm_mul_ps(
                          v15.m_quad,
                          _mm_andnot_ps(
                            _mm_cmple_ps(v24, (__m128)0i64),
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v25, v24), v25)),
                              _mm_mul_ps(*(__m128 *)_xmm, v25))));
  v26 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v64[24], *(__m128 *)&v64[24], 201), v22),
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), *(__m128 *)&v64[24]));
  v27 = _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v18);
  v28 = (__m128i)_mm_cmplt_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                     _mm_shuffle_ps(v27, v27, 170)),
                   (__m128)0i64);
  decompOut->m_flips.m_bool = _mm_movemask_ps((__m128)v28) != 0;
  *(__m128 *)v64 = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v28, 0x1Fu), 0x1Fu), v18);
  hkQuaternionf::set(&decompOut->m_rotation, (hkRotationf *)v64);
  v29.m_vec.m_quad = (__m128)decompOut->m_rotation;
  v30 = _mm_mul_ps(v29.m_vec.m_quad, v29.m_vec.m_quad);
  v31 = _mm_add_ps(_mm_shuffle_ps(v30, v30, 78), v30);
  v32 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 177), v31);
  v33 = _mm_rsqrt_ps(v32);
  decompOut->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                         _mm_mul_ps(
                                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v33, v32), v33)),
                                           _mm_mul_ps(*(__m128 *)_xmm, v33)),
                                         v29.m_vec.m_quad);
  hkRotationf::set(&a.m_rotation, &decompOut->m_rotation);
  a.m_translation = decompOut->m_translation;
  hkTransformf::setInverse((hkTransformf *)v64, &a);
  v34 = (__m128)_mm_srli_si128(_mm_slli_si128(*(__m128i *)v64, 4), 4);
  v35 = (__m128)_mm_srli_si128(_mm_slli_si128(*(__m128i *)&v64[16], 4), 4);
  v36 = (__m128)_mm_srli_si128(_mm_slli_si128(*(__m128i *)&v64[24], 4), 4);
  v37 = _mm_shuffle_ps(*(__m128 *)&v64[40], _mm_unpackhi_ps(*(__m128 *)&v64[40], query.m_quad), 196);
  decompOut->m_scaleAndSkew.m_col0.m_quad = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 85), v35),
                                                  _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 0), v34)),
                                                _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 170), v36)),
                                              _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 255), v37));
  decompOut->m_scaleAndSkew.m_col1.m_quad = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 85), v35),
                                                  _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 0), v34)),
                                                _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 170), v36)),
                                              _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 255), v37));
  decompOut->m_scaleAndSkew.m_col2.m_quad = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 85), v35),
                                                  _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 0), v34)),
                                                _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 170), v36)),
                                              _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 255), v37));
  *(float *)&retaddr = FLOAT_0_001;
  v38 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
  v67 = v38;
  decompOut->m_scaleAndSkew.m_col3.m_quad = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 85), v35),
                                                  _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 0), v34)),
                                                _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 170), v36)),
                                              _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 255), v37));
  decompOut->m_scale = 0i64;
  v39.m_quad = _mm_add_ps(_mm_mul_ps(decompOut->m_scaleAndSkew.m_col0.m_quad, transform.m_quad), (__m128)0i64);
  decompOut->m_scale = (hkVector4f)v39.m_quad;
  v40.m_quad = _mm_add_ps(_mm_mul_ps(decompOut->m_scaleAndSkew.m_col1.m_quad, direction.m_quad), v39.m_quad);
  decompOut->m_scale = (hkVector4f)v40.m_quad;
  v41.m_quad = _mm_add_ps(_mm_mul_ps(decompOut->m_scaleAndSkew.m_col2.m_quad, stru_141A71280.m_quad), v40.m_quad);
  decompOut->m_scale = (hkVector4f)v41.m_quad;
  v42 = _mm_add_ps(_mm_mul_ps(decompOut->m_scaleAndSkew.m_col3.m_quad, qi.m_vec.m_quad), v41.m_quad);
  v43.m_quad = _mm_shuffle_ps(v42, _mm_unpackhi_ps(v42, query.m_quad), 196);
  decompOut->m_scale = (hkVector4f)v43.m_quad;
  decompOut->m_hasScale.m_bool = _mm_movemask_ps(
                                   _mm_cmplt_ps(
                                     (__m128)_mm_srli_epi32(
                                               _mm_slli_epi32((__m128i)_mm_sub_ps(v43.m_quad, query.m_quad), 1u),
                                               1u),
                                     v38)) != 15;
  v44 = _mm_rcp_ps(decompOut->m_scale.m_quad);
  v45.m_quad = (__m128)decompOut->m_scaleAndSkew.m_col1;
  v46.m_quad = (__m128)decompOut->m_scaleAndSkew.m_col2;
  v47.m_quad = (__m128)decompOut->m_scaleAndSkew.m_col3;
  v48 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v44, decompOut->m_scale.m_quad)), v44);
  v49.m_quad = (__m128)decompOut->m_scaleAndSkew.m_col0;
  v69 = _mm_shuffle_ps(v45.m_quad, v45.m_quad, 0);
  v68 = _mm_shuffle_ps(v46.m_quad, v46.m_quad, 0);
  v50 = _mm_shuffle_ps(v48, _mm_unpackhi_ps(v48, query.m_quad), 196);
  v51 = _mm_mul_ps(v50, stru_141A71280.m_quad);
  scale.m_real = _mm_mul_ps(v50, transform.m_quad);
  v52 = _mm_mul_ps(v50, direction.m_quad);
  v53 = _mm_mul_ps(v50, qi.m_vec.m_quad);
  v54 = v69;
  v55.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v49.m_quad, v49.m_quad, 85), v52),
                     _mm_mul_ps(_mm_shuffle_ps(v49.m_quad, v49.m_quad, 0), scale.m_real)),
                   _mm_mul_ps(_mm_shuffle_ps(v49.m_quad, v49.m_quad, 170), v51)),
                 _mm_mul_ps(_mm_shuffle_ps(v49.m_quad, v49.m_quad, 255), v53));
  v56 = v68;
  decompOut->m_skew.m_col0 = (hkVector4f)v55.m_quad;
  v57 = _mm_add_ps(
          _mm_mul_ps(scale.m_real, _mm_shuffle_ps(v47.m_quad, v47.m_quad, 0)),
          _mm_mul_ps(_mm_shuffle_ps(v47.m_quad, v47.m_quad, 85), v52));
  v58.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(v54, scale.m_real),
                     _mm_mul_ps(_mm_shuffle_ps(v45.m_quad, v45.m_quad, 85), v52)),
                   _mm_mul_ps(_mm_shuffle_ps(v45.m_quad, v45.m_quad, 170), v51)),
                 _mm_mul_ps(_mm_shuffle_ps(v45.m_quad, v45.m_quad, 255), v53));
  v59.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(v56, scale.m_real),
                     _mm_mul_ps(_mm_shuffle_ps(v46.m_quad, v46.m_quad, 85), v52)),
                   _mm_mul_ps(_mm_shuffle_ps(v46.m_quad, v46.m_quad, 170), v51)),
                 _mm_mul_ps(_mm_shuffle_ps(v46.m_quad, v46.m_quad, 255), v53));
  decompOut->m_skew.m_col1 = (hkVector4f)v58.m_quad;
  decompOut->m_skew.m_col2 = (hkVector4f)v59.m_quad;
  v60.m_quad = (__m128)decompOut->m_skew.m_col0;
  v61.m_quad = _mm_add_ps(
                 _mm_add_ps(v57, _mm_mul_ps(_mm_shuffle_ps(v47.m_quad, v47.m_quad, 170), v51)),
                 _mm_mul_ps(_mm_shuffle_ps(v47.m_quad, v47.m_quad, 255), v53));
  decompOut->m_skew.m_col3 = (hkVector4f)v61.m_quad;
  decompOut->m_hasSkew.m_bool = _mm_movemask_ps(
                                  _mm_cmple_ps(
                                    _mm_max_ps(
                                      _mm_max_ps(
                                        (__m128)_mm_srli_epi32(
                                                  _mm_slli_epi32((__m128i)_mm_sub_ps(v60.m_quad, transform.m_quad), 1u),
                                                  1u),
                                        (__m128)_mm_srli_epi32(
                                                  _mm_slli_epi32((__m128i)_mm_sub_ps(v58.m_quad, direction.m_quad), 1u),
                                                  1u)),
                                      _mm_max_ps(
                                        (__m128)_mm_srli_epi32(
                                                  _mm_slli_epi32(
                                                    (__m128i)_mm_sub_ps(v59.m_quad, stru_141A71280.m_quad),
                                                    1u),
                                                  1u),
                                        (__m128)_mm_srli_epi32(
                                                  _mm_slli_epi32((__m128i)_mm_sub_ps(v61.m_quad, qi.m_vec.m_quad), 1u),
                                                  1u))),
                                    v67)) != 15;
}


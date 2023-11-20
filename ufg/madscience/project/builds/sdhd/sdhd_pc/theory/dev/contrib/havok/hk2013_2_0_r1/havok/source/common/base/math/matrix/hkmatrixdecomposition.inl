// File Line: 26
// RVA: 0xB72D0
void __fastcall hkMatrixDecompositionImpl<float>::decomposeMatrix(hkMatrix4f *matrixIn, hkMatrixDecompositionImpl<float>::Decomposition *decompOut)
{
  hkMatrixDecompositionImpl<float>::Decomposition *v2; // rdi
  int v3; // ebx
  hkVector4f v4; // xmm11
  hkVector4f v5; // xmm12
  hkVector4f v6; // xmm13
  hkVector4f v7; // xmm1
  hkVector4f v8; // xmm2
  hkVector4f v9; // xmm14
  hkVector4f v10; // xmm0
  hkVector4f v11; // xmm3
  hkVector4f v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm7
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  hkVector4f v22; // xmm6
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  __m128 v25; // xmm2
  __m128 v26; // xmm2
  __m128 v27; // xmm2
  __m128i v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm6
  __m128 v35; // xmm4
  __m128 v36; // xmm7
  __m128 v37; // xmm5
  __m128 v38; // xmm2
  __m128 v39; // xmm0
  __m128 v40; // xmm1
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm11
  __m128 v46; // xmm13
  __m128 v47; // xmm15
  __m128 v48; // xmm14
  __m128 v49; // xmm5
  __m128 v50; // xmm2
  __m128 v51; // xmm12
  __m128 v52; // xmm14
  __m128 v53; // xmm8
  __m128 v54; // xmm0
  __m128 v55; // xmm14
  __m128 v56; // xmm1
  __m128 v57; // xmm3
  __m128 v58; // xmm2
  __m128 v59; // xmm3
  __m128 v60; // xmm1
  __m128 v61; // xmm2
  __m128 v62; // xmm0
  __m128 v63; // xmm3
  hkSimdFloat32 scale; // [rsp+20h] [rbp-D8h]
  hkMatrix3f v65; // [rsp+30h] [rbp-C8h]
  hkMatrix3f v66; // [rsp+60h] [rbp-98h]
  hkMatrix3f m; // [rsp+98h] [rbp-60h]
  hkMatrix3f a; // [rsp+C8h] [rbp-30h]
  hkVector4f v69; // [rsp+F8h] [rbp+0h]
  __m128 v70; // [rsp+108h] [rbp+10h]
  __m128 v71; // [rsp+118h] [rbp+20h]
  __m128 v72; // [rsp+128h] [rbp+30h]
  void *retaddr; // [rsp+1E8h] [rbp+F0h]

  v2 = decompOut;
  v3 = 0;
  v4.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)matrixIn->m_col0.m_quad, 4), 4);
  v5.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)matrixIn->m_col1.m_quad, 4), 4);
  v6.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)matrixIn->m_col2.m_quad, 4), 4);
  v7.m_quad = v5.m_quad;
  v8.m_quad = v6.m_quad;
  v9.m_quad = _mm_shuffle_ps(matrixIn->m_col3.m_quad, _mm_unpackhi_ps(matrixIn->m_col3.m_quad, query.m_quad), 196);
  v10.m_quad = v4.m_quad;
  v65.m_col1 = (hkVector4f)v5.m_quad;
  v65.m_col2 = (hkVector4f)v6.m_quad;
  decompOut->m_translation = (hkVector4f)v9.m_quad;
  v65.m_col0 = (hkVector4f)v4.m_quad;
  while ( 1 )
  {
    m.m_col2 = (hkVector4f)v8.m_quad;
    a.m_col2 = (hkVector4f)v8.m_quad;
    m.m_col0 = (hkVector4f)v10.m_quad;
    m.m_col1 = (hkVector4f)v7.m_quad;
    a.m_col0 = (hkVector4f)v10.m_quad;
    a.m_col1 = (hkVector4f)v7.m_quad;
    hkMatrix3f::invert(&a, (hkResult *)&retaddr, 0.00000011920929);
    hkMatrix3f::transpose(&a);
    v66.m_col0 = m.m_col0;
    v66.m_col1 = m.m_col1;
    *(hkVector4f *)((char *)&v66.m_col1 + 8) = m.m_col2;
    hkMatrix3f::add(&v66, &a);
    scale.m_real = (__m128)xmmword_141A711B0;
    hkMatrix3f::setMul(&v65, &scale, &v66);
    if ( ++v3 >= 30 || hkMatrix3f::isApproximatelyEqual(&v65, &m, 0.00000011920929) )
      break;
    v8.m_quad = (__m128)v65.m_col2;
    v7.m_quad = (__m128)v65.m_col1;
    v10.m_quad = (__m128)v65.m_col0;
  }
  v11.m_quad = (__m128)v65.m_col0;
  v12.m_quad = (__m128)v65.m_col2;
  v2->m_basis.m_col1 = v65.m_col1;
  v2->m_basis.m_col2 = (hkVector4f)v12.m_quad;
  v2->m_basis.m_col0 = (hkVector4f)v11.m_quad;
  v13 = _mm_mul_ps(v11.m_quad, v11.m_quad);
  v14 = v2->m_basis.m_col1.m_quad;
  v15 = v2->m_basis.m_col2.m_quad;
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v17 = _mm_rsqrt_ps(v16);
  v18 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v16, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
              _mm_mul_ps(*(__m128 *)_xmm, v17))),
          v11.m_quad);
  v19 = _mm_mul_ps(v14, v14);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  v22.m_quad = _mm_mul_ps(
                 v14,
                 _mm_andnot_ps(
                   _mm_cmpleps(v20, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                     _mm_mul_ps(*(__m128 *)_xmm, v21))));
  v23 = _mm_mul_ps(v15, v15);
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)), _mm_shuffle_ps(v23, v23, 170));
  v25 = _mm_rsqrt_ps(v24);
  v66.m_col1 = (hkVector4f)v22.m_quad;
  *(__m128 *)((char *)&v66.m_col1.m_quad + 8) = _mm_mul_ps(
                                                  v15,
                                                  _mm_andnot_ps(
                                                    _mm_cmpleps(v24, (__m128)0i64),
                                                    _mm_mul_ps(
                                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v25, v24), v25)),
                                                      _mm_mul_ps(*(__m128 *)_xmm, v25))));
  v26 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(
              *(__m128 *)((char *)&v66.m_col1.m_quad + 8),
              *(__m128 *)((char *)&v66.m_col1.m_quad + 8),
              201),
            v22.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v22.m_quad, v22.m_quad, 201), *(__m128 *)((char *)&v66.m_col1.m_quad + 8)));
  v27 = _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v18);
  v28 = (__m128i)_mm_cmpltps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                     _mm_shuffle_ps(v27, v27, 170)),
                   (__m128)0i64);
  v2->m_flips.m_bool = _mm_movemask_ps((__m128)v28) != 0;
  v66.m_col0.m_quad = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v28, 0x1Fu), 0x1Fu), v18);
  hkQuaternionf::set(&v2->m_rotation, (hkRotationf *)&v66);
  v29 = v2->m_rotation.m_vec.m_quad;
  v30 = _mm_mul_ps(v29, v29);
  v31 = _mm_add_ps(_mm_shuffle_ps(v30, v30, 78), v30);
  v32 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 177), v31);
  v33 = _mm_rsqrt_ps(v32);
  v2->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                  _mm_mul_ps(
                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v33, v32), v33)),
                                    _mm_mul_ps(*(__m128 *)_xmm, v33)),
                                  v29);
  hkRotationf::set((hkRotationf *)&a, &v2->m_rotation);
  v69.m_quad = (__m128)v2->m_translation;
  hkTransformf::setInverse((hkTransformf *)&v66, (hkTransformf *)&a);
  v34 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)v66.m_col0.m_quad, 4), 4);
  v35 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)v66.m_col1.m_quad, 4), 4);
  v36 = (__m128)_mm_srli_si128(_mm_slli_si128(*(__m128i *)((char *)&v66.m_col1 + 8), 4), 4);
  v37 = _mm_shuffle_ps(
          *(__m128 *)((char *)&v66.m_col2.m_quad + 8),
          _mm_unpackhi_ps(*(__m128 *)((char *)&v66.m_col2.m_quad + 8), query.m_quad),
          196);
  v2->m_scaleAndSkew.m_col0.m_quad = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 85), v35),
                                           _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 0), v34)),
                                         _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 170), v36)),
                                       _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 255), v37));
  v2->m_scaleAndSkew.m_col1.m_quad = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 85), v35),
                                           _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 0), v34)),
                                         _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 170), v36)),
                                       _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 255), v37));
  v2->m_scaleAndSkew.m_col2.m_quad = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 85), v35),
                                           _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 0), v34)),
                                         _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 170), v36)),
                                       _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 255), v37));
  *(float *)&retaddr = FLOAT_0_001;
  v38 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
  v70 = v38;
  v2->m_scaleAndSkew.m_col3.m_quad = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 85), v35),
                                           _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 0), v34)),
                                         _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 170), v36)),
                                       _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 255), v37));
  v2->m_scale = 0i64;
  v39 = _mm_add_ps(_mm_mul_ps(v2->m_scaleAndSkew.m_col0.m_quad, transform.m_quad), (__m128)0i64);
  v2->m_scale.m_quad = v39;
  v40 = _mm_add_ps(_mm_mul_ps(v2->m_scaleAndSkew.m_col1.m_quad, direction.m_quad), v39);
  v2->m_scale.m_quad = v40;
  v41 = _mm_add_ps(_mm_mul_ps(v2->m_scaleAndSkew.m_col2.m_quad, stru_141A71280.m_quad), v40);
  v2->m_scale.m_quad = v41;
  v42 = _mm_add_ps(_mm_mul_ps(v2->m_scaleAndSkew.m_col3.m_quad, qi.m_vec.m_quad), v41);
  v43 = _mm_shuffle_ps(v42, _mm_unpackhi_ps(v42, query.m_quad), 196);
  v2->m_scale.m_quad = v43;
  v2->m_hasScale.m_bool = _mm_movemask_ps(
                            _mm_cmpltps(
                              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v43, query.m_quad), 1u), 1u),
                              v38)) != 15;
  v44 = _mm_rcp_ps(v2->m_scale.m_quad);
  v45 = v2->m_scaleAndSkew.m_col1.m_quad;
  v46 = v2->m_scaleAndSkew.m_col2.m_quad;
  v47 = v2->m_scaleAndSkew.m_col3.m_quad;
  v48 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v44, v2->m_scale.m_quad)), v44);
  v49 = _mm_shuffle_ps(v2->m_scaleAndSkew.m_col2.m_quad, v46, 170);
  v50 = v2->m_scaleAndSkew.m_col0.m_quad;
  v51 = v2->m_scaleAndSkew.m_col3.m_quad;
  v72 = _mm_shuffle_ps(v2->m_scaleAndSkew.m_col1.m_quad, v45, 0);
  v71 = _mm_shuffle_ps(v46, v46, 0);
  v52 = _mm_shuffle_ps(v48, _mm_unpackhi_ps(v48, query.m_quad), 196);
  v53 = _mm_mul_ps(v52, stru_141A71280.m_quad);
  scale.m_real = _mm_mul_ps(v52, transform.m_quad);
  v54 = _mm_mul_ps(v52, direction.m_quad);
  v55 = _mm_mul_ps(v52, qi.m_vec.m_quad);
  v56 = v72;
  v57 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v50, v50, 85), v54),
              _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), scale.m_real)),
            _mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), v53)),
          _mm_mul_ps(_mm_shuffle_ps(v50, v50, 255), v55));
  v58 = v71;
  v2->m_skew.m_col0.m_quad = v57;
  v59 = _mm_add_ps(_mm_mul_ps(scale.m_real, _mm_shuffle_ps(v51, v47, 0)), _mm_mul_ps(_mm_shuffle_ps(v47, v47, 85), v54));
  v60 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(v56, scale.m_real), _mm_mul_ps(_mm_shuffle_ps(v45, v45, 85), v54)),
            _mm_mul_ps(_mm_shuffle_ps(v45, v45, 170), v53)),
          _mm_mul_ps(_mm_shuffle_ps(v45, v45, 255), v55));
  v61 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(v58, scale.m_real), _mm_mul_ps(_mm_shuffle_ps(v46, v46, 85), v54)),
            _mm_mul_ps(v49, v53)),
          _mm_mul_ps(_mm_shuffle_ps(v46, v46, 255), v55));
  v2->m_skew.m_col1.m_quad = v60;
  v2->m_skew.m_col2.m_quad = v61;
  v62 = v2->m_skew.m_col0.m_quad;
  v63 = _mm_add_ps(
          _mm_add_ps(v59, _mm_mul_ps(_mm_shuffle_ps(v47, v47, 170), v53)),
          _mm_mul_ps(_mm_shuffle_ps(v47, v47, 255), v55));
  v2->m_skew.m_col3.m_quad = v63;
  v2->m_hasSkew.m_bool = _mm_movemask_ps(
                           _mm_cmpleps(
                             _mm_max_ps(
                               _mm_max_ps(
                                 (__m128)_mm_srli_epi32(
                                           _mm_slli_epi32((__m128i)_mm_sub_ps(v62, transform.m_quad), 1u),
                                           1u),
                                 (__m128)_mm_srli_epi32(
                                           _mm_slli_epi32((__m128i)_mm_sub_ps(v60, direction.m_quad), 1u),
                                           1u)),
                               _mm_max_ps(
                                 (__m128)_mm_srli_epi32(
                                           _mm_slli_epi32((__m128i)_mm_sub_ps(v61, stru_141A71280.m_quad), 1u),
                                           1u),
                                 (__m128)_mm_srli_epi32(
                                           _mm_slli_epi32((__m128i)_mm_sub_ps(v63, qi.m_vec.m_quad), 1u),
                                           1u))),
                             v70)) != 15;
}


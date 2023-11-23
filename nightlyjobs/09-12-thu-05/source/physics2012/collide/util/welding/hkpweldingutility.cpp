// File Line: 21
// RVA: 0x131DD00
void __fastcall hkpWeldingUtility::initWeldingTable(float edgeNormalSnapDeltaAngle, float triangleNormalSnapDeltaAngle)
{
  __m128 v2; // xmm2
  __m128 v3; // xmm3
  float *p_m_sinAccept0; // rax
  int v5; // ecx
  __m128i si128; // xmm10
  __m128 v7; // xmm12
  float v9; // xmm5_4
  float v10; // xmm1_4
  __m128i v11; // xmm8
  float v12; // xmm9_4
  float v13; // xmm12_4
  float v14; // xmm9_4
  __m128 v15; // xmm7
  __m128 v16; // xmm2
  __m128i v17; // xmm6
  __m128 v18; // xmm5
  __m128 v19; // xmm4
  __m128 v20; // xmm4
  __m128 v21; // xmm2
  unsigned int v22; // xmm0_4
  __m128 v23; // xmm7
  __m128 v24; // xmm2
  __m128i v25; // xmm6
  __m128 v26; // xmm5
  __m128 v27; // xmm4
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  unsigned int v30; // xmm0_4
  __m128 v31; // xmm7
  __m128 v32; // xmm2
  __m128i v33; // xmm6
  __m128 v34; // xmm5
  __m128 v35; // xmm4
  __m128 v36; // xmm4
  __m128 v37; // xmm2
  unsigned int v38; // xmm3_4
  __m128 v39; // xmm2
  __m128i v40; // xmm6
  __m128 v41; // xmm5
  __m128 v42; // xmm4
  __m128 v43; // xmm4
  __m128 v44; // xmm2
  __m128 v45; // xmm7
  __m128 v46; // xmm2
  __m128i v47; // xmm6
  __m128 v48; // xmm5
  __m128 v49; // xmm4
  __m128 v50; // xmm4
  __m128 v51; // xmm2
  unsigned int v52; // xmm3_4
  __m128 v53; // xmm2
  __m128i v54; // xmm6
  __m128 v55; // xmm5
  __m128 v56; // xmm0
  __m128 v57; // xmm4
  __m128 v58; // xmm2
  float v59; // xmm9_4
  __m128 v60; // xmm7
  __m128 v61; // xmm2
  __m128i v62; // xmm6
  __m128 v63; // xmm5
  __m128 v64; // xmm4
  __m128 v65; // xmm4
  __m128 v66; // xmm2
  __m128 v67; // xmm7
  __m128 v68; // xmm2
  __m128i v69; // xmm6
  __m128 v70; // xmm5
  __m128 v71; // xmm4
  __m128 v72; // xmm4
  __m128 v73; // xmm2
  void *retaddr; // [rsp+D0h] [rbp+67h]
  float v76; // [rsp+E0h] [rbp+77h]
  float v77; // [rsp+E0h] [rbp+77h]
  float v78; // [rsp+E0h] [rbp+77h]

  v2 = *(__m128 *)_xmm;
  v3 = *(__m128 *)DP3;
  p_m_sinAccept0 = &hkpWeldingUtility::m_sinCosTable[0].m_sinAccept0;
  v5 = 0;
  si128 = _mm_load_si128((const __m128i *)_xmm);
  v7 = *(__m128 *)DP2;
  v9 = edgeNormalSnapDeltaAngle;
  v10 = FLOAT_3_1415927;
  v11 = _mm_add_epi32(si128, si128);
  do
  {
    v12 = (float)((float)v5 * 0.20943952) - v10;
    if ( v12 >= 0.0 )
    {
      v45 = _mm_add_ps((__m128)LODWORD(v12), v2);
      v46 = _mm_andnot_ps(*(__m128 *)_xmm, v45);
      v47 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v46, *(__m128 *)_xmm)), si128));
      v48 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v47, v11), (__m128i)0i64);
      v49 = _mm_cvtepi32_ps(v47);
      v50 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v49, *(__m128 *)DP1_0), v46), _mm_mul_ps(v49, v7)),
              _mm_mul_ps(v49, v3));
      v51 = _mm_mul_ps(v50, v50);
      v52 = (_mm_andnot_ps(
               v48,
               _mm_add_ps(
                 _mm_sub_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v51, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v51),
                         *(__m128 *)cosCoeff2_0),
                       v51),
                     v51),
                   _mm_mul_ps(v51, *(__m128 *)_xmm)),
                 *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                   (float)((float)((float)((float)((float)((float)(v51.m128_f32[0]
                                                                                                 * -0.00019515296)
                                                                                         + 0.0083321612)
                                                                                 * v51.m128_f32[0])
                                                                         + -0.16666655)
                                                                 * v51.m128_f32[0])
                                                         * v50.m128_f32[0])
                                                 + v50.m128_f32[0]) & v48.m128_i32[0]) ^ (_mm_and_si128(
                                                                                            _mm_add_epi32(v11, v11),
                                                                                            v47).m128i_u32[0] << 29) ^ v45.m128_i32[0] & _xmm[0];
      v53 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(v12));
      *((_DWORD *)p_m_sinAccept0 - 1) = v52;
      v54 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v53, *(__m128 *)_xmm)), si128));
      v55 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v54, v11), (__m128i)0i64);
      v56 = _mm_cvtepi32_ps(v54);
      v57 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v56, *(__m128 *)DP1_0), v53), _mm_mul_ps(v56, v7)),
              _mm_mul_ps(v56, *(__m128 *)DP3));
      v58 = _mm_mul_ps(v57, v57);
      v59 = v12 + *(float *)&retaddr;
      v60 = _mm_add_ps((__m128)COERCE_UNSIGNED_INT(fminf(v59, 3.1415927)), *(__m128 *)_xmm);
      *(_DWORD *)p_m_sinAccept0 = (_mm_andnot_ps(
                                     v55,
                                     _mm_add_ps(
                                       _mm_sub_ps(
                                         _mm_mul_ps(
                                           _mm_mul_ps(
                                             _mm_add_ps(
                                               _mm_mul_ps(
                                                 _mm_add_ps(
                                                   _mm_mul_ps(v58, *(__m128 *)cosCoeff0_0),
                                                   *(__m128 *)cosCoeff1),
                                                 v58),
                                               *(__m128 *)cosCoeff2_0),
                                             v58),
                                           v58),
                                         _mm_mul_ps(v58, *(__m128 *)_xmm)),
                                       *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                                         (float)((float)((float)((float)((float)((float)(v58.m128_f32[0] * -0.00019515296) + 0.0083321612) * v58.m128_f32[0])
                                                                                               + -0.16666655)
                                                                                       * v58.m128_f32[0])
                                                                               * v57.m128_f32[0])
                                                                       + v57.m128_f32[0]) & v55.m128_i32[0]) ^ (_mm_and_si128(_mm_add_epi32(v11, v11), v54).m128i_u32[0] << 29) ^ COERCE_UNSIGNED_INT((float)((float)v5 * 0.20943952) - v10) & _xmm[0];
      v61 = _mm_andnot_ps(*(__m128 *)_xmm, v60);
      v62 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v61, *(__m128 *)_xmm)), si128));
      v63 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v62, v11), (__m128i)0i64);
      v64 = _mm_cvtepi32_ps(v62);
      v65 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v64, *(__m128 *)DP1_0), v61), _mm_mul_ps(v64, v7)),
              _mm_mul_ps(v64, *(__m128 *)DP3));
      v66 = _mm_mul_ps(v65, v65);
      *((_DWORD *)p_m_sinAccept0 + 1) = (_mm_andnot_ps(
                                           v63,
                                           _mm_add_ps(
                                             _mm_sub_ps(
                                               _mm_mul_ps(
                                                 _mm_mul_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(
                                                       _mm_add_ps(
                                                         _mm_mul_ps(v66, *(__m128 *)cosCoeff0_0),
                                                         *(__m128 *)cosCoeff1),
                                                       v66),
                                                     *(__m128 *)cosCoeff2_0),
                                                   v66),
                                                 v66),
                                               _mm_mul_ps(v66, *(__m128 *)_xmm)),
                                             *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                                               (float)((float)((float)((float)((float)((float)(v66.m128_f32[0] * -0.00019515296) + 0.0083321612) * v66.m128_f32[0]) + -0.16666655)
                                                                                             * v66.m128_f32[0])
                                                                                     * v65.m128_f32[0])
                                                                             + v65.m128_f32[0]) & v63.m128_i32[0]) ^ (_mm_and_si128(_mm_add_epi32(v11, v11), v62).m128i_u32[0] << 29) ^ v60.m128_i32[0] & _xmm[0];
      if ( v59 >= (float)(3.1415927 - edgeNormalSnapDeltaAngle) )
        v78 = fminf(v59, 3.1415927);
      else
        v78 = 3.1415927 - edgeNormalSnapDeltaAngle;
      p_m_sinAccept0[3] = -1.0;
      p_m_sinAccept0[4] = 0.0;
      v67 = _mm_add_ps((__m128)LODWORD(v78), *(__m128 *)_xmm);
      v68 = _mm_andnot_ps(*(__m128 *)_xmm, v67);
      v69 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v68, *(__m128 *)_xmm)), si128));
      v70 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v69, v11), (__m128i)0i64);
      v71 = _mm_cvtepi32_ps(v69);
      v72 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v71, *(__m128 *)DP1_0), v68), _mm_mul_ps(v71, v7)),
              _mm_mul_ps(v71, *(__m128 *)DP3));
      v73 = _mm_mul_ps(v72, v72);
      *((_DWORD *)p_m_sinAccept0 + 2) = (_mm_andnot_ps(
                                           v70,
                                           _mm_add_ps(
                                             _mm_sub_ps(
                                               _mm_mul_ps(
                                                 _mm_mul_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(
                                                       _mm_add_ps(
                                                         _mm_mul_ps(v73, *(__m128 *)cosCoeff0_0),
                                                         *(__m128 *)cosCoeff1),
                                                       v73),
                                                     *(__m128 *)cosCoeff2_0),
                                                   v73),
                                                 v73),
                                               _mm_mul_ps(v73, *(__m128 *)_xmm)),
                                             *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                                               (float)((float)((float)((float)((float)((float)(v73.m128_f32[0] * -0.00019515296) + 0.0083321612) * v73.m128_f32[0]) + -0.16666655)
                                                                                             * v73.m128_f32[0])
                                                                                     * v72.m128_f32[0])
                                                                             + v72.m128_f32[0]) & v70.m128_i32[0]) ^ (_mm_and_si128(_mm_add_epi32(v11, v11), v69).m128i_u32[0] << 29) ^ v67.m128_i32[0] & _xmm[0];
    }
    else
    {
      *(_QWORD *)(p_m_sinAccept0 - 1) = 1065353216i64;
      v13 = v10 - COERCE_FLOAT((unsigned int)(2 * LODWORD(v12)) >> 1);
      v14 = v13 - v9;
      if ( (float)(v13 - v9) <= triangleNormalSnapDeltaAngle )
        v76 = fmaxf(v14, 0.0);
      else
        v76 = triangleNormalSnapDeltaAngle;
      v15 = _mm_add_ps((__m128)LODWORD(v76), v2);
      v16 = _mm_andnot_ps(*(__m128 *)_xmm, v15);
      v17 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v16, *(__m128 *)_xmm)), si128));
      v18 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v17, v11), (__m128i)0i64);
      v19 = _mm_cvtepi32_ps(v17);
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v19, *(__m128 *)DP1_0), v16), _mm_mul_ps(v19, *(__m128 *)DP2)),
              _mm_mul_ps(v19, v3));
      v21 = _mm_mul_ps(v20, v20);
      v22 = (_mm_and_si128(_mm_add_epi32(v11, v11), v17).m128i_u32[0] << 29) ^ v15.m128_i32[0] & _xmm[0];
      v23 = _mm_add_ps((__m128)COERCE_UNSIGNED_INT(fmaxf(v14, 0.0)), *(__m128 *)_xmm);
      *((_DWORD *)p_m_sinAccept0 + 1) = (_mm_andnot_ps(
                                           v18,
                                           _mm_add_ps(
                                             _mm_sub_ps(
                                               _mm_mul_ps(
                                                 _mm_mul_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(
                                                       _mm_add_ps(
                                                         _mm_mul_ps(v21, *(__m128 *)cosCoeff0_0),
                                                         *(__m128 *)cosCoeff1),
                                                       v21),
                                                     *(__m128 *)cosCoeff2_0),
                                                   v21),
                                                 v21),
                                               _mm_mul_ps(v21, *(__m128 *)_xmm)),
                                             *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                                               (float)((float)((float)((float)((float)((float)(v21.m128_f32[0] * -0.00019515296) + 0.0083321612) * v21.m128_f32[0]) + -0.16666655)
                                                                                             * v21.m128_f32[0])
                                                                                     * v20.m128_f32[0])
                                                                             + v20.m128_f32[0]) & v18.m128_i32[0]) ^ v22;
      v24 = _mm_andnot_ps(*(__m128 *)_xmm, v23);
      v25 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v24, *(__m128 *)_xmm)), si128));
      v26 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v25, v11), (__m128i)0i64);
      v27 = _mm_cvtepi32_ps(v25);
      v28 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v27, *(__m128 *)DP1_0), v24), _mm_mul_ps(v27, *(__m128 *)DP2)),
              _mm_mul_ps(v27, *(__m128 *)DP3));
      v29 = _mm_mul_ps(v28, v28);
      v30 = (_mm_and_si128(_mm_add_epi32(v11, v11), v25).m128i_u32[0] << 29) ^ v23.m128_i32[0] & _xmm[0];
      v31 = _mm_add_ps((__m128)LODWORD(v13), *(__m128 *)_xmm);
      *((_DWORD *)p_m_sinAccept0 + 2) = (_mm_andnot_ps(
                                           v26,
                                           _mm_add_ps(
                                             _mm_sub_ps(
                                               _mm_mul_ps(
                                                 _mm_mul_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(
                                                       _mm_add_ps(
                                                         _mm_mul_ps(v29, *(__m128 *)cosCoeff0_0),
                                                         *(__m128 *)cosCoeff1),
                                                       v29),
                                                     *(__m128 *)cosCoeff2_0),
                                                   v29),
                                                 v29),
                                               _mm_mul_ps(v29, *(__m128 *)_xmm)),
                                             *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                                               (float)((float)((float)((float)((float)((float)(v29.m128_f32[0] * -0.00019515296) + 0.0083321612) * v29.m128_f32[0]) + -0.16666655)
                                                                                             * v29.m128_f32[0])
                                                                                     * v28.m128_f32[0])
                                                                             + v28.m128_f32[0]) & v26.m128_i32[0]) ^ v30;
      v32 = _mm_andnot_ps(*(__m128 *)_xmm, v31);
      v33 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v32, *(__m128 *)_xmm)), si128));
      v34 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v33, v11), (__m128i)0i64);
      v35 = _mm_cvtepi32_ps(v33);
      v36 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v35, *(__m128 *)DP1_0), v32), _mm_mul_ps(v35, *(__m128 *)DP2)),
              _mm_mul_ps(v35, *(__m128 *)DP3));
      v37 = _mm_mul_ps(v36, v36);
      v77 = v13;
      v7 = *(__m128 *)DP2;
      v38 = (_mm_andnot_ps(
               v34,
               _mm_add_ps(
                 _mm_sub_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v37, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v37),
                         *(__m128 *)cosCoeff2_0),
                       v37),
                     v37),
                   _mm_mul_ps(v37, *(__m128 *)_xmm)),
                 *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                   (float)((float)((float)((float)((float)((float)(v37.m128_f32[0]
                                                                                                 * -0.00019515296)
                                                                                         + 0.0083321612)
                                                                                 * v37.m128_f32[0])
                                                                         + -0.16666655)
                                                                 * v37.m128_f32[0])
                                                         * v36.m128_f32[0])
                                                 + v36.m128_f32[0]) & v34.m128_i32[0]) ^ (_mm_and_si128(
                                                                                            _mm_add_epi32(v11, v11),
                                                                                            v33).m128i_u32[0] << 29) ^ v31.m128_i32[0] & _xmm[0];
      v39 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(v77));
      *((_DWORD *)p_m_sinAccept0 + 3) = v38;
      v40 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v39, *(__m128 *)_xmm)), si128));
      v41 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v40, v11), (__m128i)0i64);
      v42 = _mm_cvtepi32_ps(v40);
      v43 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v42, *(__m128 *)DP1_0), v39), _mm_mul_ps(v42, *(__m128 *)DP2)),
              _mm_mul_ps(v42, *(__m128 *)DP3));
      v44 = _mm_mul_ps(v43, v43);
      *((_DWORD *)p_m_sinAccept0 + 4) = (_mm_andnot_ps(
                                           v41,
                                           _mm_add_ps(
                                             _mm_sub_ps(
                                               _mm_mul_ps(
                                                 _mm_mul_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(
                                                       _mm_add_ps(
                                                         _mm_mul_ps(v44, *(__m128 *)cosCoeff0_0),
                                                         *(__m128 *)cosCoeff1),
                                                       v44),
                                                     *(__m128 *)cosCoeff2_0),
                                                   v44),
                                                 v44),
                                               _mm_mul_ps(v44, *(__m128 *)_xmm)),
                                             *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                                               (float)((float)((float)((float)((float)((float)(v44.m128_f32[0] * -0.00019515296) + 0.0083321612) * v44.m128_f32[0]) + -0.16666655)
                                                                                             * v44.m128_f32[0])
                                                                                     * v43.m128_f32[0])
                                                                             + v43.m128_f32[0]) & v41.m128_i32[0]) ^ (_mm_and_si128(_mm_add_epi32(v11, v11), v40).m128i_u32[0] << 29) ^ LODWORD(v77) & _xmm[0];
    }
    v3 = *(__m128 *)DP3;
    v2 = *(__m128 *)_xmm;
    v10 = FLOAT_3_1415927;
    triangleNormalSnapDeltaAngle = edgeNormalSnapDeltaAngle;
    v9 = *(float *)&retaddr;
    ++v5;
    p_m_sinAccept0 += 6;
  }
  while ( v5 < 31 );
}

// File Line: 138
// RVA: 0x131E670
__int64 __fastcall hkpWeldingUtility::calcScaledWeldingInfo(
        hkVector4f *vertices,
        unsigned __int16 weldingInfo,
        hkpWeldingUtility::WeldingType weldingType,
        hkVector4f *scale)
{
  __m128 v4; // xmm9
  __m128 m_quad; // xmm12
  __m128 v6; // xmm8
  __m128 v7; // xmm11
  __m128 v8; // xmm6
  __m128 v9; // xmm5
  __m128 v10; // xmm4
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm8
  __m128 v17; // xmm8
  __m128 v18; // xmm9
  __m128 v19; // xmm0
  __m128 v20; // xmm11
  __m128 v21; // xmm1
  __m128 v22; // xmm9
  __m128 v23; // xmm11
  __m128 v24; // xmm11
  unsigned __int64 v25; // r10
  __int64 v26; // r9
  __m128 v27; // xmm3
  __int64 v28; // r8
  hkpWeldingUtility::SinCosTableEntry *v29; // rdx
  hkpWeldingUtility::SinCosTableEntry *v30; // rcx
  __m128 v31; // xmm8
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  __m128 v35; // xmm9
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  __m128 v40; // xmm11
  __m128 v41; // xmm2
  hkpWeldingUtility::SinCosTableEntry *v42; // rcx
  __m128 v43; // xmm14
  __m128 v44; // xmm1
  __m128 v45; // xmm6
  __m128 v46; // xmm4
  __m128 v47; // xmm8
  __m128 v48; // xmm1
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  __m128 v51; // xmm8
  __m128 v52; // xmm1
  __m128 v53; // xmm7
  __m128 v54; // xmm7
  __m128 v55; // xmm9
  __m128 v56; // xmm10
  __m128 v57; // xmm1
  __m128 v58; // xmm9
  __m128 v59; // xmm10
  __m128 v60; // xmm3
  __m128 v61; // xmm10
  __m128 v62; // xmm1
  __m128 v63; // xmm7
  __m128 v64; // xmm6
  __m128 v65; // xmm14
  __m128 v66; // xmm13
  __m128 v67; // xmm3
  __m128 v68; // xmm9
  __m128 v69; // xmm1
  __m128 v70; // xmm3
  __m128 v71; // xmm10
  __m128 v72; // xmm1
  __m128 v73; // xmm3
  __m128 v74; // xmm6
  __m128 v75; // xmm1
  __m128 v76; // xmm3
  __m128 v77; // xmm14
  __m128 v78; // xmm1
  __m128 v79; // xmm2
  __m128 v80; // xmm13
  __m128 v81; // xmm1
  __m128 v82; // xmm6
  __m128 v83; // xmm10
  __m128 v84; // xmm5
  __m128 v85; // xmm1
  __m128 v86; // xmm8
  __m128 v87; // xmm14
  __m128 v88; // xmm3
  __m128 v89; // xmm0
  __m128 v90; // xmm1
  __m128 v91; // xmm11
  __m128 v92; // xmm8
  __m128 v93; // xmm1
  __m128 v94; // xmm4
  __m128 v95; // xmm7
  __m128 v96; // xmm3
  __m128 v97; // xmm2
  __m128 v98; // xmm7
  __m128 v99; // xmm6
  int v100; // eax
  int v101; // ebx
  int v102; // ebx
  __m128 v104; // [rsp+20h] [rbp-E8h]
  __m128 v105; // [rsp+30h] [rbp-D8h]
  __m128 v106; // [rsp+40h] [rbp-C8h]
  __m128 v107; // [rsp+50h] [rbp-B8h]

  v4 = _mm_sub_ps(vertices[2].m_quad, vertices[1].m_quad);
  m_quad = scale->m_quad;
  v6 = _mm_sub_ps(vertices[1].m_quad, vertices->m_quad);
  v7 = _mm_sub_ps(vertices->m_quad, vertices[2].m_quad);
  v8 = _mm_shuffle_ps(v4, v4, 201);
  v9 = _mm_shuffle_ps(v6, v6, 201);
  v105 = _mm_mul_ps(v6, scale->m_quad);
  v107 = _mm_mul_ps(v7, scale->m_quad);
  v106 = _mm_mul_ps(v4, scale->m_quad);
  v10 = _mm_sub_ps(_mm_mul_ps(v6, v8), _mm_mul_ps(v4, v9));
  v11 = _mm_shuffle_ps(v10, v10, 201);
  v12 = _mm_mul_ps(v11, v11);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  v104 = _mm_mul_ps(
           _mm_andnot_ps(
             _mm_cmple_ps(v13, (__m128)0i64),
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
               _mm_mul_ps(v14, *(__m128 *)_xmm))),
           v11);
  v15 = _mm_shuffle_ps(v104, v104, 201);
  v16 = _mm_sub_ps(_mm_mul_ps(v6, v15), _mm_mul_ps(v104, v9));
  v17 = _mm_shuffle_ps(v16, v16, 201);
  v18 = _mm_sub_ps(_mm_mul_ps(v4, v15), _mm_mul_ps(v104, v8));
  v19 = _mm_shuffle_ps(v7, v7, 201);
  v20 = _mm_mul_ps(v7, v15);
  v21 = _mm_mul_ps(v17, v17);
  v22 = _mm_shuffle_ps(v18, v18, 201);
  v23 = _mm_sub_ps(v20, _mm_mul_ps(v19, v104));
  v24 = _mm_shuffle_ps(v23, v23, 201);
  v25 = weldingInfo;
  v26 = weldingType;
  v27 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v28 = weldingType + 1;
  v29 = &hkpWeldingUtility::m_sinCosTable[weldingInfo & 0x1F];
  v30 = &hkpWeldingUtility::m_sinCosTable[((unsigned int)v25 >> 5) & 0x1F];
  v31 = _mm_mul_ps(v17, _mm_andnot_ps(_mm_cmple_ps(v27, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v27))));
  v32 = _mm_mul_ps(v22, v22);
  v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)), _mm_shuffle_ps(v32, v32, 170));
  v34 = _mm_mul_ps(v24, v24);
  v35 = _mm_mul_ps(v22, _mm_andnot_ps(_mm_cmple_ps(v33, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v33))));
  v36 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)), _mm_shuffle_ps(v34, v34, 170));
  v37 = _mm_cmple_ps(v36, (__m128)0i64);
  v38 = _mm_div_ps(query.m_quad, _mm_sqrt_ps(v36));
  v39 = _mm_shuffle_ps(
          (__m128)*((unsigned int *)&v30->m_cosAccept0 + v28),
          (__m128)*((unsigned int *)&v30->m_cosAccept0 + v28),
          0);
  v40 = _mm_mul_ps(v24, _mm_andnot_ps(v37, v38));
  v41 = (__m128)*((unsigned int *)&v30->m_cosAccept0 + v26);
  v42 = &hkpWeldingUtility::m_sinCosTable[(v25 >> 10) & 0x1F];
  v43 = _mm_add_ps(_mm_mul_ps(_mm_add_ps((__m128)0i64, v104), _mm_shuffle_ps(v41, v41, 0)), _mm_mul_ps(v35, v39));
  v44 = _mm_rcp_ps(m_quad);
  v45 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps((__m128)0i64, v104),
            _mm_shuffle_ps(
              (__m128)*((unsigned int *)&v29->m_cosAccept0 + v26),
              (__m128)*((unsigned int *)&v29->m_cosAccept0 + v26),
              0)),
          _mm_mul_ps(
            v31,
            _mm_shuffle_ps(
              (__m128)*((unsigned int *)&v29->m_cosAccept0 + v28),
              (__m128)*((unsigned int *)&v29->m_cosAccept0 + v28),
              0)));
  v46 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v44, m_quad)), v44);
  v47 = _mm_mul_ps(v104, v46);
  v48 = _mm_mul_ps(v47, v47);
  v49 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)), _mm_shuffle_ps(v48, v48, 170));
  v50 = _mm_rsqrt_ps(v49);
  v51 = _mm_mul_ps(
          v47,
          _mm_andnot_ps(
            _mm_cmple_ps(v49, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v49), v50)),
              _mm_mul_ps(v50, *(__m128 *)_xmm))));
  v52 = _mm_shuffle_ps(v51, v51, 201);
  v53 = _mm_sub_ps(_mm_mul_ps(v105, v52), _mm_mul_ps(_mm_shuffle_ps(v105, v105, 201), v51));
  v54 = _mm_shuffle_ps(v53, v53, 201);
  v55 = _mm_sub_ps(_mm_mul_ps(v106, v52), _mm_mul_ps(_mm_shuffle_ps(v106, v106, 201), v51));
  v56 = _mm_mul_ps(v107, v52);
  v57 = _mm_mul_ps(v54, v54);
  v58 = _mm_shuffle_ps(v55, v55, 201);
  v59 = _mm_sub_ps(v56, _mm_mul_ps(_mm_shuffle_ps(v107, v107, 201), v51));
  v60 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)), _mm_shuffle_ps(v57, v57, 170));
  v61 = _mm_shuffle_ps(v59, v59, 201);
  v62 = _mm_mul_ps(v58, v58);
  v63 = _mm_mul_ps(v54, _mm_andnot_ps(_mm_cmple_ps(v60, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v60))));
  v64 = _mm_mul_ps(v45, v46);
  v65 = _mm_mul_ps(v43, v46);
  v66 = _mm_mul_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps((__m128)0i64, v104),
              _mm_shuffle_ps(
                (__m128)*((unsigned int *)&v42->m_cosAccept0 + v26),
                (__m128)*((unsigned int *)&v42->m_cosAccept0 + v26),
                0)),
            _mm_mul_ps(
              v40,
              _mm_shuffle_ps(
                (__m128)*((unsigned int *)&v42->m_cosAccept0 + v28),
                (__m128)*((unsigned int *)&v42->m_cosAccept0 + v28),
                0))),
          v46);
  v67 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)), _mm_shuffle_ps(v62, v62, 170));
  v68 = _mm_mul_ps(v58, _mm_andnot_ps(_mm_cmple_ps(v67, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v67))));
  v69 = _mm_mul_ps(v61, v61);
  v70 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v69, v69, 85), _mm_shuffle_ps(v69, v69, 0)), _mm_shuffle_ps(v69, v69, 170));
  v71 = _mm_mul_ps(v61, _mm_andnot_ps(_mm_cmple_ps(v70, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v70))));
  v72 = _mm_mul_ps(v64, v64);
  v73 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v72, v72, 0)), _mm_shuffle_ps(v72, v72, 170));
  v74 = _mm_mul_ps(v64, _mm_andnot_ps(_mm_cmple_ps(v73, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v73))));
  v75 = _mm_mul_ps(v65, v65);
  v76 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v75, v75, 85), _mm_shuffle_ps(v75, v75, 0)), _mm_shuffle_ps(v75, v75, 170));
  v77 = _mm_mul_ps(v65, _mm_andnot_ps(_mm_cmple_ps(v76, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v76))));
  v78 = _mm_mul_ps(v66, v66);
  v79 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v78, v78, 85), _mm_shuffle_ps(v78, v78, 0)), _mm_shuffle_ps(v78, v78, 170));
  v80 = _mm_mul_ps(v66, _mm_andnot_ps(_mm_cmple_ps(v79, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v79))));
  v81 = _mm_mul_ps(v74, v51);
  v82 = _mm_mul_ps(v74, v63);
  v83 = _mm_mul_ps(v71, v80);
  v84 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v81, v81, 85), _mm_shuffle_ps(v81, v81, 0)), _mm_shuffle_ps(v81, v81, 170));
  v85 = _mm_mul_ps(v77, v51);
  v86 = _mm_mul_ps(v51, v80);
  v87 = _mm_mul_ps(v77, v68);
  v88 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v86, v86, 85), _mm_shuffle_ps(v86, v86, 0)), _mm_shuffle_ps(v86, v86, 170));
  v89 = _mm_rcp_ps(
          _mm_movelh_ps(
            _mm_unpacklo_ps(
              v84,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v85, v85, 85), _mm_shuffle_ps(v85, v85, 0)),
                _mm_shuffle_ps(v85, v85, 170))),
            _mm_unpacklo_ps(v88, v88)));
  v90 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v83, v83, 85), _mm_shuffle_ps(v83, v83, 0)), _mm_shuffle_ps(v83, v83, 170));
  v91 = _mm_cmple_ps((__m128)0i64, v89);
  v92 = _mm_movelh_ps(
          _mm_unpacklo_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v82, v82, 85), _mm_shuffle_ps(v82, v82, 0)),
              _mm_shuffle_ps(v82, v82, 170)),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v87, v87, 85), _mm_shuffle_ps(v87, v87, 0)),
              _mm_shuffle_ps(v87, v87, 170))),
          _mm_unpacklo_ps(v90, v90));
  v93 = _mm_mul_ps(v92, v89);
  v94 = _mm_or_ps(_mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v93), _mm_cmplt_ps(*(__m128 *)_xmm, v93));
  v95 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v93), v94), _mm_andnot_ps(v94, v93));
  v96 = _mm_mul_ps(v95, v95);
  v97 = _mm_mul_ps(
          _mm_rcp_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_rcp_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_rcp_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v96, *(__m128 *)s0)), *(__m128 *)t0),
                          _mm_add_ps(v96, *(__m128 *)s1))),
                      *(__m128 *)t1),
                    _mm_add_ps(v96, *(__m128 *)s2))),
                *(__m128 *)t2),
              _mm_add_ps(v96, *(__m128 *)s3))),
          _mm_mul_ps(v95, *(__m128 *)t3));
  v98 = _mm_or_ps(
          _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v95, *(__m128 *)_xmm), *(__m128 *)_xmm), v97), v94),
          _mm_andnot_ps(v94, v97));
  v99 = _mm_or_ps(
          _mm_andnot_ps(v91, _mm_add_ps(_mm_or_ps(_mm_and_ps(v92, *(__m128 *)_xmm), *(__m128 *)_xmm), v98)),
          _mm_and_ps(v98, v91));
  v100 = hkpWeldingUtility::calcEdgeAngleBitcode(_mm_shuffle_ps(v99, v99, 85).m128_f32[0]);
  HIWORD(v101) = HIWORD(v100);
  LOWORD(v101) = 32 * v100;
  v102 = hkpWeldingUtility::calcEdgeAngleBitcode(v99.m128_f32[0]) | v101;
  return v102 | (unsigned int)(hkpWeldingUtility::calcEdgeAngleBitcode(_mm_shuffle_ps(v99, v99, 170).m128_f32[0]) << 10);
}cEdgeAngleBitcode(_mm_shuffle_ps(v99, v99, 170).m128_f32[0]) << 10);
}

// File Line: 258
// RVA: 0x131ED90
__int64 __fastcall hkpWeldingUtility::calcEdgeAngleBitcode(float angle)
{
  __int64 result; // rax
  float v2; // xmm1_4

  result = 0i64;
  while ( 1 )
  {
    v2 = (float)((float)(int)result * 0.20943952) - 3.1415927;
    if ( angle <= v2 )
      break;
    result = (unsigned int)(result + 1);
    if ( (int)result >= 31 )
      return result;
  }
  if ( angle > 0.0 && angle != v2 )
    return (unsigned int)(result - 1);
  return result;
}


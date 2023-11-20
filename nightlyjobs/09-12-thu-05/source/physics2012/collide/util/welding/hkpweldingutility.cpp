// File Line: 21
// RVA: 0x131DD00
void __fastcall hkpWeldingUtility::initWeldingTable(float edgeNormalSnapDeltaAngle, float triangleNormalSnapDeltaAngle)
{
  __m128 v2; // xmm2
  __m128 v3; // xmm3
  _DWORD *v4; // rax
  signed int v5; // ecx
  __m128i v6; // xmm10
  __m128 v7; // xmm12
  float v8; // xmm4_4
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
  int v38; // xmm3_4
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
  int v52; // xmm3_4
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
  float v75; // [rsp+D8h] [rbp+6Fh]
  float v76; // [rsp+E0h] [rbp+77h]
  float v77; // [rsp+E0h] [rbp+77h]
  float v78; // [rsp+E0h] [rbp+77h]
  float v79; // [rsp+E0h] [rbp+77h]

  v75 = edgeNormalSnapDeltaAngle;
  v2 = *(__m128 *)_xmm;
  v3 = *(__m128 *)DP3;
  v4 = (_DWORD *)&hkpWeldingUtility::m_sinCosTable[0].m_sinAccept0;
  v5 = 0;
  v6 = _mm_load_si128((const __m128i *)_xmm);
  v7 = *(__m128 *)DP2;
  v8 = triangleNormalSnapDeltaAngle;
  v9 = edgeNormalSnapDeltaAngle;
  v10 = FLOAT_3_1415927;
  v11 = _mm_add_epi32(v6, v6);
  do
  {
    v12 = (float)((float)v5 * 0.20943952) - v10;
    v76 = (float)((float)v5 * 0.20943952) - v10;
    if ( v12 >= 0.0 )
    {
      v45 = _mm_add_ps((__m128)LODWORD(v76), v2);
      v46 = _mm_andnot_ps(*(__m128 *)_xmm, v45);
      v47 = _mm_andnot_si128(v6, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v46, *(__m128 *)_xmm)), v6));
      v48 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v47, v11), (__m128i)0i64);
      v49 = _mm_cvtepi32_ps(v47);
      v50 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v49, *(__m128 *)DP1_0), v46), _mm_mul_ps(v49, v7)),
              _mm_mul_ps(v49, v3));
      v51 = _mm_mul_ps(v50, v50);
      v52 = (*(unsigned __int128 *)&_mm_andnot_ps(
                                      v48,
                                      _mm_add_ps(
                                        _mm_sub_ps(
                                          _mm_mul_ps(
                                            _mm_mul_ps(
                                              _mm_add_ps(
                                                _mm_mul_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(v51, *(__m128 *)cosCoeff0_0),
                                                    *(__m128 *)cosCoeff1),
                                                  v51),
                                                *(__m128 *)cosCoeff2_0),
                                              v51),
                                            v51),
                                          _mm_mul_ps(v51, *(__m128 *)_xmm)),
                                        *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                              (float)((float)((float)((float)((float)((float)(v51.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                                                                            * v51.m128_f32[0])
                                                                                    + -0.16666655)
                                                                            * v51.m128_f32[0])
                                                                    * v50.m128_f32[0])
                                                            + v50.m128_f32[0]) & v48.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v11, v11), v47) << 29) ^ v45.m128_i32[0] & _xmm[0];
      v53 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(v12));
      *(v4 - 1) = v52;
      v54 = _mm_andnot_si128(v6, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v53, *(__m128 *)_xmm)), v6));
      v55 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v54, v11), (__m128i)0i64);
      v56 = _mm_cvtepi32_ps(v54);
      v57 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v56, *(__m128 *)DP1_0), v53), _mm_mul_ps(v56, v7)),
              _mm_mul_ps(v56, *(__m128 *)DP3));
      v58 = _mm_mul_ps(v57, v57);
      v59 = v12 + *(float *)&retaddr;
      v60 = _mm_add_ps((__m128)COERCE_UNSIGNED_INT(fminf(v59, 3.1415927)), *(__m128 *)_xmm);
      *v4 = (*(unsigned __int128 *)&_mm_andnot_ps(
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
                                        *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                              (float)((float)((float)((float)((float)((float)(v58.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                                                                            * v58.m128_f32[0])
                                                                                    + -0.16666655)
                                                                            * v58.m128_f32[0])
                                                                    * v57.m128_f32[0])
                                                            + v57.m128_f32[0]) & v55.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v11, v11), v54) << 29) ^ COERCE_UNSIGNED_INT((float)((float)v5 * 0.20943952) - v10) & _xmm[0];
      v61 = _mm_andnot_ps(*(__m128 *)_xmm, v60);
      v62 = _mm_andnot_si128(v6, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v61, *(__m128 *)_xmm)), v6));
      v63 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v62, v11), (__m128i)0i64);
      v64 = _mm_cvtepi32_ps(v62);
      v65 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v64, *(__m128 *)DP1_0), v61), _mm_mul_ps(v64, v7)),
              _mm_mul_ps(v64, *(__m128 *)DP3));
      v66 = _mm_mul_ps(v65, v65);
      v4[1] = (*(unsigned __int128 *)&_mm_andnot_ps(
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
                                          *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                (float)((float)((float)((float)((float)((float)(v66.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                                                                              * v66.m128_f32[0])
                                                                                      + -0.16666655)
                                                                              * v66.m128_f32[0])
                                                                      * v65.m128_f32[0])
                                                              + v65.m128_f32[0]) & v63.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v11, v11), v62) << 29) ^ v60.m128_i32[0] & _xmm[0];
      if ( v59 >= (float)(3.1415927 - v75) )
        v79 = fminf(v59, 3.1415927);
      else
        v79 = 3.1415927 - v75;
      v4[3] = -1082130432;
      v4[4] = 0;
      v67 = _mm_add_ps((__m128)LODWORD(v79), *(__m128 *)_xmm);
      v68 = _mm_andnot_ps(*(__m128 *)_xmm, v67);
      v69 = _mm_andnot_si128(v6, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v68, *(__m128 *)_xmm)), v6));
      v70 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v69, v11), (__m128i)0i64);
      v71 = _mm_cvtepi32_ps(v69);
      v72 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v71, *(__m128 *)DP1_0), v68), _mm_mul_ps(v71, v7)),
              _mm_mul_ps(v71, *(__m128 *)DP3));
      v73 = _mm_mul_ps(v72, v72);
      v4[2] = (*(unsigned __int128 *)&_mm_andnot_ps(
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
                                          *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                (float)((float)((float)((float)((float)((float)(v73.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                                                                              * v73.m128_f32[0])
                                                                                      + -0.16666655)
                                                                              * v73.m128_f32[0])
                                                                      * v72.m128_f32[0])
                                                              + v72.m128_f32[0]) & v70.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v11, v11), v69) << 29) ^ v67.m128_i32[0] & _xmm[0];
    }
    else
    {
      *(_QWORD *)(v4 - 1) = 1065353216i64;
      v13 = v10 - COERCE_FLOAT((unsigned int)(2 * LODWORD(v76)) >> 1);
      v14 = v13 - v9;
      if ( (float)(v13 - v9) <= v8 )
        v77 = fmaxf(v14, 0.0);
      else
        v77 = v8;
      v15 = _mm_add_ps((__m128)LODWORD(v77), v2);
      v16 = _mm_andnot_ps(*(__m128 *)_xmm, v15);
      v17 = _mm_andnot_si128(v6, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v16, *(__m128 *)_xmm)), v6));
      v18 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v17, v11), (__m128i)0i64);
      v19 = _mm_cvtepi32_ps(v17);
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v19, *(__m128 *)DP1_0), v16), _mm_mul_ps(v19, *(__m128 *)DP2)),
              _mm_mul_ps(v19, v3));
      v21 = _mm_mul_ps(v20, v20);
      v22 = ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v11, v11), v17) << 29) ^ v15.m128_i32[0] & _xmm[0];
      v23 = _mm_add_ps((__m128)COERCE_UNSIGNED_INT(fmaxf(v14, 0.0)), *(__m128 *)_xmm);
      v4[1] = (*(unsigned __int128 *)&_mm_andnot_ps(
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
                                          *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                (float)((float)((float)((float)((float)((float)(v21.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                                                                              * v21.m128_f32[0])
                                                                                      + -0.16666655)
                                                                              * v21.m128_f32[0])
                                                                      * v20.m128_f32[0])
                                                              + v20.m128_f32[0]) & v18.m128_i32[0]) ^ v22;
      v24 = _mm_andnot_ps(*(__m128 *)_xmm, v23);
      v25 = _mm_andnot_si128(v6, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v24, *(__m128 *)_xmm)), v6));
      v26 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v25, v11), (__m128i)0i64);
      v27 = _mm_cvtepi32_ps(v25);
      v28 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v27, *(__m128 *)DP1_0), v24), _mm_mul_ps(v27, *(__m128 *)DP2)),
              _mm_mul_ps(v27, *(__m128 *)DP3));
      v29 = _mm_mul_ps(v28, v28);
      v30 = ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v11, v11), v25) << 29) ^ v23.m128_i32[0] & _xmm[0];
      v31 = _mm_add_ps((__m128)LODWORD(v13), *(__m128 *)_xmm);
      v4[2] = (*(unsigned __int128 *)&_mm_andnot_ps(
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
                                          *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                (float)((float)((float)((float)((float)((float)(v29.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                                                                              * v29.m128_f32[0])
                                                                                      + -0.16666655)
                                                                              * v29.m128_f32[0])
                                                                      * v28.m128_f32[0])
                                                              + v28.m128_f32[0]) & v26.m128_i32[0]) ^ v30;
      v32 = _mm_andnot_ps(*(__m128 *)_xmm, v31);
      v33 = _mm_andnot_si128(v6, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v32, *(__m128 *)_xmm)), v6));
      v34 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v33, v11), (__m128i)0i64);
      v35 = _mm_cvtepi32_ps(v33);
      v36 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v35, *(__m128 *)DP1_0), v32), _mm_mul_ps(v35, *(__m128 *)DP2)),
              _mm_mul_ps(v35, *(__m128 *)DP3));
      v37 = _mm_mul_ps(v36, v36);
      v78 = v13;
      v7 = *(__m128 *)DP2;
      v38 = (*(unsigned __int128 *)&_mm_andnot_ps(
                                      v34,
                                      _mm_add_ps(
                                        _mm_sub_ps(
                                          _mm_mul_ps(
                                            _mm_mul_ps(
                                              _mm_add_ps(
                                                _mm_mul_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(v37, *(__m128 *)cosCoeff0_0),
                                                    *(__m128 *)cosCoeff1),
                                                  v37),
                                                *(__m128 *)cosCoeff2_0),
                                              v37),
                                            v37),
                                          _mm_mul_ps(v37, *(__m128 *)_xmm)),
                                        *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                              (float)((float)((float)((float)((float)((float)(v37.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                                                                            * v37.m128_f32[0])
                                                                                    + -0.16666655)
                                                                            * v37.m128_f32[0])
                                                                    * v36.m128_f32[0])
                                                            + v36.m128_f32[0]) & v34.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v11, v11), v33) << 29) ^ v31.m128_i32[0] & _xmm[0];
      v39 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(v78));
      v4[3] = v38;
      v40 = _mm_andnot_si128(v6, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v39, *(__m128 *)_xmm)), v6));
      v41 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v40, v11), (__m128i)0i64);
      v42 = _mm_cvtepi32_ps(v40);
      v43 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v42, *(__m128 *)DP1_0), v39), _mm_mul_ps(v42, *(__m128 *)DP2)),
              _mm_mul_ps(v42, *(__m128 *)DP3));
      v44 = _mm_mul_ps(v43, v43);
      v4[4] = (*(unsigned __int128 *)&_mm_andnot_ps(
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
                                          *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                (float)((float)((float)((float)((float)((float)(v44.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                                                                              * v44.m128_f32[0])
                                                                                      + -0.16666655)
                                                                              * v44.m128_f32[0])
                                                                      * v43.m128_f32[0])
                                                              + v43.m128_f32[0]) & v41.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v11, v11), v40) << 29) ^ LODWORD(v78) & _xmm[0];
    }
    v3 = *(__m128 *)DP3;
    v2 = *(__m128 *)_xmm;
    v10 = FLOAT_3_1415927;
    v8 = v75;
    v9 = *(float *)&retaddr;
    ++v5;
    v4 += 6;
  }
  while ( v5 < 31 );
}

// File Line: 138
// RVA: 0x131E670
__int64 __fastcall hkpWeldingUtility::calcScaledWeldingInfo(hkVector4f *vertices, unsigned __int16 weldingInfo, hkpWeldingUtility::WeldingType weldingType, hkVector4f *scale)
{
  __m128 v4; // xmm9
  __m128 v5; // xmm12
  __m128 v6; // xmm8
  __m128 v7; // xmm11
  __m128 v8; // xmm6
  __m128 v9; // xmm5
  __m128 v10; // ST30_16
  __m128 v11; // ST50_16
  __m128 v12; // ST40_16
  __m128 v13; // xmm4
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // ST20_16
  __m128 v19; // xmm1
  __m128 v20; // xmm8
  __m128 v21; // xmm8
  __m128 v22; // xmm9
  __m128 v23; // xmm0
  __m128 v24; // xmm11
  __m128 v25; // xmm1
  __m128 v26; // xmm9
  __m128 v27; // xmm11
  __m128 v28; // xmm11
  unsigned __int64 v29; // r10
  __int64 v30; // r9
  __m128 v31; // xmm3
  __int64 v32; // r8
  hkpWeldingUtility::SinCosTableEntry *v33; // rdx
  hkpWeldingUtility::SinCosTableEntry *v34; // rcx
  __m128 v35; // xmm8
  __m128 v36; // xmm1
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  __m128 v39; // xmm9
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  __m128 v43; // xmm3
  __m128 v44; // xmm11
  __m128 v45; // xmm2
  hkpWeldingUtility::SinCosTableEntry *v46; // rcx
  __m128 v47; // xmm14
  __m128 v48; // xmm1
  __m128 v49; // xmm6
  __m128 v50; // xmm4
  __m128 v51; // xmm8
  __m128 v52; // xmm1
  __m128 v53; // xmm2
  __m128 v54; // xmm1
  __m128 v55; // xmm8
  __m128 v56; // xmm1
  __m128 v57; // xmm7
  __m128 v58; // xmm7
  __m128 v59; // xmm9
  __m128 v60; // xmm10
  __m128 v61; // xmm1
  __m128 v62; // xmm9
  __m128 v63; // xmm10
  __m128 v64; // xmm3
  __m128 v65; // xmm10
  __m128 v66; // xmm1
  __m128 v67; // xmm7
  __m128 v68; // xmm6
  __m128 v69; // xmm14
  __m128 v70; // xmm13
  __m128 v71; // xmm3
  __m128 v72; // xmm9
  __m128 v73; // xmm1
  __m128 v74; // xmm3
  __m128 v75; // xmm10
  __m128 v76; // xmm1
  __m128 v77; // xmm3
  __m128 v78; // xmm6
  __m128 v79; // xmm1
  __m128 v80; // xmm3
  __m128 v81; // xmm14
  __m128 v82; // xmm1
  __m128 v83; // xmm2
  __m128 v84; // xmm13
  __m128 v85; // xmm1
  __m128 v86; // xmm6
  __m128 v87; // xmm10
  __m128 v88; // xmm5
  __m128 v89; // xmm1
  __m128 v90; // xmm8
  __m128 v91; // xmm14
  __m128 v92; // xmm3
  __m128 v93; // xmm0
  __m128 v94; // xmm1
  __m128 v95; // xmm11
  __m128 v96; // xmm8
  __m128 v97; // xmm1
  __m128 v98; // xmm4
  __m128 v99; // xmm7
  __m128 v100; // xmm3
  __m128 v101; // xmm2
  __m128 v102; // xmm7
  __m128 v103; // xmm6
  int v104; // eax
  int v105; // ebx
  int v106; // ebx

  v4 = _mm_sub_ps(vertices[2].m_quad, vertices[1].m_quad);
  v5 = scale->m_quad;
  v6 = _mm_sub_ps(vertices[1].m_quad, vertices->m_quad);
  v7 = _mm_sub_ps(vertices->m_quad, vertices[2].m_quad);
  v8 = _mm_shuffle_ps(v4, v4, 201);
  v9 = _mm_shuffle_ps(v6, v6, 201);
  v10 = _mm_mul_ps(v6, scale->m_quad);
  v11 = _mm_mul_ps(v7, scale->m_quad);
  v12 = _mm_mul_ps(v4, scale->m_quad);
  v13 = _mm_sub_ps(_mm_mul_ps(v6, v8), _mm_mul_ps(v4, v9));
  v14 = _mm_shuffle_ps(v13, v13, 201);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  v18 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v16, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
              _mm_mul_ps(v17, *(__m128 *)_xmm))),
          v14);
  v19 = _mm_shuffle_ps(v18, v18, 201);
  v20 = _mm_sub_ps(_mm_mul_ps(v6, v19), _mm_mul_ps(v18, v9));
  v21 = _mm_shuffle_ps(v20, v20, 201);
  v22 = _mm_sub_ps(_mm_mul_ps(v4, v19), _mm_mul_ps(v18, v8));
  v23 = _mm_shuffle_ps(v7, v7, 201);
  v24 = _mm_mul_ps(v7, v19);
  v25 = _mm_mul_ps(v21, v21);
  v26 = _mm_shuffle_ps(v22, v22, 201);
  v27 = _mm_sub_ps(v24, _mm_mul_ps(v23, v18));
  v28 = _mm_shuffle_ps(v27, v27, 201);
  v29 = weldingInfo;
  v30 = weldingType;
  v31 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)), _mm_shuffle_ps(v25, v25, 170));
  v32 = weldingType + 1;
  v33 = &hkpWeldingUtility::m_sinCosTable[weldingInfo & 0x1F];
  v34 = &hkpWeldingUtility::m_sinCosTable[((unsigned int)v29 >> 5) & 0x1F];
  v35 = _mm_mul_ps(v21, _mm_andnot_ps(_mm_cmpleps(v31, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v31))));
  v36 = _mm_mul_ps(v26, v26);
  v37 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)), _mm_shuffle_ps(v36, v36, 170));
  v38 = _mm_mul_ps(v28, v28);
  v39 = _mm_mul_ps(v26, _mm_andnot_ps(_mm_cmpleps(v37, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v37))));
  v40 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)), _mm_shuffle_ps(v38, v38, 170));
  v41 = _mm_cmpleps(v40, (__m128)0i64);
  v42 = _mm_div_ps(query.m_quad, _mm_sqrt_ps(v40));
  v43 = _mm_shuffle_ps(
          (__m128)*((unsigned int *)&v34->m_cosAccept0 + v32),
          (__m128)*((unsigned int *)&v34->m_cosAccept0 + v32),
          0);
  v44 = _mm_mul_ps(v28, _mm_andnot_ps(v41, v42));
  v45 = (__m128)*((unsigned int *)&v34->m_cosAccept0 + v30);
  v46 = &hkpWeldingUtility::m_sinCosTable[(v29 >> 10) & 0x1F];
  v47 = _mm_add_ps(_mm_mul_ps(_mm_add_ps((__m128)0i64, v18), _mm_shuffle_ps(v45, v45, 0)), _mm_mul_ps(v39, v43));
  v48 = _mm_rcp_ps(v5);
  v49 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps((__m128)0i64, v18),
            _mm_shuffle_ps(
              (__m128)*((unsigned int *)&v33->m_cosAccept0 + v30),
              (__m128)*((unsigned int *)&v33->m_cosAccept0 + v30),
              0)),
          _mm_mul_ps(
            v35,
            _mm_shuffle_ps(
              (__m128)*((unsigned int *)&v33->m_cosAccept0 + v32),
              (__m128)*((unsigned int *)&v33->m_cosAccept0 + v32),
              0)));
  v50 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v48, v5)), v48);
  v51 = _mm_mul_ps(v18, v50);
  v52 = _mm_mul_ps(v51, v51);
  v53 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)), _mm_shuffle_ps(v52, v52, 170));
  v54 = _mm_rsqrt_ps(v53);
  v55 = _mm_mul_ps(
          v51,
          _mm_andnot_ps(
            _mm_cmpleps(v53, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v54, v53), v54)),
              _mm_mul_ps(v54, *(__m128 *)_xmm))));
  v56 = _mm_shuffle_ps(v55, v55, 201);
  v57 = _mm_sub_ps(_mm_mul_ps(v10, v56), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v55));
  v58 = _mm_shuffle_ps(v57, v57, 201);
  v59 = _mm_sub_ps(_mm_mul_ps(v12, v56), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v55));
  v60 = _mm_mul_ps(v11, v56);
  v61 = _mm_mul_ps(v58, v58);
  v62 = _mm_shuffle_ps(v59, v59, 201);
  v63 = _mm_sub_ps(v60, _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v55));
  v64 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v61, v61, 85), _mm_shuffle_ps(v61, v61, 0)), _mm_shuffle_ps(v61, v61, 170));
  v65 = _mm_shuffle_ps(v63, v63, 201);
  v66 = _mm_mul_ps(v62, v62);
  v67 = _mm_mul_ps(v58, _mm_andnot_ps(_mm_cmpleps(v64, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v64))));
  v68 = _mm_mul_ps(v49, v50);
  v69 = _mm_mul_ps(v47, v50);
  v70 = _mm_mul_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps((__m128)0i64, v18),
              _mm_shuffle_ps(
                (__m128)*((unsigned int *)&v46->m_cosAccept0 + v30),
                (__m128)*((unsigned int *)&v46->m_cosAccept0 + v30),
                0)),
            _mm_mul_ps(
              v44,
              _mm_shuffle_ps(
                (__m128)*((unsigned int *)&v46->m_cosAccept0 + v32),
                (__m128)*((unsigned int *)&v46->m_cosAccept0 + v32),
                0))),
          v50);
  v71 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)), _mm_shuffle_ps(v66, v66, 170));
  v72 = _mm_mul_ps(v62, _mm_andnot_ps(_mm_cmpleps(v71, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v71))));
  v73 = _mm_mul_ps(v65, v65);
  v74 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)), _mm_shuffle_ps(v73, v73, 170));
  v75 = _mm_mul_ps(v65, _mm_andnot_ps(_mm_cmpleps(v74, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v74))));
  v76 = _mm_mul_ps(v68, v68);
  v77 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v76, v76, 85), _mm_shuffle_ps(v76, v76, 0)), _mm_shuffle_ps(v76, v76, 170));
  v78 = _mm_mul_ps(v68, _mm_andnot_ps(_mm_cmpleps(v77, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v77))));
  v79 = _mm_mul_ps(v69, v69);
  v80 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v79, v79, 85), _mm_shuffle_ps(v79, v79, 0)), _mm_shuffle_ps(v79, v79, 170));
  v81 = _mm_mul_ps(v69, _mm_andnot_ps(_mm_cmpleps(v80, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v80))));
  v82 = _mm_mul_ps(v70, v70);
  v83 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v82, v82, 85), _mm_shuffle_ps(v82, v82, 0)), _mm_shuffle_ps(v82, v82, 170));
  v84 = _mm_mul_ps(v70, _mm_andnot_ps(_mm_cmpleps(v83, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v83))));
  v85 = _mm_mul_ps(v78, v55);
  v86 = _mm_mul_ps(v78, v67);
  v87 = _mm_mul_ps(v75, v84);
  v88 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v85, v85, 85), _mm_shuffle_ps(v85, v85, 0)), _mm_shuffle_ps(v85, v85, 170));
  v89 = _mm_mul_ps(v81, v55);
  v90 = _mm_mul_ps(v55, v84);
  v91 = _mm_mul_ps(v81, v72);
  v92 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v90, v90, 85), _mm_shuffle_ps(v90, v90, 0)), _mm_shuffle_ps(v90, v90, 170));
  v93 = _mm_rcp_ps(
          _mm_movelh_ps(
            _mm_unpacklo_ps(
              v88,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v89, v89, 85), _mm_shuffle_ps(v89, v89, 0)),
                _mm_shuffle_ps(v89, v89, 170))),
            _mm_unpacklo_ps(v92, v92)));
  v94 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v87, v87, 85), _mm_shuffle_ps(v87, v87, 0)), _mm_shuffle_ps(v87, v87, 170));
  v95 = _mm_cmpleps((__m128)0i64, v93);
  v96 = _mm_movelh_ps(
          _mm_unpacklo_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v86, v86, 85), _mm_shuffle_ps(v86, v86, 0)),
              _mm_shuffle_ps(v86, v86, 170)),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v91, v91, 85), _mm_shuffle_ps(v91, v91, 0)),
              _mm_shuffle_ps(v91, v91, 170))),
          _mm_unpacklo_ps(v94, v94));
  v97 = _mm_mul_ps(v96, v93);
  v98 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v97), _mm_cmpltps(*(__m128 *)_xmm, v97));
  v99 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v97), v98), _mm_andnot_ps(v98, v97));
  v100 = _mm_mul_ps(v99, v99);
  v101 = _mm_mul_ps(
           _mm_rcp_ps(
             _mm_add_ps(
               _mm_mul_ps(
                 _mm_rcp_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_rcp_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v100, *(__m128 *)s0)), *(__m128 *)t0),
                           _mm_add_ps(v100, *(__m128 *)s1))),
                       *(__m128 *)t1),
                     _mm_add_ps(v100, *(__m128 *)s2))),
                 *(__m128 *)t2),
               _mm_add_ps(v100, *(__m128 *)s3))),
           _mm_mul_ps(v99, *(__m128 *)t3));
  v102 = _mm_or_ps(
           _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v99, *(__m128 *)_xmm), *(__m128 *)_xmm), v101), v98),
           _mm_andnot_ps(v98, v101));
  v103 = _mm_or_ps(
           _mm_andnot_ps(v95, _mm_add_ps(_mm_or_ps(_mm_and_ps(v96, *(__m128 *)_xmm), *(__m128 *)_xmm), v102)),
           _mm_and_ps(v102, v95));
  v104 = hkpWeldingUtility::calcEdgeAngleBitcode(COERCE_FLOAT(_mm_shuffle_ps(v103, v103, 85)));
  HIWORD(v105) = HIWORD(v104);
  LOWORD(v105) = 32 * v104;
  v106 = hkpWeldingUtility::calcEdgeAngleBitcode(v103.m128_f32[0]) | v105;
  return v106 | (unsigned int)(hkpWeldingUtility::calcEdgeAngleBitcode(COERCE_FLOAT(_mm_shuffle_ps(v103, v103, 170))) << 10);
}ngleBitcode(COERCE_FLOAT(_mm_shuffle_ps(v103, v103, 170))) << 10);
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
    v2 = (float)((float)(signed int)result * 0.20943952) - 3.1415927;
    if ( angle <= v2 )
      break;
    result = (unsigned int)(result + 1);
    if ( (signed int)result >= 31 )
      return result;
  }
  if ( angle > 0.0 && angle != v2 )
    result = (unsigned int)(result - 1);
  return result;
}


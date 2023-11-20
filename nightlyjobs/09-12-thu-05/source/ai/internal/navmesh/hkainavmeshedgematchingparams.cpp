// File Line: 26
// RVA: 0xB5B4D0
void __fastcall hkaiNavMeshEdgeMatchingParameters::hkaiNavMeshEdgeMatchingParameters(hkaiNavMeshEdgeMatchingParameters *this)
{
  __m128i v1; // xmm6
  __m128 v2; // xmm9
  __m128 v3; // xmm3
  __m128i v4; // xmm7
  __m128i v5; // xmm6
  __m128 v6; // xmm2
  __m128 v7; // xmm5
  __m128 v8; // xmm4
  __m128 v9; // xmm2
  __m128 v10; // xmm9
  __m128i v11; // xmm6
  __m128i v12; // xmm8
  __m128 v13; // xmm2
  __m128i v14; // xmm6
  __m128 v15; // xmm4
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm9
  __m128i v20; // xmm6
  __m128i v21; // xmm8
  __m128 v22; // xmm2
  __m128i v23; // xmm6
  __m128 v24; // xmm5
  __m128 v25; // xmm0
  __m128 v26; // xmm4
  __m128 v27; // xmm2
  __m128i v28; // xmm6
  __m128 v29; // xmm9
  __m128i v30; // xmm8
  __m128 v31; // xmm2
  __m128i v32; // xmm6
  __m128 v33; // xmm4
  __m128 v34; // xmm5
  __m128 v35; // xmm4
  __m128 v36; // xmm2

  this->m_maxStepHeight = 0.5;
  this->m_maxSeparation = 0.1;
  this->m_maxOverhang = 0.0099999998;
  this->m_behindFaceTolerance = 0.000099999997;
  v1 = _mm_load_si128((const __m128i *)_xmm);
  v2 = _mm_add_ps((__m128)0x3DB2B8C3u, *(__m128 *)_xmm);
  v3 = _mm_andnot_ps(*(__m128 *)_xmm, v2);
  v4 = _mm_add_epi32(v1, v1);
  v5 = _mm_andnot_si128(v1, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(*(__m128 *)_xmm, v3)), v1));
  v6 = _mm_cvtepi32_ps(v5);
  v7 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v5, v4), (__m128i)0i64);
  v8 = _mm_add_ps(
         _mm_add_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)DP1_0, v6), v3), _mm_mul_ps(*(__m128 *)DP2, v6)),
         _mm_mul_ps(*(__m128 *)DP3, v6));
  v9 = _mm_mul_ps(v8, v8);
  LODWORD(this->m_cosPlanarAlignmentAngle) = (*(unsigned __int128 *)&_mm_andnot_ps(
                                                                       v7,
                                                                       _mm_add_ps(
                                                                         _mm_sub_ps(
                                                                           _mm_mul_ps(
                                                                             _mm_mul_ps(
                                                                               _mm_add_ps(
                                                                                 _mm_mul_ps(
                                                                                   _mm_add_ps(
                                                                                     _mm_mul_ps(
                                                                                       v9,
                                                                                       *(__m128 *)cosCoeff0_0),
                                                                                     *(__m128 *)cosCoeff1),
                                                                                   v9),
                                                                                 *(__m128 *)cosCoeff2_0),
                                                                               v9),
                                                                             v9),
                                                                           _mm_mul_ps(v9, *(__m128 *)_xmm)),
                                                                         *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                                               (float)((float)((float)((float)((float)((float)(v9.m128_f32[0] * -0.00019515296) + 0.0083321612) * v9.m128_f32[0]) + -0.16666655) * v9.m128_f32[0]) * v8.m128_f32[0])
                                                                                             + v8.m128_f32[0]) & v7.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v4, v4), v5) << 29) ^ _xmm[0] & v2.m128_i32[0];
  v10 = _mm_add_ps((__m128)LODWORD(FLOAT_1_0471976), *(__m128 *)_xmm);
  v11 = _mm_load_si128((const __m128i *)_xmm);
  v12 = _mm_add_epi32(v11, v11);
  v13 = _mm_andnot_ps(*(__m128 *)_xmm, v10);
  v14 = _mm_andnot_si128(v11, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v13, *(__m128 *)_xmm)), v11));
  v15 = _mm_cvtepi32_ps(v14);
  v16 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v14, v12), (__m128i)0i64);
  v17 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v15, *(__m128 *)DP1_0), v13), _mm_mul_ps(v15, *(__m128 *)DP2)),
          _mm_mul_ps(v15, *(__m128 *)DP3));
  v18 = _mm_mul_ps(v17, v17);
  this->m_minEdgeOverlap = 0.02;
  this->m_edgeTraversibilityHorizontalEpsilon = 0.0099999998;
  this->m_edgeTraversibilityVerticalEpsilon = 0.0099999998;
  LODWORD(this->m_cosVerticalAlignmentAngle) = (*(unsigned __int128 *)&_mm_andnot_ps(
                                                                         v16,
                                                                         _mm_add_ps(
                                                                           _mm_sub_ps(
                                                                             _mm_mul_ps(
                                                                               _mm_mul_ps(
                                                                                 _mm_add_ps(
                                                                                   _mm_mul_ps(
                                                                                     _mm_add_ps(
                                                                                       _mm_mul_ps(
                                                                                         v18,
                                                                                         *(__m128 *)cosCoeff0_0),
                                                                                       *(__m128 *)cosCoeff1),
                                                                                     v18),
                                                                                   *(__m128 *)cosCoeff2_0),
                                                                                 v18),
                                                                               v18),
                                                                             _mm_mul_ps(v18, *(__m128 *)_xmm)),
                                                                           *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                                                 (float)((float)((float)((float)((float)((float)(v18.m128_f32[0] * -0.00019515296) + 0.0083321612) * v18.m128_f32[0]) + -0.16666655) * v18.m128_f32[0]) * v17.m128_f32[0])
                                                                                               + v17.m128_f32[0]) & v16.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v12, v12), v14) << 29) ^ v10.m128_i32[0] & _xmm[0];
  v19 = _mm_add_ps((__m128)LODWORD(FLOAT_2_0943952), *(__m128 *)_xmm);
  v20 = _mm_load_si128((const __m128i *)_xmm);
  v21 = _mm_add_epi32(v20, v20);
  v22 = _mm_andnot_ps(*(__m128 *)_xmm, v19);
  v23 = _mm_andnot_si128(v20, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v22, *(__m128 *)_xmm)), v20));
  v24 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v23, v21), (__m128i)0i64);
  v25 = _mm_cvtepi32_ps(v23);
  v26 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v25, *(__m128 *)DP1_0), v22), _mm_mul_ps(v25, *(__m128 *)DP2)),
          _mm_mul_ps(v25, *(__m128 *)DP3));
  v27 = _mm_mul_ps(v26, v26);
  LODWORD(this->m_cosClimbingFaceNormalAlignmentAngle) = (*(unsigned __int128 *)&_mm_andnot_ps(
                                                                                   v24,
                                                                                   _mm_add_ps(
                                                                                     _mm_sub_ps(
                                                                                       _mm_mul_ps(
                                                                                         _mm_mul_ps(
                                                                                           _mm_add_ps(
                                                                                             _mm_mul_ps(
                                                                                               _mm_add_ps(
                                                                                                 _mm_mul_ps(
                                                                                                   v27,
                                                                                                   *(__m128 *)cosCoeff0_0),
                                                                                                 *(__m128 *)cosCoeff1),
                                                                                               v27),
                                                                                             *(__m128 *)cosCoeff2_0),
                                                                                           v27),
                                                                                         v27),
                                                                                       _mm_mul_ps(v27, *(__m128 *)_xmm)),
                                                                                     *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT((float)((float)((float)((float)((float)((float)(v27.m128_f32[0] * -0.00019515296) + 0.0083321612) * v27.m128_f32[0]) + -0.16666655) * v27.m128_f32[0]) * v26.m128_f32[0]) + v26.m128_f32[0]) & v24.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v21, v21), v23) << 29) ^ v19.m128_i32[0] & _xmm[0];
  v28 = _mm_load_si128((const __m128i *)_xmm);
  v29 = _mm_add_ps((__m128)0x3DB2B8C3u, *(__m128 *)_xmm);
  v30 = _mm_add_epi32(v28, v28);
  v31 = _mm_andnot_ps(*(__m128 *)_xmm, v29);
  v32 = _mm_andnot_si128(v28, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v31, *(__m128 *)_xmm)), v28));
  v33 = _mm_cvtepi32_ps(v32);
  v34 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v32, v30), (__m128i)0i64);
  v35 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v33, *(__m128 *)DP1_0), v31), _mm_mul_ps(v33, *(__m128 *)DP2)),
          _mm_mul_ps(v33, *(__m128 *)DP3));
  v36 = _mm_mul_ps(v35, v35);
  this->m_minAngleBetweenFaces = 1.5184364;
  this->m_edgeParallelTolerance = 0.0000099999997;
  LODWORD(this->m_cosClimbingEdgeAlignmentAngle) = (*(unsigned __int128 *)&_mm_andnot_ps(
                                                                             v34,
                                                                             _mm_add_ps(
                                                                               _mm_sub_ps(
                                                                                 _mm_mul_ps(
                                                                                   _mm_mul_ps(
                                                                                     _mm_add_ps(
                                                                                       _mm_mul_ps(
                                                                                         _mm_add_ps(
                                                                                           _mm_mul_ps(
                                                                                             v36,
                                                                                             *(__m128 *)cosCoeff0_0),
                                                                                           *(__m128 *)cosCoeff1),
                                                                                         v36),
                                                                                       *(__m128 *)cosCoeff2_0),
                                                                                     v36),
                                                                                   v36),
                                                                                 _mm_mul_ps(v36, *(__m128 *)_xmm)),
                                                                               *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT((float)((float)((float)((float)((float)((float)(v36.m128_f32[0] * -0.00019515296) + 0.0083321612) * v36.m128_f32[0]) + -0.16666655) * v36.m128_f32[0]) * v35.m128_f32[0]) + v35.m128_f32[0]) & v34.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v30, v30), v32) << 29) ^ v29.m128_i32[0] & _xmm[0];
  this->m_useSafeEdgeTraversibilityHorizontalEpsilon.m_bool = 0;
}


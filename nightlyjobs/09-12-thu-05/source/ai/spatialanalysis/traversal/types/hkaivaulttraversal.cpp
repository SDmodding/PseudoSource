// File Line: 25
// RVA: 0xC37E70
void __fastcall hkaiVaultAnalyzer::analyze(hkaiVaultAnalyzer *this, hkaiTraversalAnalysisContext *context)
{
  __m128i si128; // xmm3
  float m_maxPlanarAngle; // xmm8_4
  hkaiTraversalAnalysisSettings *m_settings; // rax
  __m128 v7; // xmm7
  __m128 v8; // xmm2
  int v9; // xmm0_4
  float m_maxWallWidth; // xmm0_4
  __m128i v11; // xmm6
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm4
  __m128 v15; // xmm3
  __m128 v16; // xmm11
  __m128i v17; // xmm3
  __m128i v18; // xmm6
  __m128 v19; // xmm2
  __m128i v20; // xmm6
  __m128 v21; // xmm5
  __m128 v22; // xmm0
  __m128 v23; // xmm4
  __m128 v24; // xmm2
  __m128i v25; // xmm4
  __m128i v26; // xmm7
  hkaiPairedEdgeFinder *m_pntr; // rcx
  __m128 v28; // xmm6
  __m128 v29; // xmm2
  __m128i v30; // xmm7
  __m128 v31; // xmm5
  __m128 v32; // xmm0
  __m128 v33; // xmm4
  __m128 v34; // xmm2
  __m128i v35; // xmm1
  hkVector4f *v36; // r9
  __m128 m_minWallHeight_low; // xmm0
  __m128 v38; // xmm9
  __m128 v39; // xmm11
  __m128i v40; // xmm5
  hkaiTraversalAnalysisSettings *v41; // rax
  __int64 m_size; // rbx
  __m128 v43; // xmm1
  __m128 v44; // xmm8
  __m128i v45; // xmm7
  __m128 v46; // xmm8
  __m128 m_maxWallHeight_low; // xmm0
  __m128 v48; // xmm2
  __m128i v49; // xmm5
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 v52; // xmm3
  __m128 v53; // xmm2
  __m128 v54; // xmm10
  float v55; // xmm10_4
  float v56; // xmm15_4
  __int64 v57; // r14
  hkaiPairedEdgeFinder::EdgePair *m_data; // r15
  hkaiNavMeshInstance *m_fromNavMeshInstance; // rcx
  hkVector4f *v60; // r9
  __m128 v61; // xmm8
  __m128 v62; // xmm7
  __m128 v63; // xmm14
  __m128 v64; // xmm5
  __m128 v65; // xmm4
  __m128 v66; // xmm2
  __m128 v67; // xmm3
  __m128 v68; // xmm14
  __m128 v69; // xmm7
  __m128 v70; // xmm5
  __m128 v71; // xmm5
  __m128 v72; // xmm1
  __m128 v73; // xmm3
  __m128 v74; // xmm2
  __m128 v75; // xmm1
  __m128 v76; // xmm7
  __m128 v77; // xmm1
  __m128 v78; // xmm2
  __m128 v79; // xmm1
  __m128 v80; // xmm9
  __m128 v81; // xmm11
  int v82; // esi
  hkaiIntervalPartition::Interval *Interval; // rbx
  __m128 v84; // xmm5
  __m128 v85; // xmm0
  __m128 v86; // xmm5
  __m128 v87; // xmm2
  __m128 v88; // xmm1
  __m128 v89; // xmm4
  __m128 v90; // xmm6
  __m128 v91; // xmm2
  __m128 v92; // xmm4
  __m128 v93; // xmm4
  __m128 v94; // xmm6
  float Extreme; // xmm0_4
  int v96; // r12d
  hkVector4f *v97; // rdx
  int m_capacityAndFlags; // r8d
  __m128 m_minEdgeLength_low; // xmm0
  __m128 v100; // xmm0
  __m128 v101; // xmm6
  __m128 v102; // xmm11
  __m128 v103; // xmm10
  __m128 v104; // xmm12
  __m128 v105; // xmm12
  __m128 v106; // xmm1
  __m128 v107; // xmm3
  __m128 v108; // xmm2
  __m128 v109; // xmm12
  __m128 v110; // xmm2
  __m128 v111; // xmm8
  __m128 v112; // xmm0
  __m128 v113; // xmm7
  __m128 v114; // xmm7
  __m128 v115; // xmm1
  __m128 v116; // xmm3
  __m128 v117; // xmm2
  __m128 v118; // xmm7
  __m128 v119; // xmm2
  __m128 v120; // xmm12
  __m128 v121; // xmm12
  __m128 v122; // xmm1
  __m128 v123; // xmm3
  __m128 v124; // xmm2
  __m128 v125; // xmm12
  __m128 v126; // xmm3
  __m128 v127; // xmm4
  __m128 v128; // xmm2
  __m128 v129; // xmm10
  __m128 v130; // xmm1
  __m128 v131; // xmm12
  __m128 v132; // xmm1
  __m128 v133; // xmm3
  __m128 v134; // xmm2
  __m128 v135; // xmm12
  __m128 v136; // xmm1
  __m128 v137; // xmm2
  __m128 v138; // xmm1
  int v139; // esi
  float v140; // xmm13_4
  __m128 v141; // xmm15
  unsigned int *v142; // rax
  int v143; // xmm1_4
  __m128 v144; // xmm3
  __m128 v145; // xmm4
  int v146; // xmm0_4
  __m128 v147; // xmm4
  __m128 v148; // xmm0
  __m128 v149; // xmm8
  __m128 v150; // xmm9
  __m128 v151; // xmm2
  __m128 v152; // xmm2
  __m128 v153; // xmm0
  __m128 v154; // xmm6
  __m128 v155; // xmm7
  hkaiNavMeshInstance *v156; // rax
  unsigned int m_userdata; // r9d
  __m128 v158; // xmm2
  __m128 v159; // xmm1
  unsigned int m_sectionUid; // ecx
  hkaiNavMeshInstance *m_toNavMeshInstance; // rax
  unsigned int v162; // ecx
  hkaiTraversalAnnotationLibrary *m_outputLibrary; // rcx
  unsigned int v164; // ebx
  __m128 v165; // xmm2
  __m128 v166; // xmm2
  hkaiIntervalPartition clearZonesOut; // [rsp+50h] [rbp-A8h] BYREF
  hkaiIntervalPartition partition; // [rsp+60h] [rbp-98h] BYREF
  char uPartition[24]; // [rsp+70h] [rbp-88h] BYREF
  hkaiIntervalPartition other; // [rsp+88h] [rbp-70h] BYREF
  hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> pairsOut; // [rsp+98h] [rbp-60h] BYREF
  hkaiIntervalPartition intervalPartition; // [rsp+A8h] [rbp-50h] BYREF
  hkVector4f rightInOut; // [rsp+B8h] [rbp-40h] BYREF
  hkVector4f vVector; // [rsp+C8h] [rbp-30h] BYREF
  hkVector4f leftEnd; // [rsp+D8h] [rbp-20h] BYREF
  hkVector4f leftInOut; // [rsp+E8h] [rbp-10h] BYREF
  hkVector4f rightEnd; // [rsp+F8h] [rbp+0h] BYREF
  __m128 v178; // [rsp+108h] [rbp+10h] BYREF
  int v179; // [rsp+118h] [rbp+20h]
  hkVector4f uVector; // [rsp+128h] [rbp+30h] BYREF
  hkVector4f left; // [rsp+138h] [rbp+40h] BYREF
  __m128 v182; // [rsp+148h] [rbp+50h]
  hkVector4f right; // [rsp+158h] [rbp+60h] BYREF
  __m128 v184; // [rsp+168h] [rbp+70h]
  hkaiPairedEdgeFinder::PairedEdgeSettings settings; // [rsp+178h] [rbp+80h] BYREF
  __m128 v186; // [rsp+1B8h] [rbp+C0h]
  hkArrayBase<hkVector4f> clippingPlanes; // [rsp+1C8h] [rbp+D0h] BYREF
  __int128 v188[6]; // [rsp+1D8h] [rbp+E0h] BYREF
  hkaiUserEdgeUtils::UserEdgePair userEdgePair; // [rsp+238h] [rbp+140h] BYREF
  hkVector4f facePlane; // [rsp+288h] [rbp+190h] BYREF
  __m128 v191; // [rsp+298h] [rbp+1A0h]
  hkVector4f leftStart; // [rsp+2A8h] [rbp+1B0h] BYREF
  __m128 v193; // [rsp+2B8h] [rbp+1C0h]
  hkVector4f v194; // [rsp+2C8h] [rbp+1D0h] BYREF
  __m128 v195; // [rsp+2D8h] [rbp+1E0h]
  hkVector4f v196; // [rsp+2E8h] [rbp+1F0h] BYREF
  __m128 v197; // [rsp+2F8h] [rbp+200h]
  __m128 v198; // [rsp+308h] [rbp+210h]
  __m128 faceIndex; // [rsp+318h] [rbp+220h] BYREF
  hkVector4f v200; // [rsp+328h] [rbp+230h] BYREF
  hkVector4f extremalVector; // [rsp+338h] [rbp+240h] BYREF
  hkVector4f v202; // [rsp+348h] [rbp+250h] BYREF
  hkVector4f extrusion; // [rsp+358h] [rbp+260h] BYREF
  hkVector4f v204; // [rsp+368h] [rbp+270h] BYREF
  hkVector4f displacement; // [rsp+378h] [rbp+280h] BYREF
  __m128 v206; // [rsp+388h] [rbp+290h]
  hkVector4f rightStart; // [rsp+398h] [rbp+2A0h] BYREF
  void *retaddr; // [rsp+498h] [rbp+3A0h]
  float newX2; // [rsp+4A0h] [rbp+3A8h]
  float v210; // [rsp+4A4h] [rbp+3ACh]
  float newX1; // [rsp+4A8h] [rbp+3B0h]
  float v212; // [rsp+4ACh] [rbp+3B4h]
  __int64 v213; // [rsp+4B0h] [rbp+3B8h]

  vVector.m_quad = (__m128)context->m_settings->m_up;
  hkaiPairedEdgeFinder::PairedEdgeSettings::PairedEdgeSettings(&settings);
  si128 = _mm_load_si128((const __m128i *)_xmm);
  m_maxPlanarAngle = this->m_maxPlanarAngle;
  m_settings = context->m_settings;
  v7 = _mm_add_ps((__m128)LODWORD(m_maxPlanarAngle), *(__m128 *)_xmm);
  v8 = _mm_andnot_ps(*(__m128 *)_xmm, v7);
  settings.m_up = (hkVector4f)vVector.m_quad;
  v9 = LODWORD(this->m_maxDownHeight) ^ _xmm[0];
  settings.m_minLength = m_settings->m_minEdgeLength;
  settings.m_minHorizontalDelta = this->m_minWallWidth;
  LODWORD(settings.m_minHeightDelta) = v9;
  settings.m_maxHeightDelta = this->m_maxUpHeight;
  m_maxWallWidth = this->m_maxWallWidth;
  *(__m128i *)&uPartition[8] = _mm_add_epi32(si128, si128);
  settings.m_maxHorizontalDelta = m_maxWallWidth;
  v11 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v8, *(__m128 *)_xmm)), si128));
  v12 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v11, *(__m128i *)&uPartition[8]), (__m128i)0i64);
  v13 = _mm_cvtepi32_ps(v11);
  v14 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v13, *(__m128 *)DP1_0), v8), _mm_mul_ps(v13, *(__m128 *)DP2)),
          _mm_mul_ps(v13, *(__m128 *)DP3));
  v15 = _mm_mul_ps(v14, v14);
  v16 = *(__m128 *)sinCoeff0;
  v8.m128_f32[0] = _mm_andnot_ps(
                     v12,
                     _mm_add_ps(
                       _mm_sub_ps(
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_add_ps(_mm_mul_ps(v15, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1),
                                 v15),
                               *(__m128 *)cosCoeff2_0),
                             v15),
                           v15),
                         _mm_mul_ps(v15, *(__m128 *)_xmm)),
                       *(__m128 *)_xmm)).m128_f32[0];
  v13.m128_f32[0] = (float)((float)((float)((float)(v15.m128_f32[0] * -0.00019515296) + 0.0083321612) * v15.m128_f32[0])
                          + -0.16666655)
                  * v15.m128_f32[0];
  v17 = _mm_load_si128((const __m128i *)&uPartition[8]);
  v8.m128_i32[0] |= COERCE_UNSIGNED_INT((float)(v13.m128_f32[0] * v14.m128_f32[0]) + v14.m128_f32[0]) & v12.m128_i32[0];
  v13.m128_i32[0] = _mm_and_si128(_mm_add_epi32(v17, v17), v11).m128i_u32[0];
  v18 = _mm_load_si128((const __m128i *)_xmm);
  LODWORD(settings.m_cosMaxPlanarAngle) = v8.m128_i32[0] ^ (v13.m128_i32[0] << 29) ^ v7.m128_i32[0] & _xmm[0];
  v19 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(m_maxPlanarAngle));
  v20 = _mm_andnot_si128(v18, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v19, *(__m128 *)_xmm)), v18));
  v21 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v20, v17), (__m128i)0i64);
  v22 = _mm_cvtepi32_ps(v20);
  v23 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v22, *(__m128 *)DP1_0), v19), _mm_mul_ps(v22, *(__m128 *)DP2)),
          _mm_mul_ps(v22, *(__m128 *)DP3));
  v24 = _mm_mul_ps(v23, v23);
  v22.m128_f32[0] = (float)((float)((float)((float)((float)((float)(v24.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                                  * v24.m128_f32[0])
                                          + -0.16666655)
                                  * v24.m128_f32[0])
                          * v23.m128_f32[0])
                  + v23.m128_f32[0];
  v25 = _mm_load_si128((const __m128i *)&uPartition[8]);
  LODWORD(settings.m_sinMaxPlanarAngle) = (_mm_andnot_ps(
                                             v21,
                                             _mm_add_ps(
                                               _mm_sub_ps(
                                                 _mm_mul_ps(
                                                   _mm_mul_ps(
                                                     _mm_add_ps(
                                                       _mm_mul_ps(
                                                         _mm_add_ps(
                                                           _mm_mul_ps(v24, *(__m128 *)cosCoeff0_0),
                                                           *(__m128 *)cosCoeff1),
                                                         v24),
                                                       *(__m128 *)cosCoeff2_0),
                                                     v24),
                                                   v24),
                                                 _mm_mul_ps(v24, *(__m128 *)_xmm)),
                                               *(__m128 *)_xmm)).m128_u32[0] | v22.m128_i32[0] & v21.m128_i32[0]) ^ (_mm_and_si128(_mm_add_epi32(v25, v25), v20).m128i_u32[0] << 29) ^ LODWORD(m_maxPlanarAngle) & _xmm[0];
  v26 = _mm_load_si128((const __m128i *)_xmm);
  m_pntr = context->m_pairedEdgeFinder.m_pntr;
  v28 = _mm_add_ps((__m128)LODWORD(this->m_maxRelativeSlopeAngle), *(__m128 *)_xmm);
  settings.m_matchAngles.m_bool = 1;
  pairsOut.m_capacityAndFlags = 0x80000000;
  pairsOut.m_data = 0i64;
  pairsOut.m_size = 0;
  v29 = _mm_andnot_ps(*(__m128 *)_xmm, v28);
  v30 = _mm_andnot_si128(v26, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v29, *(__m128 *)_xmm)), v26));
  v31 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v30, v25), (__m128i)0i64);
  v32 = _mm_cvtepi32_ps(v30);
  v33 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v32, *(__m128 *)DP1_0), v29), _mm_mul_ps(v32, *(__m128 *)DP2)),
          _mm_mul_ps(v32, *(__m128 *)DP3));
  v34 = _mm_mul_ps(v33, v33);
  v35 = _mm_load_si128((const __m128i *)&uPartition[8]);
  LODWORD(settings.m_cosMaxDeltaSlopeAngle) = (_mm_andnot_ps(
                                                 v31,
                                                 _mm_add_ps(
                                                   _mm_sub_ps(
                                                     _mm_mul_ps(
                                                       _mm_mul_ps(
                                                         _mm_add_ps(
                                                           _mm_mul_ps(
                                                             _mm_add_ps(
                                                               _mm_mul_ps(v34, *(__m128 *)cosCoeff0_0),
                                                               *(__m128 *)cosCoeff1),
                                                             v34),
                                                           *(__m128 *)cosCoeff2_0),
                                                         v34),
                                                       v34),
                                                     _mm_mul_ps(v34, *(__m128 *)_xmm)),
                                                   *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                                                     (float)((float)((float)((float)((float)((float)(v34.m128_f32[0] * -0.00019515296) + 0.0083321612) * v34.m128_f32[0]) + -0.16666655) * v34.m128_f32[0])
                                                                                           * v33.m128_f32[0])
                                                                                   + v33.m128_f32[0]) & v31.m128_i32[0]) ^ (_mm_and_si128(_mm_add_epi32(v35, v35), v30).m128i_u32[0] << 29) ^ v28.m128_i32[0] & _xmm[0];
  hkaiPairedEdgeFinder::findEdgePairs(m_pntr, &settings, &pairsOut);
  v16.m128_f32[0] = this->m_minWallWidth * 0.5;
  m_minWallHeight_low = (__m128)LODWORD(this->m_minWallHeight);
  v38 = _mm_mul_ps(
          _mm_shuffle_ps((__m128)LODWORD(this->m_maxWallHeight), (__m128)LODWORD(this->m_maxWallHeight), 0),
          vVector.m_quad);
  v39 = _mm_shuffle_ps(v16, v16, 0);
  m_minWallHeight_low.m128_f32[0] = m_minWallHeight_low.m128_f32[0] - this->m_maxWallHeight;
  v186 = v39;
  v184 = v38;
  v40 = _mm_load_si128((const __m128i *)_xmm);
  v41 = context->m_settings;
  m_size = pairsOut.m_size;
  v43 = _mm_mul_ps(_mm_shuffle_ps(m_minWallHeight_low, m_minWallHeight_low, 0), vVector.m_quad);
  m_minWallHeight_low.m128_i32[0] = LODWORD(this->m_verticalApex) ^ _xmm[0];
  v44 = _mm_shuffle_ps((__m128)LODWORD(this->m_handPlantAngle), (__m128)LODWORD(this->m_handPlantAngle), 0);
  v45 = _mm_add_epi32(v40, v40);
  displacement.m_quad = v43;
  v46 = _mm_add_ps(v44, *(__m128 *)offset_1);
  v43.m128_f32[0] = m_minWallHeight_low.m128_f32[0];
  v198 = _mm_shuffle_ps((__m128)LODWORD(this->m_minWallHeight), (__m128)LODWORD(this->m_minWallHeight), 0);
  m_maxWallHeight_low = (__m128)LODWORD(this->m_maxWallHeight);
  v200.m_quad = _mm_mul_ps(_mm_shuffle_ps(v43, v43, 0), vVector.m_quad);
  v48 = _mm_andnot_ps(*(__m128 *)_xmm, v46);
  v206 = _mm_shuffle_ps(m_maxWallHeight_low, m_maxWallHeight_low, 0);
  v182 = _mm_shuffle_ps((__m128)LODWORD(v41->m_characterRadius), (__m128)LODWORD(v41->m_characterRadius), 0);
  v49 = _mm_andnot_si128(v40, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v48, *(__m128 *)_xmm)), v40));
  v50 = _mm_cvtepi32_ps(v49);
  v51 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v49, v45), (__m128i)0i64);
  v52 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v50, *(__m128 *)DP1_0), v48), _mm_mul_ps(v50, *(__m128 *)DP2)),
          _mm_mul_ps(v50, *(__m128 *)DP3));
  v53 = _mm_mul_ps(v52, v52);
  v54 = _mm_xor_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              v51,
              _mm_add_ps(
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v53, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v53),
                        *(__m128 *)cosCoeff2_0),
                      v53),
                    v53),
                  _mm_mul_ps(v53, *(__m128 *)_xmm)),
                *(__m128 *)_xmm)),
            _mm_and_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v53, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v53),
                      *(__m128 *)sinCoeff2_0),
                    v53),
                  v52),
                v52),
              v51)),
          _mm_xor_ps(
            (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v45, v45), v49), 0x1Du),
            _mm_and_ps(v46, *(__m128 *)_xmm)));
  v195 = _mm_shuffle_ps(v54, v54, 85);
  v193 = _mm_shuffle_ps(v54, v54, 0);
  v213 = pairsOut.m_size;
  if ( pairsOut.m_size > 0 )
  {
    v55 = *(float *)&FLOAT_1_0;
    v56 = FLOAT_0_0099999998;
    v57 = 0i64;
    do
    {
      m_data = pairsOut.m_data;
      m_fromNavMeshInstance = context->m_fromNavMeshInstance;
      leftInOut.m_quad = (__m128)pairsOut.m_data[v57].m_startLeft;
      rightInOut.m_quad = (__m128)pairsOut.m_data[v57].m_startRight;
      leftEnd.m_quad = (__m128)pairsOut.m_data[v57].m_endLeft;
      rightEnd.m_quad = (__m128)pairsOut.m_data[v57].m_endRight;
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)m_fromNavMeshInstance,
        (hkaiNavMeshInstance *)(unsigned int)pairsOut.m_data[v57].m_startFace,
        &faceIndex,
        v36);
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)context->m_toNavMeshInstance,
        (hkaiNavMeshInstance *)(unsigned int)m_data[v57].m_endFace,
        &facePlane.m_quad,
        v60);
      hkaiTraversalAnalysisUtils::setBackEdge(&leftInOut, &rightInOut, (hkVector4f *)&faceIndex, context);
      hkaiTraversalAnalysisUtils::setBackEdge(&rightEnd, &leftEnd, &facePlane, context);
      hkaiIntervalPartition::hkaiIntervalPartition(&clearZonesOut);
      hkaiTraversalAnalysisUtils::filterUnwalkableLandingZones(
        &leftInOut,
        &rightInOut,
        &leftEnd,
        &rightEnd,
        m_data[v57].m_startFace,
        m_data[v57].m_endFace,
        &clearZonesOut,
        context);
      if ( clearZonesOut.m_intervals.m_size
        && hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&leftInOut, &rightInOut, context)
        && hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&rightEnd, &leftEnd, context) )
      {
        v61 = 0i64;
        v62 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(rightEnd.m_quad, rightInOut.m_quad), (__m128)xmmword_141A711B0),
                rightInOut.m_quad);
        v63 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(leftEnd.m_quad, leftInOut.m_quad), (__m128)xmmword_141A711B0),
                leftInOut.m_quad);
        v64 = _mm_mul_ps(rightInOut.m_quad, vVector.m_quad);
        v65 = _mm_mul_ps(leftInOut.m_quad, vVector.m_quad);
        v66 = _mm_mul_ps(v63, vVector.m_quad);
        v67 = _mm_mul_ps(v62, vVector.m_quad);
        v68 = _mm_add_ps(
                _mm_sub_ps(
                  v63,
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)),
                      _mm_shuffle_ps(v66, v66, 170)),
                    vVector.m_quad)),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
                    _mm_shuffle_ps(v65, v65, 170)),
                  vVector.m_quad));
        v69 = _mm_add_ps(
                _mm_sub_ps(
                  v62,
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)),
                      _mm_shuffle_ps(v67, v67, 170)),
                    vVector.m_quad)),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
                    _mm_shuffle_ps(v64, v64, 170)),
                  vVector.m_quad));
        v191 = _mm_sub_ps(v69, v68);
        v70 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v191, v191, 201), vVector.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(vVector.m_quad, vVector.m_quad, 201), v191));
        v71 = _mm_shuffle_ps(v70, v70, 201);
        v72 = _mm_mul_ps(v71, v71);
        v73 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v72, v72, 0)),
                _mm_shuffle_ps(v72, v72, 170));
        v74 = _mm_rsqrt_ps(v73);
        uVector.m_quad = _mm_mul_ps(
                           v71,
                           _mm_andnot_ps(
                             _mm_cmple_ps(v73, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v74, v73), v74)),
                               _mm_mul_ps(v74, *(__m128 *)_xmm))));
        v75 = _mm_mul_ps(uVector.m_quad, v39);
        v76 = _mm_add_ps(_mm_sub_ps(v69, v75), v38);
        leftStart.m_quad = _mm_add_ps(_mm_sub_ps(v68, v75), v38);
        rightStart.m_quad = v76;
        extrusion.m_quad = _mm_mul_ps(
                             _mm_shuffle_ps(
                               (__m128)LODWORD(this->m_minWallWidth),
                               (__m128)LODWORD(this->m_minWallWidth),
                               0),
                             uVector.m_quad);
        hkaiIntervalPartition::hkaiIntervalPartition(&partition);
        hkaiGeometrySegmentCaster::castSegmentExtruded(
          context->m_cuttingGeometrySegmentCaster.m_pntr,
          &leftStart,
          &rightStart,
          &displacement,
          &extrusion,
          &partition);
        if ( partition.m_intervals.m_size )
        {
          hkaiIntervalPartition::remapY(&partition, 0.0, v55, this->m_maxWallHeight, this->m_minWallHeight);
          v77 = _mm_mul_ps(leftEnd.m_quad, vVector.m_quad);
          v78 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v77, v77, 85), _mm_shuffle_ps(v77, v77, 0)),
                  _mm_shuffle_ps(v77, v77, 170));
          v79 = _mm_mul_ps(rightEnd.m_quad, vVector.m_quad);
          v80 = _mm_sub_ps(leftEnd.m_quad, _mm_mul_ps(v78, vVector.m_quad));
          v81 = _mm_sub_ps(
                  rightEnd.m_quad,
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v79, v79, 85), _mm_shuffle_ps(v79, v79, 0)),
                      _mm_shuffle_ps(v79, v79, 170)),
                    vVector.m_quad));
          hkaiIntervalPartition::hkaiIntervalPartition((hkaiIntervalPartition *)uPartition);
          v82 = 0;
          if ( partition.m_intervals.m_size > 0 )
          {
            do
            {
              Interval = hkaiIntervalPartition::getInterval(&partition, v82);
              hkaiIntervalPartition::Interval::getLeftEndpoint(Interval);
              hkaiIntervalPartition::Interval::getRightEndpoint(Interval);
              if ( (float)(newX2 - newX1) >= v56 )
              {
                v85 = (__m128)LODWORD(v212);
                v84.m128_f32[0] = newX1;
                v85.m128_f32[0] = v212 + v56;
                v76.m128_f32[0] = newX2;
                v86 = _mm_shuffle_ps(v84, v84, 0);
                v76 = _mm_shuffle_ps(v76, v76, 0);
                v87 = _mm_sub_ps(rightInOut.m_quad, leftInOut.m_quad);
                v88 = _mm_mul_ps(_mm_shuffle_ps(v85, v85, 0), vVector.m_quad);
                v89 = _mm_add_ps(_mm_mul_ps(v86, v87), leftInOut.m_quad);
                v90 = _mm_add_ps(_mm_mul_ps(v76, v87), leftInOut.m_quad);
                v91 = _mm_sub_ps(v81, v80);
                v92 = _mm_add_ps(v89, v88);
                v88.m128_f32[0] = v210 + v56;
                v202.m_quad = v92;
                v93 = _mm_mul_ps(v92, vVector.m_quad);
                v196.m_quad = _mm_add_ps(v90, _mm_mul_ps(_mm_shuffle_ps(v88, v88, 0), vVector.m_quad));
                v94 = _mm_mul_ps(v196.m_quad, vVector.m_quad);
                v204.m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v93, v93, 85), _mm_shuffle_ps(v93, v93, 0)),
                                    _mm_shuffle_ps(v93, v93, 170)),
                                  vVector.m_quad),
                                _mm_add_ps(_mm_mul_ps(v91, v86), v80));
                v194.m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v94, v94, 85), _mm_shuffle_ps(v94, v94, 0)),
                                    _mm_shuffle_ps(v94, v94, 170)),
                                  vVector.m_quad),
                                _mm_add_ps(_mm_mul_ps(v91, v76), v80));
                hkaiIntervalPartition::hkaiIntervalPartition(&other);
                hkaiGeometrySegmentCaster::turnSegmentExtruded(
                  context->m_cuttingGeometrySegmentCaster.m_pntr,
                  &v202,
                  &v196,
                  &v204,
                  &v194,
                  &v200,
                  &other);
                hkaiIntervalPartition::remapX(&other, 0.0, v55, newX1, newX2);
                if ( *(_DWORD *)&uPartition[8] )
                {
                  Extreme = hkaiIntervalPartition::getExtremeX<1>((hkaiIntervalPartition *)uPartition);
                  hkaiIntervalPartition::clipX(&other, Extreme, v55);
                }
                hkaiIntervalPartition::appendPartition((hkaiIntervalPartition *)uPartition, &other);
                other.m_intervals.m_size = 0;
                if ( other.m_intervals.m_capacityAndFlags >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    &hkContainerHeapAllocator::s_alloc,
                    other.m_intervals.m_data,
                    20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
                other.m_intervals.m_data = 0i64;
                other.m_intervals.m_capacityAndFlags = 0x80000000;
              }
              ++v82;
            }
            while ( v82 < partition.m_intervals.m_size );
            m_size = v213;
            v61 = 0i64;
          }
          hkaiIntervalPartition::complement((hkaiIntervalPartition *)uPartition, 0.0, v55);
          hkaiIntervalPartition::clipNotDefined((hkaiIntervalPartition *)uPartition, &partition);
          hkaiIntervalPartition::clipNotDefined((hkaiIntervalPartition *)uPartition, &clearZonesOut);
          v96 = *(_DWORD *)&uPartition[8];
          if ( *(_DWORD *)&uPartition[8] )
          {
            v97 = (hkVector4f *)v188;
            m_capacityAndFlags = -2147483642;
            m_minEdgeLength_low = (__m128)LODWORD(context->m_settings->m_minEdgeLength);
            clippingPlanes.m_size = 6;
            clippingPlanes.m_capacityAndFlags = -2147483642;
            clippingPlanes.m_data = (hkVector4f *)v188;
            v100 = _mm_shuffle_ps(m_minEdgeLength_low, m_minEdgeLength_low, 0);
            v101 = _mm_shuffle_ps(vVector.m_quad, vVector.m_quad, 201);
            v102 = _mm_sub_ps(rightInOut.m_quad, leftInOut.m_quad);
            v197 = _mm_mul_ps(v100, v100);
            v103 = _mm_shuffle_ps(v102, v102, 201);
            v104 = _mm_sub_ps(_mm_mul_ps(v102, v101), _mm_mul_ps(v103, vVector.m_quad));
            v105 = _mm_shuffle_ps(v104, v104, 201);
            v106 = _mm_mul_ps(v105, v105);
            v107 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v106, v106, 85), _mm_shuffle_ps(v106, v106, 0)),
                     _mm_shuffle_ps(v106, v106, 170));
            v108 = _mm_rsqrt_ps(v107);
            v109 = _mm_mul_ps(
                     v105,
                     _mm_andnot_ps(
                       _mm_cmple_ps(v107, v61),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v108, v107), v108)),
                         _mm_mul_ps(v108, *(__m128 *)_xmm))));
            v110 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v109, v182), leftInOut.m_quad), v109);
            v111 = _mm_shuffle_ps(
                     v109,
                     _mm_unpackhi_ps(
                       v109,
                       _mm_sub_ps(
                         v61,
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v110, v110, 85), _mm_shuffle_ps(v110, v110, 0)),
                           _mm_shuffle_ps(v110, v110, 170)))),
                     196);
            v112 = _mm_sub_ps(rightEnd.m_quad, leftEnd.m_quad);
            v113 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v112, v112, 201), vVector.m_quad), _mm_mul_ps(v112, v101));
            v114 = _mm_shuffle_ps(v113, v113, 201);
            v115 = _mm_mul_ps(v114, v114);
            v116 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), _mm_shuffle_ps(v115, v115, 0)),
                     _mm_shuffle_ps(v115, v115, 170));
            v117 = _mm_rsqrt_ps(v116);
            v188[0] = (__int128)v111;
            v118 = _mm_mul_ps(
                     v114,
                     _mm_andnot_ps(
                       _mm_cmple_ps(v116, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v117, v116), v117)),
                         _mm_mul_ps(v117, *(__m128 *)_xmm))));
            v119 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v118, v182), leftEnd.m_quad), v118);
            v188[1] = (__int128)_mm_shuffle_ps(
                                  v118,
                                  _mm_unpackhi_ps(
                                    v118,
                                    _mm_sub_ps(
                                      (__m128)0i64,
                                      _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v119, v119, 85), _mm_shuffle_ps(v119, v119, 0)),
                                        _mm_shuffle_ps(v119, v119, 170)))),
                                  196);
            v120 = _mm_sub_ps(_mm_mul_ps(v109, v103), _mm_mul_ps(_mm_shuffle_ps(v109, v109, 201), v102));
            v121 = _mm_shuffle_ps(v120, v120, 201);
            v122 = _mm_mul_ps(v121, v121);
            v123 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v122, v122, 85), _mm_shuffle_ps(v122, v122, 0)),
                     _mm_shuffle_ps(v122, v122, 170));
            v124 = _mm_rsqrt_ps(v123);
            v125 = _mm_mul_ps(
                     v121,
                     _mm_andnot_ps(
                       _mm_cmple_ps(v123, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v124, v123), v124)),
                         _mm_mul_ps(v124, *(__m128 *)_xmm))));
            v178 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
            v126 = _mm_xor_ps(v125, v178);
            v127 = _mm_mul_ps(v125, _mm_add_ps(_mm_mul_ps(v206, vVector.m_quad), leftInOut.m_quad));
            v128 = _mm_mul_ps(v126, _mm_add_ps(_mm_mul_ps(v198, vVector.m_quad), leftInOut.m_quad));
            v129 = v191;
            v188[2] = (__int128)_mm_shuffle_ps(
                                  v126,
                                  _mm_unpackhi_ps(
                                    v126,
                                    _mm_sub_ps(
                                      (__m128)0i64,
                                      _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v128, v128, 85), _mm_shuffle_ps(v128, v128, 0)),
                                        _mm_shuffle_ps(v128, v128, 170)))),
                                  196);
            v130 = _mm_mul_ps(v191, vVector.m_quad);
            v188[3] = (__int128)_mm_shuffle_ps(
                                  v125,
                                  _mm_unpackhi_ps(
                                    v125,
                                    _mm_sub_ps(
                                      (__m128)0i64,
                                      _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v127, v127, 85), _mm_shuffle_ps(v127, v127, 0)),
                                        _mm_shuffle_ps(v127, v127, 170)))),
                                  196);
            v131 = _mm_sub_ps(
                     v191,
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v130, v130, 85), _mm_shuffle_ps(v130, v130, 0)),
                         _mm_shuffle_ps(v130, v130, 170)),
                       vVector.m_quad));
            v132 = _mm_mul_ps(v131, v131);
            v133 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v132, v132, 85), _mm_shuffle_ps(v132, v132, 0)),
                     _mm_shuffle_ps(v132, v132, 170));
            v134 = _mm_rsqrt_ps(v133);
            v135 = _mm_mul_ps(
                     v131,
                     _mm_andnot_ps(
                       _mm_cmple_ps(v133, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v134, v133), v134)),
                         _mm_mul_ps(v134, *(__m128 *)_xmm))));
            v136 = _mm_mul_ps(uVector.m_quad, uVector.m_quad);
            v137 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v136, v136, 85), _mm_shuffle_ps(v136, v136, 0)),
                     _mm_shuffle_ps(v136, v136, 170));
            v138 = _mm_rsqrt_ps(v137);
            extremalVector.m_quad = _mm_sub_ps(
                                      _mm_mul_ps(v195, vVector.m_quad),
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_andnot_ps(
                                            _mm_cmple_ps(v137, (__m128)0i64),
                                            _mm_mul_ps(
                                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v138, v137), v138)),
                                              _mm_mul_ps(v138, *(__m128 *)_xmm))),
                                          uVector.m_quad),
                                        v193));
            v139 = 0;
            if ( *(int *)&uPartition[8] > 0 )
            {
              v140 = v197.m128_f32[0];
              v141 = (__m128)_mm_load_si128((const __m128i *)&v178);
              do
              {
                v142 = (unsigned int *)hkaiIntervalPartition::getInterval((hkaiIntervalPartition *)uPartition, v139);
                v143 = v142[3];
                v144 = _mm_shuffle_ps((__m128)*v142, (__m128)*v142, 0);
                v145 = (__m128)v142[1];
                v178.m128_i32[2] = v142[2];
                v146 = v142[4];
                v147 = _mm_shuffle_ps(v145, v145, 0);
                v178.m128_i32[3] = v143;
                v179 = v146;
                v148 = _mm_sub_ps(rightInOut.m_quad, leftInOut.m_quad);
                v149 = _mm_add_ps(_mm_mul_ps(v144, v148), leftInOut.m_quad);
                v150 = _mm_add_ps(_mm_mul_ps(v147, v148), leftInOut.m_quad);
                v151 = _mm_sub_ps(v149, v150);
                v152 = _mm_mul_ps(v151, v151);
                if ( (float)((float)(_mm_shuffle_ps(v152, v152, 85).m128_f32[0]
                                   + _mm_shuffle_ps(v152, v152, 0).m128_f32[0])
                           + _mm_shuffle_ps(v152, v152, 170).m128_f32[0]) >= v140 )
                {
                  v153 = _mm_sub_ps(rightEnd.m_quad, leftEnd.m_quad);
                  v154 = _mm_add_ps(_mm_mul_ps(v144, v153), leftEnd.m_quad);
                  left.m_quad = _mm_add_ps(_mm_mul_ps(v144, v129), v68);
                  v155 = _mm_add_ps(_mm_mul_ps(v147, v153), leftEnd.m_quad);
                  right.m_quad = _mm_add_ps(_mm_mul_ps(v147, v129), v68);
                  hkaiUserEdgeUtils::UserEdgePair::UserEdgePair(&userEdgePair);
                  v156 = context->m_fromNavMeshInstance;
                  m_userdata = this->m_userdata;
                  v158 = _mm_shuffle_ps(v149, v150, 68);
                  v159 = _mm_shuffle_ps(v155, v154, 68);
                  userEdgePair.m_x.m_quad = _mm_shuffle_ps(v158, v159, 136);
                  v153.m128_i32[0] = LODWORD(this->m_baseCost);
                  userEdgePair.m_y.m_quad = _mm_shuffle_ps(v158, v159, 221);
                  userEdgePair.m_z.m_quad = _mm_shuffle_ps(
                                              _mm_shuffle_ps(v149, v150, 238),
                                              _mm_shuffle_ps(v155, v154, 238),
                                              136);
                  m_sectionUid = v156->m_sectionUid;
                  m_toNavMeshInstance = context->m_toNavMeshInstance;
                  userEdgePair.m_instanceUidA = m_sectionUid;
                  v162 = m_toNavMeshInstance->m_sectionUid;
                  *(float *)&retaddr = v153.m128_f32[0] * 1.0039062;
                  userEdgePair.m_faceA = m_data[v57].m_startFace;
                  LODWORD(m_toNavMeshInstance) = m_data[v57].m_endFace;
                  userEdgePair.m_instanceUidB = v162;
                  m_outputLibrary = context->m_outputLibrary;
                  userEdgePair.m_faceB = (int)m_toNavMeshInstance;
                  userEdgePair.m_direction.m_storage = 1;
                  userEdgePair.m_costBtoA.m_value = 0;
                  userEdgePair.m_costAtoB.m_value = WORD1(retaddr);
                  v164 = hkaiTraversalAnnotationLibrary::addAnnotation(
                           m_outputLibrary,
                           &userEdgePair,
                           HKAI_TRAVERSAL_TYPE_VAULT,
                           m_userdata);
                  clippingPlanes.m_data[4].m_quad = _mm_xor_ps(v135, v141);
                  v165 = _mm_mul_ps(clippingPlanes.m_data[4].m_quad, v149);
                  clippingPlanes.m_data[4].m_quad = _mm_shuffle_ps(
                                                      clippingPlanes.m_data[4].m_quad,
                                                      _mm_unpackhi_ps(
                                                        clippingPlanes.m_data[4].m_quad,
                                                        _mm_sub_ps(
                                                          (__m128)0i64,
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_shuffle_ps(v165, v165, 85),
                                                              _mm_shuffle_ps(v165, v165, 0)),
                                                            _mm_shuffle_ps(v165, v165, 170)))),
                                                      196);
                  clippingPlanes.m_data[5].m_quad = v135;
                  v166 = _mm_mul_ps(clippingPlanes.m_data[5].m_quad, v150);
                  clippingPlanes.m_data[5].m_quad = _mm_shuffle_ps(
                                                      clippingPlanes.m_data[5].m_quad,
                                                      _mm_unpackhi_ps(
                                                        clippingPlanes.m_data[5].m_quad,
                                                        _mm_sub_ps(
                                                          (__m128)0i64,
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_shuffle_ps(v166, v166, 85),
                                                              _mm_shuffle_ps(v166, v166, 0)),
                                                            _mm_shuffle_ps(v166, v166, 170)))),
                                                      196);
                  hkaiIntervalPartition::hkaiIntervalPartition((hkaiIntervalPartition *)&uPartition[8]);
                  hkaiIntervalPartition::hkaiIntervalPartition(&intervalPartition);
                  hkaiGeometrySegmentCaster::findExtremalProfile(
                    context->m_cuttingGeometrySegmentCaster.m_pntr,
                    &clippingPlanes,
                    &left,
                    &right,
                    &extremalVector,
                    &uVector,
                    &vVector,
                    (hkaiIntervalPartition *)&uPartition[8],
                    &intervalPartition);
                  hkaiTraversalAnnotationLibrary::addIntervalPartition(
                    context->m_outputLibrary,
                    v164,
                    0,
                    (hkaiIntervalPartition *)&uPartition[8],
                    1,
                    0);
                  hkaiTraversalAnnotationLibrary::addIntervalPartition(
                    context->m_outputLibrary,
                    v164,
                    1,
                    &intervalPartition,
                    1,
                    0);
                  hkaiTraversalAnnotationLibrary::addVector(context->m_outputLibrary, v164, 0, &left);
                  hkaiTraversalAnnotationLibrary::addVector(context->m_outputLibrary, v164, 1, &right);
                  hkaiTraversalAnnotationLibrary::addVector(context->m_outputLibrary, v164, 2, &uVector);
                  intervalPartition.m_intervals.m_size = 0;
                  if ( intervalPartition.m_intervals.m_capacityAndFlags >= 0 )
                    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                      &hkContainerHeapAllocator::s_alloc,
                      intervalPartition.m_intervals.m_data,
                      20 * (intervalPartition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
                  intervalPartition.m_intervals.m_data = 0i64;
                  intervalPartition.m_intervals.m_capacityAndFlags = 0x80000000;
                  *(_DWORD *)&uPartition[16] = 0;
                  if ( *(int *)&uPartition[20] >= 0 )
                    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                      &hkContainerHeapAllocator::s_alloc,
                      *(void **)&uPartition[8],
                      20 * (*(_DWORD *)&uPartition[20] & 0x3FFFFFFF));
                  *(_QWORD *)&uPartition[8] = 0i64;
                  *(_DWORD *)&uPartition[20] = 0x80000000;
                }
                ++v139;
              }
              while ( v139 < v96 );
              m_capacityAndFlags = clippingPlanes.m_capacityAndFlags;
              v97 = clippingPlanes.m_data;
              v56 = FLOAT_0_0099999998;
            }
            clippingPlanes.m_size = 0;
            if ( m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                v97,
                16 * m_capacityAndFlags);
            clippingPlanes.m_data = 0i64;
            clippingPlanes.m_capacityAndFlags = 0x80000000;
            *(_DWORD *)&uPartition[8] = 0;
            if ( *(int *)&uPartition[12] >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                *(void **)uPartition,
                20 * (*(_DWORD *)&uPartition[12] & 0x3FFFFFFF));
            *(_QWORD *)uPartition = 0i64;
            *(_DWORD *)&uPartition[12] = 0x80000000;
            partition.m_intervals.m_size = 0;
            if ( partition.m_intervals.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                partition.m_intervals.m_data,
                20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
            partition.m_intervals.m_data = 0i64;
            partition.m_intervals.m_capacityAndFlags = 0x80000000;
            clearZonesOut.m_intervals.m_size = 0;
            if ( clearZonesOut.m_intervals.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                clearZonesOut.m_intervals.m_data,
                20 * (clearZonesOut.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
            v55 = *(float *)&FLOAT_1_0;
            m_size = v213;
          }
          else
          {
            *(_DWORD *)&uPartition[8] = 0;
            if ( *(int *)&uPartition[12] >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                *(void **)uPartition,
                20 * (*(_DWORD *)&uPartition[12] & 0x3FFFFFFF));
            *(_QWORD *)uPartition = 0i64;
            *(_DWORD *)&uPartition[12] = 0x80000000;
            partition.m_intervals.m_size = 0;
            if ( partition.m_intervals.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                partition.m_intervals.m_data,
                20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
            partition.m_intervals.m_data = 0i64;
            partition.m_intervals.m_capacityAndFlags = 0x80000000;
            clearZonesOut.m_intervals.m_size = 0;
            if ( clearZonesOut.m_intervals.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                clearZonesOut.m_intervals.m_data,
                20 * (clearZonesOut.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
          }
          v39 = v186;
          v38 = v184;
          goto LABEL_48;
        }
        partition.m_intervals.m_size = 0;
        if ( partition.m_intervals.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            partition.m_intervals.m_data,
            20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
        partition.m_intervals.m_data = 0i64;
        partition.m_intervals.m_capacityAndFlags = 0x80000000;
      }
      clearZonesOut.m_intervals.m_size = 0;
      if ( clearZonesOut.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          clearZonesOut.m_intervals.m_data,
          20 * (clearZonesOut.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
LABEL_48:
      ++v57;
      --m_size;
      clearZonesOut.m_intervals.m_capacityAndFlags = 0x80000000;
      v213 = m_size;
      clearZonesOut.m_intervals.m_data = 0i64;
    }
    while ( m_size );
  }
  pairsOut.m_size = 0;
  if ( pairsOut.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      pairsOut.m_data,
      80 * (pairsOut.m_capacityAndFlags & 0x3FFFFFFF));
}irsOut.m_data,
      80 * (pairsOut.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 308
// RVA: 0xC39500
__int64 __fastcall hkaiVaultUtils::getHandPlantPoint(
        hkaiTraversalAnnotationLibrary *library,
        unsigned int *annotationIndex,
        hkVector4f *handPos,
        hkVector4f *handPlantPointOut,
        hkVector4f *handPlantFwdDirOut)
{
  unsigned int v8; // edx
  __int64 v9; // rax
  unsigned int v10; // edx
  hkVector4f v11; // xmm3
  __m128 v12; // xmm5
  __m128 v13; // xmm5
  __m128 v14; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  float tInOut; // [rsp+30h] [rbp-58h] BYREF
  float y; // [rsp+34h] [rbp-54h] BYREF
  float v20; // [rsp+38h] [rbp-50h] BYREF
  hkSimdFloat32 result; // [rsp+40h] [rbp-48h] BYREF
  hkVector4f v22; // [rsp+50h] [rbp-38h] BYREF
  hkVector4f vecOut; // [rsp+60h] [rbp-28h] BYREF
  hkVector4f v24; // [rsp+70h] [rbp-18h] BYREF

  hkaiTraversalAnnotationLibrary::evaluateT(library, &result, *annotationIndex, handPos);
  v8 = *annotationIndex;
  tInOut = result.m_real.m128_f32[0];
  if ( !hkaiTraversalAnnotationLibrary::getClosestDefined(library, v8, 0, &tInOut) )
    return 0i64;
  v10 = *annotationIndex;
  result.m_real = _mm_shuffle_ps((__m128)LODWORD(tInOut), (__m128)LODWORD(tInOut), 0);
  if ( !hkaiTraversalAnnotationLibrary::tryEvaluateYAt(library, v10, 0, result.m_real.m128_f32[0], &y) )
    return 0i64;
  hkaiTraversalAnnotationLibrary::tryEvaluateYAt(library, *annotationIndex, 1, result.m_real.m128_f32[0], &v20);
  hkaiTraversalAnnotationLibrary::getVectorData(library, *annotationIndex, 0, &vecOut);
  hkaiTraversalAnnotationLibrary::getVectorData(library, *annotationIndex, 1, &v22);
  hkaiTraversalAnnotationLibrary::getVectorData(library, *annotationIndex, 2, &v24);
  v9 = 1i64;
  v11.m_quad = (__m128)library->m_up;
  v12 = _mm_sub_ps(v22.m_quad, vecOut.m_quad);
  handPlantPointOut->m_quad = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(v12, result.m_real), vecOut.m_quad),
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(y), (__m128)LODWORD(y), 0), v24.m_quad)),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v20), (__m128)LODWORD(v20), 0), v11.m_quad));
  v13 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v11.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v11.m_quad, v11.m_quad, 201), v12));
  v14 = _mm_shuffle_ps(v13, v13, 201);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  handPlantFwdDirOut->m_quad = _mm_mul_ps(
                                 _mm_andnot_ps(
                                   _mm_cmple_ps(v16, (__m128)0i64),
                                   _mm_mul_ps(
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                                     _mm_mul_ps(*(__m128 *)_xmm, v17))),
                                 v14);
  return v9;
}

// File Line: 360
// RVA: 0xC396B0
__int64 __fastcall hkaiVaultUtils::getNumHandPlantSegments(
        hkaiTraversalAnnotationLibrary *library,
        unsigned int *annotationIndex)
{
  return hkaiTraversalAnnotationLibrary::getNumPartitionIntervals(library, *annotationIndex, 0);
}

// File Line: 370
// RVA: 0xC396D0
void __fastcall hkaiVaultUtils::getHandPlantSegment(
        hkaiTraversalAnnotationLibrary *library,
        unsigned int *annotationIndex,
        unsigned __int16 handPlantSegmentIndex,
        hkVector4f *leftPointOut,
        hkVector4f *rightPointOut)
{
  hkVector4f v9; // xmm6
  hkVector2f LeftEndpoint; // rax
  hkVector2f RightEndpoint; // rax
  hkVector4f vecOut; // [rsp+30h] [rbp-88h] BYREF
  hkVector4f v13; // [rsp+40h] [rbp-78h] BYREF
  hkVector4f yVector; // [rsp+50h] [rbp-68h] BYREF
  hkVector4f xVector; // [rsp+60h] [rbp-58h] BYREF
  hkaiIntervalPartition::Interval v16; // [rsp+70h] [rbp-48h] BYREF
  hkaiIntervalPartition::Interval intervalOut; // [rsp+88h] [rbp-30h] BYREF

  hkaiTraversalAnnotationLibrary::getPartitionInterval(
    library,
    *annotationIndex,
    0,
    handPlantSegmentIndex,
    &intervalOut);
  hkaiTraversalAnnotationLibrary::getPartitionInterval(library, *annotationIndex, 1, handPlantSegmentIndex, &v16);
  hkaiTraversalAnnotationLibrary::getVectorData(library, *annotationIndex, 0, &vecOut);
  hkaiTraversalAnnotationLibrary::getVectorData(library, *annotationIndex, 1, &v13);
  hkaiTraversalAnnotationLibrary::getVectorData(library, *annotationIndex, 2, &yVector);
  v9.m_quad = (__m128)library->m_up;
  xVector.m_quad = _mm_sub_ps(v13.m_quad, vecOut.m_quad);
  hkaiIntervalPartition::Interval::interpolateParallelogram(
    &intervalOut,
    &vecOut,
    &xVector,
    &yVector,
    leftPointOut,
    rightPointOut);
  LeftEndpoint = hkaiIntervalPartition::Interval::getLeftEndpoint(&v16);
  leftPointOut->m_quad = _mm_add_ps(
                           leftPointOut->m_quad,
                           _mm_mul_ps(
                             _mm_shuffle_ps(
                               (__m128)*(unsigned int *)(*(_QWORD *)&LeftEndpoint + 4i64),
                               (__m128)*(unsigned int *)(*(_QWORD *)&LeftEndpoint + 4i64),
                               0),
                             v9.m_quad));
  RightEndpoint = hkaiIntervalPartition::Interval::getRightEndpoint(&v16);
  rightPointOut->m_quad = _mm_add_ps(
                            rightPointOut->m_quad,
                            _mm_mul_ps(
                              _mm_shuffle_ps(
                                (__m128)*(unsigned int *)(*(_QWORD *)&RightEndpoint + 4i64),
                                (__m128)*(unsigned int *)(*(_QWORD *)&RightEndpoint + 4i64),
                                0),
                              v9.m_quad));
}


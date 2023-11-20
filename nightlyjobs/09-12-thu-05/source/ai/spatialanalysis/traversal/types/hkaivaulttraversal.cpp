// File Line: 25
// RVA: 0xC37E70
void __fastcall hkaiVaultAnalyzer::analyze(hkaiVaultAnalyzer *this, hkaiTraversalAnalysisContext *context)
{
  hkaiVaultAnalyzer *v2; // r13
  hkaiTraversalAnalysisContext *v3; // rdi
  __m128i v4; // xmm3
  float v5; // xmm8_4
  hkaiTraversalAnalysisSettings *v6; // rax
  __m128 v7; // xmm7
  __m128 v8; // xmm2
  int v9; // xmm0_4
  float v10; // xmm0_4
  __m128i v11; // xmm4
  __m128i v12; // xmm6
  __m128 v13; // xmm5
  __m128 v14; // xmm0
  __m128 v15; // xmm4
  __m128 v16; // xmm3
  __m128 v17; // xmm11
  __m128i v18; // xmm3
  __m128i v19; // xmm6
  __m128 v20; // xmm2
  __m128i v21; // xmm6
  __m128 v22; // xmm5
  __m128 v23; // xmm0
  __m128 v24; // xmm4
  __m128 v25; // xmm2
  __m128i v26; // xmm4
  __m128i v27; // xmm7
  hkaiPairedEdgeFinder *v28; // rcx
  __m128 v29; // xmm6
  __m128 v30; // xmm2
  __m128i v31; // xmm7
  __m128 v32; // xmm5
  __m128 v33; // xmm0
  __m128 v34; // xmm4
  __m128 v35; // xmm2
  __m128i v36; // xmm1
  hkVector4f *v37; // r9
  __m128 v38; // xmm0
  __m128 v39; // xmm9
  __m128 v40; // xmm11
  __m128i v41; // xmm5
  hkaiTraversalAnalysisSettings *v42; // rax
  __int64 v43; // rbx
  __m128 v44; // xmm1
  __m128 v45; // xmm8
  __m128i v46; // xmm7
  __m128 v47; // xmm8
  __m128 v48; // xmm0
  __m128 v49; // xmm2
  __m128i v50; // xmm5
  __m128 v51; // xmm1
  __m128 v52; // xmm4
  __m128 v53; // xmm3
  __m128 v54; // xmm2
  __m128 v55; // xmm10
  float v56; // xmm10_4
  float v57; // xmm15_4
  __int64 v58; // r14
  hkaiPairedEdgeFinder::EdgePair *v59; // r15
  hkaiNavMeshUtils *v60; // rcx
  hkVector4f *v61; // r9
  __m128 v62; // xmm8
  __m128 v63; // xmm7
  __m128 v64; // xmm14
  __m128 v65; // xmm5
  __m128 v66; // xmm4
  __m128 v67; // xmm2
  __m128 v68; // xmm3
  __m128 v69; // xmm14
  __m128 v70; // xmm7
  __m128 v71; // xmm5
  __m128 v72; // xmm5
  __m128 v73; // xmm1
  __m128 v74; // xmm3
  __m128 v75; // xmm2
  __m128 v76; // xmm1
  __m128 v77; // xmm7
  __m128 v78; // xmm1
  __m128 v79; // xmm2
  __m128 v80; // xmm1
  __m128 v81; // xmm9
  __m128 v82; // xmm11
  int v83; // esi
  hkaiIntervalPartition::Interval *v84; // rbx
  __m128 v85; // xmm5
  __m128 v86; // xmm0
  __m128 v87; // xmm5
  __m128 v88; // xmm2
  __m128 v89; // xmm1
  __m128 v90; // xmm4
  __m128 v91; // xmm6
  __m128 v92; // xmm2
  __m128 v93; // xmm4
  __m128 v94; // xmm4
  __m128 v95; // xmm6
  __m128 v96; // xmm6
  float v97; // xmm0_4
  int v98; // er12
  __m128 v99; // xmm13
  hkVector4f *v100; // rdx
  int v101; // er8
  __m128 v102; // xmm0
  __m128 v103; // xmm0
  __m128 v104; // xmm6
  __m128 v105; // xmm11
  __m128 v106; // xmm10
  __m128 v107; // xmm12
  __m128 v108; // xmm12
  __m128 v109; // xmm1
  __m128 v110; // xmm3
  __m128 v111; // xmm2
  __m128 v112; // xmm12
  __m128 v113; // xmm2
  __m128 v114; // xmm8
  __m128 v115; // xmm0
  __m128 v116; // xmm7
  __m128 v117; // xmm7
  __m128 v118; // xmm1
  __m128 v119; // xmm3
  __m128 v120; // xmm2
  __m128 v121; // xmm5
  __m128 v122; // xmm7
  __m128 v123; // xmm2
  __m128 v124; // xmm6
  __m128 v125; // xmm12
  __m128 v126; // xmm12
  __m128 v127; // xmm1
  __m128 v128; // xmm3
  __m128 v129; // xmm2
  __m128 v130; // xmm12
  __m128i v131; // xmm0
  __m128 v132; // xmm3
  __m128 v133; // xmm4
  __m128 v134; // xmm2
  __m128 v135; // xmm10
  __m128 v136; // xmm1
  __m128 v137; // xmm12
  __m128 v138; // xmm1
  __m128 v139; // xmm3
  __m128 v140; // xmm2
  __m128 v141; // xmm12
  __m128 v142; // xmm1
  __m128 v143; // xmm2
  __m128 v144; // xmm1
  int v145; // esi
  float v146; // xmm13_4
  __m128 v147; // xmm15
  unsigned int *v148; // rax
  unsigned int v149; // xmm1_4
  __m128 v150; // xmm3
  __m128 v151; // xmm4
  int v152; // xmm0_4
  __m128 v153; // xmm4
  __m128 v154; // xmm0
  __m128 v155; // xmm8
  __m128 v156; // xmm9
  __m128 v157; // xmm2
  __m128 v158; // xmm2
  __m128 v159; // xmm0
  __m128 v160; // xmm6
  __m128 v161; // xmm7
  hkaiNavMeshInstance *v162; // rax
  unsigned int v163; // er9
  __m128 v164; // xmm2
  __m128 v165; // xmm1
  unsigned int v166; // ecx
  hkaiNavMeshInstance *v167; // rax
  unsigned int v168; // ecx
  hkaiTraversalAnnotationLibrary *v169; // rcx
  unsigned int v170; // ebx
  __m128 v171; // xmm2
  __m128 v172; // xmm2
  hkaiIntervalPartition clearZonesOut; // [rsp+50h] [rbp-A8h]
  hkaiIntervalPartition partition; // [rsp+60h] [rbp-98h]
  hkaiIntervalPartition uPartition; // [rsp+70h] [rbp-88h]
  int v176; // [rsp+80h] [rbp-78h]
  int v177; // [rsp+84h] [rbp-74h]
  hkaiIntervalPartition other; // [rsp+88h] [rbp-70h]
  hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> pairsOut; // [rsp+98h] [rbp-60h]
  hkaiIntervalPartition intervalPartition; // [rsp+A8h] [rbp-50h]
  hkVector4f rightInOut; // [rsp+B8h] [rbp-40h]
  hkVector4f vVector; // [rsp+C8h] [rbp-30h]
  hkVector4f leftEnd; // [rsp+D8h] [rbp-20h]
  hkVector4f leftInOut; // [rsp+E8h] [rbp-10h]
  hkVector4f rightEnd; // [rsp+F8h] [rbp+0h]
  __int128 v186; // [rsp+108h] [rbp+10h]
  int v187; // [rsp+118h] [rbp+20h]
  hkVector4f uVector; // [rsp+128h] [rbp+30h]
  hkVector4f left; // [rsp+138h] [rbp+40h]
  __m128 v190; // [rsp+148h] [rbp+50h]
  hkVector4f right; // [rsp+158h] [rbp+60h]
  __m128 v192; // [rsp+168h] [rbp+70h]
  hkaiPairedEdgeFinder::PairedEdgeSettings settings; // [rsp+178h] [rbp+80h]
  __m128 v194; // [rsp+1B8h] [rbp+C0h]
  hkArrayBase<hkVector4f> clippingPlanes; // [rsp+1C8h] [rbp+D0h]
  __m128 v196; // [rsp+1D8h] [rbp+E0h]
  __m128 v197; // [rsp+1E8h] [rbp+F0h]
  __m128 v198; // [rsp+1F8h] [rbp+100h]
  __m128 v199; // [rsp+208h] [rbp+110h]
  hkaiUserEdgeUtils::UserEdgePair userEdgePair; // [rsp+238h] [rbp+140h]
  hkVector4f facePlane; // [rsp+288h] [rbp+190h]
  __m128 v202; // [rsp+298h] [rbp+1A0h]
  hkVector4f leftStart; // [rsp+2A8h] [rbp+1B0h]
  __m128 v204; // [rsp+2B8h] [rbp+1C0h]
  hkVector4f v205; // [rsp+2C8h] [rbp+1D0h]
  __m128 v206; // [rsp+2D8h] [rbp+1E0h]
  hkVector4f v207; // [rsp+2E8h] [rbp+1F0h]
  __m128 v208; // [rsp+2F8h] [rbp+200h]
  __m128 v209; // [rsp+308h] [rbp+210h]
  int faceIndex; // [rsp+318h] [rbp+220h]
  hkVector4f v211; // [rsp+328h] [rbp+230h]
  hkVector4f extremalVector; // [rsp+338h] [rbp+240h]
  hkVector4f v213; // [rsp+348h] [rbp+250h]
  hkVector4f extrusion; // [rsp+358h] [rbp+260h]
  hkVector4f v215; // [rsp+368h] [rbp+270h]
  hkVector4f displacement; // [rsp+378h] [rbp+280h]
  __m128 v217; // [rsp+388h] [rbp+290h]
  hkVector4f rightStart; // [rsp+398h] [rbp+2A0h]
  float retaddr; // [rsp+498h] [rbp+3A0h]
  float newX2; // [rsp+4A0h] [rbp+3A8h]
  float v221; // [rsp+4A4h] [rbp+3ACh]
  float newX1; // [rsp+4A8h] [rbp+3B0h]
  float v223; // [rsp+4ACh] [rbp+3B4h]
  __int64 v224; // [rsp+4B0h] [rbp+3B8h]

  v2 = this;
  v3 = context;
  _mm_store_si128((__m128i *)&vVector, (__m128i)context->m_settings->m_up.m_quad);
  hkaiPairedEdgeFinder::PairedEdgeSettings::PairedEdgeSettings(&settings);
  v4 = _mm_load_si128((const __m128i *)_xmm);
  v5 = v2->m_maxPlanarAngle;
  v6 = v3->m_settings;
  v7 = _mm_add_ps((__m128)LODWORD(v2->m_maxPlanarAngle), *(__m128 *)_xmm);
  v8 = _mm_andnot_ps(*(__m128 *)_xmm, v7);
  settings.m_up = (hkVector4f)vVector.m_quad;
  v9 = LODWORD(v2->m_maxDownHeight) ^ _xmm[0];
  settings.m_minLength = v6->m_minEdgeLength;
  settings.m_minHorizontalDelta = v2->m_minWallWidth;
  LODWORD(settings.m_minHeightDelta) = v9;
  settings.m_maxHeightDelta = v2->m_maxUpHeight;
  v10 = v2->m_maxWallWidth;
  v11 = _mm_add_epi32(v4, v4);
  _mm_store_si128((__m128i *)&uPartition.m_intervals.m_size, v11);
  settings.m_maxHorizontalDelta = v10;
  v12 = _mm_andnot_si128(v4, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v8, *(__m128 *)_xmm)), v4));
  v13 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v12, v11), (__m128i)0i64);
  v14 = _mm_cvtepi32_ps(v12);
  v15 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v14, *(__m128 *)DP1_0), v8), _mm_mul_ps(v14, *(__m128 *)DP2)),
          _mm_mul_ps(v14, *(__m128 *)DP3));
  v16 = _mm_mul_ps(v15, v15);
  v17 = *(__m128 *)sinCoeff0;
  v8.m128_i32[0] = (unsigned __int128)_mm_andnot_ps(
                                        v13,
                                        _mm_add_ps(
                                          _mm_sub_ps(
                                            _mm_mul_ps(
                                              _mm_mul_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(
                                                    _mm_add_ps(
                                                      _mm_mul_ps(v16, *(__m128 *)cosCoeff0_0),
                                                      *(__m128 *)cosCoeff1),
                                                    v16),
                                                  *(__m128 *)cosCoeff2_0),
                                                v16),
                                              v16),
                                            _mm_mul_ps(v16, *(__m128 *)_xmm)),
                                          *(__m128 *)_xmm));
  v14.m128_f32[0] = (float)((float)((float)((float)(v16.m128_f32[0] * v17.m128_f32[0]) + 0.0083321612) * v16.m128_f32[0])
                          + -0.16666655)
                  * v16.m128_f32[0];
  v18 = _mm_load_si128((const __m128i *)&uPartition.m_intervals.m_size);
  v8.m128_i32[0] |= COERCE_UNSIGNED_INT((float)(v14.m128_f32[0] * v15.m128_f32[0]) + v15.m128_f32[0]) & v13.m128_i32[0];
  v14.m128_i32[0] = (unsigned __int128)_mm_and_si128(_mm_add_epi32(v18, v18), v12);
  v19 = _mm_load_si128((const __m128i *)_xmm);
  LODWORD(settings.m_cosMaxPlanarAngle) = v8.m128_i32[0] ^ (v14.m128_i32[0] << 29) ^ v7.m128_i32[0] & _xmm[0];
  v20 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(v5));
  v21 = _mm_andnot_si128(v19, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v20, *(__m128 *)_xmm)), v19));
  v22 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v21, v18), (__m128i)0i64);
  v23 = _mm_cvtepi32_ps(v21);
  v24 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v23, *(__m128 *)DP1_0), v20), _mm_mul_ps(v23, *(__m128 *)DP2)),
          _mm_mul_ps(v23, *(__m128 *)DP3));
  v25 = _mm_mul_ps(v24, v24);
  v23.m128_f32[0] = (float)((float)((float)((float)((float)((float)(v25.m128_f32[0] * v17.m128_f32[0]) + 0.0083321612)
                                                  * v25.m128_f32[0])
                                          + -0.16666655)
                                  * v25.m128_f32[0])
                          * v24.m128_f32[0])
                  + v24.m128_f32[0];
  v26 = _mm_load_si128((const __m128i *)&uPartition.m_intervals.m_size);
  LODWORD(settings.m_sinMaxPlanarAngle) = (*(unsigned __int128 *)&_mm_andnot_ps(
                                                                    v22,
                                                                    _mm_add_ps(
                                                                      _mm_sub_ps(
                                                                        _mm_mul_ps(
                                                                          _mm_mul_ps(
                                                                            _mm_add_ps(
                                                                              _mm_mul_ps(
                                                                                _mm_add_ps(
                                                                                  _mm_mul_ps(
                                                                                    v25,
                                                                                    *(__m128 *)cosCoeff0_0),
                                                                                  *(__m128 *)cosCoeff1),
                                                                                v25),
                                                                              *(__m128 *)cosCoeff2_0),
                                                                            v25),
                                                                          v25),
                                                                        _mm_mul_ps(v25, *(__m128 *)_xmm)),
                                                                      *(__m128 *)_xmm)) | v23.m128_i32[0] & v22.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v26, v26), v21) << 29) ^ LODWORD(v5) & _xmm[0];
  v27 = _mm_load_si128((const __m128i *)_xmm);
  v28 = v3->m_pairedEdgeFinder.m_pntr;
  v29 = _mm_add_ps((__m128)LODWORD(v2->m_maxRelativeSlopeAngle), *(__m128 *)_xmm);
  settings.m_matchAngles.m_bool = 1;
  pairsOut.m_capacityAndFlags = 2147483648;
  pairsOut.m_data = 0i64;
  pairsOut.m_size = 0;
  v30 = _mm_andnot_ps(*(__m128 *)_xmm, v29);
  v31 = _mm_andnot_si128(v27, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v30, *(__m128 *)_xmm)), v27));
  v32 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v31, v26), (__m128i)0i64);
  v33 = _mm_cvtepi32_ps(v31);
  v34 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v33, *(__m128 *)DP1_0), v30), _mm_mul_ps(v33, *(__m128 *)DP2)),
          _mm_mul_ps(v33, *(__m128 *)DP3));
  v35 = _mm_mul_ps(v34, v34);
  v36 = _mm_load_si128((const __m128i *)&uPartition.m_intervals.m_size);
  LODWORD(settings.m_cosMaxDeltaSlopeAngle) = (*(unsigned __int128 *)&_mm_andnot_ps(
                                                                        v32,
                                                                        _mm_add_ps(
                                                                          _mm_sub_ps(
                                                                            _mm_mul_ps(
                                                                              _mm_mul_ps(
                                                                                _mm_add_ps(
                                                                                  _mm_mul_ps(
                                                                                    _mm_add_ps(
                                                                                      _mm_mul_ps(
                                                                                        v35,
                                                                                        *(__m128 *)cosCoeff0_0),
                                                                                      *(__m128 *)cosCoeff1),
                                                                                    v35),
                                                                                  *(__m128 *)cosCoeff2_0),
                                                                                v35),
                                                                              v35),
                                                                            _mm_mul_ps(v35, *(__m128 *)_xmm)),
                                                                          *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                                                (float)((float)((float)((float)((float)((float)(v35.m128_f32[0] * -0.00019515296) + 0.0083321612) * v35.m128_f32[0]) + -0.16666655) * v35.m128_f32[0]) * v34.m128_f32[0])
                                                                                              + v34.m128_f32[0]) & v32.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v36, v36), v31) << 29) ^ v29.m128_i32[0] & _xmm[0];
  hkaiPairedEdgeFinder::findEdgePairs(v28, &settings, &pairsOut);
  v17.m128_f32[0] = v2->m_minWallWidth * 0.5;
  v38 = (__m128)LODWORD(v2->m_minWallHeight);
  v39 = _mm_mul_ps(
          _mm_shuffle_ps((__m128)LODWORD(v2->m_maxWallHeight), (__m128)LODWORD(v2->m_maxWallHeight), 0),
          vVector.m_quad);
  v40 = _mm_shuffle_ps(v17, v17, 0);
  v38.m128_f32[0] = v38.m128_f32[0] - v2->m_maxWallHeight;
  v194 = v40;
  v192 = v39;
  v41 = _mm_load_si128((const __m128i *)_xmm);
  v42 = v3->m_settings;
  v43 = pairsOut.m_size;
  v44 = _mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), vVector.m_quad);
  v38.m128_i32[0] = LODWORD(v2->m_verticalApex) ^ _xmm[0];
  v45 = _mm_shuffle_ps((__m128)LODWORD(v2->m_handPlantAngle), (__m128)LODWORD(v2->m_handPlantAngle), 0);
  v46 = _mm_add_epi32(v41, v41);
  displacement.m_quad = v44;
  v47 = _mm_add_ps(v45, *(__m128 *)offset_1);
  v44.m128_f32[0] = v38.m128_f32[0];
  v209 = _mm_shuffle_ps((__m128)LODWORD(v2->m_minWallHeight), (__m128)LODWORD(v2->m_minWallHeight), 0);
  v48 = (__m128)LODWORD(v2->m_maxWallHeight);
  v211.m_quad = _mm_mul_ps(_mm_shuffle_ps(v44, v44, 0), vVector.m_quad);
  v49 = _mm_andnot_ps(*(__m128 *)_xmm, v47);
  v217 = _mm_shuffle_ps(v48, v48, 0);
  v190 = _mm_shuffle_ps((__m128)LODWORD(v42->m_characterRadius), (__m128)LODWORD(v42->m_characterRadius), 0);
  v50 = _mm_andnot_si128(v41, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v49, *(__m128 *)_xmm)), v41));
  v51 = _mm_cvtepi32_ps(v50);
  v52 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v50, v46), (__m128i)0i64);
  v53 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v51, *(__m128 *)DP1_0), v49), _mm_mul_ps(v51, *(__m128 *)DP2)),
          _mm_mul_ps(v51, *(__m128 *)DP3));
  v54 = _mm_mul_ps(v53, v53);
  v55 = _mm_xor_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              v52,
              _mm_add_ps(
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v54, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v54),
                        *(__m128 *)cosCoeff2_0),
                      v54),
                    v54),
                  _mm_mul_ps(v54, *(__m128 *)_xmm)),
                *(__m128 *)_xmm)),
            _mm_and_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v54, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v54),
                      *(__m128 *)sinCoeff2_0),
                    v54),
                  v53),
                v53),
              v52)),
          _mm_xor_ps(
            (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v46, v46), v50), 0x1Du),
            _mm_and_ps(v47, *(__m128 *)_xmm)));
  v206 = _mm_shuffle_ps(v55, v55, 85);
  v204 = _mm_shuffle_ps(v55, v55, 0);
  v224 = pairsOut.m_size;
  if ( pairsOut.m_size > 0i64 )
  {
    v56 = *(float *)&FLOAT_1_0;
    v57 = FLOAT_0_0099999998;
    v58 = 0i64;
    do
    {
      v59 = pairsOut.m_data;
      v60 = (hkaiNavMeshUtils *)v3->m_fromNavMeshInstance;
      _mm_store_si128((__m128i *)&leftInOut, (__m128i)pairsOut.m_data[v58].m_startLeft.m_quad);
      _mm_store_si128((__m128i *)&rightInOut, (__m128i)v59[v58].m_startRight.m_quad);
      _mm_store_si128((__m128i *)&leftEnd, (__m128i)v59[v58].m_endLeft.m_quad);
      _mm_store_si128((__m128i *)&rightEnd, (__m128i)v59[v58].m_endRight.m_quad);
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        v60,
        (hkaiNavMeshInstance *)(unsigned int)v59[v58].m_startFace,
        (__int64)&faceIndex,
        v37);
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)v3->m_toNavMeshInstance,
        (hkaiNavMeshInstance *)(unsigned int)v59[v58].m_endFace,
        (__int64)&facePlane,
        v61);
      hkaiTraversalAnalysisUtils::setBackEdge(&leftInOut, &rightInOut, (hkVector4f *)&faceIndex, v3);
      hkaiTraversalAnalysisUtils::setBackEdge(&rightEnd, &leftEnd, &facePlane, v3);
      hkaiIntervalPartition::hkaiIntervalPartition(&clearZonesOut);
      hkaiTraversalAnalysisUtils::filterUnwalkableLandingZones(
        &leftInOut,
        &rightInOut,
        &leftEnd,
        &rightEnd,
        v59[v58].m_startFace,
        v59[v58].m_endFace,
        &clearZonesOut,
        v3);
      if ( clearZonesOut.m_intervals.m_size
        && hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&leftInOut, &rightInOut, v3)
        && hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&rightEnd, &leftEnd, v3) )
      {
        v62 = 0i64;
        v63 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(rightEnd.m_quad, rightInOut.m_quad), (__m128)xmmword_141A711B0),
                rightInOut.m_quad);
        v64 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(leftEnd.m_quad, leftInOut.m_quad), (__m128)xmmword_141A711B0),
                leftInOut.m_quad);
        v65 = _mm_mul_ps(rightInOut.m_quad, vVector.m_quad);
        v66 = _mm_mul_ps(leftInOut.m_quad, vVector.m_quad);
        v67 = _mm_mul_ps(v64, vVector.m_quad);
        v68 = _mm_mul_ps(v63, vVector.m_quad);
        v69 = _mm_add_ps(
                _mm_sub_ps(
                  v64,
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)),
                      _mm_shuffle_ps(v67, v67, 170)),
                    vVector.m_quad)),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)),
                    _mm_shuffle_ps(v66, v66, 170)),
                  vVector.m_quad));
        v70 = _mm_add_ps(
                _mm_sub_ps(
                  v63,
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
                      _mm_shuffle_ps(v68, v68, 170)),
                    vVector.m_quad)),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
                    _mm_shuffle_ps(v65, v65, 170)),
                  vVector.m_quad));
        v202 = _mm_sub_ps(v70, v69);
        v71 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v202, v202, 201), vVector.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(vVector.m_quad, vVector.m_quad, 201), v202));
        v72 = _mm_shuffle_ps(v71, v71, 201);
        v73 = _mm_mul_ps(v72, v72);
        v74 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
                _mm_shuffle_ps(v73, v73, 170));
        v75 = _mm_rsqrt_ps(v74);
        uVector.m_quad = _mm_mul_ps(
                           v72,
                           _mm_andnot_ps(
                             _mm_cmpleps(v74, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v75, v74), v75)),
                               _mm_mul_ps(v75, *(__m128 *)_xmm))));
        v76 = _mm_mul_ps(uVector.m_quad, v40);
        v77 = _mm_add_ps(_mm_sub_ps(v70, v76), v39);
        leftStart.m_quad = _mm_add_ps(_mm_sub_ps(v69, v76), v39);
        rightStart.m_quad = v77;
        extrusion.m_quad = _mm_mul_ps(
                             _mm_shuffle_ps((__m128)LODWORD(v2->m_minWallWidth), (__m128)LODWORD(v2->m_minWallWidth), 0),
                             uVector.m_quad);
        hkaiIntervalPartition::hkaiIntervalPartition(&partition);
        hkaiGeometrySegmentCaster::castSegmentExtruded(
          v3->m_cuttingGeometrySegmentCaster.m_pntr,
          &leftStart,
          &rightStart,
          &displacement,
          &extrusion,
          &partition);
        if ( partition.m_intervals.m_size )
        {
          hkaiIntervalPartition::remapY(&partition, 0.0, v56, v2->m_maxWallHeight, v2->m_minWallHeight);
          v78 = _mm_mul_ps(leftEnd.m_quad, vVector.m_quad);
          v79 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v78, v78, 85), _mm_shuffle_ps(v78, v78, 0)),
                  _mm_shuffle_ps(v78, v78, 170));
          v80 = _mm_mul_ps(rightEnd.m_quad, vVector.m_quad);
          v81 = _mm_sub_ps(leftEnd.m_quad, _mm_mul_ps(v79, vVector.m_quad));
          v82 = _mm_sub_ps(
                  rightEnd.m_quad,
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v80, v80, 85), _mm_shuffle_ps(v80, v80, 0)),
                      _mm_shuffle_ps(v80, v80, 170)),
                    vVector.m_quad));
          hkaiIntervalPartition::hkaiIntervalPartition(&uPartition);
          v83 = 0;
          if ( partition.m_intervals.m_size > 0 )
          {
            do
            {
              v84 = hkaiIntervalPartition::getInterval(&partition, v83);
              hkaiIntervalPartition::Interval::getLeftEndpoint(v84);
              hkaiIntervalPartition::Interval::getRightEndpoint(v84);
              if ( (float)(newX2 - newX1) >= v57 )
              {
                v86 = (__m128)LODWORD(v223);
                v85.m128_f32[0] = newX1;
                v86.m128_f32[0] = v223 + v57;
                v77.m128_f32[0] = newX2;
                v87 = _mm_shuffle_ps(v85, v85, 0);
                v77 = _mm_shuffle_ps(v77, v77, 0);
                v88 = _mm_sub_ps(rightInOut.m_quad, leftInOut.m_quad);
                v89 = _mm_mul_ps(_mm_shuffle_ps(v86, v86, 0), vVector.m_quad);
                v90 = _mm_add_ps(_mm_mul_ps(v87, v88), leftInOut.m_quad);
                v91 = _mm_add_ps(_mm_mul_ps(v77, v88), leftInOut.m_quad);
                v92 = _mm_sub_ps(v82, v81);
                v93 = _mm_add_ps(v90, v89);
                v89.m128_f32[0] = v221 + v57;
                v213.m_quad = v93;
                v94 = _mm_mul_ps(v93, vVector.m_quad);
                v95 = _mm_add_ps(v91, _mm_mul_ps(_mm_shuffle_ps(v89, v89, 0), vVector.m_quad));
                v207.m_quad = v95;
                v96 = _mm_mul_ps(v95, vVector.m_quad);
                v215.m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v94, v94, 85), _mm_shuffle_ps(v94, v94, 0)),
                                    _mm_shuffle_ps(v94, v94, 170)),
                                  vVector.m_quad),
                                _mm_add_ps(_mm_mul_ps(v92, v87), v81));
                v205.m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)),
                                    _mm_shuffle_ps(v96, v96, 170)),
                                  vVector.m_quad),
                                _mm_add_ps(_mm_mul_ps(v92, v77), v81));
                hkaiIntervalPartition::hkaiIntervalPartition(&other);
                hkaiGeometrySegmentCaster::turnSegmentExtruded(
                  v3->m_cuttingGeometrySegmentCaster.m_pntr,
                  &v213,
                  &v207,
                  &v215,
                  &v205,
                  &v211,
                  &other);
                hkaiIntervalPartition::remapX(&other, 0.0, v56, newX1, newX2);
                if ( uPartition.m_intervals.m_size )
                {
                  v97 = hkaiIntervalPartition::getExtremeX<1>(&uPartition);
                  hkaiIntervalPartition::clipX(&other, v97, v56);
                }
                hkaiIntervalPartition::appendPartition(&uPartition, &other);
                other.m_intervals.m_size = 0;
                if ( other.m_intervals.m_capacityAndFlags >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    other.m_intervals.m_data,
                    20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
                other.m_intervals.m_data = 0i64;
                other.m_intervals.m_capacityAndFlags = 2147483648;
              }
              ++v83;
            }
            while ( v83 < partition.m_intervals.m_size );
            v43 = v224;
            v62 = 0i64;
          }
          hkaiIntervalPartition::complement(&uPartition, 0.0, v56);
          hkaiIntervalPartition::clipNotDefined(&uPartition, &partition);
          hkaiIntervalPartition::clipNotDefined(&uPartition, &clearZonesOut);
          v98 = uPartition.m_intervals.m_size;
          if ( uPartition.m_intervals.m_size )
          {
            v99 = vVector.m_quad;
            v100 = (hkVector4f *)&v196;
            v101 = -2147483642;
            v102 = (__m128)LODWORD(v3->m_settings->m_minEdgeLength);
            clippingPlanes.m_size = 6;
            clippingPlanes.m_capacityAndFlags = -2147483642;
            clippingPlanes.m_data = (hkVector4f *)&v196;
            v103 = _mm_shuffle_ps(v102, v102, 0);
            v104 = _mm_shuffle_ps(vVector.m_quad, vVector.m_quad, 201);
            v105 = _mm_sub_ps(rightInOut.m_quad, leftInOut.m_quad);
            v208 = _mm_mul_ps(v103, v103);
            v106 = _mm_shuffle_ps(v105, v105, 201);
            v107 = _mm_sub_ps(_mm_mul_ps(v105, v104), _mm_mul_ps(v106, vVector.m_quad));
            v108 = _mm_shuffle_ps(v107, v107, 201);
            v109 = _mm_mul_ps(v108, v108);
            v110 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v109, v109, 85), _mm_shuffle_ps(v109, v109, 0)),
                     _mm_shuffle_ps(v109, v109, 170));
            v111 = _mm_rsqrt_ps(v110);
            v112 = _mm_mul_ps(
                     v108,
                     _mm_andnot_ps(
                       _mm_cmpleps(v110, v62),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v111, v110), v111)),
                         _mm_mul_ps(v111, *(__m128 *)_xmm))));
            v113 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v112, v190), leftInOut.m_quad), v112);
            v114 = _mm_shuffle_ps(
                     v112,
                     _mm_unpackhi_ps(
                       v112,
                       _mm_sub_ps(
                         v62,
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v113, v113, 85), _mm_shuffle_ps(v113, v113, 0)),
                           _mm_shuffle_ps(v113, v113, 170)))),
                     196);
            v115 = _mm_sub_ps(rightEnd.m_quad, leftEnd.m_quad);
            v116 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v115, v115, 201), vVector.m_quad), _mm_mul_ps(v115, v104));
            v117 = _mm_shuffle_ps(v116, v116, 201);
            v118 = _mm_mul_ps(v117, v117);
            v119 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v118, v118, 85), _mm_shuffle_ps(v118, v118, 0)),
                     _mm_shuffle_ps(v118, v118, 170));
            v120 = _mm_rsqrt_ps(v119);
            v196 = v114;
            v121 = _mm_add_ps(_mm_mul_ps(v217, vVector.m_quad), leftInOut.m_quad);
            v122 = _mm_mul_ps(
                     v117,
                     _mm_andnot_ps(
                       _mm_cmpleps(v119, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v120, v119), v120)),
                         _mm_mul_ps(v120, *(__m128 *)_xmm))));
            v123 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v122, v190), leftEnd.m_quad), v122);
            v124 = _mm_add_ps(_mm_mul_ps(v209, vVector.m_quad), leftInOut.m_quad);
            v197 = _mm_shuffle_ps(
                     v122,
                     _mm_unpackhi_ps(
                       v122,
                       _mm_sub_ps(
                         (__m128)0i64,
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v123, v123, 85), _mm_shuffle_ps(v123, v123, 0)),
                           _mm_shuffle_ps(v123, v123, 170)))),
                     196);
            v125 = _mm_sub_ps(_mm_mul_ps(v112, v106), _mm_mul_ps(_mm_shuffle_ps(v112, v112, 201), v105));
            v126 = _mm_shuffle_ps(v125, v125, 201);
            v127 = _mm_mul_ps(v126, v126);
            v128 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v127, v127, 85), _mm_shuffle_ps(v127, v127, 0)),
                     _mm_shuffle_ps(v127, v127, 170));
            v129 = _mm_rsqrt_ps(v128);
            v130 = _mm_mul_ps(
                     v126,
                     _mm_andnot_ps(
                       _mm_cmpleps(v128, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v129, v128), v129)),
                         _mm_mul_ps(v129, *(__m128 *)_xmm))));
            v131 = _mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
            _mm_store_si128((__m128i *)&v186, v131);
            v132 = _mm_xor_ps(v130, (__m128)v131);
            v133 = _mm_mul_ps(v130, v121);
            v134 = _mm_mul_ps(v132, v124);
            v135 = v202;
            v198 = _mm_shuffle_ps(
                     v132,
                     _mm_unpackhi_ps(
                       v132,
                       _mm_sub_ps(
                         (__m128)0i64,
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v134, v134, 85), _mm_shuffle_ps(v134, v134, 0)),
                           _mm_shuffle_ps(v134, v134, 170)))),
                     196);
            v136 = _mm_mul_ps(v202, v99);
            v199 = _mm_shuffle_ps(
                     v130,
                     _mm_unpackhi_ps(
                       v130,
                       _mm_sub_ps(
                         (__m128)0i64,
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v133, v133, 85), _mm_shuffle_ps(v133, v133, 0)),
                           _mm_shuffle_ps(v133, v133, 170)))),
                     196);
            v137 = _mm_sub_ps(
                     v202,
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v136, v136, 85), _mm_shuffle_ps(v136, v136, 0)),
                         _mm_shuffle_ps(v136, v136, 170)),
                       v99));
            v138 = _mm_mul_ps(v137, v137);
            v139 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v138, v138, 85), _mm_shuffle_ps(v138, v138, 0)),
                     _mm_shuffle_ps(v138, v138, 170));
            v140 = _mm_rsqrt_ps(v139);
            v141 = _mm_mul_ps(
                     v137,
                     _mm_andnot_ps(
                       _mm_cmpleps(v139, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v140, v139), v140)),
                         _mm_mul_ps(v140, *(__m128 *)_xmm))));
            v142 = _mm_mul_ps(uVector.m_quad, uVector.m_quad);
            v143 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v142, v142, 85), _mm_shuffle_ps(v142, v142, 0)),
                     _mm_shuffle_ps(v142, v142, 170));
            v144 = _mm_rsqrt_ps(v143);
            extremalVector.m_quad = _mm_sub_ps(
                                      _mm_mul_ps(v206, v99),
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_andnot_ps(
                                            _mm_cmpleps(v143, (__m128)0i64),
                                            _mm_mul_ps(
                                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v144, v143), v144)),
                                              _mm_mul_ps(v144, *(__m128 *)_xmm))),
                                          uVector.m_quad),
                                        v204));
            v145 = 0;
            if ( v98 > 0 )
            {
              v146 = v208.m128_f32[0];
              v147 = (__m128)_mm_load_si128((const __m128i *)&v186);
              do
              {
                v148 = (unsigned int *)hkaiIntervalPartition::getInterval(&uPartition, v145);
                v149 = v148[3];
                v150 = _mm_shuffle_ps((__m128)*v148, (__m128)*v148, 0);
                v151 = (__m128)v148[1];
                DWORD2(v186) = v148[2];
                v152 = v148[4];
                v153 = _mm_shuffle_ps(v151, v151, 0);
                HIDWORD(v186) = v149;
                v187 = v152;
                v154 = _mm_sub_ps(rightInOut.m_quad, leftInOut.m_quad);
                v155 = _mm_add_ps(_mm_mul_ps(v150, v154), leftInOut.m_quad);
                v156 = _mm_add_ps(_mm_mul_ps(v153, v154), leftInOut.m_quad);
                v157 = _mm_sub_ps(v155, v156);
                v158 = _mm_mul_ps(v157, v157);
                if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v158, v158, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v158, v158, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v158, v158, 170))) >= v146 )
                {
                  v159 = _mm_sub_ps(rightEnd.m_quad, leftEnd.m_quad);
                  v160 = _mm_add_ps(_mm_mul_ps(v150, v159), leftEnd.m_quad);
                  left.m_quad = _mm_add_ps(_mm_mul_ps(v150, v135), v69);
                  v161 = _mm_add_ps(_mm_mul_ps(v153, v159), leftEnd.m_quad);
                  right.m_quad = _mm_add_ps(_mm_mul_ps(v153, v135), v69);
                  hkaiUserEdgeUtils::UserEdgePair::UserEdgePair(&userEdgePair);
                  v162 = v3->m_fromNavMeshInstance;
                  v163 = v2->m_userdata;
                  v164 = _mm_shuffle_ps(v155, v156, 68);
                  v165 = _mm_shuffle_ps(v161, v160, 68);
                  userEdgePair.m_x.m_quad = _mm_shuffle_ps(v164, v165, 136);
                  v159.m128_i32[0] = LODWORD(v2->m_baseCost);
                  userEdgePair.m_y.m_quad = _mm_shuffle_ps(v164, v165, 221);
                  userEdgePair.m_z.m_quad = _mm_shuffle_ps(
                                              _mm_shuffle_ps(v155, v156, 238),
                                              _mm_shuffle_ps(v161, v160, 238),
                                              136);
                  v166 = v162->m_sectionUid;
                  v167 = v3->m_toNavMeshInstance;
                  userEdgePair.m_instanceUidA = v166;
                  v168 = v167->m_sectionUid;
                  retaddr = v159.m128_f32[0] * 1.0039062;
                  userEdgePair.m_faceA = v59[v58].m_startFace;
                  LODWORD(v167) = v59[v58].m_endFace;
                  userEdgePair.m_instanceUidB = v168;
                  v169 = v3->m_outputLibrary;
                  userEdgePair.m_faceB = (signed int)v167;
                  userEdgePair.m_direction.m_storage = 1;
                  userEdgePair.m_costBtoA.m_value = 0;
                  userEdgePair.m_costAtoB.m_value = HIWORD(retaddr);
                  v170 = hkaiTraversalAnnotationLibrary::addAnnotation(
                           v169,
                           &userEdgePair,
                           HKAI_TRAVERSAL_TYPE_VAULT,
                           v163);
                  clippingPlanes.m_data[4].m_quad = _mm_xor_ps(v141, v147);
                  v171 = _mm_mul_ps(clippingPlanes.m_data[4].m_quad, v155);
                  clippingPlanes.m_data[4].m_quad = _mm_shuffle_ps(
                                                      clippingPlanes.m_data[4].m_quad,
                                                      _mm_unpackhi_ps(
                                                        clippingPlanes.m_data[4].m_quad,
                                                        _mm_sub_ps(
                                                          (__m128)0i64,
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_shuffle_ps(v171, v171, 85),
                                                              _mm_shuffle_ps(v171, v171, 0)),
                                                            _mm_shuffle_ps(v171, v171, 170)))),
                                                      196);
                  clippingPlanes.m_data[5].m_quad = v141;
                  v172 = _mm_mul_ps(clippingPlanes.m_data[5].m_quad, v156);
                  clippingPlanes.m_data[5].m_quad = _mm_shuffle_ps(
                                                      clippingPlanes.m_data[5].m_quad,
                                                      _mm_unpackhi_ps(
                                                        clippingPlanes.m_data[5].m_quad,
                                                        _mm_sub_ps(
                                                          (__m128)0i64,
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_shuffle_ps(v172, v172, 85),
                                                              _mm_shuffle_ps(v172, v172, 0)),
                                                            _mm_shuffle_ps(v172, v172, 170)))),
                                                      196);
                  hkaiIntervalPartition::hkaiIntervalPartition((hkaiIntervalPartition *)((char *)&uPartition + 8));
                  hkaiIntervalPartition::hkaiIntervalPartition(&intervalPartition);
                  hkaiGeometrySegmentCaster::findExtremalProfile(
                    v3->m_cuttingGeometrySegmentCaster.m_pntr,
                    &clippingPlanes,
                    &left,
                    &right,
                    &extremalVector,
                    &uVector,
                    &vVector,
                    (hkaiIntervalPartition *)((char *)&uPartition + 8),
                    &intervalPartition);
                  hkaiTraversalAnnotationLibrary::addIntervalPartition(
                    v3->m_outputLibrary,
                    v170,
                    0,
                    (hkaiIntervalPartition *)((char *)&uPartition + 8),
                    1,
                    0);
                  hkaiTraversalAnnotationLibrary::addIntervalPartition(
                    v3->m_outputLibrary,
                    v170,
                    1,
                    &intervalPartition,
                    1,
                    0);
                  hkaiTraversalAnnotationLibrary::addVector(v3->m_outputLibrary, v170, 0, &left);
                  hkaiTraversalAnnotationLibrary::addVector(v3->m_outputLibrary, v170, 1, &right);
                  hkaiTraversalAnnotationLibrary::addVector(v3->m_outputLibrary, v170, 2, &uVector);
                  intervalPartition.m_intervals.m_size = 0;
                  if ( intervalPartition.m_intervals.m_capacityAndFlags >= 0 )
                    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                      intervalPartition.m_intervals.m_data,
                      20 * (intervalPartition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
                  intervalPartition.m_intervals.m_data = 0i64;
                  intervalPartition.m_intervals.m_capacityAndFlags = 2147483648;
                  v176 = 0;
                  if ( v177 >= 0 )
                    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                      *(void **)&uPartition.m_intervals.m_size,
                      20 * (v177 & 0x3FFFFFFF));
                  *(_QWORD *)&uPartition.m_intervals.m_size = 0i64;
                  v177 = 2147483648;
                }
                ++v145;
              }
              while ( v145 < v98 );
              v101 = clippingPlanes.m_capacityAndFlags;
              v100 = clippingPlanes.m_data;
              v57 = FLOAT_0_0099999998;
            }
            clippingPlanes.m_size = 0;
            if ( v101 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                v100,
                16 * v101);
            clippingPlanes.m_data = 0i64;
            clippingPlanes.m_capacityAndFlags = 2147483648;
            uPartition.m_intervals.m_size = 0;
            if ( uPartition.m_intervals.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                uPartition.m_intervals.m_data,
                20 * (uPartition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
            uPartition.m_intervals.m_data = 0i64;
            uPartition.m_intervals.m_capacityAndFlags = 2147483648;
            partition.m_intervals.m_size = 0;
            if ( partition.m_intervals.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                partition.m_intervals.m_data,
                20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
            partition.m_intervals.m_data = 0i64;
            partition.m_intervals.m_capacityAndFlags = 2147483648;
            clearZonesOut.m_intervals.m_size = 0;
            if ( clearZonesOut.m_intervals.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                clearZonesOut.m_intervals.m_data,
                20 * (clearZonesOut.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
            v56 = *(float *)&FLOAT_1_0;
            v43 = v224;
          }
          else
          {
            uPartition.m_intervals.m_size = 0;
            if ( uPartition.m_intervals.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                uPartition.m_intervals.m_data,
                20 * (uPartition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
            uPartition.m_intervals.m_data = 0i64;
            uPartition.m_intervals.m_capacityAndFlags = 2147483648;
            partition.m_intervals.m_size = 0;
            if ( partition.m_intervals.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                partition.m_intervals.m_data,
                20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
            partition.m_intervals.m_data = 0i64;
            partition.m_intervals.m_capacityAndFlags = 2147483648;
            clearZonesOut.m_intervals.m_size = 0;
            if ( clearZonesOut.m_intervals.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                clearZonesOut.m_intervals.m_data,
                20 * (clearZonesOut.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
          }
          v40 = v194;
          v39 = v192;
          goto LABEL_48;
        }
        partition.m_intervals.m_size = 0;
        if ( partition.m_intervals.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            partition.m_intervals.m_data,
            20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
        partition.m_intervals.m_data = 0i64;
        partition.m_intervals.m_capacityAndFlags = 2147483648;
      }
      clearZonesOut.m_intervals.m_size = 0;
      if ( clearZonesOut.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          clearZonesOut.m_intervals.m_data,
          20 * (clearZonesOut.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
LABEL_48:
      ++v58;
      --v43;
      clearZonesOut.m_intervals.m_capacityAndFlags = 2147483648;
      v224 = v43;
      clearZonesOut.m_intervals.m_data = 0i64;
    }
    while ( v43 );
  }
  pairsOut.m_size = 0;
  if ( pairsOut.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      pairsOut.m_data,
      80 * (pairsOut.m_capacityAndFlags & 0x3FFFFFFF));
}ervals.m_capacityAndFlags & 0x3FFFFFFF));
        partition.m_intervals.m_data = 0i64;
        partition.m_intervals.m_capacityAndFlags = 2147483648;
      }
      clearZonesOut.m_intervals.m_size = 0;
      if ( clearZonesOut.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          clearZonesOut.m_intervals.m_data,
          20 * (clearZonesOut.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
LABEL_48:
      ++v58;
      --v43;
      clearZonesOut.m_intervals.m_capacityAndFlags = 2147483648;
      v224 = v43;
      clearZonesOut.m_intervals.m_data = 0i64;
    }
    while ( v43 );
  }
  pairsOut.m_size = 0;
  if ( pairsOut.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_al

// File Line: 308
// RVA: 0xC39500
signed __int64 __fastcall hkaiVaultUtils::getHandPlantPoint(hkaiTraversalAnnotationLibrary *library, unsigned int *annotationIndex, hkVector4f *handPos, hkVector4f *handPlantPointOut, hkVector4f *handPlantFwdDirOut)
{
  hkVector4f *v5; // rsi
  unsigned int *v6; // rdi
  hkaiTraversalAnnotationLibrary *v7; // rbx
  unsigned int v8; // edx
  signed __int64 v9; // rax
  unsigned int v10; // edx
  __m128 v11; // xmm3
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm5
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  float tInOut; // [rsp+30h] [rbp-58h]
  float y; // [rsp+34h] [rbp-54h]
  float v21; // [rsp+38h] [rbp-50h]
  hkSimdFloat32 result; // [rsp+40h] [rbp-48h]
  hkVector4f v23; // [rsp+50h] [rbp-38h]
  hkVector4f vecOut; // [rsp+60h] [rbp-28h]
  hkVector4f v25; // [rsp+70h] [rbp-18h]

  v5 = handPlantPointOut;
  v6 = annotationIndex;
  v7 = library;
  hkaiTraversalAnnotationLibrary::evaluateT(library, &result, *annotationIndex, handPos);
  v8 = *v6;
  tInOut = result.m_real.m128_f32[0];
  if ( !hkaiTraversalAnnotationLibrary::getClosestDefined(v7, v8, 0, &tInOut) )
    return 0i64;
  v10 = *v6;
  result.m_real = _mm_shuffle_ps((__m128)LODWORD(tInOut), (__m128)LODWORD(tInOut), 0);
  if ( !hkaiTraversalAnnotationLibrary::tryEvaluateYAt(v7, v10, 0, result.m_real.m128_f32[0], &y) )
    return 0i64;
  hkaiTraversalAnnotationLibrary::tryEvaluateYAt(v7, *v6, 1, result.m_real.m128_f32[0], &v21);
  hkaiTraversalAnnotationLibrary::getVectorData(v7, *v6, 0, &vecOut);
  hkaiTraversalAnnotationLibrary::getVectorData(v7, *v6, 1, &v23);
  hkaiTraversalAnnotationLibrary::getVectorData(v7, *v6, 2, &v25);
  v9 = 1i64;
  v11 = v7->m_up.m_quad;
  v12 = _mm_sub_ps(v23.m_quad, vecOut.m_quad);
  v13 = _mm_mul_ps(_mm_shuffle_ps(v7->m_up.m_quad, v11, 201), v12);
  v5->m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_mul_ps(v12, result.m_real), vecOut.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(y), (__m128)LODWORD(y), 0), v25.m_quad)),
                 _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v21), (__m128)LODWORD(v21), 0), v11));
  v14 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v11), v13);
  v15 = _mm_shuffle_ps(v14, v14, 201);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  handPlantFwdDirOut->m_quad = _mm_mul_ps(
                                 _mm_andnot_ps(
                                   _mm_cmpleps(v17, (__m128)0i64),
                                   _mm_mul_ps(
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                     _mm_mul_ps(*(__m128 *)_xmm, v18))),
                                 v15);
  return v9;
}

// File Line: 360
// RVA: 0xC396B0
__int64 __fastcall hkaiVaultUtils::getNumHandPlantSegments(hkaiTraversalAnnotationLibrary *library, unsigned int *annotationIndex)
{
  return hkaiTraversalAnnotationLibrary::getNumPartitionIntervals(library, *annotationIndex, 0);
}

// File Line: 370
// RVA: 0xC396D0
void __fastcall hkaiVaultUtils::getHandPlantSegment(hkaiTraversalAnnotationLibrary *library, unsigned int *annotationIndex, int handPlantSegmentIndex, hkVector4f *leftPointOut, hkVector4f *rightPointOut)
{
  unsigned int *v5; // rdi
  hkVector4f *v6; // rbp
  unsigned __int16 v7; // bx
  hkaiTraversalAnnotationLibrary *v8; // rsi
  __m128 v9; // xmm6
  hkVector2f v10; // rax
  hkVector2f v11; // rax
  hkVector4f vecOut; // [rsp+30h] [rbp-88h]
  hkVector4f v13; // [rsp+40h] [rbp-78h]
  hkVector4f yVector; // [rsp+50h] [rbp-68h]
  hkVector4f xVector; // [rsp+60h] [rbp-58h]
  hkaiIntervalPartition::Interval v16; // [rsp+70h] [rbp-48h]
  hkaiIntervalPartition::Interval intervalOut; // [rsp+88h] [rbp-30h]

  v5 = annotationIndex;
  v6 = leftPointOut;
  v7 = handPlantSegmentIndex;
  v8 = library;
  hkaiTraversalAnnotationLibrary::getPartitionInterval(
    library,
    *annotationIndex,
    0,
    handPlantSegmentIndex,
    &intervalOut);
  hkaiTraversalAnnotationLibrary::getPartitionInterval(v8, *v5, 1, v7, &v16);
  hkaiTraversalAnnotationLibrary::getVectorData(v8, *v5, 0, &vecOut);
  hkaiTraversalAnnotationLibrary::getVectorData(v8, *v5, 1, &v13);
  hkaiTraversalAnnotationLibrary::getVectorData(v8, *v5, 2, &yVector);
  v9 = v8->m_up.m_quad;
  xVector.m_quad = _mm_sub_ps(v13.m_quad, vecOut.m_quad);
  hkaiIntervalPartition::Interval::interpolateParallelogram(
    &intervalOut,
    &vecOut,
    &xVector,
    &yVector,
    v6,
    rightPointOut);
  v10 = hkaiIntervalPartition::Interval::getLeftEndpoint(&v16);
  v6->m_quad = _mm_add_ps(
                 v6->m_quad,
                 _mm_mul_ps(
                   _mm_shuffle_ps(
                     (__m128)*(unsigned int *)(*(_QWORD *)&v10 + 4i64),
                     (__m128)*(unsigned int *)(*(_QWORD *)&v10 + 4i64),
                     0),
                   v9));
  v11 = hkaiIntervalPartition::Interval::getRightEndpoint(&v16);
  rightPointOut->m_quad = _mm_add_ps(
                            rightPointOut->m_quad,
                            _mm_mul_ps(
                              _mm_shuffle_ps(
                                (__m128)*(unsigned int *)(*(_QWORD *)&v11 + 4i64),
                                (__m128)*(unsigned int *)(*(_QWORD *)&v11 + 4i64),
                                0),
                              v9));
}


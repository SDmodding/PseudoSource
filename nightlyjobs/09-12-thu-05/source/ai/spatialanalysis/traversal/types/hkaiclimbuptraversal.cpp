// File Line: 24
// RVA: 0xC32CD0
void __fastcall hkaiClimbUpAnalyzer::analyze(hkaiClimbUpAnalyzer *this, hkaiTraversalAnalysisContext *context)
{
  hkaiClimbUpAnalyzer *v2; // r13
  hkaiTraversalAnalysisContext *v3; // rdi
  __m128i v4; // xmm3
  float v5; // xmm8_4
  hkaiTraversalAnalysisSettings *v6; // rax
  __m128 v7; // xmm7
  __m128 v8; // xmm2
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  __m128i v12; // xmm4
  __m128i v13; // xmm6
  __m128 v14; // xmm5
  __m128 v15; // xmm0
  __m128 v16; // xmm4
  __m128 v17; // xmm3
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
  int v29; // esi
  __m128 v30; // xmm6
  __m128 v31; // xmm2
  __m128i v32; // xmm7
  __m128 v33; // xmm5
  __m128 v34; // xmm0
  __m128 v35; // xmm4
  __m128 v36; // xmm2
  __m128i v37; // xmm1
  __m128 v38; // xmm8
  __m128 v39; // xmm0
  __m128i v40; // xmm5
  __m128 v41; // xmm2
  __m128i v42; // xmm7
  __m128i v43; // xmm5
  __m128 v44; // xmm1
  __m128 v45; // xmm4
  __m128 v46; // xmm3
  __m128 v47; // xmm2
  __m128 v48; // xmm9
  hkVector4f *v49; // r9
  __int64 v50; // rbx
  __int64 v51; // r14
  hkaiPairedEdgeFinder::EdgePair *v52; // r15
  hkaiNavMeshUtils *v53; // rcx
  hkVector4f *v54; // r9
  __m128 v55; // xmm1
  __m128 v56; // xmm0
  __m128 v57; // xmm1
  __m128 v58; // xmm6
  __m128 v59; // xmm3
  __m128 v60; // xmm1
  __m128 v61; // xmm4
  __m128 v62; // xmm5
  __m128 v63; // xmm2
  __m128 v64; // xmm6
  int v65; // er12
  bool v66; // zf
  bool v67; // sf
  __m128 v68; // xmm15
  __m128 v69; // xmm10
  __m128 v70; // xmm11
  hkVector4f *v71; // rdx
  int v72; // er8
  __m128 v73; // xmm9
  __m128 v74; // xmm5
  __m128 v75; // xmm5
  __m128 v76; // xmm1
  __m128 v77; // xmm3
  __m128 v78; // xmm2
  __m128 v79; // xmm5
  __m128 v80; // xmm2
  __m128 v81; // xmm8
  __m128i v82; // xmm0
  __m128 v83; // xmm6
  __m128 v84; // xmm7
  __m128 v85; // xmm4
  __m128 v86; // xmm4
  __m128 v87; // xmm1
  __m128 v88; // xmm3
  __m128 v89; // xmm2
  __m128 v90; // xmm5
  __m128 v91; // xmm2
  __m128 v92; // xmm5
  __m128 v93; // xmm2
  __m128 v94; // xmm10
  __m128 v95; // xmm1
  __m128 v96; // xmm10
  __m128 v97; // xmm1
  __m128 v98; // xmm6
  __m128 v99; // xmm3
  __m128 v100; // xmm2
  __m128 v101; // xmm1
  __m128 v102; // xmm10
  __m128 v103; // xmm6
  __m128 v104; // xmm1
  __m128 v105; // xmm2
  __m128 v106; // xmm1
  __m128i v107; // xmm12
  unsigned int *v108; // rax
  unsigned int v109; // xmm1_4
  __m128 v110; // xmm8
  __m128 v111; // xmm7
  int v112; // xmm0_4
  __m128 v113; // xmm7
  __m128 v114; // xmm0
  __m128 v115; // xmm6
  __m128 v116; // xmm9
  __m128 v117; // xmm2
  __m128 v118; // xmm2
  __m128 v119; // xmm0
  __m128 v120; // xmm8
  __m128 v121; // xmm7
  hkaiNavMeshInstance *v122; // rax
  unsigned int v123; // er9
  __m128 v124; // xmm2
  __m128 v125; // xmm1
  unsigned int v126; // ecx
  hkaiNavMeshInstance *v127; // rax
  unsigned int v128; // ecx
  hkaiTraversalAnnotationLibrary *v129; // rcx
  unsigned int v130; // ebx
  __m128 v131; // xmm3
  __m128 v132; // xmm2
  __m128 v133; // xmm3
  __m128 v134; // xmm2
  hkaiIntervalPartition other; // [rsp+50h] [rbp-A8h]
  hkaiIntervalPartition reachableAreasOut; // [rsp+60h] [rbp-98h]
  hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> pairsOut; // [rsp+70h] [rbp-88h]
  hkaiIntervalPartition intervalPartition; // [rsp+88h] [rbp-70h]
  hkaiIntervalPartition uPartition; // [rsp+98h] [rbp-60h]
  hkVector4f leftEnd; // [rsp+A8h] [rbp-50h]
  hkVector4f leftInOut; // [rsp+B8h] [rbp-40h]
  hkaiIntervalPartition v142; // [rsp+C8h] [rbp-30h]
  hkVector4f rightEnd; // [rsp+D8h] [rbp-20h]
  hkaiIntervalPartition v144; // [rsp+E8h] [rbp-10h]
  hkaiIntervalPartition v145; // [rsp+F8h] [rbp+0h]
  hkVector4f rightInOut; // [rsp+108h] [rbp+10h]
  hkaiIntervalPartition v147; // [rsp+118h] [rbp+20h]
  hkVector4f vVector; // [rsp+128h] [rbp+30h]
  hkVector4f topRightIn; // [rsp+138h] [rbp+40h]
  hkVector4f left; // [rsp+148h] [rbp+50h]
  hkVector4f right; // [rsp+158h] [rbp+60h]
  hkVector4f bottomLeftIn; // [rsp+168h] [rbp+70h]
  hkVector4f bottomRightIn; // [rsp+178h] [rbp+80h]
  __int128 v154; // [rsp+188h] [rbp+90h]
  int v155; // [rsp+198h] [rbp+A0h]
  hkaiPairedEdgeFinder::PairedEdgeSettings settings; // [rsp+1A8h] [rbp+B0h]
  hkVector4f uVector; // [rsp+1E8h] [rbp+F0h]
  hkArrayBase<hkVector4f> clippingPlanes; // [rsp+1F8h] [rbp+100h]
  __m128 v159; // [rsp+208h] [rbp+110h]
  __m128 v160; // [rsp+218h] [rbp+120h]
  __m128 v161; // [rsp+228h] [rbp+130h]
  __m128 v162; // [rsp+238h] [rbp+140h]
  hkaiUserEdgeUtils::UserEdgePair userEdgePair; // [rsp+268h] [rbp+170h]
  __m128 v164; // [rsp+2B8h] [rbp+1C0h]
  int faceIndex; // [rsp+2C8h] [rbp+1D0h]
  __m128 v166; // [rsp+2D8h] [rbp+1E0h]
  __m128 v167; // [rsp+2E8h] [rbp+1F0h]
  hkVector4f extremalVector; // [rsp+2F8h] [rbp+200h]
  hkVector4f facePlane; // [rsp+308h] [rbp+210h]
  float retaddr; // [rsp+3F8h] [rbp+300h]
  __int64 v171; // [rsp+400h] [rbp+308h]

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
  v9 = v2->m_minUpHeight;
  settings.m_minLength = v6->m_minEdgeLength;
  v10 = v2->m_maxUpHeight;
  settings.m_minHeightDelta = v9;
  settings.m_maxHeightDelta = v10;
  v11 = v2->m_maxUnderhang;
  v12 = _mm_add_epi32(v4, v4);
  _mm_store_si128((__m128i *)&pairsOut.m_size, v12);
  settings.m_maxHorizontalDelta = v11;
  settings.m_minHorizontalDelta = 0.0;
  v13 = _mm_andnot_si128(v4, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v8, *(__m128 *)_xmm)), v4));
  v14 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v13, v12), (__m128i)0i64);
  v15 = _mm_cvtepi32_ps(v13);
  v16 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v15, *(__m128 *)DP1_0), v8), _mm_mul_ps(v15, *(__m128 *)DP2)),
          _mm_mul_ps(v15, *(__m128 *)DP3));
  v17 = _mm_mul_ps(v16, v16);
  v8.m128_i32[0] = (unsigned __int128)_mm_andnot_ps(
                                        v14,
                                        _mm_add_ps(
                                          _mm_sub_ps(
                                            _mm_mul_ps(
                                              _mm_mul_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(
                                                    _mm_add_ps(
                                                      _mm_mul_ps(v17, *(__m128 *)cosCoeff0_0),
                                                      *(__m128 *)cosCoeff1),
                                                    v17),
                                                  *(__m128 *)cosCoeff2_0),
                                                v17),
                                              v17),
                                            _mm_mul_ps(v17, *(__m128 *)_xmm)),
                                          *(__m128 *)_xmm));
  v15.m128_f32[0] = (float)((float)((float)((float)(v17.m128_f32[0] * -0.00019515296) + 0.0083321612) * v17.m128_f32[0])
                          + -0.16666655)
                  * v17.m128_f32[0];
  v18 = _mm_load_si128((const __m128i *)&pairsOut.m_size);
  v8.m128_i32[0] |= COERCE_UNSIGNED_INT((float)(v15.m128_f32[0] * v16.m128_f32[0]) + v16.m128_f32[0]) & v14.m128_i32[0];
  v15.m128_i32[0] = (unsigned __int128)_mm_and_si128(_mm_add_epi32(v18, v18), v13);
  v19 = _mm_load_si128((const __m128i *)_xmm);
  LODWORD(settings.m_cosMaxPlanarAngle) = v8.m128_i32[0] ^ (v15.m128_i32[0] << 29) ^ v7.m128_i32[0] & _xmm[0];
  v20 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(v5));
  v21 = _mm_andnot_si128(v19, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v20, *(__m128 *)_xmm)), v19));
  v22 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v21, v18), (__m128i)0i64);
  v23 = _mm_cvtepi32_ps(v21);
  v24 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v23, *(__m128 *)DP1_0), v20), _mm_mul_ps(v23, *(__m128 *)DP2)),
          _mm_mul_ps(v23, *(__m128 *)DP3));
  v25 = _mm_mul_ps(v24, v24);
  v23.m128_f32[0] = (float)((float)((float)((float)((float)((float)(v25.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                                  * v25.m128_f32[0])
                                          + -0.16666655)
                                  * v25.m128_f32[0])
                          * v24.m128_f32[0])
                  + v24.m128_f32[0];
  v26 = _mm_load_si128((const __m128i *)&pairsOut.m_size);
  v18.m128i_i32[0] = (*(unsigned __int128 *)&_mm_andnot_ps(
                                               v22,
                                               _mm_add_ps(
                                                 _mm_sub_ps(
                                                   _mm_mul_ps(
                                                     _mm_mul_ps(
                                                       _mm_add_ps(
                                                         _mm_mul_ps(
                                                           _mm_add_ps(
                                                             _mm_mul_ps(v25, *(__m128 *)cosCoeff0_0),
                                                             *(__m128 *)cosCoeff1),
                                                           v25),
                                                         *(__m128 *)cosCoeff2_0),
                                                       v25),
                                                     v25),
                                                   _mm_mul_ps(v25, *(__m128 *)_xmm)),
                                                 *(__m128 *)_xmm)) | v23.m128_i32[0] & v22.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v26, v26), v21) << 29) ^ LODWORD(v5) & _xmm[0];
  v23.m128_i32[0] = LODWORD(v2->m_maxRelativeSlopeAngle);
  LODWORD(settings.m_sinMaxPlanarAngle) = v18.m128i_i32[0];
  v27 = _mm_load_si128((const __m128i *)_xmm);
  v28 = v3->m_pairedEdgeFinder.m_pntr;
  retaddr = v23.m128_f32[0];
  v29 = 0;
  *(_WORD *)&settings.m_matchAngles.m_bool = 257;
  v30 = _mm_add_ps((__m128)v23.m128_u32[0], *(__m128 *)_xmm);
  pairsOut.m_data = 0i64;
  pairsOut.m_size = 0;
  pairsOut.m_capacityAndFlags = 2147483648;
  v31 = _mm_andnot_ps(*(__m128 *)_xmm, v30);
  v32 = _mm_andnot_si128(v27, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v31, *(__m128 *)_xmm)), v27));
  v33 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v32, v26), (__m128i)0i64);
  v34 = _mm_cvtepi32_ps(v32);
  v35 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v34, *(__m128 *)DP1_0), v31), _mm_mul_ps(v34, *(__m128 *)DP2)),
          _mm_mul_ps(v34, *(__m128 *)DP3));
  v36 = _mm_mul_ps(v35, v35);
  v37 = _mm_load_si128((const __m128i *)&pairsOut.m_size);
  LODWORD(settings.m_cosMaxDeltaSlopeAngle) = (*(unsigned __int128 *)&_mm_andnot_ps(
                                                                        v33,
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
                                                                          *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                                                (float)((float)((float)((float)((float)((float)(v36.m128_f32[0] * -0.00019515296) + 0.0083321612) * v36.m128_f32[0]) + -0.16666655) * v36.m128_f32[0]) * v35.m128_f32[0])
                                                                                              + v35.m128_f32[0]) & v33.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v37, v37), v32) << 29) ^ v30.m128_i32[0] & _xmm[0];
  hkaiPairedEdgeFinder::findEdgePairs(v28, &settings, &pairsOut);
  hkaiIntervalPartition::hkaiIntervalPartition(&reachableAreasOut);
  hkaiIntervalPartition::hkaiIntervalPartition(&v144);
  hkaiIntervalPartition::hkaiIntervalPartition(&v142);
  v38 = _mm_add_ps(
          _mm_shuffle_ps((__m128)LODWORD(v2->m_grabAngle), (__m128)LODWORD(v2->m_grabAngle), 0),
          *(__m128 *)offset_1);
  v39 = _mm_shuffle_ps(
          (__m128)LODWORD(v3->m_settings->m_minEdgeLength),
          (__m128)LODWORD(v3->m_settings->m_minEdgeLength),
          0);
  v166 = _mm_mul_ps(v39, v39);
  v40 = _mm_load_si128((const __m128i *)_xmm);
  v41 = _mm_andnot_ps(*(__m128 *)_xmm, v38);
  v42 = _mm_add_epi32(v40, v40);
  v43 = _mm_andnot_si128(v40, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v41, *(__m128 *)_xmm)), v40));
  v44 = _mm_cvtepi32_ps(v43);
  v45 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v43, v42), (__m128i)0i64);
  v46 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v44, *(__m128 *)DP1_0), v41), _mm_mul_ps(v44, *(__m128 *)DP2)),
          _mm_mul_ps(v44, *(__m128 *)DP3));
  v47 = _mm_mul_ps(v46, v46);
  v48 = _mm_xor_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              v45,
              _mm_add_ps(
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v47, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v47),
                        *(__m128 *)cosCoeff2_0),
                      v47),
                    v47),
                  _mm_mul_ps(v47, *(__m128 *)_xmm)),
                *(__m128 *)_xmm)),
            _mm_and_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v47, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v47),
                      *(__m128 *)sinCoeff2_0),
                    v47),
                  v46),
                v46),
              v45)),
          _mm_xor_ps(
            (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v42, v42), v43), 0x1Du),
            _mm_and_ps(v38, *(__m128 *)_xmm)));
  v167 = _mm_shuffle_ps(v48, v48, 85);
  v164 = _mm_shuffle_ps(v48, v48, 0);
  hkaiIntervalPartition::hkaiIntervalPartition(&v145);
  hkaiIntervalPartition::hkaiIntervalPartition(&v147);
  v50 = pairsOut.m_size;
  v171 = pairsOut.m_size;
  if ( pairsOut.m_size > 0i64 )
  {
    v51 = 0i64;
    do
    {
      v52 = pairsOut.m_data;
      v53 = (hkaiNavMeshUtils *)v3->m_fromNavMeshInstance;
      _mm_store_si128((__m128i *)&leftInOut, (__m128i)pairsOut.m_data[v51].m_startLeft.m_quad);
      _mm_store_si128((__m128i *)&rightInOut, (__m128i)v52[v51].m_startRight.m_quad);
      _mm_store_si128((__m128i *)&leftEnd, (__m128i)v52[v51].m_endLeft.m_quad);
      _mm_store_si128((__m128i *)&rightEnd, (__m128i)v52[v51].m_endRight.m_quad);
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        v53,
        (hkaiNavMeshInstance *)(unsigned int)v52[v51].m_startFace,
        (__int64)&faceIndex,
        v49);
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)v3->m_toNavMeshInstance,
        (hkaiNavMeshInstance *)(unsigned int)v52[v51].m_endFace,
        (__int64)&facePlane,
        v54);
      hkaiTraversalAnalysisUtils::setBackEdge(&leftInOut, &rightInOut, (hkVector4f *)&faceIndex, v3);
      hkaiTraversalAnalysisUtils::setBackEdge(&rightEnd, &leftEnd, &facePlane, v3);
      hkaiIntervalPartition::hkaiIntervalPartition(&other);
      hkaiTraversalAnalysisUtils::filterUnwalkableLandingZones(
        &leftInOut,
        &rightInOut,
        &leftEnd,
        &rightEnd,
        v52[v51].m_startFace,
        v52[v51].m_endFace,
        &other,
        v3);
      if ( other.m_intervals.m_size )
      {
        v55 = rightInOut.m_quad;
        _mm_store_si128((__m128i *)&bottomLeftIn, (__m128i)leftInOut.m_quad);
        v56 = leftEnd.m_quad;
        _mm_store_si128((__m128i *)&bottomRightIn, (__m128i)v55);
        v57 = rightEnd.m_quad;
        _mm_store_si128((__m128i *)&pairsOut.m_size, (__m128i)v56);
        _mm_store_si128((__m128i *)&topRightIn, (__m128i)v57);
        if ( hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&bottomLeftIn, &bottomRightIn, v3) )
        {
          if ( hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&topRightIn, (hkVector4f *)&pairsOut.m_size, v3) )
          {
            v58 = _mm_mul_ps(bottomLeftIn.m_quad, vVector.m_quad);
            v59 = _mm_mul_ps(bottomRightIn.m_quad, vVector.m_quad);
            v60 = _mm_mul_ps(topRightIn.m_quad, vVector.m_quad);
            v61 = _mm_mul_ps(*(__m128 *)&pairsOut.m_size, vVector.m_quad);
            v62 = _mm_shuffle_ps(v58, v59, 68);
            v63 = _mm_shuffle_ps(v61, v60, 68);
            v64 = _mm_add_ps(
                    _mm_shuffle_ps(_mm_shuffle_ps(v58, v59, 238), _mm_shuffle_ps(v61, v60, 238), 136),
                    _mm_add_ps(_mm_shuffle_ps(v62, v63, 221), _mm_shuffle_ps(v62, v63, 136)));
            if ( fmax(COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 0)), COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 85))) < fmin(COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 170)), COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 255))) )
            {
              hkaiIntervalPartition::clear(&reachableAreasOut);
              hkaiTraversalAnalysisUtils::findOverLedgeReachability(
                &bottomLeftIn,
                &bottomRightIn,
                (hkVector4f *)&pairsOut.m_size,
                &topRightIn,
                v3,
                &reachableAreasOut);
              hkaiIntervalPartition::clipNotDefined(&reachableAreasOut, &other);
              v65 = reachableAreasOut.m_intervals.m_size;
              v66 = reachableAreasOut.m_intervals.m_size == 0;
              v67 = reachableAreasOut.m_intervals.m_size < 0;
              if ( reachableAreasOut.m_intervals.m_size )
              {
                v68 = vVector.m_quad;
                v69 = _mm_sub_ps(rightEnd.m_quad, leftEnd.m_quad);
                v70 = _mm_shuffle_ps((__m128)LODWORD(v2->m_grabScanDepth), (__m128)LODWORD(v2->m_grabScanDepth), 0);
                v71 = (hkVector4f *)&v159;
                v72 = -2147483642;
                clippingPlanes.m_size = 6;
                clippingPlanes.m_data = (hkVector4f *)&v159;
                clippingPlanes.m_capacityAndFlags = -2147483642;
                v73 = _mm_shuffle_ps(v69, v69, 201);
                v74 = _mm_sub_ps(
                        _mm_mul_ps(vVector.m_quad, v73),
                        _mm_mul_ps(_mm_shuffle_ps(vVector.m_quad, vVector.m_quad, 201), v69));
                v75 = _mm_shuffle_ps(v74, v74, 201);
                v76 = _mm_mul_ps(v75, v75);
                v77 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), _mm_shuffle_ps(v76, v76, 0)),
                        _mm_shuffle_ps(v76, v76, 170));
                v78 = _mm_rsqrt_ps(v77);
                v79 = _mm_mul_ps(
                        v75,
                        _mm_andnot_ps(
                          _mm_cmpleps(v77, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v78, v77), v78)),
                            _mm_mul_ps(*(__m128 *)_xmm, v78))));
                v80 = _mm_mul_ps(v79, leftEnd.m_quad);
                v81 = _mm_shuffle_ps(
                        v79,
                        _mm_unpackhi_ps(
                          v79,
                          _mm_sub_ps(
                            (__m128)0i64,
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v80, v80, 85), _mm_shuffle_ps(v80, v80, 0)),
                              _mm_shuffle_ps(v80, v80, 170)))),
                        196);
                v82 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
                _mm_store_si128((__m128i *)&v154, v82);
                v83 = (__m128)_mm_shuffle_epi32(v82, 0);
                v84 = _mm_xor_ps(v81, v83);
                v159 = _mm_shuffle_ps(v84, _mm_unpackhi_ps(v84, _mm_sub_ps(_mm_shuffle_ps(v84, v84, 255), v70)), 196);
                v160 = _mm_shuffle_ps(v81, _mm_unpackhi_ps(v81, _mm_sub_ps(_mm_shuffle_ps(v81, v81, 255), v70)), 196);
                v85 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v79, v79, 201), v69), _mm_mul_ps(v79, v73));
                v86 = _mm_shuffle_ps(v85, v85, 201);
                v87 = _mm_mul_ps(v86, v86);
                v88 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v87, v87, 85), _mm_shuffle_ps(v87, v87, 0)),
                        _mm_shuffle_ps(v87, v87, 170));
                v89 = _mm_rsqrt_ps(v88);
                v90 = _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v88, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v89, v88), v89)),
                            _mm_mul_ps(*(__m128 *)_xmm, v89))),
                        v86);
                v91 = _mm_mul_ps(v90, *(__m128 *)&pairsOut.m_size);
                v92 = _mm_shuffle_ps(
                        v90,
                        _mm_unpackhi_ps(
                          v90,
                          _mm_sub_ps(
                            (__m128)0i64,
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v91, v91, 85), _mm_shuffle_ps(v91, v91, 0)),
                              _mm_shuffle_ps(v91, v91, 170)))),
                        196);
                v93 = _mm_xor_ps(v92, v83);
                v94 = _mm_mul_ps(
                        _mm_sub_ps(
                          _mm_sub_ps(_mm_add_ps(rightInOut.m_quad, rightEnd.m_quad), leftInOut.m_quad),
                          leftEnd.m_quad),
                        (__m128)xmmword_141A711B0);
                v161 = _mm_shuffle_ps(v93, _mm_unpackhi_ps(v93, _mm_sub_ps(_mm_shuffle_ps(v93, v93, 255), v70)), 196);
                v95 = _mm_mul_ps(v94, v68);
                v162 = _mm_shuffle_ps(v92, _mm_unpackhi_ps(v92, _mm_sub_ps(_mm_shuffle_ps(v92, v92, 255), v70)), 196);
                v96 = _mm_sub_ps(
                        v94,
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v95, v95, 85), _mm_shuffle_ps(v95, v95, 0)),
                            _mm_shuffle_ps(v95, v95, 170)),
                          v68));
                v97 = _mm_mul_ps(v96, v96);
                v98 = _mm_sub_ps(leftEnd.m_quad, leftInOut.m_quad);
                v99 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v97, v97, 85), _mm_shuffle_ps(v97, v97, 0)),
                        _mm_shuffle_ps(v97, v97, 170));
                v100 = _mm_rsqrt_ps(v99);
                v101 = _mm_mul_ps(v98, v68);
                v102 = _mm_mul_ps(
                         v96,
                         _mm_andnot_ps(
                           _mm_cmpleps(v99, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v100, v99), v100)),
                             _mm_mul_ps(v100, *(__m128 *)_xmm))));
                v103 = _mm_sub_ps(
                         v98,
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v101, v101, 85), _mm_shuffle_ps(v101, v101, 0)),
                             _mm_shuffle_ps(v101, v101, 170)),
                           v68));
                v104 = _mm_mul_ps(v103, v103);
                v105 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v104, v104, 85), _mm_shuffle_ps(v104, v104, 0)),
                         _mm_shuffle_ps(v104, v104, 170));
                v106 = _mm_rsqrt_ps(v105);
                uVector.m_quad = _mm_mul_ps(
                                   v103,
                                   _mm_andnot_ps(
                                     _mm_cmpleps(v105, (__m128)0i64),
                                     _mm_mul_ps(
                                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v106, v105), v106)),
                                       _mm_mul_ps(v106, *(__m128 *)_xmm))));
                extremalVector.m_quad = _mm_add_ps(
                                          _mm_mul_ps(_mm_sub_ps((__m128)0i64, v164), uVector.m_quad),
                                          _mm_mul_ps(v167, v68));
                if ( !v67 && !v66 )
                {
                  v107 = _mm_load_si128((const __m128i *)&v154);
                  do
                  {
                    v108 = (unsigned int *)hkaiIntervalPartition::getInterval(&reachableAreasOut, v29);
                    v109 = v108[3];
                    v110 = _mm_shuffle_ps((__m128)*v108, (__m128)*v108, 0);
                    v111 = (__m128)v108[1];
                    DWORD2(v154) = v108[2];
                    v112 = v108[4];
                    v113 = _mm_shuffle_ps(v111, v111, 0);
                    HIDWORD(v154) = v109;
                    v155 = v112;
                    v114 = _mm_sub_ps(rightInOut.m_quad, leftInOut.m_quad);
                    v115 = _mm_add_ps(_mm_mul_ps(v110, v114), leftInOut.m_quad);
                    v116 = _mm_add_ps(_mm_mul_ps(v113, v114), leftInOut.m_quad);
                    v117 = _mm_sub_ps(v115, v116);
                    v118 = _mm_mul_ps(v117, v117);
                    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v118, v118, 85))
                                       + COERCE_FLOAT(_mm_shuffle_ps(v118, v118, 0)))
                               + COERCE_FLOAT(_mm_shuffle_ps(v118, v118, 170))) >= v166.m128_f32[0] )
                    {
                      v119 = _mm_sub_ps(rightEnd.m_quad, leftEnd.m_quad);
                      v120 = _mm_add_ps(_mm_mul_ps(v110, v119), leftEnd.m_quad);
                      v121 = _mm_add_ps(_mm_mul_ps(v113, v119), leftEnd.m_quad);
                      left.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v120, v115), (__m128)xmmword_141A711B0), v115);
                      right.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v121, v116), (__m128)xmmword_141A711B0), v116);
                      hkaiUserEdgeUtils::UserEdgePair::UserEdgePair(&userEdgePair);
                      v122 = v3->m_fromNavMeshInstance;
                      v123 = v2->m_userdata;
                      v124 = _mm_shuffle_ps(v115, v116, 68);
                      v125 = _mm_shuffle_ps(v121, v120, 68);
                      userEdgePair.m_z.m_quad = _mm_shuffle_ps(
                                                  _mm_shuffle_ps(v115, v116, 238),
                                                  _mm_shuffle_ps(v121, v120, 238),
                                                  136);
                      userEdgePair.m_x.m_quad = _mm_shuffle_ps(v124, v125, 136);
                      v119.m128_i32[0] = LODWORD(v2->m_baseCost);
                      userEdgePair.m_y.m_quad = _mm_shuffle_ps(v124, v125, 221);
                      v126 = v122->m_sectionUid;
                      v127 = v3->m_toNavMeshInstance;
                      userEdgePair.m_instanceUidA = v126;
                      v128 = v127->m_sectionUid;
                      retaddr = v119.m128_f32[0] * 1.0039062;
                      userEdgePair.m_faceA = v52[v51].m_startFace;
                      LODWORD(v127) = v52[v51].m_endFace;
                      userEdgePair.m_instanceUidB = v128;
                      v129 = v3->m_outputLibrary;
                      userEdgePair.m_faceB = (signed int)v127;
                      userEdgePair.m_direction.m_storage = 1;
                      userEdgePair.m_costAtoB.m_value = HIWORD(retaddr);
                      userEdgePair.m_costBtoA.m_value = 0;
                      v130 = hkaiTraversalAnnotationLibrary::addAnnotation(
                               v129,
                               &userEdgePair,
                               HKAI_TRAVERSAL_TYPE_CLIMB_UP,
                               v123);
                      clippingPlanes.m_data[4].m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(v107, 64), v102);
                      v131 = clippingPlanes.m_data[4].m_quad;
                      v132 = _mm_mul_ps(left.m_quad, v131);
                      clippingPlanes.m_data[4].m_quad = _mm_shuffle_ps(
                                                          v131,
                                                          _mm_unpackhi_ps(
                                                            clippingPlanes.m_data[4].m_quad,
                                                            _mm_sub_ps(
                                                              (__m128)0i64,
                                                              _mm_add_ps(
                                                                _mm_add_ps(
                                                                  _mm_shuffle_ps(v132, v132, 85),
                                                                  _mm_shuffle_ps(v132, v132, 0)),
                                                                _mm_shuffle_ps(v132, v132, 170)))),
                                                          196);
                      clippingPlanes.m_data[5].m_quad = v102;
                      v133 = clippingPlanes.m_data[5].m_quad;
                      v134 = _mm_mul_ps(right.m_quad, v133);
                      clippingPlanes.m_data[5].m_quad = _mm_shuffle_ps(
                                                          v133,
                                                          _mm_unpackhi_ps(
                                                            clippingPlanes.m_data[5].m_quad,
                                                            _mm_sub_ps(
                                                              (__m128)0i64,
                                                              _mm_add_ps(
                                                                _mm_add_ps(
                                                                  _mm_shuffle_ps(v134, v134, 85),
                                                                  _mm_shuffle_ps(v134, v134, 0)),
                                                                _mm_shuffle_ps(v134, v134, 170)))),
                                                          196);
                      clippingPlanes.m_data[4].m_quad = _mm_shuffle_ps(
                                                          clippingPlanes.m_data[4].m_quad,
                                                          _mm_unpackhi_ps(
                                                            clippingPlanes.m_data[4].m_quad,
                                                            _mm_sub_ps(
                                                              _mm_shuffle_ps(
                                                                clippingPlanes.m_data[4].m_quad,
                                                                clippingPlanes.m_data[4].m_quad,
                                                                255),
                                                              query.m_quad)),
                                                          196);
                      clippingPlanes.m_data[5].m_quad = _mm_shuffle_ps(
                                                          clippingPlanes.m_data[5].m_quad,
                                                          _mm_unpackhi_ps(
                                                            clippingPlanes.m_data[5].m_quad,
                                                            _mm_sub_ps(
                                                              _mm_shuffle_ps(
                                                                clippingPlanes.m_data[5].m_quad,
                                                                clippingPlanes.m_data[5].m_quad,
                                                                255),
                                                              query.m_quad)),
                                                          196);
                      hkaiIntervalPartition::hkaiIntervalPartition(&uPartition);
                      hkaiIntervalPartition::hkaiIntervalPartition(&intervalPartition);
                      hkaiGeometrySegmentCaster::findExtremalProfile(
                        v3->m_cuttingGeometrySegmentCaster.m_pntr,
                        &clippingPlanes,
                        &left,
                        &right,
                        &extremalVector,
                        &uVector,
                        &vVector,
                        &uPartition,
                        &intervalPartition);
                      hkaiTraversalAnnotationLibrary::addIntervalPartition(
                        v3->m_outputLibrary,
                        v130,
                        0,
                        &uPartition,
                        1,
                        0);
                      hkaiTraversalAnnotationLibrary::addIntervalPartition(
                        v3->m_outputLibrary,
                        v130,
                        1,
                        &intervalPartition,
                        1,
                        0);
                      hkaiTraversalAnnotationLibrary::addVector(v3->m_outputLibrary, v130, 0, &left);
                      hkaiTraversalAnnotationLibrary::addVector(v3->m_outputLibrary, v130, 1, &right);
                      hkaiTraversalAnnotationLibrary::addVector(v3->m_outputLibrary, v130, 2, &uVector);
                      intervalPartition.m_intervals.m_size = 0;
                      if ( intervalPartition.m_intervals.m_capacityAndFlags >= 0 )
                        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                          intervalPartition.m_intervals.m_data,
                          20 * (intervalPartition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
                      intervalPartition.m_intervals.m_data = 0i64;
                      intervalPartition.m_intervals.m_capacityAndFlags = 2147483648;
                      uPartition.m_intervals.m_size = 0;
                      if ( uPartition.m_intervals.m_capacityAndFlags >= 0 )
                        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                          uPartition.m_intervals.m_data,
                          20 * (uPartition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
                      uPartition.m_intervals.m_data = 0i64;
                      uPartition.m_intervals.m_capacityAndFlags = 2147483648;
                    }
                    ++v29;
                  }
                  while ( v29 < v65 );
                  v72 = clippingPlanes.m_capacityAndFlags;
                  v71 = clippingPlanes.m_data;
                  v50 = v171;
                }
                v29 = 0;
                clippingPlanes.m_size = 0;
                if ( v72 >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    v71,
                    16 * v72);
                clippingPlanes.m_data = 0i64;
                clippingPlanes.m_capacityAndFlags = 2147483648;
              }
            }
          }
        }
      }
      other.m_intervals.m_size = 0;
      if ( other.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          other.m_intervals.m_data,
          20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      ++v51;
      --v50;
      other.m_intervals.m_capacityAndFlags = 2147483648;
      v171 = v50;
      other.m_intervals.m_data = 0i64;
    }
    while ( v50 );
  }
  v147.m_intervals.m_size = 0;
  if ( v147.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v147.m_intervals.m_data,
      20 * (v147.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  v147.m_intervals.m_data = 0i64;
  v147.m_intervals.m_capacityAndFlags = 2147483648;
  v145.m_intervals.m_size = 0;
  if ( v145.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v145.m_intervals.m_data,
      20 * (v145.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  v145.m_intervals.m_data = 0i64;
  v145.m_intervals.m_capacityAndFlags = 2147483648;
  v142.m_intervals.m_size = 0;
  if ( v142.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v142.m_intervals.m_data,
      20 * (v142.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  v142.m_intervals.m_data = 0i64;
  v142.m_intervals.m_capacityAndFlags = 2147483648;
  v144.m_intervals.m_size = 0;
  if ( v144.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v144.m_intervals.m_data,
      20 * (v144.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  v144.m_intervals.m_data = 0i64;
  v144.m_intervals.m_capacityAndFlags = 2147483648;
  reachableAreasOut.m_intervals.m_size = 0;
  if ( reachableAreasOut.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      reachableAreasOut.m_intervals.m_data,
      20 * (reachableAreasOut.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  reachableAreasOut.m_intervals.m_data = 0i64;
  pairsOut.m_size = 0;
  reachableAreasOut.m_intervals.m_capacityAndFlags = 2147483648;
  if ( pairsOut.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      pairsOut.m_data,
      80 * (pairsOut.m_capacityAndFlags & 0x3FFFFFFF));
}oc,
      pairsOut.m_data,
      80 * (pairsOut.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 252
// RVA: 0xC33E60
signed __int64 __fastcall hkaiClimbUpUtils::getGrabPoint(hkaiTraversalAnnotationLibrary *library, unsigned int *annotationIndex, hkVector4f *handPos, hkVector4f *grabPointOut, hkVector4f *grabFwdDirOut)
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

  v5 = grabPointOut;
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
  grabFwdDirOut->m_quad = _mm_mul_ps(
                            _mm_andnot_ps(
                              _mm_cmpleps(v17, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                _mm_mul_ps(*(__m128 *)_xmm, v18))),
                            v15);
  return v9;
}

// File Line: 305
// RVA: 0xC34010
__int64 __fastcall hkaiClimbUpUtils::getNumGrabSegments(hkaiTraversalAnnotationLibrary *library, unsigned int *annotationIndex)
{
  return hkaiTraversalAnnotationLibrary::getNumPartitionIntervals(library, *annotationIndex, 0);
}

// File Line: 315
// RVA: 0xC34030
void __fastcall hkaiClimbUpUtils::getGrabSegment(hkaiTraversalAnnotationLibrary *library, unsigned int *annotationIndex, int grabSegmentIndex, hkVector4f *leftPointOut, hkVector4f *rightPointOut)
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
  v7 = grabSegmentIndex;
  v8 = library;
  hkaiTraversalAnnotationLibrary::getPartitionInterval(library, *annotationIndex, 0, grabSegmentIndex, &intervalOut);
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


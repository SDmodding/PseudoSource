// File Line: 24
// RVA: 0xC32CD0
void __fastcall hkaiClimbUpAnalyzer::analyze(hkaiClimbUpAnalyzer *this, hkaiTraversalAnalysisContext *context)
{
  __m128i si128; // xmm3
  float m_maxPlanarAngle; // xmm8_4
  hkaiTraversalAnalysisSettings *m_settings; // rax
  __m128 v7; // xmm7
  __m128 v8; // xmm2
  float m_minUpHeight; // xmm0_4
  float m_maxUpHeight; // xmm1_4
  float m_maxUnderhang; // xmm1_4
  __m128i v12; // xmm6
  __m128 v13; // xmm5
  __m128 v14; // xmm0
  __m128 v15; // xmm4
  __m128 v16; // xmm3
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
  int v28; // esi
  __m128 v29; // xmm6
  __m128 v30; // xmm2
  __m128i v31; // xmm7
  __m128 v32; // xmm5
  __m128 v33; // xmm0
  __m128 v34; // xmm4
  __m128 v35; // xmm2
  __m128i v36; // xmm1
  __m128 v37; // xmm8
  __m128 v38; // xmm0
  __m128i v39; // xmm5
  __m128 v40; // xmm2
  __m128i v41; // xmm7
  __m128i v42; // xmm5
  __m128 v43; // xmm1
  __m128 v44; // xmm4
  __m128 v45; // xmm3
  __m128 v46; // xmm2
  __m128 v47; // xmm9
  hkVector4f *v48; // r9
  __int64 v49; // rbx
  __int64 v50; // r14
  __int64 v51; // r15
  hkaiNavMeshInstance *m_fromNavMeshInstance; // rcx
  hkVector4f *v53; // r9
  __m128 v54; // xmm3
  __m128 v55; // xmm5
  __m128 v56; // xmm6
  __m128 v57; // xmm1
  __m128 v58; // xmm4
  __m128 v59; // xmm5
  __m128 v60; // xmm2
  __m128 v61; // xmm6
  int m_size; // r12d
  __m128 v63; // xmm10
  __m128 v64; // xmm11
  hkVector4f *m_data; // rdx
  int m_capacityAndFlags; // r8d
  __m128 v67; // xmm9
  __m128 v68; // xmm5
  __m128 v69; // xmm5
  __m128 v70; // xmm1
  __m128 v71; // xmm3
  __m128 v72; // xmm2
  __m128 v73; // xmm5
  __m128 v74; // xmm2
  __m128 v75; // xmm8
  __m128 v76; // xmm6
  __m128 v77; // xmm7
  __m128 v78; // xmm4
  __m128 v79; // xmm4
  __m128 v80; // xmm1
  __m128 v81; // xmm3
  __m128 v82; // xmm2
  __m128 v83; // xmm5
  __m128 v84; // xmm2
  __m128 v85; // xmm5
  __m128 v86; // xmm2
  __m128 v87; // xmm10
  __m128 v88; // xmm1
  __m128 v89; // xmm10
  __m128 v90; // xmm1
  __m128 v91; // xmm6
  __m128 v92; // xmm3
  __m128 v93; // xmm2
  __m128 v94; // xmm1
  __m128 v95; // xmm10
  __m128 v96; // xmm6
  __m128 v97; // xmm1
  __m128 v98; // xmm2
  __m128 v99; // xmm1
  __m128i v100; // xmm12
  unsigned int *Interval; // rax
  int v102; // xmm1_4
  __m128 v103; // xmm8
  __m128 v104; // xmm7
  int v105; // xmm0_4
  __m128 v106; // xmm7
  __m128 v107; // xmm0
  __m128 v108; // xmm6
  __m128 v109; // xmm9
  __m128 v110; // xmm2
  __m128 v111; // xmm2
  __m128 v112; // xmm0
  __m128 v113; // xmm8
  __m128 v114; // xmm7
  hkaiNavMeshInstance *v115; // rax
  unsigned int m_userdata; // r9d
  __m128 v117; // xmm2
  __m128 v118; // xmm1
  unsigned int m_sectionUid; // ecx
  hkaiNavMeshInstance *m_toNavMeshInstance; // rax
  unsigned int v121; // ecx
  hkaiTraversalAnnotationLibrary *m_outputLibrary; // rcx
  unsigned int v123; // ebx
  __m128 m_quad; // xmm3
  __m128 v125; // xmm2
  __m128 v126; // xmm3
  __m128 v127; // xmm2
  hkaiIntervalPartition other; // [rsp+50h] [rbp-A8h] BYREF
  hkaiIntervalPartition reachableAreasOut; // [rsp+60h] [rbp-98h] BYREF
  char pairsOut[24]; // [rsp+70h] [rbp-88h] BYREF
  hkaiIntervalPartition intervalPartition; // [rsp+88h] [rbp-70h] BYREF
  hkaiIntervalPartition uPartition; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f leftEnd; // [rsp+A8h] [rbp-50h] BYREF
  hkVector4f leftInOut; // [rsp+B8h] [rbp-40h] BYREF
  hkaiIntervalPartition v135; // [rsp+C8h] [rbp-30h] BYREF
  hkVector4f rightEnd; // [rsp+D8h] [rbp-20h] BYREF
  hkaiIntervalPartition v137; // [rsp+E8h] [rbp-10h] BYREF
  hkaiIntervalPartition v138; // [rsp+F8h] [rbp+0h] BYREF
  hkVector4f rightInOut; // [rsp+108h] [rbp+10h] BYREF
  hkaiIntervalPartition v140; // [rsp+118h] [rbp+20h] BYREF
  hkVector4f vVector; // [rsp+128h] [rbp+30h] BYREF
  hkVector4f topRightIn; // [rsp+138h] [rbp+40h] BYREF
  hkVector4f left; // [rsp+148h] [rbp+50h] BYREF
  hkVector4f right; // [rsp+158h] [rbp+60h] BYREF
  hkVector4f bottomLeftIn; // [rsp+168h] [rbp+70h] BYREF
  hkVector4f bottomRightIn; // [rsp+178h] [rbp+80h] BYREF
  __m128i inserted; // [rsp+188h] [rbp+90h] BYREF
  int v148; // [rsp+198h] [rbp+A0h]
  hkaiPairedEdgeFinder::PairedEdgeSettings settings; // [rsp+1A8h] [rbp+B0h] BYREF
  hkVector4f uVector; // [rsp+1E8h] [rbp+F0h] BYREF
  hkArrayBase<hkVector4f> clippingPlanes; // [rsp+1F8h] [rbp+100h] BYREF
  __int128 v152[6]; // [rsp+208h] [rbp+110h] BYREF
  hkaiUserEdgeUtils::UserEdgePair userEdgePair; // [rsp+268h] [rbp+170h] BYREF
  __m128 v154; // [rsp+2B8h] [rbp+1C0h]
  __m128 faceIndex; // [rsp+2C8h] [rbp+1D0h] BYREF
  __m128 v156; // [rsp+2D8h] [rbp+1E0h]
  __m128 v157; // [rsp+2E8h] [rbp+1F0h]
  hkVector4f extremalVector; // [rsp+2F8h] [rbp+200h] BYREF
  hkVector4f facePlane; // [rsp+308h] [rbp+210h] BYREF
  void *retaddr; // [rsp+3F8h] [rbp+300h]
  __int64 v161; // [rsp+400h] [rbp+308h]

  vVector.m_quad = (__m128)context->m_settings->m_up;
  hkaiPairedEdgeFinder::PairedEdgeSettings::PairedEdgeSettings(&settings);
  si128 = _mm_load_si128((const __m128i *)_xmm);
  m_maxPlanarAngle = this->m_maxPlanarAngle;
  m_settings = context->m_settings;
  v7 = _mm_add_ps((__m128)LODWORD(m_maxPlanarAngle), *(__m128 *)_xmm);
  v8 = _mm_andnot_ps(*(__m128 *)_xmm, v7);
  settings.m_up = (hkVector4f)vVector.m_quad;
  m_minUpHeight = this->m_minUpHeight;
  settings.m_minLength = m_settings->m_minEdgeLength;
  m_maxUpHeight = this->m_maxUpHeight;
  settings.m_minHeightDelta = m_minUpHeight;
  settings.m_maxHeightDelta = m_maxUpHeight;
  m_maxUnderhang = this->m_maxUnderhang;
  *(__m128i *)&pairsOut[8] = _mm_add_epi32(si128, si128);
  settings.m_maxHorizontalDelta = m_maxUnderhang;
  settings.m_minHorizontalDelta = 0.0;
  v12 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v8, *(__m128 *)_xmm)), si128));
  v13 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v12, *(__m128i *)&pairsOut[8]), (__m128i)0i64);
  v14 = _mm_cvtepi32_ps(v12);
  v15 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v14, *(__m128 *)DP1_0), v8), _mm_mul_ps(v14, *(__m128 *)DP2)),
          _mm_mul_ps(v14, *(__m128 *)DP3));
  v16 = _mm_mul_ps(v15, v15);
  v8.m128_f32[0] = _mm_andnot_ps(
                     v13,
                     _mm_add_ps(
                       _mm_sub_ps(
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_add_ps(_mm_mul_ps(v16, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1),
                                 v16),
                               *(__m128 *)cosCoeff2_0),
                             v16),
                           v16),
                         _mm_mul_ps(v16, *(__m128 *)_xmm)),
                       *(__m128 *)_xmm)).m128_f32[0];
  v14.m128_f32[0] = (float)((float)((float)((float)(v16.m128_f32[0] * -0.00019515296) + 0.0083321612) * v16.m128_f32[0])
                          + -0.16666655)
                  * v16.m128_f32[0];
  v17 = _mm_load_si128((const __m128i *)&pairsOut[8]);
  v8.m128_i32[0] |= COERCE_UNSIGNED_INT((float)(v14.m128_f32[0] * v15.m128_f32[0]) + v15.m128_f32[0]) & v13.m128_i32[0];
  v14.m128_i32[0] = _mm_and_si128(_mm_add_epi32(v17, v17), v12).m128i_u32[0];
  v18 = _mm_load_si128((const __m128i *)_xmm);
  LODWORD(settings.m_cosMaxPlanarAngle) = v8.m128_i32[0] ^ (v14.m128_i32[0] << 29) ^ v7.m128_i32[0] & _xmm[0];
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
  v25 = _mm_load_si128((const __m128i *)&pairsOut[8]);
  v17.m128i_i32[0] = (_mm_andnot_ps(
                        v21,
                        _mm_add_ps(
                          _mm_sub_ps(
                            _mm_mul_ps(
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_add_ps(_mm_mul_ps(v24, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1),
                                    v24),
                                  *(__m128 *)cosCoeff2_0),
                                v24),
                              v24),
                            _mm_mul_ps(v24, *(__m128 *)_xmm)),
                          *(__m128 *)_xmm)).m128_u32[0] | v22.m128_i32[0] & v21.m128_i32[0]) ^ (_mm_and_si128(
                                                                                                  _mm_add_epi32(
                                                                                                    v25,
                                                                                                    v25),
                                                                                                  v20).m128i_u32[0] << 29) ^ LODWORD(m_maxPlanarAngle) & _xmm[0];
  v22.m128_i32[0] = LODWORD(this->m_maxRelativeSlopeAngle);
  LODWORD(settings.m_sinMaxPlanarAngle) = v17.m128i_i32[0];
  v26 = _mm_load_si128((const __m128i *)_xmm);
  m_pntr = context->m_pairedEdgeFinder.m_pntr;
  LODWORD(retaddr) = v22.m128_i32[0];
  v28 = 0;
  *(_WORD *)&settings.m_matchAngles.m_bool = 257;
  v29 = _mm_add_ps((__m128)v22.m128_u32[0], *(__m128 *)_xmm);
  *(_QWORD *)pairsOut = 0i64;
  *(_QWORD *)&pairsOut[8] = 0x8000000000000000ui64;
  v30 = _mm_andnot_ps(*(__m128 *)_xmm, v29);
  v31 = _mm_andnot_si128(v26, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v30, *(__m128 *)_xmm)), v26));
  v32 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v31, v25), (__m128i)0i64);
  v33 = _mm_cvtepi32_ps(v31);
  v34 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v33, *(__m128 *)DP1_0), v30), _mm_mul_ps(v33, *(__m128 *)DP2)),
          _mm_mul_ps(v33, *(__m128 *)DP3));
  v35 = _mm_mul_ps(v34, v34);
  v36 = _mm_load_si128((const __m128i *)&pairsOut[8]);
  LODWORD(settings.m_cosMaxDeltaSlopeAngle) = (_mm_andnot_ps(
                                                 v32,
                                                 _mm_add_ps(
                                                   _mm_sub_ps(
                                                     _mm_mul_ps(
                                                       _mm_mul_ps(
                                                         _mm_add_ps(
                                                           _mm_mul_ps(
                                                             _mm_add_ps(
                                                               _mm_mul_ps(v35, *(__m128 *)cosCoeff0_0),
                                                               *(__m128 *)cosCoeff1),
                                                             v35),
                                                           *(__m128 *)cosCoeff2_0),
                                                         v35),
                                                       v35),
                                                     _mm_mul_ps(v35, *(__m128 *)_xmm)),
                                                   *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                                                     (float)((float)((float)((float)((float)((float)(v35.m128_f32[0] * -0.00019515296) + 0.0083321612) * v35.m128_f32[0]) + -0.16666655) * v35.m128_f32[0])
                                                                                           * v34.m128_f32[0])
                                                                                   + v34.m128_f32[0]) & v32.m128_i32[0]) ^ (_mm_and_si128(_mm_add_epi32(v36, v36), v31).m128i_u32[0] << 29) ^ v29.m128_i32[0] & _xmm[0];
  hkaiPairedEdgeFinder::findEdgePairs(
    m_pntr,
    &settings,
    (hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> *)pairsOut);
  hkaiIntervalPartition::hkaiIntervalPartition(&reachableAreasOut);
  hkaiIntervalPartition::hkaiIntervalPartition(&v137);
  hkaiIntervalPartition::hkaiIntervalPartition(&v135);
  v37 = _mm_add_ps(
          _mm_shuffle_ps((__m128)LODWORD(this->m_grabAngle), (__m128)LODWORD(this->m_grabAngle), 0),
          *(__m128 *)offset_1);
  v38 = _mm_shuffle_ps(
          (__m128)LODWORD(context->m_settings->m_minEdgeLength),
          (__m128)LODWORD(context->m_settings->m_minEdgeLength),
          0);
  v156 = _mm_mul_ps(v38, v38);
  v39 = _mm_load_si128((const __m128i *)_xmm);
  v40 = _mm_andnot_ps(*(__m128 *)_xmm, v37);
  v41 = _mm_add_epi32(v39, v39);
  v42 = _mm_andnot_si128(v39, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v40, *(__m128 *)_xmm)), v39));
  v43 = _mm_cvtepi32_ps(v42);
  v44 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v42, v41), (__m128i)0i64);
  v45 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v43, *(__m128 *)DP1_0), v40), _mm_mul_ps(v43, *(__m128 *)DP2)),
          _mm_mul_ps(v43, *(__m128 *)DP3));
  v46 = _mm_mul_ps(v45, v45);
  v47 = _mm_xor_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              v44,
              _mm_add_ps(
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v46, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v46),
                        *(__m128 *)cosCoeff2_0),
                      v46),
                    v46),
                  _mm_mul_ps(v46, *(__m128 *)_xmm)),
                *(__m128 *)_xmm)),
            _mm_and_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v46, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v46),
                      *(__m128 *)sinCoeff2_0),
                    v46),
                  v45),
                v45),
              v44)),
          _mm_xor_ps(
            (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v41, v41), v42), 0x1Du),
            _mm_and_ps(v37, *(__m128 *)_xmm)));
  v157 = _mm_shuffle_ps(v47, v47, 85);
  v154 = _mm_shuffle_ps(v47, v47, 0);
  hkaiIntervalPartition::hkaiIntervalPartition(&v138);
  hkaiIntervalPartition::hkaiIntervalPartition(&v140);
  v49 = *(int *)&pairsOut[8];
  v161 = *(int *)&pairsOut[8];
  if ( *(int *)&pairsOut[8] > 0 )
  {
    v50 = 0i64;
    do
    {
      v51 = *(_QWORD *)pairsOut;
      m_fromNavMeshInstance = context->m_fromNavMeshInstance;
      leftInOut.m_quad = *(__m128 *)(*(_QWORD *)pairsOut + v50 + 16);
      rightInOut.m_quad = *(__m128 *)(*(_QWORD *)pairsOut + v50);
      leftEnd.m_quad = *(__m128 *)(*(_QWORD *)pairsOut + v50 + 48);
      rightEnd.m_quad = *(__m128 *)(*(_QWORD *)pairsOut + v50 + 32);
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)m_fromNavMeshInstance,
        (hkaiNavMeshInstance *)*(unsigned int *)(*(_QWORD *)pairsOut + v50 + 64),
        &faceIndex,
        v48);
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)context->m_toNavMeshInstance,
        (hkaiNavMeshInstance *)*(unsigned int *)(v51 + v50 + 72),
        &facePlane.m_quad,
        v53);
      hkaiTraversalAnalysisUtils::setBackEdge(&leftInOut, &rightInOut, (hkVector4f *)&faceIndex, context);
      hkaiTraversalAnalysisUtils::setBackEdge(&rightEnd, &leftEnd, &facePlane, context);
      hkaiIntervalPartition::hkaiIntervalPartition(&other);
      hkaiTraversalAnalysisUtils::filterUnwalkableLandingZones(
        &leftInOut,
        &rightInOut,
        &leftEnd,
        &rightEnd,
        *(_DWORD *)(v51 + v50 + 64),
        *(_DWORD *)(v51 + v50 + 72),
        &other,
        context);
      if ( other.m_intervals.m_size )
      {
        bottomLeftIn.m_quad = leftInOut.m_quad;
        bottomRightIn.m_quad = rightInOut.m_quad;
        *(hkVector4f *)&pairsOut[8] = (hkVector4f)leftEnd.m_quad;
        topRightIn.m_quad = rightEnd.m_quad;
        if ( hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&bottomLeftIn, &bottomRightIn, context) )
        {
          if ( hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&topRightIn, (hkVector4f *)&pairsOut[8], context) )
          {
            v54 = _mm_mul_ps(bottomRightIn.m_quad, vVector.m_quad);
            v55 = _mm_mul_ps(bottomLeftIn.m_quad, vVector.m_quad);
            v56 = _mm_shuffle_ps(v55, v54, 238);
            v57 = _mm_mul_ps(topRightIn.m_quad, vVector.m_quad);
            v58 = _mm_mul_ps(*(__m128 *)&pairsOut[8], vVector.m_quad);
            v59 = _mm_shuffle_ps(v55, v54, 68);
            v60 = _mm_shuffle_ps(v58, v57, 68);
            v61 = _mm_add_ps(
                    _mm_shuffle_ps(v56, _mm_shuffle_ps(v58, v57, 238), 136),
                    _mm_add_ps(_mm_shuffle_ps(v59, v60, 221), _mm_shuffle_ps(v59, v60, 136)));
            if ( fmax(_mm_shuffle_ps(v61, v61, 0).m128_f32[0], _mm_shuffle_ps(v61, v61, 85).m128_f32[0]) < fmin(_mm_shuffle_ps(v61, v61, 170).m128_f32[0], _mm_shuffle_ps(v61, v61, 255).m128_f32[0]) )
            {
              hkaiIntervalPartition::clear(&reachableAreasOut);
              hkaiTraversalAnalysisUtils::findOverLedgeReachability(
                &bottomLeftIn,
                &bottomRightIn,
                (hkVector4f *)&pairsOut[8],
                &topRightIn,
                context,
                &reachableAreasOut);
              hkaiIntervalPartition::clipNotDefined(&reachableAreasOut, &other);
              m_size = reachableAreasOut.m_intervals.m_size;
              if ( reachableAreasOut.m_intervals.m_size )
              {
                v63 = _mm_sub_ps(rightEnd.m_quad, leftEnd.m_quad);
                v64 = _mm_shuffle_ps((__m128)LODWORD(this->m_grabScanDepth), (__m128)LODWORD(this->m_grabScanDepth), 0);
                m_data = (hkVector4f *)v152;
                m_capacityAndFlags = -2147483642;
                clippingPlanes.m_size = 6;
                clippingPlanes.m_data = (hkVector4f *)v152;
                clippingPlanes.m_capacityAndFlags = -2147483642;
                v67 = _mm_shuffle_ps(v63, v63, 201);
                v68 = _mm_sub_ps(
                        _mm_mul_ps(vVector.m_quad, v67),
                        _mm_mul_ps(_mm_shuffle_ps(vVector.m_quad, vVector.m_quad, 201), v63));
                v69 = _mm_shuffle_ps(v68, v68, 201);
                v70 = _mm_mul_ps(v69, v69);
                v71 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v70, v70, 85), _mm_shuffle_ps(v70, v70, 0)),
                        _mm_shuffle_ps(v70, v70, 170));
                v72 = _mm_rsqrt_ps(v71);
                v73 = _mm_mul_ps(
                        v69,
                        _mm_andnot_ps(
                          _mm_cmple_ps(v71, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v72, v71), v72)),
                            _mm_mul_ps(*(__m128 *)_xmm, v72))));
                v74 = _mm_mul_ps(v73, leftEnd.m_quad);
                v75 = _mm_shuffle_ps(
                        v73,
                        _mm_unpackhi_ps(
                          v73,
                          _mm_sub_ps(
                            (__m128)0i64,
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v74, v74, 85), _mm_shuffle_ps(v74, v74, 0)),
                              _mm_shuffle_ps(v74, v74, 170)))),
                        196);
                inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
                v76 = (__m128)_mm_shuffle_epi32(inserted, 0);
                v77 = _mm_xor_ps(v75, v76);
                v152[0] = (__int128)_mm_shuffle_ps(
                                      v77,
                                      _mm_unpackhi_ps(v77, _mm_sub_ps(_mm_shuffle_ps(v77, v77, 255), v64)),
                                      196);
                v152[1] = (__int128)_mm_shuffle_ps(
                                      v75,
                                      _mm_unpackhi_ps(v75, _mm_sub_ps(_mm_shuffle_ps(v75, v75, 255), v64)),
                                      196);
                v78 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v73, v73, 201), v63), _mm_mul_ps(v73, v67));
                v79 = _mm_shuffle_ps(v78, v78, 201);
                v80 = _mm_mul_ps(v79, v79);
                v81 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v80, v80, 85), _mm_shuffle_ps(v80, v80, 0)),
                        _mm_shuffle_ps(v80, v80, 170));
                v82 = _mm_rsqrt_ps(v81);
                v83 = _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v81, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v82, v81), v82)),
                            _mm_mul_ps(*(__m128 *)_xmm, v82))),
                        v79);
                v84 = _mm_mul_ps(v83, *(__m128 *)&pairsOut[8]);
                v85 = _mm_shuffle_ps(
                        v83,
                        _mm_unpackhi_ps(
                          v83,
                          _mm_sub_ps(
                            (__m128)0i64,
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v84, v84, 85), _mm_shuffle_ps(v84, v84, 0)),
                              _mm_shuffle_ps(v84, v84, 170)))),
                        196);
                v86 = _mm_xor_ps(v85, v76);
                v87 = _mm_mul_ps(
                        _mm_sub_ps(
                          _mm_sub_ps(_mm_add_ps(rightInOut.m_quad, rightEnd.m_quad), leftInOut.m_quad),
                          leftEnd.m_quad),
                        (__m128)xmmword_141A711B0);
                v152[2] = (__int128)_mm_shuffle_ps(
                                      v86,
                                      _mm_unpackhi_ps(v86, _mm_sub_ps(_mm_shuffle_ps(v86, v86, 255), v64)),
                                      196);
                v88 = _mm_mul_ps(v87, vVector.m_quad);
                v152[3] = (__int128)_mm_shuffle_ps(
                                      v85,
                                      _mm_unpackhi_ps(v85, _mm_sub_ps(_mm_shuffle_ps(v85, v85, 255), v64)),
                                      196);
                v89 = _mm_sub_ps(
                        v87,
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v88, v88, 85), _mm_shuffle_ps(v88, v88, 0)),
                            _mm_shuffle_ps(v88, v88, 170)),
                          vVector.m_quad));
                v90 = _mm_mul_ps(v89, v89);
                v91 = _mm_sub_ps(leftEnd.m_quad, leftInOut.m_quad);
                v92 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v90, v90, 85), _mm_shuffle_ps(v90, v90, 0)),
                        _mm_shuffle_ps(v90, v90, 170));
                v93 = _mm_rsqrt_ps(v92);
                v94 = _mm_mul_ps(v91, vVector.m_quad);
                v95 = _mm_mul_ps(
                        v89,
                        _mm_andnot_ps(
                          _mm_cmple_ps(v92, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v93, v92), v93)),
                            _mm_mul_ps(v93, *(__m128 *)_xmm))));
                v96 = _mm_sub_ps(
                        v91,
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v94, v94, 85), _mm_shuffle_ps(v94, v94, 0)),
                            _mm_shuffle_ps(v94, v94, 170)),
                          vVector.m_quad));
                v97 = _mm_mul_ps(v96, v96);
                v98 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v97, v97, 85), _mm_shuffle_ps(v97, v97, 0)),
                        _mm_shuffle_ps(v97, v97, 170));
                v99 = _mm_rsqrt_ps(v98);
                uVector.m_quad = _mm_mul_ps(
                                   v96,
                                   _mm_andnot_ps(
                                     _mm_cmple_ps(v98, (__m128)0i64),
                                     _mm_mul_ps(
                                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v99, v98), v99)),
                                       _mm_mul_ps(v99, *(__m128 *)_xmm))));
                extremalVector.m_quad = _mm_add_ps(
                                          _mm_mul_ps(_mm_sub_ps((__m128)0i64, v154), uVector.m_quad),
                                          _mm_mul_ps(v157, vVector.m_quad));
                if ( reachableAreasOut.m_intervals.m_size > 0 )
                {
                  v100 = _mm_load_si128(&inserted);
                  do
                  {
                    Interval = (unsigned int *)hkaiIntervalPartition::getInterval(&reachableAreasOut, v28);
                    v102 = Interval[3];
                    v103 = _mm_shuffle_ps((__m128)*Interval, (__m128)*Interval, 0);
                    v104 = (__m128)Interval[1];
                    inserted.m128i_i32[2] = Interval[2];
                    v105 = Interval[4];
                    v106 = _mm_shuffle_ps(v104, v104, 0);
                    inserted.m128i_i32[3] = v102;
                    v148 = v105;
                    v107 = _mm_sub_ps(rightInOut.m_quad, leftInOut.m_quad);
                    v108 = _mm_add_ps(_mm_mul_ps(v103, v107), leftInOut.m_quad);
                    v109 = _mm_add_ps(_mm_mul_ps(v106, v107), leftInOut.m_quad);
                    v110 = _mm_sub_ps(v108, v109);
                    v111 = _mm_mul_ps(v110, v110);
                    if ( (float)((float)(_mm_shuffle_ps(v111, v111, 85).m128_f32[0]
                                       + _mm_shuffle_ps(v111, v111, 0).m128_f32[0])
                               + _mm_shuffle_ps(v111, v111, 170).m128_f32[0]) >= v156.m128_f32[0] )
                    {
                      v112 = _mm_sub_ps(rightEnd.m_quad, leftEnd.m_quad);
                      v113 = _mm_add_ps(_mm_mul_ps(v103, v112), leftEnd.m_quad);
                      v114 = _mm_add_ps(_mm_mul_ps(v106, v112), leftEnd.m_quad);
                      left.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v113, v108), (__m128)xmmword_141A711B0), v108);
                      right.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v114, v109), (__m128)xmmword_141A711B0), v109);
                      hkaiUserEdgeUtils::UserEdgePair::UserEdgePair(&userEdgePair);
                      v115 = context->m_fromNavMeshInstance;
                      m_userdata = this->m_userdata;
                      v117 = _mm_shuffle_ps(v108, v109, 68);
                      v118 = _mm_shuffle_ps(v114, v113, 68);
                      userEdgePair.m_z.m_quad = _mm_shuffle_ps(
                                                  _mm_shuffle_ps(v108, v109, 238),
                                                  _mm_shuffle_ps(v114, v113, 238),
                                                  136);
                      userEdgePair.m_x.m_quad = _mm_shuffle_ps(v117, v118, 136);
                      v112.m128_i32[0] = LODWORD(this->m_baseCost);
                      userEdgePair.m_y.m_quad = _mm_shuffle_ps(v117, v118, 221);
                      m_sectionUid = v115->m_sectionUid;
                      m_toNavMeshInstance = context->m_toNavMeshInstance;
                      userEdgePair.m_instanceUidA = m_sectionUid;
                      v121 = m_toNavMeshInstance->m_sectionUid;
                      *(float *)&retaddr = v112.m128_f32[0] * 1.0039062;
                      userEdgePair.m_faceA = *(_DWORD *)(v51 + v50 + 64);
                      LODWORD(m_toNavMeshInstance) = *(_DWORD *)(v51 + v50 + 72);
                      userEdgePair.m_instanceUidB = v121;
                      m_outputLibrary = context->m_outputLibrary;
                      userEdgePair.m_faceB = (int)m_toNavMeshInstance;
                      userEdgePair.m_direction.m_storage = 1;
                      userEdgePair.m_costAtoB.m_value = WORD1(retaddr);
                      userEdgePair.m_costBtoA.m_value = 0;
                      v123 = hkaiTraversalAnnotationLibrary::addAnnotation(
                               m_outputLibrary,
                               &userEdgePair,
                               HKAI_TRAVERSAL_TYPE_CLIMB_UP,
                               m_userdata);
                      clippingPlanes.m_data[4].m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(v100, 64), v95);
                      m_quad = clippingPlanes.m_data[4].m_quad;
                      v125 = _mm_mul_ps(left.m_quad, m_quad);
                      clippingPlanes.m_data[4].m_quad = _mm_shuffle_ps(
                                                          m_quad,
                                                          _mm_unpackhi_ps(
                                                            m_quad,
                                                            _mm_sub_ps(
                                                              (__m128)0i64,
                                                              _mm_add_ps(
                                                                _mm_add_ps(
                                                                  _mm_shuffle_ps(v125, v125, 85),
                                                                  _mm_shuffle_ps(v125, v125, 0)),
                                                                _mm_shuffle_ps(v125, v125, 170)))),
                                                          196);
                      clippingPlanes.m_data[5].m_quad = v95;
                      v126 = clippingPlanes.m_data[5].m_quad;
                      v127 = _mm_mul_ps(right.m_quad, v126);
                      clippingPlanes.m_data[5].m_quad = _mm_shuffle_ps(
                                                          v126,
                                                          _mm_unpackhi_ps(
                                                            v126,
                                                            _mm_sub_ps(
                                                              (__m128)0i64,
                                                              _mm_add_ps(
                                                                _mm_add_ps(
                                                                  _mm_shuffle_ps(v127, v127, 85),
                                                                  _mm_shuffle_ps(v127, v127, 0)),
                                                                _mm_shuffle_ps(v127, v127, 170)))),
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
                        context->m_cuttingGeometrySegmentCaster.m_pntr,
                        &clippingPlanes,
                        &left,
                        &right,
                        &extremalVector,
                        &uVector,
                        &vVector,
                        &uPartition,
                        &intervalPartition);
                      hkaiTraversalAnnotationLibrary::addIntervalPartition(
                        context->m_outputLibrary,
                        v123,
                        0,
                        &uPartition,
                        1,
                        0);
                      hkaiTraversalAnnotationLibrary::addIntervalPartition(
                        context->m_outputLibrary,
                        v123,
                        1,
                        &intervalPartition,
                        1,
                        0);
                      hkaiTraversalAnnotationLibrary::addVector(context->m_outputLibrary, v123, 0, &left);
                      hkaiTraversalAnnotationLibrary::addVector(context->m_outputLibrary, v123, 1, &right);
                      hkaiTraversalAnnotationLibrary::addVector(context->m_outputLibrary, v123, 2, &uVector);
                      intervalPartition.m_intervals.m_size = 0;
                      if ( intervalPartition.m_intervals.m_capacityAndFlags >= 0 )
                        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                          &hkContainerHeapAllocator::s_alloc,
                          intervalPartition.m_intervals.m_data,
                          20 * (intervalPartition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
                      intervalPartition.m_intervals.m_data = 0i64;
                      intervalPartition.m_intervals.m_capacityAndFlags = 0x80000000;
                      uPartition.m_intervals.m_size = 0;
                      if ( uPartition.m_intervals.m_capacityAndFlags >= 0 )
                        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                          &hkContainerHeapAllocator::s_alloc,
                          uPartition.m_intervals.m_data,
                          20 * (uPartition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
                      uPartition.m_intervals.m_data = 0i64;
                      uPartition.m_intervals.m_capacityAndFlags = 0x80000000;
                    }
                    ++v28;
                  }
                  while ( v28 < m_size );
                  m_capacityAndFlags = clippingPlanes.m_capacityAndFlags;
                  m_data = clippingPlanes.m_data;
                  v49 = v161;
                }
                v28 = 0;
                clippingPlanes.m_size = 0;
                if ( m_capacityAndFlags >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    &hkContainerHeapAllocator::s_alloc,
                    m_data,
                    16 * m_capacityAndFlags);
                clippingPlanes.m_data = 0i64;
                clippingPlanes.m_capacityAndFlags = 0x80000000;
              }
            }
          }
        }
      }
      other.m_intervals.m_size = 0;
      if ( other.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          other.m_intervals.m_data,
          20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      v50 += 80i64;
      --v49;
      other.m_intervals.m_capacityAndFlags = 0x80000000;
      v161 = v49;
      other.m_intervals.m_data = 0i64;
    }
    while ( v49 );
  }
  v140.m_intervals.m_size = 0;
  if ( v140.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v140.m_intervals.m_data,
      20 * (v140.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  v140.m_intervals.m_data = 0i64;
  v140.m_intervals.m_capacityAndFlags = 0x80000000;
  v138.m_intervals.m_size = 0;
  if ( v138.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v138.m_intervals.m_data,
      20 * (v138.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  v138.m_intervals.m_data = 0i64;
  v138.m_intervals.m_capacityAndFlags = 0x80000000;
  v135.m_intervals.m_size = 0;
  if ( v135.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v135.m_intervals.m_data,
      20 * (v135.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  v135.m_intervals.m_data = 0i64;
  v135.m_intervals.m_capacityAndFlags = 0x80000000;
  v137.m_intervals.m_size = 0;
  if ( v137.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v137.m_intervals.m_data,
      20 * (v137.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  v137.m_intervals.m_data = 0i64;
  v137.m_intervals.m_capacityAndFlags = 0x80000000;
  reachableAreasOut.m_intervals.m_size = 0;
  if ( reachableAreasOut.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      reachableAreasOut.m_intervals.m_data,
      20 * (reachableAreasOut.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  reachableAreasOut.m_intervals.m_data = 0i64;
  *(_DWORD *)&pairsOut[8] = 0;
  reachableAreasOut.m_intervals.m_capacityAndFlags = 0x80000000;
  if ( *(int *)&pairsOut[12] >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      *(void **)pairsOut,
      80 * (*(_DWORD *)&pairsOut[12] & 0x3FFFFFFF));
}

// File Line: 252
// RVA: 0xC33E60
__int64 __fastcall hkaiClimbUpUtils::getGrabPoint(
        hkaiTraversalAnnotationLibrary *library,
        unsigned int *annotationIndex,
        hkVector4f *handPos,
        hkVector4f *grabPointOut,
        hkVector4f *grabFwdDirOut)
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
  grabPointOut->m_quad = _mm_add_ps(
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
  grabFwdDirOut->m_quad = _mm_mul_ps(
                            _mm_andnot_ps(
                              _mm_cmple_ps(v16, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                                _mm_mul_ps(*(__m128 *)_xmm, v17))),
                            v14);
  return v9;
}

// File Line: 305
// RVA: 0xC34010
__int64 __fastcall hkaiClimbUpUtils::getNumGrabSegments(
        hkaiTraversalAnnotationLibrary *library,
        unsigned int *annotationIndex)
{
  return hkaiTraversalAnnotationLibrary::getNumPartitionIntervals(library, *annotationIndex, 0);
}

// File Line: 315
// RVA: 0xC34030
void __fastcall hkaiClimbUpUtils::getGrabSegment(
        hkaiTraversalAnnotationLibrary *library,
        unsigned int *annotationIndex,
        unsigned __int16 grabSegmentIndex,
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

  hkaiTraversalAnnotationLibrary::getPartitionInterval(library, *annotationIndex, 0, grabSegmentIndex, &intervalOut);
  hkaiTraversalAnnotationLibrary::getPartitionInterval(library, *annotationIndex, 1, grabSegmentIndex, &v16);
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


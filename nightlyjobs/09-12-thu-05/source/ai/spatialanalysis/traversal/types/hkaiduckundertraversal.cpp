// File Line: 25
// RVA: 0xC354B0
void __fastcall hkaiDuckUnderAnalyzer::analyze(hkaiDuckUnderAnalyzer *this, hkaiTraversalAnalysisContext *context)
{
  hkaiDuckUnderAnalyzer *v2; // r13
  hkaiTraversalAnalysisContext *v3; // rdi
  __m128i v4; // xmm3
  float v5; // xmm2_4
  float v6; // xmm8_4
  hkaiTraversalAnalysisSettings *v7; // rax
  __m128 v8; // xmm7
  float v9; // xmm1_4
  float v10; // xmm0_4
  __m128 v11; // xmm2
  __m128i v12; // xmm4
  __m128i v13; // xmm6
  __m128 v14; // xmm1
  __m128 v15; // xmm5
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  float v18; // xmm0_4
  __m128i v19; // xmm3
  int v20; // xmm0_4
  __m128i v21; // xmm6
  __m128 v22; // xmm2
  __m128i v23; // xmm6
  __m128 v24; // xmm1
  __m128 v25; // xmm5
  __m128 v26; // xmm4
  __m128 v27; // xmm2
  float v28; // xmm0_4
  __m128i v29; // xmm4
  float v30; // xmm0_4
  __m128i v31; // xmm7
  hkaiPairedEdgeFinder *v32; // rcx
  int v33; // esi
  __m128 v34; // xmm6
  __m128 v35; // xmm2
  __m128i v36; // xmm7
  __m128 v37; // xmm1
  __m128 v38; // xmm5
  __m128 v39; // xmm4
  __m128 v40; // xmm2
  __m128i v41; // xmm1
  __m128 v42; // xmm1
  __m128 v43; // xmm3
  __m128 v44; // xmm15
  float v45; // xmm15_4
  __int64 v46; // rbx
  __int64 v47; // r14
  hkaiPairedEdgeFinder::EdgePair *v48; // r15
  hkaiNavMeshUtils *v49; // rcx
  hkVector4f *v50; // r9
  hkVector4f *v51; // r9
  __m128 v52; // xmm1
  __m128 v53; // xmm0
  __m128 v54; // xmm1
  int v55; // er12
  __m128 v56; // xmm10
  __m128 v57; // xmm13
  hkaiIntervalPartition::Interval *v58; // rax
  int v59; // xmm1_4
  float v60; // xmm11_4
  float v61; // xmm12_4
  int v62; // xmm0_4
  __m128 v63; // xmm0
  __m128 v64; // xmm4
  __m128 v65; // xmm4
  __m128 v66; // xmm8
  __m128 v67; // xmm9
  __m128 v68; // xmm2
  __m128 v69; // xmm2
  __m128 v70; // xmm0
  __m128 v71; // xmm7
  __m128 v72; // xmm6
  __m128 v73; // xmm0
  __m128 v74; // xmm7
  hkaiNavMeshInstance *v75; // rax
  unsigned int v76; // er9
  __m128 v77; // xmm2
  __m128 v78; // xmm1
  unsigned int v79; // ecx
  hkaiNavMeshInstance *v80; // rax
  unsigned int v81; // ecx
  hkaiTraversalAnnotationLibrary *v82; // rcx
  unsigned int v83; // ebx
  hkaiIntervalPartition other; // [rsp+40h] [rbp-B8h]
  hkaiIntervalPartition clearanceOut; // [rsp+50h] [rbp-A8h]
  hkaiIntervalPartition v86; // [rsp+60h] [rbp-98h]
  hkaiIntervalPartition partition; // [rsp+70h] [rbp-88h]
  int v88; // [rsp+80h] [rbp-78h]
  int v89; // [rsp+84h] [rbp-74h]
  hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> pairsOut; // [rsp+88h] [rbp-70h]
  hkVector4f leftEnd; // [rsp+98h] [rbp-60h]
  hkVector4f p2; // [rsp+A8h] [rbp-50h]
  hkVector4f p1; // [rsp+B8h] [rbp-40h]
  hkVector4f p3; // [rsp+C8h] [rbp-30h]
  hkVector4f p0; // [rsp+D8h] [rbp-20h]
  hkVector4f leftInOut; // [rsp+E8h] [rbp-10h]
  hkVector4f rightEnd; // [rsp+F8h] [rbp+0h]
  hkVector4f rightInOut; // [rsp+108h] [rbp+10h]
  hkVector4f up; // [rsp+118h] [rbp+20h]
  hkaiPairedEdgeFinder::PairedEdgeSettings settings; // [rsp+128h] [rbp+30h]
  hkVector4f left; // [rsp+168h] [rbp+70h]
  hkVector4f right; // [rsp+178h] [rbp+80h]
  float v103; // [rsp+190h] [rbp+98h]
  int v104; // [rsp+194h] [rbp+9Ch]
  int v105; // [rsp+198h] [rbp+A0h]
  hkaiUserEdgeUtils::UserEdgePair userEdgePair; // [rsp+1A8h] [rbp+B0h]
  hkVector4f facePlane; // [rsp+1F8h] [rbp+100h]
  int faceIndex; // [rsp+208h] [rbp+110h]
  hkVector4f extrusion; // [rsp+218h] [rbp+120h]
  hkVector4f tEqnOut; // [rsp+228h] [rbp+130h]
  hkSimdFloat32 maxClearance; // [rsp+238h] [rbp+140h]
  float retaddr; // [rsp+328h] [rbp+230h]
  __int64 v113; // [rsp+330h] [rbp+238h]

  v2 = this;
  v3 = context;
  _mm_store_si128((__m128i *)&up, (__m128i)context->m_settings->m_up.m_quad);
  hkaiPairedEdgeFinder::PairedEdgeSettings::PairedEdgeSettings(&settings);
  v4 = _mm_load_si128((const __m128i *)_xmm);
  v5 = v2->m_maxHeightDifference;
  v6 = v2->m_maxPlanarAngle;
  v7 = v3->m_settings;
  v8 = _mm_add_ps((__m128)LODWORD(v2->m_maxPlanarAngle), *(__m128 *)_xmm);
  settings.m_up = (hkVector4f)up.m_quad;
  v9 = v7->m_minEdgeLength;
  settings.m_maxHeightDelta = v5;
  settings.m_minHorizontalDelta = 0.0;
  settings.m_minLength = v9;
  v10 = v5;
  v11 = _mm_andnot_ps(*(__m128 *)_xmm, v8);
  LODWORD(settings.m_minHeightDelta) = LODWORD(v10) ^ _xmm[0];
  v12 = _mm_add_epi32(v4, v4);
  settings.m_maxHorizontalDelta = v2->m_maxHorizontalDistance;
  _mm_store_si128((__m128i *)&leftEnd, v12);
  v13 = _mm_andnot_si128(v4, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v11, *(__m128 *)_xmm)), v4));
  v14 = _mm_cvtepi32_ps(v13);
  v15 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v13, v12), (__m128i)0i64);
  v16 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v14, *(__m128 *)DP1_0), v11), _mm_mul_ps(v14, *(__m128 *)DP2)),
          _mm_mul_ps(v14, *(__m128 *)DP3));
  v17 = _mm_mul_ps(v16, v16);
  v11.m128_i32[0] = (unsigned __int128)_mm_andnot_ps(
                                         v15,
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
  v18 = (float)((float)((float)((float)(v17.m128_f32[0] * -0.00019515296) + 0.0083321612) * v17.m128_f32[0])
              + -0.16666655)
      * v17.m128_f32[0];
  v19 = _mm_load_si128((const __m128i *)&leftEnd);
  v11.m128_i32[0] |= COERCE_UNSIGNED_INT((float)(v18 * v16.m128_f32[0]) + v16.m128_f32[0]) & v15.m128_i32[0];
  v20 = (unsigned __int128)_mm_and_si128(_mm_add_epi32(v19, v19), v13);
  v21 = _mm_load_si128((const __m128i *)_xmm);
  LODWORD(settings.m_cosMaxPlanarAngle) = v11.m128_i32[0] ^ (v20 << 29) ^ v8.m128_i32[0] & _xmm[0];
  v22 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(v6));
  v23 = _mm_andnot_si128(v21, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v22, *(__m128 *)_xmm)), v21));
  v24 = _mm_cvtepi32_ps(v23);
  v25 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v23, v19), (__m128i)0i64);
  v26 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v24, *(__m128 *)DP1_0), v22), _mm_mul_ps(v24, *(__m128 *)DP2)),
          _mm_mul_ps(v24, *(__m128 *)DP3));
  v27 = _mm_mul_ps(v26, v26);
  v28 = (float)((float)((float)((float)((float)((float)(v27.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                      * v27.m128_f32[0])
                              + -0.16666655)
                      * v27.m128_f32[0])
              * v26.m128_f32[0])
      + v26.m128_f32[0];
  v29 = _mm_load_si128((const __m128i *)&leftEnd);
  v19.m128i_i32[0] = (*(unsigned __int128 *)&_mm_andnot_ps(
                                               v25,
                                               _mm_add_ps(
                                                 _mm_sub_ps(
                                                   _mm_mul_ps(
                                                     _mm_mul_ps(
                                                       _mm_add_ps(
                                                         _mm_mul_ps(
                                                           _mm_add_ps(
                                                             _mm_mul_ps(v27, *(__m128 *)cosCoeff0_0),
                                                             *(__m128 *)cosCoeff1),
                                                           v27),
                                                         *(__m128 *)cosCoeff2_0),
                                                       v27),
                                                     v27),
                                                   _mm_mul_ps(v27, *(__m128 *)_xmm)),
                                                 *(__m128 *)_xmm)) | LODWORD(v28) & v25.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v29, v29), v23) << 29) ^ LODWORD(v6) & _xmm[0];
  v30 = v2->m_maxRelativeSlopeAngle;
  LODWORD(settings.m_sinMaxPlanarAngle) = v19.m128i_i32[0];
  v31 = _mm_load_si128((const __m128i *)_xmm);
  v32 = v3->m_pairedEdgeFinder.m_pntr;
  retaddr = v30;
  v33 = 0;
  *(_WORD *)&settings.m_matchAngles.m_bool = 1;
  v34 = _mm_add_ps((__m128)LODWORD(v30), *(__m128 *)_xmm);
  pairsOut.m_data = 0i64;
  pairsOut.m_size = 0;
  pairsOut.m_capacityAndFlags = 2147483648;
  v35 = _mm_andnot_ps(*(__m128 *)_xmm, v34);
  v36 = _mm_andnot_si128(v31, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v35, *(__m128 *)_xmm)), v31));
  v37 = _mm_cvtepi32_ps(v36);
  v38 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v36, v29), (__m128i)0i64);
  v39 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v37, *(__m128 *)DP1_0), v35), _mm_mul_ps(v37, *(__m128 *)DP2)),
          _mm_mul_ps(v37, *(__m128 *)DP3));
  v40 = _mm_mul_ps(v39, v39);
  v41 = _mm_load_si128((const __m128i *)&leftEnd);
  v42 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v41, v41), v36), 0x1Du),
          _mm_and_ps(v34, *(__m128 *)_xmm));
  v43 = _mm_xor_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              v38,
              _mm_add_ps(
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v40, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v40),
                        *(__m128 *)cosCoeff2_0),
                      v40),
                    v40),
                  _mm_mul_ps(v40, *(__m128 *)_xmm)),
                *(__m128 *)_xmm)),
            _mm_and_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v40, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v40),
                      *(__m128 *)sinCoeff2_0),
                    v40),
                  v39),
                v39),
              v38)),
          v42);
  LODWORD(settings.m_cosMaxDeltaSlopeAngle) = v43.m128_i32[0];
  hkaiPairedEdgeFinder::findEdgePairs(v32, &settings, &pairsOut);
  hkaiIntervalPartition::hkaiIntervalPartition(&partition);
  hkaiIntervalPartition::hkaiIntervalPartition(&clearanceOut);
  hkaiIntervalPartition::hkaiIntervalPartition(&v86);
  hkaiIntervalPartition::hkaiIntervalPartition((hkaiIntervalPartition *)((char *)&partition + 8));
  v44 = (__m128)LODWORD(v3->m_settings->m_minEdgeLength);
  maxClearance.m_real = _mm_shuffle_ps((__m128)LODWORD(v2->m_maxClearance), (__m128)LODWORD(v2->m_maxClearance), 0);
  v44.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v44, v44, 0);
  v45 = v44.m128_f32[0] * v44.m128_f32[0];
  v46 = pairsOut.m_size;
  v113 = pairsOut.m_size;
  v42.m128_f32[0] = COERCE_FLOAT(LODWORD(v2->m_minClearance) ^ _xmm[0]);
  extrusion.m_quad = _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), up.m_quad);
  if ( pairsOut.m_size > 0i64 )
  {
    v47 = 0i64;
    do
    {
      hkaiIntervalPartition::clear(&partition);
      hkaiIntervalPartition::clear(&clearanceOut);
      hkaiIntervalPartition::clear(&v86);
      v48 = pairsOut.m_data;
      v49 = (hkaiNavMeshUtils *)v3->m_fromNavMeshInstance;
      _mm_store_si128((__m128i *)&leftInOut, (__m128i)pairsOut.m_data[v47].m_startLeft.m_quad);
      _mm_store_si128((__m128i *)&rightInOut, (__m128i)v48[v47].m_startRight.m_quad);
      _mm_store_si128((__m128i *)&leftEnd, (__m128i)v48[v47].m_endLeft.m_quad);
      _mm_store_si128((__m128i *)&rightEnd, (__m128i)v48[v47].m_endRight.m_quad);
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        v49,
        (hkaiNavMeshInstance *)(unsigned int)v48[v47].m_startFace,
        (__int64)&faceIndex,
        v50);
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)v3->m_toNavMeshInstance,
        (hkaiNavMeshInstance *)(unsigned int)v48[v47].m_endFace,
        (__int64)&facePlane,
        v51);
      hkaiTraversalAnalysisUtils::setBackEdge(&leftInOut, &rightInOut, (hkVector4f *)&faceIndex, v3);
      hkaiTraversalAnalysisUtils::setBackEdge(&rightEnd, &leftEnd, &facePlane, v3);
      hkaiIntervalPartition::hkaiIntervalPartition(&other);
      hkaiTraversalAnalysisUtils::filterUnwalkableLandingZones(
        &leftInOut,
        &rightInOut,
        &leftEnd,
        &rightEnd,
        v48[v47].m_startFace,
        v48[v47].m_endFace,
        &other,
        v3);
      if ( other.m_intervals.m_size )
      {
        v52 = rightInOut.m_quad;
        _mm_store_si128((__m128i *)&p0, (__m128i)leftInOut.m_quad);
        v53 = leftEnd.m_quad;
        _mm_store_si128((__m128i *)&p1, (__m128i)v52);
        v54 = rightEnd.m_quad;
        _mm_store_si128((__m128i *)&p3, (__m128i)v53);
        _mm_store_si128((__m128i *)&p2, (__m128i)v54);
        hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&p0, &p1, v3);
        hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&p3, &p2, v3);
        hkaiTraversalAnalysisUtils::raiseToPlane(&p0, &p1, &p2, &p3, &up);
        hkaiGeometrySegmentCaster::turnSegmentExtruded(
          v3->m_cuttingGeometrySegmentCaster.m_pntr,
          &p0,
          &p1,
          &p3,
          &p2,
          &extrusion,
          &partition);
        if ( !hkaiIntervalPartition::coversInterval(&partition, 0.0, 1.0) )
        {
          hkaiIntervalPartition::discardRange(&partition);
          hkaiTraversalAnalysisUtils::findClearanceProfile(&p0, &p1, &p3, &p2, &up, &maxClearance, &clearanceOut, v3);
          hkaiIntervalPartition::clipY(&clearanceOut, v2->m_minClearance, v2->m_maxClearance);
          hkaiIntervalPartition::clipDefined(&clearanceOut, &partition);
          hkaiIntervalPartition::copyFrom(&v86, &clearanceOut);
          hkaiIntervalPartition::discardRange(&v86);
          hkaiIntervalPartition::clipNotDefined(&v86, &other);
          v55 = v86.m_intervals.m_size;
          v56 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(p3.m_quad, p0.m_quad), (__m128)xmmword_141A711B0), p0.m_quad);
          v57 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(p2.m_quad, p1.m_quad), (__m128)xmmword_141A711B0), p1.m_quad);
          if ( v86.m_intervals.m_size > 0 )
          {
            do
            {
              hkaiIntervalPartition::clear((hkaiIntervalPartition *)((char *)&partition + 8));
              v58 = hkaiIntervalPartition::getInterval(&v86, v33);
              v59 = LODWORD(v58->m_offset);
              v60 = v58->m_leftX;
              v61 = v58->m_rightX;
              v103 = v58->m_slope;
              v62 = v58->m_data;
              v104 = v59;
              v105 = v62;
              v43.m128_f32[0] = v60;
              v43 = _mm_shuffle_ps(v43, v43, 0);
              v63 = _mm_sub_ps(rightInOut.m_quad, leftInOut.m_quad);
              v64.m128_f32[0] = v61;
              v65 = _mm_shuffle_ps(v64, v64, 0);
              v66 = _mm_add_ps(_mm_mul_ps(v43, v63), leftInOut.m_quad);
              v67 = _mm_add_ps(_mm_mul_ps(v65, v63), leftInOut.m_quad);
              v68 = _mm_sub_ps(v66, v67);
              v69 = _mm_mul_ps(v68, v68);
              if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 170))) >= v45 )
              {
                v70 = _mm_sub_ps(rightEnd.m_quad, leftEnd.m_quad);
                v71 = _mm_mul_ps(v65, v70);
                v72 = _mm_add_ps(_mm_mul_ps(v43, v70), leftEnd.m_quad);
                v73 = _mm_sub_ps(v57, v56);
                v74 = _mm_add_ps(v71, leftEnd.m_quad);
                left.m_quad = _mm_add_ps(_mm_mul_ps(v43, v73), v56);
                right.m_quad = _mm_add_ps(_mm_mul_ps(v65, v73), v56);
                hkaiUserEdgeUtils::UserEdgePair::UserEdgePair(&userEdgePair);
                v75 = v3->m_fromNavMeshInstance;
                v76 = v2->m_userdata;
                v77 = _mm_shuffle_ps(v66, v67, 68);
                v78 = _mm_shuffle_ps(v74, v72, 68);
                userEdgePair.m_z.m_quad = _mm_shuffle_ps(
                                            _mm_shuffle_ps(v66, v67, 238),
                                            _mm_shuffle_ps(v74, v72, 238),
                                            136);
                userEdgePair.m_x.m_quad = _mm_shuffle_ps(v77, v78, 136);
                v73.m128_i32[0] = LODWORD(v2->m_baseCost);
                userEdgePair.m_y.m_quad = _mm_shuffle_ps(v77, v78, 221);
                v79 = v75->m_sectionUid;
                v80 = v3->m_toNavMeshInstance;
                userEdgePair.m_instanceUidA = v79;
                v81 = v80->m_sectionUid;
                retaddr = v73.m128_f32[0] * 1.0039062;
                userEdgePair.m_faceA = v48[v47].m_startFace;
                LODWORD(v80) = v48[v47].m_endFace;
                userEdgePair.m_instanceUidB = v81;
                v82 = v3->m_outputLibrary;
                userEdgePair.m_faceB = (signed int)v80;
                userEdgePair.m_direction.m_storage = 1;
                userEdgePair.m_costAtoB.m_value = HIWORD(retaddr);
                userEdgePair.m_costBtoA.m_value = 0;
                v83 = hkaiTraversalAnnotationLibrary::addAnnotation(
                        v82,
                        &userEdgePair,
                        HKAI_TRAVERSAL_TYPE_DUCK_UNDER,
                        v76);
                hkaiIntervalPartition::copyRegionFrom(
                  (hkaiIntervalPartition *)((char *)&partition + 8),
                  &clearanceOut,
                  v60,
                  v61);
                v43 = 0i64;
                hkaiIntervalPartition::remapX((hkaiIntervalPartition *)((char *)&partition + 8), v60, v61, 0.0, 1.0);
                hkaiTraversalAnnotationLibrary::addIntervalPartition(
                  v3->m_outputLibrary,
                  v83,
                  0,
                  (hkaiIntervalPartition *)((char *)&partition + 8),
                  1,
                  0);
                hkaiTraversalAnalysisUtils::makeTEquation(&left, &right, &tEqnOut);
                hkaiTraversalAnnotationLibrary::addVector(v3->m_outputLibrary, v83, 0, &left);
                hkaiTraversalAnnotationLibrary::addVector(v3->m_outputLibrary, v83, 1, &right);
                hkaiTraversalAnnotationLibrary::addVector(v3->m_outputLibrary, v83, 2, &tEqnOut);
              }
              ++v33;
            }
            while ( v33 < v55 );
            v46 = v113;
          }
          v33 = 0;
        }
      }
      other.m_intervals.m_size = 0;
      if ( other.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          other.m_intervals.m_data,
          20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      ++v47;
      --v46;
      other.m_intervals.m_data = 0i64;
      v113 = v46;
      other.m_intervals.m_capacityAndFlags = 2147483648;
    }
    while ( v46 );
  }
  v88 = 0;
  if ( v89 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)&partition.m_intervals.m_size,
      20 * (v89 & 0x3FFFFFFF));
  *(_QWORD *)&partition.m_intervals.m_size = 0i64;
  v89 = 2147483648;
  v86.m_intervals.m_size = 0;
  if ( v86.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v86.m_intervals.m_data,
      20 * (v86.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  v86.m_intervals.m_data = 0i64;
  v86.m_intervals.m_capacityAndFlags = 2147483648;
  clearanceOut.m_intervals.m_size = 0;
  if ( clearanceOut.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      clearanceOut.m_intervals.m_data,
      20 * (clearanceOut.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  clearanceOut.m_intervals.m_data = 0i64;
  clearanceOut.m_intervals.m_capacityAndFlags = 2147483648;
  partition.m_intervals.m_size = 0;
  if ( partition.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      partition.m_intervals.m_data,
      20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  partition.m_intervals.m_data = 0i64;
  pairsOut.m_size = 0;
  partition.m_intervals.m_capacityAndFlags = 2147483648;
  if ( pairsOut.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      pairsOut.m_data,
      80 * (pairsOut.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 194
// RVA: 0xC36050
unsigned int __fastcall hkaiDuckUnderUtils::getClearance(hkaiTraversalAnnotationLibrary *library, unsigned int *annotationIndex, hkVector4f *startPoint, float *clearanceOut)
{
  unsigned int *v4; // rsi
  float *y; // rdi
  hkVector4f *v6; // rbx
  hkaiTraversalAnnotationLibrary *v7; // rbp
  __m128 v8; // xmm2
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  hkVector4f v12; // [rsp+30h] [rbp-38h]
  hkVector4f vecOut; // [rsp+40h] [rbp-28h]
  hkVector4f v14; // [rsp+50h] [rbp-18h]

  v4 = annotationIndex;
  y = clearanceOut;
  v6 = startPoint;
  v7 = library;
  hkaiTraversalAnnotationLibrary::getVectorData(library, *annotationIndex, 0, &vecOut);
  hkaiTraversalAnnotationLibrary::getVectorData(v7, *v4, 1, &v14);
  hkaiTraversalAnnotationLibrary::getVectorData(v7, *v4, 2, &v12);
  v8 = _mm_mul_ps(v6->m_quad, v12.m_quad);
  v9 = _mm_shuffle_ps(v8, _mm_unpackhi_ps(v8, v12.m_quad), 196);
  v10 = _mm_add_ps(_mm_shuffle_ps(v9, v9, 78), v9);
  return hkaiTraversalAnnotationLibrary::tryEvaluateYAt(
           v7,
           *v4,
           0,
           COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 177)) + v10.m128_f32[0],
           y);
}

// File Line: 212
// RVA: 0xC36110
__int64 __fastcall hkaiDuckUnderUtils::getNumClearanceIntervals(hkaiTraversalAnnotationLibrary *library, unsigned int *annotationIndex)
{
  return hkaiTraversalAnnotationLibrary::getNumPartitionIntervals(library, *annotationIndex, 0);
}

// File Line: 219
// RVA: 0xC36480
void __fastcall `anonymous namespace'::linePlaneIntersection(hkVector4f *origin, hkVector4f *dir, hkVector4f *plane, hkVector4f *intOut)
{
  __m128 v4; // xmm2
  __m128 v5; // xmm1
  __m128 v6; // xmm4
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  __m128 v10; // xmm1

  v4 = _mm_mul_ps(origin->m_quad, plane->m_quad);
  v5 = _mm_mul_ps(plane->m_quad, dir->m_quad);
  v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v7 = _mm_shuffle_ps(v4, _mm_unpackhi_ps(v4, plane->m_quad), 196);
  v8 = _mm_add_ps(_mm_shuffle_ps(v7, v7, 78), v7);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 177), v8);
  v10 = _mm_rcp_ps(v6);
  intOut->m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       dir->m_quad,
                       _mm_mul_ps(
                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v10, v6)), v10),
                         _mm_sub_ps((__m128)0i64, v9))),
                     origin->m_quad);
}

// File Line: 234
// RVA: 0xC36130
void __fastcall hkaiDuckUnderUtils::getClearanceInterval(hkaiTraversalAnnotationLibrary *library, unsigned int *annotationIndex, int clearanceIntervalIndex, hkVector4f *leftStartPointOut, hkVector4f *rightStartPointOut, hkVector4f *leftEndPointOut)
{
  unsigned int *v6; // rdi
  unsigned int v7; // edx
  hkVector4f *v8; // r14
  unsigned __int16 v9; // bx
  hkaiTraversalAnnotationLibrary *v10; // rsi
  unsigned int v11; // edx
  hkaiUserEdgeUtils::UserEdgePair *v12; // rax
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  __m128 v15; // xmm9
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm0
  __m128 v19; // xmm10
  __m128 v20; // xmm13
  __m128 v21; // xmm2
  __m128 v22; // xmm9
  __m128 v23; // xmm7
  __m128 v24; // xmm5
  __m128 v25; // xmm5
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm5
  unsigned int v30; // edx
  __m128 v31; // xmm2
  __m128 v32; // xmm4
  __m128 v33; // xmm4
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  __m128 v37; // xmm4
  __m128 v38; // xmm2
  __m128 v39; // xmm13
  __m128 v40; // xmm1
  hkVector4f dir; // [rsp+30h] [rbp-C8h]
  hkVector4f leftOut; // [rsp+40h] [rbp-B8h]
  hkVector4f v43; // [rsp+50h] [rbp-A8h]
  hkVector4f origin; // [rsp+60h] [rbp-98h]
  char plane[24]; // [rsp+70h] [rbp-88h]
  hkVector4f yVector; // [rsp+88h] [rbp-70h]
  hkVector4f v47; // [rsp+98h] [rbp-60h]
  hkVector4f xVector; // [rsp+A8h] [rbp-50h]
  hkaiIntervalPartition::Interval intervalOut; // [rsp+B8h] [rbp-40h]
  hkVector4f *intOut; // [rsp+188h] [rbp+90h]

  v6 = annotationIndex;
  v7 = *annotationIndex;
  v8 = leftStartPointOut;
  v9 = clearanceIntervalIndex;
  v10 = library;
  _mm_store_si128((__m128i *)&yVector.m_quad.m128_u16[4], (__m128i)library->m_up.m_quad);
  hkaiTraversalAnnotationLibrary::getVectorData(library, v7, 0, (hkVector4f *)&plane[16]);
  hkaiTraversalAnnotationLibrary::getVectorData(v10, *v6, 1, &v47);
  v11 = *v6;
  xVector.m_quad = _mm_sub_ps(v47.m_quad, *(__m128 *)&plane[8]);
  v12 = hkaiTraversalAnnotationLibrary::getUserEdgePair(v10, v11);
  v13 = v12->m_z.m_quad;
  v14 = v13;
  v15 = _mm_shuffle_ps(v12->m_x.m_quad, v12->m_y.m_quad, 238);
  v16 = _mm_shuffle_ps(v13, (__m128)0i64, 238);
  v17 = _mm_shuffle_ps(v12->m_x.m_quad, v12->m_y.m_quad, 68);
  v18 = _mm_shuffle_ps(v14, (__m128)0i64, 68);
  v19 = _mm_shuffle_ps(v17, v18, 136);
  v20 = _mm_shuffle_ps(v15, v16, 221);
  v21 = _mm_sub_ps(_mm_shuffle_ps(v17, v18, 221), v19);
  v22 = _mm_sub_ps(_mm_shuffle_ps(v15, v16, 136), v20);
  v23 = _mm_shuffle_ps(yVector.m_quad, yVector.m_quad, 201);
  v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), yVector.m_quad), _mm_mul_ps(v23, v21));
  v25 = _mm_shuffle_ps(v24, v24, 201);
  v26 = _mm_mul_ps(v25, v25);
  v27 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)), _mm_shuffle_ps(v26, v26, 170));
  v28 = _mm_rsqrt_ps(v27);
  v29 = _mm_mul_ps(
          v25,
          _mm_andnot_ps(
            _mm_cmpleps(v27, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v27), v28)),
              _mm_mul_ps(*(__m128 *)_xmm, v28))));
  v30 = *v6;
  v31 = _mm_mul_ps(v29, v19);
  v32 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), yVector.m_quad), _mm_mul_ps(v23, v22));
  v33 = _mm_shuffle_ps(v32, v32, 201);
  *(__m128 *)plane = _mm_shuffle_ps(
                       v29,
                       _mm_unpackhi_ps(
                         v29,
                         _mm_sub_ps(
                           (__m128)0i64,
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                             _mm_shuffle_ps(v31, v31, 170)))),
                       196);
  v34 = _mm_mul_ps(v33, v33);
  v35 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)), _mm_shuffle_ps(v34, v34, 170));
  v36 = _mm_rsqrt_ps(v35);
  v37 = _mm_mul_ps(
          v33,
          _mm_andnot_ps(
            _mm_cmpleps(v35, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
              _mm_mul_ps(*(__m128 *)_xmm, v36))));
  v38 = _mm_mul_ps(v37, v20);
  v39 = _mm_sub_ps(v20, v19);
  v40 = _mm_mul_ps(v39, yVector.m_quad);
  v43.m_quad = _mm_shuffle_ps(
                 v37,
                 _mm_unpackhi_ps(
                   v37,
                   _mm_sub_ps(
                     (__m128)0i64,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                       _mm_shuffle_ps(v38, v38, 170)))),
                 196);
  dir.m_quad = _mm_sub_ps(
                 v39,
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
                     _mm_shuffle_ps(v40, v40, 170)),
                   yVector.m_quad));
  hkaiTraversalAnnotationLibrary::getPartitionInterval(v10, v30, 0, v9, &intervalOut);
  hkaiIntervalPartition::Interval::interpolateParallelogram(
    &intervalOut,
    (hkVector4f *)&plane[8],
    &xVector,
    &yVector,
    &leftOut,
    &origin);
  `anonymous namespace'::linePlaneIntersection(&leftOut, &dir, (hkVector4f *)plane, v8);
  `anonymous namespace'::linePlaneIntersection(&origin, &dir, (hkVector4f *)plane, intOut);
  `anonymous namespace'::linePlaneIntersection(&leftOut, &dir, &v43, rightStartPointOut);
  `anonymous namespace'::linePlaneIntersection(&origin, &dir, &v43, leftEndPointOut);
}


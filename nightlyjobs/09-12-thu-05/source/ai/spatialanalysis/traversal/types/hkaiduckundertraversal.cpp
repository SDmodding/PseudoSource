// File Line: 25
// RVA: 0xC354B0
void __fastcall hkaiDuckUnderAnalyzer::analyze(hkaiDuckUnderAnalyzer *this, hkaiTraversalAnalysisContext *context)
{
  __m128i si128; // xmm3
  float m_maxHeightDifference; // xmm2_4
  float m_maxPlanarAngle; // xmm8_4
  hkaiTraversalAnalysisSettings *m_settings; // rax
  __m128 v8; // xmm7
  float m_minEdgeLength; // xmm1_4
  float v10; // xmm0_4
  __m128 v11; // xmm2
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
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 m_minEdgeLength_low; // xmm15
  float v40; // xmm15_4
  __int64 m_size; // rbx
  __int64 v42; // r14
  hkaiPairedEdgeFinder::EdgePair *m_data; // r15
  hkaiNavMeshInstance *m_fromNavMeshInstance; // rcx
  hkVector4f *v45; // r9
  hkVector4f *v46; // r9
  int v47; // r12d
  __m128 v48; // xmm10
  __m128 v49; // xmm13
  hkaiIntervalPartition::Interval *Interval; // rax
  int m_offset_low; // xmm1_4
  float m_leftX; // xmm11_4
  float m_rightX; // xmm12_4
  int v54; // xmm0_4
  __m128 v55; // xmm0
  __m128 v56; // xmm4
  __m128 v57; // xmm4
  __m128 v58; // xmm8
  __m128 v59; // xmm9
  __m128 v60; // xmm2
  __m128 v61; // xmm2
  __m128 v62; // xmm0
  __m128 v63; // xmm7
  __m128 v64; // xmm6
  __m128 v65; // xmm0
  __m128 v66; // xmm7
  hkaiNavMeshInstance *v67; // rax
  unsigned int m_userdata; // r9d
  __m128 v69; // xmm2
  __m128 v70; // xmm1
  unsigned int m_sectionUid; // ecx
  hkaiNavMeshInstance *m_toNavMeshInstance; // rax
  unsigned int v73; // ecx
  hkaiTraversalAnnotationLibrary *m_outputLibrary; // rcx
  unsigned int v75; // ebx
  hkaiIntervalPartition other; // [rsp+40h] [rbp-B8h] BYREF
  hkaiIntervalPartition clearanceOut; // [rsp+50h] [rbp-A8h] BYREF
  hkaiIntervalPartition v78; // [rsp+60h] [rbp-98h] BYREF
  hkaiIntervalPartition partition; // [rsp+70h] [rbp-88h] BYREF
  int v80; // [rsp+80h] [rbp-78h]
  int v81; // [rsp+84h] [rbp-74h]
  hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> pairsOut; // [rsp+88h] [rbp-70h] BYREF
  hkVector4f leftEnd; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f p2; // [rsp+A8h] [rbp-50h] BYREF
  hkVector4f p1; // [rsp+B8h] [rbp-40h] BYREF
  hkVector4f p3; // [rsp+C8h] [rbp-30h] BYREF
  hkVector4f p0; // [rsp+D8h] [rbp-20h] BYREF
  hkVector4f leftInOut; // [rsp+E8h] [rbp-10h] BYREF
  hkVector4f rightEnd; // [rsp+F8h] [rbp+0h] BYREF
  hkVector4f rightInOut; // [rsp+108h] [rbp+10h] BYREF
  hkVector4f up; // [rsp+118h] [rbp+20h] BYREF
  hkaiPairedEdgeFinder::PairedEdgeSettings settings; // [rsp+128h] [rbp+30h] BYREF
  hkVector4f left; // [rsp+168h] [rbp+70h] BYREF
  hkVector4f right; // [rsp+178h] [rbp+80h] BYREF
  float m_slope; // [rsp+190h] [rbp+98h]
  int v96; // [rsp+194h] [rbp+9Ch]
  int v97; // [rsp+198h] [rbp+A0h]
  hkaiUserEdgeUtils::UserEdgePair userEdgePair; // [rsp+1A8h] [rbp+B0h] BYREF
  hkVector4f facePlane; // [rsp+1F8h] [rbp+100h] BYREF
  __m128 faceIndex; // [rsp+208h] [rbp+110h] BYREF
  hkVector4f extrusion; // [rsp+218h] [rbp+120h] BYREF
  hkVector4f tEqnOut; // [rsp+228h] [rbp+130h] BYREF
  hkSimdFloat32 maxClearance; // [rsp+238h] [rbp+140h] BYREF
  void *retaddr; // [rsp+328h] [rbp+230h]
  __int64 v105; // [rsp+330h] [rbp+238h]

  up.m_quad = (__m128)context->m_settings->m_up;
  hkaiPairedEdgeFinder::PairedEdgeSettings::PairedEdgeSettings(&settings);
  si128 = _mm_load_si128((const __m128i *)_xmm);
  m_maxHeightDifference = this->m_maxHeightDifference;
  m_maxPlanarAngle = this->m_maxPlanarAngle;
  m_settings = context->m_settings;
  v8 = _mm_add_ps((__m128)LODWORD(m_maxPlanarAngle), *(__m128 *)_xmm);
  settings.m_up = (hkVector4f)up.m_quad;
  m_minEdgeLength = m_settings->m_minEdgeLength;
  settings.m_maxHeightDelta = m_maxHeightDifference;
  settings.m_minHorizontalDelta = 0.0;
  settings.m_minLength = m_minEdgeLength;
  v10 = m_maxHeightDifference;
  v11 = _mm_andnot_ps(*(__m128 *)_xmm, v8);
  LODWORD(settings.m_minHeightDelta) = LODWORD(v10) ^ _xmm[0];
  settings.m_maxHorizontalDelta = this->m_maxHorizontalDistance;
  leftEnd.m_quad = (__m128)_mm_add_epi32(si128, si128);
  v12 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v11, *(__m128 *)_xmm)), si128));
  v13 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v12, (__m128i)leftEnd.m_quad), (__m128i)0i64);
  v14 = _mm_cvtepi32_ps(v12);
  v15 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v14, *(__m128 *)DP1_0), v11), _mm_mul_ps(v14, *(__m128 *)DP2)),
          _mm_mul_ps(v14, *(__m128 *)DP3));
  v16 = _mm_mul_ps(v15, v15);
  v11.m128_f32[0] = _mm_andnot_ps(
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
  v17 = _mm_load_si128((const __m128i *)&leftEnd);
  v11.m128_i32[0] |= COERCE_UNSIGNED_INT((float)(v14.m128_f32[0] * v15.m128_f32[0]) + v15.m128_f32[0]) & v13.m128_i32[0];
  v14.m128_i32[0] = _mm_and_si128(_mm_add_epi32(v17, v17), v12).m128i_u32[0];
  v18 = _mm_load_si128((const __m128i *)_xmm);
  LODWORD(settings.m_cosMaxPlanarAngle) = v11.m128_i32[0] ^ (v14.m128_i32[0] << 29) ^ v8.m128_i32[0] & _xmm[0];
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
  v25 = _mm_load_si128((const __m128i *)&leftEnd);
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
  *(_WORD *)&settings.m_matchAngles.m_bool = 1;
  v29 = _mm_add_ps((__m128)v22.m128_u32[0], *(__m128 *)_xmm);
  pairsOut.m_data = 0i64;
  pairsOut.m_size = 0;
  pairsOut.m_capacityAndFlags = 0x80000000;
  v30 = _mm_andnot_ps(*(__m128 *)_xmm, v29);
  v31 = _mm_andnot_si128(v26, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v30, *(__m128 *)_xmm)), v26));
  v32 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v31, v25), (__m128i)0i64);
  v33 = _mm_cvtepi32_ps(v31);
  v34 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v33, *(__m128 *)DP1_0), v30), _mm_mul_ps(v33, *(__m128 *)DP2)),
          _mm_mul_ps(v33, *(__m128 *)DP3));
  v35 = _mm_mul_ps(v34, v34);
  v36 = _mm_load_si128((const __m128i *)&leftEnd);
  v37 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v36, v36), v31), 0x1Du),
          _mm_and_ps(v29, *(__m128 *)_xmm));
  v38 = _mm_xor_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              v32,
              _mm_add_ps(
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v35, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v35),
                        *(__m128 *)cosCoeff2_0),
                      v35),
                    v35),
                  _mm_mul_ps(v35, *(__m128 *)_xmm)),
                *(__m128 *)_xmm)),
            _mm_and_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v35, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v35),
                      *(__m128 *)sinCoeff2_0),
                    v35),
                  v34),
                v34),
              v32)),
          v37);
  LODWORD(settings.m_cosMaxDeltaSlopeAngle) = v38.m128_i32[0];
  hkaiPairedEdgeFinder::findEdgePairs(m_pntr, &settings, &pairsOut);
  hkaiIntervalPartition::hkaiIntervalPartition(&partition);
  hkaiIntervalPartition::hkaiIntervalPartition(&clearanceOut);
  hkaiIntervalPartition::hkaiIntervalPartition(&v78);
  hkaiIntervalPartition::hkaiIntervalPartition((hkaiIntervalPartition *)&partition.m_intervals.m_size);
  m_minEdgeLength_low = (__m128)LODWORD(context->m_settings->m_minEdgeLength);
  maxClearance.m_real = _mm_shuffle_ps((__m128)LODWORD(this->m_maxClearance), (__m128)LODWORD(this->m_maxClearance), 0);
  m_minEdgeLength_low.m128_f32[0] = _mm_shuffle_ps(m_minEdgeLength_low, m_minEdgeLength_low, 0).m128_f32[0];
  v40 = m_minEdgeLength_low.m128_f32[0] * m_minEdgeLength_low.m128_f32[0];
  m_size = pairsOut.m_size;
  v105 = pairsOut.m_size;
  v37.m128_i32[0] = LODWORD(this->m_minClearance) ^ _xmm[0];
  extrusion.m_quad = _mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), up.m_quad);
  if ( pairsOut.m_size > 0 )
  {
    v42 = 0i64;
    do
    {
      hkaiIntervalPartition::clear(&partition);
      hkaiIntervalPartition::clear(&clearanceOut);
      hkaiIntervalPartition::clear(&v78);
      m_data = pairsOut.m_data;
      m_fromNavMeshInstance = context->m_fromNavMeshInstance;
      leftInOut.m_quad = (__m128)pairsOut.m_data[v42].m_startLeft;
      rightInOut.m_quad = (__m128)pairsOut.m_data[v42].m_startRight;
      leftEnd.m_quad = (__m128)pairsOut.m_data[v42].m_endLeft;
      rightEnd.m_quad = (__m128)pairsOut.m_data[v42].m_endRight;
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)m_fromNavMeshInstance,
        (hkaiNavMeshInstance *)(unsigned int)pairsOut.m_data[v42].m_startFace,
        &faceIndex,
        v45);
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)context->m_toNavMeshInstance,
        (hkaiNavMeshInstance *)(unsigned int)m_data[v42].m_endFace,
        &facePlane.m_quad,
        v46);
      hkaiTraversalAnalysisUtils::setBackEdge(&leftInOut, &rightInOut, (hkVector4f *)&faceIndex, context);
      hkaiTraversalAnalysisUtils::setBackEdge(&rightEnd, &leftEnd, &facePlane, context);
      hkaiIntervalPartition::hkaiIntervalPartition(&other);
      hkaiTraversalAnalysisUtils::filterUnwalkableLandingZones(
        &leftInOut,
        &rightInOut,
        &leftEnd,
        &rightEnd,
        m_data[v42].m_startFace,
        m_data[v42].m_endFace,
        &other,
        context);
      if ( other.m_intervals.m_size )
      {
        p0.m_quad = leftInOut.m_quad;
        p1.m_quad = rightInOut.m_quad;
        p3.m_quad = leftEnd.m_quad;
        p2.m_quad = rightEnd.m_quad;
        hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&p0, &p1, context);
        hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&p3, &p2, context);
        hkaiTraversalAnalysisUtils::raiseToPlane(&p0, &p1, &p2, &p3, &up);
        hkaiGeometrySegmentCaster::turnSegmentExtruded(
          context->m_cuttingGeometrySegmentCaster.m_pntr,
          &p0,
          &p1,
          &p3,
          &p2,
          &extrusion,
          &partition);
        if ( !hkaiIntervalPartition::coversInterval(&partition, 0.0, 1.0) )
        {
          hkaiIntervalPartition::discardRange(&partition);
          hkaiTraversalAnalysisUtils::findClearanceProfile(
            &p0,
            &p1,
            &p3,
            &p2,
            &up,
            &maxClearance,
            &clearanceOut,
            context);
          hkaiIntervalPartition::clipY(&clearanceOut, this->m_minClearance, this->m_maxClearance);
          hkaiIntervalPartition::clipDefined(&clearanceOut, &partition);
          hkaiIntervalPartition::copyFrom(&v78, &clearanceOut);
          hkaiIntervalPartition::discardRange(&v78);
          hkaiIntervalPartition::clipNotDefined(&v78, &other);
          v47 = v78.m_intervals.m_size;
          v48 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(p3.m_quad, p0.m_quad), (__m128)xmmword_141A711B0), p0.m_quad);
          v49 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(p2.m_quad, p1.m_quad), (__m128)xmmword_141A711B0), p1.m_quad);
          if ( v78.m_intervals.m_size > 0 )
          {
            do
            {
              hkaiIntervalPartition::clear((hkaiIntervalPartition *)&partition.m_intervals.m_size);
              Interval = hkaiIntervalPartition::getInterval(&v78, v28);
              m_offset_low = LODWORD(Interval->m_offset);
              m_leftX = Interval->m_leftX;
              m_rightX = Interval->m_rightX;
              m_slope = Interval->m_slope;
              v54 = Interval->m_data;
              v96 = m_offset_low;
              v97 = v54;
              v38.m128_f32[0] = m_leftX;
              v38 = _mm_shuffle_ps(v38, v38, 0);
              v55 = _mm_sub_ps(rightInOut.m_quad, leftInOut.m_quad);
              v56.m128_f32[0] = m_rightX;
              v57 = _mm_shuffle_ps(v56, v56, 0);
              v58 = _mm_add_ps(_mm_mul_ps(v38, v55), leftInOut.m_quad);
              v59 = _mm_add_ps(_mm_mul_ps(v57, v55), leftInOut.m_quad);
              v60 = _mm_sub_ps(v58, v59);
              v61 = _mm_mul_ps(v60, v60);
              if ( (float)((float)(_mm_shuffle_ps(v61, v61, 85).m128_f32[0] + _mm_shuffle_ps(v61, v61, 0).m128_f32[0])
                         + _mm_shuffle_ps(v61, v61, 170).m128_f32[0]) >= v40 )
              {
                v62 = _mm_sub_ps(rightEnd.m_quad, leftEnd.m_quad);
                v63 = _mm_mul_ps(v57, v62);
                v64 = _mm_add_ps(_mm_mul_ps(v38, v62), leftEnd.m_quad);
                v65 = _mm_sub_ps(v49, v48);
                v66 = _mm_add_ps(v63, leftEnd.m_quad);
                left.m_quad = _mm_add_ps(_mm_mul_ps(v38, v65), v48);
                right.m_quad = _mm_add_ps(_mm_mul_ps(v57, v65), v48);
                hkaiUserEdgeUtils::UserEdgePair::UserEdgePair(&userEdgePair);
                v67 = context->m_fromNavMeshInstance;
                m_userdata = this->m_userdata;
                v69 = _mm_shuffle_ps(v58, v59, 68);
                v70 = _mm_shuffle_ps(v66, v64, 68);
                userEdgePair.m_z.m_quad = _mm_shuffle_ps(
                                            _mm_shuffle_ps(v58, v59, 238),
                                            _mm_shuffle_ps(v66, v64, 238),
                                            136);
                userEdgePair.m_x.m_quad = _mm_shuffle_ps(v69, v70, 136);
                v65.m128_i32[0] = LODWORD(this->m_baseCost);
                userEdgePair.m_y.m_quad = _mm_shuffle_ps(v69, v70, 221);
                m_sectionUid = v67->m_sectionUid;
                m_toNavMeshInstance = context->m_toNavMeshInstance;
                userEdgePair.m_instanceUidA = m_sectionUid;
                v73 = m_toNavMeshInstance->m_sectionUid;
                *(float *)&retaddr = v65.m128_f32[0] * 1.0039062;
                userEdgePair.m_faceA = m_data[v42].m_startFace;
                LODWORD(m_toNavMeshInstance) = m_data[v42].m_endFace;
                userEdgePair.m_instanceUidB = v73;
                m_outputLibrary = context->m_outputLibrary;
                userEdgePair.m_faceB = (int)m_toNavMeshInstance;
                userEdgePair.m_direction.m_storage = 1;
                userEdgePair.m_costAtoB.m_value = WORD1(retaddr);
                userEdgePair.m_costBtoA.m_value = 0;
                v75 = hkaiTraversalAnnotationLibrary::addAnnotation(
                        m_outputLibrary,
                        &userEdgePair,
                        HKAI_TRAVERSAL_TYPE_DUCK_UNDER,
                        m_userdata);
                hkaiIntervalPartition::copyRegionFrom(
                  (hkaiIntervalPartition *)&partition.m_intervals.m_size,
                  &clearanceOut,
                  m_leftX,
                  m_rightX);
                v38 = 0i64;
                hkaiIntervalPartition::remapX(
                  (hkaiIntervalPartition *)&partition.m_intervals.m_size,
                  m_leftX,
                  m_rightX,
                  0.0,
                  1.0);
                hkaiTraversalAnnotationLibrary::addIntervalPartition(
                  context->m_outputLibrary,
                  v75,
                  0,
                  (hkaiIntervalPartition *)&partition.m_intervals.m_size,
                  1,
                  0);
                hkaiTraversalAnalysisUtils::makeTEquation(&left, &right, &tEqnOut);
                hkaiTraversalAnnotationLibrary::addVector(context->m_outputLibrary, v75, 0, &left);
                hkaiTraversalAnnotationLibrary::addVector(context->m_outputLibrary, v75, 1, &right);
                hkaiTraversalAnnotationLibrary::addVector(context->m_outputLibrary, v75, 2, &tEqnOut);
              }
              ++v28;
            }
            while ( v28 < v47 );
            m_size = v105;
          }
          v28 = 0;
        }
      }
      other.m_intervals.m_size = 0;
      if ( other.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          other.m_intervals.m_data,
          20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      ++v42;
      --m_size;
      other.m_intervals.m_data = 0i64;
      v105 = m_size;
      other.m_intervals.m_capacityAndFlags = 0x80000000;
    }
    while ( m_size );
  }
  v80 = 0;
  if ( v81 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)&partition.m_intervals.m_size,
      20 * (v81 & 0x3FFFFFFF));
  *(_QWORD *)&partition.m_intervals.m_size = 0i64;
  v81 = 0x80000000;
  v78.m_intervals.m_size = 0;
  if ( v78.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v78.m_intervals.m_data,
      20 * (v78.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  v78.m_intervals.m_data = 0i64;
  v78.m_intervals.m_capacityAndFlags = 0x80000000;
  clearanceOut.m_intervals.m_size = 0;
  if ( clearanceOut.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      clearanceOut.m_intervals.m_data,
      20 * (clearanceOut.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  clearanceOut.m_intervals.m_data = 0i64;
  clearanceOut.m_intervals.m_capacityAndFlags = 0x80000000;
  partition.m_intervals.m_size = 0;
  if ( partition.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      partition.m_intervals.m_data,
      20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  partition.m_intervals.m_data = 0i64;
  pairsOut.m_size = 0;
  partition.m_intervals.m_capacityAndFlags = 0x80000000;
  if ( pairsOut.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      pairsOut.m_data,
      80 * (pairsOut.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 194
// RVA: 0xC36050
unsigned int __fastcall hkaiDuckUnderUtils::getClearance(
        hkaiTraversalAnnotationLibrary *library,
        unsigned int *annotationIndex,
        hkVector4f *startPoint,
        float *clearanceOut)
{
  __m128 v8; // xmm2
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  hkVector4f v12; // [rsp+30h] [rbp-38h] BYREF
  hkVector4f vecOut; // [rsp+40h] [rbp-28h] BYREF
  hkVector4f v14; // [rsp+50h] [rbp-18h] BYREF

  hkaiTraversalAnnotationLibrary::getVectorData(library, *annotationIndex, 0, &vecOut);
  hkaiTraversalAnnotationLibrary::getVectorData(library, *annotationIndex, 1, &v14);
  hkaiTraversalAnnotationLibrary::getVectorData(library, *annotationIndex, 2, &v12);
  v8 = _mm_mul_ps(startPoint->m_quad, v12.m_quad);
  v9 = _mm_shuffle_ps(v8, _mm_unpackhi_ps(v8, v12.m_quad), 196);
  v10 = _mm_add_ps(_mm_shuffle_ps(v9, v9, 78), v9);
  return hkaiTraversalAnnotationLibrary::tryEvaluateYAt(
           library,
           *annotationIndex,
           0,
           _mm_shuffle_ps(v10, v10, 177).m128_f32[0] + v10.m128_f32[0],
           clearanceOut);
}

// File Line: 212
// RVA: 0xC36110
__int64 __fastcall hkaiDuckUnderUtils::getNumClearanceIntervals(
        hkaiTraversalAnnotationLibrary *library,
        unsigned int *annotationIndex)
{
  return hkaiTraversalAnnotationLibrary::getNumPartitionIntervals(library, *annotationIndex, 0);
}

// File Line: 219
// RVA: 0xC36480
void __fastcall `anonymous namespace::linePlaneIntersection(
        hkVector4f *origin,
        hkVector4f *dir,
        hkVector4f *plane,
        hkVector4f *intOut)
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
void __fastcall hkaiDuckUnderUtils::getClearanceInterval(
        hkaiTraversalAnnotationLibrary *library,
        unsigned int *annotationIndex,
        unsigned __int16 clearanceIntervalIndex,
        hkVector4f *leftStartPointOut,
        hkVector4f *rightStartPointOut,
        hkVector4f *leftEndPointOut)
{
  unsigned int v7; // edx
  unsigned int v11; // edx
  hkaiUserEdgeUtils::UserEdgePair *UserEdgePair; // rax
  __m128 m_quad; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm13
  __m128 v16; // xmm0
  __m128 v17; // xmm9
  __m128 v18; // xmm10
  __m128 v19; // xmm2
  __m128 v20; // xmm10
  __m128 v21; // xmm13
  __m128 v22; // xmm2
  __m128 v23; // xmm9
  __m128 v24; // xmm7
  __m128 v25; // xmm5
  __m128 v26; // xmm5
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm5
  unsigned int v31; // edx
  __m128 v32; // xmm2
  __m128 v33; // xmm4
  __m128 v34; // xmm4
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm4
  __m128 v39; // xmm2
  __m128 v40; // xmm13
  __m128 v41; // xmm1
  hkVector4f dir; // [rsp+30h] [rbp-C8h] BYREF
  hkVector4f leftOut; // [rsp+40h] [rbp-B8h] BYREF
  hkVector4f v44; // [rsp+50h] [rbp-A8h] BYREF
  hkVector4f origin; // [rsp+60h] [rbp-98h] BYREF
  char plane[24]; // [rsp+70h] [rbp-88h] BYREF
  hkVector4f yVector; // [rsp+88h] [rbp-70h] BYREF
  hkVector4f v48; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f xVector; // [rsp+A8h] [rbp-50h] BYREF
  hkaiIntervalPartition::Interval intervalOut; // [rsp+B8h] [rbp-40h] BYREF
  hkVector4f *intOut; // [rsp+188h] [rbp+90h]

  v7 = *annotationIndex;
  yVector.m_quad = (__m128)library->m_up;
  hkaiTraversalAnnotationLibrary::getVectorData(library, v7, 0, (hkVector4f *)&plane[16]);
  hkaiTraversalAnnotationLibrary::getVectorData(library, *annotationIndex, 1, &v48);
  v11 = *annotationIndex;
  xVector.m_quad = _mm_sub_ps(v48.m_quad, *(__m128 *)&plane[8]);
  UserEdgePair = hkaiTraversalAnnotationLibrary::getUserEdgePair(library, v11);
  m_quad = UserEdgePair->m_z.m_quad;
  v14 = _mm_shuffle_ps(m_quad, (__m128)0i64, 238);
  v15 = _mm_shuffle_ps(UserEdgePair->m_x.m_quad, UserEdgePair->m_y.m_quad, 238);
  v16 = _mm_shuffle_ps(m_quad, (__m128)0i64, 68);
  v17 = _mm_shuffle_ps(v15, v14, 136);
  v18 = _mm_shuffle_ps(UserEdgePair->m_x.m_quad, UserEdgePair->m_y.m_quad, 68);
  v19 = _mm_shuffle_ps(v18, v16, 221);
  v20 = _mm_shuffle_ps(v18, v16, 136);
  v21 = _mm_shuffle_ps(v15, v14, 221);
  v22 = _mm_sub_ps(v19, v20);
  v23 = _mm_sub_ps(v17, v21);
  v24 = _mm_shuffle_ps(yVector.m_quad, yVector.m_quad, 201);
  v25 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), yVector.m_quad), _mm_mul_ps(v24, v22));
  v26 = _mm_shuffle_ps(v25, v25, 201);
  v27 = _mm_mul_ps(v26, v26);
  v28 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)), _mm_shuffle_ps(v27, v27, 170));
  v29 = _mm_rsqrt_ps(v28);
  v30 = _mm_mul_ps(
          v26,
          _mm_andnot_ps(
            _mm_cmple_ps(v28, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
              _mm_mul_ps(*(__m128 *)_xmm, v29))));
  v31 = *annotationIndex;
  v32 = _mm_mul_ps(v30, v20);
  v33 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), yVector.m_quad), _mm_mul_ps(v24, v23));
  v34 = _mm_shuffle_ps(v33, v33, 201);
  *(__m128 *)plane = _mm_shuffle_ps(
                       v30,
                       _mm_unpackhi_ps(
                         v30,
                         _mm_sub_ps(
                           (__m128)0i64,
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                             _mm_shuffle_ps(v32, v32, 170)))),
                       196);
  v35 = _mm_mul_ps(v34, v34);
  v36 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)), _mm_shuffle_ps(v35, v35, 170));
  v37 = _mm_rsqrt_ps(v36);
  v38 = _mm_mul_ps(
          v34,
          _mm_andnot_ps(
            _mm_cmple_ps(v36, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v36), v37)),
              _mm_mul_ps(*(__m128 *)_xmm, v37))));
  v39 = _mm_mul_ps(v38, v21);
  v40 = _mm_sub_ps(v21, v20);
  v41 = _mm_mul_ps(v40, yVector.m_quad);
  v44.m_quad = _mm_shuffle_ps(
                 v38,
                 _mm_unpackhi_ps(
                   v38,
                   _mm_sub_ps(
                     (__m128)0i64,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                       _mm_shuffle_ps(v39, v39, 170)))),
                 196);
  dir.m_quad = _mm_sub_ps(
                 v40,
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                     _mm_shuffle_ps(v41, v41, 170)),
                   yVector.m_quad));
  hkaiTraversalAnnotationLibrary::getPartitionInterval(library, v31, 0, clearanceIntervalIndex, &intervalOut);
  hkaiIntervalPartition::Interval::interpolateParallelogram(
    &intervalOut,
    (hkVector4f *)&plane[8],
    &xVector,
    &yVector,
    &leftOut,
    &origin);
  `anonymous namespace::linePlaneIntersection(&leftOut, &dir, (hkVector4f *)plane, leftStartPointOut);
  `anonymous namespace::linePlaneIntersection(&origin, &dir, (hkVector4f *)plane, intOut);
  `anonymous namespace::linePlaneIntersection(&leftOut, &dir, &v44, rightStartPointOut);
  `anonymous namespace::linePlaneIntersection(&origin, &dir, &v44, leftEndPointOut);
}


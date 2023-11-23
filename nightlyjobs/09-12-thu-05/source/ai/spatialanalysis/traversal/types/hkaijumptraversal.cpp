// File Line: 23
// RVA: 0xC36A20
void __fastcall hkaiJumpAnalyzer::analyze(hkaiJumpAnalyzer *this, hkaiTraversalAnalysisContext *context)
{
  hkVector4f v4; // xmm6
  __m128i si128; // xmm3
  hkaiTraversalAnalysisSettings *m_settings; // rax
  float m_maxPlanarAngle; // xmm8_4
  int v8; // xmm1_4
  __m128 v9; // xmm7
  float m_minEdgeLength; // xmm0_4
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
  __m128 v28; // xmm6
  __m128 v29; // xmm2
  __m128i v30; // xmm7
  __m128 v31; // xmm5
  __m128 v32; // xmm0
  __m128 v33; // xmm4
  __m128 v34; // xmm2
  __m128 v35; // xmm14
  __m128i v36; // xmm1
  __m128 v37; // xmm15
  __m128 v38; // xmm6
  __m128 v39; // xmm6
  __m128 v40; // xmm12
  hkVector4f *v41; // r9
  __int64 m_size; // r12
  char v43; // di
  __int64 v44; // rsi
  hkaiPairedEdgeFinder::EdgePair *m_data; // r14
  hkaiNavMeshInstance *m_fromNavMeshInstance; // rcx
  hkVector4f *v47; // r9
  __m128 v48; // xmm7
  hkaiTraversalAnalysisSettings *v49; // rax
  __m128 v50; // xmm2
  int v51; // r15d
  hkaiTraversalAnalysisSettings *v52; // rax
  hkaiGeometrySegmentCaster *v53; // rcx
  __m128 v54; // xmm6
  __m128 v55; // xmm5
  __m128 v56; // xmm5
  __m128 v57; // xmm5
  __m128 v58; // xmm1
  __m128 v59; // xmm3
  __m128 v60; // xmm2
  hkaiTraversalAnalysisSettings *v61; // rax
  hkaiGeometrySegmentCaster *v62; // rcx
  __m128 v63; // xmm2
  __m128 v64; // xmm4
  __m128 v65; // xmm4
  __m128 v66; // xmm1
  __m128 v67; // xmm2
  __m128 v68; // xmm1
  int v69; // edi
  float v70; // xmm10_4
  float v71; // xmm10_4
  unsigned int *Interval; // rax
  __m128 v73; // xmm3
  __m128 v74; // xmm4
  int v75; // xmm1_4
  __m128 v76; // xmm8
  __m128 v77; // xmm9
  __m128 v78; // xmm8
  __m128 v79; // xmm2
  __m128 v80; // xmm2
  __m128 v81; // xmm6
  __m128 v82; // xmm7
  __m128 v83; // xmm6
  hkaiNavMeshInstance *v84; // rax
  unsigned int m_userdata; // r9d
  __m128 v86; // xmm2
  __m128 v87; // xmm1
  float m_baseCost; // xmm0_4
  unsigned int m_sectionUid; // ecx
  hkaiNavMeshInstance *m_toNavMeshInstance; // rax
  unsigned int v91; // ecx
  hkaiTraversalAnnotationLibrary *m_outputLibrary; // rcx
  hkaiIntervalPartition other; // [rsp+40h] [rbp-B8h] BYREF
  hkaiIntervalPartition partition; // [rsp+50h] [rbp-A8h] BYREF
  hkVector4f leftEnd; // [rsp+60h] [rbp-98h] BYREF
  hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> pairsOut; // [rsp+70h] [rbp-88h] BYREF
  int v97; // [rsp+80h] [rbp-78h]
  int v98; // [rsp+84h] [rbp-74h]
  hkaiIntervalPartition v99; // [rsp+88h] [rbp-70h] BYREF
  hkVector4f rightEnd; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f leftInOut; // [rsp+A8h] [rbp-50h] BYREF
  hkVector4f rightInOut; // [rsp+B8h] [rbp-40h] BYREF
  __m128 v103; // [rsp+C8h] [rbp-30h]
  hkVector4f leftStart; // [rsp+D8h] [rbp-20h] BYREF
  hkVector4f v105; // [rsp+E8h] [rbp-10h] BYREF
  hkVector4f v106; // [rsp+F8h] [rbp+0h] BYREF
  hkVector4f v107; // [rsp+108h] [rbp+10h] BYREF
  hkVector4f v108; // [rsp+118h] [rbp+20h] BYREF
  hkVector4f rightStart; // [rsp+128h] [rbp+30h] BYREF
  hkVector4f v110; // [rsp+138h] [rbp+40h] BYREF
  hkVector4f v111; // [rsp+148h] [rbp+50h] BYREF
  hkaiPairedEdgeFinder::PairedEdgeSettings settings; // [rsp+158h] [rbp+60h] BYREF
  unsigned int v113; // [rsp+1A0h] [rbp+A8h]
  int v114; // [rsp+1A4h] [rbp+ACh]
  unsigned int v115; // [rsp+1A8h] [rbp+B0h]
  hkaiUserEdgeUtils::UserEdgePair userEdgePair; // [rsp+1B8h] [rbp+C0h] BYREF
  __m128 m_quad; // [rsp+208h] [rbp+110h]
  hkVector4f v118; // [rsp+218h] [rbp+120h] BYREF
  hkVector4f v119; // [rsp+228h] [rbp+130h] BYREF
  hkVector4f v120; // [rsp+238h] [rbp+140h] BYREF
  hkVector4f v121; // [rsp+248h] [rbp+150h] BYREF
  hkVector4f facePlane; // [rsp+258h] [rbp+160h] BYREF
  hkVector4f v123; // [rsp+268h] [rbp+170h] BYREF
  __m128 faceIndex; // [rsp+278h] [rbp+180h] BYREF
  hkVector4f v125; // [rsp+288h] [rbp+190h] BYREF
  hkVector4f extrusion; // [rsp+298h] [rbp+1A0h] BYREF
  void *retaddr; // [rsp+388h] [rbp+290h]
  float v128; // [rsp+390h] [rbp+298h]
  __int64 v129; // [rsp+398h] [rbp+2A0h]

  m_quad = context->m_settings->m_up.m_quad;
  v4.m_quad = m_quad;
  hkaiPairedEdgeFinder::PairedEdgeSettings::PairedEdgeSettings(&settings);
  si128 = _mm_load_si128((const __m128i *)_xmm);
  m_settings = context->m_settings;
  m_maxPlanarAngle = this->m_maxPlanarAngle;
  v8 = LODWORD(this->m_maxDownHeight) ^ _xmm[0];
  v9 = _mm_add_ps((__m128)LODWORD(m_maxPlanarAngle), *(__m128 *)_xmm);
  settings.m_up = (hkVector4f)v4.m_quad;
  m_minEdgeLength = m_settings->m_minEdgeLength;
  LODWORD(settings.m_minHeightDelta) = v8;
  v11 = _mm_andnot_ps(*(__m128 *)_xmm, v9);
  settings.m_minHorizontalDelta = 0.0;
  settings.m_minLength = m_minEdgeLength;
  settings.m_maxHeightDelta = this->m_maxUpHeight;
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
  LODWORD(settings.m_cosMaxPlanarAngle) = v11.m128_i32[0] ^ (v14.m128_i32[0] << 29) ^ v9.m128_i32[0] & _xmm[0];
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
  settings.m_matchAngles.m_bool = 1;
  v28 = _mm_add_ps((__m128)v22.m128_u32[0], *(__m128 *)_xmm);
  v29 = _mm_andnot_ps(*(__m128 *)_xmm, v28);
  v30 = _mm_andnot_si128(v26, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v29, *(__m128 *)_xmm)), v26));
  v31 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v30, v25), (__m128i)0i64);
  v32 = _mm_cvtepi32_ps(v30);
  v33 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v32, *(__m128 *)DP1_0), v29), _mm_mul_ps(v32, *(__m128 *)DP2)),
          _mm_mul_ps(v32, *(__m128 *)DP3));
  v34 = _mm_mul_ps(v33, v33);
  v35 = _mm_shuffle_ps((__m128)LODWORD(this->m_verticalApex), (__m128)LODWORD(this->m_verticalApex), 0);
  v36 = _mm_load_si128((const __m128i *)&leftEnd);
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
                                                                                   + v33.m128_f32[0]) & v31.m128_i32[0]) ^ (_mm_and_si128(_mm_add_epi32(v36, v36), v30).m128i_u32[0] << 29) ^ v28.m128_i32[0] & _xmm[0];
  v37 = _mm_shuffle_ps(
          (__m128)LODWORD(m_settings->m_characterHeight),
          (__m128)LODWORD(m_settings->m_characterHeight),
          0);
  v32.m128_i32[0] = LODWORD(m_settings->m_characterRadius);
  v38 = (__m128)COERCE_UNSIGNED_INT(m_settings->m_characterHeight * 0.89999998);
  pairsOut.m_data = 0i64;
  pairsOut.m_size = 0;
  pairsOut.m_capacityAndFlags = 0x80000000;
  v39 = _mm_shuffle_ps(v38, v38, 0);
  v103 = v39;
  v40 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT(v32.m128_f32[0] * 2.0),
          (__m128)COERCE_UNSIGNED_INT(v32.m128_f32[0] * 2.0),
          0);
  hkaiPairedEdgeFinder::findEdgePairs(m_pntr, &settings, &pairsOut);
  m_size = pairsOut.m_size;
  v43 = v35.m128_f32[0] > v39.m128_f32[0];
  v129 = pairsOut.m_size;
  LOBYTE(retaddr) = v35.m128_f32[0] > v39.m128_f32[0];
  if ( pairsOut.m_size > 0 )
  {
    v44 = 0i64;
    do
    {
      m_data = pairsOut.m_data;
      m_fromNavMeshInstance = context->m_fromNavMeshInstance;
      leftInOut.m_quad = (__m128)pairsOut.m_data[v44].m_startLeft;
      rightInOut.m_quad = (__m128)pairsOut.m_data[v44].m_startRight;
      leftEnd.m_quad = (__m128)pairsOut.m_data[v44].m_endLeft;
      rightEnd.m_quad = (__m128)pairsOut.m_data[v44].m_endRight;
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)m_fromNavMeshInstance,
        (hkaiNavMeshInstance *)(unsigned int)pairsOut.m_data[v44].m_startFace,
        &faceIndex,
        v41);
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)context->m_toNavMeshInstance,
        (hkaiNavMeshInstance *)(unsigned int)m_data[v44].m_endFace,
        &facePlane.m_quad,
        v47);
      hkaiTraversalAnalysisUtils::setBackEdge(&leftInOut, &rightInOut, (hkVector4f *)&faceIndex, context);
      hkaiTraversalAnalysisUtils::setBackEdge(&rightEnd, &leftEnd, &facePlane, context);
      hkaiIntervalPartition::hkaiIntervalPartition(&other);
      hkaiTraversalAnalysisUtils::filterUnwalkableLandingZones(
        &leftInOut,
        &rightInOut,
        &leftEnd,
        &rightEnd,
        m_data[v44].m_startFace,
        m_data[v44].m_endFace,
        &other,
        context);
      if ( other.m_intervals.m_size )
      {
        v105.m_quad = leftInOut.m_quad;
        v110.m_quad = rightInOut.m_quad;
        v107.m_quad = leftEnd.m_quad;
        v111.m_quad = rightEnd.m_quad;
        if ( hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&v105, &v110, context) )
        {
          if ( hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&v111, &v107, context) )
          {
            v48 = m_quad;
            v49 = context->m_settings;
            v50 = _mm_mul_ps(v35, m_quad);
            leftStart.m_quad = _mm_add_ps(v50, v105.m_quad);
            rightStart.m_quad = _mm_add_ps(v50, v110.m_quad);
            v108.m_quad = _mm_add_ps(v50, v107.m_quad);
            v106.m_quad = _mm_add_ps(v50, v111.m_quad);
            extrusion.m_quad = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v37), v49->m_up.m_quad);
            hkaiIntervalPartition::hkaiIntervalPartition(&partition);
            hkaiGeometrySegmentCaster::turnSegmentExtruded(
              context->m_cuttingGeometrySegmentCaster.m_pntr,
              &leftStart,
              &rightStart,
              &v108,
              &v106,
              &extrusion,
              &partition);
            hkaiIntervalPartition::complement(&partition, 0.0, 1.0);
            hkaiIntervalPartition::clipNotDefined(&partition, &other);
            v51 = partition.m_intervals.m_size;
            if ( partition.m_intervals.m_size )
            {
              if ( !v43 )
                goto LABEL_23;
              hkaiIntervalPartition::hkaiIntervalPartition(&v99);
              v52 = context->m_settings;
              v53 = context->m_cuttingGeometrySegmentCaster.m_pntr;
              v54 = _mm_mul_ps(v39, v48);
              v55 = _mm_sub_ps(rightInOut.m_quad, leftInOut.m_quad);
              v123.m_quad = _mm_add_ps(v54, rightInOut.m_quad);
              v121.m_quad = _mm_add_ps(v54, leftInOut.m_quad);
              v56 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v55, v55, 201), v52->m_up.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v52->m_up.m_quad, v52->m_up.m_quad, 201), v55));
              v57 = _mm_shuffle_ps(v56, v56, 201);
              v58 = _mm_mul_ps(v57, v57);
              v59 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)),
                      _mm_shuffle_ps(v58, v58, 170));
              v60 = _mm_rsqrt_ps(v59);
              v119.m_quad = _mm_mul_ps(
                              _mm_mul_ps(
                                _mm_andnot_ps(
                                  _mm_cmple_ps(v59, (__m128)0i64),
                                  _mm_mul_ps(
                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v60, v59), v60)),
                                    _mm_mul_ps(*(__m128 *)_xmm, v60))),
                                v57),
                              v40);
              hkaiGeometrySegmentCaster::turnSegmentExtruded(v53, &v121, &v123, &leftStart, &rightStart, &v119, &v99);
              hkaiIntervalPartition::clipDefined(&partition, &v99);
              v99.m_intervals.m_size = 0;
              if ( v99.m_intervals.m_capacityAndFlags >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  &hkContainerHeapAllocator::s_alloc,
                  v99.m_intervals.m_data,
                  20 * (v99.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
              v99.m_intervals.m_data = 0i64;
              v99.m_intervals.m_capacityAndFlags = 0x80000000;
              if ( !partition.m_intervals.m_size )
                goto LABEL_16;
              hkaiIntervalPartition::hkaiIntervalPartition((hkaiIntervalPartition *)&pairsOut.m_size);
              v61 = context->m_settings;
              v62 = context->m_cuttingGeometrySegmentCaster.m_pntr;
              v63 = _mm_sub_ps(rightEnd.m_quad, leftEnd.m_quad);
              v120.m_quad = _mm_add_ps(v54, leftEnd.m_quad);
              v118.m_quad = _mm_add_ps(v54, rightEnd.m_quad);
              v64 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v61->m_up.m_quad, v61->m_up.m_quad, 201), v63),
                      _mm_mul_ps(_mm_shuffle_ps(v63, v63, 201), v61->m_up.m_quad));
              v65 = _mm_shuffle_ps(v64, v64, 201);
              v66 = _mm_mul_ps(v65, v65);
              v67 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)),
                      _mm_shuffle_ps(v66, v66, 170));
              v68 = _mm_rsqrt_ps(v67);
              v125.m_quad = _mm_mul_ps(
                              _mm_mul_ps(
                                _mm_andnot_ps(
                                  _mm_cmple_ps(v67, (__m128)0i64),
                                  _mm_mul_ps(
                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v68, v67), v68)),
                                    _mm_mul_ps(v68, *(__m128 *)_xmm))),
                                v65),
                              v40);
              hkaiGeometrySegmentCaster::turnSegmentExtruded(
                v62,
                &v120,
                &v118,
                &v108,
                &v106,
                &v125,
                (hkaiIntervalPartition *)&pairsOut.m_size);
              hkaiIntervalPartition::clipDefined(&partition, (hkaiIntervalPartition *)&pairsOut.m_size);
              v97 = 0;
              if ( v98 >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  &hkContainerHeapAllocator::s_alloc,
                  *(void **)&pairsOut.m_size,
                  20 * (v98 & 0x3FFFFFFF));
              *(_QWORD *)&pairsOut.m_size = 0i64;
              v51 = partition.m_intervals.m_size;
              v98 = 0x80000000;
              if ( partition.m_intervals.m_size )
              {
LABEL_23:
                v69 = 0;
                v70 = _mm_shuffle_ps(
                        (__m128)LODWORD(context->m_settings->m_minEdgeLength),
                        (__m128)LODWORD(context->m_settings->m_minEdgeLength),
                        0).m128_f32[0];
                v71 = v70 * v70;
                if ( v51 > 0 )
                {
                  do
                  {
                    Interval = (unsigned int *)hkaiIntervalPartition::getInterval(&partition, v69);
                    v73 = _mm_shuffle_ps((__m128)*Interval, (__m128)*Interval, 0);
                    v74 = _mm_shuffle_ps((__m128)Interval[1], (__m128)Interval[1], 0);
                    v75 = Interval[3];
                    v113 = Interval[2];
                    v115 = Interval[4];
                    v114 = v75;
                    v76 = _mm_sub_ps(rightInOut.m_quad, leftInOut.m_quad);
                    v77 = _mm_add_ps(_mm_mul_ps(v76, v74), leftInOut.m_quad);
                    v78 = _mm_add_ps(_mm_mul_ps(v76, v73), leftInOut.m_quad);
                    v79 = _mm_sub_ps(v78, v77);
                    v80 = _mm_mul_ps(v79, v79);
                    if ( (float)((float)(_mm_shuffle_ps(v80, v80, 85).m128_f32[0]
                                       + _mm_shuffle_ps(v80, v80, 0).m128_f32[0])
                               + _mm_shuffle_ps(v80, v80, 170).m128_f32[0]) >= v71 )
                    {
                      v81 = _mm_sub_ps(rightEnd.m_quad, leftEnd.m_quad);
                      v82 = _mm_add_ps(_mm_mul_ps(v81, v74), leftEnd.m_quad);
                      v83 = _mm_add_ps(_mm_mul_ps(v81, v73), leftEnd.m_quad);
                      hkaiUserEdgeUtils::UserEdgePair::UserEdgePair(&userEdgePair);
                      v84 = context->m_fromNavMeshInstance;
                      m_userdata = this->m_userdata;
                      v86 = _mm_shuffle_ps(v78, v77, 68);
                      v87 = _mm_shuffle_ps(v82, v83, 68);
                      userEdgePair.m_x.m_quad = _mm_shuffle_ps(v86, v87, 136);
                      m_baseCost = this->m_baseCost;
                      userEdgePair.m_y.m_quad = _mm_shuffle_ps(v86, v87, 221);
                      userEdgePair.m_z.m_quad = _mm_shuffle_ps(
                                                  _mm_shuffle_ps(v78, v77, 238),
                                                  _mm_shuffle_ps(v82, v83, 238),
                                                  136);
                      m_sectionUid = v84->m_sectionUid;
                      m_toNavMeshInstance = context->m_toNavMeshInstance;
                      userEdgePair.m_instanceUidA = m_sectionUid;
                      v91 = m_toNavMeshInstance->m_sectionUid;
                      v128 = m_baseCost * 1.0039062;
                      userEdgePair.m_faceA = m_data[v44].m_startFace;
                      LODWORD(m_toNavMeshInstance) = m_data[v44].m_endFace;
                      userEdgePair.m_instanceUidB = v91;
                      m_outputLibrary = context->m_outputLibrary;
                      userEdgePair.m_faceB = (int)m_toNavMeshInstance;
                      userEdgePair.m_direction.m_storage = 1;
                      userEdgePair.m_costBtoA.m_value = 0;
                      userEdgePair.m_costAtoB.m_value = HIWORD(v128);
                      hkaiTraversalAnnotationLibrary::addAnnotation(
                        m_outputLibrary,
                        &userEdgePair,
                        HKAI_TRAVERSAL_TYPE_JUMP,
                        m_userdata);
                    }
                    ++v69;
                  }
                  while ( v69 < v51 );
                  m_size = v129;
                }
                partition.m_intervals.m_size = 0;
                if ( partition.m_intervals.m_capacityAndFlags >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    &hkContainerHeapAllocator::s_alloc,
                    partition.m_intervals.m_data,
                    20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
                partition.m_intervals.m_data = 0i64;
                partition.m_intervals.m_capacityAndFlags = 0x80000000;
                other.m_intervals.m_size = 0;
                if ( other.m_intervals.m_capacityAndFlags >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    &hkContainerHeapAllocator::s_alloc,
                    other.m_intervals.m_data,
                    20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
                v43 = (char)retaddr;
              }
              else
              {
LABEL_16:
                partition.m_intervals.m_size = 0;
                if ( partition.m_intervals.m_capacityAndFlags >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    &hkContainerHeapAllocator::s_alloc,
                    partition.m_intervals.m_data,
                    20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
                partition.m_intervals.m_data = 0i64;
                partition.m_intervals.m_capacityAndFlags = 0x80000000;
                other.m_intervals.m_size = 0;
                if ( other.m_intervals.m_capacityAndFlags >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    &hkContainerHeapAllocator::s_alloc,
                    other.m_intervals.m_data,
                    20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
              }
              v39 = v103;
              goto LABEL_34;
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
        }
      }
      other.m_intervals.m_size = 0;
      if ( other.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          other.m_intervals.m_data,
          20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
LABEL_34:
      ++v44;
      --m_size;
      other.m_intervals.m_data = 0i64;
      v129 = m_size;
      other.m_intervals.m_capacityAndFlags = 0x80000000;
    }
    while ( m_size );
  }
  pairsOut.m_size = 0;
  if ( pairsOut.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      pairsOut.m_data,
      80 * (pairsOut.m_capacityAndFlags & 0x3FFFFFFF));
}


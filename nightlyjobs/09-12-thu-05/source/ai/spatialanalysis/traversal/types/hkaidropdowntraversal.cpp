// File Line: 24
// RVA: 0xC34660
void __fastcall hkaiDropDownAnalyzer::analyze(hkaiDropDownAnalyzer *this, hkaiTraversalAnalysisContext *context)
{
  hkVector4f v4; // xmm6
  __m128i si128; // xmm3
  hkaiTraversalAnalysisSettings *m_settings; // rax
  float m_maxPlanarAngle; // xmm8_4
  int v8; // xmm1_4
  __m128 v9; // xmm7
  float m_minEdgeLength; // xmm0_4
  float m_maxUnderhang; // xmm1_4
  __m128 v12; // xmm2
  float m_minDropDistance; // xmm0_4
  __m128i v14; // xmm6
  __m128 v15; // xmm5
  __m128 v16; // xmm0
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128i v19; // xmm3
  __m128i v20; // xmm6
  __m128 v21; // xmm2
  __m128i v22; // xmm6
  __m128 v23; // xmm5
  __m128 v24; // xmm0
  __m128 v25; // xmm4
  __m128 v26; // xmm2
  __m128i v27; // xmm4
  __m128 v28; // xmm6
  __m128 v29; // xmm2
  __m128i v30; // xmm7
  hkaiPairedEdgeFinder *m_pntr; // rcx
  int v32; // edi
  __m128i v33; // xmm7
  __m128 v34; // xmm5
  __m128 v35; // xmm0
  __m128 v36; // xmm4
  __m128 v37; // xmm2
  __m128i v38; // xmm1
  float v39; // xmm11_4
  float v40; // xmm11_4
  hkVector4f *v41; // r9
  __int64 m_size; // r12
  __int64 v43; // rsi
  hkaiPairedEdgeFinder::EdgePair *m_data; // r14
  hkaiNavMeshInstance *m_fromNavMeshInstance; // rcx
  hkVector4f *v46; // r9
  __m128 v47; // xmm2
  __m128 v48; // xmm4
  __m128 v49; // xmm5
  __m128 v50; // xmm0
  __m128 v51; // xmm3
  __m128 v52; // xmm4
  __m128 v53; // xmm1
  __m128 v54; // xmm5
  int v55; // r15d
  unsigned int *Interval; // rax
  __m128 v57; // xmm3
  __m128 v58; // xmm4
  int v59; // xmm1_4
  __m128 v60; // xmm8
  __m128 v61; // xmm9
  __m128 v62; // xmm8
  __m128 v63; // xmm2
  __m128 v64; // xmm2
  __m128 v65; // xmm6
  __m128 v66; // xmm7
  __m128 v67; // xmm6
  hkaiNavMeshInstance *v68; // rax
  unsigned int m_userdata; // r9d
  __m128 v70; // xmm2
  __m128 v71; // xmm1
  float m_baseCost; // xmm0_4
  unsigned int m_sectionUid; // ecx
  hkaiNavMeshInstance *m_toNavMeshInstance; // rax
  unsigned int v75; // ecx
  hkaiTraversalAnnotationLibrary *m_outputLibrary; // rcx
  hkaiIntervalPartition reachableAreasOut; // [rsp+40h] [rbp-B8h] BYREF
  hkaiIntervalPartition other; // [rsp+50h] [rbp-A8h] BYREF
  hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> pairsOut; // [rsp+60h] [rbp-98h] BYREF
  char rightInOut[24]; // [rsp+70h] [rbp-88h] BYREF
  hkVector4f rightEnd; // [rsp+88h] [rbp-70h] BYREF
  hkVector4f leftInOut; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f topLeftIn; // [rsp+A8h] [rbp-50h] BYREF
  hkVector4f bottomLeftIn; // [rsp+B8h] [rbp-40h] BYREF
  hkVector4f topRightIn; // [rsp+C8h] [rbp-30h] BYREF
  hkVector4f bottomRightIn; // [rsp+D8h] [rbp-20h] BYREF
  hkaiPairedEdgeFinder::PairedEdgeSettings settings; // [rsp+E8h] [rbp-10h] BYREF
  unsigned int v88; // [rsp+130h] [rbp+38h]
  int v89; // [rsp+134h] [rbp+3Ch]
  unsigned int v90; // [rsp+138h] [rbp+40h]
  hkaiUserEdgeUtils::UserEdgePair userEdgePair; // [rsp+148h] [rbp+50h] BYREF
  hkVector4f facePlane; // [rsp+198h] [rbp+A0h] BYREF
  __m128 m_quad; // [rsp+1A8h] [rbp+B0h]
  hkVector4f faceIndex; // [rsp+1B8h] [rbp+C0h] BYREF
  void *retaddr; // [rsp+268h] [rbp+170h]
  __int64 v96; // [rsp+270h] [rbp+178h]

  m_quad = context->m_settings->m_up.m_quad;
  v4.m_quad = m_quad;
  hkaiPairedEdgeFinder::PairedEdgeSettings::PairedEdgeSettings(&settings);
  si128 = _mm_load_si128((const __m128i *)_xmm);
  m_settings = context->m_settings;
  m_maxPlanarAngle = this->m_maxPlanarAngle;
  v8 = LODWORD(this->m_maxDropDistance) ^ _xmm[0];
  v9 = _mm_add_ps((__m128)LODWORD(m_maxPlanarAngle), *(__m128 *)_xmm);
  settings.m_up = (hkVector4f)v4.m_quad;
  m_minEdgeLength = m_settings->m_minEdgeLength;
  LODWORD(settings.m_minHeightDelta) = v8;
  m_maxUnderhang = this->m_maxUnderhang;
  v12 = _mm_andnot_ps(*(__m128 *)_xmm, v9);
  settings.m_minLength = m_minEdgeLength;
  m_minDropDistance = this->m_minDropDistance;
  settings.m_maxHorizontalDelta = m_maxUnderhang;
  LODWORD(settings.m_maxHeightDelta) = LODWORD(m_minDropDistance) ^ _xmm[0];
  settings.m_minHorizontalDelta = 0.0;
  *(__m128i *)rightInOut = _mm_add_epi32(si128, si128);
  v14 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v12, *(__m128 *)_xmm)), si128));
  v15 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v14, *(__m128i *)rightInOut), (__m128i)0i64);
  v16 = _mm_cvtepi32_ps(v14);
  v17 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v16, *(__m128 *)DP1_0), v12), _mm_mul_ps(v16, *(__m128 *)DP2)),
          _mm_mul_ps(v16, *(__m128 *)DP3));
  v18 = _mm_mul_ps(v17, v17);
  v12.m128_f32[0] = _mm_andnot_ps(
                      v15,
                      _mm_add_ps(
                        _mm_sub_ps(
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_add_ps(_mm_mul_ps(v18, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1),
                                  v18),
                                *(__m128 *)cosCoeff2_0),
                              v18),
                            v18),
                          _mm_mul_ps(v18, *(__m128 *)_xmm)),
                        *(__m128 *)_xmm)).m128_f32[0];
  v16.m128_f32[0] = (float)((float)((float)((float)(v18.m128_f32[0] * -0.00019515296) + 0.0083321612) * v18.m128_f32[0])
                          + -0.16666655)
                  * v18.m128_f32[0];
  v19 = _mm_load_si128((const __m128i *)rightInOut);
  v12.m128_i32[0] |= COERCE_UNSIGNED_INT((float)(v16.m128_f32[0] * v17.m128_f32[0]) + v17.m128_f32[0]) & v15.m128_i32[0];
  v16.m128_i32[0] = _mm_and_si128(_mm_add_epi32(v19, v19), v14).m128i_u32[0];
  v20 = _mm_load_si128((const __m128i *)_xmm);
  LODWORD(settings.m_cosMaxPlanarAngle) = v12.m128_i32[0] ^ (v16.m128_i32[0] << 29) ^ v9.m128_i32[0] & _xmm[0];
  v21 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(m_maxPlanarAngle));
  v22 = _mm_andnot_si128(v20, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v21, *(__m128 *)_xmm)), v20));
  v23 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v22, v19), (__m128i)0i64);
  v24 = _mm_cvtepi32_ps(v22);
  v25 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v24, *(__m128 *)DP1_0), v21), _mm_mul_ps(v24, *(__m128 *)DP2)),
          _mm_mul_ps(v24, *(__m128 *)DP3));
  v26 = _mm_mul_ps(v25, v25);
  v24.m128_f32[0] = (float)((float)((float)((float)((float)((float)(v26.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                                  * v26.m128_f32[0])
                                          + -0.16666655)
                                  * v26.m128_f32[0])
                          * v25.m128_f32[0])
                  + v25.m128_f32[0];
  v27 = _mm_load_si128((const __m128i *)rightInOut);
  *(float *)&retaddr = this->m_maxRelativeSlopeAngle;
  LODWORD(settings.m_sinMaxPlanarAngle) = (_mm_andnot_ps(
                                             v23,
                                             _mm_add_ps(
                                               _mm_sub_ps(
                                                 _mm_mul_ps(
                                                   _mm_mul_ps(
                                                     _mm_add_ps(
                                                       _mm_mul_ps(
                                                         _mm_add_ps(
                                                           _mm_mul_ps(v26, *(__m128 *)cosCoeff0_0),
                                                           *(__m128 *)cosCoeff1),
                                                         v26),
                                                       *(__m128 *)cosCoeff2_0),
                                                     v26),
                                                   v26),
                                                 _mm_mul_ps(v26, *(__m128 *)_xmm)),
                                               *(__m128 *)_xmm)).m128_u32[0] | v24.m128_i32[0] & v23.m128_i32[0]) ^ (_mm_and_si128(_mm_add_epi32(v27, v27), v22).m128i_u32[0] << 29) ^ LODWORD(m_maxPlanarAngle) & _xmm[0];
  v28 = _mm_add_ps((__m128)(unsigned int)retaddr, *(__m128 *)_xmm);
  v29 = _mm_andnot_ps(*(__m128 *)_xmm, v28);
  v30 = _mm_load_si128((const __m128i *)_xmm);
  m_pntr = context->m_pairedEdgeFinder.m_pntr;
  v32 = 0;
  settings.m_matchAngles.m_bool = 1;
  settings.m_findInternalEnds.m_bool = 1;
  v33 = _mm_andnot_si128(v30, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v29, *(__m128 *)_xmm)), v30));
  pairsOut.m_data = 0i64;
  pairsOut.m_size = 0;
  pairsOut.m_capacityAndFlags = 0x80000000;
  v34 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v33, v27), (__m128i)0i64);
  v35 = _mm_cvtepi32_ps(v33);
  v36 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v35, *(__m128 *)DP1_0), v29), _mm_mul_ps(v35, *(__m128 *)DP2)),
          _mm_mul_ps(v35, *(__m128 *)DP3));
  v37 = _mm_mul_ps(v36, v36);
  v38 = _mm_load_si128((const __m128i *)rightInOut);
  LODWORD(settings.m_cosMaxDeltaSlopeAngle) = (_mm_andnot_ps(
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
                                                   *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                                                     (float)((float)((float)((float)((float)((float)(v37.m128_f32[0] * -0.00019515296) + 0.0083321612) * v37.m128_f32[0]) + -0.16666655) * v37.m128_f32[0])
                                                                                           * v36.m128_f32[0])
                                                                                   + v36.m128_f32[0]) & v34.m128_i32[0]) ^ (_mm_and_si128(_mm_add_epi32(v38, v38), v33).m128i_u32[0] << 29) ^ v28.m128_i32[0] & _xmm[0];
  hkaiPairedEdgeFinder::findEdgePairs(m_pntr, &settings, &pairsOut);
  v39 = _mm_shuffle_ps(
          (__m128)LODWORD(context->m_settings->m_minEdgeLength),
          (__m128)LODWORD(context->m_settings->m_minEdgeLength),
          0).m128_f32[0];
  v40 = v39 * v39;
  hkaiIntervalPartition::hkaiIntervalPartition(&other);
  hkaiIntervalPartition::hkaiIntervalPartition(&reachableAreasOut);
  m_size = pairsOut.m_size;
  v96 = pairsOut.m_size;
  if ( pairsOut.m_size > 0 )
  {
    v43 = 0i64;
    do
    {
      m_data = pairsOut.m_data;
      m_fromNavMeshInstance = context->m_fromNavMeshInstance;
      leftInOut.m_quad = (__m128)pairsOut.m_data[v43].m_startLeft;
      *(hkVector4f *)&rightInOut[8] = pairsOut.m_data[v43].m_startRight;
      *(hkVector4f *)rightInOut = pairsOut.m_data[v43].m_endLeft;
      rightEnd.m_quad = (__m128)pairsOut.m_data[v43].m_endRight;
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)m_fromNavMeshInstance,
        (hkaiNavMeshInstance *)(unsigned int)pairsOut.m_data[v43].m_startFace,
        &faceIndex.m_quad,
        v41);
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)context->m_toNavMeshInstance,
        (hkaiNavMeshInstance *)(unsigned int)m_data[v43].m_endFace,
        &facePlane.m_quad,
        v46);
      hkaiTraversalAnalysisUtils::setBackEdge(&leftInOut, (hkVector4f *)&rightInOut[8], &faceIndex, context);
      hkaiTraversalAnalysisUtils::setBackEdge(&rightEnd, (hkVector4f *)rightInOut, &facePlane, context);
      hkaiIntervalPartition::clear(&other);
      hkaiTraversalAnalysisUtils::filterUnwalkableLandingZones(
        &leftInOut,
        (hkVector4f *)&rightInOut[8],
        (hkVector4f *)rightInOut,
        &rightEnd,
        m_data[v43].m_startFace,
        m_data[v43].m_endFace,
        &other,
        context);
      if ( other.m_intervals.m_size )
      {
        topRightIn.m_quad = leftInOut.m_quad;
        topLeftIn.m_quad = *(__m128 *)&rightInOut[8];
        bottomRightIn.m_quad = *(__m128 *)rightInOut;
        bottomLeftIn.m_quad = rightEnd.m_quad;
        if ( hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&topRightIn, &topLeftIn, context) )
        {
          if ( hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&bottomLeftIn, &bottomRightIn, context) )
          {
            v47 = _mm_mul_ps(topLeftIn.m_quad, m_quad);
            v48 = _mm_mul_ps(topRightIn.m_quad, m_quad);
            v49 = _mm_shuffle_ps(v48, v47, 238);
            v50 = _mm_mul_ps(bottomLeftIn.m_quad, m_quad);
            v51 = _mm_mul_ps(bottomRightIn.m_quad, m_quad);
            v52 = _mm_shuffle_ps(v48, v47, 68);
            v53 = _mm_shuffle_ps(v51, v50, 68);
            v54 = _mm_add_ps(
                    _mm_shuffle_ps(v49, _mm_shuffle_ps(v51, v50, 238), 136),
                    _mm_add_ps(_mm_shuffle_ps(v52, v53, 221), _mm_shuffle_ps(v52, v53, 136)));
            if ( fmin(_mm_shuffle_ps(v54, v54, 0).m128_f32[0], _mm_shuffle_ps(v54, v54, 85).m128_f32[0]) > fmax(_mm_shuffle_ps(v54, v54, 170).m128_f32[0], _mm_shuffle_ps(v54, v54, 255).m128_f32[0]) )
            {
              hkaiIntervalPartition::clear(&reachableAreasOut);
              hkaiTraversalAnalysisUtils::findOverLedgeReachability(
                &bottomLeftIn,
                &bottomRightIn,
                &topLeftIn,
                &topRightIn,
                context,
                &reachableAreasOut);
              hkaiIntervalPartition::clipNotDefined(&reachableAreasOut, &other);
              v55 = reachableAreasOut.m_intervals.m_size;
              if ( reachableAreasOut.m_intervals.m_size )
              {
                if ( reachableAreasOut.m_intervals.m_size > 0 )
                {
                  do
                  {
                    Interval = (unsigned int *)hkaiIntervalPartition::getInterval(&reachableAreasOut, v32);
                    v57 = _mm_shuffle_ps((__m128)*Interval, (__m128)*Interval, 0);
                    v58 = _mm_shuffle_ps((__m128)Interval[1], (__m128)Interval[1], 0);
                    v59 = Interval[3];
                    v88 = Interval[2];
                    v90 = Interval[4];
                    v89 = v59;
                    v60 = _mm_sub_ps(*(__m128 *)&rightInOut[8], leftInOut.m_quad);
                    v61 = _mm_add_ps(_mm_mul_ps(v60, v58), leftInOut.m_quad);
                    v62 = _mm_add_ps(_mm_mul_ps(v60, v57), leftInOut.m_quad);
                    v63 = _mm_sub_ps(v62, v61);
                    v64 = _mm_mul_ps(v63, v63);
                    if ( (float)((float)(_mm_shuffle_ps(v64, v64, 85).m128_f32[0]
                                       + _mm_shuffle_ps(v64, v64, 0).m128_f32[0])
                               + _mm_shuffle_ps(v64, v64, 170).m128_f32[0]) >= v40 )
                    {
                      v65 = _mm_sub_ps(rightEnd.m_quad, *(__m128 *)rightInOut);
                      v66 = _mm_add_ps(_mm_mul_ps(v65, v58), *(__m128 *)rightInOut);
                      v67 = _mm_add_ps(_mm_mul_ps(v65, v57), *(__m128 *)rightInOut);
                      hkaiUserEdgeUtils::UserEdgePair::UserEdgePair(&userEdgePair);
                      v68 = context->m_fromNavMeshInstance;
                      m_userdata = this->m_userdata;
                      v70 = _mm_shuffle_ps(v62, v61, 68);
                      v71 = _mm_shuffle_ps(v66, v67, 68);
                      userEdgePair.m_x.m_quad = _mm_shuffle_ps(v70, v71, 136);
                      m_baseCost = this->m_baseCost;
                      userEdgePair.m_y.m_quad = _mm_shuffle_ps(v70, v71, 221);
                      userEdgePair.m_z.m_quad = _mm_shuffle_ps(
                                                  _mm_shuffle_ps(v62, v61, 238),
                                                  _mm_shuffle_ps(v66, v67, 238),
                                                  136);
                      m_sectionUid = v68->m_sectionUid;
                      m_toNavMeshInstance = context->m_toNavMeshInstance;
                      userEdgePair.m_instanceUidA = m_sectionUid;
                      v75 = m_toNavMeshInstance->m_sectionUid;
                      *(float *)&retaddr = m_baseCost * 1.0039062;
                      userEdgePair.m_faceA = m_data[v43].m_startFace;
                      LODWORD(m_toNavMeshInstance) = m_data[v43].m_endFace;
                      userEdgePair.m_instanceUidB = v75;
                      m_outputLibrary = context->m_outputLibrary;
                      userEdgePair.m_faceB = (int)m_toNavMeshInstance;
                      userEdgePair.m_direction.m_storage = 1;
                      userEdgePair.m_costBtoA.m_value = 0;
                      userEdgePair.m_costAtoB.m_value = WORD1(retaddr);
                      hkaiTraversalAnnotationLibrary::addAnnotation(
                        m_outputLibrary,
                        &userEdgePair,
                        HKAI_TRAVERSAL_TYPE_DROP_DOWN,
                        m_userdata);
                    }
                    ++v32;
                  }
                  while ( v32 < v55 );
                  m_size = v96;
                }
                v32 = 0;
              }
            }
          }
        }
      }
      ++v43;
      v96 = --m_size;
    }
    while ( m_size );
  }
  reachableAreasOut.m_intervals.m_size = 0;
  if ( reachableAreasOut.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      reachableAreasOut.m_intervals.m_data,
      20 * (reachableAreasOut.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  reachableAreasOut.m_intervals.m_data = 0i64;
  reachableAreasOut.m_intervals.m_capacityAndFlags = 0x80000000;
  other.m_intervals.m_size = 0;
  if ( other.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      other.m_intervals.m_data,
      20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  other.m_intervals.m_data = 0i64;
  pairsOut.m_size = 0;
  other.m_intervals.m_capacityAndFlags = 0x80000000;
  if ( pairsOut.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      pairsOut.m_data,
      80 * (pairsOut.m_capacityAndFlags & 0x3FFFFFFF));
}


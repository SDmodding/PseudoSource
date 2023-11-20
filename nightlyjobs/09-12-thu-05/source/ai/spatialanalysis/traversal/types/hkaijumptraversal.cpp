// File Line: 23
// RVA: 0xC36A20
void __fastcall hkaiJumpAnalyzer::analyze(hkaiJumpAnalyzer *this, hkaiTraversalAnalysisContext *context)
{
  hkaiJumpAnalyzer *v2; // r13
  hkaiTraversalAnalysisContext *v3; // rbx
  hkVector4f v4; // xmm6
  __m128i v5; // xmm3
  hkaiTraversalAnalysisSettings *v6; // rax
  float v7; // xmm8_4
  int v8; // xmm1_4
  __m128 v9; // xmm7
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
  __m128 v33; // xmm6
  __m128 v34; // xmm2
  __m128i v35; // xmm7
  __m128 v36; // xmm1
  __m128 v37; // xmm5
  __m128 v38; // xmm4
  __m128 v39; // xmm2
  __m128 v40; // xmm14
  __m128i v41; // xmm1
  __m128 v42; // xmm15
  float v43; // xmm0_4
  __m128 v44; // xmm6
  __m128 v45; // xmm12
  hkVector4f *v46; // r9
  __int64 v47; // r12
  char v48; // di
  __int64 v49; // rsi
  hkaiPairedEdgeFinder::EdgePair *v50; // r14
  hkaiNavMeshUtils *v51; // rcx
  hkVector4f *v52; // r9
  __m128 v53; // xmm1
  __m128 v54; // xmm0
  __m128 v55; // xmm1
  __m128 v56; // xmm7
  __m128 *v57; // rax
  __m128 v58; // xmm2
  int v59; // er15
  __m128 *v60; // rax
  hkaiGeometrySegmentCaster *v61; // rcx
  __m128 v62; // xmm6
  __m128 v63; // xmm5
  __m128 v64; // xmm5
  __m128 v65; // xmm5
  __m128 v66; // xmm1
  __m128 v67; // xmm3
  __m128 v68; // xmm2
  __m128 *v69; // rax
  hkaiGeometrySegmentCaster *v70; // rcx
  __m128 v71; // xmm2
  __m128 v72; // xmm4
  __m128 v73; // xmm4
  __m128 v74; // xmm1
  __m128 v75; // xmm2
  __m128 v76; // xmm1
  int v77; // edi
  float v78; // xmm10_4
  float v79; // xmm10_4
  unsigned int *v80; // rax
  __m128 v81; // xmm3
  __m128 v82; // xmm4
  int v83; // xmm1_4
  __m128 v84; // xmm9
  __m128 v85; // xmm8
  __m128 v86; // xmm9
  __m128 v87; // xmm8
  __m128 v88; // xmm2
  __m128 v89; // xmm2
  __m128 v90; // xmm6
  __m128 v91; // xmm7
  __m128 v92; // xmm6
  hkaiNavMeshInstance *v93; // rax
  unsigned int v94; // er9
  __m128 v95; // xmm2
  __m128 v96; // xmm1
  float v97; // xmm0_4
  unsigned int v98; // ecx
  hkaiNavMeshInstance *v99; // rax
  unsigned int v100; // ecx
  hkaiTraversalAnnotationLibrary *v101; // rcx
  hkaiIntervalPartition other; // [rsp+40h] [rbp-B8h]
  hkaiIntervalPartition partition; // [rsp+50h] [rbp-A8h]
  hkVector4f leftEnd; // [rsp+60h] [rbp-98h]
  hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> pairsOut; // [rsp+70h] [rbp-88h]
  int v106; // [rsp+80h] [rbp-78h]
  int v107; // [rsp+84h] [rbp-74h]
  hkaiIntervalPartition v108; // [rsp+88h] [rbp-70h]
  hkVector4f rightEnd; // [rsp+98h] [rbp-60h]
  hkVector4f leftInOut; // [rsp+A8h] [rbp-50h]
  hkVector4f rightInOut; // [rsp+B8h] [rbp-40h]
  __m128 v112; // [rsp+C8h] [rbp-30h]
  hkVector4f leftStart; // [rsp+D8h] [rbp-20h]
  hkVector4f v114; // [rsp+E8h] [rbp-10h]
  hkVector4f v115; // [rsp+F8h] [rbp+0h]
  hkVector4f v116; // [rsp+108h] [rbp+10h]
  hkVector4f v117; // [rsp+118h] [rbp+20h]
  hkVector4f rightStart; // [rsp+128h] [rbp+30h]
  hkVector4f v119; // [rsp+138h] [rbp+40h]
  hkVector4f v120; // [rsp+148h] [rbp+50h]
  hkaiPairedEdgeFinder::PairedEdgeSettings settings; // [rsp+158h] [rbp+60h]
  unsigned int v122; // [rsp+1A0h] [rbp+A8h]
  int v123; // [rsp+1A4h] [rbp+ACh]
  unsigned int v124; // [rsp+1A8h] [rbp+B0h]
  hkaiUserEdgeUtils::UserEdgePair userEdgePair; // [rsp+1B8h] [rbp+C0h]
  hkVector4f v126; // [rsp+208h] [rbp+110h]
  hkVector4f v127; // [rsp+218h] [rbp+120h]
  hkVector4f v128; // [rsp+228h] [rbp+130h]
  hkVector4f v129; // [rsp+238h] [rbp+140h]
  hkVector4f v130; // [rsp+248h] [rbp+150h]
  hkVector4f facePlane; // [rsp+258h] [rbp+160h]
  hkVector4f v132; // [rsp+268h] [rbp+170h]
  int faceIndex; // [rsp+278h] [rbp+180h]
  hkVector4f v134; // [rsp+288h] [rbp+190h]
  hkVector4f extrusion; // [rsp+298h] [rbp+1A0h]
  unsigned int retaddr; // [rsp+388h] [rbp+290h]
  float v137; // [rsp+390h] [rbp+298h]
  __int64 v138; // [rsp+398h] [rbp+2A0h]

  v2 = this;
  v3 = context;
  v126.m_quad = (__m128)context->m_settings->m_up;
  v4.m_quad = v126.m_quad;
  hkaiPairedEdgeFinder::PairedEdgeSettings::PairedEdgeSettings(&settings);
  v5 = _mm_load_si128((const __m128i *)_xmm);
  v6 = v3->m_settings;
  v7 = v2->m_maxPlanarAngle;
  v8 = LODWORD(v2->m_maxDownHeight) ^ _xmm[0];
  v9 = _mm_add_ps((__m128)LODWORD(v2->m_maxPlanarAngle), *(__m128 *)_xmm);
  settings.m_up = (hkVector4f)v4.m_quad;
  v10 = v6->m_minEdgeLength;
  LODWORD(settings.m_minHeightDelta) = v8;
  v11 = _mm_andnot_ps(*(__m128 *)_xmm, v9);
  settings.m_minHorizontalDelta = 0.0;
  settings.m_minLength = v10;
  settings.m_maxHeightDelta = v2->m_maxUpHeight;
  v12 = _mm_add_epi32(v5, v5);
  settings.m_maxHorizontalDelta = v2->m_maxHorizontalDistance;
  _mm_store_si128((__m128i *)&leftEnd, v12);
  v13 = _mm_andnot_si128(v5, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v11, *(__m128 *)_xmm)), v5));
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
  LODWORD(settings.m_cosMaxPlanarAngle) = v11.m128_i32[0] ^ (v20 << 29) ^ v9.m128_i32[0] & _xmm[0];
  v22 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(v7));
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
                                                 *(__m128 *)_xmm)) | LODWORD(v28) & v25.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v29, v29), v23) << 29) ^ LODWORD(v7) & _xmm[0];
  v30 = v2->m_maxRelativeSlopeAngle;
  LODWORD(settings.m_sinMaxPlanarAngle) = v19.m128i_i32[0];
  v31 = _mm_load_si128((const __m128i *)_xmm);
  v32 = v3->m_pairedEdgeFinder.m_pntr;
  settings.m_matchAngles.m_bool = 1;
  v33 = _mm_add_ps((__m128)LODWORD(v30), *(__m128 *)_xmm);
  v34 = _mm_andnot_ps(*(__m128 *)_xmm, v33);
  v35 = _mm_andnot_si128(v31, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v34, *(__m128 *)_xmm)), v31));
  v36 = _mm_cvtepi32_ps(v35);
  v37 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v35, v29), (__m128i)0i64);
  v38 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v36, *(__m128 *)DP1_0), v34), _mm_mul_ps(v36, *(__m128 *)DP2)),
          _mm_mul_ps(v36, *(__m128 *)DP3));
  v39 = _mm_mul_ps(v38, v38);
  v40 = _mm_shuffle_ps((__m128)LODWORD(v2->m_verticalApex), (__m128)LODWORD(v2->m_verticalApex), 0);
  v41 = _mm_load_si128((const __m128i *)&leftEnd);
  LODWORD(settings.m_cosMaxDeltaSlopeAngle) = (*(unsigned __int128 *)&_mm_andnot_ps(
                                                                        v37,
                                                                        _mm_add_ps(
                                                                          _mm_sub_ps(
                                                                            _mm_mul_ps(
                                                                              _mm_mul_ps(
                                                                                _mm_add_ps(
                                                                                  _mm_mul_ps(
                                                                                    _mm_add_ps(
                                                                                      _mm_mul_ps(
                                                                                        v39,
                                                                                        *(__m128 *)cosCoeff0_0),
                                                                                      *(__m128 *)cosCoeff1),
                                                                                    v39),
                                                                                  *(__m128 *)cosCoeff2_0),
                                                                                v39),
                                                                              v39),
                                                                            _mm_mul_ps(v39, *(__m128 *)_xmm)),
                                                                          *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                                                (float)((float)((float)((float)((float)((float)(v39.m128_f32[0] * -0.00019515296) + 0.0083321612) * v39.m128_f32[0]) + -0.16666655) * v39.m128_f32[0]) * v38.m128_f32[0])
                                                                                              + v38.m128_f32[0]) & v37.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v41, v41), v35) << 29) ^ v33.m128_i32[0] & _xmm[0];
  v42 = _mm_shuffle_ps((__m128)LODWORD(v6->m_characterHeight), (__m128)LODWORD(v6->m_characterHeight), 0);
  *(float *)&retaddr = v6->m_characterHeight * 0.89999998;
  v43 = v6->m_characterRadius;
  pairsOut.m_data = 0i64;
  pairsOut.m_size = 0;
  pairsOut.m_capacityAndFlags = 2147483648;
  v44 = _mm_shuffle_ps((__m128)retaddr, (__m128)retaddr, 0);
  v112 = v44;
  v45 = _mm_shuffle_ps((__m128)COERCE_UNSIGNED_INT(v43 * 2.0), (__m128)COERCE_UNSIGNED_INT(v43 * 2.0), 0);
  hkaiPairedEdgeFinder::findEdgePairs(v32, &settings, &pairsOut);
  v47 = pairsOut.m_size;
  v48 = v40.m128_f32[0] > v44.m128_f32[0];
  v138 = pairsOut.m_size;
  LOBYTE(retaddr) = v40.m128_f32[0] > v44.m128_f32[0];
  if ( pairsOut.m_size > 0i64 )
  {
    v49 = 0i64;
    do
    {
      v50 = pairsOut.m_data;
      v51 = (hkaiNavMeshUtils *)v3->m_fromNavMeshInstance;
      _mm_store_si128((__m128i *)&leftInOut, (__m128i)pairsOut.m_data[v49].m_startLeft.m_quad);
      _mm_store_si128((__m128i *)&rightInOut, (__m128i)v50[v49].m_startRight.m_quad);
      _mm_store_si128((__m128i *)&leftEnd, (__m128i)v50[v49].m_endLeft.m_quad);
      _mm_store_si128((__m128i *)&rightEnd, (__m128i)v50[v49].m_endRight.m_quad);
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        v51,
        (hkaiNavMeshInstance *)(unsigned int)v50[v49].m_startFace,
        (__int64)&faceIndex,
        v46);
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)v3->m_toNavMeshInstance,
        (hkaiNavMeshInstance *)(unsigned int)v50[v49].m_endFace,
        (__int64)&facePlane,
        v52);
      hkaiTraversalAnalysisUtils::setBackEdge(&leftInOut, &rightInOut, (hkVector4f *)&faceIndex, v3);
      hkaiTraversalAnalysisUtils::setBackEdge(&rightEnd, &leftEnd, &facePlane, v3);
      hkaiIntervalPartition::hkaiIntervalPartition(&other);
      hkaiTraversalAnalysisUtils::filterUnwalkableLandingZones(
        &leftInOut,
        &rightInOut,
        &leftEnd,
        &rightEnd,
        v50[v49].m_startFace,
        v50[v49].m_endFace,
        &other,
        v3);
      if ( other.m_intervals.m_size )
      {
        v53 = rightInOut.m_quad;
        _mm_store_si128((__m128i *)&v114, (__m128i)leftInOut.m_quad);
        v54 = leftEnd.m_quad;
        _mm_store_si128((__m128i *)&v119, (__m128i)v53);
        v55 = rightEnd.m_quad;
        _mm_store_si128((__m128i *)&v116, (__m128i)v54);
        _mm_store_si128((__m128i *)&v120, (__m128i)v55);
        if ( hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&v114, &v119, v3) )
        {
          if ( hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&v120, &v116, v3) )
          {
            v56 = v126.m_quad;
            v57 = (__m128 *)v3->m_settings;
            v58 = _mm_mul_ps(v40, v126.m_quad);
            leftStart.m_quad = _mm_add_ps(v58, v114.m_quad);
            rightStart.m_quad = _mm_add_ps(v58, v119.m_quad);
            v117.m_quad = _mm_add_ps(v58, v116.m_quad);
            v115.m_quad = _mm_add_ps(v58, v120.m_quad);
            extrusion.m_quad = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v42), v57[1]);
            hkaiIntervalPartition::hkaiIntervalPartition(&partition);
            hkaiGeometrySegmentCaster::turnSegmentExtruded(
              v3->m_cuttingGeometrySegmentCaster.m_pntr,
              &leftStart,
              &rightStart,
              &v117,
              &v115,
              &extrusion,
              &partition);
            hkaiIntervalPartition::complement(&partition, 0.0, 1.0);
            hkaiIntervalPartition::clipNotDefined(&partition, &other);
            v59 = partition.m_intervals.m_size;
            if ( partition.m_intervals.m_size )
            {
              if ( !v48 )
                goto LABEL_39;
              hkaiIntervalPartition::hkaiIntervalPartition(&v108);
              v60 = (__m128 *)v3->m_settings;
              v61 = v3->m_cuttingGeometrySegmentCaster.m_pntr;
              v62 = _mm_mul_ps(v44, v56);
              v63 = _mm_sub_ps(rightInOut.m_quad, leftInOut.m_quad);
              v132.m_quad = _mm_add_ps(v62, rightInOut.m_quad);
              v130.m_quad = _mm_add_ps(v62, leftInOut.m_quad);
              v64 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v63, v63, 201), v60[1]),
                      _mm_mul_ps(_mm_shuffle_ps(v60[1], v60[1], 201), v63));
              v65 = _mm_shuffle_ps(v64, v64, 201);
              v66 = _mm_mul_ps(v65, v65);
              v67 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)),
                      _mm_shuffle_ps(v66, v66, 170));
              v68 = _mm_rsqrt_ps(v67);
              v128.m_quad = _mm_mul_ps(
                              _mm_mul_ps(
                                _mm_andnot_ps(
                                  _mm_cmpleps(v67, (__m128)0i64),
                                  _mm_mul_ps(
                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v68, v67), v68)),
                                    _mm_mul_ps(*(__m128 *)_xmm, v68))),
                                v65),
                              v45);
              hkaiGeometrySegmentCaster::turnSegmentExtruded(v61, &v130, &v132, &leftStart, &rightStart, &v128, &v108);
              hkaiIntervalPartition::clipDefined(&partition, &v108);
              v108.m_intervals.m_size = 0;
              if ( v108.m_intervals.m_capacityAndFlags >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  v108.m_intervals.m_data,
                  20 * (v108.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
              v108.m_intervals.m_data = 0i64;
              v108.m_intervals.m_capacityAndFlags = 2147483648;
              if ( !partition.m_intervals.m_size )
                goto LABEL_40;
              hkaiIntervalPartition::hkaiIntervalPartition((hkaiIntervalPartition *)&pairsOut.m_size);
              v69 = (__m128 *)v3->m_settings;
              v70 = v3->m_cuttingGeometrySegmentCaster.m_pntr;
              v71 = _mm_sub_ps(rightEnd.m_quad, leftEnd.m_quad);
              v129.m_quad = _mm_add_ps(v62, leftEnd.m_quad);
              v127.m_quad = _mm_add_ps(v62, rightEnd.m_quad);
              v72 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v69[1], v69[1], 201), v71),
                      _mm_mul_ps(_mm_shuffle_ps(v71, v71, 201), v69[1]));
              v73 = _mm_shuffle_ps(v72, v72, 201);
              v74 = _mm_mul_ps(v73, v73);
              v75 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v74, v74, 85), _mm_shuffle_ps(v74, v74, 0)),
                      _mm_shuffle_ps(v74, v74, 170));
              v76 = _mm_rsqrt_ps(v75);
              v134.m_quad = _mm_mul_ps(
                              _mm_mul_ps(
                                _mm_andnot_ps(
                                  _mm_cmpleps(v75, (__m128)0i64),
                                  _mm_mul_ps(
                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v76, v75), v76)),
                                    _mm_mul_ps(v76, *(__m128 *)_xmm))),
                                v73),
                              v45);
              hkaiGeometrySegmentCaster::turnSegmentExtruded(
                v70,
                &v129,
                &v127,
                &v117,
                &v115,
                &v134,
                (hkaiIntervalPartition *)&pairsOut.m_size);
              hkaiIntervalPartition::clipDefined(&partition, (hkaiIntervalPartition *)&pairsOut.m_size);
              v106 = 0;
              if ( v107 >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  *(void **)&pairsOut.m_size,
                  20 * (v107 & 0x3FFFFFFF));
              *(_QWORD *)&pairsOut.m_size = 0i64;
              v59 = partition.m_intervals.m_size;
              v107 = 2147483648;
              if ( partition.m_intervals.m_size )
              {
LABEL_39:
                v77 = 0;
                LODWORD(v78) = (unsigned __int128)_mm_shuffle_ps(
                                                    (__m128)LODWORD(v3->m_settings->m_minEdgeLength),
                                                    (__m128)LODWORD(v3->m_settings->m_minEdgeLength),
                                                    0);
                v79 = v78 * v78;
                if ( v59 > 0 )
                {
                  do
                  {
                    v80 = (unsigned int *)hkaiIntervalPartition::getInterval(&partition, v77);
                    v81 = _mm_shuffle_ps((__m128)*v80, (__m128)*v80, 0);
                    v82 = _mm_shuffle_ps((__m128)v80[1], (__m128)v80[1], 0);
                    v83 = v80[3];
                    v122 = v80[2];
                    v124 = v80[4];
                    v123 = v83;
                    v84 = _mm_sub_ps(rightInOut.m_quad, leftInOut.m_quad);
                    v85 = v84;
                    v86 = _mm_add_ps(_mm_mul_ps(v84, v82), leftInOut.m_quad);
                    v87 = _mm_add_ps(_mm_mul_ps(v85, v81), leftInOut.m_quad);
                    v88 = _mm_sub_ps(v87, v86);
                    v89 = _mm_mul_ps(v88, v88);
                    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v89, v89, 85))
                                       + COERCE_FLOAT(_mm_shuffle_ps(v89, v89, 0)))
                               + COERCE_FLOAT(_mm_shuffle_ps(v89, v89, 170))) >= v79 )
                    {
                      v90 = _mm_sub_ps(rightEnd.m_quad, leftEnd.m_quad);
                      v91 = _mm_add_ps(_mm_mul_ps(v90, v82), leftEnd.m_quad);
                      v92 = _mm_add_ps(_mm_mul_ps(v90, v81), leftEnd.m_quad);
                      hkaiUserEdgeUtils::UserEdgePair::UserEdgePair(&userEdgePair);
                      v93 = v3->m_fromNavMeshInstance;
                      v94 = v2->m_userdata;
                      v95 = _mm_shuffle_ps(v87, v86, 68);
                      v96 = _mm_shuffle_ps(v91, v92, 68);
                      userEdgePair.m_x.m_quad = _mm_shuffle_ps(v95, v96, 136);
                      v97 = v2->m_baseCost;
                      userEdgePair.m_y.m_quad = _mm_shuffle_ps(v95, v96, 221);
                      userEdgePair.m_z.m_quad = _mm_shuffle_ps(
                                                  _mm_shuffle_ps(v87, v86, 238),
                                                  _mm_shuffle_ps(v91, v92, 238),
                                                  136);
                      v98 = v93->m_sectionUid;
                      v99 = v3->m_toNavMeshInstance;
                      userEdgePair.m_instanceUidA = v98;
                      v100 = v99->m_sectionUid;
                      v137 = v97 * 1.0039062;
                      userEdgePair.m_faceA = v50[v49].m_startFace;
                      LODWORD(v99) = v50[v49].m_endFace;
                      userEdgePair.m_instanceUidB = v100;
                      v101 = v3->m_outputLibrary;
                      userEdgePair.m_faceB = (signed int)v99;
                      userEdgePair.m_direction.m_storage = 1;
                      userEdgePair.m_costBtoA.m_value = 0;
                      userEdgePair.m_costAtoB.m_value = HIWORD(v137);
                      hkaiTraversalAnnotationLibrary::addAnnotation(v101, &userEdgePair, 0, v94);
                    }
                    ++v77;
                  }
                  while ( v77 < v59 );
                  v47 = v138;
                }
                partition.m_intervals.m_size = 0;
                if ( partition.m_intervals.m_capacityAndFlags >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    partition.m_intervals.m_data,
                    20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
                partition.m_intervals.m_data = 0i64;
                partition.m_intervals.m_capacityAndFlags = 2147483648;
                other.m_intervals.m_size = 0;
                if ( other.m_intervals.m_capacityAndFlags >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    other.m_intervals.m_data,
                    20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
                v48 = retaddr;
              }
              else
              {
LABEL_40:
                partition.m_intervals.m_size = 0;
                if ( partition.m_intervals.m_capacityAndFlags >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    partition.m_intervals.m_data,
                    20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
                partition.m_intervals.m_data = 0i64;
                partition.m_intervals.m_capacityAndFlags = 2147483648;
                other.m_intervals.m_size = 0;
                if ( other.m_intervals.m_capacityAndFlags >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    other.m_intervals.m_data,
                    20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
              }
              v44 = v112;
              goto LABEL_34;
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
        }
      }
      other.m_intervals.m_size = 0;
      if ( other.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          other.m_intervals.m_data,
          20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
LABEL_34:
      ++v49;
      --v47;
      other.m_intervals.m_data = 0i64;
      v138 = v47;
      other.m_intervals.m_capacityAndFlags = 2147483648;
    }
    while ( v47 );
  }
  pairsOut.m_size = 0;
  if ( pairsOut.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      pairsOut.m_data,
      80 * (pairsOut.m_capacityAndFlags & 0x3FFFFFFF));
}


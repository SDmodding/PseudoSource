// File Line: 24
// RVA: 0xC34660
void __fastcall hkaiDropDownAnalyzer::analyze(hkaiDropDownAnalyzer *this, hkaiTraversalAnalysisContext *context)
{
  hkaiDropDownAnalyzer *v2; // r13
  hkaiTraversalAnalysisContext *v3; // rbx
  hkVector4f v4; // xmm6
  __m128i v5; // xmm3
  hkaiTraversalAnalysisSettings *v6; // rax
  float v7; // xmm8_4
  int v8; // xmm1_4
  __m128 v9; // xmm7
  float v10; // xmm0_4
  float v11; // xmm1_4
  __m128 v12; // xmm2
  float v13; // xmm0_4
  __m128i v14; // xmm4
  __m128i v15; // xmm6
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  float v20; // xmm0_4
  __m128i v21; // xmm3
  int v22; // xmm0_4
  __m128i v23; // xmm6
  __m128 v24; // xmm2
  __m128i v25; // xmm6
  __m128 v26; // xmm1
  __m128 v27; // xmm5
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  float v30; // xmm0_4
  __m128i v31; // xmm4
  __m128 v32; // xmm6
  __m128 v33; // xmm2
  __m128i v34; // xmm7
  hkaiPairedEdgeFinder *v35; // rcx
  int v36; // edi
  __m128i v37; // xmm7
  __m128 v38; // xmm1
  __m128 v39; // xmm5
  __m128 v40; // xmm4
  __m128 v41; // xmm2
  __m128i v42; // xmm1
  float v43; // xmm11_4
  float v44; // xmm11_4
  hkVector4f *v45; // r9
  __int64 v46; // r12
  __int64 v47; // rsi
  hkaiPairedEdgeFinder::EdgePair *v48; // r14
  hkaiNavMeshUtils *v49; // rcx
  hkVector4f *v50; // r9
  __m128i v51; // xmm1
  __m128 v52; // xmm0
  __m128 v53; // xmm1
  __m128 v54; // xmm5
  __m128 v55; // xmm2
  __m128 v56; // xmm0
  __m128 v57; // xmm3
  __m128 v58; // xmm4
  __m128 v59; // xmm1
  __m128 v60; // xmm5
  int v61; // er15
  unsigned int *v62; // rax
  __m128 v63; // xmm3
  __m128 v64; // xmm4
  int v65; // xmm1_4
  __m128 v66; // xmm9
  __m128 v67; // xmm8
  __m128 v68; // xmm9
  __m128 v69; // xmm8
  __m128 v70; // xmm2
  __m128 v71; // xmm2
  __m128 v72; // xmm6
  __m128 v73; // xmm7
  __m128 v74; // xmm6
  hkaiNavMeshInstance *v75; // rax
  unsigned int v76; // er9
  __m128 v77; // xmm2
  __m128 v78; // xmm1
  float v79; // xmm0_4
  unsigned int v80; // ecx
  hkaiNavMeshInstance *v81; // rax
  unsigned int v82; // ecx
  hkaiTraversalAnnotationLibrary *v83; // rcx
  hkaiIntervalPartition reachableAreasOut; // [rsp+40h] [rbp-B8h]
  hkaiIntervalPartition other; // [rsp+50h] [rbp-A8h]
  hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> pairsOut; // [rsp+60h] [rbp-98h]
  hkVector4f rightInOut; // [rsp+70h] [rbp-88h]
  hkVector4f rightEnd; // [rsp+88h] [rbp-70h]
  hkVector4f leftInOut; // [rsp+98h] [rbp-60h]
  hkVector4f topLeftIn; // [rsp+A8h] [rbp-50h]
  hkVector4f bottomLeftIn; // [rsp+B8h] [rbp-40h]
  hkVector4f topRightIn; // [rsp+C8h] [rbp-30h]
  hkVector4f bottomRightIn; // [rsp+D8h] [rbp-20h]
  hkaiPairedEdgeFinder::PairedEdgeSettings settings; // [rsp+E8h] [rbp-10h]
  unsigned int v95; // [rsp+130h] [rbp+38h]
  int v96; // [rsp+134h] [rbp+3Ch]
  unsigned int v97; // [rsp+138h] [rbp+40h]
  hkaiUserEdgeUtils::UserEdgePair userEdgePair; // [rsp+148h] [rbp+50h]
  hkVector4f facePlane; // [rsp+198h] [rbp+A0h]
  hkVector4f v100; // [rsp+1A8h] [rbp+B0h]
  int faceIndex; // [rsp+1B8h] [rbp+C0h]
  float retaddr; // [rsp+268h] [rbp+170h]
  __int64 v103; // [rsp+270h] [rbp+178h]

  v2 = this;
  v3 = context;
  v100.m_quad = (__m128)context->m_settings->m_up;
  v4.m_quad = v100.m_quad;
  hkaiPairedEdgeFinder::PairedEdgeSettings::PairedEdgeSettings(&settings);
  v5 = _mm_load_si128((const __m128i *)_xmm);
  v6 = v3->m_settings;
  v7 = v2->m_maxPlanarAngle;
  v8 = LODWORD(v2->m_maxDropDistance) ^ _xmm[0];
  v9 = _mm_add_ps((__m128)LODWORD(v2->m_maxPlanarAngle), *(__m128 *)_xmm);
  settings.m_up = (hkVector4f)v4.m_quad;
  v10 = v6->m_minEdgeLength;
  LODWORD(settings.m_minHeightDelta) = v8;
  v11 = v2->m_maxUnderhang;
  v12 = _mm_andnot_ps(*(__m128 *)_xmm, v9);
  settings.m_minLength = v10;
  v13 = v2->m_minDropDistance;
  settings.m_maxHorizontalDelta = v11;
  LODWORD(settings.m_maxHeightDelta) = LODWORD(v13) ^ _xmm[0];
  v14 = _mm_add_epi32(v5, v5);
  settings.m_minHorizontalDelta = 0.0;
  _mm_store_si128((__m128i *)&rightInOut, v14);
  v15 = _mm_andnot_si128(v5, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v12, *(__m128 *)_xmm)), v5));
  v16 = _mm_cvtepi32_ps(v15);
  v17 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v15, v14), (__m128i)0i64);
  v18 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v16, *(__m128 *)DP1_0), v12), _mm_mul_ps(v16, *(__m128 *)DP2)),
          _mm_mul_ps(v16, *(__m128 *)DP3));
  v19 = _mm_mul_ps(v18, v18);
  v12.m128_i32[0] = (unsigned __int128)_mm_andnot_ps(
                                         v17,
                                         _mm_add_ps(
                                           _mm_sub_ps(
                                             _mm_mul_ps(
                                               _mm_mul_ps(
                                                 _mm_add_ps(
                                                   _mm_mul_ps(
                                                     _mm_add_ps(
                                                       _mm_mul_ps(v19, *(__m128 *)cosCoeff0_0),
                                                       *(__m128 *)cosCoeff1),
                                                     v19),
                                                   *(__m128 *)cosCoeff2_0),
                                                 v19),
                                               v19),
                                             _mm_mul_ps(v19, *(__m128 *)_xmm)),
                                           *(__m128 *)_xmm));
  v20 = (float)((float)((float)((float)(v19.m128_f32[0] * -0.00019515296) + 0.0083321612) * v19.m128_f32[0])
              + -0.16666655)
      * v19.m128_f32[0];
  v21 = _mm_load_si128((const __m128i *)&rightInOut);
  v12.m128_i32[0] |= COERCE_UNSIGNED_INT((float)(v20 * v18.m128_f32[0]) + v18.m128_f32[0]) & v17.m128_i32[0];
  v22 = (unsigned __int128)_mm_and_si128(_mm_add_epi32(v21, v21), v15);
  v23 = _mm_load_si128((const __m128i *)_xmm);
  LODWORD(settings.m_cosMaxPlanarAngle) = v12.m128_i32[0] ^ (v22 << 29) ^ v9.m128_i32[0] & _xmm[0];
  v24 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(v7));
  v25 = _mm_andnot_si128(v23, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v24, *(__m128 *)_xmm)), v23));
  v26 = _mm_cvtepi32_ps(v25);
  v27 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v25, v21), (__m128i)0i64);
  v28 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v26, *(__m128 *)DP1_0), v24), _mm_mul_ps(v26, *(__m128 *)DP2)),
          _mm_mul_ps(v26, *(__m128 *)DP3));
  v29 = _mm_mul_ps(v28, v28);
  v30 = (float)((float)((float)((float)((float)((float)(v29.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                      * v29.m128_f32[0])
                              + -0.16666655)
                      * v29.m128_f32[0])
              * v28.m128_f32[0])
      + v28.m128_f32[0];
  v31 = _mm_load_si128((const __m128i *)&rightInOut);
  retaddr = v2->m_maxRelativeSlopeAngle;
  LODWORD(settings.m_sinMaxPlanarAngle) = (*(unsigned __int128 *)&_mm_andnot_ps(
                                                                    v27,
                                                                    _mm_add_ps(
                                                                      _mm_sub_ps(
                                                                        _mm_mul_ps(
                                                                          _mm_mul_ps(
                                                                            _mm_add_ps(
                                                                              _mm_mul_ps(
                                                                                _mm_add_ps(
                                                                                  _mm_mul_ps(
                                                                                    v29,
                                                                                    *(__m128 *)cosCoeff0_0),
                                                                                  *(__m128 *)cosCoeff1),
                                                                                v29),
                                                                              *(__m128 *)cosCoeff2_0),
                                                                            v29),
                                                                          v29),
                                                                        _mm_mul_ps(v29, *(__m128 *)_xmm)),
                                                                      *(__m128 *)_xmm)) | LODWORD(v30) & v27.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v31, v31), v25) << 29) ^ LODWORD(v7) & _xmm[0];
  v32 = _mm_add_ps((__m128)LODWORD(retaddr), *(__m128 *)_xmm);
  v33 = _mm_andnot_ps(*(__m128 *)_xmm, v32);
  v34 = _mm_load_si128((const __m128i *)_xmm);
  v35 = v3->m_pairedEdgeFinder.m_pntr;
  v36 = 0;
  settings.m_matchAngles.m_bool = 1;
  settings.m_findInternalEnds.m_bool = 1;
  v37 = _mm_andnot_si128(v34, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v33, *(__m128 *)_xmm)), v34));
  v38 = _mm_cvtepi32_ps(v37);
  pairsOut.m_data = 0i64;
  pairsOut.m_size = 0;
  pairsOut.m_capacityAndFlags = 2147483648;
  v39 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v37, v31), (__m128i)0i64);
  v40 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v38, *(__m128 *)DP1_0), v33), _mm_mul_ps(v38, *(__m128 *)DP2)),
          _mm_mul_ps(v38, *(__m128 *)DP3));
  v41 = _mm_mul_ps(v40, v40);
  v42 = _mm_load_si128((const __m128i *)&rightInOut);
  LODWORD(settings.m_cosMaxDeltaSlopeAngle) = (*(unsigned __int128 *)&_mm_andnot_ps(
                                                                        v39,
                                                                        _mm_add_ps(
                                                                          _mm_sub_ps(
                                                                            _mm_mul_ps(
                                                                              _mm_mul_ps(
                                                                                _mm_add_ps(
                                                                                  _mm_mul_ps(
                                                                                    _mm_add_ps(
                                                                                      _mm_mul_ps(
                                                                                        v41,
                                                                                        *(__m128 *)cosCoeff0_0),
                                                                                      *(__m128 *)cosCoeff1),
                                                                                    v41),
                                                                                  *(__m128 *)cosCoeff2_0),
                                                                                v41),
                                                                              v41),
                                                                            _mm_mul_ps(v41, *(__m128 *)_xmm)),
                                                                          *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                                                (float)((float)((float)((float)((float)((float)(v41.m128_f32[0] * -0.00019515296) + 0.0083321612) * v41.m128_f32[0]) + -0.16666655) * v41.m128_f32[0]) * v40.m128_f32[0])
                                                                                              + v40.m128_f32[0]) & v39.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v42, v42), v37) << 29) ^ v32.m128_i32[0] & _xmm[0];
  hkaiPairedEdgeFinder::findEdgePairs(v35, &settings, &pairsOut);
  LODWORD(v43) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(v3->m_settings->m_minEdgeLength),
                                      (__m128)LODWORD(v3->m_settings->m_minEdgeLength),
                                      0);
  v44 = v43 * v43;
  hkaiIntervalPartition::hkaiIntervalPartition(&other);
  hkaiIntervalPartition::hkaiIntervalPartition(&reachableAreasOut);
  v46 = pairsOut.m_size;
  v103 = pairsOut.m_size;
  if ( pairsOut.m_size > 0i64 )
  {
    v47 = 0i64;
    do
    {
      v48 = pairsOut.m_data;
      v49 = (hkaiNavMeshUtils *)v3->m_fromNavMeshInstance;
      _mm_store_si128((__m128i *)&leftInOut, (__m128i)pairsOut.m_data[v47].m_startLeft.m_quad);
      _mm_store_si128((__m128i *)&rightInOut.m_quad.m128_u16[4], (__m128i)v48[v47].m_startRight.m_quad);
      _mm_store_si128((__m128i *)&rightInOut, (__m128i)v48[v47].m_endLeft.m_quad);
      _mm_store_si128((__m128i *)&rightEnd, (__m128i)v48[v47].m_endRight.m_quad);
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        v49,
        (hkaiNavMeshInstance *)(unsigned int)v48[v47].m_startFace,
        (__int64)&faceIndex,
        v45);
      hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)v3->m_toNavMeshInstance,
        (hkaiNavMeshInstance *)(unsigned int)v48[v47].m_endFace,
        (__int64)&facePlane,
        v50);
      hkaiTraversalAnalysisUtils::setBackEdge(
        &leftInOut,
        (hkVector4f *)((char *)&rightInOut + 8),
        (hkVector4f *)&faceIndex,
        v3);
      hkaiTraversalAnalysisUtils::setBackEdge(&rightEnd, &rightInOut, &facePlane, v3);
      hkaiIntervalPartition::clear(&other);
      hkaiTraversalAnalysisUtils::filterUnwalkableLandingZones(
        &leftInOut,
        (hkVector4f *)((char *)&rightInOut + 8),
        &rightInOut,
        &rightEnd,
        v48[v47].m_startFace,
        v48[v47].m_endFace,
        &other,
        v3);
      if ( other.m_intervals.m_size )
      {
        v51 = *(__m128i *)((char *)&rightInOut + 8);
        _mm_store_si128((__m128i *)&topRightIn, (__m128i)leftInOut.m_quad);
        v52 = rightInOut.m_quad;
        _mm_store_si128((__m128i *)&topLeftIn, v51);
        v53 = rightEnd.m_quad;
        _mm_store_si128((__m128i *)&bottomRightIn, (__m128i)v52);
        _mm_store_si128((__m128i *)&bottomLeftIn, (__m128i)v53);
        if ( hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&topRightIn, &topLeftIn, v3) )
        {
          if ( hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&bottomLeftIn, &bottomRightIn, v3) )
          {
            v54 = _mm_mul_ps(topRightIn.m_quad, v100.m_quad);
            v55 = _mm_mul_ps(topLeftIn.m_quad, v100.m_quad);
            v56 = _mm_mul_ps(bottomLeftIn.m_quad, v100.m_quad);
            v57 = _mm_mul_ps(bottomRightIn.m_quad, v100.m_quad);
            v58 = _mm_shuffle_ps(v54, v55, 68);
            v59 = _mm_shuffle_ps(v57, v56, 68);
            v60 = _mm_add_ps(
                    _mm_shuffle_ps(_mm_shuffle_ps(v54, v55, 238), _mm_shuffle_ps(v57, v56, 238), 136),
                    _mm_add_ps(_mm_shuffle_ps(v58, v59, 221), _mm_shuffle_ps(v58, v59, 136)));
            if ( fmin(COERCE_FLOAT(_mm_shuffle_ps(v60, v60, 0)), COERCE_FLOAT(_mm_shuffle_ps(v60, v60, 85))) > fmax(COERCE_FLOAT(_mm_shuffle_ps(v60, v60, 170)), COERCE_FLOAT(_mm_shuffle_ps(v60, v60, 255))) )
            {
              hkaiIntervalPartition::clear(&reachableAreasOut);
              hkaiTraversalAnalysisUtils::findOverLedgeReachability(
                &bottomLeftIn,
                &bottomRightIn,
                &topLeftIn,
                &topRightIn,
                v3,
                &reachableAreasOut);
              hkaiIntervalPartition::clipNotDefined(&reachableAreasOut, &other);
              v61 = reachableAreasOut.m_intervals.m_size;
              if ( reachableAreasOut.m_intervals.m_size )
              {
                if ( reachableAreasOut.m_intervals.m_size > 0 )
                {
                  do
                  {
                    v62 = (unsigned int *)hkaiIntervalPartition::getInterval(&reachableAreasOut, v36);
                    v63 = _mm_shuffle_ps((__m128)*v62, (__m128)*v62, 0);
                    v64 = _mm_shuffle_ps((__m128)v62[1], (__m128)v62[1], 0);
                    v65 = v62[3];
                    v95 = v62[2];
                    v97 = v62[4];
                    v96 = v65;
                    v66 = _mm_sub_ps(*(__m128 *)((char *)&rightInOut.m_quad + 8), leftInOut.m_quad);
                    v67 = v66;
                    v68 = _mm_add_ps(_mm_mul_ps(v66, v64), leftInOut.m_quad);
                    v69 = _mm_add_ps(_mm_mul_ps(v67, v63), leftInOut.m_quad);
                    v70 = _mm_sub_ps(v69, v68);
                    v71 = _mm_mul_ps(v70, v70);
                    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v71, v71, 85))
                                       + COERCE_FLOAT(_mm_shuffle_ps(v71, v71, 0)))
                               + COERCE_FLOAT(_mm_shuffle_ps(v71, v71, 170))) >= v44 )
                    {
                      v72 = _mm_sub_ps(rightEnd.m_quad, rightInOut.m_quad);
                      v73 = _mm_add_ps(_mm_mul_ps(v72, v64), rightInOut.m_quad);
                      v74 = _mm_add_ps(_mm_mul_ps(v72, v63), rightInOut.m_quad);
                      hkaiUserEdgeUtils::UserEdgePair::UserEdgePair(&userEdgePair);
                      v75 = v3->m_fromNavMeshInstance;
                      v76 = v2->m_userdata;
                      v77 = _mm_shuffle_ps(v69, v68, 68);
                      v78 = _mm_shuffle_ps(v73, v74, 68);
                      userEdgePair.m_x.m_quad = _mm_shuffle_ps(v77, v78, 136);
                      v79 = v2->m_baseCost;
                      userEdgePair.m_y.m_quad = _mm_shuffle_ps(v77, v78, 221);
                      userEdgePair.m_z.m_quad = _mm_shuffle_ps(
                                                  _mm_shuffle_ps(v69, v68, 238),
                                                  _mm_shuffle_ps(v73, v74, 238),
                                                  136);
                      v80 = v75->m_sectionUid;
                      v81 = v3->m_toNavMeshInstance;
                      userEdgePair.m_instanceUidA = v80;
                      v82 = v81->m_sectionUid;
                      retaddr = v79 * 1.0039062;
                      userEdgePair.m_faceA = v48[v47].m_startFace;
                      LODWORD(v81) = v48[v47].m_endFace;
                      userEdgePair.m_instanceUidB = v82;
                      v83 = v3->m_outputLibrary;
                      userEdgePair.m_faceB = (signed int)v81;
                      userEdgePair.m_direction.m_storage = 1;
                      userEdgePair.m_costBtoA.m_value = 0;
                      userEdgePair.m_costAtoB.m_value = HIWORD(retaddr);
                      hkaiTraversalAnnotationLibrary::addAnnotation(
                        v83,
                        &userEdgePair,
                        HKAI_TRAVERSAL_TYPE_DROP_DOWN,
                        v76);
                    }
                    ++v36;
                  }
                  while ( v36 < v61 );
                  v46 = v103;
                }
                v36 = 0;
              }
            }
          }
        }
      }
      ++v47;
      v103 = --v46;
    }
    while ( v46 );
  }
  reachableAreasOut.m_intervals.m_size = 0;
  if ( reachableAreasOut.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      reachableAreasOut.m_intervals.m_data,
      20 * (reachableAreasOut.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  reachableAreasOut.m_intervals.m_data = 0i64;
  reachableAreasOut.m_intervals.m_capacityAndFlags = 2147483648;
  other.m_intervals.m_size = 0;
  if ( other.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      other.m_intervals.m_data,
      20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  other.m_intervals.m_data = 0i64;
  pairsOut.m_size = 0;
  other.m_intervals.m_capacityAndFlags = 2147483648;
  if ( pairsOut.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      pairsOut.m_data,
      80 * (pairsOut.m_capacityAndFlags & 0x3FFFFFFF));
}er.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));



// File Line: 26
// RVA: 0xC3A610
__int64 __fastcall hkaiTraversalAnalysisUtils::findOffsetDist(
        hkVector4f *left,
        hkVector4f *right,
        hkVector4f *offsetDir,
        hkSimdFloat32 *maxOffset,
        hkSimdFloat32 *distOut,
        hkaiTraversalAnalysisContext *context)
{
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  unsigned int v11; // ebx
  hkaiIntervalPartition partition; // [rsp+30h] [rbp-58h] BYREF
  hkVector4f displacement; // [rsp+40h] [rbp-48h] BYREF
  hkVector4f rightStart; // [rsp+50h] [rbp-38h] BYREF
  hkVector4f leftStart; // [rsp+60h] [rbp-28h] BYREF
  float distOuta; // [rsp+B0h] [rbp+28h]

  *distOut = 0i64;
  v8 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, maxOffset->m_real), offsetDir->m_quad);
  v9 = _mm_sub_ps(left->m_quad, v8);
  v10 = _mm_sub_ps(right->m_quad, v8);
  displacement.m_quad = v8;
  leftStart.m_quad = v9;
  rightStart.m_quad = v10;
  hkaiIntervalPartition::hkaiIntervalPartition(&partition);
  hkaiGeometrySegmentCaster::castSegment(
    context->m_walkableGeometrySegmentCaster.m_pntr,
    &leftStart,
    &rightStart,
    &displacement,
    &partition);
  if ( !partition.m_intervals.m_size )
    goto LABEL_7;
  distOuta = hkaiIntervalPartition::getExtremeY<0>(&partition);
  if ( distOuta >= 0.001 )
    goto LABEL_6;
  hkaiIntervalPartition::clipX(&partition, 0.001, 0.99900001);
  hkaiIntervalPartition::spread(&partition, 0.001);
  if ( partition.m_intervals.m_size )
  {
    distOuta = hkaiIntervalPartition::getExtremeY<0>(&partition);
    if ( distOuta < 0.001 )
    {
      v11 = 0;
      goto LABEL_8;
    }
LABEL_6:
    distOut->m_real = _mm_mul_ps(
                        _mm_sub_ps(
                          query.m_quad,
                          _mm_shuffle_ps((__m128)LODWORD(distOuta), (__m128)LODWORD(distOuta), 0)),
                        maxOffset->m_real);
  }
LABEL_7:
  v11 = 1;
LABEL_8:
  partition.m_intervals.m_size = 0;
  if ( partition.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      partition.m_intervals.m_data,
      20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  return v11;
}

// File Line: 82
// RVA: 0xC3A770
__int64 __fastcall hkaiTraversalAnalysisUtils::findOffsetDistExtruded(
        hkVector4f *left,
        hkVector4f *right,
        hkVector4f *extrusion,
        hkVector4f *offsetDir,
        hkSimdFloat32 *maxOffset,
        hkSimdFloat32 *distOut,
        hkaiTraversalAnalysisContext *context)
{
  __m128 v9; // xmm2
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  unsigned int v12; // ebx
  hkaiIntervalPartition partition; // [rsp+30h] [rbp-58h] BYREF
  hkVector4f displacement; // [rsp+40h] [rbp-48h] BYREF
  hkVector4f rightStart; // [rsp+50h] [rbp-38h] BYREF
  hkVector4f leftStart; // [rsp+60h] [rbp-28h] BYREF
  float distOuta; // [rsp+B8h] [rbp+30h]

  *distOut = 0i64;
  v9 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, maxOffset->m_real), offsetDir->m_quad);
  v10 = _mm_sub_ps(left->m_quad, v9);
  v11 = _mm_sub_ps(right->m_quad, v9);
  displacement.m_quad = v9;
  leftStart.m_quad = v10;
  rightStart.m_quad = v11;
  hkaiIntervalPartition::hkaiIntervalPartition(&partition);
  hkaiGeometrySegmentCaster::castSegmentExtruded(
    context->m_walkableGeometrySegmentCaster.m_pntr,
    &leftStart,
    &rightStart,
    &displacement,
    extrusion,
    &partition);
  if ( !partition.m_intervals.m_size )
    goto LABEL_7;
  distOuta = hkaiIntervalPartition::getExtremeY<0>(&partition);
  if ( distOuta >= 0.001 )
    goto LABEL_6;
  hkaiIntervalPartition::clipX(&partition, 0.001, 0.99900001);
  hkaiIntervalPartition::spread(&partition, 0.001);
  if ( partition.m_intervals.m_size )
  {
    distOuta = hkaiIntervalPartition::getExtremeY<0>(&partition);
    if ( distOuta < 0.001 )
    {
      v12 = 0;
      goto LABEL_8;
    }
LABEL_6:
    distOut->m_real = _mm_mul_ps(
                        _mm_sub_ps(
                          query.m_quad,
                          _mm_shuffle_ps((__m128)LODWORD(distOuta), (__m128)LODWORD(distOuta), 0)),
                        maxOffset->m_real);
  }
LABEL_7:
  v12 = 1;
LABEL_8:
  partition.m_intervals.m_size = 0;
  if ( partition.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      partition.m_intervals.m_data,
      20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  return v12;
}

// File Line: 134
// RVA: 0xC3A8F0
__int64 __fastcall hkaiTraversalAnalysisUtils::findRaiseHeight(
        hkVector4f *left,
        hkVector4f *right,
        hkSimdFloat32 *raiseHeightOut,
        hkaiTraversalAnalysisContext *context)
{
  hkVector4f *p_m_up; // r8
  hkSimdFloat32 maxOffset; // [rsp+30h] [rbp-18h] BYREF

  p_m_up = &context->m_settings->m_up;
  maxOffset.m_real = _mm_shuffle_ps(
                       (__m128)LODWORD(context->m_settings->m_raiseEdgeHeightLimit),
                       (__m128)LODWORD(context->m_settings->m_raiseEdgeHeightLimit),
                       0);
  return hkaiTraversalAnalysisUtils::findOffsetDist(left, right, p_m_up, &maxOffset, raiseHeightOut, context);
}

// File Line: 149
// RVA: 0xC3A930
__int64 __fastcall hkaiTraversalAnalysisUtils::findExtrudedRaiseHeight(
        hkVector4f *left,
        hkVector4f *right,
        hkVector4f *extrusion,
        hkSimdFloat32 *raiseHeightOut,
        hkaiTraversalAnalysisContext *context)
{
  hkVector4f *p_m_up; // r9
  hkSimdFloat32 maxOffset; // [rsp+40h] [rbp-18h] BYREF

  p_m_up = &context->m_settings->m_up;
  maxOffset.m_real = _mm_shuffle_ps(
                       (__m128)LODWORD(context->m_settings->m_raiseEdgeHeightLimit),
                       (__m128)LODWORD(context->m_settings->m_raiseEdgeHeightLimit),
                       0);
  return hkaiTraversalAnalysisUtils::findOffsetDistExtruded(
           left,
           right,
           extrusion,
           p_m_up,
           &maxOffset,
           raiseHeightOut,
           context);
}

// File Line: 164
// RVA: 0xC3A980
__int64 __fastcall hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(
        hkVector4f *leftInOut,
        hkVector4f *rightInOut,
        hkaiTraversalAnalysisContext *context)
{
  __int64 result; // rax
  __m128 v7; // xmm2
  hkSimdFloat32 raiseHeightOut; // [rsp+20h] [rbp-28h] BYREF

  result = hkaiTraversalAnalysisUtils::findRaiseHeight(leftInOut, rightInOut, &raiseHeightOut, context);
  if ( (_DWORD)result )
  {
    v7 = _mm_add_ps(
           raiseHeightOut.m_real,
           _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0));
    leftInOut->m_quad = _mm_add_ps(_mm_mul_ps(context->m_settings->m_up.m_quad, v7), leftInOut->m_quad);
    result = 1i64;
    rightInOut->m_quad = _mm_add_ps(_mm_mul_ps(context->m_settings->m_up.m_quad, v7), rightInOut->m_quad);
  }
  return result;
}

// File Line: 186
// RVA: 0xC3AA10
__int64 __fastcall hkaiTraversalAnalysisUtils::raiseExtrudedEdgeAboveGeometry(
        hkVector4f *leftInOut,
        hkVector4f *rightInOut,
        hkVector4f *extrusion,
        hkaiTraversalAnalysisContext *context)
{
  __int64 result; // rax
  __m128 v8; // xmm2
  hkSimdFloat32 v9; // [rsp+40h] [rbp-28h] BYREF

  result = hkaiTraversalAnalysisUtils::findExtrudedRaiseHeight(leftInOut, rightInOut, extrusion, &v9, context);
  if ( (_DWORD)result )
  {
    v8 = _mm_add_ps(v9.m_real, _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0));
    leftInOut->m_quad = _mm_add_ps(_mm_mul_ps(context->m_settings->m_up.m_quad, v8), leftInOut->m_quad);
    result = 1i64;
    rightInOut->m_quad = _mm_add_ps(_mm_mul_ps(context->m_settings->m_up.m_quad, v8), rightInOut->m_quad);
  }
  return result;
}

// File Line: 208
// RVA: 0xC3AAA0
void __fastcall hkaiTraversalAnalysisUtils::setBackEdge(
        hkVector4f *leftInOut,
        hkVector4f *rightInOut,
        hkVector4f *facePlane,
        hkaiTraversalAnalysisContext *context)
{
  __m128 v4; // xmm5
  __m128 v5; // xmm5
  __m128 v6; // xmm5
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  __m128 v10; // xmm4

  v4 = _mm_sub_ps(rightInOut->m_quad, leftInOut->m_quad);
  v5 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), context->m_settings->m_up.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(context->m_settings->m_up.m_quad, context->m_settings->m_up.m_quad, 201), v4));
  v6 = _mm_shuffle_ps(v5, v5, 201);
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  v10 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(v8, (__m128)0i64),
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)), _mm_mul_ps(*(__m128 *)_xmm, v9))),
            v6),
          (__m128)_xmm_bc23d70abc23d70abc23d70abc23d70a);
  leftInOut->m_quad = _mm_add_ps(leftInOut->m_quad, v10);
  rightInOut->m_quad = _mm_add_ps(rightInOut->m_quad, v10);
}

// File Line: 225
// RVA: 0xC3AD60
void __fastcall hkaiTraversalAnalysisUtils::findOverLedgeReachability(
        hkVector4f *bottomLeftIn,
        hkVector4f *bottomRightIn,
        hkVector4f *topLeftIn,
        hkVector4f *topRightIn,
        hkaiIntervalPartition *context)
{
  __m128 m_quad; // xmm0
  __m128 m_characterHeight_low; // xmm6
  __m128 m_characterRadius_low; // xmm8
  __m128 m_raiseEdgeHeightLimit_low; // xmm7
  __m128 v9; // xmm9
  __m128 v10; // xmm6
  __m128 v11; // xmm7
  __m128 v12; // xmm8
  __m128 v13; // xmm1
  __m128 v14; // xmm10
  __m128 v15; // xmm5
  __m128 v16; // xmm5
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  hkaiGeometrySegmentCaster *m_pntr; // rcx
  __m128 v21; // xmm0
  __m128 v22; // xmm4
  __m128 v23; // xmm5
  __m128 v24; // xmm0
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  __m128 v27; // xmm5
  __m128 v28; // xmm1
  __m128 v29; // xmm7
  __m128 v30; // xmm1
  __m128 v31; // xmm4
  __m128 v32; // xmm6
  __m128 v33; // xmm4
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  hkaiIntervalPartition partition; // [rsp+40h] [rbp-B8h] BYREF
  hkaiIntervalPartition other; // [rsp+50h] [rbp-A8h] BYREF
  hkVector4f topRightInOut; // [rsp+60h] [rbp-98h] BYREF
  char bottomRightInOut[24]; // [rsp+70h] [rbp-88h] BYREF
  hkVector4f bottomLeftInOut; // [rsp+88h] [rbp-70h] BYREF
  hkVector4f leftStart; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f rightInOut; // [rsp+A8h] [rbp-50h] BYREF
  hkVector4f rightStart; // [rsp+B8h] [rbp-40h] BYREF
  hkVector4f leftInOut; // [rsp+C8h] [rbp-30h] BYREF
  hkVector4f up; // [rsp+D8h] [rbp-20h] BYREF
  hkVector4f v48; // [rsp+E8h] [rbp-10h] BYREF
  hkVector4f extrusion; // [rsp+F8h] [rbp+0h] BYREF
  hkVector4f v50; // [rsp+108h] [rbp+10h] BYREF
  hkSimdFloat32 extraDistance; // [rsp+118h] [rbp+20h] BYREF
  hkVector4f displacement; // [rsp+128h] [rbp+30h] BYREF
  hkaiTraversalAnalysisContext *v53; // [rsp+1E8h] [rbp+F0h]

  m_quad = bottomLeftIn->m_quad;
  m_characterHeight_low = (__m128)LODWORD(v53->m_settings->m_characterHeight);
  m_characterRadius_low = (__m128)LODWORD(v53->m_settings->m_characterRadius);
  m_raiseEdgeHeightLimit_low = (__m128)LODWORD(v53->m_settings->m_raiseEdgeHeightLimit);
  v9 = v53->m_settings->m_up.m_quad;
  rightStart.m_quad = bottomRightIn->m_quad;
  v10 = _mm_shuffle_ps(m_characterHeight_low, m_characterHeight_low, 0);
  v11 = _mm_shuffle_ps(m_raiseEdgeHeightLimit_low, m_raiseEdgeHeightLimit_low, 0);
  v12 = _mm_mul_ps(_mm_shuffle_ps(m_characterRadius_low, m_characterRadius_low, 0), (__m128)xmmword_141A710D0);
  rightInOut.m_quad = topRightIn->m_quad;
  leftStart.m_quad = m_quad;
  v13 = _mm_sub_ps(rightInOut.m_quad, topLeftIn->m_quad);
  leftInOut.m_quad = topLeftIn->m_quad;
  v14 = _mm_shuffle_ps(v9, v9, 201);
  up.m_quad = v9;
  v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v9), _mm_mul_ps(v13, v14));
  v16 = _mm_shuffle_ps(v15, v15, 201);
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  extrusion.m_quad = _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmple_ps(v18, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                             _mm_mul_ps(v19, *(__m128 *)_xmm))),
                         v16),
                       v12);
  hkaiTraversalAnalysisUtils::raiseExtrudedEdgeAboveGeometry(
    (hkVector4f *)&leftInOut.m_quad.m128_u16[4],
    (hkVector4f *)&rightInOut.m_quad.m128_u16[4],
    &extrusion,
    v53);
  hkaiTraversalAnalysisUtils::raiseEdgeAboveGeometry(&leftStart, &rightStart, v53);
  bottomLeftInOut.m_quad = leftStart.m_quad;
  *(_QWORD *)&bottomRightInOut[16] = rightStart.m_quad.m128_u64[1];
  *(hkVector4f *)bottomRightInOut = (hkVector4f)leftInOut.m_quad;
  topRightInOut.m_quad = rightInOut.m_quad;
  extraDistance.m_real = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_050000001), (__m128)LODWORD(FLOAT_0_050000001), 0);
  hkaiTraversalAnalysisUtils::resolveHangs(
    &bottomLeftInOut,
    (hkVector4f *)&bottomRightInOut[8],
    (hkVector4f *)bottomRightInOut,
    &topRightInOut,
    &extraDistance,
    &up);
  v48.m_quad = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v10), v9);
  hkaiIntervalPartition::hkaiIntervalPartition(&partition);
  hkaiGeometrySegmentCaster::turnSegment(
    v53->m_walkableGeometrySegmentCaster.m_pntr,
    &leftStart,
    &rightStart,
    &bottomLeftInOut,
    (hkVector4f *)&bottomRightInOut[8],
    &partition);
  hkaiIntervalPartition::hkaiIntervalPartition(&other);
  hkaiGeometrySegmentCaster::turnSegmentExtruded(
    v53->m_walkableGeometrySegmentCaster.m_pntr,
    &leftInOut,
    &rightInOut,
    (hkVector4f *)bottomRightInOut,
    &topRightInOut,
    &v48,
    &other);
  hkaiIntervalPartition::complement(&partition, 0.0, 1.0);
  hkaiIntervalPartition::clipDefined(&partition, &other);
  if ( partition.m_intervals.m_size )
  {
    m_pntr = v53->m_walkableGeometrySegmentCaster.m_pntr;
    v21 = _mm_mul_ps(v9, v10);
    v22 = _mm_add_ps(*(__m128 *)bottomRightInOut, v21);
    v23 = _mm_add_ps(topRightInOut.m_quad, v21);
    v24 = _mm_mul_ps(v9, v11);
    *(_QWORD *)bottomRightInOut = v22.m128_u64[0];
    topRightInOut.m_quad = v23;
    bottomLeftInOut.m_quad = _mm_sub_ps(bottomLeftInOut.m_quad, v24);
    *(__m128 *)&bottomRightInOut[8] = _mm_sub_ps(*(__m128 *)&bottomRightInOut[8], v24);
    v25 = _mm_sub_ps(bottomLeftInOut.m_quad, v22);
    v26 = _mm_sub_ps(*(__m128 *)&bottomRightInOut[8], v23);
    v27 = _mm_sub_ps(v23, v22);
    v28 = _mm_mul_ps(v25, v9);
    v29 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
            _mm_shuffle_ps(v28, v28, 170));
    v30 = _mm_mul_ps(v26, v9);
    v31 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v9), _mm_mul_ps(v27, v14));
    v32 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
            _mm_shuffle_ps(v30, v30, 170));
    v33 = _mm_shuffle_ps(v31, v31, 201);
    v34 = _mm_cmplt_ps(v29, v32);
    displacement.m_quad = _mm_or_ps(_mm_andnot_ps(v34, v26), _mm_and_ps(v25, v34));
    v35 = _mm_mul_ps(v33, v33);
    v36 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
            _mm_shuffle_ps(v35, v35, 170));
    v37 = _mm_rsqrt_ps(v36);
    v50.m_quad = _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_andnot_ps(
                       _mm_cmple_ps(v36, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v36), v37)),
                         _mm_mul_ps(v37, *(__m128 *)_xmm))),
                     v33),
                   v12);
    hkaiGeometrySegmentCaster::castSegmentExtruded(
      m_pntr,
      (hkVector4f *)bottomRightInOut,
      &topRightInOut,
      &displacement,
      &v50,
      context);
    hkaiIntervalPartition::clipNotDefined(context, &partition);
    v29.m128_i32[0] ^= _xmm[0];
    v37.m128_f32[0] = v53->m_settings->m_raiseEdgeHeightLimit * 2.0;
    v36.m128_f32[0] = fmaxf(0.0, (float)(v29.m128_f32[0] - v37.m128_f32[0]) * (float)(1.0 / v29.m128_f32[0]));
    hkaiIntervalPartition::clipFunc<0>(
      context,
      fmaxf(0.0, (float)(COERCE_FLOAT(v32.m128_i32[0] ^ _xmm[0]) - v37.m128_f32[0]) * (float)(1.0 / v29.m128_f32[0]))
    - v36.m128_f32[0],
      v36.m128_f32[0]);
    hkaiIntervalPartition::discardRange(context);
  }
  other.m_intervals.m_size = 0;
  if ( other.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      other.m_intervals.m_data,
      20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  other.m_intervals.m_data = 0i64;
  other.m_intervals.m_capacityAndFlags = 0x80000000;
  partition.m_intervals.m_size = 0;
  if ( partition.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      partition.m_intervals.m_data,
      20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 328
// RVA: 0xC3AB50
void __fastcall hkaiTraversalAnalysisUtils::resolveHangs(
        hkVector4f *bottomLeftInOut,
        hkVector4f *bottomRightInOut,
        hkVector4f *topLeftInOut,
        hkVector4f *topRightInOut,
        hkSimdFloat32 *extraDistance,
        hkVector4f *up)
{
  __m128 v6; // xmm5
  __m128 v7; // xmm2
  __m128 v8; // xmm9
  __m128 v9; // xmm6
  __m128 v10; // xmm3
  __m128 v11; // xmm9
  __m128 v12; // xmm9
  __m128 v13; // xmm9
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm9
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  __m128 v21; // xmm4
  __m128 v22; // xmm7
  __m128 v23; // xmm2
  __m128 v24; // xmm9
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  __m128 v30; // xmm3
  __m128 v31; // xmm1

  v6 = _mm_add_ps(
         _mm_mul_ps(_mm_sub_ps(topLeftInOut->m_quad, bottomLeftInOut->m_quad), (__m128)xmmword_141A711B0),
         bottomLeftInOut->m_quad);
  v7 = _mm_mul_ps(up->m_quad, v6);
  v8 = _mm_add_ps(
         _mm_mul_ps(_mm_sub_ps(topRightInOut->m_quad, bottomRightInOut->m_quad), (__m128)xmmword_141A711B0),
         bottomRightInOut->m_quad);
  v9 = _mm_shuffle_ps(bottomLeftInOut->m_quad, bottomRightInOut->m_quad, 68);
  v10 = _mm_mul_ps(up->m_quad, v8);
  v11 = _mm_sub_ps(
          _mm_sub_ps(
            v8,
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                _mm_shuffle_ps(v10, v10, 170)),
              up->m_quad)),
          _mm_sub_ps(
            v6,
            _mm_mul_ps(
              _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170)),
              up->m_quad)));
  v12 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), up->m_quad),
          _mm_mul_ps(_mm_shuffle_ps(up->m_quad, up->m_quad, 201), v11));
  v13 = _mm_shuffle_ps(v12, v12, 201);
  v14 = _mm_mul_ps(v13, v13);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_rsqrt_ps(v15);
  v17 = _mm_shuffle_ps(topLeftInOut->m_quad, topRightInOut->m_quad, 68);
  v18 = _mm_mul_ps(
          v13,
          _mm_andnot_ps(
            _mm_cmple_ps(v15, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
              _mm_mul_ps(*(__m128 *)_xmm, v16))));
  v19 = _mm_shuffle_ps(v9, v17, 136);
  v20 = _mm_shuffle_ps(v9, v17, 221);
  v21 = _mm_shuffle_ps(v18, v18, 85);
  v22 = _mm_shuffle_ps(
          _mm_shuffle_ps(bottomLeftInOut->m_quad, bottomRightInOut->m_quad, 238),
          _mm_shuffle_ps(topLeftInOut->m_quad, topRightInOut->m_quad, 238),
          136);
  v23 = _mm_shuffle_ps(v18, v18, 0);
  v24 = _mm_shuffle_ps(v18, v18, 170);
  v25 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v21, v20), _mm_mul_ps(v23, v19)), _mm_mul_ps(v24, v22));
  v26 = _mm_min_ps(_mm_shuffle_ps(v25, v25, 78), v25);
  v27 = _mm_add_ps(_mm_sub_ps(v25, _mm_min_ps(v26, _mm_shuffle_ps(v26, v26, 177))), extraDistance->m_real);
  bottomLeftInOut->m_quad = _mm_sub_ps(v19, _mm_mul_ps(v23, v27));
  bottomRightInOut->m_quad = _mm_sub_ps(v20, _mm_mul_ps(v21, v27));
  topLeftInOut->m_quad = _mm_sub_ps(v22, _mm_mul_ps(v24, v27));
  *topRightInOut = 0i64;
  v28 = _mm_shuffle_ps(bottomLeftInOut->m_quad, bottomRightInOut->m_quad, 238);
  v29 = _mm_shuffle_ps(topLeftInOut->m_quad, (__m128)0i64, 238);
  v30 = _mm_shuffle_ps(bottomLeftInOut->m_quad, bottomRightInOut->m_quad, 68);
  v31 = _mm_shuffle_ps(topLeftInOut->m_quad, (__m128)0i64, 68);
  bottomLeftInOut->m_quad = _mm_shuffle_ps(v30, v31, 136);
  bottomRightInOut->m_quad = _mm_shuffle_ps(v30, v31, 221);
  topLeftInOut->m_quad = _mm_shuffle_ps(v28, v29, 136);
  topRightInOut->m_quad = _mm_shuffle_ps(v28, v29, 221);
}

// File Line: 372
// RVA: 0xC3B400
void __fastcall `anonymous namespace::planeFromPoints(
        hkVector4f *p0,
        hkVector4f *p1,
        hkVector4f *p2,
        hkVector4f *planeOut)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm6
  __m128 v6; // xmm6
  __m128 v7; // xmm6
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm5
  __m128 v12; // xmm2

  v4 = _mm_sub_ps(p1->m_quad, p0->m_quad);
  v5 = _mm_sub_ps(p2->m_quad, p0->m_quad);
  v6 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v4), _mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v5));
  v7 = _mm_shuffle_ps(v6, v6, 201);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v9, (__m128)0i64),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)), _mm_mul_ps(*(__m128 *)_xmm, v10))),
          v7);
  *planeOut = (hkVector4f)v11;
  v12 = _mm_mul_ps(p0->m_quad, v11);
  planeOut->m_quad = _mm_shuffle_ps(
                       v11,
                       _mm_unpackhi_ps(
                         v11,
                         _mm_sub_ps(
                           (__m128)0i64,
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                             _mm_shuffle_ps(v12, v12, 170)))),
                       196);
}

// File Line: 382
// RVA: 0xC3B4C0
void __fastcall `anonymous namespace::planeFromPoints(
        hkVector4f *p0,
        hkVector4f *p1,
        hkVector4f *p2,
        hkVector4f *p3,
        hkVector4f *planeOut)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm6
  __m128 v7; // xmm6
  __m128 v8; // xmm6
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  __m128 v12; // xmm5
  __m128 v13; // xmm2

  v5 = _mm_sub_ps(p2->m_quad, p0->m_quad);
  v6 = _mm_sub_ps(p3->m_quad, p1->m_quad);
  v7 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v5), _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v6));
  v8 = _mm_shuffle_ps(v7, v7, 201);
  v9 = _mm_mul_ps(v8, v8);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_rsqrt_ps(v10);
  v12 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v10, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
              _mm_mul_ps(*(__m128 *)_xmm, v11))),
          v8);
  *planeOut = (hkVector4f)v12;
  v13 = _mm_mul_ps(p0->m_quad, v12);
  planeOut->m_quad = _mm_shuffle_ps(
                       v12,
                       _mm_unpackhi_ps(
                         v12,
                         _mm_sub_ps(
                           (__m128)0i64,
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                             _mm_shuffle_ps(v13, v13, 170)))),
                       196);
}

// File Line: 398
// RVA: 0xC39DE0
void __fastcall hkaiTraversalAnalysisUtils::findClearanceProfile(
        hkVector4f *leftStartIn,
        hkVector4f *rightStartIn,
        hkVector4f *leftEndIn,
        hkVector4f *rightEndIn,
        hkVector4f *up,
        hkSimdFloat32 *maxClearance,
        hkaiIntervalPartition *clearanceOut)
{
  __m128 m_quad; // xmm2
  __m128 v8; // xmm0
  __m128 v10; // xmm6
  __m128 v11; // xmm5
  __m128 v12; // xmm7
  __m128 v13; // xmm14
  __m128 v14; // xmm1
  __m128 v15; // xmm13
  __m128 v16; // xmm15
  __m128 v17; // xmm11
  __m128 v18; // xmm11
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm11
  __m128 v23; // xmm2
  __m128 v24; // xmm11
  __m128 v25; // xmm8
  __m128 v26; // xmm8
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm8
  __m128 v31; // xmm2
  __m128 v32; // xmm8
  __m128 v33; // xmm7
  __m128 v34; // xmm7
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm7
  __m128 v39; // xmm2
  __m128 v40; // xmm7
  __m128 v41; // xmm13
  __m128 v42; // xmm13
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm1
  __m128 v46; // xmm10
  __m128 v47; // xmm13
  __m128 v48; // xmm6
  __m128i inserted; // xmm5
  __m128 v50; // xmm3
  hkaiIntervalPartition vPartition; // [rsp+50h] [rbp-A8h] BYREF
  __m128 v52; // [rsp+60h] [rbp-98h]
  char planeOut[24]; // [rsp+70h] [rbp-88h] BYREF
  hkVector4f uVector; // [rsp+88h] [rbp-70h] BYREF
  hkVector4f p1; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f extremalVector; // [rsp+A8h] [rbp-50h] BYREF
  hkVector4f p3; // [rsp+B8h] [rbp-40h] BYREF
  hkVector4f right; // [rsp+C8h] [rbp-30h] BYREF
  hkVector4f p0; // [rsp+D8h] [rbp-20h] BYREF
  hkVector4f left; // [rsp+E8h] [rbp-10h] BYREF
  hkVector4f p2; // [rsp+F8h] [rbp+0h] BYREF
  hkArrayBase<hkVector4f> clippingPlanes; // [rsp+108h] [rbp+10h] BYREF
  __int128 v63[16]; // [rsp+118h] [rbp+20h] BYREF
  __m128 *v64; // [rsp+248h] [rbp+150h]

  m_quad = rightStartIn->m_quad;
  v8 = rightEndIn->m_quad;
  clippingPlanes.m_size = 6;
  clippingPlanes.m_capacityAndFlags = -2147483642;
  p2.m_quad = v8;
  v10 = leftEndIn->m_quad;
  v52 = _mm_sub_ps(v8, m_quad);
  v11 = _mm_sub_ps(v8, v10);
  v12 = leftStartIn->m_quad;
  v13 = *v64;
  v14 = _mm_sub_ps(m_quad, leftStartIn->m_quad);
  p1.m_quad = m_quad;
  v15 = _mm_shuffle_ps(v13, v13, 201);
  clippingPlanes.m_data = (hkVector4f *)((char *)v63 + 8);
  v16 = _mm_sub_ps(v10, v12);
  v17 = _mm_sub_ps(_mm_mul_ps(v15, v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v13));
  p0.m_quad = v12;
  p3.m_quad = v10;
  v18 = _mm_shuffle_ps(v17, v17, 201);
  v19 = _mm_mul_ps(v18, v18);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  v22 = _mm_mul_ps(
          v18,
          _mm_andnot_ps(
            _mm_cmple_ps(v20, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
              _mm_mul_ps(*(__m128 *)_xmm, v21))));
  v23 = _mm_mul_ps(v22, v12);
  v24 = _mm_shuffle_ps(
          v22,
          _mm_unpackhi_ps(
            v22,
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                _mm_shuffle_ps(v23, v23, 170)))),
          196);
  v25 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v13), _mm_mul_ps(v15, v11));
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
  v31 = _mm_mul_ps(v30, v10);
  v32 = _mm_shuffle_ps(
          v30,
          _mm_unpackhi_ps(
            v30,
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                _mm_shuffle_ps(v31, v31, 170)))),
          196);
  v33 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v13), _mm_mul_ps(v15, v16));
  v34 = _mm_shuffle_ps(v33, v33, 201);
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
  v39 = _mm_mul_ps(v38, leftStartIn->m_quad);
  v40 = _mm_shuffle_ps(
          v38,
          _mm_unpackhi_ps(
            v38,
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                _mm_shuffle_ps(v39, v39, 170)))),
          196);
  v41 = _mm_sub_ps(_mm_mul_ps(v15, v52), _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v13));
  v42 = _mm_shuffle_ps(v41, v41, 201);
  v43 = _mm_mul_ps(v42, v42);
  v44 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)), _mm_shuffle_ps(v43, v43, 170));
  v45 = _mm_rsqrt_ps(v44);
  v46 = rightStartIn->m_quad;
  v47 = _mm_mul_ps(
          v42,
          _mm_andnot_ps(
            _mm_cmple_ps(v44, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v44), v45)),
              _mm_mul_ps(v45, *(__m128 *)_xmm))));
  v48 = _mm_mul_ps(v47, rightStartIn->m_quad);
  `anonymous namespace::planeFromPoints(&p0, &p1, &p2, &p3, (hkVector4f *)planeOut);
  v63[0] = (__int128)v24;
  v63[1] = (__int128)v32;
  v63[2] = (__int128)v40;
  inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v50 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v13, up->m_quad), leftStartIn->m_quad), *(__m128 *)planeOut);
  v63[3] = (__int128)_mm_shuffle_ps(
                       v47,
                       _mm_unpackhi_ps(
                         v47,
                         _mm_sub_ps(
                           (__m128)0i64,
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)),
                             _mm_shuffle_ps(v48, v48, 170)))),
                       196);
  v63[4] = (__int128)_mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 0), *(__m128 *)planeOut);
  v63[5] = (__int128)_mm_shuffle_ps(
                       *(__m128 *)planeOut,
                       _mm_unpackhi_ps(
                         *(__m128 *)planeOut,
                         _mm_sub_ps(
                           (__m128)0i64,
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
                             _mm_shuffle_ps(v50, v50, 170)))),
                       196);
  *(__m128 *)&planeOut[8] = v16;
  left.m_quad = _mm_add_ps(_mm_mul_ps(v16, (__m128)xmmword_141A711B0), leftStartIn->m_quad);
  right.m_quad = _mm_add_ps(_mm_mul_ps(v52, (__m128)xmmword_141A711B0), v46);
  extremalVector.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 64), v13);
  uVector.m_quad = v13;
  hkaiIntervalPartition::hkaiIntervalPartition(&vPartition);
  hkaiGeometrySegmentCaster::findExtremalProfile(
    *(hkaiGeometrySegmentCaster **)&clearanceOut[2].m_intervals.m_size,
    &clippingPlanes,
    &left,
    &right,
    &extremalVector,
    &uVector,
    (hkVector4f *)&planeOut[8],
    (hkaiIntervalPartition *)maxClearance,
    &vPartition);
  vPartition.m_intervals.m_size = 0;
  if ( vPartition.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      vPartition.m_intervals.m_data,
      20 * (vPartition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  vPartition.m_intervals.m_data = 0i64;
  vPartition.m_intervals.m_capacityAndFlags = 0x80000000;
  clippingPlanes.m_size = 0;
  if ( clippingPlanes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      clippingPlanes.m_data,
      16 * clippingPlanes.m_capacityAndFlags);
}

// File Line: 477
// RVA: 0xC3A300
void __fastcall hkaiTraversalAnalysisUtils::filterUnwalkableLandingZones(
        hkVector4f *leftStart,
        hkVector4f *rightStart,
        hkVector4f *leftEnd,
        hkVector4f *rightEnd,
        int startFace,
        int endFace,
        hkaiIntervalPartition *clearZonesOut,
        hkaiTraversalAnalysisContext *context)
{
  hkaiIntervalPartition other; // [rsp+40h] [rbp-18h] BYREF

  hkaiTraversalAnalysisUtils::filterUnwalkableLandingZones_aux(
    leftStart,
    rightStart,
    0,
    startFace,
    clearZonesOut,
    context->m_fromNavMeshInstanceSegmentCaster.m_pntr,
    context);
  if ( clearZonesOut->m_intervals.m_size )
  {
    hkaiIntervalPartition::hkaiIntervalPartition(&other);
    hkaiTraversalAnalysisUtils::filterUnwalkableLandingZones_aux(
      leftEnd,
      rightEnd,
      1u,
      endFace,
      &other,
      context->m_toNavMeshInstanceSegmentCaster.m_pntr,
      context);
    hkaiIntervalPartition::clipNotDefined(clearZonesOut, &other);
    other.m_intervals.m_size = 0;
    if ( other.m_intervals.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        other.m_intervals.m_data,
        20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  }
}

// File Line: 512
// RVA: 0xC3A3F0
void __fastcall hkaiTraversalAnalysisUtils::filterUnwalkableLandingZones_aux(
        hkVector4f *left,
        hkVector4f *right,
        unsigned int castForward,
        int faceIndex,
        hkaiIntervalPartition *clearZonesOut,
        hkaiNavMeshInstanceSegmentCaster *caster,
        hkaiTraversalAnalysisContext *context)
{
  __m128 m_quad; // xmm5
  __m128 v8; // xmm6
  __m128 v9; // xmm1
  hkaiTraversalAnalysisSettings *m_settings; // r10
  __m128 v11; // xmm1
  __m128 v12; // xmm8
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm10
  __m128 v16; // xmm6
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm9
  __m128 v23; // xmm4
  __m128 v24; // xmm9
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm1
  __m128 v28; // xmm1
  float v29; // xmm2_4
  float v30; // xmm7_4
  hkVector4f up; // [rsp+40h] [rbp-98h] BYREF
  hkVector4f displacement; // [rsp+50h] [rbp-88h] BYREF
  hkVector4f rightStartIn; // [rsp+60h] [rbp-78h] BYREF
  hkVector4f leftStartIn; // [rsp+70h] [rbp-68h] BYREF

  m_quad = right->m_quad;
  v8 = left->m_quad;
  v9 = left->m_quad;
  m_settings = context->m_settings;
  up.m_quad = (__m128)context->m_settings->m_up;
  v11 = _mm_mul_ps(v9, up.m_quad);
  v12 = _mm_shuffle_ps(
          (__m128)LODWORD(m_settings->m_characterRadius),
          (__m128)LODWORD(m_settings->m_characterRadius),
          0);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v14 = _mm_mul_ps(m_quad, up.m_quad);
  v15 = _mm_mul_ps((__m128)xmmword_141A710D0, v12);
  v16 = _mm_sub_ps(v8, _mm_mul_ps(v13, up.m_quad));
  v17 = _mm_sub_ps(
          m_quad,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
              _mm_shuffle_ps(v14, v14, 170)),
            up.m_quad));
  v18 = _mm_sub_ps(v17, v16);
  v19 = _mm_mul_ps(v18, v18);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  v22 = _mm_andnot_ps(
          _mm_cmple_ps(v20, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)), _mm_mul_ps(*(__m128 *)_xmm, v21)));
  v23 = _mm_mul_ps(v18, v22);
  v24 = _mm_mul_ps(v22, v20);
  v25 = _mm_mul_ps(v23, v12);
  leftStartIn.m_quad = _mm_sub_ps(v16, v25);
  rightStartIn.m_quad = _mm_add_ps(v25, v17);
  v26 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), up.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(up.m_quad, up.m_quad, 201), v23));
  v27 = _mm_shuffle_ps(v26, v26, 201);
  if ( !castForward )
    v27 = _mm_xor_ps(v27, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64));
  displacement.m_quad = _mm_mul_ps(v27, v15);
  hkaiNavMeshInstanceSegmentCaster::castSegmentAlongSurface(
    caster,
    &leftStartIn,
    &rightStartIn,
    &displacement,
    &up,
    faceIndex,
    clearZonesOut);
  v28 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A710D0, v12), v24);
  v29 = _mm_rcp_ps(v28).m128_f32[0];
  v30 = (float)((float)(2.0 - (float)(v29 * v28.m128_f32[0])) * v29) * v12.m128_f32[0];
  hkaiIntervalPartition::complement(clearZonesOut, 0.0, 1.0);
  hkaiIntervalPartition::contract(clearZonesOut, v30);
  hkaiIntervalPartition::remapX(clearZonesOut, v30, 1.0 - v30, 0.0, 1.0);
}

// File Line: 571
// RVA: 0xC3B240
void __fastcall hkaiTraversalAnalysisUtils::raiseToPlane(
        hkVector4f *p0,
        hkVector4f *p1,
        hkVector4f *p2,
        hkVector4f *p3,
        hkVector4f *up)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm5
  __m128 v7; // xmm7
  __m128 v8; // xmm2
  __m128 v9; // xmm2
  __m128 v10; // xmm4
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm5

  v5 = _mm_sub_ps(p2->m_quad, p0->m_quad);
  v6 = _mm_sub_ps(p3->m_quad, p1->m_quad);
  v7 = _mm_sub_ps(p1->m_quad, p0->m_quad);
  v8 = _mm_mul_ps(v7, v7);
  if ( (float)((float)(_mm_shuffle_ps(v8, v8, 85).m128_f32[0] + _mm_shuffle_ps(v8, v8, 0).m128_f32[0])
             + _mm_shuffle_ps(v8, v8, 170).m128_f32[0]) >= 0.00000011920929 )
  {
    v9 = _mm_mul_ps(v5, v5);
    if ( (float)((float)(_mm_shuffle_ps(v9, v9, 85).m128_f32[0] + _mm_shuffle_ps(v9, v9, 0).m128_f32[0])
               + _mm_shuffle_ps(v9, v9, 170).m128_f32[0]) >= 0.00000011920929 )
    {
      v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v5), _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v6));
      v11 = _mm_shuffle_ps(v10, v10, 201);
      v12 = _mm_mul_ps(up->m_quad, v11);
      v13 = _mm_mul_ps(v11, v7);
      v14 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
              _mm_shuffle_ps(v12, v12, 170));
      v15 = _mm_rcp_ps(v14);
      v16 = _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v15, v14)), v15),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                _mm_shuffle_ps(v13, v13, 170)));
      v17 = _mm_mul_ps(up->m_quad, v16);
      if ( v16.m128_f32[0] <= 0.0 )
      {
        p1->m_quad = _mm_sub_ps(p1->m_quad, v17);
        p3->m_quad = _mm_sub_ps(p3->m_quad, _mm_mul_ps(v16, up->m_quad));
      }
      else
      {
        p0->m_quad = _mm_add_ps(v17, p0->m_quad);
        p2->m_quad = _mm_add_ps(_mm_mul_ps(v16, up->m_quad), p2->m_quad);
      }
    }
  }
}

// File Line: 602
// RVA: 0xC3B380
void __fastcall hkaiTraversalAnalysisUtils::makeTEquation(hkVector4f *left, hkVector4f *right, hkVector4f *tEqnOut)
{
  __m128 v3; // xmm4
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm1
  __m128 v7; // xmm4
  __m128 v8; // xmm3

  v3 = _mm_sub_ps(right->m_quad, left->m_quad);
  v4 = _mm_mul_ps(v3, v3);
  v5 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170));
  v6 = _mm_rcp_ps(v5);
  v7 = _mm_mul_ps(v3, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v5, v6)), v6));
  v8 = _mm_mul_ps(left->m_quad, v7);
  tEqnOut->m_quad = _mm_shuffle_ps(
                      v7,
                      _mm_unpackhi_ps(
                        v7,
                        _mm_sub_ps(
                          (__m128)0i64,
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)),
                            _mm_shuffle_ps(v8, v8, 170)))),
                      196);
}


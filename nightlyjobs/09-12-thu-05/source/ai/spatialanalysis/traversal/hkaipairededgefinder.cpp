// File Line: 29
// RVA: 0xC3BAF0
void __fastcall hkaiPairedEdgeFinder::hkaiPairedEdgeFinder(hkaiPairedEdgeFinder *this, hkaiNavMeshInstance *fromNavMeshInstance, hkaiPairedEdgeFinder::AccelerationData *fromAccelerationData, hkaiNavMeshInstance *toNavMeshInstance, hkaiPairedEdgeFinder::AccelerationData *toAccelerationData)
{
  hkaiNavMeshInstance *v5; // rdi
  hkaiPairedEdgeFinder::AccelerationData *v6; // rsi
  hkaiNavMeshInstance *v7; // rbp
  hkaiPairedEdgeFinder *v8; // rbx

  v5 = toNavMeshInstance;
  v6 = fromAccelerationData;
  v7 = fromNavMeshInstance;
  v8 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPairedEdgeFinder::`vftable';
  if ( fromNavMeshInstance )
    hkReferencedObject::addReference((hkReferencedObject *)&fromNavMeshInstance->vfptr);
  v8->m_fromNavMeshInstance.m_pntr = v7;
  if ( v6 )
    hkReferencedObject::addReference((hkReferencedObject *)&v6->vfptr);
  v8->m_fromAccelerationData.m_pntr = v6;
  if ( v5 )
    hkReferencedObject::addReference((hkReferencedObject *)&v5->vfptr);
  v8->m_toNavMeshInstance.m_pntr = v5;
  if ( toAccelerationData )
    hkReferencedObject::addReference((hkReferencedObject *)&toAccelerationData->vfptr);
  v8->m_toAccelerationData.m_pntr = toAccelerationData;
}

// File Line: 33
// RVA: 0xC3BB90
void __fastcall hkaiPairedEdgeFinder::~hkaiPairedEdgeFinder(hkaiPairedEdgeFinder *this)
{
  hkaiPairedEdgeFinder *v1; // rbx
  hkaiPairedEdgeFinder::AccelerationData *v2; // rcx
  hkReferencedObject *v3; // rcx
  hkReferencedObject *v4; // rcx
  hkReferencedObject *v5; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPairedEdgeFinder::`vftable';
  v2 = this->m_toAccelerationData.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_toAccelerationData.m_pntr = 0i64;
  v3 = (hkReferencedObject *)&v1->m_toNavMeshInstance.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_toNavMeshInstance.m_pntr = 0i64;
  v4 = (hkReferencedObject *)&v1->m_fromAccelerationData.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v1->m_fromAccelerationData.m_pntr = 0i64;
  v5 = (hkReferencedObject *)&v1->m_fromNavMeshInstance.m_pntr->vfptr;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  v1->m_fromNavMeshInstance.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 42
// RVA: 0xC3C8E0
void __fastcall hkaiPairedEdgeFinder::buildPairedEdgeAabb(hkVector4f *left, hkVector4f *right, hkaiPairedEdgeFinder::PairedEdgeSettings *settings, hkAabb *aabbOut)
{
  __m128 v4; // xmm5
  __m128 v5; // xmm0
  float v6; // [rsp+8h] [rbp+8h]

  v6 = fmaxf(
         COERCE_FLOAT((unsigned int)(2 * LODWORD(settings->m_minHorizontalDelta)) >> 1),
         COERCE_FLOAT((unsigned int)(2 * LODWORD(settings->m_maxHorizontalDelta)) >> 1));
  v4 = _mm_mul_ps(
         _mm_shuffle_ps((__m128)LODWORD(v6), (__m128)LODWORD(v6), 0),
         _mm_sub_ps(query.m_quad, settings->m_up.m_quad));
  v5 = _mm_add_ps(
         _mm_mul_ps(
           _mm_shuffle_ps((__m128)LODWORD(settings->m_minHeightDelta), (__m128)LODWORD(settings->m_minHeightDelta), 0),
           settings->m_up.m_quad),
         _mm_min_ps(left->m_quad, right->m_quad));
  aabbOut->m_max.m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(settings->m_maxHeightDelta),
                                  (__m128)LODWORD(settings->m_maxHeightDelta),
                                  0),
                                settings->m_up.m_quad),
                              _mm_max_ps(left->m_quad, right->m_quad)),
                            v4);
  aabbOut->m_min.m_quad = _mm_sub_ps(v5, v4);
}

// File Line: 72
// RVA: 0xC3CB10
bool __fastcall hkaiPairedEdgeFinder::edgeAnglesMatch(hkVector4f *startLeft, hkVector4f *startRight, hkVector4f *endLeft, hkVector4f *endRight, float cosMaxHorizontalAngle)
{
  bool result; // al
  __m128 v6; // xmm8
  __m128 v7; // xmm10
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm7
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm9
  __m128 v16; // xmm8
  float v17; // xmm1_4

  result = 0;
  v6 = _mm_sub_ps(startRight->m_quad, startLeft->m_quad);
  v7 = _mm_sub_ps(endRight->m_quad, endLeft->m_quad);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_andnot_ps(
          _mm_cmpleps(v9, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)), _mm_mul_ps(*(__m128 *)_xmm, v10)),
            v9));
  v12 = _mm_mul_ps(v6, v6);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  v15 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v13, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                _mm_mul_ps(*(__m128 *)_xmm, v14)),
              v13)),
          v11);
  if ( v15.m128_f32[0] >= 0.00000011920929 )
  {
    v16 = _mm_mul_ps(v6, v7);
    LODWORD(v17) = (unsigned __int128)_mm_rcp_ps(v15);
    result = (float)((float)((float)(2.0 - (float)(v17 * v15.m128_f32[0])) * v17)
                   * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 170)))) > COERCE_FLOAT(
                                                                               _mm_shuffle_ps(
                                                                                 (__m128)LODWORD(cosMaxHorizontalAngle),
                                                                                 (__m128)LODWORD(cosMaxHorizontalAngle),
                                                                                 0));
  }
  return result;
}

// File Line: 99
// RVA: 0xC3CC70
signed __int64 __fastcall hkaiPairedEdgeFinder::matchEdgeEnds(hkVector4f *startLeftInOut, hkVector4f *startRightInOut, hkVector4f *endLeftInOut, hkVector4f *endRightInOut, hkVector4f *up)
{
  __m128 v5; // xmm7
  __m128 v6; // xmm8
  __m128 v7; // xmm10
  __m128 v8; // xmm1
  __m128 v9; // xmm11
  __m128 v10; // xmm6
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm6
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm5
  __m128 v21; // xmm3
  signed __int64 result; // rax
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm5
  __m128 v26; // xmm4
  __m128 v27; // xmm0
  __m128 v28; // xmm2
  __m128 v29; // xmm5
  __m128 v30; // xmm0
  __m128 v31; // xmm4
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  __m128 v35; // xmm4
  __m128 v36; // xmm2
  __m128 v37; // xmm4
  __m128 v38; // xmm3
  __m128 v39; // xmm5
  __m128 v40; // xmm4
  __m128 v41; // xmm3
  __m128 v42; // xmm0
  __m128 v43; // xmm2

  v5 = startLeftInOut->m_quad;
  v6 = endLeftInOut->m_quad;
  v7 = _mm_sub_ps(startRightInOut->m_quad, startLeftInOut->m_quad);
  v8 = _mm_mul_ps(v7, up->m_quad);
  v9 = _mm_sub_ps(endRightInOut->m_quad, endLeftInOut->m_quad);
  v10 = _mm_sub_ps(
          v7,
          _mm_mul_ps(
            _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170)),
            up->m_quad));
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  v14 = _mm_mul_ps(v9, up->m_quad);
  v15 = _mm_mul_ps(
          v10,
          _mm_andnot_ps(
            _mm_cmpleps(v12, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
              _mm_mul_ps(v13, *(__m128 *)_xmm))));
  v16 = _mm_sub_ps(
          v9,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
              _mm_shuffle_ps(v14, v14, 170)),
            up->m_quad));
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  v20 = _mm_add_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmpleps(v18, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                _mm_mul_ps(v19, *(__m128 *)_xmm))),
            v16),
          v15);
  v21 = _mm_mul_ps(v20, v20);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 170))) <= 0.00000011920929 )
    return 0i64;
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v24 = _mm_rsqrt_ps(v23);
  v25 = _mm_mul_ps(
          v20,
          _mm_andnot_ps(
            _mm_cmpleps(v23, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
              _mm_mul_ps(v24, *(__m128 *)_xmm))));
  v26 = v25;
  v27 = v25;
  v28 = v25;
  v29 = _mm_mul_ps(v25, endRightInOut->m_quad);
  v30 = _mm_mul_ps(v27, startRightInOut->m_quad);
  v31 = _mm_mul_ps(v26, v5);
  v32 = _mm_mul_ps(v28, v6);
  v33 = _mm_shuffle_ps(v31, v30, 68);
  v34 = _mm_shuffle_ps(v32, v29, 68);
  v35 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v31, v30, 238), _mm_shuffle_ps(v32, v29, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v33, v34, 221), _mm_shuffle_ps(v33, v34, 136)));
  v36 = _mm_shuffle_ps(v35, v35, 160);
  v37 = _mm_shuffle_ps(v35, v35, 245);
  v38 = _mm_max_ps(_mm_shuffle_ps(v36, v36, 170), _mm_max_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)));
  v39 = _mm_min_ps(_mm_shuffle_ps(v37, v37, 170), _mm_min_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)));
  if ( v38.m128_f32[0] >= v39.m128_f32[0] )
    return 0i64;
  v40 = _mm_sub_ps(v37, v36);
  v41 = _mm_unpacklo_ps(v38, v39);
  result = 1i64;
  v42 = _mm_rcp_ps(v40);
  v43 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v40, v42)), v42),
          _mm_sub_ps(_mm_movelh_ps(v41, v41), v36));
  startLeftInOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v43, v43, 0), v7), v5);
  startRightInOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v43, v43, 85), v7), v5);
  endLeftInOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v43, v43, 170), v9), v6);
  endRightInOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v43, v43, 255), v9), v6);
  return result;
}

// File Line: 161
// RVA: 0xC3D4E0
hkSimdFloat32 *__fastcall `anonymous namespace'::cosAngleAboutAxis(hkSimdFloat32 *result, hkVector4f *a, hkVector4f *b, hkVector4f *u)
{
  hkSimdFloat32 *v4; // rax
  __m128 v5; // xmm1
  __m128 v6; // xmm6
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm7
  __m128 v11; // xmm4
  __m128 v12; // xmm3

  v4 = result;
  v5 = _mm_mul_ps(u->m_quad, a->m_quad);
  v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v7 = _mm_mul_ps(b->m_quad, u->m_quad);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_mul_ps(b->m_quad, a->m_quad);
  v10 = _mm_mul_ps(a->m_quad, a->m_quad);
  v11 = _mm_mul_ps(b->m_quad, b->m_quad);
  v12 = _mm_mul_ps(
          _mm_sub_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
              _mm_shuffle_ps(v11, v11, 170)),
            _mm_mul_ps(v8, v8)),
          _mm_sub_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
              _mm_shuffle_ps(v10, v10, 170)),
            _mm_mul_ps(v6, v6)));
  result->m_real = _mm_mul_ps(
                     _mm_andnot_ps(_mm_cmpleps(v12, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v12))),
                     _mm_sub_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)),
                         _mm_shuffle_ps(v9, v9, 170)),
                       _mm_mul_ps(v8, v6)));
  return v4;
}

// File Line: 183
// RVA: 0xC3CF70
signed __int64 __fastcall hkaiPairedEdgeFinder::slopeAnglesMatch(hkVector4f *startLeft, hkVector4f *startRight, hkVector4f *endLeft, hkVector4f *endRight, hkVector4f *up, float cosMaxDeltaAngle)
{
  __m128 v6; // xmm1
  __m128 v7; // xmm1
  __m128 v8; // xmm5
  __m128 v9; // xmm5
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  __m128 v13; // xmm0
  signed __int64 v14; // rax
  hkVector4f u; // [rsp+20h] [rbp-48h]
  hkVector4f b; // [rsp+30h] [rbp-38h]
  hkVector4f a; // [rsp+40h] [rbp-28h]
  hkSimdFloat32 result; // [rsp+50h] [rbp-18h]

  v6 = _mm_sub_ps(endRight->m_quad, endLeft->m_quad);
  a.m_quad = _mm_sub_ps(startRight->m_quad, startLeft->m_quad);
  b.m_quad = v6;
  v7 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v6, a.m_quad), (__m128)xmmword_141A711B0), a.m_quad);
  v8 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), up->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(up->m_quad, up->m_quad, 201), v7));
  v9 = _mm_shuffle_ps(v8, v8, 201);
  v10 = _mm_mul_ps(v9, v9);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_rsqrt_ps(v11);
  u.m_quad = _mm_mul_ps(
               v9,
               _mm_andnot_ps(
                 _mm_cmpleps(v11, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                   _mm_mul_ps(*(__m128 *)_xmm, v12))));
  v13 = `anonymous namespace'::cosAngleAboutAxis(&result, &a, &b, &u)->m_real;
  v14 = 0i64;
  if ( v13.m128_f32[0] > COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(cosMaxDeltaAngle), (__m128)LODWORD(cosMaxDeltaAngle), 0)) )
    v14 = 1i64;
  return v14;
}

// File Line: 199
// RVA: 0xC3D060
signed __int64 __fastcall hkaiPairedEdgeFinder::filterEdgeDistances(hkVector4f *startLeftInOut, hkVector4f *startRightInOut, hkVector4f *endLeftInOut, hkVector4f *endRightInOut, hkaiPairedEdgeFinder::PairedEdgeSettings *settings)
{
  __m128 v5; // xmm10
  __m128 v6; // xmm5
  __m128 v7; // xmm13
  __m128 v8; // xmm14
  __m128 v9; // xmm1
  __m128 v10; // xmm7
  __m128 v11; // xmm7
  __m128 v12; // xmm11
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm9
  __m128 v16; // xmm5
  __m128 v17; // xmm10
  __m128 v18; // xmm1
  __m128 v19; // xmm5
  __m128 v20; // xmm1
  __m128i v21; // xmm8
  __m128 v22; // xmm4
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  __m128 v26; // xmm10
  __m128 v27; // xmm8
  __m128 v28; // xmm7
  __m128 v29; // xmm3
  __m128 v30; // xmm1
  __m128 v31; // xmm7
  __m128 v32; // xmm3
  __m128 v33; // xmm4
  __m128i v34; // xmm7
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  __m128 v37; // xmm7
  __m128 v38; // xmm5
  signed __int64 result; // rax
  __m128 v40; // xmm1
  __m128 v41; // xmm5
  __m128 v42; // xmm0
  __m128 v43; // xmm1
  __m128 v44; // xmm0
  __m128 v45; // xmm2
  __m128 v46; // xmm12
  hkVector4f v47; // xmm1
  __m128 v48; // [rsp+0h] [rbp-B8h]

  v48 = endLeftInOut->m_quad;
  v5 = _mm_sub_ps(endRightInOut->m_quad, startRightInOut->m_quad);
  v6 = _mm_sub_ps(endLeftInOut->m_quad, startLeftInOut->m_quad);
  v7 = _mm_sub_ps(startRightInOut->m_quad, startLeftInOut->m_quad);
  v8 = _mm_sub_ps(endRightInOut->m_quad, endLeftInOut->m_quad);
  v9 = _mm_mul_ps(v6, settings->m_up.m_quad);
  v10 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), settings->m_up.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(settings->m_up.m_quad, settings->m_up.m_quad, 201), v7));
  v11 = _mm_shuffle_ps(v10, v10, 201);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v13 = _mm_mul_ps(v5, settings->m_up.m_quad);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_sub_ps(v14, v12);
  v16 = _mm_sub_ps(v6, _mm_mul_ps(settings->m_up.m_quad, v12));
  v17 = _mm_sub_ps(v5, _mm_mul_ps(settings->m_up.m_quad, v14));
  v18 = v16;
  v19 = _mm_mul_ps(v16, v16);
  v20 = _mm_mul_ps(v18, v11);
  v21 = (__m128i)_mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                   _mm_shuffle_ps(v20, v20, 170));
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v23 = _mm_rsqrt_ps(v22);
  v24 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)), _mm_mul_ps(v23, *(__m128 *)_xmm));
  v25 = _mm_mul_ps(v17, v11);
  v26 = _mm_mul_ps(v17, v17);
  v27 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32(v21, 0x1Fu), 0x1Fu),
          _mm_andnot_ps(_mm_cmpleps(v22, (__m128)0i64), _mm_mul_ps(v24, v22)));
  v28 = (__m128)_mm_slli_epi32(
                  _mm_srli_epi32(
                    (__m128i)_mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                               _mm_shuffle_ps(v25, v25, 170)),
                    0x1Fu),
                  0x1Fu);
  v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)), _mm_shuffle_ps(v26, v26, 170));
  v30 = _mm_rsqrt_ps(v29);
  v31 = _mm_sub_ps(
          _mm_xor_ps(
            v28,
            _mm_andnot_ps(
              _mm_cmpleps(v29, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                  _mm_mul_ps(v30, *(__m128 *)_xmm)),
                v29))),
          v27);
  v32 = _mm_sub_ps(
          _mm_unpacklo_ps(
            _mm_unpacklo_ps(
              (__m128)LODWORD(settings->m_maxHorizontalDelta),
              (__m128)LODWORD(settings->m_maxHeightDelta)),
            _mm_unpacklo_ps(
              (__m128)LODWORD(settings->m_minHorizontalDelta),
              (__m128)LODWORD(settings->m_minHeightDelta))),
          _mm_movelh_ps(_mm_unpacklo_ps(v27, v27), _mm_unpacklo_ps(v12, v12)));
  v33 = _mm_cmpltps((__m128)0i64, v32);
  v34 = (__m128i)_mm_movelh_ps(_mm_unpacklo_ps(v31, v31), _mm_unpacklo_ps(v15, v15));
  v35 = _mm_div_ps(v32, (__m128)v34);
  v36 = _mm_cmpltps((__m128)v34, (__m128)0i64);
  v37 = _mm_cmpleps((__m128)_mm_srli_epi32(_mm_slli_epi32(v34, 1u), 1u), *(__m128 *)&epsilon);
  v38 = _mm_or_ps(
          _mm_andnot_ps(v37, _mm_or_ps(_mm_and_ps(_mm_shuffle_ps(v35, v35, 177), v36), _mm_andnot_ps(v36, v35))),
          _mm_and_ps(_mm_or_ps(_mm_andnot_ps(v33, aabbOut.m_quad), _mm_and_ps(v33, query.m_quad)), v37));
  result = 0i64;
  v40 = _mm_max_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 255));
  v41 = _mm_min_ps(_mm_shuffle_ps(v38, v38, 0), _mm_shuffle_ps(v38, v38, 170));
  v42 = _mm_cmpltps(v40, query.m_quad);
  v43 = _mm_or_ps(_mm_and_ps(v40, v42), _mm_andnot_ps(v42, query.m_quad));
  v44 = _mm_cmpltps(v41, query.m_quad);
  v45 = _mm_max_ps((__m128)0i64, v43);
  v46 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v41, v44), _mm_andnot_ps(v44, query.m_quad)));
  v47.m_quad = _mm_add_ps(_mm_mul_ps(v46, v7), startLeftInOut->m_quad);
  startLeftInOut->m_quad = _mm_add_ps(_mm_mul_ps(v45, v7), startLeftInOut->m_quad);
  if ( v45.m128_f32[0] < v46.m128_f32[0] )
    result = 1i64;
  *startRightInOut = (hkVector4f)v47.m_quad;
  endLeftInOut->m_quad = _mm_add_ps(_mm_mul_ps(v45, v8), v48);
  endRightInOut->m_quad = _mm_add_ps(_mm_mul_ps(v46, v8), v48);
  return result;
}

// File Line: 291
// RVA: 0xC3C990
__int64 __fastcall hkaiPairedEdgeFinder::filterPairedEdge(hkVector4f *origStartLeft, hkVector4f *origStartRight, hkVector4f *origEndLeft, hkVector4f *origEndRight, hkaiPairedEdgeFinder::PairedEdgeSettings *settings, hkVector4f *filteredStartLeft, hkVector4f *filteredStartRight, hkVector4f *filteredEndLeft, hkVector4f *filteredEndRight)
{
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  float cosMaxHorizontalAngle; // ST20_4
  unsigned int v14; // ecx
  __m128 v15; // xmm5
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm4
  __m128 v20; // xmm0
  float v21; // xmm2_4
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  hkVector4f startRight; // [rsp+30h] [rbp-50h]
  hkVector4f startLeft; // [rsp+40h] [rbp-40h]
  hkVector4f endLeft; // [rsp+50h] [rbp-30h]
  hkVector4f endRight; // [rsp+60h] [rbp-20h]

  v9 = origStartRight->m_quad;
  _mm_store_si128((__m128i *)&startLeft, (__m128i)origStartLeft->m_quad);
  v10 = origEndLeft->m_quad;
  _mm_store_si128((__m128i *)&startRight, (__m128i)v9);
  v11 = origEndRight->m_quad;
  _mm_store_si128((__m128i *)&endLeft, (__m128i)v10);
  cosMaxHorizontalAngle = settings->m_cosMaxPlanarAngle;
  _mm_store_si128((__m128i *)&endRight, (__m128i)v11);
  if ( !hkaiPairedEdgeFinder::edgeAnglesMatch(&startLeft, &startRight, &endLeft, &endRight, cosMaxHorizontalAngle)
    || !hkaiPairedEdgeFinder::matchEdgeEnds(&startLeft, &startRight, &endLeft, &endRight, &settings->m_up)
    || !hkaiPairedEdgeFinder::slopeAnglesMatch(
          &startLeft,
          &startRight,
          &endLeft,
          &endRight,
          &settings->m_up,
          settings->m_cosMaxDeltaSlopeAngle) )
  {
    return 0i64;
  }
  v14 = hkaiPairedEdgeFinder::filterEdgeDistances(&startLeft, &startRight, &endLeft, &endRight, settings);
  v15 = startRight.m_quad;
  v16 = _mm_sub_ps(startRight.m_quad, startLeft.m_quad);
  v17 = _mm_mul_ps(settings->m_up.m_quad, v16);
  v18 = _mm_sub_ps(
          v16,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170)),
            settings->m_up.m_quad));
  v19 = _mm_mul_ps(v18, v18);
  v20 = _mm_shuffle_ps(v19, v19, 0);
  v21 = COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 85)) + v20.m128_f32[0];
  v20.m128_f32[0] = settings->m_minLength * settings->m_minLength;
  if ( (float)(v21 + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 170))) < COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 0)) )
    return 0i64;
  v22 = endLeft.m_quad;
  v23 = endRight.m_quad;
  *filteredStartLeft = (hkVector4f)startLeft.m_quad;
  *filteredStartRight = (hkVector4f)v15;
  *filteredEndLeft = (hkVector4f)v22;
  *filteredEndRight = (hkVector4f)v23;
  return v14;
}

// File Line: 375
// RVA: 0xC3D710
signed __int64 __fastcall hkaiPairedEdgeFinder::PairedEdgeQuery::processLeaf(hkaiPairedEdgeFinder::PairedEdgeQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  hkArray<hkaiPairedEdgeFinder::AccelerationData::BoundaryEdge,hkContainerHeapAllocator> *v3; // rax
  hkaiPairedEdgeFinder::PairedEdgeQuery *v4; // rdi
  hkaiPairedEdgeFinder::AccelerationData::BoundaryEdge v5; // rbx
  hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> *v6; // rsi
  __int64 v7; // rcx
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  signed __int64 v10; // rdx
  int v11; // eax
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  hkVector4f edgeB; // [rsp+50h] [rbp-68h]
  hkVector4f edgeA; // [rsp+60h] [rbp-58h]
  hkVector4f filteredStartLeft; // [rsp+70h] [rbp-48h]
  hkVector4f filteredStartRight; // [rsp+80h] [rbp-38h]
  hkVector4f filteredEndLeft; // [rsp+90h] [rbp-28h]
  hkVector4f filteredEndRight; // [rsp+A0h] [rbp-18h]
  hkaiPairedEdgeFinder::AccelerationData::BoundaryEdge v21; // [rsp+C0h] [rbp+8h]

  v3 = this->m_toBoundaryEdges;
  v4 = this;
  v5 = v3->m_data[leafKey];
  v21 = v3->m_data[leafKey];
  if ( !this->m_isWithinSameSection.m_bool || v5.m_edgeIndex != this->m_startEdgeIndex )
  {
    hkaiNavMeshInstance::getEdgePoints(this->m_toNavMeshInstance, v5.m_edgeIndex, &edgeA, &edgeB);
    if ( (unsigned int)hkaiPairedEdgeFinder::filterPairedEdge(
                         &v4->m_startLeft,
                         &v4->m_startRight,
                         &edgeA,
                         &edgeB,
                         v4->m_settings,
                         &filteredStartLeft,
                         &filteredStartRight,
                         &filteredEndLeft,
                         &filteredEndRight) )
    {
      v6 = v4->m_pairsOut;
      if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4->m_pairsOut, 80);
      v7 = v6->m_size;
      v8 = filteredStartLeft.m_quad;
      v9 = filteredStartRight.m_quad;
      v6->m_size = v7 + 1;
      v10 = (signed __int64)&v6->m_data[v7];
      *(_DWORD *)(v10 + 64) = v4->m_startFaceIndex;
      v11 = v4->m_startEdgeIndex;
      *(_DWORD *)(v10 + 72) = v5.m_faceIndex;
      *(__m128 *)(v10 + 16) = v8;
      v12 = filteredEndLeft.m_quad;
      *(__m128 *)v10 = v9;
      *(_DWORD *)(v10 + 68) = v11;
      v13 = filteredEndRight.m_quad;
      *(__m128 *)(v10 + 48) = v12;
      *(_DWORD *)(v10 + 76) = v21.m_edgeIndex;
      *(__m128 *)(v10 + 32) = v13;
    }
  }
  return 1i64;
}

// File Line: 439
// RVA: 0xC3BC30
void __fastcall hkaiPairedEdgeFinder::findEdgePairs(hkaiPairedEdgeFinder *this, hkaiPairedEdgeFinder::PairedEdgeSettings *settings, hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> *pairsOut)
{
  bool v3; // zf
  __int128 v4; // xmm1
  __int128 v5; // xmm0
  hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> *v6; // rdi
  hkaiPairedEdgeFinder::PairedEdgeSettings *v7; // rbx
  hkaiPairedEdgeFinder *v8; // rsi
  __int128 v9; // xmm1
  hkaiPairedEdgeFinder::PairedEdgeSettings settingsIn; // [rsp+20h] [rbp-48h]

  pairsOut->m_size = 0;
  v3 = settings->m_findInternalStarts.m_bool == 0;
  v4 = *(_OWORD *)&settings->m_minLength;
  settingsIn.m_up = settings->m_up;
  v5 = *(_OWORD *)&settings->m_maxHorizontalDelta;
  v6 = pairsOut;
  v7 = settings;
  v8 = this;
  *(_OWORD *)&settingsIn.m_minLength = v4;
  v9 = *(_OWORD *)&settings->m_matchAngles.m_bool;
  *(_OWORD *)&settingsIn.m_maxHorizontalDelta = v5;
  *(_OWORD *)&settingsIn.m_matchAngles.m_bool = v9;
  if ( !v3 || settings->m_findInternalEnds.m_bool )
    settingsIn.m_minHorizontalDelta = FLOAT_0_0099999998;
  hkaiPairedEdgeFinder::findExternalPairs(this, &settingsIn, pairsOut);
  if ( v7->m_findInternalStarts.m_bool )
    hkaiPairedEdgeFinder::findInternalStarts(v8, v7, v6);
  if ( v7->m_findInternalEnds.m_bool )
    hkaiPairedEdgeFinder::findInternalEnds(v8, v7, v6);
}

// File Line: 465
// RVA: 0xC3B6F0
hkaiPairedEdgeFinder::AccelerationData *__fastcall hkaiPairedEdgeFinder::buildAccelerationData(hkaiNavMeshInstance *navMeshInstance, hkaiNavMeshInstanceSegmentCaster::AccelerationData *segmentCasterAccelerationData)
{
  hkaiNavMeshInstance *v2; // rdi
  hkaiNavMeshInstanceSegmentCaster::AccelerationData *v3; // rsi
  _QWORD **v4; // rax
  __int64 v5; // rax
  unsigned int v6; // ebx
  __int64 v7; // r14
  hkReferencedObject *v8; // rcx
  int index; // er15
  __int64 v10; // rax
  __int64 v11; // r13
  hkResult *v12; // rax
  hkaiNavMesh::Face *v13; // rax
  int v14; // esi
  int v15; // er12
  hkaiNavMesh::Face *v16; // r13
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v18; // rdx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v19; // r8
  int v20; // ebp
  hkaiNavMesh::Edge *v21; // rax
  bool v22; // zf
  int v23; // ecx
  __int64 v24; // rdx
  int *v25; // r8
  _QWORD **v26; // rax
  hkcdDynamicAabbTree *v27; // rax
  hkcdDynamicAabbTree *v28; // rax
  hkcdDynamicAabbTree *v29; // rsi
  hkReferencedObject *v30; // rcx
  __int64 v31; // r13
  __int64 j; // rsi
  hkaiNavMesh::Edge *v33; // rax
  signed int v34; // edx
  __int64 v35; // rcx
  __m128 *v36; // rcx
  __m128 v37; // xmm4
  __m128 v38; // xmm5
  __int64 v39; // rax
  __m128 v40; // xmm6
  __m128 v41; // xmm7
  __m128 v42; // xmm3
  __m128 *v43; // rax
  hkcdDynamicAabbTree *v44; // rcx
  __m128 v45; // xmm2
  __int64 i; // [rsp+30h] [rbp-98h]
  hkAabb aabb; // [rsp+40h] [rbp-88h]
  hkResult result; // [rsp+D0h] [rbp+8h]
  char v50; // [rsp+D8h] [rbp+10h]
  __int64 v51; // [rsp+E0h] [rbp+18h]
  hkaiNavMesh::Face *v52; // [rsp+E8h] [rbp+20h]

  v2 = navMeshInstance;
  v3 = segmentCasterAccelerationData;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 48i64);
  v6 = 0;
  v7 = v5;
  if ( v5 )
  {
    *(_DWORD *)(v5 + 8) = 0x1FFFF;
    *(_QWORD *)v5 = &hkaiPairedEdgeFinder::AccelerationData::`vftable';
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_DWORD *)(v5 + 24) = 0;
    *(_DWORD *)(v5 + 28) = 2147483648;
    *(_QWORD *)(v5 + 32) = 0i64;
    *(_QWORD *)(v5 + 40) = 0i64;
  }
  else
  {
    v7 = 0i64;
  }
  if ( v3 )
    hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
  v8 = *(hkReferencedObject **)(v7 + 40);
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  *(_QWORD *)(v7 + 40) = v3;
  index = 0;
  v10 = v2->m_numOriginalFaces + v2->m_ownedFaces.m_size;
  v11 = 0i64;
  v51 = 0i64;
  for ( i = v10; v11 < i; v51 = v11 )
  {
    if ( v2->m_faceFlags.m_size )
    {
      v12 = &result;
      LOBYTE(result.m_enum) = v2->m_faceFlags.m_data[v11].m_storage;
    }
    else
    {
      v50 = 0;
      v12 = (hkResult *)&v50;
    }
    if ( !(v12->m_enum & 1) )
    {
      v13 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__19(
              v2->m_originalFaces,
              v2->m_numOriginalFaces,
              &v2->m_instancedFaces,
              &v2->m_ownedFaces,
              &v2->m_faceMap,
              index);
      v14 = 0;
      v15 = v13->m_numEdges;
      v52 = v13;
      if ( v15 > 0 )
      {
        v16 = v52;
        instanceMap = &v2->m_edgeMap;
        v18 = &v2->m_ownedEdges;
        v19 = &v2->m_instancedEdges;
        do
        {
          v20 = v14 + v16->m_startEdgeIndex;
          v21 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__21(
                  v2->m_originalEdges,
                  v2->m_numOriginalEdges,
                  v19,
                  v18,
                  instanceMap,
                  v14 + v16->m_startEdgeIndex);
          v22 = v21->m_oppositeEdge == -1;
          aabb.m_min.m_quad.m128_u64[0] = *(_QWORD *)&v21->m_a;
          v23 = v21->m_oppositeFace;
          aabb.m_max.m_quad.m128_i32[0] = *(_DWORD *)&v21->m_flags.m_storage;
          aabb.m_min.m_quad.m128_i32[3] = v23;
          if ( v22 )
          {
            if ( *(_DWORD *)(v7 + 24) == (*(_DWORD *)(v7 + 28) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                (void *)(v7 + 16),
                8);
            v24 = *(signed int *)(v7 + 24);
            v25 = (int *)(*(_QWORD *)(v7 + 16) + 8 * v24);
            *(_DWORD *)(v7 + 24) = v24 + 1;
            *v25 = index;
            v25[1] = v20;
          }
          ++v14;
          instanceMap = &v2->m_edgeMap;
          v18 = &v2->m_ownedEdges;
          v19 = &v2->m_instancedEdges;
        }
        while ( v14 < v15 );
        v11 = v51;
        v6 = 0;
      }
    }
    ++v11;
    ++index;
  }
  v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (hkcdDynamicAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v26[11] + 8i64))(v26[11], 32i64);
  if ( v27 )
  {
    hkcdDynamicAabbTree::hkcdDynamicAabbTree(v27);
    v29 = v28;
  }
  else
  {
    v29 = 0i64;
  }
  v30 = *(hkReferencedObject **)(v7 + 32);
  if ( v30 && v30 != (hkReferencedObject *)v29 )
    hkReferencedObject::removeReference(v30);
  *(_QWORD *)(v7 + 32) = v29;
  hkcdDynamicAabbTree::reserveLeaves(v29, &result, *(_DWORD *)(v7 + 24));
  v31 = *(signed int *)(v7 + 24);
  for ( j = 0i64; j < v31; ++v6 )
  {
    v33 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__21(
            v2->m_originalEdges,
            v2->m_numOriginalEdges,
            &v2->m_instancedEdges,
            &v2->m_ownedEdges,
            &v2->m_edgeMap,
            *(_DWORD *)(*(_QWORD *)(v7 + 16) + 8 * j + 4));
    v34 = v2->m_numOriginalVertices;
    v35 = v33->m_a;
    if ( (signed int)v35 >= v34 )
      v36 = &v2->m_ownedVertices.m_data[(signed int)v35 - v34].m_quad;
    else
      v36 = &v2->m_originalVertices[v35].m_quad;
    v37 = v2->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
    v38 = v2->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
    v39 = v33->m_b;
    v40 = v2->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
    v41 = v2->m_referenceFrame.m_transform.m_translation.m_quad;
    v42 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v36, *v36, 0), v38),
                _mm_mul_ps(_mm_shuffle_ps(*v36, *v36, 85), v37)),
              _mm_mul_ps(_mm_shuffle_ps(*v36, *v36, 170), v40)),
            v41);
    if ( (signed int)v39 >= v34 )
      v43 = &v2->m_ownedVertices.m_data[(signed int)v39 - v34].m_quad;
    else
      v43 = &v2->m_originalVertices[v39].m_quad;
    v44 = *(hkcdDynamicAabbTree **)(v7 + 32);
    v45 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v43, *v43, 85), v37),
                _mm_mul_ps(_mm_shuffle_ps(*v43, *v43, 0), v38)),
              _mm_mul_ps(_mm_shuffle_ps(*v43, *v43, 170), v40)),
            v41);
    aabb.m_min.m_quad = _mm_min_ps(v42, v45);
    aabb.m_max.m_quad = _mm_max_ps(v42, v45);
    hkcdDynamicAabbTree::insert(v44, &aabb, v6);
    ++j;
  }
  hkcdDynamicAabbTree::rebuild(*(hkcdDynamicAabbTree **)(v7 + 32));
  return (hkaiPairedEdgeFinder::AccelerationData *)v7;
}

// File Line: 511
// RVA: 0xC3BCE0
void __fastcall hkaiPairedEdgeFinder::findExternalPairs(hkaiPairedEdgeFinder *this, hkaiPairedEdgeFinder::PairedEdgeSettings *settingsIn, hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> *pairsOut)
{
  hkVector4f v3; // xmm0
  hkaiPairedEdgeFinder *v4; // rdi
  __m128i v5; // xmm1
  __int128 v6; // xmm0
  unsigned int v7; // edx
  hkaiNavMeshInstance *v8; // rax
  unsigned int v9; // ecx
  signed __int64 v10; // rax
  hkaiPairedEdgeFinder::AccelerationData *v11; // rax
  __int64 v12; // r14
  __int64 i; // rsi
  __int64 v14; // rbx
  hkVector4f edgeB; // [rsp+20h] [rbp-E0h]
  hkVector4f edgeA; // [rsp+30h] [rbp-D0h]
  hkaiPairedEdgeFinder::PairedEdgeSettings settings; // [rsp+40h] [rbp-C0h]
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+80h] [rbp-80h]
  __int64 v19; // [rsp+88h] [rbp-78h]
  hkaiNavMeshInstance *v20; // [rsp+90h] [rbp-70h]
  __int64 v21; // [rsp+98h] [rbp-68h]
  hkaiPairedEdgeFinder::PairedEdgeSettings *v22; // [rsp+A0h] [rbp-60h]
  hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> *v23; // [rsp+A8h] [rbp-58h]
  bool v24; // [rsp+B0h] [rbp-50h]
  __m128 v25; // [rsp+C0h] [rbp-40h]
  __m128 v26; // [rsp+D0h] [rbp-30h]
  hkAabb aabbOut; // [rsp+E0h] [rbp-20h]

  v3.m_quad = (__m128)settingsIn->m_up;
  v4 = this;
  *(_OWORD *)&settings.m_minLength = *(_OWORD *)&settingsIn->m_minLength;
  v5 = *(__m128i *)&settingsIn->m_matchAngles.m_bool;
  settings.m_up = (hkVector4f)v3.m_quad;
  v6 = *(_OWORD *)&settingsIn->m_maxHorizontalDelta;
  *(__m128i *)&settings.m_matchAngles.m_bool = v5;
  *(_OWORD *)&settings.m_maxHorizontalDelta = v6;
  if ( !(unsigned __int8)_mm_cvtsi128_si32(_mm_srli_si128(v5, 2))
    || (settings.m_minHorizontalDelta = 0.0, settings.m_maxHorizontalDelta > 0.0) )
  {
    v7 = this->m_fromNavMeshInstance.m_pntr->m_sectionUid;
    v8 = this->m_toNavMeshInstance.m_pntr;
    v9 = v8->m_sectionUid;
    v20 = v8;
    v10 = (signed __int64)&v4->m_toAccelerationData.m_pntr->m_boundaryEdges;
    collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkaiPairedEdgeFinder::PairedEdgeQuery::`vftable';
    v21 = v10;
    v24 = v7 == v9;
    v22 = &settings;
    v11 = v4->m_fromAccelerationData.m_pntr;
    v23 = pairsOut;
    v12 = v11->m_boundaryEdges.m_size;
    for ( i = 0i64; i < v12; ++i )
    {
      v14 = (__int64)v4->m_fromAccelerationData.m_pntr->m_boundaryEdges.m_data[i];
      hkaiNavMeshInstance::getEdgePoints(v4->m_fromNavMeshInstance.m_pntr, SHIDWORD(v14), &edgeA, &edgeB);
      v25 = edgeB.m_quad;
      v26 = edgeA.m_quad;
      v19 = v14;
      hkaiPairedEdgeFinder::buildPairedEdgeAabb(&edgeB, &edgeA, &settings, &aabbOut);
      hkcdDynamicAabbTree::queryAabb(v4->m_toAccelerationData.m_pntr->m_boundaryEdgeTree.m_pntr, &aabbOut, &collector);
    }
  }
}

// File Line: 550
// RVA: 0xC3BE60
void __usercall hkaiPairedEdgeFinder::findInternalStarts(hkaiPairedEdgeFinder *this@<rcx>, hkaiPairedEdgeFinder::PairedEdgeSettings *settings@<rdx>, hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> *pairsOut@<r8>, signed __int64 a4@<rbx>)
{
  hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> *v4; // rsi
  hkaiPairedEdgeFinder::PairedEdgeSettings *v5; // r14
  hkVector4f v6; // xmm8
  hkaiPairedEdgeFinder *v7; // rdi
  signed __int64 v8; // rcx
  __m128 v9; // xmm9
  hkaiPairedEdgeFinder::AccelerationData *v10; // rax
  hkaiNavMeshInstance *v11; // rdi
  int v12; // edx
  unsigned __int64 index; // rbx
  hkaiNavMesh::Edge *v14; // rax
  signed int v15; // edx
  __int64 v16; // rcx
  __m128 *v17; // rcx
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __int64 v20; // rax
  __m128 v21; // xmm6
  __m128 v22; // xmm7
  __m128 v23; // xmm3
  __m128 *v24; // rax
  __m128 v25; // xmm1
  __m128 v26; // xmm5
  __m128 v27; // xmm5
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  int v31; // er13
  int v32; // er14
  float v33; // er12
  hkaiIntervalPartition::Interval *v34; // rax
  unsigned int v35; // er15
  hkaiIntervalPartition::Interval *v36; // rdi
  __int64 v37; // rcx
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  signed __int64 v40; // rdx
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  hkaiIntervalPartition partition; // [rsp+50h] [rbp-A8h]
  hkaiIntervalPartition v44; // [rsp+60h] [rbp-98h]
  __int64 v45; // [rsp+70h] [rbp-88h]
  hkVector4f displacement; // [rsp+78h] [rbp-80h]
  hkVector4f xVector; // [rsp+88h] [rbp-70h]
  hkVector4f startLeftOut; // [rsp+98h] [rbp-60h]
  hkVector4f toLeft; // [rsp+A8h] [rbp-50h]
  hkVector4f toRight; // [rsp+B8h] [rbp-40h]
  hkVector4f leftOut; // [rsp+C8h] [rbp-30h]
  hkVector4f fwdDir; // [rsp+D8h] [rbp-20h]
  hkVector4f filteredStartLeft; // [rsp+E8h] [rbp-10h]
  hkVector4f origEndRight; // [rsp+F8h] [rbp+0h]
  hkVector4f filteredStartRight; // [rsp+108h] [rbp+10h]
  hkVector4f rightOut; // [rsp+118h] [rbp+20h]
  hkVector4f filteredEndLeft; // [rsp+128h] [rbp+30h]
  hkVector4f origEndLeft; // [rsp+138h] [rbp+40h]
  hkVector4f filteredEndRight; // [rsp+148h] [rbp+50h]
  hkVector4f startRightOut; // [rsp+158h] [rbp+60h]
  hkaiNavMeshInstanceSegmentCaster v61; // [rsp+168h] [rbp+70h]
  hkaiPairedEdgeFinder *retaddr; // [rsp+238h] [rbp+140h]
  hkaiPairedEdgeFinder::PairedEdgeSettings *settingsa; // [rsp+240h] [rbp+148h]
  signed __int64 v64; // [rsp+250h] [rbp+158h]

  settingsa = (hkaiPairedEdgeFinder::PairedEdgeSettings *)this;
  v4 = pairsOut;
  v5 = settings;
  v6.m_quad = (__m128)settings->m_up;
  v7 = this;
  hkaiNavMeshInstanceSegmentCaster::hkaiNavMeshInstanceSegmentCaster(
    &v61,
    this->m_fromNavMeshInstance.m_pntr,
    this->m_fromAccelerationData.m_pntr->m_segmentCasterAccelerationData.m_pntr);
  hkaiIntervalPartition::hkaiIntervalPartition(&partition);
  hkaiIntervalPartition::hkaiIntervalPartition(&v44);
  v8 = 0i64;
  v45 = v7->m_toAccelerationData.m_pntr->m_boundaryEdges.m_size;
  if ( v45 > 0 )
  {
    v64 = a4;
    v9 = _mm_shuffle_ps(v6.m_quad, v6.m_quad, 201);
    do
    {
      v10 = v7->m_toAccelerationData.m_pntr;
      v11 = v7->m_fromNavMeshInstance.m_pntr;
      v12 = v11->m_numOriginalEdges;
      index = (unsigned __int64)v10->m_boundaryEdges.m_data[v8];
      displacement.m_quad.m128_u64[0] = index;
      v14 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__21(
              v11->m_originalEdges,
              v12,
              &v11->m_instancedEdges,
              &v11->m_ownedEdges,
              &v11->m_edgeMap,
              SHIDWORD(index));
      v15 = v11->m_numOriginalVertices;
      v16 = v14->m_a;
      if ( (signed int)v16 >= v15 )
        v17 = &v11->m_ownedVertices.m_data[(signed int)v16 - v15].m_quad;
      else
        v17 = &v11->m_originalVertices[v16].m_quad;
      v18 = v11->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
      v19 = v11->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
      v20 = v14->m_b;
      v21 = v11->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
      v22 = v11->m_referenceFrame.m_transform.m_translation.m_quad;
      v23 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 0), v19),
                  _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 85), v18)),
                _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 170), v21)),
              v22);
      if ( (signed int)v20 >= v15 )
        v24 = &v11->m_ownedVertices.m_data[(signed int)v20 - v15].m_quad;
      else
        v24 = &v11->m_originalVertices[v20].m_quad;
      v25 = *v24;
      toLeft.m_quad = v23;
      toRight.m_quad = _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v19),
                             _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v18)),
                           _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v21)),
                         v22);
      xVector.m_quad = _mm_sub_ps(toRight.m_quad, v23);
      v26 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(xVector.m_quad, xVector.m_quad, 201), v6.m_quad),
              _mm_mul_ps(v9, xVector.m_quad));
      v27 = _mm_shuffle_ps(v26, v26, 201);
      v28 = _mm_mul_ps(v27, v27);
      v29 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
              _mm_shuffle_ps(v28, v28, 170));
      v30 = _mm_rsqrt_ps(v29);
      fwdDir.m_quad = _mm_mul_ps(
                        v27,
                        _mm_andnot_ps(
                          _mm_cmpleps(v29, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                            _mm_mul_ps(*(__m128 *)_xmm, v30))));
      hkaiPairedEdgeFinder::calcInternalStartFaceCast(
        v5,
        &toLeft,
        &toRight,
        &fwdDir,
        &startLeftOut,
        &startRightOut,
        &displacement);
      hkaiIntervalPartition::clear(&partition);
      hkaiNavMeshInstanceSegmentCaster::castSegment(&v61, &startLeftOut, &startRightOut, &displacement, &partition);
      v31 = partition.m_intervals.m_size;
      v32 = 0;
      if ( partition.m_intervals.m_size > 0 )
      {
        v33 = displacement.m_quad.m128_f32[1];
        do
        {
          v34 = hkaiIntervalPartition::getInterval(&partition, v32);
          v35 = v34->m_data;
          v36 = v34;
          hkaiIntervalPartition::Interval::interpolateParallelogram(
            v34,
            &startLeftOut,
            &xVector,
            &displacement,
            &leftOut,
            &rightOut);
          hkaiIntervalPartition::Interval::interpolateParallelogram(
            v36,
            &toLeft,
            &xVector,
            &aabbOut,
            &origEndLeft,
            &origEndRight);
          if ( hkaiPairedEdgeFinder::filterPairedEdge(
                 &leftOut,
                 &rightOut,
                 &origEndLeft,
                 &origEndRight,
                 settingsa,
                 &filteredStartLeft,
                 &filteredStartRight,
                 &filteredEndLeft,
                 &filteredEndRight) )
          {
            if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, 80);
            v37 = v4->m_size;
            v38 = filteredStartLeft.m_quad;
            v39 = filteredStartRight.m_quad;
            v4->m_size = v37 + 1;
            v40 = (signed __int64)&v4->m_data[v37];
            *(__m128 *)(v40 + 16) = v38;
            v41 = filteredEndLeft.m_quad;
            *(__m128 *)v40 = v39;
            *(_DWORD *)(v40 + 64) = v35;
            *(_DWORD *)(v40 + 68) = -1;
            *(_DWORD *)(v40 + 72) = index;
            *(float *)(v40 + 76) = v33;
            v42 = filteredEndRight.m_quad;
            *(__m128 *)(v40 + 48) = v41;
            *(__m128 *)(v40 + 32) = v42;
          }
          ++v32;
        }
        while ( v32 < v31 );
      }
      v5 = settingsa;
      v7 = retaddr;
      v8 = v64 + 1;
      v64 = v8;
    }
    while ( v8 < v45 );
  }
  v44.m_intervals.m_size = 0;
  if ( v44.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v44.m_intervals.m_data,
      20 * (v44.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  v44.m_intervals.m_data = 0i64;
  v44.m_intervals.m_capacityAndFlags = 2147483648;
  partition.m_intervals.m_size = 0;
  if ( partition.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      partition.m_intervals.m_data,
      20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  partition.m_intervals.m_data = 0i64;
  partition.m_intervals.m_capacityAndFlags = 2147483648;
  hkaiNavMeshInstanceSegmentCaster::~hkaiNavMeshInstanceSegmentCaster(&v61);
}

// File Line: 630
// RVA: 0xC3C3A0
void __usercall hkaiPairedEdgeFinder::findInternalEnds(hkaiPairedEdgeFinder *this@<rcx>, hkaiPairedEdgeFinder::PairedEdgeSettings *settings@<rdx>, hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> *pairsOut@<r8>, signed __int64 a4@<rbx>)
{
  hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> *v4; // rsi
  hkaiPairedEdgeFinder::PairedEdgeSettings *v5; // r14
  hkVector4f v6; // xmm8
  hkaiPairedEdgeFinder *v7; // rdi
  signed __int64 v8; // rcx
  __m128 v9; // xmm9
  hkaiPairedEdgeFinder::AccelerationData *v10; // rax
  hkaiNavMeshInstance *v11; // rdi
  int v12; // edx
  unsigned __int64 index; // rbx
  hkaiNavMesh::Edge *v14; // rax
  signed int v15; // edx
  __int64 v16; // rcx
  __m128 *v17; // rcx
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __int64 v20; // rax
  __m128 v21; // xmm6
  __m128 v22; // xmm7
  __m128 v23; // xmm3
  __m128 *v24; // rax
  __m128 v25; // xmm1
  __m128 v26; // xmm5
  __m128 v27; // xmm5
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  int v31; // er13
  int v32; // er14
  float v33; // er12
  hkaiIntervalPartition::Interval *v34; // rax
  unsigned int v35; // er15
  hkaiIntervalPartition::Interval *v36; // rdi
  __int64 v37; // rcx
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  signed __int64 v40; // rdx
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  hkaiIntervalPartition partition; // [rsp+50h] [rbp-A8h]
  hkaiIntervalPartition v44; // [rsp+60h] [rbp-98h]
  __int64 v45; // [rsp+70h] [rbp-88h]
  hkVector4f displacement; // [rsp+78h] [rbp-80h]
  hkVector4f xVector; // [rsp+88h] [rbp-70h]
  hkVector4f startLeftOut; // [rsp+98h] [rbp-60h]
  hkVector4f fromLeft; // [rsp+A8h] [rbp-50h]
  hkVector4f fromRight; // [rsp+B8h] [rbp-40h]
  hkVector4f origStartLeft; // [rsp+C8h] [rbp-30h]
  hkVector4f fwdDir; // [rsp+D8h] [rbp-20h]
  hkVector4f filteredStartLeft; // [rsp+E8h] [rbp-10h]
  hkVector4f rightOut; // [rsp+F8h] [rbp+0h]
  hkVector4f filteredStartRight; // [rsp+108h] [rbp+10h]
  hkVector4f origStartRight; // [rsp+118h] [rbp+20h]
  hkVector4f filteredEndLeft; // [rsp+128h] [rbp+30h]
  hkVector4f leftOut; // [rsp+138h] [rbp+40h]
  hkVector4f filteredEndRight; // [rsp+148h] [rbp+50h]
  hkVector4f startRightOut; // [rsp+158h] [rbp+60h]
  hkaiNavMeshInstanceSegmentCaster v61; // [rsp+168h] [rbp+70h]
  hkaiPairedEdgeFinder *retaddr; // [rsp+238h] [rbp+140h]
  hkaiPairedEdgeFinder::PairedEdgeSettings *settingsa; // [rsp+240h] [rbp+148h]
  signed __int64 v64; // [rsp+250h] [rbp+158h]

  settingsa = (hkaiPairedEdgeFinder::PairedEdgeSettings *)this;
  v4 = pairsOut;
  v5 = settings;
  v6.m_quad = (__m128)settings->m_up;
  v7 = this;
  hkaiNavMeshInstanceSegmentCaster::hkaiNavMeshInstanceSegmentCaster(
    &v61,
    this->m_toNavMeshInstance.m_pntr,
    this->m_toAccelerationData.m_pntr->m_segmentCasterAccelerationData.m_pntr);
  hkaiIntervalPartition::hkaiIntervalPartition(&partition);
  hkaiIntervalPartition::hkaiIntervalPartition(&v44);
  v8 = 0i64;
  v45 = v7->m_fromAccelerationData.m_pntr->m_boundaryEdges.m_size;
  if ( v45 > 0 )
  {
    v64 = a4;
    v9 = _mm_shuffle_ps(v6.m_quad, v6.m_quad, 201);
    do
    {
      v10 = v7->m_fromAccelerationData.m_pntr;
      v11 = v7->m_fromNavMeshInstance.m_pntr;
      v12 = v11->m_numOriginalEdges;
      index = (unsigned __int64)v10->m_boundaryEdges.m_data[v8];
      displacement.m_quad.m128_u64[0] = index;
      v14 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__21(
              v11->m_originalEdges,
              v12,
              &v11->m_instancedEdges,
              &v11->m_ownedEdges,
              &v11->m_edgeMap,
              SHIDWORD(index));
      v15 = v11->m_numOriginalVertices;
      v16 = v14->m_a;
      if ( (signed int)v16 >= v15 )
        v17 = &v11->m_ownedVertices.m_data[(signed int)v16 - v15].m_quad;
      else
        v17 = &v11->m_originalVertices[v16].m_quad;
      v18 = v11->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
      v19 = v11->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
      v20 = v14->m_b;
      v21 = v11->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
      v22 = v11->m_referenceFrame.m_transform.m_translation.m_quad;
      v23 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 0), v19),
                  _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 85), v18)),
                _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 170), v21)),
              v22);
      if ( (signed int)v20 >= v15 )
        v24 = &v11->m_ownedVertices.m_data[(signed int)v20 - v15].m_quad;
      else
        v24 = &v11->m_originalVertices[v20].m_quad;
      v25 = *v24;
      fromRight.m_quad = v23;
      fromLeft.m_quad = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v19),
                              _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v18)),
                            _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v21)),
                          v22);
      xVector.m_quad = _mm_sub_ps(v23, fromLeft.m_quad);
      v26 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(xVector.m_quad, xVector.m_quad, 201), v6.m_quad),
              _mm_mul_ps(v9, xVector.m_quad));
      v27 = _mm_shuffle_ps(v26, v26, 201);
      v28 = _mm_mul_ps(v27, v27);
      v29 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
              _mm_shuffle_ps(v28, v28, 170));
      v30 = _mm_rsqrt_ps(v29);
      fwdDir.m_quad = _mm_mul_ps(
                        v27,
                        _mm_andnot_ps(
                          _mm_cmpleps(v29, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                            _mm_mul_ps(*(__m128 *)_xmm, v30))));
      hkaiPairedEdgeFinder::calcInternalEndFaceCast(
        v5,
        &fromLeft,
        &fromRight,
        &fwdDir,
        &startLeftOut,
        &startRightOut,
        &displacement);
      hkaiIntervalPartition::clear(&partition);
      hkaiNavMeshInstanceSegmentCaster::castSegment(&v61, &startLeftOut, &startRightOut, &displacement, &partition);
      v31 = partition.m_intervals.m_size;
      v32 = 0;
      if ( partition.m_intervals.m_size > 0 )
      {
        v33 = displacement.m_quad.m128_f32[1];
        do
        {
          v34 = hkaiIntervalPartition::getInterval(&partition, v32);
          v35 = v34->m_data;
          v36 = v34;
          hkaiIntervalPartition::Interval::interpolateParallelogram(
            v34,
            &startLeftOut,
            &xVector,
            &displacement,
            &leftOut,
            &rightOut);
          hkaiIntervalPartition::Interval::interpolateParallelogram(
            v36,
            &fromLeft,
            &xVector,
            &aabbOut,
            &origStartLeft,
            &origStartRight);
          if ( hkaiPairedEdgeFinder::filterPairedEdge(
                 &origStartLeft,
                 &origStartRight,
                 &leftOut,
                 &rightOut,
                 settingsa,
                 &filteredStartLeft,
                 &filteredStartRight,
                 &filteredEndLeft,
                 &filteredEndRight) )
          {
            if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, 80);
            v37 = v4->m_size;
            v38 = filteredStartLeft.m_quad;
            v39 = filteredStartRight.m_quad;
            v4->m_size = v37 + 1;
            v40 = (signed __int64)&v4->m_data[v37];
            *(__m128 *)(v40 + 16) = v38;
            v41 = filteredEndLeft.m_quad;
            *(__m128 *)v40 = v39;
            *(_DWORD *)(v40 + 64) = index;
            *(float *)(v40 + 68) = v33;
            *(_DWORD *)(v40 + 72) = v35;
            *(_DWORD *)(v40 + 76) = -1;
            v42 = filteredEndRight.m_quad;
            *(__m128 *)(v40 + 48) = v41;
            *(__m128 *)(v40 + 32) = v42;
          }
          ++v32;
        }
        while ( v32 < v31 );
      }
      v5 = settingsa;
      v7 = retaddr;
      v8 = v64 + 1;
      v64 = v8;
    }
    while ( v8 < v45 );
  }
  v44.m_intervals.m_size = 0;
  if ( v44.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v44.m_intervals.m_data,
      20 * (v44.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  v44.m_intervals.m_data = 0i64;
  v44.m_intervals.m_capacityAndFlags = 2147483648;
  partition.m_intervals.m_size = 0;
  if ( partition.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      partition.m_intervals.m_data,
      20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  partition.m_intervals.m_data = 0i64;
  partition.m_intervals.m_capacityAndFlags = 2147483648;
  hkaiNavMeshInstanceSegmentCaster::~hkaiNavMeshInstanceSegmentCaster(&v61);
}

// File Line: 711
// RVA: 0xC3D3C0
void __fastcall hkaiPairedEdgeFinder::calcInternalStartFaceCast(hkaiPairedEdgeFinder::PairedEdgeSettings *settings, hkVector4f *toLeft, hkVector4f *toRight, hkVector4f *fwdDir, hkVector4f *startLeftOut, hkVector4f *startRightOut, hkVector4f *displacementOut)
{
  hkVector4f v7; // xmm5
  __m128 v8; // xmm0
  __m128 v9; // xmm4
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  hkVector4f v12; // xmm1

  v7.m_quad = (__m128)settings->m_up;
  v8 = _mm_shuffle_ps((__m128)LODWORD(settings->m_minHeightDelta), (__m128)LODWORD(settings->m_minHeightDelta), 0);
  v9 = _mm_sub_ps(
         _mm_shuffle_ps((__m128)LODWORD(settings->m_maxHeightDelta), (__m128)LODWORD(settings->m_maxHeightDelta), 0),
         v8);
  v10 = _mm_mul_ps(settings->m_up.m_quad, v8);
  v11 = _mm_shuffle_ps((__m128)LODWORD(INTERNAL_CAST_SET_OUTWARD), (__m128)LODWORD(INTERNAL_CAST_SET_OUTWARD), 0);
  v12.m_quad = _mm_sub_ps(toLeft->m_quad, v10);
  *startLeftOut = (hkVector4f)v12.m_quad;
  startLeftOut->m_quad = _mm_sub_ps(v12.m_quad, _mm_mul_ps(fwdDir->m_quad, v11));
  startRightOut->m_quad = _mm_sub_ps(toRight->m_quad, v10);
  startLeftOut->m_quad = _mm_sub_ps(startLeftOut->m_quad, _mm_mul_ps(fwdDir->m_quad, v11));
  displacementOut->m_quad = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v9), v7.m_quad);
}

// File Line: 729
// RVA: 0xC3D440
void __fastcall hkaiPairedEdgeFinder::calcInternalEndFaceCast(hkaiPairedEdgeFinder::PairedEdgeSettings *settings, hkVector4f *fromLeft, hkVector4f *fromRight, hkVector4f *fwdDir, hkVector4f *startLeftOut, hkVector4f *startRightOut, hkVector4f *displacementOut)
{
  hkVector4f v7; // xmm5
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  hkVector4f v12; // xmm1
  hkVector4f v13; // xmm1

  v7.m_quad = (__m128)settings->m_up;
  v8 = _mm_shuffle_ps((__m128)LODWORD(INTERNAL_CAST_SET_OUTWARD), (__m128)LODWORD(INTERNAL_CAST_SET_OUTWARD), 0);
  v9 = _mm_sub_ps(
         (__m128)0i64,
         _mm_shuffle_ps((__m128)LODWORD(settings->m_minHeightDelta), (__m128)LODWORD(settings->m_minHeightDelta), 0));
  v10 = _mm_mul_ps(settings->m_up.m_quad, v9);
  v11 = _mm_sub_ps(
          _mm_sub_ps(
            (__m128)0i64,
            _mm_shuffle_ps((__m128)LODWORD(settings->m_maxHeightDelta), (__m128)LODWORD(settings->m_maxHeightDelta), 0)),
          v9);
  v12.m_quad = _mm_sub_ps(fromLeft->m_quad, v10);
  *startLeftOut = (hkVector4f)v12.m_quad;
  startLeftOut->m_quad = _mm_add_ps(_mm_mul_ps(fwdDir->m_quad, v8), v12.m_quad);
  v13.m_quad = _mm_sub_ps(fromRight->m_quad, v10);
  *startRightOut = (hkVector4f)v13.m_quad;
  startRightOut->m_quad = _mm_add_ps(_mm_mul_ps(fwdDir->m_quad, v8), v13.m_quad);
  displacementOut->m_quad = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v11), v7.m_quad);
}

// File Line: 744
// RVA: 0xC3B6C0
__int64 __fastcall hkaiPairedEdgeFinder::AccelerationData::getSize(hkaiPairedEdgeFinder::AccelerationData *this)
{
  int v1; // ebx

  v1 = this->m_boundaryEdges.m_capacityAndFlags & 0x3FFFFFFF;
  return (unsigned int)(hkcdDynamicAabbTree::getMemoryFootPrint(this->m_boundaryEdgeTree.m_pntr) + 8 * v1 + 48);
}

// File Line: 754
// RVA: 0xC3BC10
void __fastcall hkaiPairedEdgeFinder::PairedEdgeSettings::PairedEdgeSettings(hkaiPairedEdgeFinder::PairedEdgeSettings *this)
{
  *(_WORD *)&this->m_matchAngles.m_bool = 1;
  this->m_findInternalEnds.m_bool = 0;
}


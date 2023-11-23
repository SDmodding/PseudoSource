// File Line: 29
// RVA: 0xC3BAF0
void __fastcall hkaiPairedEdgeFinder::hkaiPairedEdgeFinder(
        hkaiPairedEdgeFinder *this,
        hkaiNavMeshInstance *fromNavMeshInstance,
        hkaiPairedEdgeFinder::AccelerationData *fromAccelerationData,
        hkaiNavMeshInstance *toNavMeshInstance,
        hkaiPairedEdgeFinder::AccelerationData *toAccelerationData)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPairedEdgeFinder::`vftable;
  if ( fromNavMeshInstance )
    hkReferencedObject::addReference(fromNavMeshInstance);
  this->m_fromNavMeshInstance.m_pntr = fromNavMeshInstance;
  if ( fromAccelerationData )
    hkReferencedObject::addReference(fromAccelerationData);
  this->m_fromAccelerationData.m_pntr = fromAccelerationData;
  if ( toNavMeshInstance )
    hkReferencedObject::addReference(toNavMeshInstance);
  this->m_toNavMeshInstance.m_pntr = toNavMeshInstance;
  if ( toAccelerationData )
    hkReferencedObject::addReference(toAccelerationData);
  this->m_toAccelerationData.m_pntr = toAccelerationData;
}

// File Line: 33
// RVA: 0xC3BB90
void __fastcall hkaiPairedEdgeFinder::~hkaiPairedEdgeFinder(hkaiPairedEdgeFinder *this)
{
  hkaiPairedEdgeFinder::AccelerationData *m_pntr; // rcx
  hkaiNavMeshInstance *v3; // rcx
  hkaiPairedEdgeFinder::AccelerationData *v4; // rcx
  hkaiNavMeshInstance *v5; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiPairedEdgeFinder::`vftable;
  m_pntr = this->m_toAccelerationData.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_toAccelerationData.m_pntr = 0i64;
  v3 = this->m_toNavMeshInstance.m_pntr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  this->m_toNavMeshInstance.m_pntr = 0i64;
  v4 = this->m_fromAccelerationData.m_pntr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  this->m_fromAccelerationData.m_pntr = 0i64;
  v5 = this->m_fromNavMeshInstance.m_pntr;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  this->m_fromNavMeshInstance.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 42
// RVA: 0xC3C8E0
void __fastcall hkaiPairedEdgeFinder::buildPairedEdgeAabb(
        hkVector4f *left,
        hkVector4f *right,
        hkaiPairedEdgeFinder::PairedEdgeSettings *settings,
        hkAabb *aabbOut)
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
bool __fastcall hkaiPairedEdgeFinder::edgeAnglesMatch(
        hkVector4f *startLeft,
        hkVector4f *startRight,
        hkVector4f *endLeft,
        hkVector4f *endRight,
        float cosMaxHorizontalAngle)
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
          _mm_cmple_ps(v9, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)), _mm_mul_ps(*(__m128 *)_xmm, v10)),
            v9));
  v12 = _mm_mul_ps(v6, v6);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  v15 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v13, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                _mm_mul_ps(*(__m128 *)_xmm, v14)),
              v13)),
          v11);
  if ( v15.m128_f32[0] >= 0.00000011920929 )
  {
    v16 = _mm_mul_ps(v6, v7);
    v17 = _mm_rcp_ps(v15).m128_f32[0];
    return (float)((float)((float)(2.0 - (float)(v17 * v15.m128_f32[0])) * v17)
                 * (float)((float)(_mm_shuffle_ps(v16, v16, 85).m128_f32[0] + _mm_shuffle_ps(v16, v16, 0).m128_f32[0])
                         + _mm_shuffle_ps(v16, v16, 170).m128_f32[0])) > _mm_shuffle_ps(
                                                                           (__m128)LODWORD(cosMaxHorizontalAngle),
                                                                           (__m128)LODWORD(cosMaxHorizontalAngle),
                                                                           0).m128_f32[0];
  }
  return result;
}

// File Line: 99
// RVA: 0xC3CC70
__int64 __fastcall hkaiPairedEdgeFinder::matchEdgeEnds(
        hkVector4f *startLeftInOut,
        hkVector4f *startRightInOut,
        hkVector4f *endLeftInOut,
        hkVector4f *endRightInOut,
        hkVector4f *up)
{
  __m128 m_quad; // xmm7
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
  __int64 result; // rax
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm5
  __m128 v27; // xmm0
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  __m128 v32; // xmm4
  __m128 v33; // xmm2
  __m128 v34; // xmm4
  __m128 v35; // xmm3
  __m128 v36; // xmm5
  __m128 v37; // xmm4
  __m128 v38; // xmm3
  __m128 v39; // xmm0
  __m128 v40; // xmm2

  m_quad = startLeftInOut->m_quad;
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
            _mm_cmple_ps(v12, (__m128)0i64),
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
              _mm_cmple_ps(v18, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                _mm_mul_ps(v19, *(__m128 *)_xmm))),
            v16),
          v15);
  v21 = _mm_mul_ps(v20, v20);
  if ( (float)((float)(_mm_shuffle_ps(v21, v21, 85).m128_f32[0] + _mm_shuffle_ps(v21, v21, 0).m128_f32[0])
             + _mm_shuffle_ps(v21, v21, 170).m128_f32[0]) <= 0.00000011920929 )
    return 0i64;
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v24 = _mm_rsqrt_ps(v23);
  v25 = _mm_mul_ps(
          v20,
          _mm_andnot_ps(
            _mm_cmple_ps(v23, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
              _mm_mul_ps(v24, *(__m128 *)_xmm))));
  v26 = _mm_mul_ps(v25, endRightInOut->m_quad);
  v27 = _mm_mul_ps(v25, startRightInOut->m_quad);
  v28 = _mm_mul_ps(v25, m_quad);
  v29 = _mm_mul_ps(v25, v6);
  v30 = _mm_shuffle_ps(v28, v27, 68);
  v31 = _mm_shuffle_ps(v29, v26, 68);
  v32 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v28, v27, 238), _mm_shuffle_ps(v29, v26, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v30, v31, 221), _mm_shuffle_ps(v30, v31, 136)));
  v33 = _mm_shuffle_ps(v32, v32, 160);
  v34 = _mm_shuffle_ps(v32, v32, 245);
  v35 = _mm_max_ps(_mm_shuffle_ps(v33, v33, 170), _mm_max_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)));
  v36 = _mm_min_ps(_mm_shuffle_ps(v34, v34, 170), _mm_min_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)));
  if ( v35.m128_f32[0] >= v36.m128_f32[0] )
    return 0i64;
  v37 = _mm_sub_ps(v34, v33);
  v38 = _mm_unpacklo_ps(v35, v36);
  result = 1i64;
  v39 = _mm_rcp_ps(v37);
  v40 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v37, v39)), v39),
          _mm_sub_ps(_mm_movelh_ps(v38, v38), v33));
  startLeftInOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), v7), m_quad);
  startRightInOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v40, v40, 85), v7), m_quad);
  endLeftInOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v40, v40, 170), v9), v6);
  endRightInOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v40, v40, 255), v9), v6);
  return result;
}

// File Line: 161
// RVA: 0xC3D4E0
hkSimdFloat32 *__fastcall `anonymous namespace::cosAngleAboutAxis(
        hkSimdFloat32 *result,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *u)
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
                     _mm_andnot_ps(_mm_cmple_ps(v12, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v12))),
                     _mm_sub_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)),
                         _mm_shuffle_ps(v9, v9, 170)),
                       _mm_mul_ps(v8, v6)));
  return v4;
}

// File Line: 183
// RVA: 0xC3CF70
_BOOL8 __fastcall hkaiPairedEdgeFinder::slopeAnglesMatch(
        hkVector4f *startLeft,
        hkVector4f *startRight,
        hkVector4f *endLeft,
        hkVector4f *endRight,
        hkVector4f *up,
        float cosMaxDeltaAngle)
{
  __m128 v6; // xmm1
  __m128 v7; // xmm1
  __m128 v8; // xmm5
  __m128 v9; // xmm5
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  hkVector4f u; // [rsp+20h] [rbp-48h] BYREF
  hkVector4f b; // [rsp+30h] [rbp-38h] BYREF
  hkVector4f a; // [rsp+40h] [rbp-28h] BYREF
  hkSimdFloat32 result; // [rsp+50h] [rbp-18h] BYREF

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
                 _mm_cmple_ps(v11, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                   _mm_mul_ps(*(__m128 *)_xmm, v12))));
  return COERCE_FLOAT(*`anonymous namespace::cosAngleAboutAxis(&result, &a, &b, &u)) > _mm_shuffle_ps(
                                                                                          (__m128)LODWORD(cosMaxDeltaAngle),
                                                                                          (__m128)LODWORD(cosMaxDeltaAngle),
                                                                                          0).m128_f32[0];
}

// File Line: 199
// RVA: 0xC3D060
__int64 __fastcall hkaiPairedEdgeFinder::filterEdgeDistances(
        hkVector4f *startLeftInOut,
        hkVector4f *startRightInOut,
        hkVector4f *endLeftInOut,
        hkVector4f *endRightInOut,
        hkaiPairedEdgeFinder::PairedEdgeSettings *settings)
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
  __m128 v16; // xmm10
  __m128 v17; // xmm1
  __m128 v18; // xmm5
  __m128 v19; // xmm1
  __m128i v20; // xmm8
  __m128 v21; // xmm4
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm10
  __m128 v26; // xmm8
  __m128 v27; // xmm7
  __m128 v28; // xmm3
  __m128 v29; // xmm1
  __m128 v30; // xmm7
  __m128 v31; // xmm3
  __m128 v32; // xmm4
  __m128i v33; // xmm7
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm7
  __m128 v37; // xmm5
  __int64 result; // rax
  __m128 v39; // xmm1
  __m128 v40; // xmm5
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  __m128 v43; // xmm0
  __m128 v44; // xmm2
  __m128 v45; // xmm12
  hkVector4f v46; // xmm1
  __m128 m_quad; // [rsp+0h] [rbp-B8h]

  m_quad = endLeftInOut->m_quad;
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
  v16 = _mm_sub_ps(v5, _mm_mul_ps(settings->m_up.m_quad, v14));
  v17 = _mm_sub_ps(v6, _mm_mul_ps(settings->m_up.m_quad, v12));
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_mul_ps(v17, v11);
  v20 = (__m128i)_mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                   _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v22 = _mm_rsqrt_ps(v21);
  v23 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)), _mm_mul_ps(v22, *(__m128 *)_xmm));
  v24 = _mm_mul_ps(v16, v11);
  v25 = _mm_mul_ps(v16, v16);
  v26 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32(v20, 0x1Fu), 0x1Fu),
          _mm_andnot_ps(_mm_cmple_ps(v21, (__m128)0i64), _mm_mul_ps(v23, v21)));
  v27 = (__m128)_mm_slli_epi32(
                  _mm_srli_epi32(
                    (__m128i)_mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                               _mm_shuffle_ps(v24, v24, 170)),
                    0x1Fu),
                  0x1Fu);
  v28 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)), _mm_shuffle_ps(v25, v25, 170));
  v29 = _mm_rsqrt_ps(v28);
  v30 = _mm_sub_ps(
          _mm_xor_ps(
            v27,
            _mm_andnot_ps(
              _mm_cmple_ps(v28, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                  _mm_mul_ps(v29, *(__m128 *)_xmm)),
                v28))),
          v26);
  v31 = _mm_sub_ps(
          _mm_unpacklo_ps(
            _mm_unpacklo_ps(
              (__m128)LODWORD(settings->m_maxHorizontalDelta),
              (__m128)LODWORD(settings->m_maxHeightDelta)),
            _mm_unpacklo_ps(
              (__m128)LODWORD(settings->m_minHorizontalDelta),
              (__m128)LODWORD(settings->m_minHeightDelta))),
          _mm_movelh_ps(_mm_unpacklo_ps(v26, v26), _mm_unpacklo_ps(v12, v12)));
  v32 = _mm_cmplt_ps((__m128)0i64, v31);
  v33 = (__m128i)_mm_movelh_ps(_mm_unpacklo_ps(v30, v30), _mm_unpacklo_ps(v15, v15));
  v34 = _mm_div_ps(v31, (__m128)v33);
  v35 = _mm_cmplt_ps((__m128)v33, (__m128)0i64);
  v36 = _mm_cmple_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v33, 1u), 1u), *(__m128 *)&epsilon);
  v37 = _mm_or_ps(
          _mm_andnot_ps(v36, _mm_or_ps(_mm_and_ps(_mm_shuffle_ps(v34, v34, 177), v35), _mm_andnot_ps(v35, v34))),
          _mm_and_ps(_mm_or_ps(_mm_andnot_ps(v32, aabbOut.m_quad), _mm_and_ps(v32, query.m_quad)), v36));
  result = 0i64;
  v39 = _mm_max_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 255));
  v40 = _mm_min_ps(_mm_shuffle_ps(v37, v37, 0), _mm_shuffle_ps(v37, v37, 170));
  v41 = _mm_cmplt_ps(v39, query.m_quad);
  v42 = _mm_or_ps(_mm_and_ps(v39, v41), _mm_andnot_ps(v41, query.m_quad));
  v43 = _mm_cmplt_ps(v40, query.m_quad);
  v44 = _mm_max_ps((__m128)0i64, v42);
  v45 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v40, v43), _mm_andnot_ps(v43, query.m_quad)));
  v46.m_quad = _mm_add_ps(_mm_mul_ps(v45, v7), startLeftInOut->m_quad);
  startLeftInOut->m_quad = _mm_add_ps(_mm_mul_ps(v44, v7), startLeftInOut->m_quad);
  if ( v44.m128_f32[0] < v45.m128_f32[0] )
    result = 1i64;
  *startRightInOut = (hkVector4f)v46.m_quad;
  endLeftInOut->m_quad = _mm_add_ps(_mm_mul_ps(v44, v8), m_quad);
  endRightInOut->m_quad = _mm_add_ps(_mm_mul_ps(v45, v8), m_quad);
  return result;
}

// File Line: 291
// RVA: 0xC3C990
__int64 __fastcall hkaiPairedEdgeFinder::filterPairedEdge(
        hkVector4f *origStartLeft,
        hkVector4f *origStartRight,
        hkVector4f *origEndLeft,
        hkVector4f *origEndRight,
        hkaiPairedEdgeFinder::PairedEdgeSettings *settings,
        hkVector4f *filteredStartLeft,
        hkVector4f *filteredStartRight,
        hkVector4f *filteredEndLeft,
        hkVector4f *filteredEndRight)
{
  __m128 m_quad; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  unsigned int v13; // ecx
  __m128 v14; // xmm5
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm4
  __m128 v19; // xmm0
  float v20; // xmm2_4
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  float cosMaxHorizontalAngle; // [rsp+20h] [rbp-60h]
  hkVector4f startRight; // [rsp+30h] [rbp-50h] BYREF
  hkVector4f startLeft; // [rsp+40h] [rbp-40h] BYREF
  hkVector4f endLeft; // [rsp+50h] [rbp-30h] BYREF
  hkVector4f endRight; // [rsp+60h] [rbp-20h] BYREF

  m_quad = origStartRight->m_quad;
  startLeft.m_quad = origStartLeft->m_quad;
  v10 = origEndLeft->m_quad;
  startRight.m_quad = m_quad;
  v11 = origEndRight->m_quad;
  endLeft.m_quad = v10;
  cosMaxHorizontalAngle = settings->m_cosMaxPlanarAngle;
  endRight.m_quad = v11;
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
  v13 = hkaiPairedEdgeFinder::filterEdgeDistances(&startLeft, &startRight, &endLeft, &endRight, settings);
  v14 = startRight.m_quad;
  v15 = _mm_sub_ps(startRight.m_quad, startLeft.m_quad);
  v16 = _mm_mul_ps(settings->m_up.m_quad, v15);
  v17 = _mm_sub_ps(
          v15,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
              _mm_shuffle_ps(v16, v16, 170)),
            settings->m_up.m_quad));
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_shuffle_ps(v18, v18, 0);
  v20 = _mm_shuffle_ps(v18, v18, 85).m128_f32[0] + v19.m128_f32[0];
  v19.m128_f32[0] = settings->m_minLength * settings->m_minLength;
  if ( (float)(v20 + _mm_shuffle_ps(v18, v18, 170).m128_f32[0]) < _mm_shuffle_ps(v19, v19, 0).m128_f32[0] )
    return 0i64;
  v21 = endLeft.m_quad;
  v22 = endRight.m_quad;
  *filteredStartLeft = (hkVector4f)startLeft.m_quad;
  *filteredStartRight = (hkVector4f)v14;
  *filteredEndLeft = (hkVector4f)v21;
  *filteredEndRight = (hkVector4f)v22;
  return v13;
}

// File Line: 375
// RVA: 0xC3D710
__int64 __fastcall hkaiPairedEdgeFinder::PairedEdgeQuery::processLeaf(
        hkaiPairedEdgeFinder::PairedEdgeQuery *this,
        unsigned int leafKey,
        hkAabb *leafAabb)
{
  hkaiPairedEdgeFinder::AccelerationData::BoundaryEdge v4; // rbx
  hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> *m_pairsOut; // rsi
  __int64 m_size; // rcx
  __m128 m_quad; // xmm0
  __m128 v8; // xmm1
  __int64 v9; // rdx
  int m_startEdgeIndex; // eax
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  hkVector4f edgeB; // [rsp+50h] [rbp-68h] BYREF
  hkVector4f edgeA; // [rsp+60h] [rbp-58h] BYREF
  hkVector4f filteredStartLeft; // [rsp+70h] [rbp-48h] BYREF
  hkVector4f filteredStartRight; // [rsp+80h] [rbp-38h] BYREF
  hkVector4f filteredEndLeft; // [rsp+90h] [rbp-28h] BYREF
  hkVector4f filteredEndRight; // [rsp+A0h] [rbp-18h] BYREF

  v4 = this->m_toBoundaryEdges->m_data[leafKey];
  if ( !this->m_isWithinSameSection.m_bool || v4.m_edgeIndex != this->m_startEdgeIndex )
  {
    hkaiNavMeshInstance::getEdgePoints(this->m_toNavMeshInstance, v4.m_edgeIndex, &edgeA, &edgeB);
    if ( (unsigned int)hkaiPairedEdgeFinder::filterPairedEdge(
                         &this->m_startLeft,
                         &this->m_startRight,
                         &edgeA,
                         &edgeB,
                         this->m_settings,
                         &filteredStartLeft,
                         &filteredStartRight,
                         &filteredEndLeft,
                         &filteredEndRight) )
    {
      m_pairsOut = this->m_pairsOut;
      if ( m_pairsOut->m_size == (m_pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, this->m_pairsOut, 80);
      m_size = m_pairsOut->m_size;
      m_quad = filteredStartLeft.m_quad;
      v8 = filteredStartRight.m_quad;
      m_pairsOut->m_size = m_size + 1;
      v9 = (__int64)&m_pairsOut->m_data[m_size];
      *(_DWORD *)(v9 + 64) = this->m_startFaceIndex;
      m_startEdgeIndex = this->m_startEdgeIndex;
      *(_DWORD *)(v9 + 72) = v4.m_faceIndex;
      *(__m128 *)(v9 + 16) = m_quad;
      v11 = filteredEndLeft.m_quad;
      *(__m128 *)v9 = v8;
      *(_DWORD *)(v9 + 68) = m_startEdgeIndex;
      v12 = filteredEndRight.m_quad;
      *(__m128 *)(v9 + 48) = v11;
      *(_DWORD *)(v9 + 76) = v4.m_edgeIndex;
      *(__m128 *)(v9 + 32) = v12;
    }
  }
  return 1i64;
}

// File Line: 439
// RVA: 0xC3BC30
void __fastcall hkaiPairedEdgeFinder::findEdgePairs(
        hkaiPairedEdgeFinder *this,
        hkaiPairedEdgeFinder::PairedEdgeSettings *settings,
        hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> *pairsOut)
{
  bool v3; // zf
  __int128 v4; // xmm1
  __int128 v5; // xmm0
  __int128 v9; // xmm1
  hkaiPairedEdgeFinder::PairedEdgeSettings settingsIn; // [rsp+20h] [rbp-48h] BYREF

  pairsOut->m_size = 0;
  v3 = settings->m_findInternalStarts.m_bool == 0;
  v4 = *(_OWORD *)&settings->m_minLength;
  settingsIn.m_up = settings->m_up;
  v5 = *(_OWORD *)&settings->m_maxHorizontalDelta;
  *(_OWORD *)&settingsIn.m_minLength = v4;
  v9 = *(_OWORD *)&settings->m_matchAngles.m_bool;
  *(_OWORD *)&settingsIn.m_maxHorizontalDelta = v5;
  *(_OWORD *)&settingsIn.m_matchAngles.m_bool = v9;
  if ( !v3 || settings->m_findInternalEnds.m_bool )
    settingsIn.m_minHorizontalDelta = FLOAT_0_0099999998;
  hkaiPairedEdgeFinder::findExternalPairs(this, &settingsIn, pairsOut);
  if ( settings->m_findInternalStarts.m_bool )
    hkaiPairedEdgeFinder::findInternalStarts(this, settings, pairsOut);
  if ( settings->m_findInternalEnds.m_bool )
    hkaiPairedEdgeFinder::findInternalEnds(this, settings, pairsOut);
}

// File Line: 465
// RVA: 0xC3B6F0
hkaiPairedEdgeFinder::AccelerationData *__fastcall hkaiPairedEdgeFinder::buildAccelerationData(
        hkaiNavMeshInstance *navMeshInstance,
        hkaiNavMeshInstanceSegmentCaster::AccelerationData *segmentCasterAccelerationData)
{
  _QWORD **Value; // rax
  __int64 v5; // rax
  unsigned int v6; // ebx
  __int64 v7; // r14
  hkReferencedObject *v8; // rcx
  int index; // r15d
  __int64 v10; // rax
  __int64 v11; // r13
  hkResult *p_result; // rax
  hkaiNavMesh::Face *v13; // rax
  int v14; // esi
  int m_numEdges; // r12d
  hkaiNavMesh::Face *v16; // r13
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // rdx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // r8
  int v20; // ebp
  hkaiNavMesh::Edge *v21; // rax
  bool v22; // zf
  int m_oppositeFace; // ecx
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
  int m_numOriginalVertices; // edx
  __int64 m_a; // rcx
  hkVector4f *v36; // rcx
  hkVector4f v37; // xmm4
  hkVector4f v38; // xmm5
  __int64 m_b; // rax
  hkVector4f v40; // xmm6
  hkVector4f v41; // xmm7
  __m128 v42; // xmm3
  hkVector4f *v43; // rax
  hkcdDynamicAabbTree *v44; // rcx
  __m128 v45; // xmm2
  __int64 i; // [rsp+30h] [rbp-98h]
  hkAabb aabb; // [rsp+40h] [rbp-88h] BYREF
  hkResult result; // [rsp+D0h] [rbp+8h] BYREF
  char v50; // [rsp+D8h] [rbp+10h] BYREF
  __int64 v51; // [rsp+E0h] [rbp+18h]
  hkaiNavMesh::Face *v52; // [rsp+E8h] [rbp+20h]

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  v6 = 0;
  v7 = v5;
  if ( v5 )
  {
    *(_DWORD *)(v5 + 8) = 0x1FFFF;
    *(_QWORD *)v5 = &hkaiPairedEdgeFinder::AccelerationData::`vftable;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_DWORD *)(v5 + 24) = 0;
    *(_DWORD *)(v5 + 28) = 0x80000000;
    *(_QWORD *)(v5 + 32) = 0i64;
    *(_QWORD *)(v5 + 40) = 0i64;
  }
  else
  {
    v7 = 0i64;
  }
  if ( segmentCasterAccelerationData )
    hkReferencedObject::addReference(segmentCasterAccelerationData);
  v8 = *(hkReferencedObject **)(v7 + 40);
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  *(_QWORD *)(v7 + 40) = segmentCasterAccelerationData;
  index = 0;
  v10 = navMeshInstance->m_numOriginalFaces + navMeshInstance->m_ownedFaces.m_size;
  v11 = 0i64;
  v51 = 0i64;
  for ( i = v10; v11 < i; v51 = v11 )
  {
    if ( navMeshInstance->m_faceFlags.m_size )
    {
      p_result = &result;
      LOBYTE(result.m_enum) = navMeshInstance->m_faceFlags.m_data[v11].m_storage;
    }
    else
    {
      v50 = 0;
      p_result = (hkResult *)&v50;
    }
    if ( (p_result->m_enum & 1) == 0 )
    {
      v13 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__19(
              navMeshInstance->m_originalFaces,
              navMeshInstance->m_numOriginalFaces,
              &navMeshInstance->m_instancedFaces,
              &navMeshInstance->m_ownedFaces,
              &navMeshInstance->m_faceMap,
              index);
      v14 = 0;
      m_numEdges = v13->m_numEdges;
      v52 = v13;
      if ( m_numEdges > 0 )
      {
        v16 = v52;
        instanceMap = &navMeshInstance->m_edgeMap;
        p_m_ownedEdges = &navMeshInstance->m_ownedEdges;
        p_m_instancedEdges = &navMeshInstance->m_instancedEdges;
        do
        {
          v20 = v14 + v16->m_startEdgeIndex;
          v21 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__21(
                  navMeshInstance->m_originalEdges,
                  navMeshInstance->m_numOriginalEdges,
                  p_m_instancedEdges,
                  p_m_ownedEdges,
                  instanceMap,
                  v20);
          v22 = v21->m_oppositeEdge == -1;
          aabb.m_min.m_quad.m128_u64[0] = *(_QWORD *)&v21->m_a;
          m_oppositeFace = v21->m_oppositeFace;
          aabb.m_max.m_quad.m128_i32[0] = *(_DWORD *)&v21->m_flags.m_storage;
          aabb.m_min.m_quad.m128_i32[3] = m_oppositeFace;
          if ( v22 )
          {
            if ( *(_DWORD *)(v7 + 24) == (*(_DWORD *)(v7 + 28) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (void *)(v7 + 16), 8);
            v24 = *(int *)(v7 + 24);
            v25 = (int *)(*(_QWORD *)(v7 + 16) + 8 * v24);
            *(_DWORD *)(v7 + 24) = v24 + 1;
            *v25 = index;
            v25[1] = v20;
          }
          ++v14;
          instanceMap = &navMeshInstance->m_edgeMap;
          p_m_ownedEdges = &navMeshInstance->m_ownedEdges;
          p_m_instancedEdges = &navMeshInstance->m_instancedEdges;
        }
        while ( v14 < m_numEdges );
        v11 = v51;
        v6 = 0;
      }
    }
    ++v11;
    ++index;
  }
  v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (hkcdDynamicAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v26[11] + 8i64))(v26[11], 32i64);
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
  if ( v30 && v30 != v29 )
    hkReferencedObject::removeReference(v30);
  *(_QWORD *)(v7 + 32) = v29;
  hkcdDynamicAabbTree::reserveLeaves(v29, &result, *(_DWORD *)(v7 + 24));
  v31 = *(int *)(v7 + 24);
  for ( j = 0i64; j < v31; ++v6 )
  {
    v33 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__21(
            navMeshInstance->m_originalEdges,
            navMeshInstance->m_numOriginalEdges,
            &navMeshInstance->m_instancedEdges,
            &navMeshInstance->m_ownedEdges,
            &navMeshInstance->m_edgeMap,
            *(_DWORD *)(*(_QWORD *)(v7 + 16) + 8 * j + 4));
    m_numOriginalVertices = navMeshInstance->m_numOriginalVertices;
    m_a = v33->m_a;
    if ( (int)m_a >= m_numOriginalVertices )
      v36 = &navMeshInstance->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices];
    else
      v36 = &navMeshInstance->m_originalVertices[m_a];
    v37.m_quad = (__m128)navMeshInstance->m_referenceFrame.m_transform.m_rotation.m_col1;
    v38.m_quad = (__m128)navMeshInstance->m_referenceFrame.m_transform.m_rotation.m_col0;
    m_b = v33->m_b;
    v40.m_quad = (__m128)navMeshInstance->m_referenceFrame.m_transform.m_rotation.m_col2;
    v41.m_quad = (__m128)navMeshInstance->m_referenceFrame.m_transform.m_translation;
    v42 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v36->m_quad, v36->m_quad, 0), v38.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v36->m_quad, v36->m_quad, 85), v37.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v36->m_quad, v36->m_quad, 170), v40.m_quad)),
            v41.m_quad);
    if ( (int)m_b >= m_numOriginalVertices )
      v43 = &navMeshInstance->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices];
    else
      v43 = &navMeshInstance->m_originalVertices[m_b];
    v44 = *(hkcdDynamicAabbTree **)(v7 + 32);
    v45 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v43->m_quad, v43->m_quad, 85), v37.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v43->m_quad, v43->m_quad, 0), v38.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v43->m_quad, v43->m_quad, 170), v40.m_quad)),
            v41.m_quad);
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
void __fastcall hkaiPairedEdgeFinder::findExternalPairs(
        hkaiPairedEdgeFinder *this,
        hkaiPairedEdgeFinder::PairedEdgeSettings *settingsIn,
        hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> *pairsOut)
{
  hkVector4f v3; // xmm0
  __m128i v5; // xmm1
  __int128 v6; // xmm0
  unsigned int m_sectionUid; // edx
  hkaiNavMeshInstance *m_pntr; // rax
  unsigned int v9; // ecx
  hkArray<hkaiPairedEdgeFinder::AccelerationData::BoundaryEdge,hkContainerHeapAllocator> *p_m_boundaryEdges; // rax
  hkaiPairedEdgeFinder::AccelerationData *v11; // rax
  __int64 m_size; // r14
  __int64 i; // rsi
  hkVector4f edgeB; // [rsp+20h] [rbp-E0h] BYREF
  hkVector4f edgeA; // [rsp+30h] [rbp-D0h] BYREF
  hkaiPairedEdgeFinder::PairedEdgeSettings settings; // [rsp+40h] [rbp-C0h] BYREF
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+80h] [rbp-80h] BYREF
  hkaiPairedEdgeFinder::AccelerationData::BoundaryEdge v18; // [rsp+88h] [rbp-78h]
  hkaiNavMeshInstance *v19; // [rsp+90h] [rbp-70h]
  hkArray<hkaiPairedEdgeFinder::AccelerationData::BoundaryEdge,hkContainerHeapAllocator> *v20; // [rsp+98h] [rbp-68h]
  hkaiPairedEdgeFinder::PairedEdgeSettings *p_settings; // [rsp+A0h] [rbp-60h]
  hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> *v22; // [rsp+A8h] [rbp-58h]
  bool v23; // [rsp+B0h] [rbp-50h]
  __m128 m_quad; // [rsp+C0h] [rbp-40h]
  __m128 v25; // [rsp+D0h] [rbp-30h]
  hkAabb aabbOut; // [rsp+E0h] [rbp-20h] BYREF
  hkaiPairedEdgeFinder::AccelerationData::BoundaryEdge v27; // [rsp+128h] [rbp+28h]

  v3.m_quad = (__m128)settingsIn->m_up;
  *(_OWORD *)&settings.m_minLength = *(_OWORD *)&settingsIn->m_minLength;
  v5 = *(__m128i *)&settingsIn->m_matchAngles.m_bool;
  settings.m_up = (hkVector4f)v3.m_quad;
  v6 = *(_OWORD *)&settingsIn->m_maxHorizontalDelta;
  *(__m128i *)&settings.m_matchAngles.m_bool = v5;
  *(_OWORD *)&settings.m_maxHorizontalDelta = v6;
  if ( !(unsigned __int8)_mm_cvtsi128_si32(_mm_srli_si128(v5, 2))
    || (settings.m_minHorizontalDelta = 0.0, settings.m_maxHorizontalDelta > 0.0) )
  {
    m_sectionUid = this->m_fromNavMeshInstance.m_pntr->m_sectionUid;
    m_pntr = this->m_toNavMeshInstance.m_pntr;
    v9 = m_pntr->m_sectionUid;
    v19 = m_pntr;
    p_m_boundaryEdges = &this->m_toAccelerationData.m_pntr->m_boundaryEdges;
    collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkaiPairedEdgeFinder::PairedEdgeQuery::`vftable;
    v20 = p_m_boundaryEdges;
    v23 = m_sectionUid == v9;
    p_settings = &settings;
    v11 = this->m_fromAccelerationData.m_pntr;
    v22 = pairsOut;
    m_size = v11->m_boundaryEdges.m_size;
    for ( i = 0i64; i < m_size; ++i )
    {
      v27 = this->m_fromAccelerationData.m_pntr->m_boundaryEdges.m_data[i];
      hkaiNavMeshInstance::getEdgePoints(this->m_fromNavMeshInstance.m_pntr, v27.m_edgeIndex, &edgeA, &edgeB);
      m_quad = edgeB.m_quad;
      v25 = edgeA.m_quad;
      v18 = v27;
      hkaiPairedEdgeFinder::buildPairedEdgeAabb(&edgeB, &edgeA, &settings, &aabbOut);
      hkcdDynamicAabbTree::queryAabb(this->m_toAccelerationData.m_pntr->m_boundaryEdgeTree.m_pntr, &aabbOut, &collector);
    }
  }
}

// File Line: 550
// RVA: 0xC3BE60
void __fastcall hkaiPairedEdgeFinder::findInternalStarts(
        hkaiPairedEdgeFinder *this,
        hkaiPairedEdgeFinder::PairedEdgeSettings *settings,
        hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> *pairsOut)
{
  __int64 v3; // rbx
  hkaiPairedEdgeFinder::PairedEdgeSettings *v5; // r14
  hkVector4f v6; // xmm8
  hkaiPairedEdgeFinder *v7; // rdi
  __int64 v8; // rcx
  __m128 v9; // xmm9
  hkaiPairedEdgeFinder::AccelerationData *m_pntr; // rax
  hkaiNavMeshInstance *v11; // rdi
  int m_numOriginalEdges; // edx
  unsigned __int64 index; // rbx
  hkaiNavMesh::Edge *v14; // rax
  int m_numOriginalVertices; // edx
  __int64 m_a; // rcx
  __m128 *p_m_quad; // rcx
  __m128 m_quad; // xmm4
  __m128 v19; // xmm5
  __int64 m_b; // rax
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
  int v31; // r13d
  int v32; // r14d
  int v33; // r12d
  hkaiIntervalPartition::Interval *Interval; // rax
  int m_data; // r15d
  hkaiIntervalPartition::Interval *v36; // rdi
  __int64 v37; // rcx
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  hkaiPairedEdgeFinder::EdgePair *v40; // rdx
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  hkaiIntervalPartition partition; // [rsp+50h] [rbp-A8h] BYREF
  hkaiIntervalPartition v44; // [rsp+60h] [rbp-98h] BYREF
  __int64 m_size; // [rsp+70h] [rbp-88h]
  hkVector4f displacement; // [rsp+78h] [rbp-80h] BYREF
  hkVector4f xVector; // [rsp+88h] [rbp-70h] BYREF
  hkVector4f startLeftOut; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f toLeft; // [rsp+A8h] [rbp-50h] BYREF
  hkVector4f toRight; // [rsp+B8h] [rbp-40h] BYREF
  hkVector4f leftOut; // [rsp+C8h] [rbp-30h] BYREF
  hkVector4f fwdDir; // [rsp+D8h] [rbp-20h] BYREF
  hkVector4f filteredStartLeft; // [rsp+E8h] [rbp-10h] BYREF
  hkVector4f origEndRight; // [rsp+F8h] [rbp+0h] BYREF
  hkVector4f filteredStartRight; // [rsp+108h] [rbp+10h] BYREF
  hkVector4f rightOut; // [rsp+118h] [rbp+20h] BYREF
  hkVector4f filteredEndLeft; // [rsp+128h] [rbp+30h] BYREF
  hkVector4f origEndLeft; // [rsp+138h] [rbp+40h] BYREF
  hkVector4f filteredEndRight; // [rsp+148h] [rbp+50h] BYREF
  hkVector4f startRightOut; // [rsp+158h] [rbp+60h] BYREF
  hkaiNavMeshInstanceSegmentCaster v61; // [rsp+168h] [rbp+70h] BYREF
  hkaiPairedEdgeFinder *retaddr; // [rsp+238h] [rbp+140h]
  __int64 v64; // [rsp+250h] [rbp+158h]

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
  m_size = v7->m_toAccelerationData.m_pntr->m_boundaryEdges.m_size;
  if ( m_size > 0 )
  {
    v64 = v3;
    v9 = _mm_shuffle_ps(v6.m_quad, v6.m_quad, 201);
    do
    {
      m_pntr = v7->m_toAccelerationData.m_pntr;
      v11 = v7->m_fromNavMeshInstance.m_pntr;
      m_numOriginalEdges = v11->m_numOriginalEdges;
      index = (unsigned __int64)m_pntr->m_boundaryEdges.m_data[v8];
      displacement.m_quad.m128_u64[0] = index;
      v14 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__21(
              v11->m_originalEdges,
              m_numOriginalEdges,
              &v11->m_instancedEdges,
              &v11->m_ownedEdges,
              &v11->m_edgeMap,
              SHIDWORD(index));
      m_numOriginalVertices = v11->m_numOriginalVertices;
      m_a = v14->m_a;
      if ( (int)m_a >= m_numOriginalVertices )
        p_m_quad = &v11->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices].m_quad;
      else
        p_m_quad = &v11->m_originalVertices[m_a].m_quad;
      m_quad = v11->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
      v19 = v11->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
      m_b = v14->m_b;
      v21 = v11->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
      v22 = v11->m_referenceFrame.m_transform.m_translation.m_quad;
      v23 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 0), v19),
                  _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 85), m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 170), v21)),
              v22);
      if ( (int)m_b >= m_numOriginalVertices )
        v24 = &v11->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices].m_quad;
      else
        v24 = &v11->m_originalVertices[m_b].m_quad;
      v25 = *v24;
      toLeft.m_quad = v23;
      toRight.m_quad = _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v19),
                             _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), m_quad)),
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
                          _mm_cmple_ps(v29, (__m128)0i64),
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
        v33 = displacement.m_quad.m128_i32[1];
        do
        {
          Interval = hkaiIntervalPartition::getInterval(&partition, v32);
          m_data = Interval->m_data;
          v36 = Interval;
          hkaiIntervalPartition::Interval::interpolateParallelogram(
            Interval,
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
                 (hkaiPairedEdgeFinder::PairedEdgeSettings *)this,
                 &filteredStartLeft,
                 &filteredStartRight,
                 &filteredEndLeft,
                 &filteredEndRight) )
          {
            if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, pairsOut, 80);
            v37 = pairsOut->m_size;
            v38 = filteredStartLeft.m_quad;
            v39 = filteredStartRight.m_quad;
            pairsOut->m_size = v37 + 1;
            v40 = &pairsOut->m_data[v37];
            v40->m_startLeft.m_quad = v38;
            v41 = filteredEndLeft.m_quad;
            v40->m_startRight.m_quad = v39;
            v40->m_startFace = m_data;
            v40->m_startEdge = -1;
            v40->m_endFace = index;
            v40->m_endEdge = v33;
            v42 = filteredEndRight.m_quad;
            v40->m_endLeft.m_quad = v41;
            v40->m_endRight.m_quad = v42;
          }
          ++v32;
        }
        while ( v32 < v31 );
      }
      v5 = (hkaiPairedEdgeFinder::PairedEdgeSettings *)this;
      v7 = retaddr;
      v8 = v64 + 1;
      v64 = v8;
    }
    while ( v8 < m_size );
  }
  v44.m_intervals.m_size = 0;
  if ( v44.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v44.m_intervals.m_data,
      20 * (v44.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  v44.m_intervals.m_data = 0i64;
  v44.m_intervals.m_capacityAndFlags = 0x80000000;
  partition.m_intervals.m_size = 0;
  if ( partition.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      partition.m_intervals.m_data,
      20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  partition.m_intervals.m_data = 0i64;
  partition.m_intervals.m_capacityAndFlags = 0x80000000;
  hkaiNavMeshInstanceSegmentCaster::~hkaiNavMeshInstanceSegmentCaster(&v61);
}

// File Line: 630
// RVA: 0xC3C3A0
void __fastcall hkaiPairedEdgeFinder::findInternalEnds(
        hkaiPairedEdgeFinder *this,
        hkaiPairedEdgeFinder::PairedEdgeSettings *settings,
        hkArray<hkaiPairedEdgeFinder::EdgePair,hkContainerTempAllocator> *pairsOut)
{
  __int64 v3; // rbx
  hkaiPairedEdgeFinder::PairedEdgeSettings *v5; // r14
  hkVector4f v6; // xmm8
  hkaiPairedEdgeFinder *v7; // rdi
  __int64 v8; // rcx
  __m128 v9; // xmm9
  hkaiPairedEdgeFinder::AccelerationData *m_pntr; // rax
  hkaiNavMeshInstance *v11; // rdi
  int m_numOriginalEdges; // edx
  unsigned __int64 index; // rbx
  hkaiNavMesh::Edge *v14; // rax
  int m_numOriginalVertices; // edx
  __int64 m_a; // rcx
  __m128 *p_m_quad; // rcx
  __m128 m_quad; // xmm4
  __m128 v19; // xmm5
  __int64 m_b; // rax
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
  int v31; // r13d
  int v32; // r14d
  int v33; // r12d
  hkaiIntervalPartition::Interval *Interval; // rax
  int m_data; // r15d
  hkaiIntervalPartition::Interval *v36; // rdi
  __int64 v37; // rcx
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  hkaiPairedEdgeFinder::EdgePair *v40; // rdx
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  hkaiIntervalPartition partition; // [rsp+50h] [rbp-A8h] BYREF
  hkaiIntervalPartition v44; // [rsp+60h] [rbp-98h] BYREF
  __int64 m_size; // [rsp+70h] [rbp-88h]
  hkVector4f displacement; // [rsp+78h] [rbp-80h] BYREF
  hkVector4f xVector; // [rsp+88h] [rbp-70h] BYREF
  hkVector4f startLeftOut; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f fromLeft; // [rsp+A8h] [rbp-50h] BYREF
  hkVector4f fromRight; // [rsp+B8h] [rbp-40h] BYREF
  hkVector4f origStartLeft; // [rsp+C8h] [rbp-30h] BYREF
  hkVector4f fwdDir; // [rsp+D8h] [rbp-20h] BYREF
  hkVector4f filteredStartLeft; // [rsp+E8h] [rbp-10h] BYREF
  hkVector4f rightOut; // [rsp+F8h] [rbp+0h] BYREF
  hkVector4f filteredStartRight; // [rsp+108h] [rbp+10h] BYREF
  hkVector4f origStartRight; // [rsp+118h] [rbp+20h] BYREF
  hkVector4f filteredEndLeft; // [rsp+128h] [rbp+30h] BYREF
  hkVector4f leftOut; // [rsp+138h] [rbp+40h] BYREF
  hkVector4f filteredEndRight; // [rsp+148h] [rbp+50h] BYREF
  hkVector4f startRightOut; // [rsp+158h] [rbp+60h] BYREF
  hkaiNavMeshInstanceSegmentCaster v61; // [rsp+168h] [rbp+70h] BYREF
  hkaiPairedEdgeFinder *retaddr; // [rsp+238h] [rbp+140h]
  __int64 v64; // [rsp+250h] [rbp+158h]

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
  m_size = v7->m_fromAccelerationData.m_pntr->m_boundaryEdges.m_size;
  if ( m_size > 0 )
  {
    v64 = v3;
    v9 = _mm_shuffle_ps(v6.m_quad, v6.m_quad, 201);
    do
    {
      m_pntr = v7->m_fromAccelerationData.m_pntr;
      v11 = v7->m_fromNavMeshInstance.m_pntr;
      m_numOriginalEdges = v11->m_numOriginalEdges;
      index = (unsigned __int64)m_pntr->m_boundaryEdges.m_data[v8];
      displacement.m_quad.m128_u64[0] = index;
      v14 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__21(
              v11->m_originalEdges,
              m_numOriginalEdges,
              &v11->m_instancedEdges,
              &v11->m_ownedEdges,
              &v11->m_edgeMap,
              SHIDWORD(index));
      m_numOriginalVertices = v11->m_numOriginalVertices;
      m_a = v14->m_a;
      if ( (int)m_a >= m_numOriginalVertices )
        p_m_quad = &v11->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices].m_quad;
      else
        p_m_quad = &v11->m_originalVertices[m_a].m_quad;
      m_quad = v11->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
      v19 = v11->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
      m_b = v14->m_b;
      v21 = v11->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
      v22 = v11->m_referenceFrame.m_transform.m_translation.m_quad;
      v23 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 0), v19),
                  _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 85), m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 170), v21)),
              v22);
      if ( (int)m_b >= m_numOriginalVertices )
        v24 = &v11->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices].m_quad;
      else
        v24 = &v11->m_originalVertices[m_b].m_quad;
      v25 = *v24;
      fromRight.m_quad = v23;
      fromLeft.m_quad = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v19),
                              _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), m_quad)),
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
                          _mm_cmple_ps(v29, (__m128)0i64),
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
        v33 = displacement.m_quad.m128_i32[1];
        do
        {
          Interval = hkaiIntervalPartition::getInterval(&partition, v32);
          m_data = Interval->m_data;
          v36 = Interval;
          hkaiIntervalPartition::Interval::interpolateParallelogram(
            Interval,
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
                 (hkaiPairedEdgeFinder::PairedEdgeSettings *)this,
                 &filteredStartLeft,
                 &filteredStartRight,
                 &filteredEndLeft,
                 &filteredEndRight) )
          {
            if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, pairsOut, 80);
            v37 = pairsOut->m_size;
            v38 = filteredStartLeft.m_quad;
            v39 = filteredStartRight.m_quad;
            pairsOut->m_size = v37 + 1;
            v40 = &pairsOut->m_data[v37];
            v40->m_startLeft.m_quad = v38;
            v41 = filteredEndLeft.m_quad;
            v40->m_startRight.m_quad = v39;
            v40->m_startFace = index;
            v40->m_startEdge = v33;
            v40->m_endFace = m_data;
            v40->m_endEdge = -1;
            v42 = filteredEndRight.m_quad;
            v40->m_endLeft.m_quad = v41;
            v40->m_endRight.m_quad = v42;
          }
          ++v32;
        }
        while ( v32 < v31 );
      }
      v5 = (hkaiPairedEdgeFinder::PairedEdgeSettings *)this;
      v7 = retaddr;
      v8 = v64 + 1;
      v64 = v8;
    }
    while ( v8 < m_size );
  }
  v44.m_intervals.m_size = 0;
  if ( v44.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v44.m_intervals.m_data,
      20 * (v44.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  v44.m_intervals.m_data = 0i64;
  v44.m_intervals.m_capacityAndFlags = 0x80000000;
  partition.m_intervals.m_size = 0;
  if ( partition.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      partition.m_intervals.m_data,
      20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  partition.m_intervals.m_data = 0i64;
  partition.m_intervals.m_capacityAndFlags = 0x80000000;
  hkaiNavMeshInstanceSegmentCaster::~hkaiNavMeshInstanceSegmentCaster(&v61);
}

// File Line: 711
// RVA: 0xC3D3C0
void __fastcall hkaiPairedEdgeFinder::calcInternalStartFaceCast(
        hkaiPairedEdgeFinder::PairedEdgeSettings *settings,
        hkVector4f *toLeft,
        hkVector4f *toRight,
        hkVector4f *fwdDir,
        hkVector4f *startLeftOut,
        hkVector4f *startRightOut,
        hkVector4f *displacementOut)
{
  hkVector4f v7; // xmm5
  __m128 v8; // xmm0
  __m128 v9; // xmm4
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128 v12; // xmm1

  v7.m_quad = (__m128)settings->m_up;
  v8 = _mm_shuffle_ps((__m128)LODWORD(settings->m_minHeightDelta), (__m128)LODWORD(settings->m_minHeightDelta), 0);
  v9 = _mm_sub_ps(
         _mm_shuffle_ps((__m128)LODWORD(settings->m_maxHeightDelta), (__m128)LODWORD(settings->m_maxHeightDelta), 0),
         v8);
  v10 = _mm_mul_ps(settings->m_up.m_quad, v8);
  v11 = _mm_shuffle_ps((__m128)LODWORD(INTERNAL_CAST_SET_OUTWARD), (__m128)LODWORD(INTERNAL_CAST_SET_OUTWARD), 0);
  v12 = _mm_sub_ps(toLeft->m_quad, v10);
  *startLeftOut = (hkVector4f)v12;
  startLeftOut->m_quad = _mm_sub_ps(v12, _mm_mul_ps(fwdDir->m_quad, v11));
  startRightOut->m_quad = _mm_sub_ps(toRight->m_quad, v10);
  startLeftOut->m_quad = _mm_sub_ps(startLeftOut->m_quad, _mm_mul_ps(fwdDir->m_quad, v11));
  displacementOut->m_quad = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v9), v7.m_quad);
}

// File Line: 729
// RVA: 0xC3D440
void __fastcall hkaiPairedEdgeFinder::calcInternalEndFaceCast(
        hkaiPairedEdgeFinder::PairedEdgeSettings *settings,
        hkVector4f *fromLeft,
        hkVector4f *fromRight,
        hkVector4f *fwdDir,
        hkVector4f *startLeftOut,
        hkVector4f *startRightOut,
        hkVector4f *displacementOut)
{
  hkVector4f v7; // xmm5
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  __m128 v13; // xmm1

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
  v12 = _mm_sub_ps(fromLeft->m_quad, v10);
  *startLeftOut = (hkVector4f)v12;
  startLeftOut->m_quad = _mm_add_ps(_mm_mul_ps(fwdDir->m_quad, v8), v12);
  v13 = _mm_sub_ps(fromRight->m_quad, v10);
  *startRightOut = (hkVector4f)v13;
  startRightOut->m_quad = _mm_add_ps(_mm_mul_ps(fwdDir->m_quad, v8), v13);
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
void __fastcall hkaiPairedEdgeFinder::PairedEdgeSettings::PairedEdgeSettings(
        hkaiPairedEdgeFinder::PairedEdgeSettings *this)
{
  *(_WORD *)&this->m_matchAngles.m_bool = 1;
  this->m_findInternalEnds.m_bool = 0;
}


// File Line: 47
// RVA: 0xB4140
char __fastcall UFG::SweptSphereQuery(float r0, UFG::qVector3 *p0, UFG::qVector3 *p1, float r1, UFG::qVector3 *q0, UFG::qVector3 *q1, float *t)
{
  __m128 v7; // xmm8
  float v8; // xmm10_4
  float v9; // xmm7_4
  float v10; // xmm9_4
  __m128 v11; // xmm4
  char result; // al
  __m128 v13; // xmm3
  float v14; // xmm11_4
  float v15; // xmm12_4
  float v16; // xmm2_4
  __m128 v17; // xmm1
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm2_4

  v7 = (__m128)LODWORD(p0->x);
  v7.m128_f32[0] = v7.m128_f32[0] - q0->x;
  v8 = p0->z - q0->z;
  v9 = r1;
  v11 = v7;
  v10 = p0->y - q0->y;
  v11.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v10 * v10)) + (float)(v8 * v8);
  if ( COERCE_FLOAT(_mm_sqrt_ps(v11)) > (float)(r0 + r1) )
  {
    v13 = (__m128)LODWORD(p1->x);
    v13.m128_f32[0] = (float)(v13.m128_f32[0] - p0->x) - (float)(q1->x - q0->x);
    v14 = (float)(p1->y - p0->y) - (float)(q1->y - q0->y);
    v15 = (float)(p1->z - p0->z) - (float)(q1->z - q0->z);
    v16 = (float)((float)(v14 * v14) + (float)(v13.m128_f32[0] * v13.m128_f32[0])) + (float)(v15 * v15);
    if ( v16 <= 0.0
      || (v13.m128_f32[0] = (float)((float)((float)(v13.m128_f32[0] * v7.m128_f32[0]) + (float)(v14 * v10))
                                  + (float)(v15 * v8))
                          * 2.0,
          v17 = v13,
          v17.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0])
                          - (float)((float)(v11.m128_f32[0] - (float)((float)(r0 * r0) + (float)(v9 * v9)))
                                  * (float)(v16 * 4.0)),
          v17.m128_f32[0] < 0.0)
      || (LODWORD(v18) = (unsigned __int128)_mm_sqrt_ps(v17),
          v19 = 1.0 / (float)(v16 * 2.0),
          v20 = (float)(COERCE_FLOAT(v13.m128_i32[0] ^ _xmm[0]) - v18) * v19,
          (float)((float)(v18 - v13.m128_f32[0]) * v19) < 0.0)
      || v20 > 1.0 )
    {
      result = 0;
    }
    else
    {
      if ( v20 <= 0.0 )
        v20 = 0.0;
      *t = v20;
      result = 1;
    }
  }
  else
  {
    *t = 0.0;
    result = 1;
  }
  return result;
}

// File Line: 93
// RVA: 0xB3C10
__int64 __fastcall UFG::SweptSphereCapsuleQuery(float r0, UFG::qVector3 *p0, UFG::qVector3 *p1, UFG::qVector3 *capsuleA)
{
  UFG::qVector3 *v4; // rdi
  UFG::qVector3 *v5; // r13
  UFG::qVector3 *v6; // rbx
  unsigned __int8 v7; // r12
  void (__fastcall ***v8)(_QWORD, signed __int64); // r14
  _QWORD **v9; // rax
  hkpSphereShape *v10; // rax
  void (__fastcall ***v11)(_QWORD, signed __int64); // rax
  void (__fastcall ***v12)(_QWORD, signed __int64); // r15
  _QWORD **v13; // rax
  __int64 v14; // rax
  hkpCdBody *v15; // rsi
  signed __int64 v16; // rbx
  _QWORD **v17; // rax
  hkpCapsuleShape *v18; // rax
  void (__fastcall ***v19)(_QWORD, signed __int64); // rax
  _QWORD **v20; // rax
  _QWORD *v21; // rax
  hkpCdBody *v22; // rdi
  signed __int64 v23; // rbx
  hkpWorld *v24; // r8
  __m128 v25; // xmm4
  hkpProcessCollisionInput *v26; // rcx
  __m128 v27; // xmm4
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  _QWORD **v30; // rax
  _QWORD **v31; // rax
  hkpCollisionDispatcher *v33; // [rsp+30h] [rbp-A8h]
  unsigned int v34; // [rsp+38h] [rbp-A0h]
  unsigned int v35; // [rsp+3Ch] [rbp-9Ch]
  float v36; // [rsp+40h] [rbp-98h]
  hkpCollisionFilter *v37; // [rsp+48h] [rbp-90h]
  hkpConvexListFilter *v38; // [rsp+50h] [rbp-88h]
  hkVector4f v39; // [rsp+58h] [rbp-80h]
  char v40[24]; // [rsp+68h] [rbp-70h]
  hkpCollisionAgentConfig *v41; // [rsp+80h] [rbp-58h]
  hkVector4f vertexA; // [rsp+88h] [rbp-50h]
  __int64 v43; // [rsp+98h] [rbp-40h]
  void **v44; // [rsp+A8h] [rbp-30h]
  int v45; // [rsp+B0h] [rbp-28h]
  __m128 v46; // [rsp+C8h] [rbp-10h]
  __int64 v47; // [rsp+D8h] [rbp+0h]
  hkVector4f vertexB; // [rsp+108h] [rbp+30h]
  void **v49; // [rsp+118h] [rbp+40h]
  int v50; // [rsp+120h] [rbp+48h]
  __m128 v51; // [rsp+138h] [rbp+60h]
  __int64 v52; // [rsp+148h] [rbp+70h]
  __m128 v53; // [rsp+178h] [rbp+A0h]
  __m128 v54; // [rsp+188h] [rbp+B0h]
  __m128 v55; // [rsp+198h] [rbp+C0h]
  __m128 v56; // [rsp+1A8h] [rbp+D0h]
  __m128 v57; // [rsp+1B8h] [rbp+E0h]
  __m128 v58; // [rsp+1C8h] [rbp+F0h]
  __m128 v59; // [rsp+1D8h] [rbp+100h]
  __int128 v60; // [rsp+1E8h] [rbp+110h]
  __int64 v61; // [rsp+250h] [rbp+178h]
  hkpCapsuleShape *retaddr; // [rsp+268h] [rbp+190h]
  float radius; // [rsp+270h] [rbp+198h]
  _DWORD *v64; // [rsp+278h] [rbp+1A0h]

  v43 = -2i64;
  v4 = capsuleA;
  v5 = p1;
  v6 = p0;
  v7 = 0;
  v44 = &hkpClosestCdPointCollector::`vftable;
  v8 = 0i64;
  v47 = 0i64;
  v46 = _mm_shuffle_ps(v46, _mm_unpackhi_ps(v46, (__m128)xmmword_141A712A0), 196);
  v45 = 2139095022;
  v49 = &hkpClosestCdPointCollector::`vftable;
  v52 = 0i64;
  v51 = _mm_shuffle_ps(v51, _mm_unpackhi_ps(v51, (__m128)xmmword_141A712A0), 196);
  v50 = 2139095022;
  v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkpSphereShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(v9[11], 56i64);
  v61 = (__int64)v10;
  if ( v10 )
  {
    hkpSphereShape::hkpSphereShape(v10, r0);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v53 = transform.m_quad;
  v54 = direction.m_quad;
  v55 = stru_141A71280.m_quad;
  v56 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(v6->x), (__m128)LODWORD(v6->z)),
          _mm_unpacklo_ps((__m128)LODWORD(v6->y), (__m128)(unsigned int)FLOAT_1_0));
  v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v13[11] + 8i64))(v13[11], 112i64);
  v15 = (hkpCdBody *)v14;
  v61 = v14;
  if ( v14 )
  {
    *(_QWORD *)v14 = v12;
    *(_QWORD *)(v14 + 16) = &v53;
    *(_QWORD *)(v14 + 24) = 0i64;
    *(_DWORD *)(v14 + 8) = -1;
    *(_BYTE *)(v14 + 32) = 0;
    v16 = v14 + 36;
    *(_DWORD *)v16 = 0;
    *(_WORD *)(v16 + 4) = 32512;
    *(_DWORD *)(v16 + 8) = 0;
    *(_BYTE *)(v16 + 6) = -1;
    hkpCollidable::BoundingVolumeData::BoundingVolumeData((hkpCollidable::BoundingVolumeData *)(v14 + 48));
    v15[3].m_shapeKey = -1082130432;
    BYTE1(v15[1].m_shapeKey) = -36;
    BYTE1(v15[1].m_shape) = 8;
    WORD1(v15[1].m_shape) = 0;
  }
  else
  {
    v15 = 0i64;
  }
  vertexA.m_quad = _mm_unpacklo_ps(
                     _mm_unpacklo_ps((__m128)LODWORD(v4->x), (__m128)LODWORD(v4->z)),
                     _mm_unpacklo_ps((__m128)LODWORD(v4->y), (__m128)(unsigned int)FLOAT_1_0));
  vertexB.m_quad = _mm_unpacklo_ps(
                     _mm_unpacklo_ps(
                       (__m128)LODWORD(retaddr->vfptr),
                       (__m128)*(unsigned int *)&retaddr->m_memSizeAndFlags),
                     _mm_unpacklo_ps((__m128)HIDWORD(retaddr->vfptr), (__m128)(unsigned int)FLOAT_1_0));
  v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (hkpCapsuleShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v17[11] + 8i64))(v17[11], 80i64);
  retaddr = v18;
  if ( v18 )
  {
    hkpCapsuleShape::hkpCapsuleShape(v18, &vertexA, &vertexB, radius);
    v8 = v19;
  }
  v57 = transform.m_quad;
  v58 = direction.m_quad;
  v59 = stru_141A71280.m_quad;
  v60 = 0i64;
  v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v21 = (_QWORD *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v20[11] + 8i64))(v20[11], 112i64);
  v22 = (hkpCdBody *)v21;
  retaddr = (hkpCapsuleShape *)v21;
  if ( v21 )
  {
    *v21 = v8;
    v21[2] = &v57;
    v21[3] = 0i64;
    *((_DWORD *)v21 + 2) = -1;
    *((_BYTE *)v21 + 32) = 0;
    v23 = (signed __int64)v21 + 36;
    *(_DWORD *)v23 = 0;
    *(_WORD *)(v23 + 4) = 32512;
    *(_DWORD *)(v23 + 8) = 0;
    *(_BYTE *)(v23 + 6) = -1;
    hkpCollidable::BoundingVolumeData::BoundingVolumeData((hkpCollidable::BoundingVolumeData *)(v21 + 6));
    v22[3].m_shapeKey = -1082130432;
    BYTE1(v22[1].m_shapeKey) = -36;
    BYTE1(v22[1].m_shape) = 8;
    WORD1(v22[1].m_shape) = 0;
  }
  else
  {
    v22 = 0i64;
  }
  v24 = UFG::BasePhysicsSystem::mInstance->mWorld;
  v25 = _mm_sub_ps(
          _mm_unpacklo_ps(
            _mm_unpacklo_ps((__m128)LODWORD(v5->x), (__m128)LODWORD(v5->z)),
            _mm_unpacklo_ps((__m128)LODWORD(v5->y), (__m128)(unsigned int)FLOAT_1_0)),
          v56);
  v35 = 0;
  *(_DWORD *)&v40[16] = 872415232;
  v26 = v24->m_collisionInput;
  v33 = v26->m_dispatcher.m_storage;
  v34 = v26->m_weldClosestPoints.m_storage;
  v35 = v26->m_forceAcceptContactPoints.m_storage;
  v36 = v26->m_tolerance.m_storage;
  v37 = v26->m_filter.m_storage;
  v38 = v26->m_convexListFilter.m_storage;
  v39.m_quad.m128_i32[0] = v26->m_createPredictiveAgents.m_storage;
  *(hkVector4f *)((char *)&v39 + 8) = v26->m_aabb32Info.m_bitOffsetLow;
  *(hkVector4f *)&v40[8] = v26->m_aabb32Info.m_bitOffsetHigh;
  v39.m_quad = (__m128)v26->m_aabb32Info.m_bitScale;
  v41 = v26->m_config;
  *(__m128 *)v40 = v25;
  v27 = _mm_mul_ps(v25, v25);
  v28 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 170), _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)));
  v29 = _mm_rsqrt_ps(v28);
  *(_DWORD *)&v40[20] = (unsigned __int128)_mm_andnot_ps(
                                             _mm_cmpleps(v28, (__m128)0i64),
                                             _mm_mul_ps(
                                               _mm_mul_ps(
                                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                                                 _mm_mul_ps(v29, *(__m128 *)_xmm)),
                                               v28));
  v36 = 0.00000011920929;
  *(_DWORD *)&v40[16] = 872415232;
  v24->m_collisionDispatcher->m_agent2Func[(unsigned __int8)v24->m_collisionDispatcher->m_agent2Types[(unsigned __int8)v15->m_shape->m_type.m_storage][(unsigned __int8)v22->m_shape->m_type.m_storage]].m_linearCastFunc(
    v15,
    v22,
    (hkpLinearCastCollisionInput *)&v33,
    (hkpCdPointCollector *)&v44,
    (hkpCdPointCollector *)&v49);
  if ( v52 )
  {
    *v64 = 0;
  }
  else
  {
    if ( !v47 )
      goto LABEL_17;
    *v64 = LODWORD(v46.m128_f32[3]);
  }
  v7 = 1;
LABEL_17:
  v30 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpCdBody *, signed __int64))(*v30[11] + 16i64))(v30[11], v15, 32i64);
  v31 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpCdBody *, signed __int64))(*v31[11] + 16i64))(v31[11], v22, 32i64);
  if ( v12 )
    (**v12)(v12, 1i64);
  if ( v8 )
    (**v8)(v8, 1i64);
  return v7;
}


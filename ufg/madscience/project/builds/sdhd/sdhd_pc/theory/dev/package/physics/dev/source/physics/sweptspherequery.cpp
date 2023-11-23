// File Line: 47
// RVA: 0xB4140
char __fastcall UFG::SweptSphereQuery(
        float r0,
        UFG::qVector3 *p0,
        UFG::qVector3 *p1,
        float r1,
        UFG::qVector3 *q0,
        UFG::qVector3 *q1,
        float *t)
{
  __m128 x_low; // xmm8
  float v8; // xmm10_4
  float v10; // xmm9_4
  __m128 v11; // xmm4
  __m128 v13; // xmm3
  float v14; // xmm11_4
  float v15; // xmm12_4
  float v16; // xmm2_4
  __m128 v17; // xmm1
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm2_4

  x_low = (__m128)LODWORD(p0->x);
  x_low.m128_f32[0] = x_low.m128_f32[0] - q0->x;
  v8 = p0->z - q0->z;
  v11 = x_low;
  v10 = p0->y - q0->y;
  v11.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v10 * v10)) + (float)(v8 * v8);
  if ( _mm_sqrt_ps(v11).m128_f32[0] > (float)(r0 + r1) )
  {
    v13 = (__m128)LODWORD(p1->x);
    v13.m128_f32[0] = (float)(v13.m128_f32[0] - p0->x) - (float)(q1->x - q0->x);
    v14 = (float)(p1->y - p0->y) - (float)(q1->y - q0->y);
    v15 = (float)(p1->z - p0->z) - (float)(q1->z - q0->z);
    v16 = (float)((float)(v14 * v14) + (float)(v13.m128_f32[0] * v13.m128_f32[0])) + (float)(v15 * v15);
    if ( v16 <= 0.0 )
      return 0;
    v13.m128_f32[0] = (float)((float)((float)(v13.m128_f32[0] * x_low.m128_f32[0]) + (float)(v14 * v10))
                            + (float)(v15 * v8))
                    * 2.0;
    v17 = v13;
    v17.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0])
                    - (float)((float)(v11.m128_f32[0] - (float)((float)(r0 * r0) + (float)(r1 * r1)))
                            * (float)(v16 * 4.0));
    if ( v17.m128_f32[0] < 0.0 )
      return 0;
    v18 = _mm_sqrt_ps(v17).m128_f32[0];
    v19 = 1.0 / (float)(v16 * 2.0);
    v20 = (float)(COERCE_FLOAT(v13.m128_i32[0] ^ _xmm[0]) - v18) * v19;
    if ( (float)((float)(v18 - v13.m128_f32[0]) * v19) < 0.0 || v20 > 1.0 )
    {
      return 0;
    }
    else
    {
      if ( v20 <= 0.0 )
        v20 = 0.0;
      *t = v20;
      return 1;
    }
  }
  else
  {
    *t = 0.0;
    return 1;
  }
}

// File Line: 93
// RVA: 0xB3C10
__int64 __fastcall UFG::SweptSphereCapsuleQuery(
        float r0,
        UFG::qVector3 *p0,
        UFG::qVector3 *p1,
        UFG::qVector3 *capsuleA)
{
  unsigned __int8 v7; // r12
  void (__fastcall ***v8)(_QWORD, __int64); // r14
  _QWORD **Value; // rax
  hkpSphereShape *v10; // rax
  void (__fastcall ***v11)(_QWORD, __int64); // rax
  void (__fastcall ***v12)(_QWORD, __int64); // r15
  _QWORD **v13; // rax
  __int64 v14; // rax
  hkpCdBody *v15; // rsi
  _QWORD **v16; // rax
  hkpCapsuleShape *v17; // rax
  void (__fastcall ***v18)(_QWORD, __int64); // rax
  _QWORD **v19; // rax
  _QWORD *v20; // rax
  hkpCdBody *v21; // rdi
  hkpWorld *mWorld; // r8
  __m128 v23; // xmm4
  hkpProcessCollisionInput *m_collisionInput; // rcx
  __m128 v25; // xmm4
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  _QWORD **v28; // rax
  _QWORD **v29; // rax
  hkpCollisionDispatcher *m_storage; // [rsp+30h] [rbp-A8h] BYREF
  unsigned int v32; // [rsp+38h] [rbp-A0h]
  unsigned int v33; // [rsp+3Ch] [rbp-9Ch]
  int m_storage_low; // [rsp+40h] [rbp-98h]
  hkpCollisionFilter *v35; // [rsp+48h] [rbp-90h]
  hkpConvexListFilter *v36; // [rsp+50h] [rbp-88h]
  _BYTE v37[40]; // [rsp+58h] [rbp-80h]
  hkpCollisionAgentConfig *m_config; // [rsp+80h] [rbp-58h]
  hkVector4f vertexA; // [rsp+88h] [rbp-50h] BYREF
  __int64 v40; // [rsp+98h] [rbp-40h]
  void **v41; // [rsp+A8h] [rbp-30h] BYREF
  int v42; // [rsp+B0h] [rbp-28h]
  __m128 v43; // [rsp+C8h] [rbp-10h]
  __int64 v44; // [rsp+D8h] [rbp+0h]
  hkVector4f vertexB; // [rsp+108h] [rbp+30h] BYREF
  void **v46; // [rsp+118h] [rbp+40h] BYREF
  int v47; // [rsp+120h] [rbp+48h]
  __m128 v48; // [rsp+138h] [rbp+60h]
  __int64 v49; // [rsp+148h] [rbp+70h]
  __int128 v50[3]; // [rsp+178h] [rbp+A0h] BYREF
  __m128 v51; // [rsp+1A8h] [rbp+D0h]
  __int128 v52[8]; // [rsp+1B8h] [rbp+E0h] BYREF
  __int64 v53; // [rsp+250h] [rbp+178h]
  hkpCapsuleShape *retaddr; // [rsp+268h] [rbp+190h]
  float radius; // [rsp+270h] [rbp+198h]
  _DWORD *v56; // [rsp+278h] [rbp+1A0h]

  v40 = -2i64;
  v7 = 0;
  v41 = &hkpClosestCdPointCollector::`vftable;
  v8 = 0i64;
  v44 = 0i64;
  v43 = _mm_shuffle_ps(v43, _mm_unpackhi_ps(v43, (__m128)xmmword_141A712A0), 196);
  v42 = 2139095022;
  v46 = &hkpClosestCdPointCollector::`vftable;
  v49 = 0i64;
  v48 = _mm_shuffle_ps(v48, _mm_unpackhi_ps(v48, (__m128)xmmword_141A712A0), 196);
  v47 = 2139095022;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkpSphereShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 56i64);
  v53 = (__int64)v10;
  if ( v10 )
  {
    hkpSphereShape::hkpSphereShape(v10, r0);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v50[0] = (__int128)transform.m_quad;
  v50[1] = (__int128)direction.m_quad;
  v50[2] = (__int128)stru_141A71280.m_quad;
  v51 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(p0->x), (__m128)LODWORD(p0->z)),
          _mm_unpacklo_ps((__m128)LODWORD(p0->y), (__m128)(unsigned int)FLOAT_1_0));
  v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v13[11] + 8i64))(v13[11], 112i64);
  v15 = (hkpCdBody *)v14;
  v53 = v14;
  if ( v14 )
  {
    *(_QWORD *)v14 = v12;
    *(_QWORD *)(v14 + 16) = v50;
    *(_QWORD *)(v14 + 24) = 0i64;
    *(_DWORD *)(v14 + 8) = -1;
    *(_BYTE *)(v14 + 32) = 0;
    *(_DWORD *)(v14 + 36) = 0;
    *(_WORD *)(v14 + 40) = 32512;
    *(_DWORD *)(v14 + 44) = 0;
    *(_BYTE *)(v14 + 42) = -1;
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
                     _mm_unpacklo_ps((__m128)LODWORD(capsuleA->x), (__m128)LODWORD(capsuleA->z)),
                     _mm_unpacklo_ps((__m128)LODWORD(capsuleA->y), (__m128)(unsigned int)FLOAT_1_0));
  vertexB.m_quad = _mm_unpacklo_ps(
                     _mm_unpacklo_ps(
                       (__m128)LODWORD(retaddr->vfptr),
                       (__m128)*(unsigned int *)&retaddr->m_memSizeAndFlags),
                     _mm_unpacklo_ps((__m128)HIDWORD(retaddr->vfptr), (__m128)(unsigned int)FLOAT_1_0));
  v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkpCapsuleShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v16[11] + 8i64))(v16[11], 80i64);
  retaddr = v17;
  if ( v17 )
  {
    hkpCapsuleShape::hkpCapsuleShape(v17, &vertexA, &vertexB, radius);
    v8 = v18;
  }
  v52[0] = (__int128)transform.m_quad;
  v52[1] = (__int128)direction.m_quad;
  v52[2] = (__int128)stru_141A71280.m_quad;
  v52[3] = 0i64;
  v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v20 = (_QWORD *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v19[11] + 8i64))(v19[11], 112i64);
  v21 = (hkpCdBody *)v20;
  retaddr = (hkpCapsuleShape *)v20;
  if ( v20 )
  {
    *v20 = v8;
    v20[2] = v52;
    v20[3] = 0i64;
    *((_DWORD *)v20 + 2) = -1;
    *((_BYTE *)v20 + 32) = 0;
    *((_DWORD *)v20 + 9) = 0;
    *((_WORD *)v20 + 20) = 32512;
    *((_DWORD *)v20 + 11) = 0;
    *((_BYTE *)v20 + 42) = -1;
    hkpCollidable::BoundingVolumeData::BoundingVolumeData((hkpCollidable::BoundingVolumeData *)(v20 + 6));
    v21[3].m_shapeKey = -1082130432;
    BYTE1(v21[1].m_shapeKey) = -36;
    BYTE1(v21[1].m_shape) = 8;
    WORD1(v21[1].m_shape) = 0;
  }
  else
  {
    v21 = 0i64;
  }
  mWorld = UFG::BasePhysicsSystem::mInstance->mWorld;
  v23 = _mm_sub_ps(
          _mm_unpacklo_ps(
            _mm_unpacklo_ps((__m128)LODWORD(p1->x), (__m128)LODWORD(p1->z)),
            _mm_unpacklo_ps((__m128)LODWORD(p1->y), (__m128)(unsigned int)FLOAT_1_0)),
          v51);
  v33 = 0;
  *(_DWORD *)&v37[32] = 872415232;
  m_collisionInput = mWorld->m_collisionInput;
  m_storage = m_collisionInput->m_dispatcher.m_storage;
  v32 = m_collisionInput->m_weldClosestPoints.m_storage;
  v33 = m_collisionInput->m_forceAcceptContactPoints.m_storage;
  m_storage_low = LODWORD(m_collisionInput->m_tolerance.m_storage);
  v35 = m_collisionInput->m_filter.m_storage;
  v36 = m_collisionInput->m_convexListFilter.m_storage;
  *(_DWORD *)v37 = m_collisionInput->m_createPredictiveAgents.m_storage;
  *(hkVector4f *)&v37[8] = m_collisionInput->m_aabb32Info.m_bitOffsetLow;
  *(hkVector4f *)&v37[24] = m_collisionInput->m_aabb32Info.m_bitOffsetHigh;
  *(hkVector4f *)v37 = m_collisionInput->m_aabb32Info.m_bitScale;
  m_config = m_collisionInput->m_config;
  *(__m128 *)&v37[16] = v23;
  v25 = _mm_mul_ps(v23, v23);
  v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 170), _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)));
  v27 = _mm_rsqrt_ps(v26);
  *(_DWORD *)&v37[36] = _mm_andnot_ps(
                          _mm_cmple_ps(v26, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                              _mm_mul_ps(v27, *(__m128 *)_xmm)),
                            v26)).m128_u32[0];
  m_storage_low = 872415232;
  *(_DWORD *)&v37[32] = 872415232;
  mWorld->m_collisionDispatcher->m_agent2Func[(unsigned __int8)mWorld->m_collisionDispatcher->m_agent2Types[(unsigned __int8)v15->m_shape->m_type.m_storage][(unsigned __int8)v21->m_shape->m_type.m_storage]].m_linearCastFunc(
    v15,
    v21,
    (hkpLinearCastCollisionInput *)&m_storage,
    (hkpCdPointCollector *)&v41,
    (hkpCdPointCollector *)&v46);
  if ( v49 )
  {
    *v56 = 0;
  }
  else
  {
    if ( !v44 )
      goto LABEL_17;
    *v56 = v43.m128_i32[3];
  }
  v7 = 1;
LABEL_17:
  v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpCdBody *, __int64))(*v28[11] + 16i64))(v28[11], v15, 32i64);
  v29 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpCdBody *, __int64))(*v29[11] + 16i64))(v29[11], v21, 32i64);
  if ( v12 )
    (**v12)(v12, 1i64);
  if ( v8 )
    (**v8)(v8, 1i64);
  return v7;
}emoryRouter.m_sl


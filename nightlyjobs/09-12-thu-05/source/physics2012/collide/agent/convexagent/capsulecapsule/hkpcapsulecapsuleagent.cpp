// File Line: 31
// RVA: 0xD224F0
hkpCollisionAgent *__fastcall hkpCapsuleCapsuleAgent::createCapsuleCapsuleAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpCollisionAgent *result; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->m_contactMgr = mgr;
    result->vfptr = (hkBaseObjectVtbl *)&hkpCapsuleCapsuleAgent::`vftable;
    LODWORD(result[1].vfptr) = -1;
    WORD2(result[1].vfptr) = -1;
  }
  return result;
}

// File Line: 37
// RVA: 0xD21DD0
void __fastcall hkpCapsuleCapsuleAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpCapsuleCapsuleAgent::createCapsuleCapsuleAgent;
  f.m_getPenetrationsFunc = hkpCapsuleCapsuleAgent::staticGetPenetrations;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  f.m_getClosestPointFunc = hkpCapsuleCapsuleAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpIterativeLinearCastAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, CAPSULE, CAPSULE);
}

// File Line: 53
// RVA: 0xD22470
void __fastcall hkpCapsuleCapsuleAgent::cleanup(hkpCapsuleCapsuleAgent *this, hkpConstraintOwner *constraintOwner)
{
  unsigned __int16 *m_contactPointId; // rbx
  __int64 v5; // rdi
  __int64 v6; // rdx

  m_contactPointId = this->m_contactPointId;
  v5 = 3i64;
  do
  {
    v6 = *m_contactPointId;
    if ( (_WORD)v6 != 0xFFFF )
      ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[2].__first_virtual_table_function__)(
        this->m_contactMgr,
        v6,
        constraintOwner);
    ++m_contactPointId;
    --v5;
  }
  while ( v5 );
  if ( this )
    this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 67
// RVA: 0xD22550
void __fastcall getThreeClosestPointsInl(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkContactPoint *points,
        hkSimdFloat32 *maxD)
{
  __m128 *m_motion; // rax
  hkpShape *m_shape; // rbx
  hkpShape *v9; // r9
  __int64 v10; // rcx
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm5
  __int64 v14; // rdx
  __m128 v15; // xmm6
  __m128 *v16; // rax
  __m128 v17; // xmm1
  __m128 *v18; // rax
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm7
  __m128 *v23; // rax
  __m128 v24; // xmm1
  hkVector4f capsBPoints; // [rsp+30h] [rbp-68h] BYREF
  char v26[16]; // [rsp+40h] [rbp-58h] BYREF
  hkVector4f capsAPointsIn; // [rsp+50h] [rbp-48h] BYREF
  char v28[16]; // [rsp+60h] [rbp-38h] BYREF

  points->m_separatingNormal.m_quad = _mm_shuffle_ps(
                                        points->m_separatingNormal.m_quad,
                                        _mm_unpackhi_ps(points->m_separatingNormal.m_quad, maxD->m_real),
                                        196);
  points[1].m_separatingNormal.m_quad = _mm_shuffle_ps(
                                          points[1].m_separatingNormal.m_quad,
                                          _mm_unpackhi_ps(points[1].m_separatingNormal.m_quad, maxD->m_real),
                                          196);
  points[2].m_separatingNormal.m_quad = _mm_shuffle_ps(
                                          points[2].m_separatingNormal.m_quad,
                                          _mm_unpackhi_ps(points[2].m_separatingNormal.m_quad, maxD->m_real),
                                          196);
  m_motion = (__m128 *)bodyA->m_motion;
  m_shape = bodyA->m_shape;
  v9 = bodyB->m_shape;
  v10 = 1i64;
  v11 = *m_motion;
  v12 = m_motion[1];
  v13 = m_motion[2];
  v14 = 1i64;
  v15 = m_motion[3];
  v16 = (__m128 *)&m_shape[2];
  do
  {
    v17 = *v16--;
    --v14;
    *(__m128 *)((char *)v16 + v28 - (char *)m_shape - 48) = _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_add_ps(
                                                                  _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), v12),
                                                                  _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v11)),
                                                                _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), v13)),
                                                              v15);
  }
  while ( v14 >= 0 );
  v18 = (__m128 *)bodyB->m_motion;
  v19 = *v18;
  v20 = v18[1];
  v21 = v18[2];
  v22 = v18[3];
  v23 = (__m128 *)&v9[2];
  do
  {
    v24 = *v23--;
    --v10;
    *(__m128 *)((char *)v23 + v26 - (char *)v9 - 48) = _mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_add_ps(
                                                             _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v20),
                                                             _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v19)),
                                                           _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v21)),
                                                         v22);
  }
  while ( v10 >= 0 );
  hkLineSegmentUtil::capsuleCapsuleManifold(
    &capsAPointsIn,
    *(float *)&m_shape[1].vfptr,
    &capsBPoints,
    *(float *)&v9[1].vfptr,
    points);
}

// File Line: 82
// RVA: 0xD226B0
hkResult *__fastcall getClosestPointInternal(
        hkResult *result,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkContactPoint *cpoint)
{
  __m128 *m_motion; // rax
  hkpShape *m_shape; // r11
  hkpShape *v7; // r10
  __m128 v8; // xmm3
  __m128 v9; // xmm4
  __m128 v10; // xmm5
  __int64 v13; // rcx
  signed __int64 v14; // r8
  __m128 v15; // xmm6
  hkpShape *v16; // rax
  __int64 i; // rdx
  __m128 v18; // xmm1
  __m128 *v19; // rax
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  __m128 v23; // xmm6
  __m128 *v24; // rax
  __m128 v25; // xmm1
  hkVector4f capsB; // [rsp+40h] [rbp-58h] BYREF
  char v28[16]; // [rsp+50h] [rbp-48h] BYREF
  hkVector4f capsA; // [rsp+60h] [rbp-38h] BYREF
  char v30; // [rsp+70h] [rbp-28h] BYREF

  m_motion = (__m128 *)bodyA->m_motion;
  m_shape = bodyA->m_shape;
  v7 = bodyB->m_shape;
  v8 = *m_motion;
  v9 = m_motion[1];
  v10 = m_motion[2];
  v13 = 1i64;
  v14 = &v30 - (char *)bodyA->m_shape;
  v15 = m_motion[3];
  v16 = bodyA->m_shape + 2;
  for ( i = 1i64; i >= 0; --i )
  {
    v18 = (__m128)v16->hkReferencedObject;
    v16 = (hkpShape *)((char *)v16 - 16);
    *(__m128 *)((char *)&v16[-1] + v14 - 16) = _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v8),
                                                     _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v9)),
                                                   _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v10)),
                                                 v15);
  }
  v19 = (__m128 *)bodyB->m_motion;
  v20 = *v19;
  v21 = v19[1];
  v22 = v19[2];
  v23 = v19[3];
  v24 = (__m128 *)&v7[2];
  do
  {
    v25 = *v24--;
    --v13;
    *(__m128 *)((char *)v24 + v28 - (char *)v7 - 48) = _mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_add_ps(
                                                             _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v21),
                                                             _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v20)),
                                                           _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v22)),
                                                         v23);
  }
  while ( v13 >= 0 );
  hkCollideCapsuleUtilClostestPointCapsVsCaps(
    result,
    &capsA,
    (const float *)&m_shape[1],
    &capsB,
    (const float *)&v7[1],
    input->m_tolerance.m_storage,
    cpoint);
  return result;
}

// File Line: 97
// RVA: 0xD227F0
void __fastcall hkpCapsuleCapsuleAgent::processCollision(
        hkpCapsuleCapsuleAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *result)
{
  _QWORD *Value; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  __m128 *m_motion; // rax
  hkpShape *m_shape; // r10
  hkpShape *v15; // r9
  __m128 v16; // xmm8
  __int64 v17; // rdx
  __int64 v18; // rcx
  signed __int64 v19; // r8
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  __m128 v23; // xmm6
  __m128 *v24; // rax
  __m128 v25; // xmm1
  __m128 *v26; // rax
  __m128 v27; // xmm4
  __m128 v28; // xmm5
  __m128 v29; // xmm6
  __m128 v30; // xmm7
  __m128 *v31; // rax
  __m128 v32; // xmm1
  hkVector4f *p_m_separatingNormal; // rdi
  unsigned __int16 *m_contactPointId; // rbx
  hkContactPoint *p_points; // rbp
  __int64 v36; // r14
  unsigned __int16 v37; // ax
  hkpProcessCdPoint *m_storage; // rcx
  hkVector4f v39; // xmm0
  __int64 v40; // rdx
  _QWORD *v41; // r8
  _QWORD *v42; // rcx
  unsigned __int64 v43; // rax
  _QWORD *v44; // rcx
  hkContactPoint points; // [rsp+40h] [rbp-F8h] BYREF
  __m128 v46; // [rsp+70h] [rbp-C8h]
  __m128 v47; // [rsp+90h] [rbp-A8h]
  hkVector4f capsAPointsIn; // [rsp+A0h] [rbp-98h] BYREF
  char v49; // [rsp+B0h] [rbp-88h] BYREF
  hkVector4f capsBPoints; // [rsp+C0h] [rbp-78h] BYREF
  char v51[64]; // [rsp+D0h] [rbp-68h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtCapsCaps";
    v11 = __rdtsc();
    v12 = v10 + 2;
    *((_DWORD *)v12 - 2) = v11;
    Value[1] = v12;
  }
  m_motion = (__m128 *)bodyA->m_motion;
  m_shape = bodyA->m_shape;
  v15 = bodyB->m_shape;
  v16 = _mm_shuffle_ps((__m128)LODWORD(input->m_tolerance.m_storage), (__m128)LODWORD(input->m_tolerance.m_storage), 0);
  v17 = 1i64;
  v18 = 1i64;
  v19 = &v49 - (char *)bodyA->m_shape;
  points.m_separatingNormal.m_quad = _mm_shuffle_ps(
                                       points.m_separatingNormal.m_quad,
                                       _mm_unpackhi_ps(points.m_separatingNormal.m_quad, v16),
                                       196);
  v46 = _mm_shuffle_ps(v46, _mm_unpackhi_ps(v46, v16), 196);
  v47 = _mm_shuffle_ps(v47, _mm_unpackhi_ps(v47, v16), 196);
  v20 = *m_motion;
  v21 = m_motion[1];
  v22 = m_motion[2];
  v23 = m_motion[3];
  v24 = (__m128 *)&m_shape[2];
  do
  {
    v25 = *v24--;
    --v18;
    *(__m128 *)((char *)v24 + v19 - 48) = _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v21),
                                                _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v20)),
                                              _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v22)),
                                            v23);
  }
  while ( v18 >= 0 );
  v26 = (__m128 *)bodyB->m_motion;
  v27 = *v26;
  v28 = v26[1];
  v29 = v26[2];
  v30 = v26[3];
  v31 = (__m128 *)&v15[2];
  do
  {
    v32 = *v31--;
    --v17;
    *(__m128 *)((char *)v31 + v51 - (char *)v15 - 48) = _mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), v28),
                                                              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v27)),
                                                            _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), v29)),
                                                          v30);
  }
  while ( v17 >= 0 );
  hkLineSegmentUtil::capsuleCapsuleManifold(
    &capsAPointsIn,
    *(float *)&m_shape[1].vfptr,
    &capsBPoints,
    *(float *)&v15[1].vfptr,
    &points);
  p_m_separatingNormal = &points.m_separatingNormal;
  m_contactPointId = this->m_contactPointId;
  p_points = &points;
  v36 = 3i64;
  do
  {
    if ( _mm_shuffle_ps(p_m_separatingNormal->m_quad, p_m_separatingNormal->m_quad, 255).m128_f32[0] >= v16.m128_f32[0] )
    {
      v40 = *m_contactPointId;
      if ( (_WORD)v40 != 0xFFFF )
      {
        ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[2].__first_virtual_table_function__)(
          this->m_contactMgr,
          v40,
          result->m_constraintOwner.m_storage);
        *m_contactPointId = -1;
      }
    }
    else if ( *m_contactPointId != 0xFFFF
           || (v37 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkContactPoint *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[1].__first_virtual_table_function__)(
                       this->m_contactMgr,
                       bodyA,
                       bodyB,
                       input,
                       result,
                       0i64,
                       p_points),
               *m_contactPointId = v37,
               v37 != 0xFFFF) )
    {
      m_storage = result->m_firstFreeContactPoint.m_storage;
      v39.m_quad = (__m128)p_m_separatingNormal[-1];
      ++result->m_firstFreeContactPoint.m_storage;
      m_storage->m_contact.m_position = (hkVector4f)v39.m_quad;
      m_storage->m_contact.m_separatingNormal = (hkVector4f)p_m_separatingNormal->m_quad;
      m_storage->m_contactPointId = *m_contactPointId;
    }
    ++p_points;
    ++m_contactPointId;
    p_m_separatingNormal += 2;
    --v36;
  }
  while ( v36 );
  v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v42 = (_QWORD *)v41[1];
  if ( (unsigned __int64)v42 < v41[3] )
  {
    *v42 = "Et";
    v43 = __rdtsc();
    v44 = v42 + 2;
    *((_DWORD *)v44 - 2) = v43;
    v41[1] = v44;
  }
}

// File Line: 140
// RVA: 0xD21E30
void __fastcall hkpCapsuleCapsuleAgent::getClosestPoints(
        hkpCapsuleCapsuleAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  __m128 *m_motion; // rax
  hkpShape *m_shape; // r10
  hkpShape *v15; // r9
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm5
  __int64 v19; // rcx
  __int64 v20; // rdx
  signed __int64 v21; // r8
  __m128 v22; // xmm6
  hkpShape *v23; // rax
  __m128 v24; // xmm1
  __m128 *v25; // rax
  __m128 v26; // xmm3
  __m128 v27; // xmm4
  __m128 v28; // xmm5
  __m128 v29; // xmm6
  __m128 *v30; // rax
  __m128 v31; // xmm1
  _QWORD *v32; // r8
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  _QWORD *v35; // rcx
  hkContactPoint cpoint; // [rsp+40h] [rbp-98h] BYREF
  hkVector4f capsB; // [rsp+60h] [rbp-78h] BYREF
  char v38[16]; // [rsp+70h] [rbp-68h] BYREF
  hkVector4f capsA; // [rsp+80h] [rbp-58h] BYREF
  __int128 v40[2]; // [rsp+90h] [rbp-48h] BYREF
  hkpCdBody *v41; // [rsp+B0h] [rbp-28h]
  hkpCdBody *v42; // [rsp+B8h] [rbp-20h]
  hkResult result; // [rsp+E8h] [rbp+10h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtCapsCaps";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  m_motion = (__m128 *)bodyA->m_motion;
  m_shape = bodyA->m_shape;
  v15 = bodyB->m_shape;
  v16 = *m_motion;
  v17 = m_motion[1];
  v18 = m_motion[2];
  v19 = 1i64;
  v20 = 1i64;
  v21 = (char *)v40 - (char *)bodyA->m_shape;
  v22 = m_motion[3];
  v23 = bodyA->m_shape + 2;
  do
  {
    v24 = (__m128)v23->hkReferencedObject;
    v23 = (hkpShape *)((char *)v23 - 16);
    --v20;
    *(__m128 *)((char *)&v23[-1] + v21 - 16) = _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v17),
                                                     _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v16)),
                                                   _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v18)),
                                                 v22);
  }
  while ( v20 >= 0 );
  v25 = (__m128 *)bodyB->m_motion;
  v26 = *v25;
  v27 = v25[1];
  v28 = v25[2];
  v29 = v25[3];
  v30 = (__m128 *)&v15[2];
  do
  {
    v31 = *v30--;
    --v19;
    *(__m128 *)((char *)v30 + v38 - (char *)v15 - 48) = _mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), v27),
                                                              _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v26)),
                                                            _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), v28)),
                                                          v29);
  }
  while ( v19 >= 0 );
  hkCollideCapsuleUtilClostestPointCapsVsCaps(
    &result,
    &capsA,
    (const float *)&m_shape[1],
    &capsB,
    (const float *)&v15[1],
    input->m_tolerance.m_storage,
    &cpoint);
  if ( result.m_enum == HK_SUCCESS )
  {
    v41 = bodyA;
    v42 = bodyB;
    capsA.m_quad = (__m128)cpoint.m_position;
    v40[0] = (__int128)cpoint.m_separatingNormal;
    v40[1] = (__int128)cpoint.m_separatingNormal;
    collector->vfptr->addCdPoint(collector, (hkpCdPoint *)&capsA);
  }
  v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v33 = (_QWORD *)v32[1];
  if ( (unsigned __int64)v33 < v32[3] )
  {
    *v33 = "Et";
    v34 = __rdtsc();
    v35 = v33 + 2;
    *((_DWORD *)v35 - 2) = v34;
    v32[1] = v35;
  }
})
  {
    *v33 = "Et";
    v34 = __rdtsc();
    v35 = v33 + 2;
    *((_DWORD *)v35 - 2) = v34;
    v32[1] = v35;

// File Line: 154
// RVA: 0xD22040
void __fastcall hkpCapsuleCapsuleAgent::staticGetClosestPoints(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  __m128 *m_motion; // rax
  hkpShape *m_shape; // r10
  hkpShape *v14; // r9
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  __int64 v18; // rcx
  __int64 v19; // rdx
  signed __int64 v20; // r8
  __m128 v21; // xmm6
  hkpShape *v22; // rax
  __m128 v23; // xmm1
  __m128 *v24; // rax
  __m128 v25; // xmm3
  __m128 v26; // xmm4
  __m128 v27; // xmm5
  __m128 v28; // xmm6
  __m128 *v29; // rax
  __m128 v30; // xmm1
  hkpCdPointCollectorVtbl *vfptr; // rax
  _QWORD *v32; // r8
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  _QWORD *v35; // rcx
  hkContactPoint cpoint; // [rsp+40h] [rbp-98h] BYREF
  hkVector4f capsB; // [rsp+60h] [rbp-78h] BYREF
  char v38[16]; // [rsp+70h] [rbp-68h] BYREF
  hkVector4f capsA; // [rsp+80h] [rbp-58h] BYREF
  __int128 v40[2]; // [rsp+90h] [rbp-48h] BYREF
  hkpCdBody *v41; // [rsp+B0h] [rbp-28h]
  hkpCdBody *v42; // [rsp+B8h] [rbp-20h]
  hkResult result; // [rsp+E0h] [rbp+8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtCapsCaps";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  m_motion = (__m128 *)bodyA->m_motion;
  m_shape = bodyA->m_shape;
  v14 = bodyB->m_shape;
  v15 = *m_motion;
  v16 = m_motion[1];
  v17 = m_motion[2];
  v18 = 1i64;
  v19 = 1i64;
  v20 = (char *)v40 - (char *)bodyA->m_shape;
  v21 = m_motion[3];
  v22 = bodyA->m_shape + 2;
  do
  {
    v23 = (__m128)v22->hkReferencedObject;
    v22 = (hkpShape *)((char *)v22 - 16);
    --v19;
    *(__m128 *)((char *)&v22[-1] + v20 - 16) = _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v16),
                                                     _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v15)),
                                                   _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v17)),
                                                 v21);
  }
  while ( v19 >= 0 );
  v24 = (__m128 *)bodyB->m_motion;
  v25 = *v24;
  v26 = v24[1];
  v27 = v24[2];
  v28 = v24[3];
  v29 = (__m128 *)&v14[2];
  do
  {
    v30 = *v29--;
    --v18;
    *(__m128 *)((char *)v29 + v38 - (char *)v14 - 48) = _mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v26),
                                                              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v25)),
                                                            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v27)),
                                                          v28);
  }
  while ( v18 >= 0 );
  hkCollideCapsuleUtilClostestPointCapsVsCaps(
    &result,
    &capsA,
    (const float *)&m_shape[1],
    &capsB,
    (const float *)&v14[1],
    input->m_tolerance.m_storage,
    &cpoint);
  if ( result.m_enum == HK_SUCCESS )
  {
    vfptr = collector->vfptr;
    v41 = bodyA;
    capsA.m_quad = (__m128)cpoint.m_position;
    v40[0] = (__int128)cpoint.m_separatingNormal;
    v40[1] = (__int128)cpoint.m_separatingNormal;
    v42 = bodyB;
    vfptr->addCdPoint(collector, (hkpCdPoint *)&capsA);
  }
  v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v33 = (_QWORD *)v32[1];
  if ( (unsigned __int64)v33 < v32[3] )
  {
    *v33 = "Et";
    v34 = __rdtsc();
    v35 = v33 + 2;
    *((_DWORD *)v35 - 2) = v34;
    v32[1] = v35;
  }
}

// File Line: 168
// RVA: 0xD22270
void __fastcall hkpCapsuleCapsuleAgent::staticGetPenetrations(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r8
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  __m128 *m_motion; // rax
  hkpShape *m_shape; // r14
  hkpShape *v14; // rbp
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  __int64 v18; // rcx
  __int64 v19; // rdx
  signed __int64 v20; // r8
  __m128 v21; // xmm6
  hkpShape *v22; // rax
  __m128 v23; // xmm1
  __m128 *v24; // rax
  __m128 v25; // xmm3
  __m128 v26; // xmm4
  __m128 v27; // xmm5
  __m128 v28; // xmm6
  __m128 *v29; // rax
  __m128 v30; // xmm1
  _QWORD *v31; // r8
  _QWORD *v32; // rcx
  unsigned __int64 v33; // rax
  _QWORD *v34; // rcx
  hkVector4f B; // [rsp+30h] [rbp-C8h] BYREF
  __m128 v36; // [rsp+40h] [rbp-B8h] BYREF
  hkVector4f dB; // [rsp+50h] [rbp-A8h] BYREF
  hkVector4f A; // [rsp+60h] [rbp-98h] BYREF
  __m128 v39; // [rsp+70h] [rbp-88h] BYREF
  hkVector4f dA; // [rsp+80h] [rbp-78h] BYREF
  hkLineSegmentUtil::ClosestLineSegLineSegResult result; // [rsp+90h] [rbp-68h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)Value[1];
  v9 = Value;
  if ( (unsigned __int64)v8 < Value[3] )
  {
    *v8 = "TtCapsCaps";
    v10 = __rdtsc();
    v11 = v8 + 2;
    *((_DWORD *)v11 - 2) = v10;
    v9[1] = v11;
  }
  m_motion = (__m128 *)bodyA->m_motion;
  m_shape = bodyA->m_shape;
  v14 = bodyB->m_shape;
  v15 = *m_motion;
  v16 = m_motion[1];
  v17 = m_motion[2];
  v18 = 1i64;
  v19 = 1i64;
  v20 = (char *)&v39 - (char *)bodyA->m_shape;
  v21 = m_motion[3];
  v22 = bodyA->m_shape + 2;
  do
  {
    v23 = (__m128)v22->hkReferencedObject;
    v22 = (hkpShape *)((char *)v22 - 16);
    --v19;
    *(__m128 *)((char *)&v22[-1] + v20 - 16) = _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v16),
                                                     _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v15)),
                                                   _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v17)),
                                                 v21);
  }
  while ( v19 >= 0 );
  v24 = (__m128 *)bodyB->m_motion;
  v25 = *v24;
  v26 = v24[1];
  v27 = v24[2];
  v28 = v24[3];
  v29 = (__m128 *)&v14[2];
  do
  {
    v30 = *v29--;
    --v18;
    *(__m128 *)((char *)v29 + (char *)&v36 - (char *)v14 - 48) = _mm_add_ps(
                                                                   _mm_add_ps(
                                                                     _mm_add_ps(
                                                                       _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v26),
                                                                       _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v25)),
                                                                     _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v27)),
                                                                   v28);
  }
  while ( v18 >= 0 );
  dA.m_quad = _mm_sub_ps(v39, A.m_quad);
  dB.m_quad = _mm_sub_ps(v36, B.m_quad);
  hkLineSegmentUtil::closestLineSegLineSeg(&A, &dA, &B, &dB, &result);
  if ( result.m_distanceSquared.m_storage < (float)((float)(*(float *)&v14[1].vfptr + *(float *)&m_shape[1].vfptr)
                                                  * (float)(*(float *)&v14[1].vfptr + *(float *)&m_shape[1].vfptr)) )
    collector->vfptr->addCdBodyPair(collector, bodyA, bodyB);
  v31 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v32 = (_QWORD *)v31[1];
  if ( (unsigned __int64)v32 < v31[3] )
  {
    *v32 = "Et";
    v33 = __rdtsc();
    v34 = v32 + 2;
    *((_DWORD *)v34 - 2) = v33;
    v31[1] = v34;
  }
}

// File Line: 193
// RVA: 0xD22250
void __fastcall hkpCapsuleCapsuleAgent::getPenetrations(
        hkpCapsuleCapsuleAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpCapsuleCapsuleAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}


// File Line: 26
// RVA: 0xD1A380
void __fastcall hkpBoxBoxAgent::initAgentFunc(hkpCollisionDispatcher::AgentFuncs *af)
{
  af->m_createFunc = hkpBoxBoxAgent::createBoxBoxAgent;
  af->m_getPenetrationsFunc = hkpBoxBoxAgent::staticGetPenetrations;
  af->m_getClosestPointFunc = hkpGskBaseAgent::staticGetClosestPoints;
  af->m_linearCastFunc = hkpIterativeLinearCastAgent::staticLinearCast;
  *(_WORD *)&af->m_isFlipped.m_bool = 0;
}

// File Line: 48
// RVA: 0xD1A3C0
void __fastcall hkpBoxBoxAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpBoxBoxAgent::initAgentFunc(&f);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, BOX, BOX);
}

// File Line: 58
// RVA: 0xD1AAE0
hkpCollisionAgent *__fastcall hkpBoxBoxAgent::createBoxBoxAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *contactMgr)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm0
  _QWORD **Value; // rax
  __int64 v9; // rax
  __int64 v10; // rbx

  v5 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_999), (__m128)LODWORD(FLOAT_1_999), 0);
  v6 = _mm_shuffle_ps((__m128)LODWORD(input->m_tolerance.m_storage), (__m128)LODWORD(input->m_tolerance.m_storage), 0);
  if ( _mm_movemask_ps(
         _mm_or_ps(
           _mm_cmple_ps(
             _mm_mul_ps(
               _mm_shuffle_ps(
                 *(__m128 *)&bodyB->m_shape[1].m_type.m_storage,
                 *(__m128 *)&bodyB->m_shape[1].m_type.m_storage,
                 255),
               v5),
             v6),
           _mm_cmple_ps(
             _mm_mul_ps(
               _mm_shuffle_ps(
                 *(__m128 *)&bodyA->m_shape[1].m_type.m_storage,
                 *(__m128 *)&bodyA->m_shape[1].m_type.m_storage,
                 255),
               v5),
             v6))) )
  {
    return hkpGskfAgent::createGskfAgent(bodyA, bodyB, input, contactMgr);
  }
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 96i64);
  v10 = v9;
  if ( !v9 )
    return 0i64;
  *(_DWORD *)(v9 + 8) = 0x1FFFF;
  *(_QWORD *)(v9 + 16) = contactMgr;
  *(_QWORD *)v9 = &hkpBoxBoxAgent::`vftable;
  hkpBoxBoxManifold::hkpBoxBoxManifold((hkpBoxBoxManifold *)(v9 + 32));
  return (hkpCollisionAgent *)v10;
}

// File Line: 88
// RVA: 0xD1AA60
void __fastcall hkpBoxBoxAgent::cleanup(hkpBoxBoxAgent *this, hkpConstraintOwner *constraintOwner)
{
  int v2; // esi
  unsigned __int16 *p_m_contactPointId; // rdi

  v2 = 0;
  if ( this->m_manifold.m_numPoints )
  {
    p_m_contactPointId = &this->m_manifold.m_contactPoints[0].m_contactPointId;
    do
    {
      ((void (__fastcall *)(hkpContactMgr *, _QWORD, hkpConstraintOwner *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[2].__first_virtual_table_function__)(
        this->m_contactMgr,
        *p_m_contactPointId,
        constraintOwner);
      ++v2;
      p_m_contactPointId += 2;
    }
    while ( v2 < (unsigned __int8)this->m_manifold.m_numPoints );
  }
  this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 101
// RVA: 0xD1A400
void __fastcall hkpBoxBoxAgent::processCollision(
        hkpBoxBoxAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input)
{
  _QWORD *Value; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  __m128 *m_shape; // rcx
  __m128 *v13; // rax
  hkTransformf *m_motion; // r8
  hkTransformf *v15; // rdx
  __m128 v16; // xmm6
  __m128 v17; // xmm7
  __m128 v18; // xmm8
  __m128 v19; // xmm6
  hkpProcessCollisionInput *v20; // rax
  hkpContactMgr *v21; // rax
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  hkTransformf v26; // [rsp+20h] [rbp-C8h] BYREF
  hkpBoxBoxCollisionDetection v27; // [rsp+60h] [rbp-88h] BYREF
  float m_storage; // [rsp+1E8h] [rbp+100h]
  hkpCdBody *v29; // [rsp+208h] [rbp+120h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtBoxBox";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  m_shape = (__m128 *)bodyB->m_shape;
  v13 = (__m128 *)bodyA->m_shape;
  m_motion = (hkTransformf *)bodyB->m_motion;
  v15 = (hkTransformf *)bodyA->m_motion;
  m_storage = input->m_tolerance.m_storage;
  v16 = (__m128)LODWORD(m_storage);
  v17 = _mm_add_ps(_mm_shuffle_ps((__m128)m_shape[2].m128_u32[0], (__m128)m_shape[2].m128_u32[0], 0), m_shape[3]);
  v18 = _mm_add_ps(_mm_shuffle_ps((__m128)v13[2].m128_u32[0], (__m128)v13[2].m128_u32[0], 0), v13[3]);
  hkTransformf::setMulInverseMul(&v26, v15, m_motion);
  v19 = _mm_shuffle_ps(v16, v16, 0);
  v27.m_contactMgr = this->m_contactMgr;
  *(hkVector4f *)&v27.m_wTa = v26.m_rotation.m_col0;
  *(hkVector4f *)(&v27.m_wTb + 1) = v26.m_rotation.m_col1;
  v27.m_bodyB = v29;
  v20 = (hkpProcessCollisionInput *)bodyA->m_motion;
  v27.m_bodyA = bodyA;
  *(hkVector4f *)((char *)&v27.m_aTb.m_rotation.m_col0 + 8) = v26.m_rotation.m_col2;
  *(__m128 *)((char *)&v27.m_aTb.m_rotation.m_col2.m_quad + 8) = v18;
  v27.m_env = v20;
  v21 = (hkpContactMgr *)bodyB->m_motion;
  v27.m_bodyB = bodyB;
  *(hkVector4f *)((char *)&v27.m_aTb.m_rotation.m_col1 + 8) = v26.m_translation;
  *(__m128 *)((char *)&v27.m_aTb.m_translation.m_quad + 8) = v17;
  v27.m_env = input;
  v27.m_contactMgr = v21;
  *(__m128 *)((char *)&v27.m_radiusA.m_quad + 8) = _mm_shuffle_ps(
                                                     v19,
                                                     _mm_unpackhi_ps(v19, (__m128)xmmword_141A712A0),
                                                     196);
  *(__m128 *)((char *)&v27.m_keepRadiusA.m_quad + 8) = _mm_shuffle_ps(
                                                         (__m128)LODWORD(FLOAT_0_0099999998),
                                                         (__m128)LODWORD(FLOAT_0_0099999998),
                                                         0);
  *(__m128 *)((char *)&v27.m_tolerance4.m_quad + 8) = _mm_add_ps(*(__m128 *)((char *)&v27.m_radiusA.m_quad + 8), v17);
  *(__m128 *)((char *)&v27.m_radiusB.m_quad + 8) = _mm_add_ps(*(__m128 *)((char *)&v27.m_radiusA.m_quad + 8), v18);
  hkpBoxBoxCollisionDetection::calcManifold(&v27, &this->m_manifold);
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "Et";
    v24 = __rdtsc();
    v25 = v23 + 2;
    *((_DWORD *)v25 - 2) = v24;
    v22[1] = v25;
  }
}

// File Line: 128
// RVA: 0xD1A600
void __fastcall hkpBoxBoxAgent::staticGetClosestPoints(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  __m128 *m_shape; // rcx
  __m128 *v13; // rax
  hkTransformf *m_motion; // r8
  hkTransformf *v15; // rdx
  __m128 v16; // xmm6
  hkVector4f v17; // xmm7
  hkVector4f v18; // xmm8
  hkTransformf *v19; // rax
  __m128 v20; // xmm6
  hkTransformf *v21; // rax
  hkpCdPointCollectorVtbl *vfptr; // rax
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  _QWORD *v26; // rcx
  __int128 v27[3]; // [rsp+20h] [rbp-C8h] BYREF
  hkpCdBody *v28; // [rsp+50h] [rbp-98h]
  hkpCdBody *v29; // [rsp+58h] [rbp-90h]
  char v30[72]; // [rsp+60h] [rbp-88h] BYREF
  hkpBoxBoxCollisionDetection v31; // [rsp+A8h] [rbp-40h] BYREF
  hkBool result; // [rsp+248h] [rbp+160h] BYREF
  float m_storage; // [rsp+250h] [rbp+168h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtBoxBox";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  m_shape = (__m128 *)bodyB->m_shape;
  v13 = (__m128 *)bodyA->m_shape;
  m_motion = (hkTransformf *)bodyB->m_motion;
  v15 = (hkTransformf *)bodyA->m_motion;
  m_storage = input->m_tolerance.m_storage;
  v16 = (__m128)LODWORD(m_storage);
  v17.m_quad = _mm_add_ps(_mm_shuffle_ps((__m128)m_shape[2].m128_u32[0], (__m128)m_shape[2].m128_u32[0], 0), m_shape[3]);
  v18.m_quad = _mm_add_ps(_mm_shuffle_ps((__m128)v13[2].m128_u32[0], (__m128)v13[2].m128_u32[0], 0), v13[3]);
  hkTransformf::setMulInverseMul((hkTransformf *)&v30[8], v15, m_motion);
  v19 = (hkTransformf *)bodyA->m_motion;
  v20 = _mm_shuffle_ps(v16, v16, 0);
  memset(&v31.m_env, 0, 24);
  v31.m_aTb.m_rotation.m_col1 = *(hkVector4f *)&v30[24];
  v31.m_wTa = v19;
  v21 = (hkTransformf *)bodyB->m_motion;
  v31.m_aTb.m_rotation.m_col0 = *(hkVector4f *)&v30[8];
  v31.m_bodyA = bodyA;
  v31.m_bodyB = bodyB;
  v31.m_aTb.m_rotation.m_col2 = *(hkVector4f *)&v30[40];
  v31.m_aTb.m_translation = *(hkVector4f *)&v30[56];
  v31.m_radiusA = (hkVector4f)v18.m_quad;
  v31.m_wTb = v21;
  m_storage = FLOAT_0_0099999998;
  v31.m_radiusB = (hkVector4f)v17.m_quad;
  v31.m_boundaryTolerance.m_real = _mm_shuffle_ps(
                                     (__m128)LODWORD(FLOAT_0_0099999998),
                                     (__m128)LODWORD(FLOAT_0_0099999998),
                                     0);
  v31.m_tolerance4.m_quad = _mm_shuffle_ps(v20, _mm_unpackhi_ps(v20, (__m128)xmmword_141A712A0), 196);
  v31.m_keepRadiusB.m_quad = _mm_add_ps(v31.m_tolerance4.m_quad, v17.m_quad);
  v31.m_keepRadiusA.m_quad = _mm_add_ps(v31.m_tolerance4.m_quad, v18.m_quad);
  hkpBoxBoxCollisionDetection::calculateClosestPoint(&v31, &result, (hkContactPoint *)v30);
  if ( result.m_bool )
  {
    vfptr = collector->vfptr;
    v28 = bodyA;
    v27[0] = *(_OWORD *)v30;
    v27[1] = *(_OWORD *)&v30[16];
    v27[2] = *(_OWORD *)&v30[16];
    v29 = bodyB;
    vfptr->addCdPoint(collector, (hkpCdPoint *)v27);
  }
  v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v24 = (_QWORD *)v23[1];
  if ( (unsigned __int64)v24 < v23[3] )
  {
    *v24 = "Et";
    v25 = __rdtsc();
    v26 = v24 + 2;
    *((_DWORD *)v26 - 2) = v25;
    v23[1] = v26;
  }
}

// File Line: 159
// RVA: 0xD1A5E0
void __fastcall hkpBoxBoxAgent::getClosestPoints(
        hkpBoxBoxAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  hkpBoxBoxAgent::staticGetClosestPoints(bodyA, bodyB, input, collector);
}

// File Line: 167
// RVA: 0xD1A830
void __fastcall hkpBoxBoxAgent::staticGetPenetrations(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  _QWORD *Value; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  __m128 *m_shape; // rcx
  __m128 *v13; // rax
  hkTransformf *m_motion; // r8
  hkTransformf *v15; // rdx
  __m128 m_enum; // xmm6
  __m128 v17; // xmm7
  __m128 v18; // xmm8
  __m128 v19; // xmm6
  hkpContactMgr *v20; // rax
  __m128 v21; // xmm1
  __m128 v22; // xmm6
  __m128 v23; // xmm2
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  _QWORD *v27; // rcx
  hkTransformf v28; // [rsp+20h] [rbp-C8h] BYREF
  hkpBoxBoxCollisionDetection v29; // [rsp+60h] [rbp-88h] BYREF
  hkResult result; // [rsp+1E8h] [rbp+100h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtBoxBox";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  m_shape = (__m128 *)bodyB->m_shape;
  v13 = (__m128 *)bodyA->m_shape;
  m_motion = (hkTransformf *)bodyB->m_motion;
  v15 = (hkTransformf *)bodyA->m_motion;
  result.m_enum = LODWORD(input->m_tolerance.m_storage);
  m_enum = (__m128)(unsigned int)result.m_enum;
  v17 = _mm_add_ps(_mm_shuffle_ps((__m128)m_shape[2].m128_u32[0], (__m128)m_shape[2].m128_u32[0], 0), m_shape[3]);
  v18 = _mm_add_ps(_mm_shuffle_ps((__m128)v13[2].m128_u32[0], (__m128)v13[2].m128_u32[0], 0), v13[3]);
  hkTransformf::setMulInverseMul(&v28, v15, m_motion);
  v19 = _mm_shuffle_ps(m_enum, m_enum, 0);
  v29.m_env = (hkpProcessCollisionInput *)bodyA->m_motion;
  v20 = (hkpContactMgr *)bodyB->m_motion;
  v29.m_env = 0i64;
  *(hkTransformf *)&v29.m_wTa = v28;
  result.m_enum = LODWORD(FLOAT_0_0099999998);
  v29.m_bodyA = bodyA;
  *(__m128 *)((char *)&v29.m_keepRadiusA.m_quad + 8) = _mm_shuffle_ps(
                                                         (__m128)LODWORD(FLOAT_0_0099999998),
                                                         (__m128)LODWORD(FLOAT_0_0099999998),
                                                         0);
  v29.m_bodyB = 0i64;
  v29.m_contactMgr = v20;
  v21 = _mm_unpacklo_ps(v28.m_rotation.m_col0.m_quad, v28.m_rotation.m_col1.m_quad);
  *(hkVector4f *)((char *)&v29.m_keepRadiusB + 8) = v28.m_translation;
  v22 = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, (__m128)xmmword_141A712A0), 196);
  v23 = _mm_movelh_ps(v21, v28.m_rotation.m_col2.m_quad);
  *(__m128 *)((char *)&v29.m_radiusB.m_quad + 8) = _mm_add_ps(v22, v18);
  *(__m128 *)((char *)&v29.m_radiusA.m_quad + 8) = v22;
  *(__m128 *)((char *)&v29.m_aTb.m_rotation.m_col2.m_quad + 8) = v18;
  *(__m128 *)((char *)&v29.m_aTb.m_translation.m_quad + 8) = v17;
  *(__m128 *)((char *)&v29.m_tolerance4.m_quad + 8) = _mm_add_ps(v22, v17);
  *(__m128 *)((char *)&v29.m_boundaryTolerance.m_real + 8) = _mm_add_ps(
                                                               _mm_add_ps(
                                                                 _mm_mul_ps(
                                                                   _mm_shuffle_ps(
                                                                     v28.m_translation.m_quad,
                                                                     v28.m_translation.m_quad,
                                                                     85),
                                                                   _mm_shuffle_ps(
                                                                     _mm_movehl_ps(v23, v21),
                                                                     v28.m_rotation.m_col2.m_quad,
                                                                     212)),
                                                                 _mm_mul_ps(
                                                                   _mm_shuffle_ps(
                                                                     v28.m_translation.m_quad,
                                                                     v28.m_translation.m_quad,
                                                                     0),
                                                                   v23)),
                                                               _mm_mul_ps(
                                                                 _mm_shuffle_ps(
                                                                   _mm_unpackhi_ps(
                                                                     v28.m_rotation.m_col0.m_quad,
                                                                     v28.m_rotation.m_col1.m_quad),
                                                                   v28.m_rotation.m_col2.m_quad,
                                                                   228),
                                                                 _mm_shuffle_ps(
                                                                   *(__m128 *)((char *)&v29.m_aTb.m_rotation.m_col1.m_quad
                                                                             + 8),
                                                                   *(__m128 *)((char *)&v29.m_aTb.m_rotation.m_col1.m_quad
                                                                             + 8),
                                                                   170)));
  if ( hkpBoxBoxCollisionDetection::checkIntersection(&v29, &result, (hkVector4f *)&v29.m_radiusA.m_quad.m128_u16[4])->m_enum == HK_SUCCESS )
    collector->vfptr->addCdBodyPair(collector, bodyA, bodyB);
  v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v25 = (_QWORD *)v24[1];
  if ( (unsigned __int64)v25 < v24[3] )
  {
    *v25 = "Et";
    v26 = __rdtsc();
    v27 = v25 + 2;
    *((_DWORD *)v27 - 2) = v26;
    v24[1] = v27;
  }
}

// File Line: 195
// RVA: 0xD1A810
void __fastcall hkpBoxBoxAgent::getPenetrations(
        hkpBoxBoxAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpBoxBoxAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}


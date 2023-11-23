// File Line: 26
// RVA: 0xD1FA70
void __fastcall hkpSphereCapsuleAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpSphereCapsuleAgent::createCapsuleSphereAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpSphereCapsuleAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpSphereCapsuleAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 1;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpCapsuleTriangleAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, CAPSULE, SPHERE);
  f.m_createFunc = hkpSphereCapsuleAgent::createSphereCapsuleAgent;
  f.m_getPenetrationsFunc = hkpSphereCapsuleAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSphereCapsuleAgent::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  f.m_linearCastFunc = hkpIterativeLinearCastAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, SPHERE, CAPSULE);
}

// File Line: 52
// RVA: 0xD204C0
hkpCollisionAgent *__fastcall hkpSphereCapsuleAgent::createCapsuleSphereAgent(
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
    result->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgentLinearCast<hkpSphereCapsuleAgent>::`vftable;
    result->m_contactMgr = mgr;
    LOWORD(result[1].vfptr) = -1;
  }
  return result;
}

// File Line: 59
// RVA: 0xD20460
hkpCollisionAgent *__fastcall hkpSphereCapsuleAgent::createSphereCapsuleAgent(
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
    result->vfptr = (hkBaseObjectVtbl *)&hkpSphereCapsuleAgent::`vftable;
    result->m_contactMgr = mgr;
    LOWORD(result[1].vfptr) = -1;
  }
  return result;
}

// File Line: 64
// RVA: 0xD20420
void __fastcall hkpSphereCapsuleAgent::cleanup(hkpSphereCapsuleAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpConstraintOwner *v2; // r8
  __int64 m_contactPointId; // rdx

  v2 = constraintOwner;
  m_contactPointId = this->m_contactPointId;
  if ( (_WORD)m_contactPointId != 0xFFFF )
    ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[2].__first_virtual_table_function__)(
      this->m_contactMgr,
      m_contactPointId,
      v2);
  ((void (__fastcall *)(hkpSphereCapsuleAgent *, __int64, hkpConstraintOwner *))this->vfptr->__vecDelDtor)(
    this,
    1i64,
    v2);
}

// File Line: 117
// RVA: 0xD20520
__int64 __fastcall hkpSphereCapsuleAgent::getClosestPoint(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkContactPoint *cpoint)
{
  hkpShape *m_shape; // rdi
  hkVector4f *m_motion; // rbx
  hkpShape *v6; // rbp
  __m128 *v7; // rax
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  __m128 v12; // xmm5
  __int64 v13; // rcx
  __m128 v14; // xmm6
  hkpShape *v15; // rax
  __m128 v16; // xmm1
  __m128 v17; // xmm7
  __m128 v18; // xmm9
  __m128 v19; // xmm1
  __m128 v20; // xmm9
  __m128 v21; // xmm3
  float v22; // xmm2_4
  __int64 v23; // rax
  __m128 v24; // xmm1
  __m128 v25; // xmm6
  __m128 v26; // xmm7
  __m128 v27; // xmm7
  __m128 v28; // xmm5
  __m128 v29; // xmm7
  __m128 v30; // xmm1
  __m128 v31; // xmm4
  __m128 v32; // xmm2
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm2
  __m128 v36; // xmm7
  hkVector4f v37; // xmm7
  hkLineSegmentUtil::ClosestPointLineSegResult result; // [rsp+20h] [rbp-88h] BYREF
  hkVector4f B; // [rsp+30h] [rbp-78h] BYREF
  hkVector4f B2; // [rsp+40h] [rbp-68h] BYREF

  m_shape = bodyB->m_shape;
  m_motion = (hkVector4f *)bodyA->m_motion;
  v6 = bodyA->m_shape;
  v7 = (__m128 *)bodyB->m_motion;
  v10 = *v7;
  v11 = v7[1];
  v12 = v7[2];
  v13 = 1i64;
  v14 = v7[3];
  v15 = bodyB->m_shape + 2;
  do
  {
    v16 = (__m128)v15->hkReferencedObject;
    v15 = (hkpShape *)((char *)v15 - 16);
    --v13;
    *(__m128 *)((char *)&v15[-1] + (char *)&B2 - (char *)m_shape - 16) = _mm_add_ps(
                                                                           _mm_add_ps(
                                                                             _mm_add_ps(
                                                                               _mm_mul_ps(
                                                                                 _mm_shuffle_ps(v16, v16, 85),
                                                                                 v11),
                                                                               _mm_mul_ps(
                                                                                 _mm_shuffle_ps(v16, v16, 0),
                                                                                 v10)),
                                                                             _mm_mul_ps(
                                                                               _mm_shuffle_ps(v16, v16, 170),
                                                                               v12)),
                                                                           v14);
  }
  while ( v13 >= 0 );
  hkLineSegmentUtil::closestPointLineSeg(m_motion + 3, &B, &B2, &result);
  v17 = _mm_sub_ps(m_motion[3].m_quad, result.m_pointOnEdge.m_quad);
  v18 = (__m128)COERCE_UNSIGNED_INT(*(float *)&v6[1].vfptr + *(float *)&m_shape[1].vfptr);
  v19 = _mm_mul_ps(v17, v17);
  v20 = _mm_shuffle_ps(v18, v18, 0);
  v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v22 = _mm_shuffle_ps((__m128)LODWORD(input->m_tolerance.m_storage), (__m128)LODWORD(input->m_tolerance.m_storage), 0).m128_f32[0]
      + v20.m128_f32[0];
  if ( v21.m128_f32[0] >= (float)(v22 * v22) )
    return 0i64;
  if ( v21.m128_f32[0] <= 0.0 )
  {
    v25 = 0i64;
    v26 = _mm_sub_ps(B2.m_quad, B.m_quad);
    v27 = _mm_shuffle_ps(v26, _mm_unpackhi_ps(v26, (__m128)0i64), 196);
    v28 = _mm_shuffle_ps(v27, v27, 241);
    v29 = _mm_shuffle_ps(v27, v27, 206);
    v30 = _mm_mul_ps(v29, v29);
    v31 = _mm_mul_ps(v28, v28);
    v32 = _mm_cmplt_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
              _mm_shuffle_ps(v31, v31, 170)),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
              _mm_shuffle_ps(v30, v30, 170)));
    v17 = _mm_xor_ps(
            _mm_or_ps(_mm_and_ps(v29, v32), _mm_andnot_ps(v32, v28)),
            (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  }
  else
  {
    v24 = _mm_rsqrt_ps(v21);
    v25 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v21), v24)),
              _mm_mul_ps(*(__m128 *)_xmm, v24)),
            v21);
  }
  v23 = 1i64;
  v33 = _mm_mul_ps(v17, v17);
  v34 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)), _mm_shuffle_ps(v33, v33, 170));
  v35 = _mm_rsqrt_ps(v34);
  v36 = _mm_mul_ps(
          v17,
          _mm_andnot_ps(
            _mm_cmple_ps(v34, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v34), v35)),
              _mm_mul_ps(*(__m128 *)_xmm, v35))));
  v37.m_quad = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, _mm_sub_ps(v25, v20)), 196);
  cpoint->m_separatingNormal = (hkVector4f)v37.m_quad;
  cpoint->m_position.m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_sub_ps(
                                    _mm_shuffle_ps(
                                      (__m128)LODWORD(m_shape[1].vfptr),
                                      (__m128)LODWORD(m_shape[1].vfptr),
                                      0),
                                    v25),
                                  v37.m_quad),
                                m_motion[3].m_quad);
  return v23;
}

// File Line: 126
// RVA: 0xD208F0
void __fastcall hkpSphereCapsuleAgent::processCollision(
        hkpSphereCapsuleAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *result)
{
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  hkpShape *m_shape; // rbp
  hkpProcessCdPoint *m_storage; // r13
  hkVector4f *m_motion; // rsi
  __m128 *v18; // rax
  __int64 v19; // rcx
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  __m128 v23; // xmm6
  hkpShape *v24; // rax
  __m128 v25; // xmm1
  __m128 v26; // xmm8
  __m128 v27; // xmm1
  __m128 v28; // xmm10
  __m128 v29; // xmm3
  float v30; // xmm2_4
  __m128 v31; // xmm1
  __m128 v32; // xmm7
  __m128 v33; // xmm6
  __m128 v34; // xmm6
  __m128 v35; // xmm5
  __m128 v36; // xmm6
  __m128 v37; // xmm1
  __m128 v38; // xmm4
  __m128 v39; // xmm2
  __m128 v40; // xmm1
  __m128 v41; // xmm3
  __m128 v42; // xmm2
  __m128 v43; // xmm8
  __m128 v44; // xmm8
  unsigned __int16 v45; // ax
  __int64 m_contactPointId; // rdx
  _QWORD *v47; // rax
  _QWORD *v48; // rcx
  _QWORD *v49; // r8
  unsigned __int64 v50; // rax
  _QWORD *v51; // rcx
  hkLineSegmentUtil::ClosestPointLineSegResult v52; // [rsp+40h] [rbp-A8h] BYREF
  hkVector4f B; // [rsp+50h] [rbp-98h] BYREF
  hkVector4f B2; // [rsp+60h] [rbp-88h] BYREF
  hkpShape *resulta; // [rsp+110h] [rbp+28h]
  unsigned int resultb; // [rsp+110h] [rbp+28h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtSphereCapsule";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  m_shape = bodyB->m_shape;
  m_storage = result->m_firstFreeContactPoint.m_storage;
  m_motion = (hkVector4f *)bodyA->m_motion;
  resulta = bodyA->m_shape;
  v18 = (__m128 *)bodyB->m_motion;
  v19 = 1i64;
  v20 = *v18;
  v21 = v18[1];
  v22 = v18[2];
  v23 = v18[3];
  v24 = bodyB->m_shape + 2;
  do
  {
    v25 = (__m128)v24->hkReferencedObject;
    v24 = (hkpShape *)((char *)v24 - 16);
    --v19;
    *(__m128 *)((char *)&v24[-1] + (char *)&B2 - (char *)m_shape - 16) = _mm_add_ps(
                                                                           _mm_add_ps(
                                                                             _mm_add_ps(
                                                                               _mm_mul_ps(
                                                                                 _mm_shuffle_ps(v25, v25, 85),
                                                                                 v21),
                                                                               _mm_mul_ps(
                                                                                 _mm_shuffle_ps(v25, v25, 0),
                                                                                 v20)),
                                                                             _mm_mul_ps(
                                                                               _mm_shuffle_ps(v25, v25, 170),
                                                                               v22)),
                                                                           v23);
  }
  while ( v19 >= 0 );
  hkLineSegmentUtil::closestPointLineSeg(m_motion + 3, &B, &B2, &v52);
  v26 = _mm_sub_ps(m_motion[3].m_quad, v52.m_pointOnEdge.m_quad);
  v27 = _mm_mul_ps(v26, v26);
  *(float *)&resultb = *(float *)&resulta[1].vfptr + *(float *)&m_shape[1].vfptr;
  v28 = _mm_shuffle_ps((__m128)resultb, (__m128)resultb, 0);
  v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)), _mm_shuffle_ps(v27, v27, 170));
  v30 = _mm_shuffle_ps((__m128)LODWORD(input->m_tolerance.m_storage), (__m128)LODWORD(input->m_tolerance.m_storage), 0).m128_f32[0]
      + v28.m128_f32[0];
  if ( v29.m128_f32[0] >= (float)(v30 * v30) )
  {
    m_contactPointId = this->m_contactPointId;
    if ( (_WORD)m_contactPointId != 0xFFFF )
    {
      ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[2].__first_virtual_table_function__)(
        this->m_contactMgr,
        m_contactPointId,
        result->m_constraintOwner.m_storage);
      this->m_contactPointId = -1;
    }
  }
  else
  {
    if ( v29.m128_f32[0] <= 0.0 )
    {
      v32 = 0i64;
      v33 = _mm_sub_ps(B2.m_quad, B.m_quad);
      v34 = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, (__m128)0i64), 196);
      v35 = _mm_shuffle_ps(v34, v34, 241);
      v36 = _mm_shuffle_ps(v34, v34, 206);
      v37 = _mm_mul_ps(v36, v36);
      v38 = _mm_mul_ps(v35, v35);
      v39 = _mm_cmplt_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                _mm_shuffle_ps(v38, v38, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
                _mm_shuffle_ps(v37, v37, 170)));
      v26 = _mm_xor_ps(
              _mm_or_ps(_mm_andnot_ps(v39, v35), _mm_and_ps(v36, v39)),
              (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
    }
    else
    {
      v31 = _mm_rsqrt_ps(v29);
      v32 = _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v29), v31)),
                _mm_mul_ps(*(__m128 *)_xmm, v31)),
              v29);
    }
    v40 = _mm_mul_ps(v26, v26);
    v41 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
            _mm_shuffle_ps(v40, v40, 170));
    v42 = _mm_rsqrt_ps(v41);
    v43 = _mm_mul_ps(
            v26,
            _mm_andnot_ps(
              _mm_cmple_ps(v41, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v42, v41), v42)),
                _mm_mul_ps(*(__m128 *)_xmm, v42))));
    v44 = _mm_shuffle_ps(v43, _mm_unpackhi_ps(v43, _mm_sub_ps(v32, v28)), 196);
    m_storage->m_contact.m_separatingNormal.m_quad = v44;
    m_storage->m_contact.m_position.m_quad = _mm_add_ps(
                                               _mm_mul_ps(
                                                 _mm_sub_ps(
                                                   _mm_shuffle_ps(
                                                     (__m128)LODWORD(m_shape[1].vfptr),
                                                     (__m128)LODWORD(m_shape[1].vfptr),
                                                     0),
                                                   v32),
                                                 v44),
                                               m_motion[3].m_quad);
    if ( this->m_contactPointId == 0xFFFF )
      this->m_contactPointId = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkpProcessCdPoint *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[1].__first_virtual_table_function__)(
                                 this->m_contactMgr,
                                 bodyA,
                                 bodyB,
                                 input,
                                 result,
                                 0i64,
                                 m_storage);
    v45 = this->m_contactPointId;
    if ( v45 != 0xFFFF )
    {
      m_storage->m_contactPointId = v45;
      ++result->m_firstFreeContactPoint.m_storage;
    }
  }
  v47 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v48 = (_QWORD *)v47[1];
  v49 = v47;
  if ( (unsigned __int64)v48 < v47[3] )
  {
    *v48 = "Et";
    v50 = __rdtsc();
    v51 = v48 + 2;
    *((_DWORD *)v51 - 2) = v50;
    v49[1] = v51;
  }
}50 = __rdtsc();
    v51 = v48 + 2;
    *((_DWORD *)v51 - 2) = v50;
    v49[1] = v51;
  }
}

// File Line: 165
// RVA: 0xD1FB20
void __fastcall hkpSphereCapsuleAgent::getClosestPoints(
        hkpSphereCapsuleAgent *this,
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
  hkpShape *m_shape; // rdi
  hkpShape *v14; // r15
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  hkVector4f *v18; // rbx
  __int64 v19; // rcx
  __m128 v20; // xmm6
  hkpShape *v21; // rax
  signed __int64 v22; // rdx
  __m128 v23; // xmm1
  __m128 m_quad; // xmm11
  __m128 v25; // xmm8
  __m128 v26; // xmm10
  __m128 v27; // xmm1
  __m128 v28; // xmm10
  __m128 v29; // xmm3
  float v30; // xmm2_4
  __m128 v31; // xmm1
  __m128 v32; // xmm7
  __m128 v33; // xmm6
  __m128 v34; // xmm6
  __m128 v35; // xmm5
  __m128 v36; // xmm6
  __m128 v37; // xmm1
  __m128 v38; // xmm4
  __m128 v39; // xmm2
  hkpCdPointCollectorVtbl *vfptr; // rax
  __m128 v41; // xmm1
  __m128 v42; // xmm3
  __m128 v43; // xmm2
  __m128 v44; // xmm8
  __m128 vfptr_low; // xmm0
  _QWORD *v46; // rax
  _QWORD *v47; // rcx
  _QWORD *v48; // r8
  unsigned __int64 v49; // rax
  _QWORD *v50; // rcx
  hkLineSegmentUtil::ClosestPointLineSegResult result; // [rsp+20h] [rbp-C8h] BYREF
  hkVector4f B; // [rsp+30h] [rbp-B8h] BYREF
  hkVector4f B2; // [rsp+40h] [rbp-A8h] BYREF
  __m128 v54; // [rsp+50h] [rbp-98h]
  hkpCdBody *v55; // [rsp+60h] [rbp-88h]
  hkpCdBody *v56; // [rsp+68h] [rbp-80h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtSphereCapsule";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  m_motion = (__m128 *)bodyB->m_motion;
  m_shape = bodyB->m_shape;
  v14 = bodyA->m_shape;
  v15 = *m_motion;
  v16 = m_motion[1];
  v17 = m_motion[2];
  v18 = (hkVector4f *)bodyA->m_motion;
  v19 = 1i64;
  v20 = m_motion[3];
  v21 = bodyB->m_shape + 2;
  v22 = (char *)&B2 - (char *)bodyB->m_shape;
  do
  {
    v23 = (__m128)v21->hkReferencedObject;
    v21 = (hkpShape *)((char *)v21 - 16);
    --v19;
    *(__m128 *)((char *)&v21[-1] + v22 - 16) = _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v16),
                                                     _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v15)),
                                                   _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v17)),
                                                 v20);
  }
  while ( v19 >= 0 );
  hkLineSegmentUtil::closestPointLineSeg(v18 + 3, &B, &B2, &result);
  m_quad = v18[3].m_quad;
  v25 = _mm_sub_ps(m_quad, result.m_pointOnEdge.m_quad);
  v26 = (__m128)COERCE_UNSIGNED_INT(*(float *)&v14[1].vfptr + *(float *)&m_shape[1].vfptr);
  v27 = _mm_mul_ps(v25, v25);
  v28 = _mm_shuffle_ps(v26, v26, 0);
  v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)), _mm_shuffle_ps(v27, v27, 170));
  v30 = _mm_shuffle_ps((__m128)LODWORD(input->m_tolerance.m_storage), (__m128)LODWORD(input->m_tolerance.m_storage), 0).m128_f32[0]
      + v28.m128_f32[0];
  if ( v29.m128_f32[0] < (float)(v30 * v30) )
  {
    if ( v29.m128_f32[0] <= 0.0 )
    {
      v32 = 0i64;
      v33 = _mm_sub_ps(B2.m_quad, B.m_quad);
      v34 = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, (__m128)0i64), 196);
      v35 = _mm_shuffle_ps(v34, v34, 241);
      v36 = _mm_shuffle_ps(v34, v34, 206);
      v37 = _mm_mul_ps(v36, v36);
      v38 = _mm_mul_ps(v35, v35);
      v39 = _mm_cmplt_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                _mm_shuffle_ps(v38, v38, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
                _mm_shuffle_ps(v37, v37, 170)));
      v25 = _mm_xor_ps(
              _mm_or_ps(_mm_andnot_ps(v39, v35), _mm_and_ps(v36, v39)),
              (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
    }
    else
    {
      v31 = _mm_rsqrt_ps(v29);
      v32 = _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v29), v31)),
                _mm_mul_ps(*(__m128 *)_xmm, v31)),
              v29);
    }
    vfptr = collector->vfptr;
    v41 = _mm_mul_ps(v25, v25);
    v42 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
            _mm_shuffle_ps(v41, v41, 170));
    v43 = _mm_rsqrt_ps(v42);
    v44 = _mm_mul_ps(
            v25,
            _mm_andnot_ps(
              _mm_cmple_ps(v42, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v42), v43)),
                _mm_mul_ps(*(__m128 *)_xmm, v43))));
    vfptr_low = (__m128)LODWORD(m_shape[1].vfptr);
    v55 = bodyA;
    v56 = bodyB;
    B2.m_quad = _mm_shuffle_ps(v44, _mm_unpackhi_ps(v44, _mm_sub_ps(v32, v28)), 196);
    v54 = B2.m_quad;
    B.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(vfptr_low, vfptr_low, 0), v32), B2.m_quad), m_quad);
    vfptr->addCdPoint(collector, (hkpCdPoint *)&B);
  }
  v46 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v47 = (_QWORD *)v46[1];
  v48 = v46;
  if ( (unsigned __int64)v47 < v46[3] )
  {
    *v47 = "Et";
    v49 = __rdtsc();
    v50 = v47 + 2;
    *((_DWORD *)v50 - 2) = v49;
    v48[1] = v50;
  }
}

// File Line: 179
// RVA: 0xD1FEC0
void __fastcall hkpSphereCapsuleAgent::staticGetClosestPoints(
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
  hkpShape *m_shape; // rdi
  hkpShape *v14; // r15
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  hkVector4f *v18; // rbx
  __int64 v19; // rcx
  __m128 v20; // xmm6
  hkpShape *v21; // rax
  signed __int64 v22; // rdx
  __m128 v23; // xmm1
  __m128 m_quad; // xmm11
  __m128 v25; // xmm8
  __m128 v26; // xmm10
  __m128 v27; // xmm1
  __m128 v28; // xmm10
  __m128 v29; // xmm3
  float v30; // xmm2_4
  __m128 v31; // xmm1
  __m128 v32; // xmm7
  __m128 v33; // xmm6
  __m128 v34; // xmm6
  __m128 v35; // xmm5
  __m128 v36; // xmm6
  __m128 v37; // xmm1
  __m128 v38; // xmm4
  __m128 v39; // xmm2
  hkpCdPointCollectorVtbl *vfptr; // rax
  __m128 v41; // xmm1
  __m128 v42; // xmm3
  __m128 v43; // xmm2
  __m128 v44; // xmm8
  __m128 vfptr_low; // xmm0
  _QWORD *v46; // rax
  _QWORD *v47; // rcx
  _QWORD *v48; // r8
  unsigned __int64 v49; // rax
  _QWORD *v50; // rcx
  hkLineSegmentUtil::ClosestPointLineSegResult result; // [rsp+20h] [rbp-D8h] BYREF
  hkVector4f B; // [rsp+30h] [rbp-C8h] BYREF
  hkVector4f B2; // [rsp+40h] [rbp-B8h] BYREF
  __m128 v54; // [rsp+50h] [rbp-A8h]
  hkpCdBody *v55; // [rsp+60h] [rbp-98h]
  hkpCdBody *v56; // [rsp+68h] [rbp-90h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtSphereCapsule";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  m_motion = (__m128 *)bodyB->m_motion;
  m_shape = bodyB->m_shape;
  v14 = bodyA->m_shape;
  v15 = *m_motion;
  v16 = m_motion[1];
  v17 = m_motion[2];
  v18 = (hkVector4f *)bodyA->m_motion;
  v19 = 1i64;
  v20 = m_motion[3];
  v21 = bodyB->m_shape + 2;
  v22 = (char *)&B2 - (char *)bodyB->m_shape;
  do
  {
    v23 = (__m128)v21->hkReferencedObject;
    v21 = (hkpShape *)((char *)v21 - 16);
    --v19;
    *(__m128 *)((char *)&v21[-1] + v22 - 16) = _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v16),
                                                     _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v15)),
                                                   _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v17)),
                                                 v20);
  }
  while ( v19 >= 0 );
  hkLineSegmentUtil::closestPointLineSeg(v18 + 3, &B, &B2, &result);
  m_quad = v18[3].m_quad;
  v25 = _mm_sub_ps(m_quad, result.m_pointOnEdge.m_quad);
  v26 = (__m128)COERCE_UNSIGNED_INT(*(float *)&v14[1].vfptr + *(float *)&m_shape[1].vfptr);
  v27 = _mm_mul_ps(v25, v25);
  v28 = _mm_shuffle_ps(v26, v26, 0);
  v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)), _mm_shuffle_ps(v27, v27, 170));
  v30 = _mm_shuffle_ps((__m128)LODWORD(input->m_tolerance.m_storage), (__m128)LODWORD(input->m_tolerance.m_storage), 0).m128_f32[0]
      + v28.m128_f32[0];
  if ( v29.m128_f32[0] < (float)(v30 * v30) )
  {
    if ( v29.m128_f32[0] <= 0.0 )
    {
      v32 = 0i64;
      v33 = _mm_sub_ps(B2.m_quad, B.m_quad);
      v34 = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, (__m128)0i64), 196);
      v35 = _mm_shuffle_ps(v34, v34, 241);
      v36 = _mm_shuffle_ps(v34, v34, 206);
      v37 = _mm_mul_ps(v36, v36);
      v38 = _mm_mul_ps(v35, v35);
      v39 = _mm_cmplt_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                _mm_shuffle_ps(v38, v38, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
                _mm_shuffle_ps(v37, v37, 170)));
      v25 = _mm_xor_ps(
              _mm_or_ps(_mm_andnot_ps(v39, v35), _mm_and_ps(v36, v39)),
              (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
    }
    else
    {
      v31 = _mm_rsqrt_ps(v29);
      v32 = _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v29), v31)),
                _mm_mul_ps(*(__m128 *)_xmm, v31)),
              v29);
    }
    vfptr = collector->vfptr;
    v41 = _mm_mul_ps(v25, v25);
    v42 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
            _mm_shuffle_ps(v41, v41, 170));
    v43 = _mm_rsqrt_ps(v42);
    v44 = _mm_mul_ps(
            v25,
            _mm_andnot_ps(
              _mm_cmple_ps(v42, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v42), v43)),
                _mm_mul_ps(*(__m128 *)_xmm, v43))));
    vfptr_low = (__m128)LODWORD(m_shape[1].vfptr);
    v55 = bodyA;
    v56 = bodyB;
    B2.m_quad = _mm_shuffle_ps(v44, _mm_unpackhi_ps(v44, _mm_sub_ps(v32, v28)), 196);
    v54 = B2.m_quad;
    B.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(vfptr_low, vfptr_low, 0), v32), B2.m_quad), m_quad);
    vfptr->addCdPoint(collector, (hkpCdPoint *)&B);
  }
  v46 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v47 = (_QWORD *)v46[1];
  v48 = v46;
  if ( (unsigned __int64)v47 < v46[3] )
  {
    *v47 = "Et";
    v49 = __rdtsc();
    v50 = v47 + 2;
    *((_DWORD *)v50 - 2) = v49;
    v48[1] = v50;
  }
}

// File Line: 193
// RVA: 0xD20280
void __fastcall hkpSphereCapsuleAgent::staticGetPenetrations(
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
  hkpShape *v14; // r15
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  hkVector4f *v18; // rbp
  __int64 v19; // rcx
  __m128 v20; // xmm6
  hkpShape *v21; // rax
  signed __int64 v22; // rdx
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  float v25; // xmm2_4
  __m128 v26; // xmm3
  _QWORD *v27; // r8
  _QWORD *v28; // rcx
  unsigned __int64 v29; // rax
  _QWORD *v30; // rcx
  hkLineSegmentUtil::ClosestPointLineSegResult result; // [rsp+20h] [rbp-58h] BYREF
  hkVector4f B; // [rsp+30h] [rbp-48h] BYREF
  hkVector4f B2; // [rsp+40h] [rbp-38h] BYREF
  unsigned int v34; // [rsp+80h] [rbp+8h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)Value[1];
  v9 = Value;
  if ( (unsigned __int64)v8 < Value[3] )
  {
    *v8 = "TtSphereCapsule";
    v10 = __rdtsc();
    v11 = v8 + 2;
    *((_DWORD *)v11 - 2) = v10;
    v9[1] = v11;
  }
  m_motion = (__m128 *)bodyB->m_motion;
  m_shape = bodyB->m_shape;
  v14 = bodyA->m_shape;
  v15 = *m_motion;
  v16 = m_motion[1];
  v17 = m_motion[2];
  v18 = (hkVector4f *)bodyA->m_motion;
  v19 = 1i64;
  v20 = m_motion[3];
  v21 = bodyB->m_shape + 2;
  v22 = (char *)&B2 - (char *)bodyB->m_shape;
  do
  {
    v23 = (__m128)v21->hkReferencedObject;
    v21 = (hkpShape *)((char *)v21 - 16);
    --v19;
    *(__m128 *)((char *)&v21[-1] + v22 - 16) = _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v16),
                                                     _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v15)),
                                                   _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v17)),
                                                 v20);
  }
  while ( v19 >= 0 );
  hkLineSegmentUtil::closestPointLineSeg(v18 + 3, &B, &B2, &result);
  v24 = _mm_sub_ps(result.m_pointOnEdge.m_quad, v18[3].m_quad);
  *(float *)&v34 = *(float *)&m_shape[1].vfptr + *(float *)&v14[1].vfptr;
  v25 = _mm_shuffle_ps((__m128)v34, (__m128)v34, 0).m128_f32[0];
  v26 = _mm_mul_ps(v24, v24);
  if ( (float)((float)(_mm_shuffle_ps(v26, v26, 85).m128_f32[0] + _mm_shuffle_ps(v26, v26, 0).m128_f32[0])
             + _mm_shuffle_ps(v26, v26, 170).m128_f32[0]) < (float)(v25 * v25) )
    collector->vfptr->addCdBodyPair(collector, bodyA, bodyB);
  v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v28 = (_QWORD *)v27[1];
  if ( (unsigned __int64)v28 < v27[3] )
  {
    *v28 = "Et";
    v29 = __rdtsc();
    v30 = v28 + 2;
    *((_DWORD *)v30 - 2) = v29;
    v27[1] = v30;
  }
}

// File Line: 221
// RVA: 0xD20260
void __fastcall hkpSphereCapsuleAgent::getPenetrations(
        hkpSphereCapsuleAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpSphereCapsuleAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}


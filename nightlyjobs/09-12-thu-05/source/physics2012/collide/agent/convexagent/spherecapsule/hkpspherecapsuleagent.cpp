// File Line: 26
// RVA: 0xD1FA70
void __fastcall hkpSphereCapsuleAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  f.m_createFunc = hkpSphereCapsuleAgent::createCapsuleSphereAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpSphereCapsuleAgent>::staticGetPenetrations;
  v1 = dispatcher;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpSphereCapsuleAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 1;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpCapsuleTriangleAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, CAPSULE, 0);
  f.m_createFunc = hkpSphereCapsuleAgent::createSphereCapsuleAgent;
  f.m_getPenetrationsFunc = hkpSphereCapsuleAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSphereCapsuleAgent::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  f.m_linearCastFunc = hkpIterativeLinearCastAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, 0, CAPSULE);
}

// File Line: 52
// RVA: 0xD204C0
hkpCollisionAgent *__fastcall hkpSphereCapsuleAgent::createCapsuleSphereAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // rbx
  _QWORD **v5; // rax
  hkpCollisionAgent *result; // rax

  v4 = mgr;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 32i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgentLinearCast<hkpSphereCapsuleAgent>::`vftable;
    result->m_contactMgr = v4;
    LOWORD(result[1].vfptr) = -1;
  }
  return result;
}

// File Line: 59
// RVA: 0xD20460
hkpCollisionAgent *__fastcall hkpSphereCapsuleAgent::createSphereCapsuleAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // rbx
  _QWORD **v5; // rax
  hkpCollisionAgent *result; // rax

  v4 = mgr;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 32i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpSphereCapsuleAgent::`vftable;
    result->m_contactMgr = v4;
    LOWORD(result[1].vfptr) = -1;
  }
  return result;
}

// File Line: 64
// RVA: 0xD20420
void __fastcall hkpSphereCapsuleAgent::cleanup(hkpSphereCapsuleAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpConstraintOwner *v2; // r8
  __int64 v3; // rdx
  hkpSphereCapsuleAgent *v4; // rbx

  v2 = constraintOwner;
  v3 = this->m_contactPointId;
  v4 = this;
  if ( (_WORD)v3 != -1 )
    ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
      this->m_contactMgr,
      v3,
      v2);
  ((void (__fastcall *)(hkpSphereCapsuleAgent *, signed __int64, hkpConstraintOwner *))v4->vfptr->__vecDelDtor)(
    v4,
    1i64,
    v2);
}

// File Line: 117
// RVA: 0xD20520
signed __int64 __fastcall hkpSphereCapsuleAgent::getClosestPoint(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkContactPoint *cpoint)
{
  hkpShape *v4; // rdi
  hkVector4f *v5; // rbx
  hkpShape *v6; // rbp
  __m128 *v7; // rax
  hkContactPoint *v8; // r14
  hkpCollisionInput *v9; // rsi
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  __m128 v12; // xmm5
  signed __int64 v13; // rcx
  __m128 v14; // xmm6
  hkpShape *v15; // rax
  __m128 v16; // xmm1
  __m128 v17; // xmm7
  __m128 v18; // xmm9
  __m128 v19; // xmm1
  __m128 v20; // xmm9
  __m128 v21; // xmm3
  float v22; // xmm2_4
  signed __int64 v23; // rax
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
  __m128 v37; // xmm7
  hkLineSegmentUtil::ClosestPointLineSegResult result; // [rsp+20h] [rbp-88h]
  hkVector4f B; // [rsp+30h] [rbp-78h]
  hkVector4f B2; // [rsp+40h] [rbp-68h]

  v4 = bodyB->m_shape;
  v5 = (hkVector4f *)bodyA->m_motion;
  v6 = bodyA->m_shape;
  v7 = (__m128 *)bodyB->m_motion;
  v8 = cpoint;
  v9 = input;
  v10 = *v7;
  v11 = v7[1];
  v12 = v7[2];
  v13 = 1i64;
  v14 = v7[3];
  v15 = bodyB->m_shape + 2;
  do
  {
    v16 = *(__m128 *)&v15->vfptr;
    v15 = (hkpShape *)((char *)v15 - 16);
    --v13;
    *(__m128 *)((char *)&v15[-1] + (char *)&B2 - (char *)v4 - 16) = _mm_add_ps(
                                                                      _mm_add_ps(
                                                                        _mm_add_ps(
                                                                          _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), v11),
                                                                          _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v10)),
                                                                        _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), v12)),
                                                                      v14);
  }
  while ( v13 >= 0 );
  hkLineSegmentUtil::closestPointLineSeg(v5 + 3, &B, &B2, &result);
  v17 = _mm_sub_ps(v5[3].m_quad, result.m_pointOnEdge.m_quad);
  v18 = (__m128)COERCE_UNSIGNED_INT(*(float *)&v6[1].vfptr + *(float *)&v4[1].vfptr);
  v19 = _mm_mul_ps(v17, v17);
  v20 = _mm_shuffle_ps(v18, v18, 0);
  v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v22 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v9->m_tolerance.m_storage), (__m128)LODWORD(v9->m_tolerance.m_storage), 0))
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
    v32 = _mm_cmpltps(
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
            _mm_cmpleps(v34, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v34), v35)),
              _mm_mul_ps(*(__m128 *)_xmm, v35))));
  v37 = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, _mm_sub_ps(v25, v20)), 196);
  v8->m_separatingNormal.m_quad = v37;
  v8->m_position.m_quad = _mm_add_ps(
                            _mm_mul_ps(
                              _mm_sub_ps(
                                _mm_shuffle_ps((__m128)LODWORD(v4[1].vfptr), (__m128)LODWORD(v4[1].vfptr), 0),
                                v25),
                              v37),
                            v5[3].m_quad);
  return v23;
}

// File Line: 126
// RVA: 0xD208F0
void __fastcall hkpSphereCapsuleAgent::processCollision(hkpSphereCapsuleAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *result)
{
  hkpSphereCapsuleAgent *v5; // rbx
  hkpProcessCollisionInput *v6; // r12
  hkpCdBody *v7; // r14
  hkpCdBody *v8; // r15
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  hkpProcessCollisionOutput *v14; // rdi
  hkpShape *v15; // rbp
  hkpProcessCdPoint *v16; // r13
  hkVector4f *v17; // rsi
  __m128 *v18; // rax
  signed __int64 v19; // rcx
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  __m128 v23; // xmm6
  __m128 *v24; // rax
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
  __int64 v46; // rdx
  _QWORD *v47; // rax
  _QWORD *v48; // rcx
  _QWORD *v49; // r8
  unsigned __int64 v50; // rax
  signed __int64 v51; // rcx
  hkLineSegmentUtil::ClosestPointLineSegResult v52; // [rsp+40h] [rbp-A8h]
  hkVector4f B; // [rsp+50h] [rbp-98h]
  hkVector4f B2; // [rsp+60h] [rbp-88h]
  hkpProcessCollisionOutput *resulta; // [rsp+110h] [rbp+28h]
  unsigned int resultb; // [rsp+110h] [rbp+28h]

  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtSphereCapsule";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v14 = result;
  v15 = v7->m_shape;
  v16 = result->m_firstFreeContactPoint.m_storage;
  v17 = (hkVector4f *)v8->m_motion;
  resulta = (hkpProcessCollisionOutput *)v8->m_shape;
  v18 = (__m128 *)v7->m_motion;
  v19 = 1i64;
  v20 = *v18;
  v21 = v18[1];
  v22 = v18[2];
  v23 = v18[3];
  v24 = (__m128 *)&v7->m_shape[2];
  do
  {
    v25 = *v24;
    --v24;
    --v19;
    *(__m128 *)((char *)v24 + (char *)&B2 - (char *)v15 - 48) = _mm_add_ps(
                                                                  _mm_add_ps(
                                                                    _mm_add_ps(
                                                                      _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v21),
                                                                      _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v20)),
                                                                    _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v22)),
                                                                  v23);
  }
  while ( v19 >= 0 );
  hkLineSegmentUtil::closestPointLineSeg(v17 + 3, &B, &B2, &v52);
  v26 = _mm_sub_ps(v17[3].m_quad, v52.m_pointOnEdge.m_quad);
  v27 = _mm_mul_ps(v26, v26);
  *(float *)&resultb = resulta->m_contactPoints[0].m_contact.m_separatingNormal.m_quad.m128_f32[0]
                     + *(float *)&v15[1].vfptr;
  v28 = _mm_shuffle_ps((__m128)resultb, (__m128)resultb, 0);
  v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)), _mm_shuffle_ps(v27, v27, 170));
  v30 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v6->m_tolerance.m_storage), (__m128)LODWORD(v6->m_tolerance.m_storage), 0))
      + v28.m128_f32[0];
  if ( v29.m128_f32[0] >= (float)(v30 * v30) )
  {
    v46 = v5->m_contactPointId;
    if ( (_WORD)v46 != -1 )
    {
      ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))v5->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
        v5->m_contactMgr,
        v46,
        v14->m_constraintOwner.m_storage);
      v5->m_contactPointId = -1;
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
      v39 = _mm_cmpltps(
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
              _mm_cmpleps(v41, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v42, v41), v42)),
                _mm_mul_ps(*(__m128 *)_xmm, v42))));
    v44 = _mm_shuffle_ps(v43, _mm_unpackhi_ps(v43, _mm_sub_ps(v32, v28)), 196);
    v16->m_contact.m_separatingNormal.m_quad = v44;
    v16->m_contact.m_position.m_quad = _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_sub_ps(
                                             _mm_shuffle_ps(
                                               (__m128)LODWORD(v15[1].vfptr),
                                               (__m128)LODWORD(v15[1].vfptr),
                                               0),
                                             v32),
                                           v44),
                                         v17[3].m_quad);
    if ( v5->m_contactPointId == -1 )
      v5->m_contactPointId = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkpProcessCdPoint *))v5->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
                               v5->m_contactMgr,
                               v8,
                               v7,
                               v6,
                               v14,
                               0i64,
                               v16);
    v45 = v5->m_contactPointId;
    if ( v45 != -1 )
    {
      v16->m_contactPointId = v45;
      ++v14->m_firstFreeContactPoint.m_storage;
    }
  }
  v47 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v48 = (_QWORD *)v47[1];
  v49 = v47;
  if ( (unsigned __int64)v48 < v47[3] )
  {
    *v48 = "Et";
    v50 = __rdtsc();
    v51 = (signed __int64)(v48 + 2);
    *(_DWORD *)(v51 - 8) = v50;
    v49[1] = v51;
  }
}

// File Line: 165
// RVA: 0xD1FB20
void __fastcall hkpSphereCapsuleAgent::getClosestPoints(hkpSphereCapsuleAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpCollisionInput *v5; // rbp
  hkpCdBody *v6; // rsi
  hkpCdBody *v7; // r14
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 *v12; // rax
  hkpShape *v13; // rdi
  hkpShape *v14; // r15
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  hkVector4f *v18; // rbx
  signed __int64 v19; // rcx
  __m128 v20; // xmm6
  __m128 *v21; // rax
  char *v22; // rdx
  __m128 v23; // xmm1
  __m128 v24; // xmm11
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
  hkpCdPointCollectorVtbl *v40; // rax
  __m128 v41; // xmm1
  __m128 v42; // xmm3
  __m128 v43; // xmm2
  __m128 v44; // xmm8
  __m128 v45; // xmm0
  _QWORD *v46; // rax
  _QWORD *v47; // rcx
  _QWORD *v48; // r8
  unsigned __int64 v49; // rax
  signed __int64 v50; // rcx
  hkLineSegmentUtil::ClosestPointLineSegResult result; // [rsp+20h] [rbp-C8h]
  hkVector4f B; // [rsp+30h] [rbp-B8h]
  hkVector4f B2; // [rsp+40h] [rbp-A8h]
  __m128 v54; // [rsp+50h] [rbp-98h]
  hkpCdBody *v55; // [rsp+60h] [rbp-88h]
  hkpCdBody *v56; // [rsp+68h] [rbp-80h]

  v5 = input;
  v6 = bodyB;
  v7 = bodyA;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtSphereCapsule";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = (__m128 *)v6->m_motion;
  v13 = v6->m_shape;
  v14 = v7->m_shape;
  v15 = *v12;
  v16 = v12[1];
  v17 = v12[2];
  v18 = (hkVector4f *)v7->m_motion;
  v19 = 1i64;
  v20 = v12[3];
  v21 = (__m128 *)&v6->m_shape[2];
  v22 = (char *)((char *)&B2 - (char *)v6->m_shape);
  do
  {
    v23 = *v21;
    --v21;
    --v19;
    *(__m128 *)((char *)v21 + (_QWORD)v22 - 48) = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v16),
                                                        _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v15)),
                                                      _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v17)),
                                                    v20);
  }
  while ( v19 >= 0 );
  hkLineSegmentUtil::closestPointLineSeg(v18 + 3, &B, &B2, &result);
  v24 = v18[3].m_quad;
  v25 = _mm_sub_ps(v24, result.m_pointOnEdge.m_quad);
  v26 = (__m128)COERCE_UNSIGNED_INT(*(float *)&v14[1].vfptr + *(float *)&v13[1].vfptr);
  v27 = _mm_mul_ps(v25, v25);
  v28 = _mm_shuffle_ps(v26, v26, 0);
  v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)), _mm_shuffle_ps(v27, v27, 170));
  v30 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v5->m_tolerance.m_storage), (__m128)LODWORD(v5->m_tolerance.m_storage), 0))
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
      v39 = _mm_cmpltps(
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
    v40 = collector->vfptr;
    v41 = _mm_mul_ps(v25, v25);
    v42 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
            _mm_shuffle_ps(v41, v41, 170));
    v43 = _mm_rsqrt_ps(v42);
    v44 = _mm_mul_ps(
            v25,
            _mm_andnot_ps(
              _mm_cmpleps(v42, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v42), v43)),
                _mm_mul_ps(*(__m128 *)_xmm, v43))));
    v45 = (__m128)LODWORD(v13[1].vfptr);
    v55 = v7;
    v56 = v6;
    B2.m_quad = _mm_shuffle_ps(v44, _mm_unpackhi_ps(v44, _mm_sub_ps(v32, v28)), 196);
    v54 = B2.m_quad;
    B.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v45, v45, 0), v32), B2.m_quad), v24);
    v40->addCdPoint(collector, (hkpCdPoint *)&B);
  }
  v46 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v47 = (_QWORD *)v46[1];
  v48 = v46;
  if ( (unsigned __int64)v47 < v46[3] )
  {
    *v47 = "Et";
    v49 = __rdtsc();
    v50 = (signed __int64)(v47 + 2);
    *(_DWORD *)(v50 - 8) = v49;
    v48[1] = v50;
  }
}

// File Line: 179
// RVA: 0xD1FEC0
void __fastcall hkpSphereCapsuleAgent::staticGetClosestPoints(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpCdBody *v4; // r14
  hkpCdPointCollector *v5; // r12
  hkpCollisionInput *v6; // rbp
  hkpCdBody *v7; // rsi
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 *v12; // rax
  hkpShape *v13; // rdi
  hkpShape *v14; // r15
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  hkVector4f *v18; // rbx
  signed __int64 v19; // rcx
  __m128 v20; // xmm6
  __m128 *v21; // rax
  char *v22; // rdx
  __m128 v23; // xmm1
  __m128 v24; // xmm11
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
  hkpCdPointCollectorVtbl *v40; // rax
  __m128 v41; // xmm1
  __m128 v42; // xmm3
  __m128 v43; // xmm2
  __m128 v44; // xmm8
  __m128 v45; // xmm0
  _QWORD *v46; // rax
  _QWORD *v47; // rcx
  _QWORD *v48; // r8
  unsigned __int64 v49; // rax
  signed __int64 v50; // rcx
  hkLineSegmentUtil::ClosestPointLineSegResult result; // [rsp+20h] [rbp-D8h]
  hkVector4f B; // [rsp+30h] [rbp-C8h]
  hkVector4f B2; // [rsp+40h] [rbp-B8h]
  __m128 v54; // [rsp+50h] [rbp-A8h]
  hkpCdBody *v55; // [rsp+60h] [rbp-98h]
  hkpCdBody *v56; // [rsp+68h] [rbp-90h]

  v4 = bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtSphereCapsule";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = (__m128 *)v7->m_motion;
  v13 = v7->m_shape;
  v14 = v4->m_shape;
  v15 = *v12;
  v16 = v12[1];
  v17 = v12[2];
  v18 = (hkVector4f *)v4->m_motion;
  v19 = 1i64;
  v20 = v12[3];
  v21 = (__m128 *)&v7->m_shape[2];
  v22 = (char *)((char *)&B2 - (char *)v7->m_shape);
  do
  {
    v23 = *v21;
    --v21;
    --v19;
    *(__m128 *)((char *)v21 + (_QWORD)v22 - 48) = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v16),
                                                        _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v15)),
                                                      _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v17)),
                                                    v20);
  }
  while ( v19 >= 0 );
  hkLineSegmentUtil::closestPointLineSeg(v18 + 3, &B, &B2, &result);
  v24 = v18[3].m_quad;
  v25 = _mm_sub_ps(v24, result.m_pointOnEdge.m_quad);
  v26 = (__m128)COERCE_UNSIGNED_INT(*(float *)&v14[1].vfptr + *(float *)&v13[1].vfptr);
  v27 = _mm_mul_ps(v25, v25);
  v28 = _mm_shuffle_ps(v26, v26, 0);
  v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)), _mm_shuffle_ps(v27, v27, 170));
  v30 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v6->m_tolerance.m_storage), (__m128)LODWORD(v6->m_tolerance.m_storage), 0))
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
      v39 = _mm_cmpltps(
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
    v40 = v5->vfptr;
    v41 = _mm_mul_ps(v25, v25);
    v42 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
            _mm_shuffle_ps(v41, v41, 170));
    v43 = _mm_rsqrt_ps(v42);
    v44 = _mm_mul_ps(
            v25,
            _mm_andnot_ps(
              _mm_cmpleps(v42, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v42), v43)),
                _mm_mul_ps(*(__m128 *)_xmm, v43))));
    v45 = (__m128)LODWORD(v13[1].vfptr);
    v55 = v4;
    v56 = v7;
    B2.m_quad = _mm_shuffle_ps(v44, _mm_unpackhi_ps(v44, _mm_sub_ps(v32, v28)), 196);
    v54 = B2.m_quad;
    B.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v45, v45, 0), v32), B2.m_quad), v24);
    v40->addCdPoint(v5, (hkpCdPoint *)&B);
  }
  v46 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v47 = (_QWORD *)v46[1];
  v48 = v46;
  if ( (unsigned __int64)v47 < v46[3] )
  {
    *v47 = "Et";
    v49 = __rdtsc();
    v50 = (signed __int64)(v47 + 2);
    *(_DWORD *)(v50 - 8) = v49;
    v48[1] = v50;
  }
}

// File Line: 193
// RVA: 0xD20280
void __fastcall hkpSphereCapsuleAgent::staticGetPenetrations(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpCdBody *v4; // rdi
  hkpCdBodyPairCollector *v5; // rsi
  hkpCdBody *v6; // rbx
  _QWORD *v7; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r8
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 *v12; // rax
  hkpShape *v13; // r14
  hkpShape *v14; // r15
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  hkVector4f *v18; // rbp
  signed __int64 v19; // rcx
  __m128 v20; // xmm6
  __m128 *v21; // rax
  char *v22; // rdx
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  float v25; // xmm2_4
  __m128 v26; // xmm3
  _QWORD *v27; // r8
  _QWORD *v28; // rcx
  unsigned __int64 v29; // rax
  signed __int64 v30; // rcx
  hkLineSegmentUtil::ClosestPointLineSegResult result; // [rsp+20h] [rbp-58h]
  hkVector4f B; // [rsp+30h] [rbp-48h]
  hkVector4f B2; // [rsp+40h] [rbp-38h]
  unsigned int v34; // [rsp+80h] [rbp+8h]

  v4 = bodyA;
  v5 = collector;
  v6 = bodyB;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)v7[1];
  v9 = v7;
  if ( (unsigned __int64)v8 < v7[3] )
  {
    *v8 = "TtSphereCapsule";
    v10 = __rdtsc();
    v11 = (signed __int64)(v8 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v9[1] = v11;
  }
  v12 = (__m128 *)v6->m_motion;
  v13 = v6->m_shape;
  v14 = v4->m_shape;
  v15 = *v12;
  v16 = v12[1];
  v17 = v12[2];
  v18 = (hkVector4f *)v4->m_motion;
  v19 = 1i64;
  v20 = v12[3];
  v21 = (__m128 *)&v6->m_shape[2];
  v22 = (char *)((char *)&B2 - (char *)v6->m_shape);
  do
  {
    v23 = *v21;
    --v21;
    --v19;
    *(__m128 *)((char *)v21 + (_QWORD)v22 - 48) = _mm_add_ps(
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
  *(float *)&v34 = *(float *)&v13[1].vfptr + *(float *)&v14[1].vfptr;
  LODWORD(v25) = (unsigned __int128)_mm_shuffle_ps((__m128)v34, (__m128)v34, 0);
  v26 = _mm_mul_ps(v24, v24);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 170))) < (float)(v25 * v25) )
    v5->vfptr->addCdBodyPair(v5, v4, v6);
  v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v28 = (_QWORD *)v27[1];
  if ( (unsigned __int64)v28 < v27[3] )
  {
    *v28 = "Et";
    v29 = __rdtsc();
    v30 = (signed __int64)(v28 + 2);
    *(_DWORD *)(v30 - 8) = v29;
    v27[1] = v30;
  }
}

// File Line: 221
// RVA: 0xD20260
void __fastcall hkpSphereCapsuleAgent::getPenetrations(hkpSphereCapsuleAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpSphereCapsuleAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}


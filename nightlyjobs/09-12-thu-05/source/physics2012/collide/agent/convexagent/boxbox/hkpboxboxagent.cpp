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
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  v1 = dispatcher;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpBoxBoxAgent::initAgentFunc(&f);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, BOX, BOX);
}

// File Line: 58
// RVA: 0xD1AAE0
hkpCollisionAgent *__fastcall hkpBoxBoxAgent::createBoxBoxAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *contactMgr)
{
  hkpContactMgr *v4; // rdi
  __m128 v5; // xmm3
  __m128 v6; // xmm0
  _QWORD **v8; // rax
  __int64 v9; // rax
  __int64 v10; // rbx

  v4 = contactMgr;
  v5 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_999), (__m128)LODWORD(FLOAT_1_999), 0);
  v6 = _mm_shuffle_ps((__m128)LODWORD(input->m_tolerance.m_storage), (__m128)LODWORD(input->m_tolerance.m_storage), 0);
  if ( _mm_movemask_ps(
         _mm_or_ps(
           _mm_cmpleps(
             _mm_mul_ps(
               _mm_shuffle_ps(
                 *(__m128 *)&bodyB->m_shape[1].m_type.m_storage,
                 *(__m128 *)&bodyB->m_shape[1].m_type.m_storage,
                 255),
               v5),
             v6),
           _mm_cmpleps(
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
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 96i64);
  v10 = v9;
  if ( !v9 )
    return 0i64;
  *(_DWORD *)(v9 + 8) = 0x1FFFF;
  *(_QWORD *)(v9 + 16) = v4;
  *(_QWORD *)v9 = &hkpBoxBoxAgent::`vftable;
  hkpBoxBoxManifold::hkpBoxBoxManifold((hkpBoxBoxManifold *)(v9 + 32));
  return (hkpCollisionAgent *)v10;
}

// File Line: 88
// RVA: 0xD1AA60
void __fastcall hkpBoxBoxAgent::cleanup(hkpBoxBoxAgent *this, hkpConstraintOwner *constraintOwner)
{
  signed int v2; // esi
  hkpConstraintOwner *v3; // rbp
  hkpBoxBoxAgent *v4; // rbx
  unsigned __int16 *v5; // rdi

  v2 = 0;
  v3 = constraintOwner;
  v4 = this;
  if ( this->m_manifold.m_numPoints )
  {
    v5 = &this->m_manifold.m_contactPoints[0].m_contactPointId;
    do
    {
      ((void (__fastcall *)(hkpContactMgr *, _QWORD, hkpConstraintOwner *))v4->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
        v4->m_contactMgr,
        *v5,
        v3);
      ++v2;
      v5 += 2;
    }
    while ( v2 < (unsigned __int8)v4->m_manifold.m_numPoints );
  }
  v4->vfptr->__vecDelDtor((hkBaseObject *)&v4->vfptr, 1u);
}

// File Line: 101
// RVA: 0xD1A400
void __fastcall hkpBoxBoxAgent::processCollision(hkpBoxBoxAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input)
{
  hkpBoxBoxAgent *v4; // r14
  hkpProcessCollisionInput *v5; // rsi
  hkpCdBody *v6; // rbx
  hkpCdBody *v7; // rdi
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 *v12; // rcx
  __m128 *v13; // rax
  hkTransformf *v14; // r8
  hkTransformf *v15; // rdx
  __m128 v16; // xmm6
  __m128i v17; // xmm7
  __m128i v18; // xmm8
  __m128 v19; // xmm6
  hkpProcessCollisionInput *v20; // rax
  hkVector4f v21; // xmm1
  hkpContactMgr *v22; // rax
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  hkTransformf v27; // [rsp+20h] [rbp-C8h]
  hkpBoxBoxCollisionDetection v28; // [rsp+60h] [rbp-88h]
  unsigned int v29; // [rsp+1E8h] [rbp+100h]
  hkpCdBody *v30; // [rsp+208h] [rbp+120h]

  v4 = this;
  v5 = input;
  v6 = bodyB;
  v7 = bodyA;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtBoxBox";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = (__m128 *)v6->m_shape;
  v13 = (__m128 *)v7->m_shape;
  v14 = (hkTransformf *)v6->m_motion;
  v15 = (hkTransformf *)v7->m_motion;
  v29 = LODWORD(v5->m_tolerance.m_storage);
  v16 = (__m128)v29;
  v17 = (__m128i)_mm_add_ps(_mm_shuffle_ps((__m128)v12[2].m128_u32[0], (__m128)v12[2].m128_u32[0], 0), v12[3]);
  v18 = (__m128i)_mm_add_ps(_mm_shuffle_ps((__m128)v13[2].m128_u32[0], (__m128)v13[2].m128_u32[0], 0), v13[3]);
  hkTransformf::setMulInverseMul(&v27, v15, v14);
  v19 = _mm_shuffle_ps(v16, v16, 0);
  v28.m_contactMgr = v4->m_contactMgr;
  *(hkVector4f *)&v28.m_wTa = v27.m_rotation.m_col0;
  *(hkVector4f *)(&v28.m_wTb + 1) = v27.m_rotation.m_col1;
  v28.m_bodyB = v30;
  v20 = (hkpProcessCollisionInput *)v7->m_motion;
  v28.m_bodyA = v7;
  v21.m_quad = (__m128)v27.m_translation;
  *(hkVector4f *)((char *)&v28.m_aTb.m_rotation.m_col0 + 8) = v27.m_rotation.m_col2;
  _mm_store_si128((__m128i *)&v28.m_aTb.m_rotation.m_col2.m_quad.m128_u16[4], v18);
  v28.m_env = v20;
  v22 = (hkpContactMgr *)v6->m_motion;
  v28.m_bodyB = v6;
  *(hkVector4f *)((char *)&v28.m_aTb.m_rotation.m_col1 + 8) = (hkVector4f)v21.m_quad;
  _mm_store_si128((__m128i *)&v28.m_aTb.m_translation.m_quad.m128_u16[4], v17);
  v28.m_env = v5;
  v28.m_contactMgr = v22;
  *(__m128 *)((char *)&v28.m_radiusA.m_quad + 8) = _mm_shuffle_ps(
                                                     v19,
                                                     _mm_unpackhi_ps(v19, (__m128)xmmword_141A712A0),
                                                     196);
  *(__m128 *)((char *)&v28.m_keepRadiusA.m_quad + 8) = _mm_shuffle_ps(
                                                         (__m128)LODWORD(FLOAT_0_0099999998),
                                                         (__m128)LODWORD(FLOAT_0_0099999998),
                                                         0);
  *(__m128 *)((char *)&v28.m_tolerance4.m_quad + 8) = _mm_add_ps(
                                                        *(__m128 *)((char *)&v28.m_radiusA.m_quad + 8),
                                                        (__m128)v17);
  *(__m128 *)((char *)&v28.m_radiusB.m_quad + 8) = _mm_add_ps(
                                                     *(__m128 *)((char *)&v28.m_radiusA.m_quad + 8),
                                                     (__m128)v18);
  hkpBoxBoxCollisionDetection::calcManifold(&v28, &v4->m_manifold);
  v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v24 = (_QWORD *)v23[1];
  if ( (unsigned __int64)v24 < v23[3] )
  {
    *v24 = "Et";
    v25 = __rdtsc();
    v26 = (signed __int64)(v24 + 2);
    *(_DWORD *)(v26 - 8) = v25;
    v23[1] = v26;
  }
}

// File Line: 128
// RVA: 0xD1A600
void __fastcall hkpBoxBoxAgent::staticGetClosestPoints(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpCdBody *v4; // rsi
  hkpCdPointCollector *v5; // rbx
  hkpCollisionInput *v6; // r14
  hkpCdBody *v7; // rdi
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 *v12; // rcx
  __m128 *v13; // rax
  hkTransformf *v14; // r8
  hkTransformf *v15; // rdx
  __m128 v16; // xmm6
  __m128i v17; // xmm7
  __m128i v18; // xmm8
  hkTransformf *v19; // rax
  hkVector4f v20; // xmm1
  __m128 v21; // xmm6
  hkTransformf *v22; // rax
  hkpCdPointCollectorVtbl *v23; // rax
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  signed __int64 v27; // rcx
  hkVector4f v28; // [rsp+20h] [rbp-C8h]
  hkVector4f v29; // [rsp+30h] [rbp-B8h]
  hkVector4f v30; // [rsp+40h] [rbp-A8h]
  hkpCdBody *v31; // [rsp+50h] [rbp-98h]
  hkpCdBody *v32; // [rsp+58h] [rbp-90h]
  hkTransformf v33; // [rsp+60h] [rbp-88h]
  hkpBoxBoxCollisionDetection v34; // [rsp+A8h] [rbp-40h]
  hkBool result; // [rsp+248h] [rbp+160h]
  unsigned int vars0; // [rsp+250h] [rbp+168h]

  v4 = bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtBoxBox";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = (__m128 *)v7->m_shape;
  v13 = (__m128 *)v4->m_shape;
  v14 = (hkTransformf *)v7->m_motion;
  v15 = (hkTransformf *)v4->m_motion;
  vars0 = LODWORD(v6->m_tolerance.m_storage);
  v16 = (__m128)vars0;
  v17 = (__m128i)_mm_add_ps(_mm_shuffle_ps((__m128)v12[2].m128_u32[0], (__m128)v12[2].m128_u32[0], 0), v12[3]);
  v18 = (__m128i)_mm_add_ps(_mm_shuffle_ps((__m128)v13[2].m128_u32[0], (__m128)v13[2].m128_u32[0], 0), v13[3]);
  hkTransformf::setMulInverseMul((hkTransformf *)((char *)&v33 + 8), v15, v14);
  v19 = (hkTransformf *)v4->m_motion;
  v20.m_quad = *(__m128 *)((char *)&v33.m_rotation.m_col1 + 8);
  v21 = _mm_shuffle_ps(v16, v16, 0);
  _mm_store_si128((__m128i *)&v34.m_env, (__m128i)0i64);
  v34.m_aTb.m_rotation.m_col1 = (hkVector4f)v20.m_quad;
  v34.m_wTa = v19;
  v22 = (hkTransformf *)v7->m_motion;
  v34.m_aTb.m_rotation.m_col0 = *(hkVector4f *)((char *)&v33.m_rotation.m_col0 + 8);
  v34.m_bodyA = v4;
  v34.m_bodyB = v7;
  v34.m_aTb.m_rotation.m_col2 = *(hkVector4f *)((char *)&v33.m_rotation.m_col2 + 8);
  v34.m_aTb.m_translation = *(hkVector4f *)((char *)&v33.m_translation + 8);
  _mm_store_si128((__m128i *)&v34.m_radiusA, v18);
  v34.m_result = 0i64;
  v34.m_wTb = v22;
  vars0 = LODWORD(FLOAT_0_0099999998);
  _mm_store_si128((__m128i *)&v34.m_radiusB, v17);
  v34.m_boundaryTolerance.m_real = _mm_shuffle_ps(
                                     (__m128)LODWORD(FLOAT_0_0099999998),
                                     (__m128)LODWORD(FLOAT_0_0099999998),
                                     0);
  v34.m_tolerance4.m_quad = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, (__m128)xmmword_141A712A0), 196);
  v34.m_keepRadiusB.m_quad = _mm_add_ps(v34.m_tolerance4.m_quad, (__m128)v17);
  v34.m_keepRadiusA.m_quad = _mm_add_ps(v34.m_tolerance4.m_quad, (__m128)v18);
  hkpBoxBoxCollisionDetection::calculateClosestPoint(&v34, &result, (hkContactPoint *)&v33);
  if ( result.m_bool )
  {
    v23 = v5->vfptr;
    v31 = v4;
    v28.m_quad = (__m128)v33.m_rotation.m_col0;
    v29.m_quad = (__m128)v33.m_rotation.m_col1;
    v30.m_quad = (__m128)v33.m_rotation.m_col1;
    v32 = v7;
    v23->addCdPoint(v5, (hkpCdPoint *)&v28);
  }
  v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v25 = (_QWORD *)v24[1];
  if ( (unsigned __int64)v25 < v24[3] )
  {
    *v25 = "Et";
    v26 = __rdtsc();
    v27 = (signed __int64)(v25 + 2);
    *(_DWORD *)(v27 - 8) = v26;
    v24[1] = v27;
  }
}

// File Line: 159
// RVA: 0xD1A5E0
void __fastcall hkpBoxBoxAgent::getClosestPoints(hkpBoxBoxAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpBoxBoxAgent::staticGetClosestPoints(bodyA, bodyB, input, collector);
}

// File Line: 167
// RVA: 0xD1A830
void __fastcall hkpBoxBoxAgent::staticGetPenetrations(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpCdBody *v4; // rsi
  hkpCdBodyPairCollector *v5; // rbx
  hkpCollisionInput *v6; // r14
  hkpCdBody *v7; // rdi
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 *v12; // rcx
  __m128 *v13; // rax
  hkTransformf *v14; // r8
  hkTransformf *v15; // rdx
  __m128 v16; // xmm6
  __m128i v17; // xmm7
  __m128i v18; // xmm8
  hkVector4f v19; // xmm4
  hkVector4f v20; // xmm2
  hkVector4f v21; // xmm3
  __m128 v22; // xmm6
  hkpContactMgr *v23; // rax
  hkVector4f v24; // xmm5
  __m128 v25; // xmm1
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  _QWORD *v29; // r8
  _QWORD *v30; // rcx
  unsigned __int64 v31; // rax
  signed __int64 v32; // rcx
  hkTransformf v33; // [rsp+20h] [rbp-C8h]
  hkpBoxBoxCollisionDetection v34; // [rsp+60h] [rbp-88h]
  hkResult result; // [rsp+1E8h] [rbp+100h]

  v4 = bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtBoxBox";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = (__m128 *)v7->m_shape;
  v13 = (__m128 *)v4->m_shape;
  v14 = (hkTransformf *)v7->m_motion;
  v15 = (hkTransformf *)v4->m_motion;
  result.m_enum = LODWORD(v6->m_tolerance.m_storage);
  v16 = (__m128)(unsigned int)result.m_enum;
  v17 = (__m128i)_mm_add_ps(_mm_shuffle_ps((__m128)v12[2].m128_u32[0], (__m128)v12[2].m128_u32[0], 0), v12[3]);
  v18 = (__m128i)_mm_add_ps(_mm_shuffle_ps((__m128)v13[2].m128_u32[0], (__m128)v13[2].m128_u32[0], 0), v13[3]);
  hkTransformf::setMulInverseMul(&v33, v15, v14);
  v19.m_quad = (__m128)v33.m_translation;
  v20.m_quad = (__m128)v33.m_rotation.m_col1;
  v21.m_quad = (__m128)v33.m_rotation.m_col2;
  v22 = _mm_shuffle_ps(v16, v16, 0);
  v34.m_env = (hkpProcessCollisionInput *)v4->m_motion;
  v23 = (hkpContactMgr *)v7->m_motion;
  v24.m_quad = (__m128)v33.m_rotation.m_col0;
  _mm_store_si128((__m128i *)&v34.m_env, (__m128i)0i64);
  *(hkVector4f *)(&v34.m_wTb + 1) = (hkVector4f)v20.m_quad;
  result.m_enum = LODWORD(FLOAT_0_0099999998);
  v34.m_bodyA = v4;
  *(__m128 *)((char *)&v34.m_keepRadiusA.m_quad + 8) = _mm_shuffle_ps(
                                                         (__m128)LODWORD(FLOAT_0_0099999998),
                                                         (__m128)LODWORD(FLOAT_0_0099999998),
                                                         0);
  v34.m_bodyB = 0i64;
  v34.m_contactMgr = v23;
  v25 = _mm_unpacklo_ps(v24.m_quad, v20.m_quad);
  *(hkVector4f *)&v34.m_wTa = (hkVector4f)v24.m_quad;
  *(hkVector4f *)((char *)&v34.m_aTb.m_rotation.m_col1 + 8) = (hkVector4f)v19.m_quad;
  *(hkVector4f *)((char *)&v34.m_keepRadiusB + 8) = (hkVector4f)v19.m_quad;
  v26 = _mm_shuffle_ps(v22, _mm_unpackhi_ps(v22, (__m128)xmmword_141A712A0), 196);
  v27 = _mm_unpackhi_ps(v24.m_quad, v20.m_quad);
  v28 = _mm_movelh_ps(v25, v21.m_quad);
  *(__m128 *)((char *)&v34.m_radiusB.m_quad + 8) = _mm_add_ps(v26, (__m128)v18);
  *(__m128 *)((char *)&v34.m_radiusA.m_quad + 8) = v26;
  *(hkVector4f *)((char *)&v34.m_aTb.m_rotation.m_col0 + 8) = (hkVector4f)v21.m_quad;
  _mm_store_si128((__m128i *)&v34.m_aTb.m_rotation.m_col2.m_quad.m128_u16[4], v18);
  _mm_store_si128((__m128i *)&v34.m_aTb.m_translation.m_quad.m128_u16[4], v17);
  *(__m128 *)((char *)&v34.m_tolerance4.m_quad + 8) = _mm_add_ps(v26, (__m128)v17);
  *(__m128 *)((char *)&v34.m_boundaryTolerance.m_real + 8) = _mm_add_ps(
                                                               _mm_add_ps(
                                                                 _mm_mul_ps(
                                                                   _mm_shuffle_ps(v19.m_quad, v19.m_quad, 85),
                                                                   _mm_shuffle_ps(
                                                                     _mm_movehl_ps(v28, v25),
                                                                     v21.m_quad,
                                                                     212)),
                                                                 _mm_mul_ps(
                                                                   _mm_shuffle_ps(v19.m_quad, v19.m_quad, 0),
                                                                   v28)),
                                                               _mm_mul_ps(
                                                                 _mm_shuffle_ps(v27, v21.m_quad, 228),
                                                                 _mm_shuffle_ps(v19.m_quad, v19.m_quad, 170)));
  if ( hkpBoxBoxCollisionDetection::checkIntersection(&v34, &result, (hkVector4f *)((char *)&v34.m_radiusA + 8))->m_enum == HK_SUCCESS )
    v5->vfptr->addCdBodyPair(v5, v4, v7);
  v29 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v30 = (_QWORD *)v29[1];
  if ( (unsigned __int64)v30 < v29[3] )
  {
    *v30 = "Et";
    v31 = __rdtsc();
    v32 = (signed __int64)(v30 + 2);
    *(_DWORD *)(v32 - 8) = v31;
    v29[1] = v32;
  }
}

// File Line: 195
// RVA: 0xD1A810
void __fastcall hkpBoxBoxAgent::getPenetrations(hkpBoxBoxAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpBoxBoxAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}


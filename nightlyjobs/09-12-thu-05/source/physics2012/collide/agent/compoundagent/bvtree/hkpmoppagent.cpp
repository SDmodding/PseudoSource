// File Line: 33
// RVA: 0xD1E5E0
void __fastcall hkpMoppAgent::hkpMoppAgent(hkpMoppAgent *this, hkpContactMgr *mgr)
{
  hkpBvTreeAgent::hkpBvTreeAgent(this, mgr);
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppAgent::`vftable;
}

// File Line: 37
// RVA: 0xD1E260
void __fastcall hkpMoppAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = (hkpCollisionAgent *(__fastcall *)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *))hkpBvTreeAgent::createBvTreeShapeAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticGetClosestPoints;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 1;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, MOPP, ALL_SHAPE_TYPES);
  f.m_createFunc = (hkpCollisionAgent *(__fastcall *)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *))hkpBvTreeAgent::createShapeBvAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpMoppAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, ALL_SHAPE_TYPES, MOPP);
  f.m_createFunc = hkpMoppAgent::createBvBvAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpMoppAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, MOPP, MOPP);
}

// File Line: 74
// RVA: 0xD1E520
void __fastcall hkpMoppAgent::createBvBvAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **v5; // rax
  hkpMoppAgent *v6; // rax
  _QWORD **Value; // rax
  hkpMoppAgent *v8; // rax
  hkpMoppAgent *v9; // rbx

  if ( *(_DWORD *)(*(_QWORD *)&bodyA->m_shape[1].m_memSizeAndFlags + 40i64) >= *(_DWORD *)(*(_QWORD *)&bodyB->m_shape[1].m_memSizeAndFlags
                                                                                         + 40i64) )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkpMoppAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
    v9 = v8;
    if ( v8 )
    {
      hkpMoppAgent::hkpMoppAgent(v8, mgr);
      v9->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpMoppAgent>::`vftable;
    }
  }
  else
  {
    v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (hkpMoppAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v5[11] + 8i64))(v5[11], 80i64);
    if ( v6 )
      hkpMoppAgent::hkpMoppAgent(v6, mgr);
  }
}

// File Line: 120
// RVA: 0xD1E360
void __fastcall hkpMoppAgent::staticLinearCast(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  _QWORD *Value; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  __int64 v13; // r8
  __m128 *m_motion; // rax
  __m128 v15; // xmm7
  __m128 v16; // xmm6
  __m128 v17; // xmm1
  __m128 v18; // xmm8
  __m128 v19; // xmm5
  __m128 v20; // xmm2
  hkVector4f v21; // xmm1
  __m128 v22; // xmm0
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  _QWORD *v26; // rcx
  __m128 v27[2]; // [rsp+20h] [rbp-138h] BYREF
  hkpMoppAabbCastVirtualMachine::hkpAabbCastInput inputa; // [rsp+40h] [rbp-118h] BYREF
  hkTransformf v29; // [rsp+90h] [rbp-C8h] BYREF
  hkpMoppAabbCastVirtualMachine v30; // [rsp+D0h] [rbp-88h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtMopp";
    v11 = __rdtsc();
    v12 = v10 + 2;
    *((_DWORD *)v12 - 2) = v11;
    Value[1] = v12;
  }
  hkTransformf::setMulInverseMul(&v29, (hkTransformf *)bodyB->m_motion, (hkTransformf *)bodyA->m_motion);
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, __m128 *))bodyA->m_shape->vfptr[2].__vecDelDtor)(
    bodyA->m_shape,
    &v29,
    v13,
    v27);
  m_motion = (__m128 *)bodyB->m_motion;
  v15 = m_motion[2];
  v16 = _mm_mul_ps(_mm_sub_ps(v27[1], v27[0]), (__m128)xmmword_141A711B0);
  v17 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
  v18 = _mm_unpackhi_ps(*m_motion, m_motion[1]);
  inputa.m_castBody = bodyA;
  inputa.m_moppBody = bodyB;
  inputa.m_collisionInput = input;
  v19 = _mm_movelh_ps(v17, v15);
  v20 = _mm_movehl_ps(v19, v17);
  v21.m_quad = (__m128)input->m_path;
  inputa.m_from.m_quad = _mm_add_ps(v16, v27[0]);
  v22 = (__m128)_mm_srli_si128(
                  _mm_slli_si128(
                    (__m128i)_mm_shuffle_ps(
                               (__m128)LODWORD(input->m_tolerance.m_storage),
                               (__m128)LODWORD(input->m_tolerance.m_storage),
                               0),
                    4),
                  4);
  inputa.m_to.m_quad = _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v21.m_quad, v21.m_quad, 85), _mm_shuffle_ps(v20, v15, 212)),
                             _mm_mul_ps(_mm_shuffle_ps(v21.m_quad, v21.m_quad, 0), v19)),
                           _mm_mul_ps(_mm_shuffle_ps(v21.m_quad, v21.m_quad, 170), _mm_shuffle_ps(v18, v15, 228))),
                         inputa.m_from.m_quad);
  inputa.m_extents.m_quad = _mm_add_ps(v22, v16);
  hkpMoppAabbCastVirtualMachine::aabbCast(&v30, &inputa, collector, startCollector);
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


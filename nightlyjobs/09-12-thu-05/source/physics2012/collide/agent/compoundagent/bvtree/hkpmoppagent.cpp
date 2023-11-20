// File Line: 33
// RVA: 0xD1E5E0
void __fastcall hkpMoppAgent::hkpMoppAgent(hkpMoppAgent *this, hkpContactMgr *mgr)
{
  hkpMoppAgent *v2; // rbx

  v2 = this;
  hkpBvTreeAgent::hkpBvTreeAgent((hkpBvTreeAgent *)&this->vfptr, mgr);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpMoppAgent::`vftable';
}

// File Line: 37
// RVA: 0xD1E260
void __fastcall hkpMoppAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  f.m_createFunc = (hkpCollisionAgent *(__fastcall *)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *))hkpBvTreeAgent::createBvTreeShapeAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticGetPenetrations;
  v1 = dispatcher;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticGetClosestPoints;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 1;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, MOPP, ALL_SHAPE_TYPES);
  f.m_createFunc = (hkpCollisionAgent *(__fastcall *)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *))hkpBvTreeAgent::createShapeBvAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpMoppAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, ALL_SHAPE_TYPES, MOPP);
  f.m_createFunc = hkpMoppAgent::createBvBvAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpMoppAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, MOPP, MOPP);
}

// File Line: 74
// RVA: 0xD1E520
void __fastcall hkpMoppAgent::createBvBvAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // rdi
  _QWORD **v5; // rax
  hkpMoppAgent *v6; // rax
  _QWORD **v7; // rax
  hkpMoppAgent *v8; // rax
  hkpMoppAgent *v9; // rbx

  v4 = mgr;
  if ( *(_DWORD *)(*(_QWORD *)&bodyA->m_shape[1].m_memSizeAndFlags + 40i64) >= *(_DWORD *)(*(_QWORD *)&bodyB->m_shape[1].m_memSizeAndFlags
                                                                                         + 40i64) )
  {
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkpMoppAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 80i64);
    v9 = v8;
    if ( v8 )
    {
      hkpMoppAgent::hkpMoppAgent(v8, v4);
      v9->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpMoppAgent>::`vftable';
    }
  }
  else
  {
    v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (hkpMoppAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 80i64);
    if ( v6 )
      hkpMoppAgent::hkpMoppAgent(v6, v4);
  }
}

// File Line: 120
// RVA: 0xD1E360
void __fastcall hkpMoppAgent::staticLinearCast(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpCdBody *v5; // rsi
  hkpCdPointCollector *v6; // rbp
  hkpLinearCastCollisionInput *v7; // rbx
  hkpCdBody *v8; // rdi
  _QWORD *v9; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  __int128 v13; // xmm2
  __int64 v14; // r8
  __m128 *v15; // rax
  __m128 v16; // xmm7
  __m128 v17; // xmm6
  __m128 v18; // xmm1
  __m128 v19; // xmm8
  __m128 v20; // xmm5
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  __m128 v24; // xmm3
  __m128 v25; // xmm0
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  signed __int64 v29; // rcx
  __m128 v30; // [rsp+20h] [rbp-138h]
  __m128 v31; // [rsp+30h] [rbp-128h]
  hkpMoppAabbCastVirtualMachine::hkpAabbCastInput inputa; // [rsp+40h] [rbp-118h]
  hkTransformf v33; // [rsp+90h] [rbp-C8h]
  hkpMoppAabbCastVirtualMachine v34; // [rsp+D0h] [rbp-88h]

  v5 = bodyA;
  v6 = collector;
  v7 = input;
  v8 = bodyB;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtMopp";
    v11 = __rdtsc();
    v12 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v9[1] = v12;
  }
  hkTransformf::setMulInverseMul(&v33, (hkTransformf *)v8->m_motion, (hkTransformf *)v5->m_motion);
  v13 = LODWORD(v7->m_tolerance.m_storage);
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, __m128 *))v5->m_shape->vfptr[2].__vecDelDtor)(
    v5->m_shape,
    &v33,
    v14,
    &v30);
  v15 = (__m128 *)v8->m_motion;
  v16 = v15[2];
  v17 = _mm_mul_ps(_mm_sub_ps(v31, v30), (__m128)xmmword_141A711B0);
  v18 = _mm_unpacklo_ps(*v15, v15[1]);
  v19 = _mm_unpackhi_ps(*v15, v15[1]);
  inputa.m_castBody = v5;
  inputa.m_moppBody = v8;
  inputa.m_collisionInput = v7;
  v20 = _mm_movelh_ps(v18, v16);
  v21 = _mm_movehl_ps(v20, v18);
  v22 = v7->m_path.m_quad;
  v23 = v7->m_path.m_quad;
  inputa.m_from.m_quad = _mm_add_ps(v17, v30);
  v24 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v21, v16, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v23, v22, 0), v20)),
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), _mm_shuffle_ps(v19, v16, 228)));
  v25 = (__m128)_mm_srli_si128(
                  _mm_slli_si128(
                    (__m128i)_mm_shuffle_ps(
                               (__m128)LODWORD(v7->m_tolerance.m_storage),
                               (__m128)LODWORD(v7->m_tolerance.m_storage),
                               0),
                    4),
                  4);
  inputa.m_to.m_quad = _mm_add_ps(v24, inputa.m_from.m_quad);
  inputa.m_extents.m_quad = _mm_add_ps(v25, v17);
  hkpMoppAabbCastVirtualMachine::aabbCast(&v34, &inputa, v6, startCollector);
  v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v27 = (_QWORD *)v26[1];
  if ( (unsigned __int64)v27 < v26[3] )
  {
    *v27 = "Et";
    v28 = __rdtsc();
    v29 = (signed __int64)(v27 + 2);
    *(_DWORD *)(v29 - 8) = v28;
    v26[1] = v29;
  }
}


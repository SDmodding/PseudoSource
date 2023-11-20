// File Line: 32
// RVA: 0xD1EA60
void __fastcall hkpBvCompressedMeshAgent::hkpBvCompressedMeshAgent(hkpBvCompressedMeshAgent *this, hkpContactMgr *mgr)
{
  hkpBvCompressedMeshAgent *v2; // rbx

  v2 = this;
  hkpBvTreeAgent::hkpBvTreeAgent((hkpBvTreeAgent *)&this->vfptr, mgr);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpBvCompressedMeshAgent::`vftable';
}

// File Line: 39
// RVA: 0xD1E660
void __fastcall hkpBvCompressedMeshAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  f.m_createFunc = hkpBvCompressedMeshAgent::createStaticMeshVsShapeAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticGetPenetrations;
  v1 = dispatcher;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticGetClosestPoints;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, BV_COMPRESSED_MESH, ALL_SHAPE_TYPES);
  f.m_createFunc = hkpBvCompressedMeshAgent::createShapeVsStaticMeshAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpBvCompressedMeshAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, ALL_SHAPE_TYPES, BV_COMPRESSED_MESH);
  f.m_createFunc = hkpBvCompressedMeshAgent::createStaticMeshVsStaticMeshAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpBvCompressedMeshAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, BV_COMPRESSED_MESH, BV_COMPRESSED_MESH);
}

// File Line: 82
// RVA: 0xD1E760
void __fastcall hkpBvCompressedMeshAgent::createShapeVsStaticMeshAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // rbx
  _QWORD **v5; // rax
  hkpBvCompressedMeshAgent *v6; // rax

  v4 = mgr;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkpBvCompressedMeshAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 80i64);
  if ( v6 )
    hkpBvCompressedMeshAgent::hkpBvCompressedMeshAgent(v6, v4);
}

// File Line: 87
// RVA: 0xD1E7B0
void __fastcall hkpBvCompressedMeshAgent::createStaticMeshVsShapeAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // rbx
  _QWORD **v5; // rax
  hkpBvCompressedMeshAgent *v6; // rax

  v4 = mgr;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkpBvCompressedMeshAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 80i64);
  if ( v6 )
    hkpBvCompressedMeshAgent::hkpBvCompressedMeshAgent(v6, v4);
}

// File Line: 95
// RVA: 0xD1E800
void __fastcall hkpBvCompressedMeshAgent::createStaticMeshVsStaticMeshAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpShape *v4; // rdi
  hkpContactMgr *v5; // rsi
  signed int v6; // ebx
  _QWORD **v7; // rax
  hkpBvCompressedMeshAgent *v8; // rax
  _QWORD **v9; // rax
  hkpBvCompressedMeshAgent *v10; // rax
  hkpBvCompressedMeshAgent *v11; // rbx

  v4 = bodyB->m_shape;
  v5 = mgr;
  v6 = (*(__int64 (__fastcall **)(unsigned __int16 *, hkpCdBody *, hkpCollisionInput *))(*(_QWORD *)&bodyA->m_shape[1].m_memSizeAndFlags
                                                                                       + 8i64))(
         &bodyA->m_shape[1].m_memSizeAndFlags,
         bodyB,
         input);
  if ( v6 >= (*(signed int (__fastcall **)(unsigned __int16 *))(*(_QWORD *)&v4[1].m_memSizeAndFlags + 8i64))(&v4[1].m_memSizeAndFlags) )
  {
    v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (hkpBvCompressedMeshAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(
                                        v9[11],
                                        80i64);
    v11 = v10;
    if ( v10 )
    {
      hkpBvCompressedMeshAgent::hkpBvCompressedMeshAgent(v10, v5);
      v11->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpBvCompressedMeshAgent>::`vftable';
    }
  }
  else
  {
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkpBvCompressedMeshAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(
                                       v7[11],
                                       80i64);
    if ( v8 )
      hkpBvCompressedMeshAgent::hkpBvCompressedMeshAgent(v8, v5);
  }
}

// File Line: 138
// RVA: 0xD1E8E0
void __fastcall hkpBvCompressedMeshAgent::linearCast(hkpBvCompressedMeshAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpBvCompressedMeshAgent::staticLinearCast(bodyA, bodyB, input, collector, startCollector);
}

// File Line: 145
// RVA: 0xD1E920
void __fastcall hkpBvCompressedMeshAgent::staticLinearCast(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *castCollector, hkpCdPointCollector *startCollector)
{
  __m128 *v5; // rbx
  hkpLinearCastCollisionInput *v6; // rbp
  hkpCdBody *v7; // rdi
  hkpCdBody *v8; // rsi
  hkpCdPointCollector *v9; // r14
  __int128 v10; // xmm2
  __int64 v11; // r8
  hkpShape *v12; // rcx
  __m128 v13; // xmm4
  __m128 v14; // xmm1
  __m128 v15; // xmm5
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // [rsp+20h] [rbp-C8h]
  __m128 v20; // [rsp+30h] [rbp-B8h]
  __m128 v21; // [rsp+40h] [rbp-A8h]
  void **v22; // [rsp+50h] [rbp-98h]
  __m128 v23; // [rsp+60h] [rbp-88h]
  hkpCdBody *v24; // [rsp+70h] [rbp-78h]
  hkpCdBody *v25; // [rsp+78h] [rbp-70h]
  hkpLinearCastCollisionInput *v26; // [rsp+80h] [rbp-68h]
  hkpCdPointCollector *v27; // [rsp+88h] [rbp-60h]
  hkpCdPointCollector *v28; // [rsp+90h] [rbp-58h]
  hkTransformf v29; // [rsp+A0h] [rbp-48h]

  v5 = (__m128 *)bodyB->m_motion;
  v6 = input;
  v7 = bodyA;
  v8 = bodyB;
  v9 = castCollector;
  hkTransformf::setMulInverseMul(&v29, (hkTransformf *)bodyB->m_motion, (hkTransformf *)bodyA->m_motion);
  v10 = LODWORD(v6->m_tolerance.m_storage);
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, __m128 *))v7->m_shape->vfptr[2].__vecDelDtor)(
    v7->m_shape,
    &v29,
    v11,
    &v19);
  v12 = v8->m_shape;
  v13 = v5[2];
  v14 = _mm_unpacklo_ps(*v5, v5[1]);
  v15 = _mm_shuffle_ps(_mm_unpackhi_ps(*v5, v5[1]), v13, 228);
  v22 = &hkpBvTreeAgent::LinearCastAabbCastCollector::`vftable';
  v24 = v7;
  v16 = _mm_movelh_ps(v14, v13);
  v17 = _mm_movehl_ps(v16, v14);
  v18 = v6->m_path.m_quad;
  v25 = v8;
  v26 = v6;
  v27 = v9;
  v28 = startCollector;
  v23 = query.m_quad;
  v21 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v16),
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v17, v13, 212))),
            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v15)),
          _mm_mul_ps(_mm_add_ps(v20, v19), (__m128)xmmword_141A711B0));
  ((void (__fastcall *)(hkpShape *, __m128 *, __m128 *, void ***))v12->vfptr[9].__vecDelDtor)(v12, &v19, &v21, &v22);
}


// File Line: 32
// RVA: 0xD1EA60
void __fastcall hkpBvCompressedMeshAgent::hkpBvCompressedMeshAgent(hkpBvCompressedMeshAgent *this, hkpContactMgr *mgr)
{
  hkpBvTreeAgent::hkpBvTreeAgent(this, mgr);
  this->vfptr = (hkBaseObjectVtbl *)&hkpBvCompressedMeshAgent::`vftable;
}

// File Line: 39
// RVA: 0xD1E660
void __fastcall hkpBvCompressedMeshAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpBvCompressedMeshAgent::createStaticMeshVsShapeAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticGetClosestPoints;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, BV_COMPRESSED_MESH, ALL_SHAPE_TYPES);
  f.m_createFunc = hkpBvCompressedMeshAgent::createShapeVsStaticMeshAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpBvCompressedMeshAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, ALL_SHAPE_TYPES, BV_COMPRESSED_MESH);
  f.m_createFunc = hkpBvCompressedMeshAgent::createStaticMeshVsStaticMeshAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpBvCompressedMeshAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, BV_COMPRESSED_MESH, BV_COMPRESSED_MESH);
}

// File Line: 82
// RVA: 0xD1E760
void __fastcall hkpBvCompressedMeshAgent::createShapeVsStaticMeshAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpBvCompressedMeshAgent *v6; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkpBvCompressedMeshAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  if ( v6 )
    hkpBvCompressedMeshAgent::hkpBvCompressedMeshAgent(v6, mgr);
}

// File Line: 87
// RVA: 0xD1E7B0
void __fastcall hkpBvCompressedMeshAgent::createStaticMeshVsShapeAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpBvCompressedMeshAgent *v6; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkpBvCompressedMeshAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  if ( v6 )
    hkpBvCompressedMeshAgent::hkpBvCompressedMeshAgent(v6, mgr);
}

// File Line: 95
// RVA: 0xD1E800
void __fastcall hkpBvCompressedMeshAgent::createStaticMeshVsStaticMeshAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  hkpShape *m_shape; // rdi
  int v6; // ebx
  _QWORD **v7; // rax
  hkpBvCompressedMeshAgent *v8; // rax
  _QWORD **Value; // rax
  hkpBvCompressedMeshAgent *v10; // rax
  hkpBvCompressedMeshAgent *v11; // rbx

  m_shape = bodyB->m_shape;
  v6 = (*(__int64 (__fastcall **)(unsigned __int16 *, hkpCdBody *, hkpCollisionInput *))(*(_QWORD *)&bodyA->m_shape[1].m_memSizeAndFlags
                                                                                       + 8i64))(
         &bodyA->m_shape[1].m_memSizeAndFlags,
         bodyB,
         input);
  if ( v6 >= (*(int (__fastcall **)(unsigned __int16 *))(*(_QWORD *)&m_shape[1].m_memSizeAndFlags + 8i64))(&m_shape[1].m_memSizeAndFlags) )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (hkpBvCompressedMeshAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                        Value[11],
                                        80i64);
    v11 = v10;
    if ( v10 )
    {
      hkpBvCompressedMeshAgent::hkpBvCompressedMeshAgent(v10, mgr);
      v11->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpBvCompressedMeshAgent>::`vftable;
    }
  }
  else
  {
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkpBvCompressedMeshAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v7[11] + 8i64))(v7[11], 80i64);
    if ( v8 )
      hkpBvCompressedMeshAgent::hkpBvCompressedMeshAgent(v8, mgr);
  }
}

// File Line: 138
// RVA: 0xD1E8E0
void __fastcall hkpBvCompressedMeshAgent::linearCast(
        hkpBvCompressedMeshAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  hkpBvCompressedMeshAgent::staticLinearCast(bodyA, bodyB, input, collector, startCollector);
}

// File Line: 145
// RVA: 0xD1E920
void __fastcall hkpBvCompressedMeshAgent::staticLinearCast(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *castCollector,
        hkpCdPointCollector *startCollector)
{
  hkTransformf *m_motion; // rbx
  __int64 v10; // r8
  hkpShape *m_shape; // rcx
  __m128 m_quad; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm5
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  hkVector4f v17; // xmm1
  __m128 v18[2]; // [rsp+20h] [rbp-C8h] BYREF
  __m128 v19; // [rsp+40h] [rbp-A8h] BYREF
  void **v20; // [rsp+50h] [rbp-98h] BYREF
  __m128 v21; // [rsp+60h] [rbp-88h]
  hkpCdBody *v22; // [rsp+70h] [rbp-78h]
  hkpCdBody *v23; // [rsp+78h] [rbp-70h]
  hkpLinearCastCollisionInput *v24; // [rsp+80h] [rbp-68h]
  hkpCdPointCollector *v25; // [rsp+88h] [rbp-60h]
  hkpCdPointCollector *v26; // [rsp+90h] [rbp-58h]
  hkTransformf v27; // [rsp+A0h] [rbp-48h] BYREF

  m_motion = (hkTransformf *)bodyB->m_motion;
  hkTransformf::setMulInverseMul(&v27, m_motion, (hkTransformf *)bodyA->m_motion);
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, __m128 *))bodyA->m_shape->vfptr[2].__vecDelDtor)(
    bodyA->m_shape,
    &v27,
    v10,
    v18);
  m_shape = bodyB->m_shape;
  m_quad = m_motion->m_rotation.m_col2.m_quad;
  v13 = _mm_unpacklo_ps(m_motion->m_rotation.m_col0.m_quad, m_motion->m_rotation.m_col1.m_quad);
  v14 = _mm_shuffle_ps(
          _mm_unpackhi_ps(m_motion->m_rotation.m_col0.m_quad, m_motion->m_rotation.m_col1.m_quad),
          m_quad,
          228);
  v20 = &hkpBvTreeAgent::LinearCastAabbCastCollector::`vftable;
  v22 = bodyA;
  v15 = _mm_movelh_ps(v13, m_quad);
  v16 = _mm_movehl_ps(v15, v13);
  v17.m_quad = (__m128)input->m_path;
  v23 = bodyB;
  v24 = input;
  v25 = castCollector;
  v26 = startCollector;
  v21 = query.m_quad;
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v17.m_quad, v17.m_quad, 0), v15),
              _mm_mul_ps(_mm_shuffle_ps(v17.m_quad, v17.m_quad, 85), _mm_shuffle_ps(v16, m_quad, 212))),
            _mm_mul_ps(_mm_shuffle_ps(v17.m_quad, v17.m_quad, 170), v14)),
          _mm_mul_ps(_mm_add_ps(v18[1], v18[0]), (__m128)xmmword_141A711B0));
  ((void (__fastcall *)(hkpShape *, __m128 *, __m128 *, void ***))m_shape->vfptr[9].__vecDelDtor)(
    m_shape,
    v18,
    &v19,
    &v20);
}


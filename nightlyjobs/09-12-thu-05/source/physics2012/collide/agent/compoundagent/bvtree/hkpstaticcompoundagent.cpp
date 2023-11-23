// File Line: 33
// RVA: 0xD1F090
void __fastcall hkpStaticCompoundAgent::hkpStaticCompoundAgent(hkpStaticCompoundAgent *this, hkpContactMgr *mgr)
{
  hkpBvTreeAgent::hkpBvTreeAgent(this, mgr);
  this->vfptr = (hkBaseObjectVtbl *)&hkpStaticCompoundAgent::`vftable;
}

// File Line: 40
// RVA: 0xD1ED30
void __fastcall hkpStaticCompoundAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpStaticCompoundAgent::createStaticCompoundVsShapeAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticGetClosestPoints;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpStaticCompoundAgent>::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, STATIC_COMPOUND, ALL_SHAPE_TYPES);
  f.m_createFunc = hkpStaticCompoundAgent::createShapeVsStaticCompoundAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpStaticCompoundAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, ALL_SHAPE_TYPES, STATIC_COMPOUND);
  f.m_createFunc = hkpStaticCompoundAgent::createStaticCompoundVsStaticCompoundAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpStaticCompoundAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, STATIC_COMPOUND, STATIC_COMPOUND);
}

// File Line: 83
// RVA: 0xD1EE30
void __fastcall hkpStaticCompoundAgent::createShapeVsStaticCompoundAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpStaticCompoundAgent *v6; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkpStaticCompoundAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  if ( v6 )
    hkpStaticCompoundAgent::hkpStaticCompoundAgent(v6, mgr);
}

// File Line: 88
// RVA: 0xD1EE80
void __fastcall hkpStaticCompoundAgent::createStaticCompoundVsShapeAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpStaticCompoundAgent *v6; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkpStaticCompoundAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  if ( v6 )
    hkpStaticCompoundAgent::hkpStaticCompoundAgent(v6, mgr);
}

// File Line: 93
// RVA: 0xD1EED0
void __fastcall hkpStaticCompoundAgent::createStaticCompoundVsStaticCompoundAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpStaticCompoundAgent *v6; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkpStaticCompoundAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  if ( v6 )
    hkpStaticCompoundAgent::hkpStaticCompoundAgent(v6, mgr);
}

// File Line: 123
// RVA: 0xD1EF20
void __fastcall hkpStaticCompoundAgent::linearCast(
        hkpStaticCompoundAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  hkpStaticCompoundAgent::staticLinearCast(bodyA, bodyB, input, collector, startCollector);
}

// File Line: 130
// RVA: 0xD1EF60
void __fastcall hkpStaticCompoundAgent::staticLinearCast(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  __m128 *m_motion; // rbx
  hkpShape *m_shape; // rdx
  hkpStaticCompoundShape *v11; // rcx
  __m128 v12; // xmm1
  float tolerance; // xmm0_4
  hkVector4f to; // [rsp+30h] [rbp-E8h] BYREF
  hkpAabbCastCollector v15; // [rsp+40h] [rbp-D8h] BYREF
  hkpCdBody *v16; // [rsp+60h] [rbp-B8h]
  hkpCdBody *v17; // [rsp+68h] [rbp-B0h]
  hkpLinearCastCollisionInput *v18; // [rsp+70h] [rbp-A8h]
  hkpCdPointCollector *v19; // [rsp+78h] [rbp-A0h]
  hkpCdPointCollector *v20; // [rsp+80h] [rbp-98h]
  hkTransformf aTb; // [rsp+90h] [rbp-88h] BYREF
  hkTransformf AtoB; // [rsp+D0h] [rbp-48h] BYREF

  m_motion = (__m128 *)bodyA->m_motion;
  hkTransformf::setInverse(&aTb, (hkTransformf *)bodyB->m_motion);
  hkTransformf::setMul(&AtoB, &aTb, (hkTransformf *)bodyA->m_motion);
  m_shape = bodyA->m_shape;
  v11 = (hkpStaticCompoundShape *)bodyB->m_shape;
  v12 = _mm_add_ps(m_motion[3], input->m_path.m_quad);
  v15.vfptr = (hkpAabbCastCollectorVtbl *)&hkpBvTreeAgent::LinearCastAabbCastCollector::`vftable;
  v16 = bodyA;
  v20 = startCollector;
  v17 = bodyB;
  v15.m_earlyOutFraction = (hkSimdFloat32)query.m_quad;
  tolerance = input->m_tolerance.m_storage;
  v18 = input;
  v19 = collector;
  to.m_quad = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), aTb.m_rotation.m_col1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), aTb.m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), aTb.m_rotation.m_col2.m_quad)),
                aTb.m_translation.m_quad);
  hkpStaticCompoundShape::castAabb(v11, m_shape, &AtoB, &to, &v15, tolerance);
}


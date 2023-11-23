// File Line: 35
// RVA: 0xD263C0
void __fastcall hkpListAgent::initAgentFunc(hkpCollisionDispatcher::AgentFuncs *af)
{
  af->m_createFunc = hkpListAgent::createListAAgent;
  af->m_getPenetrationsFunc = hkpShapeCollectionAgent::staticGetPenetrations;
  af->m_getClosestPointFunc = hkpShapeCollectionAgent::staticGetClosestPoints;
  af->m_linearCastFunc = hkpShapeCollectionAgent::staticLinearCast;
  *(_WORD *)&af->m_isFlipped.m_bool = 257;
}

// File Line: 49
// RVA: 0xD26400
void __fastcall hkpListAgent::initAgentFuncInverse(hkpCollisionDispatcher::AgentFuncs *af)
{
  af->m_createFunc = hkpListAgent::createListBAgent;
  af->m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetPenetrations;
  af->m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetClosestPoints;
  af->m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticLinearCast;
  *(_WORD *)&af->m_isFlipped.m_bool = 256;
}

// File Line: 81
// RVA: 0xD26440
void __fastcall hkpListAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpListAgent::initAgentFunc(&f);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, LIST, ALL_SHAPE_TYPES);
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpListAgent::initAgentFuncInverse(&f);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, ALL_SHAPE_TYPES, LIST);
}

// File Line: 100
// RVA: 0xD26890
hkpListAgent *__fastcall hkpListAgent::createListAAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *contactMgr)
{
  _QWORD **Value; // rax
  hkpListAgent *result; // rax
  hkpListAgent *v10; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpListAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  v10 = result;
  if ( result )
  {
    hkpListAgent::hkpListAgent(result, bodyB, bodyA, input, contactMgr);
    v10->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpListAgent>::`vftable;
    return v10;
  }
  return result;
}

// File Line: 107
// RVA: 0xD26920
void __fastcall hkpListAgent::createListBAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *contactMgr)
{
  _QWORD **Value; // rax
  hkpListAgent *v9; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpListAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  if ( v9 )
    hkpListAgent::hkpListAgent(v9, bodyA, bodyB, input, contactMgr);
}

// File Line: 116
// RVA: 0xD26830
void __fastcall hkpListAgent::hkpListAgent(
        hkpListAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *contactMgr)
{
  hkpAgent1nTrack *p_m_agentTrack; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_contactMgr = contactMgr;
  p_m_agentTrack = &this->m_agentTrack;
  p_m_agentTrack[-2].m_sectors.m_data = (hkpAgent1nSector **)&hkpListAgent::`vftable;
  p_m_agentTrack->m_sectors.m_capacityAndFlags = 0x80000000;
  p_m_agentTrack->m_sectors.m_data = 0i64;
  p_m_agentTrack->m_sectors.m_size = 0;
  this->m_dispatcher = input->m_dispatcher.m_storage;
  hkAgent1nMachine_Create(p_m_agentTrack);
}

// File Line: 123
// RVA: 0xD267F0
void __fastcall hkpListAgent::cleanup(hkpListAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkAgent1nMachine_Destroy(&this->m_agentTrack, this->m_dispatcher, this->m_contactMgr, constraintOwner);
  this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 129
// RVA: 0xD267D0
void __fastcall hkpListAgent::invalidateTim(hkpListAgent *this, hkpCollisionInput *input)
{
  hkAgent1nMachine_InvalidateTim(&this->m_agentTrack, input);
}

// File Line: 134
// RVA: 0xD267E0
void __fastcall hkpListAgent::warpTime(hkpListAgent *this, float oldTime, float newTime, hkpCollisionInput *input)
{
  hkAgent1nMachine_WarpTime(&this->m_agentTrack, oldTime, newTime, input);
}

// File Line: 141
// RVA: 0xD264B0
void __fastcall hkpListAgent::processCollision(
        hkpListAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *output)
{
  hkpContactMgr *m_contactMgr; // rax
  float m_storage; // xmm0_4
  hkpShape *m_shape; // rbp
  hkTransformf *m_motion; // rdx
  __m128 v9; // xmm0
  hkTransformf *v10; // r8
  int v11; // ebx
  __m128 m_quad; // xmm1
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  __m128 v16; // xmm4
  int m_userData; // esi
  hkLifoAllocator *Value; // rax
  unsigned int *m_cur; // rdi
  int v20; // edx
  char *v21; // rcx
  unsigned int v22; // edx
  int v23; // r8d
  unsigned int *v24; // r9
  signed int v25; // ebx
  hkLifoAllocator *v26; // rax
  int v27; // r8d
  hkpAgent3ProcessInput inputIn; // [rsp+30h] [rbp-B8h] BYREF

  m_contactMgr = this->m_contactMgr;
  m_storage = input->m_stepInfo.m_deltaTime.m_storage;
  m_shape = bodyB->m_shape;
  inputIn.m_bodyA.m_storage = bodyA;
  m_motion = (hkTransformf *)bodyA->m_motion;
  inputIn.m_bodyB.m_storage = bodyB;
  v9 = _mm_shuffle_ps((__m128)LODWORD(m_storage), (__m128)LODWORD(m_storage), 0);
  v10 = (hkTransformf *)bodyB->m_motion;
  inputIn.m_contactMgr.m_storage = m_contactMgr;
  inputIn.m_input.m_storage = input;
  v11 = 0;
  inputIn.m_overrideBodyA.m_storage = 0i64;
  m_quad = m_motion[1].m_rotation.m_col1.m_quad;
  v14 = v10[1].m_rotation.m_col1.m_quad;
  v15 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), v9);
  v16 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 255), v9);
  inputIn.m_linearTimInfo.m_quad = _mm_add_ps(
                                     _mm_mul_ps(_mm_sub_ps(v14, v10[1].m_rotation.m_col0.m_quad), v15),
                                     _mm_mul_ps(_mm_sub_ps(m_motion[1].m_rotation.m_col0.m_quad, m_quad), v16));
  inputIn.m_linearTimInfo.m_quad = _mm_shuffle_ps(
                                     inputIn.m_linearTimInfo.m_quad,
                                     _mm_unpackhi_ps(
                                       inputIn.m_linearTimInfo.m_quad,
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_mul_ps(
                                             _mm_shuffle_ps(
                                               m_motion[2].m_rotation.m_col1.m_quad,
                                               m_motion[2].m_rotation.m_col1.m_quad,
                                               255),
                                             v16),
                                           _mm_shuffle_ps(
                                             (__m128)m_motion[2].m_rotation.m_col2.m_quad.m128_u32[0],
                                             (__m128)m_motion[2].m_rotation.m_col2.m_quad.m128_u32[0],
                                             0)),
                                         _mm_mul_ps(
                                           _mm_mul_ps(
                                             _mm_shuffle_ps(
                                               v10[2].m_rotation.m_col1.m_quad,
                                               v10[2].m_rotation.m_col1.m_quad,
                                               255),
                                             v15),
                                           _mm_shuffle_ps(
                                             (__m128)v10[2].m_rotation.m_col2.m_quad.m128_u32[0],
                                             (__m128)v10[2].m_rotation.m_col2.m_quad.m128_u32[0],
                                             0)))),
                                     196);
  hkTransformf::setMulInverseMul(&inputIn.m_aTb, m_motion, v10);
  m_userData = m_shape[1].m_userData;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (unsigned int *)Value->m_cur;
  v20 = (4 * m_userData + 131) & 0xFFFFFF80;
  v21 = (char *)m_cur + v20;
  if ( v20 > Value->m_slabSize || v21 > Value->m_end )
    m_cur = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(Value, v20);
  else
    Value->m_cur = v21;
  v22 = 0;
  v23 = 1;
  if ( m_userData > 0 )
  {
    v24 = m_cur;
    do
    {
      if ( v22 >= 0x100 || (v23 & *((_DWORD *)&m_shape[3].m_type.m_storage + ((unsigned __int64)v22 >> 5))) != 0 )
      {
        *v24 = v22;
        ++v11;
        ++v24;
      }
      v23 = __ROL4__(v23, 1);
      ++v22;
    }
    while ( (int)v22 < m_userData );
  }
  m_cur[v11] = -1;
  hkAgent1nMachine_Process(&this->m_agentTrack, &inputIn, (hkpShapeContainer *)&m_shape[1], m_cur, output);
  v25 = (4 * m_userData + 131) & 0xFFFFFF80;
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (v25 + 15) & 0xFFFFFFF0;
  if ( v25 > v26->m_slabSize || (char *)m_cur + v27 != v26->m_cur || v26->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v26, (char *)m_cur, v27);
  else
    v26->m_cur = m_cur;
}

// File Line: 194
// RVA: 0xD26730
// attributes: thunk
void __fastcall hkpListAgent::staticGetClosestPoints(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetClosestPoints(bodyA, bodyB, input, collector);
}

// File Line: 289
// RVA: 0xD26700
// attributes: thunk
void __fastcall hkpListAgent::staticLinearCast(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticLinearCast(bodyA, bodyB, input, collector, startCollector);
}

// File Line: 380
// RVA: 0xD26710
void __fastcall hkpListAgent::getClosestPoints(
        hkpListAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  hkpListAgent::staticGetClosestPoints(bodyA, bodyB, input, collector);
}

// File Line: 385
// RVA: 0xD266C0
void __fastcall hkpListAgent::linearCast(
        hkpListAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  hkpListAgent::staticLinearCast(bodyA, bodyB, input, collector, startCollector);
}

// File Line: 390
// RVA: 0xD26740
void __fastcall hkpListAgent::getPenetrations(
        hkpListAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpListAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}

// File Line: 395
// RVA: 0xD26760
// attributes: thunk
void __fastcall hkpListAgent::staticGetPenetrations(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetPenetrations(bodyA, bodyB, input, collector);
}

// File Line: 402
// RVA: 0xD26770
void __fastcall hkpListAgent::updateShapeCollectionFilter(
        hkpListAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *listShapeBodyB,
        hkpCollisionInput *input,
        hkpConstraintOwner *constraintOwner)
{
  hkpContactMgr *m_contactMgr; // rax
  hkpShape *m_shape; // rcx
  hkpAgent1nMachine_VisitorInput vin; // [rsp+20h] [rbp-48h] BYREF

  m_contactMgr = this->m_contactMgr;
  m_shape = listShapeBodyB->m_shape;
  vin.m_contactMgr = m_contactMgr;
  vin.m_bodyA = bodyA;
  vin.m_collectionBodyB = listShapeBodyB;
  vin.m_input = input;
  vin.m_constraintOwner = constraintOwner;
  vin.m_containerShapeB = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))m_shape->vfptr[7].__vecDelDtor)(m_shape);
  hkAgent1nMachine_UpdateShapeCollectionFilter(&this->m_agentTrack, &vin);
}


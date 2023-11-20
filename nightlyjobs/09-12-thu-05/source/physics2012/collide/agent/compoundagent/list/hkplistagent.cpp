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
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  v1 = dispatcher;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpListAgent::initAgentFunc(&f);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, LIST, ALL_SHAPE_TYPES);
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpListAgent::initAgentFuncInverse(&f);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, ALL_SHAPE_TYPES, LIST);
}

// File Line: 100
// RVA: 0xD26890
hkpListAgent *__fastcall hkpListAgent::createListAAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *contactMgr)
{
  hkpCdBody *v4; // r14
  hkpContactMgr *v5; // rdi
  hkpCollisionInput *v6; // rsi
  hkpCdBody *v7; // rbp
  _QWORD **v8; // rax
  hkpListAgent *result; // rax
  hkpCollisionAgent *v10; // rbx

  v4 = bodyA;
  v5 = contactMgr;
  v6 = input;
  v7 = bodyB;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpListAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 48i64);
  v10 = (hkpCollisionAgent *)&result->vfptr;
  if ( result )
  {
    hkpListAgent::hkpListAgent(result, v7, v4, v6, v5);
    v10->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpListAgent>::`vftable';
    result = (hkpListAgent *)v10;
  }
  return result;
}

// File Line: 107
// RVA: 0xD26920
void __fastcall hkpListAgent::createListBAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *contactMgr)
{
  hkpCdBody *v4; // rbp
  hkpContactMgr *v5; // rbx
  hkpCollisionInput *v6; // rdi
  hkpCdBody *v7; // rsi
  _QWORD **v8; // rax
  hkpListAgent *v9; // rax

  v4 = bodyA;
  v5 = contactMgr;
  v6 = input;
  v7 = bodyB;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpListAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 48i64);
  if ( v9 )
    hkpListAgent::hkpListAgent(v9, v4, v7, v6, v5);
}

// File Line: 116
// RVA: 0xD26830
void __fastcall hkpListAgent::hkpListAgent(hkpListAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *contactMgr)
{
  hkpListAgent *v5; // rbx
  hkpAgent1nTrack *v6; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v5 = this;
  this->m_contactMgr = contactMgr;
  v6 = &this->m_agentTrack;
  v6[-2].m_sectors.m_data = (hkpAgent1nSector **)&hkpListAgent::`vftable';
  v6->m_sectors.m_capacityAndFlags = 2147483648;
  v6->m_sectors.m_data = 0i64;
  v6->m_sectors.m_size = 0;
  v5->m_dispatcher = input->m_dispatcher.m_storage;
  hkAgent1nMachine_Create(v6);
}

// File Line: 123
// RVA: 0xD267F0
void __fastcall hkpListAgent::cleanup(hkpListAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpListAgent *v2; // rbx

  v2 = this;
  hkAgent1nMachine_Destroy(&this->m_agentTrack, v2->m_dispatcher, v2->m_contactMgr, constraintOwner);
  v2->vfptr->__vecDelDtor((hkBaseObject *)&v2->vfptr, 1u);
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
void __fastcall hkpListAgent::processCollision(hkpListAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *output)
{
  hkpContactMgr *v5; // rax
  float v6; // xmm0_4
  hkpShape *v7; // rbp
  hkTransformf *v8; // rdx
  __m128 v9; // xmm0
  hkTransformf *v10; // r8
  int v11; // ebx
  hkpListAgent *v12; // r14
  __m128 v13; // xmm1
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  __m128 v16; // xmm4
  signed int v17; // esi
  hkLifoAllocator *v18; // rax
  unsigned int *v19; // rdi
  int v20; // edx
  char *v21; // rcx
  unsigned int v22; // edx
  signed int v23; // er8
  unsigned int *v24; // r9
  signed int v25; // ebx
  hkLifoAllocator *v26; // rax
  int v27; // er8
  hkpAgent3ProcessInput inputIn; // [rsp+30h] [rbp-B8h]

  v5 = this->m_contactMgr;
  v6 = input->m_stepInfo.m_deltaTime.m_storage;
  v7 = bodyB->m_shape;
  inputIn.m_bodyA.m_storage = bodyA;
  v8 = (hkTransformf *)bodyA->m_motion;
  inputIn.m_bodyB.m_storage = bodyB;
  v9 = _mm_shuffle_ps((__m128)LODWORD(v6), (__m128)LODWORD(v6), 0);
  v10 = (hkTransformf *)bodyB->m_motion;
  inputIn.m_contactMgr.m_storage = v5;
  inputIn.m_input.m_storage = input;
  v11 = 0;
  v12 = this;
  inputIn.m_overrideBodyA.m_storage = 0i64;
  v13 = v8[1].m_rotation.m_col1.m_quad;
  v14 = v10[1].m_rotation.m_col1.m_quad;
  v15 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), v9);
  v16 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 255), v9);
  inputIn.m_linearTimInfo.m_quad = _mm_add_ps(
                                     _mm_mul_ps(_mm_sub_ps(v14, v10[1].m_rotation.m_col0.m_quad), v15),
                                     _mm_mul_ps(_mm_sub_ps(v8[1].m_rotation.m_col0.m_quad, v13), v16));
  inputIn.m_linearTimInfo.m_quad = _mm_shuffle_ps(
                                     inputIn.m_linearTimInfo.m_quad,
                                     _mm_unpackhi_ps(
                                       inputIn.m_linearTimInfo.m_quad,
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_mul_ps(
                                             _mm_shuffle_ps(
                                               v8[2].m_rotation.m_col1.m_quad,
                                               v8[2].m_rotation.m_col1.m_quad,
                                               255),
                                             v16),
                                           _mm_shuffle_ps(
                                             (__m128)v8[2].m_rotation.m_col2.m_quad.m128_u32[0],
                                             (__m128)v8[2].m_rotation.m_col2.m_quad.m128_u32[0],
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
  hkTransformf::setMulInverseMul(&inputIn.m_aTb, v8, v10);
  v17 = v7[1].m_userData;
  v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v19 = (unsigned int *)v18->m_cur;
  v20 = (4 * v17 + 131) & 0xFFFFFF80;
  v21 = (char *)v19 + v20;
  if ( v20 > v18->m_slabSize || v21 > v18->m_end )
    v19 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v18, v20);
  else
    v18->m_cur = v21;
  v22 = 0;
  v23 = 1;
  if ( v17 > 0 )
  {
    v24 = v19;
    do
    {
      if ( v22 >= 0x100 || v23 & *((_DWORD *)&v7[3].m_type.m_storage + ((unsigned __int64)v22 >> 5)) )
      {
        *v24 = v22;
        ++v11;
        ++v24;
      }
      v23 = __ROL4__(v23, 1);
      ++v22;
    }
    while ( (signed int)v22 < v17 );
  }
  v19[v11] = -1;
  hkAgent1nMachine_Process(&v12->m_agentTrack, &inputIn, (hkpShapeContainer *)&v7[1], v19, output);
  v25 = (4 * v17 + 131) & 0xFFFFFF80;
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (v25 + 15) & 0xFFFFFFF0;
  if ( v25 > v26->m_slabSize || (char *)v19 + v27 != v26->m_cur || v26->m_firstNonLifoEnd == v19 )
    hkLifoAllocator::slowBlockFree(v26, v19, v27);
  else
    v26->m_cur = v19;
}

// File Line: 194
// RVA: 0xD26730
void __fastcall hkpListAgent::staticGetClosestPoints(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetClosestPoints(bodyA, bodyB, input, collector);
}

// File Line: 289
// RVA: 0xD26700
void __fastcall hkpListAgent::staticLinearCast(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticLinearCast(bodyA, bodyB, input, collector, startCollector);
}

// File Line: 380
// RVA: 0xD26710
void __fastcall hkpListAgent::getClosestPoints(hkpListAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpListAgent::staticGetClosestPoints(bodyA, bodyB, input, collector);
}

// File Line: 385
// RVA: 0xD266C0
void __fastcall hkpListAgent::linearCast(hkpListAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpListAgent::staticLinearCast(bodyA, bodyB, input, collector, startCollector);
}

// File Line: 390
// RVA: 0xD26740
void __fastcall hkpListAgent::getPenetrations(hkpListAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpListAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}

// File Line: 395
// RVA: 0xD26760
void __fastcall hkpListAgent::staticGetPenetrations(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetPenetrations(bodyA, bodyB, input, collector);
}

// File Line: 402
// RVA: 0xD26770
void __fastcall hkpListAgent::updateShapeCollectionFilter(hkpListAgent *this, hkpCdBody *bodyA, hkpCdBody *listShapeBodyB, hkpCollisionInput *input, hkpConstraintOwner *constraintOwner)
{
  hkpContactMgr *v5; // rax
  hkpListAgent *v6; // rbx
  hkpShape *v7; // rcx
  hkpAgent1nMachine_VisitorInput vin; // [rsp+20h] [rbp-48h]

  v5 = this->m_contactMgr;
  v6 = this;
  v7 = listShapeBodyB->m_shape;
  vin.m_contactMgr = v5;
  vin.m_bodyA = bodyA;
  vin.m_collectionBodyB = listShapeBodyB;
  vin.m_input = input;
  vin.m_constraintOwner = constraintOwner;
  vin.m_containerShapeB = (hkpShapeContainer *)((__int64 (__cdecl *)(hkpShape *, hkpCdBody *))v7->vfptr[7].__vecDelDtor)(
                                                 v7,
                                                 bodyA);
  hkAgent1nMachine_UpdateShapeCollectionFilter(&v6->m_agentTrack, &vin);
}


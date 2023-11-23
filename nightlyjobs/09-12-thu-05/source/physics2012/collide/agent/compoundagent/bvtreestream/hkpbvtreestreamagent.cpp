// File Line: 43
// RVA: 0xD1D930
void __fastcall hkpBvTreeStreamAgent::hkpBvTreeStreamAgent(
        hkpBvTreeStreamAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  hkpAgent1nTrack *p_m_agentTrack; // rcx
  hkpCollisionDispatcher *m_storage; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_contactMgr = mgr;
  p_m_agentTrack = &this->m_agentTrack;
  p_m_agentTrack[-4].m_sectors.m_data = (hkpAgent1nSector **)&hkpBvTreeStreamAgent::`vftable;
  p_m_agentTrack->m_sectors.m_capacityAndFlags = 0x80000000;
  p_m_agentTrack->m_sectors.m_data = 0i64;
  p_m_agentTrack->m_sectors.m_size = 0;
  m_storage = input->m_dispatcher.m_storage;
  this->m_cachedAabb.m_min = 0i64;
  this->m_cachedAabb.m_max = 0i64;
  this->m_dispatcher = m_storage;
  hkAgent1nMachine_Create(p_m_agentTrack);
}

// File Line: 51
// RVA: 0xD1CF10
void __fastcall hkpBvTreeStreamAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpBvTreeStreamAgent::createBvTreeShapeAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpBvTreeAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, BV_TREE, CONVEX);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE, CONVEX);
  f.m_createFunc = hkpBvTreeStreamAgent::createShapeBvAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpBvTreeAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, CONVEX, BV_TREE);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, CONVEX, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE);
}

// File Line: 78
// RVA: 0xD1CFF0
void __fastcall hkpBvTreeStreamAgent::registerConvexListAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpBvTreeStreamAgent::dispatchBvTreeConvexList;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpBvTreeAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, BV_TREE, CONVEX_LIST);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE, CONVEX_LIST);
  f.m_createFunc = hkpBvTreeStreamAgent::dispatchConvexListBvTree;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpBvTreeAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, CONVEX_LIST, BV_TREE);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, CONVEX_LIST, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE);
}

// File Line: 105
// RVA: 0xD1D0D0
void __fastcall hkpBvTreeStreamAgent::registerMultiRayAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpBvTreeStreamAgent::createBvTreeShapeAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpBvTreeAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, BV_TREE, MULTI_RAY);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE, MULTI_RAY);
  f.m_createFunc = hkpBvTreeStreamAgent::createShapeBvAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpBvTreeAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, MULTI_RAY, BV_TREE);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, MULTI_RAY, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE);
}

// File Line: 133
// RVA: 0xD1DAA0
hkpBvTreeStreamAgent *__fastcall hkpBvTreeStreamAgent::dispatchBvTreeConvexList(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  int v8; // eax
  int v9; // eax
  _QWORD **v11; // rax
  hkpShapeCollectionAgent *v12; // rax
  hkpShapeCollectionAgent *v13; // rdi
  _QWORD **v14; // rax
  hkpBvTreeStreamAgent *v15; // rax
  hkpBvTreeStreamAgent *v16; // rdi
  _QWORD **Value; // rax
  hkpBvTreeStreamAgent *v18; // rax

  if ( !mgr )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (hkpBvTreeStreamAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
    v16 = v18;
    if ( !v18 )
      return 0i64;
    hkpBvTreeStreamAgent::hkpBvTreeStreamAgent(v18, bodyB, bodyA, input, 0i64);
LABEL_12:
    v16->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpBvTreeStreamAgent>::`vftable;
    return v16;
  }
  v8 = ((__int64 (__fastcall *)(hkpConvexListFilter *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))input->m_convexListFilter.m_storage->vfptr[1].__first_virtual_table_function__)(
         input->m_convexListFilter.m_storage,
         bodyB,
         bodyA,
         input);
  if ( !v8 )
  {
LABEL_8:
    v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (hkpBvTreeStreamAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v14[11] + 8i64))(v14[11], 80i64);
    v16 = v15;
    if ( !v15 )
      return 0i64;
    hkpBvTreeStreamAgent::hkpBvTreeStreamAgent(v15, bodyB, bodyA, input, mgr);
    goto LABEL_12;
  }
  v9 = v8 - 1;
  if ( v9 )
  {
    if ( v9 != 1 )
      return 0i64;
    goto LABEL_8;
  }
  v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v11[11] + 8i64))(v11[11], 104i64);
  v13 = v12;
  if ( !v12 )
    return 0i64;
  hkpShapeCollectionAgent::hkpShapeCollectionAgent(v12, bodyB, bodyA, input, mgr);
  v13->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpShapeCollectionAgent>::`vftable;
  return (hkpBvTreeStreamAgent *)v13;
}

// File Line: 172
// RVA: 0xD1DBE0
void __fastcall hkpBvTreeStreamAgent::dispatchConvexListBvTree(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  int v8; // eax
  int v9; // eax
  _QWORD **v10; // rax
  hkpShapeCollectionAgent *v11; // rax
  _QWORD **Value; // rax
  hkpBvTreeStreamAgent *v13; // rax
  _QWORD **v14; // rax
  hkpBvTreeStreamAgent *v15; // rax
  hkpBvTreeStreamAgent *v16; // rdi

  if ( mgr )
  {
    v8 = ((__int64 (__fastcall *)(hkpConvexListFilter *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))input->m_convexListFilter.m_storage->vfptr[1].__first_virtual_table_function__)(
           input->m_convexListFilter.m_storage,
           bodyA,
           bodyB,
           input);
    if ( !v8 )
    {
LABEL_8:
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v13 = (hkpBvTreeStreamAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
      if ( v13 )
        hkpBvTreeStreamAgent::hkpBvTreeStreamAgent(v13, bodyA, bodyB, input, mgr);
      return;
    }
    v9 = v8 - 1;
    if ( v9 )
    {
      if ( v9 != 1 )
        return;
      goto LABEL_8;
    }
    v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v10[11] + 8i64))(v10[11], 104i64);
    if ( v11 )
      hkpShapeCollectionAgent::hkpShapeCollectionAgent(v11, bodyA, bodyB, input, mgr);
  }
  else
  {
    v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (hkpBvTreeStreamAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v14[11] + 8i64))(v14[11], 80i64);
    v16 = v15;
    if ( v15 )
    {
      hkpBvTreeStreamAgent::hkpBvTreeStreamAgent(v15, bodyB, bodyA, input, 0i64);
      v16->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpBvTreeStreamAgent>::`vftable;
    }
  }
}

// File Line: 212
// RVA: 0xD1DA10
hkpBvTreeStreamAgent *__fastcall hkpBvTreeStreamAgent::createBvTreeShapeAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpBvTreeStreamAgent *result; // rax
  hkpBvTreeStreamAgent *v10; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpBvTreeStreamAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  v10 = result;
  if ( result )
  {
    hkpBvTreeStreamAgent::hkpBvTreeStreamAgent(result, bodyB, bodyA, input, mgr);
    v10->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpBvTreeStreamAgent>::`vftable;
    return v10;
  }
  return result;
}

// File Line: 220
// RVA: 0xD1D990
void __fastcall hkpBvTreeStreamAgent::createShapeBvAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpBvTreeStreamAgent *v9; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpBvTreeStreamAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  if ( v9 )
    hkpBvTreeStreamAgent::hkpBvTreeStreamAgent(v9, bodyA, bodyB, input, mgr);
}

// File Line: 226
// RVA: 0xD1D800
void __fastcall hkpBvTreeStreamAgent::getPenetrations(
        hkpBvTreeStreamAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpBvTreeAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}

// File Line: 232
// RVA: 0xD1D820
void __fastcall hkpBvTreeStreamAgent::getClosestPoints(
        hkpBvTreeStreamAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  hkpBvTreeAgent::staticGetClosestPoints(bodyA, bodyB, input, collector);
}

// File Line: 238
// RVA: 0xD1D840
void __fastcall hkpBvTreeStreamAgent::linearCast(
        hkpBvTreeStreamAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  hkpBvTreeAgent::staticLinearCast(bodyA, bodyB, input, collector, startCollector);
}

// File Line: 246
// RVA: 0xD1D7C0
void __fastcall hkpBvTreeStreamAgent::cleanup(hkpBvTreeStreamAgent *this, hkpConstraintOwner *info)
{
  hkAgent1nMachine_Destroy(&this->m_agentTrack, this->m_dispatcher, this->m_contactMgr, info);
  this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 281
// RVA: 0xD1D1B0
void __fastcall hkpBvTreeStreamAgent::processCollision(
        hkpBvTreeStreamAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *output)
{
  hkpProcessCollisionOutput *v5; // rdi
  _QWORD *Value; // r8
  unsigned __int64 v11; // r10
  unsigned __int64 v12; // rax
  hkTransformf *m_motion; // rdx
  hkTransformf *v14; // r8
  hkpContactMgr *m_contactMgr; // rax
  __m128 v16; // xmm0
  __m128 m_quad; // xmm1
  __m128 v18; // xmm6
  __m128 v19; // xmm5
  __m128 v20; // xmm4
  __int64 v21; // r8
  __m128 *v22; // r15
  __m128 *v23; // r12
  hkAabb *p_m_cachedAabb; // rbx
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  __m128 v28; // xmm8
  hkpShape *m_shape; // rcx
  __m128i v30; // xmm9
  hkBaseObjectVtbl *vfptr; // rax
  __m128 v32; // xmm7
  __m128 v33; // xmm1
  __m128 v34; // xmm6
  __m128 *v35; // rax
  __m128 v36; // xmm5
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  __m128 v39; // xmm7
  __m128 v40; // xmm2
  __m128 v41; // xmm1
  __m128 v42; // xmm5
  __m128 v43; // xmm6
  __m128 v44; // xmm2
  __m128 v45; // xmm7
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm6
  __m128 v49; // xmm5
  int v50; // ebx
  __m128 v51; // xmm3
  __m128 v52; // xmm2
  __m128 v53; // xmm9
  unsigned __int64 v54; // rdx
  _QWORD *v55; // r8
  _QWORD *v56; // rcx
  unsigned __int64 v57; // rax
  _QWORD *v58; // rcx
  int v59; // ebx
  int m_size; // edi
  hkMemorySystem *Instance; // rax
  hkpShapeContainer *v62; // rax
  unsigned int *v63; // r9
  _QWORD *v64; // r8
  unsigned __int64 v65; // rcx
  unsigned __int64 v66; // rax
  __m128 v67; // [rsp+30h] [rbp-C8h] BYREF
  __m128 v68; // [rsp+40h] [rbp-B8h]
  hkpAgent3ProcessInput inputIn; // [rsp+50h] [rbp-A8h] BYREF
  unsigned int *pArr; // [rsp+118h] [rbp+20h] BYREF
  int v71; // [rsp+120h] [rbp+28h]
  __int64 v72; // [rsp+124h] [rbp+2Ch] BYREF
  void *retaddr; // [rsp+398h] [rbp+2A0h]
  hkpProcessCollisionOutput *v74; // [rsp+3B8h] [rbp+2C0h]

  v74 = v5;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = Value[1];
  if ( v11 < Value[3] )
  {
    *(_QWORD *)v11 = "LtBvTree3";
    *(_QWORD *)(v11 + 16) = "StQueryTree";
    v12 = __rdtsc();
    *(_DWORD *)(v11 + 8) = v12;
    Value[1] = v11 + 24;
  }
  m_motion = (hkTransformf *)bodyA->m_motion;
  v14 = (hkTransformf *)bodyB->m_motion;
  m_contactMgr = this->m_contactMgr;
  *(float *)&retaddr = input->m_stepInfo.m_deltaTime.m_storage;
  inputIn.m_overrideBodyA.m_storage = 0i64;
  inputIn.m_bodyA.m_storage = bodyA;
  inputIn.m_bodyB.m_storage = bodyB;
  v16 = _mm_shuffle_ps((__m128)(unsigned int)retaddr, (__m128)(unsigned int)retaddr, 0);
  inputIn.m_contactMgr.m_storage = m_contactMgr;
  inputIn.m_input.m_storage = input;
  m_quad = m_motion[1].m_rotation.m_col1.m_quad;
  v18 = v14[1].m_rotation.m_col1.m_quad;
  v19 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 255), v16);
  v20 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 255), v16);
  *(__m128 *)(&inputIn.m_distAtT1 + 2) = _mm_add_ps(
                                           _mm_mul_ps(_mm_sub_ps(v18, v14[1].m_rotation.m_col0.m_quad), v19),
                                           _mm_mul_ps(_mm_sub_ps(m_motion[1].m_rotation.m_col0.m_quad, m_quad), v20));
  *(__m128 *)(&inputIn.m_distAtT1 + 2) = _mm_shuffle_ps(
                                           *(__m128 *)(&inputIn.m_distAtT1 + 2),
                                           _mm_unpackhi_ps(
                                             *(__m128 *)(&inputIn.m_distAtT1 + 2),
                                             _mm_add_ps(
                                               _mm_mul_ps(
                                                 _mm_mul_ps(
                                                   _mm_shuffle_ps(
                                                     m_motion[2].m_rotation.m_col1.m_quad,
                                                     m_motion[2].m_rotation.m_col1.m_quad,
                                                     255),
                                                   v20),
                                                 _mm_shuffle_ps(
                                                   (__m128)m_motion[2].m_rotation.m_col2.m_quad.m128_u32[0],
                                                   (__m128)m_motion[2].m_rotation.m_col2.m_quad.m128_u32[0],
                                                   0)),
                                               _mm_mul_ps(
                                                 _mm_mul_ps(
                                                   _mm_shuffle_ps(
                                                     v14[2].m_rotation.m_col1.m_quad,
                                                     v14[2].m_rotation.m_col1.m_quad,
                                                     255),
                                                   v19),
                                                 _mm_shuffle_ps(
                                                   (__m128)v14[2].m_rotation.m_col2.m_quad.m128_u32[0],
                                                   (__m128)v14[2].m_rotation.m_col2.m_quad.m128_u32[0],
                                                   0)))),
                                           196);
  hkTransformf::setMulInverseMul((hkTransformf *)(&inputIn.m_contactMgr + 1), m_motion, v14);
  v72 = -2147483520i64;
  pArr = (unsigned int *)&v72 + 1;
  v71 = 1;
  hkTransformf::setInverse(
    (hkTransformf *)&inputIn.m_linearTimInfo.m_quad.m128_u16[4],
    (hkTransformf *)(&inputIn.m_contactMgr + 1));
  v22 = (__m128 *)bodyB->m_motion;
  v23 = (__m128 *)bodyA->m_motion;
  p_m_cachedAabb = &this->m_cachedAabb;
  v25 = v22[2];
  v26 = _mm_unpacklo_ps(*v22, v22[1]);
  v27 = _mm_movelh_ps(v26, v25);
  v28 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(*(__m128 *)(&inputIn.m_distAtT1 + 2), *(__m128 *)(&inputIn.m_distAtT1 + 2), 85),
              _mm_shuffle_ps(_mm_movehl_ps(v27, v26), v25, 212)),
            _mm_mul_ps(
              _mm_shuffle_ps(*(__m128 *)(&inputIn.m_distAtT1 + 2), *(__m128 *)(&inputIn.m_distAtT1 + 2), 0),
              v27)),
          _mm_mul_ps(
            _mm_shuffle_ps(*(__m128 *)(&inputIn.m_distAtT1 + 2), *(__m128 *)(&inputIn.m_distAtT1 + 2), 170),
            _mm_shuffle_ps(_mm_unpackhi_ps(*v22, v22[1]), v25, 228)));
  m_shape = bodyA->m_shape;
  v30 = (__m128i)_mm_mul_ps(
                   _mm_shuffle_ps(
                     (__m128)LODWORD(input->m_tolerance.m_storage),
                     (__m128)LODWORD(input->m_tolerance.m_storage),
                     0),
                   (__m128)xmmword_141A711B0);
  vfptr = bodyA->m_shape->vfptr;
  if ( input->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage )
  {
    v32 = _mm_shuffle_ps((__m128)v23[10].m128_u32[0], (__m128)v23[10].m128_u32[0], 0);
    v33 = _mm_shuffle_ps(v22[9], v22[9], 255);
    v34 = _mm_mul_ps(_mm_shuffle_ps((__m128)v22[10].m128_u32[0], (__m128)v22[10].m128_u32[0], 0), _mm_mul_ps(v33, v33));
    ((void (__fastcall *)(hkpShape *, unsigned __int16 *, __int64, __m128 *))vfptr[2].__vecDelDtor)(
      m_shape,
      &inputIn.m_linearTimInfo.m_quad.m128_u16[4],
      v21,
      &v67);
    v35 = (__m128 *)bodyB->m_motion;
    v36 = _mm_sub_ps(v23[5], v35[3]);
    v37 = v35[2];
    v38 = _mm_unpacklo_ps(*v35, v35[1]);
    v39 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_add_ps(_mm_add_ps(v32, (__m128)v30), v34), 4), 4);
    v40 = _mm_movelh_ps(v38, v37);
    v41 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(_mm_movehl_ps(v40, v38), v37, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v36, v36, 0), v40)),
            _mm_mul_ps(_mm_shuffle_ps(_mm_unpackhi_ps(*v35, v35[1]), v37, 228), _mm_shuffle_ps(v36, v36, 170)));
    v42 = _mm_max_ps(v67, _mm_sub_ps(v41, v39));
    v67 = v42;
    v43 = _mm_min_ps(v68, _mm_add_ps(v41, v39));
    v68 = v43;
    v44 = v22[9];
    v45 = _mm_sub_ps(v43, v42);
    if ( _mm_shuffle_ps(v44, v44, 255).m128_f32[0] > 0.0 )
    {
      v46 = _mm_sub_ps(v41, v22[8]);
      v47 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v46), _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v44));
      v28 = _mm_add_ps(
              v28,
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
                    (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
                    0),
                  _mm_shuffle_ps(v22[5], v22[5], 255)),
                _mm_shuffle_ps(v47, v47, 201)));
    }
    v48 = _mm_add_ps(v43, _mm_max_ps((__m128)0i64, v28));
    v49 = _mm_add_ps(v42, _mm_min_ps((__m128)0i64, v28));
    v68 = v48;
    v67 = v49;
  }
  else
  {
    ((void (__fastcall *)(hkpShape *, unsigned __int16 *, __int64, __m128 *))vfptr[2].__vecDelDtor)(
      m_shape,
      &inputIn.m_linearTimInfo.m_quad.m128_u16[4],
      v21,
      &v67);
    v48 = v68;
    v49 = v67;
    v45 = _mm_sub_ps(v68, v67);
  }
  if ( this != (hkpBvTreeStreamAgent *)-32i64 )
  {
    if ( (_mm_movemask_ps(
            _mm_and_ps(
              _mm_cmple_ps(p_m_cachedAabb->m_min.m_quad, v49),
              _mm_cmple_ps(v48, this->m_cachedAabb.m_max.m_quad))) & 7) == 7 )
    {
      v50 = 1;
      goto LABEL_13;
    }
    v51 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_40000001), (__m128)LODWORD(FLOAT_0_40000001), 0), v45);
    *(float *)&retaddr = FLOAT_N2_0;
    v52 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_N2_0), (__m128)LODWORD(FLOAT_N2_0), 0);
    v53 = (__m128)_mm_srli_si128(_mm_slli_si128(v30, 4), 4);
    v67 = _mm_add_ps(
            _mm_sub_ps(v49, v53),
            _mm_max_ps(
              _mm_mul_ps(_mm_max_ps((__m128)0i64, v28), v52),
              _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v51)));
    p_m_cachedAabb->m_min.m_quad = v67;
    v68 = _mm_add_ps(_mm_add_ps(v48, v53), _mm_min_ps(_mm_mul_ps(_mm_min_ps((__m128)0i64, v28), v52), v51));
    this->m_cachedAabb.m_max.m_quad = v68;
  }
  ((void (__fastcall *)(hkpShape *, __m128 *, unsigned int **))bodyB->m_shape->vfptr[8].__first_virtual_table_function__)(
    bodyB->m_shape,
    &v67,
    &pArr);
  v50 = 0;
LABEL_13:
  v55 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v56 = (_QWORD *)v55[1];
  if ( (unsigned __int64)v56 < v55[3] )
  {
    *v56 = "StNarrow";
    v57 = __rdtsc();
    v54 = (unsigned __int64)HIDWORD(v57) << 32;
    v58 = v56 + 2;
    *((_DWORD *)v58 - 2) = v57;
    v55[1] = v58;
  }
  if ( v50 )
  {
    v62 = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *, unsigned __int64, _QWORD *))bodyB->m_shape->vfptr[7].__vecDelDtor)(
                                 bodyB->m_shape,
                                 v54,
                                 v55);
    v63 = 0i64;
  }
  else
  {
    v59 = v71;
    m_size = this->m_agentTrack.m_sectors.m_size;
    Instance = hkMemorySystem::getInstance();
    if ( !Instance->vfptr->heapCanAllocTotal(Instance, (v59 / 4 - m_size + 1) << 9) )
    {
      hkSetOutOfMemoryState(MEMORY_STATE_OUT_OF_MEMORY);
      goto LABEL_23;
    }
    if ( v71 > 1 )
      hkAlgorithm::quickSortRecursive<unsigned int,hkAlgorithm::less<unsigned int>>(pArr, 0, v71 - 1, 0);
    v62 = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))bodyB->m_shape->vfptr[7].__vecDelDtor)(bodyB->m_shape);
    v63 = pArr;
  }
  hkAgent1nMachine_Process(&this->m_agentTrack, &inputIn, v62, v63, v74);
LABEL_23:
  v64 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v65 = v64[1];
  if ( v65 < v64[3] )
  {
    *(_QWORD *)v65 = "lt";
    v66 = __rdtsc();
    *(_DWORD *)(v65 + 8) = v66;
    v64[1] = v65 + 16;
  }
  v71 = 0;
  if ( (int)v72 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, pArr, 4 * v72);
} )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, pArr, 4 * v72);
}

// File Line: 349
// RVA: 0xD1D880
void __fastcall hkpBvTreeStreamAgent::updateShapeCollectionFilter(
        hkpBvTreeStreamAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *collectionBodyB,
        hkpCollisionInput *input,
        hkpConstraintOwner *constraintOwner)
{
  hkpShapeContainer *v9; // rax
  hkpAgent1nMachine_VisitorInput vin; // [rsp+20h] [rbp-48h] BYREF

  this->m_cachedAabb.m_min = 0i64;
  this->m_cachedAabb.m_max = 0i64;
  v9 = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))collectionBodyB->m_shape->vfptr[7].__vecDelDtor)(collectionBodyB->m_shape);
  vin.m_contactMgr = this->m_contactMgr;
  vin.m_constraintOwner = constraintOwner;
  vin.m_bodyA = bodyA;
  vin.m_collectionBodyB = collectionBodyB;
  vin.m_input = input;
  vin.m_containerShapeB = v9;
  hkAgent1nMachine_UpdateShapeCollectionFilter(&this->m_agentTrack, &vin);
}

// File Line: 370
// RVA: 0xD1D910
void __fastcall hkpBvTreeStreamAgent::invalidateTim(hkpBvTreeStreamAgent *this, hkpCollisionInput *input)
{
  hkAgent1nMachine_InvalidateTim(&this->m_agentTrack, input);
}

// File Line: 375
// RVA: 0xD1D920
void __fastcall hkpBvTreeStreamAgent::warpTime(
        hkpBvTreeStreamAgent *this,
        float oldTime,
        float newTime,
        hkpCollisionInput *input)
{
  hkAgent1nMachine_WarpTime(&this->m_agentTrack, oldTime, newTime, input);
}


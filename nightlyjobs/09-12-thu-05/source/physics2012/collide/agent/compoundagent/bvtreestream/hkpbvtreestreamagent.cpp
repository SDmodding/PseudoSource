// File Line: 43
// RVA: 0xD1D930
void __fastcall hkpBvTreeStreamAgent::hkpBvTreeStreamAgent(hkpBvTreeStreamAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpBvTreeStreamAgent *v5; // rbx
  hkpAgent1nTrack *v6; // rcx
  hkpCollisionDispatcher *v7; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v5 = this;
  this->m_contactMgr = mgr;
  v6 = &this->m_agentTrack;
  v6[-4].m_sectors.m_data = (hkpAgent1nSector **)&hkpBvTreeStreamAgent::`vftable';
  v6->m_sectors.m_capacityAndFlags = 2147483648;
  v6->m_sectors.m_data = 0i64;
  v6->m_sectors.m_size = 0;
  v7 = input->m_dispatcher.m_storage;
  v5->m_cachedAabb.m_min = 0i64;
  v5->m_cachedAabb.m_max = 0i64;
  v5->m_dispatcher = v7;
  hkAgent1nMachine_Create(v6);
}

// File Line: 51
// RVA: 0xD1CF10
void __fastcall hkpBvTreeStreamAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  f.m_createFunc = hkpBvTreeStreamAgent::createBvTreeShapeAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticGetPenetrations;
  v1 = dispatcher;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpBvTreeAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, BV_TREE, CONVEX);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE, CONVEX);
  f.m_createFunc = hkpBvTreeStreamAgent::createShapeBvAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpBvTreeAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, CONVEX, BV_TREE);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, CONVEX, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE);
}

// File Line: 78
// RVA: 0xD1CFF0
void __fastcall hkpBvTreeStreamAgent::registerConvexListAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  f.m_createFunc = hkpBvTreeStreamAgent::dispatchBvTreeConvexList;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticGetPenetrations;
  v1 = dispatcher;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpBvTreeAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, BV_TREE, CONVEX_LIST);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE, CONVEX_LIST);
  f.m_createFunc = hkpBvTreeStreamAgent::dispatchConvexListBvTree;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpBvTreeAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, CONVEX_LIST, BV_TREE);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, CONVEX_LIST, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE);
}

// File Line: 105
// RVA: 0xD1D0D0
void __fastcall hkpBvTreeStreamAgent::registerMultiRayAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  f.m_createFunc = hkpBvTreeStreamAgent::createBvTreeShapeAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticGetPenetrations;
  v1 = dispatcher;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpBvTreeAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, BV_TREE, MULTI_RAY);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE, MULTI_RAY);
  f.m_createFunc = hkpBvTreeStreamAgent::createShapeBvAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpBvTreeAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, MULTI_RAY, BV_TREE);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, MULTI_RAY, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE);
}

// File Line: 133
// RVA: 0xD1DAA0
hkpBvTreeStreamAgent *__fastcall hkpBvTreeStreamAgent::dispatchBvTreeConvexList(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // r14
  hkpCollisionInput *v5; // rbx
  hkpCdBody *v6; // rsi
  hkpCdBody *v7; // rbp
  int v8; // eax
  int v9; // eax
  _QWORD **v11; // rax
  hkpShapeCollectionAgent *v12; // rax
  hkpShapeCollectionAgent *v13; // rdi
  _QWORD **v14; // rax
  hkpBvTreeStreamAgent *v15; // rax
  hkpBvTreeStreamAgent *v16; // rdi
  _QWORD **v17; // rax
  hkpBvTreeStreamAgent *v18; // rax

  v4 = mgr;
  v5 = input;
  v6 = bodyB;
  v7 = bodyA;
  if ( !mgr )
  {
    v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (hkpBvTreeStreamAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v17[11] + 8i64))(
                                    v17[11],
                                    80i64);
    v16 = v18;
    if ( !v18 )
      return 0i64;
    hkpBvTreeStreamAgent::hkpBvTreeStreamAgent(v18, v6, v7, v5, 0i64);
LABEL_13:
    v16->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpBvTreeStreamAgent>::`vftable';
    return v16;
  }
  v8 = ((__int64 (__fastcall *)(hkpConvexListFilter *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))input->m_convexListFilter.m_storage->vfptr[1].__first_virtual_table_function__)(
         input->m_convexListFilter.m_storage,
         bodyB,
         bodyA,
         input);
  if ( !v8 )
  {
LABEL_9:
    v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (hkpBvTreeStreamAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(
                                    v14[11],
                                    80i64);
    v16 = v15;
    if ( !v15 )
      return 0i64;
    hkpBvTreeStreamAgent::hkpBvTreeStreamAgent(v15, v6, v7, v5, v4);
    goto LABEL_13;
  }
  v9 = v8 - 1;
  if ( v9 )
  {
    if ( v9 != 1 )
      return 0i64;
    goto LABEL_9;
  }
  v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(
                                     v11[11],
                                     104i64);
  v13 = v12;
  if ( !v12 )
    return 0i64;
  hkpShapeCollectionAgent::hkpShapeCollectionAgent(v12, v6, v7, v5, v4);
  v13->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpShapeCollectionAgent>::`vftable';
  return (hkpBvTreeStreamAgent *)v13;
}

// File Line: 172
// RVA: 0xD1DBE0
void __fastcall hkpBvTreeStreamAgent::dispatchConvexListBvTree(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // rdi
  hkpCollisionInput *v5; // rbx
  hkpCdBody *v6; // rsi
  hkpCdBody *v7; // rbp
  int v8; // eax
  int v9; // eax
  _QWORD **v10; // rax
  hkpShapeCollectionAgent *v11; // rax
  _QWORD **v12; // rax
  hkpBvTreeStreamAgent *v13; // rax
  _QWORD **v14; // rax
  hkpBvTreeStreamAgent *v15; // rax
  hkpBvTreeStreamAgent *v16; // rdi

  v4 = mgr;
  v5 = input;
  v6 = bodyB;
  v7 = bodyA;
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
      v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v13 = (hkpBvTreeStreamAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(
                                      v12[11],
                                      80i64);
      if ( v13 )
        hkpBvTreeStreamAgent::hkpBvTreeStreamAgent(v13, v7, v6, v5, v4);
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
    v11 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(
                                       v10[11],
                                       104i64);
    if ( v11 )
      hkpShapeCollectionAgent::hkpShapeCollectionAgent(v11, v7, v6, v5, v4);
  }
  else
  {
    v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (hkpBvTreeStreamAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(
                                    v14[11],
                                    80i64);
    v16 = v15;
    if ( v15 )
    {
      hkpBvTreeStreamAgent::hkpBvTreeStreamAgent(v15, v6, v7, v5, 0i64);
      v16->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpBvTreeStreamAgent>::`vftable';
    }
  }
}

// File Line: 212
// RVA: 0xD1DA10
hkpBvTreeStreamAgent *__fastcall hkpBvTreeStreamAgent::createBvTreeShapeAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCdBody *v4; // r14
  hkpContactMgr *v5; // rdi
  hkpCollisionInput *v6; // rsi
  hkpCdBody *v7; // rbp
  _QWORD **v8; // rax
  hkpBvTreeStreamAgent *result; // rax
  hkpCollisionAgent *v10; // rbx

  v4 = bodyA;
  v5 = mgr;
  v6 = input;
  v7 = bodyB;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpBvTreeStreamAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 80i64);
  v10 = (hkpCollisionAgent *)&result->vfptr;
  if ( result )
  {
    hkpBvTreeStreamAgent::hkpBvTreeStreamAgent(result, v7, v4, v6, v5);
    v10->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpBvTreeStreamAgent>::`vftable';
    result = (hkpBvTreeStreamAgent *)v10;
  }
  return result;
}

// File Line: 220
// RVA: 0xD1D990
void __fastcall hkpBvTreeStreamAgent::createShapeBvAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCdBody *v4; // rbp
  hkpContactMgr *v5; // rbx
  hkpCollisionInput *v6; // rdi
  hkpCdBody *v7; // rsi
  _QWORD **v8; // rax
  hkpBvTreeStreamAgent *v9; // rax

  v4 = bodyA;
  v5 = mgr;
  v6 = input;
  v7 = bodyB;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpBvTreeStreamAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 80i64);
  if ( v9 )
    hkpBvTreeStreamAgent::hkpBvTreeStreamAgent(v9, v4, v7, v6, v5);
}

// File Line: 226
// RVA: 0xD1D800
void __fastcall hkpBvTreeStreamAgent::getPenetrations(hkpBvTreeStreamAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpBvTreeAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}

// File Line: 232
// RVA: 0xD1D820
void __fastcall hkpBvTreeStreamAgent::getClosestPoints(hkpBvTreeStreamAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpBvTreeAgent::staticGetClosestPoints(bodyA, bodyB, input, collector);
}

// File Line: 238
// RVA: 0xD1D840
void __fastcall hkpBvTreeStreamAgent::linearCast(hkpBvTreeStreamAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpBvTreeAgent::staticLinearCast(bodyA, bodyB, input, collector, startCollector);
}

// File Line: 246
// RVA: 0xD1D7C0
void __fastcall hkpBvTreeStreamAgent::cleanup(hkpBvTreeStreamAgent *this, hkpConstraintOwner *info)
{
  hkpBvTreeStreamAgent *v2; // rbx

  v2 = this;
  hkAgent1nMachine_Destroy(&this->m_agentTrack, v2->m_dispatcher, v2->m_contactMgr, info);
  v2->vfptr->__vecDelDtor((hkBaseObject *)&v2->vfptr, 1u);
}

// File Line: 281
// RVA: 0xD1D1B0
void __fastcall hkpBvTreeStreamAgent::processCollision(hkpBvTreeStreamAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *output)
{
  hkpBvTreeStreamAgent *v5; // r14
  hkpProcessCollisionInput *v6; // r13
  hkpCdBody *v7; // rsi
  hkpCdBody *v8; // rdi
  _QWORD *v9; // r8
  unsigned __int64 v10; // r10
  unsigned __int64 v11; // rax
  hkTransformf *v12; // rdx
  hkTransformf *v13; // r8
  hkpContactMgr *v14; // rax
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm6
  __m128 v18; // xmm5
  __m128 v19; // xmm4
  __int64 v20; // r8
  __m128 *v21; // r15
  __m128 *v22; // r12
  __m128 *v23; // rbx
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm8
  hkpShape *v28; // rcx
  __m128i v29; // xmm9
  hkBaseObjectVtbl *v30; // rax
  __m128 v31; // xmm7
  __m128 v32; // xmm1
  __m128 v33; // xmm6
  __m128 *v34; // rax
  __m128 v35; // xmm5
  __m128 v36; // xmm3
  __m128 v37; // xmm1
  __m128 v38; // xmm7
  __m128 v39; // xmm2
  __m128 v40; // xmm1
  __m128 v41; // xmm5
  __m128 v42; // xmm6
  __m128 v43; // xmm2
  __m128 v44; // xmm7
  __m128 v45; // xmm1
  __m128 v46; // xmm2
  __m128 v47; // xmm6
  __m128 v48; // xmm5
  signed int v49; // ebx
  __m128 v50; // xmm3
  __m128 v51; // xmm2
  __m128 v52; // xmm9
  unsigned __int64 v53; // rdx
  _QWORD *v54; // r8
  _QWORD *v55; // rcx
  unsigned __int64 v56; // rax
  signed __int64 v57; // rcx
  int v58; // ebx
  int v59; // edi
  hkMemorySystem *v60; // rax
  hkpShapeContainer *v61; // rax
  unsigned int *v62; // r9
  _QWORD *v63; // r8
  unsigned __int64 v64; // rcx
  unsigned __int64 v65; // rax
  __m128 v66; // [rsp+30h] [rbp-C8h]
  __m128 v67; // [rsp+40h] [rbp-B8h]
  hkpAgent3ProcessInput inputIn; // [rsp+50h] [rbp-A8h]
  unsigned int *pArr; // [rsp+118h] [rbp+20h]
  int v70; // [rsp+120h] [rbp+28h]
  __int64 v71; // [rsp+124h] [rbp+2Ch]
  float retaddr; // [rsp+398h] [rbp+2A0h]
  hkpProcessCollisionOutput *v73; // [rsp+3B8h] [rbp+2C0h]

  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = v9[1];
  if ( v10 < v9[3] )
  {
    *(_QWORD *)v10 = "LtBvTree3";
    *(_QWORD *)(v10 + 16) = "StQueryTree";
    v11 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v11;
    v9[1] = v10 + 24;
  }
  v12 = (hkTransformf *)v8->m_motion;
  v13 = (hkTransformf *)v7->m_motion;
  v14 = v5->m_contactMgr;
  retaddr = v6->m_stepInfo.m_deltaTime.m_storage;
  inputIn.m_overrideBodyA.m_storage = 0i64;
  inputIn.m_bodyA.m_storage = v8;
  inputIn.m_bodyB.m_storage = v7;
  v15 = _mm_shuffle_ps((__m128)LODWORD(retaddr), (__m128)LODWORD(retaddr), 0);
  inputIn.m_contactMgr.m_storage = v14;
  inputIn.m_input.m_storage = v6;
  v16 = v12[1].m_rotation.m_col1.m_quad;
  v17 = v13[1].m_rotation.m_col1.m_quad;
  v18 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 255), v15);
  v19 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 255), v15);
  *(__m128 *)(&inputIn.m_distAtT1 + 2) = _mm_add_ps(
                                           _mm_mul_ps(_mm_sub_ps(v17, v13[1].m_rotation.m_col0.m_quad), v18),
                                           _mm_mul_ps(_mm_sub_ps(v12[1].m_rotation.m_col0.m_quad, v16), v19));
  *(__m128 *)(&inputIn.m_distAtT1 + 2) = _mm_shuffle_ps(
                                           *(__m128 *)(&inputIn.m_distAtT1 + 2),
                                           _mm_unpackhi_ps(
                                             *(__m128 *)(&inputIn.m_distAtT1 + 2),
                                             _mm_add_ps(
                                               _mm_mul_ps(
                                                 _mm_mul_ps(
                                                   _mm_shuffle_ps(
                                                     v12[2].m_rotation.m_col1.m_quad,
                                                     v12[2].m_rotation.m_col1.m_quad,
                                                     255),
                                                   v19),
                                                 _mm_shuffle_ps(
                                                   (__m128)v12[2].m_rotation.m_col2.m_quad.m128_u32[0],
                                                   (__m128)v12[2].m_rotation.m_col2.m_quad.m128_u32[0],
                                                   0)),
                                               _mm_mul_ps(
                                                 _mm_mul_ps(
                                                   _mm_shuffle_ps(
                                                     v13[2].m_rotation.m_col1.m_quad,
                                                     v13[2].m_rotation.m_col1.m_quad,
                                                     255),
                                                   v18),
                                                 _mm_shuffle_ps(
                                                   (__m128)v13[2].m_rotation.m_col2.m_quad.m128_u32[0],
                                                   (__m128)v13[2].m_rotation.m_col2.m_quad.m128_u32[0],
                                                   0)))),
                                           196);
  hkTransformf::setMulInverseMul((hkTransformf *)(&inputIn.m_contactMgr + 1), v12, v13);
  v71 = -2147483520i64;
  pArr = (unsigned int *)((char *)&v71 + 4);
  v70 = 1;
  hkTransformf::setInverse(
    (hkTransformf *)&inputIn.m_linearTimInfo.m_quad.m128_u16[4],
    (hkTransformf *)(&inputIn.m_contactMgr + 1));
  v21 = (__m128 *)v7->m_motion;
  v22 = (__m128 *)v8->m_motion;
  v23 = &v5->m_cachedAabb.m_min.m_quad;
  v24 = v21[2];
  v25 = _mm_unpacklo_ps(*v21, v21[1]);
  v26 = _mm_movelh_ps(v25, v24);
  v27 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(*(__m128 *)(&inputIn.m_distAtT1 + 2), *(__m128 *)(&inputIn.m_distAtT1 + 2), 85),
              _mm_shuffle_ps(_mm_movehl_ps(v26, v25), v24, 212)),
            _mm_mul_ps(
              _mm_shuffle_ps(*(__m128 *)(&inputIn.m_distAtT1 + 2), *(__m128 *)(&inputIn.m_distAtT1 + 2), 0),
              v26)),
          _mm_mul_ps(
            _mm_shuffle_ps(*(__m128 *)(&inputIn.m_distAtT1 + 2), *(__m128 *)(&inputIn.m_distAtT1 + 2), 170),
            _mm_shuffle_ps(_mm_unpackhi_ps(*v21, v21[1]), v24, 228)));
  v28 = v8->m_shape;
  v29 = (__m128i)_mm_mul_ps(
                   _mm_shuffle_ps(
                     (__m128)LODWORD(v6->m_tolerance.m_storage),
                     (__m128)LODWORD(v6->m_tolerance.m_storage),
                     0),
                   (__m128)xmmword_141A711B0);
  v30 = v8->m_shape->vfptr;
  if ( v6->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage )
  {
    v31 = _mm_shuffle_ps((__m128)v22[10].m128_u32[0], (__m128)v22[10].m128_u32[0], 0);
    v32 = _mm_shuffle_ps(v21[9], v21[9], 255);
    v33 = _mm_mul_ps(_mm_shuffle_ps((__m128)v21[10].m128_u32[0], (__m128)v21[10].m128_u32[0], 0), _mm_mul_ps(v32, v32));
    ((void (__fastcall *)(hkpShape *, unsigned __int16 *, __int64, __m128 *))v30[2].__vecDelDtor)(
      v28,
      &inputIn.m_linearTimInfo.m_quad.m128_u16[4],
      v20,
      &v66);
    v34 = (__m128 *)v7->m_motion;
    v35 = _mm_sub_ps(v22[5], v34[3]);
    v36 = v34[2];
    v37 = _mm_unpacklo_ps(*v34, v34[1]);
    v38 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_add_ps(_mm_add_ps(v31, (__m128)v29), v33), 4), 4);
    v39 = _mm_movelh_ps(v37, v36);
    v40 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(_mm_movehl_ps(v39, v37), v36, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), v39)),
            _mm_mul_ps(_mm_shuffle_ps(_mm_unpackhi_ps(*v34, v34[1]), v36, 228), _mm_shuffle_ps(v35, v35, 170)));
    v41 = _mm_max_ps(v66, _mm_sub_ps(v40, v38));
    v66 = v41;
    v42 = _mm_min_ps(v67, _mm_add_ps(v40, v38));
    v67 = v42;
    v43 = v21[9];
    v44 = _mm_sub_ps(v42, v41);
    if ( COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 255)) > 0.0 )
    {
      v45 = _mm_sub_ps(v40, v21[8]);
      v46 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v45), _mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), v43));
      v27 = _mm_add_ps(
              v27,
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    (__m128)LODWORD(v6->m_stepInfo.m_deltaTime.m_storage),
                    (__m128)LODWORD(v6->m_stepInfo.m_deltaTime.m_storage),
                    0),
                  _mm_shuffle_ps(v21[5], v21[5], 255)),
                _mm_shuffle_ps(v46, v46, 201)));
    }
    v47 = _mm_add_ps(v42, _mm_max_ps((__m128)0i64, v27));
    v48 = _mm_add_ps(v41, _mm_min_ps((__m128)0i64, v27));
    v67 = v47;
    v66 = v48;
  }
  else
  {
    ((void (__fastcall *)(hkpShape *, unsigned __int16 *, __int64, __m128 *))v30[2].__vecDelDtor)(
      v28,
      &inputIn.m_linearTimInfo.m_quad.m128_u16[4],
      v20,
      &v66);
    v47 = v67;
    v48 = v66;
    v44 = _mm_sub_ps(v67, v66);
  }
  if ( v5 != (hkpBvTreeStreamAgent *)-32i64 )
  {
    if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(*v23, v48), _mm_cmpleps(v47, v5->m_cachedAabb.m_max.m_quad))) & 7) == 7 )
    {
      v49 = 1;
      goto LABEL_13;
    }
    v50 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_40000001), (__m128)LODWORD(FLOAT_0_40000001), 0), v44);
    retaddr = FLOAT_N2_0;
    v51 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_N2_0), (__m128)LODWORD(FLOAT_N2_0), 0);
    v52 = (__m128)_mm_srli_si128(_mm_slli_si128(v29, 4), 4);
    v66 = _mm_add_ps(
            _mm_sub_ps(v48, v52),
            _mm_max_ps(
              _mm_mul_ps(_mm_max_ps((__m128)0i64, v27), v51),
              _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v50)));
    *v23 = v66;
    v67 = _mm_add_ps(_mm_add_ps(v47, v52), _mm_min_ps(_mm_mul_ps(_mm_min_ps((__m128)0i64, v27), v51), v50));
    v5->m_cachedAabb.m_max.m_quad = v67;
  }
  ((void (__fastcall *)(hkpShape *, __m128 *, unsigned int **))v7->m_shape->vfptr[8].__first_virtual_table_function__)(
    v7->m_shape,
    &v66,
    &pArr);
  v49 = 0;
LABEL_13:
  v54 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v55 = (_QWORD *)v54[1];
  if ( (unsigned __int64)v55 < v54[3] )
  {
    *v55 = "StNarrow";
    v56 = __rdtsc();
    v53 = (unsigned __int64)HIDWORD(v56) << 32;
    v57 = (signed __int64)(v55 + 2);
    *(_DWORD *)(v57 - 8) = v56;
    v54[1] = v57;
  }
  if ( v49 )
  {
    v61 = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *, unsigned __int64, _QWORD *))v7->m_shape->vfptr[7].__vecDelDtor)(
                                 v7->m_shape,
                                 v53,
                                 v54);
    v62 = 0i64;
  }
  else
  {
    v58 = v70;
    v59 = v5->m_agentTrack.m_sectors.m_size;
    v60 = hkMemorySystem::getInstance();
    if ( !v60->vfptr->heapCanAllocTotal(v60, (v58 / 4 - v59 + 1) << 9) )
    {
      hkSetOutOfMemoryState(MEMORY_STATE_OUT_OF_MEMORY);
      goto LABEL_23;
    }
    if ( v70 > 1 )
      hkAlgorithm::quickSortRecursive<unsigned int,hkAlgorithm::less<unsigned int>>(pArr, 0, v70 - 1, 0);
    v61 = (hkpShapeContainer *)((__int64 (*)(void))v7->m_shape->vfptr[7].__vecDelDtor)();
    v62 = pArr;
  }
  hkAgent1nMachine_Process(&v5->m_agentTrack, &inputIn, v61, v62, v73);
LABEL_23:
  v63 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v64 = v63[1];
  if ( v64 < v63[3] )
  {
    *(_QWORD *)v64 = "lt";
    v65 = __rdtsc();
    *(_DWORD *)(v64 + 8) = v65;
    v63[1] = v64 + 16;
  }
  v70 = 0;
  if ( (signed int)v71 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      pArr,
      4 * v71);
}

// File Line: 349
// RVA: 0xD1D880
void __fastcall hkpBvTreeStreamAgent::updateShapeCollectionFilter(hkpBvTreeStreamAgent *this, hkpCdBody *bodyA, hkpCdBody *collectionBodyB, hkpCollisionInput *input, hkpConstraintOwner *constraintOwner)
{
  hkpBvTreeStreamAgent *v5; // rbp
  hkpCollisionInput *v6; // rsi
  hkpCdBody *v7; // rdi
  hkpCdBody *v8; // rbx
  hkpShapeContainer *v9; // rax
  hkpAgent1nMachine_VisitorInput vin; // [rsp+20h] [rbp-48h]

  v5 = this;
  v6 = input;
  v7 = collectionBodyB;
  v8 = bodyA;
  this->m_cachedAabb.m_min = 0i64;
  this->m_cachedAabb.m_max = 0i64;
  v9 = (hkpShapeContainer *)((__int64 (*)(void))collectionBodyB->m_shape->vfptr[7].__vecDelDtor)();
  vin.m_contactMgr = v5->m_contactMgr;
  vin.m_constraintOwner = constraintOwner;
  vin.m_bodyA = v8;
  vin.m_collectionBodyB = v7;
  vin.m_input = v6;
  vin.m_containerShapeB = v9;
  hkAgent1nMachine_UpdateShapeCollectionFilter(&v5->m_agentTrack, &vin);
}

// File Line: 370
// RVA: 0xD1D910
void __fastcall hkpBvTreeStreamAgent::invalidateTim(hkpBvTreeStreamAgent *this, hkpCollisionInput *input)
{
  hkAgent1nMachine_InvalidateTim(&this->m_agentTrack, input);
}

// File Line: 375
// RVA: 0xD1D920
void __fastcall hkpBvTreeStreamAgent::warpTime(hkpBvTreeStreamAgent *this, float oldTime, float newTime, hkpCollisionInput *input)
{
  hkAgent1nMachine_WarpTime(&this->m_agentTrack, oldTime, newTime, input);
}


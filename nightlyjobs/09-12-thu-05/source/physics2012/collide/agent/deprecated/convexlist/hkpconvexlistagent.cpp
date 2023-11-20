// File Line: 51
// RVA: 0xD27A00
void __fastcall hkpConvexListAgent::hkpConvexListAgent(hkpConvexListAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCollisionInput *v5; // rbx
  hkpCdBody *v6; // rsi
  hkpCdBody *v7; // r14
  hkpConvexListAgent *v8; // r15
  hkpConvexShape *v9; // rdi
  hkpConvexShape *v10; // rbx
  hkTransformf aTb; // [rsp+20h] [rbp-48h]

  v5 = input;
  v6 = bodyB;
  v7 = bodyA;
  v8 = this;
  hkpGskfAgent::hkpGskfAgent((hkpGskfAgent *)&this->vfptr, bodyA, bodyB, mgr);
  v8->vfptr = (hkBaseObjectVtbl *)&hkpConvexListAgent::`vftable;
  v8->m_dispatcher = v5->m_dispatcher.m_storage;
  *(_WORD *)&v8->m_inGskMode.m_bool = 1;
  v9 = (hkpConvexShape *)v7->m_shape;
  v10 = (hkpConvexShape *)v6->m_shape;
  hkTransformf::setMulInverseMul(&aTb, (hkTransformf *)v7->m_motion, (hkTransformf *)v6->m_motion);
  hkpGskCache::init(&v8->m_cache, v9, v10, &aTb);
  v8->m_separatingNormal.m_quad.m128_i32[3] = -1082130432;
  v8->m_timeOfSeparatingNormal = -1.0;
}

// File Line: 71
// RVA: 0xD27B80
hkpCollisionAgent *__fastcall hkpConvexListAgent::createConvexConvexListAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // rbp
  hkpCollisionInput *v5; // r14
  hkpCdBody *v6; // rdi
  hkpCdBody *v7; // rsi
  int v8; // eax
  int v9; // eax
  _QWORD **v10; // rax
  hkpGskfAgent *v11; // rax
  _QWORD *v12; // rbx
  _QWORD **v13; // rax
  hkpShapeCollectionAgent *v14; // rax
  _QWORD **v15; // rax
  hkpConvexListAgent *v16; // rax
  __int64 v17; // rax
  _QWORD **v18; // rax
  hkpShapeCollectionAgent *v19; // rax
  hkpShapeCollectionAgent *v20; // r15

  v4 = mgr;
  v5 = input;
  v6 = bodyB;
  v7 = bodyA;
  if ( mgr )
  {
    v8 = ((__int64 (__fastcall *)(hkpConvexListFilter *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))input->m_convexListFilter.m_storage->vfptr[1].__first_virtual_table_function__)(
           input->m_convexListFilter.m_storage,
           bodyB,
           bodyA,
           input);
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( v9 )
      {
        if ( v9 == 1 )
        {
          v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v11 = (hkpGskfAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 144i64);
          v12 = &v11->vfptr;
          if ( v11 )
          {
            hkpGskfAgent::hkpGskfAgent(v11, v7, v6, v4);
            *v12 = &hkpPredGskfAgent::`vftable;
            return (hkpCollisionAgent *)v12;
          }
        }
      }
      else
      {
        v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v14 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v13[11] + 8i64))(
                                           v13[11],
                                           104i64);
        v12 = &v14->vfptr;
        if ( v14 )
        {
          hkpShapeCollectionAgent::hkpShapeCollectionAgent(v14, v6, v7, v5, v4);
          *v12 = &hkpSymmetricAgent<hkpShapeCollectionAgent>::`vftable;
          return (hkpCollisionAgent *)v12;
        }
      }
    }
    else
    {
      v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v16 = (hkpConvexListAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v15[11] + 8i64))(
                                    v15[11],
                                    160i64);
      if ( v16 )
      {
        hkpConvexListAgent::hkpConvexListAgent(v16, v7, v6, v5, v4);
        return (hkpCollisionAgent *)v17;
      }
    }
    return 0i64;
  }
  v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v19 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v18[11] + 8i64))(
                                     v18[11],
                                     104i64);
  v12 = 0i64;
  v20 = v19;
  if ( v19 )
  {
    hkpShapeCollectionAgent::hkpShapeCollectionAgent(v19, v6, v7, v5, 0i64);
    v12 = &v20->vfptr;
    v20->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpShapeCollectionAgent>::`vftable;
  }
  return (hkpCollisionAgent *)v12;
}

// File Line: 109
// RVA: 0xD27D10
hkpConvexListAgent *__fastcall hkpConvexListAgent::createConvexListConvexAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // r14
  hkpCollisionInput *v5; // rbp
  hkpCdBody *v6; // rdi
  hkpCdBody *v7; // rsi
  int v8; // eax
  int v9; // eax
  _QWORD **v10; // rax
  hkpGskfAgent *v11; // rax
  hkpConvexListAgent *v12; // rbx
  _QWORD **v13; // rax
  hkpShapeCollectionAgent *v14; // rax
  __int64 v15; // rax
  _QWORD **v16; // rax
  hkpConvexListAgent *v17; // rax
  _QWORD **v18; // rax
  hkpShapeCollectionAgent *v19; // rax

  v4 = mgr;
  v5 = input;
  v6 = bodyB;
  v7 = bodyA;
  if ( !mgr )
  {
    v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v19 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v18[11] + 8i64))(
                                       v18[11],
                                       104i64);
    if ( v19 )
    {
      hkpShapeCollectionAgent::hkpShapeCollectionAgent(v19, v7, v6, v5, 0i64);
      return (hkpConvexListAgent *)v15;
    }
    return 0i64;
  }
  v8 = ((__int64 (__fastcall *)(hkpConvexListFilter *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))input->m_convexListFilter.m_storage->vfptr[1].__first_virtual_table_function__)(
         input->m_convexListFilter.m_storage,
         bodyA,
         bodyB,
         input);
  if ( !v8 )
  {
    v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (hkpConvexListAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(v16[11], 160i64);
    v12 = v17;
    if ( v17 )
    {
      hkpConvexListAgent::hkpConvexListAgent(v17, v6, v7, v5, v4);
      v12->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpConvexListAgent>::`vftable;
      return v12;
    }
    return 0i64;
  }
  v9 = v8 - 1;
  if ( !v9 )
  {
    v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v13[11] + 8i64))(
                                       v13[11],
                                       104i64);
    if ( v14 )
    {
      hkpShapeCollectionAgent::hkpShapeCollectionAgent(v14, v7, v6, v5, v4);
      return (hkpConvexListAgent *)v15;
    }
    return 0i64;
  }
  if ( v9 != 1 )
    return 0i64;
  v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (hkpGskfAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 144i64);
  v12 = (hkpConvexListAgent *)v11;
  if ( !v11 )
    return 0i64;
  hkpGskfAgent::hkpGskfAgent(v11, v7, v6, v4);
  v12->vfptr = (hkBaseObjectVtbl *)&hkpPredGskfAgent::`vftable;
  return v12;
}

// File Line: 149
// RVA: 0xD27E80
void __fastcall hkpConvexListAgent::createConvexListConvexListAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // r14
  hkpCollisionInput *v5; // rdi
  hkpCdBody *v6; // rsi
  hkpCdBody *v7; // rbp
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _QWORD **v12; // rax
  hkpGskfAgent *v13; // rax
  hkpGskfAgent *v14; // rbx
  _QWORD **v15; // rax
  hkpShapeCollectionAgent *v16; // rax
  hkpShapeCollectionAgent *v17; // rbx
  _QWORD **v18; // rax
  hkpConvexListAgent *v19; // rax
  _QWORD **v20; // rax
  hkpShapeCollectionAgent *v21; // rax
  _QWORD **v22; // rax
  hkpConvexListAgent *v23; // rax
  hkpConvexListAgent *v24; // rbx
  _QWORD **v25; // rax
  hkpShapeCollectionAgent *v26; // rcx

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
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( v9 )
      {
        if ( v9 == 1 )
        {
          v10 = ((__int64 (__fastcall *)(hkpConvexListFilter *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))v5->m_convexListFilter.m_storage->vfptr[1].__first_virtual_table_function__)(
                  v5->m_convexListFilter.m_storage,
                  v6,
                  v7,
                  v5);
          if ( v10 )
          {
            v11 = v10 - 1;
            if ( v11 )
            {
              if ( v11 == 1 )
              {
                v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
                v13 = (hkpGskfAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(
                                        v12[11],
                                        144i64);
                v14 = v13;
                if ( v13 )
                {
                  hkpGskfAgent::hkpGskfAgent(v13, v7, v6, v4);
                  v14->vfptr = (hkBaseObjectVtbl *)&hkpPredGskfAgent::`vftable;
                }
              }
            }
            else
            {
              v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v16 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v15[11] + 8i64))(
                                                 v15[11],
                                                 104i64);
              v17 = v16;
              if ( v16 )
              {
                hkpShapeCollectionAgent::hkpShapeCollectionAgent(v16, v6, v7, v5, v4);
                v17->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpShapeCollectionAgent>::`vftable;
              }
            }
          }
          else
          {
            v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v19 = (hkpConvexListAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v18[11] + 8i64))(
                                          v18[11],
                                          160i64);
            if ( v19 )
              hkpConvexListAgent::hkpConvexListAgent(v19, v7, v6, v5, v4);
          }
        }
      }
      else
      {
        v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v21 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v20[11] + 8i64))(
                                           v20[11],
                                           104i64);
        if ( v21 )
          hkpShapeCollectionAgent::hkpShapeCollectionAgent(v21, v7, v6, v5, v4);
      }
    }
    else
    {
      v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v23 = (hkpConvexListAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v22[11] + 8i64))(
                                    v22[11],
                                    160i64);
      v24 = v23;
      if ( v23 )
      {
        hkpConvexListAgent::hkpConvexListAgent(v23, v6, v7, v5, v4);
        v24->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpConvexListAgent>::`vftable;
      }
    }
  }
  else
  {
    v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v26 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v25[11] + 8i64))(
                                       v25[11],
                                       104i64);
    if ( v26 )
      hkpShapeCollectionAgent::hkpShapeCollectionAgent(v26, v7, v6, v5, 0i64);
  }
}

// File Line: 203
// RVA: 0xD26CC0
void __fastcall hkpConvexListAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  f.m_createFunc = hkpConvexListAgent::createConvexListConvexAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpConvexListAgent>::staticGetPenetrations;
  v1 = dispatcher;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpConvexListAgent>::staticGetClosestPoints;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpConvexListAgent>::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, CONVEX_LIST, CONVEX);
  f.m_createFunc = hkpConvexListAgent::createConvexConvexListAgent;
  f.m_getPenetrationsFunc = hkpConvexListAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpConvexListAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpConvexListAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, CONVEX, CONVEX_LIST);
  f.m_createFunc = hkpConvexListAgent::createConvexListConvexListAgent;
  f.m_getPenetrationsFunc = hkpConvexListAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpConvexListAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpConvexListAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, CONVEX_LIST, CONVEX_LIST);
}

// File Line: 238
// RVA: 0xD27890
void __fastcall hkpConvexListAgent::updateShapeCollectionFilter(hkpConvexListAgent *this, hkpCdBody *bodyA, hkpCdBody *listShapeBodyB, hkpCollisionInput *input, hkpConstraintOwner *constraintOwner)
{
  hkpConvexListAgent *v5; // rbx
  hkpContactMgr *v6; // rax
  hkpShape *v7; // rcx
  hkpAgent1nMachine_VisitorInput vin; // [rsp+20h] [rbp-48h]

  v5 = this;
  if ( !this->m_inGskMode.m_bool )
  {
    v6 = this->m_contactMgr;
    v7 = listShapeBodyB->m_shape;
    vin.m_bodyA = bodyA;
    vin.m_contactMgr = v6;
    vin.m_collectionBodyB = listShapeBodyB;
    vin.m_constraintOwner = constraintOwner;
    vin.m_input = input;
    vin.m_containerShapeB = (hkpShapeContainer *)((__int64 (__cdecl *)(hkpShape *, hkpCdBody *))v7->vfptr[7].__vecDelDtor)(
                                                   v7,
                                                   bodyA);
    hkAgent1nMachine_UpdateShapeCollectionFilter((hkpAgent1nTrack *)&v5->m_manifold, &vin);
  }
}

// File Line: 258
// RVA: 0xD278F0
void __fastcall hkpConvexListAgent::invalidateTim(hkpConvexListAgent *this, hkpCollisionInput *input)
{
  JUMPOUT(this->m_inGskMode.m_bool, 0, hkpGskBaseAgent::invalidateTim);
  hkAgent1nMachine_InvalidateTim((hkpAgent1nTrack *)&this->m_manifold, input);
}

// File Line: 270
// RVA: 0xD27910
void __fastcall hkpConvexListAgent::warpTime(hkpConvexListAgent *this, float oldTime, float newTime, hkpCollisionInput *input)
{
  JUMPOUT(this->m_inGskMode.m_bool, 0, hkpGskBaseAgent::warpTime);
  hkAgent1nMachine_WarpTime((hkpAgent1nTrack *)&this->m_manifold, oldTime, newTime, input);
}

// File Line: 281
// RVA: 0xD279A0
void __fastcall hkpConvexListAgent::removePoint(hkpConvexListAgent *this, unsigned __int16 idToRemove)
{
  JUMPOUT(this->m_inGskMode.m_bool, 0, hkpGskfAgent::removePoint);
}

// File Line: 289
// RVA: 0xD279C0
void __fastcall hkpConvexListAgent::commitPotential(hkpConvexListAgent *this, unsigned __int16 idToCommit)
{
  JUMPOUT(this->m_inGskMode.m_bool, 0, hkpGskfAgent::commitPotential);
}

// File Line: 297
// RVA: 0xD279E0
void __fastcall hkpConvexListAgent::createZombie(hkpConvexListAgent *this, unsigned __int16 idTobecomeZombie)
{
  JUMPOUT(this->m_inGskMode.m_bool, 0, hkpGskfAgent::createZombie);
}

// File Line: 307
// RVA: 0xD27560
void __fastcall hkpConvexListAgent::staticGetClosestPoints(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpCdBody *v4; // rdi
  hkpCdPointCollector *v5; // rsi
  hkpCollisionInput *v6; // rbp
  hkpCdBody *v7; // rbx
  _QWORD *v8; // rax
  unsigned __int64 v9; // rcx
  _QWORD *v10; // r8
  unsigned __int64 v11; // rax
  hkpCdPointCollectorVtbl *v12; // rax
  _QWORD *v13; // r8
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rax
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx
  hkpCdBodyPairCollector collectora; // [rsp+20h] [rbp-B8h]
  hkpCdPointCollector v21; // [rsp+30h] [rbp-A8h]
  __int128 v22; // [rsp+40h] [rbp-98h]
  __m128 v23; // [rsp+50h] [rbp-88h]
  __int64 v24; // [rsp+60h] [rbp-78h]
  __int128 v25; // [rsp+90h] [rbp-48h]
  __m128 v26; // [rsp+A0h] [rbp-38h]
  __m128 v27; // [rsp+B0h] [rbp-28h]
  hkpCdBody *v28; // [rsp+C0h] [rbp-18h]
  hkpCdBody *v29; // [rsp+C8h] [rbp-10h]

  v4 = bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = v8[1];
  v10 = v8;
  if ( v9 < v8[3] )
  {
    *(_QWORD *)v9 = "LtCvxList";
    *(_QWORD *)(v9 + 16) = "StcheckHull";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  collectora.m_earlyOut.m_bool = 0;
  collectora.vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpFlagCdBodyPairCollector::`vftable;
  hkpGskBaseAgent::staticGetPenetrations(v4, v7, v6, &collectora);
  if ( collectora.m_earlyOut.m_bool )
    goto LABEL_14;
  v24 = 0i64;
  v21.vfptr = (hkpCdPointCollectorVtbl *)&hkpClosestCdPointCollector::`vftable;
  v21.m_earlyOutDistance = FLOAT_3_40282e38;
  v23 = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, (__m128)xmmword_141A712A0), 196);
  hkpGskBaseAgent::staticGetClosestPoints(v4, v7, v6, &v21);
  if ( !v24 )
    goto LABEL_10;
  if ( v23.m128_f32[3] <= *(float *)&v7->m_shape[1].m_type.m_storage )
  {
LABEL_14:
    v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v14 = v13[1];
    if ( v14 < v13[3] )
    {
      *(_QWORD *)v14 = "Stchildren";
      v15 = __rdtsc();
      *(_DWORD *)(v14 + 8) = v15;
      v13[1] = v14 + 16;
    }
    hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetClosestPoints(v4, v7, v6, v5);
  }
  else
  {
    v12 = v5->vfptr;
    v28 = v4;
    v25 = v22;
    v26 = v23;
    v27 = v23;
    v29 = v7;
    v12->addCdPoint(v5, (hkpCdPoint *)&v25);
  }
LABEL_10:
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "lt";
    v18 = __rdtsc();
    v19 = (signed __int64)(v17 + 2);
    *(_DWORD *)(v19 - 8) = v18;
    v16[1] = v19;
  }
}

// File Line: 344
// RVA: 0xD27540
void __fastcall hkpConvexListAgent::getClosestPoints(hkpConvexListAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpConvexListAgent::staticGetClosestPoints(bodyA, bodyB, input, collector);
}

// File Line: 349
// RVA: 0xD27760
void __fastcall hkpConvexListAgent::staticGetPenetrations(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpCdBody *v4; // rsi
  hkpCdBodyPairCollector *v5; // rbp
  hkpCollisionInput *v6; // rbx
  hkpCdBody *v7; // rdi
  _QWORD *v8; // rax
  unsigned __int64 v9; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx
  hkpCdBodyPairCollector collectora; // [rsp+20h] [rbp-18h]

  v4 = bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = v8[1];
  v10 = v8;
  if ( v9 < v8[3] )
  {
    *(_QWORD *)v9 = "LtCvxList";
    *(_QWORD *)(v9 + 16) = "StcheckHull";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  collectora.m_earlyOut.m_bool = 0;
  collectora.vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpFlagCdBodyPairCollector::`vftable;
  hkpGskBaseAgent::staticGetPenetrations(v4, v7, v6, &collectora);
  if ( collectora.m_earlyOut.m_bool )
  {
    v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v13 = (_QWORD *)v12[1];
    if ( (unsigned __int64)v13 < v12[3] )
    {
      *v13 = "Stchildren";
      v14 = __rdtsc();
      v15 = (signed __int64)(v13 + 2);
      *(_DWORD *)(v15 - 8) = v14;
      v12[1] = v15;
    }
    hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetPenetrations(v4, v7, v6, v5);
  }
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "lt";
    v18 = __rdtsc();
    v19 = (signed __int64)(v17 + 2);
    *(_DWORD *)(v19 - 8) = v18;
    v16[1] = v19;
  }
}

// File Line: 364
// RVA: 0xD27740
void __fastcall hkpConvexListAgent::getPenetrations(hkpConvexListAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpConvexListAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}

// File Line: 370
// RVA: 0xD273D0
void __fastcall hkpConvexListAgent::staticLinearCast(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpCdBody *v5; // rsi
  hkpCdPointCollector *v6; // rbp
  hkpLinearCastCollisionInput *v7; // rbx
  hkpCdBody *v8; // rdi
  _QWORD *v9; // rax
  unsigned __int64 v10; // r10
  _QWORD *v11; // r11
  unsigned __int64 v12; // rax
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  signed __int64 v16; // rcx
  _QWORD *v17; // r8
  _QWORD *v18; // rcx
  unsigned __int64 v19; // rax
  signed __int64 v20; // rcx
  hkpCdPointCollector collectora; // [rsp+30h] [rbp-48h]
  char v22; // [rsp+40h] [rbp-38h]
  __m128 v23; // [rsp+60h] [rbp-18h]

  v5 = bodyA;
  v6 = collector;
  v7 = input;
  v8 = bodyB;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = v9[1];
  v11 = v9;
  if ( v10 < v9[3] )
  {
    *(_QWORD *)v10 = "LtCvsListAgent";
    *(_QWORD *)(v10 + 16) = "StcheckHull";
    v12 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v12;
    v11[1] = v10 + 24;
  }
  collectora.vfptr = (hkpCdPointCollectorVtbl *)&hkpSimpleClosestContactCollector::`vftable;
  v22 = 0;
  collectora.m_earlyOutDistance = FLOAT_3_40282e38;
  v23 = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, (__m128)xmmword_141A712A0), 196);
  hkpIterativeLinearCastAgent::staticLinearCast(v5, v8, v7, &collectora, &collectora);
  if ( v22 )
  {
    v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v14 = (_QWORD *)v13[1];
    if ( (unsigned __int64)v14 < v13[3] )
    {
      *v14 = "Stchild";
      v15 = __rdtsc();
      v16 = (signed __int64)(v14 + 2);
      *(_DWORD *)(v16 - 8) = v15;
      v13[1] = v16;
    }
    hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticLinearCast(v5, v8, v7, v6, startCollector);
  }
  v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v18 = (_QWORD *)v17[1];
  if ( (unsigned __int64)v18 < v17[3] )
  {
    *v18 = "lt";
    v19 = __rdtsc();
    v20 = (signed __int64)(v18 + 2);
    *(_DWORD *)(v20 - 8) = v19;
    v17[1] = v20;
  }
}

// File Line: 385
// RVA: 0xD27390
void __fastcall hkpConvexListAgent::linearCast(hkpConvexListAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpConvexListAgent::staticLinearCast(bodyA, bodyB, input, collector, startCollector);
}

// File Line: 391
// RVA: 0xD27B10
void __fastcall hkpConvexListAgent::switchToStreamMode(hkpConvexListAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpAgent1nTrack *v2; // rbx
  hkpConvexListAgent *v3; // rdi

  v2 = (hkpAgent1nTrack *)&this->m_manifold;
  v3 = this;
  hkGskManifold_cleanup(&this->m_manifold, this->m_contactMgr, constraintOwner);
  v3->m_inGskMode.m_bool = 0;
  if ( v2 )
  {
    v2->m_sectors.m_data = 0i64;
    v2->m_sectors.m_size = 0;
    v2->m_sectors.m_capacityAndFlags = 2147483648;
  }
  hkAgent1nMachine_Create(v2);
  v3->m_inStreamModeCounter = 25;
  v3->m_manifold.m_contactPoints[1].m_allVerts = 0;
}

// File Line: 403
// RVA: 0xD27AC0
void __fastcall hkpConvexListAgent::switchToGskMode(hkpConvexListAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpConvexListAgent *v2; // rdi

  v2 = this;
  hkAgent1nMachine_Destroy(
    (hkpAgent1nTrack *)&this->m_manifold,
    this->m_dispatcher,
    this->m_contactMgr,
    constraintOwner);
  *(_DWORD *)&v2->m_manifold.m_numVertsA = 0;
  v2->m_inGskMode.m_bool = 1;
}

// File Line: 412
// RVA: 0xD27930
void __fastcall hkpConvexListAgent::cleanup(hkpConvexListAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpConvexListAgent *v2; // rbx

  v2 = this;
  if ( this->m_inGskMode.m_bool )
    hkGskManifold_cleanup(&this->m_manifold, this->m_contactMgr, constraintOwner);
  else
    hkAgent1nMachine_Destroy(
      (hkpAgent1nTrack *)&this->m_manifold,
      this->m_dispatcher,
      this->m_contactMgr,
      constraintOwner);
  v2->vfptr->__vecDelDtor((hkBaseObject *)&v2->vfptr, 1u);
}

// File Line: 428
// RVA: 0xD26DC0
void __fastcall hkpConvexListAgent::processCollision(hkpConvexListAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *output)
{
  hkpConvexListAgent *v5; // rdi
  hkpProcessCollisionInput *v6; // r12
  hkpCdBody *v7; // rsi
  hkpCdBody *v8; // rbx
  _QWORD *v9; // r8
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rax
  __m128 *v12; // rcx
  __m128 *v13; // rax
  hkpProcessCollisionOutput *v14; // r14
  hkpShape *v15; // r13
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  hkVector4f v22; // xmm6
  __m128 v23; // xmm1
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  signed __int64 v29; // rcx
  bool v30; // zf
  hkpContactMgr *v31; // rdx
  hkpCdBody *v32; // rax
  hkpCdBody *i; // rcx
  hkpCdBody *v34; // rax
  float v35; // xmm0_4
  hkpCdBody *j; // rcx
  _QWORD *v37; // r8
  _QWORD *v38; // rcx
  unsigned __int64 v39; // rax
  signed __int64 v40; // rcx
  __int16 v41; // cx
  hkpConvexShape *v42; // rax
  hkTransformf *v43; // r8
  hkTransformf *v44; // rdx
  unsigned int v45; // er15
  __m128 v46; // xmm1
  __m128 v47; // xmm4
  __m128 v48; // xmm1
  __int64 v49; // rbx
  hkLifoAllocator *v50; // rax
  unsigned int *v51; // rsi
  int v52; // edx
  char *v53; // rcx
  __int64 v54; // rcx
  int v55; // ebx
  hkLifoAllocator *v56; // rax
  int v57; // er8
  _QWORD *v58; // r8
  _QWORD *v59; // rcx
  unsigned __int64 v60; // rax
  signed __int64 v61; // rcx
  hkpGsk::GetClosesetPointInput inputa; // [rsp+30h] [rbp-D0h]
  hkVector4f pointOnBOut; // [rsp+60h] [rbp-A0h]
  hkpAgent3ProcessInput inputIn; // [rsp+70h] [rbp-90h]
  hkTransformf v65; // [rsp+100h] [rbp+0h]
  hkpProcessCollisionOutputBackup v66; // [rsp+140h] [rbp+40h]
  hkResult result; // [rsp+2260h] [rbp+2160h]

  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = v9[1];
  if ( v10 < v9[3] )
  {
    *(_QWORD *)v10 = "LtCvxLst";
    *(_QWORD *)(v10 + 16) = "StTim";
    v11 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v11;
    v9[1] = v10 + 24;
  }
  v12 = (__m128 *)v7->m_motion;
  v13 = (__m128 *)v8->m_motion;
  v14 = output;
  v15 = v7->m_shape;
  v16 = v13[5];
  v17 = v12[5];
  v18 = _mm_shuffle_ps(
          (__m128)LODWORD(v6->m_stepInfo.m_deltaTime.m_storage),
          (__m128)LODWORD(v6->m_stepInfo.m_deltaTime.m_storage),
          0);
  v19 = _mm_mul_ps(_mm_shuffle_ps(v13[5], v16, 255), v18);
  v20 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 255), v18);
  v21 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v13[4], v16), v19), _mm_mul_ps(_mm_sub_ps(v17, v12[4]), v20));
  v22.m_quad = _mm_shuffle_ps(
                 v21,
                 _mm_unpackhi_ps(
                   v21,
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v13[9], v13[9], 255), v19),
                       _mm_shuffle_ps((__m128)v13[10].m128_u32[0], (__m128)v13[10].m128_u32[0], 0)),
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v12[9], v12[9], 255), v20),
                       _mm_shuffle_ps((__m128)v12[10].m128_u32[0], (__m128)v12[10].m128_u32[0], 0)))),
                 196);
  hkpProcessCollisionOutputBackup::hkpProcessCollisionOutputBackup(&v66, output);
  if ( !v5->m_inGskMode.m_bool )
    goto $streamMode;
  while ( 1 )
  {
    if ( v6->m_tolerance.m_storage < v5->m_separatingNormal.m_quad.m128_f32[3] )
    {
      v23 = _mm_mul_ps(v5->m_separatingNormal.m_quad, v22.m_quad);
      v24 = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, v22.m_quad), 196);
      v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 78), v24);
      v25.m128_f32[0] = v5->m_separatingNormal.m_quad.m128_f32[3]
                      - (float)(COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 177)) + v25.m128_f32[0]);
      v5->m_separatingNormal.m_quad.m128_i32[3] = v25.m128_i32[0];
      if ( v25.m128_f32[0] > v6->m_tolerance.m_storage )
        break;
    }
    v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v27 = (_QWORD *)v26[1];
    if ( (unsigned __int64)v27 < v26[3] )
    {
      *v27 = "StGsk";
      v28 = __rdtsc();
      v29 = (signed __int64)(v27 + 2);
      *(_DWORD *)(v29 - 8) = v28;
      v26[1] = v29;
    }
    inputa.m_aTb.m_storage = (hkTransformf *)&hkpMapPointsToSubShapeContactMgr::`vftable;
    inputa.m_shapeB.m_storage = (hkpConvexShape *)v5->m_contactMgr;
    LODWORD(inputa.m_transformA.m_storage) = 0x1FFFF;
    LODWORD(inputa.m_shapeA.m_storage) = 2;
    LOBYTE(inputa.m_collisionTolerance.m_storage) = 0;
    v5->m_contactMgr = (hkpContactMgr *)&inputa;
    hkpPredGskfAgent::processCollision((hkpPredGskfAgent *)&v5->vfptr, v8, v7, v6, (hkpProcessCollisionOutput *)v5, v14);
    v30 = LOBYTE(inputa.m_collisionTolerance.m_storage) == 0;
    v31 = (hkpContactMgr *)inputa.m_shapeB.m_storage;
    v5->m_contactMgr = (hkpContactMgr *)inputa.m_shapeB.m_storage;
    if ( v30 )
    {
      if ( !v5->m_manifold.m_numContactPoints || v5->m_processFunctionCalled.m_bool )
        goto $END;
      v32 = v7->m_parent;
      for ( i = v7; v32; v32 = v32->m_parent )
        i = v32;
      v34 = v8->m_parent;
      v35 = *(float *)&i[3].m_shapeKey;
      for ( j = v8; v34; v34 = v34->m_parent )
        j = v34;
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(fminf(*(float *)&j[3].m_shapeKey, v35) * 2.0) ^ _xmm[0]) <= v5->m_separatingNormal.m_quad.m128_f32[3] )
        goto $END;
    }
    hkpProcessCollisionOutputBackup::rollbackOutput(&v66, v8, v7, v14, v31);
    hkpConvexListAgent::switchToStreamMode(v5, v14->m_constraintOwner.m_storage);
$streamMode:
    v37 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v38 = (_QWORD *)v37[1];
    if ( (unsigned __int64)v38 < v37[3] )
    {
      *v38 = "StStream";
      v39 = __rdtsc();
      v40 = (signed __int64)(v38 + 2);
      *(_DWORD *)(v40 - 8) = v39;
      v37[1] = v40;
    }
    v41 = v5->m_inStreamModeCounter;
    v5->m_inStreamModeCounter = v41 - 1;
    if ( v41 >= 0 )
      goto LABEL_25;
    v5->m_inStreamModeCounter = 25;
    hkTransformf::setMulInverseMul(&v65, (hkTransformf *)v8->m_motion, (hkTransformf *)v7->m_motion);
    v42 = (hkpConvexShape *)v8->m_shape;
    inputa.m_collisionTolerance.m_storage = v6->m_tolerance.m_storage;
    inputa.m_shapeA.m_storage = v42;
    inputa.m_shapeB.m_storage = (hkpConvexShape *)v7->m_shape;
    inputa.m_aTb.m_storage = &v65;
    inputa.m_transformA.m_storage = (hkTransformf *)v8->m_motion;
    if ( hkpGsk::getClosestPoint(&result, &inputa, &v5->m_cache, &v5->m_separatingNormal, &pointOnBOut)->m_enum == HK_SUCCESS )
    {
      v5->m_manifold.m_contactPoints[1].m_allVerts = v5->m_separatingNormal.m_quad.m128_i32[3] ^ _xmm[0];
LABEL_25:
      v43 = (hkTransformf *)v7->m_motion;
      v44 = (hkTransformf *)v8->m_motion;
      v45 = 0;
      inputIn.m_linearTimInfo = (hkVector4f)v22.m_quad;
      inputIn.m_bodyA.m_storage = v8;
      inputIn.m_bodyB.m_storage = v7;
      inputIn.m_input.m_storage = v6;
      v46 = _mm_mul_ps(v22.m_quad, v22.m_quad);
      inputIn.m_overrideBodyA.m_storage = 0i64;
      v47 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
              _mm_shuffle_ps(v46, v46, 170));
      v48 = _mm_rsqrt_ps(v47);
      *(float *)&v5->m_manifold.m_contactPoints[1].m_allVerts = *(float *)&v5->m_manifold.m_contactPoints[1].m_allVerts
                                                              - COERCE_FLOAT(
                                                                  _mm_andnot_ps(
                                                                    _mm_cmpleps(v47, (__m128)0i64),
                                                                    _mm_mul_ps(
                                                                      _mm_mul_ps(
                                                                        _mm_sub_ps(
                                                                          (__m128)_xmm,
                                                                          _mm_mul_ps(_mm_mul_ps(v48, v47), v48)),
                                                                        _mm_mul_ps(*(__m128 *)_xmm, v48)),
                                                                      v47)));
      inputIn.m_contactMgr.m_storage = v5->m_contactMgr;
      hkTransformf::setMulInverseMul(&inputIn.m_aTb, v44, v43);
      v49 = *(signed int *)&v15[3].m_type.m_storage;
      v50 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v51 = (unsigned int *)v50->m_cur;
      v52 = (4 * v49 + 131) & 0xFFFFFF80;
      v53 = (char *)v51 + v52;
      if ( v52 > v50->m_slabSize || v53 > v50->m_end )
        v51 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v50, v52);
      else
        v50->m_cur = v53;
      v54 = 0i64;
      if ( (signed int)v49 > 0 )
      {
        do
          v51[v54++] = v45++;
        while ( v54 < v49 );
      }
      v51[v49] = -1;
      hkAgent1nMachine_Process(
        (hkpAgent1nTrack *)&v5->m_manifold,
        &inputIn,
        (hkpShapeContainer *)&v15[1].m_memSizeAndFlags,
        v51,
        v14);
      v55 = (4 * v49 + 131) & 0xFFFFFF80;
      v56 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v57 = (v55 + 15) & 0xFFFFFFF0;
      if ( v55 > v56->m_slabSize || (char *)v51 + v57 != v56->m_cur || v56->m_firstNonLifoEnd == v51 )
        hkLifoAllocator::slowBlockFree(v56, v51, v57);
      else
        v56->m_cur = v51;
      goto $END;
    }
    hkpConvexListAgent::switchToGskMode(v5, v14->m_constraintOwner.m_storage);
    hkpProcessCollisionOutputBackup::rollbackOutput(&v66, v8, v7, v14, v5->m_contactMgr);
  }
  if ( v5->m_manifold.m_numContactPoints )
    hkGskManifold_cleanup(&v5->m_manifold, v5->m_contactMgr, v14->m_constraintOwner.m_storage);
$END:
  v5->m_processFunctionCalled.m_bool = 1;
  v58 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v59 = (_QWORD *)v58[1];
  if ( (unsigned __int64)v59 < v58[3] )
  {
    *v59 = "lt";
    v60 = __rdtsc();
    v61 = (signed __int64)(v59 + 2);
    *(_DWORD *)(v61 - 8) = v60;
    v58[1] = v61;
  }
}


// File Line: 51
// RVA: 0xD27A00
void __fastcall hkpConvexListAgent::hkpConvexListAgent(
        hkpConvexListAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  hkpConvexShape *m_shape; // rdi
  hkpConvexShape *v10; // rbx
  hkTransformf aTb; // [rsp+20h] [rbp-48h] BYREF

  hkpGskfAgent::hkpGskfAgent(this, bodyA, bodyB, mgr);
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexListAgent::`vftable;
  this->m_dispatcher = input->m_dispatcher.m_storage;
  *(_WORD *)&this->m_inGskMode.m_bool = 1;
  m_shape = (hkpConvexShape *)bodyA->m_shape;
  v10 = (hkpConvexShape *)bodyB->m_shape;
  hkTransformf::setMulInverseMul(&aTb, (hkTransformf *)bodyA->m_motion, (hkTransformf *)bodyB->m_motion);
  hkpGskCache::init(&this->m_cache, m_shape, v10, &aTb);
  this->m_separatingNormal.m_quad.m128_i32[3] = -1082130432;
  this->m_timeOfSeparatingNormal = -1.0;
}

// File Line: 71
// RVA: 0xD27B80
hkpCollisionAgent *__fastcall hkpConvexListAgent::createConvexConvexListAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  int v8; // eax
  int v9; // eax
  _QWORD **Value; // rax
  hkpGskfAgent *v11; // rax
  _QWORD *p_vfptr; // rbx
  _QWORD **v13; // rax
  hkpShapeCollectionAgent *v14; // rax
  _QWORD **v15; // rax
  hkpConvexListAgent *v16; // rax
  __int64 v17; // rax
  _QWORD **v18; // rax
  hkpShapeCollectionAgent *v19; // rax
  hkpShapeCollectionAgent *v20; // r15

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
          Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v11 = (hkpGskfAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 144i64);
          p_vfptr = &v11->vfptr;
          if ( v11 )
          {
            hkpGskfAgent::hkpGskfAgent(v11, bodyA, bodyB, mgr);
            *p_vfptr = &hkpPredGskfAgent::`vftable;
            return (hkpCollisionAgent *)p_vfptr;
          }
        }
      }
      else
      {
        v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v14 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v13[11] + 8i64))(
                                           v13[11],
                                           104i64);
        p_vfptr = &v14->vfptr;
        if ( v14 )
        {
          hkpShapeCollectionAgent::hkpShapeCollectionAgent(v14, bodyB, bodyA, input, mgr);
          *p_vfptr = &hkpSymmetricAgent<hkpShapeCollectionAgent>::`vftable;
          return (hkpCollisionAgent *)p_vfptr;
        }
      }
    }
    else
    {
      v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v16 = (hkpConvexListAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v15[11] + 8i64))(v15[11], 160i64);
      if ( v16 )
      {
        hkpConvexListAgent::hkpConvexListAgent(v16, bodyA, bodyB, input, mgr);
        return (hkpCollisionAgent *)v17;
      }
    }
    return 0i64;
  }
  v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v19 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v18[11] + 8i64))(v18[11], 104i64);
  p_vfptr = 0i64;
  v20 = v19;
  if ( v19 )
  {
    hkpShapeCollectionAgent::hkpShapeCollectionAgent(v19, bodyB, bodyA, input, 0i64);
    p_vfptr = &v20->vfptr;
    v20->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpShapeCollectionAgent>::`vftable;
  }
  return (hkpCollisionAgent *)p_vfptr;
}

// File Line: 109
// RVA: 0xD27D10
hkpConvexListAgent *__fastcall hkpConvexListAgent::createConvexListConvexAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
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
  _QWORD **Value; // rax
  hkpShapeCollectionAgent *v19; // rax

  if ( !mgr )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v19 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                       Value[11],
                                       104i64);
    if ( v19 )
    {
      hkpShapeCollectionAgent::hkpShapeCollectionAgent(v19, bodyA, bodyB, input, 0i64);
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
    v17 = (hkpConvexListAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v16[11] + 8i64))(v16[11], 160i64);
    v12 = v17;
    if ( v17 )
    {
      hkpConvexListAgent::hkpConvexListAgent(v17, bodyB, bodyA, input, mgr);
      v12->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpConvexListAgent>::`vftable;
      return v12;
    }
    return 0i64;
  }
  v9 = v8 - 1;
  if ( !v9 )
  {
    v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v13[11] + 8i64))(v13[11], 104i64);
    if ( v14 )
    {
      hkpShapeCollectionAgent::hkpShapeCollectionAgent(v14, bodyA, bodyB, input, mgr);
      return (hkpConvexListAgent *)v15;
    }
    return 0i64;
  }
  if ( v9 != 1 )
    return 0i64;
  v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (hkpGskfAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v10[11] + 8i64))(v10[11], 144i64);
  v12 = (hkpConvexListAgent *)v11;
  if ( !v11 )
    return 0i64;
  hkpGskfAgent::hkpGskfAgent(v11, bodyA, bodyB, mgr);
  v12->vfptr = (hkBaseObjectVtbl *)&hkpPredGskfAgent::`vftable;
  return v12;
}

// File Line: 149
// RVA: 0xD27E80
void __fastcall hkpConvexListAgent::createConvexListConvexListAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _QWORD **Value; // rax
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
          v10 = ((__int64 (__fastcall *)(hkpConvexListFilter *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))input->m_convexListFilter.m_storage->vfptr[1].__first_virtual_table_function__)(
                  input->m_convexListFilter.m_storage,
                  bodyB,
                  bodyA,
                  input);
          if ( v10 )
          {
            v11 = v10 - 1;
            if ( v11 )
            {
              if ( v11 == 1 )
              {
                Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
                v13 = (hkpGskfAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                        Value[11],
                                        144i64);
                v14 = v13;
                if ( v13 )
                {
                  hkpGskfAgent::hkpGskfAgent(v13, bodyA, bodyB, mgr);
                  v14->vfptr = (hkBaseObjectVtbl *)&hkpPredGskfAgent::`vftable;
                }
              }
            }
            else
            {
              v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v16 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v15[11] + 8i64))(
                                                 v15[11],
                                                 104i64);
              v17 = v16;
              if ( v16 )
              {
                hkpShapeCollectionAgent::hkpShapeCollectionAgent(v16, bodyB, bodyA, input, mgr);
                v17->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpShapeCollectionAgent>::`vftable;
              }
            }
          }
          else
          {
            v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v19 = (hkpConvexListAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v18[11] + 8i64))(
                                          v18[11],
                                          160i64);
            if ( v19 )
              hkpConvexListAgent::hkpConvexListAgent(v19, bodyA, bodyB, input, mgr);
          }
        }
      }
      else
      {
        v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v21 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v20[11] + 8i64))(
                                           v20[11],
                                           104i64);
        if ( v21 )
          hkpShapeCollectionAgent::hkpShapeCollectionAgent(v21, bodyA, bodyB, input, mgr);
      }
    }
    else
    {
      v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v23 = (hkpConvexListAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v22[11] + 8i64))(v22[11], 160i64);
      v24 = v23;
      if ( v23 )
      {
        hkpConvexListAgent::hkpConvexListAgent(v23, bodyB, bodyA, input, mgr);
        v24->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpConvexListAgent>::`vftable;
      }
    }
  }
  else
  {
    v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v26 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v25[11] + 8i64))(v25[11], 104i64);
    if ( v26 )
      hkpShapeCollectionAgent::hkpShapeCollectionAgent(v26, bodyA, bodyB, input, 0i64);
  }
}

// File Line: 203
// RVA: 0xD26CC0
void __fastcall hkpConvexListAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpConvexListAgent::createConvexListConvexAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpConvexListAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpConvexListAgent>::staticGetClosestPoints;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpConvexListAgent>::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, CONVEX_LIST, CONVEX);
  f.m_createFunc = hkpConvexListAgent::createConvexConvexListAgent;
  f.m_getPenetrationsFunc = hkpConvexListAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpConvexListAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpConvexListAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, CONVEX, CONVEX_LIST);
  f.m_createFunc = hkpConvexListAgent::createConvexListConvexListAgent;
  f.m_getPenetrationsFunc = hkpConvexListAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpConvexListAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpConvexListAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, CONVEX_LIST, CONVEX_LIST);
}

// File Line: 238
// RVA: 0xD27890
void __fastcall hkpConvexListAgent::updateShapeCollectionFilter(
        hkpConvexListAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *listShapeBodyB,
        hkpCollisionInput *input,
        hkpConstraintOwner *constraintOwner)
{
  hkpContactMgr *m_contactMgr; // rax
  hkpShape *m_shape; // rcx
  hkpAgent1nMachine_VisitorInput vin; // [rsp+20h] [rbp-48h] BYREF

  if ( !this->m_inGskMode.m_bool )
  {
    m_contactMgr = this->m_contactMgr;
    m_shape = listShapeBodyB->m_shape;
    vin.m_bodyA = bodyA;
    vin.m_contactMgr = m_contactMgr;
    vin.m_collectionBodyB = listShapeBodyB;
    vin.m_constraintOwner = constraintOwner;
    vin.m_input = input;
    vin.m_containerShapeB = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))m_shape->vfptr[7].__vecDelDtor)(m_shape);
    hkAgent1nMachine_UpdateShapeCollectionFilter((hkpAgent1nTrack *)&this->m_manifold, &vin);
  }
}

// File Line: 258
// RVA: 0xD278F0
void __fastcall hkpConvexListAgent::invalidateTim(hkpConvexListAgent *this, hkpCollisionInput *input)
{
  if ( this->m_inGskMode.m_bool )
    hkpGskBaseAgent::invalidateTim(this, input);
  else
    hkAgent1nMachine_InvalidateTim((hkpAgent1nTrack *)&this->m_manifold, input);
}

// File Line: 270
// RVA: 0xD27910
void __fastcall hkpConvexListAgent::warpTime(
        hkpConvexListAgent *this,
        float oldTime,
        float newTime,
        hkpCollisionInput *input)
{
  if ( this->m_inGskMode.m_bool )
    hkpGskBaseAgent::warpTime(this, oldTime, newTime, input);
  else
    hkAgent1nMachine_WarpTime((hkpAgent1nTrack *)&this->m_manifold, oldTime, newTime, input);
}

// File Line: 281
// RVA: 0xD279A0
void __fastcall hkpConvexListAgent::removePoint(hkpConvexListAgent *this, unsigned __int16 idToRemove)
{
  if ( this->m_inGskMode.m_bool )
    hkpGskfAgent::removePoint(this, idToRemove);
}

// File Line: 289
// RVA: 0xD279C0
void __fastcall hkpConvexListAgent::commitPotential(hkpConvexListAgent *this, unsigned __int16 idToCommit)
{
  if ( this->m_inGskMode.m_bool )
    hkpGskfAgent::commitPotential(this, idToCommit);
}

// File Line: 297
// RVA: 0xD279E0
void __fastcall hkpConvexListAgent::createZombie(hkpConvexListAgent *this, unsigned __int16 idTobecomeZombie)
{
  if ( this->m_inGskMode.m_bool )
    hkpGskfAgent::createZombie(this, idTobecomeZombie);
}

// File Line: 307
// RVA: 0xD27560
void __fastcall hkpConvexListAgent::staticGetClosestPoints(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // rax
  unsigned __int64 v9; // rcx
  _QWORD *v10; // r8
  unsigned __int64 v11; // rax
  hkpCdPointCollectorVtbl *vfptr; // rax
  _QWORD *v13; // r8
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rax
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  hkpCdBodyPairCollector collectora; // [rsp+20h] [rbp-B8h] BYREF
  hkpCdPointCollector v21; // [rsp+30h] [rbp-A8h] BYREF
  __int128 v22; // [rsp+40h] [rbp-98h]
  __m128 v23; // [rsp+50h] [rbp-88h]
  __int64 v24; // [rsp+60h] [rbp-78h]
  __int128 v25[3]; // [rsp+90h] [rbp-48h] BYREF
  hkpCdBody *v26; // [rsp+C0h] [rbp-18h]
  hkpCdBody *v27; // [rsp+C8h] [rbp-10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = Value[1];
  v10 = Value;
  if ( v9 < Value[3] )
  {
    *(_QWORD *)v9 = "LtCvxList";
    *(_QWORD *)(v9 + 16) = "StcheckHull";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  collectora.m_earlyOut.m_bool = 0;
  collectora.vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpFlagCdBodyPairCollector::`vftable;
  hkpGskBaseAgent::staticGetPenetrations(bodyA, bodyB, input, &collectora);
  if ( collectora.m_earlyOut.m_bool )
    goto LABEL_7;
  v24 = 0i64;
  v21.vfptr = (hkpCdPointCollectorVtbl *)&hkpClosestCdPointCollector::`vftable;
  v21.m_earlyOutDistance = FLOAT_3_40282e38;
  v23 = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, (__m128)xmmword_141A712A0), 196);
  hkpGskBaseAgent::staticGetClosestPoints(bodyA, bodyB, input, &v21);
  if ( !v24 )
    goto LABEL_10;
  if ( v23.m128_f32[3] <= *(float *)&bodyB->m_shape[1].m_type.m_storage )
  {
LABEL_7:
    v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v14 = v13[1];
    if ( v14 < v13[3] )
    {
      *(_QWORD *)v14 = "Stchildren";
      v15 = __rdtsc();
      *(_DWORD *)(v14 + 8) = v15;
      v13[1] = v14 + 16;
    }
    hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetClosestPoints(bodyA, bodyB, input, collector);
  }
  else
  {
    vfptr = collector->vfptr;
    v26 = bodyA;
    v25[0] = v22;
    v25[1] = (__int128)v23;
    v25[2] = (__int128)v23;
    v27 = bodyB;
    vfptr->addCdPoint(collector, (hkpCdPoint *)v25);
  }
LABEL_10:
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "lt";
    v18 = __rdtsc();
    v19 = v17 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v16[1] = v19;
  }
}

// File Line: 344
// RVA: 0xD27540
void __fastcall hkpConvexListAgent::getClosestPoints(
        hkpConvexListAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  hkpConvexListAgent::staticGetClosestPoints(bodyA, bodyB, input, collector);
}

// File Line: 349
// RVA: 0xD27760
void __fastcall hkpConvexListAgent::staticGetPenetrations(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  _QWORD *Value; // rax
  unsigned __int64 v9; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  hkpCdBodyPairCollector collectora; // [rsp+20h] [rbp-18h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = Value[1];
  v10 = Value;
  if ( v9 < Value[3] )
  {
    *(_QWORD *)v9 = "LtCvxList";
    *(_QWORD *)(v9 + 16) = "StcheckHull";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  collectora.m_earlyOut.m_bool = 0;
  collectora.vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpFlagCdBodyPairCollector::`vftable;
  hkpGskBaseAgent::staticGetPenetrations(bodyA, bodyB, input, &collectora);
  if ( collectora.m_earlyOut.m_bool )
  {
    v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v13 = (_QWORD *)v12[1];
    if ( (unsigned __int64)v13 < v12[3] )
    {
      *v13 = "Stchildren";
      v14 = __rdtsc();
      v15 = v13 + 2;
      *((_DWORD *)v15 - 2) = v14;
      v12[1] = v15;
    }
    hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetPenetrations(bodyA, bodyB, input, collector);
  }
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "lt";
    v18 = __rdtsc();
    v19 = v17 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v16[1] = v19;
  }
}

// File Line: 364
// RVA: 0xD27740
void __fastcall hkpConvexListAgent::getPenetrations(
        hkpConvexListAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpConvexListAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}

// File Line: 370
// RVA: 0xD273D0
void __fastcall hkpConvexListAgent::staticLinearCast(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  _QWORD *Value; // rax
  unsigned __int64 v10; // r10
  _QWORD *v11; // r11
  unsigned __int64 v12; // rax
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx
  _QWORD *v17; // r8
  _QWORD *v18; // rcx
  unsigned __int64 v19; // rax
  _QWORD *v20; // rcx
  hkpCdPointCollector collectora; // [rsp+30h] [rbp-48h] BYREF
  char v22; // [rsp+40h] [rbp-38h]
  __m128 v23; // [rsp+60h] [rbp-18h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = Value[1];
  v11 = Value;
  if ( v10 < Value[3] )
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
  hkpIterativeLinearCastAgent::staticLinearCast(bodyA, bodyB, input, &collectora, &collectora);
  if ( v22 )
  {
    v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v14 = (_QWORD *)v13[1];
    if ( (unsigned __int64)v14 < v13[3] )
    {
      *v14 = "Stchild";
      v15 = __rdtsc();
      v16 = v14 + 2;
      *((_DWORD *)v16 - 2) = v15;
      v13[1] = v16;
    }
    hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticLinearCast(
      bodyA,
      bodyB,
      input,
      collector,
      startCollector);
  }
  v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v18 = (_QWORD *)v17[1];
  if ( (unsigned __int64)v18 < v17[3] )
  {
    *v18 = "lt";
    v19 = __rdtsc();
    v20 = v18 + 2;
    *((_DWORD *)v20 - 2) = v19;
    v17[1] = v20;
  }
}

// File Line: 385
// RVA: 0xD27390
void __fastcall hkpConvexListAgent::linearCast(
        hkpConvexListAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  hkpConvexListAgent::staticLinearCast(bodyA, bodyB, input, collector, startCollector);
}

// File Line: 391
// RVA: 0xD27B10
void __fastcall hkpConvexListAgent::switchToStreamMode(hkpConvexListAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpAgent1nTrack *p_m_manifold; // rbx

  p_m_manifold = (hkpAgent1nTrack *)&this->m_manifold;
  hkGskManifold_cleanup(&this->m_manifold, this->m_contactMgr, constraintOwner);
  this->m_inGskMode.m_bool = 0;
  if ( p_m_manifold )
  {
    p_m_manifold->m_sectors.m_data = 0i64;
    p_m_manifold->m_sectors.m_size = 0;
    p_m_manifold->m_sectors.m_capacityAndFlags = 0x80000000;
  }
  hkAgent1nMachine_Create(p_m_manifold);
  this->m_inStreamModeCounter = 25;
  this->m_manifold.m_contactPoints[1].m_allVerts = 0;
}

// File Line: 403
// RVA: 0xD27AC0
void __fastcall hkpConvexListAgent::switchToGskMode(hkpConvexListAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkAgent1nMachine_Destroy(
    (hkpAgent1nTrack *)&this->m_manifold,
    this->m_dispatcher,
    this->m_contactMgr,
    constraintOwner);
  *(_DWORD *)&this->m_manifold.m_numVertsA = 0;
  this->m_inGskMode.m_bool = 1;
}

// File Line: 412
// RVA: 0xD27930
void __fastcall hkpConvexListAgent::cleanup(hkpConvexListAgent *this, hkpConstraintOwner *constraintOwner)
{
  if ( this->m_inGskMode.m_bool )
    hkGskManifold_cleanup(&this->m_manifold, this->m_contactMgr, constraintOwner);
  else
    hkAgent1nMachine_Destroy(
      (hkpAgent1nTrack *)&this->m_manifold,
      this->m_dispatcher,
      this->m_contactMgr,
      constraintOwner);
  this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 428
// RVA: 0xD26DC0
void __fastcall hkpConvexListAgent::processCollision(
        hkpConvexListAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *output)
{
  _QWORD *Value; // r8
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rax
  __m128 *m_motion; // rcx
  __m128 *v13; // rax
  hkpProcessCollisionOutput *v14; // r14
  hkpShape *m_shape; // r13
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
  _QWORD *v29; // rcx
  bool v30; // zf
  hkpContactMgr *m_storage; // rdx
  hkpCdBody *m_parent; // rax
  hkpCdBody *i; // rcx
  hkpCdBody *v34; // rax
  float v35; // xmm0_4
  hkpCdBody *j; // rcx
  _QWORD *v37; // r8
  _QWORD *v38; // rcx
  unsigned __int64 v39; // rax
  _QWORD *v40; // rcx
  __int16 m_inStreamModeCounter; // cx
  hkpConvexShape *v42; // rax
  hkTransformf *v43; // r8
  hkTransformf *v44; // rdx
  unsigned int v45; // r15d
  __m128 v46; // xmm1
  __m128 v47; // xmm4
  __m128 v48; // xmm1
  __int64 v49; // rbx
  hkLifoAllocator *v50; // rax
  unsigned int *m_cur; // rsi
  int v52; // edx
  char *v53; // rcx
  __int64 v54; // rcx
  int v55; // ebx
  hkLifoAllocator *v56; // rax
  int v57; // r8d
  _QWORD *v58; // r8
  _QWORD *v59; // rcx
  unsigned __int64 v60; // rax
  _QWORD *v61; // rcx
  hkpGsk::GetClosesetPointInput inputa; // [rsp+30h] [rbp-D0h] BYREF
  hkVector4f pointOnBOut; // [rsp+60h] [rbp-A0h] BYREF
  hkpAgent3ProcessInput inputIn; // [rsp+70h] [rbp-90h] BYREF
  hkTransformf v65; // [rsp+100h] [rbp+0h] BYREF
  hkpProcessCollisionOutputBackup v66; // [rsp+140h] [rbp+40h] BYREF
  hkResult result; // [rsp+2260h] [rbp+2160h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = Value[1];
  if ( v10 < Value[3] )
  {
    *(_QWORD *)v10 = "LtCvxLst";
    *(_QWORD *)(v10 + 16) = "StTim";
    v11 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v11;
    Value[1] = v10 + 24;
  }
  m_motion = (__m128 *)bodyB->m_motion;
  v13 = (__m128 *)bodyA->m_motion;
  v14 = output;
  m_shape = bodyB->m_shape;
  v16 = v13[5];
  v17 = m_motion[5];
  v18 = _mm_shuffle_ps(
          (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
          (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
          0);
  v19 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 255), v18);
  v20 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 255), v18);
  v21 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v13[4], v16), v19), _mm_mul_ps(_mm_sub_ps(v17, m_motion[4]), v20));
  v22.m_quad = _mm_shuffle_ps(
                 v21,
                 _mm_unpackhi_ps(
                   v21,
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v13[9], v13[9], 255), v19),
                       _mm_shuffle_ps((__m128)v13[10].m128_u32[0], (__m128)v13[10].m128_u32[0], 0)),
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_shuffle_ps(m_motion[9], m_motion[9], 255), v20),
                       _mm_shuffle_ps((__m128)m_motion[10].m128_u32[0], (__m128)m_motion[10].m128_u32[0], 0)))),
                 196);
  hkpProcessCollisionOutputBackup::hkpProcessCollisionOutputBackup(&v66, output);
  if ( !this->m_inGskMode.m_bool )
    goto $streamMode;
  while ( 1 )
  {
    if ( input->m_tolerance.m_storage < this->m_separatingNormal.m_quad.m128_f32[3] )
    {
      v23 = _mm_mul_ps(this->m_separatingNormal.m_quad, v22.m_quad);
      v24 = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, v22.m_quad), 196);
      v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 78), v24);
      v25.m128_f32[0] = this->m_separatingNormal.m_quad.m128_f32[3]
                      - (float)(_mm_shuffle_ps(v25, v25, 177).m128_f32[0] + v25.m128_f32[0]);
      this->m_separatingNormal.m_quad.m128_i32[3] = v25.m128_i32[0];
      if ( v25.m128_f32[0] > input->m_tolerance.m_storage )
        break;
    }
    v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v27 = (_QWORD *)v26[1];
    if ( (unsigned __int64)v27 < v26[3] )
    {
      *v27 = "StGsk";
      v28 = __rdtsc();
      v29 = v27 + 2;
      *((_DWORD *)v29 - 2) = v28;
      v26[1] = v29;
    }
    inputa.m_aTb.m_storage = (hkTransformf *)&hkpMapPointsToSubShapeContactMgr::`vftable;
    inputa.m_shapeB.m_storage = (hkpConvexShape *)this->m_contactMgr;
    LODWORD(inputa.m_transformA.m_storage) = 0x1FFFF;
    LODWORD(inputa.m_shapeA.m_storage) = 2;
    LOBYTE(inputa.m_collisionTolerance.m_storage) = 0;
    this->m_contactMgr = (hkpContactMgr *)&inputa;
    hkpPredGskfAgent::processCollision(this, bodyA, bodyB, input, v14);
    v30 = LOBYTE(inputa.m_collisionTolerance.m_storage) == 0;
    m_storage = (hkpContactMgr *)inputa.m_shapeB.m_storage;
    this->m_contactMgr = (hkpContactMgr *)inputa.m_shapeB.m_storage;
    if ( v30 )
    {
      if ( !this->m_manifold.m_numContactPoints || this->m_processFunctionCalled.m_bool )
        goto $END;
      m_parent = bodyB->m_parent;
      for ( i = bodyB; m_parent; m_parent = m_parent->m_parent )
        i = m_parent;
      v34 = bodyA->m_parent;
      v35 = *(float *)&i[3].m_shapeKey;
      for ( j = bodyA; v34; v34 = v34->m_parent )
        j = v34;
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(fminf(*(float *)&j[3].m_shapeKey, v35) * 2.0) ^ _xmm[0]) <= this->m_separatingNormal.m_quad.m128_f32[3] )
        goto $END;
    }
    hkpProcessCollisionOutputBackup::rollbackOutput(&v66, bodyA, bodyB, v14, m_storage);
    hkpConvexListAgent::switchToStreamMode(this, v14->m_constraintOwner.m_storage);
$streamMode:
    v37 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v38 = (_QWORD *)v37[1];
    if ( (unsigned __int64)v38 < v37[3] )
    {
      *v38 = "StStream";
      v39 = __rdtsc();
      v40 = v38 + 2;
      *((_DWORD *)v40 - 2) = v39;
      v37[1] = v40;
    }
    m_inStreamModeCounter = this->m_inStreamModeCounter;
    this->m_inStreamModeCounter = m_inStreamModeCounter - 1;
    if ( m_inStreamModeCounter >= 0 )
      goto LABEL_25;
    this->m_inStreamModeCounter = 25;
    hkTransformf::setMulInverseMul(&v65, (hkTransformf *)bodyA->m_motion, (hkTransformf *)bodyB->m_motion);
    v42 = (hkpConvexShape *)bodyA->m_shape;
    inputa.m_collisionTolerance.m_storage = input->m_tolerance.m_storage;
    inputa.m_shapeA.m_storage = v42;
    inputa.m_shapeB.m_storage = (hkpConvexShape *)bodyB->m_shape;
    inputa.m_aTb.m_storage = &v65;
    inputa.m_transformA.m_storage = (hkTransformf *)bodyA->m_motion;
    if ( hkpGsk::getClosestPoint(&result, &inputa, &this->m_cache, &this->m_separatingNormal, &pointOnBOut)->m_enum == HK_SUCCESS )
    {
      this->m_manifold.m_contactPoints[1].m_allVerts = this->m_separatingNormal.m_quad.m128_i32[3] ^ _xmm[0];
LABEL_25:
      v43 = (hkTransformf *)bodyB->m_motion;
      v44 = (hkTransformf *)bodyA->m_motion;
      v45 = 0;
      inputIn.m_linearTimInfo = (hkVector4f)v22.m_quad;
      inputIn.m_bodyA.m_storage = bodyA;
      inputIn.m_bodyB.m_storage = bodyB;
      inputIn.m_input.m_storage = input;
      v46 = _mm_mul_ps(v22.m_quad, v22.m_quad);
      inputIn.m_overrideBodyA.m_storage = 0i64;
      v47 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
              _mm_shuffle_ps(v46, v46, 170));
      v48 = _mm_rsqrt_ps(v47);
      *(float *)&this->m_manifold.m_contactPoints[1].m_allVerts = *(float *)&this->m_manifold.m_contactPoints[1].m_allVerts
                                                                - _mm_andnot_ps(
                                                                    _mm_cmple_ps(v47, (__m128)0i64),
                                                                    _mm_mul_ps(
                                                                      _mm_mul_ps(
                                                                        _mm_sub_ps(
                                                                          (__m128)_xmm,
                                                                          _mm_mul_ps(_mm_mul_ps(v48, v47), v48)),
                                                                        _mm_mul_ps(*(__m128 *)_xmm, v48)),
                                                                      v47)).m128_f32[0];
      inputIn.m_contactMgr.m_storage = this->m_contactMgr;
      hkTransformf::setMulInverseMul(&inputIn.m_aTb, v44, v43);
      v49 = *(int *)&m_shape[3].m_type.m_storage;
      v50 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (unsigned int *)v50->m_cur;
      v52 = (4 * v49 + 131) & 0xFFFFFF80;
      v53 = (char *)m_cur + v52;
      if ( v52 > v50->m_slabSize || v53 > v50->m_end )
        m_cur = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v50, v52);
      else
        v50->m_cur = v53;
      v54 = 0i64;
      if ( (int)v49 > 0 )
      {
        do
          m_cur[v54++] = v45++;
        while ( v54 < v49 );
      }
      m_cur[v49] = -1;
      hkAgent1nMachine_Process(
        (hkpAgent1nTrack *)&this->m_manifold,
        &inputIn,
        (hkpShapeContainer *)&m_shape[1].m_memSizeAndFlags,
        m_cur,
        v14);
      v55 = (4 * v49 + 131) & 0xFFFFFF80;
      v56 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v57 = (v55 + 15) & 0xFFFFFFF0;
      if ( v55 > v56->m_slabSize || (char *)m_cur + v57 != v56->m_cur || v56->m_firstNonLifoEnd == m_cur )
        hkLifoAllocator::slowBlockFree(v56, (char *)m_cur, v57);
      else
        v56->m_cur = m_cur;
      goto $END;
    }
    hkpConvexListAgent::switchToGskMode(this, v14->m_constraintOwner.m_storage);
    hkpProcessCollisionOutputBackup::rollbackOutput(&v66, bodyA, bodyB, v14, this->m_contactMgr);
  }
  if ( this->m_manifold.m_numContactPoints )
    hkGskManifold_cleanup(&this->m_manifold, this->m_contactMgr, v14->m_constraintOwner.m_storage);
$END:
  this->m_processFunctionCalled.m_bool = 1;
  v58 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v59 = (_QWORD *)v58[1];
  if ( (unsigned __int64)v59 < v58[3] )
  {
    *v59 = "lt";
    v60 = __rdtsc();
    v61 = v59 + 2;
    *((_DWORD *)v61 - 2) = v60;
    v58[1] = v61;
  }
}


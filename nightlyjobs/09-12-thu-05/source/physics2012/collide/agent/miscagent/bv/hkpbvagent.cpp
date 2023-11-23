// File Line: 28
// RVA: 0xCF7550
void __fastcall hkpBvAgent::hkpBvAgent(
        hkpBvAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  bool v6; // zf
  hkpCollisionDispatcher *m_storage; // r10
  hkBaseObjectVtbl *vfptr; // rdx
  hkpShape *m_shape; // rax
  __int64 vecDelDtor_low; // rcx
  char (*m_agent2TypesPred)[35]; // rdx
  hkpCollisionAgent *v12; // rax
  hkBaseObjectVtbl *v13; // [rsp+20h] [rbp-28h] BYREF
  int v14; // [rsp+28h] [rbp-20h]
  const void *m_motion; // [rsp+30h] [rbp-18h]
  hkpCdBody *v16; // [rsp+38h] [rbp-10h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v16 = bodyA;
  this->m_contactMgr = mgr;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBvAgent::`vftable;
  v6 = input->m_createPredictiveAgents.m_storage == 0;
  m_storage = input->m_dispatcher.m_storage;
  m_motion = bodyA->m_motion;
  vfptr = bodyA->m_shape[1].vfptr;
  m_shape = bodyB->m_shape;
  v14 = -1;
  v13 = vfptr;
  vecDelDtor_low = LOBYTE(vfptr[1].__vecDelDtor);
  m_agent2TypesPred = m_storage->m_agent2TypesPred;
  if ( v6 )
    m_agent2TypesPred = m_storage->m_agent2Types;
  v12 = (hkpCollisionAgent *)((__int64 (__fastcall *)(hkBaseObjectVtbl **, hkpCdBody *, hkpCollisionInput *))m_storage->m_agent2Func[(unsigned __int8)m_agent2TypesPred[vecDelDtor_low][(unsigned __int8)m_shape->m_type.m_storage]].m_createFunc)(
                               &v13,
                               bodyB,
                               input);
  this->m_childAgent = 0i64;
  this->m_boundingVolumeAgent = v12;
}

// File Line: 40
// RVA: 0xCF64F0
void __fastcall hkpBvAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpBvAgent::createShapeBvAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpBvAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpBvAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpBvAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, ALL_SHAPE_TYPES, BV);
  f.m_createFunc = hkpBvAgent::createBvShapeAgent;
  f.m_getPenetrationsFunc = hkpBvAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvAgent::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  f.m_linearCastFunc = hkpBvAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, BV, ALL_SHAPE_TYPES);
}

// File Line: 67
// RVA: 0xCF7610
void __fastcall hkpBvAgent::createBvShapeAgent(
        hkpCdBody *A,
        hkpCdBody *B,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpBvAgent *v9; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpBvAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( v9 )
    hkpBvAgent::hkpBvAgent(v9, A, B, input, mgr);
}

// File Line: 74
// RVA: 0xCF7690
hkpBvAgent *__fastcall hkpBvAgent::createShapeBvAgent(
        hkpCdBody *A,
        hkpCdBody *B,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpBvAgent *result; // rax
  hkpBvAgent *v10; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpBvAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  v10 = result;
  if ( result )
  {
    hkpBvAgent::hkpBvAgent(result, B, A, input, mgr);
    v10->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpBvAgent>::`vftable;
    return v10;
  }
  return result;
}

// File Line: 81
// RVA: 0xCF7340
void __fastcall hkpBvAgent::cleanup(hkpBvAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpCollisionAgent *m_childAgent; // rcx

  this->m_boundingVolumeAgent->vfptr[3].__first_virtual_table_function__(this->m_boundingVolumeAgent);
  m_childAgent = this->m_childAgent;
  if ( m_childAgent )
  {
    ((void (__fastcall *)(hkpCollisionAgent *, hkpConstraintOwner *))m_childAgent->vfptr[3].__first_virtual_table_function__)(
      m_childAgent,
      constraintOwner);
    this->m_childAgent = 0i64;
  }
  this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 93
// RVA: 0xCF7450
void __fastcall hkpBvAgent::invalidateTim(hkpBvAgent *this, hkpCollisionInput *input)
{
  hkpCollisionAgent *m_childAgent; // rcx

  this->m_boundingVolumeAgent->vfptr[4].__first_virtual_table_function__(this->m_boundingVolumeAgent);
  m_childAgent = this->m_childAgent;
  if ( m_childAgent )
    ((void (__fastcall *)(hkpCollisionAgent *, hkpCollisionInput *))m_childAgent->vfptr[4].__first_virtual_table_function__)(
      m_childAgent,
      input);
}

// File Line: 102
// RVA: 0xCF7490
void __fastcall hkpBvAgent::warpTime(hkpBvAgent *this, float oldTime, float newTime, hkpCollisionInput *input)
{
  __int64 v6; // rdx
  __int64 v7; // r8
  hkpCollisionAgent *m_childAgent; // rcx

  ((void (__fastcall *)(hkpCollisionAgent *))this->m_boundingVolumeAgent->vfptr[5].__vecDelDtor)(this->m_boundingVolumeAgent);
  m_childAgent = this->m_childAgent;
  if ( m_childAgent )
    ((void (__fastcall *)(hkpCollisionAgent *, __int64, __int64, hkpCollisionInput *))m_childAgent->vfptr[5].__vecDelDtor)(
      m_childAgent,
      v6,
      v7,
      input);
}

// File Line: 111
// RVA: 0xCF74F0
void __fastcall hkpBvAgent::removePoint(hkpBvAgent *this, __int64 idToRemove)
{
  hkpCollisionAgent *m_childAgent; // rcx

  m_childAgent = this->m_childAgent;
  if ( m_childAgent )
    ((void (__fastcall *)(hkpCollisionAgent *, __int64))m_childAgent->vfptr[5].__first_virtual_table_function__)(
      m_childAgent,
      idToRemove);
}

// File Line: 119
// RVA: 0xCF7510
void __fastcall hkpBvAgent::commitPotential(hkpBvAgent *this, __int64 newId)
{
  hkpCollisionAgent *m_childAgent; // rcx

  m_childAgent = this->m_childAgent;
  if ( m_childAgent )
    m_childAgent->vfptr[6].__vecDelDtor(m_childAgent, newId);
}

// File Line: 127
// RVA: 0xCF7530
void __fastcall hkpBvAgent::createZombie(hkpBvAgent *this, __int64 idTobecomeZombie)
{
  hkpCollisionAgent *m_childAgent; // rcx

  m_childAgent = this->m_childAgent;
  if ( m_childAgent )
    ((void (__fastcall *)(hkpCollisionAgent *, __int64))m_childAgent->vfptr[6].__first_virtual_table_function__)(
      m_childAgent,
      idTobecomeZombie);
}

// File Line: 135
// RVA: 0xCF65A0
void __fastcall hkpBvAgent::processCollision(
        hkpBvAgent *this,
        hkpCdBody *bodyAin,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *result)
{
  _QWORD *Value; // rax
  unsigned __int64 v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  hkpShape *m_shape; // rbp
  hkpCollisionAgent *m_boundingVolumeAgent; // rcx
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  _QWORD *v18; // rcx
  bool v19; // zf
  __int64 v20; // rax
  hkpCollisionDispatcher *m_storage; // r10
  char (*m_agent2TypesPred)[35]; // rdx
  hkpCollisionAgent *m_childAgent; // rcx
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  _QWORD *v27; // rcx
  void **v28; // [rsp+30h] [rbp-38h] BYREF
  char v29; // [rsp+38h] [rbp-30h]
  __int64 vfptr; // [rsp+40h] [rbp-28h] BYREF
  int v31; // [rsp+48h] [rbp-20h]
  const void *m_motion; // [rsp+50h] [rbp-18h]
  hkpCdBody *v33; // [rsp+58h] [rbp-10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = Value[1];
  v11 = Value;
  if ( v10 < Value[3] )
  {
    *(_QWORD *)v10 = "LthkpBvAgent";
    *(_QWORD *)(v10 + 16) = "StcheckBvShape";
    v12 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v12;
    v11[1] = v10 + 24;
  }
  m_shape = bodyAin->m_shape;
  m_boundingVolumeAgent = this->m_boundingVolumeAgent;
  m_motion = bodyAin->m_motion;
  v33 = bodyAin;
  vfptr = (__int64)m_shape[1].vfptr;
  v31 = -1;
  v29 = 0;
  v28 = &hkpFlagCdBodyPairCollector::`vftable;
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpProcessCollisionInput *, void ***))m_boundingVolumeAgent->vfptr[1].__first_virtual_table_function__)(
    m_boundingVolumeAgent,
    &vfptr,
    bodyB,
    input,
    &v28);
  if ( v29 )
  {
    v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v16 = (_QWORD *)v15[1];
    if ( (unsigned __int64)v16 < v15[3] )
    {
      *v16 = "Stchild";
      v17 = __rdtsc();
      v18 = v16 + 2;
      *((_DWORD *)v18 - 2) = v17;
      v15[1] = v18;
    }
    v19 = this->m_childAgent == 0i64;
    v20 = *(_QWORD *)&m_shape[1].m_type.m_storage;
    v31 = 0;
    vfptr = v20;
    if ( v19 )
    {
      m_storage = input->m_dispatcher.m_storage;
      m_agent2TypesPred = input->m_dispatcher.m_storage->m_agent2TypesPred;
      if ( !input->m_createPredictiveAgents.m_storage )
        m_agent2TypesPred = m_storage->m_agent2Types;
      this->m_childAgent = m_storage->m_agent2Func[(unsigned __int8)m_agent2TypesPred[*(unsigned __int8 *)(v20 + 16)][(unsigned __int8)bodyB->m_shape->m_type.m_storage]].m_createFunc(
                             (hkpCdBody *)&vfptr,
                             bodyB,
                             input,
                             this->m_contactMgr);
    }
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))this->m_childAgent->vfptr[3].__vecDelDtor)(
      this->m_childAgent,
      &vfptr,
      bodyB,
      input,
      result);
  }
  else
  {
    m_childAgent = this->m_childAgent;
    if ( m_childAgent )
    {
      ((void (__fastcall *)(hkpCollisionAgent *, hkpConstraintOwner *))m_childAgent->vfptr[3].__first_virtual_table_function__)(
        m_childAgent,
        result->m_constraintOwner.m_storage);
      this->m_childAgent = 0i64;
    }
  }
  v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v25 = (_QWORD *)v24[1];
  if ( (unsigned __int64)v25 < v24[3] )
  {
    *v25 = "lt";
    v26 = __rdtsc();
    v27 = v25 + 2;
    *((_DWORD *)v27 - 2) = v26;
    v24[1] = v27;
  }
}

// File Line: 170
// RVA: 0xCF67B0
void __fastcall hkpBvAgent::linearCast(
        hkpBvAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *pointDetails,
        hkpCdPointCollector *startCollector)
{
  _QWORD *Value; // rax
  unsigned __int64 v11; // r10
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  hkpShape *m_shape; // rbp
  hkpCollisionAgent *m_boundingVolumeAgent; // rcx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  bool v20; // zf
  __int64 v21; // rax
  hkpCollisionDispatcher *m_storage; // r10
  char (*m_agent2TypesPred)[35]; // rdx
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  _QWORD *v27; // rcx
  __int64 vfptr; // [rsp+30h] [rbp-68h] BYREF
  int v29; // [rsp+38h] [rbp-60h]
  const void *m_motion; // [rsp+40h] [rbp-58h]
  hkpCdBody *v31; // [rsp+48h] [rbp-50h]
  void **v32; // [rsp+50h] [rbp-48h] BYREF
  float v33; // [rsp+58h] [rbp-40h]
  char v34; // [rsp+60h] [rbp-38h]
  __m128 v35; // [rsp+80h] [rbp-18h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = Value[1];
  v12 = Value;
  if ( v11 < Value[3] )
  {
    *(_QWORD *)v11 = "LthkpBvAgent";
    *(_QWORD *)(v11 + 16) = "StcheckBvShape";
    v13 = __rdtsc();
    *(_DWORD *)(v11 + 8) = v13;
    v12[1] = v11 + 24;
  }
  m_shape = bodyA->m_shape;
  m_boundingVolumeAgent = this->m_boundingVolumeAgent;
  m_motion = bodyA->m_motion;
  v31 = bodyA;
  vfptr = (__int64)m_shape[1].vfptr;
  v33 = FLOAT_3_40282e38;
  v35 = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, (__m128)xmmword_141A712A0), 196);
  v29 = -1;
  v32 = &hkpSimpleClosestContactCollector::`vftable;
  v34 = 0;
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpLinearCastCollisionInput *, void ***, void ***))m_boundingVolumeAgent->vfptr[2].__first_virtual_table_function__)(
    m_boundingVolumeAgent,
    &vfptr,
    bodyB,
    input,
    &v32,
    &v32);
  if ( v34 )
  {
    v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v17 = (_QWORD *)v16[1];
    if ( (unsigned __int64)v17 < v16[3] )
    {
      *v17 = "Stchild";
      v18 = __rdtsc();
      v19 = v17 + 2;
      *((_DWORD *)v19 - 2) = v18;
      v16[1] = v19;
    }
    v20 = this->m_childAgent == 0i64;
    v21 = *(_QWORD *)&m_shape[1].m_type.m_storage;
    v29 = 0;
    vfptr = v21;
    if ( v20 )
    {
      m_storage = input->m_dispatcher.m_storage;
      m_agent2TypesPred = input->m_dispatcher.m_storage->m_agent2TypesPred;
      if ( !input->m_createPredictiveAgents.m_storage )
        m_agent2TypesPred = m_storage->m_agent2Types;
      this->m_childAgent = m_storage->m_agent2Func[(unsigned __int8)m_agent2TypesPred[*(unsigned __int8 *)(v21 + 16)][(unsigned __int8)bodyB->m_shape->m_type.m_storage]].m_createFunc(
                             (hkpCdBody *)&vfptr,
                             bodyB,
                             input,
                             this->m_contactMgr);
    }
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpLinearCastCollisionInput *, hkpCdPointCollector *, hkpCdPointCollector *))this->m_childAgent->vfptr[2].__first_virtual_table_function__)(
      this->m_childAgent,
      &vfptr,
      bodyB,
      input,
      pointDetails,
      startCollector);
  }
  v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v25 = (_QWORD *)v24[1];
  if ( (unsigned __int64)v25 < v24[3] )
  {
    *v25 = "lt";
    v26 = __rdtsc();
    v27 = v25 + 2;
    *((_DWORD *)v27 - 2) = v26;
    v24[1] = v27;
  }
}

// File Line: 202
// RVA: 0xCF69E0
void __fastcall hkpBvAgent::staticLinearCast(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *pointDetails,
        hkpCdPointCollector *startCollector)
{
  _QWORD *Value; // rax
  unsigned __int64 v10; // r10
  _QWORD *v11; // r11
  unsigned __int64 v12; // rax
  hkpCollisionDispatcher *m_storage; // r8
  hkpShape *m_shape; // r14
  hkpShape *v15; // rax
  __int64 vfptr; // rdx
  __int64 v17; // rsi
  void (__fastcall *m_linearCastFunc)(hkpCdBody *, hkpCdBody *, hkpLinearCastCollisionInput *, hkpCdPointCollector *, hkpCdPointCollector *); // rax
  _QWORD *v19; // r8
  _QWORD *v20; // rcx
  unsigned __int64 v21; // rax
  _QWORD *v22; // rcx
  __int64 v23; // rax
  hkpCollisionDispatcher *v24; // r11
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  _QWORD *v28; // rcx
  __int64 v29; // [rsp+30h] [rbp-68h] BYREF
  int v30; // [rsp+38h] [rbp-60h]
  const void *m_motion; // [rsp+40h] [rbp-58h]
  hkpCdBody *v32; // [rsp+48h] [rbp-50h]
  void **v33; // [rsp+50h] [rbp-48h] BYREF
  float v34; // [rsp+58h] [rbp-40h]
  char v35; // [rsp+60h] [rbp-38h]
  __m128 v36; // [rsp+80h] [rbp-18h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = Value[1];
  v11 = Value;
  if ( v10 < Value[3] )
  {
    *(_QWORD *)v10 = "LthkpBvAgent";
    *(_QWORD *)(v10 + 16) = "StcheckBvShape";
    v12 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v12;
    v11[1] = v10 + 24;
  }
  m_storage = input->m_dispatcher.m_storage;
  m_shape = bodyA->m_shape;
  m_motion = bodyA->m_motion;
  v15 = bodyB->m_shape;
  v32 = bodyA;
  vfptr = (__int64)m_shape[1].vfptr;
  v30 = -1;
  v29 = vfptr;
  v17 = (unsigned __int8)v15->m_type.m_storage;
  m_linearCastFunc = m_storage->m_agent2Func[(unsigned __int8)m_storage->m_agent2Types[*(unsigned __int8 *)(vfptr + 16)][v17]].m_linearCastFunc;
  v34 = FLOAT_3_40282e38;
  v36 = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, (__m128)xmmword_141A712A0), 196);
  v33 = &hkpSimpleClosestContactCollector::`vftable;
  v35 = 0;
  m_linearCastFunc((hkpCdBody *)&v29, bodyB, input, (hkpCdPointCollector *)&v33, (hkpCdPointCollector *)&v33);
  if ( v35 )
  {
    v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v20 = (_QWORD *)v19[1];
    if ( (unsigned __int64)v20 < v19[3] )
    {
      *v20 = "Stchild";
      v21 = __rdtsc();
      v22 = v20 + 2;
      *((_DWORD *)v22 - 2) = v21;
      v19[1] = v22;
    }
    v23 = *(_QWORD *)&m_shape[1].m_type.m_storage;
    v24 = input->m_dispatcher.m_storage;
    v30 = 0;
    v29 = v23;
    v24->m_agent2Func[(unsigned __int8)v24->m_agent2Types[*(unsigned __int8 *)(v23 + 16)][v17]].m_linearCastFunc(
      (hkpCdBody *)&v29,
      bodyB,
      input,
      pointDetails,
      startCollector);
  }
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "lt";
    v27 = __rdtsc();
    v28 = v26 + 2;
    *((_DWORD *)v28 - 2) = v27;
    v25[1] = v28;
  }
}

// File Line: 234
// RVA: 0xCF6BE0
void __fastcall hkpBvAgent::getClosestPoints(
        hkpBvAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // rax
  unsigned __int64 v10; // r10
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  hkpShape *m_shape; // rbp
  hkpCollisionAgent *m_boundingVolumeAgent; // rcx
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  _QWORD *v18; // rcx
  bool v19; // zf
  __int64 v20; // rax
  hkpCollisionDispatcher *m_storage; // r10
  char (*m_agent2TypesPred)[35]; // rdx
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  _QWORD *v26; // rcx
  void **v27; // [rsp+30h] [rbp-38h] BYREF
  char v28; // [rsp+38h] [rbp-30h]
  __int64 vfptr; // [rsp+40h] [rbp-28h] BYREF
  int v30; // [rsp+48h] [rbp-20h]
  const void *m_motion; // [rsp+50h] [rbp-18h]
  hkpCdBody *v32; // [rsp+58h] [rbp-10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = Value[1];
  v11 = Value;
  if ( v10 < Value[3] )
  {
    *(_QWORD *)v10 = "LthkpBvAgent";
    *(_QWORD *)(v10 + 16) = "StcheckBvShape";
    v12 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v12;
    v11[1] = v10 + 24;
  }
  m_shape = bodyA->m_shape;
  m_boundingVolumeAgent = this->m_boundingVolumeAgent;
  m_motion = bodyA->m_motion;
  v32 = bodyA;
  vfptr = (__int64)m_shape[1].vfptr;
  v30 = -1;
  v28 = 0;
  v27 = &hkpFlagCdBodyPairCollector::`vftable;
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, void ***))m_boundingVolumeAgent->vfptr[1].__first_virtual_table_function__)(
    m_boundingVolumeAgent,
    &vfptr,
    bodyB,
    input,
    &v27);
  if ( v28 )
  {
    v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v16 = (_QWORD *)v15[1];
    if ( (unsigned __int64)v16 < v15[3] )
    {
      *v16 = "Stchild";
      v17 = __rdtsc();
      v18 = v16 + 2;
      *((_DWORD *)v18 - 2) = v17;
      v15[1] = v18;
    }
    v19 = this->m_childAgent == 0i64;
    v20 = *(_QWORD *)&m_shape[1].m_type.m_storage;
    v30 = 0;
    vfptr = v20;
    if ( v19 )
    {
      m_storage = input->m_dispatcher.m_storage;
      m_agent2TypesPred = input->m_dispatcher.m_storage->m_agent2TypesPred;
      if ( !input->m_createPredictiveAgents.m_storage )
        m_agent2TypesPred = m_storage->m_agent2Types;
      this->m_childAgent = m_storage->m_agent2Func[(unsigned __int8)m_agent2TypesPred[*(unsigned __int8 *)(v20 + 16)][(unsigned __int8)bodyB->m_shape->m_type.m_storage]].m_createFunc(
                             (hkpCdBody *)&vfptr,
                             bodyB,
                             input,
                             this->m_contactMgr);
    }
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpCdPointCollector *))this->m_childAgent->vfptr[2].__vecDelDtor)(
      this->m_childAgent,
      &vfptr,
      bodyB,
      input,
      collector);
  }
  v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v24 = (_QWORD *)v23[1];
  if ( (unsigned __int64)v24 < v23[3] )
  {
    *v24 = "lt";
    v25 = __rdtsc();
    v26 = v24 + 2;
    *((_DWORD *)v26 - 2) = v25;
    v23[1] = v26;
  }
}

// File Line: 269
// RVA: 0xCF6DD0
void __fastcall hkpBvAgent::staticGetClosestPoints(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // rax
  unsigned __int64 v9; // r10
  _QWORD *v10; // r11
  unsigned __int64 v11; // rax
  hkpCollisionDispatcher *m_storage; // r8
  hkpShape *m_shape; // rbp
  hkpShape *v14; // rax
  __int64 vfptr; // rdx
  __int64 v16; // rsi
  void (__fastcall *m_getPenetrationsFunc)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpCdBodyPairCollector *); // rax
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  _QWORD *v21; // rcx
  __int64 v22; // rax
  hkpCollisionDispatcher *v23; // r11
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  _QWORD *v27; // rcx
  void **v28; // [rsp+20h] [rbp-38h] BYREF
  char v29; // [rsp+28h] [rbp-30h]
  __int64 v30; // [rsp+30h] [rbp-28h] BYREF
  int v31; // [rsp+38h] [rbp-20h]
  const void *m_motion; // [rsp+40h] [rbp-18h]
  hkpCdBody *v33; // [rsp+48h] [rbp-10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = Value[1];
  v10 = Value;
  if ( v9 < Value[3] )
  {
    *(_QWORD *)v9 = "LthkpBvAgent";
    *(_QWORD *)(v9 + 16) = "StcheckBvShape";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  m_storage = input->m_dispatcher.m_storage;
  m_shape = bodyA->m_shape;
  m_motion = bodyA->m_motion;
  v14 = bodyB->m_shape;
  v33 = bodyA;
  vfptr = (__int64)m_shape[1].vfptr;
  v31 = -1;
  v30 = vfptr;
  v16 = (unsigned __int8)v14->m_type.m_storage;
  m_getPenetrationsFunc = m_storage->m_agent2Func[(unsigned __int8)m_storage->m_agent2Types[*(unsigned __int8 *)(vfptr + 16)][v16]].m_getPenetrationsFunc;
  v28 = &hkpFlagCdBodyPairCollector::`vftable;
  v29 = 0;
  m_getPenetrationsFunc((hkpCdBody *)&v30, bodyB, input, (hkpCdBodyPairCollector *)&v28);
  if ( v29 )
  {
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = (_QWORD *)v18[1];
    if ( (unsigned __int64)v19 < v18[3] )
    {
      *v19 = "Stchild";
      v20 = __rdtsc();
      v21 = v19 + 2;
      *((_DWORD *)v21 - 2) = v20;
      v18[1] = v21;
    }
    v22 = *(_QWORD *)&m_shape[1].m_type.m_storage;
    v23 = input->m_dispatcher.m_storage;
    v31 = 0;
    v30 = v22;
    v23->m_agent2Func[(unsigned __int8)v23->m_agent2Types[*(unsigned __int8 *)(v22 + 16)][v16]].m_getClosestPointFunc(
      (hkpCdBody *)&v30,
      bodyB,
      input,
      collector);
  }
  v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v25 = (_QWORD *)v24[1];
  if ( (unsigned __int64)v25 < v24[3] )
  {
    *v25 = "lt";
    v26 = __rdtsc();
    v27 = v25 + 2;
    *((_DWORD *)v27 - 2) = v26;
    v24[1] = v27;
  }
}

// File Line: 303
// RVA: 0xCF6F90
void __fastcall hkpBvAgent::getPenetrations(
        hkpBvAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  _QWORD *Value; // rax
  unsigned __int64 v10; // r10
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  hkpShape *m_shape; // rbp
  hkpCollisionAgent *m_boundingVolumeAgent; // rcx
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  _QWORD *v18; // rcx
  bool v19; // zf
  __int64 v20; // rax
  hkpCollisionDispatcher *m_storage; // r10
  char (*m_agent2TypesPred)[35]; // rdx
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  _QWORD *v26; // rcx
  void **v27; // [rsp+30h] [rbp-38h] BYREF
  char v28; // [rsp+38h] [rbp-30h]
  __int64 vfptr; // [rsp+40h] [rbp-28h] BYREF
  int v30; // [rsp+48h] [rbp-20h]
  const void *m_motion; // [rsp+50h] [rbp-18h]
  hkpCdBody *v32; // [rsp+58h] [rbp-10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = Value[1];
  v11 = Value;
  if ( v10 < Value[3] )
  {
    *(_QWORD *)v10 = "LthkpBvAgent";
    *(_QWORD *)(v10 + 16) = "StcheckBvShape";
    v12 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v12;
    v11[1] = v10 + 24;
  }
  m_shape = bodyA->m_shape;
  m_boundingVolumeAgent = this->m_boundingVolumeAgent;
  m_motion = bodyA->m_motion;
  v32 = bodyA;
  vfptr = (__int64)m_shape[1].vfptr;
  v30 = -1;
  v28 = 0;
  v27 = &hkpFlagCdBodyPairCollector::`vftable;
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, void ***))m_boundingVolumeAgent->vfptr[1].__first_virtual_table_function__)(
    m_boundingVolumeAgent,
    &vfptr,
    bodyB,
    input,
    &v27);
  if ( v28 )
  {
    v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v16 = (_QWORD *)v15[1];
    if ( (unsigned __int64)v16 < v15[3] )
    {
      *v16 = "Stchild";
      v17 = __rdtsc();
      v18 = v16 + 2;
      *((_DWORD *)v18 - 2) = v17;
      v15[1] = v18;
    }
    v19 = this->m_childAgent == 0i64;
    v20 = *(_QWORD *)&m_shape[1].m_type.m_storage;
    v30 = 0;
    vfptr = v20;
    if ( v19 )
    {
      m_storage = input->m_dispatcher.m_storage;
      m_agent2TypesPred = input->m_dispatcher.m_storage->m_agent2TypesPred;
      if ( !input->m_createPredictiveAgents.m_storage )
        m_agent2TypesPred = m_storage->m_agent2Types;
      this->m_childAgent = m_storage->m_agent2Func[(unsigned __int8)m_agent2TypesPred[*(unsigned __int8 *)(v20 + 16)][(unsigned __int8)bodyB->m_shape->m_type.m_storage]].m_createFunc(
                             (hkpCdBody *)&vfptr,
                             bodyB,
                             input,
                             this->m_contactMgr);
    }
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpCdBodyPairCollector *))this->m_childAgent->vfptr[1].__first_virtual_table_function__)(
      this->m_childAgent,
      &vfptr,
      bodyB,
      input,
      collector);
  }
  v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v24 = (_QWORD *)v23[1];
  if ( (unsigned __int64)v24 < v23[3] )
  {
    *v24 = "lt";
    v25 = __rdtsc();
    v26 = v24 + 2;
    *((_DWORD *)v26 - 2) = v25;
    v23[1] = v26;
  }
}

// File Line: 329
// RVA: 0xCF7180
void __fastcall hkpBvAgent::staticGetPenetrations(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  _QWORD *Value; // rax
  unsigned __int64 v9; // r10
  _QWORD *v10; // r11
  unsigned __int64 v11; // rax
  hkpCollisionDispatcher *m_storage; // r8
  hkpShape *m_shape; // rbp
  hkpShape *v14; // rax
  __int64 vfptr; // rdx
  __int64 v16; // rsi
  void (__fastcall *m_getPenetrationsFunc)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpCdBodyPairCollector *); // rax
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  _QWORD *v21; // rcx
  __int64 v22; // rax
  hkpCollisionDispatcher *v23; // r11
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  _QWORD *v27; // rcx
  void **v28; // [rsp+20h] [rbp-38h] BYREF
  char v29; // [rsp+28h] [rbp-30h]
  __int64 v30; // [rsp+30h] [rbp-28h] BYREF
  int v31; // [rsp+38h] [rbp-20h]
  const void *m_motion; // [rsp+40h] [rbp-18h]
  hkpCdBody *v33; // [rsp+48h] [rbp-10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = Value[1];
  v10 = Value;
  if ( v9 < Value[3] )
  {
    *(_QWORD *)v9 = "LthkpBvAgent";
    *(_QWORD *)(v9 + 16) = "StcheckBvShape";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  m_storage = input->m_dispatcher.m_storage;
  m_shape = bodyA->m_shape;
  m_motion = bodyA->m_motion;
  v14 = bodyB->m_shape;
  v33 = bodyA;
  vfptr = (__int64)m_shape[1].vfptr;
  v31 = -1;
  v30 = vfptr;
  v16 = (unsigned __int8)v14->m_type.m_storage;
  m_getPenetrationsFunc = m_storage->m_agent2Func[(unsigned __int8)m_storage->m_agent2Types[*(unsigned __int8 *)(vfptr + 16)][v16]].m_getPenetrationsFunc;
  v28 = &hkpFlagCdBodyPairCollector::`vftable;
  v29 = 0;
  m_getPenetrationsFunc((hkpCdBody *)&v30, bodyB, input, (hkpCdBodyPairCollector *)&v28);
  if ( v29 )
  {
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = (_QWORD *)v18[1];
    if ( (unsigned __int64)v19 < v18[3] )
    {
      *v19 = "Stchild";
      v20 = __rdtsc();
      v21 = v19 + 2;
      *((_DWORD *)v21 - 2) = v20;
      v18[1] = v21;
    }
    v22 = *(_QWORD *)&m_shape[1].m_type.m_storage;
    v23 = input->m_dispatcher.m_storage;
    v31 = 0;
    v30 = v22;
    v23->m_agent2Func[(unsigned __int8)v23->m_agent2Types[*(unsigned __int8 *)(v22 + 16)][v16]].m_getPenetrationsFunc(
      (hkpCdBody *)&v30,
      bodyB,
      input,
      collector);
  }
  v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v25 = (_QWORD *)v24[1];
  if ( (unsigned __int64)v25 < v24[3] )
  {
    *v25 = "lt";
    v26 = __rdtsc();
    v27 = v25 + 2;
    *((_DWORD *)v27 - 2) = v26;
    v24[1] = v27;
  }
}

// File Line: 359
// RVA: 0xCF73A0
void __fastcall hkpBvAgent::updateShapeCollectionFilter(
        hkpBvAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpConstraintOwner *constraintOwner)
{
  const void *m_motion; // rax
  hkpShape *m_shape; // rbp
  hkpCollisionAgent *m_boundingVolumeAgent; // rcx
  hkpCollisionAgent *m_childAgent; // rcx
  __int64 v12; // rax
  __int64 vfptr; // [rsp+30h] [rbp-28h] BYREF
  int v14; // [rsp+38h] [rbp-20h]
  const void *v15; // [rsp+40h] [rbp-18h]
  hkpCdBody *v16; // [rsp+48h] [rbp-10h]

  m_motion = bodyA->m_motion;
  m_shape = bodyA->m_shape;
  v16 = bodyA;
  v15 = m_motion;
  vfptr = (__int64)m_shape[1].vfptr;
  m_boundingVolumeAgent = this->m_boundingVolumeAgent;
  v14 = -1;
  m_boundingVolumeAgent->vfptr[4].__vecDelDtor(m_boundingVolumeAgent, (unsigned int)&vfptr);
  m_childAgent = this->m_childAgent;
  if ( m_childAgent )
  {
    v12 = *(_QWORD *)&m_shape[1].m_type.m_storage;
    v14 = 0;
    vfptr = v12;
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpConstraintOwner *))m_childAgent->vfptr[4].__vecDelDtor)(
      m_childAgent,
      &vfptr,
      bodyB,
      input,
      constraintOwner);
  }
}


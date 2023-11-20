// File Line: 28
// RVA: 0xCF7550
void __fastcall hkpBvAgent::hkpBvAgent(hkpBvAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpBvAgent *v5; // rbx
  bool v6; // zf
  hkpCollisionDispatcher *v7; // r10
  hkBaseObjectVtbl *v8; // rdx
  hkpShape *v9; // rax
  __int64 v10; // rcx
  signed __int64 v11; // rdx
  __int64 v12; // rax
  hkBaseObjectVtbl *v13; // [rsp+20h] [rbp-28h]
  int v14; // [rsp+28h] [rbp-20h]
  const void *v15; // [rsp+30h] [rbp-18h]
  hkpCdBody *v16; // [rsp+38h] [rbp-10h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v16 = bodyA;
  v5 = this;
  this->m_contactMgr = mgr;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBvAgent::`vftable';
  v6 = input->m_createPredictiveAgents.m_storage == 0;
  v7 = input->m_dispatcher.m_storage;
  v15 = bodyA->m_motion;
  v8 = bodyA->m_shape[1].vfptr;
  v9 = bodyB->m_shape;
  v14 = -1;
  v13 = v8;
  v10 = LOBYTE(v8[1].__vecDelDtor);
  v11 = (signed __int64)v7->m_agent2TypesPred;
  if ( v6 )
    v11 = (signed __int64)v7->m_agent2Types;
  v12 = ((__int64 (__fastcall *)(hkBaseObjectVtbl **, hkpCdBody *, hkpCollisionInput *))v7->m_agent2Func[*(unsigned __int8 *)((unsigned __int8)v9->m_type.m_storage + v11 + 35 * v10)].m_createFunc)(
          &v13,
          bodyB,
          input);
  v5->m_childAgent = 0i64;
  v5->m_boundingVolumeAgent = (hkpCollisionAgent *)v12;
}

// File Line: 40
// RVA: 0xCF64F0
void __fastcall hkpBvAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  f.m_createFunc = hkpBvAgent::createShapeBvAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpBvAgent>::staticGetPenetrations;
  v1 = dispatcher;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpBvAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpBvAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, ALL_SHAPE_TYPES, BV);
  f.m_createFunc = hkpBvAgent::createBvShapeAgent;
  f.m_getPenetrationsFunc = hkpBvAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvAgent::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  f.m_linearCastFunc = hkpBvAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, BV, ALL_SHAPE_TYPES);
}

// File Line: 67
// RVA: 0xCF7610
void __fastcall hkpBvAgent::createBvShapeAgent(hkpCdBody *A, hkpCdBody *B, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCdBody *v4; // rbp
  hkpContactMgr *v5; // rbx
  hkpCollisionInput *v6; // rdi
  hkpCdBody *v7; // rsi
  _QWORD **v8; // rax
  hkpBvAgent *v9; // rax

  v4 = A;
  v5 = mgr;
  v6 = input;
  v7 = B;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpBvAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 40i64);
  if ( v9 )
    hkpBvAgent::hkpBvAgent(v9, v4, v7, v6, v5);
}

// File Line: 74
// RVA: 0xCF7690
hkpBvAgent *__fastcall hkpBvAgent::createShapeBvAgent(hkpCdBody *A, hkpCdBody *B, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCdBody *v4; // r14
  hkpContactMgr *v5; // rdi
  hkpCollisionInput *v6; // rsi
  hkpCdBody *v7; // rbp
  _QWORD **v8; // rax
  hkpBvAgent *result; // rax
  hkpCollisionAgent *v10; // rbx

  v4 = A;
  v5 = mgr;
  v6 = input;
  v7 = B;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpBvAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 40i64);
  v10 = (hkpCollisionAgent *)&result->vfptr;
  if ( result )
  {
    hkpBvAgent::hkpBvAgent(result, v7, v4, v6, v5);
    v10->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpBvAgent>::`vftable';
    result = (hkpBvAgent *)v10;
  }
  return result;
}

// File Line: 81
// RVA: 0xCF7340
void __fastcall hkpBvAgent::cleanup(hkpBvAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpBvAgent *v2; // rbx
  hkpConstraintOwner *v3; // rdi
  hkpCollisionAgent *v4; // rcx

  v2 = this;
  v3 = constraintOwner;
  ((void (*)(void))this->m_boundingVolumeAgent->vfptr[3].__first_virtual_table_function__)();
  v4 = v2->m_childAgent;
  if ( v4 )
  {
    ((void (__fastcall *)(hkpCollisionAgent *, hkpConstraintOwner *))v4->vfptr[3].__first_virtual_table_function__)(
      v4,
      v3);
    v2->m_childAgent = 0i64;
  }
  v2->vfptr->__vecDelDtor((hkBaseObject *)&v2->vfptr, 1u);
}

// File Line: 93
// RVA: 0xCF7450
void __fastcall hkpBvAgent::invalidateTim(hkpBvAgent *this, hkpCollisionInput *input)
{
  hkpBvAgent *v2; // rbx
  hkpCollisionInput *v3; // rdi
  hkpCollisionAgent *v4; // rcx

  v2 = this;
  v3 = input;
  ((void (*)(void))this->m_boundingVolumeAgent->vfptr[4].__first_virtual_table_function__)();
  v4 = v2->m_childAgent;
  if ( v4 )
    ((void (__fastcall *)(hkpCollisionAgent *, hkpCollisionInput *))v4->vfptr[4].__first_virtual_table_function__)(
      v4,
      v3);
}

// File Line: 102
// RVA: 0xCF7490
void __fastcall hkpBvAgent::warpTime(hkpBvAgent *this, float oldTime, float newTime, hkpCollisionInput *input)
{
  hkpBvAgent *v4; // rbx
  hkpCollisionInput *v5; // rdi
  __int64 v6; // rdx
  __int64 v7; // r8
  hkpCollisionAgent *v8; // rcx

  v4 = this;
  v5 = input;
  ((void (*)(void))this->m_boundingVolumeAgent->vfptr[5].__vecDelDtor)();
  v8 = v4->m_childAgent;
  if ( v8 )
    ((void (__fastcall *)(hkpCollisionAgent *, __int64, __int64, hkpCollisionInput *))v8->vfptr[5].__vecDelDtor)(
      v8,
      v6,
      v7,
      v5);
}

// File Line: 111
// RVA: 0xCF74F0
void __fastcall hkpBvAgent::removePoint(hkpBvAgent *this, __int64 idToRemove)
{
  hkpCollisionAgent *v2; // rcx

  v2 = this->m_childAgent;
  if ( v2 )
    ((void (__fastcall *)(hkpCollisionAgent *, __int64))v2->vfptr[5].__first_virtual_table_function__)(v2, idToRemove);
}

// File Line: 119
// RVA: 0xCF7510
void __fastcall hkpBvAgent::commitPotential(hkpBvAgent *this, __int64 newId)
{
  hkpCollisionAgent *v2; // rcx

  v2 = this->m_childAgent;
  if ( v2 )
    v2->vfptr[6].__vecDelDtor((hkBaseObject *)&v2->vfptr, newId);
}

// File Line: 127
// RVA: 0xCF7530
void __fastcall hkpBvAgent::createZombie(hkpBvAgent *this, __int64 idTobecomeZombie)
{
  hkpCollisionAgent *v2; // rcx

  v2 = this->m_childAgent;
  if ( v2 )
    ((void (__fastcall *)(hkpCollisionAgent *, __int64))v2->vfptr[6].__first_virtual_table_function__)(
      v2,
      idTobecomeZombie);
}

// File Line: 135
// RVA: 0xCF65A0
void __fastcall hkpBvAgent::processCollision(hkpBvAgent *this, hkpCdBody *bodyAin, hkpCdBody *bodyB, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *result)
{
  hkpBvAgent *v5; // rbx
  hkpProcessCollisionInput *v6; // rdi
  hkpCdBody *v7; // rsi
  hkpCdBody *v8; // r14
  _QWORD *v9; // rax
  unsigned __int64 v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  hkpShape *v13; // rbp
  hkpCollisionAgent *v14; // rcx
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  signed __int64 v18; // rcx
  bool v19; // zf
  __int64 v20; // rax
  hkpCollisionDispatcher *v21; // r10
  signed __int64 v22; // rdx
  hkpCollisionAgent *v23; // rcx
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  signed __int64 v27; // rcx
  void **v28; // [rsp+30h] [rbp-38h]
  char v29; // [rsp+38h] [rbp-30h]
  __int64 v30; // [rsp+40h] [rbp-28h]
  int v31; // [rsp+48h] [rbp-20h]
  const void *v32; // [rsp+50h] [rbp-18h]
  hkpCdBody *v33; // [rsp+58h] [rbp-10h]

  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = bodyAin;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = v9[1];
  v11 = v9;
  if ( v10 < v9[3] )
  {
    *(_QWORD *)v10 = "LthkpBvAgent";
    *(_QWORD *)(v10 + 16) = "StcheckBvShape";
    v12 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v12;
    v11[1] = v10 + 24;
  }
  v13 = v8->m_shape;
  v14 = v5->m_boundingVolumeAgent;
  v32 = v8->m_motion;
  v33 = v8;
  v30 = (__int64)v13[1].vfptr;
  v31 = -1;
  v29 = 0;
  v28 = &hkpFlagCdBodyPairCollector::`vftable';
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpProcessCollisionInput *, void ***))v14->vfptr[1].__first_virtual_table_function__)(
    v14,
    &v30,
    v7,
    v6,
    &v28);
  if ( v29 )
  {
    v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v16 = (_QWORD *)v15[1];
    if ( (unsigned __int64)v16 < v15[3] )
    {
      *v16 = "Stchild";
      v17 = __rdtsc();
      v18 = (signed __int64)(v16 + 2);
      *(_DWORD *)(v18 - 8) = v17;
      v15[1] = v18;
    }
    v19 = v5->m_childAgent == 0i64;
    v20 = *(_QWORD *)&v13[1].m_type.m_storage;
    v31 = 0;
    v30 = v20;
    if ( v19 )
    {
      v21 = v6->m_dispatcher.m_storage;
      v22 = (signed __int64)v6->m_dispatcher.m_storage->m_agent2TypesPred;
      if ( !v6->m_createPredictiveAgents.m_storage )
        v22 = (signed __int64)v21->m_agent2Types;
      v5->m_childAgent = v21->m_agent2Func[*(unsigned __int8 *)((unsigned __int8)v7->m_shape->m_type.m_storage
                                                              + v22
                                                              + 35i64 * *(unsigned __int8 *)(v20 + 16))].m_createFunc(
                           (hkpCdBody *)&v30,
                           v7,
                           (hkpCollisionInput *)&v6->m_dispatcher,
                           v5->m_contactMgr);
    }
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v5->m_childAgent->vfptr[3].__vecDelDtor)(
      v5->m_childAgent,
      &v30,
      v7,
      v6,
      result);
  }
  else
  {
    v23 = v5->m_childAgent;
    if ( v23 )
    {
      ((void (__fastcall *)(hkpCollisionAgent *, hkpConstraintOwner *))v23->vfptr[3].__first_virtual_table_function__)(
        v23,
        result->m_constraintOwner.m_storage);
      v5->m_childAgent = 0i64;
    }
  }
  v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v25 = (_QWORD *)v24[1];
  if ( (unsigned __int64)v25 < v24[3] )
  {
    *v25 = "lt";
    v26 = __rdtsc();
    v27 = (signed __int64)(v25 + 2);
    *(_DWORD *)(v27 - 8) = v26;
    v24[1] = v27;
  }
}

// File Line: 170
// RVA: 0xCF67B0
void __fastcall hkpBvAgent::linearCast(hkpBvAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *pointDetails, hkpCdPointCollector *startCollector)
{
  hkpBvAgent *v6; // rbx
  hkpLinearCastCollisionInput *v7; // rdi
  hkpCdBody *v8; // rsi
  hkpCdBody *v9; // r14
  _QWORD *v10; // rax
  unsigned __int64 v11; // r10
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  hkpShape *v14; // rbp
  hkpCollisionAgent *v15; // rcx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx
  bool v20; // zf
  __int64 v21; // rax
  hkpCollisionDispatcher *v22; // r10
  signed __int64 v23; // rdx
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  signed __int64 v27; // rcx
  __int64 v28; // [rsp+30h] [rbp-68h]
  int v29; // [rsp+38h] [rbp-60h]
  const void *v30; // [rsp+40h] [rbp-58h]
  hkpCdBody *v31; // [rsp+48h] [rbp-50h]
  void **v32; // [rsp+50h] [rbp-48h]
  float v33; // [rsp+58h] [rbp-40h]
  char v34; // [rsp+60h] [rbp-38h]
  __m128 v35; // [rsp+80h] [rbp-18h]

  v6 = this;
  v7 = input;
  v8 = bodyB;
  v9 = bodyA;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = v10[1];
  v12 = v10;
  if ( v11 < v10[3] )
  {
    *(_QWORD *)v11 = "LthkpBvAgent";
    *(_QWORD *)(v11 + 16) = "StcheckBvShape";
    v13 = __rdtsc();
    *(_DWORD *)(v11 + 8) = v13;
    v12[1] = v11 + 24;
  }
  v14 = v9->m_shape;
  v15 = v6->m_boundingVolumeAgent;
  v30 = v9->m_motion;
  v31 = v9;
  v28 = (__int64)v14[1].vfptr;
  v33 = FLOAT_3_40282e38;
  v35 = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, (__m128)xmmword_141A712A0), 196);
  v29 = -1;
  v32 = &hkpSimpleClosestContactCollector::`vftable';
  v34 = 0;
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpLinearCastCollisionInput *, void ***, void ***, __int64, _QWORD, const void *, hkpCdBody *, void **, _QWORD))v15->vfptr[2].__first_virtual_table_function__)(
    v15,
    &v28,
    v8,
    v7,
    &v32,
    &v32,
    v28,
    *(_QWORD *)&v29,
    v30,
    v9,
    &hkpSimpleClosestContactCollector::`vftable',
    *(_QWORD *)&v33);
  if ( v34 )
  {
    v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v17 = (_QWORD *)v16[1];
    if ( (unsigned __int64)v17 < v16[3] )
    {
      *v17 = "Stchild";
      v18 = __rdtsc();
      v19 = (signed __int64)(v17 + 2);
      *(_DWORD *)(v19 - 8) = v18;
      v16[1] = v19;
    }
    v20 = v6->m_childAgent == 0i64;
    v21 = *(_QWORD *)&v14[1].m_type.m_storage;
    v29 = 0;
    v28 = v21;
    if ( v20 )
    {
      v22 = v7->m_dispatcher.m_storage;
      v23 = (signed __int64)v7->m_dispatcher.m_storage->m_agent2TypesPred;
      if ( !v7->m_createPredictiveAgents.m_storage )
        v23 = (signed __int64)v22->m_agent2Types;
      v6->m_childAgent = v22->m_agent2Func[*(unsigned __int8 *)((unsigned __int8)v8->m_shape->m_type.m_storage
                                                              + v23
                                                              + 35i64 * *(unsigned __int8 *)(v21 + 16))].m_createFunc(
                           (hkpCdBody *)&v28,
                           v8,
                           (hkpCollisionInput *)&v7->m_dispatcher,
                           v6->m_contactMgr);
    }
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpLinearCastCollisionInput *, hkpCdPointCollector *, hkpCdPointCollector *, __int64, _QWORD))v6->m_childAgent->vfptr[2].__first_virtual_table_function__)(
      v6->m_childAgent,
      &v28,
      v8,
      v7,
      pointDetails,
      startCollector,
      v28,
      *(_QWORD *)&v29);
  }
  v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v25 = (_QWORD *)v24[1];
  if ( (unsigned __int64)v25 < v24[3] )
  {
    *v25 = "lt";
    v26 = __rdtsc();
    v27 = (signed __int64)(v25 + 2);
    *(_DWORD *)(v27 - 8) = v26;
    v24[1] = v27;
  }
}

// File Line: 202
// RVA: 0xCF69E0
void __fastcall hkpBvAgent::staticLinearCast(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *pointDetails, hkpCdPointCollector *startCollector)
{
  hkpCdBody *v5; // rsi
  hkpCdPointCollector *v6; // rbp
  hkpLinearCastCollisionInput *v7; // rbx
  hkpCdBody *v8; // rdi
  _QWORD *v9; // rax
  unsigned __int64 v10; // r10
  _QWORD *v11; // r11
  unsigned __int64 v12; // rax
  hkpCollisionDispatcher *v13; // r8
  hkpShape *v14; // r14
  hkpShape *v15; // rax
  __int64 v16; // rdx
  __int64 v17; // rsi
  void (__fastcall *v18)(hkpCdBody *, hkpCdBody *, hkpLinearCastCollisionInput *, hkpCdPointCollector *, hkpCdPointCollector *); // rax
  _QWORD *v19; // r8
  _QWORD *v20; // rcx
  unsigned __int64 v21; // rax
  signed __int64 v22; // rcx
  __int64 v23; // rax
  hkpCollisionDispatcher *v24; // r11
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  signed __int64 v28; // rcx
  __int64 v29; // [rsp+30h] [rbp-68h]
  int v30; // [rsp+38h] [rbp-60h]
  const void *v31; // [rsp+40h] [rbp-58h]
  hkpCdBody *v32; // [rsp+48h] [rbp-50h]
  void **v33; // [rsp+50h] [rbp-48h]
  float v34; // [rsp+58h] [rbp-40h]
  char v35; // [rsp+60h] [rbp-38h]
  __m128 v36; // [rsp+80h] [rbp-18h]

  v5 = bodyA;
  v6 = pointDetails;
  v7 = input;
  v8 = bodyB;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = v9[1];
  v11 = v9;
  if ( v10 < v9[3] )
  {
    *(_QWORD *)v10 = "LthkpBvAgent";
    *(_QWORD *)(v10 + 16) = "StcheckBvShape";
    v12 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v12;
    v11[1] = v10 + 24;
  }
  v13 = v7->m_dispatcher.m_storage;
  v14 = v5->m_shape;
  v31 = v5->m_motion;
  v15 = v8->m_shape;
  v32 = v5;
  v16 = (__int64)v14[1].vfptr;
  v30 = -1;
  v29 = v16;
  v17 = (unsigned __int8)v15->m_type.m_storage;
  v18 = v13->m_agent2Func[(unsigned __int8)v13->m_agent2Types[*(unsigned __int8 *)(v16 + 16)][v17]].m_linearCastFunc;
  v34 = FLOAT_3_40282e38;
  v36 = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, (__m128)xmmword_141A712A0), 196);
  v33 = &hkpSimpleClosestContactCollector::`vftable';
  v35 = 0;
  v18((hkpCdBody *)&v29, v8, v7, (hkpCdPointCollector *)&v33, (hkpCdPointCollector *)&v33);
  if ( v35 )
  {
    v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v20 = (_QWORD *)v19[1];
    if ( (unsigned __int64)v20 < v19[3] )
    {
      *v20 = "Stchild";
      v21 = __rdtsc();
      v22 = (signed __int64)(v20 + 2);
      *(_DWORD *)(v22 - 8) = v21;
      v19[1] = v22;
    }
    v23 = *(_QWORD *)&v14[1].m_type.m_storage;
    v24 = v7->m_dispatcher.m_storage;
    v30 = 0;
    v29 = v23;
    v24->m_agent2Func[(unsigned __int8)v24->m_agent2Types[*(unsigned __int8 *)(v23 + 16)][v17]].m_linearCastFunc(
      (hkpCdBody *)&v29,
      v8,
      v7,
      v6,
      startCollector);
  }
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "lt";
    v27 = __rdtsc();
    v28 = (signed __int64)(v26 + 2);
    *(_DWORD *)(v28 - 8) = v27;
    v25[1] = v28;
  }
}

// File Line: 234
// RVA: 0xCF6BE0
void __fastcall hkpBvAgent::getClosestPoints(hkpBvAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpBvAgent *v5; // rbx
  hkpCollisionInput *v6; // rdi
  hkpCdBody *v7; // rsi
  hkpCdBody *v8; // r14
  _QWORD *v9; // rax
  unsigned __int64 v10; // r10
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  hkpShape *v13; // rbp
  hkpCollisionAgent *v14; // rcx
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  signed __int64 v18; // rcx
  bool v19; // zf
  __int64 v20; // rax
  hkpCollisionDispatcher *v21; // r10
  signed __int64 v22; // rdx
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  void **v27; // [rsp+30h] [rbp-38h]
  char v28; // [rsp+38h] [rbp-30h]
  __int64 v29; // [rsp+40h] [rbp-28h]
  int v30; // [rsp+48h] [rbp-20h]
  const void *v31; // [rsp+50h] [rbp-18h]
  hkpCdBody *v32; // [rsp+58h] [rbp-10h]

  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = v9[1];
  v11 = v9;
  if ( v10 < v9[3] )
  {
    *(_QWORD *)v10 = "LthkpBvAgent";
    *(_QWORD *)(v10 + 16) = "StcheckBvShape";
    v12 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v12;
    v11[1] = v10 + 24;
  }
  v13 = v8->m_shape;
  v14 = v5->m_boundingVolumeAgent;
  v31 = v8->m_motion;
  v32 = v8;
  v29 = (__int64)v13[1].vfptr;
  v30 = -1;
  v28 = 0;
  v27 = &hkpFlagCdBodyPairCollector::`vftable';
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, void ***))v14->vfptr[1].__first_virtual_table_function__)(
    v14,
    &v29,
    v7,
    v6,
    &v27);
  if ( v28 )
  {
    v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v16 = (_QWORD *)v15[1];
    if ( (unsigned __int64)v16 < v15[3] )
    {
      *v16 = "Stchild";
      v17 = __rdtsc();
      v18 = (signed __int64)(v16 + 2);
      *(_DWORD *)(v18 - 8) = v17;
      v15[1] = v18;
    }
    v19 = v5->m_childAgent == 0i64;
    v20 = *(_QWORD *)&v13[1].m_type.m_storage;
    v30 = 0;
    v29 = v20;
    if ( v19 )
    {
      v21 = v6->m_dispatcher.m_storage;
      v22 = (signed __int64)v6->m_dispatcher.m_storage->m_agent2TypesPred;
      if ( !v6->m_createPredictiveAgents.m_storage )
        v22 = (signed __int64)v21->m_agent2Types;
      v5->m_childAgent = v21->m_agent2Func[*(unsigned __int8 *)((unsigned __int8)v7->m_shape->m_type.m_storage
                                                              + v22
                                                              + 35i64 * *(unsigned __int8 *)(v20 + 16))].m_createFunc(
                           (hkpCdBody *)&v29,
                           v7,
                           v6,
                           v5->m_contactMgr);
    }
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpCdPointCollector *))v5->m_childAgent->vfptr[2].__vecDelDtor)(
      v5->m_childAgent,
      &v29,
      v7,
      v6,
      collector);
  }
  v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v24 = (_QWORD *)v23[1];
  if ( (unsigned __int64)v24 < v23[3] )
  {
    *v24 = "lt";
    v25 = __rdtsc();
    v26 = (signed __int64)(v24 + 2);
    *(_DWORD *)(v26 - 8) = v25;
    v23[1] = v26;
  }
}

// File Line: 269
// RVA: 0xCF6DD0
void __fastcall hkpBvAgent::staticGetClosestPoints(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpCdBody *v4; // rsi
  hkpCdPointCollector *v5; // r14
  hkpCollisionInput *v6; // rbx
  hkpCdBody *v7; // rdi
  _QWORD *v8; // rax
  unsigned __int64 v9; // r10
  _QWORD *v10; // r11
  unsigned __int64 v11; // rax
  hkpCollisionDispatcher *v12; // r8
  hkpShape *v13; // rbp
  hkpShape *v14; // rax
  __int64 v15; // rdx
  __int64 v16; // rsi
  void (__fastcall *v17)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpCdBodyPairCollector *); // rax
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  signed __int64 v21; // rcx
  __int64 v22; // rax
  hkpCollisionDispatcher *v23; // r11
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  signed __int64 v27; // rcx
  __int64 v28; // [rsp+20h] [rbp-38h]
  char v29; // [rsp+28h] [rbp-30h]
  __int64 v30; // [rsp+30h] [rbp-28h]
  int v31; // [rsp+38h] [rbp-20h]
  const void *v32; // [rsp+40h] [rbp-18h]
  hkpCdBody *v33; // [rsp+48h] [rbp-10h]

  v4 = bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = v8[1];
  v10 = v8;
  if ( v9 < v8[3] )
  {
    *(_QWORD *)v9 = "LthkpBvAgent";
    *(_QWORD *)(v9 + 16) = "StcheckBvShape";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  v12 = v6->m_dispatcher.m_storage;
  v13 = v4->m_shape;
  v32 = v4->m_motion;
  v14 = v7->m_shape;
  v33 = v4;
  v15 = (__int64)v13[1].vfptr;
  v31 = -1;
  v30 = v15;
  v16 = (unsigned __int8)v14->m_type.m_storage;
  v17 = v12->m_agent2Func[(unsigned __int8)v12->m_agent2Types[*(unsigned __int8 *)(v15 + 16)][v16]].m_getPenetrationsFunc;
  v29 = 0;
  ((void (__fastcall *)(__int64 *, hkpCdBody *, hkpCollisionInput *, __int64 *, void **))v17)(
    &v30,
    v7,
    v6,
    &v28,
    &hkpFlagCdBodyPairCollector::`vftable');
  if ( v29 )
  {
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = (_QWORD *)v18[1];
    if ( (unsigned __int64)v19 < v18[3] )
    {
      *v19 = "Stchild";
      v20 = __rdtsc();
      v21 = (signed __int64)(v19 + 2);
      *(_DWORD *)(v21 - 8) = v20;
      v18[1] = v21;
    }
    v22 = *(_QWORD *)&v13[1].m_type.m_storage;
    v23 = v6->m_dispatcher.m_storage;
    v31 = 0;
    v30 = v22;
    (*((void (__fastcall **)(__int64 *, hkpCdBody *, hkpCollisionInput *, hkpCdPointCollector *))&v23->vfptr
     + 5 * ((unsigned __int8)v23->m_agent2Types[*(unsigned __int8 *)(v22 + 16)][v16] + 79i64)))(
      &v30,
      v7,
      v6,
      v5);
  }
  v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v25 = (_QWORD *)v24[1];
  if ( (unsigned __int64)v25 < v24[3] )
  {
    *v25 = "lt";
    v26 = __rdtsc();
    v27 = (signed __int64)(v25 + 2);
    *(_DWORD *)(v27 - 8) = v26;
    v24[1] = v27;
  }
}

// File Line: 303
// RVA: 0xCF6F90
void __fastcall hkpBvAgent::getPenetrations(hkpBvAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpBvAgent *v5; // rbx
  hkpCollisionInput *v6; // rdi
  hkpCdBody *v7; // rsi
  hkpCdBody *v8; // r14
  _QWORD *v9; // rax
  unsigned __int64 v10; // r10
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  hkpShape *v13; // rbp
  hkpCollisionAgent *v14; // rcx
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  signed __int64 v18; // rcx
  bool v19; // zf
  __int64 v20; // rax
  hkpCollisionDispatcher *v21; // r10
  signed __int64 v22; // rdx
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  void **v27; // [rsp+30h] [rbp-38h]
  char v28; // [rsp+38h] [rbp-30h]
  __int64 v29; // [rsp+40h] [rbp-28h]
  int v30; // [rsp+48h] [rbp-20h]
  const void *v31; // [rsp+50h] [rbp-18h]
  hkpCdBody *v32; // [rsp+58h] [rbp-10h]

  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = v9[1];
  v11 = v9;
  if ( v10 < v9[3] )
  {
    *(_QWORD *)v10 = "LthkpBvAgent";
    *(_QWORD *)(v10 + 16) = "StcheckBvShape";
    v12 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v12;
    v11[1] = v10 + 24;
  }
  v13 = v8->m_shape;
  v14 = v5->m_boundingVolumeAgent;
  v31 = v8->m_motion;
  v32 = v8;
  v29 = (__int64)v13[1].vfptr;
  v30 = -1;
  v28 = 0;
  v27 = &hkpFlagCdBodyPairCollector::`vftable';
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, void ***))v14->vfptr[1].__first_virtual_table_function__)(
    v14,
    &v29,
    v7,
    v6,
    &v27);
  if ( v28 )
  {
    v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v16 = (_QWORD *)v15[1];
    if ( (unsigned __int64)v16 < v15[3] )
    {
      *v16 = "Stchild";
      v17 = __rdtsc();
      v18 = (signed __int64)(v16 + 2);
      *(_DWORD *)(v18 - 8) = v17;
      v15[1] = v18;
    }
    v19 = v5->m_childAgent == 0i64;
    v20 = *(_QWORD *)&v13[1].m_type.m_storage;
    v30 = 0;
    v29 = v20;
    if ( v19 )
    {
      v21 = v6->m_dispatcher.m_storage;
      v22 = (signed __int64)v6->m_dispatcher.m_storage->m_agent2TypesPred;
      if ( !v6->m_createPredictiveAgents.m_storage )
        v22 = (signed __int64)v21->m_agent2Types;
      v5->m_childAgent = v21->m_agent2Func[*(unsigned __int8 *)((unsigned __int8)v7->m_shape->m_type.m_storage
                                                              + v22
                                                              + 35i64 * *(unsigned __int8 *)(v20 + 16))].m_createFunc(
                           (hkpCdBody *)&v29,
                           v7,
                           v6,
                           v5->m_contactMgr);
    }
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpCdBodyPairCollector *))v5->m_childAgent->vfptr[1].__first_virtual_table_function__)(
      v5->m_childAgent,
      &v29,
      v7,
      v6,
      collector);
  }
  v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v24 = (_QWORD *)v23[1];
  if ( (unsigned __int64)v24 < v23[3] )
  {
    *v24 = "lt";
    v25 = __rdtsc();
    v26 = (signed __int64)(v24 + 2);
    *(_DWORD *)(v26 - 8) = v25;
    v23[1] = v26;
  }
}

// File Line: 329
// RVA: 0xCF7180
void __fastcall hkpBvAgent::staticGetPenetrations(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpCdBody *v4; // rsi
  hkpCdBodyPairCollector *v5; // r14
  hkpCollisionInput *v6; // rbx
  hkpCdBody *v7; // rdi
  _QWORD *v8; // rax
  unsigned __int64 v9; // r10
  _QWORD *v10; // r11
  unsigned __int64 v11; // rax
  hkpCollisionDispatcher *v12; // r8
  hkpShape *v13; // rbp
  hkpShape *v14; // rax
  __int64 v15; // rdx
  __int64 v16; // rsi
  void (__fastcall *v17)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpCdBodyPairCollector *); // rax
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  signed __int64 v21; // rcx
  __int64 v22; // rax
  hkpCollisionDispatcher *v23; // r11
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  signed __int64 v27; // rcx
  __int64 v28; // [rsp+20h] [rbp-38h]
  char v29; // [rsp+28h] [rbp-30h]
  __int64 v30; // [rsp+30h] [rbp-28h]
  int v31; // [rsp+38h] [rbp-20h]
  const void *v32; // [rsp+40h] [rbp-18h]
  hkpCdBody *v33; // [rsp+48h] [rbp-10h]

  v4 = bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = v8[1];
  v10 = v8;
  if ( v9 < v8[3] )
  {
    *(_QWORD *)v9 = "LthkpBvAgent";
    *(_QWORD *)(v9 + 16) = "StcheckBvShape";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  v12 = v6->m_dispatcher.m_storage;
  v13 = v4->m_shape;
  v32 = v4->m_motion;
  v14 = v7->m_shape;
  v33 = v4;
  v15 = (__int64)v13[1].vfptr;
  v31 = -1;
  v30 = v15;
  v16 = (unsigned __int8)v14->m_type.m_storage;
  v17 = v12->m_agent2Func[(unsigned __int8)v12->m_agent2Types[*(unsigned __int8 *)(v15 + 16)][v16]].m_getPenetrationsFunc;
  v29 = 0;
  ((void (__fastcall *)(__int64 *, hkpCdBody *, hkpCollisionInput *, __int64 *, void **))v17)(
    &v30,
    v7,
    v6,
    &v28,
    &hkpFlagCdBodyPairCollector::`vftable');
  if ( v29 )
  {
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = (_QWORD *)v18[1];
    if ( (unsigned __int64)v19 < v18[3] )
    {
      *v19 = "Stchild";
      v20 = __rdtsc();
      v21 = (signed __int64)(v19 + 2);
      *(_DWORD *)(v21 - 8) = v20;
      v18[1] = v21;
    }
    v22 = *(_QWORD *)&v13[1].m_type.m_storage;
    v23 = v6->m_dispatcher.m_storage;
    v31 = 0;
    v30 = v22;
    v23->m_agent2Func[(unsigned __int8)v23->m_agent2Types[*(unsigned __int8 *)(v22 + 16)][v16]].m_getPenetrationsFunc(
      (hkpCdBody *)&v30,
      v7,
      v6,
      v5);
  }
  v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v25 = (_QWORD *)v24[1];
  if ( (unsigned __int64)v25 < v24[3] )
  {
    *v25 = "lt";
    v26 = __rdtsc();
    v27 = (signed __int64)(v25 + 2);
    *(_DWORD *)(v27 - 8) = v26;
    v24[1] = v27;
  }
}

// File Line: 359
// RVA: 0xCF73A0
void __fastcall hkpBvAgent::updateShapeCollectionFilter(hkpBvAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpConstraintOwner *constraintOwner)
{
  const void *v5; // rax
  hkpShape *v6; // rbp
  hkpBvAgent *v7; // rbx
  hkpCollisionAgent *v8; // rcx
  hkpCollisionInput *v9; // rdi
  hkpCdBody *v10; // rsi
  hkpCollisionAgent *v11; // rcx
  __int64 v12; // rax
  __int64 v13; // [rsp+30h] [rbp-28h]
  int v14; // [rsp+38h] [rbp-20h]
  const void *v15; // [rsp+40h] [rbp-18h]
  hkpCdBody *v16; // [rsp+48h] [rbp-10h]

  v5 = bodyA->m_motion;
  v6 = bodyA->m_shape;
  v16 = bodyA;
  v15 = v5;
  v13 = (__int64)v6[1].vfptr;
  v7 = this;
  v8 = this->m_boundingVolumeAgent;
  v14 = -1;
  v9 = input;
  v10 = bodyB;
  v8->vfptr[4].__vecDelDtor((hkBaseObject *)&v8->vfptr, (unsigned int)&v13);
  v11 = v7->m_childAgent;
  if ( v11 )
  {
    v12 = *(_QWORD *)&v6[1].m_type.m_storage;
    v14 = 0;
    v13 = v12;
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpConstraintOwner *))v11->vfptr[4].__vecDelDtor)(
      v11,
      &v13,
      v10,
      v9,
      constraintOwner);
  }
}


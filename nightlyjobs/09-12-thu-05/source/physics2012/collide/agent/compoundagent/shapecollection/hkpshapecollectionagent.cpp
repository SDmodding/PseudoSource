// File Line: 17
// RVA: 0xCF38F0
void __fastcall hkpShapeCollectionAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpShapeCollectionAgent::createListBAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, ALL_SHAPE_TYPES, COLLECTION);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, ALL_SHAPE_TYPES, TRI_SAMPLED_HEIGHT_FIELD_COLLECTION);
  f.m_createFunc = hkpShapeCollectionAgent::createListAAgent;
  f.m_getPenetrationsFunc = hkpShapeCollectionAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpShapeCollectionAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpShapeCollectionAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, COLLECTION, ALL_SHAPE_TYPES);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, TRI_SAMPLED_HEIGHT_FIELD_COLLECTION, ALL_SHAPE_TYPES);
}

// File Line: 46
// RVA: 0xCF4A00
void __fastcall hkpShapeCollectionAgent::createListAAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpShapeCollectionAgent *v9; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 104i64);
  if ( v9 )
    hkpShapeCollectionAgent::hkpShapeCollectionAgent(v9, bodyA, bodyB, input, mgr);
}

// File Line: 55
// RVA: 0xCF4A80
hkpShapeCollectionAgent *__fastcall hkpShapeCollectionAgent::createListBAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpShapeCollectionAgent *result; // rax
  hkpShapeCollectionAgent *v10; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                        Value[11],
                                        104i64);
  v10 = result;
  if ( result )
  {
    hkpShapeCollectionAgent::hkpShapeCollectionAgent(result, bodyB, bodyA, input, mgr);
    v10->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpShapeCollectionAgent>::`vftable;
    return v10;
  }
  return result;
}

// File Line: 64
// RVA: 0xCF4820
void __fastcall hkpShapeCollectionAgent::hkpShapeCollectionAgent(
        hkpShapeCollectionAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  hkpContactMgr *v5; // rax
  hkInplaceArray<hkpShapeCollectionAgent::KeyAgentPair,4,hkContainerHeapAllocator> *p_m_agents; // r15
  hkpShape *m_shape; // rcx
  __int64 v11; // rsi
  int v12; // eax
  int v13; // ecx
  int v14; // ecx
  unsigned int v15; // ebx
  hkpContactMgr *v16; // r12
  __int64 v17; // rax
  hkpCollisionFilter *m_storage; // rcx
  __int64 m_size; // rdi
  int v20; // eax
  __int64 v21; // rdi
  hkpCollisionDispatcher *v22; // r10
  char (*m_agent2TypesPred)[35]; // rdx
  __int64 v24; // rax
  __int64 v25; // [rsp+40h] [rbp-258h] BYREF
  unsigned int v26; // [rsp+48h] [rbp-250h]
  const void *m_motion; // [rsp+50h] [rbp-248h]
  hkpCdBody *v28; // [rsp+58h] [rbp-240h]
  char v29[568]; // [rsp+60h] [rbp-238h] BYREF
  hkResult result; // [rsp+2A8h] [rbp+10h] BYREF

  v5 = mgr;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  p_m_agents = &this->m_agents;
  this->m_contactMgr = v5;
  this->vfptr = (hkBaseObjectVtbl *)&hkpShapeCollectionAgent::`vftable;
  this->m_agents.m_size = 0;
  this->m_agents.m_capacityAndFlags = -2147483644;
  v28 = bodyA;
  this->m_agents.m_data = this->m_agents.m_storage;
  m_shape = bodyA->m_shape;
  m_motion = bodyA->m_motion;
  v11 = ((__int64 (__fastcall *)(hkpShape *))m_shape->vfptr[7].__vecDelDtor)(m_shape);
  v12 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 8i64))(v11);
  v13 = p_m_agents->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < v12 )
  {
    v14 = 2 * v13;
    if ( v12 < v14 )
      v12 = v14;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_agents->m_data, v12, 16);
  }
  v15 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 16i64))(v11);
  if ( v15 != -1 )
  {
    v16 = mgr;
    do
    {
      v17 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v11 + 40i64))(v11, v15, v29);
      m_storage = input->m_filter.m_storage;
      v26 = v15;
      v25 = v17;
      if ( m_storage->hkpShapeCollectionFilter::vfptr->isCollisionEnabled(
             &m_storage->hkpShapeCollectionFilter,
             (hkBool *)&mgr,
             input,
             bodyB,
             bodyA,
             (hkpShapeContainer *)v11,
             v15)->m_bool )
      {
        m_size = p_m_agents->m_size;
        v20 = m_size + 1;
        v21 = (__int64)&p_m_agents->m_data[m_size];
        p_m_agents->m_size = v20;
        v22 = input->m_dispatcher.m_storage;
        m_agent2TypesPred = input->m_dispatcher.m_storage->m_agent2TypesPred;
        if ( !input->m_createPredictiveAgents.m_storage )
          m_agent2TypesPred = v22->m_agent2Types;
        v24 = (__int64)v22->m_agent2Func[(unsigned __int8)m_agent2TypesPred[*(unsigned __int8 *)(v25 + 16)][(unsigned __int8)bodyB->m_shape->m_type.m_storage]].m_createFunc(
                         (hkpCdBody *)&v25,
                         bodyB,
                         input,
                         v16);
        *(_DWORD *)v21 = v15;
        *(_QWORD *)(v21 + 8) = v24;
      }
      v15 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v11 + 24i64))(v11, v15);
    }
    while ( v15 != -1 );
  }
}

// File Line: 93
// RVA: 0xCF4450
void __fastcall hkpShapeCollectionAgent::cleanup(hkpShapeCollectionAgent *this, hkpConstraintOwner *info)
{
  int v2; // edi
  __int64 v5; // rsi
  hkpCollisionAgent *m_agent; // rcx

  v2 = 0;
  if ( this->m_agents.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      m_agent = this->m_agents.m_data[v5].m_agent;
      ((void (__fastcall *)(hkpCollisionAgent *, hkpConstraintOwner *))m_agent->vfptr[3].__first_virtual_table_function__)(
        m_agent,
        info);
      ++v2;
      ++v5;
    }
    while ( v2 < this->m_agents.m_size );
  }
  this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 102
// RVA: 0xCF4730
void __fastcall hkpShapeCollectionAgent::invalidateTim(hkpShapeCollectionAgent *this, hkpCollisionInput *input)
{
  int v2; // ebx
  __int64 v5; // rdi
  hkpCollisionAgent *m_agent; // rcx

  v2 = 0;
  if ( this->m_agents.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      m_agent = this->m_agents.m_data[v5].m_agent;
      ((void (__fastcall *)(hkpCollisionAgent *, hkpCollisionInput *))m_agent->vfptr[4].__first_virtual_table_function__)(
        m_agent,
        input);
      ++v2;
      ++v5;
    }
    while ( v2 < this->m_agents.m_size );
  }
}

// File Line: 110
// RVA: 0xCF47A0
void __fastcall hkpShapeCollectionAgent::warpTime(
        hkpShapeCollectionAgent *this,
        float oldTime,
        float newTime,
        hkpCollisionInput *input)
{
  __int64 v4; // rdx
  __int64 v5; // r8
  int v6; // ebx
  __int64 v9; // rdi
  hkpCollisionAgent *m_agent; // rcx

  v6 = 0;
  if ( this->m_agents.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      m_agent = this->m_agents.m_data[v9].m_agent;
      ((void (__fastcall *)(hkpCollisionAgent *, __int64, __int64, hkpCollisionInput *))m_agent->vfptr[5].__vecDelDtor)(
        m_agent,
        v4,
        v5,
        input);
      ++v6;
      ++v9;
    }
    while ( v6 < this->m_agents.m_size );
  }
}

// File Line: 119
// RVA: 0xCF39D0
void __fastcall hkpShapeCollectionAgent::processCollision(
        hkpShapeCollectionAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *result)
{
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  __int64 v14; // rax
  hkpShapeCollectionAgent::KeyAgentPair *m_data; // rdi
  int v16; // esi
  const void *m_motion; // rcx
  __int64 v18; // r14
  int m_key; // ebx
  __int64 v20; // rax
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r8
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  __int64 v26; // [rsp+30h] [rbp-238h] BYREF
  int v27; // [rsp+38h] [rbp-230h]
  const void *i; // [rsp+40h] [rbp-228h]
  hkpCdBody *v29; // [rsp+48h] [rbp-220h]
  char v30[512]; // [rsp+50h] [rbp-218h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtShapeCollection";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  v14 = ((__int64 (__fastcall *)(hkpShape *))bodyA->m_shape->vfptr[7].__vecDelDtor)(bodyA->m_shape);
  m_data = this->m_agents.m_data;
  v16 = this->m_agents.m_size - 1;
  m_motion = bodyA->m_motion;
  v18 = v14;
  v29 = bodyA;
  for ( i = m_motion; v16 >= 0; ++m_data )
  {
    m_key = m_data->m_key;
    v20 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v18 + 40i64))(v18, m_data->m_key, v30);
    v27 = m_key;
    v26 = v20;
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))m_data->m_agent->vfptr[3].__vecDelDtor)(
      m_data->m_agent,
      &v26,
      bodyB,
      input,
      result);
    --v16;
  }
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  v23 = v21;
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v24 = __rdtsc();
    v25 = v22 + 2;
    *((_DWORD *)v25 - 2) = v24;
    v23[1] = v25;
  }
}

// File Line: 153
// RVA: 0xCF3E60
void __fastcall hkpShapeCollectionAgent::getClosestPoints(
        hkpShapeCollectionAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  __int64 v14; // rax
  hkpShapeCollectionAgent::KeyAgentPair *m_data; // rdi
  int v16; // esi
  const void *m_motion; // rcx
  __int64 v18; // r14
  int m_key; // ebx
  __int64 v20; // rax
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r8
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  __int64 v26; // [rsp+30h] [rbp-238h] BYREF
  int v27; // [rsp+38h] [rbp-230h]
  const void *i; // [rsp+40h] [rbp-228h]
  hkpCdBody *v29; // [rsp+48h] [rbp-220h]
  char v30[512]; // [rsp+50h] [rbp-218h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtShapeCollection";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  v14 = ((__int64 (__fastcall *)(hkpShape *))bodyA->m_shape->vfptr[7].__vecDelDtor)(bodyA->m_shape);
  m_data = this->m_agents.m_data;
  v16 = this->m_agents.m_size - 1;
  m_motion = bodyA->m_motion;
  v18 = v14;
  v29 = bodyA;
  for ( i = m_motion; v16 >= 0; ++m_data )
  {
    m_key = m_data->m_key;
    v20 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v18 + 40i64))(v18, m_data->m_key, v30);
    v27 = m_key;
    v26 = v20;
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpCdPointCollector *))m_data->m_agent->vfptr[2].__vecDelDtor)(
      m_data->m_agent,
      &v26,
      bodyB,
      input,
      collector);
    --v16;
  }
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  v23 = v21;
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v24 = __rdtsc();
    v25 = v22 + 2;
    *((_DWORD *)v25 - 2) = v24;
    v23[1] = v25;
  }
}

// File Line: 179
// RVA: 0xCF3FC0
void __fastcall hkpShapeCollectionAgent::staticGetClosestPoints(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // rax
  unsigned __int64 v9; // rdx
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  __int64 v14; // rax
  const void *m_motion; // rcx
  __int64 m_storage; // rdi
  hkpShapeContainer *v17; // rsi
  unsigned int i; // ebx
  __int64 v19; // rax
  hkpCollisionDispatcher *v20; // r11
  _QWORD *v21; // r8
  _QWORD *v22; // rcx
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx
  __int64 v25; // [rsp+40h] [rbp-248h] BYREF
  unsigned int v26; // [rsp+48h] [rbp-240h]
  const void *v27; // [rsp+50h] [rbp-238h]
  hkpCdBody *v28; // [rsp+58h] [rbp-230h]
  char v29[512]; // [rsp+60h] [rbp-228h] BYREF
  char v30; // [rsp+290h] [rbp+8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtShapeCollection";
    v12 = __rdtsc();
    v9 = (unsigned __int64)HIDWORD(v12) << 32;
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  v14 = ((__int64 (__fastcall *)(hkpShape *, unsigned __int64, _QWORD *))bodyA->m_shape->vfptr[7].__vecDelDtor)(
          bodyA->m_shape,
          v9,
          v11);
  m_motion = bodyA->m_motion;
  v28 = bodyA;
  v27 = m_motion;
  m_storage = (unsigned __int8)bodyB->m_shape->m_type.m_storage;
  v17 = (hkpShapeContainer *)v14;
  for ( i = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14); i != -1; i = v17->vfptr->getNextKey(
                                                                                               v17,
                                                                                               i) )
  {
    if ( input->m_filter.m_storage->vfptr->isCollisionEnabled(
           &input->m_filter.m_storage->hkpShapeCollectionFilter,
           &v30,
           input,
           bodyB,
           bodyA,
           v17,
           i)->m_bool )
    {
      v19 = (__int64)v17->vfptr->getChildShape(v17, i, (char (*)[512])v29);
      v20 = input->m_dispatcher.m_storage;
      v26 = i;
      v25 = v19;
      v20->m_agent2Func[(unsigned __int8)v20->m_agent2Types[*(unsigned __int8 *)(v19 + 16)][m_storage]].m_getClosestPointFunc(
        (hkpCdBody *)&v25,
        bodyB,
        input,
        collector);
    }
  }
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v23 = __rdtsc();
    v24 = v22 + 2;
    *((_DWORD *)v24 - 2) = v23;
    v21[1] = v24;
  }
}

// File Line: 212
// RVA: 0xCF3B30
void __fastcall hkpShapeCollectionAgent::linearCast(
        hkpShapeCollectionAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  _QWORD *Value; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r10
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  __int64 v15; // rax
  hkpShapeCollectionAgent::KeyAgentPair *m_data; // rdi
  int v17; // esi
  const void *m_motion; // rcx
  __int64 v19; // r14
  int m_key; // ebx
  __int64 v21; // rax
  _QWORD *v22; // rax
  _QWORD *v23; // rcx
  _QWORD *v24; // r8
  unsigned __int64 v25; // rax
  _QWORD *v26; // rcx
  __int64 v27; // [rsp+30h] [rbp-248h] BYREF
  int v28; // [rsp+38h] [rbp-240h]
  const void *i; // [rsp+40h] [rbp-238h]
  hkpCdBody *v30; // [rsp+48h] [rbp-230h]
  char v31[512]; // [rsp+50h] [rbp-228h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)Value[1];
  v12 = Value;
  if ( (unsigned __int64)v11 < Value[3] )
  {
    *v11 = "TtShapeCollection";
    v13 = __rdtsc();
    v14 = v11 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v12[1] = v14;
  }
  v15 = ((__int64 (__fastcall *)(hkpShape *))bodyA->m_shape->vfptr[7].__vecDelDtor)(bodyA->m_shape);
  m_data = this->m_agents.m_data;
  v17 = this->m_agents.m_size - 1;
  m_motion = bodyA->m_motion;
  v19 = v15;
  v30 = bodyA;
  for ( i = m_motion; v17 >= 0; ++m_data )
  {
    m_key = m_data->m_key;
    v21 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v19 + 40i64))(v19, m_data->m_key, v31);
    v28 = m_key;
    v27 = v21;
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpLinearCastCollisionInput *, hkpCdPointCollector *, hkpCdPointCollector *))m_data->m_agent->vfptr[2].__first_virtual_table_function__)(
      m_data->m_agent,
      &v27,
      bodyB,
      input,
      collector,
      startCollector);
    --v17;
  }
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  v24 = v22;
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "Et";
    v25 = __rdtsc();
    v26 = v23 + 2;
    *((_DWORD *)v26 - 2) = v25;
    v24[1] = v26;
  }
}

// File Line: 237
// RVA: 0xCF3CB0
void __fastcall hkpShapeCollectionAgent::staticLinearCast(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  _QWORD *Value; // rax
  unsigned __int64 v10; // rdx
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  __int64 v15; // rax
  const void *m_motion; // rcx
  __int64 m_storage; // r13
  hkpShapeContainer *v18; // rsi
  unsigned int v19; // ebx
  hkpCdPointCollector *v20; // rdi
  __int64 v21; // rax
  hkpCollisionDispatcher *v22; // r11
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  _QWORD *v26; // rcx
  __int64 v27; // [rsp+40h] [rbp-248h] BYREF
  unsigned int v28; // [rsp+48h] [rbp-240h]
  const void *v29; // [rsp+50h] [rbp-238h]
  hkpCdBody *v30; // [rsp+58h] [rbp-230h]
  char v31[512]; // [rsp+60h] [rbp-228h] BYREF
  char v32; // [rsp+290h] [rbp+8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)Value[1];
  v12 = Value;
  if ( (unsigned __int64)v11 < Value[3] )
  {
    *v11 = "TtShapeCollection";
    v13 = __rdtsc();
    v10 = (unsigned __int64)HIDWORD(v13) << 32;
    v14 = v11 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v12[1] = v14;
  }
  v15 = ((__int64 (__fastcall *)(hkpShape *, unsigned __int64, _QWORD *))bodyA->m_shape->vfptr[7].__vecDelDtor)(
          bodyA->m_shape,
          v10,
          v12);
  m_motion = bodyA->m_motion;
  v30 = bodyA;
  v29 = m_motion;
  m_storage = (unsigned __int8)bodyB->m_shape->m_type.m_storage;
  v18 = (hkpShapeContainer *)v15;
  v19 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v15 + 16i64))(v15);
  if ( v19 != -1 )
  {
    v20 = startCollector;
    do
    {
      if ( input->m_filter.m_storage->vfptr->isCollisionEnabled(
             &input->m_filter.m_storage->hkpShapeCollectionFilter,
             &v32,
             input,
             bodyB,
             bodyA,
             v18,
             v19)->m_bool )
      {
        v21 = (__int64)v18->vfptr->getChildShape(v18, v19, (char (*)[512])v31);
        v22 = input->m_dispatcher.m_storage;
        v28 = v19;
        v27 = v21;
        v22->m_agent2Func[(unsigned __int8)v22->m_agent2Types[*(unsigned __int8 *)(v21 + 16)][m_storage]].m_linearCastFunc(
          (hkpCdBody *)&v27,
          bodyB,
          input,
          collector,
          v20);
      }
      v19 = v18->vfptr->getNextKey(v18, v19);
    }
    while ( v19 != -1 );
  }
  v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v24 = (_QWORD *)v23[1];
  if ( (unsigned __int64)v24 < v23[3] )
  {
    *v24 = "Et";
    v25 = __rdtsc();
    v26 = v24 + 2;
    *((_DWORD *)v26 - 2) = v25;
    v23[1] = v26;
  }
}

// File Line: 267
// RVA: 0xCF4150
void __fastcall hkpShapeCollectionAgent::getPenetrations(
        hkpShapeCollectionAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  __int64 v14; // rax
  hkpShapeCollectionAgent::KeyAgentPair *m_data; // rdi
  int v16; // esi
  const void *m_motion; // rcx
  __int64 v18; // r14
  int m_key; // ebx
  __int64 v20; // rax
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r8
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  __int64 v26; // [rsp+30h] [rbp-238h] BYREF
  int v27; // [rsp+38h] [rbp-230h]
  const void *i; // [rsp+40h] [rbp-228h]
  hkpCdBody *v29; // [rsp+48h] [rbp-220h]
  char v30[512]; // [rsp+50h] [rbp-218h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtShapeCollection";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  v14 = ((__int64 (__fastcall *)(hkpShape *))bodyA->m_shape->vfptr[7].__vecDelDtor)(bodyA->m_shape);
  m_data = this->m_agents.m_data;
  v16 = this->m_agents.m_size - 1;
  m_motion = bodyA->m_motion;
  v18 = v14;
  v29 = bodyA;
  for ( i = m_motion; v16 >= 0; --v16 )
  {
    m_key = m_data->m_key;
    v20 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v18 + 40i64))(v18, m_data->m_key, v30);
    v27 = m_key;
    v26 = v20;
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpCdBodyPairCollector *))m_data->m_agent->vfptr[1].__first_virtual_table_function__)(
      m_data->m_agent,
      &v26,
      bodyB,
      input,
      collector);
    if ( collector->m_earlyOut.m_bool )
      break;
    ++m_data;
  }
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  v23 = v21;
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v24 = __rdtsc();
    v25 = v22 + 2;
    *((_DWORD *)v25 - 2) = v24;
    v23[1] = v25;
  }
}

// File Line: 295
// RVA: 0xCF42B0
void __fastcall hkpShapeCollectionAgent::staticGetPenetrations(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  _QWORD *Value; // rax
  unsigned __int64 v9; // rdx
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  __int64 v14; // rax
  const void *m_motion; // rcx
  __int64 m_storage; // rdi
  hkpShapeContainer *v17; // rsi
  unsigned int i; // ebx
  __int64 v19; // rax
  hkpCollisionDispatcher *v20; // r11
  _QWORD *v21; // r8
  _QWORD *v22; // rcx
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx
  __int64 v25; // [rsp+40h] [rbp-248h] BYREF
  unsigned int v26; // [rsp+48h] [rbp-240h]
  const void *v27; // [rsp+50h] [rbp-238h]
  hkpCdBody *v28; // [rsp+58h] [rbp-230h]
  char v29[512]; // [rsp+60h] [rbp-228h] BYREF
  char v30; // [rsp+290h] [rbp+8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtShapeCollection";
    v12 = __rdtsc();
    v9 = (unsigned __int64)HIDWORD(v12) << 32;
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  v14 = ((__int64 (__fastcall *)(hkpShape *, unsigned __int64, _QWORD *))bodyA->m_shape->vfptr[7].__vecDelDtor)(
          bodyA->m_shape,
          v9,
          v11);
  m_motion = bodyA->m_motion;
  v28 = bodyA;
  v27 = m_motion;
  m_storage = (unsigned __int8)bodyB->m_shape->m_type.m_storage;
  v17 = (hkpShapeContainer *)v14;
  for ( i = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14); i != -1; i = v17->vfptr->getNextKey(
                                                                                               v17,
                                                                                               i) )
  {
    if ( input->m_filter.m_storage->vfptr->isCollisionEnabled(
           &input->m_filter.m_storage->hkpShapeCollectionFilter,
           &v30,
           input,
           bodyB,
           bodyA,
           v17,
           i)->m_bool )
    {
      v19 = (__int64)v17->vfptr->getChildShape(v17, i, (char (*)[512])v29);
      v20 = input->m_dispatcher.m_storage;
      v26 = i;
      v25 = v19;
      v20->m_agent2Func[(unsigned __int8)v20->m_agent2Types[*(unsigned __int8 *)(v19 + 16)][m_storage]].m_getPenetrationsFunc(
        (hkpCdBody *)&v25,
        bodyB,
        input,
        collector);
      if ( collector->m_earlyOut.m_bool )
        break;
    }
  }
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v23 = __rdtsc();
    v24 = v22 + 2;
    *((_DWORD *)v24 - 2) = v23;
    v21[1] = v24;
  }
}

// File Line: 339
// RVA: 0xCF44D0
void __fastcall hkpShapeCollectionAgent::updateShapeCollectionFilter(
        hkpShapeCollectionAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpConstraintOwner *constraintOwner)
{
  const void *m_motion; // rax
  hkpShape *m_shape; // rcx
  hkpShapeContainer *v10; // r14
  unsigned int i; // esi
  __int64 m_size; // rcx
  int v13; // edi
  __int64 v14; // rbx
  hkpShapeCollectionAgent::KeyAgentPair *m_data; // rax
  __int64 v16; // rax
  hkpShapeCollectionAgent::KeyAgentPair *v17; // rdi
  hkpCollisionDispatcher *m_storage; // r10
  char (*m_agent2TypesPred)[35]; // rdx
  hkpCollisionAgent *m_agent; // rcx
  __int64 v21; // rbx
  hkpCollisionAgent *v22; // rcx
  __int64 v23; // rcx
  __int64 v24; // rdx
  __int64 v25; // r8
  hkpShapeCollectionAgent::KeyAgentPair *v26; // rcx
  __int64 v27; // r8
  hkpCollisionAgent *v28; // rax
  char v29[8]; // [rsp+40h] [rbp-258h] BYREF
  __int64 v30; // [rsp+48h] [rbp-250h] BYREF
  unsigned int v31; // [rsp+50h] [rbp-248h]
  const void *v32; // [rsp+58h] [rbp-240h]
  hkpCdBody *v33; // [rsp+60h] [rbp-238h]
  char v34[512]; // [rsp+70h] [rbp-228h] BYREF

  m_motion = bodyA->m_motion;
  m_shape = bodyA->m_shape;
  v33 = bodyA;
  v32 = m_motion;
  v10 = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))m_shape->vfptr[7].__vecDelDtor)(m_shape);
  for ( i = v10->vfptr->getFirstKey(v10); i != -1; i = v10->vfptr->getNextKey(v10, i) )
  {
    m_size = this->m_agents.m_size;
    v13 = 0;
    v14 = 0i64;
    if ( m_size <= 0 )
    {
LABEL_6:
      v13 = -1;
      v14 = -1i64;
    }
    else
    {
      m_data = this->m_agents.m_data;
      while ( m_data->m_key != i )
      {
        ++v14;
        ++v13;
        ++m_data;
        if ( v14 >= m_size )
          goto LABEL_6;
      }
    }
    if ( input->m_filter.m_storage->vfptr->isCollisionEnabled(
           &input->m_filter.m_storage->hkpShapeCollectionFilter,
           v29,
           input,
           bodyB,
           bodyA,
           v10,
           i)->m_bool )
    {
      v16 = (__int64)v10->vfptr->getChildShape(v10, i, (char (*)[512])v34);
      v31 = i;
      v30 = v16;
      if ( v14 == -1 )
      {
        if ( this->m_agents.m_size == (this->m_agents.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_agents.m_data, 16);
        v17 = &this->m_agents.m_data[this->m_agents.m_size++];
        v17->m_key = i;
        m_storage = input->m_dispatcher.m_storage;
        m_agent2TypesPred = input->m_dispatcher.m_storage->m_agent2TypesPred;
        if ( !input->m_createPredictiveAgents.m_storage )
          m_agent2TypesPred = m_storage->m_agent2Types;
        v17->m_agent = m_storage->m_agent2Func[(unsigned __int8)m_agent2TypesPred[*(unsigned __int8 *)(v30 + 16)][(unsigned __int8)bodyB->m_shape->m_type.m_storage]].m_createFunc(
                         (hkpCdBody *)&v30,
                         bodyB,
                         input,
                         this->m_contactMgr);
      }
      else
      {
        m_agent = this->m_agents.m_data[v14].m_agent;
        ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpConstraintOwner *))m_agent->vfptr[4].__vecDelDtor)(
          m_agent,
          &v30,
          bodyB,
          input,
          constraintOwner);
      }
    }
    else if ( v14 != -1 )
    {
      v21 = v14;
      v22 = this->m_agents.m_data[v21].m_agent;
      ((void (__fastcall *)(hkpCollisionAgent *, hkpConstraintOwner *))v22->vfptr[3].__first_virtual_table_function__)(
        v22,
        constraintOwner);
      v23 = --this->m_agents.m_size;
      if ( (_DWORD)v23 != v13 )
      {
        v24 = 2i64;
        v25 = 16 * v23;
        v26 = &this->m_agents.m_data[v21];
        v27 = v25 - 4 * v21;
        do
        {
          v28 = *(hkpCollisionAgent **)((char *)&v26->m_key + v27);
          v26 = (hkpShapeCollectionAgent::KeyAgentPair *)((char *)v26 + 8);
          v26[-1].m_agent = v28;
          --v24;
        }
        while ( v24 );
      }
    }
  }
}


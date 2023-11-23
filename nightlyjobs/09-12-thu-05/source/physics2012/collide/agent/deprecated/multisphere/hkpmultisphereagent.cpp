// File Line: 15
// RVA: 0xD28AA0
void __fastcall hkpMultiSphereAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpMultiSphereAgent::createListBAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMultiSphereAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpMultiSphereAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpMultiSphereAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, ALL_SHAPE_TYPES, MULTI_SPHERE);
  f.m_createFunc = hkpMultiSphereAgent::createListAAgent;
  f.m_getPenetrationsFunc = hkpMultiSphereAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpMultiSphereAgent::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  f.m_linearCastFunc = hkpMultiSphereAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, MULTI_SPHERE, ALL_SHAPE_TYPES);
}

// File Line: 42
// RVA: 0xD29BE0
void __fastcall hkpMultiSphereAgent::createListAAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpMultiSphereAgent *v9; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpMultiSphereAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 104i64);
  if ( v9 )
    hkpMultiSphereAgent::hkpMultiSphereAgent(v9, bodyA, bodyB, input, mgr);
}

// File Line: 51
// RVA: 0xD29C60
hkpMultiSphereAgent *__fastcall hkpMultiSphereAgent::createListBAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpMultiSphereAgent *result; // rax
  hkpMultiSphereAgent *v10; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpMultiSphereAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 104i64);
  v10 = result;
  if ( result )
  {
    hkpMultiSphereAgent::hkpMultiSphereAgent(result, bodyB, bodyA, input, mgr);
    v10->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpMultiSphereAgent>::`vftable;
    return v10;
  }
  return result;
}

// File Line: 60
// RVA: 0xD29930
void __fastcall hkpMultiSphereAgent::hkpMultiSphereAgent(
        hkpMultiSphereAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  hkInplaceArray<hkpMultiSphereAgent::KeyAgentPair,4,hkContainerHeapAllocator> *p_m_agents; // r15
  int v6; // ebx
  int vfptr; // ebp
  __int64 v11; // rdi
  int v12; // r9d
  __m128 *m_motion; // rdx
  __m128 *v14; // rcx
  __m128 v15; // xmm0
  __m128 *p_m_type; // rsi
  __m128 *v17; // rax
  int m_size; // ecx
  __int64 v19; // rdi
  __m128 v20; // xmm2
  float v21; // xmm0_4
  __int64 m_storage; // rcx
  hkpCollisionDispatcher *v23; // r10
  char (*m_agent2TypesPred)[35]; // rdx
  __int64 v25; // rax
  hkResult result; // [rsp+30h] [rbp-158h] BYREF
  hkpShape *m_shape; // [rsp+38h] [rbp-150h]
  hkpSphereShape *v28; // [rsp+40h] [rbp-148h] BYREF
  int v29; // [rsp+48h] [rbp-140h]
  __m128 *v30; // [rsp+50h] [rbp-138h]
  hkpCdBody *v31; // [rsp+58h] [rbp-130h]
  hkpSphereShape v32; // [rsp+60h] [rbp-128h] BYREF
  __m128 Dst[14]; // [rsp+A0h] [rbp-E8h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  p_m_agents = &this->m_agents;
  this->m_contactMgr = mgr;
  v6 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMultiSphereAgent::`vftable;
  this->m_agents.m_size = 0;
  this->m_agents.m_capacityAndFlags = -2147483644;
  this->m_agents.m_data = this->m_agents.m_storage;
  vfptr = (int)bodyA->m_shape[1].vfptr;
  v11 = 1i64;
  m_shape = bodyA->m_shape;
  if ( vfptr > 4 )
  {
    v12 = vfptr;
    if ( vfptr < 8 )
      v12 = 8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_agents->m_data, v12, 16);
  }
  hkpSphereShape::hkpSphereShape(&v32, 0.0);
  m_motion = (__m128 *)bodyA->m_motion;
  v14 = Dst;
  if ( (((unsigned __int8)Dst | (unsigned __int8)m_motion) & 0xF) != 0 )
  {
    memmove(Dst, m_motion, 0xB0ui64);
  }
  else
  {
    do
    {
      v15 = *m_motion;
      v14 += 8;
      m_motion += 8;
      v14[-8] = v15;
      v14[-7] = m_motion[-7];
      v14[-6] = m_motion[-6];
      v14[-5] = m_motion[-5];
      v14[-4] = m_motion[-4];
      v14[-3] = m_motion[-3];
      v14[-2] = m_motion[-2];
      v14[-1] = m_motion[-1];
      --v11;
    }
    while ( v11 );
    *v14 = *m_motion;
    v14[1] = m_motion[1];
    v14[2] = m_motion[2];
  }
  v31 = bodyA;
  p_m_type = (__m128 *)&m_shape[1].m_type;
  v30 = Dst;
  if ( vfptr > 0 )
  {
    do
    {
      v17 = (__m128 *)bodyA->m_motion;
      m_size = p_m_agents->m_size;
      v19 = (__int64)&p_m_agents->m_data[m_size];
      v20 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*p_m_type, *p_m_type, 85), Dst[1]),
                _mm_mul_ps(_mm_shuffle_ps(*p_m_type, *p_m_type, 0), Dst[0])),
              _mm_mul_ps(_mm_shuffle_ps(*p_m_type, *p_m_type, 170), Dst[2]));
      Dst[3] = _mm_add_ps(v17[3], v20);
      Dst[4] = _mm_add_ps(v17[4], v20);
      Dst[5] = _mm_add_ps(v17[5], v20);
      v21 = p_m_type->m128_f32[3];
      v28 = &v32;
      LODWORD(v17) = m_size + 1;
      m_storage = (unsigned __int8)v32.m_type.m_storage;
      v29 = v6;
      v32.m_radius = v21;
      p_m_agents->m_size = (int)v17;
      v23 = input->m_dispatcher.m_storage;
      m_agent2TypesPred = input->m_dispatcher.m_storage->m_agent2TypesPred;
      if ( !input->m_createPredictiveAgents.m_storage )
        m_agent2TypesPred = v23->m_agent2Types;
      v25 = (__int64)v23->m_agent2Func[(unsigned __int8)m_agent2TypesPred[m_storage][(unsigned __int8)bodyB->m_shape->m_type.m_storage]].m_createFunc(
                       (hkpCdBody *)&v28,
                       bodyB,
                       input,
                       mgr);
      *(_DWORD *)v19 = v6++;
      ++p_m_type;
      *(_QWORD *)(v19 + 8) = v25;
    }
    while ( v6 < vfptr );
  }
}

// File Line: 99
// RVA: 0xD298B0
void __fastcall hkpMultiSphereAgent::cleanup(hkpMultiSphereAgent *this, hkpConstraintOwner *info)
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

// File Line: 110
// RVA: 0xD28B50
void __fastcall hkpMultiSphereAgent::processCollision(
        hkpMultiSphereAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *result)
{
  hkpShape *m_shape; // r12
  __m128 *m_motion; // rdx
  __m128 *v8; // r10
  __int64 v12; // rax
  __m128 v13; // xmm0
  hkpMultiSphereAgent::KeyAgentPair *m_data; // rsi
  int v15; // ebx
  __m128 *v16; // rax
  __int64 v17; // rcx
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  float v20; // xmm0_4
  hkpSphereShape *v21; // [rsp+30h] [rbp-128h] BYREF
  int v22; // [rsp+38h] [rbp-120h]
  __m128 *i; // [rsp+40h] [rbp-118h]
  hkpCdBody *v24; // [rsp+48h] [rbp-110h]
  hkpSphereShape v25; // [rsp+50h] [rbp-108h] BYREF
  __m128 Dst[11]; // [rsp+90h] [rbp-C8h] BYREF

  m_shape = bodyA->m_shape;
  m_motion = (__m128 *)bodyA->m_motion;
  v8 = Dst;
  if ( (((unsigned __int8)Dst | (unsigned __int8)m_motion) & 0xF) != 0 )
  {
    memmove(Dst, m_motion, 0xB0ui64);
  }
  else
  {
    v12 = 1i64;
    do
    {
      v13 = *m_motion;
      v8 += 8;
      m_motion += 8;
      v8[-8] = v13;
      v8[-7] = m_motion[-7];
      v8[-6] = m_motion[-6];
      v8[-5] = m_motion[-5];
      v8[-4] = m_motion[-4];
      v8[-3] = m_motion[-3];
      v8[-2] = m_motion[-2];
      v8[-1] = m_motion[-1];
      --v12;
    }
    while ( v12 );
    *v8 = *m_motion;
    v8[1] = m_motion[1];
    v8[2] = m_motion[2];
  }
  hkpSphereShape::hkpSphereShape(&v25, 0.0);
  m_data = this->m_agents.m_data;
  v15 = this->m_agents.m_size - 1;
  v24 = bodyA;
  for ( i = Dst; v15 >= 0; --v15 )
  {
    v16 = (__m128 *)bodyA->m_motion;
    v17 = 2 * (m_data->m_key + 3i64);
    v18 = *((__m128 *)&m_shape[1].m_type.m_storage + m_data->m_key);
    v19 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), Dst[1]),
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), Dst[0])),
            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), Dst[2]));
    Dst[3] = _mm_add_ps(v16[3], v19);
    Dst[4] = _mm_add_ps(v16[4], v19);
    Dst[5] = _mm_add_ps(v16[5], v19);
    v20 = *(float *)(&m_shape->m_referenceCount + 4 * v17 + 1);
    v21 = &v25;
    v25.m_radius = v20;
    v22 = v15;
    ((void (__fastcall *)(hkpCollisionAgent *, hkpSphereShape **, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))m_data->m_agent->vfptr[3].__vecDelDtor)(
      m_data->m_agent,
      &v21,
      bodyB,
      input,
      result);
    ++m_data;
  }
}

// File Line: 151
// RVA: 0xD29130
void __fastcall hkpMultiSphereAgent::getClosestPoints(
        hkpMultiSphereAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  hkpShape *m_shape; // r12
  __m128 *m_motion; // rdx
  __m128 *v8; // r10
  __int64 v12; // rax
  __m128 v13; // xmm0
  hkpMultiSphereAgent::KeyAgentPair *m_data; // rsi
  int v15; // ebx
  __int64 v16; // rcx
  __m128 v17; // xmm1
  float v18; // xmm0_4
  hkpSphereShape *v19; // [rsp+30h] [rbp-128h] BYREF
  int v20; // [rsp+38h] [rbp-120h]
  __m128 *i; // [rsp+40h] [rbp-118h]
  hkpCdBody *v22; // [rsp+48h] [rbp-110h]
  hkpSphereShape v23; // [rsp+50h] [rbp-108h] BYREF
  __m128 Dst[11]; // [rsp+90h] [rbp-C8h] BYREF

  m_shape = bodyA->m_shape;
  m_motion = (__m128 *)bodyA->m_motion;
  v8 = Dst;
  if ( (((unsigned __int8)Dst | (unsigned __int8)m_motion) & 0xF) != 0 )
  {
    memmove(Dst, m_motion, 0xB0ui64);
  }
  else
  {
    v12 = 1i64;
    do
    {
      v13 = *m_motion;
      v8 += 8;
      m_motion += 8;
      v8[-8] = v13;
      v8[-7] = m_motion[-7];
      v8[-6] = m_motion[-6];
      v8[-5] = m_motion[-5];
      v8[-4] = m_motion[-4];
      v8[-3] = m_motion[-3];
      v8[-2] = m_motion[-2];
      v8[-1] = m_motion[-1];
      --v12;
    }
    while ( v12 );
    *v8 = *m_motion;
    v8[1] = m_motion[1];
    v8[2] = m_motion[2];
  }
  hkpSphereShape::hkpSphereShape(&v23, 0.0);
  m_data = this->m_agents.m_data;
  v15 = this->m_agents.m_size - 1;
  v22 = bodyA;
  for ( i = Dst; v15 >= 0; --v15 )
  {
    v16 = 2 * (m_data->m_key + 3i64);
    v17 = *((__m128 *)&m_shape[1].m_type.m_storage + m_data->m_key);
    Dst[3] = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), Dst[1]),
                   _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), Dst[0])),
                 _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), Dst[2])),
               *((__m128 *)bodyA->m_motion + 3));
    v18 = *(float *)(&m_shape->m_referenceCount + 4 * v16 + 1);
    v19 = &v23;
    v23.m_radius = v18;
    v20 = v15;
    ((void (__fastcall *)(hkpCollisionAgent *, hkpSphereShape **, hkpCdBody *, hkpCollisionInput *, hkpCdPointCollector *))m_data->m_agent->vfptr[2].__vecDelDtor)(
      m_data->m_agent,
      &v19,
      bodyB,
      input,
      collector);
    ++m_data;
  }
}

// File Line: 184
// RVA: 0xD29300
void __fastcall hkpMultiSphereAgent::staticGetClosestPoints(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  hkpShape *m_shape; // rsi
  __m128 *m_motion; // rdx
  __m128 *v7; // r10
  __int64 v11; // rax
  __m128 v12; // xmm0
  int v13; // ebp
  __int64 m_storage; // r15
  __m128 *p_m_type; // rdi
  hkpCollisionDispatcher *v16; // r11
  float v17; // xmm0_4
  hkpSphereShape *v18; // [rsp+20h] [rbp-138h] BYREF
  int v19; // [rsp+28h] [rbp-130h]
  __m128 *v20; // [rsp+30h] [rbp-128h]
  hkpCdBody *v21; // [rsp+38h] [rbp-120h]
  hkpSphereShape v22; // [rsp+40h] [rbp-118h] BYREF
  __m128 Dst[11]; // [rsp+80h] [rbp-D8h] BYREF

  m_shape = bodyA->m_shape;
  m_motion = (__m128 *)bodyA->m_motion;
  v7 = Dst;
  if ( (((unsigned __int8)Dst | (unsigned __int8)m_motion) & 0xF) != 0 )
  {
    memmove(Dst, m_motion, 0xB0ui64);
  }
  else
  {
    v11 = 1i64;
    do
    {
      v12 = *m_motion;
      v7 += 8;
      m_motion += 8;
      v7[-8] = v12;
      v7[-7] = m_motion[-7];
      v7[-6] = m_motion[-6];
      v7[-5] = m_motion[-5];
      v7[-4] = m_motion[-4];
      v7[-3] = m_motion[-3];
      v7[-2] = m_motion[-2];
      v7[-1] = m_motion[-1];
      --v11;
    }
    while ( v11 );
    *v7 = *m_motion;
    v7[1] = m_motion[1];
    v7[2] = m_motion[2];
  }
  hkpSphereShape::hkpSphereShape(&v22, 0.0);
  v21 = bodyA;
  v20 = Dst;
  v13 = 0;
  m_storage = (unsigned __int8)bodyB->m_shape->m_type.m_storage;
  if ( SLODWORD(m_shape[1].vfptr) > 0 )
  {
    p_m_type = (__m128 *)&m_shape[1].m_type;
    do
    {
      v16 = input->m_dispatcher.m_storage;
      Dst[3] = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(*p_m_type, *p_m_type, 85), Dst[1]),
                     _mm_mul_ps(_mm_shuffle_ps(*p_m_type, *p_m_type, 0), Dst[0])),
                   _mm_mul_ps(_mm_shuffle_ps(*p_m_type, *p_m_type, 170), Dst[2])),
                 *((__m128 *)bodyA->m_motion + 3));
      v17 = p_m_type->m128_f32[3];
      v18 = &v22;
      v19 = v13;
      v22.m_radius = v17;
      v16->m_agent2Func[(unsigned __int8)v16->m_agent2Types[(unsigned __int8)v22.m_type.m_storage][m_storage]].m_getClosestPointFunc(
        (hkpCdBody *)&v18,
        bodyB,
        input,
        collector);
      ++v13;
      ++p_m_type;
    }
    while ( v13 < SLODWORD(m_shape[1].vfptr) );
  }
}

// File Line: 218
// RVA: 0xD28D40
void __fastcall hkpMultiSphereAgent::linearCast(
        hkpMultiSphereAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  hkpShape *m_shape; // rbp
  __m128 *m_motion; // rdx
  __m128 *v9; // r10
  __int64 v13; // rax
  __m128 v14; // xmm0
  hkpMultiSphereAgent::KeyAgentPair *m_data; // r15
  int v16; // edi
  __m128 *v17; // rbx
  float v18; // xmm0_4
  hkpSphereShape *v19; // [rsp+30h] [rbp-138h] BYREF
  int v20; // [rsp+38h] [rbp-130h]
  __m128 *v21; // [rsp+40h] [rbp-128h]
  hkpCdBody *v22; // [rsp+48h] [rbp-120h]
  hkpSphereShape v23; // [rsp+50h] [rbp-118h] BYREF
  __m128 Dst[11]; // [rsp+90h] [rbp-D8h] BYREF

  m_shape = bodyA->m_shape;
  m_motion = (__m128 *)bodyA->m_motion;
  v9 = Dst;
  if ( (((unsigned __int8)Dst | (unsigned __int8)m_motion) & 0xF) != 0 )
  {
    memmove(Dst, m_motion, 0xB0ui64);
  }
  else
  {
    v13 = 1i64;
    do
    {
      v14 = *m_motion;
      v9 += 8;
      m_motion += 8;
      v9[-8] = v14;
      v9[-7] = m_motion[-7];
      v9[-6] = m_motion[-6];
      v9[-5] = m_motion[-5];
      v9[-4] = m_motion[-4];
      v9[-3] = m_motion[-3];
      v9[-2] = m_motion[-2];
      v9[-1] = m_motion[-1];
      --v13;
    }
    while ( v13 );
    *v9 = *m_motion;
    v9[1] = m_motion[1];
    v9[2] = m_motion[2];
  }
  hkpSphereShape::hkpSphereShape(&v23, 0.0);
  m_data = this->m_agents.m_data;
  v16 = this->m_agents.m_size - 1;
  v22 = bodyA;
  v21 = Dst;
  if ( v16 >= 0 )
  {
    v17 = (__m128 *)(&m_shape[1].m_type + 16 * v16);
    do
    {
      Dst[3] = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 85), Dst[1]),
                     _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 0), Dst[0])),
                   _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 170), Dst[2])),
                 *((__m128 *)bodyA->m_motion + 3));
      v18 = v17->m128_f32[3];
      v19 = &v23;
      v23.m_radius = v18;
      v20 = v16;
      ((void (__fastcall *)(hkpCollisionAgent *, hkpSphereShape **, hkpCdBody *, hkpLinearCastCollisionInput *, hkpCdPointCollector *, hkpCdPointCollector *))m_data->m_agent->vfptr[2].__first_virtual_table_function__)(
        m_data->m_agent,
        &v19,
        bodyB,
        input,
        collector,
        startCollector);
      --v17;
      --v16;
    }
    while ( v16 >= 0 );
  }
}

// File Line: 248
// RVA: 0xD28F30
void __fastcall hkpMultiSphereAgent::staticLinearCast(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  hkpShape *m_shape; // rsi
  __m128 *m_motion; // rdx
  __m128 *v8; // r10
  __int64 v11; // rax
  __m128 v12; // xmm0
  int v13; // ebp
  __int64 m_storage; // r12
  __m128 *p_m_type; // rdi
  hkpCollisionDispatcher *v16; // r11
  float v17; // xmm0_4
  hkpSphereShape *v18; // [rsp+30h] [rbp-138h] BYREF
  int v19; // [rsp+38h] [rbp-130h]
  __m128 *v20; // [rsp+40h] [rbp-128h]
  hkpCdBody *v21; // [rsp+48h] [rbp-120h]
  hkpSphereShape v22; // [rsp+50h] [rbp-118h] BYREF
  __m128 Dst[13]; // [rsp+90h] [rbp-D8h] BYREF

  m_shape = bodyA->m_shape;
  m_motion = (__m128 *)bodyA->m_motion;
  v8 = Dst;
  if ( (((unsigned __int8)Dst | (unsigned __int8)m_motion) & 0xF) != 0 )
  {
    memmove(Dst, m_motion, 0xB0ui64);
  }
  else
  {
    v11 = 1i64;
    do
    {
      v12 = *m_motion;
      v8 += 8;
      m_motion += 8;
      v8[-8] = v12;
      v8[-7] = m_motion[-7];
      v8[-6] = m_motion[-6];
      v8[-5] = m_motion[-5];
      v8[-4] = m_motion[-4];
      v8[-3] = m_motion[-3];
      v8[-2] = m_motion[-2];
      v8[-1] = m_motion[-1];
      --v11;
    }
    while ( v11 );
    *v8 = *m_motion;
    v8[1] = m_motion[1];
    v8[2] = m_motion[2];
  }
  hkpSphereShape::hkpSphereShape(&v22, 0.0);
  v21 = bodyA;
  v20 = Dst;
  v13 = 0;
  m_storage = (unsigned __int8)bodyB->m_shape->m_type.m_storage;
  if ( SLODWORD(m_shape[1].vfptr) > 0 )
  {
    p_m_type = (__m128 *)&m_shape[1].m_type;
    do
    {
      v16 = input->m_dispatcher.m_storage;
      Dst[3] = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(*p_m_type, *p_m_type, 85), Dst[1]),
                     _mm_mul_ps(_mm_shuffle_ps(*p_m_type, *p_m_type, 0), Dst[0])),
                   _mm_mul_ps(_mm_shuffle_ps(*p_m_type, *p_m_type, 170), Dst[2])),
                 *((__m128 *)bodyA->m_motion + 3));
      v17 = p_m_type->m128_f32[3];
      v18 = &v22;
      v19 = v13;
      v22.m_radius = v17;
      v16->m_agent2Func[(unsigned __int8)v16->m_agent2Types[(unsigned __int8)v22.m_type.m_storage][m_storage]].m_linearCastFunc(
        (hkpCdBody *)&v18,
        bodyB,
        input,
        collector,
        startCollector);
      ++v13;
      ++p_m_type;
    }
    while ( v13 < SLODWORD(m_shape[1].vfptr) );
  }
}

// File Line: 280
// RVA: 0xD294E0
void __fastcall hkpMultiSphereAgent::getPenetrations(
        hkpMultiSphereAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpShape *m_shape; // r12
  __m128 *m_motion; // rdx
  __m128 *v8; // r10
  __int64 v12; // rax
  __m128 v13; // xmm0
  hkpMultiSphereAgent::KeyAgentPair *m_data; // rdi
  int v15; // ebx
  __int64 v16; // rcx
  __m128 v17; // xmm1
  float v18; // xmm0_4
  hkpSphereShape *v19; // [rsp+30h] [rbp-128h] BYREF
  int v20; // [rsp+38h] [rbp-120h]
  __m128 *i; // [rsp+40h] [rbp-118h]
  hkpCdBody *v22; // [rsp+48h] [rbp-110h]
  hkpSphereShape v23; // [rsp+50h] [rbp-108h] BYREF
  __m128 Dst[11]; // [rsp+90h] [rbp-C8h] BYREF

  m_shape = bodyA->m_shape;
  m_motion = (__m128 *)bodyA->m_motion;
  v8 = Dst;
  if ( (((unsigned __int8)Dst | (unsigned __int8)m_motion) & 0xF) != 0 )
  {
    memmove(Dst, m_motion, 0xB0ui64);
  }
  else
  {
    v12 = 1i64;
    do
    {
      v13 = *m_motion;
      v8 += 8;
      m_motion += 8;
      v8[-8] = v13;
      v8[-7] = m_motion[-7];
      v8[-6] = m_motion[-6];
      v8[-5] = m_motion[-5];
      v8[-4] = m_motion[-4];
      v8[-3] = m_motion[-3];
      v8[-2] = m_motion[-2];
      v8[-1] = m_motion[-1];
      --v12;
    }
    while ( v12 );
    *v8 = *m_motion;
    v8[1] = m_motion[1];
    v8[2] = m_motion[2];
  }
  hkpSphereShape::hkpSphereShape(&v23, 0.0);
  m_data = this->m_agents.m_data;
  v15 = this->m_agents.m_size - 1;
  v22 = bodyA;
  for ( i = Dst; v15 >= 0; --v15 )
  {
    v16 = 2 * (m_data->m_key + 3i64);
    v17 = *((__m128 *)&m_shape[1].m_type.m_storage + m_data->m_key);
    Dst[3] = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), Dst[1]),
                   _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), Dst[0])),
                 _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), Dst[2])),
               *((__m128 *)bodyA->m_motion + 3));
    v18 = *(float *)(&m_shape->m_referenceCount + 4 * v16 + 1);
    v19 = &v23;
    v23.m_radius = v18;
    v20 = v15;
    ((void (__fastcall *)(hkpCollisionAgent *, hkpSphereShape **, hkpCdBody *, hkpCollisionInput *, hkpCdBodyPairCollector *))m_data->m_agent->vfptr[1].__first_virtual_table_function__)(
      m_data->m_agent,
      &v19,
      bodyB,
      input,
      collector);
    if ( collector->m_earlyOut.m_bool )
      break;
    ++m_data;
  }
}

// File Line: 313
// RVA: 0xD296C0
void __fastcall hkpMultiSphereAgent::staticGetPenetrations(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpShape *m_shape; // rsi
  __m128 *m_motion; // rdx
  __m128 *v7; // r10
  __int64 v11; // rax
  __m128 v12; // xmm0
  int v13; // ebx
  __int64 m_storage; // rbp
  __m128 *p_m_type; // rdi
  hkpCollisionDispatcher *v16; // r11
  float v17; // xmm0_4
  hkpSphereShape *v18; // [rsp+20h] [rbp-138h] BYREF
  int v19; // [rsp+28h] [rbp-130h]
  __m128 *v20; // [rsp+30h] [rbp-128h]
  hkpCdBody *v21; // [rsp+38h] [rbp-120h]
  hkpSphereShape v22; // [rsp+40h] [rbp-118h] BYREF
  __m128 Dst[11]; // [rsp+80h] [rbp-D8h] BYREF

  m_shape = bodyA->m_shape;
  m_motion = (__m128 *)bodyA->m_motion;
  v7 = Dst;
  if ( (((unsigned __int8)Dst | (unsigned __int8)m_motion) & 0xF) != 0 )
  {
    memmove(Dst, m_motion, 0xB0ui64);
  }
  else
  {
    v11 = 1i64;
    do
    {
      v12 = *m_motion;
      v7 += 8;
      m_motion += 8;
      v7[-8] = v12;
      v7[-7] = m_motion[-7];
      v7[-6] = m_motion[-6];
      v7[-5] = m_motion[-5];
      v7[-4] = m_motion[-4];
      v7[-3] = m_motion[-3];
      v7[-2] = m_motion[-2];
      v7[-1] = m_motion[-1];
      --v11;
    }
    while ( v11 );
    *v7 = *m_motion;
    v7[1] = m_motion[1];
    v7[2] = m_motion[2];
  }
  hkpSphereShape::hkpSphereShape(&v22, 0.0);
  v21 = bodyA;
  v20 = Dst;
  v13 = 0;
  m_storage = (unsigned __int8)bodyB->m_shape->m_type.m_storage;
  if ( SLODWORD(m_shape[1].vfptr) > 0 )
  {
    p_m_type = (__m128 *)&m_shape[1].m_type;
    do
    {
      v16 = input->m_dispatcher.m_storage;
      Dst[3] = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(*p_m_type, *p_m_type, 85), Dst[1]),
                     _mm_mul_ps(_mm_shuffle_ps(*p_m_type, *p_m_type, 0), Dst[0])),
                   _mm_mul_ps(_mm_shuffle_ps(*p_m_type, *p_m_type, 170), Dst[2])),
                 *((__m128 *)bodyA->m_motion + 3));
      v17 = p_m_type->m128_f32[3];
      v18 = &v22;
      v19 = v13;
      v22.m_radius = v17;
      v16->m_agent2Func[(unsigned __int8)v16->m_agent2Types[(unsigned __int8)v22.m_type.m_storage][m_storage]].m_getPenetrationsFunc(
        (hkpCdBody *)&v18,
        bodyB,
        input,
        collector);
      if ( collector->m_earlyOut.m_bool )
        break;
      ++v13;
      ++p_m_type;
    }
    while ( v13 < SLODWORD(m_shape[1].vfptr) );
  }
}


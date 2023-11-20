// File Line: 15
// RVA: 0xD28AA0
void __fastcall hkpMultiSphereAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  f.m_createFunc = hkpMultiSphereAgent::createListBAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMultiSphereAgent>::staticGetPenetrations;
  v1 = dispatcher;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpMultiSphereAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpMultiSphereAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, ALL_SHAPE_TYPES, MULTI_SPHERE);
  f.m_createFunc = hkpMultiSphereAgent::createListAAgent;
  f.m_getPenetrationsFunc = hkpMultiSphereAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpMultiSphereAgent::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  f.m_linearCastFunc = hkpMultiSphereAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, MULTI_SPHERE, ALL_SHAPE_TYPES);
}

// File Line: 42
// RVA: 0xD29BE0
void __fastcall hkpMultiSphereAgent::createListAAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCdBody *v4; // rbp
  hkpContactMgr *v5; // rbx
  hkpCollisionInput *v6; // rdi
  hkpCdBody *v7; // rsi
  _QWORD **v8; // rax
  hkpMultiSphereAgent *v9; // rax

  v4 = bodyA;
  v5 = mgr;
  v6 = input;
  v7 = bodyB;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpMultiSphereAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 104i64);
  if ( v9 )
    hkpMultiSphereAgent::hkpMultiSphereAgent(v9, v4, v7, v6, v5);
}

// File Line: 51
// RVA: 0xD29C60
hkpMultiSphereAgent *__fastcall hkpMultiSphereAgent::createListBAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCdBody *v4; // r14
  hkpContactMgr *v5; // rdi
  hkpCollisionInput *v6; // rsi
  hkpCdBody *v7; // rbp
  _QWORD **v8; // rax
  hkpMultiSphereAgent *result; // rax
  hkpCollisionAgent *v10; // rbx

  v4 = bodyA;
  v5 = mgr;
  v6 = input;
  v7 = bodyB;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpMultiSphereAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 104i64);
  v10 = (hkpCollisionAgent *)&result->vfptr;
  if ( result )
  {
    hkpMultiSphereAgent::hkpMultiSphereAgent(result, v7, v4, v6, v5);
    v10->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpMultiSphereAgent>::`vftable';
    result = (hkpMultiSphereAgent *)v10;
  }
  return result;
}

// File Line: 60
// RVA: 0xD29930
void __fastcall hkpMultiSphereAgent::hkpMultiSphereAgent(hkpMultiSphereAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkInplaceArray<hkpMultiSphereAgent::KeyAgentPair,4,hkContainerHeapAllocator> *v5; // r15
  int v6; // ebx
  signed int v7; // ebp
  hkpCollisionInput *v8; // r12
  hkpCdBody *v9; // r13
  hkpCdBody *v10; // rsi
  signed __int64 v11; // rdi
  int v12; // er9
  __m128 *v13; // rdx
  __m128 *v14; // rcx
  __m128 v15; // xmm0
  __m128 *v16; // rsi
  __m128 *v17; // rax
  int v18; // ecx
  signed __int64 v19; // rdi
  __m128 v20; // xmm2
  float v21; // xmm0_4
  __int64 v22; // rcx
  hkpCollisionDispatcher *v23; // r10
  signed __int64 v24; // rdx
  __int64 v25; // rax
  hkResult result; // [rsp+30h] [rbp-158h]
  hkpShape *v27; // [rsp+38h] [rbp-150h]
  hkpSphereShape *v28; // [rsp+40h] [rbp-148h]
  int v29; // [rsp+48h] [rbp-140h]
  __m128 *v30; // [rsp+50h] [rbp-138h]
  hkpCdBody *v31; // [rsp+58h] [rbp-130h]
  hkpSphereShape v32; // [rsp+60h] [rbp-128h]
  __m128 Dst; // [rsp+A0h] [rbp-E8h]
  __m128 v34; // [rsp+B0h] [rbp-D8h]
  __m128 v35; // [rsp+C0h] [rbp-C8h]
  __m128 v36; // [rsp+D0h] [rbp-B8h]
  __m128 v37; // [rsp+E0h] [rbp-A8h]
  __m128 v38; // [rsp+F0h] [rbp-98h]
  hkpCdBody *v39; // [rsp+198h] [rbp+10h]

  v39 = bodyA;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v5 = &this->m_agents;
  this->m_contactMgr = mgr;
  v6 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMultiSphereAgent::`vftable';
  v5->m_size = 0;
  v5->m_capacityAndFlags = -2147483644;
  v5->m_data = this->m_agents.m_storage;
  v7 = (signed int)bodyA->m_shape[1].vfptr;
  v8 = input;
  v9 = bodyB;
  v10 = bodyA;
  v11 = 1i64;
  v27 = bodyA->m_shape;
  if ( v7 > 4 )
  {
    v12 = v7;
    if ( v7 < 8 )
      v12 = 8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, v12, 16);
  }
  hkpSphereShape::hkpSphereShape(&v32, 0.0);
  v13 = (__m128 *)v10->m_motion;
  v14 = &Dst;
  if ( ((unsigned __int8)&Dst | (unsigned __int8)v10->m_motion) & 0xF )
  {
    memmove(&Dst, v13, 0xB0ui64);
  }
  else
  {
    do
    {
      v15 = *v13;
      v14 += 8;
      v13 += 8;
      v14[-8] = v15;
      v14[-7] = v13[-7];
      v14[-6] = v13[-6];
      v14[-5] = v13[-5];
      v14[-4] = v13[-4];
      v14[-3] = v13[-3];
      v14[-2] = v13[-2];
      v14[-1] = v13[-1];
      --v11;
    }
    while ( v11 );
    *v14 = *v13;
    v14[1] = v13[1];
    v14[2] = v13[2];
  }
  v31 = v10;
  v16 = (__m128 *)&v27[1].m_type;
  v30 = &Dst;
  if ( v7 > 0 )
  {
    do
    {
      v17 = (__m128 *)v39->m_motion;
      v18 = v5->m_size;
      v19 = (signed __int64)&v5->m_data[v5->m_size];
      v20 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v16, *v16, 85), v34),
                _mm_mul_ps(_mm_shuffle_ps(*v16, *v16, 0), Dst)),
              _mm_mul_ps(_mm_shuffle_ps(*v16, *v16, 170), v35));
      v36 = _mm_add_ps(v17[3], v20);
      v37 = _mm_add_ps(v17[4], v20);
      v38 = _mm_add_ps(v17[5], v20);
      v21 = *((float *)&v16->m128_u64[1] + 1);
      v28 = &v32;
      LODWORD(v17) = v18 + 1;
      v22 = (unsigned __int8)v32.m_type.m_storage;
      v29 = v6;
      v32.m_radius = v21;
      v5->m_size = (signed int)v17;
      v23 = v8->m_dispatcher.m_storage;
      v24 = (signed __int64)v8->m_dispatcher.m_storage->m_agent2TypesPred;
      if ( !v8->m_createPredictiveAgents.m_storage )
        v24 = (signed __int64)v23->m_agent2Types;
      v25 = (__int64)v23->m_agent2Func[*(unsigned __int8 *)((unsigned __int8)v9->m_shape->m_type.m_storage
                                                          + v24
                                                          + 35 * v22)].m_createFunc(
                       (hkpCdBody *)&v28,
                       v9,
                       v8,
                       mgr);
      *(_DWORD *)v19 = v6++;
      ++v16;
      *(_QWORD *)(v19 + 8) = v25;
    }
    while ( v6 < v7 );
  }
}        mgr);
      *(_DWORD *)v19 = v6++;
      ++v16;
      *(_QWORD *)(v19 + 8) = v25;
    }
    while ( v6 < v7 

// File Line: 99
// RVA: 0xD298B0
void __fastcall hkpMultiSphereAgent::cleanup(hkpMultiSphereAgent *this, hkpConstraintOwner *info)
{
  int v2; // edi
  hkpConstraintOwner *v3; // rbp
  hkpMultiSphereAgent *v4; // rbx
  __int64 v5; // rsi
  hkpCollisionAgent *v6; // rcx

  v2 = 0;
  v3 = info;
  v4 = this;
  if ( this->m_agents.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v4->m_agents.m_data[v5].m_agent;
      ((void (__fastcall *)(hkpCollisionAgent *, hkpConstraintOwner *))v6->vfptr[3].__first_virtual_table_function__)(
        v6,
        v3);
      ++v2;
      ++v5;
    }
    while ( v2 < v4->m_agents.m_size );
  }
  v4->vfptr->__vecDelDtor((hkBaseObject *)&v4->vfptr, 1u);
}

// File Line: 110
// RVA: 0xD28B50
void __fastcall hkpMultiSphereAgent::processCollision(hkpMultiSphereAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *result)
{
  hkpShape *v5; // r12
  hkpCdBody *v6; // rdi
  __m128 *v7; // rdx
  __m128 *v8; // r10
  hkpMultiSphereAgent *v9; // rbx
  hkpProcessCollisionInput *v10; // r14
  hkpCdBody *v11; // r15
  signed __int64 v12; // rax
  __m128 v13; // xmm0
  hkpMultiSphereAgent::KeyAgentPair *v14; // rsi
  int v15; // ebx
  __m128 *v16; // rax
  signed __int64 v17; // rcx
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  float v20; // xmm0_4
  hkpSphereShape *v21; // [rsp+30h] [rbp-128h]
  int v22; // [rsp+38h] [rbp-120h]
  __m128 *i; // [rsp+40h] [rbp-118h]
  hkpCdBody *v24; // [rsp+48h] [rbp-110h]
  hkpSphereShape v25; // [rsp+50h] [rbp-108h]
  __m128 Dst; // [rsp+90h] [rbp-C8h]
  __m128 v27; // [rsp+A0h] [rbp-B8h]
  __m128 v28; // [rsp+B0h] [rbp-A8h]
  __m128 v29; // [rsp+C0h] [rbp-98h]
  __m128 v30; // [rsp+D0h] [rbp-88h]
  __m128 v31; // [rsp+E0h] [rbp-78h]

  v5 = bodyA->m_shape;
  v6 = bodyA;
  v7 = (__m128 *)bodyA->m_motion;
  v8 = &Dst;
  v9 = this;
  v10 = input;
  v11 = bodyB;
  if ( ((unsigned __int8)&Dst | (unsigned __int8)v7) & 0xF )
  {
    memmove(&Dst, v7, 0xB0ui64);
  }
  else
  {
    v12 = 1i64;
    do
    {
      v13 = *v7;
      v8 += 8;
      v7 += 8;
      v8[-8] = v13;
      v8[-7] = v7[-7];
      v8[-6] = v7[-6];
      v8[-5] = v7[-5];
      v8[-4] = v7[-4];
      v8[-3] = v7[-3];
      v8[-2] = v7[-2];
      v8[-1] = v7[-1];
      --v12;
    }
    while ( v12 );
    *v8 = *v7;
    v8[1] = v7[1];
    v8[2] = v7[2];
  }
  hkpSphereShape::hkpSphereShape(&v25, 0.0);
  v14 = v9->m_agents.m_data;
  v15 = v9->m_agents.m_size - 1;
  v24 = v6;
  for ( i = &Dst; v15 >= 0; --v15 )
  {
    v16 = (__m128 *)v6->m_motion;
    v17 = 2 * (v14->m_key + 3i64);
    v18 = *(__m128 *)&(&v5->vfptr)[2 * (v14->m_key + 3i64)];
    v19 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v27),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&(&v5->vfptr)[2 * (v14->m_key + 3i64)], v18, 0), Dst)),
            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v28));
    v29 = _mm_add_ps(v16[3], v19);
    v30 = _mm_add_ps(v16[4], v19);
    v31 = _mm_add_ps(v16[5], v19);
    v20 = *(float *)(&v5->m_referenceCount + 4 * v17 + 1);
    v21 = &v25;
    v25.m_radius = v20;
    v22 = v15;
    ((void (__fastcall *)(hkpCollisionAgent *, hkpSphereShape **, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v14->m_agent->vfptr[3].__vecDelDtor)(
      v14->m_agent,
      &v21,
      v11,
      v10,
      result);
    ++v14;
  }
}

// File Line: 151
// RVA: 0xD29130
void __fastcall hkpMultiSphereAgent::getClosestPoints(hkpMultiSphereAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpShape *v5; // r12
  hkpCdBody *v6; // rdi
  __m128 *v7; // rdx
  __m128 *v8; // r10
  hkpMultiSphereAgent *v9; // rbx
  hkpCollisionInput *v10; // r14
  hkpCdBody *v11; // r15
  signed __int64 v12; // rax
  __m128 v13; // xmm0
  hkpMultiSphereAgent::KeyAgentPair *v14; // rsi
  int v15; // ebx
  signed __int64 v16; // rcx
  __m128 v17; // xmm1
  float v18; // xmm0_4
  hkpSphereShape *v19; // [rsp+30h] [rbp-128h]
  int v20; // [rsp+38h] [rbp-120h]
  __m128 *i; // [rsp+40h] [rbp-118h]
  hkpCdBody *v22; // [rsp+48h] [rbp-110h]
  hkpSphereShape v23; // [rsp+50h] [rbp-108h]
  __m128 Dst; // [rsp+90h] [rbp-C8h]
  __m128 v25; // [rsp+A0h] [rbp-B8h]
  __m128 v26; // [rsp+B0h] [rbp-A8h]
  __m128 v27; // [rsp+C0h] [rbp-98h]

  v5 = bodyA->m_shape;
  v6 = bodyA;
  v7 = (__m128 *)bodyA->m_motion;
  v8 = &Dst;
  v9 = this;
  v10 = input;
  v11 = bodyB;
  if ( ((unsigned __int8)&Dst | (unsigned __int8)v7) & 0xF )
  {
    memmove(&Dst, v7, 0xB0ui64);
  }
  else
  {
    v12 = 1i64;
    do
    {
      v13 = *v7;
      v8 += 8;
      v7 += 8;
      v8[-8] = v13;
      v8[-7] = v7[-7];
      v8[-6] = v7[-6];
      v8[-5] = v7[-5];
      v8[-4] = v7[-4];
      v8[-3] = v7[-3];
      v8[-2] = v7[-2];
      v8[-1] = v7[-1];
      --v12;
    }
    while ( v12 );
    *v8 = *v7;
    v8[1] = v7[1];
    v8[2] = v7[2];
  }
  hkpSphereShape::hkpSphereShape(&v23, 0.0);
  v14 = v9->m_agents.m_data;
  v15 = v9->m_agents.m_size - 1;
  v22 = v6;
  for ( i = &Dst; v15 >= 0; --v15 )
  {
    v16 = 2 * (v14->m_key + 3i64);
    v17 = *(__m128 *)&(&v5->vfptr)[2 * (v14->m_key + 3i64)];
    v27 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), v25),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&(&v5->vfptr)[2 * (v14->m_key + 3i64)], v17, 0), Dst)),
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), v26)),
            *((__m128 *)v6->m_motion + 3));
    v18 = *(float *)(&v5->m_referenceCount + 4 * v16 + 1);
    v19 = &v23;
    v23.m_radius = v18;
    v20 = v15;
    ((void (__fastcall *)(hkpCollisionAgent *, hkpSphereShape **, hkpCdBody *, hkpCollisionInput *, hkpCdPointCollector *))v14->m_agent->vfptr[2].__vecDelDtor)(
      v14->m_agent,
      &v19,
      v11,
      v10,
      collector);
    ++v14;
  }
}

// File Line: 184
// RVA: 0xD29300
void __fastcall hkpMultiSphereAgent::staticGetClosestPoints(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpShape *v4; // rsi
  hkpCdBody *v5; // r14
  __m128 *v6; // rdx
  __m128 *v7; // r10
  hkpCdBody *v8; // rbx
  hkpCdPointCollector *v9; // r13
  hkpCollisionInput *v10; // r12
  signed __int64 v11; // rax
  __m128 v12; // xmm0
  int v13; // ebp
  __int64 v14; // r15
  __m128 *v15; // rdi
  hkpCollisionDispatcher *v16; // r11
  float v17; // xmm0_4
  hkpSphereShape *v18; // [rsp+20h] [rbp-138h]
  int v19; // [rsp+28h] [rbp-130h]
  __m128 *v20; // [rsp+30h] [rbp-128h]
  hkpCdBody *v21; // [rsp+38h] [rbp-120h]
  hkpSphereShape v22; // [rsp+40h] [rbp-118h]
  __m128 Dst; // [rsp+80h] [rbp-D8h]
  __m128 v24; // [rsp+90h] [rbp-C8h]
  __m128 v25; // [rsp+A0h] [rbp-B8h]
  __m128 v26; // [rsp+B0h] [rbp-A8h]

  v4 = bodyA->m_shape;
  v5 = bodyB;
  v6 = (__m128 *)bodyA->m_motion;
  v7 = &Dst;
  v8 = bodyA;
  v9 = collector;
  v10 = input;
  if ( ((unsigned __int8)&Dst | (unsigned __int8)bodyA->m_motion) & 0xF )
  {
    memmove(&Dst, v6, 0xB0ui64);
  }
  else
  {
    v11 = 1i64;
    do
    {
      v12 = *v6;
      v7 += 8;
      v6 += 8;
      v7[-8] = v12;
      v7[-7] = v6[-7];
      v7[-6] = v6[-6];
      v7[-5] = v6[-5];
      v7[-4] = v6[-4];
      v7[-3] = v6[-3];
      v7[-2] = v6[-2];
      v7[-1] = v6[-1];
      --v11;
    }
    while ( v11 );
    *v7 = *v6;
    v7[1] = v6[1];
    v7[2] = v6[2];
  }
  hkpSphereShape::hkpSphereShape(&v22, 0.0);
  v21 = v8;
  v20 = &Dst;
  v13 = 0;
  v14 = (unsigned __int8)v5->m_shape->m_type.m_storage;
  if ( SLODWORD(v4[1].vfptr) > 0 )
  {
    v15 = (__m128 *)&v4[1].m_type;
    do
    {
      v16 = v10->m_dispatcher.m_storage;
      v26 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 85), v24),
                  _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 0), Dst)),
                _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 170), v25)),
              *((__m128 *)v8->m_motion + 3));
      v17 = *((float *)&v15->m128_u64[1] + 1);
      v18 = &v22;
      v19 = v13;
      v22.m_radius = v17;
      (*((void (__fastcall **)(hkpSphereShape **, hkpCdBody *, hkpCollisionInput *, hkpCdPointCollector *, hkpSphereShape *, _QWORD, __m128 *, hkpCdBody *))&v16->vfptr
       + 5 * ((unsigned __int8)v16->m_agent2Types[(unsigned __int8)v22.m_type.m_storage][v14] + 79i64)))(
        &v18,
        v5,
        v10,
        v9,
        &v22,
        *(_QWORD *)&v19,
        v20,
        v21);
      ++v13;
      ++v15;
    }
    while ( v13 < SLODWORD(v4[1].vfptr) );
  }
}

// File Line: 218
// RVA: 0xD28D40
void __fastcall hkpMultiSphereAgent::linearCast(hkpMultiSphereAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpShape *v6; // rbp
  hkpCdBody *v7; // rsi
  __m128 *v8; // rdx
  __m128 *v9; // r10
  hkpMultiSphereAgent *v10; // rbx
  hkpLinearCastCollisionInput *v11; // r12
  hkpCdBody *v12; // r13
  signed __int64 v13; // rax
  __m128 v14; // xmm0
  hkpMultiSphereAgent::KeyAgentPair *v15; // r15
  int v16; // edi
  __m128 *v17; // rbx
  float v18; // xmm0_4
  hkpSphereShape *v19; // [rsp+30h] [rbp-138h]
  int v20; // [rsp+38h] [rbp-130h]
  __m128 *v21; // [rsp+40h] [rbp-128h]
  hkpCdBody *v22; // [rsp+48h] [rbp-120h]
  hkpSphereShape v23; // [rsp+50h] [rbp-118h]
  __m128 Dst; // [rsp+90h] [rbp-D8h]
  __m128 v25; // [rsp+A0h] [rbp-C8h]
  __m128 v26; // [rsp+B0h] [rbp-B8h]
  __m128 v27; // [rsp+C0h] [rbp-A8h]

  v6 = bodyA->m_shape;
  v7 = bodyA;
  v8 = (__m128 *)bodyA->m_motion;
  v9 = &Dst;
  v10 = this;
  v11 = input;
  v12 = bodyB;
  if ( ((unsigned __int8)&Dst | (unsigned __int8)v8) & 0xF )
  {
    memmove(&Dst, v8, 0xB0ui64);
  }
  else
  {
    v13 = 1i64;
    do
    {
      v14 = *v8;
      v9 += 8;
      v8 += 8;
      v9[-8] = v14;
      v9[-7] = v8[-7];
      v9[-6] = v8[-6];
      v9[-5] = v8[-5];
      v9[-4] = v8[-4];
      v9[-3] = v8[-3];
      v9[-2] = v8[-2];
      v9[-1] = v8[-1];
      --v13;
    }
    while ( v13 );
    *v9 = *v8;
    v9[1] = v8[1];
    v9[2] = v8[2];
  }
  hkpSphereShape::hkpSphereShape(&v23, 0.0);
  v15 = v10->m_agents.m_data;
  v16 = v10->m_agents.m_size - 1;
  v22 = v7;
  v21 = &Dst;
  if ( v16 >= 0 )
  {
    v17 = (__m128 *)&(&v6->vfptr)[2 * (v16 + 3i64)];
    do
    {
      v27 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 85), v25),
                  _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 0), Dst)),
                _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 170), v26)),
              *((__m128 *)v7->m_motion + 3));
      v18 = *((float *)&v17->m128_u64[1] + 1);
      v19 = &v23;
      v23.m_radius = v18;
      v20 = v16;
      ((void (__fastcall *)(hkpCollisionAgent *, hkpSphereShape **, hkpCdBody *, hkpLinearCastCollisionInput *, hkpCdPointCollector *, hkpCdPointCollector *, hkpSphereShape *, _QWORD, __m128 *, hkpCdBody *))v15->m_agent->vfptr[2].__first_virtual_table_function__)(
        v15->m_agent,
        &v19,
        v12,
        v11,
        collector,
        startCollector,
        &v23,
        *(_QWORD *)&v20,
        v21,
        v22);
      --v17;
      --v16;
    }
    while ( v16 >= 0 );
  }
}

// File Line: 248
// RVA: 0xD28F30
void __fastcall hkpMultiSphereAgent::staticLinearCast(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpShape *v5; // rsi
  hkpCdBody *v6; // r14
  __m128 *v7; // rdx
  __m128 *v8; // r10
  hkpCdBody *v9; // rbx
  hkpLinearCastCollisionInput *v10; // r13
  signed __int64 v11; // rax
  __m128 v12; // xmm0
  int v13; // ebp
  __int64 v14; // r12
  __m128 *v15; // rdi
  hkpCollisionDispatcher *v16; // r11
  float v17; // xmm0_4
  hkpSphereShape *v18; // [rsp+30h] [rbp-138h]
  int v19; // [rsp+38h] [rbp-130h]
  __m128 *v20; // [rsp+40h] [rbp-128h]
  hkpCdBody *v21; // [rsp+48h] [rbp-120h]
  hkpSphereShape v22; // [rsp+50h] [rbp-118h]
  __m128 Dst; // [rsp+90h] [rbp-D8h]
  __m128 v24; // [rsp+A0h] [rbp-C8h]
  __m128 v25; // [rsp+B0h] [rbp-B8h]
  __m128 v26; // [rsp+C0h] [rbp-A8h]
  hkpCdPointCollector *v27; // [rsp+188h] [rbp+20h]

  v27 = collector;
  v5 = bodyA->m_shape;
  v6 = bodyB;
  v7 = (__m128 *)bodyA->m_motion;
  v8 = &Dst;
  v9 = bodyA;
  v10 = input;
  if ( ((unsigned __int8)&Dst | (unsigned __int8)bodyA->m_motion) & 0xF )
  {
    memmove(&Dst, v7, 0xB0ui64);
  }
  else
  {
    v11 = 1i64;
    do
    {
      v12 = *v7;
      v8 += 8;
      v7 += 8;
      v8[-8] = v12;
      v8[-7] = v7[-7];
      v8[-6] = v7[-6];
      v8[-5] = v7[-5];
      v8[-4] = v7[-4];
      v8[-3] = v7[-3];
      v8[-2] = v7[-2];
      v8[-1] = v7[-1];
      --v11;
    }
    while ( v11 );
    *v8 = *v7;
    v8[1] = v7[1];
    v8[2] = v7[2];
  }
  hkpSphereShape::hkpSphereShape(&v22, 0.0);
  v21 = v9;
  v20 = &Dst;
  v13 = 0;
  v14 = (unsigned __int8)v6->m_shape->m_type.m_storage;
  if ( SLODWORD(v5[1].vfptr) > 0 )
  {
    v15 = (__m128 *)&v5[1].m_type;
    do
    {
      v16 = v10->m_dispatcher.m_storage;
      v26 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 85), v24),
                  _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 0), Dst)),
                _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 170), v25)),
              *((__m128 *)v9->m_motion + 3));
      v17 = *((float *)&v15->m128_u64[1] + 1);
      v18 = &v22;
      v19 = v13;
      v22.m_radius = v17;
      v16->m_agent2Func[(unsigned __int8)v16->m_agent2Types[(unsigned __int8)v22.m_type.m_storage][v14]].m_linearCastFunc(
        (hkpCdBody *)&v18,
        v6,
        v10,
        v27,
        startCollector);
      ++v13;
      ++v15;
    }
    while ( v13 < SLODWORD(v5[1].vfptr) );
  }
}

// File Line: 280
// RVA: 0xD294E0
void __fastcall hkpMultiSphereAgent::getPenetrations(hkpMultiSphereAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpShape *v5; // r12
  hkpCdBody *v6; // rsi
  __m128 *v7; // rdx
  __m128 *v8; // r10
  hkpMultiSphereAgent *v9; // rbx
  hkpCollisionInput *v10; // r14
  hkpCdBody *v11; // r15
  signed __int64 v12; // rax
  __m128 v13; // xmm0
  hkpMultiSphereAgent::KeyAgentPair *v14; // rdi
  int v15; // ebx
  signed __int64 v16; // rcx
  __m128 v17; // xmm1
  float v18; // xmm0_4
  hkpSphereShape *v19; // [rsp+30h] [rbp-128h]
  int v20; // [rsp+38h] [rbp-120h]
  __m128 *i; // [rsp+40h] [rbp-118h]
  hkpCdBody *v22; // [rsp+48h] [rbp-110h]
  hkpSphereShape v23; // [rsp+50h] [rbp-108h]
  __m128 Dst; // [rsp+90h] [rbp-C8h]
  __m128 v25; // [rsp+A0h] [rbp-B8h]
  __m128 v26; // [rsp+B0h] [rbp-A8h]
  __m128 v27; // [rsp+C0h] [rbp-98h]

  v5 = bodyA->m_shape;
  v6 = bodyA;
  v7 = (__m128 *)bodyA->m_motion;
  v8 = &Dst;
  v9 = this;
  v10 = input;
  v11 = bodyB;
  if ( ((unsigned __int8)&Dst | (unsigned __int8)v7) & 0xF )
  {
    memmove(&Dst, v7, 0xB0ui64);
  }
  else
  {
    v12 = 1i64;
    do
    {
      v13 = *v7;
      v8 += 8;
      v7 += 8;
      v8[-8] = v13;
      v8[-7] = v7[-7];
      v8[-6] = v7[-6];
      v8[-5] = v7[-5];
      v8[-4] = v7[-4];
      v8[-3] = v7[-3];
      v8[-2] = v7[-2];
      v8[-1] = v7[-1];
      --v12;
    }
    while ( v12 );
    *v8 = *v7;
    v8[1] = v7[1];
    v8[2] = v7[2];
  }
  hkpSphereShape::hkpSphereShape(&v23, 0.0);
  v14 = v9->m_agents.m_data;
  v15 = v9->m_agents.m_size - 1;
  v22 = v6;
  for ( i = &Dst; v15 >= 0; --v15 )
  {
    v16 = 2 * (v14->m_key + 3i64);
    v17 = *(__m128 *)&(&v5->vfptr)[2 * (v14->m_key + 3i64)];
    v27 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), v25),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&(&v5->vfptr)[2 * (v14->m_key + 3i64)], v17, 0), Dst)),
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), v26)),
            *((__m128 *)v6->m_motion + 3));
    v18 = *(float *)(&v5->m_referenceCount + 4 * v16 + 1);
    v19 = &v23;
    v23.m_radius = v18;
    v20 = v15;
    ((void (__fastcall *)(hkpCollisionAgent *, hkpSphereShape **, hkpCdBody *, hkpCollisionInput *, hkpCdBodyPairCollector *))v14->m_agent->vfptr[1].__first_virtual_table_function__)(
      v14->m_agent,
      &v19,
      v11,
      v10,
      collector);
    if ( collector->m_earlyOut.m_bool )
      break;
    ++v14;
  }
}

// File Line: 313
// RVA: 0xD296C0
void __fastcall hkpMultiSphereAgent::staticGetPenetrations(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpShape *v4; // rsi
  hkpCdBody *v5; // r15
  __m128 *v6; // rdx
  __m128 *v7; // r10
  hkpCdBody *v8; // r14
  hkpCdBodyPairCollector *v9; // r12
  hkpCollisionInput *v10; // r13
  signed __int64 v11; // rax
  __m128 v12; // xmm0
  int v13; // ebx
  __int64 v14; // rbp
  __m128 *v15; // rdi
  hkpCollisionDispatcher *v16; // r11
  float v17; // xmm0_4
  hkpSphereShape *v18; // [rsp+20h] [rbp-138h]
  int v19; // [rsp+28h] [rbp-130h]
  __m128 *v20; // [rsp+30h] [rbp-128h]
  hkpCdBody *v21; // [rsp+38h] [rbp-120h]
  hkpSphereShape v22; // [rsp+40h] [rbp-118h]
  __m128 Dst; // [rsp+80h] [rbp-D8h]
  __m128 v24; // [rsp+90h] [rbp-C8h]
  __m128 v25; // [rsp+A0h] [rbp-B8h]
  __m128 v26; // [rsp+B0h] [rbp-A8h]

  v4 = bodyA->m_shape;
  v5 = bodyB;
  v6 = (__m128 *)bodyA->m_motion;
  v7 = &Dst;
  v8 = bodyA;
  v9 = collector;
  v10 = input;
  if ( ((unsigned __int8)&Dst | (unsigned __int8)bodyA->m_motion) & 0xF )
  {
    memmove(&Dst, v6, 0xB0ui64);
  }
  else
  {
    v11 = 1i64;
    do
    {
      v12 = *v6;
      v7 += 8;
      v6 += 8;
      v7[-8] = v12;
      v7[-7] = v6[-7];
      v7[-6] = v6[-6];
      v7[-5] = v6[-5];
      v7[-4] = v6[-4];
      v7[-3] = v6[-3];
      v7[-2] = v6[-2];
      v7[-1] = v6[-1];
      --v11;
    }
    while ( v11 );
    *v7 = *v6;
    v7[1] = v6[1];
    v7[2] = v6[2];
  }
  hkpSphereShape::hkpSphereShape(&v22, 0.0);
  v21 = v8;
  v20 = &Dst;
  v13 = 0;
  v14 = (unsigned __int8)v5->m_shape->m_type.m_storage;
  if ( SLODWORD(v4[1].vfptr) > 0 )
  {
    v15 = (__m128 *)&v4[1].m_type;
    do
    {
      v16 = v10->m_dispatcher.m_storage;
      v26 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 85), v24),
                  _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 0), Dst)),
                _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 170), v25)),
              *((__m128 *)v8->m_motion + 3));
      v17 = *((float *)&v15->m128_u64[1] + 1);
      v18 = &v22;
      v19 = v13;
      v22.m_radius = v17;
      ((void (__fastcall *)(hkpSphereShape **, hkpCdBody *, hkpCollisionInput *, hkpCdBodyPairCollector *, hkpSphereShape *, _QWORD, __m128 *, hkpCdBody *))v16->m_agent2Func[(unsigned __int8)v16->m_agent2Types[(unsigned __int8)v22.m_type.m_storage][v14]].m_getPenetrationsFunc)(
        &v18,
        v5,
        v10,
        v9,
        &v22,
        *(_QWORD *)&v19,
        v20,
        v21);
      if ( v9->m_earlyOut.m_bool )
        break;
      ++v13;
      ++v15;
    }
    while ( v13 < SLODWORD(v4[1].vfptr) );
  }
}


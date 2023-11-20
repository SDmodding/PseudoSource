// File Line: 17
// RVA: 0xCF38F0
void __fastcall hkpShapeCollectionAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  f.m_createFunc = hkpShapeCollectionAgent::createListBAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetPenetrations;
  v1 = dispatcher;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, ALL_SHAPE_TYPES, COLLECTION);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, ALL_SHAPE_TYPES, TRI_SAMPLED_HEIGHT_FIELD_COLLECTION);
  f.m_createFunc = hkpShapeCollectionAgent::createListAAgent;
  f.m_getPenetrationsFunc = hkpShapeCollectionAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpShapeCollectionAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpShapeCollectionAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, COLLECTION, ALL_SHAPE_TYPES);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, TRI_SAMPLED_HEIGHT_FIELD_COLLECTION, ALL_SHAPE_TYPES);
}

// File Line: 46
// RVA: 0xCF4A00
void __fastcall hkpShapeCollectionAgent::createListAAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCdBody *v4; // rbp
  hkpContactMgr *v5; // rbx
  hkpCollisionInput *v6; // rdi
  hkpCdBody *v7; // rsi
  _QWORD **v8; // rax
  hkpShapeCollectionAgent *v9; // rax

  v4 = bodyA;
  v5 = mgr;
  v6 = input;
  v7 = bodyB;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 104i64);
  if ( v9 )
    hkpShapeCollectionAgent::hkpShapeCollectionAgent(v9, v4, v7, v6, v5);
}

// File Line: 55
// RVA: 0xCF4A80
hkpShapeCollectionAgent *__fastcall hkpShapeCollectionAgent::createListBAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCdBody *v4; // r14
  hkpContactMgr *v5; // rdi
  hkpCollisionInput *v6; // rsi
  hkpCdBody *v7; // rbp
  _QWORD **v8; // rax
  hkpShapeCollectionAgent *result; // rax
  hkpCollisionAgent *v10; // rbx

  v4 = bodyA;
  v5 = mgr;
  v6 = input;
  v7 = bodyB;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpShapeCollectionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(
                                        v8[11],
                                        104i64);
  v10 = (hkpCollisionAgent *)&result->vfptr;
  if ( result )
  {
    hkpShapeCollectionAgent::hkpShapeCollectionAgent(result, v7, v4, v6, v5);
    v10->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpShapeCollectionAgent>::`vftable';
    result = (hkpShapeCollectionAgent *)v10;
  }
  return result;
}

// File Line: 64
// RVA: 0xCF4820
void __fastcall hkpShapeCollectionAgent::hkpShapeCollectionAgent(hkpShapeCollectionAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v5; // rax
  signed int *v6; // r15
  hkpCollisionInput *v7; // r14
  hkpShape *v8; // rcx
  hkpCdBody *v9; // rbp
  hkpCdBody *v10; // r13
  __int64 v11; // rax
  __int64 v12; // rsi
  int v13; // eax
  int v14; // ecx
  int v15; // ecx
  unsigned int v16; // ebx
  hkpContactMgr *v17; // r12
  __int64 v18; // rax
  hkpCollisionFilter *v19; // rcx
  __int64 v20; // rcx
  signed __int64 v21; // rdi
  hkpCollisionDispatcher *v22; // r10
  signed __int64 v23; // rdx
  __int64 v24; // rax
  __int64 v25[2]; // [rsp+30h] [rbp-268h]
  __int64 v26; // [rsp+40h] [rbp-258h]
  unsigned int v27; // [rsp+48h] [rbp-250h]
  const void *v28; // [rsp+50h] [rbp-248h]
  hkpCdBody *v29; // [rsp+58h] [rbp-240h]
  char v30; // [rsp+60h] [rbp-238h]
  hkResult result; // [rsp+2A8h] [rbp+10h]

  v5 = mgr;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v6 = (signed int *)&this->m_agents;
  this->m_contactMgr = v5;
  this->vfptr = (hkBaseObjectVtbl *)&hkpShapeCollectionAgent::`vftable';
  v6[2] = 0;
  v6[3] = -2147483644;
  v29 = bodyA;
  v7 = input;
  *(_QWORD *)v6 = (char *)this + 40;
  v8 = bodyA->m_shape;
  v28 = bodyA->m_motion;
  v9 = bodyB;
  v10 = bodyA;
  v11 = ((__int64 (*)(void))v8->vfptr[7].__vecDelDtor)();
  v12 = v11;
  v13 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 8i64))(v11);
  v14 = v6[3] & 0x3FFFFFFF;
  if ( v14 < v13 )
  {
    v15 = 2 * v14;
    if ( v13 < v15 )
      v13 = v15;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v13, 16);
  }
  v16 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v12 + 16i64))(v12);
  if ( v16 != -1 )
  {
    v17 = mgr;
    do
    {
      v18 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v12 + 40i64))(v12, v16, &v30);
      v19 = v7->m_filter.m_storage;
      v27 = v16;
      v26 = v18;
      LODWORD(v25[0]) = v16;
      if ( *(_BYTE *)v19->vfptr->isCollisionEnabled(
                       (hkpShapeCollectionFilter *)&v19->vfptr,
                       (hkBool *)&mgr,
                       v7,
                       v9,
                       v10,
                       (hkpShapeContainer *)v12,
                       v25[0]) )
      {
        v20 = v6[2];
        v21 = *(_QWORD *)v6 + 16 * v20;
        v6[2] = v20 + 1;
        v22 = v7->m_dispatcher.m_storage;
        v23 = (signed __int64)v7->m_dispatcher.m_storage->m_agent2TypesPred;
        if ( !v7->m_createPredictiveAgents.m_storage )
          v23 = (signed __int64)v22->m_agent2Types;
        v24 = (__int64)v22->m_agent2Func[*(unsigned __int8 *)((unsigned __int8)v9->m_shape->m_type.m_storage
                                                            + v23
                                                            + 35i64 * *(unsigned __int8 *)(v26 + 16))].m_createFunc(
                         (hkpCdBody *)&v26,
                         v9,
                         v7,
                         v17);
        *(_DWORD *)v21 = v16;
        *(_QWORD *)(v21 + 8) = v24;
      }
      v16 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v12 + 24i64))(v12, v16);
    }
    while ( v16 != -1 );
  }
}

// File Line: 93
// RVA: 0xCF4450
void __fastcall hkpShapeCollectionAgent::cleanup(hkpShapeCollectionAgent *this, hkpConstraintOwner *info)
{
  int v2; // edi
  hkpConstraintOwner *v3; // rbp
  hkpShapeCollectionAgent *v4; // rbx
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

// File Line: 102
// RVA: 0xCF4730
void __fastcall hkpShapeCollectionAgent::invalidateTim(hkpShapeCollectionAgent *this, hkpCollisionInput *input)
{
  int v2; // ebx
  hkpCollisionInput *v3; // rbp
  hkpShapeCollectionAgent *v4; // rsi
  __int64 v5; // rdi
  hkpCollisionAgent *v6; // rcx

  v2 = 0;
  v3 = input;
  v4 = this;
  if ( this->m_agents.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v4->m_agents.m_data[v5].m_agent;
      ((void (__fastcall *)(hkpCollisionAgent *, hkpCollisionInput *))v6->vfptr[4].__first_virtual_table_function__)(
        v6,
        v3);
      ++v2;
      ++v5;
    }
    while ( v2 < v4->m_agents.m_size );
  }
}

// File Line: 110
// RVA: 0xCF47A0
void __usercall hkpShapeCollectionAgent::warpTime(hkpShapeCollectionAgent *this@<rcx>, float oldTime@<xmm1>, float newTime@<xmm2>, hkpCollisionInput *input@<r9>, __int64 a5@<rdx>, __int64 a6@<r8>)
{
  int v6; // ebx
  hkpCollisionInput *v7; // rbp
  hkpShapeCollectionAgent *v8; // rsi
  __int64 v9; // rdi
  hkpCollisionAgent *v10; // rcx

  v6 = 0;
  v7 = input;
  v8 = this;
  if ( this->m_agents.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      v10 = v8->m_agents.m_data[v9].m_agent;
      ((void (__fastcall *)(hkpCollisionAgent *, __int64, __int64, hkpCollisionInput *))v10->vfptr[5].__vecDelDtor)(
        v10,
        a5,
        a6,
        v7);
      ++v6;
      ++v9;
    }
    while ( v6 < v8->m_agents.m_size );
  }
}

// File Line: 119
// RVA: 0xCF39D0
void __fastcall hkpShapeCollectionAgent::processCollision(hkpShapeCollectionAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *result)
{
  hkpShapeCollectionAgent *v5; // rsi
  hkpCdBody *v6; // r12
  hkpProcessCollisionInput *v7; // r15
  hkpCdBody *v8; // rbx
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  __int64 v14; // rax
  hkpShapeCollectionAgent::KeyAgentPair *v15; // rdi
  int v16; // esi
  __int64 v17; // rcx
  __int64 v18; // r14
  int v19; // ebx
  __int64 v20; // rax
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r8
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  __int64 v26; // [rsp+30h] [rbp-238h]
  int v27; // [rsp+38h] [rbp-230h]
  __int64 i; // [rsp+40h] [rbp-228h]
  hkpCdBody *v29; // [rsp+48h] [rbp-220h]
  char v30; // [rsp+50h] [rbp-218h]

  v5 = this;
  v6 = bodyB;
  v7 = input;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtShapeCollection";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v14 = ((__int64 (*)(void))v8->m_shape->vfptr[7].__vecDelDtor)();
  v15 = v5->m_agents.m_data;
  v16 = v5->m_agents.m_size - 1;
  v17 = (__int64)v8->m_motion;
  v18 = v14;
  v29 = v8;
  for ( i = v17; v16 >= 0; ++v15 )
  {
    v19 = v15->m_key;
    v20 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v18 + 40i64))(v18, v15->m_key, &v30);
    v27 = v19;
    v26 = v20;
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v15->m_agent->vfptr[3].__vecDelDtor)(
      v15->m_agent,
      &v26,
      v6,
      v7,
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
    v25 = (signed __int64)(v22 + 2);
    *(_DWORD *)(v25 - 8) = v24;
    v23[1] = v25;
  }
}

// File Line: 153
// RVA: 0xCF3E60
void __fastcall hkpShapeCollectionAgent::getClosestPoints(hkpShapeCollectionAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpShapeCollectionAgent *v5; // rsi
  hkpCdBody *v6; // r12
  hkpCollisionInput *v7; // r15
  hkpCdBody *v8; // rbx
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  __int64 v14; // rax
  hkpShapeCollectionAgent::KeyAgentPair *v15; // rdi
  int v16; // esi
  __int64 v17; // rcx
  __int64 v18; // r14
  int v19; // ebx
  __int64 v20; // rax
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r8
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  __int64 v26; // [rsp+30h] [rbp-238h]
  int v27; // [rsp+38h] [rbp-230h]
  __int64 i; // [rsp+40h] [rbp-228h]
  hkpCdBody *v29; // [rsp+48h] [rbp-220h]
  char v30; // [rsp+50h] [rbp-218h]

  v5 = this;
  v6 = bodyB;
  v7 = input;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtShapeCollection";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v14 = ((__int64 (*)(void))v8->m_shape->vfptr[7].__vecDelDtor)();
  v15 = v5->m_agents.m_data;
  v16 = v5->m_agents.m_size - 1;
  v17 = (__int64)v8->m_motion;
  v18 = v14;
  v29 = v8;
  for ( i = v17; v16 >= 0; ++v15 )
  {
    v19 = v15->m_key;
    v20 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v18 + 40i64))(v18, v15->m_key, &v30);
    v27 = v19;
    v26 = v20;
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpCdPointCollector *))v15->m_agent->vfptr[2].__vecDelDtor)(
      v15->m_agent,
      &v26,
      v6,
      v7,
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
    v25 = (signed __int64)(v22 + 2);
    *(_DWORD *)(v25 - 8) = v24;
    v23[1] = v25;
  }
}

// File Line: 179
// RVA: 0xCF3FC0
void __fastcall hkpShapeCollectionAgent::staticGetClosestPoints(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpCdBody *v4; // rbp
  hkpCdPointCollector *v5; // r12
  hkpCollisionInput *v6; // r14
  hkpCdBody *v7; // r15
  _QWORD *v8; // rax
  unsigned __int64 v9; // rdx
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  __int64 v14; // rax
  __int64 v15; // rcx
  __int64 v16; // rdi
  __int64 v17; // rsi
  unsigned int i; // ebx
  __int64 v19; // rax
  hkpCollisionDispatcher *v20; // r11
  _QWORD *v21; // r8
  _QWORD *v22; // rcx
  unsigned __int64 v23; // rax
  signed __int64 v24; // rcx
  __int64 v25; // [rsp+40h] [rbp-248h]
  unsigned int v26; // [rsp+48h] [rbp-240h]
  __int64 v27; // [rsp+50h] [rbp-238h]
  hkpCdBody *v28; // [rsp+58h] [rbp-230h]
  char v29; // [rsp+60h] [rbp-228h]
  char v30; // [rsp+290h] [rbp+8h]

  v4 = bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v8[1];
  v11 = v8;
  if ( (unsigned __int64)v10 < v8[3] )
  {
    *v10 = "TtShapeCollection";
    v12 = __rdtsc();
    v9 = (unsigned __int64)HIDWORD(v12) << 32;
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v14 = ((__int64 (__fastcall *)(hkpShape *, unsigned __int64, _QWORD *))v4->m_shape->vfptr[7].__vecDelDtor)(
          v4->m_shape,
          v9,
          v11);
  v15 = (__int64)v4->m_motion;
  v28 = v4;
  v27 = v15;
  v16 = (unsigned __int8)v7->m_shape->m_type.m_storage;
  v17 = v14;
  for ( i = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
        i != -1;
        i = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v17 + 24i64))(v17, i) )
  {
    if ( *(_BYTE *)((__int64 (__fastcall *)(hkpShapeCollectionFilterVtbl **, char *, hkpCollisionInput *, hkpCdBody *))v6->m_filter.m_storage->vfptr->isCollisionEnabled)(
                     &v6->m_filter.m_storage->vfptr,
                     &v30,
                     v6,
                     v7) )
    {
      v19 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v17 + 40i64))(v17, i, &v29);
      v20 = v6->m_dispatcher.m_storage;
      v26 = i;
      v25 = v19;
      (*((void (__fastcall **)(__int64 *, hkpCdBody *, hkpCollisionInput *, hkpCdPointCollector *))&v20->vfptr
       + 5 * ((unsigned __int8)v20->m_agent2Types[*(unsigned __int8 *)(v19 + 16)][v16] + 79i64)))(
        &v25,
        v7,
        v6,
        v5);
    }
  }
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v23 = __rdtsc();
    v24 = (signed __int64)(v22 + 2);
    *(_DWORD *)(v24 - 8) = v23;
    v21[1] = v24;
  }
}

// File Line: 212
// RVA: 0xCF3B30
void __fastcall hkpShapeCollectionAgent::linearCast(hkpShapeCollectionAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpShapeCollectionAgent *v6; // rsi
  hkpLinearCastCollisionInput *v7; // r12
  hkpCdBody *v8; // r13
  hkpCdBody *v9; // rbx
  _QWORD *v10; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r10
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  __int64 v15; // rax
  hkpShapeCollectionAgent::KeyAgentPair *v16; // rdi
  int v17; // esi
  __int64 v18; // rcx
  __int64 v19; // r14
  int v20; // ebx
  __int64 v21; // rax
  _QWORD *v22; // rax
  _QWORD *v23; // rcx
  _QWORD *v24; // r8
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  __int64 v27; // [rsp+30h] [rbp-248h]
  int v28; // [rsp+38h] [rbp-240h]
  __int64 i; // [rsp+40h] [rbp-238h]
  hkpCdBody *v30; // [rsp+48h] [rbp-230h]
  char v31; // [rsp+50h] [rbp-228h]

  v6 = this;
  v7 = input;
  v8 = bodyB;
  v9 = bodyA;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  v12 = v10;
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "TtShapeCollection";
    v13 = __rdtsc();
    v14 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v12[1] = v14;
  }
  v15 = ((__int64 (*)(void))v9->m_shape->vfptr[7].__vecDelDtor)();
  v16 = v6->m_agents.m_data;
  v17 = v6->m_agents.m_size - 1;
  v18 = (__int64)v9->m_motion;
  v19 = v15;
  v30 = v9;
  for ( i = v18; v17 >= 0; ++v16 )
  {
    v20 = v16->m_key;
    v21 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v19 + 40i64))(v19, v16->m_key, &v31);
    v28 = v20;
    v27 = v21;
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpLinearCastCollisionInput *, hkpCdPointCollector *, hkpCdPointCollector *, __int64, _QWORD, __int64, hkpCdBody *))v16->m_agent->vfptr[2].__first_virtual_table_function__)(
      v16->m_agent,
      &v27,
      v8,
      v7,
      collector,
      startCollector,
      v21,
      *(_QWORD *)&v28,
      i,
      v30);
    --v17;
  }
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  v24 = v22;
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "Et";
    v25 = __rdtsc();
    v26 = (signed __int64)(v23 + 2);
    *(_DWORD *)(v26 - 8) = v25;
    v24[1] = v26;
  }
}

// File Line: 237
// RVA: 0xCF3CB0
void __fastcall hkpShapeCollectionAgent::staticLinearCast(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpCdBody *v5; // rbp
  hkpCdPointCollector *v6; // r12
  hkpLinearCastCollisionInput *v7; // r14
  hkpCdBody *v8; // r15
  _QWORD *v9; // rax
  unsigned __int64 v10; // rdx
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  __int64 v15; // rax
  __int64 v16; // rcx
  __int64 v17; // r13
  __int64 v18; // rsi
  unsigned int v19; // ebx
  hkpCdPointCollector *v20; // rdi
  __int64 v21; // rax
  hkpCollisionDispatcher *v22; // r11
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  __int64 v27; // [rsp+40h] [rbp-248h]
  unsigned int v28; // [rsp+48h] [rbp-240h]
  __int64 v29; // [rsp+50h] [rbp-238h]
  hkpCdBody *v30; // [rsp+58h] [rbp-230h]
  char v31; // [rsp+60h] [rbp-228h]
  char v32; // [rsp+290h] [rbp+8h]

  v5 = bodyA;
  v6 = collector;
  v7 = input;
  v8 = bodyB;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v9[1];
  v12 = v9;
  if ( (unsigned __int64)v11 < v9[3] )
  {
    *v11 = "TtShapeCollection";
    v13 = __rdtsc();
    v10 = (unsigned __int64)HIDWORD(v13) << 32;
    v14 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v12[1] = v14;
  }
  v15 = ((__int64 (__fastcall *)(hkpShape *, unsigned __int64, _QWORD *))v5->m_shape->vfptr[7].__vecDelDtor)(
          v5->m_shape,
          v10,
          v12);
  v16 = (__int64)v5->m_motion;
  v30 = v5;
  v29 = v16;
  v17 = (unsigned __int8)v8->m_shape->m_type.m_storage;
  v18 = v15;
  v19 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v15 + 16i64))(v15);
  if ( v19 != -1 )
  {
    v20 = startCollector;
    do
    {
      if ( *(_BYTE *)((__int64 (__fastcall *)(hkpShapeCollectionFilterVtbl **, char *, hkpLinearCastCollisionInput *, hkpCdBody *))v7->m_filter.m_storage->vfptr->isCollisionEnabled)(
                       &v7->m_filter.m_storage->vfptr,
                       &v32,
                       v7,
                       v8) )
      {
        v21 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v18 + 40i64))(v18, v19, &v31);
        v22 = v7->m_dispatcher.m_storage;
        v28 = v19;
        v27 = v21;
        v22->m_agent2Func[(unsigned __int8)v22->m_agent2Types[*(unsigned __int8 *)(v21 + 16)][v17]].m_linearCastFunc(
          (hkpCdBody *)&v27,
          v8,
          v7,
          v6,
          v20);
      }
      v19 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v18 + 24i64))(v18, v19);
    }
    while ( v19 != -1 );
  }
  v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v24 = (_QWORD *)v23[1];
  if ( (unsigned __int64)v24 < v23[3] )
  {
    *v24 = "Et";
    v25 = __rdtsc();
    v26 = (signed __int64)(v24 + 2);
    *(_DWORD *)(v26 - 8) = v25;
    v23[1] = v26;
  }
}

// File Line: 267
// RVA: 0xCF4150
void __fastcall hkpShapeCollectionAgent::getPenetrations(hkpShapeCollectionAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpShapeCollectionAgent *v5; // rsi
  hkpCdBody *v6; // r12
  hkpCollisionInput *v7; // r15
  hkpCdBody *v8; // rbx
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  __int64 v14; // rax
  hkpShapeCollectionAgent::KeyAgentPair *v15; // rdi
  int v16; // esi
  __int64 v17; // rcx
  __int64 v18; // r14
  int v19; // ebx
  __int64 v20; // rax
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r8
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  __int64 v26; // [rsp+30h] [rbp-238h]
  int v27; // [rsp+38h] [rbp-230h]
  __int64 i; // [rsp+40h] [rbp-228h]
  hkpCdBody *v29; // [rsp+48h] [rbp-220h]
  char v30; // [rsp+50h] [rbp-218h]

  v5 = this;
  v6 = bodyB;
  v7 = input;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtShapeCollection";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v14 = ((__int64 (*)(void))v8->m_shape->vfptr[7].__vecDelDtor)();
  v15 = v5->m_agents.m_data;
  v16 = v5->m_agents.m_size - 1;
  v17 = (__int64)v8->m_motion;
  v18 = v14;
  v29 = v8;
  for ( i = v17; v16 >= 0; --v16 )
  {
    v19 = v15->m_key;
    v20 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v18 + 40i64))(v18, v15->m_key, &v30);
    v27 = v19;
    v26 = v20;
    ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpCdBodyPairCollector *))v15->m_agent->vfptr[1].__first_virtual_table_function__)(
      v15->m_agent,
      &v26,
      v6,
      v7,
      collector);
    if ( collector->m_earlyOut.m_bool )
      break;
    ++v15;
  }
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  v23 = v21;
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v24 = __rdtsc();
    v25 = (signed __int64)(v22 + 2);
    *(_DWORD *)(v25 - 8) = v24;
    v23[1] = v25;
  }
}

// File Line: 295
// RVA: 0xCF42B0
void __fastcall hkpShapeCollectionAgent::staticGetPenetrations(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpCdBody *v4; // rbp
  hkpCdBodyPairCollector *v5; // r12
  hkpCollisionInput *v6; // r14
  hkpCdBody *v7; // r15
  _QWORD *v8; // rax
  unsigned __int64 v9; // rdx
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  __int64 v14; // rax
  __int64 v15; // rcx
  __int64 v16; // rdi
  __int64 v17; // rsi
  unsigned int i; // ebx
  __int64 v19; // rax
  hkpCollisionDispatcher *v20; // r11
  _QWORD *v21; // r8
  _QWORD *v22; // rcx
  unsigned __int64 v23; // rax
  signed __int64 v24; // rcx
  __int64 v25; // [rsp+40h] [rbp-248h]
  unsigned int v26; // [rsp+48h] [rbp-240h]
  __int64 v27; // [rsp+50h] [rbp-238h]
  hkpCdBody *v28; // [rsp+58h] [rbp-230h]
  char v29; // [rsp+60h] [rbp-228h]
  char v30; // [rsp+290h] [rbp+8h]

  v4 = bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v8[1];
  v11 = v8;
  if ( (unsigned __int64)v10 < v8[3] )
  {
    *v10 = "TtShapeCollection";
    v12 = __rdtsc();
    v9 = (unsigned __int64)HIDWORD(v12) << 32;
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v14 = ((__int64 (__fastcall *)(hkpShape *, unsigned __int64, _QWORD *))v4->m_shape->vfptr[7].__vecDelDtor)(
          v4->m_shape,
          v9,
          v11);
  v15 = (__int64)v4->m_motion;
  v28 = v4;
  v27 = v15;
  v16 = (unsigned __int8)v7->m_shape->m_type.m_storage;
  v17 = v14;
  for ( i = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
        i != -1;
        i = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v17 + 24i64))(v17, i) )
  {
    if ( *(_BYTE *)((__int64 (__fastcall *)(hkpShapeCollectionFilterVtbl **, char *, hkpCollisionInput *, hkpCdBody *))v6->m_filter.m_storage->vfptr->isCollisionEnabled)(
                     &v6->m_filter.m_storage->vfptr,
                     &v30,
                     v6,
                     v7) )
    {
      v19 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v17 + 40i64))(v17, i, &v29);
      v20 = v6->m_dispatcher.m_storage;
      v26 = i;
      v25 = v19;
      v20->m_agent2Func[(unsigned __int8)v20->m_agent2Types[*(unsigned __int8 *)(v19 + 16)][v16]].m_getPenetrationsFunc(
        (hkpCdBody *)&v25,
        v7,
        v6,
        v5);
      if ( v5->m_earlyOut.m_bool )
        break;
    }
  }
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v23 = __rdtsc();
    v24 = (signed __int64)(v22 + 2);
    *(_DWORD *)(v24 - 8) = v23;
    v21[1] = v24;
  }
}

// File Line: 339
// RVA: 0xCF44D0
void __fastcall hkpShapeCollectionAgent::updateShapeCollectionFilter(hkpShapeCollectionAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpConstraintOwner *constraintOwner)
{
  const void *v5; // rax
  hkpShapeCollectionAgent *v6; // rbp
  hkpShape *v7; // rcx
  hkpCollisionInput *v8; // r15
  hkpCdBody *v9; // r12
  __int64 v10; // r14
  unsigned int i; // esi
  signed __int64 v12; // rcx
  signed int v13; // edi
  signed __int64 v14; // rbx
  hkpShapeCollectionAgent::KeyAgentPair *v15; // rax
  __int64 v16; // rax
  signed __int64 v17; // rdi
  hkpCollisionDispatcher *v18; // r10
  signed __int64 v19; // rdx
  hkpCollisionAgent *v20; // rcx
  signed __int64 v21; // rbx
  hkpCollisionAgent *v22; // rcx
  __int64 v23; // rcx
  signed __int64 v24; // rdx
  signed __int64 v25; // r8
  signed __int64 v26; // rcx
  signed __int64 v27; // r8
  __int64 v28; // rax
  __int64 v29[2]; // [rsp+30h] [rbp-268h]
  char v30; // [rsp+40h] [rbp-258h]
  __int64 v31; // [rsp+48h] [rbp-250h]
  unsigned int v32; // [rsp+50h] [rbp-248h]
  const void *v33; // [rsp+58h] [rbp-240h]
  hkpCdBody *v34; // [rsp+60h] [rbp-238h]
  char v35; // [rsp+70h] [rbp-228h]
  hkpCdBody *v36; // [rsp+2A8h] [rbp+10h]

  v36 = bodyA;
  v5 = bodyA->m_motion;
  v6 = this;
  v7 = bodyA->m_shape;
  v34 = bodyA;
  v33 = v5;
  v8 = input;
  v9 = bodyB;
  v10 = ((__int64 (*)(void))v7->vfptr[7].__vecDelDtor)();
  for ( i = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 16i64))(v10);
        i != -1;
        i = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v10 + 24i64))(v10, i) )
  {
    v12 = v6->m_agents.m_size;
    v13 = 0;
    v14 = 0i64;
    if ( v12 <= 0 )
    {
LABEL_6:
      v13 = -1;
      v14 = -1i64;
    }
    else
    {
      v15 = v6->m_agents.m_data;
      while ( v15->m_key != i )
      {
        ++v14;
        ++v13;
        ++v15;
        if ( v14 >= v12 )
          goto LABEL_6;
      }
    }
    LODWORD(v29[0]) = i;
    if ( *(_BYTE *)v8->m_filter.m_storage->vfptr->isCollisionEnabled(
                     (hkpShapeCollectionFilter *)&v8->m_filter.m_storage->vfptr,
                     (hkBool *)&v30,
                     v8,
                     v9,
                     v36,
                     (hkpShapeContainer *)v10,
                     v29[0]) )
    {
      v16 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v10 + 40i64))(v10, i, &v35);
      v32 = i;
      v31 = v16;
      if ( v14 == -1 )
      {
        if ( v6->m_agents.m_size == (v6->m_agents.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_agents, 16);
        v17 = (signed __int64)&v6->m_agents.m_data[v6->m_agents.m_size++];
        *(_DWORD *)v17 = i;
        v18 = v8->m_dispatcher.m_storage;
        v19 = (signed __int64)v8->m_dispatcher.m_storage->m_agent2TypesPred;
        if ( !v8->m_createPredictiveAgents.m_storage )
          v19 = (signed __int64)v18->m_agent2Types;
        *(_QWORD *)(v17 + 8) = v18->m_agent2Func[*(unsigned __int8 *)((unsigned __int8)v9->m_shape->m_type.m_storage
                                                                    + v19
                                                                    + 35i64 * *(unsigned __int8 *)(v31 + 16))].m_createFunc(
                                 (hkpCdBody *)&v31,
                                 v9,
                                 v8,
                                 v6->m_contactMgr);
      }
      else
      {
        v20 = v6->m_agents.m_data[v14].m_agent;
        ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpConstraintOwner *))v20->vfptr[4].__vecDelDtor)(
          v20,
          &v31,
          v9,
          v8,
          constraintOwner);
      }
    }
    else if ( v14 != -1 )
    {
      v21 = v14;
      v22 = v6->m_agents.m_data[v21].m_agent;
      ((void (__fastcall *)(hkpCollisionAgent *, hkpConstraintOwner *))v22->vfptr[3].__first_virtual_table_function__)(
        v22,
        constraintOwner);
      v23 = --v6->m_agents.m_size;
      if ( (_DWORD)v23 != v13 )
      {
        v24 = 2i64;
        v25 = 16 * v23;
        v26 = (signed __int64)&v6->m_agents.m_data[v21];
        v27 = v25 - 4 * v21;
        do
        {
          v28 = *(_QWORD *)(v27 + v26);
          v26 += 8i64;
          *(_QWORD *)(v26 - 8) = v28;
          --v24;
        }
        while ( v24 );
      }
    }
  }
}


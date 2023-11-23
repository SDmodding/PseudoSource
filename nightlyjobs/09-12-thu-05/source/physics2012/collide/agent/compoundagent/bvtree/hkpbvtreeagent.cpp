// File Line: 57
// RVA: 0xD1C6B0
void __fastcall hkpBvTreeAgent::hkpBvTreeAgent(hkpBvTreeAgent *this, hkpContactMgr *mgr)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_contactMgr = mgr;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBvTreeAgent::`vftable;
  this->m_collisionPartners.m_capacityAndFlags = 0x80000000;
  this->m_collisionPartners.m_data = 0i64;
  this->m_collisionPartners.m_size = 0;
  this->m_cachedAabb.m_max.m_quad = _mm_shuffle_ps(
                                      (__m128)xmmword_141A712A0,
                                      _mm_unpackhi_ps((__m128)xmmword_141A712A0, this->m_cachedAabb.m_max.m_quad),
                                      196);
  this->m_cachedAabb.m_min.m_quad = _mm_shuffle_ps(
                                      (__m128)xmmword_141A712A0,
                                      _mm_unpackhi_ps((__m128)xmmword_141A712A0, this->m_cachedAabb.m_min.m_quad),
                                      196);
}

// File Line: 66
// RVA: 0xD1C3C0
hkBool *__fastcall hkpBvTreeAgent::getUseAabbCaching(hkBool *result)
{
  result->m_bool = hkpBvTreeAgent::m_useAabbCaching.m_bool;
  return result;
}

// File Line: 71
// RVA: 0xD1C3B0
void __fastcall hkpBvTreeAgent::setUseAabbCaching(hkBool useIt)
{
  hkpBvTreeAgent::m_useAabbCaching.m_bool = useIt.m_bool;
}

// File Line: 76
// RVA: 0xD1ABB0
void __fastcall hkpBvTreeAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-30h] BYREF

  f.m_createFunc = hkpBvTreeAgent::createBvTreeShapeAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpBvTreeAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, BV_TREE, ALL_SHAPE_TYPES);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE, ALL_SHAPE_TYPES);
  f.m_createFunc = hkpBvTreeAgent::createShapeBvAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpBvTreeAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, ALL_SHAPE_TYPES, BV_TREE);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, ALL_SHAPE_TYPES, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE);
  f.m_createFunc = hkpBvTreeAgent::createBvBvAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpBvTreeAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, BV_TREE, BV_TREE);
  hkpCollisionDispatcher::registerCollisionAgent(
    dispatcher,
    &f,
    TRI_SAMPLED_HEIGHT_FIELD_BV_TREE,
    TRI_SAMPLED_HEIGHT_FIELD_BV_TREE);
}

// File Line: 116
// RVA: 0xD1CA30
hkpBvTreeAgent *__fastcall hkpBvTreeAgent::createBvTreeShapeAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpBvTreeAgent *result; // rax
  hkpBvTreeAgent *v7; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpBvTreeAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  v7 = result;
  if ( result )
  {
    hkpBvTreeAgent::hkpBvTreeAgent(result, mgr);
    v7->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpBvTreeAgent>::`vftable;
    return v7;
  }
  return result;
}

// File Line: 124
// RVA: 0xD1C9E0
void __fastcall hkpBvTreeAgent::createShapeBvAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpBvTreeAgent *v6; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkpBvTreeAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  if ( v6 )
    hkpBvTreeAgent::hkpBvTreeAgent(v6, mgr);
}

// File Line: 133
// RVA: 0xD1CAA0
void __fastcall hkpBvTreeAgent::createBvBvAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **v5; // rax
  hkpBvTreeAgent *v6; // rax
  _QWORD **Value; // rax
  hkpBvTreeAgent *v8; // rax
  hkpBvTreeAgent *v9; // rbx

  if ( _mm_shuffle_ps(
         (__m128)*((unsigned int *)bodyA->m_motion + 40),
         (__m128)*((unsigned int *)bodyA->m_motion + 40),
         0).m128_f32[0] >= _mm_shuffle_ps(
                             (__m128)*((unsigned int *)bodyB->m_motion + 40),
                             (__m128)*((unsigned int *)bodyB->m_motion + 40),
                             0).m128_f32[0] )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkpBvTreeAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
    v9 = v8;
    if ( v8 )
    {
      hkpBvTreeAgent::hkpBvTreeAgent(v8, mgr);
      v9->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpBvTreeAgent>::`vftable;
    }
  }
  else
  {
    v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (hkpBvTreeAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v5[11] + 8i64))(v5[11], 80i64);
    if ( v6 )
      hkpBvTreeAgent::hkpBvTreeAgent(v6, mgr);
  }
}

// File Line: 156
// RVA: 0xD1C330
void __fastcall hkpBvTreeAgent::cleanup(hkpBvTreeAgent *this, hkpConstraintOwner *info)
{
  hkpBvTreeAgent::hkpBvAgentEntryInfo *m_data; // rbx
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v5; // rdi
  hkpCollisionAgent **p_m_collisionAgent; // rbx

  m_data = this->m_collisionPartners.m_data;
  v5 = &m_data[this->m_collisionPartners.m_size];
  if ( m_data != v5 )
  {
    p_m_collisionAgent = &m_data->m_collisionAgent;
    do
    {
      if ( *p_m_collisionAgent )
        ((void (__fastcall *)(hkpCollisionAgent *, hkpConstraintOwner *))(*p_m_collisionAgent)->vfptr[3].__first_virtual_table_function__)(
          *p_m_collisionAgent,
          info);
      p_m_collisionAgent += 2;
    }
    while ( p_m_collisionAgent - 1 != (hkpCollisionAgent **)v5 );
  }
  this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 173
// RVA: 0xD1C5B0
void __fastcall hkpBvTreeAgent::invalidateTim(hkpBvTreeAgent *this, hkpCollisionInput *input)
{
  hkpBvTreeAgent::hkpBvAgentEntryInfo *m_data; // rbx
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v4; // rdi
  hkpCollisionAgent **p_m_collisionAgent; // rbx

  m_data = this->m_collisionPartners.m_data;
  v4 = &m_data[this->m_collisionPartners.m_size];
  if ( m_data != v4 )
  {
    p_m_collisionAgent = &m_data->m_collisionAgent;
    do
    {
      if ( *p_m_collisionAgent )
        ((void (__fastcall *)(hkpCollisionAgent *, hkpCollisionInput *))(*p_m_collisionAgent)->vfptr[4].__first_virtual_table_function__)(
          *p_m_collisionAgent,
          input);
      p_m_collisionAgent += 2;
    }
    while ( p_m_collisionAgent - 1 != (hkpCollisionAgent **)v4 );
  }
}

// File Line: 188
// RVA: 0xD1C620
void __fastcall hkpBvTreeAgent::warpTime(hkpBvTreeAgent *this, float oldTime, float newTime, hkpCollisionInput *input)
{
  __int64 v4; // rdx
  __int64 v5; // r8
  hkpBvTreeAgent::hkpBvAgentEntryInfo *m_data; // rbx
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v8; // rdi
  hkpCollisionAgent **p_m_collisionAgent; // rbx

  m_data = this->m_collisionPartners.m_data;
  v8 = &m_data[this->m_collisionPartners.m_size];
  if ( m_data != v8 )
  {
    p_m_collisionAgent = &m_data->m_collisionAgent;
    do
    {
      if ( *p_m_collisionAgent )
        ((void (__fastcall *)(hkpCollisionAgent *, __int64, __int64, hkpCollisionInput *))(*p_m_collisionAgent)->vfptr[5].__vecDelDtor)(
          *p_m_collisionAgent,
          v4,
          v5,
          input);
      p_m_collisionAgent += 2;
    }
    while ( p_m_collisionAgent - 1 != (hkpCollisionAgent **)v8 );
  }
}

// File Line: 238
// RVA: 0xD1C710
hkpCollisionAgent *__fastcall hkpBvTreeAgent::defaultAgentCreate(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  hkpCollisionDispatcher *m_storage; // r10
  __int64 v6; // rcx
  char (*m_agent2TypesPred)[35]; // r11

  m_storage = input->m_dispatcher.m_storage;
  v6 = (unsigned __int8)bodyA->m_shape->m_type.m_storage;
  m_agent2TypesPred = input->m_dispatcher.m_storage->m_agent2TypesPred;
  if ( !input->m_createPredictiveAgents.m_storage )
    m_agent2TypesPred = m_storage->m_agent2Types;
  return m_storage->m_agent2Func[(unsigned __int8)m_agent2TypesPred[v6][(unsigned __int8)bodyB->m_shape->m_type.m_storage]].m_createFunc(
           bodyA,
           bodyB,
           input,
           mgr);
}

// File Line: 308
// RVA: 0xD1C3E0
void __fastcall hkpBvTreeAgent::updateShapeCollectionFilter(
        hkpBvTreeAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpConstraintOwner *constraintOwner)
{
  int v9; // ebp
  __int64 v10; // rdi
  hkpConstraintOwner *v11; // r12
  __int64 v12; // rsi
  __int64 v13; // rax
  hkpBvTreeAgent::hkpBvAgentEntryInfo *m_data; // rdx
  hkpCollisionFilter *m_storage; // rcx
  hkBool *v16; // rax
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v17; // rdi
  hkpCollisionDispatcher *v18; // r10
  char (*m_agent2TypesPred)[35]; // rdx
  hkpCollisionAgent *m_collisionAgent; // rcx
  hkpCollisionAgent *v21; // rcx
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v22; // rdi
  __int64 v23; // [rsp+40h] [rbp-258h] BYREF
  unsigned int m_key; // [rsp+48h] [rbp-250h]
  const void *m_motion; // [rsp+50h] [rbp-248h]
  hkpCdBody *v26; // [rsp+58h] [rbp-240h]
  char v27[512]; // [rsp+60h] [rbp-238h] BYREF
  char v28; // [rsp+2A0h] [rbp+8h] BYREF
  __int64 v29; // [rsp+2B0h] [rbp+18h]

  v9 = 0;
  v10 = ((__int64 (*)(void))bodyB->m_shape->vfptr[7].__vecDelDtor)();
  v29 = v10;
  if ( this->m_collisionPartners.m_size > 0 )
  {
    v11 = constraintOwner;
    v12 = 0i64;
    do
    {
      v13 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v10 + 40i64))(
              v10,
              this->m_collisionPartners.m_data[v12].m_key,
              v27);
      m_data = this->m_collisionPartners.m_data;
      m_motion = bodyB->m_motion;
      v26 = bodyB;
      m_key = m_data[v12].m_key;
      m_storage = input->m_filter.m_storage;
      v23 = v13;
      v16 = m_storage->hkpShapeCollectionFilter::vfptr->isCollisionEnabled(
              &m_storage->hkpShapeCollectionFilter,
              (hkBool *)&v28,
              input,
              bodyA,
              bodyB,
              (hkpShapeContainer *)v10,
              m_data[v12].m_key);
      v17 = this->m_collisionPartners.m_data;
      if ( v16->m_bool )
      {
        if ( v17[v12].m_collisionAgent == hkpNullAgent::getNullAgent() )
        {
          v18 = input->m_dispatcher.m_storage;
          m_agent2TypesPred = input->m_dispatcher.m_storage->m_agent2TypesPred;
          if ( !input->m_createPredictiveAgents.m_storage )
            m_agent2TypesPred = v18->m_agent2Types;
          this->m_collisionPartners.m_data[v12].m_collisionAgent = v18->m_agent2Func[(unsigned __int8)m_agent2TypesPred[(unsigned __int8)bodyA->m_shape->m_type.m_storage][*(unsigned __int8 *)(v23 + 16)]].m_createFunc(
                                                                     bodyA,
                                                                     (hkpCdBody *)&v23,
                                                                     input,
                                                                     this->m_contactMgr);
        }
        else
        {
          m_collisionAgent = this->m_collisionPartners.m_data[v12].m_collisionAgent;
          ((void (__fastcall *)(hkpCollisionAgent *, hkpCdBody *, __int64 *, hkpCollisionInput *, hkpConstraintOwner *))m_collisionAgent->vfptr[4].__vecDelDtor)(
            m_collisionAgent,
            bodyA,
            &v23,
            input,
            v11);
        }
      }
      else if ( v17[v12].m_collisionAgent != hkpNullAgent::getNullAgent() )
      {
        v21 = this->m_collisionPartners.m_data[v12].m_collisionAgent;
        ((void (__fastcall *)(hkpCollisionAgent *, hkpConstraintOwner *))v21->vfptr[3].__first_virtual_table_function__)(
          v21,
          v11);
        v22 = this->m_collisionPartners.m_data;
        v22[v12].m_collisionAgent = hkpNullAgent::getNullAgent();
      }
      v10 = v29;
      ++v9;
      ++v12;
    }
    while ( v9 < this->m_collisionPartners.m_size );
  }
}

// File Line: 351
// RVA: 0xD1B530
void __fastcall hkpBvTreeAgent::processCollision(
        hkpBvTreeAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *result)
{
  hkpBvTreeAgent *v5; // r13
  hkpCdBody *v7; // r14
  hkpCdBody *v8; // r12
  _QWORD *Value; // r9
  unsigned __int64 v10; // r8
  unsigned __int64 v11; // rax
  hkTransformf *m_motion; // r8
  hkTransformf *v13; // rdx
  __int64 v14; // rax
  __m128 *p_m_quad; // rbx
  __int64 v16; // r8
  __m128 *v17; // r15
  __m128 *v18; // rdi
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm6
  __m128 v22; // xmm4
  __m128 v23; // xmm5
  __m128 v24; // xmm6
  __m128 v25; // xmm6
  __m128 v26; // xmm3
  hkpShape *m_shape; // rcx
  hkBaseObjectVtbl *vfptr; // rax
  __m128i v29; // xmm9
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm8
  __m128 v33; // xmm7
  __m128 v34; // xmm1
  __m128 v35; // xmm6
  __m128 *v36; // rax
  __m128 v37; // xmm5
  __m128 v38; // xmm3
  __m128 v39; // xmm1
  __m128 v40; // xmm7
  __m128 v41; // xmm2
  __m128 v42; // xmm10
  __m128 v43; // xmm5
  __m128 v44; // xmm6
  __m128 v45; // xmm2
  __m128 v46; // xmm7
  __m128 v47; // xmm10
  __m128 v48; // xmm2
  __m128 v49; // xmm6
  __m128 v50; // xmm5
  __m128 v51; // xmm3
  __m128 v52; // xmm2
  __m128 v53; // xmm9
  __int64 v54; // rax
  hkpBvTreeAgent::hkpBvAgentEntryInfo *m_data; // rdi
  unsigned int *v56; // rdx
  int v57; // r8d
  hkArray<hkpBvTreeAgent::hkpBvAgentEntryInfo,hkContainerHeapAllocator> *p_m_collisionPartners; // r14
  unsigned int *v59; // rbx
  unsigned int *v60; // r15
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v61; // r13
  __int64 v62; // r12
  __int64 v63; // rax
  int v64; // r9d
  __int64 v65; // rdx
  __int64 v66; // rcx
  __int64 v67; // rax
  __int64 m_size; // r15
  __int64 v69; // rdi
  unsigned int *v70; // r13
  __int64 v71; // rcx
  int v72; // edi
  int v73; // eax
  __int64 v74; // rbx
  int v75; // r15d
  int v76; // eax
  int v77; // r9d
  __int64 v78; // rbx
  __int64 v79; // rcx
  __int64 v80; // rax
  hkpCollisionFilter *m_storage; // rcx
  hkpCollisionDispatcher *v82; // r10
  char (*m_agent2TypesPred)[35]; // rdx
  hkpNullAgent *NullAgent; // rax
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v85; // rbx
  __int64 v86; // rax
  __int64 v87; // rdi
  unsigned int *p_m_key; // rdi
  _QWORD *v89; // rax
  unsigned __int64 v90; // rdx
  _QWORD *v91; // rcx
  _QWORD *v92; // r8
  unsigned __int64 v93; // rax
  _QWORD *v94; // rcx
  __int64 v95; // r14
  __int64 v96; // r15
  __int64 v97; // rax
  _QWORD *v98; // rax
  _QWORD *v99; // rcx
  _QWORD *v100; // r8
  unsigned __int64 v101; // rax
  _QWORD *v102; // rcx
  int v103; // r15d
  __int64 v104; // rax
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v105; // rbx
  __int64 v106; // r13
  unsigned int *v107; // rdi
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v108; // r13
  int v109; // r14d
  hkLifoAllocator *v110; // rax
  unsigned __int64 m_cur; // r8
  int v112; // edx
  void *v113; // rcx
  __int64 v114; // rax
  int v115; // r14d
  int v116; // r9d
  unsigned __int64 v117; // r14
  unsigned int v118; // r15d
  __int64 v119; // rax
  __int64 v120; // rax
  hkpCollisionFilter *v121; // rcx
  hkpCollisionDispatcher *v122; // r10
  char (*m_agent2Types)[35]; // rdx
  hkpNullAgent *v124; // rax
  hkpCollisionAgent *m_collisionAgent; // rcx
  __int64 v126; // r12
  hkpCollisionAgent **p_m_collisionAgent; // rbx
  unsigned int *v128; // r13
  hkpNullAgent **v129; // r14
  int v130; // ebx
  __int64 v131; // rax
  hkpCollisionFilter *v132; // rcx
  hkpCollisionDispatcher *v133; // r10
  char (*v134)[35]; // rdx
  hkpNullAgent *v135; // rax
  int v136; // eax
  int v137; // ebx
  int v138; // r14d
  int v139; // eax
  int v140; // eax
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v141; // rdx
  __int64 *v142; // rcx
  __int64 v143; // r8
  __int64 v144; // rax
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v145; // rcx
  __int64 v146; // r8
  unsigned __int64 v147; // rdx
  char *v148; // rdi
  int v149; // ebx
  bool v150; // zf
  signed int v151; // ebx
  hkLifoAllocator *v152; // rax
  int v153; // r8d
  __m128 array; // [rsp+40h] [rbp-B8h] BYREF
  void *p[2]; // [rsp+50h] [rbp-A8h]
  hkpContactMgr *m_contactMgr; // [rsp+60h] [rbp-98h]
  hkpShapeContainer *v157; // [rsp+68h] [rbp-90h]
  unsigned int *v158; // [rsp+70h] [rbp-88h]
  __int64 v159; // [rsp+78h] [rbp-80h] BYREF
  unsigned int m_key; // [rsp+80h] [rbp-78h]
  __int64 v161; // [rsp+88h] [rbp-70h]
  hkpCdBody *v162; // [rsp+90h] [rbp-68h]
  hkTransformf v163; // [rsp+98h] [rbp-60h] BYREF
  hkpShapeContainer *v164; // [rsp+D8h] [rbp-20h]
  __int64 v165; // [rsp+E0h] [rbp-18h] BYREF
  int v166; // [rsp+E8h] [rbp-10h]
  const void *v167; // [rsp+F0h] [rbp-8h]
  hkpCdBody *v168; // [rsp+F8h] [rbp+0h]
  char v169[512]; // [rsp+108h] [rbp+10h] BYREF
  unsigned int *pArr; // [rsp+308h] [rbp+210h] BYREF
  int v171; // [rsp+310h] [rbp+218h]
  int v172; // [rsp+314h] [rbp+21Ch]
  char v173; // [rsp+318h] [rbp+220h] BYREF
  char v174[520]; // [rsp+518h] [rbp+420h] BYREF
  hkpBvTreeAgent *retaddr; // [rsp+7B8h] [rbp+6C0h] BYREF
  hkpBvTreeAgent *v176; // [rsp+7C0h] [rbp+6C8h] BYREF
  hkpCdBody *v177; // [rsp+7C8h] [rbp+6D0h]
  hkpCdBody *v178; // [rsp+7D0h] [rbp+6D8h] BYREF
  __int64 v179; // [rsp+7D8h] [rbp+6E0h]

  v178 = bodyB;
  v177 = bodyA;
  v176 = this;
  v5 = this;
  v7 = bodyB;
  v8 = bodyA;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = Value[1];
  if ( v10 < Value[3] )
  {
    *(_QWORD *)v10 = "LtBvTree";
    *(_QWORD *)(v10 + 16) = "StQueryTree";
    v11 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v11;
    Value[1] = v10 + 24;
  }
  m_motion = (hkTransformf *)v8->m_motion;
  v13 = (hkTransformf *)v7->m_motion;
  v14 = *(_QWORD *)(v179 + 8);
  p_m_quad = 0i64;
  pArr = (unsigned int *)&v173;
  v171 = 0;
  v159 = v14;
  v172 = -2147483520;
  hkTransformf::setMulInverseMul(&v163, v13, m_motion);
  *(float *)&v178 = input->m_stepInfo.m_deltaTime.m_storage;
  v17 = (__m128 *)v8->m_motion;
  v18 = (__m128 *)v7->m_motion;
  v19 = _mm_shuffle_ps((__m128)(unsigned int)v178, (__m128)(unsigned int)v178, 0);
  v20 = v17[5];
  v21 = v18[5];
  v22 = _mm_mul_ps(_mm_shuffle_ps(v21, v21, 255), v19);
  v23 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 255), v19);
  v24 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v21, v18[4]), v22), _mm_mul_ps(_mm_sub_ps(v17[4], v20), v23));
  v25 = _mm_shuffle_ps(
          v24,
          _mm_unpackhi_ps(
            v24,
            _mm_add_ps(
              _mm_mul_ps(
                _mm_mul_ps(_mm_shuffle_ps(v18[9], v18[9], 255), v22),
                _mm_shuffle_ps((__m128)v18[10].m128_u32[0], (__m128)v18[10].m128_u32[0], 0)),
              _mm_mul_ps(
                _mm_mul_ps(_mm_shuffle_ps(v17[9], v17[9], 255), v23),
                _mm_shuffle_ps((__m128)v17[10].m128_u32[0], (__m128)v17[10].m128_u32[0], 0)))),
          196);
  if ( hkpBvTreeAgent::m_useAabbCaching.m_bool )
    p_m_quad = &v5->m_cachedAabb.m_min.m_quad;
  v26 = v18[2];
  m_shape = v8->m_shape;
  vfptr = v8->m_shape->vfptr;
  v29 = (__m128i)_mm_mul_ps(
                   _mm_shuffle_ps(
                     (__m128)LODWORD(input->m_tolerance.m_storage),
                     (__m128)LODWORD(input->m_tolerance.m_storage),
                     0),
                   (__m128)xmmword_141A711B0);
  v30 = _mm_unpacklo_ps(*v18, v18[1]);
  v31 = _mm_movelh_ps(v30, v26);
  v32 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(v31, v30), v26, 212), _mm_shuffle_ps(v25, v25, 85)),
            _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v31)),
          _mm_mul_ps(_mm_shuffle_ps(_mm_unpackhi_ps(*v18, v18[1]), v26, 228), _mm_shuffle_ps(v25, v25, 170)));
  if ( input->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage )
  {
    v33 = _mm_shuffle_ps((__m128)v17[10].m128_u32[0], (__m128)v17[10].m128_u32[0], 0);
    v34 = _mm_shuffle_ps(v18[9], v18[9], 255);
    v35 = _mm_mul_ps(_mm_shuffle_ps((__m128)v18[10].m128_u32[0], (__m128)v18[10].m128_u32[0], 0), _mm_mul_ps(v34, v34));
    ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, __m128 *))vfptr[2].__vecDelDtor)(
      m_shape,
      &v163,
      v16,
      &array);
    v36 = (__m128 *)v7->m_motion;
    v37 = _mm_sub_ps(v17[5], v36[3]);
    v38 = v36[2];
    v39 = _mm_unpacklo_ps(*v36, v36[1]);
    v40 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_add_ps(_mm_add_ps(v33, (__m128)v29), v35), 4), 4);
    v41 = _mm_movelh_ps(v39, v38);
    v42 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(v41, v39), v38, 212), _mm_shuffle_ps(v37, v37, 85)),
              _mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), v41)),
            _mm_mul_ps(_mm_shuffle_ps(_mm_unpackhi_ps(*v36, v36[1]), v38, 228), _mm_shuffle_ps(v37, v37, 170)));
    v43 = _mm_max_ps(array, _mm_sub_ps(v42, v40));
    array = v43;
    v44 = _mm_min_ps(*(__m128 *)p, _mm_add_ps(v42, v40));
    *(__m128 *)p = v44;
    v45 = v18[9];
    v46 = _mm_sub_ps(v44, v43);
    if ( _mm_shuffle_ps(v45, v45, 255).m128_f32[0] > 0.0 )
    {
      v47 = _mm_sub_ps(v42, v18[8]);
      v48 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), v47), _mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v45));
      *(float *)&v178 = input->m_stepInfo.m_deltaTime.m_storage;
      v32 = _mm_add_ps(
              v32,
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(v18[5], v18[5], 255),
                  _mm_shuffle_ps((__m128)(unsigned int)v178, (__m128)(unsigned int)v178, 0)),
                _mm_shuffle_ps(v48, v48, 201)));
    }
    v49 = _mm_add_ps(v44, _mm_max_ps((__m128)0i64, v32));
    v50 = _mm_add_ps(v43, _mm_min_ps((__m128)0i64, v32));
    *(__m128 *)p = v49;
    array = v50;
  }
  else
  {
    ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, __m128 *))vfptr[2].__vecDelDtor)(
      m_shape,
      &v163,
      v16,
      &array);
    v49 = *(__m128 *)p;
    v50 = array;
    v46 = _mm_sub_ps(*(__m128 *)p, array);
  }
  if ( p_m_quad )
  {
    if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v49, p_m_quad[1]), _mm_cmple_ps(*p_m_quad, v50))) & 7) == 7 )
    {
      v171 = 0;
      if ( v172 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, pArr, 4 * v172);
      goto LABEL_49;
    }
    v51 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_40000001), (__m128)LODWORD(FLOAT_0_40000001), 0), v46);
    *(float *)&v178 = FLOAT_N2_0;
    v52 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_N2_0), (__m128)LODWORD(FLOAT_N2_0), 0);
    v53 = (__m128)_mm_srli_si128(_mm_slli_si128(v29, 4), 4);
    array = _mm_add_ps(
              _mm_sub_ps(v50, v53),
              _mm_max_ps(
                _mm_mul_ps(_mm_max_ps((__m128)0i64, v32), v52),
                _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v51)));
    *p_m_quad = array;
    *(__m128 *)p = _mm_add_ps(_mm_add_ps(v49, v53), _mm_min_ps(_mm_mul_ps(_mm_min_ps((__m128)0i64, v32), v52), v51));
    p_m_quad[1] = *(__m128 *)p;
  }
  ((void (__fastcall *)(hkpShape *, __m128 *, unsigned int **))v7->m_shape->vfptr[8].__first_virtual_table_function__)(
    v7->m_shape,
    &array,
    &pArr);
  v54 = ((__int64 (__fastcall *)(hkpShape *))v7->m_shape->vfptr[7].__vecDelDtor)(v7->m_shape);
  v167 = v7->m_motion;
  v168 = v7;
  v164 = (hkpShapeContainer *)v54;
  if ( hkpBvTreeAgent::m_useFastUpdate.m_bool )
  {
    m_data = v5->m_collisionPartners.m_data;
    v56 = pArr;
    v57 = v171;
    p_m_collisionPartners = &v5->m_collisionPartners;
    m_contactMgr = v5->m_contactMgr;
    v59 = pArr;
    v60 = &pArr[v171];
    v61 = &m_data[v5->m_collisionPartners.m_size];
    if ( m_data != v61 )
    {
      v62 = v159;
      while ( 1 )
      {
        if ( v59 == v60 || m_data->m_key != *v59 )
        {
          v59 = v56;
          if ( v56 == v60 )
          {
LABEL_24:
            ((void (__fastcall *)(hkpCollisionAgent *, __int64))m_data->m_collisionAgent->vfptr[3].__first_virtual_table_function__)(
              m_data->m_collisionAgent,
              v62);
            --p_m_collisionPartners->m_size;
            v63 = m_data - p_m_collisionPartners->m_data;
            v64 = 16 * (p_m_collisionPartners->m_size - v63);
            v65 = (__int64)&p_m_collisionPartners->m_data[(int)v63];
            if ( v64 > 0 )
            {
              v66 = ((unsigned int)(v64 - 1) >> 3) + 1;
              do
              {
                v67 = *(_QWORD *)(v65 + 16);
                v65 += 8i64;
                *(_QWORD *)(v65 - 8) = v67;
                --v66;
              }
              while ( v66 );
            }
            v56 = pArr;
            --m_data;
            --v61;
            goto LABEL_28;
          }
          while ( m_data->m_key != *v59 )
          {
            if ( ++v59 == v60 )
              goto LABEL_24;
          }
        }
        ++v59;
LABEL_28:
        if ( ++m_data == v61 )
        {
          v57 = v171;
          v8 = (hkpCdBody *)v176;
          break;
        }
      }
    }
    m_size = p_m_collisionPartners->m_size;
    v157 = v164;
    if ( v57 != (_DWORD)m_size )
    {
      v69 = (__int64)p_m_collisionPartners->m_data;
      v70 = v56;
      v71 = (__int64)&p_m_collisionPartners->m_data[m_size];
      v158 = &v56[v57];
      if ( v56 != v158 )
      {
        do
        {
          if ( v69 == v71 || *(_DWORD *)v69 != *v70 )
          {
            v72 = m_size + 1;
            v73 = p_m_collisionPartners->m_capacityAndFlags & 0x3FFFFFFF;
            v74 = v70 - v56;
            v75 = m_size - v74;
            if ( v72 > v73 )
            {
              v76 = 2 * v73;
              v77 = v72;
              if ( v72 < v76 )
                v77 = v76;
              hkArrayUtil::_reserve(
                (hkResult *)&v178,
                &hkContainerHeapAllocator::s_alloc,
                (const void **)&p_m_collisionPartners->m_data,
                v77,
                16);
            }
            v78 = 16i64 * (int)v74;
            hkMemUtil::memMove(
              (_BYTE *)&p_m_collisionPartners->m_data[1] + v78,
              (_BYTE *)p_m_collisionPartners->m_data + v78,
              16 * v75);
            v79 = (__int64)v164;
            p_m_collisionPartners->m_size = v72;
            v69 = (__int64)p_m_collisionPartners->m_data + v78;
            LODWORD(v78) = *v70;
            v80 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v79 + 40i64))(v79, *v70, v169);
            m_storage = input->m_filter.m_storage;
            v166 = v78;
            v165 = v80;
            if ( m_storage->hkpShapeCollectionFilter::vfptr->isCollisionEnabled(
                   &m_storage->hkpShapeCollectionFilter,
                   (hkBool *)&v176,
                   input,
                   v8,
                   v177,
                   v157,
                   *v70)->m_bool )
            {
              v82 = input->m_dispatcher.m_storage;
              m_agent2TypesPred = input->m_dispatcher.m_storage->m_agent2TypesPred;
              if ( !input->m_createPredictiveAgents.m_storage )
                m_agent2TypesPred = v82->m_agent2Types;
              NullAgent = (hkpNullAgent *)v82->m_agent2Func[(unsigned __int8)m_agent2TypesPred[(unsigned __int8)v8->m_shape->m_type.m_storage][*(unsigned __int8 *)(v165 + 16)]].m_createFunc(
                                            v8,
                                            (hkpCdBody *)&v165,
                                            input,
                                            m_contactMgr);
            }
            else
            {
              NullAgent = hkpNullAgent::getNullAgent();
            }
            *(_QWORD *)(v69 + 8) = NullAgent;
            *(_DWORD *)v69 = *v70;
            LODWORD(m_size) = p_m_collisionPartners->m_size;
            v56 = pArr;
            v71 = (__int64)&p_m_collisionPartners->m_data[(int)m_size];
          }
          ++v70;
          v69 += 16i64;
        }
        while ( v70 != v158 );
      }
    }
    v5 = retaddr;
  }
  else
  {
    v103 = v171;
    if ( v171 > 1 )
    {
      hkAlgorithm::quickSortRecursive<unsigned int,hkAlgorithm::less<unsigned int>>(pArr, 0, v171 - 1, 0);
      v103 = v171;
    }
    v104 = (__int64)v5->m_contactMgr;
    v105 = v5->m_collisionPartners.m_data;
    v106 = v5->m_collisionPartners.m_size;
    v107 = pArr;
    v157 = (hkpShapeContainer *)v104;
    v108 = &v105[v106];
    v109 = v103;
    LODWORD(p[1]) = v103;
    v158 = &pArr[v103];
    array.m128_u64[0] = 0i64;
    array.m128_u64[1] = 0x8000000000000000ui64;
    if ( v103 )
    {
      v110 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (unsigned __int64)v110->m_cur;
      v112 = (16 * v103 + 127) & 0xFFFFFF80;
      v113 = (void *)(m_cur + v112);
      if ( v112 > v110->m_slabSize || v113 > v110->m_end )
      {
        v114 = hkLifoAllocator::allocateFromNewSlab(v110, v112);
        v103 = v171;
        array.m128_u64[0] = v114;
      }
      else
      {
        v110->m_cur = v113;
        v103 = v171;
        array.m128_u64[0] = m_cur;
      }
    }
    else
    {
      array.m128_u64[0] = 0i64;
    }
    array.m128_i32[3] = v109 | 0x80000000;
    v115 = v109 & 0x3FFFFFFF;
    p[0] = (void *)array.m128_u64[0];
    if ( v115 < v103 )
    {
      v116 = v103;
      if ( v103 < 2 * v115 )
        v116 = 2 * v115;
      hkArrayUtil::_reserve((hkResult *)&v178, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v116, 16);
    }
    v117 = array.m128_u64[0];
    array.m128_i32[2] = v103;
    m_contactMgr = (hkpContactMgr *)v164;
    if ( v105 != v108 )
    {
      while ( v107 != v158 )
      {
        v118 = *v107;
        if ( *v107 == v105->m_key )
        {
          v119 = *(_QWORD *)&v105->m_key;
          v117 += 16i64;
          ++v105;
          *(_QWORD *)(v117 - 16) = v119;
          ++v107;
          *(_QWORD *)(v117 - 8) = v105[-1].m_collisionAgent;
        }
        else if ( v118 >= v105->m_key )
        {
          m_collisionAgent = v105->m_collisionAgent;
          if ( m_collisionAgent )
            ((void (__fastcall *)(hkpCollisionAgent *, __int64))m_collisionAgent->vfptr[3].__first_virtual_table_function__)(
              m_collisionAgent,
              v159);
          ++v105;
        }
        else
        {
          v120 = (__int64)v164->vfptr->getChildShape(v164, v118, (char (*)[512])v169);
          v121 = input->m_filter.m_storage;
          v166 = v118;
          v165 = v120;
          if ( v121->hkpShapeCollectionFilter::vfptr->isCollisionEnabled(
                 &v121->hkpShapeCollectionFilter,
                 (hkBool *)&v178,
                 input,
                 v8,
                 v177,
                 (hkpShapeContainer *)m_contactMgr,
                 *v107)->m_bool )
          {
            v122 = input->m_dispatcher.m_storage;
            m_agent2Types = input->m_dispatcher.m_storage->m_agent2TypesPred;
            if ( !input->m_createPredictiveAgents.m_storage )
              m_agent2Types = v122->m_agent2Types;
            v124 = (hkpNullAgent *)v122->m_agent2Func[(unsigned __int8)m_agent2Types[(unsigned __int8)v8->m_shape->m_type.m_storage][*(unsigned __int8 *)(v165 + 16)]].m_createFunc(
                                     v8,
                                     (hkpCdBody *)&v165,
                                     input,
                                     (hkpContactMgr *)v157);
          }
          else
          {
            v124 = hkpNullAgent::getNullAgent();
          }
          *(_QWORD *)(v117 + 8) = v124;
          v117 += 16i64;
          *(_DWORD *)(v117 - 16) = *v107++;
        }
        if ( v105 == v108 )
          goto LABEL_91;
      }
      if ( v105 != v108 )
      {
        v126 = v159;
        p_m_collisionAgent = &v105->m_collisionAgent;
        do
        {
          if ( *p_m_collisionAgent )
            ((void (__fastcall *)(hkpCollisionAgent *, __int64))(*p_m_collisionAgent)->vfptr[3].__first_virtual_table_function__)(
              *p_m_collisionAgent,
              v126);
          p_m_collisionAgent += 2;
        }
        while ( p_m_collisionAgent - 1 != (hkpCollisionAgent **)v108 );
        v8 = (hkpCdBody *)v176;
      }
LABEL_91:
      v103 = array.m128_i32[2];
    }
    v128 = v158;
    if ( v107 != v158 )
    {
      v129 = (hkpNullAgent **)(v117 + 8);
      do
      {
        v130 = *v107;
        v131 = (__int64)v164->vfptr->getChildShape(v164, *v107, (char (*)[512])v169);
        v132 = input->m_filter.m_storage;
        v166 = v130;
        v165 = v131;
        if ( v132->hkpShapeCollectionFilter::vfptr->isCollisionEnabled(
               &v132->hkpShapeCollectionFilter,
               (hkBool *)&v176,
               input,
               v8,
               v177,
               (hkpShapeContainer *)m_contactMgr,
               *v107)->m_bool )
        {
          v133 = input->m_dispatcher.m_storage;
          v134 = input->m_dispatcher.m_storage->m_agent2TypesPred;
          if ( !input->m_createPredictiveAgents.m_storage )
            v134 = v133->m_agent2Types;
          v135 = (hkpNullAgent *)v133->m_agent2Func[(unsigned __int8)v134[(unsigned __int8)v8->m_shape->m_type.m_storage][*(unsigned __int8 *)(v165 + 16)]].m_createFunc(
                                   v8,
                                   (hkpCdBody *)&v165,
                                   input,
                                   (hkpContactMgr *)v157);
        }
        else
        {
          v135 = hkpNullAgent::getNullAgent();
        }
        *v129 = v135;
        v136 = *v107++;
        *((_DWORD *)v129 - 2) = v136;
        v129 += 2;
      }
      while ( v107 != v128 );
      v103 = array.m128_i32[2];
    }
    v5 = retaddr;
    v137 = v103;
    v138 = v103;
    if ( v103 > retaddr->m_collisionPartners.m_size )
      v137 = retaddr->m_collisionPartners.m_size;
    v139 = retaddr->m_collisionPartners.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v139 < v103 )
    {
      v140 = 2 * v139;
      if ( v103 < v140 )
        v103 = v140;
      hkArrayUtil::_reserve(
        (hkResult *)&retaddr,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&retaddr->m_collisionPartners.m_data,
        v103,
        16);
      v103 = array.m128_i32[2];
    }
    v141 = retaddr->m_collisionPartners.m_data;
    if ( v137 > 0 )
    {
      v142 = (__int64 *)array.m128_u64[0];
      v143 = v137;
      do
      {
        v144 = *v142;
        ++v141;
        v142 += 2;
        *(_QWORD *)&v141[-1].m_key = v144;
        v141[-1].m_collisionAgent = (hkpCollisionAgent *)*(v142 - 1);
        --v143;
      }
      while ( v143 );
      v103 = array.m128_i32[2];
    }
    v145 = &retaddr->m_collisionPartners.m_data[v137];
    v146 = v138 - v137;
    if ( v138 - v137 > 0 )
    {
      v147 = array.m128_u64[0] - (unsigned __int64)retaddr->m_collisionPartners.m_data;
      do
      {
        if ( v145 )
        {
          *(_QWORD *)&v145->m_key = *(_QWORD *)((char *)&v145->m_key + v147);
          v145->m_collisionAgent = *(hkpCollisionAgent **)((char *)&v145->m_collisionAgent + v147);
        }
        ++v145;
        --v146;
      }
      while ( v146 );
      v103 = array.m128_i32[2];
    }
    v148 = (char *)p[0];
    v149 = (int)p[1];
    v150 = p[0] == (void *)array.m128_u64[0];
    retaddr->m_collisionPartners.m_size = v138;
    if ( v150 )
      v103 = 0;
    array.m128_i32[2] = v103;
    v151 = (16 * v149 + 127) & 0xFFFFFF80;
    v152 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v153 = (v151 + 15) & 0xFFFFFFF0;
    if ( v151 > v152->m_slabSize || &v148[v153] != v152->m_cur || v152->m_firstNonLifoEnd == v148 )
      hkLifoAllocator::slowBlockFree(v152, v148, v153);
    else
      v152->m_cur = v148;
    array.m128_i32[2] = 0;
    if ( array.m128_i32[3] >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        (void *)array.m128_u64[0],
        16 * array.m128_i32[3]);
    v56 = pArr;
  }
  v171 = 0;
  if ( v172 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v56, 4 * v172);
  v7 = v177;
LABEL_49:
  v85 = v5->m_collisionPartners.m_data;
  v86 = (__int64)v7->m_motion;
  v87 = v5->m_collisionPartners.m_size;
  v162 = v7;
  p_m_key = &v85[v87].m_key;
  v161 = v86;
  v89 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v91 = (_QWORD *)v89[1];
  v92 = v89;
  if ( (unsigned __int64)v91 < v89[3] )
  {
    *v91 = "StNarrowPhase";
    v93 = __rdtsc();
    v90 = (unsigned __int64)HIDWORD(v93) << 32;
    v94 = v91 + 2;
    *((_DWORD *)v94 - 2) = v93;
    v92[1] = v94;
  }
  v95 = ((__int64 (__fastcall *)(hkpShape *, unsigned __int64, _QWORD *))v7->m_shape->vfptr[7].__vecDelDtor)(
          v7->m_shape,
          v90,
          v92);
  if ( v85 != (hkpBvTreeAgent::hkpBvAgentEntryInfo *)p_m_key )
  {
    v96 = v179;
    do
    {
      v97 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v95 + 40i64))(v95, v85->m_key, v174);
      m_key = v85->m_key;
      v159 = v97;
      ((void (__fastcall *)(hkpCollisionAgent *, hkpCdBody *, __int64 *, hkpProcessCollisionInput *, __int64))v85->m_collisionAgent->vfptr[3].__vecDelDtor)(
        v85->m_collisionAgent,
        v8,
        &v159,
        input,
        v96);
      ++v85;
    }
    while ( v85 != (hkpBvTreeAgent::hkpBvAgentEntryInfo *)p_m_key );
  }
  v98 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v99 = (_QWORD *)v98[1];
  v100 = v98;
  if ( (unsigned __int64)v99 < v98[3] )
  {
    *v99 = "lt";
    v101 = __rdtsc();
    v102 = v99 + 2;
    *((_DWORD *)v102 - 2) = v101;
    v100[1] = v102;
  }
}

// File Line: 407
// RVA: 0xD1B280
void __fastcall hkpBvTreeAgent::linearCast(
        hkpBvTreeAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  hkpBvTreeAgent::staticLinearCast(bodyA, bodyB, input, collector, startCollector);
}

// File Line: 412
// RVA: 0xD1B2C0
void __fastcall hkpBvTreeAgent::staticLinearCast(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  _QWORD *Value; // rax
  unsigned __int64 v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  hkpShape *m_shape; // r12
  _QWORD *v13; // rcx
  unsigned __int64 v14; // r8
  unsigned __int64 v15; // rax
  unsigned int *v16; // rbx
  __int64 m_storage; // r13
  unsigned int *v18; // rbp
  hkpShapeContainer *v19; // r12
  hkpCdPointCollector *v20; // rdi
  __int64 v21; // rax
  hkpCollisionDispatcher *v22; // r10
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  _QWORD *v26; // rcx
  __int64 v27; // [rsp+40h] [rbp-488h] BYREF
  unsigned int v28; // [rsp+48h] [rbp-480h]
  const void *m_motion; // [rsp+50h] [rbp-478h]
  hkpCdBody *v30; // [rsp+58h] [rbp-470h]
  hkAabb aabbOut; // [rsp+60h] [rbp-468h] BYREF
  char *v32; // [rsp+80h] [rbp-448h] BYREF
  int v33; // [rsp+88h] [rbp-440h]
  int v34; // [rsp+8Ch] [rbp-43Ch]
  char v35; // [rsp+90h] [rbp-438h] BYREF
  char v36[512]; // [rsp+290h] [rbp-238h] BYREF
  char v37; // [rsp+4D0h] [rbp+8h] BYREF
  hkpCdPointCollector *v38; // [rsp+4E8h] [rbp+20h]

  v38 = collector;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = Value[1];
  v10 = Value;
  if ( v9 < Value[3] )
  {
    *(_QWORD *)v9 = "LtBvTree";
    *(_QWORD *)(v9 + 16) = "StQueryTree";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  hkpBvTreeAgent::calcAabbLinearCast(bodyA, bodyB, input, &aabbOut);
  m_shape = bodyB->m_shape;
  v32 = &v35;
  v33 = 0;
  v34 = -2147483520;
  ((void (__fastcall *)(hkpShape *, hkAabb *, char **))m_shape->vfptr[8].__first_virtual_table_function__)(
    m_shape,
    &aabbOut,
    &v32);
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = v13[1];
  if ( v14 < v13[3] )
  {
    *(_QWORD *)v14 = "StNarrowPhase";
    v15 = __rdtsc();
    *(_DWORD *)(v14 + 8) = v15;
    v13[1] = v14 + 16;
  }
  v16 = (unsigned int *)v32;
  m_storage = (unsigned __int8)bodyA->m_shape->m_type.m_storage;
  v30 = bodyB;
  v18 = (unsigned int *)&v32[4 * v33];
  m_motion = bodyB->m_motion;
  v19 = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))m_shape->vfptr[7].__vecDelDtor)(m_shape);
  if ( v16 != v18 )
  {
    v20 = startCollector;
    do
    {
      if ( input->m_filter.m_storage->vfptr->isCollisionEnabled(
             &input->m_filter.m_storage->hkpShapeCollectionFilter,
             &v37,
             input,
             bodyA,
             bodyB,
             v19,
             *v16)->m_bool )
      {
        v21 = (__int64)v19->vfptr->getChildShape(v19, *v16, (char (*)[512])v36);
        v22 = input->m_dispatcher.m_storage;
        v28 = *v16;
        v27 = v21;
        v22->m_agent2Func[(unsigned __int8)v22->m_agent2Types[m_storage][*(unsigned __int8 *)(v21 + 16)]].m_linearCastFunc(
          bodyA,
          (hkpCdBody *)&v27,
          input,
          v38,
          v20);
      }
      ++v16;
    }
    while ( v16 != v18 );
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
  v33 = 0;
  if ( v34 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v32, 4 * v34);
}

// File Line: 466
// RVA: 0xD1ACF0
void __fastcall hkpBvTreeAgent::getPenetrations(
        hkpBvTreeAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpBvTreeAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}

// File Line: 471
// RVA: 0xD1AD10
void __fastcall hkpBvTreeAgent::staticGetPenetrations(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  _QWORD *Value; // rax
  unsigned __int64 v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  hkpShape *m_shape; // r12
  _QWORD *v13; // rcx
  unsigned __int64 v14; // r8
  unsigned __int64 v15; // rax
  unsigned int *v16; // rbx
  __int64 m_storage; // rdi
  unsigned int *v18; // rbp
  hkpShapeContainer *i; // r12
  __int64 v20; // rax
  hkpCollisionDispatcher *v21; // r10
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  __int64 v26; // [rsp+40h] [rbp-478h] BYREF
  unsigned int v27; // [rsp+48h] [rbp-470h]
  const void *m_motion; // [rsp+50h] [rbp-468h]
  hkpCdBody *v29; // [rsp+58h] [rbp-460h]
  hkAabb aabbOut; // [rsp+60h] [rbp-458h] BYREF
  char *v31; // [rsp+80h] [rbp-438h] BYREF
  int v32; // [rsp+88h] [rbp-430h]
  int v33; // [rsp+8Ch] [rbp-42Ch]
  char v34; // [rsp+90h] [rbp-428h] BYREF
  char v35[512]; // [rsp+290h] [rbp-228h] BYREF
  char v36; // [rsp+4C0h] [rbp+8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = Value[1];
  v10 = Value;
  if ( v9 < Value[3] )
  {
    *(_QWORD *)v9 = "LtBvTree";
    *(_QWORD *)(v9 + 16) = "StQueryTree";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  hkpBvTreeAgent::staticCalcAabb(bodyA, bodyB, input, &aabbOut);
  m_shape = bodyB->m_shape;
  v31 = &v34;
  v32 = 0;
  v33 = -2147483520;
  ((void (__fastcall *)(hkpShape *, hkAabb *, char **))m_shape->vfptr[8].__first_virtual_table_function__)(
    m_shape,
    &aabbOut,
    &v31);
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = v13[1];
  if ( v14 < v13[3] )
  {
    *(_QWORD *)v14 = "StNarrowPhase";
    v15 = __rdtsc();
    *(_DWORD *)(v14 + 8) = v15;
    v13[1] = v14 + 16;
  }
  v16 = (unsigned int *)v31;
  m_storage = (unsigned __int8)bodyA->m_shape->m_type.m_storage;
  v29 = bodyB;
  v18 = (unsigned int *)&v31[4 * v32];
  m_motion = bodyB->m_motion;
  for ( i = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))m_shape->vfptr[7].__vecDelDtor)(m_shape);
        v16 != v18;
        ++v16 )
  {
    if ( input->m_filter.m_storage->vfptr->isCollisionEnabled(
           &input->m_filter.m_storage->hkpShapeCollectionFilter,
           &v36,
           input,
           bodyA,
           bodyB,
           i,
           *v16)->m_bool )
    {
      v20 = (__int64)i->vfptr->getChildShape(i, *v16, (char (*)[512])v35);
      v21 = input->m_dispatcher.m_storage;
      v27 = *v16;
      v26 = v20;
      v21->m_agent2Func[(unsigned __int8)v21->m_agent2Types[m_storage][*(unsigned __int8 *)(v20 + 16)]].m_getPenetrationsFunc(
        bodyA,
        (hkpCdBody *)&v26,
        input,
        collector);
      if ( collector->m_earlyOut.m_bool )
        break;
    }
  }
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "lt";
    v24 = __rdtsc();
    v25 = v23 + 2;
    *((_DWORD *)v25 - 2) = v24;
    v22[1] = v25;
  }
  v32 = 0;
  if ( v33 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v31, 4 * v33);
}

// File Line: 534
// RVA: 0xD1AF90
void __fastcall hkpBvTreeAgent::getClosestPoints(
        hkpBvTreeAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  hkpBvTreeAgent::staticGetClosestPoints(bodyA, bodyB, input, collector);
}

// File Line: 540
// RVA: 0xD1AFB0
void __fastcall hkpBvTreeAgent::staticGetClosestPoints(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // rax
  unsigned __int64 v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  hkLifoAllocator *v11; // rax
  char *m_cur; // rbx
  char *v13; // rcx
  hkpShape *m_shape; // rdi
  int v15; // eax
  int v16; // ebp
  hkLifoAllocator *v17; // rax
  _QWORD *v18; // rax
  unsigned __int64 v19; // r8
  _QWORD *v20; // rcx
  unsigned __int64 v21; // rax
  __int64 v22; // rax
  const void *m_motion; // rcx
  hkpShapeContainer *v24; // r13
  __int64 v25; // rdi
  __int64 v26; // r12
  hkpCollisionFilter *m_storage; // rcx
  unsigned int v28; // ebp
  __int64 v29; // rax
  hkpCollisionDispatcher *v30; // r10
  _QWORD *v31; // r8
  unsigned __int64 v32; // rcx
  unsigned __int64 v33; // rax
  __int64 i; // [rsp+40h] [rbp-288h]
  __int64 v35; // [rsp+48h] [rbp-280h] BYREF
  unsigned int v36; // [rsp+50h] [rbp-278h]
  const void *v37; // [rsp+58h] [rbp-270h]
  hkpCdBody *v38; // [rsp+60h] [rbp-268h]
  hkAabb aabbOut; // [rsp+70h] [rbp-258h] BYREF
  char v40[512]; // [rsp+90h] [rbp-238h] BYREF
  char v41; // [rsp+2D8h] [rbp+10h] BYREF
  hkpCdPointCollector *v42; // [rsp+2E8h] [rbp+20h]

  v42 = collector;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = Value[1];
  v9 = Value;
  if ( v8 < Value[3] )
  {
    *(_QWORD *)v8 = "LtBvTree";
    *(_QWORD *)(v8 + 16) = "StQueryTree";
    v10 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v10;
    v9[1] = v8 + 24;
  }
  hkpBvTreeAgent::staticCalcAabb(bodyA, bodyB, input, &aabbOut);
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)v11->m_cur;
  v13 = m_cur + 0x2000;
  if ( v11->m_slabSize < 0x2000 || v13 > v11->m_end )
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(v11, 0x2000);
  else
    v11->m_cur = v13;
  m_shape = bodyB->m_shape;
  v15 = ((__int64 (__fastcall *)(hkpShape *, hkAabb *, char *, __int64))bodyB->m_shape->vfptr[9].__first_virtual_table_function__)(
          bodyB->m_shape,
          &aabbOut,
          m_cur,
          2048i64);
  v16 = v15;
  if ( v15 )
  {
    if ( v15 >= 2048 )
      v16 = 2048;
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = v18[1];
    v20 = v18;
    if ( v19 < v18[3] )
    {
      *(_QWORD *)v19 = "StNarrowPhase";
      v21 = __rdtsc();
      *(_DWORD *)(v19 + 8) = v21;
      v20[1] = v19 + 16;
    }
    v22 = ((__int64 (__fastcall *)(hkpShape *))m_shape->vfptr[7].__vecDelDtor)(m_shape);
    m_motion = bodyB->m_motion;
    v38 = bodyB;
    v37 = m_motion;
    v24 = (hkpShapeContainer *)v22;
    v25 = 0i64;
    v26 = v16;
    for ( i = (unsigned __int8)bodyA->m_shape->m_type.m_storage; v25 < v26; ++v25 )
    {
      m_storage = input->m_filter.m_storage;
      v28 = *(_DWORD *)&m_cur[4 * v25];
      if ( m_storage
        && m_storage->hkpShapeCollectionFilter::vfptr->isCollisionEnabled(
             &m_storage->hkpShapeCollectionFilter,
             (hkBool *)&v41,
             input,
             bodyA,
             bodyB,
             v24,
             *(_DWORD *)&m_cur[4 * v25])->m_bool )
      {
        v29 = (__int64)v24->vfptr->getChildShape(v24, v28, (char (*)[512])v40);
        v30 = input->m_dispatcher.m_storage;
        v35 = v29;
        v36 = v28;
        v30->m_agent2Func[(unsigned __int8)v30->m_agent2Types[i][*(unsigned __int8 *)(v29 + 16)]].m_getClosestPointFunc(
          bodyA,
          (hkpCdBody *)&v35,
          input,
          v42);
      }
    }
    v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    if ( v17->m_slabSize >= 0x2000 && m_cur + 0x2000 == v17->m_cur && v17->m_firstNonLifoEnd != m_cur )
    {
      v17->m_cur = m_cur;
      goto LABEL_26;
    }
  }
  else
  {
    v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    if ( v17->m_slabSize >= 0x2000 && m_cur + 0x2000 == v17->m_cur && v17->m_firstNonLifoEnd != m_cur )
    {
      v17->m_cur = m_cur;
      goto LABEL_26;
    }
  }
  hkLifoAllocator::slowBlockFree(v17, m_cur, 0x2000);
LABEL_26:
  v31 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v32 = v31[1];
  if ( v32 < v31[3] )
  {
    *(_QWORD *)v32 = "lt";
    v33 = __rdtsc();
    *(_DWORD *)(v32 + 8) = v33;
    v31[1] = v32 + 16;
  }
}

// File Line: 609
// RVA: 0xD1C780
void __fastcall hkpBvTreeAgent::calcAabbLinearCast(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkAabb *aabbOut)
{
  __int64 v8; // r8
  __m128 *m_motion; // rax
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm0
  hkVector4f v14; // xmm1
  __m128 v15; // xmm3
  hkTransformf v16; // [rsp+20h] [rbp-48h] BYREF

  hkTransformf::setMulInverseMul(&v16, (hkTransformf *)bodyB->m_motion, (hkTransformf *)bodyA->m_motion);
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, hkAabb *))bodyA->m_shape->vfptr[2].__vecDelDtor)(
    bodyA->m_shape,
    &v16,
    v8,
    aabbOut);
  m_motion = (__m128 *)bodyB->m_motion;
  v10 = m_motion[2];
  v11 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
  v12 = _mm_movelh_ps(v11, v10);
  v13 = _mm_movehl_ps(v12, v11);
  v14.m_quad = (__m128)input->m_path;
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v14.m_quad, v14.m_quad, 85), _mm_shuffle_ps(v13, v10, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v14.m_quad, v14.m_quad, 0), v12)),
          _mm_mul_ps(
            _mm_shuffle_ps(v14.m_quad, v14.m_quad, 170),
            _mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v10, 228)));
  aabbOut->m_min.m_quad = _mm_add_ps(_mm_min_ps((__m128)0i64, v15), aabbOut->m_min.m_quad);
  aabbOut->m_max.m_quad = _mm_add_ps(_mm_max_ps((__m128)0i64, v15), aabbOut->m_max.m_quad);
}

// File Line: 632
// RVA: 0xD1C860
void __fastcall hkpBvTreeAgent::staticCalcAabb(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkAabb *aabbOut)
{
  __int64 v6; // r8
  hkTransformf v7; // [rsp+20h] [rbp-48h] BYREF

  hkTransformf::setMulInverseMul(&v7, (hkTransformf *)bodyB->m_motion, (hkTransformf *)bodyA->m_motion);
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, hkAabb *))bodyA->m_shape->vfptr[2].__vecDelDtor)(
    bodyA->m_shape,
    &v7,
    v6,
    aabbOut);
}

// File Line: 646
// RVA: 0xD1C8C0
void __fastcall hkpBvTreeAgent::LinearCastAabbCastCollector::addHit(
        hkpBvTreeAgent::LinearCastAabbCastCollector *this,
        unsigned int key)
{
  __int64 v4; // rax
  hkpLinearCastCollisionInput *m_input; // r8
  hkpCollisionFilter *m_storage; // rcx
  __int64 v7; // rsi
  __int64 v8; // rax
  hkpLinearCastCollisionInput *v9; // r8
  __int64 m_motion; // rcx
  hkpCdBody *m_castBody; // rcx
  __int64 v12; // [rsp+40h] [rbp-228h] BYREF
  unsigned int v13; // [rsp+48h] [rbp-220h]
  __int64 v14; // [rsp+50h] [rbp-218h]
  hkpCdBody *m_bvTreeBody; // [rsp+58h] [rbp-210h]
  char v16[512]; // [rsp+60h] [rbp-208h] BYREF
  float m_earlyOutDistance; // [rsp+270h] [rbp+8h] BYREF

  v4 = ((__int64 (__fastcall *)(hkpShape *))this->m_bvTreeBody->m_shape->vfptr[7].__vecDelDtor)(this->m_bvTreeBody->m_shape);
  m_input = this->m_input;
  m_storage = m_input->m_filter.m_storage;
  v7 = v4;
  if ( m_storage )
  {
    if ( m_storage->hkpShapeCollectionFilter::vfptr->isCollisionEnabled(
           &m_storage->hkpShapeCollectionFilter,
           (hkBool *)&m_earlyOutDistance,
           m_input,
           this->m_castBody,
           this->m_bvTreeBody,
           (hkpShapeContainer *)v4,
           key)->m_bool )
    {
      v8 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v7 + 40i64))(v7, key, v16);
      v9 = this->m_input;
      m_bvTreeBody = this->m_bvTreeBody;
      m_motion = (__int64)m_bvTreeBody->m_motion;
      v12 = v8;
      v14 = m_motion;
      m_castBody = this->m_castBody;
      v13 = key;
      v9->m_dispatcher.m_storage->m_agent2Func[(unsigned __int8)v9->m_dispatcher.m_storage->m_agent2Types[(unsigned __int8)m_castBody->m_shape->m_type.m_storage][*(unsigned __int8 *)(v8 + 16)]].m_linearCastFunc(
        m_castBody,
        (hkpCdBody *)&v12,
        v9,
        this->m_castCollector,
        this->m_startCollector);
      m_earlyOutDistance = this->m_castCollector->m_earlyOutDistance;
      this->m_earlyOutFraction.m_real = _mm_min_ps(
                                          this->m_earlyOutFraction.m_real,
                                          _mm_shuffle_ps(
                                            (__m128)LODWORD(m_earlyOutDistance),
                                            (__m128)LODWORD(m_earlyOutDistance),
                                            0));
    }
  }
}


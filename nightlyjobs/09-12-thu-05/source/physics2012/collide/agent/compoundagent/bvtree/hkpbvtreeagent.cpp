// File Line: 57
// RVA: 0xD1C6B0
void __fastcall hkpBvTreeAgent::hkpBvTreeAgent(hkpBvTreeAgent *this, hkpContactMgr *mgr)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_contactMgr = mgr;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBvTreeAgent::`vftable';
  this->m_collisionPartners.m_capacityAndFlags = 2147483648;
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
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-30h]

  f.m_createFunc = hkpBvTreeAgent::createBvTreeShapeAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticGetPenetrations;
  v1 = dispatcher;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpBvTreeAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, BV_TREE, ALL_SHAPE_TYPES);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE, ALL_SHAPE_TYPES);
  f.m_createFunc = hkpBvTreeAgent::createShapeBvAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpBvTreeAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, ALL_SHAPE_TYPES, BV_TREE);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, ALL_SHAPE_TYPES, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE);
  f.m_createFunc = hkpBvTreeAgent::createBvBvAgent;
  f.m_getPenetrationsFunc = hkpBvTreeAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpBvTreeAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpBvTreeAgent::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, BV_TREE, BV_TREE);
  hkpCollisionDispatcher::registerCollisionAgent(
    v1,
    &f,
    TRI_SAMPLED_HEIGHT_FIELD_BV_TREE,
    TRI_SAMPLED_HEIGHT_FIELD_BV_TREE);
}

// File Line: 116
// RVA: 0xD1CA30
hkpBvTreeAgent *__fastcall hkpBvTreeAgent::createBvTreeShapeAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // rdi
  _QWORD **v5; // rax
  hkpBvTreeAgent *result; // rax
  hkpCollisionAgent *v7; // rbx

  v4 = mgr;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpBvTreeAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 80i64);
  v7 = (hkpCollisionAgent *)&result->vfptr;
  if ( result )
  {
    hkpBvTreeAgent::hkpBvTreeAgent(result, v4);
    v7->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpBvTreeAgent>::`vftable';
    result = (hkpBvTreeAgent *)v7;
  }
  return result;
}

// File Line: 124
// RVA: 0xD1C9E0
void __fastcall hkpBvTreeAgent::createShapeBvAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // rbx
  _QWORD **v5; // rax
  hkpBvTreeAgent *v6; // rax

  v4 = mgr;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkpBvTreeAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 80i64);
  if ( v6 )
    hkpBvTreeAgent::hkpBvTreeAgent(v6, v4);
}

// File Line: 133
// RVA: 0xD1CAA0
void __fastcall hkpBvTreeAgent::createBvBvAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // rdi
  _QWORD **v5; // rax
  hkpBvTreeAgent *v6; // rax
  _QWORD **v7; // rax
  hkpBvTreeAgent *v8; // rax
  hkpBvTreeAgent *v9; // rbx

  v4 = mgr;
  if ( COERCE_FLOAT(
         _mm_shuffle_ps(
           (__m128)*((unsigned int *)bodyA->m_motion + 40),
           (__m128)*((unsigned int *)bodyA->m_motion + 40),
           0)) >= COERCE_FLOAT(
                    _mm_shuffle_ps(
                      (__m128)*((unsigned int *)bodyB->m_motion + 40),
                      (__m128)*((unsigned int *)bodyB->m_motion + 40),
                      0)) )
  {
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkpBvTreeAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 80i64);
    v9 = v8;
    if ( v8 )
    {
      hkpBvTreeAgent::hkpBvTreeAgent(v8, v4);
      v9->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpBvTreeAgent>::`vftable';
    }
  }
  else
  {
    v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (hkpBvTreeAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 80i64);
    if ( v6 )
      hkpBvTreeAgent::hkpBvTreeAgent(v6, v4);
  }
}

// File Line: 156
// RVA: 0xD1C330
void __fastcall hkpBvTreeAgent::cleanup(hkpBvTreeAgent *this, hkpConstraintOwner *info)
{
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v2; // rbx
  hkpConstraintOwner *v3; // rsi
  hkpBvTreeAgent *v4; // r14
  signed __int64 v5; // rdi
  hkpCollisionAgent **v6; // rbx

  v2 = this->m_collisionPartners.m_data;
  v3 = info;
  v4 = this;
  v5 = (signed __int64)&v2[this->m_collisionPartners.m_size];
  if ( v2 != (hkpBvTreeAgent::hkpBvAgentEntryInfo *)v5 )
  {
    v6 = &v2->m_collisionAgent;
    do
    {
      if ( *v6 )
        ((void (__fastcall *)(hkpCollisionAgent *, hkpConstraintOwner *))(*v6)->vfptr[3].__first_virtual_table_function__)(
          *v6,
          v3);
      v6 += 2;
    }
    while ( v6 - 1 != (hkpCollisionAgent **)v5 );
  }
  v4->vfptr->__vecDelDtor((hkBaseObject *)&v4->vfptr, 1u);
}

// File Line: 173
// RVA: 0xD1C5B0
void __fastcall hkpBvTreeAgent::invalidateTim(hkpBvTreeAgent *this, hkpCollisionInput *input)
{
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v2; // rbx
  hkpCollisionInput *v3; // rsi
  signed __int64 v4; // rdi
  hkpCollisionAgent **v5; // rbx

  v2 = this->m_collisionPartners.m_data;
  v3 = input;
  v4 = (signed __int64)&v2[this->m_collisionPartners.m_size];
  if ( v2 != (hkpBvTreeAgent::hkpBvAgentEntryInfo *)v4 )
  {
    v5 = &v2->m_collisionAgent;
    do
    {
      if ( *v5 )
        ((void (__fastcall *)(hkpCollisionAgent *, hkpCollisionInput *))(*v5)->vfptr[4].__first_virtual_table_function__)(
          *v5,
          v3);
      v5 += 2;
    }
    while ( v5 - 1 != (hkpCollisionAgent **)v4 );
  }
}

// File Line: 188
// RVA: 0xD1C620
void __usercall hkpBvTreeAgent::warpTime(hkpBvTreeAgent *this@<rcx>, float oldTime@<xmm1>, float newTime@<xmm2>, hkpCollisionInput *input@<r9>, __int64 a5@<rdx>, __int64 a6@<r8>)
{
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v6; // rbx
  hkpCollisionInput *v7; // rsi
  signed __int64 v8; // rdi
  hkpCollisionAgent **v9; // rbx

  v6 = this->m_collisionPartners.m_data;
  v7 = input;
  v8 = (signed __int64)&v6[this->m_collisionPartners.m_size];
  if ( v6 != (hkpBvTreeAgent::hkpBvAgentEntryInfo *)v8 )
  {
    v9 = &v6->m_collisionAgent;
    do
    {
      if ( *v9 )
        ((void (__fastcall *)(hkpCollisionAgent *, __int64, __int64, hkpCollisionInput *))(*v9)->vfptr[5].__vecDelDtor)(
          *v9,
          a5,
          a6,
          v7);
      v9 += 2;
    }
    while ( v9 - 1 != (hkpCollisionAgent **)v8 );
  }
}

// File Line: 238
// RVA: 0xD1C710
hkpCollisionAgent *__fastcall hkpBvTreeAgent::defaultAgentCreate(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCollisionDispatcher *v4; // r10
  hkpCdBody *v5; // rbx
  __int64 v6; // rcx
  char (*v7)[35]; // r11

  v4 = input->m_dispatcher.m_storage;
  v5 = bodyA;
  v6 = (unsigned __int8)bodyA->m_shape->m_type.m_storage;
  v7 = input->m_dispatcher.m_storage->m_agent2TypesPred;
  if ( !input->m_createPredictiveAgents.m_storage )
    v7 = v4->m_agent2Types;
  return (hkpCollisionAgent *)v4->m_agent2Func[(unsigned __int8)v7[v6][(unsigned __int8)bodyB->m_shape->m_type.m_storage]].m_createFunc(
                                v5,
                                bodyB,
                                input,
                                mgr);
}

// File Line: 308
// RVA: 0xD1C3E0
void __fastcall hkpBvTreeAgent::updateShapeCollectionFilter(hkpBvTreeAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpConstraintOwner *constraintOwner)
{
  hkpBvTreeAgent *v5; // rbx
  hkpCollisionInput *v6; // r14
  hkpCdBody *v7; // r13
  hkpCdBody *v8; // r15
  int v9; // ebp
  __int64 v10; // rdi
  hkpConstraintOwner *v11; // r12
  __int64 v12; // rsi
  __int64 v13; // rax
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v14; // rdx
  hkpCollisionFilter *v15; // rcx
  _BYTE *v16; // rax
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v17; // rdi
  hkpCollisionDispatcher *v18; // r10
  signed __int64 v19; // rdx
  hkpCollisionAgent *v20; // rcx
  hkpCollisionAgent *v21; // rcx
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v22; // rdi
  __int64 v23[2]; // [rsp+30h] [rbp-268h]
  __int64 v24; // [rsp+40h] [rbp-258h]
  unsigned int v25; // [rsp+48h] [rbp-250h]
  const void *v26; // [rsp+50h] [rbp-248h]
  hkpCdBody *v27; // [rsp+58h] [rbp-240h]
  char v28; // [rsp+60h] [rbp-238h]
  char v29; // [rsp+2A0h] [rbp+8h]
  __int64 v30; // [rsp+2B0h] [rbp+18h]

  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = bodyA;
  v9 = 0;
  v10 = ((__int64 (*)(void))bodyB->m_shape->vfptr[7].__vecDelDtor)();
  v30 = v10;
  if ( v5->m_collisionPartners.m_size > 0 )
  {
    v11 = constraintOwner;
    v12 = 0i64;
    do
    {
      v13 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v10 + 40i64))(
              v10,
              v5->m_collisionPartners.m_data[v12].m_key,
              &v28);
      v14 = v5->m_collisionPartners.m_data;
      v26 = v7->m_motion;
      v27 = v7;
      v25 = v14[v12].m_key;
      v15 = v6->m_filter.m_storage;
      v24 = v13;
      LODWORD(v23[0]) = v14[v12].m_key;
      v16 = (_BYTE *)v15->vfptr->isCollisionEnabled(
                       (hkpShapeCollectionFilter *)&v15->vfptr,
                       (hkBool *)&v29,
                       v6,
                       v8,
                       v7,
                       (hkpShapeContainer *)v10,
                       v23[0]);
      v17 = v5->m_collisionPartners.m_data;
      if ( *v16 )
      {
        if ( (hkpNullAgent *)v17[v12].m_collisionAgent == hkpNullAgent::getNullAgent() )
        {
          v18 = v6->m_dispatcher.m_storage;
          v19 = (signed __int64)v6->m_dispatcher.m_storage->m_agent2TypesPred;
          if ( !v6->m_createPredictiveAgents.m_storage )
            v19 = (signed __int64)v18->m_agent2Types;
          v5->m_collisionPartners.m_data[v12].m_collisionAgent = v18->m_agent2Func[*(unsigned __int8 *)(*(unsigned __int8 *)(v24 + 16) + v19 + 35i64 * (unsigned __int8)v8->m_shape->m_type.m_storage)].m_createFunc(
                                                                   v8,
                                                                   (hkpCdBody *)&v24,
                                                                   v6,
                                                                   v5->m_contactMgr);
        }
        else
        {
          v20 = v5->m_collisionPartners.m_data[v12].m_collisionAgent;
          ((void (__fastcall *)(hkpCollisionAgent *, hkpCdBody *, __int64 *, hkpCollisionInput *, hkpConstraintOwner *))v20->vfptr[4].__vecDelDtor)(
            v20,
            v8,
            &v24,
            v6,
            v11);
        }
      }
      else if ( (hkpNullAgent *)v17[v12].m_collisionAgent != hkpNullAgent::getNullAgent() )
      {
        v21 = v5->m_collisionPartners.m_data[v12].m_collisionAgent;
        ((void (__fastcall *)(hkpCollisionAgent *, hkpConstraintOwner *))v21->vfptr[3].__first_virtual_table_function__)(
          v21,
          v11);
        v22 = v5->m_collisionPartners.m_data;
        v22[v12].m_collisionAgent = (hkpCollisionAgent *)hkpNullAgent::getNullAgent();
      }
      v10 = v30;
      ++v9;
      ++v12;
    }
    while ( v9 < v5->m_collisionPartners.m_size );
  }
}

// File Line: 351
// RVA: 0xD1B530
void __fastcall hkpBvTreeAgent::processCollision(hkpBvTreeAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *result)
{
  hkpBvTreeAgent *v5; // r13
  hkpProcessCollisionInput *v6; // rsi
  hkpCdBody *v7; // r14
  hkpCdBody *v8; // r12
  _QWORD *v9; // r9
  unsigned __int64 v10; // r8
  unsigned __int64 v11; // rax
  hkTransformf *v12; // r8
  hkTransformf *v13; // rdx
  __int64 v14; // rax
  __m128 *v15; // rbx
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
  hkpShape *v27; // rcx
  hkBaseObjectVtbl *v28; // rax
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
  char *v55; // r8
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v56; // rdi
  unsigned int *v57; // rdx
  int v58; // er8
  hkArray<hkpBvTreeAgent::hkpBvAgentEntryInfo,hkContainerHeapAllocator> *v59; // r14
  unsigned int *v60; // rbx
  unsigned int *v61; // r15
  signed __int64 v62; // r13
  __int64 v63; // r12
  signed __int64 v64; // rax
  int v65; // er9
  signed __int64 v66; // rdx
  __int64 v67; // rcx
  __int64 v68; // rax
  __int64 v69; // r15
  signed __int64 v70; // rdi
  unsigned int *v71; // r13
  signed __int64 v72; // rcx
  int v73; // edi
  int v74; // eax
  signed __int64 v75; // rbx
  int v76; // er15
  int v77; // eax
  int v78; // er9
  signed __int64 v79; // rbx
  __int64 v80; // rcx
  __int64 v81; // rax
  hkpCollisionFilter *v82; // rcx
  hkpCollisionDispatcher *v83; // r10
  signed __int64 v84; // rdx
  hkpNullAgent *v85; // rax
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v86; // rbx
  __int64 v87; // rax
  signed __int64 v88; // rdi
  unsigned int *v89; // rdi
  _QWORD *v90; // rax
  unsigned __int64 v91; // rdx
  _QWORD *v92; // rcx
  _QWORD *v93; // r8
  unsigned __int64 v94; // rax
  signed __int64 v95; // rcx
  __int64 v96; // r14
  __int64 v97; // r15
  __int64 v98; // rax
  _QWORD *v99; // rax
  _QWORD *v100; // rcx
  _QWORD *v101; // r8
  unsigned __int64 v102; // rax
  signed __int64 v103; // rcx
  int v104; // er15
  __int64 v105; // rax
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v106; // rbx
  __int64 v107; // r13
  unsigned int *v108; // rdi
  signed __int64 v109; // r13
  int v110; // er14
  hkLifoAllocator *v111; // rax
  int v112; // edx
  char *v113; // rcx
  char *v114; // rax
  unsigned int v115; // er14
  int v116; // er14
  int v117; // er9
  unsigned __int64 v118; // r14
  unsigned int v119; // er15
  __int64 v120; // rax
  __int64 v121; // rax
  hkpCollisionFilter *v122; // rcx
  hkpCollisionDispatcher *v123; // r10
  signed __int64 v124; // rdx
  hkpNullAgent *v125; // rax
  hkpCollisionAgent *v126; // rcx
  __int64 v127; // r12
  hkpCollisionAgent **v128; // rbx
  unsigned int *v129; // r13
  hkpNullAgent **v130; // r14
  int v131; // ebx
  __int64 v132; // rax
  hkpCollisionFilter *v133; // rcx
  hkpCollisionDispatcher *v134; // r10
  signed __int64 v135; // rdx
  hkpNullAgent *v136; // rax
  unsigned int v137; // eax
  int v138; // ebx
  int v139; // er14
  int v140; // eax
  int v141; // eax
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v142; // rdx
  __int64 *v143; // rcx
  __int64 v144; // r8
  __int64 v145; // rax
  hkpBvTreeAgent::hkpBvAgentEntryInfo *v146; // rcx
  __int64 v147; // r8
  unsigned __int64 v148; // rdx
  char *v149; // rdi
  int v150; // ebx
  bool v151; // zf
  signed int v152; // ebx
  hkLifoAllocator *v153; // rax
  int v154; // er8
  __int64 v155[2]; // [rsp+30h] [rbp-C8h]
  __m128 array; // [rsp+40h] [rbp-B8h]
  void *p[2]; // [rsp+50h] [rbp-A8h]
  hkpContactMgr *v158; // [rsp+60h] [rbp-98h]
  hkpShapeContainer *v159; // [rsp+68h] [rbp-90h]
  unsigned int *v160; // [rsp+70h] [rbp-88h]
  __int64 v161; // [rsp+78h] [rbp-80h]
  unsigned int v162; // [rsp+80h] [rbp-78h]
  __int64 v163; // [rsp+88h] [rbp-70h]
  hkpCdBody *v164; // [rsp+90h] [rbp-68h]
  hkTransformf v165; // [rsp+98h] [rbp-60h]
  hkpContactMgr *v166; // [rsp+D8h] [rbp-20h]
  __int64 v167; // [rsp+E0h] [rbp-18h]
  int v168; // [rsp+E8h] [rbp-10h]
  const void *v169; // [rsp+F0h] [rbp-8h]
  hkpCdBody *v170; // [rsp+F8h] [rbp+0h]
  char v171; // [rsp+108h] [rbp+10h]
  unsigned int *pArr; // [rsp+308h] [rbp+210h]
  int v173; // [rsp+310h] [rbp+218h]
  int v174; // [rsp+314h] [rbp+21Ch]
  char v175; // [rsp+318h] [rbp+220h]
  char v176; // [rsp+518h] [rbp+420h]
  hkpBvTreeAgent *retaddr; // [rsp+7B8h] [rbp+6C0h]
  hkpBvTreeAgent *v178; // [rsp+7C0h] [rbp+6C8h]
  hkpCdBody *v179; // [rsp+7C8h] [rbp+6D0h]
  hkpCdBody *v180; // [rsp+7D0h] [rbp+6D8h]
  __int64 v181; // [rsp+7D8h] [rbp+6E0h]

  v180 = bodyB;
  v179 = bodyA;
  v178 = this;
  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = v9[1];
  if ( v10 < v9[3] )
  {
    *(_QWORD *)v10 = "LtBvTree";
    *(_QWORD *)(v10 + 16) = "StQueryTree";
    v11 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v11;
    v9[1] = v10 + 24;
  }
  v12 = (hkTransformf *)v8->m_motion;
  v13 = (hkTransformf *)v7->m_motion;
  v14 = *(_QWORD *)(v181 + 8);
  v15 = 0i64;
  pArr = (unsigned int *)&v175;
  v173 = 0;
  v161 = v14;
  v174 = -2147483520;
  hkTransformf::setMulInverseMul(&v165, v13, v12);
  *(float *)&v180 = v6->m_stepInfo.m_deltaTime.m_storage;
  v17 = (__m128 *)v8->m_motion;
  v18 = (__m128 *)v7->m_motion;
  v19 = _mm_shuffle_ps((__m128)(unsigned int)v180, (__m128)(unsigned int)v180, 0);
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
    v15 = &v5->m_cachedAabb.m_min.m_quad;
  v26 = v18[2];
  v27 = v8->m_shape;
  v28 = v8->m_shape->vfptr;
  v29 = (__m128i)_mm_mul_ps(
                   _mm_shuffle_ps(
                     (__m128)LODWORD(v6->m_tolerance.m_storage),
                     (__m128)LODWORD(v6->m_tolerance.m_storage),
                     0),
                   (__m128)xmmword_141A711B0);
  v30 = _mm_unpacklo_ps(*v18, v18[1]);
  v31 = _mm_movelh_ps(v30, v26);
  v32 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(v31, v30), v26, 212), _mm_shuffle_ps(v25, v25, 85)),
            _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v31)),
          _mm_mul_ps(_mm_shuffle_ps(_mm_unpackhi_ps(*v18, v18[1]), v26, 228), _mm_shuffle_ps(v25, v25, 170)));
  if ( v6->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage )
  {
    v33 = _mm_shuffle_ps((__m128)v17[10].m128_u32[0], (__m128)v17[10].m128_u32[0], 0);
    v34 = _mm_shuffle_ps(v18[9], v18[9], 255);
    v35 = _mm_mul_ps(_mm_shuffle_ps((__m128)v18[10].m128_u32[0], (__m128)v18[10].m128_u32[0], 0), _mm_mul_ps(v34, v34));
    ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, __m128 *))v28[2].__vecDelDtor)(v27, &v165, v16, &array);
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
    if ( COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 255)) > 0.0 )
    {
      v47 = _mm_sub_ps(v42, v18[8]);
      v48 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), v47), _mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v45));
      *(float *)&v180 = v6->m_stepInfo.m_deltaTime.m_storage;
      v32 = _mm_add_ps(
              v32,
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(v18[5], v18[5], 255),
                  _mm_shuffle_ps((__m128)(unsigned int)v180, (__m128)(unsigned int)v180, 0)),
                _mm_shuffle_ps(v48, v48, 201)));
    }
    v49 = _mm_add_ps(v44, _mm_max_ps((__m128)0i64, v32));
    v50 = _mm_add_ps(v43, _mm_min_ps((__m128)0i64, v32));
    *(__m128 *)p = v49;
    array = v50;
  }
  else
  {
    ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, __m128 *))v28[2].__vecDelDtor)(v27, &v165, v16, &array);
    v49 = *(__m128 *)p;
    v50 = array;
    v46 = _mm_sub_ps(*(__m128 *)p, array);
  }
  if ( v15 )
  {
    if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v49, v15[1]), _mm_cmpleps(*v15, v50))) & 7) == 7 )
    {
      v173 = 0;
      if ( v174 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          pArr,
          4 * v174);
      goto LABEL_51;
    }
    v51 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_40000001), (__m128)LODWORD(FLOAT_0_40000001), 0), v46);
    *(float *)&v180 = FLOAT_N2_0;
    v52 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_N2_0), (__m128)LODWORD(FLOAT_N2_0), 0);
    v53 = (__m128)_mm_srli_si128(_mm_slli_si128(v29, 4), 4);
    array = _mm_add_ps(
              _mm_sub_ps(v50, v53),
              _mm_max_ps(
                _mm_mul_ps(_mm_max_ps((__m128)0i64, v32), v52),
                _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v51)));
    *v15 = array;
    *(__m128 *)p = _mm_add_ps(_mm_add_ps(v49, v53), _mm_min_ps(_mm_mul_ps(_mm_min_ps((__m128)0i64, v32), v52), v51));
    v15[1] = *(__m128 *)p;
  }
  ((void (__fastcall *)(hkpShape *, __m128 *, unsigned int **))v7->m_shape->vfptr[8].__first_virtual_table_function__)(
    v7->m_shape,
    &array,
    &pArr);
  v54 = ((__int64 (*)(void))v7->m_shape->vfptr[7].__vecDelDtor)();
  v169 = v7->m_motion;
  v170 = v7;
  v166 = (hkpContactMgr *)v54;
  if ( hkpBvTreeAgent::m_useFastUpdate.m_bool )
  {
    v56 = v5->m_collisionPartners.m_data;
    v57 = pArr;
    v58 = v173;
    v59 = &v5->m_collisionPartners;
    v158 = v5->m_contactMgr;
    v60 = pArr;
    v61 = &pArr[v173];
    v62 = (signed __int64)&v56[v5->m_collisionPartners.m_size];
    if ( v56 != (hkpBvTreeAgent::hkpBvAgentEntryInfo *)v62 )
    {
      v63 = v161;
      while ( 1 )
      {
        if ( v60 == v61 || v56->m_key != *v60 )
        {
          v60 = v57;
          if ( v57 == v61 )
          {
LABEL_24:
            ((void (__fastcall *)(hkpCollisionAgent *, __int64))v56->m_collisionAgent->vfptr[3].__first_virtual_table_function__)(
              v56->m_collisionAgent,
              v63);
            --v59->m_size;
            v64 = v56 - v59->m_data;
            v65 = 16 * (v59->m_size - v64);
            v66 = (signed __int64)&v59->m_data[(signed int)v64];
            if ( v65 > 0 )
            {
              v67 = ((unsigned int)(v65 - 1) >> 3) + 1;
              do
              {
                v68 = *(_QWORD *)(v66 + 16);
                v66 += 8i64;
                *(_QWORD *)(v66 - 8) = v68;
                --v67;
              }
              while ( v67 );
            }
            v57 = pArr;
            --v56;
            v62 -= 16i64;
            goto LABEL_28;
          }
          while ( v56->m_key != *v60 )
          {
            ++v60;
            if ( v60 == v61 )
              goto LABEL_24;
          }
        }
        ++v60;
LABEL_28:
        ++v56;
        if ( v56 == (hkpBvTreeAgent::hkpBvAgentEntryInfo *)v62 )
        {
          v58 = v173;
          v8 = (hkpCdBody *)v178;
          break;
        }
      }
    }
    v69 = v59->m_size;
    v159 = (hkpShapeContainer *)v166;
    if ( v58 != (_DWORD)v69 )
    {
      v70 = (signed __int64)v59->m_data;
      v71 = v57;
      v72 = (signed __int64)&v59->m_data[v69];
      v160 = &v57[v58];
      if ( v57 != v160 )
      {
        do
        {
          if ( v70 == v72 || *(_DWORD *)v70 != *v71 )
          {
            v73 = v69 + 1;
            v74 = v59->m_capacityAndFlags & 0x3FFFFFFF;
            v75 = v71 - v57;
            v76 = v69 - v75;
            if ( v73 > v74 )
            {
              if ( v74 >= v73 )
              {
                LODWORD(v180) = 0;
              }
              else
              {
                v77 = 2 * v74;
                v78 = v73;
                if ( v73 < v77 )
                  v78 = v77;
                hkArrayUtil::_reserve(
                  (hkResult *)&v180,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  v59,
                  v78,
                  16);
              }
            }
            v79 = 16i64 * (signed int)v75;
            hkMemUtil::memMove((char *)&v59->m_data[1] + v79, (char *)v59->m_data + v79, 16 * v76);
            v80 = (__int64)v166;
            v59->m_size = v73;
            v70 = (signed __int64)v59->m_data + v79;
            LODWORD(v79) = *v71;
            v81 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v80 + 40i64))(v80, *v71, &v171);
            v82 = v6->m_filter.m_storage;
            v168 = v79;
            v167 = v81;
            LODWORD(v155[0]) = *v71;
            if ( *(_BYTE *)v82->vfptr->isCollisionEnabled(
                             (hkpShapeCollectionFilter *)&v82->vfptr,
                             (hkBool *)&v178,
                             (hkpCollisionInput *)&v6->m_dispatcher,
                             v8,
                             v179,
                             v159,
                             v155[0]) )
            {
              v83 = v6->m_dispatcher.m_storage;
              v84 = (signed __int64)v6->m_dispatcher.m_storage->m_agent2TypesPred;
              if ( !v6->m_createPredictiveAgents.m_storage )
                v84 = (signed __int64)v83->m_agent2Types;
              v85 = (hkpNullAgent *)v83->m_agent2Func[*(unsigned __int8 *)(*(unsigned __int8 *)(v167 + 16)
                                                                         + v84
                                                                         + 35i64
                                                                         * (unsigned __int8)v8->m_shape->m_type.m_storage)].m_createFunc(
                                      v8,
                                      (hkpCdBody *)&v167,
                                      (hkpCollisionInput *)&v6->m_dispatcher,
                                      v158);
            }
            else
            {
              v85 = hkpNullAgent::getNullAgent();
            }
            *(_QWORD *)(v70 + 8) = v85;
            *(_DWORD *)v70 = *v71;
            LODWORD(v69) = v59->m_size;
            v57 = pArr;
            v72 = (signed __int64)&v59->m_data[v59->m_size];
          }
          ++v71;
          v70 += 16i64;
        }
        while ( v71 != v160 );
      }
    }
    v5 = retaddr;
  }
  else
  {
    v104 = v173;
    if ( v173 > 1 )
    {
      hkAlgorithm::quickSortRecursive<unsigned int,hkAlgorithm::less<unsigned int>>(pArr, 0, v173 - 1, 0);
      v104 = v173;
    }
    v105 = (__int64)v5->m_contactMgr;
    v106 = v5->m_collisionPartners.m_data;
    v107 = v5->m_collisionPartners.m_size;
    v108 = pArr;
    v159 = (hkpShapeContainer *)v105;
    v109 = (signed __int64)&v106[v107];
    v110 = v104;
    LODWORD(p[1]) = v104;
    v160 = &pArr[v104];
    array.m128_u64[0] = 0i64;
    array.m128_u64[1] = 0x8000000000000000i64;
    if ( v104 )
    {
      v111 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v55 = (char *)v111->m_cur;
      v112 = (16 * v104 + 127) & 0xFFFFFF80;
      v113 = &v55[v112];
      if ( v112 > v111->m_slabSize || v113 > v111->m_end )
      {
        v114 = (char *)hkLifoAllocator::allocateFromNewSlab(v111, v112);
        v104 = v173;
        v55 = v114;
        array.m128_u64[0] = (unsigned __int64)v114;
      }
      else
      {
        v111->m_cur = v113;
        v104 = v173;
        array.m128_u64[0] = (unsigned __int64)v55;
      }
    }
    else
    {
      array.m128_u64[0] = 0i64;
    }
    v115 = v110 | 0x80000000;
    array.m128_i32[3] = v115;
    v116 = v115 & 0x3FFFFFFF;
    p[0] = (void *)array.m128_u64[0];
    if ( v116 < v104 )
    {
      v117 = v104;
      if ( v104 < 2 * v116 )
        v117 = 2 * v116;
      hkArrayUtil::_reserve(
        (hkResult *)&v180,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &array,
        v117,
        16);
    }
    v118 = array.m128_u64[0];
    array.m128_i32[2] = v104;
    v158 = v166;
    if ( v106 != (hkpBvTreeAgent::hkpBvAgentEntryInfo *)v109 )
    {
      while ( v108 != v160 )
      {
        v119 = *v108;
        if ( *v108 == v106->m_key )
        {
          v120 = *(_QWORD *)&v106->m_key;
          v118 += 16i64;
          ++v106;
          *(_QWORD *)(v118 - 16) = v120;
          ++v108;
          *(_QWORD *)(v118 - 8) = v106[-1].m_collisionAgent;
        }
        else if ( v119 >= v106->m_key )
        {
          v126 = v106->m_collisionAgent;
          if ( v126 )
            ((void (__fastcall *)(hkpCollisionAgent *, __int64, char *))v126->vfptr[3].__first_virtual_table_function__)(
              v126,
              v161,
              v55);
          ++v106;
        }
        else
        {
          v121 = ((__int64 (__fastcall *)(hkpContactMgr *, _QWORD, char *))v166->vfptr[2].__first_virtual_table_function__)(
                   v166,
                   v119,
                   &v171);
          v122 = v6->m_filter.m_storage;
          v168 = v119;
          v167 = v121;
          LODWORD(v155[0]) = *v108;
          if ( *(_BYTE *)v122->vfptr->isCollisionEnabled(
                           (hkpShapeCollectionFilter *)&v122->vfptr,
                           (hkBool *)&v180,
                           (hkpCollisionInput *)&v6->m_dispatcher,
                           v8,
                           v179,
                           (hkpShapeContainer *)v158,
                           v155[0]) )
          {
            v123 = v6->m_dispatcher.m_storage;
            v124 = (signed __int64)v6->m_dispatcher.m_storage->m_agent2TypesPred;
            if ( !v6->m_createPredictiveAgents.m_storage )
              v124 = (signed __int64)v123->m_agent2Types;
            v125 = (hkpNullAgent *)v123->m_agent2Func[*(unsigned __int8 *)(*(unsigned __int8 *)(v167 + 16)
                                                                         + v124
                                                                         + 35i64
                                                                         * (unsigned __int8)v8->m_shape->m_type.m_storage)].m_createFunc(
                                     v8,
                                     (hkpCdBody *)&v167,
                                     (hkpCollisionInput *)&v6->m_dispatcher,
                                     (hkpContactMgr *)v159);
          }
          else
          {
            v125 = hkpNullAgent::getNullAgent();
          }
          *(_QWORD *)(v118 + 8) = v125;
          v118 += 16i64;
          *(_DWORD *)(v118 - 16) = *v108;
          ++v108;
        }
        if ( v106 == (hkpBvTreeAgent::hkpBvAgentEntryInfo *)v109 )
          goto LABEL_93;
      }
      if ( v106 != (hkpBvTreeAgent::hkpBvAgentEntryInfo *)v109 )
      {
        v127 = v161;
        v128 = &v106->m_collisionAgent;
        do
        {
          if ( *v128 )
            ((void (__fastcall *)(hkpCollisionAgent *, __int64, char *))(*v128)->vfptr[3].__first_virtual_table_function__)(
              *v128,
              v127,
              v55);
          v128 += 2;
        }
        while ( v128 - 1 != (hkpCollisionAgent **)v109 );
        v8 = (hkpCdBody *)v178;
      }
LABEL_93:
      v104 = array.m128_i32[2];
    }
    v129 = v160;
    if ( v108 != v160 )
    {
      v130 = (hkpNullAgent **)(v118 + 8);
      do
      {
        v131 = *v108;
        v132 = ((__int64 (__fastcall *)(hkpContactMgr *, _QWORD, char *))v166->vfptr[2].__first_virtual_table_function__)(
                 v166,
                 *v108,
                 &v171);
        v133 = v6->m_filter.m_storage;
        v168 = v131;
        v167 = v132;
        LODWORD(v155[0]) = *v108;
        if ( *(_BYTE *)v133->vfptr->isCollisionEnabled(
                         (hkpShapeCollectionFilter *)&v133->vfptr,
                         (hkBool *)&v178,
                         (hkpCollisionInput *)&v6->m_dispatcher,
                         v8,
                         v179,
                         (hkpShapeContainer *)v158,
                         v155[0]) )
        {
          v134 = v6->m_dispatcher.m_storage;
          v135 = (signed __int64)v6->m_dispatcher.m_storage->m_agent2TypesPred;
          if ( !v6->m_createPredictiveAgents.m_storage )
            v135 = (signed __int64)v134->m_agent2Types;
          v136 = (hkpNullAgent *)v134->m_agent2Func[*(unsigned __int8 *)(*(unsigned __int8 *)(v167 + 16)
                                                                       + v135
                                                                       + 35i64
                                                                       * (unsigned __int8)v8->m_shape->m_type.m_storage)].m_createFunc(
                                   v8,
                                   (hkpCdBody *)&v167,
                                   (hkpCollisionInput *)&v6->m_dispatcher,
                                   (hkpContactMgr *)v159);
        }
        else
        {
          v136 = hkpNullAgent::getNullAgent();
        }
        *v130 = v136;
        v137 = *v108;
        ++v108;
        *((_DWORD *)v130 - 2) = v137;
        v130 += 2;
      }
      while ( v108 != v129 );
      v104 = array.m128_i32[2];
    }
    v5 = retaddr;
    v138 = v104;
    v139 = v104;
    if ( v104 > retaddr->m_collisionPartners.m_size )
      v138 = retaddr->m_collisionPartners.m_size;
    v140 = retaddr->m_collisionPartners.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v140 < v104 )
    {
      v141 = 2 * v140;
      if ( v104 < v141 )
        v104 = v141;
      hkArrayUtil::_reserve(
        (hkResult *)&retaddr,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &retaddr->m_collisionPartners,
        v104,
        16);
      v104 = array.m128_i32[2];
    }
    v142 = retaddr->m_collisionPartners.m_data;
    if ( v138 > 0 )
    {
      v143 = (__int64 *)array.m128_u64[0];
      v144 = v138;
      do
      {
        v145 = *v143;
        ++v142;
        v143 += 2;
        *(_QWORD *)&v142[-1].m_key = v145;
        v142[-1].m_collisionAgent = (hkpCollisionAgent *)*(v143 - 1);
        --v144;
      }
      while ( v144 );
      v104 = array.m128_i32[2];
    }
    v146 = &retaddr->m_collisionPartners.m_data[v138];
    v147 = v139 - v138;
    if ( v139 - v138 > 0 )
    {
      v148 = array.m128_u64[0] - (unsigned __int64)retaddr->m_collisionPartners.m_data;
      do
      {
        if ( v146 )
        {
          *(_QWORD *)&v146->m_key = *(_QWORD *)((char *)&v146->m_key + v148);
          v146->m_collisionAgent = *(hkpCollisionAgent **)((char *)&v146->m_collisionAgent + v148);
        }
        ++v146;
        --v147;
      }
      while ( v147 );
      v104 = array.m128_i32[2];
    }
    v149 = (char *)p[0];
    v150 = (int)p[1];
    v151 = p[0] == (void *)array.m128_u64[0];
    retaddr->m_collisionPartners.m_size = v139;
    if ( v151 )
      v104 = 0;
    array.m128_i32[2] = v104;
    v152 = (16 * v150 + 127) & 0xFFFFFF80;
    v153 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v154 = (v152 + 15) & 0xFFFFFFF0;
    if ( v152 > v153->m_slabSize || &v149[v154] != v153->m_cur || v153->m_firstNonLifoEnd == v149 )
      hkLifoAllocator::slowBlockFree(v153, v149, v154);
    else
      v153->m_cur = v149;
    array.m128_i32[2] = 0;
    if ( array.m128_i32[3] >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        (void *)array.m128_u64[0],
        16 * array.m128_i32[3]);
    v57 = pArr;
  }
  v173 = 0;
  if ( v174 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v57,
      4 * v174);
  v7 = v179;
LABEL_51:
  v86 = v5->m_collisionPartners.m_data;
  v87 = (__int64)v7->m_motion;
  v88 = v5->m_collisionPartners.m_size;
  v164 = v7;
  v89 = &v86[v88].m_key;
  v163 = v87;
  v90 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v92 = (_QWORD *)v90[1];
  v93 = v90;
  if ( (unsigned __int64)v92 < v90[3] )
  {
    *v92 = "StNarrowPhase";
    v94 = __rdtsc();
    v91 = (unsigned __int64)HIDWORD(v94) << 32;
    v95 = (signed __int64)(v92 + 2);
    *(_DWORD *)(v95 - 8) = v94;
    v93[1] = v95;
  }
  v96 = ((__int64 (__fastcall *)(hkpShape *, unsigned __int64, _QWORD *))v7->m_shape->vfptr[7].__vecDelDtor)(
          v7->m_shape,
          v91,
          v93);
  if ( v86 != (hkpBvTreeAgent::hkpBvAgentEntryInfo *)v89 )
  {
    v97 = v181;
    do
    {
      v98 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v96 + 40i64))(v96, v86->m_key, &v176);
      v162 = v86->m_key;
      v161 = v98;
      ((void (__fastcall *)(hkpCollisionAgent *, hkpCdBody *, __int64 *, hkpProcessCollisionInput *, __int64))v86->m_collisionAgent->vfptr[3].__vecDelDtor)(
        v86->m_collisionAgent,
        v8,
        &v161,
        v6,
        v97);
      ++v86;
    }
    while ( v86 != (hkpBvTreeAgent::hkpBvAgentEntryInfo *)v89 );
  }
  v99 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v100 = (_QWORD *)v99[1];
  v101 = v99;
  if ( (unsigned __int64)v100 < v99[3] )
  {
    *v100 = "lt";
    v102 = __rdtsc();
    v103 = (signed __int64)(v100 + 2);
    *(_DWORD *)(v103 - 8) = v102;
    v101[1] = v103;
  }
}

// File Line: 407
// RVA: 0xD1B280
void __fastcall hkpBvTreeAgent::linearCast(hkpBvTreeAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpBvTreeAgent::staticLinearCast(bodyA, bodyB, input, collector, startCollector);
}

// File Line: 412
// RVA: 0xD1B2C0
void __fastcall hkpBvTreeAgent::staticLinearCast(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpCdBody *v5; // r14
  hkpLinearCastCollisionInput *v6; // rsi
  hkpCdBody *v7; // r15
  _QWORD *v8; // rax
  unsigned __int64 v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  hkpShape *v12; // r12
  _QWORD *v13; // rcx
  unsigned __int64 v14; // r8
  unsigned __int64 v15; // rax
  int *v16; // rbx
  __int64 v17; // r13
  __int64 v18; // rbp
  __int64 v19; // r12
  hkpCdPointCollector *v20; // rdi
  int v21; // ST30_4
  __int64 v22; // rax
  hkpCollisionDispatcher *v23; // r10
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  signed __int64 v27; // rcx
  __int64 v28; // [rsp+40h] [rbp-488h]
  int v29; // [rsp+48h] [rbp-480h]
  const void *v30; // [rsp+50h] [rbp-478h]
  hkpCdBody *v31; // [rsp+58h] [rbp-470h]
  hkAabb aabbOut; // [rsp+60h] [rbp-468h]
  char *v33; // [rsp+80h] [rbp-448h]
  int v34; // [rsp+88h] [rbp-440h]
  int v35; // [rsp+8Ch] [rbp-43Ch]
  char v36; // [rsp+90h] [rbp-438h]
  char v37; // [rsp+290h] [rbp-238h]
  char v38; // [rsp+4D0h] [rbp+8h]
  hkpCdPointCollector *v39; // [rsp+4E8h] [rbp+20h]

  v39 = collector;
  v5 = bodyA;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = v8[1];
  v10 = v8;
  if ( v9 < v8[3] )
  {
    *(_QWORD *)v9 = "LtBvTree";
    *(_QWORD *)(v9 + 16) = "StQueryTree";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  hkpBvTreeAgent::calcAabbLinearCast(v5, v7, v6, &aabbOut);
  v12 = v7->m_shape;
  v33 = &v36;
  v34 = 0;
  v35 = -2147483520;
  ((void (__fastcall *)(hkpShape *, hkAabb *, char **))v12->vfptr[8].__first_virtual_table_function__)(
    v12,
    &aabbOut,
    &v33);
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = v13[1];
  if ( v14 < v13[3] )
  {
    *(_QWORD *)v14 = "StNarrowPhase";
    v15 = __rdtsc();
    *(_DWORD *)(v14 + 8) = v15;
    v13[1] = v14 + 16;
  }
  v16 = (int *)v33;
  v17 = (unsigned __int8)v5->m_shape->m_type.m_storage;
  v31 = v7;
  v18 = (__int64)&v33[4 * v34];
  v30 = v7->m_motion;
  v19 = ((__int64 (__fastcall *)(hkpShape *))v12->vfptr[7].__vecDelDtor)(v12);
  if ( v16 != (int *)v18 )
  {
    v20 = startCollector;
    do
    {
      v21 = *v16;
      if ( *(_BYTE *)((__int64 (__fastcall *)(hkpShapeCollectionFilterVtbl **, char *, hkpLinearCastCollisionInput *, hkpCdBody *))v6->m_filter.m_storage->vfptr->isCollisionEnabled)(
                       &v6->m_filter.m_storage->vfptr,
                       &v38,
                       v6,
                       v5) )
      {
        v22 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v19 + 40i64))(
                v19,
                (unsigned int)*v16,
                &v37);
        v23 = v6->m_dispatcher.m_storage;
        v29 = *v16;
        v28 = v22;
        v23->m_agent2Func[(unsigned __int8)v23->m_agent2Types[v17][*(unsigned __int8 *)(v22 + 16)]].m_linearCastFunc(
          v5,
          (hkpCdBody *)&v28,
          v6,
          v39,
          v20);
      }
      ++v16;
    }
    while ( v16 != (int *)v18 );
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
  v34 = 0;
  if ( v35 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v33,
      4 * v35);
}

// File Line: 466
// RVA: 0xD1ACF0
void __fastcall hkpBvTreeAgent::getPenetrations(hkpBvTreeAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpBvTreeAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}

// File Line: 471
// RVA: 0xD1AD10
void __fastcall hkpBvTreeAgent::staticGetPenetrations(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpCdBody *v4; // r14
  hkpCdBodyPairCollector *v5; // r13
  hkpCollisionInput *v6; // rsi
  hkpCdBody *v7; // r15
  _QWORD *v8; // rax
  unsigned __int64 v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  hkpShape *v12; // r12
  _QWORD *v13; // rcx
  unsigned __int64 v14; // r8
  unsigned __int64 v15; // rax
  int *v16; // rbx
  __int64 v17; // rdi
  __int64 v18; // rbp
  __int64 i; // r12
  int v20; // ST30_4
  __int64 v21; // rax
  hkpCollisionDispatcher *v22; // r10
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  __int64 v27; // [rsp+40h] [rbp-478h]
  int v28; // [rsp+48h] [rbp-470h]
  const void *v29; // [rsp+50h] [rbp-468h]
  hkpCdBody *v30; // [rsp+58h] [rbp-460h]
  hkAabb aabbOut; // [rsp+60h] [rbp-458h]
  char *v32; // [rsp+80h] [rbp-438h]
  int v33; // [rsp+88h] [rbp-430h]
  int v34; // [rsp+8Ch] [rbp-42Ch]
  char v35; // [rsp+90h] [rbp-428h]
  char v36; // [rsp+290h] [rbp-228h]
  char v37; // [rsp+4C0h] [rbp+8h]

  v4 = bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = v8[1];
  v10 = v8;
  if ( v9 < v8[3] )
  {
    *(_QWORD *)v9 = "LtBvTree";
    *(_QWORD *)(v9 + 16) = "StQueryTree";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  hkpBvTreeAgent::staticCalcAabb(v4, v7, v6, &aabbOut);
  v12 = v7->m_shape;
  v32 = &v35;
  v33 = 0;
  v34 = -2147483520;
  ((void (__fastcall *)(hkpShape *, hkAabb *, char **))v12->vfptr[8].__first_virtual_table_function__)(
    v12,
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
  v16 = (int *)v32;
  v17 = (unsigned __int8)v4->m_shape->m_type.m_storage;
  v30 = v7;
  v18 = (__int64)&v32[4 * v33];
  v29 = v7->m_motion;
  for ( i = ((__int64 (__fastcall *)(hkpShape *))v12->vfptr[7].__vecDelDtor)(v12); v16 != (int *)v18; ++v16 )
  {
    v20 = *v16;
    if ( *(_BYTE *)((__int64 (__fastcall *)(hkpShapeCollectionFilterVtbl **, char *, hkpCollisionInput *, hkpCdBody *))v6->m_filter.m_storage->vfptr->isCollisionEnabled)(
                     &v6->m_filter.m_storage->vfptr,
                     &v37,
                     v6,
                     v4) )
    {
      v21 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)i + 40i64))(i, (unsigned int)*v16, &v36);
      v22 = v6->m_dispatcher.m_storage;
      v28 = *v16;
      v27 = v21;
      v22->m_agent2Func[(unsigned __int8)v22->m_agent2Types[v17][*(unsigned __int8 *)(v21 + 16)]].m_getPenetrationsFunc(
        v4,
        (hkpCdBody *)&v27,
        v6,
        v5);
      if ( v5->m_earlyOut.m_bool )
        break;
    }
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
  v33 = 0;
  if ( v34 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v32,
      4 * v34);
}

// File Line: 534
// RVA: 0xD1AF90
void __fastcall hkpBvTreeAgent::getClosestPoints(hkpBvTreeAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpBvTreeAgent::staticGetClosestPoints(bodyA, bodyB, input, collector);
}

// File Line: 540
// RVA: 0xD1AFB0
void __fastcall hkpBvTreeAgent::staticGetClosestPoints(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpCdBody *v4; // r15
  hkpCollisionInput *v5; // rsi
  hkpCdBody *v6; // r14
  _QWORD *v7; // rax
  unsigned __int64 v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  hkLifoAllocator *v11; // rax
  _DWORD *v12; // rbx
  unsigned __int64 v13; // rcx
  hkpShape *v14; // rdi
  signed int v15; // eax
  signed int v16; // ebp
  hkLifoAllocator *v17; // rax
  _QWORD *v18; // rax
  unsigned __int64 v19; // r8
  _QWORD *v20; // rcx
  unsigned __int64 v21; // rax
  __int64 v22; // rax
  __int64 v23; // rcx
  __int64 v24; // r13
  __int64 v25; // rdi
  __int64 v26; // r12
  hkpCollisionFilter *v27; // rcx
  unsigned int v28; // ebp
  __int64 v29; // rax
  hkpCollisionDispatcher *v30; // r10
  _QWORD *v31; // r8
  unsigned __int64 v32; // rcx
  unsigned __int64 v33; // rax
  __int64 v34[2]; // [rsp+30h] [rbp-298h]
  __int64 v35; // [rsp+40h] [rbp-288h]
  __int64 v36; // [rsp+48h] [rbp-280h]
  unsigned int v37; // [rsp+50h] [rbp-278h]
  __int64 v38; // [rsp+58h] [rbp-270h]
  hkpCdBody *v39; // [rsp+60h] [rbp-268h]
  hkAabb aabbOut; // [rsp+70h] [rbp-258h]
  char v41; // [rsp+90h] [rbp-238h]
  char v42; // [rsp+2D8h] [rbp+10h]
  hkpCdPointCollector *v43; // [rsp+2E8h] [rbp+20h]

  v43 = collector;
  v4 = bodyA;
  v5 = input;
  v6 = bodyB;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = v7[1];
  v9 = v7;
  if ( v8 < v7[3] )
  {
    *(_QWORD *)v8 = "LtBvTree";
    *(_QWORD *)(v8 + 16) = "StQueryTree";
    v10 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v10;
    v9[1] = v8 + 24;
  }
  hkpBvTreeAgent::staticCalcAabb(v4, v6, v5, &aabbOut);
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = v11->m_cur;
  v13 = (unsigned __int64)(v12 + 2048);
  if ( v11->m_slabSize < 0x2000 || (void *)v13 > v11->m_end )
    v12 = hkLifoAllocator::allocateFromNewSlab(v11, 0x2000);
  else
    v11->m_cur = (void *)v13;
  v14 = v6->m_shape;
  v15 = ((__int64 (__fastcall *)(hkpShape *, hkAabb *, _DWORD *, signed __int64))v6->m_shape->vfptr[9].__first_virtual_table_function__)(
          v6->m_shape,
          &aabbOut,
          v12,
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
    v22 = ((__int64 (__fastcall *)(hkpShape *))v14->vfptr[7].__vecDelDtor)(v14);
    v23 = (__int64)v6->m_motion;
    v39 = v6;
    v38 = v23;
    v24 = v22;
    v25 = 0i64;
    v26 = v16;
    v35 = (unsigned __int8)v4->m_shape->m_type.m_storage;
    if ( v16 > 0 )
    {
      do
      {
        v27 = v5->m_filter.m_storage;
        v28 = v12[v25];
        if ( v27 )
        {
          LODWORD(v34[0]) = v12[v25];
          if ( *(_BYTE *)v27->vfptr->isCollisionEnabled(
                           (hkpShapeCollectionFilter *)&v27->vfptr,
                           (hkBool *)&v42,
                           v5,
                           v4,
                           v6,
                           (hkpShapeContainer *)v24,
                           v34[0]) )
          {
            v29 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v24 + 40i64))(v24, v28, &v41);
            v30 = v5->m_dispatcher.m_storage;
            v36 = v29;
            v37 = v28;
            (*((void (__fastcall **)(hkpCdBody *, __int64 *, hkpCollisionInput *, hkpCdPointCollector *))&v30->vfptr
             + 5 * ((unsigned __int8)v30->m_agent2Types[v35][*(unsigned __int8 *)(v29 + 16)] + 79i64)))(
              v4,
              &v36,
              v5,
              v43);
          }
        }
        ++v25;
      }
      while ( v25 < v26 );
    }
    v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    if ( v17->m_slabSize >= 0x2000 && v12 + 2048 == v17->m_cur && v17->m_firstNonLifoEnd != v12 )
    {
      v17->m_cur = v12;
      goto LABEL_26;
    }
  }
  else
  {
    v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    if ( v17->m_slabSize >= 0x2000 && v12 + 2048 == v17->m_cur && v17->m_firstNonLifoEnd != v12 )
    {
      v17->m_cur = v12;
      goto LABEL_26;
    }
  }
  hkLifoAllocator::slowBlockFree(v17, v12, 0x2000);
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
void __fastcall hkpBvTreeAgent::calcAabbLinearCast(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkAabb *aabbOut)
{
  hkpLinearCastCollisionInput *v4; // rsi
  hkpCdBody *v5; // rdi
  hkpCdBody *v6; // rbx
  hkAabb *v7; // rbp
  __int128 v8; // xmm2
  __int64 v9; // r8
  __m128 *v10; // rax
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  hkTransformf v17; // [rsp+20h] [rbp-48h]

  v4 = input;
  v5 = bodyB;
  v6 = bodyA;
  v7 = aabbOut;
  hkTransformf::setMulInverseMul(&v17, (hkTransformf *)bodyB->m_motion, (hkTransformf *)bodyA->m_motion);
  v8 = LODWORD(v4->m_tolerance.m_storage);
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, hkAabb *))v6->m_shape->vfptr[2].__vecDelDtor)(
    v6->m_shape,
    &v17,
    v9,
    v7);
  v10 = (__m128 *)v5->m_motion;
  v11 = v10[2];
  v12 = _mm_unpacklo_ps(*v10, v10[1]);
  v13 = _mm_movelh_ps(v12, v11);
  v14 = _mm_movehl_ps(v13, v12);
  v15 = v4->m_path.m_quad;
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v14, v11, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v13)),
          _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), _mm_shuffle_ps(_mm_unpackhi_ps(*v10, v10[1]), v11, 228)));
  v7->m_min.m_quad = _mm_add_ps(_mm_min_ps((__m128)0i64, v16), v7->m_min.m_quad);
  v7->m_max.m_quad = _mm_add_ps(_mm_max_ps((__m128)0i64, v16), v7->m_max.m_quad);
}

// File Line: 632
// RVA: 0xD1C860
void __fastcall hkpBvTreeAgent::staticCalcAabb(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkAabb *aabbOut)
{
  hkpCollisionInput *v4; // rsi
  hkpCdBody *v5; // rbx
  hkAabb *v6; // rdi
  __int128 v7; // xmm2
  __int64 v8; // r8
  hkTransformf v9; // [rsp+20h] [rbp-48h]

  v4 = input;
  v5 = bodyA;
  v6 = aabbOut;
  hkTransformf::setMulInverseMul(&v9, (hkTransformf *)bodyB->m_motion, (hkTransformf *)bodyA->m_motion);
  v7 = LODWORD(v4->m_tolerance.m_storage);
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, hkAabb *))v5->m_shape->vfptr[2].__vecDelDtor)(
    v5->m_shape,
    &v9,
    v8,
    v6);
}

// File Line: 646
// RVA: 0xD1C8C0
void __fastcall hkpBvTreeAgent::LinearCastAabbCastCollector::addHit(hkpBvTreeAgent::LinearCastAabbCastCollector *this, unsigned int key)
{
  hkpBvTreeAgent::LinearCastAabbCastCollector *v2; // rbx
  unsigned int v3; // edi
  __int64 v4; // rax
  hkpLinearCastCollisionInput *v5; // r8
  hkpCollisionFilter *v6; // rcx
  __int64 v7; // rsi
  unsigned int v8; // ST30_4
  __int64 v9; // rax
  __int64 v10; // rcx
  hkpLinearCastCollisionInput *v11; // r8
  __int64 v12; // rcx
  hkpCdBody *v13; // rcx
  __int64 v14; // [rsp+40h] [rbp-228h]
  unsigned int v15; // [rsp+48h] [rbp-220h]
  __int64 v16; // [rsp+50h] [rbp-218h]
  __int64 v17; // [rsp+58h] [rbp-210h]
  char v18; // [rsp+60h] [rbp-208h]
  unsigned int v19; // [rsp+270h] [rbp+8h]

  v2 = this;
  v3 = key;
  v4 = ((__int64 (*)(void))this->m_bvTreeBody->m_shape->vfptr[7].__vecDelDtor)();
  v5 = v2->m_input;
  v6 = v5->m_filter.m_storage;
  v7 = v4;
  if ( v6 )
  {
    v8 = v3;
    if ( *(_BYTE *)v6->vfptr->isCollisionEnabled(
                     (hkpShapeCollectionFilter *)&v6->vfptr,
                     (hkBool *)&v19,
                     (hkpCollisionInput *)&v5->m_dispatcher,
                     v2->m_castBody,
                     v2->m_bvTreeBody,
                     (hkpShapeContainer *)v4,
                     v8) )
    {
      v9 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v7 + 40i64))(v7, v3, &v18);
      v10 = (__int64)v2->m_bvTreeBody;
      v11 = v2->m_input;
      v17 = v10;
      v12 = *(_QWORD *)(v10 + 16);
      v14 = v9;
      v16 = v12;
      v13 = v2->m_castBody;
      v15 = v3;
      v11->m_dispatcher.m_storage->m_agent2Func[(unsigned __int8)v11->m_dispatcher.m_storage->m_agent2Types[(unsigned __int8)v13->m_shape->m_type.m_storage][*(unsigned __int8 *)(v9 + 16)]].m_linearCastFunc(
        v13,
        (hkpCdBody *)&v14,
        v11,
        v2->m_castCollector,
        v2->m_startCollector);
      v19 = LODWORD(v2->m_castCollector->m_earlyOutDistance);
      v2->m_earlyOutFraction.m_real = _mm_min_ps(
                                        v2->m_earlyOutFraction.m_real,
                                        _mm_shuffle_ps((__m128)v19, (__m128)v19, 0));
    }
  }
}


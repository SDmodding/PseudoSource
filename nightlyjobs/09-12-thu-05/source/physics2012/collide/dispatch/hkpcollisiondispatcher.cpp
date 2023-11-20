// File Line: 51
// RVA: 0xCEF7D0
void *__fastcall hkNullAgent3::create(hkpAgent3Input *input, hkpAgentEntry *entry, void *freeMemory)
{
  entry->m_streamCommand = 0;
  return freeMemory;
}

// File Line: 60
// RVA: 0xCEF7E0
void __fastcall hkNullAgent3::destroy(hkpAgentEntry *entry, void *agentData, hkpContactMgr *mgr, hkpConstraintOwner *constraintOwner)
{
  ;
}

// File Line: 65
// RVA: 0xCEF7F0
void *__fastcall hkNullAgent3::process(hkpAgent3ProcessInput *input, hkpAgentEntry *entry, void *agentData, hkVector4f *separatingNormalOut)
{
  return agentData;
}

// File Line: 73
// RVA: 0xCEF610
void __fastcall hkpCollisionDispatcher::resetCreationFunctions(hkpCollisionDispatcher *this)
{
  signed __int64 v1; // rdi
  hkpCollisionDispatcher *v2; // rbx
  char (*v3)[35]; // rax
  signed __int64 v4; // rdx
  signed __int64 v5; // r8
  hkpCollisionDispatcher::DebugEntry (*v6)[35][35]; // rcx
  signed __int64 v7; // rcx

  v1 = 0i64;
  v2 = this;
  this->m_numAgent2Types = 1;
  this->m_numAgent3Types = 1;
  v3 = this->m_agent3Types;
  v4 = 0i64;
  do
  {
    v5 = 35i64;
    do
    {
      v6 = v2->m_debugAgent2Table;
      if ( v6 )
      {
        (*v6)[0][v4].m_priority = 100;
        (*v2->m_debugAgent2TablePred)[0][v4].m_priority = 100;
        (*v2->m_debugAgent3Table)[0][v4].m_priority = 100;
        (*v2->m_debugAgent3TablePred)[0][v4].m_priority = 100;
      }
      (*v3)[-5024] = 0;
      *(_BYTE *)v3 = 0;
      (*v3)[-3799] = 0;
      (*v3)[1232] = 0;
      v3 = (char (*)[35])((char *)v3 + 1);
      ++v4;
      --v5;
    }
    while ( v5 );
  }
  while ( v4 < 1225 );
  v2->m_agent2Func[0].m_createFunc = hkpNullAgent::createNullAgent;
  v2->m_agent2Func[0].m_getPenetrationsFunc = hkpNullAgent::staticGetPenetrations;
  v2->m_agent2Func[0].m_getClosestPointFunc = hkpNullAgent::staticGetClosestPoints;
  v2->m_agent2Func[0].m_linearCastFunc = hkpNullAgent::staticLinearCast;
  *(_WORD *)&v2->m_agent2Func[0].m_isFlipped.m_bool = 256;
  v2->m_agent3Func[0].m_createFunc = hkNullAgent3::create;
  v2->m_agent3Func[0].m_cleanupFunc = 0i64;
  v2->m_agent3Func[0].m_destroyFunc = hkNullAgent3::destroy;
  v2->m_agent3Func[0].m_removePointFunc = 0i64;
  v2->m_agent3Func[0].m_commitPotentialFunc = 0i64;
  v2->m_agent3Func[0].m_createZombieFunc = 0i64;
  v2->m_agent3Func[0].m_updateFilterFunc = 0i64;
  v2->m_agent3Func[0].m_processFunc = hkNullAgent3::process;
  v2->m_agent3Func[0].m_sepNormalFunc = 0i64;
  v2->m_agent3Func[0].m_invalidateTimFunc = 0i64;
  v2->m_agent3Func[0].m_warpTimeFunc = 0i64;
  v2->m_agent3Func[0].m_symmetric = 0;
  hkAgent3Bridge::registerAgent3(v2);
  v2->m_collisionAgentRegistered.m_bool = 0;
  if ( v2->m_debugAgent3Table )
  {
    do
    {
      v7 = 35i64;
      do
      {
        ++v1;
        *((_BYTE *)&(*v2->m_debugAgent3Table)[0][v1] - 1) = 100;
        *((_BYTE *)&(*v2->m_debugAgent3TablePred)[0][v1] - 1) = 100;
        --v7;
      }
      while ( v7 );
    }
    while ( v1 < 1225 );
  }
}

// File Line: 143
// RVA: 0xCED990
void __fastcall hkpCollisionDispatcher::hkpCollisionDispatcher(hkpCollisionDispatcher *this, hkpCollisionAgent *(__fastcall *defaultCollisionAgent)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *), hkpContactMgrFactory *defaultContactMgrFactory)
{
  hkpCollisionDispatcher *v3; // r14
  hkpContactMgrFactory *v4; // rdi
  signed int v5; // ecx
  signed __int64 v6; // rax
  signed int v7; // ebp
  signed int v8; // ecx
  signed __int64 v9; // rax
  _QWORD *v10; // rbx
  signed __int64 v11; // r15
  signed __int64 v12; // rsi
  _DWORD *v13; // rax
  signed __int64 v14; // rcx

  v3 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpCollisionDispatcher::`vftable;
  this->m_defaultCollisionAgent = defaultCollisionAgent;
  v4 = defaultContactMgrFactory;
  v5 = 63;
  v6 = (signed __int64)&v3->m_agent2Func[0].m_isPredictive;
  v7 = 1;
  do
  {
    --v5;
    *(_WORD *)(v6 - 1) = 0;
    v6 += 40i64;
  }
  while ( v5 >= 0 );
  v8 = 17;
  v9 = (signed __int64)&v3->m_agent3Func[0].m_ignoreSymmetricVersion;
  do
  {
    --v8;
    *(_WORD *)(v9 - 1) = 0;
    *(_BYTE *)(v9 + 1) = 0;
    *(_QWORD *)(v9 - 41) = 0i64;
    *(_QWORD *)(v9 - 33) = 0i64;
    *(_QWORD *)(v9 - 25) = 0i64;
    *(_QWORD *)(v9 - 17) = 0i64;
    v9 += 112i64;
  }
  while ( v8 >= 0 );
  v3->m_shapeInheritance.m_data = 0i64;
  v3->m_shapeInheritance.m_size = 0;
  v3->m_shapeInheritance.m_capacityAndFlags = 2147483648;
  v3->m_debugAgent2Table = 0i64;
  v3->m_debugAgent2TablePred = 0i64;
  v3->m_debugAgent3Table = 0i64;
  v3->m_debugAgent3TablePred = 0i64;
  v3->m_collisionAgentRegistered.m_bool = 0;
  *(_WORD *)&v3->m_midphaseAgent3Registered.m_bool = 256;
  v3->m_numAgent3Types = 0;
  v10 = v3->m_contactMgrFactory;
  v11 = 8i64;
  do
  {
    v12 = 8i64;
    do
    {
      *v10 = v4;
      if ( v4 )
        hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
      ++v10;
      --v12;
    }
    while ( v12 );
    --v11;
  }
  while ( v11 );
  v13 = v3->m_hasAlternateType;
  v14 = 35i64;
  do
  {
    *v13 = v7;
    v7 = __ROL4__(v7, 1);
    ++v13;
    --v14;
  }
  while ( v14 );
  hkpCollisionDispatcher::resetCreationFunctions(v3);
  v3->m_agent3Registered.m_bool = 0;
}

// File Line: 206
// RVA: 0xCEDF20
void __fastcall hkpCollisionDispatcher::setEnableChecks(hkpCollisionDispatcher *this, hkBool checkEnabled)
{
  this->m_checkEnabled = checkEnabled;
}

// File Line: 211
// RVA: 0xCEE300
void __fastcall hkpCollisionDispatcher::disableDebugging(hkpCollisionDispatcher *this)
{
  hkpCollisionDispatcher::DebugEntry (*v1)[35][35]; // rbx
  hkpCollisionDispatcher *v2; // rdi
  _QWORD **v3; // rax
  hkpCollisionDispatcher::DebugEntry (*v4)[35][35]; // rbx
  _QWORD **v5; // rax
  hkpCollisionDispatcher::DebugEntry (*v6)[35][35]; // rbx
  _QWORD **v7; // rax
  hkpCollisionDispatcher::DebugEntry (*v8)[35][35]; // rbx
  _QWORD **v9; // rax

  v1 = this->m_debugAgent2Table;
  v2 = this;
  if ( v1 )
  {
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpCollisionDispatcher::DebugEntry (*)[35][35], signed __int64))(*v3[12] + 16i64))(
      v3[12],
      v1,
      3675i64);
    v4 = v2->m_debugAgent2TablePred;
    v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpCollisionDispatcher::DebugEntry (*)[35][35], signed __int64))(*v5[12] + 16i64))(
      v5[12],
      v4,
      3675i64);
    v6 = v2->m_debugAgent3Table;
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpCollisionDispatcher::DebugEntry (*)[35][35], signed __int64))(*v7[12] + 16i64))(
      v7[12],
      v6,
      3675i64);
    v8 = v2->m_debugAgent3TablePred;
    v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpCollisionDispatcher::DebugEntry (*)[35][35], signed __int64))(*v9[12] + 16i64))(
      v9[12],
      v8,
      3675i64);
    v2->m_debugAgent2Table = 0i64;
    v2->m_debugAgent2TablePred = 0i64;
    v2->m_debugAgent3Table = 0i64;
    v2->m_debugAgent3TablePred = 0i64;
  }
}

// File Line: 231
// RVA: 0xCEDAF0
void __fastcall hkpCollisionDispatcher::~hkpCollisionDispatcher(hkpCollisionDispatcher *this)
{
  hkpCollisionDispatcher *v1; // r14
  hkReferencedObject **v2; // rbx
  signed __int64 v3; // rsi
  signed __int64 v4; // rdi
  int v5; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpCollisionDispatcher::`vftable;
  hkpCollisionDispatcher::disableDebugging(this);
  v2 = (hkReferencedObject **)v1->m_contactMgrFactory;
  v3 = 8i64;
  do
  {
    v4 = 8i64;
    do
    {
      if ( *v2 )
        hkReferencedObject::removeReference(*v2);
      ++v2;
      --v4;
    }
    while ( v4 );
    --v3;
  }
  while ( v3 );
  v5 = v1->m_shapeInheritance.m_capacityAndFlags;
  v1->m_shapeInheritance.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_shapeInheritance.m_data,
      8 * v5);
  v1->m_shapeInheritance.m_data = 0i64;
  v1->m_shapeInheritance.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 249
// RVA: 0xCEDCB0
void __fastcall hkpCollisionDispatcher::registerCollisionAgent(hkpCollisionDispatcher *this, hkpCollisionDispatcher::AgentFuncs *f, hkcdShapeType::ShapeTypeEnum typeA, hkcdShapeType::ShapeTypeEnum typeB)
{
  hkcdShapeType::ShapeTypeEnum origB; // esi
  hkcdShapeType::ShapeTypeEnum origA; // ebp
  hkpCollisionDispatcher::AgentFuncs *v6; // rbx
  hkpCollisionDispatcher *v7; // rdi

  origB = typeB;
  this->m_agent2Func[this->m_numAgent2Types] = *f;
  origA = typeA;
  v6 = f;
  v7 = this;
  hkpCollisionDispatcher::internalRegisterCollisionAgent(
    this,
    this->m_agent3Types,
    1,
    typeA,
    typeB,
    typeA,
    typeB,
    this->m_debugAgent3Table,
    0);
  hkpCollisionDispatcher::internalRegisterCollisionAgent(
    v7,
    v7->m_agent2Types,
    v7->m_numAgent2Types,
    origA,
    origB,
    origA,
    origB,
    v7->m_debugAgent2Table,
    0);
  if ( v6->m_isPredictive.m_bool )
  {
    hkpCollisionDispatcher::internalRegisterCollisionAgent(
      v7,
      v7->m_agent3TypesPred,
      1,
      origA,
      origB,
      origA,
      origB,
      v7->m_debugAgent3TablePred,
      0);
    hkpCollisionDispatcher::internalRegisterCollisionAgent(
      v7,
      v7->m_agent2TypesPred,
      v7->m_numAgent2Types,
      origA,
      origB,
      origA,
      origB,
      v7->m_debugAgent2TablePred,
      0);
  }
  ++v7->m_numAgent2Types;
}

// File Line: 270
// RVA: 0xCEDE20
void __fastcall hkpCollisionDispatcher::registerCollisionAgent2(hkpCollisionDispatcher *this, hkpCollisionDispatcher::AgentFuncs *f, hkcdShapeType::ShapeTypeEnum typeA, hkcdShapeType::ShapeTypeEnum typeB)
{
  hkcdShapeType::ShapeTypeEnum origB; // esi
  hkcdShapeType::ShapeTypeEnum origA; // ebp
  hkpCollisionDispatcher::AgentFuncs *v6; // rbx
  hkpCollisionDispatcher *v7; // rdi

  origB = typeB;
  origA = typeA;
  this->m_agent2Func[this->m_numAgent2Types] = *f;
  v6 = f;
  v7 = this;
  hkpCollisionDispatcher::internalRegisterCollisionAgent(
    this,
    this->m_agent2Types,
    this->m_numAgent2Types,
    typeA,
    typeB,
    typeA,
    typeB,
    this->m_debugAgent2Table,
    0);
  if ( v6->m_isPredictive.m_bool )
    hkpCollisionDispatcher::internalRegisterCollisionAgent(
      v7,
      v7->m_agent2TypesPred,
      v7->m_numAgent2Types,
      origA,
      origB,
      origA,
      origB,
      v7->m_debugAgent2TablePred,
      0);
  ++v7->m_numAgent2Types;
}

// File Line: 289
// RVA: 0xCEE3E0
__int64 __fastcall hkpCollisionDispatcher::registerAgent3(hkpCollisionDispatcher *this, hkpCollisionDispatcher::Agent3Funcs *f, hkcdShapeType::ShapeTypeEnum typeA, hkcdShapeType::ShapeTypeEnum typeB)
{
  __int128 v4; // xmm0
  __int128 v5; // xmm1
  hkcdShapeType::ShapeTypeEnum origA; // esi
  hkcdShapeType::ShapeTypeEnum origB; // ebp
  hkpCollisionDispatcher::Agent3Funcs *v8; // rdi
  hkpCollisionDispatcher *v9; // rbx
  __int128 v10; // xmm2
  __int128 v11; // xmm5
  __int128 v12; // xmm3
  __int128 v13; // xmm4
  signed __int64 v14; // rax
  __int64 v15; // rdi
  signed __int64 v16; // rax
  __int128 v18; // [rsp+50h] [rbp-D8h]
  __int128 v19; // [rsp+60h] [rbp-C8h]
  __int128 v20; // [rsp+70h] [rbp-B8h]
  __int128 v21; // [rsp+80h] [rbp-A8h]
  __int128 v22; // [rsp+90h] [rbp-98h]
  __int128 v23; // [rsp+A0h] [rbp-88h]
  __int128 v24; // [rsp+100h] [rbp-28h]
  __int128 v25; // [rsp+110h] [rbp-18h]

  this->m_agent3Registered.m_bool = 1;
  v4 = *(_OWORD *)&f->m_processFunc;
  v5 = *(_OWORD *)&f->m_createFunc;
  origA = typeB;
  origB = typeA;
  v8 = f;
  v9 = this;
  v10 = *(_OWORD *)&f->m_cleanupFunc;
  v11 = *(_OWORD *)&f->m_warpTimeFunc;
  v12 = *(_OWORD *)&f->m_commitPotentialFunc;
  v13 = *(_OWORD *)&f->m_updateFilterFunc;
  v23 = *(_OWORD *)&f->m_createFunc;
  v21 = *(_OWORD *)&f->m_cleanupFunc;
  v22 = *(_OWORD *)&f->m_warpTimeFunc;
  v18 = *(_OWORD *)&f->m_commitPotentialFunc;
  v20 = *(_OWORD *)&f->m_updateFilterFunc;
  LODWORD(v25) = 0;
  v24 = *(_OWORD *)&f->m_processFunc;
  v19 = *(_OWORD *)&f->m_processFunc;
  if ( typeA != typeB && !f->m_ignoreSymmetricVersion.m_bool )
  {
    LODWORD(v25) = 2;
    v14 = 14 * (this->m_numAgent3Types + 73i64);
    *(_OWORD *)&(&this->vfptr)[v14] = v5;
    *(_OWORD *)((char *)&this->m_defaultCollisionAgent + v14 * 8) = v10;
    *(_OWORD *)&this->m_contactMgrFactory[0][v14 + 1] = v12;
    *(_OWORD *)&this->m_contactMgrFactory[0][v14 + 3] = v13;
    *(_OWORD *)&this->m_contactMgrFactory[0][v14 + 5] = v11;
    *(_OWORD *)&this->m_contactMgrFactory[0][v14 + 7] = v4;
    *(_OWORD *)&this->m_contactMgrFactory[1][v14 + 1] = v25;
    hkpCollisionDispatcher::internalRegisterCollisionAgent(
      this,
      this->m_agent3Types,
      this->m_numAgent3Types,
      typeB,
      typeA,
      typeB,
      typeA,
      this->m_debugAgent3Table,
      0);
    if ( BYTE8(v24) )
      hkpCollisionDispatcher::internalRegisterCollisionAgent(
        v9,
        v9->m_agent3TypesPred,
        v9->m_numAgent3Types,
        origA,
        origB,
        origA,
        origB,
        v9->m_debugAgent3TablePred,
        0);
    ++v9->m_numAgent3Types;
    v4 = v19;
    v5 = v23;
    LODWORD(v25) = 1;
    v10 = v21;
    v12 = v18;
    v13 = v20;
    v11 = v22;
  }
  if ( v8->m_reusePreviousEntry.m_bool )
  {
    LODWORD(v15) = v9->m_numAgent3Types - 1;
  }
  else
  {
    v15 = v9->m_numAgent3Types;
    v9->m_numAgent3Types = v15 + 1;
    v16 = 14 * (v15 + 73);
    *(_OWORD *)&(&v9->vfptr)[v16] = v5;
    *(_OWORD *)((char *)&v9->m_defaultCollisionAgent + v16 * 8) = v10;
    *(_OWORD *)&v9->m_contactMgrFactory[0][v16 + 1] = v12;
    *(_OWORD *)&v9->m_contactMgrFactory[0][v16 + 3] = v13;
    *(_OWORD *)&v9->m_contactMgrFactory[0][v16 + 5] = v11;
    *(_OWORD *)&v9->m_contactMgrFactory[0][v16 + 7] = v4;
    *(_OWORD *)&v9->m_contactMgrFactory[1][v16 + 1] = v25;
  }
  hkpCollisionDispatcher::internalRegisterCollisionAgent(
    v9,
    v9->m_agent3Types,
    v15,
    origB,
    origA,
    origB,
    origA,
    v9->m_debugAgent3Table,
    0);
  if ( BYTE8(v24) )
    hkpCollisionDispatcher::internalRegisterCollisionAgent(
      v9,
      v9->m_agent3TypesPred,
      v15,
      origB,
      origA,
      origB,
      origA,
      v9->m_debugAgent3TablePred,
      0);
  return (unsigned int)v15;
}

// File Line: 343
// RVA: 0xCEF250
void __fastcall hkpCollisionDispatcher::internalRegisterCollisionAgent(hkpCollisionDispatcher *this, char (*agentTypesTable)[35], int agentType, hkcdShapeType::ShapeTypeEnum typeA, hkcdShapeType::ShapeTypeEnum typeB, hkcdShapeType::ShapeTypeEnum origA, hkcdShapeType::ShapeTypeEnum origB, hkpCollisionDispatcher::DebugEntry (*debugTable)[35][35], int depth)
{
  hkpCollisionDispatcher *v9; // rdi
  int v10; // ecx
  hkcdShapeType::ShapeTypeEnum v11; // esi
  int v12; // er11
  __int64 v13; // rbp
  hkpCollisionDispatcher::ShapeInheritance *v14; // rsi
  hkcdShapeType::ShapeTypeEnum v15; // eax
  int v16; // edx
  hkcdShapeType::ShapeTypeEnum v17; // er8
  int v18; // er9
  signed __int32 v19; // ecx
  hkcdShapeType::ShapeTypeEnum v20; // eax
  __int64 v21; // rbx
  __int64 v22; // rbp
  __int64 v23; // r10
  hkpCollisionDispatcher::DebugEntry (*v24)[35][35]; // r9
  signed __int64 v25; // rcx
  signed __int64 v26; // r8
  char *v27; // rcx
  __int64 v28; // rbp
  __int64 v29; // rbx
  __int64 v30; // rax
  char *v31; // rbx
  const char *v32; // rbp
  const char *v33; // rdi
  const char *v34; // rsi
  const char *v35; // rax
  int v36; // [rsp+50h] [rbp-458h]
  __int64 v37; // [rsp+50h] [rbp-458h]
  __int64 v38; // [rsp+58h] [rbp-450h]
  signed __int64 v39; // [rsp+60h] [rbp-448h]
  __int64 v40; // [rsp+68h] [rbp-440h]
  char *v41; // [rsp+70h] [rbp-438h]
  __int64 v42; // [rsp+78h] [rbp-430h]
  char buf; // [rsp+80h] [rbp-428h]
  hkpCollisionDispatcher *v44; // [rsp+4B0h] [rbp+8h]
  char (*agentTypesTablea)[35]; // [rsp+4B8h] [rbp+10h]
  int v46; // [rsp+4C0h] [rbp+18h]
  hkcdShapeType::ShapeTypeEnum typeAa; // [rsp+4C8h] [rbp+20h]

  typeAa = typeA;
  v46 = agentType;
  agentTypesTablea = agentTypesTable;
  v44 = this;
  v9 = this;
  this->m_collisionAgentRegistered.m_bool = 1;
  v10 = 0;
  v11 = typeA;
  v12 = agentType;
  v36 = 0;
  if ( v9->m_shapeInheritance.m_size > 0 )
  {
    v13 = 0i64;
    do
    {
      v14 = &v9->m_shapeInheritance.m_data[v13];
      if ( v14->m_alternateType == typeAa )
      {
        hkpCollisionDispatcher::internalRegisterCollisionAgent(
          v9,
          agentTypesTable,
          v12,
          v14->m_primaryType,
          typeB,
          origA,
          origB,
          debugTable,
          depth + 1);
        v10 = v36;
        v12 = v46;
        agentTypesTable = agentTypesTablea;
      }
      if ( v14->m_alternateType == typeB )
      {
        v15 = v14->m_primaryType;
        v11 = typeAa;
        hkpCollisionDispatcher::internalRegisterCollisionAgent(
          v9,
          agentTypesTable,
          v12,
          typeAa,
          v15,
          origA,
          origB,
          debugTable,
          depth + 1);
        v10 = v36;
      }
      else
      {
        v11 = typeAa;
      }
      v12 = v46;
      agentTypesTable = agentTypesTablea;
      ++v10;
      ++v13;
      v36 = v10;
    }
    while ( v10 < v9->m_shapeInheritance.m_size );
  }
  v16 = depth;
  v17 = v11;
  v18 = v11 + 1;
  v19 = typeB + 1;
  v20 = typeB;
  if ( v11 == -1 )
  {
    v17 = 0;
    v16 = depth + 1;
    v18 = 35;
    ++depth;
  }
  if ( typeB == -1 )
  {
    v20 = 0;
    ++v16;
    v19 = 35;
    depth = v16;
  }
  v21 = (signed int)v17;
  v22 = v18;
  v23 = v19;
  v38 = (signed int)v20;
  v42 = v19;
  if ( (signed int)v17 < (signed __int64)v18 )
  {
    v24 = debugTable;
    v25 = 35i64 * (signed int)v17 + (signed int)v20;
    v26 = (signed __int64)agentTypesTablea[v17];
    v39 = (signed __int64)agentTypesTablea[v21];
    v27 = &(*debugTable)[0][0].m_typeB + 2 * v25 + v25;
    v28 = v22 - v21;
    v29 = (signed int)v20;
    v40 = v28;
    v41 = v27;
    do
    {
      v30 = v29;
      v37 = v29;
      if ( v29 < v23 )
      {
        v31 = v27;
        do
        {
          *(_BYTE *)(v26 + v30) = v12;
          if ( v24 )
          {
            if ( v9->m_checkEnabled.m_bool )
            {
              if ( v16 > v31[1] )
              {
                v32 = hkGetShapeTypeName((hkcdShapeType::ShapeTypeEnum)*(v31 - 1));
                v33 = hkGetShapeTypeName((hkcdShapeType::ShapeTypeEnum)*v31);
                v34 = hkGetShapeTypeName(v11);
                v35 = hkGetShapeTypeName(typeB);
                hkString::snprintf(
                  &buf,
                  1000,
                  "Agent handling types <%s-%s> would override more specialized agent <%s-%s>\n"
                  "Maybe the order of registering your collision agent is wrong, make sure you register your alternate type agents first",
                  v34,
                  v35,
                  v32,
                  v33);
                v16 = depth;
                v9 = v44;
                v26 = v39;
                v24 = debugTable;
                v23 = v42;
                LOBYTE(v12) = v46;
                v11 = typeAa;
              }
              v30 = v37;
            }
            v31[1] = v16;
            *(v31 - 1) = origA;
            *v31 = origB;
          }
          ++v30;
          v31 += 3;
          v37 = v30;
        }
        while ( v30 < v23 );
        v27 = v41;
        v28 = v40;
        v29 = v38;
      }
      v27 += 105;
      v26 += 35i64;
      v40 = --v28;
      v41 = v27;
      v39 = v26;
    }
    while ( v28 );
  }
}

// File Line: 443
// RVA: 0xCEF580
void __fastcall hkpCollisionDispatcher::updateHasAlternateType(hkpCollisionDispatcher *this, hkcdShapeType::ShapeTypeEnum primaryType, hkcdShapeType::ShapeTypeEnum alternateType, int depth)
{
  hkcdShapeType::ShapeTypeEnum v4; // ebp
  int v5; // ebx
  hkpCollisionDispatcher *v6; // rsi
  __int64 v7; // rdi
  hkpCollisionDispatcher::ShapeInheritance *v8; // rax
  hkcdShapeType::ShapeTypeEnum v9; // er8
  int v10; // [rsp+48h] [rbp+20h]

  v10 = depth;
  v4 = primaryType;
  v5 = 0;
  v6 = this;
  this->m_hasAlternateType[primaryType] |= this->m_hasAlternateType[alternateType];
  if ( this->m_shapeInheritance.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = v6->m_shapeInheritance.m_data;
      v9 = v8[v7].m_alternateType;
      if ( v9 == v4 )
      {
        hkpCollisionDispatcher::updateHasAlternateType(v6, v8[v7].m_primaryType, v9, depth + 1);
        depth = v10;
      }
      ++v5;
      ++v7;
    }
    while ( v5 < v6->m_shapeInheritance.m_size );
  }
}

// File Line: 465
// RVA: 0xCEDBB0
void __fastcall hkpCollisionDispatcher::registerAlternateShapeType(hkpCollisionDispatcher *this, hkcdShapeType::ShapeTypeEnum primaryType, hkcdShapeType::ShapeTypeEnum alternateType)
{
  int v3; // er9
  hkcdShapeType::ShapeTypeEnum v4; // edi
  hkcdShapeType::ShapeTypeEnum v5; // esi
  hkpCollisionDispatcher *v6; // rbx
  __int64 v7; // r10
  hkpCollisionDispatcher::ShapeInheritance *v8; // rax
  hkpCollisionDispatcher::ShapeInheritance *v9; // rax
  int v10; // ecx
  __int64 v11; // rdx
  hkcdShapeType::ShapeTypeEnum v12; // ecx
  hkArray<hkpCollisionDispatcher::ShapeInheritance,hkContainerHeapAllocator> *v13; // rbx
  __int64 v14; // rdx
  hkcdShapeType::ShapeTypeEnum *v15; // r8

  v3 = 0;
  v4 = alternateType;
  v5 = primaryType;
  v6 = this;
  if ( this->m_shapeInheritance.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = v6->m_shapeInheritance.m_data;
      if ( v8[v7].m_primaryType == v5 && v8[v7].m_alternateType == alternateType )
      {
        --v6->m_shapeInheritance.m_size;
        v9 = &v8[v7];
        v10 = 8 * (v6->m_shapeInheritance.m_size - v3);
        if ( v10 > 0 )
        {
          v11 = ((unsigned int)(v10 - 1) >> 2) + 1;
          do
          {
            v12 = v9[1].m_primaryType;
            v9 = (hkpCollisionDispatcher::ShapeInheritance *)((char *)v9 + 4);
            v9[-1].m_alternateType = v12;
            --v11;
          }
          while ( v11 );
        }
        --v3;
        --v7;
      }
      ++v3;
      ++v7;
    }
    while ( v3 < v6->m_shapeInheritance.m_size );
  }
  hkpCollisionDispatcher::updateHasAlternateType(v6, v5, alternateType, 0);
  v13 = &v6->m_shapeInheritance;
  if ( v13->m_size == (v13->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v13, 8);
  v14 = v13->m_size;
  v15 = (hkcdShapeType::ShapeTypeEnum *)&v13->m_data[v14];
  v13->m_size = v14 + 1;
  *v15 = v5;
  *((_DWORD *)v15 + 1) = v4;
}

// File Line: 516
// RVA: 0xCEE640
void __fastcall hkpCollisionDispatcher::registerContactMgrFactory(hkpCollisionDispatcher *this, hkpContactMgrFactory *fac, int responseA, int responseB)
{
  hkpCollisionDispatcher *v4; // rbp
  __int64 v5; // rbx
  __int64 v6; // rdi
  hkpContactMgrFactory *v7; // r14
  __int64 v8; // rsi
  signed __int64 v9; // rbx
  signed __int64 v10; // rbx

  v4 = this;
  v5 = responseB;
  v6 = responseA;
  v7 = fac;
  hkReferencedObject::addReference((hkReferencedObject *)&fac->vfptr);
  v8 = v5;
  v9 = v6 + 8 * v5;
  hkReferencedObject::removeReference((hkReferencedObject *)&v4->m_contactMgrFactory[0][v9]->vfptr);
  v4->m_contactMgrFactory[0][v9] = v7;
  hkReferencedObject::addReference((hkReferencedObject *)&v7->vfptr);
  v10 = v8 + 8 * v6;
  hkReferencedObject::removeReference((hkReferencedObject *)&v4->m_contactMgrFactory[0][v10]->vfptr);
  v4->m_contactMgrFactory[0][v10] = v7;
}

// File Line: 530
// RVA: 0xCEE6D0
void __fastcall hkpCollisionDispatcher::registerContactMgrFactoryWithAll(hkpCollisionDispatcher *this, hkpContactMgrFactory *fac, int responseA)
{
  hkpContactMgrFactory *v3; // rdi
  signed __int64 v4; // rbp
  hkReferencedObject **v5; // rbx
  hkReferencedObject **v6; // rsi

  v3 = fac;
  v4 = 8i64;
  v5 = (hkReferencedObject **)((char *)this->m_contactMgrFactory + 8 * responseA);
  v6 = (hkReferencedObject **)this->m_contactMgrFactory[(signed __int64)responseA];
  do
  {
    hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
    hkReferencedObject::removeReference(*v5);
    *v5 = (hkReferencedObject *)&v3->vfptr;
    hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
    hkReferencedObject::removeReference(*v6);
    *v6 = (hkReferencedObject *)&v3->vfptr;
    ++v6;
    v5 += 8;
    --v4;
  }
  while ( v4 );
}

// File Line: 548
// RVA: 0xCEEE90
void __fastcall hkpCollisionDispatcher::getClosestPoints(hkpCollisionDispatcher *this, hkpShape *shapeA, hkTransformf *transformA, hkpShape *shapeB, hkTransformf *transformB, float collisionTolerance, hkpCdPointCollector *collector)
{
  hkpCollisionDispatcher *v7; // r14
  hkpShape *v8; // rsi
  hkTransformf *v9; // rbx
  hkpShape *v10; // rdi
  char v11; // sp
  char v12; // cl
  __int64 v13; // rcx
  __int64 v14; // rax
  void **v15; // [rsp+20h] [rbp-E0h]
  int v16; // [rsp+28h] [rbp-D8h]
  hkpShape *v17; // [rsp+30h] [rbp-D0h]
  int v18; // [rsp+38h] [rbp-C8h]
  hkTransformf *v19; // [rsp+40h] [rbp-C0h]
  __int64 v20; // [rsp+48h] [rbp-B8h]
  char v21; // [rsp+50h] [rbp-B0h]
  char v22; // [rsp+51h] [rbp-AFh]
  __int16 v23; // [rsp+52h] [rbp-AEh]
  int v24; // [rsp+54h] [rbp-ACh]
  __int16 v25; // [rsp+58h] [rbp-A8h]
  char v26; // [rsp+5Ah] [rbp-A6h]
  int v27; // [rsp+5Ch] [rbp-A4h]
  hkpCollidable::BoundingVolumeData v28; // [rsp+60h] [rbp-A0h]
  int v29; // [rsp+98h] [rbp-68h]
  hkpShape *v30; // [rsp+A0h] [rbp-60h]
  int v31; // [rsp+A8h] [rbp-58h]
  hkTransformf *v32; // [rsp+B0h] [rbp-50h]
  __int64 v33; // [rsp+B8h] [rbp-48h]
  char v34; // [rsp+C0h] [rbp-40h]
  char v35; // [rsp+C1h] [rbp-3Fh]
  __int16 v36; // [rsp+C2h] [rbp-3Eh]
  int v37; // [rsp+C4h] [rbp-3Ch]
  __int16 v38; // [rsp+C8h] [rbp-38h]
  char v39; // [rsp+CAh] [rbp-36h]
  int v40; // [rsp+CCh] [rbp-34h]
  hkpCollidable::BoundingVolumeData v41; // [rsp+D0h] [rbp-30h]
  int v42; // [rsp+108h] [rbp+8h]
  hkpCollisionFilter v43; // [rsp+110h] [rbp+10h]
  hkpCollisionDispatcher *v44; // [rsp+160h] [rbp+60h]
  int v45; // [rsp+16Ch] [rbp+6Ch]
  float v46; // [rsp+170h] [rbp+70h]
  hkpCollisionFilter *v47; // [rsp+178h] [rbp+78h]
  void ***v48; // [rsp+180h] [rbp+80h]

  v7 = this;
  v8 = shapeB;
  v9 = transformA;
  v10 = shapeA;
  hkpCollisionFilter::hkpCollisionFilter(&v43);
  v46 = collisionTolerance;
  v43.vfptr = (hkBaseObjectVtbl *)&hkpNullCollisionFilter::`vftable{for `hkReferencedObject};
  v43.vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  v43.m_type.m_storage = 1;
  v43.vfptr = (hkpShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  v43.vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  v16 = 0x1FFFF;
  v43.vfptr = (hkpRayCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  v45 = 0;
  v15 = &hkpDefaultConvexListFilter::`vftable;
  v44 = v7;
  v47 = &v43;
  v17 = v10;
  v19 = v9;
  v20 = 0i64;
  v18 = -1;
  v48 = &v15;
  v21 = 0;
  v24 = 0;
  v25 = 32512;
  v27 = 0;
  v26 = -1;
  hkpCollidable::BoundingVolumeData::BoundingVolumeData(&v28);
  v12 = v11 + 84;
  v29 = -1082130432;
  HIBYTE(v25) = v11 + 48 - v12;
  v22 = 8;
  v23 = 0;
  v30 = v8;
  v33 = 0i64;
  v32 = transformB;
  v31 = -1;
  v34 = 0;
  v37 = 0;
  v38 = 32512;
  v40 = 0;
  v39 = -1;
  hkpCollidable::BoundingVolumeData::BoundingVolumeData(&v41);
  v42 = -1082130432;
  v13 = (unsigned __int8)v8->m_type.m_storage;
  v35 = 8;
  HIBYTE(v38) = -36;
  v14 = (unsigned __int8)v10->m_type.m_storage;
  v36 = 0;
  (*((void (__fastcall **)(hkpShape **, hkpShape **, hkpCollisionDispatcher **, hkpCdPointCollector *))&v7->vfptr
   + 5 * ((unsigned __int8)v7->m_agent2Types[v14][v13] + 79i64)))(
    &v17,
    &v30,
    &v44,
    collector);
  v15 = &hkBaseObject::`vftable;
  hkpNullCollisionFilter::~hkpNullCollisionFilter((hkpNullCollisionFilter *)&v43);
}

// File Line: 568
// RVA: 0xCEF070
void __fastcall hkpCollisionDispatcher::getPenetrations(hkpCollisionDispatcher *this, hkpShape *shapeA, hkTransformf *transformA, hkpShape *shapeB, hkTransformf *transformB, float collisionTolerance, hkpCdBodyPairCollector *collector)
{
  hkpCollisionDispatcher *v7; // r14
  hkpShape *v8; // rsi
  hkTransformf *v9; // rbx
  hkpShape *v10; // rdi
  char v11; // sp
  char v12; // cl
  __int64 v13; // rcx
  __int64 v14; // rax
  void **v15; // [rsp+20h] [rbp-E0h]
  int v16; // [rsp+28h] [rbp-D8h]
  hkpShape *v17; // [rsp+30h] [rbp-D0h]
  int v18; // [rsp+38h] [rbp-C8h]
  hkTransformf *v19; // [rsp+40h] [rbp-C0h]
  __int64 v20; // [rsp+48h] [rbp-B8h]
  char v21; // [rsp+50h] [rbp-B0h]
  char v22; // [rsp+51h] [rbp-AFh]
  __int16 v23; // [rsp+52h] [rbp-AEh]
  int v24; // [rsp+54h] [rbp-ACh]
  __int16 v25; // [rsp+58h] [rbp-A8h]
  char v26; // [rsp+5Ah] [rbp-A6h]
  int v27; // [rsp+5Ch] [rbp-A4h]
  hkpCollidable::BoundingVolumeData v28; // [rsp+60h] [rbp-A0h]
  int v29; // [rsp+98h] [rbp-68h]
  hkpShape *v30; // [rsp+A0h] [rbp-60h]
  int v31; // [rsp+A8h] [rbp-58h]
  hkTransformf *v32; // [rsp+B0h] [rbp-50h]
  __int64 v33; // [rsp+B8h] [rbp-48h]
  char v34; // [rsp+C0h] [rbp-40h]
  char v35; // [rsp+C1h] [rbp-3Fh]
  __int16 v36; // [rsp+C2h] [rbp-3Eh]
  int v37; // [rsp+C4h] [rbp-3Ch]
  __int16 v38; // [rsp+C8h] [rbp-38h]
  char v39; // [rsp+CAh] [rbp-36h]
  int v40; // [rsp+CCh] [rbp-34h]
  hkpCollidable::BoundingVolumeData v41; // [rsp+D0h] [rbp-30h]
  int v42; // [rsp+108h] [rbp+8h]
  hkpCollisionFilter v43; // [rsp+110h] [rbp+10h]
  hkpCollisionDispatcher *v44; // [rsp+160h] [rbp+60h]
  int v45; // [rsp+16Ch] [rbp+6Ch]
  float v46; // [rsp+170h] [rbp+70h]
  hkpCollisionFilter *v47; // [rsp+178h] [rbp+78h]
  void ***v48; // [rsp+180h] [rbp+80h]

  v7 = this;
  v8 = shapeB;
  v9 = transformA;
  v10 = shapeA;
  hkpCollisionFilter::hkpCollisionFilter(&v43);
  v46 = collisionTolerance;
  v43.vfptr = (hkBaseObjectVtbl *)&hkpNullCollisionFilter::`vftable{for `hkReferencedObject};
  v43.vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  v43.m_type.m_storage = 1;
  v43.vfptr = (hkpShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  v43.vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  v16 = 0x1FFFF;
  v43.vfptr = (hkpRayCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  v45 = 0;
  v15 = &hkpDefaultConvexListFilter::`vftable;
  v44 = v7;
  v47 = &v43;
  v17 = v10;
  v19 = v9;
  v20 = 0i64;
  v18 = -1;
  v48 = &v15;
  v21 = 0;
  v24 = 0;
  v25 = 32512;
  v27 = 0;
  v26 = -1;
  hkpCollidable::BoundingVolumeData::BoundingVolumeData(&v28);
  v12 = v11 + 84;
  v29 = -1082130432;
  HIBYTE(v25) = v11 + 48 - v12;
  v22 = 8;
  v23 = 0;
  v30 = v8;
  v33 = 0i64;
  v32 = transformB;
  v31 = -1;
  v34 = 0;
  v37 = 0;
  v38 = 32512;
  v40 = 0;
  v39 = -1;
  hkpCollidable::BoundingVolumeData::BoundingVolumeData(&v41);
  v42 = -1082130432;
  v13 = (unsigned __int8)v8->m_type.m_storage;
  v35 = 8;
  HIBYTE(v38) = -36;
  v14 = (unsigned __int8)v10->m_type.m_storage;
  v36 = 0;
  v7->m_agent2Func[(unsigned __int8)v7->m_agent2Types[v14][v13]].m_getPenetrationsFunc(
    (hkpCdBody *)&v17,
    (hkpCdBody *)&v30,
    (hkpCollisionInput *)&v44,
    collector);
  v15 = &hkBaseObject::`vftable;
  hkpNullCollisionFilter::~hkpNullCollisionFilter((hkpNullCollisionFilter *)&v43);
}

// File Line: 588
// RVA: 0xCEDF30
void __fastcall hkpCollisionDispatcher::debugPrintTable(hkpCollisionDispatcher *this)
{
  hkpCollisionDispatcher *v1; // r13
  __int64 v2; // r14
  hkcdShapeType::ShapeTypeEnum v3; // er12
  const char *v4; // rax
  hkcdShapeType::ShapeTypeEnum v5; // esi
  char *v6; // r15
  const char *v7; // rdi
  const char *v8; // rbx
  const char *v9; // rax
  hkcdShapeType::ShapeTypeEnum v10; // ebx
  hkcdShapeType::ShapeTypeEnum v11; // er12
  __int64 v12; // r14
  const char *v13; // rax
  char *v14; // r15
  const char *v15; // rsi
  const char *v16; // rdi
  const char *v17; // rax
  char *s3; // [rsp+20h] [rbp-E0h]
  char *s3a; // [rsp+20h] [rbp-E0h]
  hkErrStream v20; // [rsp+40h] [rbp-C0h]
  hkStringBuf str; // [rsp+60h] [rbp-A0h]
  char s; // [rsp+F0h] [rbp-10h]
  char buf; // [rsp+1F0h] [rbp+F0h]

  v1 = this;
  ((void (__fastcall *)(hkError *, signed __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    1581467108i64,
    "hkpCollisionDispatcher::debugPrintTable");
  if ( v1->m_debugAgent2Table && v1->m_debugAgent2TablePred )
  {
    v2 = 0i64;
    v3 = 0;
    do
    {
      v4 = hkGetShapeTypeName(v3);
      hkStringBuf::hkStringBuf(&str, "\nEntries for (continuous)", v4, 0i64, 0i64, 0i64, 0i64);
      hkErrStream::hkErrStream(&v20, &buf, 512);
      hkOstream::operator<<((hkOstream *)&v20.vfptr, &str);
      hkError::messageReport(-1, &buf, "Dispatch\\hkpCollisionDispatcher.cpp", 601);
      hkOstream::~hkOstream((hkOstream *)&v20.vfptr);
      v5 = 0;
      do
      {
        v6 = (char *)v1->m_debugAgent2TablePred + v2;
        if ( v6[2] < 100 )
        {
          v7 = hkGetShapeTypeName(v5);
          v8 = hkGetShapeTypeName((hkcdShapeType::ShapeTypeEnum)*v6);
          v9 = hkGetShapeTypeName((hkcdShapeType::ShapeTypeEnum)v6[1]);
          LODWORD(s3) = v6[2];
          hkString::snprintf(&s, 255, "vs %30s <%i:%s-%s>", v7, s3, v8, v9);
          hkErrStream::hkErrStream(&v20, &buf, 512);
          hkOstream::operator<<((hkOstream *)&v20.vfptr, &s);
          hkError::messageReport(-1, &buf, "Dispatch\\hkpCollisionDispatcher.cpp", 616);
          hkOstream::~hkOstream((hkOstream *)&v20.vfptr);
        }
        ++v5;
        v2 += 3i64;
      }
      while ( (signed int)v5 < 35 );
      v10 = 0;
      str.m_string.m_size = 0;
      if ( str.m_string.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          str.m_string.m_data,
          str.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      ++v3;
    }
    while ( (signed int)v3 < 35 );
    v11 = 0;
    v12 = 0i64;
    do
    {
      v13 = hkGetShapeTypeName(v11);
      hkStringBuf::hkStringBuf(&str, "\nEntries for (discrete)", v13, 0i64, 0i64, 0i64, 0i64);
      hkErrStream::hkErrStream(&v20, &buf, 512);
      hkOstream::operator<<((hkOstream *)&v20.vfptr, &str);
      hkError::messageReport(-1, &buf, "Dispatch\\hkpCollisionDispatcher.cpp", 624);
      hkOstream::~hkOstream((hkOstream *)&v20.vfptr);
      do
      {
        v14 = (char *)v1->m_debugAgent2Table + v12;
        if ( v14[2] < 100 )
        {
          v15 = hkGetShapeTypeName(v10);
          v16 = hkGetShapeTypeName((hkcdShapeType::ShapeTypeEnum)*v14);
          v17 = hkGetShapeTypeName((hkcdShapeType::ShapeTypeEnum)v14[1]);
          LODWORD(s3a) = v14[2];
          hkString::snprintf(&s, 255, "vs %30s <%i:%s-%s>", v15, s3a, v16, v17);
          hkErrStream::hkErrStream(&v20, &buf, 512);
          hkOstream::operator<<((hkOstream *)&v20.vfptr, &s);
          hkError::messageReport(-1, &buf, "Dispatch\\hkpCollisionDispatcher.cpp", 639);
          hkOstream::~hkOstream((hkOstream *)&v20.vfptr);
        }
        ++v10;
        v12 += 3i64;
      }
      while ( (signed int)v10 < 35 );
      v10 = 0;
      str.m_string.m_size = 0;
      if ( str.m_string.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          str.m_string.m_data,
          str.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      ++v11;
    }
    while ( (signed int)v11 < 35 );
    ((void (*)(void))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)();
  }
}

// File Line: 647
// RVA: 0xCEE760
void __fastcall hkpCollisionDispatcher::initCollisionQualityInfo(hkpCollisionDispatcher *this, hkpCollisionDispatcher::InitCollisionQualityInfo *input)
{
  hkpCollisionDispatcher *v2; // r8
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm1_4
  unsigned __int16 v6; // ax
  __int128 v7; // xmm1
  __int128 v8; // xmm0
  __int128 v9; // xmm1
  __int128 v10; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  __int128 v14; // xmm0
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  __int128 v17; // xmm1
  __int128 v18; // xmm0
  __int128 v19; // xmm1
  __int128 v20; // xmm0
  __int128 v21; // xmm1
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  unsigned __int16 v25; // ax
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  unsigned __int16 v29; // ax
  float v30; // xmm0_4
  float v31; // xmm3_4
  float v32; // xmm0_4
  float v33; // xmm3_4
  float v34; // xmm5_4
  unsigned __int16 v35; // ax
  float v36; // xmm0_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm2_4
  float v40; // xmm0_4
  unsigned __int16 v41; // ax
  char (*v42)[10]; // rdi
  float v43; // ecx

  this->m_expectedMinPsiDeltaTime = input->m_minDeltaTime;
  v2 = this;
  this->m_expectedMaxLinearVelocity = input->m_maxLinearVelocity;
  v3 = input->m_minDeltaTime;
  v4 = input->m_minDeltaTime * input->m_gravityLength;
  this->m_collisionQualityInfo[1].m_enableToiWeldRejection.m_bool = input->m_enableToiWeldRejection.m_bool;
  this->m_collisionQualityInfo[1].m_keepContact = input->m_collisionTolerance;
  v5 = (float)(v4 * v3) * 0.5;
  this->m_collisionQualityInfo[1].m_create4dContact = input->m_collisionTolerance;
  this->m_collisionQualityInfo[1].m_manifoldTimDistance = input->m_collisionTolerance;
  if ( input->m_enableNegativeManifoldTims.m_bool )
    this->m_collisionQualityInfo[1].m_manifoldTimDistance = v5 * -2.0;
  this->m_collisionQualityInfo[1].m_createContact = input->m_collisionTolerance;
  if ( input->m_enableNegativeToleranceToCreateNon4dContacts.m_bool )
    this->m_collisionQualityInfo[1].m_createContact = v5 * -1.0;
  this->m_collisionQualityInfo[1].m_maxContraintViolation = 3.40282e38;
  this->m_collisionQualityInfo[1].m_useContinuousPhysics.m_storage = 0;
  this->m_collisionQualityInfo[1].m_useSimpleToiHandling.m_bool = 0;
  v6 = input->m_defaultConstraintPriority;
  this->m_collisionQualityInfo[1].m_minSeparation = -5.0000001e19;
  this->m_collisionQualityInfo[1].m_minExtraSeparation = -5.0000001e19;
  this->m_collisionQualityInfo[1].m_toiSeparation = -1.0e19;
  this->m_collisionQualityInfo[1].m_toiExtraSeparation = -1.0e19;
  this->m_collisionQualityInfo[1].m_minSafeDeltaTime = 1.0;
  this->m_collisionQualityInfo[1].m_constraintPriority = v6;
  this->m_collisionQualityInfo[1].m_minAbsoluteSafeDeltaTime = 1.0;
  this->m_collisionQualityInfo[1].m_minToiDeltaTime = 1.0;
  LODWORD(this->m_collisionQualityInfo[1].m_toiAccuracy) = (unsigned int)(2 * LODWORD(FLOAT_N5_0e18)) >> 1;
  v7 = *(_OWORD *)&this->m_collisionQualityInfo[1].m_useContinuousPhysics.m_storage;
  *(_OWORD *)&this->m_collisionQualityInfo[7].m_keepContact = *(_OWORD *)&this->m_collisionQualityInfo[1].m_keepContact;
  v8 = *(_OWORD *)&this->m_collisionQualityInfo[1].m_minSafeDeltaTime;
  *(_OWORD *)&this->m_collisionQualityInfo[7].m_useContinuousPhysics.m_storage = v7;
  v9 = *(_OWORD *)&this->m_collisionQualityInfo[1].m_toiAccuracy;
  *(_OWORD *)&this->m_collisionQualityInfo[7].m_minSafeDeltaTime = v8;
  *(_OWORD *)&this->m_collisionQualityInfo[2].m_keepContact = *(_OWORD *)&this->m_collisionQualityInfo[1].m_keepContact;
  v10 = *(_OWORD *)&this->m_collisionQualityInfo[1].m_minSafeDeltaTime;
  *(_OWORD *)&this->m_collisionQualityInfo[7].m_toiAccuracy = v9;
  *(_OWORD *)&this->m_collisionQualityInfo[2].m_useContinuousPhysics.m_storage = *(_OWORD *)&this->m_collisionQualityInfo[1].m_useContinuousPhysics.m_storage;
  v11 = *(_OWORD *)&this->m_collisionQualityInfo[1].m_toiAccuracy;
  *(_OWORD *)&this->m_collisionQualityInfo[2].m_minSafeDeltaTime = v10;
  v12 = *(_OWORD *)&this->m_collisionQualityInfo[1].m_keepContact;
  *(_OWORD *)&this->m_collisionQualityInfo[2].m_toiAccuracy = v11;
  v13 = *(_OWORD *)&this->m_collisionQualityInfo[1].m_useContinuousPhysics.m_storage;
  *(_OWORD *)&this->m_collisionQualityInfo[3].m_keepContact = v12;
  v14 = *(_OWORD *)&this->m_collisionQualityInfo[1].m_minSafeDeltaTime;
  *(_OWORD *)&this->m_collisionQualityInfo[3].m_useContinuousPhysics.m_storage = v13;
  v15 = *(_OWORD *)&this->m_collisionQualityInfo[1].m_toiAccuracy;
  *(_OWORD *)&this->m_collisionQualityInfo[3].m_minSafeDeltaTime = v14;
  *(_OWORD *)&this->m_collisionQualityInfo[4].m_keepContact = *(_OWORD *)&this->m_collisionQualityInfo[1].m_keepContact;
  v16 = *(_OWORD *)&this->m_collisionQualityInfo[1].m_minSafeDeltaTime;
  *(_OWORD *)&this->m_collisionQualityInfo[3].m_toiAccuracy = v15;
  *(_OWORD *)&this->m_collisionQualityInfo[4].m_useContinuousPhysics.m_storage = *(_OWORD *)&this->m_collisionQualityInfo[1].m_useContinuousPhysics.m_storage;
  v17 = *(_OWORD *)&this->m_collisionQualityInfo[1].m_toiAccuracy;
  *(_OWORD *)&this->m_collisionQualityInfo[4].m_minSafeDeltaTime = v16;
  v18 = *(_OWORD *)&this->m_collisionQualityInfo[1].m_keepContact;
  *(_OWORD *)&this->m_collisionQualityInfo[4].m_toiAccuracy = v17;
  v19 = *(_OWORD *)&this->m_collisionQualityInfo[1].m_useContinuousPhysics.m_storage;
  *(_OWORD *)&this->m_collisionQualityInfo[5].m_keepContact = v18;
  v20 = *(_OWORD *)&this->m_collisionQualityInfo[1].m_minSafeDeltaTime;
  *(_OWORD *)&this->m_collisionQualityInfo[5].m_useContinuousPhysics.m_storage = v19;
  v21 = *(_OWORD *)&this->m_collisionQualityInfo[1].m_toiAccuracy;
  *(_OWORD *)&this->m_collisionQualityInfo[5].m_minSafeDeltaTime = v20;
  *(_OWORD *)&this->m_collisionQualityInfo[5].m_toiAccuracy = v21;
  this->m_collisionQualityInfo[7].m_manifoldTimDistance = input->m_collisionTolerance;
  this->m_collisionQualityInfo[7].m_create4dContact = input->m_collisionTolerance;
  this->m_collisionQualityInfo[7].m_createContact = input->m_collisionTolerance;
  if ( input->m_wantContinuousCollisionDetection.m_bool )
  {
    this->m_collisionQualityInfo[2].m_minSeparation = -0.5;
    v22 = input->m_numToisTillAllowedPenetrationSimplifiedToi;
    this->m_collisionQualityInfo[2].m_toiSeparation = -0.25;
    v23 = -0.5 / (float)(v22 - 1.0);
    this->m_collisionQualityInfo[2].m_minExtraSeparation = v23;
    v24 = -0.34999999 / (float)(input->m_numToisTillAllowedPenetrationSimplifiedToi - 1.0);
    this->m_collisionQualityInfo[2].m_toiExtraSeparation = v24;
    this->m_collisionQualityInfo[2].m_toiAccuracy = v24 * -0.30000001;
    this->m_collisionQualityInfo[2].m_maxContraintViolation = (float)(-0.5 / (float)(v22 - 1.0)) * -1.0;
    this->m_collisionQualityInfo[2].m_minSafeDeltaTime = 5.0 / input->m_maxLinearVelocity;
    this->m_collisionQualityInfo[2].m_minAbsoluteSafeDeltaTime = 0.0049999999 / input->m_maxLinearVelocity;
    this->m_collisionQualityInfo[2].m_minToiDeltaTime = (float)(v23 * -2.0) / input->m_maxLinearVelocity;
    v25 = input->m_toiConstraintPriority;
    this->m_collisionQualityInfo[2].m_useContinuousPhysics.m_storage = 1;
    this->m_collisionQualityInfo[2].m_constraintPriority = v25;
    this->m_collisionQualityInfo[2].m_useSimpleToiHandling.m_bool = 1;
    if ( input->m_wantContinuousCollisionDetection.m_bool )
    {
      this->m_collisionQualityInfo[3].m_minSeparation = -0.5;
      v26 = input->m_numToisTillAllowedPenetrationToi;
      this->m_collisionQualityInfo[3].m_toiSeparation = -0.25;
      v27 = -0.5 / (float)(v26 - 1.0);
      this->m_collisionQualityInfo[3].m_minExtraSeparation = v27;
      v28 = -0.34999999 / (float)(input->m_numToisTillAllowedPenetrationToi - 1.0);
      this->m_collisionQualityInfo[3].m_toiExtraSeparation = v28;
      this->m_collisionQualityInfo[3].m_toiAccuracy = v28 * -0.30000001;
      this->m_collisionQualityInfo[3].m_maxContraintViolation = (float)(-0.5 / (float)(v26 - 1.0)) * -1.0;
      this->m_collisionQualityInfo[3].m_minSafeDeltaTime = 5.0 / input->m_maxLinearVelocity;
      this->m_collisionQualityInfo[3].m_minAbsoluteSafeDeltaTime = 0.0049999999 / input->m_maxLinearVelocity;
      this->m_collisionQualityInfo[3].m_minToiDeltaTime = (float)(v27 * -2.0) / input->m_maxLinearVelocity;
      v29 = input->m_toiConstraintPriority;
      this->m_collisionQualityInfo[3].m_useContinuousPhysics.m_storage = 1;
      this->m_collisionQualityInfo[3].m_constraintPriority = v29;
      if ( input->m_wantContinuousCollisionDetection.m_bool )
      {
        this->m_collisionQualityInfo[4].m_minSeparation = -0.5;
        v30 = input->m_numToisTillAllowedPenetrationToiHigher;
        this->m_collisionQualityInfo[4].m_toiSeparation = -0.25;
        v31 = -0.5 / (float)(v30 - 1.0);
        this->m_collisionQualityInfo[4].m_minExtraSeparation = v31;
        v32 = input->m_numToisTillAllowedPenetrationToiHigher;
        v33 = v31 * -1.0;
        this->m_collisionQualityInfo[4].m_maxContraintViolation = v33;
        v34 = -0.34999999 / (float)(v32 - 1.0);
        this->m_collisionQualityInfo[4].m_toiExtraSeparation = v34;
        this->m_collisionQualityInfo[4].m_toiAccuracy = v34 * -0.30000001;
        this->m_collisionQualityInfo[4].m_minSafeDeltaTime = 5.0 / input->m_maxLinearVelocity;
        this->m_collisionQualityInfo[4].m_minAbsoluteSafeDeltaTime = 0.0049999999 / input->m_maxLinearVelocity;
        this->m_collisionQualityInfo[4].m_minToiDeltaTime = v33 / input->m_maxLinearVelocity;
        v35 = input->m_toiHigherConstraintPriority;
        this->m_collisionQualityInfo[4].m_useContinuousPhysics.m_storage = 1;
        this->m_collisionQualityInfo[4].m_constraintPriority = v35;
      }
    }
  }
  this->m_collisionQualityInfo[5].m_keepContact = input->m_collisionTolerance;
  if ( input->m_wantContinuousCollisionDetection.m_bool )
  {
    this->m_collisionQualityInfo[5].m_minSeparation = -0.40000001;
    v36 = input->m_numToisTillAllowedPenetrationToiForced;
    this->m_collisionQualityInfo[5].m_toiSeparation = -0.2;
    v37 = -0.60000002 / (float)(v36 - 1.0);
    this->m_collisionQualityInfo[5].m_minExtraSeparation = v37;
    v38 = input->m_numToisTillAllowedPenetrationToiForced;
    v39 = v37 * -1.0;
    this->m_collisionQualityInfo[5].m_maxContraintViolation = v39;
    v40 = v38 - 1.0;
    this->m_collisionQualityInfo[5].m_toiExtraSeparation = -0.41999999 / v40;
    this->m_collisionQualityInfo[5].m_toiAccuracy = (float)(-0.41999999 / v40) * -0.30000001;
    this->m_collisionQualityInfo[5].m_minSafeDeltaTime = 5.0 / input->m_maxLinearVelocity;
    this->m_collisionQualityInfo[5].m_minAbsoluteSafeDeltaTime = 0.0049999999 / input->m_maxLinearVelocity;
    this->m_collisionQualityInfo[5].m_minToiDeltaTime = v39 / input->m_maxLinearVelocity;
    v41 = input->m_toiForcedConstraintPriority;
    this->m_collisionQualityInfo[5].m_useContinuousPhysics.m_storage = 1;
    this->m_collisionQualityInfo[5].m_constraintPriority = v41;
  }
  v42 = this->m_collisionQualityTable;
  *(_OWORD *)&this->m_collisionQualityInfo[6].m_keepContact = *(_OWORD *)&this->m_collisionQualityInfo[5].m_keepContact;
  *(_OWORD *)&this->m_collisionQualityInfo[6].m_useContinuousPhysics.m_storage = *(_OWORD *)&this->m_collisionQualityInfo[5].m_useContinuousPhysics.m_storage;
  *(_OWORD *)&this->m_collisionQualityInfo[6].m_minSafeDeltaTime = *(_OWORD *)&this->m_collisionQualityInfo[5].m_minSafeDeltaTime;
  *(_OWORD *)&this->m_collisionQualityInfo[6].m_toiAccuracy = *(_OWORD *)&this->m_collisionQualityInfo[5].m_toiAccuracy;
  v43 = input->m_collisionTolerance;
  v2->m_collisionQualityInfo[6].m_createContact = 0.001;
  v2->m_collisionQualityInfo[6].m_create4dContact = 0.0099999998;
  v2->m_collisionQualityInfo[6].m_manifoldTimDistance = v43;
  memset(v42, 1, 0x64ui64);
  *(_DWORD *)&v2->m_collisionQualityTable[0][0] = 33619968;
  *(_DWORD *)&v2->m_collisionQualityTable[0][8] = 774;
  *(_WORD *)&v2->m_collisionQualityTable[0][4] = 1284;
  v2->m_collisionQualityTable[0][6] = 4;
  *(_DWORD *)&v2->m_collisionQualityTable[1][8] = 16843523;
  *(_DWORD *)&v2->m_collisionQualityTable[1][2] = 50528513;
  v2->m_collisionQualityTable[1][6] = 3;
  *(_DWORD *)&v2->m_collisionQualityTable[9][0] = 16843523;
  *(_WORD *)&v2->m_collisionQualityTable[9][8] = 771;
  *(_WORD *)&v2->m_collisionQualityTable[9][4] = 771;
  v2->m_collisionQualityTable[9][6] = 3;
  *(_DWORD *)&v2->m_collisionQualityTable[2][8] = 16908545;
  *(_DWORD *)&v2->m_collisionQualityTable[2][2] = 16843009;
  v2->m_collisionQualityTable[2][6] = 3;
  *(_DWORD *)&v2->m_collisionQualityTable[3][8] = 50594049;
  *(_DWORD *)&v2->m_collisionQualityTable[3][2] = 16843009;
  v2->m_collisionQualityTable[3][6] = 3;
  *(_DWORD *)&v2->m_collisionQualityTable[4][8] = 50660099;
  *(_DWORD *)&v2->m_collisionQualityTable[4][2] = 50397441;
  v2->m_collisionQualityTable[4][6] = 3;
  *(_DWORD *)&v2->m_collisionQualityTable[5][8] = 50594563;
  *(_DWORD *)&v2->m_collisionQualityTable[5][2] = 50528513;
  v2->m_collisionQualityTable[5][6] = 3;
  *(_WORD *)&v2->m_collisionQualityTable[6][8] = 771;
  *(_DWORD *)&v2->m_collisionQualityTable[6][2] = 50529027;
  v2->m_collisionQualityTable[6][6] = 3;
  *(_DWORD *)&v2->m_collisionQualityTable[8][0] = 16843526;
  *(_WORD *)&v2->m_collisionQualityTable[8][8] = 771;
  *(_WORD *)&v2->m_collisionQualityTable[8][4] = 771;
  v2->m_collisionQualityTable[8][6] = 3;
}


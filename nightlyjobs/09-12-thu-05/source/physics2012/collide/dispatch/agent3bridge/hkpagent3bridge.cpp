// File Line: 16
// RVA: 0xD2F880
__int64 __fastcall hkAgent3Bridge::registerAgent3(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::Agent3Funcs v2; // [rsp+20h] [rbp-68h] BYREF

  *(_WORD *)&v2.m_ignoreSymmetricVersion.m_bool = 0;
  v2.m_commitPotentialFunc = hkAgent3Bridge::commitPotential;
  v2.m_createZombieFunc = hkAgent3Bridge::createZombie;
  v2.m_removePointFunc = hkAgent3Bridge::removePoint;
  v2.m_createFunc = (void *(__fastcall *)(hkpAgent3Input *, hkpAgentEntry *, void *))hkAgent3Bridge::create;
  v2.m_processFunc = (void *(__fastcall *)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *))hkAgent3Bridge::process;
  v2.m_sepNormalFunc = 0i64;
  v2.m_cleanupFunc = 0i64;
  v2.m_destroyFunc = (void (__fastcall *)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *, hkpCollisionDispatcher *))hkAgent3Bridge::destroy;
  v2.m_updateFilterFunc = (void (__fastcall *)(hkpAgentEntry *, void *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *, hkpConstraintOwner *))hkAgent3Bridge::updateFilter;
  v2.m_invalidateTimFunc = (void (__fastcall *)(hkpAgentEntry *, void *, hkpCollisionInput *))hkAgent3Bridge::invalidateTim;
  v2.m_warpTimeFunc = (void (__fastcall *)(hkpAgentEntry *, void *, float, float, hkpCollisionInput *))hkAgent3Bridge::warpTime;
  v2.m_isPredictive.m_bool = 1;
  return hkpCollisionDispatcher::registerAgent3(dispatcher, &v2, ALL_SHAPE_TYPES, ALL_SHAPE_TYPES);
}

// File Line: 36
// RVA: 0xD2F6F0
char *__fastcall hkAgent3Bridge::create(hkpAgent3Input *input, hkpAgentEntry *entry, char *agentData)
{
  hkpCdBody *m_storage; // rdi
  hkpCdBody *v4; // r11
  hkpContactMgr *v5; // r9
  __int64 v6; // r10
  hkpProcessCollisionInput *v8; // r8
  hkpCollisionDispatcher *v10; // rdx
  __int64 m_agent2TypesPred; // rcx

  entry->m_streamCommand &= 8u;
  entry->m_streamCommand |= 6u;
  m_storage = input->m_bodyA.m_storage;
  v4 = input->m_bodyB.m_storage;
  v5 = input->m_contactMgr.m_storage;
  v6 = (unsigned __int8)input->m_bodyA.m_storage->m_shape->m_type.m_storage;
  v8 = input->m_input.m_storage;
  v10 = v8->m_dispatcher.m_storage;
  m_agent2TypesPred = (__int64)v8->m_dispatcher.m_storage->m_agent2TypesPred;
  if ( !v8->m_createPredictiveAgents.m_storage )
    m_agent2TypesPred = (__int64)v10->m_agent2Types;
  *(_QWORD *)agentData = v10->m_agent2Func[*(unsigned __int8 *)((unsigned __int8)v4->m_shape->m_type.m_storage
                                                              + m_agent2TypesPred
                                                              + 35 * v6)].m_createFunc(
                           m_storage,
                           v4,
                           v8,
                           v5);
  entry->m_numContactPoints = -1;
  return agentData + 16;
}

// File Line: 46
// RVA: 0xD2F7A0
char *__fastcall hkAgent3Bridge::process(
        hkpAgent3ProcessInput *input,
        hkpAgentEntry *entry,
        char *agentData,
        hkVector4f *separatingNormalOut,
        hkpProcessCollisionOutput *result)
{
  (*(void (__fastcall **)(_QWORD, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))(**(_QWORD **)agentData + 48i64))(
    *(_QWORD *)agentData,
    input->m_bodyA.m_storage,
    input->m_bodyB.m_storage,
    input->m_input.m_storage,
    result);
  return agentData + 16;
}

// File Line: 55
// RVA: 0xD2F7E0
void __fastcall hkAgent3Bridge::destroy(
        hkpAgentEntry *entry,
        _QWORD *agentData,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner,
        hkpCollisionDispatcher *dispatcher)
{
  (*(void (__fastcall **)(_QWORD, hkpConstraintOwner *, hkpContactMgr *))(*(_QWORD *)*agentData + 56i64))(
    *agentData,
    constraintOwner,
    mgr);
}

// File Line: 61
// RVA: 0xD2F800
void __fastcall hkAgent3Bridge::updateFilter(
        hkpAgentEntry *entry,
        _QWORD *agentData,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner)
{
  (*(void (__fastcall **)(_QWORD, hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpConstraintOwner *))(*(_QWORD *)*agentData + 64i64))(
    *agentData,
    bodyA,
    bodyB,
    input,
    constraintOwner);
}

// File Line: 67
// RVA: 0xD2F840
void __fastcall hkAgent3Bridge::invalidateTim(hkpAgentEntry *entry, _QWORD *agentData, hkpCollisionInput *input)
{
  (*(void (__fastcall **)(_QWORD, hkpCollisionInput *))(*(_QWORD *)*agentData + 72i64))(*agentData, input);
}

// File Line: 73
// RVA: 0xD2F860
void __fastcall hkAgent3Bridge::warpTime(
        hkpAgentEntry *entry,
        _QWORD *agentData,
        float oldTime,
        float newTime,
        hkpCollisionInput *input)
{
  __int64 v5; // r8

  (*(void (__fastcall **)(_QWORD, _QWORD *, __int64, hkpCollisionInput *))(*(_QWORD *)*agentData + 80i64))(
    *agentData,
    agentData,
    v5,
    input);
}

// File Line: 80
// RVA: 0xD2F930
void __fastcall hkAgent3Bridge::removePoint(hkpAgentEntry *entry, _QWORD *agentData, unsigned __int16 idToRemove)
{
  (*(void (__fastcall **)(_QWORD, _QWORD))(*(_QWORD *)*agentData + 88i64))(*agentData, idToRemove);
}

// File Line: 86
// RVA: 0xD2F950
void __fastcall hkAgent3Bridge::commitPotential(hkpAgentEntry *entry, _QWORD *agentData, unsigned __int16 newId)
{
  (*(void (__fastcall **)(_QWORD, _QWORD))(*(_QWORD *)*agentData + 96i64))(*agentData, newId);
}

// File Line: 92
// RVA: 0xD2F970
void __fastcall hkAgent3Bridge::createZombie(
        hkpAgentEntry *entry,
        _QWORD *agentData,
        unsigned __int16 idTobecomeZombie)
{
  (*(void (__fastcall **)(_QWORD, _QWORD))(*(_QWORD *)*agentData + 104i64))(*agentData, idTobecomeZombie);
}


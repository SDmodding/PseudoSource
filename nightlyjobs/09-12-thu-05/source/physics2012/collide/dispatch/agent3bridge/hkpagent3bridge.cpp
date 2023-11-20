// File Line: 16
// RVA: 0xD2F880
__int64 __fastcall hkAgent3Bridge::registerAgent3(hkpCollisionDispatcher *dispatcher)
{
  signed __int64 (__fastcall *v2)(hkpAgent3Input *, hkpAgentEntry *, void *); // [rsp+20h] [rbp-68h]
  void (__fastcall *v3)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *, hkpCollisionDispatcher *); // [rsp+28h] [rbp-60h]
  __int64 v4; // [rsp+30h] [rbp-58h]
  void (__fastcall *v5)(hkpAgentEntry *, void *, unsigned __int16); // [rsp+38h] [rbp-50h]
  void (__fastcall *v6)(hkpAgentEntry *, void *, unsigned __int16); // [rsp+40h] [rbp-48h]
  void (__fastcall *v7)(hkpAgentEntry *, void *, unsigned __int16); // [rsp+48h] [rbp-40h]
  void (__fastcall *v8)(hkpAgentEntry *, void *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *, hkpConstraintOwner *); // [rsp+50h] [rbp-38h]
  void (__fastcall *v9)(hkpAgentEntry *, void *, hkpCollisionInput *); // [rsp+58h] [rbp-30h]
  void (__usercall *v10)(hkpAgentEntry *@<rcx>, void *@<rdx>, float@<xmm2>, float@<xmm3>, __int64@<r8>, hkpCollisionInput *); // [rsp+60h] [rbp-28h]
  __int64 v11; // [rsp+68h] [rbp-20h]
  signed __int64 (__fastcall *v12)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *); // [rsp+70h] [rbp-18h]
  char v13; // [rsp+78h] [rbp-10h]
  __int16 v14; // [rsp+79h] [rbp-Fh]

  v14 = 0;
  v6 = hkAgent3Bridge::commitPotential;
  v7 = hkAgent3Bridge::createZombie;
  v5 = hkAgent3Bridge::removePoint;
  v2 = hkAgent3Bridge::create;
  v12 = hkAgent3Bridge::process;
  v11 = 0i64;
  v4 = 0i64;
  v3 = hkAgent3Bridge::destroy;
  v8 = hkAgent3Bridge::updateFilter;
  v9 = hkAgent3Bridge::invalidateTim;
  v10 = hkAgent3Bridge::warpTime;
  v13 = 1;
  return hkpCollisionDispatcher::registerAgent3(
           dispatcher,
           (hkpCollisionDispatcher::Agent3Funcs *)&v2,
           ALL_SHAPE_TYPES,
           ALL_SHAPE_TYPES);
}

// File Line: 36
// RVA: 0xD2F6F0
signed __int64 __fastcall hkAgent3Bridge::create(hkpAgent3Input *input, hkpAgentEntry *entry, void *agentData)
{
  hkpCdBody *v3; // rdi
  hkpCdBody *v4; // r11
  hkpContactMgr *v5; // r9
  __int64 v6; // r10
  _QWORD *v7; // rsi
  hkpProcessCollisionInput *v8; // r8
  hkpAgentEntry *v9; // rbx
  hkpCollisionDispatcher *v10; // rdx
  signed __int64 v11; // rcx

  entry->m_streamCommand &= 8u;
  entry->m_streamCommand |= 6u;
  v3 = input->m_bodyA.m_storage;
  v4 = input->m_bodyB.m_storage;
  v5 = input->m_contactMgr.m_storage;
  v6 = (unsigned __int8)input->m_bodyA.m_storage->m_shape->m_type.m_storage;
  v7 = agentData;
  v8 = input->m_input.m_storage;
  v9 = entry;
  v10 = v8->m_dispatcher.m_storage;
  v11 = (signed __int64)v8->m_dispatcher.m_storage->m_agent2TypesPred;
  if ( !v8->m_createPredictiveAgents.m_storage )
    v11 = (signed __int64)v10->m_agent2Types;
  *v7 = v10->m_agent2Func[*(unsigned __int8 *)((unsigned __int8)v4->m_shape->m_type.m_storage + v11 + 35 * v6)].m_createFunc(
          v3,
          v4,
          (hkpCollisionInput *)&v8->m_dispatcher,
          v5);
  v9->m_numContactPoints = -1;
  return (signed __int64)(v7 + 2);
}

// File Line: 46
// RVA: 0xD2F7A0
signed __int64 __fastcall hkAgent3Bridge::process(hkpAgent3ProcessInput *input, hkpAgentEntry *entry, void *agentData, hkVector4f *separatingNormalOut, hkpProcessCollisionOutput *result)
{
  char *v5; // rbx

  v5 = (char *)agentData;
  (*(void (__fastcall **)(_QWORD, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))(**(_QWORD **)agentData + 48i64))(
    *(_QWORD *)agentData,
    input->m_bodyA.m_storage,
    input->m_bodyB.m_storage,
    input->m_input.m_storage,
    result);
  return (signed __int64)(v5 + 16);
}

// File Line: 55
// RVA: 0xD2F7E0
void __fastcall hkAgent3Bridge::destroy(hkpAgentEntry *entry, void *agentData, hkpContactMgr *mgr, hkpConstraintOwner *constraintOwner, hkpCollisionDispatcher *dispatcher)
{
  (*(void (__fastcall **)(_QWORD, hkpConstraintOwner *, hkpContactMgr *))(**(_QWORD **)agentData + 56i64))(
    *(_QWORD *)agentData,
    constraintOwner,
    mgr);
}

// File Line: 61
// RVA: 0xD2F800
void __fastcall hkAgent3Bridge::updateFilter(hkpAgentEntry *entry, void *agentData, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr, hkpConstraintOwner *constraintOwner)
{
  (*(void (__fastcall **)(_QWORD, hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpConstraintOwner *))(**(_QWORD **)agentData + 64i64))(
    *(_QWORD *)agentData,
    bodyA,
    bodyB,
    input,
    constraintOwner);
}

// File Line: 67
// RVA: 0xD2F840
void __fastcall hkAgent3Bridge::invalidateTim(hkpAgentEntry *entry, void *agentData, hkpCollisionInput *input)
{
  (*(void (__fastcall **)(_QWORD, hkpCollisionInput *))(**(_QWORD **)agentData + 72i64))(*(_QWORD *)agentData, input);
}

// File Line: 73
// RVA: 0xD2F860
void __usercall hkAgent3Bridge::warpTime(hkpAgentEntry *entry@<rcx>, void *agentData@<rdx>, float oldTime@<xmm2>, float newTime@<xmm3>, __int64 a5@<r8>, hkpCollisionInput *input)
{
  (*(void (__fastcall **)(_QWORD, void *, __int64, hkpCollisionInput *))(**(_QWORD **)agentData + 80i64))(
    *(_QWORD *)agentData,
    agentData,
    a5,
    input);
}

// File Line: 80
// RVA: 0xD2F930
void __fastcall hkAgent3Bridge::removePoint(hkpAgentEntry *entry, void *agentData, unsigned __int16 idToRemove)
{
  (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)agentData + 88i64))(*(_QWORD *)agentData, idToRemove);
}

// File Line: 86
// RVA: 0xD2F950
void __fastcall hkAgent3Bridge::commitPotential(hkpAgentEntry *entry, void *agentData, unsigned __int16 newId)
{
  (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)agentData + 96i64))(*(_QWORD *)agentData, newId);
}

// File Line: 92
// RVA: 0xD2F970
void __fastcall hkAgent3Bridge::createZombie(hkpAgentEntry *entry, void *agentData, unsigned __int16 idTobecomeZombie)
{
  (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)agentData + 104i64))(*(_QWORD *)agentData, idTobecomeZombie);
}


// File Line: 35
// RVA: 0xD40C80
void __fastcall hkListAgent3::initAgentFunc(hkpCollisionDispatcher::Agent3Funcs *f)
{
  f->m_createFunc = (void *(__fastcall *)(hkpAgent3Input *, hkpAgentEntry *, void *))hkListAgent3::create;
  f->m_processFunc = (void *(__fastcall *)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *))hkListAgent3::process;
  f->m_sepNormalFunc = 0i64;
  f->m_cleanupFunc = 0i64;
  f->m_removePointFunc = 0i64;
  f->m_commitPotentialFunc = 0i64;
  f->m_createZombieFunc = 0i64;
  f->m_updateFilterFunc = hkListAgent3::updateFilter;
  f->m_invalidateTimFunc = hkListAgent3::invalidateTim;
  f->m_warpTimeFunc = hkListAgent3::warpTime;
  f->m_destroyFunc = (void (__fastcall *)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *, hkpCollisionDispatcher *))hkListAgent3::destroy;
  f->m_isPredictive.m_bool = 1;
}

// File Line: 54
// RVA: 0xD40C20
void __fastcall hkListAgent3::registerAgent3(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::Agent3Funcs f; // [rsp+20h] [rbp-68h] BYREF

  *(_WORD *)&f.m_isPredictive.m_bool = 0;
  f.m_reusePreviousEntry.m_bool = 0;
  memset(&f.m_updateFilterFunc, 0, 32);
  hkListAgent3::initAgentFunc(&f);
  hkpCollisionDispatcher::registerAgent3(dispatcher, &f, ALL_SHAPE_TYPES, LIST);
}

// File Line: 62
// RVA: 0xD40A10
char *__fastcall hkListAgent3::create(hkpAgent3Input *input, hkpAgentEntry *entry, _DWORD *agentData)
{
  hkpAgent1nTrack *v3; // rcx

  v3 = (hkpAgent1nTrack *)(agentData + 2);
  if ( agentData != (_DWORD *)-8i64 )
  {
    agentData[5] = 0x80000000;
    v3->m_sectors.m_data = 0i64;
    agentData[4] = 0;
  }
  hkAgent1nMachine_Create(v3);
  return (char *)(agentData + 8);
}

// File Line: 79
// RVA: 0xD40C00
void __fastcall hkListAgent3::destroy(
        hkpAgentEntry *entry,
        char *agentData,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner,
        hkpCollisionDispatcher *dispatcher)
{
  hkAgent1nMachine_Destroy((hkpAgent1nTrack *)(agentData + 8), dispatcher, mgr, constraintOwner);
}

// File Line: 88
// RVA: 0xD40A50
char *__fastcall hkListAgent3::process(
        hkpAgent3ProcessInput *input,
        hkpAgentEntry *entry,
        char *agentData,
        hkVector4f *separatingNormal,
        hkpProcessCollisionOutput *output)
{
  _QWORD *Value; // r9
  _QWORD *v8; // rcx
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkpCdBody *m_storage; // rax
  hkpShapeContainer *m_shape; // rsi
  int m_userData; // ebx
  hkLifoAllocator *v14; // rax
  unsigned int *m_cur; // rdi
  int v16; // edx
  char *v17; // rcx
  int v18; // r10d
  unsigned int v19; // edx
  int v20; // r8d
  unsigned int *v21; // r9
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  signed int v26; // ebx
  hkLifoAllocator *v27; // rax
  int v28; // r8d

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v8 < Value[3] )
  {
    *v8 = "TtList3";
    v9 = __rdtsc();
    v10 = v8 + 2;
    *((_DWORD *)v10 - 2) = v9;
    Value[1] = v10;
  }
  m_storage = input->m_bodyB.m_storage;
  m_shape = (hkpShapeContainer *)m_storage->m_shape;
  m_userData = m_storage->m_shape[1].m_userData;
  v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (unsigned int *)v14->m_cur;
  v16 = (4 * m_userData + 131) & 0xFFFFFF80;
  v17 = (char *)m_cur + v16;
  if ( v16 > v14->m_slabSize || v17 > v14->m_end )
    m_cur = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v14, v16);
  else
    v14->m_cur = v17;
  v18 = 0;
  v19 = 0;
  v20 = 1;
  if ( m_userData > 0 )
  {
    v21 = m_cur;
    do
    {
      if ( v19 >= 0x100 || (v20 & *((_DWORD *)&m_shape[14].vfptr + ((unsigned __int64)v19 >> 5))) != 0 )
      {
        *v21 = v19;
        ++v18;
        ++v21;
      }
      v20 = __ROL4__(v20, 1);
      ++v19;
    }
    while ( (int)v19 < m_userData );
  }
  m_cur[v18] = -1;
  hkAgent1nMachine_Process((hkpAgent1nTrack *)(agentData + 8), input, m_shape + 4, m_cur, output);
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "Et";
    v24 = __rdtsc();
    v25 = v23 + 2;
    *((_DWORD *)v25 - 2) = v24;
    v22[1] = v25;
  }
  v26 = (4 * m_userData + 131) & 0xFFFFFF80;
  v27 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v28 = (v26 + 15) & 0xFFFFFFF0;
  if ( v26 > v27->m_slabSize || (char *)m_cur + v28 != v27->m_cur || v27->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v27, (char *)m_cur, v28);
  else
    v27->m_cur = m_cur;
  return agentData + 32;
}

// File Line: 163
// RVA: 0xD40CF0
void __fastcall hkListAgent3::updateFilter(
        hkpAgentEntry *entry,
        char *agentData,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner)
{
  hkpShapeContainer *v10; // rax
  hkpAgent1nMachine_VisitorInput vin; // [rsp+20h] [rbp-48h] BYREF

  v10 = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))bodyB->m_shape->vfptr[7].__vecDelDtor)(bodyB->m_shape);
  vin.m_input = input;
  vin.m_bodyA = bodyA;
  vin.m_contactMgr = mgr;
  vin.m_collectionBodyB = bodyB;
  vin.m_constraintOwner = constraintOwner;
  vin.m_containerShapeB = v10;
  hkAgent1nMachine_UpdateShapeCollectionFilter((hkpAgent1nTrack *)(agentData + 8), &vin);
}

// File Line: 182
// RVA: 0xD40D70
void __fastcall hkListAgent3::invalidateTim(hkpAgentEntry *entry, char *agentData, hkpCollisionInput *input)
{
  hkAgent1nMachine_InvalidateTim((hkpAgent1nTrack *)(agentData + 8), input);
}

// File Line: 189
// RVA: 0xD40D90
void __fastcall hkListAgent3::warpTime(
        hkpAgentEntry *entry,
        char *agentData,
        float oldTime,
        float newTime,
        hkpCollisionInput *input)
{
  hkAgent1nMachine_WarpTime((hkpAgent1nTrack *)(agentData + 8), oldTime, newTime, input);
}


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
  f->m_destroyFunc = hkListAgent3::destroy;
  f->m_isPredictive.m_bool = 1;
}

// File Line: 54
// RVA: 0xD40C20
void __fastcall hkListAgent3::registerAgent3(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::Agent3Funcs f; // [rsp+20h] [rbp-68h]

  v1 = dispatcher;
  *(_WORD *)&f.m_isPredictive.m_bool = 0;
  f.m_reusePreviousEntry.m_bool = 0;
  f.m_updateFilterFunc = 0i64;
  f.m_invalidateTimFunc = 0i64;
  f.m_warpTimeFunc = 0i64;
  f.m_sepNormalFunc = 0i64;
  hkListAgent3::initAgentFunc(&f);
  hkpCollisionDispatcher::registerAgent3(v1, &f, ALL_SHAPE_TYPES, LIST);
}

// File Line: 62
// RVA: 0xD40A10
signed __int64 __fastcall hkListAgent3::create(hkpAgent3Input *input, hkpAgentEntry *entry, void *agentData)
{
  hkpAgent1nTrack *v3; // rcx
  char *v4; // rbx

  v3 = (hkpAgent1nTrack *)((char *)agentData + 8);
  v4 = (char *)agentData;
  if ( agentData != (void *)-8i64 )
  {
    *((_DWORD *)agentData + 5) = 2147483648;
    v3->m_sectors.m_data = 0i64;
    *((_DWORD *)agentData + 4) = 0;
  }
  hkAgent1nMachine_Create(v3);
  return (signed __int64)(v4 + 32);
}

// File Line: 79
// RVA: 0xD40C00
void __fastcall hkListAgent3::destroy(hkpAgentEntry *entry, void *agentData, hkpContactMgr *mgr, hkpConstraintOwner *constraintOwner, hkpCollisionDispatcher *dispatcher)
{
  hkAgent1nMachine_Destroy((hkpAgent1nTrack *)((char *)agentData + 8), dispatcher, mgr, constraintOwner);
}

// File Line: 88
// RVA: 0xD40A50
signed __int64 __fastcall hkListAgent3::process(hkpAgent3ProcessInput *input, hkpAgentEntry *entry, void *agentData, hkVector4f *separatingNormal, hkpProcessCollisionOutput *output)
{
  hkpAgent3ProcessInput *v5; // r15
  char *v6; // rbp
  _QWORD *v7; // r9
  _QWORD *v8; // rcx
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkpShapeContainer **v11; // rax
  hkpShapeContainer *v12; // rsi
  signed int v13; // ebx
  hkLifoAllocator *v14; // rax
  unsigned int *v15; // rdi
  int v16; // edx
  char *v17; // rcx
  int v18; // er10
  unsigned int v19; // edx
  signed int v20; // er8
  unsigned int *v21; // r9
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  signed int v26; // ebx
  hkLifoAllocator *v27; // rax
  int v28; // er8

  v5 = input;
  v6 = (char *)agentData;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)v7[1];
  if ( (unsigned __int64)v8 < v7[3] )
  {
    *v8 = "TtList3";
    v9 = __rdtsc();
    v10 = (signed __int64)(v8 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v7[1] = v10;
  }
  v11 = (hkpShapeContainer **)v5->m_bodyB.m_storage;
  v12 = *v11;
  v13 = (signed int)(*v11)[7].vfptr;
  v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (unsigned int *)v14->m_cur;
  v16 = (4 * v13 + 131) & 0xFFFFFF80;
  v17 = (char *)v15 + v16;
  if ( v16 > v14->m_slabSize || v17 > v14->m_end )
    v15 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v14, v16);
  else
    v14->m_cur = v17;
  v18 = 0;
  v19 = 0;
  v20 = 1;
  if ( v13 > 0 )
  {
    v21 = v15;
    do
    {
      if ( v19 >= 0x100 || v20 & *((_DWORD *)&v12[14].vfptr + ((unsigned __int64)v19 >> 5)) )
      {
        *v21 = v19;
        ++v18;
        ++v21;
      }
      v20 = __ROL4__(v20, 1);
      ++v19;
    }
    while ( (signed int)v19 < v13 );
  }
  v15[v18] = -1;
  hkAgent1nMachine_Process((hkpAgent1nTrack *)(v6 + 8), v5, v12 + 4, v15, output);
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "Et";
    v24 = __rdtsc();
    v25 = (signed __int64)(v23 + 2);
    *(_DWORD *)(v25 - 8) = v24;
    v22[1] = v25;
  }
  v26 = (4 * v13 + 131) & 0xFFFFFF80;
  v27 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v28 = (v26 + 15) & 0xFFFFFFF0;
  if ( v26 > v27->m_slabSize || (char *)v15 + v28 != v27->m_cur || v27->m_firstNonLifoEnd == v15 )
    hkLifoAllocator::slowBlockFree(v27, v15, v28);
  else
    v27->m_cur = v15;
  return (signed __int64)(v6 + 32);
}

// File Line: 163
// RVA: 0xD40CF0
void __fastcall hkListAgent3::updateFilter(hkpAgentEntry *entry, void *agentData, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr, hkpConstraintOwner *constraintOwner)
{
  hkpCdBody *v7; // rdi
  hkpCdBody *v8; // rbx
  char *v9; // rsi
  hkpShapeContainer *v10; // rax
  hkpAgent1nMachine_VisitorInput vin; // [rsp+20h] [rbp-48h]

  v7 = bodyB;
  v8 = bodyA;
  v9 = (char *)agentData;
  v10 = (hkpShapeContainer *)((__int64 (*)(void))bodyB->m_shape->vfptr[7].__vecDelDtor)();
  vin.m_input = input;
  vin.m_bodyA = v8;
  vin.m_contactMgr = mgr;
  vin.m_collectionBodyB = v7;
  vin.m_constraintOwner = constraintOwner;
  vin.m_containerShapeB = v10;
  hkAgent1nMachine_UpdateShapeCollectionFilter((hkpAgent1nTrack *)(v9 + 8), &vin);
}

// File Line: 182
// RVA: 0xD40D70
void __fastcall hkListAgent3::invalidateTim(hkpAgentEntry *entry, void *agentData, hkpCollisionInput *input)
{
  hkAgent1nMachine_InvalidateTim((hkpAgent1nTrack *)((char *)agentData + 8), input);
}

// File Line: 189
// RVA: 0xD40D90
void __fastcall hkListAgent3::warpTime(hkpAgentEntry *entry, void *agentData, float oldTime, float newTime, hkpCollisionInput *input)
{
  hkAgent1nMachine_WarpTime((hkpAgent1nTrack *)((char *)agentData + 8), oldTime, newTime, input);
}


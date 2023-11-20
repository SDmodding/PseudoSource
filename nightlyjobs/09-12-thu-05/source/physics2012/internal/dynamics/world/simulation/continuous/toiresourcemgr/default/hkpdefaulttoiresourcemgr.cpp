// File Line: 20
// RVA: 0x15D2A50
void dynamic_initializer_for__hkpDefaultToiResourceMgrClass__()
{
  hkClass::hkClass(
    &hkpDefaultToiResourceMgrClass,
    "hkpDefaultToiResourceMgr",
    &hkReferencedObjectClass,
    24,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 26
// RVA: 0xDE5A60
void __fastcall hkpDefaultToiResourceMgr::hkpDefaultToiResourceMgr(hkpDefaultToiResourceMgr *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_defaultScratchpadSize = 0x20000;
  this->vfptr = (hkBaseObjectVtbl *)&hkpDefaultToiResourceMgr::`vftable;
}

// File Line: 31
// RVA: 0xDE5BF0
__int64 __fastcall hkpDefaultToiResourceMgr::getScratchpadCapacity(hkpDefaultToiResourceMgr *this)
{
  return (unsigned int)this->m_defaultScratchpadSize;
}

// File Line: 46
// RVA: 0xDE5AB0
hkResult *__fastcall hkpDefaultToiResourceMgr::beginToiAndSetupResources(hkpDefaultToiResourceMgr *this, hkResult *result, hkpToiEvent *event, hkArray<hkpToiEvent,hkContainerHeapAllocator> *otherEvents, hkpToiResources *resourcesOut)
{
  hkResult *v5; // rdi
  hkpDefaultToiResourceMgr *v6; // rsi
  int v7; // eax
  __int64 v8; // rcx
  char *v9; // rax
  int v10; // ecx
  hkBool resulta; // [rsp+20h] [rbp-18h]
  int v13; // [rsp+24h] [rbp-14h]

  v5 = result;
  v6 = this;
  if ( hkpDefaultToiResourceMgr::shouldHandleGivenToi(this, &resulta, event)->m_bool )
  {
    v7 = v6->m_defaultScratchpadSize;
    resourcesOut->m_scratchpadSize = v7;
    v6->m_scratchPadCapacity = v7;
    v8 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 13);
    v13 = v6->m_scratchPadCapacity;
    v9 = (char *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v8 + 24i64))(v8, &v13);
    v10 = v13;
    v5->m_enum = 0;
    v6->m_scratchPadCapacity = v10;
    resourcesOut->m_scratchpad = v9;
    resourcesOut->m_priorityClassMap = hkpDefaultToiResourceMgr::s_priorityClassMap;
    resourcesOut->m_numToiSolverIterations = 3;
    resourcesOut->m_priorityClassRatios = hkpDefaultToiResourceMgr::s_priorityClassRatios;
    resourcesOut->m_numForcedToiFinalSolverIterations = 4;
    resourcesOut->m_maxNumActiveEntities = 1000;
    resourcesOut->m_maxNumConstraints = 1000;
    resourcesOut->m_maxNumEntities = 1000;
    resourcesOut->m_minPriorityToProcess = 3;
  }
  else
  {
    v5->m_enum = 1;
  }
  return v5;
}

// File Line: 81
// RVA: 0xDE5BB0
void __fastcall hkpDefaultToiResourceMgr::endToiAndFreeResources(hkpDefaultToiResourceMgr *this, hkpToiEvent *event, hkArray<hkpToiEvent,hkContainerHeapAllocator> *otherEvents, hkpToiResources *resources)
{
  unsigned int v4; // ebx
  char *v5; // rdi
  _QWORD **v6; // rax

  v4 = this->m_scratchPadCapacity;
  v5 = resources->m_scratchpad;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v6[13] + 32i64))(v6[13], v5, v4);
}

// File Line: 86
// RVA: 0xDE5A90
void __fastcall hkpDefaultToiResourceMgr::~hkpDefaultToiResourceMgr(hkpDefaultToiResourceMgr *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 91
// RVA: 0xDE5C00
hkBool *__fastcall hkpDefaultToiResourceMgr::shouldHandleGivenToi(hkpDefaultToiResourceMgr *this, hkBool *result, hkpToiEvent *event)
{
  result->m_bool = 1;
  return result;
}

// File Line: 96
// RVA: 0xDE5BA0
signed __int64 __fastcall hkpDefaultToiResourceMgr::resourcesDepleted(hkpDefaultToiResourceMgr *this)
{
  return 1i64;
}

// File Line: 105
// RVA: 0xDE5B90
__int64 __fastcall hkpDefaultToiResourceMgr::cannotSolve(hkpDefaultToiResourceMgr *this, hkArray<hkpToiResourceMgr::ConstraintViolationInfo,hkContainerHeapAllocator> *violatedConstraints)
{
  return 0i64;
}


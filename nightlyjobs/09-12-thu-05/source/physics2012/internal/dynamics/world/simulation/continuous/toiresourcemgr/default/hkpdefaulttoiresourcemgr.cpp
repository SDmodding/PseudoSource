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
hkResult *__fastcall hkpDefaultToiResourceMgr::beginToiAndSetupResources(
        hkpDefaultToiResourceMgr *this,
        hkResult *result,
        hkpToiEvent *event,
        hkArray<hkpToiEvent,hkContainerHeapAllocator> *otherEvents,
        hkpToiResources *resourcesOut)
{
  int m_defaultScratchpadSize; // eax
  __int64 v8; // rcx
  char *v9; // rax
  int v10; // ecx
  hkBool resulta; // [rsp+20h] [rbp-18h] BYREF
  int v13[5]; // [rsp+24h] [rbp-14h] BYREF

  if ( hkpDefaultToiResourceMgr::shouldHandleGivenToi(this, &resulta, event)->m_bool )
  {
    m_defaultScratchpadSize = this->m_defaultScratchpadSize;
    resourcesOut->m_scratchpadSize = m_defaultScratchpadSize;
    this->m_scratchPadCapacity = m_defaultScratchpadSize;
    v8 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 13);
    v13[0] = this->m_scratchPadCapacity;
    v9 = (char *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v8 + 24i64))(v8, v13);
    v10 = v13[0];
    result->m_enum = HK_SUCCESS;
    this->m_scratchPadCapacity = v10;
    resourcesOut->m_scratchpad = v9;
    resourcesOut->m_priorityClassMap = hkpDefaultToiResourceMgr::s_priorityClassMap;
    resourcesOut->m_numToiSolverIterations = 3;
    resourcesOut->m_priorityClassRatios = hkpDefaultToiResourceMgr::s_priorityClassRatios;
    resourcesOut->m_numForcedToiFinalSolverIterations = 4;
    resourcesOut->m_maxNumActiveEntities = 1000;
    resourcesOut->m_maxNumConstraints = 1000;
    resourcesOut->m_maxNumEntities = 1000;
    resourcesOut->m_minPriorityToProcess = PRIORITY_TOI;
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 81
// RVA: 0xDE5BB0
void __fastcall hkpDefaultToiResourceMgr::endToiAndFreeResources(
        hkpDefaultToiResourceMgr *this,
        hkpToiEvent *event,
        hkArray<hkpToiEvent,hkContainerHeapAllocator> *otherEvents,
        hkpToiResources *resources)
{
  unsigned int m_scratchPadCapacity; // ebx
  char *m_scratchpad; // rdi
  _QWORD **Value; // rax

  m_scratchPadCapacity = this->m_scratchPadCapacity;
  m_scratchpad = resources->m_scratchpad;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*Value[13] + 32i64))(Value[13], m_scratchpad, m_scratchPadCapacity);
}

// File Line: 86
// RVA: 0xDE5A90
void __fastcall hkpDefaultToiResourceMgr::~hkpDefaultToiResourceMgr(hkpDefaultToiResourceMgr *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 91
// RVA: 0xDE5C00
hkBool *__fastcall hkpDefaultToiResourceMgr::shouldHandleGivenToi(
        hkpDefaultToiResourceMgr *this,
        hkBool *result,
        hkpToiEvent *event)
{
  result->m_bool = 1;
  return result;
}

// File Line: 96
// RVA: 0xDE5BA0
__int64 __fastcall hkpDefaultToiResourceMgr::resourcesDepleted(hkpDefaultToiResourceMgr *this)
{
  return 1i64;
}

// File Line: 105
// RVA: 0xDE5B90
__int64 __fastcall hkpDefaultToiResourceMgr::cannotSolve(
        hkpDefaultToiResourceMgr *this,
        hkArray<hkpToiResourceMgr::ConstraintViolationInfo,hkContainerHeapAllocator> *violatedConstraints)
{
  return 0i64;
}


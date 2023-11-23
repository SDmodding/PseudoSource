// File Line: 14
// RVA: 0xC62D60
void __fastcall hkMemorySystem::FrameInfo::FrameInfo(hkMemorySystem::FrameInfo *this, int solverBufferSize)
{
  this->m_solverBufferSize = solverBufferSize;
}

// File Line: 20
// RVA: 0xC62E30
void __fastcall hkMemorySystem::replaceInstance(hkMemorySystem *m)
{
  hkMemorySystem::s_instance = m;
}

// File Line: 25
// RVA: 0xC62E40
hkMemorySystem *__fastcall hkMemorySystem::getInstance()
{
  return hkMemorySystem::s_instance;
}

// File Line: 30
// RVA: 0xC62E50
hkMemorySystem *__fastcall hkMemorySystem::getInstancePtr()
{
  return hkMemorySystem::s_instance;
}

// File Line: 35
// RVA: 0xC62D70
void __fastcall hkMemorySystem::~hkMemorySystem(hkMemorySystem *this)
{
  this->vfptr = (hkMemorySystemVtbl *)&hkMemorySystem::`vftable;
}

// File Line: 70
// RVA: 0xC62DD0
void __fastcall hkMemorySystem::garbageCollectThread(hkMemorySystem *this, hkMemoryRouter *__formal)
{
  ;
}

// File Line: 74
// RVA: 0xC62DE0
void __fastcall hkMemorySystem::garbageCollectShared(hkMemorySystem *this)
{
  ;
}

// File Line: 78
// RVA: 0xC62DF0
void __fastcall hkMemorySystem::garbageCollect(hkMemorySystem *this)
{
  hkMemoryRouter *Value; // rax

  Value = (hkMemoryRouter *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  this->vfptr->garbageCollectThread(this, Value);
  this->vfptr->garbageCollectShared(this);
}

// File Line: 84
// RVA: 0xC62D90
hkResult *__fastcall hkMemorySystem::setHeapSoftLimit(hkMemorySystem *this, hkResult *result, int nbytes)
{
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 89
// RVA: 0xC62DA0
__int64 __fastcall hkMemorySystem::getHeapSoftLimit(hkMemorySystem *this)
{
  return 0xFFFFFFFFi64;
}

// File Line: 94
// RVA: 0xC62DB0
char __fastcall hkMemorySystem::solverCanAllocSingleBlock(hkMemorySystem *this, int numBytes)
{
  return 1;
}

// File Line: 99
// RVA: 0xC62DC0
char __fastcall hkMemorySystem::heapCanAllocTotal(hkMemorySystem *this, int numBytes)
{
  return 1;
}


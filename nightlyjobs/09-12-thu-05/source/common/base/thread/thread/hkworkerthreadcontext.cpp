// File Line: 21
// RVA: 0x15C7720
__int64 dynamic_initializer_for__hkThreadNumber__()
{
  hkThreadNumber.m_slotID = TlsAlloc();
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__hkThreadNumber__);
}

// File Line: 25
// RVA: 0xC81100
void __fastcall hkWorkerThreadContext::hkWorkerThreadContext(hkWorkerThreadContext *this, int threadId)
{
  void *v2; // rbx
  hkMemorySystem *Instance; // rax
  hkResult result; // [rsp+30h] [rbp+8h] BYREF
  int v6; // [rsp+38h] [rbp+10h]

  v2 = (void *)threadId;
  hkMemoryRouter::hkMemoryRouter(&this->m_memoryRouter);
  v6 = _mm_getcsr() | 0x8000;
  _mm_setcsr(v6);
  Instance = hkMemorySystem::getInstance();
  ((void (__fastcall *)(hkMemorySystem *, hkWorkerThreadContext *, const char *, __int64))Instance->vfptr->threadInit)(
    Instance,
    this,
    "hkWorkerThreadContext",
    3i64);
  hkBaseSystem::initThread(&result, &this->m_memoryRouter);
  TlsSetValue(hkThreadNumber.m_slotID, v2);
}

// File Line: 45
// RVA: 0xC81180
void __fastcall hkWorkerThreadContext::~hkWorkerThreadContext(hkWorkerThreadContext *this)
{
  hkMemorySystem *Instance; // rax
  hkResult result; // [rsp+30h] [rbp+8h] BYREF

  hkBaseSystem::quitThread(&result);
  Instance = hkMemorySystem::getInstance();
  ((void (__fastcall *)(hkMemorySystem *, hkWorkerThreadContext *, __int64))Instance->vfptr->threadQuit)(
    Instance,
    this,
    3i64);
  hkMemoryAllocator::~hkMemoryAllocator(&this->m_memoryRouter.m_stack);
}


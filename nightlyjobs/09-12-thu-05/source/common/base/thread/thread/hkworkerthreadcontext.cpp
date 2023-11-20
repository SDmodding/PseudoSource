// File Line: 21
// RVA: 0x15C7720
__int64 dynamic_initializer_for__hkThreadNumber__()
{
  hkThreadNumber.m_slotID = TlsAlloc();
  return atexit(dynamic_atexit_destructor_for__hkThreadNumber__);
}

// File Line: 25
// RVA: 0xC81100
void __fastcall hkWorkerThreadContext::hkWorkerThreadContext(hkWorkerThreadContext *this, int threadId)
{
  void *v2; // rbx
  hkWorkerThreadContext *v3; // rdi
  hkMemorySystem *v4; // rax
  hkResult result; // [rsp+30h] [rbp+8h]
  int v6; // [rsp+38h] [rbp+10h]

  v2 = (void *)threadId;
  v3 = this;
  hkMemoryRouter::hkMemoryRouter(&this->m_memoryRouter);
  v6 = _mm_getcsr() | 0x8000;
  _mm_setcsr(v6);
  v4 = hkMemorySystem::getInstance();
  ((void (__fastcall *)(hkMemorySystem *, hkWorkerThreadContext *, const char *, signed __int64))v4->vfptr->threadInit)(
    v4,
    v3,
    "hkWorkerThreadContext",
    3i64);
  hkBaseSystem::initThread(&result, &v3->m_memoryRouter);
  TlsSetValue(hkThreadNumber.m_slotID, v2);
}

// File Line: 45
// RVA: 0xC81180
void __fastcall hkWorkerThreadContext::~hkWorkerThreadContext(hkWorkerThreadContext *this)
{
  hkWorkerThreadContext *v1; // rbx
  hkMemorySystem *v2; // rax
  hkResult result; // [rsp+30h] [rbp+8h]

  v1 = this;
  hkBaseSystem::quitThread(&result);
  v2 = hkMemorySystem::getInstance();
  ((void (__fastcall *)(hkMemorySystem *, hkWorkerThreadContext *, signed __int64))v2->vfptr->threadQuit)(v2, v1, 3i64);
  hkMemoryAllocator::~hkMemoryAllocator((hkMemoryAllocator *)&v1->m_memoryRouter.m_stack.vfptr);
}


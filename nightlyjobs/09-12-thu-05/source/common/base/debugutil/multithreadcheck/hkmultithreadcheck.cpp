// File Line: 16
// RVA: 0x15C76B0
__int64 dynamic_initializer_for__hkMultiThreadCheck::s_stackTracer__()
{
  hkStackTracer::hkStackTracer(&hkMultiThreadCheck::s_stackTracer);
  return atexit(dynamic_atexit_destructor_for__hkMultiThreadCheck::s_stackTracer__);
}

// File Line: 22
// RVA: 0xC750D0
void __fastcall hkMultiThreadCheck::staticInit(hkMemoryAllocator *memoryAllocator)
{
  hkMemoryAllocator *v1; // rbx
  _QWORD **v2; // rax
  hkCriticalSection *v3; // rax
  _RTL_CRITICAL_SECTION *v4; // rax

  v1 = memoryAllocator;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 40i64);
  if ( v3 )
  {
    hkCriticalSection::hkCriticalSection(v3, 1000);
    hkMultiThreadCheck::m_criticalSection = v4;
  }
  else
  {
    hkMultiThreadCheck::m_criticalSection = 0i64;
  }
  s_stackTreeMemory[0] = 0i64;
  dword_1424A64E8 = 0;
  dword_1424A64EC = 2147483648;
  qword_1424A64F8 = -1i64;
  qword_1424A64F0 = (__int64)v1;
  hkMultiThreadCheck::s_stackTree = (hkStackTracer::CallTree *)s_stackTreeMemory;
}

// File Line: 32
// RVA: 0xC75170
void hkMultiThreadCheck::staticQuit(void)
{
  LPCRITICAL_SECTION v0; // rbx
  _QWORD **v1; // rax

  if ( hkMultiThreadCheck::s_stackTree )
  {
    hkStackTracer::CallTree::quit(hkMultiThreadCheck::s_stackTree);
    hkStackTracer::CallTree::~CallTree(hkMultiThreadCheck::s_stackTree);
  }
  v0 = hkMultiThreadCheck::m_criticalSection;
  if ( hkMultiThreadCheck::m_criticalSection )
  {
    DeleteCriticalSection(hkMultiThreadCheck::m_criticalSection);
    v1 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, LPCRITICAL_SECTION, signed __int64))(*v1[11] + 16i64))(v1[11], v0, 40i64);
    hkMultiThreadCheck::m_criticalSection = 0i64;
  }
}

// File Line: 47
// RVA: 0xC75440
void __fastcall _printStackTrace(const char *text, void *context)
{
  hkStringBuf *v2; // rbx
  int v3; // eax
  hkStringBuf v4; // [rsp+20h] [rbp-98h]

  v2 = (hkStringBuf *)context;
  hkStringBuf::hkStringBuf(&v4, text);
  if ( (unsigned int)hkStringBuf::indexOf(&v4, "Cannot find symbol", 0, 0x7FFFFFFF) == -1 )
  {
    v3 = hkStringBuf::lastIndexOf(&v4, "\\", 0, 0x7FFFFFFF);
    if ( v3 != -1 )
      hkStringBuf::chompStart(&v4, v3 + 1);
    hkStringBuf::operator+=(v2, v4.m_string.m_data);
  }
  v4.m_string.m_size = 0;
  if ( v4.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v4.m_string.m_data,
      v4.m_string.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 63
// RVA: 0xC751E0
void __fastcall hkMultiThreadCheck::markForReadImpl(hkMultiThreadCheck *this, hkMultiThreadCheck::ReadMode mode)
{
  hkMultiThreadCheck::ReadMode v2; // esi
  hkMultiThreadCheck *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx
  signed int v5; // eax

  v2 = mode;
  v3 = this;
  if ( (this->m_markCount & 0x8000u) == 0 )
  {
    v4 = hkMultiThreadCheck::m_criticalSection;
    if ( hkMultiThreadCheck::m_criticalSection )
    {
      EnterCriticalSection(hkMultiThreadCheck::m_criticalSection);
      if ( !((v3->m_threadId + 63) & 0xFFFFFFCF) && v3->m_threadId != -47 )
      {
        v5 = -63;
        if ( v2 == 1 )
          v5 = -31;
        v3->m_threadId = v5;
      }
      v3->m_markBitStack *= 2;
      ++v3->m_markCount;
      LeaveCriticalSection(v4);
    }
  }
}

// File Line: 116
// RVA: 0xC75260
void __fastcall hkMultiThreadCheck::markForWriteImpl(hkMultiThreadCheck *this)
{
  hkMultiThreadCheck *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  unsigned int v3; // eax
  unsigned __int16 v4; // cx
  bool v5; // zf

  v1 = this;
  if ( (this->m_markCount & 0x8000u) == 0 )
  {
    v2 = hkMultiThreadCheck::m_criticalSection;
    if ( hkMultiThreadCheck::m_criticalSection )
    {
      EnterCriticalSection(hkMultiThreadCheck::m_criticalSection);
      v3 = hkThread::getMyThreadId();
      v4 = v1->m_markBitStack;
      ++v1->m_markCount;
      v5 = v1->m_threadId == -15;
      v1->m_markBitStack = 2 * v4 | 1;
      if ( v5 )
        v1->m_threadId = v3;
      LeaveCriticalSection(v2);
    }
  }
}

// File Line: 167
// RVA: 0xC752D0
char __fastcall hkMultiThreadCheck::isMarkedForWriteImpl(hkMultiThreadCheck *this)
{
  hkMultiThreadCheck *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  bool v3; // di

  v1 = this;
  if ( (this->m_markCount & 0x8000u) != 0 )
    return 1;
  v2 = hkMultiThreadCheck::m_criticalSection;
  if ( !hkMultiThreadCheck::m_criticalSection )
    return 1;
  EnterCriticalSection(hkMultiThreadCheck::m_criticalSection);
  v3 = v1->m_threadId == (unsigned int)hkThread::getMyThreadId();
  LeaveCriticalSection(v2);
  return v3;
}

// File Line: 185
// RVA: 0xC75340
void __fastcall hkMultiThreadCheck::unmarkForReadImpl(hkMultiThreadCheck *this)
{
  hkMultiThreadCheck *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx

  v1 = this;
  if ( (this->m_markCount & 0x8000u) == 0 )
  {
    v2 = hkMultiThreadCheck::m_criticalSection;
    if ( hkMultiThreadCheck::m_criticalSection )
    {
      EnterCriticalSection(hkMultiThreadCheck::m_criticalSection);
      v1->m_markBitStack >>= 1;
      if ( !--v1->m_markCount )
        v1->m_threadId = -15;
      LeaveCriticalSection(v2);
    }
  }
}

// File Line: 209
// RVA: 0xC753B0
void __fastcall hkMultiThreadCheck::unmarkForWriteImpl(hkMultiThreadCheck *this)
{
  hkMultiThreadCheck *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx

  v1 = this;
  if ( (this->m_markCount & 0x8000u) == 0 )
  {
    v2 = hkMultiThreadCheck::m_criticalSection;
    if ( hkMultiThreadCheck::m_criticalSection )
    {
      EnterCriticalSection(hkMultiThreadCheck::m_criticalSection);
      v1->m_markBitStack >>= 1;
      if ( !--v1->m_markCount )
        v1->m_threadId = -15;
      LeaveCriticalSection(v2);
    }
  }
}

// File Line: 236
// RVA: 0xC750B0
void __fastcall hkMultiThreadCheck::accessCheck(hkMultiThreadCheck *this, hkMultiThreadCheck::AccessType type)
{
  ;
}

// File Line: 259
// RVA: 0xC750C0
void __fastcall hkMultiThreadCheck::accessCheckWithParent(hkMultiThreadCheck *parentLock, hkMultiThreadCheck::AccessType parentType, hkMultiThreadCheck *lock, hkMultiThreadCheck::AccessType type)
{
  ;
}

// File Line: 318
// RVA: 0xC75060
void __fastcall hkMultiThreadCheck::disableChecks(hkMultiThreadCheck *this)
{
  this->m_markCount |= 0x8000u;
}

// File Line: 323
// RVA: 0xC75070
void __fastcall hkMultiThreadCheck::enableChecks(hkMultiThreadCheck *this)
{
  if ( (this->m_markCount & 0x8000u) != 0 || !hkMultiThreadCheck::m_criticalSection )
  {
    this->m_threadId = -15;
    this->m_markCount = 0;
  }
}

// File Line: 333
// RVA: 0xC750A0
void __fastcall hkMultiThreadCheck::reenableChecks(hkMultiThreadCheck *this)
{
  this->m_markCount &= 0x7FFFu;
}

// File Line: 338
// RVA: 0xC75420
void hkMultiThreadCheck::globalCriticalSectionLock(void)
{
  ;
}

// File Line: 348
// RVA: 0xC75430
void hkMultiThreadCheck::globalCriticalSectionUnlock(void)
{
  ;
}


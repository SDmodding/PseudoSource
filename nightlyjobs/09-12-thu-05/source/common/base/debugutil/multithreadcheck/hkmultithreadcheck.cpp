// File Line: 16
// RVA: 0x15C76B0
__int64 dynamic_initializer_for__hkMultiThreadCheck::s_stackTracer__()
{
  hkStackTracer::hkStackTracer(&hkMultiThreadCheck::s_stackTracer);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__hkMultiThreadCheck::s_stackTracer__);
}

// File Line: 22
// RVA: 0xC750D0
void __fastcall hkMultiThreadCheck::staticInit(hkMemoryAllocator *memoryAllocator)
{
  _QWORD **Value; // rax
  hkCriticalSection *v3; // rax
  _RTL_CRITICAL_SECTION *v4; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
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
  dword_1424A64EC = 0x80000000;
  qword_1424A64F8 = -1i64;
  qword_1424A64F0 = (__int64)memoryAllocator;
  hkMultiThreadCheck::s_stackTree = (hkStackTracer::CallTree *)s_stackTreeMemory;
}

// File Line: 32
// RVA: 0xC75170
void hkMultiThreadCheck::staticQuit(void)
{
  LPCRITICAL_SECTION v0; // rbx
  _QWORD **Value; // rax

  if ( hkMultiThreadCheck::s_stackTree )
  {
    hkStackTracer::CallTree::quit(hkMultiThreadCheck::s_stackTree);
    hkStackTracer::CallTree::~CallTree(hkMultiThreadCheck::s_stackTree);
  }
  v0 = hkMultiThreadCheck::m_criticalSection;
  if ( hkMultiThreadCheck::m_criticalSection )
  {
    DeleteCriticalSection(hkMultiThreadCheck::m_criticalSection);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, LPCRITICAL_SECTION, __int64))(*Value[11] + 16i64))(Value[11], v0, 40i64);
    hkMultiThreadCheck::m_criticalSection = 0i64;
  }
}

// File Line: 47
// RVA: 0xC75440
void __fastcall _printStackTrace(const char *text, hkStringBuf *context)
{
  int v3; // eax
  hkStringBuf v4; // [rsp+20h] [rbp-98h] BYREF

  hkStringBuf::hkStringBuf(&v4, text);
  if ( (unsigned int)hkStringBuf::indexOf(&v4, "Cannot find symbol", 0, 0x7FFFFFFF) == -1 )
  {
    v3 = hkStringBuf::lastIndexOf(&v4, "\\", 0, 0x7FFFFFFF);
    if ( v3 != -1 )
      hkStringBuf::chompStart(&v4, v3 + 1);
    hkStringBuf::operator+=(context, v4.m_string.m_data);
  }
  v4.m_string.m_size = 0;
  if ( v4.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v4.m_string.m_data,
      v4.m_string.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 63
// RVA: 0xC751E0
void __fastcall hkMultiThreadCheck::markForReadImpl(hkMultiThreadCheck *this, hkMultiThreadCheck::ReadMode mode)
{
  _RTL_CRITICAL_SECTION *v4; // rbx
  unsigned int v5; // eax

  if ( (this->m_markCount & 0x8000u) == 0 )
  {
    v4 = hkMultiThreadCheck::m_criticalSection;
    if ( hkMultiThreadCheck::m_criticalSection )
    {
      EnterCriticalSection(hkMultiThreadCheck::m_criticalSection);
      if ( ((this->m_threadId + 63) & 0xFFFFFFCF) == 0 && this->m_threadId != -47 )
      {
        v5 = -63;
        if ( mode == RECURSIVE )
          v5 = -31;
        this->m_threadId = v5;
      }
      this->m_markBitStack *= 2;
      ++this->m_markCount;
      LeaveCriticalSection(v4);
    }
  }
}

// File Line: 116
// RVA: 0xC75260
void __fastcall hkMultiThreadCheck::markForWriteImpl(hkMultiThreadCheck *this)
{
  _RTL_CRITICAL_SECTION *v2; // rbx
  unsigned int MyThreadId; // eax
  unsigned __int16 m_markBitStack; // cx
  bool v5; // zf

  if ( (this->m_markCount & 0x8000u) == 0 )
  {
    v2 = hkMultiThreadCheck::m_criticalSection;
    if ( hkMultiThreadCheck::m_criticalSection )
    {
      EnterCriticalSection(hkMultiThreadCheck::m_criticalSection);
      MyThreadId = hkThread::getMyThreadId();
      m_markBitStack = this->m_markBitStack;
      ++this->m_markCount;
      v5 = this->m_threadId == -15;
      this->m_markBitStack = (2 * m_markBitStack) | 1;
      if ( v5 )
        this->m_threadId = MyThreadId;
      LeaveCriticalSection(v2);
    }
  }
}

// File Line: 167
// RVA: 0xC752D0
char __fastcall hkMultiThreadCheck::isMarkedForWriteImpl(hkMultiThreadCheck *this)
{
  _RTL_CRITICAL_SECTION *v2; // rbx
  bool v3; // di

  if ( (this->m_markCount & 0x8000u) != 0 )
    return 1;
  v2 = hkMultiThreadCheck::m_criticalSection;
  if ( !hkMultiThreadCheck::m_criticalSection )
    return 1;
  EnterCriticalSection(hkMultiThreadCheck::m_criticalSection);
  v3 = this->m_threadId == (unsigned int)hkThread::getMyThreadId();
  LeaveCriticalSection(v2);
  return v3;
}

// File Line: 185
// RVA: 0xC75340
void __fastcall hkMultiThreadCheck::unmarkForReadImpl(hkMultiThreadCheck *this)
{
  _RTL_CRITICAL_SECTION *v2; // rbx

  if ( (this->m_markCount & 0x8000u) == 0 )
  {
    v2 = hkMultiThreadCheck::m_criticalSection;
    if ( hkMultiThreadCheck::m_criticalSection )
    {
      EnterCriticalSection(hkMultiThreadCheck::m_criticalSection);
      this->m_markBitStack >>= 1;
      if ( !--this->m_markCount )
        this->m_threadId = -15;
      LeaveCriticalSection(v2);
    }
  }
}

// File Line: 209
// RVA: 0xC753B0
void __fastcall hkMultiThreadCheck::unmarkForWriteImpl(hkMultiThreadCheck *this)
{
  _RTL_CRITICAL_SECTION *v2; // rbx

  if ( (this->m_markCount & 0x8000u) == 0 )
  {
    v2 = hkMultiThreadCheck::m_criticalSection;
    if ( hkMultiThreadCheck::m_criticalSection )
    {
      EnterCriticalSection(hkMultiThreadCheck::m_criticalSection);
      this->m_markBitStack >>= 1;
      if ( !--this->m_markCount )
        this->m_threadId = -15;
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
void __fastcall hkMultiThreadCheck::accessCheckWithParent(
        hkMultiThreadCheck *parentLock,
        hkMultiThreadCheck::AccessType parentType,
        hkMultiThreadCheck *lock,
        hkMultiThreadCheck::AccessType type)
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
  this->m_markCount &= ~0x8000u;
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


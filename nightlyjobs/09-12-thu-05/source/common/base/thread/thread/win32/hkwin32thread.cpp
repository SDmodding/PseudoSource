// File Line: 19
// RVA: 0xC60C60
void __fastcall hkThread::hkThread(hkThread *this)
{
  this->m_thread = 0i64;
}

// File Line: 23
// RVA: 0xC60C80
// attributes: thunk
void __fastcall hkThread::~hkThread(hkThread *this)
{
  hkThread::joinThread(this);
}

// File Line: 28
// RVA: 0xC60D00
void __fastcall hkThread::joinThread(hkThread *this)
{
  void *m_thread; // rcx

  m_thread = this->m_thread;
  if ( m_thread )
  {
    WaitForSingleObject(m_thread, 0xFFFFFFFF);
    CloseHandle(this->m_thread);
    this->m_thread = 0i64;
  }
}

// File Line: 47
// RVA: 0xC60C90
hkResult *__fastcall hkThread::startThread(
        hkThread *this,
        hkResult *result,
        unsigned int (__fastcall *func)(void *),
        void *arg,
        const char *name,
        unsigned int stackSize)
{
  HANDLE v8; // rax
  unsigned __int64 v10; // rax

  v8 = CreateThread(0i64, (int)stackSize, func, arg, 0, &stackSize);
  this->m_thread = v8;
  if ( v8 )
  {
    v10 = stackSize;
    result->m_enum = HK_SUCCESS;
    this->m_threadId = v10;
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 88
// RVA: 0xC60D40
__int64 __fastcall hkThread::getStatus(hkThread *this)
{
  void *m_thread; // rcx
  unsigned int ExitCode; // [rsp+30h] [rbp+8h] BYREF

  m_thread = this->m_thread;
  if ( !m_thread )
    return 2i64;
  GetExitCodeThread(m_thread, &ExitCode);
  return ExitCode == 259;
}

// File Line: 104
// RVA: 0xC60DA0
unsigned __int64 __fastcall hkThread::getMyThreadId()
{
  return GetCurrentThreadId();
}

// File Line: 109
// RVA: 0xC60D80
unsigned __int64 __fastcall hkThread::getChildThreadId(hkThread *this)
{
  return this->m_threadId;
}

// File Line: 114
// RVA: 0xC60D90
void *__fastcall hkThread::getHandle(hkThread *this)
{
  return this->m_thread;
}


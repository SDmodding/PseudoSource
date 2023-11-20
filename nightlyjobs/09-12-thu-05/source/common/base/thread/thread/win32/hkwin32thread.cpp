// File Line: 19
// RVA: 0xC60C60
void __fastcall hkThread::hkThread(hkThread *this)
{
  this->m_thread = 0i64;
}

// File Line: 23
// RVA: 0xC60C80
void __fastcall hkThread::~hkThread(hkThread *this)
{
  hkThread::joinThread(this);
}

// File Line: 28
// RVA: 0xC60D00
void __fastcall hkThread::joinThread(hkThread *this)
{
  hkThread *v1; // rbx
  void *v2; // rcx

  v1 = this;
  v2 = this->m_thread;
  if ( v2 )
  {
    WaitForSingleObject(v2, 0xFFFFFFFF);
    CloseHandle(v1->m_thread);
    v1->m_thread = 0i64;
  }
}

// File Line: 47
// RVA: 0xC60C90
hkResult *__fastcall hkThread::startThread(hkThread *this, hkResult *result, void *(__fastcall *func)(void *), void *arg, const char *name, int stackSize)
{
  hkResult *v6; // rbx
  hkThread *v7; // rdi
  HANDLE v8; // rax
  unsigned __int64 v10; // rax

  v6 = result;
  v7 = this;
  v8 = CreateThread(0i64, stackSize, (LPTHREAD_START_ROUTINE)func, arg, 0, (LPDWORD)&stackSize);
  v7->m_thread = v8;
  if ( v8 )
  {
    v10 = (unsigned int)stackSize;
    v6->m_enum = 0;
    v7->m_threadId = v10;
  }
  else
  {
    v6->m_enum = 1;
  }
  return v6;
}

// File Line: 88
// RVA: 0xC60D40
signed __int64 __fastcall hkThread::getStatus(hkThread *this)
{
  void *v1; // rcx
  unsigned int ExitCode; // [rsp+30h] [rbp+8h]

  v1 = this->m_thread;
  if ( !v1 )
    return 2i64;
  GetExitCodeThread(v1, &ExitCode);
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


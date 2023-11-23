// File Line: 68
// RVA: 0xEE6BB4
void __fastcall __noreturn OSuite::Helper::Run(_BYTE *param)
{
  char v1; // bl

  v1 = param[20];
  (*(void (__fastcall **)(_BYTE *))(*(_QWORD *)param + 8i64))(param);
  if ( v1 )
    (**(void (__fastcall ***)(_BYTE *, __int64))param)(param, 1i64);
  ExitThread(0);
}

// File Line: 166
// RVA: 0xEE6AA4
void __fastcall OSuite::ZThread::ZThread(OSuite::ZThread *this, bool bAutoDestroy)
{
  this->m_thread = 0i64;
  this->m_threadID = 0;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZThread::`vftable;
  this->m_bAutoDestroy = bAutoDestroy;
  if ( bAutoDestroy )
    _InterlockedExchangeAdd(&OSuite::ZThread::s_nTotalRogueThreads, 1u);
}

// File Line: 189
// RVA: 0xEE6AD0
void __fastcall OSuite::ZThread::~ZThread(OSuite::ZThread *this)
{
  bool v1; // zf

  v1 = !this->m_bAutoDestroy;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZThread::`vftable;
  if ( !v1 )
    _InterlockedExchangeAdd(&OSuite::ZThread::s_nTotalRogueThreads, 0xFFFFFFFF);
  this->m_thread = 0i64;
}

// File Line: 205
// RVA: 0xEE6C80
void __fastcall OSuite::ZThread::Start(OSuite::ZThread *this)
{
  HANDLE Thread; // rax

  Thread = CreateThread(0i64, 0x10000ui64, (LPTHREAD_START_ROUTINE)OSuite::Helper::Run, this, 4u, &this->m_threadID);
  this->m_thread = Thread;
  if ( OSuite::ZThread::s_bUseAbsolutePriority )
    SetThreadPriority(Thread, OSuite::ZThread::s_nDefaultAbsolutePriority);
  else
    OSuite::ZThread::SetPriority(this, OSuite::ZThread::s_eDefaultPriority);
  ResumeThread(this->m_thread);
  if ( this->m_bAutoDestroy )
    CloseHandle(this->m_thread);
}

// File Line: 255
// RVA: 0xEE6B60
void __fastcall OSuite::ZThread::Join(OSuite::ZThread *this)
{
  void *m_thread; // rcx

  m_thread = this->m_thread;
  if ( m_thread )
  {
    WaitForSingleObject(m_thread, 0xFFFFFFFF);
    CloseHandle(this->m_thread);
  }
  this->m_thread = 0i64;
}

// File Line: 328
// RVA: 0xEE6BFC
void __fastcall OSuite::ZThread::SetDefaultPriority(OSuite::ZThread::EThreadPriority ePriority)
{
  OSuite::ZThread::s_bUseAbsolutePriority = 0;
  OSuite::ZThread::s_eDefaultPriority = ePriority;
}

// File Line: 365
// RVA: 0xEE6C0C
void __fastcall OSuite::ZThread::SetPriority(OSuite::ZThread *this, OSuite::ZThread::EThreadPriority ePriority)
{
  int v2; // ebx
  HANDLE CurrentThread; // rax
  int ThreadPriority; // eax

  v2 = 0;
  if ( this->m_thread )
  {
    CurrentThread = GetCurrentThread();
    ThreadPriority = GetThreadPriority(CurrentThread);
    if ( ePriority == PRI_BELOW_CALLER )
    {
      if ( ThreadPriority < 15 )
      {
        if ( ThreadPriority < 2 )
        {
          if ( ThreadPriority < 1 )
          {
            LOBYTE(v2) = ThreadPriority >= 0;
            ThreadPriority = v2 - 2;
          }
          else
          {
            ThreadPriority = 0;
          }
        }
        else
        {
          ThreadPriority = 1;
        }
      }
      else
      {
        ThreadPriority = 2;
      }
    }
    SetThreadPriority(this->m_thread, ThreadPriority);
  }
}

// File Line: 404
// RVA: 0xEE6BE4
void __fastcall OSuite::ZThread::SetAbsolutePriority(OSuite::ZThread *this, int priority)
{
  void *m_thread; // rcx

  m_thread = this->m_thread;
  if ( m_thread )
    SetThreadPriority(m_thread, priority);
}

// File Line: 444
// RVA: 0xEE6B2C
void __fastcall OSuite::ZThread::ClockSleep(int iClocks)
{
  Sleep(1000 * iClocks / 1000);
}

// File Line: 462
// RVA: 0xEE6B24
__int64 __fastcall OSuite::ZThread::AtomicAdd(volatile int *pValue, unsigned int nAdd)
{
  return (unsigned int)_InterlockedExchangeAdd(pValue, nAdd);
}

// File Line: 492
// RVA: 0xEE6B4C
unsigned __int64 __fastcall OSuite::ZThread::GetCurrentTID()
{
  return GetCurrentThreadId();
}

// File Line: 512
// RVA: 0xEE6B90
void OSuite::ZThread::JoinRogueThreads(void)
{
  while ( _InterlockedExchangeAdd(&OSuite::ZThread::s_nTotalRogueThreads, 0) )
    Sleep(0x14u);
}


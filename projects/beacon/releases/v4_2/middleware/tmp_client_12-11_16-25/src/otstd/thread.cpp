// File Line: 68
// RVA: 0xEE6BB4
void __fastcall __noreturn OSuite::Helper::Run(void *param)
{
  char v1; // bl
  void (__fastcall ***v2)(void *, signed __int64); // rdi

  v1 = *((_BYTE *)param + 20);
  v2 = (void (__fastcall ***)(void *, signed __int64))param;
  (*(void (**)(void))(*(_QWORD *)param + 8i64))();
  if ( v1 )
    (**v2)(v2, 1i64);
  ExitThread(0);
}

// File Line: 166
// RVA: 0xEE6AA4
void __fastcall OSuite::ZThread::ZThread(OSuite::ZThread *this, bool bAutoDestroy)
{
  this->m_thread = 0i64;
  this->m_threadID = 0;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZThread::`vftable';
  this->m_bAutoDestroy = bAutoDestroy;
  if ( bAutoDestroy )
    _InterlockedExchangeAdd(&OSuite::ZThread::s_nTotalRogueThreads, 1u);
}

// File Line: 189
// RVA: 0xEE6AD0
void __fastcall OSuite::ZThread::~ZThread(OSuite::ZThread *this)
{
  bool v1; // zf

  v1 = this->m_bAutoDestroy == 0;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZThread::`vftable';
  if ( !v1 )
    _InterlockedExchangeAdd(&OSuite::ZThread::s_nTotalRogueThreads, 0xFFFFFFFF);
  this->m_thread = 0i64;
}

// File Line: 205
// RVA: 0xEE6C80
void __fastcall OSuite::ZThread::Start(OSuite::ZThread *this)
{
  OSuite::ZThread *v1; // rbx
  HANDLE v2; // rax

  v1 = this;
  v2 = CreateThread(0i64, 0x10000ui64, (LPTHREAD_START_ROUTINE)OSuite::Helper::Run, this, 4u, &this->m_threadID);
  v1->m_thread = v2;
  if ( OSuite::ZThread::s_bUseAbsolutePriority )
    SetThreadPriority(v2, OSuite::ZThread::s_nDefaultAbsolutePriority);
  else
    OSuite::ZThread::SetPriority(v1, OSuite::ZThread::s_eDefaultPriority);
  ResumeThread(v1->m_thread);
  if ( v1->m_bAutoDestroy )
    CloseHandle(v1->m_thread);
}

// File Line: 255
// RVA: 0xEE6B60
void __fastcall OSuite::ZThread::Join(OSuite::ZThread *this)
{
  OSuite::ZThread *v1; // rbx
  void *v2; // rcx

  v1 = this;
  v2 = this->m_thread;
  if ( v2 )
  {
    WaitForSingleObject(v2, 0xFFFFFFFF);
    CloseHandle(v1->m_thread);
  }
  v1->m_thread = 0i64;
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
  OSuite::ZThread::EThreadPriority v3; // esi
  OSuite::ZThread *v4; // rdi
  HANDLE v5; // rax
  int v6; // eax

  v2 = 0;
  v3 = ePriority;
  v4 = this;
  if ( this->m_thread )
  {
    v5 = GetCurrentThread();
    v6 = GetThreadPriority(v5);
    if ( v3 == 1 )
    {
      if ( v6 < 15 )
      {
        if ( v6 < 2 )
        {
          if ( v6 < 1 )
          {
            LOBYTE(v2) = v6 >= 0;
            v6 = v2 - 2;
          }
          else
          {
            v6 = 0;
          }
        }
        else
        {
          v6 = 1;
        }
      }
      else
      {
        v6 = 2;
      }
    }
    SetThreadPriority(v4->m_thread, v6);
  }
}

// File Line: 404
// RVA: 0xEE6BE4
void __fastcall OSuite::ZThread::SetAbsolutePriority(OSuite::ZThread *this, int priority)
{
  void *v2; // rcx

  v2 = this->m_thread;
  if ( v2 )
    SetThreadPriority(v2, priority);
}

// File Line: 444
// RVA: 0xEE6B2C
void __fastcall OSuite::ZThread::ClockSleep(int iClocks)
{
  unsigned int v1; // edx

  v1 = (signed int)((unsigned __int64)(274877907000i64 * iClocks) >> 32) >> 6;
  Sleep(v1 + (v1 >> 31));
}

// File Line: 462
// RVA: 0xEE6B24
__int64 __fastcall OSuite::ZThread::AtomicAdd(volatile int *pValue, int nAdd)
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


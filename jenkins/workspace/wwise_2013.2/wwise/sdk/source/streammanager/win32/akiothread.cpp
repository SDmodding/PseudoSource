// File Line: 32
// RVA: 0xAA8060
void __fastcall AK::StreamMgr::CAkClientThreadAware::CAkClientThreadAware(AK::StreamMgr::CAkClientThreadAware *this)
{
  this->m_hBlockEvent = 0i64;
  this->m_bIsBlocked = 0;
  this->vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkClientThreadAware::`vftable';
}

// File Line: 36
// RVA: 0xAA80D0
void __fastcall AK::StreamMgr::CAkClientThreadAware::~CAkClientThreadAware(AK::StreamMgr::CAkClientThreadAware *this)
{
  AK::StreamMgr::CAkClientThreadAware *v1; // rbx
  void *v2; // rcx

  v1 = this;
  this->vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkClientThreadAware::`vftable';
  v2 = this->m_hBlockEvent;
  if ( v2 )
  {
    CloseHandle(v2);
    v1->m_hBlockEvent = 0i64;
  }
}

// File Line: 46
// RVA: 0xAA8560
void __fastcall AK::StreamMgr::CAkClientThreadAware::SetBlockedStatus(AK::StreamMgr::CAkClientThreadAware *this)
{
  AK::StreamMgr::CAkClientThreadAware *v1; // rbx
  void *v2; // rcx
  HANDLE v3; // rax

  v1 = this;
  v2 = this->m_hBlockEvent;
  if ( v2 )
  {
    ResetEvent(v2);
    v1->m_bIsBlocked = 1;
  }
  else
  {
    v3 = CreateEventW(0i64, 1, 0, 0i64);
    v1->m_bIsBlocked = 1;
    v1->m_hBlockEvent = v3;
  }
}

// File Line: 93
// RVA: 0xAA8080
void __fastcall AK::StreamMgr::CAkIOThread::CAkIOThread(AK::StreamMgr::CAkIOThread *this)
{
  AK::StreamMgr::CAkIOThread *v1; // rbx

  v1 = this;
  this->vfptr = (AK::StreamMgr::CAkIOThreadVtbl *)&AK::StreamMgr::CAkIOThread::`vftable';
  this->m_hIOThread = 0i64;
  InitializeCriticalSection(&this->m_lockSems.m_csLock);
  v1->m_hIOThreadStopEvent = 0i64;
  v1->m_hMaxIOGate = 0i64;
  v1->m_hStdSem = 0i64;
  v1->m_hAutoSem = 0i64;
  *(_QWORD *)&v1->m_cPendingStdStms = 0i64;
  v1->m_bDoWaitMemoryChange = 0;
  v1->m_uNumConcurrentIO = 0;
}

// File Line: 97
// RVA: 0xAA8100
void __fastcall AK::StreamMgr::CAkIOThread::~CAkIOThread(AK::StreamMgr::CAkIOThread *this)
{
  _RTL_CRITICAL_SECTION *v1; // rcx

  v1 = &this->m_lockSems.m_csLock;
  v1[-1].OwningThread = &AK::StreamMgr::CAkIOThread::`vftable';
  DeleteCriticalSection(v1);
}

// File Line: 104
// RVA: 0xAA8400
signed __int64 __fastcall AK::StreamMgr::CAkIOThread::Init(AK::StreamMgr::CAkIOThread *this, AkThreadProperties *in_threadProperties)
{
  AkThreadProperties *v2; // rdi
  AK::StreamMgr::CAkIOThread *v3; // rbx
  HANDLE v4; // rax
  unsigned int v5; // eax
  signed __int64 result; // rax
  unsigned int ThreadId; // [rsp+40h] [rbp+8h]

  v2 = in_threadProperties;
  v3 = this;
  this->m_hStdSem = CreateEventW(0i64, 1, 0, 0i64);
  v3->m_hAutoSem = CreateEventW(0i64, 1, 0, 0i64);
  v3->m_hIOThreadStopEvent = CreateEventW(0i64, 1, 0, 0i64);
  v3->m_hMaxIOGate = CreateEventW(0i64, 1, 1, 0i64);
  *(_QWORD *)&v3->m_cPendingStdStms = 0i64;
  v3->m_uNumConcurrentIO = 0;
  v4 = CreateThread(
         0i64,
         v2->uStackSize,
         (LPTHREAD_START_ROUTINE)AK::StreamMgr::CAkIOThread::IOSchedThread,
         v3,
         0,
         &ThreadId);
  v3->m_hIOThread = v4;
  if ( !v4 )
    goto LABEL_6;
  AKPLATFORM::AkSetThreadName(ThreadId, "AK::IOThread");
  if ( !SetThreadPriority(v3->m_hIOThread, v2->nPriority)
    || (v5 = v2->dwAffinityMask) != 0 && !SetThreadAffinityMask(v3->m_hIOThread, v5) )
  {
    CloseHandle(v3->m_hIOThread);
LABEL_6:
    v3->m_hIOThread = 0i64;
  }
  if ( !v3->m_hIOThread || !v3->m_hIOThreadStopEvent || !v3->m_hStdSem || (result = 1i64, !v3->m_hAutoSem) )
    result = 2i64;
  return result;
}

// File Line: 161
// RVA: 0xAA8640
void __fastcall AK::StreamMgr::CAkIOThread::Term(AK::StreamMgr::CAkIOThread *this)
{
  AK::StreamMgr::CAkIOThread *v1; // rbx
  void *v2; // rcx
  void *v3; // rcx
  void *v4; // rcx
  void *v5; // rcx
  void *v6; // rcx
  void *v7; // rcx

  v1 = this;
  v2 = this->m_hIOThreadStopEvent;
  if ( v2 )
  {
    SetEvent(v2);
    v3 = v1->m_hIOThread;
    if ( v3 )
    {
      WaitForSingleObject(v3, 0xFFFFFFFF);
      CloseHandle(v1->m_hIOThread);
      v1->m_hIOThread = 0i64;
    }
    CloseHandle(v1->m_hIOThreadStopEvent);
    v1->m_hIOThreadStopEvent = 0i64;
  }
  v4 = v1->m_hIOThread;
  if ( v4 )
  {
    CloseHandle(v4);
    v1->m_hIOThread = 0i64;
  }
  v5 = v1->m_hStdSem;
  if ( v5 )
  {
    CloseHandle(v5);
    v1->m_hStdSem = 0i64;
  }
  v6 = v1->m_hAutoSem;
  v1->m_cPendingStdStms = 0;
  if ( v6 )
  {
    CloseHandle(v6);
    v1->m_hAutoSem = 0i64;
  }
  v7 = v1->m_hMaxIOGate;
  v1->m_cRunningAutoStms = 0;
  if ( v7 )
  {
    CloseHandle(v7);
    v1->m_hMaxIOGate = 0i64;
  }
}

// File Line: 216
// RVA: 0xAA8290
signed __int64 __fastcall AK::StreamMgr::CAkIOThread::IOSchedThread(void *lpParameter)
{
  void *v1; // rdx
  char *v2; // rsi
  __int64 v3; // rax
  __int64 v4; // rax
  DWORD v5; // eax
  bool v6; // bl
  HANDLE Handles; // [rsp+30h] [rbp-38h]
  __int64 v9; // [rsp+38h] [rbp-30h]
  HANDLE v10; // [rsp+40h] [rbp-28h]
  __int64 v11; // [rsp+48h] [rbp-20h]
  __int64 v12; // [rsp+50h] [rbp-18h]

  v1 = (void *)*((_QWORD *)lpParameter + 8);
  v2 = (char *)lpParameter;
  v11 = *((_QWORD *)lpParameter + 10);
  v3 = *((_QWORD *)lpParameter + 11);
  v10 = v1;
  v12 = v3;
  v4 = *((_QWORD *)lpParameter + 9);
  Handles = v1;
  v9 = v4;
  (*(void (**)(void))(*(_QWORD *)lpParameter + 24i64))();
  while ( 1 )
  {
    while ( WaitForMultipleObjectsEx(2u, &Handles, 0, 0xFFFFFFFF, 1) )
    {
      v5 = WaitForMultipleObjectsEx(3u, &v10, 0, 0xFFFFFFFF, 1);
      if ( !v5 )
        break;
      if ( v5 <= 2 )
        goto LABEL_7;
      if ( v5 != 192 )
      {
        if ( v5 != 258 )
          return 1i64;
LABEL_7:
        EnterCriticalSection((LPCRITICAL_SECTION)(v2 + 24));
        v6 = *((_DWORD *)v2 + 27) < *((_DWORD *)v2 + 2);
        LeaveCriticalSection((LPCRITICAL_SECTION)(v2 + 24));
        if ( v6 )
          (*(void (__fastcall **)(char *))(*(_QWORD *)v2 + 8i64))(v2);
      }
    }
    if ( (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v2 + 16i64))(v2) )
      return 0i64;
    SleepEx(0x64u, 1);
  }
}

// File Line: 301
// RVA: 0xAA8600
void __fastcall AK::StreamMgr::CAkIOThread::StdSemIncr(AK::StreamMgr::CAkIOThread *this)
{
  AK::StreamMgr::CAkIOThread *v1; // rdi

  v1 = this;
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  if ( ++v1->m_cPendingStdStms == 1 )
    SetEvent(v1->m_hStdSem);
  LeaveCriticalSection(&v1->m_lockSems.m_csLock);
}

// File Line: 311
// RVA: 0xAA85C0
void __fastcall AK::StreamMgr::CAkIOThread::StdSemDecr(AK::StreamMgr::CAkIOThread *this)
{
  AK::StreamMgr::CAkIOThread *v1; // rdi
  bool v2; // zf

  v1 = this;
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  v2 = v1->m_cPendingStdStms-- == 1;
  if ( v2 )
    ResetEvent(v1->m_hStdSem);
  LeaveCriticalSection(&v1->m_lockSems.m_csLock);
}

// File Line: 322
// RVA: 0xAA81F0
void __fastcall AK::StreamMgr::CAkIOThread::AutoSemIncr(AK::StreamMgr::CAkIOThread *this)
{
  AK::StreamMgr::CAkIOThread *v1; // rdi

  v1 = this;
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  if ( ++v1->m_cRunningAutoStms == 1 && !v1->m_bDoWaitMemoryChange )
    SetEvent(v1->m_hAutoSem);
  LeaveCriticalSection(&v1->m_lockSems.m_csLock);
}

// File Line: 339
// RVA: 0xAA81B0
void __fastcall AK::StreamMgr::CAkIOThread::AutoSemDecr(AK::StreamMgr::CAkIOThread *this)
{
  AK::StreamMgr::CAkIOThread *v1; // rdi
  bool v2; // zf

  v1 = this;
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  v2 = v1->m_cRunningAutoStms-- == 1;
  if ( v2 )
    ResetEvent(v1->m_hAutoSem);
  LeaveCriticalSection(&v1->m_lockSems.m_csLock);
}

// File Line: 358
// RVA: 0xAA8520
void __fastcall AK::StreamMgr::CAkIOThread::NotifyMemChange(AK::StreamMgr::CAkIOThread *this)
{
  bool v1; // zf
  bool v2; // sf

  if ( this->m_bDoWaitMemoryChange )
  {
    v1 = this->m_cRunningAutoStms == 0;
    v2 = this->m_cRunningAutoStms < 0;
    this->m_bDoWaitMemoryChange = 0;
    if ( !v2 && !v1 )
      SetEvent(this->m_hAutoSem);
  }
}

// File Line: 379
// RVA: 0xAA8540
void __fastcall AK::StreamMgr::CAkIOThread::NotifyMemIdle(AK::StreamMgr::CAkIOThread *this)
{
  bool v1; // zf
  bool v2; // sf

  v1 = this->m_cRunningAutoStms == 0;
  v2 = this->m_cRunningAutoStms < 0;
  this->m_bDoWaitMemoryChange = 1;
  if ( !v2 && !v1 )
    ResetEvent(this->m_hAutoSem);
}

// File Line: 394
// RVA: 0xAA83B0
void __fastcall AK::StreamMgr::CAkIOThread::IncrementIOCount(AK::StreamMgr::CAkIOThread *this)
{
  AK::StreamMgr::CAkIOThread *v1; // rdi

  v1 = this;
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  if ( ++v1->m_uNumConcurrentIO >= v1->m_uMaxConcurrentIO )
    ResetEvent(v1->m_hMaxIOGate);
  LeaveCriticalSection(&v1->m_lockSems.m_csLock);
}

// File Line: 402
// RVA: 0xAA8240
void __fastcall AK::StreamMgr::CAkIOThread::DecrementIOCount(AK::StreamMgr::CAkIOThread *this)
{
  AK::StreamMgr::CAkIOThread *v1; // rdi
  unsigned int v2; // eax

  v1 = this;
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  v2 = v1->m_uMaxConcurrentIO;
  if ( --v1->m_uNumConcurrentIO == v2 - 1 )
    SetEvent(v1->m_hMaxIOGate);
  LeaveCriticalSection(&v1->m_lockSems.m_csLock);
}

// File Line: 415
// RVA: 0xAA86F0
void __fastcall AK::StreamMgr::CAkIOThread::WaitForIOCompletion(AK::StreamMgr::CAkIOThread *this, AK::StreamMgr::CAkClientThreadAware *in_pWaitingTask)
{
  WaitForSingleObject(in_pWaitingTask->m_hBlockEvent, 0xFFFFFFFF);
}

// File Line: 430
// RVA: 0xAA85B0
void __fastcall AK::StreamMgr::CAkIOThread::SignalIOCompleted(AK::StreamMgr::CAkIOThread *this, AK::StreamMgr::CAkClientThreadAware *in_pWaitingTask)
{
  void *v2; // rcx

  v2 = in_pWaitingTask->m_hBlockEvent;
  in_pWaitingTask->m_bIsBlocked = 0;
  SetEvent(v2);
}


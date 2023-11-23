// File Line: 32
// RVA: 0xAA8060
void __fastcall AK::StreamMgr::CAkClientThreadAware::CAkClientThreadAware(AK::StreamMgr::CAkClientThreadAware *this)
{
  this->m_hBlockEvent = 0i64;
  this->m_bIsBlocked = 0;
  this->vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkClientThreadAware::`vftable;
}

// File Line: 36
// RVA: 0xAA80D0
void __fastcall AK::StreamMgr::CAkClientThreadAware::~CAkClientThreadAware(AK::StreamMgr::CAkClientThreadAware *this)
{
  void *m_hBlockEvent; // rcx

  this->vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkClientThreadAware::`vftable;
  m_hBlockEvent = this->m_hBlockEvent;
  if ( m_hBlockEvent )
  {
    CloseHandle(m_hBlockEvent);
    this->m_hBlockEvent = 0i64;
  }
}

// File Line: 46
// RVA: 0xAA8560
void __fastcall AK::StreamMgr::CAkClientThreadAware::SetBlockedStatus(AK::StreamMgr::CAkClientThreadAware *this)
{
  void *m_hBlockEvent; // rcx
  HANDLE EventW; // rax

  m_hBlockEvent = this->m_hBlockEvent;
  if ( m_hBlockEvent )
  {
    ResetEvent(m_hBlockEvent);
    this->m_bIsBlocked = 1;
  }
  else
  {
    EventW = CreateEventW(0i64, 1, 0, 0i64);
    this->m_bIsBlocked = 1;
    this->m_hBlockEvent = EventW;
  }
}

// File Line: 93
// RVA: 0xAA8080
void __fastcall AK::StreamMgr::CAkIOThread::CAkIOThread(AK::StreamMgr::CAkIOThread *this)
{
  this->vfptr = (AK::StreamMgr::CAkIOThreadVtbl *)&AK::StreamMgr::CAkIOThread::`vftable;
  this->m_hIOThread = 0i64;
  InitializeCriticalSection(&this->m_lockSems.m_csLock);
  this->m_hIOThreadStopEvent = 0i64;
  this->m_hMaxIOGate = 0i64;
  this->m_hStdSem = 0i64;
  this->m_hAutoSem = 0i64;
  *(_QWORD *)&this->m_cPendingStdStms = 0i64;
  this->m_bDoWaitMemoryChange = 0;
  this->m_uNumConcurrentIO = 0;
}

// File Line: 97
// RVA: 0xAA8100
void __fastcall AK::StreamMgr::CAkIOThread::~CAkIOThread(AK::StreamMgr::CAkIOThread *this)
{
  CAkLock *p_m_lockSems; // rcx

  p_m_lockSems = &this->m_lockSems;
  p_m_lockSems[-1].m_csLock.OwningThread = &AK::StreamMgr::CAkIOThread::`vftable;
  DeleteCriticalSection(&p_m_lockSems->m_csLock);
}

// File Line: 104
// RVA: 0xAA8400
__int64 __fastcall AK::StreamMgr::CAkIOThread::Init(
        AK::StreamMgr::CAkIOThread *this,
        AkThreadProperties *in_threadProperties)
{
  HANDLE v4; // rax
  unsigned int dwAffinityMask; // eax
  __int64 result; // rax
  unsigned int ThreadId; // [rsp+40h] [rbp+8h] BYREF

  this->m_hStdSem = CreateEventW(0i64, 1, 0, 0i64);
  this->m_hAutoSem = CreateEventW(0i64, 1, 0, 0i64);
  this->m_hIOThreadStopEvent = CreateEventW(0i64, 1, 0, 0i64);
  this->m_hMaxIOGate = CreateEventW(0i64, 1, 1, 0i64);
  *(_QWORD *)&this->m_cPendingStdStms = 0i64;
  this->m_uNumConcurrentIO = 0;
  v4 = CreateThread(
         0i64,
         in_threadProperties->uStackSize,
         (LPTHREAD_START_ROUTINE)AK::StreamMgr::CAkIOThread::IOSchedThread,
         this,
         0,
         &ThreadId);
  this->m_hIOThread = v4;
  if ( !v4 )
    goto LABEL_6;
  AKPLATFORM::AkSetThreadName(ThreadId, "AK::IOThread");
  if ( !SetThreadPriority(this->m_hIOThread, in_threadProperties->nPriority)
    || (dwAffinityMask = in_threadProperties->dwAffinityMask) != 0
    && !SetThreadAffinityMask(this->m_hIOThread, dwAffinityMask) )
  {
    CloseHandle(this->m_hIOThread);
LABEL_6:
    this->m_hIOThread = 0i64;
  }
  if ( !this->m_hIOThread )
    return 2i64;
  if ( !this->m_hIOThreadStopEvent )
    return 2i64;
  if ( !this->m_hStdSem )
    return 2i64;
  result = 1i64;
  if ( !this->m_hAutoSem )
    return 2i64;
  return result;
}

// File Line: 161
// RVA: 0xAA8640
void __fastcall AK::StreamMgr::CAkIOThread::Term(AK::StreamMgr::CAkIOThread *this)
{
  void *m_hIOThreadStopEvent; // rcx
  void *m_hIOThread; // rcx
  void *v4; // rcx
  void *m_hStdSem; // rcx
  void *m_hAutoSem; // rcx
  void *m_hMaxIOGate; // rcx

  m_hIOThreadStopEvent = this->m_hIOThreadStopEvent;
  if ( m_hIOThreadStopEvent )
  {
    SetEvent(m_hIOThreadStopEvent);
    m_hIOThread = this->m_hIOThread;
    if ( m_hIOThread )
    {
      WaitForSingleObject(m_hIOThread, 0xFFFFFFFF);
      CloseHandle(this->m_hIOThread);
      this->m_hIOThread = 0i64;
    }
    CloseHandle(this->m_hIOThreadStopEvent);
    this->m_hIOThreadStopEvent = 0i64;
  }
  v4 = this->m_hIOThread;
  if ( v4 )
  {
    CloseHandle(v4);
    this->m_hIOThread = 0i64;
  }
  m_hStdSem = this->m_hStdSem;
  if ( m_hStdSem )
  {
    CloseHandle(m_hStdSem);
    this->m_hStdSem = 0i64;
  }
  m_hAutoSem = this->m_hAutoSem;
  this->m_cPendingStdStms = 0;
  if ( m_hAutoSem )
  {
    CloseHandle(m_hAutoSem);
    this->m_hAutoSem = 0i64;
  }
  m_hMaxIOGate = this->m_hMaxIOGate;
  this->m_cRunningAutoStms = 0;
  if ( m_hMaxIOGate )
  {
    CloseHandle(m_hMaxIOGate);
    this->m_hMaxIOGate = 0i64;
  }
}

// File Line: 216
// RVA: 0xAA8290
__int64 __fastcall AK::StreamMgr::CAkIOThread::IOSchedThread(char *lpParameter)
{
  void *v1; // rdx
  void *v3; // rax
  void *v4; // rax
  DWORD v5; // eax
  bool v6; // bl
  HANDLE Handles[2]; // [rsp+30h] [rbp-38h] BYREF
  HANDLE v9[5]; // [rsp+40h] [rbp-28h] BYREF

  v1 = (void *)*((_QWORD *)lpParameter + 8);
  v9[1] = *((HANDLE *)lpParameter + 10);
  v3 = (void *)*((_QWORD *)lpParameter + 11);
  v9[0] = v1;
  v9[2] = v3;
  v4 = (void *)*((_QWORD *)lpParameter + 9);
  Handles[0] = v1;
  Handles[1] = v4;
  (*(void (__fastcall **)(char *))(*(_QWORD *)lpParameter + 24i64))(lpParameter);
  while ( 1 )
  {
    while ( WaitForMultipleObjectsEx(2u, Handles, 0, 0xFFFFFFFF, 1) )
    {
      v5 = WaitForMultipleObjectsEx(3u, v9, 0, 0xFFFFFFFF, 1);
      if ( !v5 )
        break;
      if ( v5 <= 2 )
        goto LABEL_7;
      if ( v5 != 192 )
      {
        if ( v5 != 258 )
          return 1i64;
LABEL_7:
        EnterCriticalSection((LPCRITICAL_SECTION)(lpParameter + 24));
        v6 = *((_DWORD *)lpParameter + 27) < *((_DWORD *)lpParameter + 2);
        LeaveCriticalSection((LPCRITICAL_SECTION)(lpParameter + 24));
        if ( v6 )
          (*(void (__fastcall **)(char *))(*(_QWORD *)lpParameter + 8i64))(lpParameter);
      }
    }
    if ( (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)lpParameter + 16i64))(lpParameter) )
      return 0i64;
    SleepEx(0x64u, 1);
  }
}

// File Line: 301
// RVA: 0xAA8600
void __fastcall AK::StreamMgr::CAkIOThread::StdSemIncr(AK::StreamMgr::CAkIOThread *this)
{
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  if ( ++this->m_cPendingStdStms == 1 )
    SetEvent(this->m_hStdSem);
  LeaveCriticalSection(&this->m_lockSems.m_csLock);
}

// File Line: 311
// RVA: 0xAA85C0
void __fastcall AK::StreamMgr::CAkIOThread::StdSemDecr(AK::StreamMgr::CAkIOThread *this)
{
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  if ( this->m_cPendingStdStms-- == 1 )
    ResetEvent(this->m_hStdSem);
  LeaveCriticalSection(&this->m_lockSems.m_csLock);
}

// File Line: 322
// RVA: 0xAA81F0
void __fastcall AK::StreamMgr::CAkIOThread::AutoSemIncr(AK::StreamMgr::CAkIOThread *this)
{
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  if ( ++this->m_cRunningAutoStms == 1 && !this->m_bDoWaitMemoryChange )
    SetEvent(this->m_hAutoSem);
  LeaveCriticalSection(&this->m_lockSems.m_csLock);
}

// File Line: 339
// RVA: 0xAA81B0
void __fastcall AK::StreamMgr::CAkIOThread::AutoSemDecr(AK::StreamMgr::CAkIOThread *this)
{
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  if ( this->m_cRunningAutoStms-- == 1 )
    ResetEvent(this->m_hAutoSem);
  LeaveCriticalSection(&this->m_lockSems.m_csLock);
}

// File Line: 358
// RVA: 0xAA8520
void __fastcall AK::StreamMgr::CAkIOThread::NotifyMemChange(AK::StreamMgr::CAkIOThread *this)
{
  bool v1; // cc

  if ( this->m_bDoWaitMemoryChange )
  {
    v1 = this->m_cRunningAutoStms <= 0;
    this->m_bDoWaitMemoryChange = 0;
    if ( !v1 )
      SetEvent(this->m_hAutoSem);
  }
}

// File Line: 379
// RVA: 0xAA8540
void __fastcall AK::StreamMgr::CAkIOThread::NotifyMemIdle(AK::StreamMgr::CAkIOThread *this)
{
  bool v1; // cc

  v1 = this->m_cRunningAutoStms <= 0;
  this->m_bDoWaitMemoryChange = 1;
  if ( !v1 )
    ResetEvent(this->m_hAutoSem);
}

// File Line: 394
// RVA: 0xAA83B0
void __fastcall AK::StreamMgr::CAkIOThread::IncrementIOCount(AK::StreamMgr::CAkIOThread *this)
{
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  if ( ++this->m_uNumConcurrentIO >= this->m_uMaxConcurrentIO )
    ResetEvent(this->m_hMaxIOGate);
  LeaveCriticalSection(&this->m_lockSems.m_csLock);
}

// File Line: 402
// RVA: 0xAA8240
void __fastcall AK::StreamMgr::CAkIOThread::DecrementIOCount(AK::StreamMgr::CAkIOThread *this)
{
  unsigned int m_uMaxConcurrentIO; // eax

  EnterCriticalSection(&this->m_lockSems.m_csLock);
  m_uMaxConcurrentIO = this->m_uMaxConcurrentIO;
  if ( --this->m_uNumConcurrentIO == m_uMaxConcurrentIO - 1 )
    SetEvent(this->m_hMaxIOGate);
  LeaveCriticalSection(&this->m_lockSems.m_csLock);
}

// File Line: 415
// RVA: 0xAA86F0
void __fastcall AK::StreamMgr::CAkIOThread::WaitForIOCompletion(
        AK::StreamMgr::CAkIOThread *this,
        AK::StreamMgr::CAkClientThreadAware *in_pWaitingTask)
{
  WaitForSingleObject(in_pWaitingTask->m_hBlockEvent, 0xFFFFFFFF);
}

// File Line: 430
// RVA: 0xAA85B0
void __fastcall AK::StreamMgr::CAkIOThread::SignalIOCompleted(
        AK::StreamMgr::CAkIOThread *this,
        AK::StreamMgr::CAkClientThreadAware *in_pWaitingTask)
{
  void *m_hBlockEvent; // rcx

  m_hBlockEvent = in_pWaitingTask->m_hBlockEvent;
  in_pWaitingTask->m_bIsBlocked = 0;
  SetEvent(m_hBlockEvent);
}


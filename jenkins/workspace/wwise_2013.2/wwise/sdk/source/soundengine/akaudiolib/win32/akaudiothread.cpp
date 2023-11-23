// File Line: 35
// RVA: 0xA76D30
void __fastcall CAkAudioThread::CAkAudioThread(CAkAudioThread *this)
{
  HANDLE v1; // rax

  v1 = CAkLEngine::m_eventProcess;
  this->m_bStopThread = 0;
  this->m_eventProcess = v1;
}

// File Line: 39
// RVA: 0xA76F20
void __fastcall CAkAudioThread::WakeupEventsConsumer(CAkAudioThread *this)
{
  void *m_eventProcess; // rcx

  m_eventProcess = this->m_eventProcess;
  if ( m_eventProcess )
    SetEvent(m_eventProcess);
}

// File Line: 49
// RVA: 0xA76D50
__int64 __fastcall CAkAudioThread::EventMgrThreadFunc(HANDLE *lpParameter)
{
  unsigned int v2; // eax
  bool v3; // di
  DWORD v4; // eax
  DWORD v5; // eax

  CAkAudioThread::m_hEventMgrThreadID = GetCurrentThreadId();
  v2 = time64(0i64);
  srand(v2);
  v3 = 0;
  if ( !CAkLEngine::m_bCoInitializeSucceeded )
    v3 = CoInitializeEx(0i64, 2u) >= 0;
  CAkLEngine::StartVoice();
  v4 = 258;
  do
  {
    if ( !v4 || v4 == 258 )
      CAkAudioMgr::Perform(g_pAudioMgr);
    v5 = g_pAkSink->vfptr->GetThreadWaitTime(g_pAkSink);
    v4 = WaitForSingleObject(*lpParameter, v5);
  }
  while ( !*((_BYTE *)lpParameter + 8) );
  if ( v3 )
    CoUninitialize();
  return 0i64;
}

// File Line: 99
// RVA: 0xA76DF0
__int64 __fastcall CAkAudioThread::Start(CAkAudioThread *this)
{
  unsigned int ThreadId; // [rsp+40h] [rbp+8h] BYREF

  this->m_bStopThread = 0;
  CAkAudioThread::m_hEventMgrThread = CreateThread(
                                        0i64,
                                        g_PDSettings.threadLEngine.uStackSize,
                                        (LPTHREAD_START_ROUTINE)CAkAudioThread::EventMgrThreadFunc,
                                        this,
                                        0,
                                        &ThreadId);
  if ( !CAkAudioThread::m_hEventMgrThread )
    goto LABEL_4;
  AKPLATFORM::AkSetThreadName(ThreadId, "AK::EventManager");
  if ( !SetThreadPriority(CAkAudioThread::m_hEventMgrThread, g_PDSettings.threadLEngine.nPriority)
    || g_PDSettings.threadLEngine.dwAffinityMask
    && !SetThreadAffinityMask(CAkAudioThread::m_hEventMgrThread, g_PDSettings.threadLEngine.dwAffinityMask) )
  {
    CloseHandle(CAkAudioThread::m_hEventMgrThread);
LABEL_4:
    CAkAudioThread::m_hEventMgrThread = 0i64;
    return 2i64;
  }
  if ( CAkAudioThread::m_hEventMgrThread )
    return 1i64;
  else
    return 2i64;
}

// File Line: 115
// RVA: 0xA76EC0
void __fastcall CAkAudioThread::Stop(CAkAudioThread *this)
{
  HANDLE v2; // rcx

  this->m_bStopThread = 1;
  v2 = CAkAudioThread::m_hEventMgrThread;
  if ( CAkAudioThread::m_hEventMgrThread )
  {
    if ( this->m_eventProcess )
    {
      SetEvent(this->m_eventProcess);
      v2 = CAkAudioThread::m_hEventMgrThread;
    }
    WaitForSingleObject(v2, 0xFFFFFFFF);
    CloseHandle(CAkAudioThread::m_hEventMgrThread);
    CAkAudioThread::m_hEventMgrThread = 0i64;
  }
}


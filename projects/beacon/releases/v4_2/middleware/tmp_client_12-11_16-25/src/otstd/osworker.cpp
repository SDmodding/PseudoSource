// File Line: 37
// RVA: 0xEE9BB0
void __fastcall OSuite::ZWorker::ZWorker(OSuite::ZWorker *this)
{
  OSuite::ZThread::ZThread(this, 0);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWorker::`vftable;
  OSuite::ZEvent::ZEvent(&this->m_wakeUpSignal, 0);
  OSuite::ZMutex::ZMutex(&this->m_mutex);
  OSuite::ZCallbackManager::ZCallbackManager(&this->m_CallbackManager);
  this->m_deltaTimeUs = 60000;
  this->m_nLastGameTime = 0;
  this->m_tid = 0i64;
  this->m_eRunning = WORKER_INIT;
  this->m_bCallbacksOwnership = 0;
}

// File Line: 41
// RVA: 0xEE9C18
void __fastcall OSuite::ZWorker::~ZWorker(OSuite::ZWorker *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWorker::`vftable;
  OSuite::ZCallbackManager::~ZCallbackManager(&this->m_CallbackManager);
  OSuite::ZMutex::~ZMutex(&this->m_mutex);
  OSuite::ZEvent::~ZEvent(&this->m_wakeUpSignal);
  OSuite::ZThread::~ZThread(this);
}

// File Line: 45
// RVA: 0xEE9CF0
OSuite::ZWorker *__fastcall OSuite::ZWorker::Instance()
{
  OSuite::ZWorker *result; // rax
  OSuite::ZWorker *v1; // rbx
  OSuite::ZWorker *v2; // rax
  OSuite::ZWorker *v3; // rax

  result = OSuite::ZWorker::_instance;
  v1 = 0i64;
  if ( !OSuite::ZWorker::_instance )
  {
    v2 = (OSuite::ZWorker *)OSuite::ZObject::operator new(0x98ui64);
    if ( v2 )
    {
      v2->m_thread = 0i64;
      v2->m_wakeUpSignal.m_event = 0i64;
      v2->m_mutex.m_pInternalMutex = 0i64;
      v2->m_CallbackManager.m_callbacksList.m_pHead = 0i64;
      v2->m_CallbackManager.m_Mutex.m_pInternalMutex = 0i64;
      OSuite::ZWorker::ZWorker(v2);
      v1 = v3;
      OSuite::ZWorker::_instance = v3;
    }
    else
    {
      OSuite::ZWorker::_instance = 0i64;
    }
    return v1;
  }
  return result;
}

// File Line: 55
// RVA: 0xEE9CD0
void OSuite::ZWorker::FreeInstance(void)
{
  if ( OSuite::ZWorker::_instance )
    OSuite::ZWorker::_instance->vfptr->__vecDelDtor(OSuite::ZWorker::_instance, 1i64);
}

// File Line: 61
// RVA: 0xEE9C90
void __fastcall OSuite::ZWorker::CallCallbacks(OSuite::ZWorker *this)
{
  OSuite::ZOnlineSuite *v2; // rax
  OSuite::IGameConfig *GameConfig; // rax

  if ( this->m_eRunning )
  {
    v2 = OSuite::ZOnlineSuite::Instance();
    GameConfig = OSuite::ZOnlineSuite::GetGameConfig(v2);
    this->m_nLastGameTime = GameConfig->vfptr->GameTime(GameConfig);
    OSuite::ZCallbackManager::Update(&this->m_CallbackManager);
  }
}

// File Line: 74
// RVA: 0xEE9C84
void __fastcall OSuite::ZWorker::AddCallback(OSuite::ZWorker *this, OSuite::ManagedCallback *callback)
{
  OSuite::ZCallbackManager::AddCallback(&this->m_CallbackManager, callback);
}

// File Line: 80
// RVA: 0xEE9D4C
void __fastcall OSuite::ZWorker::Run(OSuite::ZWorker *this)
{
  unsigned __int64 CurrentTID; // rax
  bool v3; // di
  bool v4; // di
  bool v5; // di
  OSuite::ZUsageTrackingManager *v6; // rax
  OSuite *v7; // rcx
  OSuite::psock *v8; // rcx
  OSuite::ZGameInterface *v9; // rax

  CurrentTID = OSuite::ZThread::GetCurrentTID();
  this->m_eRunning = WORKER_RUNNING;
  this->m_tid = CurrentTID;
  do
  {
    OSuite::ZEvent::Wait(&this->m_wakeUpSignal, this->m_deltaTimeUs);
    OSuite::ZMutex::Lock(&this->m_mutex);
    v3 = this->m_eRunning == WORKER_RUNNING;
    OSuite::ZMutex::Unlock(&this->m_mutex);
    if ( !v3 )
      break;
    OSuite::ZWorker::Update(this);
    OSuite::ZMutex::Lock(&this->m_mutex);
    v4 = this->m_eRunning == WORKER_RUNNING;
    OSuite::ZMutex::Unlock(&this->m_mutex);
    if ( !v4 )
      break;
    if ( this->m_bCallbacksOwnership )
      OSuite::ZWorker::CallCallbacks(this);
    OSuite::ZMutex::Lock(&this->m_mutex);
    v5 = this->m_eRunning == WORKER_RUNNING;
    OSuite::ZMutex::Unlock(&this->m_mutex);
  }
  while ( v5 );
  OSuite::ZThread::JoinRogueThreads();
  v6 = OSuite::TSingleton<OSuite::ZUsageTrackingManager>::Object();
  OSuite::ZUsageTrackingManager::DumpUsageStatistics(v6);
  OSuite::FDeleteSingletons(v7);
  OSuite::psock::shutdown(v8);
  v9 = OSuite::GameInterface();
  OSuite::ZGameInterface::Shutdown(v9);
}

// File Line: 114
// RVA: 0xEE9E48
void __fastcall OSuite::ZWorker::Stop(OSuite::ZWorker *this)
{
  this->m_eRunning = WORKER_STOP;
}

// File Line: 130
// RVA: 0xEE9E54
void __fastcall OSuite::ZWorker::Update(OSuite::ZWorker *this)
{
  OSuite::ZMutex *p_m_mutex; // rbx
  bool v3; // di
  OSuite::ZHttpManager *v4; // rax
  OSuite::ZObject *v5; // rdx
  bool v6; // di
  OSuite::ZSocketManager *v7; // rax
  bool v8; // di
  OSuite::AuthenticationManager *v9; // rax
  bool v10; // di
  OSuite::IConsumablesManager *ConsumableManager; // rax
  bool v12; // di
  bool v13; // di
  OSuite::ZGameInterface *v14; // rax
  bool v15; // di
  OSuite::ZUsageTrackingManager *v16; // rax

  p_m_mutex = &this->m_mutex;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v3 = this->m_eRunning == WORKER_RUNNING;
  OSuite::ZMutex::Unlock(p_m_mutex);
  if ( v3 )
  {
    v4 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpRequestManager::Update(v4->m_httpRequestManager, v5);
    OSuite::ZMutex::Lock(p_m_mutex);
    v6 = this->m_eRunning == WORKER_RUNNING;
    OSuite::ZMutex::Unlock(p_m_mutex);
    if ( v6 )
    {
      v7 = OSuite::TSingleton<OSuite::ZSocketManager>::Object();
      OSuite::ZSocketManager::Update(v7);
      OSuite::ZMutex::Lock(p_m_mutex);
      v8 = this->m_eRunning == WORKER_RUNNING;
      OSuite::ZMutex::Unlock(p_m_mutex);
      if ( v8 )
      {
        v9 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
        OSuite::AuthenticationManager::Update(v9);
        OSuite::ZMutex::Lock(p_m_mutex);
        v10 = this->m_eRunning == WORKER_RUNNING;
        OSuite::ZMutex::Unlock(p_m_mutex);
        if ( v10 )
        {
          ConsumableManager = OSuite::IConsumablesManager::GetConsumableManager();
          ConsumableManager->vfptr->Update(ConsumableManager);
          OSuite::ZMutex::Lock(p_m_mutex);
          v12 = this->m_eRunning == WORKER_RUNNING;
          OSuite::ZMutex::Unlock(p_m_mutex);
          if ( v12 )
          {
            OSuite::ZMetricAppender::Update();
            OSuite::ZMutex::Lock(p_m_mutex);
            v13 = this->m_eRunning == WORKER_RUNNING;
            OSuite::ZMutex::Unlock(p_m_mutex);
            if ( v13 )
            {
              v14 = OSuite::GameInterface();
              OSuite::ZGameInterface::Update(v14);
              OSuite::ZMutex::Lock(p_m_mutex);
              v15 = this->m_eRunning == WORKER_RUNNING;
              OSuite::ZMutex::Unlock(p_m_mutex);
              if ( v15 )
              {
                v16 = OSuite::TSingleton<OSuite::ZUsageTrackingManager>::Object();
                OSuite::ZUsageTrackingManager::Update(v16);
              }
            }
          }
        }
      }
    }
  }
}


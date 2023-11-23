// File Line: 45
// RVA: 0xEDFAE8
void __fastcall OSuite::ZHttpRequestBase::Execute(
        OSuite::ZHttpRequestBase *this,
        OSuite::IHttpRequest::AsynchCallback *asynchCallback)
{
  bool v4; // zf
  OSuite::ZHttpManager *v5; // rax

  ((void (__fastcall *)(OSuite::ZHttpRequestBase *))this->vfptr[8].__vecDelDtor)(this);
  this->m_OnStartedCB = asynchCallback->m_OnStarted;
  this->m_OnDataAvailableCB = asynchCallback->m_OnDataAvailable;
  this->m_OnDataNeededCB = asynchCallback->m_OnDataNeeded;
  this->m_OnFinishedCB = asynchCallback->m_OnFinished;
  v4 = this->m_nLengthToSend == 0;
  this->m_bClientCallback = asynchCallback->m_bClientCallback;
  if ( !v4 )
    this->m_bufferChain.vfptr->Size(&this->m_bufferChain.OSuite::IReader);
  v5 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::ZHttpRequestManager::ExecuteRequest(v5->m_httpRequestManager, (OSuite::ManagedCallback *)this);
}

// File Line: 65
// RVA: 0xEDF9AC
char __fastcall OSuite::ZHttpRequestBase::Busy(OSuite::ZHttpRequestBase *this)
{
  char v1; // bl

  v1 = 0;
  if ( this->m_asynchState && !this->vfptr[17].__vecDelDtor(this, 3072i64) )
    return 1;
  return v1;
}

// File Line: 71
// RVA: 0xEDFBEC
char __fastcall OSuite::ZHttpRequestBase::Ready(OSuite::ZHttpRequestBase *this)
{
  char v1; // bl

  v1 = 0;
  if ( this->m_asynchState == ASYNCHSTATE_NONE
    || this->vfptr[17].__vecDelDtor(this, 1024i64) && !this->vfptr[17].__vecDelDtor(this, 2048i64) )
  {
    return 1;
  }
  return v1;
}

// File Line: 77
// RVA: 0xEDF9DC
bool __fastcall OSuite::ZHttpRequestBase::CheckAsynchState(OSuite::ZHttpRequestBase *this, int comparedStates)
{
  OSuite::ZMutex *p_m_StateMutex; // rbx
  OSuite::ZHttpRequestBase *v3; // rdi

  p_m_StateMutex = &this->m_StateMutex;
  v3 = this;
  OSuite::ZMutex::Lock(&this->m_StateMutex);
  LOBYTE(v3) = (comparedStates & v3->m_asynchState) > 0;
  OSuite::ZMutex::Unlock(p_m_StateMutex);
  return (char)v3;
}

// File Line: 87
// RVA: 0xEDFA2C
void __fastcall OSuite::ZHttpRequestBase::ClearClientData(OSuite::ZHttpRequestBase *this)
{
  OSuite::ZString that; // [rsp+20h] [rbp-28h] BYREF

  this->m_nLengthToSend = 0i64;
  OSuite::ZString::ZString(&that, &customCaption);
  OSuite::ZString::operator=(&this->m_method, &that);
  OSuite::ZString::~ZString(&that);
  OSuite::ZRedBlackTreeBase::Clear(&this->m_headers);
  OSuite::ZRedBlackTreeBase::Clear(&this->m_clientHeaders);
  OSuite::ZString::ZString(&that, &customCaption);
  OSuite::ZString::operator=(&this->m_acceptType, &that);
  OSuite::ZString::~ZString(&that);
  OSuite::ZString::ZString(&that, &customCaption);
  OSuite::ZString::operator=(&this->m_contentType, &that);
  OSuite::ZString::~ZString(&that);
  this->m_bTransferChunked = 0;
}

// File Line: 98
// RVA: 0xEDFB78
char __fastcall OSuite::ZHttpRequestBase::HandleDataCompleted(OSuite::ZHttpRequestBase *this)
{
  char v2; // bl
  char result; // al
  __int64 v4; // rdi
  __int64 v5; // rax

  v2 = 0;
  if ( ((unsigned __int8 (__fastcall *)(OSuite::ZHttpRequestBase *))this->vfptr[18].__vecDelDtor)(this) )
    return 1;
  v4 = ((__int64 (__fastcall *)(OSuite::ZHttpRequestBase *))this->vfptr[33].__vecDelDtor)(this);
  result = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 88i64))(v4);
  if ( result )
  {
    v5 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 64i64))(v4);
    if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v5 + 80i64))(v5)
      || (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v4 + 104i64))(v4) )
    {
      return 1;
    }
    return v2;
  }
  return result;
}

// File Line: 110
// RVA: 0xEDFC3C
void __fastcall OSuite::ZHttpRequestBase::SetAsynchState(
        OSuite::ZHttpRequestBase *this,
        OSuite::IHttpRequest::AsynchState state)
{
  OSuite::ZMutex *p_m_StateMutex; // rbx

  p_m_StateMutex = &this->m_StateMutex;
  OSuite::ZMutex::Lock(&this->m_StateMutex);
  if ( !this->vfptr[17].__vecDelDtor(this, 2048i64) )
    this->m_asynchState = state;
  OSuite::ZMutex::Unlock(p_m_StateMutex);
}

// File Line: 135
// RVA: 0xEDF2B0
void __fastcall OSuite::ZHttpRequestBase::ZHttpRequestBase(
        OSuite::ZHttpRequestBase *this,
        OSuite::ZUrl *url,
        void *pParent,
        int nTimeOut)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpRequestBase::`vftable;
  this->m_OnStartedCB.m_Closure.m_pthis = 0i64;
  this->m_OnStartedCB.m_Closure.m_pFunction = 0i64;
  this->m_OnDataAvailableCB.m_Closure.m_pthis = 0i64;
  this->m_OnDataAvailableCB.m_Closure.m_pFunction = 0i64;
  this->m_OnDataNeededCB.m_Closure.m_pthis = 0i64;
  this->m_OnDataNeededCB.m_Closure.m_pFunction = 0i64;
  this->m_OnFinishedCB.m_Closure.m_pthis = 0i64;
  this->m_OnFinishedCB.m_Closure.m_pFunction = 0i64;
  OSuite::ZUrl::ZUrl(&this->m_url, url);
  this->m_pParent = pParent;
  this->m_nHttpOperationTimeout = nTimeOut;
  OSuite::ZMutex::ZMutex(&this->m_StateMutex);
  this->m_pLinkedObject = 0i64;
  this->m_asynchState = ASYNCHSTATE_NONE;
  *(_WORD *)&this->m_bClientCallback = 0;
  this->m_bRecordUsage = 1;
  this->m_nLengthToSend = 0i64;
  this->m_nMaxBytesPerSecond = 0i64;
  OSuite::ZMemoryBufferChain::ZMemoryBufferChain(&this->m_bufferChain, 1);
  OSuite::ZString::ZString(&this->m_method);
  OSuite::ZString::ZString(&this->m_acceptType);
  OSuite::ZString::ZString(&this->m_contentType);
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(&this->m_headers);
  this->m_headers.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_headers.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::ZObject};
  this->m_headers.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(&this->m_clientHeaders);
  this->m_clientHeaders.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::ZObject};
  this->m_clientHeaders.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_clientHeaders.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable;
  this->m_lastError = HTTPERROR_OK;
}

// File Line: 139
// RVA: 0xEDFC94
void __fastcall OSuite::ZHttpRequestBase::SetLastError(OSuite::ZHttpRequestBase *this, __int32 error)
{
  OSuite::ZError *v3; // rbx
  OSuite::ZError::EError v4; // eax

  this->m_lastError = error;
  v3 = OSuite::TSingleton<OSuite::ZError>::Object();
  v4 = (unsigned int)OSuite::ZHttp::HttpToOsError(error);
  OSuite::ZError::SetThreadLastError(v3, v4, 1);
}

// File Line: 145
// RVA: 0xEDF3EC
void __fastcall OSuite::ZHttpRequestBase::BuildHeaders(OSuite::ZHttpRequestBase *this)
{
  OSuite::ZString *v2; // rax
  OSuite::ZOnlineSuite *v3; // rax
  OSuite::IGameConfig *GameConfig; // rax
  const char *v5; // rax
  OSuite::ZOnlineSuite *v6; // rax
  OSuite::IGameConfig *v7; // rax
  const char *v8; // rax
  OSuite::ZOnlineSuite *v9; // rax
  OSuite::IGameConfig *v10; // rax
  const char *v11; // rax
  OSuite::ZHttpManager *v12; // rax
  OSuite::ZOnlineSuite *v13; // rax
  OSuite::IGameConfig *v14; // rax
  const char *v15; // rax
  OSuite::AuthenticationManager *v16; // rax
  int AuthenticationProvider; // eax
  OSuite::ZString *v18; // rax
  OSuite::AuthenticationManager *v19; // rax
  unsigned int TicketSize; // eax
  OSuite::ZString *v21; // rax
  OSuite::AuthenticationManager *v22; // rax
  OSuite::ZString *TicketData; // rax
  OSuite::AuthenticationManager *v24; // rax
  OSuite::ZString *TicketOwner; // rax
  OSuite::ZString value; // [rsp+20h] [rbp-C8h] BYREF
  OSuite::ZString key; // [rsp+38h] [rbp-B0h] BYREF
  void **v28; // [rsp+50h] [rbp-98h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase other; // [rsp+58h] [rbp-90h] BYREF
  OSuite::ZRedBlackTreeBase::ZIteratorBase v30; // [rsp+B8h] [rbp-30h] BYREF

  v30.m_pList = 0i64;
  v30.m_pElement = 0i64;
  v30.m_parents.m_pList = 0i64;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&other, &this->m_clientHeaders);
  other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  other.m_parents.m_staticList[4] = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
  other.m_parents.m_pList = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v30, &other);
  v30.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  other.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v28 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  other.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( other.m_parents.m_staticList[2] )
    other.m_parents.m_staticList[2]->vfptr->__vecDelDtor(other.m_parents.m_staticList[2], 1u);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v30) )
  {
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      &this->m_headers,
      (OSuite::ZString *)&v30.m_pElement[1].m_pLeft,
      (OSuite::ZString *)&v30.m_pElement[2]);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v30);
  }
  OSuite::ZString::ZString(&value, "max-age=0");
  OSuite::ZString::ZString(&key, "Cache-Control");
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &this->m_headers,
    &key,
    &value);
  OSuite::ZString::~ZString(&key);
  OSuite::ZString::~ZString(&value);
  if ( OSuite::ZString::operator bool(&this->m_contentType) )
  {
    OSuite::ZString::ZString(&value, "Content-Type");
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      &this->m_headers,
      &value,
      &this->m_contentType);
    OSuite::ZString::~ZString(&value);
  }
  if ( this->m_nLengthToSend )
  {
    OSuite::ZString::ZString(&value, "Content-Length");
    OSuite::ZString::ZString(&key, this->m_nLengthToSend);
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      &this->m_headers,
      &value,
      v2);
    OSuite::ZString::~ZString(&key);
    OSuite::ZString::~ZString(&value);
  }
  if ( this->m_bTransferChunked )
  {
    OSuite::ZString::ZString(&key, "chunked");
    OSuite::ZString::ZString(&value, "Transfer-Encoding");
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      &this->m_headers,
      &value,
      &key);
    OSuite::ZString::~ZString(&value);
    OSuite::ZString::~ZString(&key);
  }
  v3 = OSuite::ZOnlineSuite::Instance();
  GameConfig = OSuite::ZOnlineSuite::GetGameConfig(v3);
  v5 = (const char *)GameConfig->vfptr->BuildId(GameConfig);
  OSuite::ZString::ZString(&key, v5);
  OSuite::ZString::ZString(&value, "OS-BuildID");
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &this->m_headers,
    &value,
    &key);
  OSuite::ZString::~ZString(&value);
  OSuite::ZString::~ZString(&key);
  v6 = OSuite::ZOnlineSuite::Instance();
  v7 = OSuite::ZOnlineSuite::GetGameConfig(v6);
  v8 = (const char *)(*((__int64 (__fastcall **)(OSuite::IGameConfig *))&v7->vfptr->BuildId + 1))(v7);
  OSuite::ZString::ZString(&key, v8);
  OSuite::ZString::ZString(&value, "OS-Game");
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &this->m_headers,
    &value,
    &key);
  OSuite::ZString::~ZString(&value);
  OSuite::ZString::~ZString(&key);
  v9 = OSuite::ZOnlineSuite::Instance();
  v10 = OSuite::ZOnlineSuite::GetGameConfig(v9);
  v11 = v10->vfptr->Version(v10);
  OSuite::ZString::ZString(&key, v11);
  OSuite::ZString::ZString(&value, "OS-GameVersion");
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &this->m_headers,
    &value,
    &key);
  OSuite::ZString::~ZString(&value);
  OSuite::ZString::~ZString(&key);
  OSuite::ZString::ZString(&value, "OS-Platform");
  v12 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &this->m_headers,
    &value,
    &v12->m_httpRequestManager->m_osPlatform);
  OSuite::ZString::~ZString(&value);
  v13 = OSuite::ZOnlineSuite::Instance();
  v14 = OSuite::ZOnlineSuite::GetGameConfig(v13);
  v15 = v14->vfptr->DBTarget(v14);
  if ( v15 )
  {
    OSuite::ZString::ZString(&key, v15);
    OSuite::ZString::ZString(&value, "OS-DBTarget");
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      &this->m_headers,
      &value,
      &key);
    OSuite::ZString::~ZString(&value);
    OSuite::ZString::~ZString(&key);
  }
  OSuite::ZString::ZString(&value, "OS-AuthProvider");
  v16 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
  AuthenticationProvider = OSuite::AuthenticationManager::GetAuthenticationProvider(v16);
  OSuite::ZString::ZString(&key, AuthenticationProvider);
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &this->m_headers,
    &value,
    v18);
  OSuite::ZString::~ZString(&key);
  OSuite::ZString::~ZString(&value);
  OSuite::ZString::ZString(&value, "OS-AuthTicketSize");
  v19 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
  TicketSize = OSuite::AuthenticationManager::GetTicketSize(v19);
  OSuite::ZString::ZString(&key, TicketSize);
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &this->m_headers,
    &value,
    v21);
  OSuite::ZString::~ZString(&key);
  OSuite::ZString::~ZString(&value);
  OSuite::ZString::ZString(&value, "OS-AuthTicketData");
  v22 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
  TicketData = OSuite::AuthenticationManager::GetTicketData(v22);
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &this->m_headers,
    &value,
    TicketData);
  OSuite::ZString::~ZString(&value);
  OSuite::ZString::ZString(&value, "OS-UID");
  v24 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
  TicketOwner = (OSuite::ZString *)OSuite::AuthenticationManager::GetTicketOwner(v24);
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &this->m_headers,
    &value,
    TicketOwner);
  OSuite::ZString::~ZString(&value);
  OSuite::ZString::ZString(&key, "2.0");
  OSuite::ZString::ZString(&value, "DataServiceVersion");
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &this->m_headers,
    &value,
    &key);
  OSuite::ZString::~ZString(&value);
  OSuite::ZString::~ZString(&key);
  OSuite::ZString::ZString(&key, "2.0");
  OSuite::ZString::ZString(&value, "MaxDataServiceVersion");
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &this->m_headers,
    &value,
    &key);
  OSuite::ZString::~ZString(&value);
  OSuite::ZString::~ZString(&key);
  other.m_parents.m_staticList[4] = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
  other.m_parents.m_pList = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  v30.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v30.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  v30.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( v30.m_parents.m_pList )
    v30.m_parents.m_pList->vfptr->__vecDelDtor(v30.m_parents.m_pList, 1u);
}


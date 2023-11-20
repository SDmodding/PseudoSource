// File Line: 45
// RVA: 0xEDFAE8
void __fastcall OSuite::ZHttpRequestBase::Execute(OSuite::ZHttpRequestBase *this, OSuite::IHttpRequest::AsynchCallback *asynchCallback)
{
  OSuite::IHttpRequest::AsynchCallback *v2; // rbx
  OSuite::ZHttpRequestBase *v3; // rdi
  bool v4; // zf
  OSuite::ZHttpManager *v5; // rax

  v2 = asynchCallback;
  v3 = this;
  ((void (*)(void))this->vfptr[8].__vecDelDtor)();
  v3->m_OnStartedCB.m_Closure.m_pFunction = v2->m_OnStarted.m_Closure.m_pFunction;
  v3->m_OnStartedCB.m_Closure.m_pthis = v2->m_OnStarted.m_Closure.m_pthis;
  v3->m_OnDataAvailableCB.m_Closure.m_pFunction = v2->m_OnDataAvailable.m_Closure.m_pFunction;
  v3->m_OnDataAvailableCB.m_Closure.m_pthis = v2->m_OnDataAvailable.m_Closure.m_pthis;
  v3->m_OnDataNeededCB.m_Closure.m_pFunction = v2->m_OnDataNeeded.m_Closure.m_pFunction;
  v3->m_OnDataNeededCB.m_Closure.m_pthis = v2->m_OnDataNeeded.m_Closure.m_pthis;
  v3->m_OnFinishedCB.m_Closure.m_pFunction = v2->m_OnFinished.m_Closure.m_pFunction;
  v3->m_OnFinishedCB.m_Closure.m_pthis = v2->m_OnFinished.m_Closure.m_pthis;
  v4 = v3->m_nLengthToSend == 0;
  v3->m_bClientCallback = v2->m_bClientCallback;
  if ( !v4 )
    ((void (*)(void))v3->m_bufferChain.vfptr->Size)();
  v5 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::ZHttpRequestManager::ExecuteRequest(v5->m_httpRequestManager, (OSuite::IHttpRequest *)&v3->vfptr);
}

// File Line: 65
// RVA: 0xEDF9AC
char __fastcall OSuite::ZHttpRequestBase::Busy(OSuite::ZHttpRequestBase *this)
{
  char v1; // bl

  v1 = 0;
  if ( this->m_asynchState && !(unsigned __int8)this->vfptr[17].__vecDelDtor((OSuite::ZObject *)this, 3072u) )
    v1 = 1;
  return v1;
}

// File Line: 71
// RVA: 0xEDFBEC
char __fastcall OSuite::ZHttpRequestBase::Ready(OSuite::ZHttpRequestBase *this)
{
  char v1; // bl
  OSuite::ZHttpRequestBase *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->m_asynchState == ASYNCHSTATE_NONE
    || (unsigned __int8)this->vfptr[17].__vecDelDtor((OSuite::ZObject *)this, 1024u)
    && !(unsigned __int8)v2->vfptr[17].__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 2048u) )
  {
    v1 = 1;
  }
  return v1;
}

// File Line: 77
// RVA: 0xEDF9DC
bool __fastcall OSuite::ZHttpRequestBase::CheckAsynchState(OSuite::ZHttpRequestBase *this, int comparedStates)
{
  OSuite::ZMutex *v2; // rbx
  OSuite::ZHttpRequestBase *v3; // rdi
  int v4; // esi

  v2 = &this->m_StateMutex;
  v3 = this;
  v4 = comparedStates;
  OSuite::ZMutex::Lock(&this->m_StateMutex);
  LOBYTE(v3) = (v4 & v3->m_asynchState) > 0;
  OSuite::ZMutex::Unlock(v2);
  return (char)v3;
}

// File Line: 87
// RVA: 0xEDFA2C
void __fastcall OSuite::ZHttpRequestBase::ClearClientData(OSuite::ZHttpRequestBase *this)
{
  OSuite::ZHttpRequestBase *v1; // rbx
  OSuite::ZString that; // [rsp+20h] [rbp-28h]

  this->m_nLengthToSend = 0i64;
  v1 = this;
  OSuite::ZString::ZString(&that, &customWorldMapCaption);
  OSuite::ZString::operator=(&v1->m_method, &that);
  OSuite::ZString::~ZString(&that);
  OSuite::ZRedBlackTreeBase::Clear((OSuite::ZRedBlackTreeBase *)&v1->m_headers.vfptr);
  OSuite::ZRedBlackTreeBase::Clear((OSuite::ZRedBlackTreeBase *)&v1->m_clientHeaders.vfptr);
  OSuite::ZString::ZString(&that, &customWorldMapCaption);
  OSuite::ZString::operator=(&v1->m_acceptType, &that);
  OSuite::ZString::~ZString(&that);
  OSuite::ZString::ZString(&that, &customWorldMapCaption);
  OSuite::ZString::operator=(&v1->m_contentType, &that);
  OSuite::ZString::~ZString(&that);
  v1->m_bTransferChunked = 0;
}

// File Line: 98
// RVA: 0xEDFB78
char __fastcall OSuite::ZHttpRequestBase::HandleDataCompleted(OSuite::ZHttpRequestBase *this)
{
  OSuite::ZHttpRequestBase *v1; // rdi
  char v2; // bl
  char result; // al
  __int64 v4; // rax
  __int64 v5; // rdi
  __int64 v6; // rax

  v1 = this;
  v2 = 0;
  if ( ((unsigned __int8 (*)(void))this->vfptr[18].__vecDelDtor)() )
    return 1;
  v4 = ((__int64 (__fastcall *)(OSuite::ZHttpRequestBase *))v1->vfptr[33].__vecDelDtor)(v1);
  v5 = v4;
  result = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 88i64))(v4);
  if ( result )
  {
    v6 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v5 + 64i64))(v5);
    if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v6 + 80i64))(v6)
      || (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v5 + 104i64))(v5) )
    {
      v2 = 1;
    }
    result = v2;
  }
  return result;
}

// File Line: 110
// RVA: 0xEDFC3C
void __fastcall OSuite::ZHttpRequestBase::SetAsynchState(OSuite::ZHttpRequestBase *this, OSuite::IHttpRequest::AsynchState state)
{
  OSuite::ZMutex *v2; // rbx
  OSuite::ZHttpRequestBase *v3; // rdi
  OSuite::IHttpRequest::AsynchState v4; // esi

  v2 = &this->m_StateMutex;
  v3 = this;
  v4 = state;
  OSuite::ZMutex::Lock(&this->m_StateMutex);
  if ( !(unsigned __int8)v3->vfptr[17].__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 2048u) )
    v3->m_asynchState = v4;
  OSuite::ZMutex::Unlock(v2);
}

// File Line: 135
// RVA: 0xEDF2B0
void __fastcall OSuite::ZHttpRequestBase::ZHttpRequestBase(OSuite::ZHttpRequestBase *this, OSuite::ZUrl *url, void *pParent, int nTimeOut)
{
  OSuite::ZHttpRequestBase *v4; // rsi
  int v5; // edi
  void *v6; // rbx

  v4 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpRequestBase::`vftable;
  this->m_OnStartedCB.m_Closure.m_pthis = 0i64;
  this->m_OnStartedCB.m_Closure.m_pFunction = 0i64;
  this->m_OnDataAvailableCB.m_Closure.m_pthis = 0i64;
  this->m_OnDataAvailableCB.m_Closure.m_pFunction = 0i64;
  this->m_OnDataNeededCB.m_Closure.m_pthis = 0i64;
  this->m_OnDataNeededCB.m_Closure.m_pFunction = 0i64;
  this->m_OnFinishedCB.m_Closure.m_pthis = 0i64;
  this->m_OnFinishedCB.m_Closure.m_pFunction = 0i64;
  v5 = nTimeOut;
  v6 = pParent;
  OSuite::ZUrl::ZUrl(&this->m_url, url);
  v4->m_pParent = v6;
  v4->m_nHttpOperationTimeout = v5;
  OSuite::ZMutex::ZMutex(&v4->m_StateMutex);
  v4->m_pLinkedObject = 0i64;
  v4->m_asynchState = 0;
  *(_WORD *)&v4->m_bClientCallback = 0;
  v4->m_bRecordUsage = 1;
  v4->m_nLengthToSend = 0i64;
  v4->m_nMaxBytesPerSecond = 0i64;
  OSuite::ZMemoryBufferChain::ZMemoryBufferChain(&v4->m_bufferChain, 1);
  OSuite::ZString::ZString(&v4->m_method);
  OSuite::ZString::ZString(&v4->m_acceptType);
  OSuite::ZString::ZString(&v4->m_contentType);
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&v4->m_headers.vfptr);
  v4->m_headers.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  v4->m_headers.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::ZObject};
  v4->m_headers.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&v4->m_clientHeaders.vfptr);
  v4->m_clientHeaders.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::ZObject};
  v4->m_clientHeaders.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  v4->m_clientHeaders.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable;
  v4->m_lastError = 0;
}

// File Line: 139
// RVA: 0xEDFC94
void __fastcall OSuite::ZHttpRequestBase::SetLastError(OSuite::ZHttpRequestBase *this, OSuite::ZHttp::EError error)
{
  OSuite::ZHttp::EError v2; // edi
  OSuite::ZError *v3; // rbx
  OSuite::ZError::EError v4; // eax

  v2 = error;
  this->m_lastError = error;
  v3 = OSuite::TSingleton<OSuite::ZError>::Object();
  v4 = (unsigned int)OSuite::ZHttp::HttpToOsError(v2);
  OSuite::ZError::SetThreadLastError(v3, v4, 1);
}

// File Line: 145
// RVA: 0xEDF3EC
void __fastcall OSuite::ZHttpRequestBase::BuildHeaders(OSuite::ZHttpRequestBase *this)
{
  OSuite::ZHttpRequestBase *v1; // rbx
  OSuite::ZString *v2; // rax
  OSuite::ZOnlineSuite *v3; // rax
  OSuite::IGameConfig *v4; // rax
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
  int v17; // eax
  OSuite::ZString *v18; // rax
  OSuite::AuthenticationManager *v19; // rax
  unsigned int v20; // eax
  OSuite::ZString *v21; // rax
  OSuite::AuthenticationManager *v22; // rax
  OSuite::ZString *v23; // rax
  OSuite::AuthenticationManager *v24; // rax
  OSuite::ZString *v25; // rax
  OSuite::ZString value; // [rsp+20h] [rbp-C8h]
  OSuite::ZString key; // [rsp+38h] [rbp-B0h]
  void **v28; // [rsp+50h] [rbp-98h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase other; // [rsp+58h] [rbp-90h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase v30; // [rsp+B8h] [rbp-30h]

  v30.m_pList = 0i64;
  v30.m_pElement = 0i64;
  v30.m_parents.m_pList = 0i64;
  v1 = this;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
    &other,
    (OSuite::ZRedBlackTreeBase *)&this->m_clientHeaders.vfptr);
  other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  other.m_parents.m_staticList[4] = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
  other.m_parents.m_pList = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v30, &other);
  v30.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  other.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v28 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  other.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( other.m_parents.m_staticList[2] )
    other.m_parents.m_staticList[2]->vfptr->__vecDelDtor((OSuite::ZObject *)other.m_parents.m_staticList[2], 1u);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v30) )
  {
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      &v1->m_headers,
      (OSuite::ZString *)&v30.m_pElement[1].m_pLeft,
      (OSuite::ZString *)&v30.m_pElement[2]);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v30);
  }
  OSuite::ZString::ZString(&value, "max-age=0");
  OSuite::ZString::ZString(&key, "Cache-Control");
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &v1->m_headers,
    &key,
    &value);
  OSuite::ZString::~ZString(&key);
  OSuite::ZString::~ZString(&value);
  if ( OSuite::ZString::operator bool(&v1->m_contentType) )
  {
    OSuite::ZString::ZString(&value, "Content-Type");
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      &v1->m_headers,
      &value,
      &v1->m_contentType);
    OSuite::ZString::~ZString(&value);
  }
  if ( v1->m_nLengthToSend )
  {
    OSuite::ZString::ZString(&value, "Content-Length");
    OSuite::ZString::ZString(&key, v1->m_nLengthToSend);
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      &v1->m_headers,
      &value,
      v2);
    OSuite::ZString::~ZString(&key);
    OSuite::ZString::~ZString(&value);
  }
  if ( v1->m_bTransferChunked )
  {
    OSuite::ZString::ZString(&key, "chunked");
    OSuite::ZString::ZString(&value, unk_1416D0B60);
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      &v1->m_headers,
      &value,
      &key);
    OSuite::ZString::~ZString(&value);
    OSuite::ZString::~ZString(&key);
  }
  v3 = OSuite::ZOnlineSuite::Instance();
  v4 = OSuite::ZOnlineSuite::GetGameConfig(v3);
  v5 = (const char *)v4->vfptr->BuildId(v4);
  OSuite::ZString::ZString(&key, v5);
  OSuite::ZString::ZString(&value, "OS-BuildID");
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &v1->m_headers,
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
    &v1->m_headers,
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
    &v1->m_headers,
    &value,
    &key);
  OSuite::ZString::~ZString(&value);
  OSuite::ZString::~ZString(&key);
  OSuite::ZString::ZString(&value, "OS-Platform");
  v12 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &v1->m_headers,
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
      &v1->m_headers,
      &value,
      &key);
    OSuite::ZString::~ZString(&value);
    OSuite::ZString::~ZString(&key);
  }
  OSuite::ZString::ZString(&value, "OS-AuthProvider");
  v16 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
  v17 = OSuite::AuthenticationManager::GetAuthenticationProvider(v16);
  OSuite::ZString::ZString(&key, v17);
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &v1->m_headers,
    &value,
    v18);
  OSuite::ZString::~ZString(&key);
  OSuite::ZString::~ZString(&value);
  OSuite::ZString::ZString(&value, "OS-AuthTicketSize");
  v19 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
  v20 = OSuite::AuthenticationManager::GetTicketSize(v19);
  OSuite::ZString::ZString(&key, v20);
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &v1->m_headers,
    &value,
    v21);
  OSuite::ZString::~ZString(&key);
  OSuite::ZString::~ZString(&value);
  OSuite::ZString::ZString(&value, "OS-AuthTicketData");
  v22 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
  v23 = OSuite::AuthenticationManager::GetTicketData(v22);
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &v1->m_headers,
    &value,
    v23);
  OSuite::ZString::~ZString(&value);
  OSuite::ZString::ZString(&value, "OS-UID");
  v24 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
  v25 = (OSuite::ZString *)OSuite::AuthenticationManager::GetTicketOwner(v24);
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &v1->m_headers,
    &value,
    v25);
  OSuite::ZString::~ZString(&value);
  OSuite::ZString::ZString(&key, "2.0");
  OSuite::ZString::ZString(&value, "DataServiceVersion");
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &v1->m_headers,
    &value,
    &key);
  OSuite::ZString::~ZString(&value);
  OSuite::ZString::~ZString(&key);
  OSuite::ZString::ZString(&key, "2.0");
  OSuite::ZString::ZString(&value, "MaxDataServiceVersion");
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &v1->m_headers,
    &value,
    &key);
  OSuite::ZString::~ZString(&value);
  OSuite::ZString::~ZString(&key);
  other.m_parents.m_staticList[4] = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
  other.m_parents.m_pList = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  v30.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v30.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  v30.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( v30.m_parents.m_pList )
    v30.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)v30.m_parents.m_pList, 1u);
}


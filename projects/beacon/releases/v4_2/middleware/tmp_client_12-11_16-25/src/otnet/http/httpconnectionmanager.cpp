// File Line: 13
// RVA: 0xEDB13C
void __fastcall OSuite::ZHttpConnectionManager::ZHttpConnectionManager(OSuite::ZHttpConnectionManager *this)
{
  OSuite::ZHttpConnectionManager *v1; // rdi

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpConnectionManager::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&this->m_freeHttpConnectionsList);
  v1->m_freeHttpConnectionsList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZMutex::ZMutex(&v1->m_ConnectionMutex);
  v1->m_MaxHttpConnection = 16i64;
}

// File Line: 17
// RVA: 0xEDB188
void __fastcall OSuite::ZHttpConnectionManager::~ZHttpConnectionManager(OSuite::ZHttpConnectionManager *this)
{
  OSuite::ZDoublyLinkedListBase *v1; // rdi
  OSuite::ZHttpConnectionManager *v2; // rsi
  OSuite::ZObjectVtbl *v3; // rcx
  bool v4; // bl
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v5; // [rsp+20h] [rbp-40h]
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v6; // [rsp+38h] [rbp-28h]

  v5.m_pList = 0i64;
  v5.m_pElement = 0i64;
  v1 = (OSuite::ZDoublyLinkedListBase *)&this->m_freeHttpConnectionsList.vfptr;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpConnectionManager::`vftable;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    &v5,
    (OSuite::ZDoublyLinkedListBase *)&this->m_freeHttpConnectionsList.vfptr,
    this->m_freeHttpConnectionsList.m_pHead);
  v6.m_pList = 0i64;
  v6.m_pElement = 0i64;
  v5.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(&v6, v1, 0i64);
  v6.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( 1 )
  {
    v4 = OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v6);
    if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v5) == v4 )
      break;
    v3 = v5.m_pElement[1].vfptr;
    if ( v3 )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, signed __int64))v3->__vecDelDtor)(v3, 1i64);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(&v5);
  }
  OSuite::ZDoublyLinkedListBase::Clear(v1);
  OSuite::ZMutex::~ZMutex(&v2->m_ConnectionMutex);
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZDoublyLinkedListBase::Clear(v1);
}

// File Line: 43
// RVA: 0xEDB594
OSuite::ZHttpConnection *__fastcall OSuite::ZHttpConnectionManager::CreateHttpConnection(OSuite::ZHttpConnectionManager *this, OSuite::ZUrl *url, int nTimeOut)
{
  OSuite::ZHttpConnectionManager *v3; // r14
  int v4; // er13
  OSuite::ZUrl *v5; // r12
  OSuite::ZHttpConnection *v6; // rdi
  OSuite::ZDoublyLinkedListBase::ZElementBase *v7; // r8
  bool v8; // bl
  OSuite::ZObjectVtbl *v9; // rbx
  OSuite::ZUrl *v10; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *v11; // rdx
  OSuite::ZHttpConnection *v12; // rax
  OSuite::ZHttpConnection *v13; // rax
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v15; // [rsp+20h] [rbp-40h]
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v16; // [rsp+38h] [rbp-28h]

  v3 = this;
  v4 = nTimeOut;
  v5 = url;
  OSuite::ZMutex::Lock(&this->m_ConnectionMutex);
  v6 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v3->m_freeHttpConnectionsList) )
  {
    v7 = v3->m_freeHttpConnectionsList.m_pHead;
    v15.m_pList = 0i64;
    v15.m_pElement = 0i64;
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
      &v15,
      (OSuite::ZDoublyLinkedListBase *)&v3->m_freeHttpConnectionsList.vfptr,
      v7);
    v16.m_pList = 0i64;
    v16.m_pElement = 0i64;
    v15.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
      &v16,
      (OSuite::ZDoublyLinkedListBase *)&v3->m_freeHttpConnectionsList.vfptr,
      0i64);
    v16.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( 1 )
    {
      v8 = OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v16);
      if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v15) == v8 )
        break;
      v9 = v15.m_pElement[1].vfptr;
      v10 = OSuite::ZHttpConnection::Url((OSuite::ZHttpConnection *)v15.m_pElement[1].vfptr);
      if ( OSuite::ZUrl::operator==(v10, v5)
        && !OSuite::ZRedBlackTreeBase::IsEmpty((OSuite::ZRedBlackTreeBase *)&v3->m_freeHttpConnectionsList) )
      {
        v11 = v3->m_freeHttpConnectionsList.m_pHead;
        while ( v11[1].vfptr != v9 )
        {
          v11 = v11->m_pNext;
          if ( v11 == v3->m_freeHttpConnectionsList.m_pHead )
          {
            v11 = 0i64;
            break;
          }
        }
        if ( v11 )
        {
          OSuite::ZDoublyLinkedListBase::DeleteElement(
            (OSuite::ZDoublyLinkedListBase *)&v3->m_freeHttpConnectionsList.vfptr,
            v11);
          v6 = (OSuite::ZHttpConnection *)v9;
          break;
        }
      }
      OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(&v15);
    }
    v16.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v15.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  }
  OSuite::ZMutex::Unlock(&v3->m_ConnectionMutex);
  if ( v6 )
    goto LABEL_24;
  v12 = (OSuite::ZHttpConnection *)OSuite::ZObject::operator new(0xF0ui64);
  if ( v12 )
  {
    v12->m_url.m_sProtocol.m_pString = 0i64;
    v12->m_url.m_sHost.m_pString = 0i64;
    v12->m_url.m_sFakeHost.m_pString = 0i64;
    v12->m_url.m_sPath.m_pString = 0i64;
    v12->m_url.m_urlParameters.m_parameters.m_pTop = 0i64;
    v12->m_url.m_urlParameters.m_arrayParameters.m_pTop = 0i64;
    v12->m_socket = 0i64;
    OSuite::ZHttpConnection::ZHttpConnection(v12);
    v6 = v13;
  }
  else
  {
    v6 = 0i64;
  }
  if ( v6 )
  {
LABEL_24:
    if ( !OSuite::ZHttpConnectionManager::AssociateWithSocket(v3, v6, v5, v4) )
    {
      OSuite::ZHttpConnectionManager::ReleaseHttpConnection(v3, v6, 0);
      v6 = 0i64;
    }
  }
  return v6;
}

// File Line: 87
// RVA: 0xEDB834
void __fastcall OSuite::ZHttpConnectionManager::ReleaseHttpConnection(OSuite::ZHttpConnectionManager *this, OSuite::ZHttpConnection *httpConnection, bool bKeepSocketAlive)
{
  OSuite::ZHttpConnectionManager *v3; // rbp
  bool v4; // di
  OSuite::ZHttpConnection *v5; // rsi
  OSuite::ZObjectVtbl *v6; // rsi
  OSuite::ZDoublyLinkedListBase::ZElementBase *v7; // rdx
  OSuite::ZRedBlackTreeBase::ZIteratorBase *v8; // rax
  OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::ZIterator result; // [rsp+20h] [rbp-48h]
  OSuite::IHttpRequest *data; // [rsp+38h] [rbp-30h]

  v3 = this;
  v4 = bKeepSocketAlive;
  v5 = httpConnection;
  data = (OSuite::IHttpRequest *)httpConnection;
  OSuite::ZMutex::Lock(&this->m_ConnectionMutex);
  OSuite::ZHttpConnectionManager::CloseHttpConnection(v3, v5, v4);
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v3->m_freeHttpConnectionsList) >= v3->m_MaxHttpConnection )
  {
    v6 = OSuite::ZDoublyLinkedListBase::TailElement((OSuite::ZDoublyLinkedListBase *)&v3->m_freeHttpConnectionsList.vfptr)[1].vfptr;
    if ( !OSuite::ZRedBlackTreeBase::IsEmpty((OSuite::ZRedBlackTreeBase *)&v3->m_freeHttpConnectionsList) )
    {
      v7 = v3->m_freeHttpConnectionsList.m_pHead;
      while ( v7[1].vfptr != v6 )
      {
        v7 = v7->m_pNext;
        if ( v7 == v3->m_freeHttpConnectionsList.m_pHead )
        {
          v7 = 0i64;
          break;
        }
      }
      if ( v7 )
        OSuite::ZDoublyLinkedListBase::DeleteElement(
          (OSuite::ZDoublyLinkedListBase *)&v3->m_freeHttpConnectionsList.vfptr,
          v7);
    }
    if ( v6 )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, signed __int64))v6->__vecDelDtor)(v6, 1i64);
  }
  v8 = (OSuite::ZRedBlackTreeBase::ZIteratorBase *)OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::Find(
                                                     (OSuite::TDoublyLinkedList<OSuite::IHttpRequest *> *)&v3->m_freeHttpConnectionsList,
                                                     &result,
                                                     &data);
  if ( !OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool(v8) )
    OSuite::TDoublyLinkedList<OSuite::ZHttpConnection *>::Insert(
      &v3->m_freeHttpConnectionsList,
      (OSuite::ZHttpConnection *const *)&data);
  OSuite::ZMutex::Unlock(&v3->m_ConnectionMutex);
}

// File Line: 113
// RVA: 0xEDB3D8
void __fastcall OSuite::ZHttpConnectionManager::CloseHttpConnection(OSuite::ZHttpConnectionManager *this, OSuite::ZHttpConnection *httpConnection, bool bKeepSocketAlive)
{
  OSuite::ZHttpConnection *v3; // rbx
  unsigned __int64 v4; // rdi
  OSuite::ZSocketManager *v5; // rax

  v3 = httpConnection;
  if ( httpConnection->m_socket )
  {
    if ( bKeepSocketAlive
      && OSuite::ZHttpConnection::IsPersistent(httpConnection)
      && OSuite::TSingleton<OSuite::ZSocketManager>::Object()->m_KeepAliveTimeoutMs )
    {
      v4 = OSuite::TSingleton<OSuite::ZSocketManager>::Object()->m_KeepAliveTimeoutMs;
    }
    else
    {
      v4 = 0i64;
    }
    v5 = OSuite::TSingleton<OSuite::ZSocketManager>::Object();
    OSuite::ZSocketManager::ReleaseSocket(v5, v3->m_socket, v4);
    v3->m_socket = 0i64;
  }
}

// File Line: 135
// RVA: 0xEDB2B0
bool __fastcall OSuite::ZHttpConnectionManager::AssociateWithSocket(OSuite::ZHttpConnectionManager *this, OSuite::ZHttpConnection *httpConnection, OSuite::ZUrl *url, int nTimeOut)
{
  OSuite::ZHttpConnectionManager *v4; // rdi
  int v5; // er15
  OSuite::ZUrl *v6; // rsi
  OSuite::ZHttpConnection *v7; // r14
  OSuite::ZString *v8; // rax
  OSuite::ZSocket *v9; // rax
  bool v10; // bl
  OSuite::ZSocketManager *v11; // rbx
  int v12; // eax
  OSuite::ZObjectVtbl *v13; // rax
  OSuite::ZSocket *v14; // rbp
  bool v15; // di
  OSuite::ZSocketManager *v16; // rax
  bool bAlreadyConnected; // [rsp+20h] [rbp-58h]
  OSuite::ZString sHost; // [rsp+28h] [rbp-50h]

  sHost.m_pString = 0i64;
  v4 = this;
  v5 = nTimeOut;
  v6 = url;
  v7 = httpConnection;
  v8 = OSuite::IOnlineAuthentication::GetTicketData(url);
  OSuite::ZString::ZString(&sHost, v8);
  if ( !OSuite::ZHttpConnection::IsConnecting(v7) )
  {
    if ( OSuite::ZHttpConnection::IsConnected(v7) )
    {
      v10 = 1;
      goto LABEL_11;
    }
    bAlreadyConnected = 0;
    v11 = OSuite::TSingleton<OSuite::ZSocketManager>::Object();
    v12 = OSuite::ZUrl::GetPort(v6);
    v13 = OSuite::ZSocketManager::TryGetSocket(v11, &sHost, v12, &bAlreadyConnected);
    v14 = (OSuite::ZSocket *)v13;
    if ( bAlreadyConnected )
    {
      v15 = 1;
    }
    else
    {
      v15 = OSuite::ZHttpConnectionManager::Connect(v4, (OSuite::ZSocket *)v13, v6, v5);
      if ( !v15 )
      {
        v16 = OSuite::TSingleton<OSuite::ZSocketManager>::Object();
        OSuite::ZSocketManager::ReleaseSocket(v16, v14, 0i64);
        goto LABEL_10;
      }
    }
    OSuite::ZHttpConnection::BindWithSocket(v7, v14, v6, 1);
LABEL_10:
    v10 = v15;
    goto LABEL_11;
  }
  v9 = OSuite::ZHttpConnection::Socket(v7);
  v10 = OSuite::ZHttpConnectionManager::Connect(v4, v9, v6, v5);
LABEL_11:
  OSuite::ZString::~ZString(&sHost);
  return v10;
}

// File Line: 159
// RVA: 0xEDB444
bool __fastcall OSuite::ZHttpConnectionManager::Connect(OSuite::ZHttpConnectionManager *this, OSuite::ZSocket *socket, OSuite::ZUrl *url, int nTimeOut)
{
  int nConnectTimeoutMs; // er15
  OSuite::ZUrl *v5; // r12
  OSuite::ZSocket *v6; // r14
  int v7; // edi
  const char *v8; // rax
  OSuite::ZString *v9; // rax
  bool v10; // di
  int v11; // ebx
  OSuite::ZString *v12; // rax
  const char *v13; // rax
  OSuite::ZString *v14; // rax
  const char *v15; // rax
  bool v16; // zf
  char v17; // al

  nConnectTimeoutMs = nTimeOut;
  v5 = url;
  v6 = socket;
  if ( OSuite::ZSocket::VerifyConnection(socket) )
  {
    OSuite::ZSocket::SetTimeout(v6, nConnectTimeoutMs, 10000);
  }
  else if ( OSuite::ZSocket::GetProxyType() == 3 )
  {
    v7 = OSuite::ZSocket::GetProxyPort();
    v8 = OSuite::ZSocket::GetProxyHost();
    OSuite::ZSocket::Connect(v6, v8, v7, 0, nConnectTimeoutMs == 0, nConnectTimeoutMs, nConnectTimeoutMs);
  }
  else
  {
    v9 = (OSuite::ZString *)OSuite::ZUrl::GetProtocol((OSuite::ZHttpResponseBase *)v5);
    v10 = OSuite::ZString::operator==(v9, "https");
    v11 = OSuite::ZUrl::GetPort(v5);
    v12 = OSuite::IOnlineAuthentication::GetTicketData(v5);
    v13 = OSuite::ZString::c_str(v12);
    if ( OSuite::ZSocket::Connect(v6, v13, v11, v10, nConnectTimeoutMs == 0, nConnectTimeoutMs, nConnectTimeoutMs) )
    {
      v14 = OSuite::IOnlineAuthentication::GetTicketData(v5);
      v15 = OSuite::ZString::c_str(v14);
      if ( !OSuite::ZSocket::MatchSecureHostName(v6, v15) )
        OSuite::ZSocket::Abort(v6, 0);
    }
  }
  if ( v6->m_state == ZSOCKSTATE_NONE || (v16 = OSuite::ZSocket::HasFatalError(v6) == 0, v17 = 0, !v16) )
    v17 = 1;
  return v17 == 0;
}


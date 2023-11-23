// File Line: 13
// RVA: 0xEDB13C
void __fastcall OSuite::ZHttpConnectionManager::ZHttpConnectionManager(OSuite::ZHttpConnectionManager *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpConnectionManager::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&this->m_freeHttpConnectionsList);
  this->m_freeHttpConnectionsList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZMutex::ZMutex(&this->m_ConnectionMutex);
  this->m_MaxHttpConnection = 16i64;
}

// File Line: 17
// RVA: 0xEDB188
void __fastcall OSuite::ZHttpConnectionManager::~ZHttpConnectionManager(OSuite::ZHttpConnectionManager *this)
{
  OSuite::TDoublyLinkedList<OSuite::ZHttpConnection *> *p_m_freeHttpConnectionsList; // rdi
  void (__fastcall ***v3)(_QWORD, __int64); // rcx
  bool v4; // bl
  _BYTE var40[72]; // [rsp+20h] [rbp-40h] BYREF

  *(_QWORD *)&var40[8] = 0i64;
  *(_QWORD *)&var40[16] = 0i64;
  p_m_freeHttpConnectionsList = &this->m_freeHttpConnectionsList;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpConnectionManager::`vftable;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    (OSuite::ZDoublyLinkedListBase::ZIteratorBase *)var40,
    &this->m_freeHttpConnectionsList,
    this->m_freeHttpConnectionsList.m_pHead);
  *(_QWORD *)&var40[32] = 0i64;
  *(_QWORD *)&var40[40] = 0i64;
  *(_QWORD *)var40 = &OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    (OSuite::ZDoublyLinkedListBase::ZIteratorBase *)&var40[24],
    p_m_freeHttpConnectionsList,
    0i64);
  *(_QWORD *)&var40[24] = &OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( 1 )
  {
    v4 = OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&var40[24]);
    if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)var40) == v4 )
      break;
    v3 = *(void (__fastcall ****)(_QWORD, __int64))(*(_QWORD *)&var40[16] + 24i64);
    if ( v3 )
      (**v3)(v3, 1i64);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next((OSuite::ZDoublyLinkedListBase::ZIteratorBase *)var40);
  }
  OSuite::ZDoublyLinkedListBase::Clear(p_m_freeHttpConnectionsList);
  OSuite::ZMutex::~ZMutex(&this->m_ConnectionMutex);
  p_m_freeHttpConnectionsList->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZDoublyLinkedListBase::Clear(p_m_freeHttpConnectionsList);
}

// File Line: 43
// RVA: 0xEDB594
OSuite::ZHttpConnection *__fastcall OSuite::ZHttpConnectionManager::CreateHttpConnection(
        OSuite::ZHttpConnectionManager *this,
        OSuite::ZUrl *url,
        int nTimeOut)
{
  OSuite::ZHttpConnection *v6; // rdi
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pHead; // r8
  bool v8; // bl
  OSuite::ZObjectVtbl *vfptr; // rbx
  OSuite::ZUrl *v10; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *v11; // rdx
  OSuite::ZHttpConnection *v12; // rax
  OSuite::ZHttpConnection *v13; // rax
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v15; // [rsp+20h] [rbp-40h] BYREF
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v16; // [rsp+38h] [rbp-28h] BYREF

  OSuite::ZMutex::Lock(&this->m_ConnectionMutex);
  v6 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_freeHttpConnectionsList) )
  {
    m_pHead = this->m_freeHttpConnectionsList.m_pHead;
    v15.m_pList = 0i64;
    v15.m_pElement = 0i64;
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(&v15, &this->m_freeHttpConnectionsList, m_pHead);
    v16.m_pList = 0i64;
    v16.m_pElement = 0i64;
    v15.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(&v16, &this->m_freeHttpConnectionsList, 0i64);
    v16.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( 1 )
    {
      v8 = OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v16);
      if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v15) == v8 )
        break;
      vfptr = v15.m_pElement[1].vfptr;
      v10 = OSuite::ZHttpConnection::Url((OSuite::ZHttpConnection *)vfptr);
      if ( OSuite::ZUrl::operator==(v10, url)
        && !OSuite::ZRedBlackTreeBase::IsEmpty((OSuite::ZRedBlackTreeBase *)&this->m_freeHttpConnectionsList) )
      {
        v11 = this->m_freeHttpConnectionsList.m_pHead;
        while ( v11[1].vfptr != vfptr )
        {
          v11 = v11->m_pNext;
          if ( v11 == this->m_freeHttpConnectionsList.m_pHead )
          {
            v11 = 0i64;
            break;
          }
        }
        if ( v11 )
        {
          OSuite::ZDoublyLinkedListBase::DeleteElement(&this->m_freeHttpConnectionsList, v11);
          v6 = (OSuite::ZHttpConnection *)vfptr;
          break;
        }
      }
      OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(&v15);
    }
    v16.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v15.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  }
  OSuite::ZMutex::Unlock(&this->m_ConnectionMutex);
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
    if ( !OSuite::ZHttpConnectionManager::AssociateWithSocket(this, v6, url, nTimeOut) )
    {
      OSuite::ZHttpConnectionManager::ReleaseHttpConnection(this, v6, 0);
      return 0i64;
    }
  }
  return v6;
}

// File Line: 87
// RVA: 0xEDB834
void __fastcall OSuite::ZHttpConnectionManager::ReleaseHttpConnection(
        OSuite::ZHttpConnectionManager *this,
        OSuite::IHttpRequest *httpConnection,
        bool bKeepSocketAlive)
{
  OSuite::ZObjectVtbl *vfptr; // rsi
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pHead; // rdx
  OSuite::ZRedBlackTreeBase::ZIteratorBase *v8; // rax
  OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::ZIterator result; // [rsp+20h] [rbp-48h] BYREF
  OSuite::IHttpRequest *data; // [rsp+38h] [rbp-30h] BYREF

  data = httpConnection;
  OSuite::ZMutex::Lock(&this->m_ConnectionMutex);
  OSuite::ZHttpConnectionManager::CloseHttpConnection(this, (OSuite::ZHttpConnection *)httpConnection, bKeepSocketAlive);
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_freeHttpConnectionsList) >= this->m_MaxHttpConnection )
  {
    vfptr = OSuite::ZDoublyLinkedListBase::TailElement(&this->m_freeHttpConnectionsList)[1].vfptr;
    if ( !OSuite::ZRedBlackTreeBase::IsEmpty((OSuite::ZRedBlackTreeBase *)&this->m_freeHttpConnectionsList) )
    {
      m_pHead = this->m_freeHttpConnectionsList.m_pHead;
      while ( m_pHead[1].vfptr != vfptr )
      {
        m_pHead = m_pHead->m_pNext;
        if ( m_pHead == this->m_freeHttpConnectionsList.m_pHead )
        {
          m_pHead = 0i64;
          break;
        }
      }
      if ( m_pHead )
        OSuite::ZDoublyLinkedListBase::DeleteElement(&this->m_freeHttpConnectionsList, m_pHead);
    }
    if ( vfptr )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, __int64))vfptr->__vecDelDtor)(vfptr, 1i64);
  }
  v8 = (OSuite::ZRedBlackTreeBase::ZIteratorBase *)OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::Find(
                                                     (OSuite::TDoublyLinkedList<OSuite::IHttpRequest *> *)&this->m_freeHttpConnectionsList,
                                                     &result,
                                                     (OSuite::ZObjectVtbl **)&data);
  if ( !OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool(v8) )
    OSuite::TDoublyLinkedList<OSuite::ZHttpConnection *>::Insert(
      &this->m_freeHttpConnectionsList,
      (OSuite::ZHttpConnection **)&data);
  OSuite::ZMutex::Unlock(&this->m_ConnectionMutex);
}

// File Line: 113
// RVA: 0xEDB3D8
void __fastcall OSuite::ZHttpConnectionManager::CloseHttpConnection(
        OSuite::ZHttpConnectionManager *this,
        OSuite::ZHttpConnection *httpConnection,
        bool bKeepSocketAlive)
{
  unsigned __int64 m_KeepAliveTimeoutMs; // rdi
  OSuite::ZSocketManager *v5; // rax

  if ( httpConnection->m_socket )
  {
    if ( bKeepSocketAlive
      && OSuite::ZHttpConnection::IsPersistent(httpConnection)
      && OSuite::TSingleton<OSuite::ZSocketManager>::Object()->m_KeepAliveTimeoutMs )
    {
      m_KeepAliveTimeoutMs = OSuite::TSingleton<OSuite::ZSocketManager>::Object()->m_KeepAliveTimeoutMs;
    }
    else
    {
      m_KeepAliveTimeoutMs = 0i64;
    }
    v5 = OSuite::TSingleton<OSuite::ZSocketManager>::Object();
    OSuite::ZSocketManager::ReleaseSocket(v5, httpConnection->m_socket, m_KeepAliveTimeoutMs);
    httpConnection->m_socket = 0i64;
  }
}

// File Line: 135
// RVA: 0xEDB2B0
bool __fastcall OSuite::ZHttpConnectionManager::AssociateWithSocket(
        OSuite::ZHttpConnectionManager *this,
        OSuite::ZHttpConnection *httpConnection,
        OSuite::ZUrl *url,
        int nTimeOut)
{
  OSuite::ZString *TicketData; // rax
  OSuite::ZSocket *v9; // rax
  bool v10; // bl
  OSuite::ZSocketManager *v11; // rbx
  int Port; // eax
  OSuite::ZObjectVtbl *Socket; // rax
  OSuite::ZSocket *v14; // rbp
  bool v15; // di
  OSuite::ZSocketManager *v16; // rax
  bool bAlreadyConnected; // [rsp+20h] [rbp-58h] BYREF
  OSuite::ZString sHost; // [rsp+28h] [rbp-50h] BYREF

  sHost.m_pString = 0i64;
  TicketData = OSuite::IOnlineAuthentication::GetTicketData(url);
  OSuite::ZString::ZString(&sHost, TicketData);
  if ( !OSuite::ZHttpConnection::IsConnecting(httpConnection) )
  {
    if ( OSuite::ZHttpConnection::IsConnected(httpConnection) )
    {
      v10 = 1;
      goto LABEL_11;
    }
    bAlreadyConnected = 0;
    v11 = OSuite::TSingleton<OSuite::ZSocketManager>::Object();
    Port = OSuite::ZUrl::GetPort(url);
    Socket = OSuite::ZSocketManager::TryGetSocket(v11, &sHost, Port, &bAlreadyConnected);
    v14 = (OSuite::ZSocket *)Socket;
    if ( bAlreadyConnected )
    {
      v15 = 1;
    }
    else
    {
      v15 = OSuite::ZHttpConnectionManager::Connect(this, (OSuite::ZSocket *)Socket, url, nTimeOut);
      if ( !v15 )
      {
        v16 = OSuite::TSingleton<OSuite::ZSocketManager>::Object();
        OSuite::ZSocketManager::ReleaseSocket(v16, v14, 0i64);
        goto LABEL_10;
      }
    }
    OSuite::ZHttpConnection::BindWithSocket(httpConnection, v14, url, 1);
LABEL_10:
    v10 = v15;
    goto LABEL_11;
  }
  v9 = OSuite::ZHttpConnection::Socket(httpConnection);
  v10 = OSuite::ZHttpConnectionManager::Connect(this, v9, url, nTimeOut);
LABEL_11:
  OSuite::ZString::~ZString(&sHost);
  return v10;
}

// File Line: 159
// RVA: 0xEDB444
bool __fastcall OSuite::ZHttpConnectionManager::Connect(
        OSuite::ZHttpConnectionManager *this,
        OSuite::ZSocket *socket,
        OSuite::ZHttpResponseBase *url,
        int nTimeOut)
{
  int ProxyPort; // edi
  const char *ProxyHost; // rax
  OSuite::ZString *Protocol; // rax
  bool v10; // di
  int Port; // ebx
  OSuite::ZString *TicketData; // rax
  const char *v13; // rax
  OSuite::ZString *v14; // rax
  const char *v15; // rax
  bool v16; // zf
  char v17; // al

  if ( OSuite::ZSocket::VerifyConnection(socket) )
  {
    OSuite::ZSocket::SetTimeout(socket, nTimeOut, 10000);
  }
  else if ( OSuite::ZSocket::GetProxyType() == ZSOCKPROXY_HTTP )
  {
    ProxyPort = OSuite::ZSocket::GetProxyPort();
    ProxyHost = OSuite::ZSocket::GetProxyHost();
    OSuite::ZSocket::Connect(socket, ProxyHost, ProxyPort, 0, nTimeOut == 0, nTimeOut, nTimeOut);
  }
  else
  {
    Protocol = (OSuite::ZString *)OSuite::ZUrl::GetProtocol(url);
    v10 = OSuite::ZString::operator==(Protocol, "https");
    Port = OSuite::ZUrl::GetPort((OSuite::ZUrl *)url);
    TicketData = OSuite::IOnlineAuthentication::GetTicketData((OSuite::ZUrl *)url);
    v13 = OSuite::ZString::c_str(TicketData);
    if ( OSuite::ZSocket::Connect(socket, v13, Port, v10, nTimeOut == 0, nTimeOut, nTimeOut) )
    {
      v14 = OSuite::IOnlineAuthentication::GetTicketData((OSuite::ZUrl *)url);
      v15 = OSuite::ZString::c_str(v14);
      if ( !OSuite::ZSocket::MatchSecureHostName(socket, v15) )
        OSuite::ZSocket::Abort(socket, ERR_OK);
    }
  }
  if ( socket->m_state == ZSOCKSTATE_NONE || (v16 = !OSuite::ZSocket::HasFatalError(socket), v17 = 0, !v16) )
    v17 = 1;
  return v17 == 0;
}


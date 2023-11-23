// File Line: 26
// RVA: 0xEDBCC0
void __fastcall OSuite::ZHttpRequest::ZHttpRequest(
        OSuite::ZHttpRequest *this,
        OSuite::ZUrl *url,
        void *pParent,
        bool bKeepAlive,
        int nTimeOut)
{
  OSuite::ZObjectAccessor *v7; // rax

  OSuite::ZHttpRequestBase::ZHttpRequestBase(this, url, pParent, nTimeOut);
  this->m_pHttpConnection = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpRequest::`vftable;
  OSuite::ZHttpResponse::ZHttpResponse(&this->m_httpResponse);
  OSuite::ZHttpStreamWriter::ZHttpStreamWriter(&this->m_streamWriter);
  this->m_bKeepAliveOverride = bKeepAlive;
  v7 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::RegisterObject(v7, this->m_pParent);
  OSuite::ZHttpRequestBase::ClearClientData(this);
  this->m_OnDataAvailableCB.m_Closure.m_pFunction = 0i64;
  this->m_OnDataAvailableCB.m_Closure.m_pthis = 0i64;
  this->m_OnDataNeededCB.m_Closure.m_pFunction = 0i64;
  this->m_OnDataNeededCB.m_Closure.m_pthis = 0i64;
  this->m_OnFinishedCB.m_Closure.m_pFunction = 0i64;
  this->m_OnFinishedCB.m_Closure.m_pthis = 0i64;
  this->m_bufferChain.m_bDeleteOnRead = 0;
}

// File Line: 40
// RVA: 0xEDBD5C
void __fastcall OSuite::ZHttpRequest::~ZHttpRequest(OSuite::ZHttpRequest *this)
{
  OSuite::ZObjectAccessor *v2; // rax

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpRequest::`vftable;
  v2 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::UnRegisterObject(v2, this->m_pParent);
  OSuite::ZHttpStreamWriter::~ZHttpStreamWriter(&this->m_streamWriter);
  OSuite::ZHttpResponse::~ZHttpResponse(&this->m_httpResponse);
  OSuite::ZHttpRequestBase::~ZHttpRequestBase(this);
}

// File Line: 45
// RVA: 0xEDC344
char __fastcall OSuite::ZHttpRequest::Release(OSuite::ZHttpRequest *this)
{
  char v2; // di
  void *m_pParent; // rsi
  OSuite::ZObjectAccessor *v5; // rax
  OSuite::ZObjectAccessor *v6; // rax

  v2 = 0;
  if ( this->vfptr[17].__vecDelDtor(this, 2048i64) )
    return 0;
  m_pParent = this->m_pParent;
  v5 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::AccessObject(v5, m_pParent);
  if ( !this->vfptr[17].__vecDelDtor(this, 2048i64) )
  {
    this->m_streamWriter.vfptr->Flush(&this->m_streamWriter.OSuite::IWriter);
    this->m_httpResponse.vfptr->Flush(&this->m_httpResponse.OSuite::IHttpResponse);
    v2 = 1;
  }
  v6 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::ReleaseObject(v6, m_pParent);
  return v2;
}

// File Line: 65
// RVA: 0xEDCADC
char __fastcall OSuite::ZHttpRequest::Shutdown(OSuite::ZHttpRequest *this)
{
  char v2; // di
  void *m_pParent; // rsi
  OSuite::ZObjectAccessor *v5; // rax
  OSuite::ZHttpConnection *m_pHttpConnection; // rcx
  OSuite::ZObjectAccessor *v7; // rax

  v2 = 0;
  if ( this->vfptr[17].__vecDelDtor(this, 2048i64) )
    return 0;
  m_pParent = this->m_pParent;
  v5 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::AccessObject(v5, m_pParent);
  if ( !this->vfptr[17].__vecDelDtor(this, 2048i64) )
  {
    this->m_streamWriter.vfptr->Flush(&this->m_streamWriter.OSuite::IWriter);
    this->m_httpResponse.vfptr->Flush(&this->m_httpResponse.OSuite::IHttpResponse);
    m_pHttpConnection = this->m_pHttpConnection;
    if ( m_pHttpConnection )
      OSuite::ZHttpConnection::Abort(m_pHttpConnection);
    this->vfptr[40].__vecDelDtor(this, 11u);
    v2 = 1;
  }
  v7 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::ReleaseObject(v7, m_pParent);
  return v2;
}

// File Line: 90
// RVA: 0xEDC22C
__int64 __fastcall OSuite::ZHttpRequest::HandleResponse(OSuite::ZHttpRequest *this)
{
  return ((__int64 (__fastcall *)(OSuite::ZHttpResponse *))this->m_httpResponse.vfptr[1].__vecDelDtor)(&this->m_httpResponse);
}

// File Line: 95
// RVA: 0xEDC1DC
__int64 __fastcall OSuite::ZHttpRequest::HandleData(OSuite::ZHttpRequest *this)
{
  OSuite::IHttpResponse *v1; // rbx
  __int64 v4; // rax

  v1 = &this->m_httpResponse.OSuite::IHttpResponse;
  if ( !this->m_httpResponse.vfptr->IsHandled(&this->m_httpResponse.OSuite::IHttpResponse) )
    return 0i64;
  ((void (__fastcall *)(OSuite::ZHttpResponse *))this->m_httpResponse.vfptr[4].__vecDelDtor)(&this->m_httpResponse);
  v4 = (__int64)v1->vfptr->GetBufferedReader(v1);
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 64i64))(v4);
}

// File Line: 105
// RVA: 0xEDC098
unsigned __int64 __fastcall OSuite::ZHttpRequest::GetBytesSent(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttpConnection *m_pHttpConnection; // rcx

  m_pHttpConnection = this->m_pHttpConnection;
  if ( m_pHttpConnection && OSuite::ZHttpConnection::Socket(m_pHttpConnection) )
    return OSuite::ZHttpConnection::Socket(this->m_pHttpConnection)->m_nBytesSent;
  else
    return 0i64;
}

// File Line: 114
// RVA: 0xEDC05C
unsigned __int64 __fastcall OSuite::ZHttpRequest::GetBytesReceived(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttpConnection *m_pHttpConnection; // rcx

  m_pHttpConnection = this->m_pHttpConnection;
  if ( m_pHttpConnection && OSuite::ZHttpConnection::Socket(m_pHttpConnection) )
    return OSuite::ZHttpConnection::Socket(this->m_pHttpConnection)->m_nBytesReceived;
  else
    return 0i64;
}

// File Line: 125
// RVA: 0xEDBEF8
void __fastcall OSuite::ZHttpRequest::Abort(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttpConnection *m_pHttpConnection; // rcx

  m_pHttpConnection = this->m_pHttpConnection;
  if ( m_pHttpConnection )
    OSuite::ZHttpConnection::Abort(m_pHttpConnection);
  this->vfptr[40].__vecDelDtor(this, 11u);
  this->vfptr[37].__vecDelDtor(this, 512u);
}

// File Line: 144
// RVA: 0xEDC494
bool __fastcall OSuite::ZHttpRequest::SendBuffer(
        OSuite::ZHttpRequest *this,
        const void *pBuffer,
        unsigned __int64 nLength)
{
  if ( pBuffer && nLength )
    return ((__int64 (__fastcall *)(OSuite::IWriter *))this->m_streamWriter.vfptr->WriteBuffer)(&this->m_streamWriter.OSuite::IWriter);
  else
    return 0;
}

// File Line: 160
// RVA: 0xEDC444
bool __fastcall OSuite::ZHttpRequest::SendBuffer(OSuite::ZHttpRequest *this, OSuite::IReader *pReader)
{
  OSuite::IWriter *v3; // rcx
  bool v4; // di

  if ( this == (OSuite::ZHttpRequest *)-1096i64 )
    v3 = 0i64;
  else
    v3 = &this->m_streamWriter.OSuite::IWriter;
  v4 = operator<<(v3, pReader);
  if ( !v4 )
    this->vfptr[40].__vecDelDtor(this, 4u);
  return v4;
}

// File Line: 169
// RVA: 0xEDC4B0
bool __fastcall OSuite::ZHttpRequest::SendMemoryBuffer(OSuite::ZHttpRequest *this)
{
  OSuite::IReader *v2; // rdx
  OSuite::IWriter *v3; // rcx
  bool v4; // di

  if ( this == (OSuite::ZHttpRequest *)-360i64 )
    v2 = 0i64;
  else
    v2 = &this->m_bufferChain.OSuite::IReader;
  if ( this == (OSuite::ZHttpRequest *)-1096i64 )
    v3 = 0i64;
  else
    v3 = &this->m_streamWriter.OSuite::IWriter;
  v4 = operator<<(v3, v2);
  if ( !v4 )
    this->vfptr[40].__vecDelDtor(this, 4u);
  return v4;
}

// File Line: 178
// RVA: 0xEDC004
bool __fastcall OSuite::ZHttpRequest::FinishChunkedTransfer(OSuite::ZHttpRequest *this)
{
  char v1; // di

  v1 = 0;
  if ( this->m_bTransferChunked )
  {
    v1 = ((__int64 (__fastcall *)(OSuite::ZHttpStreamWriter *))this->m_streamWriter.vfptr[1].__vecDelDtor)(&this->m_streamWriter);
    if ( !v1 )
      this->vfptr[40].__vecDelDtor(this, 4u);
  }
  return v1;
}

// File Line: 205
// RVA: 0xEDBFB4
void __fastcall OSuite::ZHttpRequest::CloseHttpRequest(OSuite::ZHttpRequest *this, bool bKeepAlive)
{
  bool v3; // bl
  OSuite::ZHttpManager *v4; // rax

  if ( this->m_pHttpConnection )
  {
    v3 = this->m_bKeepAliveOverride && bKeepAlive;
    v4 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpConnectionManager::ReleaseHttpConnection(
      v4->m_httpConnectionManager,
      (OSuite::IHttpRequest *)this->m_pHttpConnection,
      v3);
    this->m_pHttpConnection = 0i64;
  }
}

// File Line: 216
// RVA: 0xEDBF3C
bool __fastcall OSuite::ZHttpRequest::AssociateWithResources(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttpManager *v2; // rax
  OSuite::ZHttpConnection *HttpConnection; // rax
  OSuite::ZHttpManager *v5; // rax

  if ( this->m_pHttpConnection )
  {
    v5 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    return OSuite::ZHttpConnectionManager::AssociateWithSocket(
             v5->m_httpConnectionManager,
             this->m_pHttpConnection,
             &this->m_url,
             0);
  }
  else
  {
    v2 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    HttpConnection = OSuite::ZHttpConnectionManager::CreateHttpConnection(v2->m_httpConnectionManager, &this->m_url, 0);
    if ( HttpConnection )
    {
      OSuite::ZHttpRequest::Init(this, HttpConnection);
      return 1;
    }
    else
    {
      this->vfptr[40].__vecDelDtor(this, 8u);
      return 0;
    }
  }
}

// File Line: 237
// RVA: 0xEDC3DC
void __fastcall OSuite::ZHttpRequest::Reset(OSuite::ZHttpRequest *this)
{
  this->m_httpResponse.vfptr->Flush(&this->m_httpResponse.OSuite::IHttpResponse);
  OSuite::ZHttpResponse::Init(&this->m_httpResponse, this->m_pHttpConnection);
  OSuite::ZHttpStreamWriter::Init(&this->m_streamWriter, this->m_pHttpConnection);
  this->m_bufferChain.vfptr->Rewind(&this->m_bufferChain.OSuite::IReader);
  OSuite::ZRedBlackTreeBase::Clear(&this->m_headers);
  this->vfptr[40].__vecDelDtor(this, 0);
}

// File Line: 247
// RVA: 0xEDC2B4
char __fastcall OSuite::ZHttpRequest::InternalMakeRequest(OSuite::ZHttpRequest *this)
{
  bool v2; // zf
  OSuite::ZObjectVtbl *vfptr; // rax
  __int64 v4; // rdx

  OSuite::ZHttpRequest::Reset(this);
  ((void (__fastcall *)(OSuite::ZHttpRequest *))this->vfptr[53].__vecDelDtor)(this);
  v2 = !OSuite::ZHttpRequest::SendRequest(this);
  vfptr = this->vfptr;
  if ( v2 )
  {
    vfptr[40].__vecDelDtor(this, 1u);
    return 0;
  }
  else
  {
    v4 = 8i64;
    if ( !this->m_nLengthToSend )
      v4 = 32i64;
    vfptr[37].__vecDelDtor(this, v4);
    return 1;
  }
}

// File Line: 269
// RVA: 0xEDC518
bool __fastcall OSuite::ZHttpRequest::SendRequest(OSuite::ZHttpRequest *this)
{
  bool IsConnected; // al
  OSuite::ZSocket::ZSocketProxyType ProxyType; // eax
  OSuite::ZHttpConnection *m_pHttpConnection; // rcx
  OSuite::ZUrl *v5; // rax
  OSuite::ZString *PathAndParameters; // rax
  OSuite::ZUrl *v7; // rax
  const char *v8; // rdx
  OSuite::ZUrl *v9; // rax
  OSuite::ZString *FakeHost; // rax
  bool v11; // al
  OSuite::ZHttpConnection *v12; // rcx
  OSuite::ZUrl *v13; // rax
  OSuite::ZString *TicketData; // rax
  OSuite::ZUrl *v15; // rax
  OSuite::ZUrl *v16; // rax
  OSuite::ZUrl *v17; // rax
  int Port; // eax
  char v19; // di
  OSuite::ZString *v20; // rax
  bool v21; // bl
  OSuite::ZHttpRequestManager *m_httpRequestManager; // rbx
  OSuite::ZString *v23; // rax
  OSuite::ZString *v24; // rax
  OSuite::ZHttpManager *v25; // rax
  unsigned __int64 v26; // rax
  OSuite::IWriterVtbl *vfptr; // rsi
  unsigned __int64 v28; // rbx
  const void *v29; // rax
  bool v30; // di
  unsigned __int64 v31; // rbx
  const char *v32; // rax
  OSuite::ZString v33; // [rsp+20h] [rbp-E0h] BYREF
  void **v34; // [rsp+38h] [rbp-C8h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase other; // [rsp+40h] [rbp-C0h] BYREF
  OSuite::ZString v36; // [rsp+A0h] [rbp-60h] BYREF
  OSuite::ZStringBuilder v37; // [rsp+B8h] [rbp-48h] BYREF
  OSuite::ZString result; // [rsp+E8h] [rbp-18h] BYREF
  void **v39; // [rsp+100h] [rbp+0h]
  void **v40; // [rsp+108h] [rbp+8h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase v41; // [rsp+110h] [rbp+10h] BYREF

  IsConnected = OSuite::ZHttpConnection::IsConnected(this->m_pHttpConnection);
  if ( IsConnected )
  {
    v37.m_Chars.m_pList = 0i64;
    OSuite::ZStringBuilder::ZStringBuilder(&v37, 0x400ui64);
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, &this->m_method);
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, " ");
    OSuite::ZHttpConnection::Socket(this->m_pHttpConnection);
    ProxyType = OSuite::ZSocket::GetProxyType();
    m_pHttpConnection = this->m_pHttpConnection;
    if ( ProxyType == ZSOCKPROXY_HTTP )
    {
      v5 = OSuite::ZHttpConnection::Url(m_pHttpConnection);
      PathAndParameters = OSuite::ZUrl::ToString(v5, &result, 0);
    }
    else
    {
      v7 = OSuite::ZHttpConnection::Url(m_pHttpConnection);
      PathAndParameters = OSuite::ZUrl::GetPathAndParameters(v7, &result);
    }
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, PathAndParameters);
    OSuite::ZString::~ZString(&result);
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, " HTTP/1.1\r\n");
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "Accept:");
    if ( OSuite::ZString::operator bool(&this->m_acceptType) )
    {
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, &this->m_acceptType);
      v8 = "\r\n";
    }
    else
    {
      v8 = "*/*\r\n";
    }
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, v8);
    if ( !OSuite::ZHttpConnection::IsPersistent(this->m_pHttpConnection) )
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "Connection:close\r\n");
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "Accept-Charset:UTF-8\r\n");
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "Accept-Encoding:identity;q=1.0, deflate;q=0\r\n");
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "Host:");
    v9 = OSuite::ZHttpConnection::Url(this->m_pHttpConnection);
    FakeHost = OSuite::ZUrl::GetFakeHost(v9);
    v11 = OSuite::ZString::operator bool(FakeHost);
    v12 = this->m_pHttpConnection;
    if ( v11 )
    {
      v13 = OSuite::ZHttpConnection::Url(v12);
      TicketData = OSuite::ZUrl::GetFakeHost(v13);
    }
    else
    {
      v15 = OSuite::ZHttpConnection::Url(v12);
      TicketData = OSuite::IOnlineAuthentication::GetTicketData(v15);
    }
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, TicketData);
    v16 = OSuite::ZHttpConnection::Url(this->m_pHttpConnection);
    if ( (unsigned int)OSuite::ZUrl::GetPort(v16) != 80 )
    {
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, ":");
      v17 = OSuite::ZHttpConnection::Url(this->m_pHttpConnection);
      Port = OSuite::ZUrl::GetPort(v17);
      OSuite::ZString::ZString(&result, Port);
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, &result);
      OSuite::ZString::~ZString(&result);
    }
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "\r\n");
    v19 = 0;
    if ( !OSuite::ZHttpStreamReader::Tell(&this->m_headers) )
      goto LABEL_25;
    v41.m_pList = 0i64;
    v41.m_pElement = 0i64;
    v41.m_parents.m_pList = 0i64;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&other, &this->m_headers);
    v39 = &OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
    v40 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v41, &other);
    other.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v41.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    v34 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    other.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( other.m_parents.m_pList )
      other.m_parents.m_pList->vfptr->__vecDelDtor(other.m_parents.m_pList, 1u);
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v41) )
    {
      result.m_pString = 0i64;
      OSuite::ZString::ZString(&result, (OSuite::ZString *)&v41.m_pElement[2]);
      v20 = OSuite::ZString::ToLower((OSuite::ZString *)&v41.m_pElement[1].m_pLeft, &v33);
      v21 = OSuite::ZString::operator==(v20, "user-agent");
      OSuite::ZString::~ZString(&v33);
      if ( v21 )
      {
        m_httpRequestManager = OSuite::TSingleton<OSuite::ZHttpManager>::Object()->m_httpRequestManager;
        v23 = OSuite::ZString::operator+(&result, &v36, " ");
        v24 = OSuite::ZString::operator+(v23, &v33, &m_httpRequestManager->m_userAgent);
        OSuite::ZString::operator=(&result, v24);
        OSuite::ZString::~ZString(&v33);
        OSuite::ZString::~ZString(&v36);
        v19 = 1;
      }
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, (OSuite::ZString *)&v41.m_pElement[1].m_pLeft);
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, ":");
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, &result);
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "\r\n");
      OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v41);
      OSuite::ZString::~ZString(&result);
    }
    v40 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v39 = &OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
    v41.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    v41.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v41.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( v41.m_parents.m_pList )
      v41.m_parents.m_pList->vfptr->__vecDelDtor(v41.m_parents.m_pList, 1u);
    if ( !v19 )
    {
LABEL_25:
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "User-Agent: ");
      v25 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, &v25->m_httpRequestManager->m_userAgent);
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "\r\n");
    }
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "\r\n");
    v26 = OSuite::ZStringBuilder::Count(&v37);
    OSuite::ZHttpWriter::Reset(&this->m_streamWriter, v26, 0, 0i64);
    vfptr = this->m_streamWriter.vfptr;
    v28 = OSuite::ZStringBuilder::Count(&v37);
    v29 = OSuite::ZUtf8Buffer::Buffer((OSuite::ZUtf8Buffer *)&v37);
    v30 = vfptr->WriteBuffer(&this->m_streamWriter.OSuite::IWriter, v29, v28);
    if ( !v30 )
    {
      result.m_pString = 0i64;
      v31 = OSuite::ZStringBuilder::Count(&v37);
      v32 = (const char *)OSuite::ZUtf8Buffer::Buffer((OSuite::ZUtf8Buffer *)&v37);
      OSuite::ZString::ZString(&result, v32, v31);
      OSuite::ZString::~ZString(&result);
    }
    OSuite::ZHttpWriter::Reset(
      &this->m_streamWriter,
      this->m_nLengthToSend,
      this->m_bTransferChunked,
      this->m_nMaxBytesPerSecond);
    OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v37);
    return v30;
  }
  return IsConnected;
}

// File Line: 359
// RVA: 0xEDC250
void __fastcall OSuite::ZHttpRequest::Init(OSuite::ZHttpRequest *this, OSuite::IHttpRequest *httpConnection)
{
  OSuite::ZHttpManager *v4; // rax

  if ( this->m_pHttpConnection )
  {
    v4 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpConnectionManager::ReleaseHttpConnection(v4->m_httpConnectionManager, httpConnection, 1);
  }
  this->m_pHttpConnection = (OSuite::ZHttpConnection *)httpConnection;
  OSuite::ZHttpResponse::Init(&this->m_httpResponse, (OSuite::ZHttpConnection *)httpConnection);
  OSuite::ZHttpStreamWriter::Init(&this->m_streamWriter, this->m_pHttpConnection);
}

// File Line: 374
// RVA: 0xEDC23C
bool __fastcall OSuite::ZHttpRequest::HasFatalError(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttpConnection *m_pHttpConnection; // rcx

  m_pHttpConnection = this->m_pHttpConnection;
  return !m_pHttpConnection || OSuite::ZHttpConnection::HasFatalError(m_pHttpConnection);
}

// File Line: 381
// RVA: 0xEDC0DC
OSuite::ZHttp::EError __fastcall OSuite::ZHttpRequest::GetLastError(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttp::EError result; // eax
  OSuite::ZHttpConnection *m_pHttpConnection; // rcx

  result = this->m_lastError;
  if ( result == HTTPERROR_OK )
  {
    result = this->m_httpResponse.vfptr->GetLastError(&this->m_httpResponse.OSuite::IHttpResponse);
    if ( result == HTTPERROR_OK )
    {
      m_pHttpConnection = this->m_pHttpConnection;
      if ( m_pHttpConnection )
        return OSuite::ZHttpConnection::GetLastError(m_pHttpConnection);
    }
  }
  return result;
}


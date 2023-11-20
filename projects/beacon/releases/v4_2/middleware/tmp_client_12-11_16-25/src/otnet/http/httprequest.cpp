// File Line: 26
// RVA: 0xEDBCC0
void __fastcall OSuite::ZHttpRequest::ZHttpRequest(OSuite::ZHttpRequest *this, OSuite::ZUrl *url, void *pParent, bool bKeepAlive, int nTimeOut)
{
  bool v5; // bl
  OSuite::ZHttpRequest *v6; // rdi
  OSuite::ZObjectAccessor *v7; // rax

  v5 = bKeepAlive;
  v6 = this;
  OSuite::ZHttpRequestBase::ZHttpRequestBase((OSuite::ZHttpRequestBase *)&this->vfptr, url, pParent, nTimeOut);
  v6->m_pHttpConnection = 0i64;
  v6->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpRequest::`vftable;
  OSuite::ZHttpResponse::ZHttpResponse(&v6->m_httpResponse);
  OSuite::ZHttpStreamWriter::ZHttpStreamWriter(&v6->m_streamWriter);
  v6->m_bKeepAliveOverride = v5;
  v7 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::RegisterObject(v7, v6->m_pParent);
  OSuite::ZHttpRequestBase::ClearClientData((OSuite::ZHttpRequestBase *)&v6->vfptr);
  v6->m_OnDataAvailableCB.m_Closure.m_pFunction = 0i64;
  v6->m_OnDataAvailableCB.m_Closure.m_pthis = 0i64;
  v6->m_OnDataNeededCB.m_Closure.m_pFunction = 0i64;
  v6->m_OnDataNeededCB.m_Closure.m_pthis = 0i64;
  v6->m_OnFinishedCB.m_Closure.m_pFunction = 0i64;
  v6->m_OnFinishedCB.m_Closure.m_pthis = 0i64;
  v6->m_bufferChain.m_bDeleteOnRead = 0;
}

// File Line: 40
// RVA: 0xEDBD5C
void __fastcall OSuite::ZHttpRequest::~ZHttpRequest(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttpRequest *v1; // rbx
  OSuite::ZObjectAccessor *v2; // rax

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpRequest::`vftable;
  v2 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::UnRegisterObject(v2, v1->m_pParent);
  OSuite::ZHttpStreamWriter::~ZHttpStreamWriter(&v1->m_streamWriter);
  OSuite::ZHttpResponse::~ZHttpResponse(&v1->m_httpResponse);
  OSuite::ZHttpRequestBase::~ZHttpRequestBase((OSuite::ZHttpRequestBase *)&v1->vfptr);
}

// File Line: 45
// RVA: 0xEDC344
char __fastcall OSuite::ZHttpRequest::Release(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttpRequest *v1; // rbx
  char v2; // di
  void *v4; // rsi
  OSuite::ZObjectAccessor *v5; // rax
  OSuite::ZObjectAccessor *v6; // rax

  v1 = this;
  v2 = 0;
  if ( this->vfptr[17].__vecDelDtor((OSuite::ZObject *)this, 2048u) )
    return 0;
  v4 = v1->m_pParent;
  v5 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::AccessObject(v5, v4);
  if ( !(unsigned __int8)v1->vfptr[17].__vecDelDtor((OSuite::ZObject *)&v1->vfptr, 2048u) )
  {
    ((void (*)(void))v1->m_streamWriter.vfptr->Flush)();
    ((void (*)(void))v1->m_httpResponse.vfptr->Flush)();
    v2 = 1;
  }
  v6 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::ReleaseObject(v6, v4);
  return v2;
}

// File Line: 65
// RVA: 0xEDCADC
char __fastcall OSuite::ZHttpRequest::Shutdown(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttpRequest *v1; // rbx
  char v2; // di
  void *v4; // rsi
  OSuite::ZObjectAccessor *v5; // rax
  OSuite::ZHttpConnection *v6; // rcx
  OSuite::ZObjectAccessor *v7; // rax

  v1 = this;
  v2 = 0;
  if ( this->vfptr[17].__vecDelDtor((OSuite::ZObject *)this, 2048u) )
    return 0;
  v4 = v1->m_pParent;
  v5 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::AccessObject(v5, v4);
  if ( !(unsigned __int8)v1->vfptr[17].__vecDelDtor((OSuite::ZObject *)&v1->vfptr, 2048u) )
  {
    ((void (*)(void))v1->m_streamWriter.vfptr->Flush)();
    ((void (*)(void))v1->m_httpResponse.vfptr->Flush)();
    v6 = v1->m_pHttpConnection;
    if ( v6 )
      OSuite::ZHttpConnection::Abort(v6);
    v1->vfptr[40].__vecDelDtor((OSuite::ZObject *)&v1->vfptr, 11u);
    v2 = 1;
  }
  v7 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::ReleaseObject(v7, v4);
  return v2;
}

// File Line: 90
// RVA: 0xEDC22C
__int64 __fastcall OSuite::ZHttpRequest::HandleResponse(OSuite::ZHttpRequest *this)
{
  return ((__int64 (*)(void))this->m_httpResponse.vfptr[1].__vecDelDtor)();
}

// File Line: 95
// RVA: 0xEDC1DC
__int64 __fastcall OSuite::ZHttpRequest::HandleData(OSuite::ZHttpRequest *this)
{
  OSuite::IHttpResponse *v1; // rbx
  OSuite::ZHttpRequest *v2; // rdi
  __int64 v4; // rax

  v1 = (OSuite::IHttpResponse *)&this->m_httpResponse.vfptr;
  v2 = this;
  if ( !this->m_httpResponse.vfptr->IsHandled((OSuite::IHttpResponse *)&this->m_httpResponse.vfptr) )
    return 0i64;
  ((void (*)(void))v2->m_httpResponse.vfptr[4].__vecDelDtor)();
  v4 = (__int64)v1->vfptr->GetBufferedReader(v1);
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 64i64))(v4);
}

// File Line: 105
// RVA: 0xEDC098
unsigned __int64 __fastcall OSuite::ZHttpRequest::GetBytesSent(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttpRequest *v1; // rbx
  OSuite::ZHttpConnection *v2; // rcx
  unsigned __int64 result; // rax

  v1 = this;
  v2 = this->m_pHttpConnection;
  if ( v2 && OSuite::ZHttpConnection::Socket(v2) )
    result = OSuite::ZHttpConnection::Socket(v1->m_pHttpConnection)->m_nBytesSent;
  else
    result = 0i64;
  return result;
}

// File Line: 114
// RVA: 0xEDC05C
unsigned __int64 __fastcall OSuite::ZHttpRequest::GetBytesReceived(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttpRequest *v1; // rbx
  OSuite::ZHttpConnection *v2; // rcx
  unsigned __int64 result; // rax

  v1 = this;
  v2 = this->m_pHttpConnection;
  if ( v2 && OSuite::ZHttpConnection::Socket(v2) )
    result = OSuite::ZHttpConnection::Socket(v1->m_pHttpConnection)->m_nBytesReceived;
  else
    result = 0i64;
  return result;
}

// File Line: 125
// RVA: 0xEDBEF8
void __fastcall OSuite::ZHttpRequest::Abort(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttpRequest *v1; // rbx
  OSuite::ZHttpConnection *v2; // rcx

  v1 = this;
  v2 = this->m_pHttpConnection;
  if ( v2 )
    OSuite::ZHttpConnection::Abort(v2);
  v1->vfptr[40].__vecDelDtor((OSuite::ZObject *)&v1->vfptr, 11u);
  v1->vfptr[37].__vecDelDtor((OSuite::ZObject *)&v1->vfptr, 512u);
}

// File Line: 144
// RVA: 0xEDC494
bool __fastcall OSuite::ZHttpRequest::SendBuffer(OSuite::ZHttpRequest *this, const void *pBuffer, unsigned __int64 nLength)
{
  bool result; // al

  if ( pBuffer && nLength )
    result = ((__int64 (*)(void))this->m_streamWriter.vfptr->WriteBuffer)();
  else
    result = 0;
  return result;
}

// File Line: 160
// RVA: 0xEDC444
bool __fastcall OSuite::ZHttpRequest::SendBuffer(OSuite::ZHttpRequest *this, OSuite::IReader *pReader)
{
  OSuite::ZHttpRequest *v2; // rbx
  OSuite::IWriter *v3; // rcx
  bool v4; // di

  v2 = this;
  if ( this == (OSuite::ZHttpRequest *)-1096i64 )
    v3 = 0i64;
  else
    v3 = (OSuite::IWriter *)&this->m_streamWriter.vfptr;
  v4 = operator<<(v3, pReader);
  if ( !v4 )
    v2->vfptr[40].__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 4u);
  return v4;
}

// File Line: 169
// RVA: 0xEDC4B0
bool __fastcall OSuite::ZHttpRequest::SendMemoryBuffer(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttpRequest *v1; // rbx
  OSuite::IReader *v2; // rdx
  OSuite::IWriter *v3; // rcx
  bool v4; // di

  v1 = this;
  if ( this == (OSuite::ZHttpRequest *)-360i64 )
    v2 = 0i64;
  else
    v2 = (OSuite::IReader *)&this->m_bufferChain.vfptr;
  if ( this == (OSuite::ZHttpRequest *)-1096i64 )
    v3 = 0i64;
  else
    v3 = (OSuite::IWriter *)&this->m_streamWriter.vfptr;
  v4 = operator<<(v3, v2);
  if ( !v4 )
    v1->vfptr[40].__vecDelDtor((OSuite::ZObject *)&v1->vfptr, 4u);
  return v4;
}

// File Line: 178
// RVA: 0xEDC004
char __fastcall OSuite::ZHttpRequest::FinishChunkedTransfer(OSuite::ZHttpRequest *this)
{
  char v1; // di
  OSuite::ZHttpRequest *v2; // rbx

  v1 = 0;
  v2 = this;
  if ( this->m_bTransferChunked )
  {
    v1 = ((__int64 (*)(void))this->m_streamWriter.vfptr[1].__vecDelDtor)();
    if ( !v1 )
      v2->vfptr[40].__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 4u);
  }
  return v1;
}

// File Line: 205
// RVA: 0xEDBFB4
void __fastcall OSuite::ZHttpRequest::CloseHttpRequest(OSuite::ZHttpRequest *this, bool bKeepAlive)
{
  OSuite::ZHttpRequest *v2; // rdi
  bool v3; // bl
  OSuite::ZHttpManager *v4; // rax

  v2 = this;
  if ( this->m_pHttpConnection )
  {
    v3 = this->m_bKeepAliveOverride != 0 ? bKeepAlive : 0;
    v4 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpConnectionManager::ReleaseHttpConnection(v4->m_httpConnectionManager, v2->m_pHttpConnection, v3);
    v2->m_pHttpConnection = 0i64;
  }
}

// File Line: 216
// RVA: 0xEDBF3C
bool __fastcall OSuite::ZHttpRequest::AssociateWithResources(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttpRequest *v1; // rbx
  OSuite::ZHttpManager *v2; // rax
  OSuite::ZHttpConnection *v3; // rax
  bool result; // al
  OSuite::ZHttpManager *v5; // rax

  v1 = this;
  if ( this->m_pHttpConnection )
  {
    v5 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    result = OSuite::ZHttpConnectionManager::AssociateWithSocket(
               v5->m_httpConnectionManager,
               v1->m_pHttpConnection,
               &v1->m_url,
               0);
  }
  else
  {
    v2 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    v3 = OSuite::ZHttpConnectionManager::CreateHttpConnection(v2->m_httpConnectionManager, &v1->m_url, 0);
    if ( v3 )
    {
      OSuite::ZHttpRequest::Init(v1, v3);
      result = 1;
    }
    else
    {
      v1->vfptr[40].__vecDelDtor((OSuite::ZObject *)&v1->vfptr, 8u);
      result = 0;
    }
  }
  return result;
}

// File Line: 237
// RVA: 0xEDC3DC
void __fastcall OSuite::ZHttpRequest::Reset(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttpRequest *v1; // rbx

  v1 = this;
  ((void (*)(void))this->m_httpResponse.vfptr->Flush)();
  OSuite::ZHttpResponse::Init(&v1->m_httpResponse, v1->m_pHttpConnection);
  OSuite::ZHttpStreamWriter::Init(&v1->m_streamWriter, v1->m_pHttpConnection);
  ((void (*)(void))v1->m_bufferChain.vfptr->Rewind)();
  OSuite::ZRedBlackTreeBase::Clear((OSuite::ZRedBlackTreeBase *)&v1->m_headers.vfptr);
  v1->vfptr[40].__vecDelDtor((OSuite::ZObject *)&v1->vfptr, 0);
}

// File Line: 247
// RVA: 0xEDC2B4
char __fastcall OSuite::ZHttpRequest::InternalMakeRequest(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttpRequest *v1; // rbx
  bool v2; // zf
  OSuite::ZObjectVtbl *v3; // rax
  signed __int64 v4; // rdx
  char result; // al

  v1 = this;
  OSuite::ZHttpRequest::Reset(this);
  ((void (__fastcall *)(OSuite::ZHttpRequest *))v1->vfptr[53].__vecDelDtor)(v1);
  v2 = OSuite::ZHttpRequest::SendRequest(v1) == 0;
  v3 = v1->vfptr;
  if ( v2 )
  {
    v3[40].__vecDelDtor((OSuite::ZObject *)&v1->vfptr, 1u);
    result = 0;
  }
  else
  {
    v4 = 8i64;
    if ( !v1->m_nLengthToSend )
      v4 = 32i64;
    v3[37].__vecDelDtor((OSuite::ZObject *)&v1->vfptr, v4);
    result = 1;
  }
  return result;
}

// File Line: 269
// RVA: 0xEDC518
bool __fastcall OSuite::ZHttpRequest::SendRequest(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttpRequest *v1; // r14
  bool v2; // al
  OSuite::ZSocket::ZSocketProxyType v3; // eax
  OSuite::ZHttpConnection *v4; // rcx
  OSuite::ZUrl *v5; // rax
  OSuite::ZString *v6; // rax
  OSuite::ZUrl *v7; // rax
  const char *v8; // rdx
  OSuite::ZUrl *v9; // rax
  OSuite::ZString *v10; // rax
  bool v11; // al
  OSuite::ZHttpConnection *v12; // rcx
  OSuite::ZUrl *v13; // rax
  OSuite::ZString *v14; // rax
  OSuite::ZUrl *v15; // rax
  OSuite::ZUrl *v16; // rax
  OSuite::ZUrl *v17; // rax
  int v18; // eax
  char v19; // di
  OSuite::ZString *v20; // rax
  bool v21; // bl
  OSuite::ZHttpRequestManager *v22; // rbx
  OSuite::ZString *v23; // rax
  OSuite::ZString *v24; // rax
  OSuite::ZHttpManager *v25; // rax
  unsigned __int64 v26; // rax
  OSuite::IWriterVtbl *v27; // rsi
  unsigned __int64 v28; // rbx
  const void *v29; // rax
  bool v30; // di
  unsigned __int64 v31; // rbx
  const char *v32; // rax
  OSuite::ZString v33; // [rsp+20h] [rbp-E0h]
  void **v34; // [rsp+38h] [rbp-C8h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase other; // [rsp+40h] [rbp-C0h]
  OSuite::ZString v36; // [rsp+A0h] [rbp-60h]
  OSuite::ZStringBuilder v37; // [rsp+B8h] [rbp-48h]
  OSuite::ZString result; // [rsp+E8h] [rbp-18h]
  void **v39; // [rsp+100h] [rbp+0h]
  void **v40; // [rsp+108h] [rbp+8h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase v41; // [rsp+110h] [rbp+10h]

  v1 = this;
  v2 = OSuite::ZHttpConnection::IsConnected(this->m_pHttpConnection);
  if ( v2 )
  {
    v37.m_Chars.m_pList = 0i64;
    OSuite::ZStringBuilder::ZStringBuilder(&v37, 0x400ui64);
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, &v1->m_method);
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, " ");
    OSuite::ZHttpConnection::Socket(v1->m_pHttpConnection);
    v3 = OSuite::ZSocket::GetProxyType();
    v4 = v1->m_pHttpConnection;
    if ( v3 == 3 )
    {
      v5 = OSuite::ZHttpConnection::Url(v4);
      v6 = OSuite::ZUrl::ToString(v5, &result, 0);
    }
    else
    {
      v7 = OSuite::ZHttpConnection::Url(v4);
      v6 = OSuite::ZUrl::GetPathAndParameters(v7, &result);
    }
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, v6);
    OSuite::ZString::~ZString(&result);
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, " HTTP/1.1\r\n");
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "Accept:");
    if ( OSuite::ZString::operator bool(&v1->m_acceptType) )
    {
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, &v1->m_acceptType);
      v8 = "\r\n";
    }
    else
    {
      v8 = "*/*\r\n";
    }
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, v8);
    if ( !OSuite::ZHttpConnection::IsPersistent(v1->m_pHttpConnection) )
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "Connection:close\r\n");
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "Accept-Charset:UTF-8\r\n");
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "Accept-Encoding:identity;q=1.0, deflate;q=0\r\n");
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "Host:");
    v9 = OSuite::ZHttpConnection::Url(v1->m_pHttpConnection);
    v10 = OSuite::ZUrl::GetFakeHost(v9);
    v11 = OSuite::ZString::operator bool(v10);
    v12 = v1->m_pHttpConnection;
    if ( v11 )
    {
      v13 = OSuite::ZHttpConnection::Url(v12);
      v14 = OSuite::ZUrl::GetFakeHost(v13);
    }
    else
    {
      v15 = OSuite::ZHttpConnection::Url(v12);
      v14 = OSuite::IOnlineAuthentication::GetTicketData(v15);
    }
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, v14);
    v16 = OSuite::ZHttpConnection::Url(v1->m_pHttpConnection);
    if ( (unsigned int)OSuite::ZUrl::GetPort(v16) != 80 )
    {
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, ":");
      v17 = OSuite::ZHttpConnection::Url(v1->m_pHttpConnection);
      v18 = OSuite::ZUrl::GetPort(v17);
      OSuite::ZString::ZString(&result, v18);
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, &result);
      OSuite::ZString::~ZString(&result);
    }
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "\r\n");
    v19 = 0;
    if ( !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v1->m_headers.vfptr) )
      goto LABEL_31;
    v41.m_pList = 0i64;
    v41.m_pElement = 0i64;
    v41.m_parents.m_pList = 0i64;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&other, (OSuite::ZRedBlackTreeBase *)&v1->m_headers.vfptr);
    v39 = &OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
    v40 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v41, &other);
    other.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v41.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    v34 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    other.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( other.m_parents.m_pList )
      other.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)other.m_parents.m_pList, 1u);
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v41) )
    {
      result.m_pString = 0i64;
      OSuite::ZString::ZString(&result, (OSuite::ZString *)&v41.m_pElement[2]);
      v20 = OSuite::ZString::ToLower((OSuite::ZString *)&v41.m_pElement[1].m_pLeft, &v33);
      v21 = OSuite::ZString::operator==(v20, "user-agent");
      OSuite::ZString::~ZString(&v33);
      if ( v21 )
      {
        v22 = OSuite::TSingleton<OSuite::ZHttpManager>::Object()->m_httpRequestManager;
        v23 = OSuite::ZString::operator+(&result, &v36, " ");
        v24 = OSuite::ZString::operator+(v23, &v33, &v22->m_userAgent);
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
    v40 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v39 = &OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
    v41.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    v41.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v41.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( v41.m_parents.m_pList )
      v41.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)v41.m_parents.m_pList, 1u);
    if ( !v19 )
    {
LABEL_31:
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "User-Agent: ");
      v25 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, &v25->m_httpRequestManager->m_userAgent);
      OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "\r\n");
    }
    OSuite::ZUtf8Buffer::Append((OSuite::ZUtf8Buffer *)&v37, "\r\n");
    v26 = OSuite::ZStringBuilder::Count(&v37);
    OSuite::ZHttpWriter::Reset((OSuite::ZHttpWriter *)&v1->m_streamWriter.vfptr, v26, 0, 0i64);
    v27 = v1->m_streamWriter.vfptr;
    v28 = OSuite::ZStringBuilder::Count(&v37);
    v29 = OSuite::ZUtf8Buffer::Buffer((OSuite::ZUtf8Buffer *)&v37);
    v30 = v27->WriteBuffer((OSuite::IWriter *)&v1->m_streamWriter.vfptr, v29, v28);
    if ( !v30 )
    {
      result.m_pString = 0i64;
      v31 = OSuite::ZStringBuilder::Count(&v37);
      v32 = (const char *)OSuite::ZUtf8Buffer::Buffer((OSuite::ZUtf8Buffer *)&v37);
      OSuite::ZString::ZString(&result, v32, v31);
      OSuite::ZString::~ZString(&result);
    }
    OSuite::ZHttpWriter::Reset(
      (OSuite::ZHttpWriter *)&v1->m_streamWriter.vfptr,
      v1->m_nLengthToSend,
      v1->m_bTransferChunked,
      v1->m_nMaxBytesPerSecond);
    OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v37);
    v2 = v30;
  }
  return v2;
}

// File Line: 359
// RVA: 0xEDC250
void __fastcall OSuite::ZHttpRequest::Init(OSuite::ZHttpRequest *this, OSuite::ZHttpConnection *httpConnection)
{
  OSuite::ZHttpConnection *v2; // rdi
  OSuite::ZHttpRequest *v3; // rbx
  OSuite::ZHttpManager *v4; // rax

  v2 = httpConnection;
  v3 = this;
  if ( this->m_pHttpConnection )
  {
    v4 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpConnectionManager::ReleaseHttpConnection(v4->m_httpConnectionManager, v2, 1);
  }
  v3->m_pHttpConnection = v2;
  OSuite::ZHttpResponse::Init(&v3->m_httpResponse, v2);
  OSuite::ZHttpStreamWriter::Init(&v3->m_streamWriter, v3->m_pHttpConnection);
}

// File Line: 374
// RVA: 0xEDC23C
char __fastcall OSuite::ZHttpRequest::HasFatalError(OSuite::ZHttpRequest *this)
{
  JUMPOUT(this->m_pHttpConnection, 0i64, OSuite::ZHttpConnection::HasFatalError);
  return 1;
}

// File Line: 381
// RVA: 0xEDC0DC
OSuite::ZHttp::EError __fastcall OSuite::ZHttpRequest::GetLastError(OSuite::ZHttpRequest *this)
{
  OSuite::ZHttp::EError result; // eax
  OSuite::ZHttpRequest *v2; // rbx
  OSuite::ZHttpConnection *v3; // rcx

  result = this->m_lastError;
  v2 = this;
  if ( result == HTTPERROR_OK )
  {
    result = ((unsigned int (*)(void))this->m_httpResponse.vfptr->GetLastError)();
    if ( result == HTTPERROR_OK )
    {
      v3 = v2->m_pHttpConnection;
      if ( v3 )
        result = OSuite::ZHttpConnection::GetLastError(v3);
    }
  }
  return result;
}


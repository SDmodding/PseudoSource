// File Line: 27
// RVA: 0xEDFD98
void __fastcall OSuite::ZHttpResponse::ZHttpResponse(OSuite::ZHttpResponse *this)
{
  OSuite::IReader *v2; // rdx

  OSuite::ZHttpResponseBase::ZHttpResponseBase(this);
  this->OSuite::ZHttpResponseBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpResponse::`vftable{for `OSuite::ZObject};
  this->OSuite::ZHttpResponseBase::OSuite::IHttpResponse::vfptr = (OSuite::IHttpResponseVtbl *)&OSuite::ZHttpResponse::`vftable{for `OSuite::IHttpResponse};
  if ( this == (OSuite::ZHttpResponse *)-256i64 )
    v2 = 0i64;
  else
    v2 = &this->m_streamReader.OSuite::IReader;
  OSuite::ZBufferedReader::ZBufferedReader(&this->m_bufferedReader, v2, 0x8000ui64, 0);
  OSuite::ZHttpStreamReader::ZHttpStreamReader(&this->m_streamReader);
  OSuite::ZUrl::ZUrl(&this->m_redirectedUrl);
  this->m_httpConnection = 0i64;
}

// File Line: 35
// RVA: 0xEDFE18
void __fastcall OSuite::ZHttpResponse::~ZHttpResponse(OSuite::ZHttpResponse *this)
{
  OSuite::ZUrl *p_m_redirectedUrl; // rcx

  this->OSuite::ZHttpResponseBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpResponse::`vftable{for `OSuite::ZObject};
  p_m_redirectedUrl = &this->m_redirectedUrl;
  p_m_redirectedUrl[-2].m_urlParameters.m_parameters.m_pTop = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::ZHttpResponse::`vftable{for `OSuite::IHttpResponse};
  OSuite::ZUrl::~ZUrl(p_m_redirectedUrl);
  OSuite::ZHttpStreamReader::~ZHttpStreamReader(&this->m_streamReader);
  OSuite::ZBufferedReader::~ZBufferedReader(&this->m_bufferedReader);
  OSuite::ZHttpResponseBase::~ZHttpResponseBase(this);
}

// File Line: 42
// RVA: 0xEDFED4
OSuite::ZBufferedReader *__fastcall OSuite::ZHttpResponse::GetBufferedReader(OSuite::ZHttpResponse *this)
{
  __int64 v1; // rdx

  v1 = 0i64;
  if ( this != (OSuite::ZHttpResponse *)-160i64 )
    return &this->m_bufferedReader;
  return (OSuite::ZBufferedReader *)v1;
}

// File Line: 51
// RVA: 0xEDFEA8
void __fastcall OSuite::ZHttpResponse::Flush(OSuite::ZHttpResponse *this)
{
  OSuite::ZBufferedReader *p_m_bufferedReader; // rbx

  p_m_bufferedReader = &this->m_bufferedReader;
  if ( !((unsigned __int8 (__fastcall *)(OSuite::ZBufferedReader *))p_m_bufferedReader->OSuite::ZObject::vfptr[10].__vecDelDtor)(p_m_bufferedReader) )
    ((void (__fastcall *)(OSuite::ZBufferedReader *))p_m_bufferedReader->OSuite::ZObject::vfptr[3].__vecDelDtor)(p_m_bufferedReader);
}

// File Line: 61
// RVA: 0xEE0490
unsigned __int64 __fastcall OSuite::ZHttpResponse::Prefetch(OSuite::ZHttpResponse *this)
{
  if ( this->m_bIsHandled )
    return OSuite::ZBufferedReader::Prefetch(&this->m_bufferedReader);
  else
    return 0i64;
}

// File Line: 71
// RVA: 0xEE04A8
bool __fastcall OSuite::ZHttpResponse::PrefetchCompleted(OSuite::ZHttpResponse *this)
{
  if ( BYTE1(this->m_nMinorVersion) )
    return (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&this->m_bufferedReader.m_memoryBufferChain.m_bDeleteOnRead
                                             + 80i64))(*(_QWORD *)&this->m_bufferedReader.m_memoryBufferChain.m_bDeleteOnRead);
  else
    return 0;
}

// File Line: 82
// RVA: 0xEE04C4
void __fastcall OSuite::ZHttpResponse::ReadHeaders(OSuite::ZHttpResponse *this)
{
  OSuite::ZSocket *i; // rax
  unsigned __int64 v3; // rbx
  char v4; // al
  OSuite::ZString *v5; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::ZString value; // [rsp+38h] [rbp-C8h] BYREF
  OSuite::ZString key; // [rsp+50h] [rbp-B0h] BYREF
  char pszString[256]; // [rsp+70h] [rbp-90h] BYREF

  for ( i = OSuite::ZHttpConnection::Socket(this->m_httpConnection);
        OSuite::ZSocket::ReceiveString(i, pszString, 0x100ui64) && pszString[0] != 10;
        i = OSuite::ZHttpConnection::Socket(this->m_httpConnection) )
  {
    v3 = 0i64;
    while ( 1 )
    {
      v4 = tolower_0(pszString[v3]);
      pszString[v3] = v4;
      if ( v4 == 58 )
        break;
      if ( ++v3 >= 0x100 )
        goto LABEL_11;
    }
    key.m_pString = 0i64;
    OSuite::ZString::ZString(&key, pszString, v3);
    value.m_pString = 0i64;
    OSuite::ZString::ZString(&value, &pszString[v3 + 1]);
    if ( OSuite::ZString::operator bool(&value) )
    {
      v5 = OSuite::ZString::Trim(&value, &result);
      OSuite::ZString::operator=(&value, v5);
      OSuite::ZString::~ZString(&result);
      if ( OSuite::ZString::operator bool(&value) )
        OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
          &this->m_ResponseHeaders,
          &key,
          &value);
    }
    OSuite::ZString::~ZString(&value);
    OSuite::ZString::~ZString(&key);
LABEL_11:
    ;
  }
}

// File Line: 122
// RVA: 0xEE00A0
void __fastcall OSuite::ZHttpResponse::Init(OSuite::ZHttpResponse *this, OSuite::ZHttpConnection *httpConnection)
{
  OSuite::ZUrl *v4; // rax
  OSuite::ZUrl v5; // [rsp+20h] [rbp-E8h] BYREF

  OSuite::ZHttpResponseBase::Init(this);
  this->m_httpConnection = httpConnection;
  OSuite::ZUrl::ZUrl(&v5);
  OSuite::ZUrl::operator=(&this->m_redirectedUrl, v4);
  OSuite::ZUrl::~ZUrl(&v5);
  OSuite::ZHttpStreamReader::Init(&this->m_streamReader, 0i64, 0i64, 0);
}

// File Line: 136
// RVA: 0xEE0064
__int64 __fastcall OSuite::ZHttpResponse::HandleConnectionHeader(
        OSuite::ZHttpResponse *this,
        OSuite::ZString *sConnection)
{
  if ( !OSuite::ZString::operator==(sConnection, "close") )
    return 0i64;
  OSuite::ZHttpConnection::SetPersistent(this->m_httpConnection, 0);
  return 9i64;
}

// File Line: 149
// RVA: 0xEE0108
char __fastcall OSuite::ZHttpResponse::InternalHandleResponse(OSuite::ZHttpResponse *this)
{
  OSuite::ZHttpConnection *m_httpConnection; // rcx
  OSuite::ZSocket *v3; // rax
  int v4; // r9d
  int v5; // eax
  char v6; // r14
  int v7; // r9d
  int v8; // r9d
  OSuite::ZHttp::EError v9; // r15d
  int v10; // edx
  OSuite::ZLog *v12; // rax
  OSuite::ZString *p_m_pLeft; // rbx
  const char *v14; // rdi
  const char *v15; // rax
  OSuite::ZHttpResponse *v16; // rcx
  OSuite::ZHttp::EError v17; // edx
  char v18[4]; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::ZTextDecoder *pDecoder; // [rsp+28h] [rbp-D8h] BYREF
  bool bTransferChunked; // [rsp+30h] [rbp-D0h] BYREF
  unsigned __int64 nContentLength; // [rsp+38h] [rbp-C8h] BYREF
  OSuite::ZStringBuilder zs; // [rsp+40h] [rbp-C0h] BYREF
  void **v23; // [rsp+70h] [rbp-90h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase v24; // [rsp+78h] [rbp-88h] BYREF
  OSuite::ZHttpParser pszString[32]; // [rsp+E0h] [rbp-20h] BYREF

  m_httpConnection = this->m_httpConnection;
  LOBYTE(pszString[0].vfptr) = 0;
  v3 = OSuite::ZHttpConnection::Socket(m_httpConnection);
  if ( OSuite::ZSocket::ReceiveString(v3, (char *)pszString, 0x100ui64) )
  {
    if ( strncmp((const char *)pszString, "HTTP/", 5ui64) )
    {
      if ( LOBYTE(pszString[0].vfptr) )
        return OSuite::ZHttpConnection::IsPersistent(this->m_httpConnection) && this->m_nStatus / 100 == 2;
      return 0;
    }
    *(_DWORD *)v18 = 5;
    v5 = OSuite::ZHttpParser::parsebase<char>(pszString, v18, (int *)0xA, v4);
    v6 = 1;
    ++*(_DWORD *)v18;
    this->m_nMajorVersion = v5;
    this->m_nMinorVersion = OSuite::ZHttpParser::parsebase<char>(pszString, v18, (int *)0xA, v7);
    this->m_nStatus = OSuite::ZHttpParser::parsebase<char>(pszString, v18, (int *)0xA, v8);
    OSuite::ZHttpResponse::ReadHeaders(this);
    nContentLength = 0i64;
    pDecoder = 0i64;
    this->m_bContentIsText = 1;
    bTransferChunked = 0;
    v9 = OSuite::ZHttpResponseBase::HandleHeaders(this, &nContentLength, &bTransferChunked, &pDecoder);
    OSuite::ZHttpStreamReader::Init(&this->m_streamReader, this->m_httpConnection, nContentLength, bTransferChunked);
    this->m_bufferedReader.vfptr[1].__vecDelDtor(
      &this->m_bufferedReader.OSuite::IBufferedReader,
      (unsigned int)pDecoder);
    this->m_bIsHandled = 1;
    v10 = this->m_nStatus / 100;
    switch ( v10 )
    {
      case 1:
        return ((__int64 (__fastcall *)(OSuite::ZHttpResponse *))this->OSuite::ZHttpResponseBase::OSuite::ZObject::vfptr[2].__vecDelDtor)(this);
      case 2:
        return v6;
      case 3:
        return OSuite::ZHttpResponse::Handle3xxStatus(this);
    }
    v12 = OSuite::TSingleton<OSuite::ZLog>::Object();
    if ( OSuite::ZMetric::TStoredData<double>::JSonQuotesRequired(v12) )
    {
      zs.m_Chars.m_pList = 0i64;
      OSuite::ZStringBuilder::ZStringBuilder(&zs, 0x100ui64);
      OSuite::ZStringBuilder::AppendFormat(&zs, "Received HTTP error %d:\n<HEADERS>", (unsigned int)this->m_nStatus);
      v24.m_parents.m_pList = 0i64;
      *(_OWORD *)&v24.m_pList = 0i64;
      v23 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
      OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v24, &this->m_ResponseHeaders);
      v24.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
      while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v24) )
      {
        p_m_pLeft = (OSuite::ZString *)&v24.m_pElement[1].m_pLeft;
        v14 = OSuite::ZString::c_str((OSuite::ZString *)&v24.m_pElement[2]);
        v15 = OSuite::ZString::c_str(p_m_pLeft);
        OSuite::ZStringBuilder::AppendFormat(&zs, "    %s : %s\n", v15, v14);
        OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v24);
      }
      v23 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
      v24.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
      v24.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
      v24.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
      if ( v24.m_parents.m_pList )
        v24.m_parents.m_pList->vfptr->__vecDelDtor(v24.m_parents.m_pList, 1u);
      OSuite::ZStringBuilder::Append(&zs, "</HEADERS><BODY>\n");
      OSuite::ZHttpResponseBase::HandleOsError(
        this,
        (OSuite::IReader *)((unsigned __int64)&this->m_bufferedReader.OSuite::IBufferedReader & ((unsigned __int128)-(__int128)(unsigned __int64)&this->m_bufferedReader >> 64)),
        &zs);
      OSuite::ZStringBuilder::Append(&zs, "</BODY>");
      OSuite::ZUtf8Buffer::~ZUtf8Buffer(&zs);
    }
    v16 = this;
    v17 = HTTPERROR_RESPONSESTATUSCODE;
    if ( v9 )
      v17 = v9;
  }
  else
  {
    v17 = HTTPERROR_RESPONSERECEIVEFAILED;
    v16 = this;
  }
  OSuite::ZHttpResponseBase::SetLastError(v16, v17);
  return 0;
}

// File Line: 238
// RVA: 0xEDFF10
char __fastcall OSuite::ZHttpResponse::Handle3xxStatus(OSuite::ZHttpResponse *this)
{
  int m_nStatus; // ecx
  OSuite::ZString *v4; // rax
  OSuite::ZHttpConnection *m_httpConnection; // rcx
  OSuite::ZUrl *v6; // rax
  OSuite::ZUrl *v7; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::ZString sPath; // [rsp+38h] [rbp-C8h] BYREF
  OSuite::ZUrl other; // [rsp+50h] [rbp-B0h] BYREF

  m_nStatus = this->m_nStatus;
  if ( (unsigned int)(m_nStatus - 301) <= 1 )
  {
    sPath.m_pString = 0i64;
    OSuite::ZString::ZString(&result, "location");
    (*(void (__fastcall **)(OSuite::IHttpResponse *, OSuite::ZString *, OSuite::ZString *))this->OSuite::ZHttpResponseBase::OSuite::IHttpResponse::vfptr->gap8)(
      &this->OSuite::IHttpResponse,
      &sPath,
      &result);
    OSuite::ZString::~ZString(&result);
    if ( OSuite::ZString::operator bool(&sPath) )
    {
      v4 = OSuite::ZString::Trim(&sPath, &result);
      OSuite::ZString::operator=(&sPath, v4);
      OSuite::ZString::~ZString(&result);
      m_httpConnection = this->m_httpConnection;
      other.m_sProtocol.m_pString = 0i64;
      other.m_sHost.m_pString = 0i64;
      other.m_sFakeHost.m_pString = 0i64;
      other.m_sPath.m_pString = 0i64;
      other.m_urlParameters.m_parameters.m_pTop = 0i64;
      other.m_urlParameters.m_arrayParameters.m_pTop = 0i64;
      v6 = OSuite::ZHttpConnection::Url(m_httpConnection);
      OSuite::ZUrl::ZUrl(&other, v6, &sPath);
      v7 = OSuite::ZHttpConnection::Url(this->m_httpConnection);
      if ( !OSuite::ZUrl::operator==(&other, v7) )
        OSuite::ZUrl::operator=(&this->m_redirectedUrl, &other);
      OSuite::ZUrl::~ZUrl(&other);
    }
    OSuite::ZString::~ZString(&sPath);
  }
  else if ( m_nStatus == 304 )
  {
    return 1;
  }
  return 0;
}


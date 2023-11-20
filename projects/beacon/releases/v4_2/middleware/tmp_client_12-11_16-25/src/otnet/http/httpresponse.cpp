// File Line: 27
// RVA: 0xEDFD98
void __fastcall OSuite::ZHttpResponse::ZHttpResponse(OSuite::ZHttpResponse *this)
{
  OSuite::ZHttpResponse *v1; // rbx
  OSuite::IReader *v2; // rdx

  v1 = this;
  OSuite::ZHttpResponseBase::ZHttpResponseBase((OSuite::ZHttpResponseBase *)&this->vfptr);
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpResponse::`vftable'{for `OSuite::ZObject'};
  v1->vfptr = (OSuite::IHttpResponseVtbl *)&OSuite::ZHttpResponse::`vftable'{for `OSuite::IHttpResponse'};
  if ( v1 == (OSuite::ZHttpResponse *)-256i64 )
    v2 = 0i64;
  else
    v2 = (OSuite::IReader *)&v1->m_streamReader.vfptr;
  OSuite::ZBufferedReader::ZBufferedReader(&v1->m_bufferedReader, v2, 0x8000ui64, 0);
  OSuite::ZHttpStreamReader::ZHttpStreamReader(&v1->m_streamReader);
  OSuite::ZUrl::ZUrl(&v1->m_redirectedUrl);
  v1->m_httpConnection = 0i64;
}

// File Line: 35
// RVA: 0xEDFE18
void __fastcall OSuite::ZHttpResponse::~ZHttpResponse(OSuite::ZHttpResponse *this)
{
  OSuite::ZHttpResponse *v1; // rbx
  OSuite::ZUrl *v2; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpResponse::`vftable'{for `OSuite::ZObject'};
  v2 = &this->m_redirectedUrl;
  v2[-2].m_urlParameters.m_parameters.m_pTop = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::ZHttpResponse::`vftable'{for `OSuite::IHttpResponse'};
  OSuite::ZUrl::~ZUrl(v2);
  OSuite::ZHttpStreamReader::~ZHttpStreamReader(&v1->m_streamReader);
  OSuite::ZBufferedReader::~ZBufferedReader(&v1->m_bufferedReader);
  OSuite::ZHttpResponseBase::~ZHttpResponseBase((OSuite::ZHttpResponseBase *)&v1->vfptr);
}

// File Line: 42
// RVA: 0xEDFED4
OSuite::ZBufferedReader *__fastcall OSuite::ZHttpResponse::GetBufferedReader(OSuite::ZHttpResponse *this)
{
  OSuite::ZBufferedReader *v1; // rdx

  v1 = 0i64;
  if ( this != (OSuite::ZHttpResponse *)-160i64 )
    v1 = &this->m_bufferedReader;
  return v1;
}

// File Line: 51
// RVA: 0xEDFEA8
void __fastcall OSuite::ZHttpResponse::Flush(OSuite::ZHttpResponse *this)
{
  char *v1; // rbx

  v1 = (char *)&this->m_bufferedReader;
  if ( !(*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v1 + 80i64))(v1) )
    (*(void (__fastcall **)(char *))(*(_QWORD *)v1 + 24i64))(v1);
}

// File Line: 61
// RVA: 0xEE0490
unsigned __int64 __fastcall OSuite::ZHttpResponse::Prefetch(OSuite::ZHttpResponse *this)
{
  unsigned __int64 result; // rax

  if ( this->m_bIsHandled )
    result = OSuite::ZBufferedReader::Prefetch(&this->m_bufferedReader);
  else
    result = 0i64;
  return result;
}

// File Line: 71
// RVA: 0xEE04A8
bool __fastcall OSuite::ZHttpResponse::PrefetchCompleted(OSuite::ZHttpResponse *this)
{
  bool result; // al

  if ( BYTE1(this->m_nMinorVersion) )
    result = (*(__int64 (**)(void))(**(_QWORD **)&this->m_bufferedReader.m_memoryBufferChain.m_bDeleteOnRead + 80i64))();
  else
    result = 0;
  return result;
}

// File Line: 82
// RVA: 0xEE04C4
void __fastcall OSuite::ZHttpResponse::ReadHeaders(OSuite::ZHttpResponse *this)
{
  OSuite::ZHttpResponse *v1; // rdi
  OSuite::ZSocket *i; // rax
  unsigned __int64 v3; // rbx
  char v4; // al
  OSuite::ZString *v5; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-E0h]
  OSuite::ZString value; // [rsp+38h] [rbp-C8h]
  OSuite::ZString key; // [rsp+50h] [rbp-B0h]
  char pszString; // [rsp+70h] [rbp-90h]
  char v10[255]; // [rsp+71h] [rbp-8Fh]

  v1 = this;
  for ( i = OSuite::ZHttpConnection::Socket(this->m_httpConnection);
        OSuite::ZSocket::ReceiveString(i, &pszString, 0x100ui64) && pszString != 10;
        i = OSuite::ZHttpConnection::Socket(v1->m_httpConnection) )
  {
    v3 = 0i64;
    while ( 1 )
    {
      v4 = tolower_0(*(&pszString + v3));
      *(&pszString + v3) = v4;
      if ( v4 == 58 )
        break;
      if ( ++v3 >= 0x100 )
        goto LABEL_11;
    }
    key.m_pString = 0i64;
    OSuite::ZString::ZString(&key, &pszString, v3);
    value.m_pString = 0i64;
    OSuite::ZString::ZString(&value, &v10[v3]);
    if ( OSuite::ZString::operator bool(&value) )
    {
      v5 = OSuite::ZString::Trim(&value, &result);
      OSuite::ZString::operator=(&value, v5);
      OSuite::ZString::~ZString(&result);
      if ( OSuite::ZString::operator bool(&value) )
        OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
          &v1->m_ResponseHeaders,
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
  OSuite::ZHttpConnection *v2; // rbx
  OSuite::ZHttpResponse *v3; // rdi
  OSuite::ZUrl *v4; // rax
  OSuite::ZUrl v5; // [rsp+20h] [rbp-E8h]

  v2 = httpConnection;
  v3 = this;
  OSuite::ZHttpResponseBase::Init((OSuite::ZHttpResponseBase *)&this->vfptr);
  v3->m_httpConnection = v2;
  OSuite::ZUrl::ZUrl(&v5);
  OSuite::ZUrl::operator=(&v3->m_redirectedUrl, v4);
  OSuite::ZUrl::~ZUrl(&v5);
  OSuite::ZHttpStreamReader::Init(&v3->m_streamReader, 0i64, 0i64, 0);
}

// File Line: 136
// RVA: 0xEE0064
signed __int64 __fastcall OSuite::ZHttpResponse::HandleConnectionHeader(OSuite::ZHttpResponse *this, OSuite::ZString *sConnection)
{
  OSuite::ZHttpResponse *v2; // rbx

  v2 = this;
  if ( !OSuite::ZString::operator==(sConnection, "close") )
    return 0i64;
  OSuite::ZHttpConnection::SetPersistent(v2->m_httpConnection, 0);
  return 9i64;
}

// File Line: 149
// RVA: 0xEE0108
char __fastcall OSuite::ZHttpResponse::InternalHandleResponse(OSuite::ZHttpResponse *this)
{
  OSuite::ZHttpResponse *v1; // rsi
  OSuite::ZHttpConnection *v2; // rcx
  OSuite::ZSocket *v3; // rax
  int v4; // er9
  int v5; // eax
  char v6; // r14
  int v7; // er9
  int v8; // er9
  OSuite::ZHttp::EError v9; // er15
  int v10; // edx
  OSuite::ZLog *v12; // rax
  OSuite::ZString *v13; // rbx
  const char *v14; // rdi
  const char *v15; // rax
  OSuite::ZHttpResponseBase *v16; // rcx
  OSuite::ZHttp::EError v17; // edx
  char v18[4]; // [rsp+20h] [rbp-E0h]
  OSuite::ZTextDecoder *pDecoder; // [rsp+28h] [rbp-D8h]
  bool bTransferChunked; // [rsp+30h] [rbp-D0h]
  unsigned __int64 nContentLength; // [rsp+38h] [rbp-C8h]
  OSuite::ZStringBuilder zs; // [rsp+40h] [rbp-C0h]
  void **v23; // [rsp+70h] [rbp-90h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase v24; // [rsp+78h] [rbp-88h]
  char pszString; // [rsp+E0h] [rbp-20h]

  v1 = this;
  v2 = this->m_httpConnection;
  pszString = 0;
  v3 = OSuite::ZHttpConnection::Socket(v2);
  if ( OSuite::ZSocket::ReceiveString(v3, &pszString, 0x100ui64) )
  {
    if ( strncmp(&pszString, "HTTP/", 5ui64) )
    {
      if ( pszString )
        return OSuite::ZHttpConnection::IsPersistent(v1->m_httpConnection) && v1->m_nStatus / 100 == 2;
      return 0;
    }
    *(_DWORD *)v18 = 5;
    v5 = OSuite::ZHttpParser::parsebase<char>((OSuite::ZHttpParser *)&pszString, v18, (int *)0xA, v4);
    v6 = 1;
    ++*(_DWORD *)v18;
    v1->m_nMajorVersion = v5;
    v1->m_nMinorVersion = OSuite::ZHttpParser::parsebase<char>((OSuite::ZHttpParser *)&pszString, v18, (int *)0xA, v7);
    v1->m_nStatus = OSuite::ZHttpParser::parsebase<char>((OSuite::ZHttpParser *)&pszString, v18, (int *)0xA, v8);
    OSuite::ZHttpResponse::ReadHeaders(v1);
    nContentLength = 0i64;
    pDecoder = 0i64;
    v1->m_bContentIsText = 1;
    bTransferChunked = 0;
    v9 = OSuite::ZHttpResponseBase::HandleHeaders(
           (OSuite::ZHttpResponseBase *)&v1->vfptr,
           &nContentLength,
           &bTransferChunked,
           &pDecoder);
    OSuite::ZHttpStreamReader::Init(&v1->m_streamReader, v1->m_httpConnection, nContentLength, bTransferChunked);
    v1->m_bufferedReader.vfptr[1].__vecDelDtor((OSuite::IReader *)&v1->m_bufferedReader.vfptr, (unsigned int)pDecoder);
    v1->m_bIsHandled = 1;
    v10 = v1->m_nStatus / 100;
    switch ( v10 )
    {
      case 1:
        return ((__int64 (__fastcall *)(OSuite::ZHttpResponse *))v1->vfptr[2].__vecDelDtor)(v1);
      case 2:
        return v6;
      case 3:
        return OSuite::ZHttpResponse::Handle3xxStatus(v1);
    }
    v12 = OSuite::TSingleton<OSuite::ZLog>::Object();
    if ( OSuite::ZMetric::TStoredData<double>::JSonQuotesRequired(v12) )
    {
      zs.m_Chars.m_pList = 0i64;
      OSuite::ZStringBuilder::ZStringBuilder(&zs, 0x100ui64);
      OSuite::ZStringBuilder::AppendFormat(&zs, "Received HTTP error %d:\n<HEADERS>", (unsigned int)v1->m_nStatus);
      v24.m_parents.m_pList = 0i64;
      _mm_store_si128((__m128i *)&v24.m_pList, (__m128i)0i64);
      v23 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
      OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
        &v24,
        (OSuite::ZRedBlackTreeBase *)&v1->m_ResponseHeaders.vfptr);
      v24.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
      while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v24) )
      {
        v13 = (OSuite::ZString *)&v24.m_pElement[1].m_pLeft;
        v14 = OSuite::ZString::c_str((OSuite::ZString *)&v24.m_pElement[2]);
        v15 = OSuite::ZString::c_str(v13);
        OSuite::ZStringBuilder::AppendFormat(&zs, "    %s : %s\n", v15, v14);
        OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v24);
      }
      v23 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
      v24.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
      v24.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
      v24.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
      if ( v24.m_parents.m_pList )
        v24.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)v24.m_parents.m_pList, 1u);
      OSuite::ZStringBuilder::Append(&zs, "</HEADERS><BODY>\n");
      OSuite::ZHttpResponseBase::HandleOsError(
        (OSuite::ZHttpResponseBase *)&v1->vfptr,
        (OSuite::IReader *)((unsigned __int64)&v1->m_bufferedReader.vfptr & -(signed __int64)(&v1->m_bufferedReader != 0i64)),
        &zs);
      OSuite::ZStringBuilder::Append(&zs, "</BODY>");
      OSuite::ZUtf8Buffer::~ZUtf8Buffer(&zs);
    }
    v16 = (OSuite::ZHttpResponseBase *)&v1->vfptr;
    v17 = 10;
    if ( v9 )
      v17 = v9;
  }
  else
  {
    v17 = 2;
    v16 = (OSuite::ZHttpResponseBase *)&v1->vfptr;
  }
  OSuite::ZHttpResponseBase::SetLastError(v16, v17);
  return 0;
}

// File Line: 238
// RVA: 0xEDFF10
char __fastcall OSuite::ZHttpResponse::Handle3xxStatus(OSuite::ZHttpResponse *this)
{
  OSuite::ZHttpResponse *v1; // rbx
  int v2; // ecx
  OSuite::ZString *v4; // rax
  OSuite::ZHttpConnection *v5; // rcx
  OSuite::ZUrl *v6; // rax
  OSuite::ZUrl *v7; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-E0h]
  OSuite::ZString sPath; // [rsp+38h] [rbp-C8h]
  OSuite::ZUrl other; // [rsp+50h] [rbp-B0h]

  v1 = this;
  v2 = this->m_nStatus;
  if ( (unsigned int)(v2 - 301) <= 1 )
  {
    sPath.m_pString = 0i64;
    OSuite::ZString::ZString(&result, "location");
    (*(void (__fastcall **)(OSuite::IHttpResponseVtbl **, OSuite::ZString *, OSuite::ZString *))v1->vfptr->gap8)(
      &v1->vfptr,
      &sPath,
      &result);
    OSuite::ZString::~ZString(&result);
    if ( OSuite::ZString::operator bool(&sPath) )
    {
      v4 = OSuite::ZString::Trim(&sPath, &result);
      OSuite::ZString::operator=(&sPath, v4);
      OSuite::ZString::~ZString(&result);
      v5 = v1->m_httpConnection;
      other.m_sProtocol.m_pString = 0i64;
      other.m_sHost.m_pString = 0i64;
      other.m_sFakeHost.m_pString = 0i64;
      other.m_sPath.m_pString = 0i64;
      other.m_urlParameters.m_parameters.m_pTop = 0i64;
      other.m_urlParameters.m_arrayParameters.m_pTop = 0i64;
      v6 = OSuite::ZHttpConnection::Url(v5);
      OSuite::ZUrl::ZUrl(&other, v6, &sPath);
      v7 = OSuite::ZHttpConnection::Url(v1->m_httpConnection);
      if ( !OSuite::ZUrl::operator==(&other, v7) )
        OSuite::ZUrl::operator=(&v1->m_redirectedUrl, &other);
      OSuite::ZUrl::~ZUrl(&other);
    }
    OSuite::ZString::~ZString(&sPath);
  }
  else if ( v2 == 304 )
  {
    return 1;
  }
  return 0;
}


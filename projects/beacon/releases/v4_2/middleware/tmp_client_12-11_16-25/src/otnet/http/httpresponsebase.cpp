// File Line: 35
// RVA: 0xEE0D44
void __fastcall OSuite::ZHttpResponseBase::ZHttpResponseBase(OSuite::ZHttpResponseBase *this)
{
  OSuite::ZDateTime *p_m_parser; // rcx
  OSuite::ZObject *v3; // rdx
  OSuite::OSError *v4; // rax

  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpResponseBase::`vftable{for `OSuite::ZObject};
  p_m_parser = (OSuite::ZDateTime *)&this->m_parser;
  *(_QWORD *)&p_m_parser[-1].m_nDate = &OSuite::ZHttpResponseBase::`vftable{for `OSuite::IHttpResponse};
  OSuite::ZDateTime::ZDateTime(p_m_parser);
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(&this->m_ResponseHeaders);
  this->m_ResponseHeaders.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_ResponseHeaders.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::ZObject};
  this->m_ResponseHeaders.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(&this->m_CacheControl);
  this->m_CacheControl.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_CacheControl.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::ZObject};
  this->m_CacheControl.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_OSErrorsList, v3);
  this->m_OSErrorsList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::OSError>::`vftable{for `OSuite::ZListBase};
  this->m_OSErrorsList.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::OSError>::`vftable{for `OSuite::IHashable};
  this->m_OSErrorsList.m_pList = 0i64;
  v4 = OSuite::TList<OSuite::OSError>::AllocList(&this->m_OSErrorsList, 0i64, 0x10ui64);
  this->m_OSErrorsList.m_nSize = 16i64;
  this->m_OSErrorsList.m_nTop = 0i64;
  this->m_OSErrorsList.m_pList = v4;
  *(_QWORD *)&this->m_nMajorVersion = 0i64;
  this->m_nStatus = 0;
  this->m_lastError = HTTPERROR_OK;
  *(_WORD *)&this->m_bContentIsText = 1;
}

// File Line: 42
// RVA: 0xEE0E3C
void __fastcall OSuite::ZHttpResponseBase::~ZHttpResponseBase(OSuite::ZHttpResponseBase *this)
{
  OSuite::OSError *m_pList; // rcx
  OSuite::OSError *v3; // rax
  OSuite::OSError *v4; // rcx

  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpResponseBase::`vftable{for `OSuite::ZObject};
  this->OSuite::IHttpResponse::vfptr = (OSuite::IHttpResponseVtbl *)&OSuite::ZHttpResponseBase::`vftable{for `OSuite::IHttpResponse};
  m_pList = this->m_OSErrorsList.m_pList;
  if ( m_pList )
  {
    if ( LODWORD(m_pList[-1].pErrorDetails) )
      m_pList->vfptr->__vecDelDtor(m_pList, 3u);
    else
      Illusion::ShaderParam::operator delete(&m_pList[-1].pErrorDetails);
  }
  v3 = OSuite::TList<OSuite::OSError>::AllocList(&this->m_OSErrorsList, this->m_OSErrorsList.m_pList, 0x10ui64);
  this->m_OSErrorsList.m_nTop = 0i64;
  this->m_OSErrorsList.m_nSize = 16i64;
  this->m_OSErrorsList.m_pList = v3;
  v4 = this->m_OSErrorsList.m_pList;
  this->m_OSErrorsList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::OSError>::`vftable{for `OSuite::ZListBase};
  this->m_OSErrorsList.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::OSError>::`vftable{for `OSuite::IHashable};
  if ( v4 )
  {
    if ( LODWORD(v4[-1].pErrorDetails) )
      v4->vfptr->__vecDelDtor(v4, 3u);
    else
      Illusion::ShaderParam::operator delete(&v4[-1].pErrorDetails);
  }
  this->m_CacheControl.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable;
  this->m_CacheControl.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_CacheControl.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::ZObject};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase(&this->m_CacheControl);
  this->m_ResponseHeaders.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable;
  this->m_ResponseHeaders.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_ResponseHeaders.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::ZObject};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase(&this->m_ResponseHeaders);
  OSuite::ZJsonSerializer::~ZJsonSerializer((OSuite::ZDateTime *)&this->m_parser);
  this->OSuite::IHttpResponse::vfptr = (OSuite::IHttpResponseVtbl *)&OSuite::IHttpResponse::`vftable;
}

// File Line: 50
// RVA: 0xEE1C84
bool __fastcall OSuite::ZHttpResponseBase::HandleResponse(OSuite::ZHttpResponseBase *this)
{
  bool result; // al

  result = this->m_bIsHandled;
  if ( !result )
    return ((__int64 (__fastcall *)(OSuite::ZHttpResponseBase *))this->OSuite::ZObject::vfptr[2].__vecDelDtor)(this);
  return result;
}

// File Line: 61
// RVA: 0xEE1258
OSuite::ZString *__fastcall OSuite::ZHttpResponseBase::GetHeader(
        OSuite::ZHttpResponseBase *this,
        OSuite::ZString *result,
        OSuite::ZString *sHeader)
{
  OSuite::ZString *v5; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx
  OSuite::ZString v8; // [rsp+20h] [rbp-69h] BYREF
  OSuite::ZString resulta; // [rsp+38h] [rbp-51h] BYREF
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::ZString,OSuite::ZString> v10; // [rsp+50h] [rbp-39h] BYREF

  resulta.m_pString = 0i64;
  OSuite::ZString::ZString(&v8, sHeader);
  OSuite::ZString::ToLower(v5, &resulta);
  OSuite::ZString::~ZString(&v8);
  v10.m_iterator.m_iterator.m_pList = 0i64;
  v10.m_iterator.m_iterator.m_pElement = 0i64;
  v10.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Find(
    (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *)&this->m_parser,
    &v10,
    &resulta);
  if ( OSuite::ZString::IsNull((OSuite::ZString *)&v10.m_iterator.m_iterator) )
  {
    OSuite::ZString::ZString(result);
    m_pList = v10.m_iterator.m_iterator.m_parents.m_pList;
    v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
    v10.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v10.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    v10.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v10.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( v10.m_iterator.m_iterator.m_parents.m_pList )
LABEL_5:
      v10.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(m_pList, 1u);
  }
  else
  {
    OSuite::ZString::ZString(result, (OSuite::ZString *)&v10.m_iterator.m_iterator.m_pElement[2]);
    m_pList = v10.m_iterator.m_iterator.m_parents.m_pList;
    v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
    v10.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v10.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    v10.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v10.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( v10.m_iterator.m_iterator.m_parents.m_pList )
      goto LABEL_5;
  }
  OSuite::ZString::~ZString(&resulta);
  return result;
}

// File Line: 77
// RVA: 0xEE0FDC
OSuite::ZString *__fastcall OSuite::ZHttpResponseBase::GetCacheControlValue(
        OSuite::ZHttpResponseBase *this,
        OSuite::ZString *result,
        OSuite::ZString *sKey)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::ZString,OSuite::ZString> resulta; // [rsp+20h] [rbp-29h] BYREF

  resulta.m_iterator.m_iterator.m_pList = 0i64;
  resulta.m_iterator.m_iterator.m_pElement = 0i64;
  resulta.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Find(
    (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *)&this->m_ResponseHeaders.m_Comparer.OSuite::ZObject,
    &resulta,
    sKey);
  if ( OSuite::ZString::IsNull((OSuite::ZString *)&resulta.m_iterator.m_iterator) )
  {
    OSuite::ZString::ZString(result);
    m_pList = resulta.m_iterator.m_iterator.m_parents.m_pList;
    resulta.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
    resulta.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    resulta.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( resulta.m_iterator.m_iterator.m_parents.m_pList )
LABEL_5:
      resulta.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(m_pList, 1u);
  }
  else
  {
    OSuite::ZString::ZString(result, (OSuite::ZString *)&resulta.m_iterator.m_iterator.m_pElement[2]);
    m_pList = resulta.m_iterator.m_iterator.m_parents.m_pList;
    resulta.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
    resulta.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    resulta.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( resulta.m_iterator.m_iterator.m_parents.m_pList )
      goto LABEL_5;
  }
  return result;
}

// File Line: 91
// RVA: 0xEE10F4
char __fastcall OSuite::ZHttpResponseBase::GetContentRange(
        OSuite::ZHttpResponseBase *this,
        unsigned __int64 *pFirst,
        unsigned __int64 *pLength)
{
  const char *v6; // rbx
  int v7; // eax
  char v8; // di
  int v9; // eax
  int v10; // eax
  __int64 v11; // rbx
  unsigned __int64 v12; // rax
  OSuite::ZString v14; // [rsp+20h] [rbp-50h] BYREF
  OSuite::ZString v15; // [rsp+38h] [rbp-38h] BYREF
  OSuite::ZString result; // [rsp+50h] [rbp-20h] BYREF

  v14.m_pString = 0i64;
  OSuite::ZString::ZString(&v15, "content-range");
  ((void (__fastcall *)(OSuite::ZHttpResponseBase *, OSuite::ZString *, OSuite::ZString *))this->OSuite::ZObject::vfptr[1].__vecDelDtor)(
    this,
    &v14,
    &v15);
  OSuite::ZString::~ZString(&v15);
  if ( OSuite::ZString::operator bool(&v14) )
  {
    OSuite::ZString::StartsWith(&v14, "bytes");
    v6 = OSuite::ZString::c_str(&v14) + 5;
    v7 = isspace(*(unsigned __int8 *)v6);
    v8 = 1;
    while ( v7 )
      v7 = isspace(*(unsigned __int8 *)++v6);
    v9 = OSuite::ZString::IndexOf(&v14, 45, 0i64);
    result.m_pString = 0i64;
    OSuite::ZString::Slice(&v14, &result, v9 + 1);
    v10 = OSuite::ZString::IndexOf(&result, 47, 0i64);
    v15.m_pString = 0i64;
    OSuite::ZString::Slice(&result, &v15, v10 + 1);
    *pFirst = OSuite::ZString::ToInt(&v14);
    v11 = OSuite::ZString::ToInt(&result);
    if ( OSuite::ZString::StartsWith(&v15, pattern) )
      v12 = v11 + 1;
    else
      v12 = OSuite::ZString::ToInt(&v15);
    *pLength = v12;
    OSuite::ZString::~ZString(&v15);
    OSuite::ZString::~ZString(&result);
  }
  else
  {
    v8 = 0;
  }
  OSuite::ZString::~ZString(&v14);
  return v8;
}

// File Line: 134
// RVA: 0xEE0FBC
_BOOL8 __fastcall OSuite::ZHttpResponseBase::CheckVersion(OSuite::ZHttpResponseBase *this, int nMajor, int nMinor)
{
  int m_pList; // eax

  m_pList = (int)this->m_OSErrorsList.m_pList;
  return m_pList > nMajor || m_pList == nMajor && SHIDWORD(this->m_OSErrorsList.m_pList) >= nMinor;
}

// File Line: 143
// RVA: 0xEE13A0
__int64 __fastcall OSuite::ZHttpResponseBase::HandleHeaders(
        OSuite::ZHttpResponseBase *this,
        unsigned __int64 *nContentLength,
        bool *bTransferChunked,
        OSuite::ZTextDecoder **pDecoder)
{
  unsigned int v6; // r14d
  OSuite::IHttpResponse *v9; // rbx
  OSuite::ZString *v10; // rax
  OSuite::ZString *i; // rcx
  int v12; // eax
  OSuite::ZString *v13; // rax
  OSuite::ZString *v14; // rax
  OSuite::ZHttpParser *v15; // rax
  int v16; // r9d
  OSuite::AuthenticationManager *v17; // rax
  OSuite::AuthenticationManager *v18; // rbx
  const char *v19; // rax
  OSuite::AuthenticationManager *v20; // rbx
  unsigned int v21; // eax
  OSuite::ZString result; // [rsp+20h] [rbp-60h] BYREF
  char pszString[4]; // [rsp+38h] [rbp-48h] BYREF
  OSuite::ZString v25; // [rsp+40h] [rbp-40h] BYREF
  OSuite::ZString sHeader; // [rsp+58h] [rbp-28h] BYREF

  v6 = 0;
  sHeader.m_pString = 0i64;
  OSuite::ZString::ZString(&result, "transfer-encoding");
  v9 = &this->OSuite::IHttpResponse;
  (*(void (__fastcall **)(OSuite::IHttpResponse *, OSuite::ZString *, OSuite::ZString *))this->OSuite::IHttpResponse::vfptr->gap8)(
    &this->OSuite::IHttpResponse,
    &sHeader,
    &result);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::operator bool(&sHeader) )
  {
    v10 = OSuite::ZString::Trim(&sHeader, &result);
    OSuite::ZString::operator=(&sHeader, v10);
    for ( i = &result; ; i = &v25 )
    {
      OSuite::ZString::~ZString(i);
      if ( !OSuite::ZString::operator bool(&sHeader) )
        break;
      if ( OSuite::ZString::StartsWith(&sHeader, "chunked") )
      {
        *bTransferChunked = 1;
        *nContentLength = -1i64;
        break;
      }
      v12 = OSuite::ZString::IndexOf(&sHeader, 44, 0i64);
      if ( v12 == -1 )
        break;
      v13 = OSuite::ZString::Slice(&sHeader, &v25, v12 + 1);
      v14 = OSuite::ZString::Trim(v13, &result);
      OSuite::ZString::operator=(&sHeader, v14);
      OSuite::ZString::~ZString(&result);
    }
  }
  OSuite::ZString::~ZString(&sHeader);
  sHeader.m_pString = 0i64;
  OSuite::ZString::ZString(&result, "content-length");
  (*(void (__fastcall **)(OSuite::IHttpResponse *, OSuite::ZString *, OSuite::ZString *))v9->vfptr->gap8)(
    &this->OSuite::IHttpResponse,
    &sHeader,
    &result);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::operator bool(&sHeader) )
  {
    *(_DWORD *)pszString = 0;
    v15 = (OSuite::ZHttpParser *)OSuite::ZString::c_str(&sHeader);
    *nContentLength = (int)OSuite::ZHttpParser::parsebase<char>(v15, pszString, (int *)0xA, v16);
  }
  OSuite::ZString::~ZString(&sHeader);
  sHeader.m_pString = 0i64;
  OSuite::ZString::ZString(&result, "cache-control");
  (*(void (__fastcall **)(OSuite::IHttpResponse *, OSuite::ZString *, OSuite::ZString *))v9->vfptr->gap8)(
    &this->OSuite::IHttpResponse,
    &sHeader,
    &result);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::operator bool(&sHeader) )
    OSuite::ZHttpParser::ParseCacheControl(&this->m_ResponseHeaders, &sHeader);
  OSuite::ZString::~ZString(&sHeader);
  sHeader.m_pString = 0i64;
  OSuite::ZString::ZString(&result, "content-type");
  (*(void (__fastcall **)(OSuite::IHttpResponse *, OSuite::ZString *, OSuite::ZString *))v9->vfptr->gap8)(
    &this->OSuite::IHttpResponse,
    &sHeader,
    &result);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::operator bool(&sHeader) )
    OSuite::ZHttpParser::ParseContentType(&sHeader, &this->m_bContentIsText, pDecoder);
  OSuite::ZString::~ZString(&sHeader);
  sHeader.m_pString = 0i64;
  OSuite::ZString::ZString(&result, "connection");
  (*(void (__fastcall **)(OSuite::IHttpResponse *, OSuite::ZString *, OSuite::ZString *))v9->vfptr->gap8)(
    &this->OSuite::IHttpResponse,
    &sHeader,
    &result);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::operator bool(&sHeader) )
    v6 = (unsigned int)this->OSuite::ZObject::vfptr[3].__vecDelDtor(this, &sHeader);
  OSuite::ZString::~ZString(&sHeader);
  sHeader.m_pString = 0i64;
  OSuite::ZString::ZString(&result, "OS-AuthResponse");
  (*(void (__fastcall **)(OSuite::IHttpResponse *, OSuite::ZString *, OSuite::ZString *))v9->vfptr->gap8)(
    &this->OSuite::IHttpResponse,
    &sHeader,
    &result);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::operator bool(&sHeader) )
  {
    v17 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
    OSuite::AuthenticationManager::SetAuthenticationProvider(v17, AUTH_PROVIDER_OSUITE);
    v18 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
    v19 = OSuite::ZString::c_str(&sHeader);
    OSuite::AuthenticationManager::SetTicketData(v18, v19);
    v20 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
    v21 = OSuite::ZString::Count(&sHeader);
    OSuite::AuthenticationManager::SetTicketSize(v20, v21);
  }
  OSuite::ZString::~ZString(&sHeader);
  return v6;
}

// File Line: 208
// RVA: 0xEE1CA0
void __fastcall OSuite::ZHttpResponseBase::Init(OSuite::ZHttpResponseBase *this)
{
  OSuite::ZRedBlackTreeBase::Clear(&this->m_ResponseHeaders);
  OSuite::ZRedBlackTreeBase::Clear(&this->m_CacheControl);
  *(_QWORD *)&this->m_nMajorVersion = 0i64;
  this->m_lastError = HTTPERROR_OK;
  this->m_nStatus = 0;
  *(_WORD *)&this->m_bContentIsText = 0;
}

// File Line: 220
// RVA: 0xEE1CE0
void __fastcall OSuite::ZHttpResponseBase::SetLastError(OSuite::ZHttpResponseBase *this, __int32 error)
{
  OSuite::ZError *v3; // rbx
  OSuite::ZError::EError v4; // eax

  this->m_lastError = error;
  v3 = OSuite::TSingleton<OSuite::ZError>::Object();
  v4 = (unsigned int)OSuite::ZHttp::HttpToOsError(error);
  OSuite::ZError::SetThreadLastError(v3, v4, 1);
}

// File Line: 226
// RVA: 0xEE16D0
void __fastcall OSuite::ZHttpResponseBase::HandleOsError(
        OSuite::ZHttpResponseBase *this,
        OSuite::IReader *reader,
        OSuite::ZStringBuilder *zs)
{
  OSuite::ZObject *v5; // rdx
  OSuite::ZString *v6; // rax
  OSuite::ZObject *v7; // rdx
  OSuite::ZString *v8; // rax
  OSuite::ZObject *v9; // rdx
  OSuite::ZString *v10; // rax
  OSuite::ZObjectVtbl *vfptr; // rbx
  OSuite::ZString *p_m_pLeft; // rdi
  OSuite::TList<OSuite::ZString> *v13; // rdx
  unsigned __int64 m_nIndex; // rdi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v16; // rsi
  OSuite::ZString *v17; // r15
  unsigned __int64 v18; // rdi
  OSuite::ZListBase *v19; // rbx
  unsigned __int64 v20; // rsi
  OSuite::ZString *v21; // r14
  unsigned __int64 v22; // rsi
  OSuite::ZListBase *v23; // rbx
  unsigned __int64 v24; // rdi
  const char *v25; // rdi
  const char *v26; // rbx
  int v27; // eax
  OSuite::OSError *v28; // rax
  OSuite::OSError *v29; // rbx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::OSError v31; // [rsp+A0h] [rbp-60h] BYREF
  OSuite::ZListBase::ZListIteratorBase v32; // [rsp+C0h] [rbp-40h] BYREF
  OSuite::TList<OSuite::ZString> v33; // [rsp+D8h] [rbp-28h] BYREF
  OSuite::TList<OSuite::ZString> v34; // [rsp+100h] [rbp+0h] BYREF
  OSuite::ZListBase::ZListIteratorBase v35; // [rsp+128h] [rbp+28h] BYREF
  OSuite::TList<OSuite::ZString> v36; // [rsp+140h] [rbp+40h] BYREF
  OSuite::ZListBase::ZListIteratorBase v37; // [rsp+168h] [rbp+68h] BYREF
  void **v38; // [rsp+180h] [rbp+80h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator v39; // [rsp+188h] [rbp+88h] BYREF
  OSuite::ZJsonDocument v40; // [rsp+210h] [rbp+110h] BYREF

  v40.m_Pairs.m_pLists = 0i64;
  OSuite::ZJsonDocument::ZJsonDocument(&v40, reader);
  if ( v40.m_bIsValid )
  {
    v34.m_pList = 0i64;
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v34, v5);
    v34.OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::ZListBase};
    v34.m_pList = 0i64;
    v34.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::IHashable};
    v6 = OSuite::TList<OSuite::ZString>::AllocList(&v34, 0i64, 0x10ui64);
    v34.m_nSize = 16i64;
    v34.m_nTop = 0i64;
    v36.m_pList = 0i64;
    v34.m_pList = v6;
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v36, v7);
    v36.OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::ZListBase};
    v36.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::IHashable};
    v36.m_pList = 0i64;
    v8 = OSuite::TList<OSuite::ZString>::AllocList(&v36, 0i64, 0x10ui64);
    v36.m_nSize = 16i64;
    v36.m_nTop = 0i64;
    v36.m_pList = v8;
    v33.m_pList = 0i64;
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v33, v9);
    v33.OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::ZListBase};
    v33.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::IHashable};
    v33.m_pList = 0i64;
    v10 = OSuite::TList<OSuite::ZString>::AllocList(&v33, 0i64, 0x10ui64);
    *(_OWORD *)&v39.m_iterator.m_iterator.m_pList = 0i64;
    v33.m_nSize = 16i64;
    v33.m_nTop = 0i64;
    v33.m_pList = v10;
    v39.m_pMap = 0i64;
    v39.m_iterator.m_iterator.m_parents.m_pList = 0i64;
    OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
      (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&v40.m_Pairs,
      &result);
    v38 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
    v39.m_pMap = result.m_pMap;
    v39.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    v39.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v39.m_iCurrentHash = result.m_iCurrentHash;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v39.m_iterator.m_iterator, &result.m_iterator.m_iterator);
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v39.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    if ( !OSuite::ZString::IsNull((OSuite::ZString *)&v39.m_iterator.m_iterator) )
    {
      while ( 1 )
      {
        vfptr = v39.m_iterator.m_iterator.m_pElement[2].vfptr;
        p_m_pLeft = (OSuite::ZString *)&v39.m_iterator.m_iterator.m_pElement[1].m_pLeft;
        if ( vfptr )
          break;
LABEL_17:
        OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&v39);
        if ( OSuite::ZString::IsNull((OSuite::ZString *)&v39.m_iterator.m_iterator) )
          goto LABEL_18;
      }
      if ( !OSuite::ZString::operator==(
              (OSuite::ZString *)&v39.m_iterator.m_iterator.m_pElement[1].m_pLeft,
              "s_ErrorsCodes")
        || OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v34) )
      {
        if ( !OSuite::ZString::operator==(p_m_pLeft, "s_ErrorsMessages")
          || OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v36) )
        {
          if ( !OSuite::ZString::operator==(p_m_pLeft, "s_ErrorsDetails")
            || OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v33) )
          {
            goto LABEL_16;
          }
          v13 = &v33;
        }
        else
        {
          v13 = &v36;
        }
      }
      else
      {
        v13 = &v34;
      }
      OSuite::ZString::Split((OSuite::ZString *)&vfptr[2], v13, 59);
LABEL_16:
      OSuite::ZStringBuilder::Append(zs, p_m_pLeft);
      OSuite::ZStringBuilder::Append(zs, " : ");
      OSuite::ZStringBuilder::Append(zs, (OSuite::ZString *)&vfptr[2]);
      OSuite::ZStringBuilder::Append(zs, "\n");
      goto LABEL_17;
    }
LABEL_18:
    v39.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    v38 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
    v39.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v39.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    v39.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v39.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( v39.m_iterator.m_iterator.m_parents.m_pList )
      v39.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(v39.m_iterator.m_iterator.m_parents.m_pList, 1u);
    v32.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v32, &v34);
    v32.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v35.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v35, &v36);
    v35.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v37.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v37, &v33);
    v37.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v32) )
    {
      if ( OSuite::ZListBase::ZListIteratorBase::AtEnd(&v35) || OSuite::ZListBase::ZListIteratorBase::AtEnd(&v37) )
        break;
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v32.m_pListBase);
      m_nIndex = v32.m_nIndex;
      m_pListBase = v32.m_pListBase;
      v16 = v32.m_nIndex + 1;
      OSuite::TList<OSuite::ZString>::Grow((OSuite::TList<OSuite::ZString> *)v32.m_pListBase, v32.m_nIndex + 1);
      if ( m_nIndex >= m_pListBase->m_nTop )
        m_pListBase->m_nTop = v16;
      v17 = (OSuite::ZString *)(m_pListBase[1].m_nSize + 24 * m_nIndex);
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v35.m_pListBase);
      v18 = v35.m_nIndex;
      v19 = v35.m_pListBase;
      v20 = v35.m_nIndex + 1;
      OSuite::TList<OSuite::ZString>::Grow((OSuite::TList<OSuite::ZString> *)v35.m_pListBase, v35.m_nIndex + 1);
      if ( v18 >= v19->m_nTop )
        v19->m_nTop = v20;
      v21 = (OSuite::ZString *)(v19[1].m_nSize + 24 * v18);
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v37.m_pListBase);
      v22 = v37.m_nIndex;
      v23 = v37.m_pListBase;
      v24 = v37.m_nIndex + 1;
      OSuite::TList<OSuite::ZString>::Grow((OSuite::TList<OSuite::ZString> *)v37.m_pListBase, v37.m_nIndex + 1);
      if ( v22 >= v23->m_nTop )
        v23->m_nTop = v24;
      v25 = OSuite::ZString::c_str((OSuite::ZString *)(v23[1].m_nSize + 24 * v22));
      v26 = OSuite::ZString::c_str(v21);
      v27 = OSuite::ZString::ToInt(v17);
      OSuite::OSError::OSError(&v31, v27, v26, v25);
      v29 = v28;
      OSuite::TList<OSuite::OSError>::Grow(&this->m_OSErrorsList, this->m_OSErrorsList.m_nTop + 1);
      OSuite::OSError::operator=(&this->m_OSErrorsList.m_pList[this->m_OSErrorsList.m_nTop], v29);
      ++this->m_OSErrorsList.m_nTop;
      OSuite::OSError::~OSError(&v31);
      OSuite::ZListBase::ZListIteratorBase::Next(&v32);
      OSuite::ZListBase::ZListIteratorBase::Next(&v35);
      OSuite::ZListBase::ZListIteratorBase::Next(&v37);
    }
    v37.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v35.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v32.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v33.OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::ZListBase};
    v33.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::IHashable};
    if ( v33.m_pList )
    {
      if ( LODWORD(v33.m_pList[-1].m_pString) )
        v33.m_pList->vfptr->__vecDelDtor(v33.m_pList, 3u);
      else
        Illusion::ShaderParam::operator delete(&v33.m_pList[-1].m_pString);
    }
    v36.OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::ZListBase};
    v36.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::IHashable};
    if ( v36.m_pList )
    {
      if ( LODWORD(v36.m_pList[-1].m_pString) )
        v36.m_pList->vfptr->__vecDelDtor(v36.m_pList, 3u);
      else
        Illusion::ShaderParam::operator delete(&v36.m_pList[-1].m_pString);
    }
    v34.OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::ZListBase};
    v34.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::IHashable};
    if ( v34.m_pList )
    {
      if ( LODWORD(v34.m_pList[-1].m_pString) )
        v34.m_pList->vfptr->__vecDelDtor(v34.m_pList, 3u);
      else
        Illusion::ShaderParam::operator delete(&v34.m_pList[-1].m_pString);
    }
  }
  OSuite::ZJsonDocument::~ZJsonDocument(&v40);
}


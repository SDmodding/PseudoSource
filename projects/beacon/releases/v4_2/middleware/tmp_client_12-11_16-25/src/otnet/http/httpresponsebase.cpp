// File Line: 35
// RVA: 0xEE0D44
void __fastcall OSuite::ZHttpResponseBase::ZHttpResponseBase(OSuite::ZHttpResponseBase *this)
{
  OSuite::ZHttpResponseBase *v1; // rdi
  OSuite::ZDateTime *v2; // rcx
  OSuite::ZObject *v3; // rdx
  OSuite::OSError *v4; // rax

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpResponseBase::`vftable'{for `OSuite::ZObject'};
  v2 = (OSuite::ZDateTime *)&this->m_parser;
  *(_QWORD *)&v2[-1].m_nDate = &OSuite::ZHttpResponseBase::`vftable'{for `OSuite::IHttpResponse'};
  OSuite::ZDateTime::ZDateTime(v2);
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&v1->m_ResponseHeaders.vfptr);
  v1->m_ResponseHeaders.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  v1->m_ResponseHeaders.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::ZObject'};
  v1->m_ResponseHeaders.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable';
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&v1->m_CacheControl.vfptr);
  v1->m_CacheControl.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  v1->m_CacheControl.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::ZObject'};
  v1->m_CacheControl.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable';
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v1->m_OSErrorsList.vfptr, v3);
  v1->m_OSErrorsList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::OSError>::`vftable'{for `OSuite::ZListBase'};
  v1->m_OSErrorsList.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::OSError>::`vftable'{for `OSuite::IHashable'};
  v1->m_OSErrorsList.m_pList = 0i64;
  v4 = OSuite::TList<OSuite::OSError>::AllocList(&v1->m_OSErrorsList, 0i64, 0x10ui64);
  v1->m_OSErrorsList.m_nSize = 16i64;
  v1->m_OSErrorsList.m_nTop = 0i64;
  v1->m_OSErrorsList.m_pList = v4;
  *(_QWORD *)&v1->m_nMajorVersion = 0i64;
  v1->m_nStatus = 0;
  v1->m_lastError = 0;
  *(_WORD *)&v1->m_bContentIsText = 1;
}

// File Line: 42
// RVA: 0xEE0E3C
void __fastcall OSuite::ZHttpResponseBase::~ZHttpResponseBase(OSuite::ZHttpResponseBase *this)
{
  OSuite::ZHttpResponseBase *v1; // rdi
  OSuite::OSError *v2; // rcx
  OSuite::OSError *v3; // rax
  OSuite::OSError *v4; // rcx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v5; // rcx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v6; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpResponseBase::`vftable'{for `OSuite::ZObject'};
  this->vfptr = (OSuite::IHttpResponseVtbl *)&OSuite::ZHttpResponseBase::`vftable'{for `OSuite::IHttpResponse'};
  v2 = this->m_OSErrorsList.m_pList;
  if ( v2 )
  {
    if ( LODWORD(v2[-1].pErrorDetails) )
      v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 3u);
    else
      Illusion::ShaderParam::operator delete(&v2[-1].pErrorDetails);
  }
  v3 = OSuite::TList<OSuite::OSError>::AllocList(
         &v1->m_OSErrorsList,
         (OSuite::ZObject *)&v1->m_OSErrorsList.m_pList->vfptr,
         0x10ui64);
  v1->m_OSErrorsList.m_nTop = 0i64;
  v1->m_OSErrorsList.m_nSize = 16i64;
  v1->m_OSErrorsList.m_pList = v3;
  v4 = v1->m_OSErrorsList.m_pList;
  v1->m_OSErrorsList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::OSError>::`vftable'{for `OSuite::ZListBase'};
  v1->m_OSErrorsList.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::OSError>::`vftable'{for `OSuite::IHashable'};
  if ( v4 )
  {
    if ( LODWORD(v4[-1].pErrorDetails) )
      v4->vfptr->__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 3u);
    else
      Illusion::ShaderParam::operator delete(&v4[-1].pErrorDetails);
  }
  v5 = &v1->m_CacheControl;
  v5->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable';
  v5->m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  v5->m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::ZObject'};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase((OSuite::ZRedBlackTreeBase *)&v1->m_CacheControl.vfptr);
  v6 = &v1->m_ResponseHeaders;
  v6->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable';
  v6->m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  v6->m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::ZObject'};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase((OSuite::ZRedBlackTreeBase *)&v1->m_ResponseHeaders.vfptr);
  OSuite::ZJsonSerializer::~ZJsonSerializer((OSuite::ZDateTime *)&v1->m_parser);
  v1->vfptr = (OSuite::IHttpResponseVtbl *)&OSuite::IHttpResponse::`vftable';
}

// File Line: 50
// RVA: 0xEE1C84
bool __fastcall OSuite::ZHttpResponseBase::HandleResponse(OSuite::ZHttpResponseBase *this)
{
  bool result; // al

  result = this->m_bIsHandled;
  if ( !result )
    result = ((__int64 (*)(void))this->vfptr[2].__vecDelDtor)();
  return result;
}

// File Line: 61
// RVA: 0xEE1258
OSuite::ZString *__fastcall OSuite::ZHttpResponseBase::GetHeader(OSuite::ZHttpResponseBase *this, OSuite::ZString *result, OSuite::ZString *sHeader)
{
  OSuite::ZHttpResponseBase *v3; // rbx
  OSuite::ZString *v4; // rdi
  OSuite::ZString *v5; // rax
  OSuite::ZString v7; // [rsp+20h] [rbp-69h]
  OSuite::ZString resulta; // [rsp+38h] [rbp-51h]
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::ZString,OSuite::ZString> v9; // [rsp+50h] [rbp-39h]

  resulta.m_pString = 0i64;
  v3 = this;
  v4 = result;
  OSuite::ZString::ZString(&v7, sHeader);
  OSuite::ZString::ToLower(v5, &resulta);
  OSuite::ZString::~ZString(&v7);
  v9.m_iterator.m_iterator.m_pList = 0i64;
  v9.m_iterator.m_iterator.m_pElement = 0i64;
  v9.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Find(
    (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *)&v3->m_parser,
    &v9,
    &resulta);
  if ( OSuite::ZString::IsNull((OSuite::ZString *)&v9.m_iterator.m_iterator) )
  {
    OSuite::ZString::ZString(v4);
    v9.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable';
    v9.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    v9.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    v9.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    v9.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( v9.m_iterator.m_iterator.m_parents.m_pList )
      v9.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)v9.m_iterator.m_iterator.m_parents.m_pList,
        1u);
  }
  else
  {
    OSuite::ZString::ZString(v4, (OSuite::ZString *)&v9.m_iterator.m_iterator.m_pElement[2]);
    v9.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable';
    v9.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    v9.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    v9.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    v9.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( v9.m_iterator.m_iterator.m_parents.m_pList )
      v9.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)v9.m_iterator.m_iterator.m_parents.m_pList,
        1u);
  }
  OSuite::ZString::~ZString(&resulta);
  return v4;
}

// File Line: 77
// RVA: 0xEE0FDC
OSuite::ZString *__fastcall OSuite::ZHttpResponseBase::GetCacheControlValue(OSuite::ZHttpResponseBase *this, OSuite::ZString *result, OSuite::ZString *sKey)
{
  OSuite::ZString *v3; // rbx
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::ZString,OSuite::ZString> resulta; // [rsp+20h] [rbp-29h]

  resulta.m_iterator.m_iterator.m_pList = 0i64;
  resulta.m_iterator.m_iterator.m_pElement = 0i64;
  resulta.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  v3 = result;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Find(
    (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *)((char *)&this->m_ResponseHeaders + 32),
    &resulta,
    sKey);
  if ( OSuite::ZString::IsNull((OSuite::ZString *)&resulta.m_iterator.m_iterator) )
  {
    OSuite::ZString::ZString(v3);
    resulta.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable';
    resulta.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    resulta.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( resulta.m_iterator.m_iterator.m_parents.m_pList )
      resulta.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)resulta.m_iterator.m_iterator.m_parents.m_pList,
        1u);
  }
  else
  {
    OSuite::ZString::ZString(v3, (OSuite::ZString *)&resulta.m_iterator.m_iterator.m_pElement[2]);
    resulta.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable';
    resulta.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    resulta.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( resulta.m_iterator.m_iterator.m_parents.m_pList )
      resulta.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)resulta.m_iterator.m_iterator.m_parents.m_pList,
        1u);
  }
  return v3;
}

// File Line: 91
// RVA: 0xEE10F4
char __fastcall OSuite::ZHttpResponseBase::GetContentRange(OSuite::ZHttpResponseBase *this, unsigned __int64 *pFirst, unsigned __int64 *pLength)
{
  unsigned __int64 *v3; // r14
  OSuite::ZHttpResponseBase *v4; // rbx
  unsigned __int64 *v5; // rsi
  const char *v6; // rbx
  int v7; // eax
  char v8; // di
  int v9; // eax
  int v10; // eax
  __int64 v11; // rbx
  signed __int64 v12; // rax
  OSuite::ZString v14; // [rsp+20h] [rbp-50h]
  OSuite::ZString v15; // [rsp+38h] [rbp-38h]
  OSuite::ZString result; // [rsp+50h] [rbp-20h]

  v14.m_pString = 0i64;
  v3 = pFirst;
  v4 = this;
  v5 = pLength;
  OSuite::ZString::ZString(&v15, "content-range");
  ((void (__fastcall *)(OSuite::ZHttpResponseBase *, OSuite::ZString *, OSuite::ZString *))v4->vfptr[1].__vecDelDtor)(
    v4,
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
    *v3 = OSuite::ZString::ToInt(&v14);
    v11 = OSuite::ZString::ToInt(&result);
    if ( OSuite::ZString::StartsWith(&v15, pattern) )
      v12 = v11 + 1;
    else
      v12 = OSuite::ZString::ToInt(&v15);
    *v5 = v12;
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
  int v3; // eax

  v3 = (int)this->m_OSErrorsList.m_pList;
  return v3 > nMajor || v3 == nMajor && SHIDWORD(this->m_OSErrorsList.m_pList) >= nMinor;
}

// File Line: 143
// RVA: 0xEE13A0
__int64 __fastcall OSuite::ZHttpResponseBase::HandleHeaders(OSuite::ZHttpResponseBase *this, unsigned __int64 *nContentLength, bool *bTransferChunked, OSuite::ZTextDecoder **pDecoder)
{
  unsigned __int64 *v4; // rsi
  OSuite::ZHttpResponseBase *v5; // rdi
  unsigned int v6; // er14
  OSuite::ZTextDecoder **v7; // r12
  bool *v8; // r15
  signed __int64 v9; // rbx
  OSuite::ZString *v10; // rax
  OSuite::ZString *i; // rcx
  int v12; // eax
  OSuite::ZString *v13; // rax
  OSuite::ZString *v14; // rax
  OSuite::ZHttpParser *v15; // rax
  int v16; // er9
  OSuite::AuthenticationManager *v17; // rax
  OSuite::AuthenticationManager *v18; // rbx
  const char *v19; // rax
  OSuite::AuthenticationManager *v20; // rbx
  unsigned int v21; // eax
  OSuite::ZString result; // [rsp+20h] [rbp-60h]
  char pszString[4]; // [rsp+38h] [rbp-48h]
  OSuite::ZString v25; // [rsp+40h] [rbp-40h]
  OSuite::ZString sHeader; // [rsp+58h] [rbp-28h]

  v4 = nContentLength;
  v5 = this;
  v6 = 0;
  v7 = pDecoder;
  sHeader.m_pString = 0i64;
  v8 = bTransferChunked;
  OSuite::ZString::ZString(&result, "transfer-encoding");
  v9 = (signed __int64)&v5->vfptr;
  (*(void (__fastcall **)(OSuite::IHttpResponseVtbl **, OSuite::ZString *, OSuite::ZString *))v5->vfptr->gap8)(
    &v5->vfptr,
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
        *v8 = 1;
        *v4 = -1i64;
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
  (*(void (__fastcall **)(OSuite::IHttpResponseVtbl **, OSuite::ZString *, OSuite::ZString *))(*(_QWORD *)v9 + 8i64))(
    &v5->vfptr,
    &sHeader,
    &result);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::operator bool(&sHeader) )
  {
    *(_DWORD *)pszString = 0;
    v15 = (OSuite::ZHttpParser *)OSuite::ZString::c_str(&sHeader);
    *v4 = (signed int)OSuite::ZHttpParser::parsebase<char>(v15, pszString, (int *)0xA, v16);
  }
  OSuite::ZString::~ZString(&sHeader);
  sHeader.m_pString = 0i64;
  OSuite::ZString::ZString(&result, "cache-control");
  (*(void (__fastcall **)(OSuite::IHttpResponseVtbl **, OSuite::ZString *, OSuite::ZString *))(*(_QWORD *)v9 + 8i64))(
    &v5->vfptr,
    &sHeader,
    &result);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::operator bool(&sHeader) )
    OSuite::ZHttpParser::ParseCacheControl(&v5->m_ResponseHeaders, &sHeader);
  OSuite::ZString::~ZString(&sHeader);
  sHeader.m_pString = 0i64;
  OSuite::ZString::ZString(&result, "content-type");
  (*(void (__fastcall **)(OSuite::IHttpResponseVtbl **, OSuite::ZString *, OSuite::ZString *))(*(_QWORD *)v9 + 8i64))(
    &v5->vfptr,
    &sHeader,
    &result);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::operator bool(&sHeader) )
    OSuite::ZHttpParser::ParseContentType(&sHeader, &v5->m_bContentIsText, v7);
  OSuite::ZString::~ZString(&sHeader);
  sHeader.m_pString = 0i64;
  OSuite::ZString::ZString(&result, "connection");
  (*(void (__fastcall **)(OSuite::IHttpResponseVtbl **, OSuite::ZString *, OSuite::ZString *))(*(_QWORD *)v9 + 8i64))(
    &v5->vfptr,
    &sHeader,
    &result);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::operator bool(&sHeader) )
    v6 = (__int64)v5->vfptr[3].__vecDelDtor((OSuite::ZObject *)&v5->vfptr, (unsigned int)&sHeader);
  OSuite::ZString::~ZString(&sHeader);
  sHeader.m_pString = 0i64;
  OSuite::ZString::ZString(&result, "OS-AuthResponse");
  (*(void (__fastcall **)(OSuite::IHttpResponseVtbl **, OSuite::ZString *, OSuite::ZString *))(*(_QWORD *)v9 + 8i64))(
    &v5->vfptr,
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
  OSuite::ZHttpResponseBase *v1; // rbx

  v1 = this;
  OSuite::ZRedBlackTreeBase::Clear((OSuite::ZRedBlackTreeBase *)&this->m_ResponseHeaders.vfptr);
  OSuite::ZRedBlackTreeBase::Clear((OSuite::ZRedBlackTreeBase *)&v1->m_CacheControl.vfptr);
  *(_QWORD *)&v1->m_nMajorVersion = 0i64;
  v1->m_lastError = 0;
  v1->m_nStatus = 0;
  *(_WORD *)&v1->m_bContentIsText = 0;
}

// File Line: 220
// RVA: 0xEE1CE0
void __fastcall OSuite::ZHttpResponseBase::SetLastError(OSuite::ZHttpResponseBase *this, OSuite::ZHttp::EError error)
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

// File Line: 226
// RVA: 0xEE16D0
void __fastcall OSuite::ZHttpResponseBase::HandleOsError(OSuite::ZHttpResponseBase *this, OSuite::IReader *reader, OSuite::ZStringBuilder *zs)
{
  OSuite::ZHttpResponseBase *v3; // r13
  OSuite::ZStringBuilder *v4; // rsi
  OSuite::ZObject *v5; // rdx
  OSuite::ZString *v6; // rax
  OSuite::ZObject *v7; // rdx
  OSuite::ZString *v8; // rax
  OSuite::ZObject *v9; // rdx
  OSuite::ZString *v10; // rax
  OSuite::ZObjectVtbl *v11; // rbx
  OSuite::ZString *v12; // rdi
  OSuite::TList<OSuite::ZString> *v13; // rdx
  unsigned __int64 v14; // rdi
  OSuite::ZListBase *v15; // rbx
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
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-E0h]
  OSuite::OSError v31; // [rsp+A0h] [rbp-60h]
  OSuite::ZListBase::ZListIteratorBase v32; // [rsp+C0h] [rbp-40h]
  OSuite::ZObject v33; // [rsp+D8h] [rbp-28h]
  __int64 v34; // [rsp+E0h] [rbp-20h]
  __int64 v35; // [rsp+E8h] [rbp-18h]
  void **v36; // [rsp+F0h] [rbp-10h]
  OSuite::ZString *v37; // [rsp+F8h] [rbp-8h]
  OSuite::ZObject v38; // [rsp+100h] [rbp+0h]
  __int64 v39; // [rsp+108h] [rbp+8h]
  __int64 v40; // [rsp+110h] [rbp+10h]
  void **v41; // [rsp+118h] [rbp+18h]
  OSuite::ZString *v42; // [rsp+120h] [rbp+20h]
  OSuite::ZListBase::ZListIteratorBase v43; // [rsp+128h] [rbp+28h]
  OSuite::ZObject v44; // [rsp+140h] [rbp+40h]
  __int64 v45; // [rsp+148h] [rbp+48h]
  __int64 v46; // [rsp+150h] [rbp+50h]
  void **v47; // [rsp+158h] [rbp+58h]
  OSuite::ZString *v48; // [rsp+160h] [rbp+60h]
  OSuite::ZListBase::ZListIteratorBase v49; // [rsp+168h] [rbp+68h]
  void **v50; // [rsp+180h] [rbp+80h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator v51; // [rsp+188h] [rbp+88h]
  OSuite::ZJsonDocument v52; // [rsp+210h] [rbp+110h]

  v3 = this;
  v4 = zs;
  v52.m_Pairs.m_pLists = 0i64;
  OSuite::ZJsonDocument::ZJsonDocument(&v52, reader);
  if ( v52.m_bIsValid )
  {
    v42 = 0i64;
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v38, v5);
    v38.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::ZListBase'};
    v42 = 0i64;
    v41 = &OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::IHashable'};
    v6 = OSuite::TList<OSuite::ZString>::AllocList((OSuite::TList<OSuite::ZString> *)&v38, 0i64, 0x10ui64);
    v39 = 16i64;
    v40 = 0i64;
    v48 = 0i64;
    v42 = v6;
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v44, v7);
    v44.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::ZListBase'};
    v47 = &OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::IHashable'};
    v48 = 0i64;
    v8 = OSuite::TList<OSuite::ZString>::AllocList((OSuite::TList<OSuite::ZString> *)&v44, 0i64, 0x10ui64);
    v45 = 16i64;
    v46 = 0i64;
    v48 = v8;
    v37 = 0i64;
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v33, v9);
    v33.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::ZListBase'};
    v36 = &OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::IHashable'};
    v37 = 0i64;
    v10 = OSuite::TList<OSuite::ZString>::AllocList((OSuite::TList<OSuite::ZString> *)&v33, 0i64, 0x10ui64);
    _mm_store_si128((__m128i *)&v51.m_iterator.m_iterator.m_pList, (__m128i)0i64);
    v34 = 16i64;
    v35 = 0i64;
    v37 = v10;
    v51.m_pMap = 0i64;
    v51.m_iterator.m_iterator.m_parents.m_pList = 0i64;
    OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
      (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&v52.m_Pairs,
      &result);
    v50 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable';
    v51.m_pMap = result.m_pMap;
    v51.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
    v51.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    v51.m_iCurrentHash = result.m_iCurrentHash;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
      (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v51.m_iterator.m_iterator.vfptr,
      (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&result.m_iterator.m_iterator.vfptr);
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    v51.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    if ( !OSuite::ZString::IsNull((OSuite::ZString *)&v51.m_iterator.m_iterator) )
    {
      while ( 1 )
      {
        v11 = v51.m_iterator.m_iterator.m_pElement[2].vfptr;
        v12 = (OSuite::ZString *)&v51.m_iterator.m_iterator.m_pElement[1].m_pLeft;
        if ( v11 )
          break;
LABEL_17:
        OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&v51);
        if ( OSuite::ZString::IsNull((OSuite::ZString *)&v51.m_iterator.m_iterator) )
          goto LABEL_18;
      }
      if ( !OSuite::ZString::operator==(
              (OSuite::ZString *)&v51.m_iterator.m_iterator.m_pElement[1].m_pLeft,
              "s_ErrorsCodes")
        || OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v38) )
      {
        if ( !OSuite::ZString::operator==(v12, "s_ErrorsMessages")
          || OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v44) )
        {
          if ( !OSuite::ZString::operator==(v12, "s_ErrorsDetails")
            || OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v33) )
          {
            goto LABEL_16;
          }
          v13 = (OSuite::TList<OSuite::ZString> *)&v33;
        }
        else
        {
          v13 = (OSuite::TList<OSuite::ZString> *)&v44;
        }
      }
      else
      {
        v13 = (OSuite::TList<OSuite::ZString> *)&v38;
      }
      OSuite::ZString::Split((OSuite::ZString *)&v11[2], v13, 59);
LABEL_16:
      OSuite::ZStringBuilder::Append(v4, v12);
      OSuite::ZStringBuilder::Append(v4, " : ");
      OSuite::ZStringBuilder::Append(v4, (OSuite::ZString *)&v11[2]);
      OSuite::ZStringBuilder::Append(v4, "\n");
      goto LABEL_17;
    }
LABEL_18:
    v51.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
    v50 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable';
    v51.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    v51.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    v51.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    v51.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( v51.m_iterator.m_iterator.m_parents.m_pList )
      v51.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)v51.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    v32.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v32, (OSuite::ZListBase *)&v38);
    v32.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
    v43.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v43, (OSuite::ZListBase *)&v44);
    v43.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
    v49.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v49, (OSuite::ZListBase *)&v33);
    v49.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v32) )
    {
      if ( OSuite::ZListBase::ZListIteratorBase::AtEnd(&v43) || OSuite::ZListBase::ZListIteratorBase::AtEnd(&v49) )
        break;
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v32.m_pListBase);
      v14 = v32.m_nIndex;
      v15 = v32.m_pListBase;
      v16 = v32.m_nIndex + 1;
      OSuite::TList<OSuite::ZString>::Grow((OSuite::TList<OSuite::ZString> *)v32.m_pListBase, v32.m_nIndex + 1);
      if ( v14 >= v15->m_nTop )
        v15->m_nTop = v16;
      v17 = (OSuite::ZString *)(v15[1].m_nSize + 24 * v14);
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v43.m_pListBase);
      v18 = v43.m_nIndex;
      v19 = v43.m_pListBase;
      v20 = v43.m_nIndex + 1;
      OSuite::TList<OSuite::ZString>::Grow((OSuite::TList<OSuite::ZString> *)v43.m_pListBase, v43.m_nIndex + 1);
      if ( v18 >= v19->m_nTop )
        v19->m_nTop = v20;
      v21 = (OSuite::ZString *)(v19[1].m_nSize + 24 * v18);
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v49.m_pListBase);
      v22 = v49.m_nIndex;
      v23 = v49.m_pListBase;
      v24 = v49.m_nIndex + 1;
      OSuite::TList<OSuite::ZString>::Grow((OSuite::TList<OSuite::ZString> *)v49.m_pListBase, v49.m_nIndex + 1);
      if ( v22 >= v23->m_nTop )
        v23->m_nTop = v24;
      v25 = OSuite::ZString::c_str((OSuite::ZString *)(v23[1].m_nSize + 24 * v22));
      v26 = OSuite::ZString::c_str(v21);
      v27 = OSuite::ZString::ToInt(v17);
      OSuite::OSError::OSError(&v31, v27, v26, v25);
      v29 = v28;
      OSuite::TList<OSuite::OSError>::Grow(&v3->m_OSErrorsList, v3->m_OSErrorsList.m_nTop + 1);
      OSuite::OSError::operator=(&v3->m_OSErrorsList.m_pList[v3->m_OSErrorsList.m_nTop], v29);
      ++v3->m_OSErrorsList.m_nTop;
      OSuite::OSError::~OSError(&v31);
      OSuite::ZListBase::ZListIteratorBase::Next(&v32);
      OSuite::ZListBase::ZListIteratorBase::Next(&v43);
      OSuite::ZListBase::ZListIteratorBase::Next(&v49);
    }
    v49.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
    v43.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
    v32.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
    v33.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::ZListBase'};
    v36 = &OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::IHashable'};
    if ( v37 )
    {
      if ( LODWORD(v37[-1].m_pString) )
        v37->vfptr->__vecDelDtor((OSuite::ZObject *)&v37->vfptr, 3u);
      else
        Illusion::ShaderParam::operator delete(&v37[-1].m_pString);
    }
    v44.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::ZListBase'};
    v47 = &OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::IHashable'};
    if ( v48 )
    {
      if ( LODWORD(v48[-1].m_pString) )
        v48->vfptr->__vecDelDtor((OSuite::ZObject *)&v48->vfptr, 3u);
      else
        Illusion::ShaderParam::operator delete(&v48[-1].m_pString);
    }
    v38.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::ZListBase'};
    v41 = &OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::IHashable'};
    if ( v42 )
    {
      if ( LODWORD(v42[-1].m_pString) )
        v42->vfptr->__vecDelDtor((OSuite::ZObject *)&v42->vfptr, 3u);
      else
        Illusion::ShaderParam::operator delete(&v42[-1].m_pString);
    }
  }
  OSuite::ZJsonDocument::~ZJsonDocument(&v52);
}


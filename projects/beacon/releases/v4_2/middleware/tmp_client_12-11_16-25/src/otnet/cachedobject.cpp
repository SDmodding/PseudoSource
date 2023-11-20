// File Line: 19
// RVA: 0xEC8270
void __fastcall OSuite::ZCachedObject::ZCachedObject(OSuite::ZCachedObject *this, OSuite::ZUrl *url, OSuite::ZString *format, OSuite::ZString *httpMethod)
{
  OSuite::ZUrl *v4; // rbp
  OSuite::ZCachedObject *v5; // r14
  OSuite::ZString *v6; // rsi
  OSuite::ZString *v7; // rdi

  v4 = url;
  v5 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZCachedObject::`vftable';
  v6 = httpMethod;
  v7 = format;
  OSuite::ZEvent::ZEvent(&this->m_UpdatedEvent, 0);
  v5->m_Callbacks.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDelegateList<OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void>>::`vftable';
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&v5->m_Callbacks.m_delegates);
  v5->m_Callbacks.m_delegates.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable';
  OSuite::SCallbackData::SCallbackData(&v5->m_cbData);
  OSuite::ZString::ZString(&v5->m_Format, v7);
  OSuite::ZString::ZString(&v5->m_HttpMethod, v6);
  v5->m_pAtomObject = 0i64;
  v5->m_pNewAtomObject = 0i64;
  v5->m_pHttpRequest = 0i64;
  OSuite::ZUrl::operator=(&v5->m_cbData.URL, v4);
}

// File Line: 24
// RVA: 0xEC8334
void __fastcall OSuite::ZCachedObject::~ZCachedObject(OSuite::ZCachedObject *this)
{
  OSuite::ZCachedObject *v1; // rbx
  OSuite::ZAtomBase *v2; // rcx
  OSuite::ZAtomBase *v3; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZCachedObject::`vftable';
  v2 = this->m_pAtomObject;
  if ( v2 )
    v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 1u);
  v3 = v1->m_pNewAtomObject;
  if ( v3 )
    v3->vfptr->__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 1u);
  OSuite::ZString::~ZString(&v1->m_HttpMethod);
  OSuite::ZString::~ZString(&v1->m_Format);
  OSuite::SCallbackData::~SCallbackData(&v1->m_cbData);
  v1->m_Callbacks.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDelegateList<OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void>>::`vftable';
  v1->m_Callbacks.m_delegates.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable';
  OSuite::ZDoublyLinkedListBase::Clear((OSuite::ZDoublyLinkedListBase *)&v1->m_Callbacks.m_delegates.vfptr);
  OSuite::ZEvent::~ZEvent(&v1->m_UpdatedEvent);
}

// File Line: 30
// RVA: 0xEC885C
void __fastcall OSuite::ZCachedObject::ProcessData(OSuite::ZCachedObject *this, OSuite::IBufferedReader *pBufferedReader)
{
  OSuite::IBufferedReader *v2; // rbx
  OSuite::ZCachedObject *v3; // rdi
  OSuite::ZAtomBase *v4; // rbx
  OSuite::ZAtomBase *v5; // rcx
  OSuite::ZError *v6; // rbx
  OSuite::ZError::EError v7; // eax

  v2 = pBufferedReader;
  v3 = this;
  if ( this->m_cbData.eEvent == 4
    && (this->m_cbData.Status.eError
     || this->m_cbData.Status.nHttpStatus / 100 != 2
     || pBufferedReader && !pBufferedReader->vfptr->Eof((OSuite::IReader *)pBufferedReader))
    && v2 )
  {
    v4 = (OSuite::ZAtomBase *)v3->vfptr[1].__vecDelDtor((OSuite::ZObject *)&v3->vfptr, (unsigned int)v2);
    if ( OSuite::ZAtomBase::HasValidSource(v4) )
    {
      v5 = v3->m_pNewAtomObject;
      if ( v5 )
        v5->vfptr->__vecDelDtor((OSuite::ZObject *)&v5->vfptr, 1u);
      v3->m_pNewAtomObject = v4;
    }
    else
    {
      if ( v4 )
        v4->vfptr->__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 1u);
      v3->m_cbData.Status.eError = 3;
      v6 = OSuite::TSingleton<OSuite::ZError>::Object();
      v7 = (unsigned int)OSuite::ZHttp::HttpToOsError(v3->m_cbData.Status.eError);
      OSuite::ZError::SetThreadLastError(v6, v7, 1);
    }
  }
  OSuite::ZCachedObject::CallCallbacks(v3);
}

// File Line: 61
// RVA: 0xEC8500
void __fastcall OSuite::ZCachedObject::CallCallbacks(OSuite::ZCachedObject *this)
{
  OSuite::ZDoublyLinkedListBase::ZElementBase *v1; // r8
  OSuite::ZCachedObject *v2; // rbx
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v3; // [rsp+20h] [rbp-40h]
  void **v4; // [rsp+38h] [rbp-28h]
  OSuite::ZListBase::ZListIteratorBase v5; // [rsp+40h] [rbp-20h]

  v1 = this->m_Callbacks.m_delegates.m_pHead;
  v5.m_pListBase = 0i64;
  v5.m_nIndex = 0i64;
  v2 = this;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    &v3,
    (OSuite::ZDoublyLinkedListBase *)&this->m_Callbacks.m_delegates.vfptr,
    v1);
  v3.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  v4 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable';
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v5, (OSuite::ZListBase::ZListIteratorBase *)&v3);
  v5.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v5) )
  {
    (*(void (__fastcall **)(_QWORD, OSuite::SCallbackData *))(v5.m_nIndex + 32))(
      *(_QWORD *)(v5.m_nIndex + 24),
      &v2->m_cbData);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next((OSuite::ZDoublyLinkedListBase::ZIteratorBase *)&v5);
  }
  if ( v2->m_cbData.eEvent )
  {
    OSuite::ZDoublyLinkedListBase::Clear((OSuite::ZDoublyLinkedListBase *)&v2->m_Callbacks.m_delegates.vfptr);
    OSuite::ZEvent::Signal(&v2->m_UpdatedEvent);
  }
}

// File Line: 79
// RVA: 0xEC8470
void __fastcall OSuite::ZCachedObject::AddCallback(OSuite::ZCachedObject *this, OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *callback)
{
  OSuite::TDoublyLinkedList<OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void>>::Append(
    &this->m_Callbacks.m_delegates,
    callback);
}

// File Line: 84
// RVA: 0xEC85D0
void __fastcall OSuite::ZCachedObject::FetchAsync(OSuite::ZCachedObject *this)
{
  OSuite::ZCachedObject *v1; // rsi
  OSuite::ZHttpManager *v2; // rax
  OSuite::IHttpRequest *v3; // rax
  OSuite::IHttpRequest v4; // rbx
  __int64 v5; // rax
  OSuite::ZObjectVtbl *v6; // rbx
  __int64 v7; // rax
  OSuite::ZObjectVtbl *v8; // rbx
  __int64 v9; // rax
  OSuite::IHttpRequest *v10; // rcx
  OSuite::ZString v11; // [rsp+28h] [rbp-9h]
  __int64 v12; // [rsp+40h] [rbp+Fh]
  __int64 v13; // [rsp+48h] [rbp+17h]
  __int64 v14; // [rsp+50h] [rbp+1Fh]
  __int64 v15; // [rsp+58h] [rbp+27h]
  __int64 v16; // [rsp+60h] [rbp+2Fh]
  __int64 v17; // [rsp+68h] [rbp+37h]
  OSuite::ZCachedObject *v18; // [rsp+70h] [rbp+3Fh]
  bool (__fastcall *v19)(OSuite::ZCachedObject *, OSuite::IHttpRequest *, OSuite::ZHttp::EError); // [rsp+78h] [rbp+47h]
  char v20; // [rsp+80h] [rbp+4Fh]

  v1 = this;
  if ( !this->m_pHttpRequest )
  {
    this->m_cbData.eEvent = 0;
    this->m_cbData.Status.nHttpStatus = -1;
    this->m_cbData.Status.eError = 0;
    v2 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpRequestManager::CreateHttpRequest(v2->m_httpRequestManager, &v1->m_cbData.URL, v1, 1, 30);
    v1->m_pHttpRequest = v3;
    v4.vfptr = v3->vfptr;
    OSuite::ZString::ZString(&v11, &v1->m_HttpMethod);
    v4.vfptr[44].__vecDelDtor((OSuite::ZObject *)&v1->m_pHttpRequest->vfptr, v5);
    v6 = v1->m_pHttpRequest->vfptr;
    OSuite::ZString::ZString(&v11, &v1->m_Format);
    v6[41].__vecDelDtor((OSuite::ZObject *)&v1->m_pHttpRequest->vfptr, v7);
    v8 = v1->m_pHttpRequest->vfptr;
    OSuite::ZString::ZString(&v11, &v1->m_Format);
    v8[36].__vecDelDtor((OSuite::ZObject *)&v1->m_pHttpRequest->vfptr, v9);
    v1->m_pHttpRequest->vfptr[43].__vecDelDtor((OSuite::ZObject *)&v1->m_pHttpRequest->vfptr, (unsigned int)v1);
    v10 = v1->m_pHttpRequest;
    v13 = 0i64;
    v12 = 0i64;
    v15 = 0i64;
    v14 = 0i64;
    v17 = 0i64;
    v16 = 0i64;
    v19 = OSuite::ZCachedObject::OnFinished;
    v18 = v1;
    v20 = 0;
    v10->vfptr[6].__vecDelDtor((OSuite::ZObject *)&v10->vfptr, (unsigned int)&v12);
  }
}

// File Line: 107
// RVA: 0xEC8438
void __fastcall OSuite::ZCachedObject::Abort(OSuite::ZCachedObject *this)
{
  OSuite::ZCachedObject *v1; // rbx
  OSuite::ZHttpManager *v2; // rax

  v1 = this;
  if ( this->m_pHttpRequest )
  {
    v2 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpRequestManager::ShutdownHttpRequest(v2->m_httpRequestManager, v1->m_pHttpRequest);
  }
  v1->m_pHttpRequest = 0i64;
}

// File Line: 116
// RVA: 0xEC8714
OSuite::ZAtomBase *__fastcall OSuite::ZCachedObject::GetAtomObject(OSuite::ZCachedObject *this, OSuite::SCallbackData *pStatus)
{
  OSuite::ZCachedObject *v2; // rbx
  OSuite::ZAtomBase *v3; // rcx
  OSuite::ZAtomBase *v4; // rax

  v2 = this;
  if ( pStatus )
    OSuite::SCallbackData::operator=(pStatus, &this->m_cbData);
  if ( v2->m_pNewAtomObject )
  {
    v3 = v2->m_pAtomObject;
    if ( v3 )
      v3->vfptr->__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 1u);
    v4 = v2->m_pNewAtomObject;
    v2->m_pNewAtomObject = 0i64;
    v2->m_pAtomObject = v4;
  }
  return v2->m_pAtomObject;
}

// File Line: 138
// RVA: 0xEC8774
OSuite::ZString *__fastcall OSuite::ZUrl::GetFakeHost(OSuite::ZUrl *this)
{
  return &this->m_sFakeHost;
}

// File Line: 144
// RVA: 0xEC877C
char __fastcall OSuite::ZCachedObject::OnFinished(OSuite::ZCachedObject *this, OSuite::IHttpRequest *pHttpRequest, OSuite::ZHttp::EError error)
{
  OSuite::ZHttp::EError v3; // ebp
  OSuite::IHttpRequest *v4; // rbx
  OSuite::ZCachedObject *v5; // rsi
  __int64 v7; // rdi
  __int64 v8; // rax
  OSuite::TList<OSuite::OSError> *v9; // rax
  __int64 v10; // rax
  OSuite::IBufferedReader *v11; // rax
  OSuite::ZHttpManager *v12; // rax

  v3 = error;
  v4 = pHttpRequest;
  v5 = this;
  if ( !this->m_pHttpRequest )
    return 0;
  v7 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[30].__vecDelDtor)(pHttpRequest);
  v4->vfptr[43].__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 0);
  if ( v7 )
  {
    OSuite::ZHttpUtils::AnalyzeError((OSuite::SCallbackData *)(v7 + 64), v4, v3);
    v8 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v4->vfptr[33].__vecDelDtor)(v4);
    v9 = (OSuite::TList<OSuite::OSError> *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 96i64))(v8);
    OSuite::TList<OSuite::OSError>::operator=((OSuite::TList<OSuite::OSError> *)(v7 + 296), v9);
    if ( *(_DWORD *)(v7 + 68) )
    {
      v11 = 0i64;
    }
    else
    {
      v10 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v4->vfptr[33].__vecDelDtor)(v4);
      v11 = (OSuite::IBufferedReader *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 64i64))(v10);
    }
    OSuite::ZCachedObject::ProcessData((OSuite::ZCachedObject *)v7, v11);
  }
  v12 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::ZHttpRequestManager::ReleaseHttpRequest(v12->m_httpRequestManager, v4);
  v5->m_pHttpRequest = 0i64;
  return 1;
}


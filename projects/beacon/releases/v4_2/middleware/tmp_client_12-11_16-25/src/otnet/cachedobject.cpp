// File Line: 19
// RVA: 0xEC8270
void __fastcall OSuite::ZCachedObject::ZCachedObject(
        OSuite::ZCachedObject *this,
        OSuite::ZUrl *url,
        OSuite::ZString *format,
        OSuite::ZString *httpMethod)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZCachedObject::`vftable;
  OSuite::ZEvent::ZEvent(&this->m_UpdatedEvent, 0);
  this->m_Callbacks.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDelegateList<OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void>>::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&this->m_Callbacks.m_delegates);
  this->m_Callbacks.m_delegates.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::SCallbackData::SCallbackData(&this->m_cbData);
  OSuite::ZString::ZString(&this->m_Format, format);
  OSuite::ZString::ZString(&this->m_HttpMethod, httpMethod);
  this->m_pAtomObject = 0i64;
  this->m_pNewAtomObject = 0i64;
  this->m_pHttpRequest = 0i64;
  OSuite::ZUrl::operator=(&this->m_cbData.URL, url);
}

// File Line: 24
// RVA: 0xEC8334
void __fastcall OSuite::ZCachedObject::~ZCachedObject(OSuite::ZCachedObject *this)
{
  OSuite::ZAtomBase *m_pAtomObject; // rcx
  OSuite::ZAtomBase *m_pNewAtomObject; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZCachedObject::`vftable;
  m_pAtomObject = this->m_pAtomObject;
  if ( m_pAtomObject )
    m_pAtomObject->vfptr->__vecDelDtor(m_pAtomObject, 1u);
  m_pNewAtomObject = this->m_pNewAtomObject;
  if ( m_pNewAtomObject )
    m_pNewAtomObject->vfptr->__vecDelDtor(m_pNewAtomObject, 1u);
  OSuite::ZString::~ZString(&this->m_HttpMethod);
  OSuite::ZString::~ZString(&this->m_Format);
  OSuite::SCallbackData::~SCallbackData(&this->m_cbData);
  this->m_Callbacks.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDelegateList<OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void>>::`vftable;
  this->m_Callbacks.m_delegates.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZDoublyLinkedListBase::Clear(&this->m_Callbacks.m_delegates);
  OSuite::ZEvent::~ZEvent(&this->m_UpdatedEvent);
}

// File Line: 30
// RVA: 0xEC885C
void __fastcall OSuite::ZCachedObject::ProcessData(
        OSuite::ZCachedObject *this,
        OSuite::IBufferedReader *pBufferedReader)
{
  OSuite::ZAtomBase *v4; // rbx
  OSuite::ZAtomBase *m_pNewAtomObject; // rcx
  OSuite::ZError *v6; // rbx
  OSuite::ZError::EError v7; // eax

  if ( this->m_cbData.eEvent == EVENT_FINISHED
    && (this->m_cbData.Status.eError
     || this->m_cbData.Status.nHttpStatus / 100 != 2
     || pBufferedReader && !pBufferedReader->vfptr->Eof(pBufferedReader))
    && pBufferedReader )
  {
    v4 = (OSuite::ZAtomBase *)this->vfptr[1].__vecDelDtor(this, pBufferedReader);
    if ( OSuite::ZAtomBase::HasValidSource(v4) )
    {
      m_pNewAtomObject = this->m_pNewAtomObject;
      if ( m_pNewAtomObject )
        m_pNewAtomObject->vfptr->__vecDelDtor(m_pNewAtomObject, 1u);
      this->m_pNewAtomObject = v4;
    }
    else
    {
      if ( v4 )
        v4->vfptr->__vecDelDtor(v4, 1u);
      this->m_cbData.Status.eError = HTTPERROR_DATAPROCESSINGFAILED;
      v6 = OSuite::TSingleton<OSuite::ZError>::Object();
      v7 = (unsigned int)OSuite::ZHttp::HttpToOsError(this->m_cbData.Status.eError);
      OSuite::ZError::SetThreadLastError(v6, v7, 1);
    }
  }
  OSuite::ZCachedObject::CallCallbacks(this);
}

// File Line: 61
// RVA: 0xEC8500
void __fastcall OSuite::ZCachedObject::CallCallbacks(OSuite::ZCachedObject *this)
{
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pHead; // r8
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v3; // [rsp+20h] [rbp-40h] BYREF
  void **v4; // [rsp+38h] [rbp-28h]
  OSuite::ZListBase::ZListIteratorBase v5; // [rsp+40h] [rbp-20h] BYREF

  m_pHead = this->m_Callbacks.m_delegates.m_pHead;
  v5.m_pListBase = 0i64;
  v5.m_nIndex = 0i64;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(&v3, &this->m_Callbacks.m_delegates, m_pHead);
  v3.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  v4 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v5, (OSuite::ZListBase::ZListIteratorBase *)&v3);
  v5.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v5) )
  {
    (*(void (__fastcall **)(_QWORD, OSuite::SCallbackData *))(v5.m_nIndex + 32))(
      *(_QWORD *)(v5.m_nIndex + 24),
      &this->m_cbData);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next((OSuite::ZDoublyLinkedListBase::ZIteratorBase *)&v5);
  }
  if ( this->m_cbData.eEvent )
  {
    OSuite::ZDoublyLinkedListBase::Clear(&this->m_Callbacks.m_delegates);
    OSuite::ZEvent::Signal(&this->m_UpdatedEvent);
  }
}

// File Line: 79
// RVA: 0xEC8470
void __fastcall OSuite::ZCachedObject::AddCallback(
        OSuite::ZCachedObject *this,
        OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *callback)
{
  OSuite::TDoublyLinkedList<OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void>>::Append(
    &this->m_Callbacks.m_delegates,
    callback);
}

// File Line: 84
// RVA: 0xEC85D0
void __fastcall OSuite::ZCachedObject::FetchAsync(OSuite::ZCachedObject *this)
{
  OSuite::ZHttpManager *v2; // rax
  OSuite::IHttpRequest *v3; // rax
  OSuite::IHttpRequest v4; // rbx
  __int64 v5; // rax
  OSuite::ZObjectVtbl *vfptr; // rbx
  __int64 v7; // rax
  OSuite::ZObjectVtbl *v8; // rbx
  __int64 v9; // rax
  OSuite::IHttpRequest *m_pHttpRequest; // rcx
  OSuite::ZString v11; // [rsp+28h] [rbp-9h] BYREF
  __int64 v12[8]; // [rsp+40h] [rbp+Fh] BYREF
  char v13; // [rsp+80h] [rbp+4Fh]

  if ( !this->m_pHttpRequest )
  {
    this->m_cbData.eEvent = EVENT_NONE;
    this->m_cbData.Status.nHttpStatus = -1;
    this->m_cbData.Status.eError = HTTPERROR_OK;
    v2 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpRequestManager::CreateHttpRequest(v2->m_httpRequestManager, &this->m_cbData.URL, this, 1, 30);
    this->m_pHttpRequest = v3;
    v4.vfptr = v3->vfptr;
    OSuite::ZString::ZString(&v11, &this->m_HttpMethod);
    v4.vfptr[44].__vecDelDtor(this->m_pHttpRequest, v5);
    vfptr = this->m_pHttpRequest->vfptr;
    OSuite::ZString::ZString(&v11, &this->m_Format);
    vfptr[41].__vecDelDtor(this->m_pHttpRequest, v7);
    v8 = this->m_pHttpRequest->vfptr;
    OSuite::ZString::ZString(&v11, &this->m_Format);
    v8[36].__vecDelDtor(this->m_pHttpRequest, v9);
    this->m_pHttpRequest->vfptr[43].__vecDelDtor(this->m_pHttpRequest, (unsigned int)this);
    m_pHttpRequest = this->m_pHttpRequest;
    memset(v12, 0, 48);
    v12[7] = (__int64)OSuite::ZCachedObject::OnFinished;
    v12[6] = (__int64)this;
    v13 = 0;
    m_pHttpRequest->vfptr[6].__vecDelDtor(m_pHttpRequest, (unsigned int)v12);
  }
}

// File Line: 107
// RVA: 0xEC8438
void __fastcall OSuite::ZCachedObject::Abort(OSuite::ZCachedObject *this)
{
  OSuite::ZHttpManager *v2; // rax

  if ( this->m_pHttpRequest )
  {
    v2 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpRequestManager::ShutdownHttpRequest(v2->m_httpRequestManager, this->m_pHttpRequest);
  }
  this->m_pHttpRequest = 0i64;
}

// File Line: 116
// RVA: 0xEC8714
OSuite::ZAtomBase *__fastcall OSuite::ZCachedObject::GetAtomObject(
        OSuite::ZCachedObject *this,
        OSuite::SCallbackData *pStatus)
{
  OSuite::ZAtomBase *m_pAtomObject; // rcx
  OSuite::ZAtomBase *m_pNewAtomObject; // rax

  if ( pStatus )
    OSuite::SCallbackData::operator=(pStatus, &this->m_cbData);
  if ( this->m_pNewAtomObject )
  {
    m_pAtomObject = this->m_pAtomObject;
    if ( m_pAtomObject )
      m_pAtomObject->vfptr->__vecDelDtor(m_pAtomObject, 1u);
    m_pNewAtomObject = this->m_pNewAtomObject;
    this->m_pNewAtomObject = 0i64;
    this->m_pAtomObject = m_pNewAtomObject;
  }
  return this->m_pAtomObject;
}

// File Line: 138
// RVA: 0xEC8774
OSuite::ZString *__fastcall OSuite::ZUrl::GetFakeHost(OSuite::ZUrl *this)
{
  return &this->m_sFakeHost;
}

// File Line: 144
// RVA: 0xEC877C
char __fastcall OSuite::ZCachedObject::OnFinished(
        OSuite::ZCachedObject *this,
        OSuite::IHttpRequest *pHttpRequest,
        OSuite::ZHttp::EError error)
{
  __int64 v7; // rdi
  __int64 v8; // rax
  OSuite::TList<OSuite::OSError> *v9; // rax
  __int64 v10; // rax
  OSuite::IBufferedReader *v11; // rax
  OSuite::ZHttpManager *v12; // rax

  if ( !this->m_pHttpRequest )
    return 0;
  v7 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[30].__vecDelDtor)(pHttpRequest);
  pHttpRequest->vfptr[43].__vecDelDtor(pHttpRequest, 0);
  if ( v7 )
  {
    OSuite::ZHttpUtils::AnalyzeError((OSuite::SCallbackData *)(v7 + 64), pHttpRequest, error);
    v8 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[33].__vecDelDtor)(pHttpRequest);
    v9 = (OSuite::TList<OSuite::OSError> *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 96i64))(v8);
    OSuite::TList<OSuite::OSError>::operator=((OSuite::TList<OSuite::OSError> *)(v7 + 296), v9);
    if ( *(_DWORD *)(v7 + 68) )
    {
      v11 = 0i64;
    }
    else
    {
      v10 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[33].__vecDelDtor)(pHttpRequest);
      v11 = (OSuite::IBufferedReader *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 64i64))(v10);
    }
    OSuite::ZCachedObject::ProcessData((OSuite::ZCachedObject *)v7, v11);
  }
  v12 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::ZHttpRequestManager::ReleaseHttpRequest(v12->m_httpRequestManager, pHttpRequest);
  this->m_pHttpRequest = 0i64;
  return 1;
}


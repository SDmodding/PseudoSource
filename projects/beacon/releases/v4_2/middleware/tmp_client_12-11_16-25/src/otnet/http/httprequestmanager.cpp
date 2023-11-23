// File Line: 24
// RVA: 0xECE860
void __fastcall OSuite::ZHttpRequestManager::ZHttpRequestManager(OSuite::ZHttpRequestManager *this)
{
  hkEntitySelectorAll *v2; // rax
  hkpEntity *v3; // rdx
  const char *v4; // rdx
  hkEntitySelectorAll *v5; // rax
  hkpEntity *v6; // rdx
  int NumOriginalFrames; // eax
  OSuite::ZString *v8; // rax
  OSuite::ZString that; // [rsp+20h] [rbp-50h] BYREF
  OSuite::ZStringBuilder v10; // [rsp+38h] [rbp-38h] BYREF

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpRequestManager::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&this->m_scheduledForDeleteHttpRequestsList);
  this->m_scheduledForDeleteHttpRequestsList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&this->m_pendingHttpRequestsList);
  this->m_pendingHttpRequestsList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZMutex::ZMutex(&this->m_RequestMutex);
  OSuite::ZString::ZString(&this->m_osPlatform);
  OSuite::ZString::ZString(&this->m_userAgent);
  v2 = (hkEntitySelectorAll *)OSuite::GameInterface();
  if ( (unsigned int)hkaReferencePoseAnimation::getNumOriginalFrames(v2, v3) == 2 )
  {
    v4 = "OnLive";
  }
  else
  {
    v5 = (hkEntitySelectorAll *)OSuite::GameInterface();
    NumOriginalFrames = hkaReferencePoseAnimation::getNumOriginalFrames(v5, v6);
    v4 = "Steam";
    if ( NumOriginalFrames != 1 )
      v4 = "Windows";
  }
  OSuite::ZString::ZString(&that, v4);
  OSuite::ZString::operator=(&this->m_osPlatform, &that);
  OSuite::ZString::~ZString(&that);
  v10.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v10, 0x20ui64);
  OSuite::ZStringBuilder::Append(&v10, "OS/");
  OSuite::ZStringBuilder::Append(&v10, "4.2.14");
  OSuite::ZStringBuilder::Append(&v10, "/");
  OSuite::ZStringBuilder::Append(&v10, &this->m_osPlatform);
  OSuite::ZStringBuilder::Append(&v10, "/");
  OSuite::ZStringBuilder::Append(&v10, "official");
  v8 = OSuite::ZStringBuilder::ToString(&v10, &that);
  OSuite::ZString::operator=(&this->m_userAgent, v8);
  OSuite::ZString::~ZString(&that);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v10);
}

// File Line: 57
// RVA: 0xECE9EC
void __fastcall OSuite::ZHttpRequestManager::~ZHttpRequestManager(OSuite::ZHttpRequestManager *this)
{
  OSuite::ZMutex *p_m_RequestMutex; // rbx
  OSuite::ZObjectVtbl *vfptr; // rcx
  OSuite::ZObjectVtbl *v4; // rcx
  OSuite::ZDoublyLinkedListBase::ZIteratorBase that; // [rsp+20h] [rbp-40h] BYREF
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v6; // [rsp+38h] [rbp-28h] BYREF

  p_m_RequestMutex = &this->m_RequestMutex;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpRequestManager::`vftable;
  OSuite::ZMutex::Lock(&this->m_RequestMutex);
  v6.m_pList = 0i64;
  v6.m_pElement = 0i64;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    &v6,
    &this->m_pendingHttpRequestsList,
    this->m_pendingHttpRequestsList.m_pHead);
  v6.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v6) )
  {
    OSuite::ZHttpRequestManager::ShutdownHttpRequest(this, (OSuite::IHttpRequest *)v6.m_pElement[1].vfptr);
    (*((void (__fastcall **)(OSuite::ZObjectVtbl *, _QWORD))v6.m_pElement[1].vfptr->__vecDelDtor + 50))(
      v6.m_pElement[1].vfptr,
      0i64);
    vfptr = v6.m_pElement[1].vfptr;
    if ( vfptr )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, __int64))vfptr->__vecDelDtor)(vfptr, 1i64);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Remove(&v6);
  }
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    &that,
    &this->m_scheduledForDeleteHttpRequestsList,
    this->m_scheduledForDeleteHttpRequestsList.m_pHead);
  that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::operator=(&v6, &that);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v6) )
  {
    (*((void (__fastcall **)(OSuite::ZObjectVtbl *, _QWORD))v6.m_pElement[1].vfptr->__vecDelDtor + 50))(
      v6.m_pElement[1].vfptr,
      0i64);
    v4 = v6.m_pElement[1].vfptr;
    if ( v4 )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, __int64))v4->__vecDelDtor)(v4, 1i64);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Remove(&v6);
  }
  OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_pendingHttpRequestsList);
  OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_scheduledForDeleteHttpRequestsList);
  OSuite::ZMutex::Unlock(p_m_RequestMutex);
  OSuite::ZString::~ZString(&this->m_userAgent);
  OSuite::ZString::~ZString(&this->m_osPlatform);
  OSuite::ZMutex::~ZMutex(p_m_RequestMutex);
  this->m_pendingHttpRequestsList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZDoublyLinkedListBase::Clear(&this->m_pendingHttpRequestsList);
  this->m_scheduledForDeleteHttpRequestsList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZDoublyLinkedListBase::Clear(&this->m_scheduledForDeleteHttpRequestsList);
}

// File Line: 94
// RVA: 0xECF394
// bad sp value at call has been detected, the output may be wrong!
void __fastcall OSuite::ZHttpRequestManager::Update(OSuite::ZHttpRequestManager *this, OSuite::ZObject *a2)
{
  char v3; // r12
  OSuite::IHttpRequest *v4; // rsi
  OSuite::ZString *v5; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pHead; // rdx
  OSuite::ZDoublyLinkedListBase::ZElementBase *v7; // rdi
  OSuite::IHttpRequest *v8; // rdi
  int v9; // eax
  int v10; // esi
  OSuite::ZDoublyLinkedListBase::ZElementBase *v11; // rdx
  OSuite::ZString *v12; // rax
  bool IsNull; // al
  unsigned __int64 *v14; // rax
  unsigned __int64 Clock; // rax
  OSuite::IHttpRequest *data; // [rsp+0h] [rbp-39h] BYREF
  OSuite::ZDoublyLinkedListBase::ZIteratorBase that; // [rsp+8h] [rbp-31h] BYREF
  OSuite::ZClock v18; // [rsp+20h] [rbp-19h] BYREF
  OSuite::ZString v19; // [rsp+28h] [rbp-11h] BYREF
  OSuite::ZClock v20; // [rsp+40h] [rbp+7h] BYREF
  OSuite::ZRedBlackTreeBase v21; // [rsp+48h] [rbp+Fh] BYREF

  v3 = 0;
  v19.OSuite::IHashable::vfptr = 0i64;
  v19.m_pString = 0i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v21.m_pTop, a2);
  v21.m_pTop = 0i64;
  v19.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(&v21);
  v21.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZMutex::Lock(&this->m_RequestMutex);
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_scheduledForDeleteHttpRequestsList) )
  {
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
      &that,
      &this->m_scheduledForDeleteHttpRequestsList,
      this->m_scheduledForDeleteHttpRequestsList.m_pHead);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::operator=((OSuite::ZDoublyLinkedListBase::ZIteratorBase *)&v19, &that);
    while ( !OSuite::ZString::IsNull(&v19) )
    {
      v4 = *(OSuite::IHttpRequest **)&v19.m_pString->m_szString[4];
      data = v4;
      v5 = (OSuite::ZString *)OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::Find(
                                &this->m_pendingHttpRequestsList,
                                (OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::ZIterator *)&that,
                                &data);
      if ( !OSuite::ZString::IsNull(v5)
        && !OSuite::ZRedBlackTreeBase::IsEmpty((OSuite::ZRedBlackTreeBase *)&this->m_pendingHttpRequestsList) )
      {
        m_pHead = this->m_pendingHttpRequestsList.m_pHead;
        while ( (OSuite::IHttpRequest *)m_pHead[1].vfptr != v4 )
        {
          m_pHead = m_pHead->m_pNext;
          if ( m_pHead == this->m_pendingHttpRequestsList.m_pHead )
          {
            m_pHead = 0i64;
            break;
          }
        }
        if ( m_pHead )
          OSuite::ZDoublyLinkedListBase::DeleteElement(&this->m_pendingHttpRequestsList, m_pHead);
      }
      LOBYTE(m_pHead) = 1;
      v4->vfptr[50].__vecDelDtor(v4, (unsigned int)m_pHead);
      v4->vfptr->__vecDelDtor(v4, 1u);
      OSuite::ZDoublyLinkedListBase::ZIteratorBase::Remove((OSuite::ZDoublyLinkedListBase::ZIteratorBase *)&v19);
    }
  }
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_pendingHttpRequestsList) )
  {
    if ( &v21 != (OSuite::ZRedBlackTreeBase *)&this->m_pendingHttpRequestsList )
    {
      OSuite::ZDoublyLinkedListBase::operator=((OSuite::ZDoublyLinkedListBase *)&v21, &this->m_pendingHttpRequestsList);
      v7 = this->m_pendingHttpRequestsList.m_pHead;
      if ( v7 )
      {
        do
        {
          OSuite::TDoublyLinkedList<OSuite::ZMetricAppender *>::Append(
            (OSuite::TDoublyLinkedList<OSuite::ManagedCallback *> *)&v21,
            (OSuite::ManagedCallback **)&v7[1]);
          v7 = v7->m_pNext;
        }
        while ( v7 != this->m_pendingHttpRequestsList.m_pHead );
      }
    }
    OSuite::ZMutex::Unlock(&this->m_RequestMutex);
    OSuite::ZClock::ZClock(&v20);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
      &that,
      (OSuite::ZDoublyLinkedListBase *)&v21,
      (OSuite::ZDoublyLinkedListBase::ZElementBase *)v21.m_pTop);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::operator=((OSuite::ZDoublyLinkedListBase::ZIteratorBase *)&v19, &that);
    while ( 1 )
    {
      while ( 1 )
      {
        if ( OSuite::ZString::IsNull(&v19) )
        {
          OSuite::ZOEdmBase::CleanTempData((int)&v20);
          goto LABEL_51;
        }
        data = *(OSuite::IHttpRequest **)&v19.m_pString->m_szString[4];
        v8 = data;
        v9 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v8->vfptr[24].__vecDelDtor)(v8);
        v10 = v9;
        if ( v9 <= 32 )
          break;
        if ( v9 == 64 )
          goto LABEL_25;
        if ( ((v9 - 256) & 0xFFFFFEFF) != 0 )
        {
          if ( v9 == 2048 )
          {
            OSuite::ZMutex::Lock(&this->m_RequestMutex);
            if ( !OSuite::ZRedBlackTreeBase::IsEmpty((OSuite::ZRedBlackTreeBase *)&this->m_pendingHttpRequestsList) )
            {
              v11 = this->m_pendingHttpRequestsList.m_pHead;
              while ( (OSuite::IHttpRequest *)v11[1].vfptr != v8 )
              {
                v11 = v11->m_pNext;
                if ( v11 == this->m_pendingHttpRequestsList.m_pHead )
                {
                  v11 = 0i64;
                  break;
                }
              }
              if ( v11 )
                OSuite::ZDoublyLinkedListBase::DeleteElement(&this->m_pendingHttpRequestsList, v11);
            }
            LOBYTE(v11) = 1;
            v8->vfptr[50].__vecDelDtor(v8, (unsigned int)v11);
            v12 = (OSuite::ZString *)OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::Find(
                                       &this->m_scheduledForDeleteHttpRequestsList,
                                       (OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::ZIterator *)&that,
                                       &data);
            IsNull = OSuite::ZString::IsNull(v12);
            that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
            if ( IsNull )
              OSuite::TDoublyLinkedList<OSuite::ZMetricAppender *>::Append(
                (OSuite::TDoublyLinkedList<OSuite::ManagedCallback *> *)&this->m_scheduledForDeleteHttpRequestsList,
                (OSuite::ManagedCallback **)&data);
            OSuite::ZMutex::Unlock(&this->m_RequestMutex);
          }
        }
        else
        {
          OSuite::ZHttpRequestManager::InternalOnFinished(this, v8);
        }
LABEL_26:
        OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next((OSuite::ZDoublyLinkedListBase::ZIteratorBase *)&v19);
        v3 = 0;
      }
      switch ( v9 )
      {
        case 32:
          OSuite::ZHttpRequestManager::ReceiveHttpResponse(this, v8);
          goto LABEL_26;
        case 1:
          OSuite::ZHttpRequestManager::InternalOnStarted(this, v8);
          goto LABEL_26;
        case 2:
          OSuite::ZHttpRequestManager::ConnectHttpRequest(this, v8);
          goto LABEL_26;
        case 4:
          goto LABEL_25;
        case 8:
          OSuite::ZHttpRequestManager::SendHttpRequestData(this, v8);
          goto LABEL_26;
      }
      if ( v9 != 16 )
        goto LABEL_26;
LABEL_25:
      ((void (__fastcall *)(OSuite::IHttpRequest *))v8->vfptr[5].__vecDelDtor)(v8);
      if ( v10 != ((unsigned int (__fastcall *)(OSuite::IHttpRequest *))v8->vfptr[24].__vecDelDtor)(v8) )
        goto LABEL_26;
      if ( v3 )
      {
        Clock = OSuite::ZClock::_GetClock();
        if ( OSuite::ZClock::_ClockToTime(Clock - v20.m_clock, UNIT_SECONDS) >= 0xF )
        {
          v8->vfptr[40].__vecDelDtor(v8, 16u);
          v8->vfptr[37].__vecDelDtor(v8, 512u);
        }
      }
      else
      {
        OSuite::ZClock::ZClock(&v18);
        v20.m_clock = *v14;
        OSuite::ZOEdmBase::CleanTempData((int)&v18);
        v3 = 1;
      }
    }
  }
  OSuite::ZMutex::Unlock(&this->m_RequestMutex);
LABEL_51:
  v21.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZDoublyLinkedListBase::Clear((OSuite::ZDoublyLinkedListBase *)&v21);
}

// File Line: 229
// RVA: 0xECEC98
void __fastcall OSuite::ZHttpRequestManager::CreateHttpRequest(
        OSuite::ZHttpRequestManager *this,
        OSuite::ZUrl *url,
        void *pParent,
        bool bKeepAlive,
        int nTimeOut)
{
  OSuite::ZHttpRequest *v8; // rbx

  v8 = (OSuite::ZHttpRequest *)OSuite::ZObject::operator new(0x498ui64);
  if ( v8 )
  {
    OSuite::ZHttpRequest::__autoclassinit(v8, 1u);
    OSuite::ZHttpRequest::ZHttpRequest(v8, url, pParent, bKeepAlive, nTimeOut);
  }
}

// File Line: 257
// RVA: 0xECF26C
char __fastcall OSuite::ZHttpRequestManager::ReleaseHttpRequest(
        OSuite::ZHttpRequestManager *this,
        OSuite::IHttpRequest *pHttpRequest)
{
  char result; // al

  result = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[47].__vecDelDtor)(pHttpRequest);
  if ( result )
    return OSuite::ZHttpRequestManager::InternalReleaseHttpRequest(this, pHttpRequest);
  return result;
}

// File Line: 269
// RVA: 0xECF314
char __fastcall OSuite::ZHttpRequestManager::ShutdownHttpRequest(
        OSuite::ZHttpRequestManager *this,
        OSuite::IHttpRequest *pHttpRequest)
{
  void *v4; // rsi
  OSuite::ZObjectAccessor *v5; // rax
  char v6; // bl
  OSuite::ZObjectAccessor *v7; // rax

  v4 = (void *)((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[32].__vecDelDtor)(pHttpRequest);
  v5 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::AccessObject(v5, v4);
  v6 = 0;
  if ( ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[48].__vecDelDtor)(pHttpRequest) )
    v6 = OSuite::ZHttpRequestManager::InternalReleaseHttpRequest(this, pHttpRequest);
  v7 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::ReleaseObject(v7, v4);
  return v6;
}

// File Line: 283
// RVA: 0xECEFD0
char __fastcall OSuite::ZHttpRequestManager::InternalReleaseHttpRequest(
        OSuite::ZHttpRequestManager *this,
        OSuite::IHttpRequest *pHttpRequest)
{
  OSuite::ZObjectVtbl *vfptr; // rax
  void *v5; // rbx
  OSuite::ZObjectAccessor *v6; // rax
  OSuite::ZObjectAccessor *v7; // rax
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::ZIterator v11; // [rsp+28h] [rbp-50h] BYREF
  OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::ZIterator result; // [rsp+40h] [rbp-38h] BYREF
  OSuite::IHttpRequest *data; // [rsp+58h] [rbp-20h] BYREF

  vfptr = pHttpRequest->vfptr;
  data = pHttpRequest;
  v5 = (void *)((__int64 (__fastcall *)(OSuite::IHttpRequest *))vfptr[32].__vecDelDtor)(pHttpRequest);
  v6 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::AccessObject(v6, v5);
  pHttpRequest->vfptr[37].__vecDelDtor(pHttpRequest, 2048u);
  v7 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::ReleaseObject(v7, v5);
  OSuite::ZMutex::Lock(&this->m_RequestMutex);
  v8 = (OSuite::ZString *)OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::Find(
                            &this->m_pendingHttpRequestsList,
                            &result,
                            &data);
  if ( OSuite::ZString::IsNull(v8) )
  {
    v9 = (OSuite::ZString *)OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::Find(
                              &this->m_scheduledForDeleteHttpRequestsList,
                              &v11,
                              &data);
    if ( OSuite::ZString::IsNull(v9) )
      OSuite::TDoublyLinkedList<OSuite::ZMetricAppender *>::Append(
        (OSuite::TDoublyLinkedList<OSuite::ManagedCallback *> *)&this->m_scheduledForDeleteHttpRequestsList,
        (OSuite::ManagedCallback **)&data);
  }
  OSuite::ZMutex::Unlock(&this->m_RequestMutex);
  return 1;
}

// File Line: 334
// RVA: 0xECED04
void __fastcall OSuite::ZHttpRequestManager::ExecuteRequest(
        OSuite::ZHttpRequestManager *this,
        OSuite::ManagedCallback *pHttpRequest)
{
  OSuite::ZObjectVtbl *vfptr; // rax
  OSuite::ManagedCallback *data; // [rsp+20h] [rbp-18h] BYREF

  vfptr = (OSuite::ZObjectVtbl *)pHttpRequest->OSuite::ICallback<void,void>::vfptr;
  data = pHttpRequest;
  ((void (__fastcall *)(OSuite::ManagedCallback *))vfptr[8].__vecDelDtor)(pHttpRequest);
  ((void (__fastcall *)(OSuite::ManagedCallback *, __int64))pHttpRequest->OSuite::ICallback<void,void>::vfptr[12].Clone)(
    pHttpRequest,
    1i64);
  OSuite::ZMutex::Lock(&this->m_RequestMutex);
  OSuite::TDoublyLinkedList<OSuite::ZMetricAppender *>::Append(
    (OSuite::TDoublyLinkedList<OSuite::ManagedCallback *> *)&this->m_pendingHttpRequestsList,
    &data);
  OSuite::ZMutex::Unlock(&this->m_RequestMutex);
}

// File Line: 357
// RVA: 0xECEC20
void __fastcall OSuite::ZHttpRequestManager::ConnectHttpRequest(
        OSuite::ZHttpRequestManager *this,
        OSuite::IHttpRequest *httpRequest)
{
  char v4; // al
  OSuite::IHttpRequest *v5; // rcx
  bool v6; // zf
  OSuite::ZObjectVtbl *vfptr; // rax
  OSuite::ZHttp::EError v8; // eax

  v4 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[49].__vecDelDtor)(httpRequest);
  v5 = httpRequest;
  v6 = v4 == 0;
  vfptr = httpRequest->vfptr;
  if ( v6 )
    goto LABEL_6;
  if ( !((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))vfptr[20].__vecDelDtor)(httpRequest)
    && ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[19].__vecDelDtor)(httpRequest)
    && !((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[52].__vecDelDtor)(httpRequest) )
  {
    vfptr = httpRequest->vfptr;
    v5 = httpRequest;
LABEL_6:
    v8 = ((unsigned int (__fastcall *)(OSuite::IHttpRequest *))vfptr[28].__vecDelDtor)(v5);
    OSuite::ZHttpRequestManager::FinishHttpRequest(this, httpRequest, v8);
  }
}

// File Line: 386
// RVA: 0xECF2A4
void __fastcall OSuite::ZHttpRequestManager::SendHttpRequestData(
        OSuite::ZHttpRequestManager *this,
        OSuite::IHttpRequest *httpRequest)
{
  bool v4; // zf
  OSuite::ZObjectVtbl *vfptr; // rax
  unsigned int v6; // eax

  v4 = ((unsigned int (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[28].__vecDelDtor)(httpRequest) == 0;
  vfptr = httpRequest->vfptr;
  if ( v4 )
  {
    if ( ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))vfptr[22].__vecDelDtor)(httpRequest) )
      httpRequest->vfptr[37].__vecDelDtor(httpRequest, 32u);
    else
      OSuite::ZHttpRequestManager::InternalOnDataNeeded(this, httpRequest);
  }
  else
  {
    v6 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))vfptr[28].__vecDelDtor)(httpRequest);
    OSuite::ZHttpRequestManager::FinishHttpRequest(this, httpRequest, v6);
  }
}

// File Line: 408
// RVA: 0xECF0C0
void __fastcall OSuite::ZHttpRequestManager::ReceiveHttpResponse(
        OSuite::ZHttpRequestManager *this,
        OSuite::IHttpRequest *httpRequest)
{
  bool v4; // zf
  OSuite::ZObjectVtbl *vfptr; // rax
  __int64 v6; // rbx
  __int64 v7; // rax
  OSuite::ZUrl *v8; // rax
  OSuite::ZString *v9; // rax
  bool v10; // bl
  __int64 v11; // rdx
  unsigned int v12; // r8d
  char v13; // al
  OSuite::IHttpRequest *v14; // rdx
  OSuite::ZHttpRequestManager *v15; // rcx
  OSuite::ZString result; // [rsp+20h] [rbp-D8h] BYREF
  OSuite::ZUrl v17; // [rsp+40h] [rbp-B8h] BYREF

  v4 = ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[10].__vecDelDtor)(httpRequest) == 0;
  vfptr = httpRequest->vfptr;
  if ( v4 )
  {
    v6 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))vfptr[33].__vecDelDtor)(httpRequest);
    if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v6 + 32i64))(v6) == 301
      || (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v6 + 32i64))(v6) == 302 )
    {
      v7 = *(_QWORD *)v6;
      v17.m_sProtocol.m_pString = 0i64;
      v17.m_sHost.m_pString = 0i64;
      v17.m_sFakeHost.vfptr = 0i64;
      v17.m_sPath.vfptr = 0i64;
      v17.m_urlParameters.m_parameters.vfptr = 0i64;
      v17.m_urlParameters.m_arrayParameters.vfptr = 0i64;
      v8 = (OSuite::ZUrl *)(*(__int64 (__fastcall **)(__int64))(v7 + 48))(v6);
      OSuite::ZUrl::ZUrl(&v17, v8);
      v9 = OSuite::ZUrl::ToString(&v17, &result, 0);
      v10 = !OSuite::ZString::Empty(v9);
      OSuite::ZString::~ZString(&result);
      if ( v10 )
      {
        LOBYTE(v11) = 1;
        httpRequest->vfptr[50].__vecDelDtor(httpRequest, v11);
        httpRequest->vfptr[45].__vecDelDtor(httpRequest, (unsigned int)&v17);
        httpRequest->vfptr[37].__vecDelDtor(httpRequest, 1u);
        OSuite::ZUrl::~ZUrl(&v17);
        return;
      }
      OSuite::ZUrl::~ZUrl(&v17);
    }
    goto LABEL_7;
  }
  v13 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))vfptr[18].__vecDelDtor)(httpRequest);
  v14 = httpRequest;
  v15 = this;
  if ( v13 )
  {
    v12 = 5;
LABEL_15:
    OSuite::ZHttpRequestManager::FinishHttpRequest(v15, v14, v12);
    return;
  }
  if ( !OSuite::ZHttpRequestManager::InternalOnDataAvailable(this, httpRequest)
    && ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[12].__vecDelDtor)(httpRequest) )
  {
    if ( !((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[18].__vecDelDtor)(httpRequest) )
    {
      OSuite::ZHttpRequestManager::InternalOnDataAvailable(this, httpRequest);
      v12 = 0;
      goto LABEL_14;
    }
LABEL_7:
    v12 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[28].__vecDelDtor)(httpRequest);
LABEL_14:
    v15 = this;
    v14 = httpRequest;
    goto LABEL_15;
  }
}

// File Line: 480
// RVA: 0xECED7C
void __fastcall OSuite::ZHttpRequestManager::FinishHttpRequest(
        OSuite::ZHttpRequestManager *this,
        OSuite::IHttpRequest *httpRequest,
        unsigned int lastError)
{
  OSuite::ZError *v5; // rbx
  OSuite::ZError::EError v6; // eax

  if ( ((unsigned int (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[28].__vecDelDtor)(httpRequest) )
  {
    v5 = OSuite::TSingleton<OSuite::ZError>::Object();
    v6 = (unsigned int)OSuite::ZHttp::HttpToOsError(lastError);
    OSuite::ZError::SetThreadLastError(v5, v6, 1);
  }
  else
  {
    httpRequest->vfptr[40].__vecDelDtor(httpRequest, lastError);
  }
  httpRequest->vfptr[37].__vecDelDtor(httpRequest, 256u);
}

// File Line: 494
// RVA: 0xECEF88
void __fastcall OSuite::ZHttpRequestManager::InternalOnStarted(
        OSuite::ZHttpRequestManager *this,
        OSuite::IHttpRequest *httpRequest)
{
  OSuite::ZOnStartedHttpRequest *v4; // rcx
  OSuite::ZHttpRequestClientCBWrapper *v5; // rax

  v4 = (OSuite::ZOnStartedHttpRequest *)OSuite::ZObject::operator new(0x28ui64);
  v5 = 0i64;
  if ( v4 )
  {
    v4->m_pHttpRequest = 0i64;
    OSuite::ZOnStartedHttpRequest::ZOnStartedHttpRequest(v4, httpRequest);
  }
  OSuite::ZHttpRequestManager::CallCallbacks(this, v5);
}

// File Line: 504
// RVA: 0xECEDF0
char __fastcall OSuite::ZHttpRequestManager::InternalOnDataAvailable(
        OSuite::ZHttpRequestManager *this,
        OSuite::IHttpRequest *httpRequest)
{
  OSuite::ZHttpRequestClientCBWrapper *v4; // rbx
  _QWORD *v5; // rax
  OSuite::ZOnDataAvailableHttpRequest *v6; // rax
  OSuite::ZHttpRequestClientCBWrapper *v7; // rax
  char v9[24]; // [rsp+20h] [rbp-18h] BYREF

  v4 = 0i64;
  if ( !((__int64 (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[11].__vecDelDtor)(httpRequest) )
    return 0;
  v5 = httpRequest->vfptr[2].__vecDelDtor(httpRequest, v9);
  if ( !*v5 && !v5[1] )
    return 0;
  v6 = (OSuite::ZOnDataAvailableHttpRequest *)OSuite::ZObject::operator new(0x28ui64);
  if ( v6 )
  {
    v6->m_pHttpRequest = 0i64;
    OSuite::ZOnDataAvailableHttpRequest::ZOnDataAvailableHttpRequest(v6, httpRequest);
    v4 = v7;
  }
  OSuite::ZHttpRequestManager::CallCallbacks(this, v4);
  return 1;
}

// File Line: 523
// RVA: 0xECEE70
void __fastcall OSuite::ZHttpRequestManager::InternalOnDataNeeded(
        OSuite::ZHttpRequestManager *this,
        OSuite::IHttpRequest *httpRequest)
{
  __int64 v4; // rax
  OSuite::ZOnDataNeededHttpRequest *v5; // rax

  v4 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[31].__vecDelDtor)(httpRequest);
  if ( (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v4 + 8) + 64i64))(v4 + 8) )
  {
    if ( ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[15].__vecDelDtor)(httpRequest) )
      return;
    goto LABEL_7;
  }
  v5 = (OSuite::ZOnDataNeededHttpRequest *)OSuite::ZObject::operator new(0x28ui64);
  if ( v5 )
  {
    v5->m_pHttpRequest = 0i64;
    OSuite::ZOnDataNeededHttpRequest::ZOnDataNeededHttpRequest(v5, httpRequest);
  }
  OSuite::ZHttpRequestManager::CallCallbacks(this, v5);
  if ( ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[18].__vecDelDtor)(httpRequest) )
LABEL_7:
    OSuite::ZHttpRequestManager::FinishHttpRequest(this, httpRequest, 4u);
}

// File Line: 545
// RVA: 0xECEF00
void __fastcall OSuite::ZHttpRequestManager::InternalOnFinished(
        OSuite::ZHttpRequestManager *this,
        OSuite::IHttpRequest *httpRequest)
{
  OSuite::ZHttpRequestClientCBWrapper *v4; // rdi
  OSuite::ZOnFinishedHttpRequest *v5; // rax
  OSuite::ZHttpRequestClientCBWrapper *v6; // rax

  v4 = 0i64;
  if ( httpRequest->vfptr[17].__vecDelDtor(httpRequest, 512i64)
    && !((unsigned int (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[28].__vecDelDtor)(httpRequest) )
  {
    httpRequest->vfptr[40].__vecDelDtor(httpRequest, 11u);
  }
  v5 = (OSuite::ZOnFinishedHttpRequest *)OSuite::ZObject::operator new(0x28ui64);
  if ( v5 )
  {
    v5->m_pHttpRequest = 0i64;
    OSuite::ZOnFinishedHttpRequest::ZOnFinishedHttpRequest(v5, httpRequest);
    v4 = v6;
  }
  OSuite::ZHttpRequestManager::CallCallbacks(this, v4);
}

// File Line: 561
// RVA: 0xECEBB8
void __fastcall OSuite::ZHttpRequestManager::CallCallbacks(
        OSuite::ZHttpRequestManager *this,
        OSuite::ZHttpRequestClientCBWrapper *pClientCbWrapper)
{
  OSuite::IHttpRequest *m_pHttpRequest; // rdi
  OSuite::ZWorker *v4; // rax

  m_pHttpRequest = pClientCbWrapper->m_pHttpRequest;
  if ( ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))m_pHttpRequest->vfptr[51].__vecDelDtor)(m_pHttpRequest) )
  {
    m_pHttpRequest->vfptr[37].__vecDelDtor(m_pHttpRequest, 128u);
    v4 = OSuite::ZWorker::Instance();
    OSuite::ZWorker::AddCallback(v4, pClientCbWrapper);
  }
  else
  {
    ((void (__fastcall *)(OSuite::ZHttpRequestClientCBWrapper *))pClientCbWrapper->OSuite::ManagedCallback::OSuite::ICallback<void,void>::vfptr[1].__vecDelDtor)(pClientCbWrapper);
    pClientCbWrapper->OSuite::ManagedCallback::OSuite::ICallback<void,void>::vfptr->__vecDelDtor(pClientCbWrapper, 1i64);
  }
}


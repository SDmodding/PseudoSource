// File Line: 24
// RVA: 0xECE860
void __fastcall OSuite::ZHttpRequestManager::ZHttpRequestManager(OSuite::ZHttpRequestManager *this)
{
  OSuite::ZHttpRequestManager *v1; // rdi
  hkEntitySelectorAll *v2; // rax
  hkpEntity *v3; // rdx
  const char *v4; // rdx
  hkEntitySelectorAll *v5; // rax
  hkpEntity *v6; // rdx
  int v7; // eax
  OSuite::ZString *v8; // rax
  OSuite::ZString that; // [rsp+20h] [rbp-50h]
  OSuite::ZStringBuilder v10; // [rsp+38h] [rbp-38h]

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpRequestManager::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&this->m_scheduledForDeleteHttpRequestsList);
  v1->m_scheduledForDeleteHttpRequestsList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&v1->m_pendingHttpRequestsList);
  v1->m_pendingHttpRequestsList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZMutex::ZMutex(&v1->m_RequestMutex);
  OSuite::ZString::ZString(&v1->m_osPlatform);
  OSuite::ZString::ZString(&v1->m_userAgent);
  v2 = (hkEntitySelectorAll *)OSuite::GameInterface();
  if ( (unsigned int)hkaReferencePoseAnimation::getNumOriginalFrames(v2, v3) == 2 )
  {
    v4 = "OnLive";
  }
  else
  {
    v5 = (hkEntitySelectorAll *)OSuite::GameInterface();
    v7 = hkaReferencePoseAnimation::getNumOriginalFrames(v5, v6);
    v4 = "Steam";
    if ( v7 != 1 )
      v4 = "Windows";
  }
  OSuite::ZString::ZString(&that, v4);
  OSuite::ZString::operator=(&v1->m_osPlatform, &that);
  OSuite::ZString::~ZString(&that);
  v10.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v10, 0x20ui64);
  OSuite::ZStringBuilder::Append(&v10, "OS/");
  OSuite::ZStringBuilder::Append(&v10, "4.2.14");
  OSuite::ZStringBuilder::Append(&v10, "/");
  OSuite::ZStringBuilder::Append(&v10, &v1->m_osPlatform);
  OSuite::ZStringBuilder::Append(&v10, "/");
  OSuite::ZStringBuilder::Append(&v10, "official");
  v8 = OSuite::ZStringBuilder::ToString(&v10, &that);
  OSuite::ZString::operator=(&v1->m_userAgent, v8);
  OSuite::ZString::~ZString(&that);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v10);
}

// File Line: 57
// RVA: 0xECE9EC
void __fastcall OSuite::ZHttpRequestManager::~ZHttpRequestManager(OSuite::ZHttpRequestManager *this)
{
  OSuite::ZMutex *v1; // rbx
  OSuite::ZHttpRequestManager *v2; // rdi
  OSuite::ZObjectVtbl *v3; // rcx
  OSuite::ZObjectVtbl *v4; // rcx
  OSuite::ZDoublyLinkedListBase::ZIteratorBase that; // [rsp+20h] [rbp-40h]
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v6; // [rsp+38h] [rbp-28h]

  v1 = &this->m_RequestMutex;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpRequestManager::`vftable;
  OSuite::ZMutex::Lock(&this->m_RequestMutex);
  v6.m_pList = 0i64;
  v6.m_pElement = 0i64;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    &v6,
    (OSuite::ZDoublyLinkedListBase *)&v2->m_pendingHttpRequestsList.vfptr,
    v2->m_pendingHttpRequestsList.m_pHead);
  v6.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v6) )
  {
    OSuite::ZHttpRequestManager::ShutdownHttpRequest(v2, (OSuite::IHttpRequest *)v6.m_pElement[1].vfptr);
    (*((void (__fastcall **)(OSuite::ZObjectVtbl *, _QWORD))v6.m_pElement[1].vfptr->__vecDelDtor + 50))(
      v6.m_pElement[1].vfptr,
      0i64);
    v3 = v6.m_pElement[1].vfptr;
    if ( v3 )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, signed __int64))v3->__vecDelDtor)(v3, 1i64);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Remove(&v6);
  }
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    &that,
    (OSuite::ZDoublyLinkedListBase *)&v2->m_scheduledForDeleteHttpRequestsList.vfptr,
    v2->m_scheduledForDeleteHttpRequestsList.m_pHead);
  that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::operator=(&v6, &that);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v6) )
  {
    (*((void (__fastcall **)(OSuite::ZObjectVtbl *, _QWORD))v6.m_pElement[1].vfptr->__vecDelDtor + 50))(
      v6.m_pElement[1].vfptr,
      0i64);
    v4 = v6.m_pElement[1].vfptr;
    if ( v4 )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, signed __int64))v4->__vecDelDtor)(v4, 1i64);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Remove(&v6);
  }
  OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v2->m_pendingHttpRequestsList);
  OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v2->m_scheduledForDeleteHttpRequestsList);
  OSuite::ZMutex::Unlock(v1);
  OSuite::ZString::~ZString(&v2->m_userAgent);
  OSuite::ZString::~ZString(&v2->m_osPlatform);
  OSuite::ZMutex::~ZMutex(v1);
  v2->m_pendingHttpRequestsList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZDoublyLinkedListBase::Clear((OSuite::ZDoublyLinkedListBase *)&v2->m_pendingHttpRequestsList.vfptr);
  v2->m_scheduledForDeleteHttpRequestsList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZDoublyLinkedListBase::Clear((OSuite::ZDoublyLinkedListBase *)&v2->m_scheduledForDeleteHttpRequestsList.vfptr);
}

// File Line: 94
// RVA: 0xECF394
void __fastcall OSuite::ZHttpRequestManager::Update(OSuite::ZHttpRequestManager *this, OSuite::ZObject *a2)
{
  OSuite::ZHttpRequestManager *v2; // r15
  char v3; // r12
  OSuite::ZObjectVtbl *v4; // rsi
  OSuite::ZString *v5; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *v6; // rdx
  OSuite::ZDoublyLinkedListBase::ZElementBase *v7; // rdi
  OSuite::IHttpRequest *v8; // rdi
  signed int v9; // eax
  signed int v10; // esi
  OSuite::ZDoublyLinkedListBase::ZElementBase *v11; // rdx
  OSuite::ZString *v12; // rax
  bool v13; // al
  unsigned __int64 *v14; // rax
  unsigned __int64 v15; // rax
  OSuite::IHttpRequest *data; // [rsp+0h] [rbp-39h]
  OSuite::ZDoublyLinkedListBase::ZIteratorBase that; // [rsp+8h] [rbp-31h]
  OSuite::ZClock v18; // [rsp+20h] [rbp-19h]
  OSuite::ZObject v19; // [rsp+28h] [rbp-11h]
  __int64 v20; // [rsp+30h] [rbp-9h]
  __int64 v21; // [rsp+38h] [rbp-1h]
  OSuite::ZClock v22; // [rsp+40h] [rbp+7h]
  OSuite::ZRedBlackTreeBase v23; // [rsp+48h] [rbp+Fh]

  v2 = this;
  v3 = 0;
  v20 = 0i64;
  v21 = 0i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v23.m_pTop, a2);
  v23.m_pTop = 0i64;
  v19.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(&v23);
  v23.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZMutex::Lock(&v2->m_RequestMutex);
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v2->m_scheduledForDeleteHttpRequestsList) )
  {
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
      &that,
      (OSuite::ZDoublyLinkedListBase *)&v2->m_scheduledForDeleteHttpRequestsList.vfptr,
      v2->m_scheduledForDeleteHttpRequestsList.m_pHead);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::operator=((OSuite::ZDoublyLinkedListBase::ZIteratorBase *)&v19, &that);
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v19) )
    {
      v4 = *(OSuite::ZObjectVtbl **)(v21 + 24);
      data = *(OSuite::IHttpRequest **)(v21 + 24);
      v5 = (OSuite::ZString *)OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::Find(
                                &v2->m_pendingHttpRequestsList,
                                (OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::ZIterator *)&that,
                                &data);
      if ( !OSuite::ZString::IsNull(v5)
        && !OSuite::ZRedBlackTreeBase::IsEmpty((OSuite::ZRedBlackTreeBase *)&v2->m_pendingHttpRequestsList) )
      {
        v6 = v2->m_pendingHttpRequestsList.m_pHead;
        while ( v6[1].vfptr != v4 )
        {
          v6 = v6->m_pNext;
          if ( v6 == v2->m_pendingHttpRequestsList.m_pHead )
          {
            v6 = 0i64;
            break;
          }
        }
        if ( v6 )
          OSuite::ZDoublyLinkedListBase::DeleteElement(
            (OSuite::ZDoublyLinkedListBase *)&v2->m_pendingHttpRequestsList.vfptr,
            v6);
      }
      LOBYTE(v6) = 1;
      (*((void (__fastcall **)(OSuite::ZObjectVtbl *, OSuite::ZDoublyLinkedListBase::ZElementBase *))v4->__vecDelDtor
       + 50))(
        v4,
        v6);
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, signed __int64))v4->__vecDelDtor)(v4, 1i64);
      OSuite::ZDoublyLinkedListBase::ZIteratorBase::Remove((OSuite::ZDoublyLinkedListBase::ZIteratorBase *)&v19);
    }
  }
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v2->m_pendingHttpRequestsList) )
  {
    if ( &v23 != (OSuite::ZRedBlackTreeBase *)&v2->m_pendingHttpRequestsList )
    {
      OSuite::ZDoublyLinkedListBase::operator=(
        (OSuite::ZDoublyLinkedListBase *)&v23,
        (OSuite::ZDoublyLinkedListBase *)&v2->m_pendingHttpRequestsList.vfptr);
      v7 = v2->m_pendingHttpRequestsList.m_pHead;
      if ( v7 )
      {
        do
        {
          OSuite::TDoublyLinkedList<OSuite::ZMetricAppender *>::Append(
            (OSuite::TDoublyLinkedList<OSuite::ManagedCallback *> *)&v23,
            (OSuite::ManagedCallback *const *)&v7[1]);
          v7 = v7->m_pNext;
        }
        while ( v7 != v2->m_pendingHttpRequestsList.m_pHead );
      }
    }
    OSuite::ZMutex::Unlock(&v2->m_RequestMutex);
    OSuite::ZClock::ZClock(&v22);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
      &that,
      (OSuite::ZDoublyLinkedListBase *)&v23,
      (OSuite::ZDoublyLinkedListBase::ZElementBase *)v23.m_pTop);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::operator=((OSuite::ZDoublyLinkedListBase::ZIteratorBase *)&v19, &that);
    while ( 1 )
    {
      while ( 1 )
      {
        if ( OSuite::ZString::IsNull((OSuite::ZString *)&v19) )
        {
          OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v22);
          goto LABEL_51;
        }
        data = *(OSuite::IHttpRequest **)(v21 + 24);
        v8 = data;
        v9 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v8->vfptr[24].__vecDelDtor)(v8);
        v10 = v9;
        if ( v9 <= 32 )
          break;
        if ( v9 == 64 )
          goto LABEL_25;
        if ( (v9 - 256) & 0xFFFFFEFF )
        {
          if ( v9 == 2048 )
          {
            OSuite::ZMutex::Lock(&v2->m_RequestMutex);
            if ( !OSuite::ZRedBlackTreeBase::IsEmpty((OSuite::ZRedBlackTreeBase *)&v2->m_pendingHttpRequestsList) )
            {
              v11 = v2->m_pendingHttpRequestsList.m_pHead;
              while ( (OSuite::IHttpRequest *)v11[1].vfptr != v8 )
              {
                v11 = v11->m_pNext;
                if ( v11 == v2->m_pendingHttpRequestsList.m_pHead )
                {
                  v11 = 0i64;
                  break;
                }
              }
              if ( v11 )
                OSuite::ZDoublyLinkedListBase::DeleteElement(
                  (OSuite::ZDoublyLinkedListBase *)&v2->m_pendingHttpRequestsList.vfptr,
                  v11);
            }
            LOBYTE(v11) = 1;
            v8->vfptr[50].__vecDelDtor((OSuite::ZObject *)&v8->vfptr, (unsigned int)v11);
            v12 = (OSuite::ZString *)OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::Find(
                                       &v2->m_scheduledForDeleteHttpRequestsList,
                                       (OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::ZIterator *)&that,
                                       &data);
            v13 = OSuite::ZString::IsNull(v12);
            that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
            if ( v13 )
              OSuite::TDoublyLinkedList<OSuite::ZMetricAppender *>::Append(
                (OSuite::TDoublyLinkedList<OSuite::ManagedCallback *> *)&v2->m_scheduledForDeleteHttpRequestsList,
                (OSuite::ManagedCallback *const *)&data);
            OSuite::ZMutex::Unlock(&v2->m_RequestMutex);
          }
        }
        else
        {
          OSuite::ZHttpRequestManager::InternalOnFinished(v2, v8);
        }
LABEL_26:
        OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next((OSuite::ZDoublyLinkedListBase::ZIteratorBase *)&v19);
        v3 = 0;
      }
      switch ( v9 )
      {
        case 32:
          OSuite::ZHttpRequestManager::ReceiveHttpResponse(v2, v8);
          goto LABEL_26;
        case 1:
          OSuite::ZHttpRequestManager::InternalOnStarted(v2, v8);
          goto LABEL_26;
        case 2:
          OSuite::ZHttpRequestManager::ConnectHttpRequest(v2, v8);
          goto LABEL_26;
        case 4:
          goto LABEL_25;
        case 8:
          OSuite::ZHttpRequestManager::SendHttpRequestData(v2, v8);
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
        v15 = OSuite::ZClock::_GetClock();
        if ( OSuite::ZClock::_ClockToTime(v15 - v22.m_clock, 0) >= 0xF )
        {
          v8->vfptr[40].__vecDelDtor((OSuite::ZObject *)&v8->vfptr, 16u);
          v8->vfptr[37].__vecDelDtor((OSuite::ZObject *)&v8->vfptr, 512u);
        }
      }
      else
      {
        OSuite::ZClock::ZClock(&v18);
        v22.m_clock = *v14;
        OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v18);
        v3 = 1;
      }
    }
  }
  OSuite::ZMutex::Unlock(&v2->m_RequestMutex);
LABEL_51:
  v23.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZDoublyLinkedListBase::Clear((OSuite::ZDoublyLinkedListBase *)&v23);
}

// File Line: 229
// RVA: 0xECEC98
void __fastcall OSuite::ZHttpRequestManager::CreateHttpRequest(OSuite::ZHttpRequestManager *this, OSuite::ZUrl *url, void *pParent, bool bKeepAlive, int nTimeOut)
{
  bool v5; // di
  void *v6; // rsi
  OSuite::ZUrl *v7; // rbp
  OSuite::ZHttpRequest *v8; // rbx

  v5 = bKeepAlive;
  v6 = pParent;
  v7 = url;
  v8 = (OSuite::ZHttpRequest *)OSuite::ZObject::operator new(0x498ui64);
  if ( v8 )
  {
    OSuite::ZHttpRequest::__autoclassinit(v8, 1u);
    OSuite::ZHttpRequest::ZHttpRequest(v8, v7, v6, v5, nTimeOut);
  }
}

// File Line: 257
// RVA: 0xECF26C
char __fastcall OSuite::ZHttpRequestManager::ReleaseHttpRequest(OSuite::ZHttpRequestManager *this, OSuite::IHttpRequest *pHttpRequest)
{
  OSuite::ZHttpRequestManager *v2; // rdi
  OSuite::IHttpRequest *v3; // rbx
  char result; // al

  v2 = this;
  v3 = pHttpRequest;
  result = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[47].__vecDelDtor)(pHttpRequest);
  if ( result )
    result = OSuite::ZHttpRequestManager::InternalReleaseHttpRequest(v2, v3);
  return result;
}

// File Line: 269
// RVA: 0xECF314
char __fastcall OSuite::ZHttpRequestManager::ShutdownHttpRequest(OSuite::ZHttpRequestManager *this, OSuite::IHttpRequest *pHttpRequest)
{
  OSuite::ZHttpRequestManager *v2; // rbp
  OSuite::IHttpRequest *v3; // rdi
  void *v4; // rsi
  OSuite::ZObjectAccessor *v5; // rax
  char v6; // bl
  OSuite::ZObjectAccessor *v7; // rax

  v2 = this;
  v3 = pHttpRequest;
  v4 = (void *)((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[32].__vecDelDtor)(pHttpRequest);
  v5 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::AccessObject(v5, v4);
  v6 = 0;
  if ( ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))v3->vfptr[48].__vecDelDtor)(v3) )
    v6 = OSuite::ZHttpRequestManager::InternalReleaseHttpRequest(v2, v3);
  v7 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::ReleaseObject(v7, v4);
  return v6;
}

// File Line: 283
// RVA: 0xECEFD0
char __fastcall OSuite::ZHttpRequestManager::InternalReleaseHttpRequest(OSuite::ZHttpRequestManager *this, OSuite::IHttpRequest *pHttpRequest)
{
  OSuite::ZObjectVtbl *v2; // rax
  OSuite::ZHttpRequestManager *v3; // rsi
  OSuite::IHttpRequest *v4; // rdi
  void *v5; // rbx
  OSuite::ZObjectAccessor *v6; // rax
  OSuite::ZObjectAccessor *v7; // rax
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::ZIterator v11; // [rsp+28h] [rbp-50h]
  OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::ZIterator result; // [rsp+40h] [rbp-38h]
  OSuite::IHttpRequest *data; // [rsp+58h] [rbp-20h]

  v2 = pHttpRequest->vfptr;
  v3 = this;
  v4 = pHttpRequest;
  data = pHttpRequest;
  v5 = (void *)((__int64 (__fastcall *)(OSuite::IHttpRequest *))v2[32].__vecDelDtor)(pHttpRequest);
  v6 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::AccessObject(v6, v5);
  v4->vfptr[37].__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 2048u);
  v7 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::ReleaseObject(v7, v5);
  OSuite::ZMutex::Lock(&v3->m_RequestMutex);
  v8 = (OSuite::ZString *)OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::Find(
                            &v3->m_pendingHttpRequestsList,
                            &result,
                            &data);
  if ( OSuite::ZString::IsNull(v8) )
  {
    v9 = (OSuite::ZString *)OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::Find(
                              &v3->m_scheduledForDeleteHttpRequestsList,
                              &v11,
                              &data);
    if ( OSuite::ZString::IsNull(v9) )
      OSuite::TDoublyLinkedList<OSuite::ZMetricAppender *>::Append(
        (OSuite::TDoublyLinkedList<OSuite::ManagedCallback *> *)&v3->m_scheduledForDeleteHttpRequestsList,
        (OSuite::ManagedCallback *const *)&data);
  }
  OSuite::ZMutex::Unlock(&v3->m_RequestMutex);
  return 1;
}

// File Line: 334
// RVA: 0xECED04
void __fastcall OSuite::ZHttpRequestManager::ExecuteRequest(OSuite::ZHttpRequestManager *this, OSuite::IHttpRequest *pHttpRequest)
{
  OSuite::ZObjectVtbl *v2; // rax
  OSuite::ZHttpRequestManager *v3; // rdi
  OSuite::IHttpRequest *v4; // rbx
  OSuite::ManagedCallback *data; // [rsp+20h] [rbp-18h]

  v2 = pHttpRequest->vfptr;
  v3 = this;
  v4 = pHttpRequest;
  data = (OSuite::ManagedCallback *)pHttpRequest;
  ((void (__fastcall *)(OSuite::IHttpRequest *))v2[8].__vecDelDtor)(pHttpRequest);
  v4->vfptr[37].__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 1u);
  OSuite::ZMutex::Lock(&v3->m_RequestMutex);
  OSuite::TDoublyLinkedList<OSuite::ZMetricAppender *>::Append(
    (OSuite::TDoublyLinkedList<OSuite::ManagedCallback *> *)&v3->m_pendingHttpRequestsList,
    &data);
  OSuite::ZMutex::Unlock(&v3->m_RequestMutex);
}

// File Line: 357
// RVA: 0xECEC20
void __fastcall OSuite::ZHttpRequestManager::ConnectHttpRequest(OSuite::ZHttpRequestManager *this, OSuite::IHttpRequest *httpRequest)
{
  OSuite::ZHttpRequestManager *v2; // rdi
  OSuite::IHttpRequest *v3; // rbx
  char v4; // al
  OSuite::IHttpRequest *v5; // rcx
  bool v6; // zf
  OSuite::IHttpRequest v7; // rax
  OSuite::ZHttp::EError v8; // eax

  v2 = this;
  v3 = httpRequest;
  v4 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[49].__vecDelDtor)(httpRequest);
  v5 = v3;
  v6 = v4 == 0;
  v7.vfptr = v3->vfptr;
  if ( v6 )
    goto LABEL_6;
  if ( !((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))v7.vfptr[20].__vecDelDtor)(v3)
    && ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))v3->vfptr[19].__vecDelDtor)(v3)
    && !((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))v3->vfptr[52].__vecDelDtor)(v3) )
  {
    v7.vfptr = v3->vfptr;
    v5 = v3;
LABEL_6:
    v8 = ((unsigned int (__fastcall *)(OSuite::IHttpRequest *))v7.vfptr[28].__vecDelDtor)(v5);
    OSuite::ZHttpRequestManager::FinishHttpRequest(v2, v3, v8);
  }
}

// File Line: 386
// RVA: 0xECF2A4
void __fastcall OSuite::ZHttpRequestManager::SendHttpRequestData(OSuite::ZHttpRequestManager *this, OSuite::IHttpRequest *httpRequest)
{
  OSuite::ZHttpRequestManager *v2; // rdi
  OSuite::IHttpRequest *v3; // rbx
  bool v4; // zf
  OSuite::ZObjectVtbl *v5; // rax
  OSuite::ZHttp::EError v6; // eax

  v2 = this;
  v3 = httpRequest;
  v4 = ((unsigned int (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[28].__vecDelDtor)(httpRequest) == 0;
  v5 = v3->vfptr;
  if ( v4 )
  {
    if ( ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))v5[22].__vecDelDtor)(v3) )
      v3->vfptr[37].__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 32u);
    else
      OSuite::ZHttpRequestManager::InternalOnDataNeeded(v2, v3);
  }
  else
  {
    v6 = ((unsigned int (__fastcall *)(OSuite::IHttpRequest *))v5[28].__vecDelDtor)(v3);
    OSuite::ZHttpRequestManager::FinishHttpRequest(v2, v3, v6);
  }
}

// File Line: 408
// RVA: 0xECF0C0
void __fastcall OSuite::ZHttpRequestManager::ReceiveHttpResponse(OSuite::ZHttpRequestManager *this, OSuite::IHttpRequest *httpRequest)
{
  unsigned __int128 v2; // di
  bool v3; // zf
  __int64 v4; // rax
  __int64 v5; // rbx
  __int64 v6; // rax
  OSuite::ZUrl *v7; // rax
  OSuite::ZString *v8; // rax
  bool v9; // bl
  __int64 v10; // rdx
  OSuite::ZHttp::EError v11; // er8
  char v12; // al
  OSuite::IHttpRequest *v13; // rdx
  OSuite::ZHttpRequestManager *v14; // rcx
  OSuite::ZString result; // [rsp+20h] [rbp-D8h]
  OSuite::ZUrl v16; // [rsp+40h] [rbp-B8h]

  v2 = __PAIR__((unsigned __int64)this, (unsigned __int64)httpRequest);
  v3 = ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[10].__vecDelDtor)(httpRequest) == 0;
  v4 = *(_QWORD *)v2;
  if ( v3 )
  {
    v5 = (*(__int64 (__fastcall **)(_QWORD))(v4 + 264))(v2);
    if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v5 + 32i64))(v5) == 301
      || (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v5 + 32i64))(v5) == 302 )
    {
      v6 = *(_QWORD *)v5;
      v16.m_sProtocol.m_pString = 0i64;
      v16.m_sHost.m_pString = 0i64;
      v16.m_sFakeHost.vfptr = 0i64;
      v16.m_sPath.vfptr = 0i64;
      v16.m_urlParameters.m_parameters.vfptr = 0i64;
      v16.m_urlParameters.m_arrayParameters.vfptr = 0i64;
      v7 = (OSuite::ZUrl *)(*(__int64 (__fastcall **)(__int64))(v6 + 48))(v5);
      OSuite::ZUrl::ZUrl(&v16, v7);
      v8 = OSuite::ZUrl::ToString(&v16, &result, 0);
      v9 = OSuite::ZString::Empty(v8) == 0;
      OSuite::ZString::~ZString(&result);
      if ( v9 )
      {
        LOBYTE(v10) = 1;
        (*(void (__fastcall **)(_QWORD, __int64))(*(_QWORD *)v2 + 400i64))(v2, v10);
        (*(void (__fastcall **)(_QWORD, OSuite::ZUrl *))(*(_QWORD *)v2 + 360i64))(v2, &v16);
        (*(void (__fastcall **)(_QWORD, signed __int64))(*(_QWORD *)v2 + 296i64))(v2, 1i64);
        OSuite::ZUrl::~ZUrl(&v16);
        return;
      }
      OSuite::ZUrl::~ZUrl(&v16);
    }
    goto LABEL_7;
  }
  v12 = (*(__int64 (__fastcall **)(_QWORD))(v4 + 144))(v2);
  v14 = (OSuite::ZHttpRequestManager *)*((_QWORD *)&v2 + 1);
  v13 = (OSuite::IHttpRequest *)v2;
  if ( v12 )
  {
    v11 = 5;
LABEL_15:
    OSuite::ZHttpRequestManager::FinishHttpRequest(v14, v13, v11);
    return;
  }
  if ( !OSuite::ZHttpRequestManager::InternalOnDataAvailable(
          *((OSuite::ZHttpRequestManager **)&v2 + 1),
          (OSuite::IHttpRequest *)v2)
    && (*(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)v2 + 96i64))(v2) )
  {
    if ( !(*(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)v2 + 144i64))(v2) )
    {
      OSuite::ZHttpRequestManager::InternalOnDataAvailable(
        *((OSuite::ZHttpRequestManager **)&v2 + 1),
        (OSuite::IHttpRequest *)v2);
      v11 = 0;
      goto LABEL_14;
    }
LABEL_7:
    v11 = (*(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)v2 + 224i64))(v2);
LABEL_14:
    v14 = (OSuite::ZHttpRequestManager *)*((_QWORD *)&v2 + 1);
    v13 = (OSuite::IHttpRequest *)v2;
    goto LABEL_15;
  }
}

// File Line: 480
// RVA: 0xECED7C
void __fastcall OSuite::ZHttpRequestManager::FinishHttpRequest(OSuite::ZHttpRequestManager *this, OSuite::IHttpRequest *httpRequest, OSuite::ZHttp::EError lastError)
{
  OSuite::ZHttp::EError v3; // esi
  OSuite::IHttpRequest *v4; // rdi
  OSuite::ZError *v5; // rbx
  OSuite::ZError::EError v6; // eax

  v3 = lastError;
  v4 = httpRequest;
  if ( ((unsigned int (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[28].__vecDelDtor)(httpRequest) )
  {
    v5 = OSuite::TSingleton<OSuite::ZError>::Object();
    v6 = (unsigned int)OSuite::ZHttp::HttpToOsError(v3);
    OSuite::ZError::SetThreadLastError(v5, v6, 1);
  }
  else
  {
    v4->vfptr[40].__vecDelDtor((OSuite::ZObject *)&v4->vfptr, v3);
  }
  v4->vfptr[37].__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 256u);
}

// File Line: 494
// RVA: 0xECEF88
void __fastcall OSuite::ZHttpRequestManager::InternalOnStarted(OSuite::ZHttpRequestManager *this, OSuite::IHttpRequest *httpRequest)
{
  OSuite::ZHttpRequestManager *v2; // rbx
  OSuite::IHttpRequest *v3; // rdi
  OSuite::ZOnStartedHttpRequest *v4; // rcx
  OSuite::ZHttpRequestClientCBWrapper *v5; // rax

  v2 = this;
  v3 = httpRequest;
  v4 = (OSuite::ZOnStartedHttpRequest *)OSuite::ZObject::operator new(0x28ui64);
  v5 = 0i64;
  if ( v4 )
  {
    v4->m_pHttpRequest = 0i64;
    OSuite::ZOnStartedHttpRequest::ZOnStartedHttpRequest(v4, v3);
  }
  OSuite::ZHttpRequestManager::CallCallbacks(v2, v5);
}

// File Line: 504
// RVA: 0xECEDF0
char __fastcall OSuite::ZHttpRequestManager::InternalOnDataAvailable(OSuite::ZHttpRequestManager *this, OSuite::IHttpRequest *httpRequest)
{
  OSuite::ZHttpRequestManager *v2; // rsi
  OSuite::IHttpRequest *v3; // rdi
  OSuite::ZHttpRequestClientCBWrapper *v4; // rbx
  _QWORD *v5; // rax
  OSuite::ZOnDataAvailableHttpRequest *v6; // rax
  OSuite::ZHttpRequestClientCBWrapper *v7; // rax
  char v9; // [rsp+20h] [rbp-18h]

  v2 = this;
  v3 = httpRequest;
  v4 = 0i64;
  if ( !((__int64 (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[11].__vecDelDtor)(httpRequest) )
    return 0;
  v5 = (_QWORD *)v3->vfptr[2].__vecDelDtor((OSuite::ZObject *)&v3->vfptr, (unsigned int)&v9);
  if ( !*v5 && !v5[1] )
    return 0;
  v6 = (OSuite::ZOnDataAvailableHttpRequest *)OSuite::ZObject::operator new(0x28ui64);
  if ( v6 )
  {
    v6->m_pHttpRequest = 0i64;
    OSuite::ZOnDataAvailableHttpRequest::ZOnDataAvailableHttpRequest(v6, v3);
    v4 = v7;
  }
  OSuite::ZHttpRequestManager::CallCallbacks(v2, v4);
  return 1;
}

// File Line: 523
// RVA: 0xECEE70
void __fastcall OSuite::ZHttpRequestManager::InternalOnDataNeeded(OSuite::ZHttpRequestManager *this, OSuite::IHttpRequest *httpRequest)
{
  OSuite::ZHttpRequestManager *v2; // rdi
  OSuite::IHttpRequest *v3; // rbx
  __int64 v4; // rax
  OSuite::ZOnDataNeededHttpRequest *v5; // rax

  v2 = this;
  v3 = httpRequest;
  v4 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))httpRequest->vfptr[31].__vecDelDtor)(httpRequest);
  if ( (*(__int64 (**)(void))(*(_QWORD *)(v4 + 8) + 64i64))() )
  {
    if ( ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))v3->vfptr[15].__vecDelDtor)(v3) )
      return;
    goto LABEL_7;
  }
  v5 = (OSuite::ZOnDataNeededHttpRequest *)OSuite::ZObject::operator new(0x28ui64);
  if ( v5 )
  {
    v5->m_pHttpRequest = 0i64;
    OSuite::ZOnDataNeededHttpRequest::ZOnDataNeededHttpRequest(v5, v3);
  }
  OSuite::ZHttpRequestManager::CallCallbacks(v2, (OSuite::ZHttpRequestClientCBWrapper *)&v5->vfptr);
  if ( ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))v3->vfptr[18].__vecDelDtor)(v3) )
LABEL_7:
    OSuite::ZHttpRequestManager::FinishHttpRequest(v2, v3, HTTPERROR_DATASENDFAILED);
}

// File Line: 545
// RVA: 0xECEF00
void __fastcall OSuite::ZHttpRequestManager::InternalOnFinished(OSuite::ZHttpRequestManager *this, OSuite::IHttpRequest *httpRequest)
{
  OSuite::IHttpRequest *v2; // rbx
  OSuite::ZHttpRequestManager *v3; // rsi
  OSuite::ZHttpRequestClientCBWrapper *v4; // rdi
  OSuite::ZOnFinishedHttpRequest *v5; // rax
  OSuite::ZHttpRequestClientCBWrapper *v6; // rax

  v2 = httpRequest;
  v3 = this;
  v4 = 0i64;
  if ( (unsigned __int8)httpRequest->vfptr[17].__vecDelDtor((OSuite::ZObject *)httpRequest, 512u)
    && !((unsigned int (__fastcall *)(OSuite::IHttpRequest *))v2->vfptr[28].__vecDelDtor)(v2) )
  {
    v2->vfptr[40].__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 11u);
  }
  v5 = (OSuite::ZOnFinishedHttpRequest *)OSuite::ZObject::operator new(0x28ui64);
  if ( v5 )
  {
    v5->m_pHttpRequest = 0i64;
    OSuite::ZOnFinishedHttpRequest::ZOnFinishedHttpRequest(v5, v2);
    v4 = v6;
  }
  OSuite::ZHttpRequestManager::CallCallbacks(v3, v4);
}

// File Line: 561
// RVA: 0xECEBB8
void __fastcall OSuite::ZHttpRequestManager::CallCallbacks(OSuite::ZHttpRequestManager *this, OSuite::ZHttpRequestClientCBWrapper *pClientCbWrapper)
{
  OSuite::IHttpRequest *v2; // rdi
  OSuite::ZHttpRequestClientCBWrapper *v3; // rbx
  OSuite::ZWorker *v4; // rax

  v2 = pClientCbWrapper->m_pHttpRequest;
  v3 = pClientCbWrapper;
  if ( ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))v2->vfptr[51].__vecDelDtor)(pClientCbWrapper->m_pHttpRequest) )
  {
    v2->vfptr[37].__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 128u);
    v4 = OSuite::ZWorker::Instance();
    OSuite::ZWorker::AddCallback(v4, (OSuite::ManagedCallback *)&v3->vfptr);
  }
  else
  {
    ((void (__fastcall *)(OSuite::ZHttpRequestClientCBWrapper *))v3->vfptr[1].__vecDelDtor)(v3);
    v3->vfptr->__vecDelDtor((OSuite::ICallback<void,void> *)&v3->vfptr, 1u);
  }
}


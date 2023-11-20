// File Line: 22
// RVA: 0xED9E6C
char __fastcall OSuite::ZWebServiceClientManager::ZWebServiceClientBucket::operator==(OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *this, OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *wscb)
{
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v2; // rbx
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v3; // rdi
  bool v4; // al
  char v5; // r8

  v2 = wscb;
  v3 = this;
  v4 = OSuite::ZString::operator==(&this->name, &wscb->name);
  v5 = 0;
  if ( v4 && v3->pWebServiceClient == v2->pWebServiceClient )
    v5 = 1;
  return v5;
}

// File Line: 30
// RVA: 0xED9DA4
void __fastcall OSuite::ZWebServiceClientManager::ZWebServiceClientList::ZWebServiceClientList(OSuite::ZWebServiceClientManager::ZWebServiceClientList *this, OSuite::ZObject *a2)
{
  OSuite::ZWebServiceClientManager::ZWebServiceClientList *v2; // rbx
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v3; // rax

  v2 = this;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&this->vfptr, a2);
  v2->m_pList = 0i64;
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWebServiceClientManager::ZWebServiceClientList::`vftable{for `OSuite::ZListBase};
  v2->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZWebServiceClientManager::ZWebServiceClientList::`vftable{for `OSuite::IHashable};
  v3 = OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::AllocList(
         (OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket> *)&v2->vfptr,
         0i64,
         0x10ui64);
  v2->m_nTop = 0i64;
  v2->m_pList = v3;
  v2->m_nSize = 16i64;
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWebServiceClientManager::ZWebServiceClientList::`vftable{for `OSuite::ZListBase};
  v2->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZWebServiceClientManager::ZWebServiceClientList::`vftable{for `OSuite::IHashable};
}

// File Line: 35
// RVA: 0xEDA4A4
OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *__fastcall OSuite::ZWebServiceClientManager::ZWebServiceClientList::Insert(OSuite::ZWebServiceClientManager::ZWebServiceClientList *this, OSuite::ZString *name, OSuite::ZWebServiceClient *pWebServiceClient)
{
  OSuite::ZWebServiceClient *v3; // rsi
  OSuite::ZString *v4; // rdi
  OSuite::ZWebServiceClientManager::ZWebServiceClientList *v5; // rbp
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v6; // rax
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v7; // rbx
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket element; // [rsp+20h] [rbp-48h]

  v3 = pWebServiceClient;
  v4 = name;
  v5 = this;
  v6 = OSuite::ZWebServiceClientManager::ZWebServiceClientList::Find(this, name);
  v7 = v6;
  if ( v6 )
  {
    if ( !v6->pWebServiceClient )
    {
      v6->refCount = 0;
      v6->pWebServiceClient = v3;
    }
  }
  else
  {
    element.refCount = 0;
    element.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWebServiceClientManager::ZWebServiceClientBucket::`vftable;
    OSuite::ZString::ZString(&element.name, &customWorldMapCaption);
    v7 = OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::Append(
           (OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket> *)&v5->vfptr,
           &element);
    OSuite::ZString::~ZString(&element.name);
    OSuite::ZString::operator=(&v7->name, v4);
    v7->pWebServiceClient = v3;
  }
  OSuite::ZString::~ZString(v4);
  return v7;
}

// File Line: 52
// RVA: 0xEDA330
OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *__fastcall OSuite::ZWebServiceClientManager::ZWebServiceClientList::Find(OSuite::ZWebServiceClientManager::ZWebServiceClientList *this, OSuite::ZString *key)
{
  OSuite::ZString *v2; // r14
  unsigned __int64 v3; // rdi
  OSuite::ZListBase *v4; // rbx
  unsigned __int64 v5; // rsi
  unsigned __int64 v7; // rdi
  OSuite::ZListBase *v8; // rbx
  unsigned __int64 v9; // rsi
  OSuite::ZListBase::ZListIteratorBase v10; // [rsp+20h] [rbp-20h]

  v10.m_pListBase = 0i64;
  v2 = key;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, (OSuite::ZListBase *)&this->vfptr);
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( 1 )
  {
    if ( OSuite::ZListBase::ZListIteratorBase::AtEnd(&v10) )
      return 0i64;
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v10.m_pListBase);
    v3 = v10.m_nIndex;
    v4 = v10.m_pListBase;
    v5 = v10.m_nIndex + 1;
    OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::Grow(
      (OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket> *)v10.m_pListBase,
      v10.m_nIndex + 1);
    if ( v3 >= v4->m_nTop )
      v4->m_nTop = v5;
    if ( OSuite::ZString::StartsWith(v2, (OSuite::ZString *)(v4[1].m_nSize + 48 * v3 + 16)) )
      break;
    OSuite::ZListBase::ZListIteratorBase::Next(&v10);
  }
  OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v10.m_pListBase);
  v7 = v10.m_nIndex;
  v8 = v10.m_pListBase;
  v9 = v10.m_nIndex + 1;
  OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::Grow(
    (OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket> *)v10.m_pListBase,
    v10.m_nIndex + 1);
  if ( v7 >= v8->m_nTop )
    v8->m_nTop = v9;
  return (OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *)(v8[1].m_nSize + 48 * v7);
}

// File Line: 65
// RVA: 0xED9E0C
void __fastcall OSuite::ZWebServiceClientManager::~ZWebServiceClientManager(OSuite::ZWebServiceClientManager *this)
{
  OSuite::ZWebServiceClientManager *v1; // rbx
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v2; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWebServiceClientManager::`vftable;
  OSuite::ZWebServiceClientManager::Clean(this);
  v2 = v1->m_webServiceList.m_pList;
  v1->m_webServiceList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWebServiceClientManager::ZWebServiceClientList::`vftable{for `OSuite::ZListBase};
  v1->m_webServiceList.vfptr = (OSuite::IHashableVtbl *)&OSuite::ZWebServiceClientManager::ZWebServiceClientList::`vftable{for `OSuite::IHashable};
  if ( v2 )
  {
    if ( LODWORD(v2[-1].pWebServiceClient) )
      v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 3u);
    else
      Illusion::ShaderParam::operator delete(&v2[-1].pWebServiceClient);
  }
  OSuite::ZMutex::~ZMutex(&v1->m_Mutex);
}

// File Line: 70
// RVA: 0xED9F30
void __fastcall OSuite::ZWebServiceClientManager::Clean(OSuite::ZWebServiceClientManager *this)
{
  OSuite::ZWebServiceClientManager::ZWebServiceClientList *v1; // rdi
  unsigned __int64 v2; // rbx
  OSuite::ZListBase *v3; // rsi
  unsigned __int64 v4; // r14
  unsigned __int64 v5; // rsi
  OSuite::ZListBase *v6; // rbx
  unsigned __int64 v7; // r14
  void (__fastcall ***v8)(_QWORD, signed __int64); // rcx
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v9; // rcx
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v10; // rax
  OSuite::ZListBase::ZListIteratorBase v11; // [rsp+20h] [rbp-20h]

  v11.m_pListBase = 0i64;
  v1 = &this->m_webServiceList;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v11, (OSuite::ZListBase *)&this->m_webServiceList.vfptr);
  v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v11) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11.m_pListBase);
    v2 = v11.m_nIndex;
    v3 = v11.m_pListBase;
    v4 = v11.m_nIndex + 1;
    OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::Grow(
      (OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket> *)v11.m_pListBase,
      v11.m_nIndex + 1);
    if ( v2 >= v3->m_nTop )
      v3->m_nTop = v4;
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11.m_pListBase);
    v5 = v11.m_nIndex;
    v6 = v11.m_pListBase;
    v7 = v11.m_nIndex + 1;
    OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::Grow(
      (OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket> *)v11.m_pListBase,
      v11.m_nIndex + 1);
    if ( v5 >= v6->m_nTop )
      v6->m_nTop = v7;
    v8 = *(void (__fastcall ****)(_QWORD, signed __int64))(v6[1].m_nSize + 48 * v5 + 40);
    if ( v8 )
      (**v8)(v8, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Remove(&v11);
  }
  v9 = v1->m_pList;
  if ( v9 )
  {
    if ( LODWORD(v9[-1].pWebServiceClient) )
      v9->vfptr->__vecDelDtor((OSuite::ZObject *)&v9->vfptr, 3u);
    else
      Illusion::ShaderParam::operator delete(&v9[-1].pWebServiceClient);
  }
  v10 = OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::AllocList(
          (OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket> *)&v1->vfptr,
          (OSuite::ZObject *)&v1->m_pList->vfptr,
          0x10ui64);
  v1->m_nTop = 0i64;
  v1->m_nSize = 16i64;
  v1->m_pList = v10;
}

// File Line: 87
// RVA: 0xEDA068
OSuite::ZWebServiceClient *__fastcall OSuite::ZWebServiceClientManager::Create(OSuite::ZWebServiceClientManager *this, const char *baseUrl, OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *cb)
{
  OSuite::ZWebServiceClientManager *v3; // r15
  char v4; // si
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *v5; // r12
  OSuite::ZUrl *v6; // rax
  OSuite::ZString *v7; // rax
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v8; // rax
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v9; // r14
  OSuite::ZWebServiceClient *v10; // rax
  OSuite::ZWebServiceClient *v11; // rbx
  OSuite::ZUrl *v12; // rax
  OSuite::ZWebServiceClient *v13; // rax
  OSuite::ZWebServiceClient *v14; // rbx
  OSuite::ZString *v15; // rax
  OSuite::ZWebServiceClient *v16; // rbx
  OSuite::ZString *v17; // rax
  OSuite::ZUrl *v18; // rax
  OSuite::ZWebServiceClient *v19; // rbx
  OSuite::ZString v21; // [rsp+20h] [rbp-E0h]
  int v22; // [rsp+38h] [rbp-C8h]
  OSuite::ZUrl result; // [rsp+40h] [rbp-C0h]
  OSuite::ZString key; // [rsp+118h] [rbp+18h]
  OSuite::SCallbackData pData; // [rsp+130h] [rbp+30h]

  v3 = this;
  v4 = 0;
  v5 = cb;
  v22 = 0;
  key.m_pString = 0i64;
  v6 = OSuite::ZUrl::Parse(&result, baseUrl);
  OSuite::ZUrl::ToString(v6, &key, 0);
  OSuite::ZUrl::~ZUrl(&result);
  if ( !OSuite::ZString::EndsWith(&key, "/") )
  {
    v7 = OSuite::ZString::operator+(&key, &v21, "/");
    OSuite::ZString::operator=(&key, v7);
    OSuite::ZString::~ZString(&v21);
  }
  OSuite::ZMutex::Lock(&v3->m_Mutex);
  v8 = OSuite::ZWebServiceClientManager::ZWebServiceClientList::Find(&v3->m_webServiceList, &key);
  v9 = v8;
  if ( v8 )
  {
    if ( (unsigned int)OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)v8->pWebServiceClient) == 1 )
    {
      v16 = v9->pWebServiceClient;
      OSuite::ZMutex::Lock(&v16->m_requestDelegatesMutex);
      OSuite::ZString::ZString(&v21, OSuite::ZWebServiceClient::METADATA_PATH);
      OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::Insert(
        &v9->pWebServiceClient->m_clientRequestDelegates,
        &v21,
        v5);
      OSuite::ZString::~ZString(&v21);
      OSuite::ZMutex::Unlock(&v16->m_requestDelegatesMutex);
      OSuite::SCallbackData::SCallbackData(&pData);
      pData.Status = (OSuite::SHttpStatus)200i64;
      pData.eEvent = 4;
      v17 = OSuite::ZString::operator+(&key, &v21, OSuite::ZWebServiceClient::METADATA_PATH);
      v18 = OSuite::ZUrl::Parse(&result, v17);
      OSuite::ZUrl::operator=(&pData.URL, v18);
      OSuite::ZUrl::~ZUrl(&result);
      OSuite::ZString::~ZString(&v21);
      OSuite::ZWebServiceClient::InvokeExternalRequestCallback(v9->pWebServiceClient, &pData);
      OSuite::SCallbackData::~SCallbackData(&pData);
    }
    else
    {
      v9->pWebServiceClient->m_eState = 0;
      OSuite::ZWebServiceClient::Initialize(v9->pWebServiceClient, v5);
    }
  }
  else
  {
    v10 = (OSuite::ZWebServiceClient *)OSuite::ZObject::operator new(0x178ui64);
    v11 = v10;
    if ( v10 )
    {
      v10->m_pCache = 0i64;
      v10->m_pMetricAppender = 0i64;
      v10->m_pUsageStatisticsMetricAppender = 0i64;
      v10->m_pPriorityMetricAppender = 0i64;
      v10->m_pUsageTracker = 0i64;
      v10->m_pMetadata = 0i64;
      v10->m_pProbeRequest = 0i64;
      v10->m_baseUrl.m_sProtocol.m_pString = 0i64;
      v10->m_baseUrl.m_sHost.m_pString = 0i64;
      v10->m_baseUrl.m_sFakeHost.m_pString = 0i64;
      v10->m_baseUrl.m_sPath.m_pString = 0i64;
      v10->m_baseUrl.m_urlParameters.m_parameters.m_pTop = 0i64;
      v10->m_baseUrl.m_urlParameters.m_arrayParameters.m_pTop = 0i64;
      v10->m_requestDelegatesMutex.m_pInternalMutex = 0i64;
      v10->m_clientRequestDelegates.m_pLists = 0i64;
      v10->m_clientProbeDelegate.m_Closure.m_pthis = 0i64;
      v10->m_pszPublicIpAddress = 0i64;
      v4 = (_BYTE)v9 + 1;
      v12 = OSuite::ZUrl::Parse(&result, &key);
      OSuite::ZWebServiceClient::ZWebServiceClient(v11, v12);
      v14 = v13;
    }
    else
    {
      v14 = 0i64;
    }
    if ( v4 & 1 )
      OSuite::ZUrl::~ZUrl(&result);
    OSuite::ZWebServiceClient::Initialize(v14, v5);
    OSuite::ZString::ZString(&v21, &key);
    v9 = OSuite::ZWebServiceClientManager::ZWebServiceClientList::Insert(&v3->m_webServiceList, v15, v14);
  }
  OSuite::ZMutex::Unlock(&v3->m_Mutex);
  OSuite::ZThread::AtomicAdd(&v9->refCount, 1);
  v19 = v9->pWebServiceClient;
  OSuite::ZString::~ZString(&key);
  return v19;
}

// File Line: 137
// RVA: 0xEDA540
void __fastcall OSuite::ZWebServiceClientManager::Release(OSuite::ZWebServiceClientManager *this, OSuite::ZWebServiceClient *pWebServiceClient, bool deleteIt)
{
  OSuite::ZWebServiceClientManager *v3; // rdi
  bool v4; // r14
  OSuite::ZWebServiceClient *v5; // rsi
  OSuite::ZString *v6; // rax
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v7; // rbp
  int *v8; // r15
  unsigned __int64 v9; // rsi
  __int64 v10; // r14
  OSuite::ZWebServiceClient *v11; // rcx
  OSuite::ZString result; // [rsp+20h] [rbp-38h]

  if ( pWebServiceClient )
  {
    v3 = this;
    v4 = deleteIt;
    v5 = pWebServiceClient;
    OSuite::ZMutex::Lock(&this->m_Mutex);
    v6 = OSuite::ZUrl::ToString(&v5->m_baseUrl, &result, 0);
    v7 = OSuite::ZWebServiceClientManager::ZWebServiceClientList::Find(&v3->m_webServiceList, v6);
    OSuite::ZString::~ZString(&result);
    v8 = &v7->refCount;
    OSuite::ZThread::AtomicAdd(&v7->refCount, -1);
    if ( v4
      || (unsigned int)OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)v7->pWebServiceClient) == 2
      && !*v8 )
    {
      v9 = 0i64;
      if ( v3->m_webServiceList.m_nTop )
      {
        v10 = 0i64;
        while ( !OSuite::ZWebServiceClientManager::ZWebServiceClientBucket::operator==(
                   &v3->m_webServiceList.m_pList[v10],
                   v7) )
        {
          ++v9;
          ++v10;
          if ( v9 >= v3->m_webServiceList.m_nTop )
            goto LABEL_11;
        }
        v3->m_webServiceList.vfptr[1].__vecDelDtor((OSuite::ZObject *)&v3->m_webServiceList.vfptr, v9);
      }
LABEL_11:
      v11 = v7->pWebServiceClient;
      if ( v11 )
        v11->vfptr->__vecDelDtor((OSuite::ZObject *)&v11->vfptr, 1u);
      *v8 = 0;
      v7->pWebServiceClient = 0i64;
    }
    OSuite::ZMutex::Unlock(&v3->m_Mutex);
  }
}

// File Line: 160
// RVA: 0xEDA42C
OSuite::ZWebServiceClient *__fastcall OSuite::ZWebServiceClientManager::GetForUrl(OSuite::ZWebServiceClientManager *this, OSuite::ZUrl *url)
{
  OSuite::ZMutex *v2; // rbx
  OSuite::ZWebServiceClientManager *v3; // rsi
  OSuite::ZUrl *v4; // rdi
  OSuite::ZString *v5; // rax
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v6; // rsi
  OSuite::ZWebServiceClient *v7; // rdi
  OSuite::ZString result; // [rsp+20h] [rbp-28h]

  v2 = &this->m_Mutex;
  v3 = this;
  v4 = url;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v5 = OSuite::ZUrl::ToString(v4, &result, 0);
  v6 = OSuite::ZWebServiceClientManager::ZWebServiceClientList::Find(&v3->m_webServiceList, v5);
  OSuite::ZString::~ZString(&result);
  v7 = 0i64;
  if ( v6 && v6->refCount > 0 )
    v7 = v6->pWebServiceClient;
  OSuite::ZMutex::Unlock(v2);
  return v7;
}


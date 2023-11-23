// File Line: 22
// RVA: 0xED9E6C
char __fastcall OSuite::ZWebServiceClientManager::ZWebServiceClientBucket::operator==(
        OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *this,
        OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *wscb)
{
  bool v4; // al
  char v5; // r8

  v4 = OSuite::ZString::operator==(&this->name, &wscb->name);
  v5 = 0;
  if ( v4 && this->pWebServiceClient == wscb->pWebServiceClient )
    return 1;
  return v5;
}

// File Line: 30
// RVA: 0xED9DA4
void __fastcall OSuite::ZWebServiceClientManager::ZWebServiceClientList::ZWebServiceClientList(
        OSuite::ZWebServiceClientManager::ZWebServiceClientList *this,
        OSuite::ZObject *a2)
{
  OSuite::IHashable *v3; // rax

  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(this, a2);
  this->m_pList = 0i64;
  this->OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWebServiceClientManager::ZWebServiceClientList::`vftable{for `OSuite::ZListBase};
  this->OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZWebServiceClientManager::ZWebServiceClientList::`vftable{for `OSuite::IHashable};
  v3 = OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::AllocList(this, 0i64, 0x10ui64);
  this->m_nTop = 0i64;
  this->m_pList = (OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *)v3;
  this->m_nSize = 16i64;
  this->OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWebServiceClientManager::ZWebServiceClientList::`vftable{for `OSuite::ZListBase};
  this->OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZWebServiceClientManager::ZWebServiceClientList::`vftable{for `OSuite::IHashable};
}

// File Line: 35
// RVA: 0xEDA4A4
OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *__fastcall OSuite::ZWebServiceClientManager::ZWebServiceClientList::Insert(
        OSuite::ZWebServiceClientManager::ZWebServiceClientList *this,
        OSuite::ZString *name,
        OSuite::ZWebServiceClient *pWebServiceClient)
{
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v6; // rax
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v7; // rbx
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket element; // [rsp+20h] [rbp-48h] BYREF

  v6 = OSuite::ZWebServiceClientManager::ZWebServiceClientList::Find(this, name);
  v7 = v6;
  if ( v6 )
  {
    if ( !v6->pWebServiceClient )
    {
      v6->refCount = 0;
      v6->pWebServiceClient = pWebServiceClient;
    }
  }
  else
  {
    element.refCount = 0;
    element.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWebServiceClientManager::ZWebServiceClientBucket::`vftable;
    OSuite::ZString::ZString(&element.name, &customCaption);
    v7 = OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::Append(this, &element);
    OSuite::ZString::~ZString(&element.name);
    OSuite::ZString::operator=(&v7->name, name);
    v7->pWebServiceClient = pWebServiceClient;
  }
  OSuite::ZString::~ZString(name);
  return v7;
}

// File Line: 52
// RVA: 0xEDA330
OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *__fastcall OSuite::ZWebServiceClientManager::ZWebServiceClientList::Find(
        OSuite::ZWebServiceClientManager::ZWebServiceClientList *this,
        OSuite::ZString *key)
{
  unsigned __int64 m_nIndex; // rdi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v5; // rsi
  unsigned __int64 v7; // rdi
  OSuite::ZListBase *v8; // rbx
  unsigned __int64 v9; // rsi
  OSuite::ZListBase::ZListIteratorBase v10; // [rsp+20h] [rbp-20h] BYREF

  v10.m_pListBase = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, this);
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( 1 )
  {
    if ( OSuite::ZListBase::ZListIteratorBase::AtEnd(&v10) )
      return 0i64;
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v10.m_pListBase);
    m_nIndex = v10.m_nIndex;
    m_pListBase = v10.m_pListBase;
    v5 = v10.m_nIndex + 1;
    OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::Grow(
      (OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket> *)v10.m_pListBase,
      v10.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v5;
    if ( OSuite::ZString::StartsWith(key, (OSuite::ZString *)(m_pListBase[1].m_nSize + 48 * m_nIndex + 16)) )
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
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *m_pList; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWebServiceClientManager::`vftable;
  OSuite::ZWebServiceClientManager::Clean(this);
  m_pList = this->m_webServiceList.m_pList;
  this->m_webServiceList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWebServiceClientManager::ZWebServiceClientList::`vftable{for `OSuite::ZListBase};
  this->m_webServiceList.vfptr = (OSuite::IHashableVtbl *)&OSuite::ZWebServiceClientManager::ZWebServiceClientList::`vftable{for `OSuite::IHashable};
  if ( m_pList )
  {
    if ( LODWORD(m_pList[-1].pWebServiceClient) )
      m_pList->vfptr->__vecDelDtor(m_pList, 3u);
    else
      Illusion::ShaderParam::operator delete(&m_pList[-1].pWebServiceClient);
  }
  OSuite::ZMutex::~ZMutex(&this->m_Mutex);
}

// File Line: 70
// RVA: 0xED9F30
void __fastcall OSuite::ZWebServiceClientManager::Clean(OSuite::ZWebServiceClientManager *this)
{
  OSuite::ZWebServiceClientManager::ZWebServiceClientList *p_m_webServiceList; // rdi
  unsigned __int64 m_nIndex; // rbx
  OSuite::ZListBase *m_pListBase; // rsi
  unsigned __int64 v4; // r14
  unsigned __int64 v5; // rsi
  OSuite::ZListBase *v6; // rbx
  unsigned __int64 v7; // r14
  void (__fastcall ***v8)(_QWORD, __int64); // rcx
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *m_pList; // rcx
  OSuite::IHashable *v10; // rax
  OSuite::ZListBase::ZListIteratorBase v11; // [rsp+20h] [rbp-20h] BYREF

  v11.m_pListBase = 0i64;
  p_m_webServiceList = &this->m_webServiceList;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v11, &this->m_webServiceList);
  v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v11) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11.m_pListBase);
    m_nIndex = v11.m_nIndex;
    m_pListBase = v11.m_pListBase;
    v4 = v11.m_nIndex + 1;
    OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::Grow(
      (OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket> *)v11.m_pListBase,
      v11.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v4;
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11.m_pListBase);
    v5 = v11.m_nIndex;
    v6 = v11.m_pListBase;
    v7 = v11.m_nIndex + 1;
    OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::Grow(
      (OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket> *)v11.m_pListBase,
      v11.m_nIndex + 1);
    if ( v5 >= v6->m_nTop )
      v6->m_nTop = v7;
    v8 = *(void (__fastcall ****)(_QWORD, __int64))(v6[1].m_nSize + 48 * v5 + 40);
    if ( v8 )
      (**v8)(v8, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Remove(&v11);
  }
  m_pList = p_m_webServiceList->m_pList;
  if ( m_pList )
  {
    if ( LODWORD(m_pList[-1].pWebServiceClient) )
      m_pList->vfptr->__vecDelDtor(m_pList, 3u);
    else
      Illusion::ShaderParam::operator delete(&m_pList[-1].pWebServiceClient);
  }
  v10 = OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::AllocList(
          p_m_webServiceList,
          p_m_webServiceList->m_pList,
          0x10ui64);
  p_m_webServiceList->m_nTop = 0i64;
  p_m_webServiceList->m_nSize = 16i64;
  p_m_webServiceList->m_pList = (OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *)v10;
}

// File Line: 87
// RVA: 0xEDA068
OSuite::ZWebServiceClient *__fastcall OSuite::ZWebServiceClientManager::Create(
        OSuite::ZWebServiceClientManager *this,
        const char *baseUrl,
        OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *cb)
{
  char v4; // si
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
  OSuite::ZWebServiceClient *pWebServiceClient; // rbx
  OSuite::ZString *v17; // rax
  OSuite::ZUrl *v18; // rax
  OSuite::ZWebServiceClient *v19; // rbx
  OSuite::ZString v21; // [rsp+20h] [rbp-E0h] BYREF
  int v22; // [rsp+38h] [rbp-C8h]
  OSuite::ZUrl result; // [rsp+40h] [rbp-C0h] BYREF
  OSuite::ZString key; // [rsp+118h] [rbp+18h] BYREF
  OSuite::SCallbackData pData; // [rsp+130h] [rbp+30h] BYREF

  v4 = 0;
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
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v8 = OSuite::ZWebServiceClientManager::ZWebServiceClientList::Find(&this->m_webServiceList, &key);
  v9 = v8;
  if ( v8 )
  {
    if ( (unsigned int)OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)v8->pWebServiceClient) == 1 )
    {
      pWebServiceClient = v9->pWebServiceClient;
      OSuite::ZMutex::Lock(&pWebServiceClient->m_requestDelegatesMutex);
      OSuite::ZString::ZString(&v21, OSuite::ZWebServiceClient::METADATA_PATH);
      OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::Insert(
        &v9->pWebServiceClient->m_clientRequestDelegates,
        &v21,
        cb);
      OSuite::ZString::~ZString(&v21);
      OSuite::ZMutex::Unlock(&pWebServiceClient->m_requestDelegatesMutex);
      OSuite::SCallbackData::SCallbackData(&pData);
      pData.Status = (OSuite::SHttpStatus)200i64;
      pData.eEvent = EVENT_FINISHED;
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
      v9->pWebServiceClient->m_eState = INIT_STATE;
      OSuite::ZWebServiceClient::Initialize(v9->pWebServiceClient, cb);
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
      v4 = 1;
      v12 = OSuite::ZUrl::Parse(&result, &key);
      OSuite::ZWebServiceClient::ZWebServiceClient(v11, v12);
      v14 = v13;
    }
    else
    {
      v14 = 0i64;
    }
    if ( (v4 & 1) != 0 )
      OSuite::ZUrl::~ZUrl(&result);
    OSuite::ZWebServiceClient::Initialize(v14, cb);
    OSuite::ZString::ZString(&v21, &key);
    v9 = OSuite::ZWebServiceClientManager::ZWebServiceClientList::Insert(&this->m_webServiceList, v15, v14);
  }
  OSuite::ZMutex::Unlock(&this->m_Mutex);
  OSuite::ZThread::AtomicAdd(&v9->refCount, 1);
  v19 = v9->pWebServiceClient;
  OSuite::ZString::~ZString(&key);
  return v19;
}

// File Line: 137
// RVA: 0xEDA540
void __fastcall OSuite::ZWebServiceClientManager::Release(
        OSuite::ZWebServiceClientManager *this,
        OSuite::ZWebServiceClient *pWebServiceClient,
        bool deleteIt)
{
  OSuite::ZString *v6; // rax
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v7; // rbp
  int *p_refCount; // r15
  unsigned __int64 v9; // rsi
  __int64 v10; // r14
  OSuite::ZWebServiceClient *v11; // rcx
  OSuite::ZString result; // [rsp+20h] [rbp-38h] BYREF

  if ( pWebServiceClient )
  {
    OSuite::ZMutex::Lock(&this->m_Mutex);
    v6 = OSuite::ZUrl::ToString(&pWebServiceClient->m_baseUrl, &result, 0);
    v7 = OSuite::ZWebServiceClientManager::ZWebServiceClientList::Find(&this->m_webServiceList, v6);
    OSuite::ZString::~ZString(&result);
    p_refCount = &v7->refCount;
    OSuite::ZThread::AtomicAdd(&v7->refCount, -1);
    if ( deleteIt
      || (unsigned int)OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)v7->pWebServiceClient) == 2
      && !*p_refCount )
    {
      v9 = 0i64;
      if ( this->m_webServiceList.m_nTop )
      {
        v10 = 0i64;
        while ( !OSuite::ZWebServiceClientManager::ZWebServiceClientBucket::operator==(
                   &this->m_webServiceList.m_pList[v10],
                   v7) )
        {
          ++v9;
          ++v10;
          if ( v9 >= this->m_webServiceList.m_nTop )
            goto LABEL_11;
        }
        this->m_webServiceList.vfptr[1].__vecDelDtor(&this->m_webServiceList, v9);
      }
LABEL_11:
      v11 = v7->pWebServiceClient;
      if ( v11 )
        v11->vfptr->__vecDelDtor(v11, 1u);
      *p_refCount = 0;
      v7->pWebServiceClient = 0i64;
    }
    OSuite::ZMutex::Unlock(&this->m_Mutex);
  }
}

// File Line: 160
// RVA: 0xEDA42C
OSuite::ZWebServiceClient *__fastcall OSuite::ZWebServiceClientManager::GetForUrl(
        OSuite::ZWebServiceClientManager *this,
        OSuite::ZUrl *url)
{
  OSuite::ZMutex *p_m_Mutex; // rbx
  OSuite::ZString *v5; // rax
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v6; // rsi
  OSuite::ZWebServiceClient *pWebServiceClient; // rdi
  OSuite::ZString result; // [rsp+20h] [rbp-28h] BYREF

  p_m_Mutex = &this->m_Mutex;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v5 = OSuite::ZUrl::ToString(url, &result, 0);
  v6 = OSuite::ZWebServiceClientManager::ZWebServiceClientList::Find(&this->m_webServiceList, v5);
  OSuite::ZString::~ZString(&result);
  pWebServiceClient = 0i64;
  if ( v6 && v6->refCount > 0 )
    pWebServiceClient = v6->pWebServiceClient;
  OSuite::ZMutex::Unlock(p_m_Mutex);
  return pWebServiceClient;
}


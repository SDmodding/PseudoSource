// File Line: 45
// RVA: 0xEC9A4C
void __fastcall OSuite::ZInternalWebServiceDelegate::ZInternalWebServiceDelegate(
        OSuite::ZInternalWebServiceDelegate *this,
        OSuite::ZWebServiceClient *pWebServiceClient,
        OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *requestDelegate,
        OSuite::SCallbackData *status)
{
  OSuite::ZUrl *p_URL; // rcx

  this->OSuite::ManagedCallback::OSuite::ICallback<void,void>::vfptr = (OSuite::ICallback<void,void>Vtbl *)&OSuite::ZInternalWebServiceDelegate::`vftable{for `OSuite::ICallback<void,void>};
  this->OSuite::ManagedCallback::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZInternalWebServiceDelegate::`vftable{for `OSuite::ZObject};
  p_URL = &this->m_Status.URL;
  p_URL[-1].m_urlParameters.m_arrayParameters.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)status->Status;
  p_URL[-1].m_nPort = status->eEvent;
  OSuite::ZUrl::ZUrl(p_URL, &status->URL);
  OSuite::TList<OSuite::OSError>::TList<OSuite::OSError>(
    &this->m_Status.OSErrors,
    (OSuite::ZListBase::ZListIteratorBase *)&status->OSErrors);
  this->m_delegate.m_Closure.m_pthis = 0i64;
  this->m_delegate.m_Closure.m_pFunction = 0i64;
  this->m_delegate = *requestDelegate;
  this->m_pWebServiceClient = pWebServiceClient;
}

// File Line: 51
// RVA: 0xECA13C
void __fastcall OSuite::ZInternalWebServiceDelegate::Call(OSuite::ZInternalWebServiceDelegate *this)
{
  ((void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *, OSuite::SCallbackData *, OSuite::ZWebServiceClient *))this->m_delegate.m_Closure.m_pFunction)(
    this->m_delegate.m_Closure.m_pthis,
    &this->m_Status,
    this->m_pWebServiceClient);
}

// File Line: 61
// RVA: 0xEC9AF8
void __fastcall OSuite::ZInternalWebServiceProbeDelegate::ZInternalWebServiceProbeDelegate(
        OSuite::ZInternalWebServiceProbeDelegate *this,
        OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,char const *,void> *probeDelegate,
        OSuite::SCallbackData *status,
        OSuite::ZString *clientIpAddress)
{
  OSuite::ZUrl *p_URL; // rcx

  this->OSuite::ManagedCallback::OSuite::ICallback<void,void>::vfptr = (OSuite::ICallback<void,void>Vtbl *)&OSuite::ZInternalWebServiceProbeDelegate::`vftable{for `OSuite::ICallback<void,void>};
  this->OSuite::ManagedCallback::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZInternalWebServiceProbeDelegate::`vftable{for `OSuite::ZObject};
  p_URL = &this->m_Status.URL;
  p_URL[-1].m_urlParameters.m_arrayParameters.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)status->Status;
  p_URL[-1].m_nPort = status->eEvent;
  OSuite::ZUrl::ZUrl(p_URL, &status->URL);
  OSuite::TList<OSuite::OSError>::TList<OSuite::OSError>(
    &this->m_Status.OSErrors,
    (OSuite::ZListBase::ZListIteratorBase *)&status->OSErrors);
  this->m_delegate.m_Closure.m_pthis = 0i64;
  this->m_delegate.m_Closure.m_pFunction = 0i64;
  this->m_delegate = *probeDelegate;
  OSuite::ZString::ZString(&this->m_sClientIP, clientIpAddress);
}

// File Line: 65
// RVA: 0xECA158
void __fastcall OSuite::ZInternalWebServiceProbeDelegate::Call(OSuite::ZInternalWebServiceProbeDelegate *this)
{
  const char *v2; // rax

  v2 = OSuite::ZString::c_str(&this->m_sClientIP);
  ((void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *, OSuite::SCallbackData *, const char *))this->m_delegate.m_Closure.m_pFunction)(
    this->m_delegate.m_Closure.m_pthis,
    &this->m_Status,
    v2);
}

// File Line: 82
// RVA: 0xEC9BA8
void __fastcall OSuite::ZWebServiceClient::ZWebServiceClient(OSuite::ZWebServiceClient *this, OSuite::ZUrl *baseUrl)
{
  OSuite::ZAtomCache *v2; // rbx
  OSuite::ZAtomCache *v5; // rax
  OSuite::ZAtomCache *v6; // rax
  OSuite::ZUsageTrackingManager *v7; // rbx
  OSuite::ZString *TicketData; // rax
  const char *v9; // rax

  v2 = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWebServiceClient::`vftable;
  this->m_eState = INIT_STATE;
  this->m_pCache = 0i64;
  this->m_pMetricAppender = 0i64;
  this->m_pUsageStatisticsMetricAppender = 0i64;
  this->m_pPriorityMetricAppender = 0i64;
  this->m_pUsageTracker = 0i64;
  this->m_pMetadata = 0i64;
  this->m_pProbeRequest = 0i64;
  this->m_LastProbeTime = 0i64;
  OSuite::ZUrl::ZUrl(&this->m_baseUrl, baseUrl);
  OSuite::ZMutex::ZMutex(&this->m_requestDelegatesMutex);
  OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>(
    &this->m_clientRequestDelegates,
    0x10ui64);
  this->m_clientProbeDelegate.m_Closure.m_pthis = 0i64;
  this->m_clientProbeDelegate.m_Closure.m_pFunction = 0i64;
  this->m_pszPublicIpAddress = 0i64;
  v5 = (OSuite::ZAtomCache *)OSuite::ZObject::operator new(0x48ui64);
  if ( v5 )
  {
    v5->m_Objects.m_pTop = 0i64;
    v5->m_Mutex.m_pInternalMutex = 0i64;
    OSuite::ZAtomCache::ZAtomCache(v5);
    v2 = v6;
  }
  this->m_pCache = v2;
  v7 = OSuite::TSingleton<OSuite::ZUsageTrackingManager>::Object();
  TicketData = OSuite::IOnlineAuthentication::GetTicketData(baseUrl);
  v9 = OSuite::ZString::c_str(TicketData);
  this->m_pUsageTracker = OSuite::ZUsageTrackingManager::CreateForHost(v7, v9);
}

// File Line: 96
// RVA: 0xECAE4C
bool __fastcall OSuite::ZWebServiceClient::Initialize(
        OSuite::ZWebServiceClient *this,
        OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *cb)
{
  OSuite::ZMutex *p_m_requestDelegatesMutex; // rbx
  OSuite::ZString key; // [rsp+20h] [rbp-28h] BYREF

  if ( !this->m_pMetadata )
  {
    p_m_requestDelegatesMutex = &this->m_requestDelegatesMutex;
    OSuite::ZMutex::Lock(&this->m_requestDelegatesMutex);
    OSuite::ZString::ZString(&key, OSuite::OS_GETSTATUS_PATH);
    OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::Insert(
      &this->m_clientRequestDelegates,
      &key,
      cb);
    OSuite::ZString::~ZString(&key);
    OSuite::ZString::ZString(&key, OSuite::ZWebServiceClient::METADATA_PATH);
    OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::Insert(
      &this->m_clientRequestDelegates,
      &key,
      cb);
    OSuite::ZString::~ZString(&key);
    OSuite::ZMutex::Unlock(p_m_requestDelegatesMutex);
    key.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)OSuite::ZWebServiceClient::InternalProbeResultCallback;
    key.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)this;
    OSuite::ZWebServiceClient::ProbeAvailability(
      this,
      (OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,char const *,void> *)&key);
  }
  return this->m_pMetadata != 0i64;
}

// File Line: 115
// RVA: 0xECC134
void __fastcall OSuite::ZWebServiceClient::Release(OSuite::ZWebServiceClient *this)
{
  OSuite::ZOnlineSuite *v2; // rax

  v2 = OSuite::ZOnlineSuite::Instance();
  OSuite::ZOnlineSuite::Release(v2, this);
}

// File Line: 121
// RVA: 0xEC9C84
void __fastcall OSuite::ZWebServiceClient::~ZWebServiceClient(OSuite::ZWebServiceClient *this)
{
  bool v1; // zf
  OSuite::ZHttpManager *v3; // rax
  OSuite::ZAtomCache *m_pCache; // rcx
  OSuite::ZMetricAppender *m_pPriorityMetricAppender; // rcx
  OSuite::ZMetricAppender *m_pMetricAppender; // rcx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> > *m_pLists; // rcx

  v1 = this->m_pProbeRequest == 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWebServiceClient::`vftable;
  this->m_eState = SHUTDOWN_STATE;
  if ( !v1 )
  {
    v3 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpRequestManager::ShutdownHttpRequest(v3->m_httpRequestManager, this->m_pProbeRequest);
    this->m_pProbeRequest = 0i64;
  }
  m_pCache = this->m_pCache;
  if ( m_pCache )
  {
    m_pCache->vfptr->__vecDelDtor(m_pCache, 1u);
    this->m_pCache = 0i64;
  }
  this->m_pMetadata = 0i64;
  if ( this->m_pUsageStatisticsMetricAppender )
  {
    OSuitePrivate::ZPlayerConsumableData::SetConsumablesData(this->m_pUsageTracker, 0i64);
    OSuite::ZMetricAppender::ReleaseAppender(this->m_pUsageStatisticsMetricAppender);
    this->m_pUsageStatisticsMetricAppender = 0i64;
  }
  m_pPriorityMetricAppender = this->m_pPriorityMetricAppender;
  if ( m_pPriorityMetricAppender )
  {
    OSuite::ZMetricAppender::ReleaseAppender(m_pPriorityMetricAppender);
    this->m_pPriorityMetricAppender = 0i64;
  }
  m_pMetricAppender = this->m_pMetricAppender;
  if ( m_pMetricAppender )
  {
    OSuite::ZMetricAppender::ReleaseAppender(m_pMetricAppender);
    this->m_pMetricAppender = 0i64;
  }
  OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, this->m_pszPublicIpAddress);
  this->m_pszPublicIpAddress = 0i64;
  m_pLists = this->m_clientRequestDelegates.m_pLists;
  this->m_clientRequestDelegates.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  if ( m_pLists )
  {
    if ( LODWORD(m_pLists[-1].m_Comparer.vfptr) )
      m_pLists->vfptr->__vecDelDtor(m_pLists, 3u);
    else
      Illusion::ShaderParam::operator delete(&m_pLists[-1].m_Comparer.OSuite::ZObject);
  }
  OSuite::ZMutex::~ZMutex(&this->m_requestDelegatesMutex);
  OSuite::ZUrl::~ZUrl(&this->m_baseUrl);
}

// File Line: 163
// RVA: 0xECBA4C
OSuite::ZOMetadata *__fastcall OSuite::ZWebServiceClient::Metadata(OSuite::ZWebServiceClient *this)
{
  return this->m_pMetadata;
}

// File Line: 198
// RVA: 0xECA264
void __fastcall OSuite::ZWebServiceClient::CloseRequest(OSuite::ZWebServiceClient *this, OSuite::ZAtomBase *obj)
{
  OSuite::ZAtomCache::CloseObject(this->m_pCache, obj);
}

// File Line: 204
// RVA: 0xECA3B8
bool __fastcall OSuite::ZWebServiceClient::ExecuteQuery(
        OSuite::ZWebServiceClient *this,
        OSuite::ZOQuery *query,
        OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *cb)
{
  OSuite::ZOMetadata *m_pMetadata; // rcx
  bool v5; // si
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *v6; // r14
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *v8; // rax
  OSuite::ZString *p_m_pLeft; // rbx
  const char *v10; // rdi
  const char *v11; // rax
  OSuite::ZString *v12; // rbx
  const char *v13; // rdi
  const char *v14; // rax
  OSuite::ZString *v15; // rax
  const char *v16; // rax
  bool v17; // bl
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *v19; // rax
  const char *v20; // rax
  OSuite::ZString *v21; // rax
  const char *v22; // rax
  const char *v23; // rax
  OSuite::ZString *v24; // rax
  const char *v25; // rax
  OSuite::ZOEdmFunctionImport::ZReturnType m_ReturnType; // edx
  OSuite::ZString *p_m_HttpMethod; // rcx
  const char *v28; // rbx
  const char *v29; // rax
  bool v30; // al
  OSuite::fastdelegate::detail::GenericClass *m_pthis; // rcx
  const char *v32; // rbx
  const char *v33; // rax
  const char *v34; // rbx
  const char *v35; // rax
  OSuite::fastdelegate::detail::GenericClass *v36; // rcx
  OSuite::ZOEdmFunctionImport *v37; // [rsp+20h] [rbp-E0h]
  OSuite::SFunctionParameter *v38; // [rsp+28h] [rbp-D8h]
  OSuite::SFunctionParameter *v39; // [rsp+28h] [rbp-D8h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+38h] [rbp-C8h] BYREF
  OSuite::ZString paramValue; // [rsp+B8h] [rbp-48h] BYREF
  void **v43; // [rsp+D0h] [rbp-30h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator v44; // [rsp+D8h] [rbp-28h] BYREF
  OSuite::ZStringBuilder v45; // [rsp+160h] [rbp+60h] BYREF
  OSuite::ZString v46; // [rsp+190h] [rbp+90h] BYREF
  OSuite::ZStringBuilder v47; // [rsp+1A8h] [rbp+A8h] BYREF
  OSuite::SCallbackData v48; // [rsp+1E0h] [rbp+E0h] BYREF
  OSuite::SCallbackData v49; // [rsp+2F0h] [rbp+1F0h] BYREF

  m_pMetadata = this->m_pMetadata;
  v5 = 0;
  v6 = cb;
  if ( !m_pMetadata )
    goto LABEL_35;
  if ( query->m_eMode != QM_ENTITYSET )
  {
    if ( query->m_eMode != QM_FUNCTIONIMPORT )
      goto LABEL_35;
    v37 = OSuite::ZOMetadata::FunctionImport(m_pMetadata, &query->m_entityName);
    if ( !v37 )
      goto LABEL_35;
    v47.m_Chars.m_pList = 0i64;
    OSuite::ZStringBuilder::ZStringBuilder(&v47, 0x100ui64);
    OSuite::ZStringBuilder::Append(&v47, &query->m_entityName);
    if ( query->m_functionParameters.m_nCount )
    {
      v44.m_pMap = 0i64;
      v44.m_iterator.m_iterator.m_parents.m_pList = 0i64;
      *(_OWORD *)&v44.m_iterator.m_iterator.m_pList = 0i64;
      v19 = OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
              (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&query->m_functionParameters,
              &result);
      v43 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
      v44.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
      v44.m_pMap = v19->m_pMap;
      v44.m_iCurrentHash = v19->m_iCurrentHash;
      v44.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
      OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v44.m_iterator.m_iterator, &v19->m_iterator.m_iterator);
      result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
      result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
      result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
      v44.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
      result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
      result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
      if ( result.m_iterator.m_iterator.m_parents.m_pList )
        result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
          result.m_iterator.m_iterator.m_parents.m_pList,
          1u);
      v38 = OSuite::ZOEdmFunctionImport::Parameter(
              v37,
              (OSuite::ZString *)&v44.m_iterator.m_iterator.m_pElement[1].m_pLeft);
      if ( !v38 )
      {
        OSuite::SCallbackData::SCallbackData(&v48);
        m_pthis = v6->m_Closure.m_pthis;
        v48.Status.eError = HTTPERROR_INVALID;
        v48.Status.nHttpStatus = 404;
        ((void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *, OSuite::SCallbackData *, OSuite::ZWebServiceClient *))v6->m_Closure.m_pFunction)(
          m_pthis,
          &v48,
          this);
        OSuite::SCallbackData::~SCallbackData(&v48);
        v43 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
        v44.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
        v44.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
        v44.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
        v44.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
        v44.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
        if ( v44.m_iterator.m_iterator.m_parents.m_pList )
          v44.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
            v44.m_iterator.m_iterator.m_parents.m_pList,
            1u);
        goto LABEL_34;
      }
      paramValue.m_pString = 0i64;
      v20 = OSuite::ZString::c_str((OSuite::ZString *)&v44.m_iterator.m_iterator.m_pElement[2]);
      OSuite::ZOQuery::SanitizeString(query, &paramValue, v20, 0);
      v21 = OSuite::SFunctionParameter::ToString(v38, (OSuite::ZString *)&v45, &paramValue);
      v22 = OSuite::ZString::c_str(v21);
      OSuite::ZStringBuilder::AppendFormat(&v47, "?%s", v22);
      OSuite::ZString::~ZString((OSuite::ZString *)&v45);
      OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&v44);
      OSuite::ZString::~ZString(&paramValue);
      if ( !OSuite::ZString::IsNull((OSuite::ZString *)&v44.m_iterator.m_iterator) )
      {
        do
        {
          v39 = OSuite::ZOEdmFunctionImport::Parameter(
                  v37,
                  (OSuite::ZString *)&v44.m_iterator.m_iterator.m_pElement[1].m_pLeft);
          if ( v39 )
          {
            paramValue.m_pString = 0i64;
            v23 = OSuite::ZString::c_str((OSuite::ZString *)&v44.m_iterator.m_iterator.m_pElement[2]);
            OSuite::ZOQuery::SanitizeString(query, &paramValue, v23, 0);
            v24 = OSuite::SFunctionParameter::ToString(v39, (OSuite::ZString *)&v45, &paramValue);
            v25 = OSuite::ZString::c_str(v24);
            OSuite::ZStringBuilder::AppendFormat(&v47, "&%s", v25);
            OSuite::ZString::~ZString((OSuite::ZString *)&v45);
            OSuite::ZString::~ZString(&paramValue);
          }
          OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&v44);
        }
        while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v44.m_iterator.m_iterator) );
        v6 = cb;
      }
      v44.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
      v43 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
      v44.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
      v44.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
      v44.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
      v44.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
      if ( v44.m_iterator.m_iterator.m_parents.m_pList )
        v44.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
          v44.m_iterator.m_iterator.m_parents.m_pList,
          1u);
    }
    v46.m_pString = 0i64;
    OSuite::ZStringBuilder::ToString(&v47, &v46);
    m_ReturnType = v37->m_ReturnType;
    p_m_HttpMethod = &v37->m_HttpMethod;
    if ( m_ReturnType )
    {
      if ( m_ReturnType == SVOP_ENTRY )
      {
        v32 = OSuite::ZString::c_str(p_m_HttpMethod);
        v33 = OSuite::ZString::c_str(&v46);
        v30 = OSuite::ZWebServiceClient::Request<OSuite::ZOEntry>(this, v33, v6, v32);
      }
      else
      {
        v34 = OSuite::ZString::c_str(p_m_HttpMethod);
        v35 = OSuite::ZString::c_str(&v46);
        v30 = OSuite::ZWebServiceClient::Request<OSuite::ZOServiceOperationResult>(this, v35, v6, v34);
      }
    }
    else
    {
      v28 = OSuite::ZString::c_str(p_m_HttpMethod);
      v29 = OSuite::ZString::c_str(&v46);
      v30 = OSuite::ZWebServiceClient::Request<OSuite::ZOFeed>(this, v29, v6, v28);
    }
    v5 = v30;
    OSuite::ZString::~ZString(&v46);
LABEL_34:
    OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v47);
    return v5;
  }
  if ( !OSuite::ZOMetadata::EntitySet(m_pMetadata, &query->m_entityName) )
  {
LABEL_35:
    OSuite::SCallbackData::SCallbackData(&v49);
    v36 = v6->m_Closure.m_pthis;
    v49.Status.eError = HTTPERROR_INVALID;
    v49.Status.nHttpStatus = 404;
    ((void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *, OSuite::SCallbackData *, OSuite::ZWebServiceClient *))v6->m_Closure.m_pFunction)(
      v36,
      &v49,
      this);
    OSuite::SCallbackData::~SCallbackData(&v49);
    return 0;
  }
  v45.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v45, 0x100ui64);
  OSuite::ZStringBuilder::Append(&v45, &query->m_entityName);
  if ( query->m_queryMap.m_nCount )
  {
    OSuite::ZStringBuilder::Append(&v45, "?");
    *(_OWORD *)&v44.m_iterator.m_iterator.m_pList = 0i64;
    v44.m_pMap = 0i64;
    v44.m_iterator.m_iterator.m_parents.m_pList = 0i64;
    v8 = OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
           (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&query->m_queryMap,
           &result);
    v43 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
    v44.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    v44.m_pMap = v8->m_pMap;
    v44.m_iCurrentHash = v8->m_iCurrentHash;
    v44.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v44.m_iterator.m_iterator, &v8->m_iterator.m_iterator);
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v44.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    p_m_pLeft = (OSuite::ZString *)&v44.m_iterator.m_iterator.m_pElement[1].m_pLeft;
    v10 = OSuite::ZString::c_str((OSuite::ZString *)&v44.m_iterator.m_iterator.m_pElement[2]);
    v11 = OSuite::ZString::c_str(p_m_pLeft);
    OSuite::ZStringBuilder::AppendFormat(&v45, "%s=%s", v11, v10);
    while ( 1 )
    {
      OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&v44);
      if ( OSuite::ZString::IsNull((OSuite::ZString *)&v44.m_iterator.m_iterator) )
        break;
      v12 = (OSuite::ZString *)&v44.m_iterator.m_iterator.m_pElement[1].m_pLeft;
      v13 = OSuite::ZString::c_str((OSuite::ZString *)&v44.m_iterator.m_iterator.m_pElement[2]);
      v14 = OSuite::ZString::c_str(v12);
      OSuite::ZStringBuilder::AppendFormat(&v45, "&%s=%s", v14, v13);
    }
    v44.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    v43 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
    v44.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v44.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    v44.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v44.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( v44.m_iterator.m_iterator.m_parents.m_pList )
      v44.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(v44.m_iterator.m_iterator.m_parents.m_pList, 1u);
  }
  v15 = OSuite::ZStringBuilder::ToString(&v45, &paramValue);
  v16 = OSuite::ZString::c_str(v15);
  v17 = OSuite::ZWebServiceClient::Request<OSuite::ZOFeed>(this, v16, v6, "GET");
  OSuite::ZString::~ZString(&paramValue);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v45);
  return v17;
}

// File Line: 379
// RVA: 0xECA2B0
OSuite::ZOEntry *__fastcall OSuite::ZWebServiceClient::CreateEntry(
        OSuite::ZWebServiceClient *this,
        const char *entitySetName)
{
  OSuite::ZOMetadata *m_pMetadata; // rdi
  __int64 v3; // rbx
  OSuite::ZOEdmEntitySet *v4; // rsi
  OSuite::ZString setName; // [rsp+20h] [rbp-28h] BYREF

  m_pMetadata = this->m_pMetadata;
  v3 = 0i64;
  if ( m_pMetadata )
  {
    OSuite::ZString::ZString(&setName, entitySetName);
    v4 = OSuite::ZOMetadata::EntitySet(m_pMetadata, &setName);
    OSuite::ZString::~ZString(&setName);
    if ( v4 )
      return OSuite::ZOMetadata::CreateEntry(m_pMetadata, v4);
  }
  return (OSuite::ZOEntry *)v3;
}

// File Line: 395
// RVA: 0xECC154
void __fastcall OSuite::ZWebServiceClient::ReleaseEntry(OSuite::ZWebServiceClient *this, OSuite::ZOEntry *pEntry)
{
  if ( pEntry )
    pEntry->vfptr->__vecDelDtor(pEntry, 1i64);
}

// File Line: 408
// RVA: 0xECAD78
OSuite::ZUrl *__fastcall OSuite::ZWebServiceClient::GetBaseUrl(OSuite::ZWebServiceClient *this)
{
  return &this->m_baseUrl;
}

// File Line: 413
// RVA: 0xECAD80
OSuite::ZString *__fastcall OSuite::ZWebServiceClient::GetRelativePath(
        OSuite::ZWebServiceClient *this,
        OSuite::ZString *result,
        OSuite::ZUrl *url)
{
  OSuite::ZString *v5; // rax
  bool v6; // bl
  unsigned __int64 v7; // rbx
  OSuite::ZString *v8; // rax
  OSuite::ZString v10; // [rsp+20h] [rbp-58h] BYREF
  OSuite::ZString resulta; // [rsp+38h] [rbp-40h] BYREF

  resulta.m_pString = 0i64;
  OSuite::ZUrl::ToString(&this->m_baseUrl, &resulta, 0);
  v5 = OSuite::ZUrl::ToString(url, &v10, 0);
  v6 = !OSuite::ZString::StartsWith(v5, &resulta);
  OSuite::ZString::~ZString(&v10);
  if ( v6 )
  {
    OSuite::ZString::ZString(result, &customCaption);
  }
  else
  {
    v7 = OSuite::ZString::Count(&resulta);
    v8 = OSuite::ZUrl::ToString(url, &v10, 0);
    OSuite::ZString::Slice(v8, result, v7);
    OSuite::ZString::~ZString(&v10);
  }
  OSuite::ZString::~ZString(&resulta);
  return result;
}

// File Line: 423
// RVA: 0xECBAFC
char __fastcall OSuite::ZWebServiceClient::ProbeAvailability(
        OSuite::ZWebServiceClient *this,
        OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,char const *,void> *cb)
{
  char v2; // di
  __int64 v5; // rax
  OSuite::ZString *v6; // rax
  OSuite::ZString *v7; // rbx
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZHttpManager *v10; // rax
  OSuite::IHttpRequest *v11; // rax
  OSuite::IHttpRequest v12; // rbx
  __int64 v13; // rax
  OSuite::ZObjectVtbl *vfptr; // rbx
  __int64 v15; // rax
  void (__fastcall *m_pFunction)(OSuite::fastdelegate::detail::GenericClass *); // rax
  OSuite::fastdelegate::detail::GenericClass *m_pthis; // rax
  OSuite::IHttpRequest *m_pProbeRequest; // rcx
  OSuite::ZString *v20; // rax
  OSuite::ZString *v21; // rbx
  OSuite::ZString *v22; // rax
  OSuite::ZString *v23; // rax
  OSuite::ZUrl *v24; // rax
  OSuite::ZInternalWebServiceProbeDelegate *v25; // rax
  OSuite::ZInternalWebServiceProbeDelegate *v26; // rbx
  OSuite::ManagedCallback *v27; // rax
  OSuite::ManagedCallback *v28; // rbx
  OSuite::ZWorker *v29; // rax
  OSuite::ZString v30; // [rsp+30h] [rbp-D0h] BYREF
  OSuite::ZString result; // [rsp+48h] [rbp-B8h] BYREF
  OSuite::ZString v32; // [rsp+60h] [rbp-A0h] BYREF
  int v33; // [rsp+78h] [rbp-88h]
  __int64 v34[8]; // [rsp+80h] [rbp-80h] BYREF
  char v35; // [rsp+C0h] [rbp-40h]
  OSuite::ZUrl v36; // [rsp+C8h] [rbp-38h] BYREF
  OSuite::ZUrl url; // [rsp+1A0h] [rbp+A0h] BYREF
  OSuite::SCallbackData v38; // [rsp+280h] [rbp+180h] BYREF

  v2 = 0;
  v33 = 0;
  v5 = OSuite::ZDateTime::Current();
  if ( *(_OWORD *)cb != 0i64 )
  {
    if ( !this->m_pProbeRequest && v5 - this->m_LastProbeTime >= 5 )
    {
      this->m_LastProbeTime = v5;
      url.m_sProtocol.m_pString = 0i64;
      url.m_sHost.m_pString = 0i64;
      url.m_sFakeHost.m_pString = 0i64;
      url.m_sPath.m_pString = 0i64;
      url.m_urlParameters.m_parameters.m_pTop = 0i64;
      url.m_urlParameters.m_arrayParameters.m_pTop = 0i64;
      OSuite::ZString::ZString(&v32, OSuite::OS_GETSTATUS_PATH);
      v7 = v6;
      v8 = OSuite::ZUrl::ToString(&this->m_baseUrl, &result, 0);
      v9 = OSuite::ZString::operator+(v8, &v30, v7);
      OSuite::ZUrl::Parse(&url, v9);
      OSuite::ZString::~ZString(&v30);
      OSuite::ZString::~ZString(&result);
      OSuite::ZString::~ZString(&v32);
      v10 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
      OSuite::ZHttpRequestManager::CreateHttpRequest(v10->m_httpRequestManager, &url, this, 1, 30);
      this->m_pProbeRequest = v11;
      v12.vfptr = v11->vfptr;
      OSuite::ZString::ZString(&v32, "application/json");
      v12.vfptr[36].__vecDelDtor(this->m_pProbeRequest, v13);
      vfptr = this->m_pProbeRequest->vfptr;
      OSuite::ZString::ZString(&v32, "GET");
      vfptr[44].__vecDelDtor(this->m_pProbeRequest, v15);
      m_pFunction = cb->m_Closure.m_pFunction;
      v34[1] = 0i64;
      this->m_clientProbeDelegate.m_Closure.m_pFunction = m_pFunction;
      m_pthis = cb->m_Closure.m_pthis;
      v34[0] = 0i64;
      this->m_clientProbeDelegate.m_Closure.m_pthis = m_pthis;
      m_pProbeRequest = this->m_pProbeRequest;
      memset(&v34[2], 0, 32);
      v34[7] = (__int64)OSuite::ZWebServiceClient::InternalProbeCallback;
      v34[6] = (__int64)this;
      v35 = 0;
      m_pProbeRequest->vfptr[6].__vecDelDtor(m_pProbeRequest, (unsigned int)v34);
      OSuite::ZUrl::~ZUrl(&url);
      return 1;
    }
    OSuite::SCallbackData::SCallbackData(&v38);
    v38.Status.eError = HTTPERROR_ABORTED;
    v38.Status.nHttpStatus = 0;
    v38.eEvent = EVENT_ABORTED;
    OSuite::ZString::ZString(&result, OSuite::OS_GETSTATUS_PATH);
    v21 = v20;
    v22 = OSuite::ZUrl::ToString(&this->m_baseUrl, &v30, 0);
    v23 = OSuite::ZString::operator+(v22, &v32, v21);
    v24 = OSuite::ZUrl::Parse(&v36, v23);
    OSuite::ZUrl::operator=(&v38.URL, v24);
    OSuite::ZUrl::~ZUrl(&v36);
    OSuite::ZString::~ZString(&v32);
    OSuite::ZString::~ZString(&v30);
    OSuite::ZString::~ZString(&result);
    v25 = (OSuite::ZInternalWebServiceProbeDelegate *)OSuite::ZObject::operator new(0x148ui64);
    v26 = v25;
    if ( v25 )
    {
      v25->m_delegate.m_Closure.m_pthis = 0i64;
      v25->m_sClientIP.m_pString = 0i64;
      OSuite::ZString::ZString(&v30, &customCaption);
      result.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)cb->m_Closure.m_pFunction;
      result.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)cb->m_Closure.m_pthis;
      v2 = 1;
      OSuite::ZInternalWebServiceProbeDelegate::ZInternalWebServiceProbeDelegate(
        v26,
        (OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,char const *,void> *)&result,
        &v38,
        &v30);
      v28 = v27;
    }
    else
    {
      v28 = 0i64;
    }
    v29 = OSuite::ZWorker::Instance();
    OSuite::ZWorker::AddCallback(v29, v28);
    if ( (v2 & 1) != 0 )
      OSuite::ZString::~ZString(&v30);
    OSuite::SCallbackData::~SCallbackData(&v38);
  }
  return 0;
}

// File Line: 501
// RVA: 0xECB194
void __fastcall OSuite::ZWebServiceClient::InternalMetadataCallback(
        OSuite::ZWebServiceClient *this,
        OSuite::SCallbackData *pData)
{
  OSuite::ZOMetadata *v4; // rax
  OSuite::ZString *v5; // rax
  const char *v6; // rax
  OSuite::ZString *v7; // rax
  const char *v8; // rax
  OSuite::ZOMetadata *m_pMetadata; // rbx
  OSuite::ZOEdmClientConfiguration *m_ClientConfiguration; // rbx
  OSuite::ZString result; // [rsp+20h] [rbp-28h] BYREF

  if ( this->m_eState != SHUTDOWN_STATE )
  {
    if ( pData->Status.eError )
    {
      this->m_eState = ERROR_STATE;
    }
    else
    {
      v4 = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOMetadata>(
             this,
             OSuite::ZWebServiceClient::METADATA_PATH);
      this->m_pMetadata = v4;
      if ( v4 )
      {
        this->m_eState = READY_STATE;
        v5 = OSuite::ZUrl::ToString(&this->m_baseUrl, &result, 0);
        v6 = OSuite::ZString::c_str(v5);
        this->m_pMetricAppender = OSuite::ZMetricAppender::CreateAppender(v6, this->m_pszPublicIpAddress, 0i64);
        OSuite::ZString::~ZString(&result);
        v7 = OSuite::ZUrl::ToString(&this->m_baseUrl, &result, 0);
        v8 = OSuite::ZString::c_str(v7);
        this->m_pUsageStatisticsMetricAppender = OSuite::ZMetricAppender::CreateAppender(
                                                   v8,
                                                   this->m_pszPublicIpAddress,
                                                   0i64);
        OSuite::ZString::~ZString(&result);
        this->m_pUsageStatisticsMetricAppender->m_pTransmitter->m_bUsageTracking = 0;
        OSuite::ZMetricAppender::SetDestinationTable(this->m_pUsageStatisticsMetricAppender, "os_metrics");
        OSuitePrivate::ZPlayerConsumableData::SetConsumablesData(
          this->m_pUsageTracker,
          this->m_pUsageStatisticsMetricAppender);
        m_pMetadata = this->m_pMetadata;
        if ( m_pMetadata )
        {
          m_ClientConfiguration = m_pMetadata->m_ClientConfiguration;
          if ( m_ClientConfiguration )
          {
            this->m_pMetricAppender->m_nTransmitMemoryThreshold = m_ClientConfiguration->m_nMetricsThreshold;
            OSuite::ZUsageTracker::SetEnabled(this->m_pUsageTracker, m_ClientConfiguration->m_bUsageTrackingEnabled);
            OSuite::ZUsageTracker::Configure(
              this->m_pUsageTracker,
              m_ClientConfiguration->m_nUsageTrackingSamplingInterval,
              m_ClientConfiguration->m_nUsageTrackingMetricsInterval);
          }
        }
      }
      else
      {
        this->m_eState = ERROR_STATE;
      }
    }
    OSuite::ZWebServiceClient::InvokeExternalRequestCallback(this, pData);
  }
}

// File Line: 550
// RVA: 0xECB838
void __fastcall OSuite::ZWebServiceClient::InternalRequestCallback(
        OSuite::ZWebServiceClient *this,
        OSuite::SCallbackData *pData)
{
  if ( this->m_eState != SHUTDOWN_STATE )
    OSuite::ZWebServiceClient::InvokeExternalRequestCallback(this, pData);
}

// File Line: 559
// RVA: 0xECB2EC
bool __fastcall OSuite::ZWebServiceClient::InternalProbeCallback(
        OSuite::ZWebServiceClient *this,
        OSuite::IHttpRequest *pHttpRequest,
        OSuite::ZHttp::EError error)
{
  bool v6; // r15
  __int64 v7; // rax
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZUrl *v10; // rax
  __int64 v11; // rax
  OSuite::TList<OSuite::OSError> *v12; // rax
  OSuite::ZObjectVtbl *vfptr; // rax
  __int64 v14; // rax
  OSuite::IReader *v15; // rax
  char v16; // bl
  OSuite::ZJsonValue *v17; // rax
  bool v18; // r14
  OSuite::ZJsonValue *v19; // rax
  OSuite::ZJsonObject *m_object; // rbx
  OSuite::ZJsonValue *v21; // rbx
  OSuite::ZHttp::EError v22; // eax
  OSuite::ZInternalWebServiceProbeDelegate *v23; // rax
  OSuite::ManagedCallback *v24; // rax
  OSuite::ManagedCallback *v25; // rbx
  OSuite::ZWorker *v26; // rax
  OSuite::ZHttpManager *v27; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::ZString sName; // [rsp+38h] [rbp-C8h] BYREF
  int v31; // [rsp+50h] [rbp-B0h]
  OSuite::ZString v32; // [rsp+58h] [rbp-A8h] BYREF
  OSuite::ZString v33; // [rsp+70h] [rbp-90h] BYREF
  OSuite::ZUrl v34; // [rsp+88h] [rbp-78h] BYREF
  OSuite::ZString v35; // [rsp+160h] [rbp+60h] BYREF
  OSuite::ZJsonDocument v36; // [rsp+178h] [rbp+78h] BYREF
  OSuite::SCallbackData cbData; // [rsp+1B0h] [rbp+B0h] BYREF

  v31 = 0;
  if ( this->m_eState == SHUTDOWN_STATE )
    return 0;
  v6 = error == HTTPERROR_OK;
  OSuite::SCallbackData::SCallbackData(&cbData);
  cbData.Status.eError = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[28].__vecDelDtor)(pHttpRequest);
  v7 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[33].__vecDelDtor)(pHttpRequest);
  cbData.Status.nHttpStatus = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 32i64))(v7);
  cbData.eEvent = 4 - (error != HTTPERROR_OK);
  v8 = OSuite::ZUrl::ToString(&this->m_baseUrl, &result, 0);
  v9 = OSuite::ZString::operator+(v8, &sName, OSuite::OS_GETSTATUS_PATH);
  v10 = OSuite::ZUrl::Parse(&v34, v9);
  OSuite::ZUrl::operator=(&cbData.URL, v10);
  OSuite::ZUrl::~ZUrl(&v34);
  OSuite::ZString::~ZString(&sName);
  OSuite::ZString::~ZString(&result);
  v11 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[33].__vecDelDtor)(pHttpRequest);
  v12 = (OSuite::TList<OSuite::OSError> *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 96i64))(v11);
  OSuite::TList<OSuite::OSError>::operator=(&cbData.OSErrors, v12);
  v35.m_pString = 0i64;
  OSuite::ZString::ZString(&v35, "0.0.0.0");
  if ( v6 )
  {
    vfptr = pHttpRequest->vfptr;
    v36.m_Pairs.m_pLists = 0i64;
    v14 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))vfptr[33].__vecDelDtor)(pHttpRequest);
    v15 = (OSuite::IReader *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 64i64))(v14);
    OSuite::ZJsonDocument::ZJsonDocument(&v36, v15);
    if ( v36.m_bIsValid )
    {
      OSuite::ZString::ZString(&sName, "d");
      v16 = 1;
      v18 = 0;
      if ( OSuite::ZJsonObject::Value(&v36, &sName) )
      {
        OSuite::ZString::ZString(&result, "d");
        v16 = 3;
        if ( OSuite::ZJsonObject::Value(&v36, &result)->m_object )
        {
          OSuite::ZString::ZString(&v33, OSuite::OS_GETSTATUS_PATH);
          OSuite::ZString::ZString(&v32, "d");
          v16 = 15;
          v17 = OSuite::ZJsonObject::Value(&v36, &v32);
          if ( OSuite::ZJsonObject::Value(v17->m_object, &v33) )
            v18 = 1;
        }
      }
      if ( (v16 & 8) != 0 )
      {
        v16 &= ~8u;
        OSuite::ZString::~ZString(&v32);
      }
      if ( (v16 & 4) != 0 )
      {
        v16 &= ~4u;
        OSuite::ZString::~ZString(&v33);
      }
      if ( (v16 & 2) != 0 )
      {
        v16 &= ~2u;
        OSuite::ZString::~ZString(&result);
      }
      if ( (v16 & 1) != 0 )
        OSuite::ZString::~ZString(&sName);
      if ( v18 )
      {
        OSuite::ZString::ZString(&result, OSuite::OS_GETSTATUS_PATH);
        OSuite::ZString::ZString(&sName, "d");
        v19 = OSuite::ZJsonObject::Value(&v36, &sName);
        m_object = OSuite::ZJsonObject::Value(v19->m_object, &result)->m_object;
        OSuite::ZString::~ZString(&sName);
        OSuite::ZString::~ZString(&result);
        if ( m_object )
        {
          OSuite::ZString::ZString(&v33, "ClientIP");
          v21 = OSuite::ZJsonObject::Value(m_object, &v33);
          OSuite::ZString::~ZString(&v33);
          if ( v21 )
          {
            if ( OSuite::ZString::operator bool(&v21->m_literal) )
              OSuite::ZString::operator=(&v35, &v21->m_literal);
          }
        }
      }
    }
    else
    {
      pHttpRequest->vfptr[40].__vecDelDtor(pHttpRequest, 3u);
      v22 = ((unsigned int (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[28].__vecDelDtor)(pHttpRequest);
      OSuite::ZHttpUtils::AnalyzeError(&cbData, pHttpRequest, v22);
    }
    OSuite::ZJsonDocument::~ZJsonDocument(&v36);
  }
  if ( this->m_clientProbeDelegate.m_Closure.m_pthis || this->m_clientProbeDelegate.m_Closure.m_pFunction )
  {
    v23 = (OSuite::ZInternalWebServiceProbeDelegate *)OSuite::ZObject::operator new(0x148ui64);
    if ( v23 )
    {
      v23->m_delegate.m_Closure.m_pthis = 0i64;
      v23->m_sClientIP.m_pString = 0i64;
      v32.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)this->m_clientProbeDelegate.m_Closure.m_pFunction;
      v32.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)this->m_clientProbeDelegate.m_Closure.m_pthis;
      OSuite::ZInternalWebServiceProbeDelegate::ZInternalWebServiceProbeDelegate(
        v23,
        (OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,char const *,void> *)&v32,
        &cbData,
        &v35);
      v25 = v24;
    }
    else
    {
      v25 = 0i64;
    }
    v26 = OSuite::ZWorker::Instance();
    OSuite::ZWorker::AddCallback(v26, v25);
  }
  this->m_pProbeRequest = 0i64;
  v27 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::ZHttpRequestManager::ReleaseHttpRequest(v27->m_httpRequestManager, pHttpRequest);
  OSuite::ZString::~ZString(&v35);
  OSuite::SCallbackData::~SCallbackData(&cbData);
  return v6;
}

// File Line: 620
// RVA: 0xECB84C
void __fastcall OSuite::ZWebServiceClient::InvokeExternalRequestCallback(
        OSuite::ZWebServiceClient *this,
        OSuite::SCallbackData *pData)
{
  OSuite::ZString *v4; // rbx
  OSuite::ZString *v5; // rax
  OSuite::ZString *v6; // rax
  unsigned __int64 v7; // rbx
  OSuite::ZString *v8; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pElement; // rdi
  OSuite::ZInternalWebServiceDelegate *v10; // rax
  OSuite::ManagedCallback *v11; // rax
  OSuite::ManagedCallback *v12; // rdi
  OSuite::ZWorker *v13; // rax
  OSuite::ZString v14; // [rsp+20h] [rbp-A9h] BYREF
  OSuite::ZString result; // [rsp+38h] [rbp-91h] BYREF
  OSuite::ZString key; // [rsp+50h] [rbp-79h] BYREF
  OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> >::ZIterator v17; // [rsp+70h] [rbp-59h] BYREF

  v4 = OSuite::ZUrl::ToString(&this->m_baseUrl, &result, 0);
  v5 = OSuite::ZUrl::ToString(&pData->URL, &v14, 0);
  OSuite::ZString::StartsWith(v5, v4);
  OSuite::ZString::~ZString(&v14);
  OSuite::ZString::~ZString(&result);
  key.m_pString = 0i64;
  v6 = OSuite::ZUrl::ToString(&this->m_baseUrl, &v14, 0);
  v7 = OSuite::ZString::Count(v6);
  v8 = OSuite::ZUrl::ToString(&pData->URL, &result, 0);
  OSuite::ZString::Slice(v8, &key, v7);
  OSuite::ZString::~ZString(&result);
  OSuite::ZString::~ZString(&v14);
  OSuite::ZMutex::Lock(&this->m_requestDelegatesMutex);
  v17.m_pMap = 0i64;
  v17.m_iterator.m_iterator.m_pList = 0i64;
  v17.m_iterator.m_iterator.m_pElement = 0i64;
  v17.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::Find(
    &this->m_clientRequestDelegates,
    &v17,
    &key);
  if ( !OSuite::ZString::IsNull((OSuite::ZString *)&v17.m_iterator.m_iterator) )
  {
    m_pElement = v17.m_iterator.m_iterator.m_pElement;
    if ( v17.m_iterator.m_iterator.m_pElement[2].vfptr || v17.m_iterator.m_iterator.m_pElement[2].m_pLeft )
    {
      v10 = (OSuite::ZInternalWebServiceDelegate *)OSuite::ZObject::operator new(0x138ui64);
      if ( v10 )
      {
        v10->m_delegate.m_Closure.m_pthis = 0i64;
        v10->m_pWebServiceClient = 0i64;
        v14.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)m_pElement[2].m_pLeft;
        v14.OSuite::ZObject::vfptr = m_pElement[2].vfptr;
        OSuite::ZInternalWebServiceDelegate::ZInternalWebServiceDelegate(
          v10,
          this,
          (OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *)&v14,
          pData);
        v12 = v11;
      }
      else
      {
        v12 = 0i64;
      }
      v13 = OSuite::ZWorker::Instance();
      OSuite::ZWorker::AddCallback(v13, v12);
    }
    OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::ZIterator::Remove((OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *)&v17);
  }
  v17.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  v17.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  v17.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  v17.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v17.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( v17.m_iterator.m_iterator.m_parents.m_pList )
    v17.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(v17.m_iterator.m_iterator.m_parents.m_pList, 1u);
  OSuite::ZMutex::Unlock(&this->m_requestDelegatesMutex);
  OSuite::ZString::~ZString(&key);
}

// File Line: 642
// RVA: 0xECB6F4
void __fastcall OSuite::ZWebServiceClient::InternalProbeResultCallback(
        OSuite::ZWebServiceClient *this,
        OSuite::SCallbackData *pData,
        const char *ipAddress)
{
  OSuite::ZString *v4; // rax
  OSuite::ZString *v5; // rax
  OSuite::ZUrl *v6; // rax
  OSuite::ZString sPublicIpAddress; // [rsp+30h] [rbp-D0h] BYREF
  OSuite::ZString httpMethod; // [rsp+48h] [rbp-B8h] BYREF
  OSuite::ZString format; // [rsp+60h] [rbp-A0h] BYREF
  OSuite::ZString v10; // [rsp+78h] [rbp-88h] BYREF
  OSuite::ZString result; // [rsp+90h] [rbp-70h] BYREF
  OSuite::ZUrl v12; // [rsp+A8h] [rbp-58h] BYREF

  if ( pData->Status.eError )
  {
    this->m_eState = ERROR_STATE;
    OSuite::ZWebServiceClient::InvokeExternalRequestCallback(this, pData);
    OSuite::ZMutex::Lock(&this->m_requestDelegatesMutex);
    OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::Clear(&this->m_clientRequestDelegates);
    OSuite::ZMutex::Unlock(&this->m_requestDelegatesMutex);
  }
  else
  {
    OSuite::ZString::ZString(&sPublicIpAddress, ipAddress);
    OSuite::ZWebServiceClient::SetPublicIpAddress(this, &sPublicIpAddress);
    OSuite::ZString::~ZString(&sPublicIpAddress);
    OSuite::ZString::ZString(&httpMethod, "GET");
    OSuite::ZString::ZString(&format, "application/json");
    sPublicIpAddress.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)OSuite::ZWebServiceClient::InternalMetadataCallback;
    sPublicIpAddress.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)this;
    v4 = OSuite::ZUrl::ToString(&this->m_baseUrl, &result, 0);
    v5 = OSuite::ZString::operator+(v4, &v10, OSuite::ZWebServiceClient::METADATA_PATH);
    v6 = OSuite::ZUrl::Parse(&v12, v5);
    OSuite::ZAtomCache::Open<OSuite::ZOMetadata>(
      this->m_pCache,
      v6,
      (OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *)&sPublicIpAddress,
      &format,
      &httpMethod);
    OSuite::ZUrl::~ZUrl(&v12);
    OSuite::ZString::~ZString(&v10);
    OSuite::ZString::~ZString(&result);
    OSuite::ZString::~ZString(&format);
    OSuite::ZString::~ZString(&httpMethod);
  }
}

// File Line: 662
// RVA: 0xECBE20
void __fastcall OSuite::ZWebServiceClient::ProcessPath(
        OSuite::ZWebServiceClient *this,
        OSuite::ZUrl *url,
        OSuite::ZString *path)
{
  OSuite::ZString *v5; // rax
  OSuite::ZUrl *v6; // rax
  OSuite::ZUrl *v7; // rax
  unsigned __int64 v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZString v10; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::ZUrl v11; // [rsp+38h] [rbp-C8h] BYREF
  OSuite::ZString result; // [rsp+110h] [rbp+10h] BYREF
  OSuite::ZString v13; // [rsp+128h] [rbp+28h] BYREF

  result.m_pString = 0i64;
  OSuite::ZUrl::ToString(&this->m_baseUrl, &result, 0);
  if ( OSuite::ZString::StartsWith(path, &result) )
  {
    v7 = OSuite::ZUrl::Parse(&v11, path);
    OSuite::ZUrl::operator=(url, v7);
    OSuite::ZUrl::~ZUrl(&v11);
  }
  else
  {
    v5 = OSuite::ZString::operator+(&result, &v10, path);
    v6 = OSuite::ZUrl::Parse(&v11, v5);
    OSuite::ZUrl::operator=(url, v6);
    OSuite::ZUrl::~ZUrl(&v11);
    OSuite::ZString::~ZString(&v10);
  }
  v13.m_pString = 0i64;
  OSuite::ZUrl::ToString(url, &v13, 0);
  v8 = OSuite::ZString::Count(&result);
  v9 = OSuite::ZString::Slice(&v13, &v10, v8);
  OSuite::ZString::operator=(path, v9);
  OSuite::ZString::~ZString(&v10);
  OSuite::ZString::~ZString(&v13);
  OSuite::ZString::~ZString(&result);
}

// File Line: 689
// RVA: 0xECC248
void __fastcall OSuite::ZWebServiceClient::SetPublicIpAddress(
        OSuite::ZWebServiceClient *this,
        OSuite::ZString *sPublicIpAddress)
{
  unsigned __int64 v4; // rbx
  char *v5; // rax
  size_t v6; // rbx
  const char *v7; // rax

  if ( !this->m_pszPublicIpAddress )
  {
    v4 = OSuite::ZString::Count(sPublicIpAddress);
    v5 = (char *)OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, v4 + 1, 0i64);
    this->m_pszPublicIpAddress = v5;
    memset(v5, 0, v4 + 1);
    v6 = OSuite::ZString::Count(sPublicIpAddress);
    v7 = OSuite::ZString::c_str(sPublicIpAddress);
    strncpy(this->m_pszPublicIpAddress, v7, v6);
    this->m_pszPublicIpAddress[OSuite::ZString::Count(sPublicIpAddress)] = 0;
  }
}


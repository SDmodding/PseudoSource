// File Line: 45
// RVA: 0xEC9A4C
void __fastcall OSuite::ZInternalWebServiceDelegate::ZInternalWebServiceDelegate(OSuite::ZInternalWebServiceDelegate *this, OSuite::ZWebServiceClient *pWebServiceClient, OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *requestDelegate, OSuite::SCallbackData *status)
{
  OSuite::ZWebServiceClient *v4; // rsi
  OSuite::ZInternalWebServiceDelegate *v5; // r14
  OSuite::ZUrl *v6; // rcx
  OSuite::SCallbackData *v7; // rbx
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *v8; // rdi

  v4 = pWebServiceClient;
  v5 = this;
  this->vfptr = (OSuite::ICallback<void,void>Vtbl *)&OSuite::ZInternalWebServiceDelegate::`vftable{for `OSuite::ICallback<void,void>};
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZInternalWebServiceDelegate::`vftable{for `OSuite::ZObject};
  v6 = &this->m_Status.URL;
  v6[-1].m_urlParameters.m_arrayParameters.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)status->Status;
  v7 = status;
  v6[-1].m_nPort = status->eEvent;
  v8 = requestDelegate;
  OSuite::ZUrl::ZUrl(v6, &status->URL);
  OSuite::TList<OSuite::OSError>::TList<OSuite::OSError>(&v5->m_Status.OSErrors, &v7->OSErrors);
  v5->m_delegate.m_Closure.m_pthis = 0i64;
  v5->m_delegate.m_Closure.m_pFunction = 0i64;
  v5->m_delegate.m_Closure.m_pFunction = v8->m_Closure.m_pFunction;
  v5->m_delegate.m_Closure.m_pthis = v8->m_Closure.m_pthis;
  v5->m_pWebServiceClient = v4;
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
void __fastcall OSuite::ZInternalWebServiceProbeDelegate::ZInternalWebServiceProbeDelegate(OSuite::ZInternalWebServiceProbeDelegate *this, OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,char const *,void> *probeDelegate, OSuite::SCallbackData *status, OSuite::ZString *clientIpAddress)
{
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,char const *,void> *v4; // rdi
  OSuite::ZInternalWebServiceProbeDelegate *v5; // rsi
  OSuite::ZUrl *v6; // rcx
  OSuite::ZString *v7; // rbp
  OSuite::SCallbackData *v8; // rbx

  v4 = probeDelegate;
  v5 = this;
  this->vfptr = (OSuite::ICallback<void,void>Vtbl *)&OSuite::ZInternalWebServiceProbeDelegate::`vftable{for `OSuite::ICallback<void,void>};
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZInternalWebServiceProbeDelegate::`vftable{for `OSuite::ZObject};
  v6 = &this->m_Status.URL;
  v6[-1].m_urlParameters.m_arrayParameters.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)status->Status;
  v7 = clientIpAddress;
  v6[-1].m_nPort = status->eEvent;
  v8 = status;
  OSuite::ZUrl::ZUrl(v6, &status->URL);
  OSuite::TList<OSuite::OSError>::TList<OSuite::OSError>(&v5->m_Status.OSErrors, &v8->OSErrors);
  v5->m_delegate.m_Closure.m_pthis = 0i64;
  v5->m_delegate.m_Closure.m_pFunction = 0i64;
  v5->m_delegate.m_Closure.m_pFunction = v4->m_Closure.m_pFunction;
  v5->m_delegate.m_Closure.m_pthis = v4->m_Closure.m_pthis;
  OSuite::ZString::ZString(&v5->m_sClientIP, v7);
}

// File Line: 65
// RVA: 0xECA158
void __fastcall OSuite::ZInternalWebServiceProbeDelegate::Call(OSuite::ZInternalWebServiceProbeDelegate *this)
{
  OSuite::ZInternalWebServiceProbeDelegate *v1; // rbx
  const char *v2; // rax

  v1 = this;
  v2 = OSuite::ZString::c_str(&this->m_sClientIP);
  ((void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *, OSuite::SCallbackData *, const char *))v1->m_delegate.m_Closure.m_pFunction)(
    v1->m_delegate.m_Closure.m_pthis,
    &v1->m_Status,
    v2);
}

// File Line: 82
// RVA: 0xEC9BA8
void __fastcall OSuite::ZWebServiceClient::ZWebServiceClient(OSuite::ZWebServiceClient *this, OSuite::ZUrl *baseUrl)
{
  OSuite::ZAtomCache *v2; // rbx
  OSuite::ZWebServiceClient *v3; // rdi
  OSuite::ZUrl *v4; // rsi
  OSuite::ZAtomCache *v5; // rax
  OSuite::ZAtomCache *v6; // rax
  OSuite::ZUsageTrackingManager *v7; // rbx
  OSuite::ZString *v8; // rax
  const char *v9; // rax

  v2 = 0i64;
  v3 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWebServiceClient::`vftable;
  this->m_eState = 0;
  this->m_pCache = 0i64;
  this->m_pMetricAppender = 0i64;
  this->m_pUsageStatisticsMetricAppender = 0i64;
  this->m_pPriorityMetricAppender = 0i64;
  this->m_pUsageTracker = 0i64;
  this->m_pMetadata = 0i64;
  this->m_pProbeRequest = 0i64;
  this->m_LastProbeTime = 0i64;
  v4 = baseUrl;
  OSuite::ZUrl::ZUrl(&this->m_baseUrl, baseUrl);
  OSuite::ZMutex::ZMutex(&v3->m_requestDelegatesMutex);
  OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>(
    &v3->m_clientRequestDelegates,
    0x10ui64);
  v3->m_clientProbeDelegate.m_Closure.m_pthis = 0i64;
  v3->m_clientProbeDelegate.m_Closure.m_pFunction = 0i64;
  v3->m_pszPublicIpAddress = 0i64;
  v5 = (OSuite::ZAtomCache *)OSuite::ZObject::operator new(0x48ui64);
  if ( v5 )
  {
    v5->m_Objects.m_pTop = 0i64;
    v5->m_Mutex.m_pInternalMutex = 0i64;
    OSuite::ZAtomCache::ZAtomCache(v5);
    v2 = v6;
  }
  v3->m_pCache = v2;
  v7 = OSuite::TSingleton<OSuite::ZUsageTrackingManager>::Object();
  v8 = OSuite::IOnlineAuthentication::GetTicketData(v4);
  v9 = OSuite::ZString::c_str(v8);
  v3->m_pUsageTracker = OSuite::ZUsageTrackingManager::CreateForHost(v7, v9);
}

// File Line: 96
// RVA: 0xECAE4C
bool __fastcall OSuite::ZWebServiceClient::Initialize(OSuite::ZWebServiceClient *this, OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *cb)
{
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *v2; // r14
  OSuite::ZWebServiceClient *v3; // rbp
  OSuite::ZMutex *v4; // rbx
  OSuite::ZString key; // [rsp+20h] [rbp-28h]

  v2 = cb;
  v3 = this;
  if ( !this->m_pMetadata )
  {
    v4 = &this->m_requestDelegatesMutex;
    OSuite::ZMutex::Lock(&this->m_requestDelegatesMutex);
    OSuite::ZString::ZString(&key, OSuite::OS_GETSTATUS_PATH);
    OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::Insert(
      &v3->m_clientRequestDelegates,
      &key,
      v2);
    OSuite::ZString::~ZString(&key);
    OSuite::ZString::ZString(&key, OSuite::ZWebServiceClient::METADATA_PATH);
    OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::Insert(
      &v3->m_clientRequestDelegates,
      &key,
      v2);
    OSuite::ZString::~ZString(&key);
    OSuite::ZMutex::Unlock(v4);
    key.vfptr = (OSuite::IHashableVtbl *)OSuite::ZWebServiceClient::InternalProbeResultCallback;
    key.vfptr = (OSuite::ZObjectVtbl *)v3;
    OSuite::ZWebServiceClient::ProbeAvailability(
      v3,
      (OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,char const *,void> *)&key);
  }
  return v3->m_pMetadata != 0i64;
}

// File Line: 115
// RVA: 0xECC134
void __fastcall OSuite::ZWebServiceClient::Release(OSuite::ZWebServiceClient *this)
{
  OSuite::ZWebServiceClient *v1; // rbx
  OSuite::ZOnlineSuite *v2; // rax

  v1 = this;
  v2 = OSuite::ZOnlineSuite::Instance();
  OSuite::ZOnlineSuite::Release(v2, v1);
}

// File Line: 121
// RVA: 0xEC9C84
void __fastcall OSuite::ZWebServiceClient::~ZWebServiceClient(OSuite::ZWebServiceClient *this)
{
  bool v1; // zf
  OSuite::ZWebServiceClient *v2; // rbx
  OSuite::ZHttpManager *v3; // rax
  OSuite::ZAtomCache *v4; // rcx
  OSuite::ZMetricAppender *v5; // rcx
  OSuite::ZMetricAppender *v6; // rcx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> > *v7; // rcx

  v1 = this->m_pProbeRequest == 0i64;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWebServiceClient::`vftable;
  this->m_eState = 3;
  if ( !v1 )
  {
    v3 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpRequestManager::ShutdownHttpRequest(v3->m_httpRequestManager, v2->m_pProbeRequest);
    v2->m_pProbeRequest = 0i64;
  }
  v4 = v2->m_pCache;
  if ( v4 )
  {
    v4->vfptr->__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 1u);
    v2->m_pCache = 0i64;
  }
  v2->m_pMetadata = 0i64;
  if ( v2->m_pUsageStatisticsMetricAppender )
  {
    OSuitePrivate::ZPlayerConsumableData::SetConsumablesData(v2->m_pUsageTracker, 0i64);
    OSuite::ZMetricAppender::ReleaseAppender(v2->m_pUsageStatisticsMetricAppender);
    v2->m_pUsageStatisticsMetricAppender = 0i64;
  }
  v5 = v2->m_pPriorityMetricAppender;
  if ( v5 )
  {
    OSuite::ZMetricAppender::ReleaseAppender(v5);
    v2->m_pPriorityMetricAppender = 0i64;
  }
  v6 = v2->m_pMetricAppender;
  if ( v6 )
  {
    OSuite::ZMetricAppender::ReleaseAppender(v6);
    v2->m_pMetricAppender = 0i64;
  }
  OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, v2->m_pszPublicIpAddress);
  v2->m_pszPublicIpAddress = 0i64;
  v7 = v2->m_clientRequestDelegates.m_pLists;
  v2->m_clientRequestDelegates.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  if ( v7 )
  {
    if ( LODWORD(v7[-1].m_Comparer.vfptr) )
      v7->vfptr->__vecDelDtor((OSuite::ZObject *)&v7->vfptr, 3u);
    else
      Illusion::ShaderParam::operator delete(&v7[-1].m_Comparer.vfptr);
  }
  OSuite::ZMutex::~ZMutex(&v2->m_requestDelegatesMutex);
  OSuite::ZUrl::~ZUrl(&v2->m_baseUrl);
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
bool __fastcall OSuite::ZWebServiceClient::ExecuteQuery(OSuite::ZWebServiceClient *this, OSuite::ZOQuery *query, OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *cb)
{
  OSuite::ZWebServiceClient *v3; // r15
  OSuite::ZOMetadata *v4; // rcx
  bool v5; // si
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *v6; // r14
  OSuite::ZOQuery *v7; // rbx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *v8; // rax
  OSuite::ZString *v9; // rbx
  const char *v10; // rdi
  const char *v11; // rax
  const char *i; // rdx
  OSuite::ZString *v13; // rbx
  OSuite::ZString *v14; // rax
  const char *v15; // rax
  bool v16; // bl
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *v18; // rax
  const char *v19; // rax
  OSuite::ZString *v20; // rax
  const char *v21; // rax
  const char *v22; // rax
  OSuite::ZString *v23; // rax
  const char *v24; // rax
  OSuite::ZOEdmFunctionImport::ZReturnType v25; // edx
  OSuite::ZString *v26; // rcx
  const char *v27; // rbx
  const char *v28; // rax
  bool v29; // al
  OSuite::fastdelegate::detail::GenericClass *v30; // rcx
  const char *v31; // rbx
  const char *v32; // rax
  const char *v33; // rbx
  const char *v34; // rax
  OSuite::fastdelegate::detail::GenericClass *v35; // rcx
  OSuite::ZOEdmFunctionImport *v36; // [rsp+20h] [rbp-E0h]
  OSuite::SFunctionParameter *v37; // [rsp+28h] [rbp-D8h]
  OSuite::SFunctionParameter *v38; // [rsp+28h] [rbp-D8h]
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *v39; // [rsp+30h] [rbp-D0h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+38h] [rbp-C8h]
  OSuite::ZString paramValue; // [rsp+B8h] [rbp-48h]
  void **v42; // [rsp+D0h] [rbp-30h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator v43; // [rsp+D8h] [rbp-28h]
  OSuite::ZStringBuilder v44; // [rsp+160h] [rbp+60h]
  OSuite::ZString v45; // [rsp+190h] [rbp+90h]
  OSuite::ZStringBuilder v46; // [rsp+1A8h] [rbp+A8h]
  OSuite::SCallbackData v47; // [rsp+1E0h] [rbp+E0h]
  OSuite::SCallbackData v48; // [rsp+2F0h] [rbp+1F0h]

  v3 = this;
  v4 = this->m_pMetadata;
  v5 = 0;
  v6 = cb;
  v39 = cb;
  v7 = query;
  if ( !v4 )
    goto LABEL_35;
  if ( query->m_eMode != 1 )
  {
    if ( query->m_eMode != 2 )
      goto LABEL_35;
    v36 = OSuite::ZOMetadata::FunctionImport(v4, &query->m_entityName);
    if ( !v36 )
      goto LABEL_35;
    v46.m_Chars.m_pList = 0i64;
    OSuite::ZStringBuilder::ZStringBuilder(&v46, 0x100ui64);
    OSuite::ZStringBuilder::Append(&v46, &v7->m_entityName);
    if ( v7->m_functionParameters.m_nCount > 0 )
    {
      v43.m_pMap = 0i64;
      v43.m_iterator.m_iterator.m_parents.m_pList = 0i64;
      _mm_store_si128((__m128i *)&v43.m_iterator.m_iterator.m_pList, (__m128i)0i64);
      v18 = OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
              (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&v7->m_functionParameters,
              &result);
      v42 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
      v43.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
      v43.m_pMap = v18->m_pMap;
      v43.m_iCurrentHash = v18->m_iCurrentHash;
      v43.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
      OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
        (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v43.m_iterator.m_iterator.vfptr,
        (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v18->m_iterator.m_iterator.vfptr);
      result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
      result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
      result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
      v43.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
      result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
      result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
      if ( result.m_iterator.m_iterator.m_parents.m_pList )
        result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
          (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
          1u);
      v37 = OSuite::ZOEdmFunctionImport::Parameter(
              v36,
              (OSuite::ZString *)&v43.m_iterator.m_iterator.m_pElement[1].m_pLeft);
      if ( !v37 )
      {
        OSuite::SCallbackData::SCallbackData(&v47);
        v30 = v6->m_Closure.m_pthis;
        v47.Status.eError = 13;
        v47.Status.nHttpStatus = 404;
        ((void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *, OSuite::SCallbackData *, OSuite::ZWebServiceClient *))v6->m_Closure.m_pFunction)(
          v30,
          &v47,
          v3);
        OSuite::SCallbackData::~SCallbackData(&v47);
        v42 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
        v43.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
        v43.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
        v43.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
        v43.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
        v43.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
        if ( v43.m_iterator.m_iterator.m_parents.m_pList )
          v43.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
            (OSuite::ZObject *)v43.m_iterator.m_iterator.m_parents.m_pList,
            1u);
        goto LABEL_34;
      }
      paramValue.m_pString = 0i64;
      v19 = OSuite::ZString::c_str((OSuite::ZString *)&v43.m_iterator.m_iterator.m_pElement[2]);
      OSuite::ZOQuery::SanitizeString(v7, &paramValue, v19, 0);
      v20 = OSuite::SFunctionParameter::ToString(v37, (OSuite::ZString *)&v44, &paramValue);
      v21 = OSuite::ZString::c_str(v20);
      OSuite::ZStringBuilder::AppendFormat(&v46, "?%s", v21);
      OSuite::ZString::~ZString((OSuite::ZString *)&v44);
      OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&v43);
      OSuite::ZString::~ZString(&paramValue);
      if ( !OSuite::ZString::IsNull((OSuite::ZString *)&v43.m_iterator.m_iterator) )
      {
        do
        {
          v38 = OSuite::ZOEdmFunctionImport::Parameter(
                  v36,
                  (OSuite::ZString *)&v43.m_iterator.m_iterator.m_pElement[1].m_pLeft);
          if ( v38 )
          {
            paramValue.m_pString = 0i64;
            v22 = OSuite::ZString::c_str((OSuite::ZString *)&v43.m_iterator.m_iterator.m_pElement[2]);
            OSuite::ZOQuery::SanitizeString(v7, &paramValue, v22, 0);
            v23 = OSuite::SFunctionParameter::ToString(v38, (OSuite::ZString *)&v44, &paramValue);
            v24 = OSuite::ZString::c_str(v23);
            OSuite::ZStringBuilder::AppendFormat(&v46, "&%s", v24);
            OSuite::ZString::~ZString((OSuite::ZString *)&v44);
            OSuite::ZString::~ZString(&paramValue);
          }
          OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&v43);
        }
        while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v43.m_iterator.m_iterator) );
        v6 = v39;
      }
      v43.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
      v42 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
      v43.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
      v43.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
      v43.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
      v43.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
      if ( v43.m_iterator.m_iterator.m_parents.m_pList )
        v43.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
          (OSuite::ZObject *)v43.m_iterator.m_iterator.m_parents.m_pList,
          1u);
    }
    v45.m_pString = 0i64;
    OSuite::ZStringBuilder::ToString(&v46, &v45);
    v25 = v36->m_ReturnType;
    v26 = &v36->m_HttpMethod;
    if ( v25 )
    {
      if ( v25 == 1 )
      {
        v31 = OSuite::ZString::c_str(v26);
        v32 = OSuite::ZString::c_str(&v45);
        v29 = OSuite::ZWebServiceClient::Request<OSuite::ZOEntry>(v3, v32, v6, v31);
      }
      else
      {
        v33 = OSuite::ZString::c_str(v26);
        v34 = OSuite::ZString::c_str(&v45);
        v29 = OSuite::ZWebServiceClient::Request<OSuite::ZOServiceOperationResult>(v3, v34, v6, v33);
      }
    }
    else
    {
      v27 = OSuite::ZString::c_str(v26);
      v28 = OSuite::ZString::c_str(&v45);
      v29 = OSuite::ZWebServiceClient::Request<OSuite::ZOFeed>(v3, v28, v6, v27);
    }
    v5 = v29;
    OSuite::ZString::~ZString(&v45);
LABEL_34:
    OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v46);
    return v5;
  }
  if ( !OSuite::ZOMetadata::EntitySet(v4, &query->m_entityName) )
  {
LABEL_35:
    OSuite::SCallbackData::SCallbackData(&v48);
    v35 = v6->m_Closure.m_pthis;
    v48.Status.eError = 13;
    v48.Status.nHttpStatus = 404;
    ((void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *, OSuite::SCallbackData *, OSuite::ZWebServiceClient *))v6->m_Closure.m_pFunction)(
      v35,
      &v48,
      v3);
    OSuite::SCallbackData::~SCallbackData(&v48);
    return 0;
  }
  v44.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v44, 0x100ui64);
  OSuite::ZStringBuilder::Append(&v44, &v7->m_entityName);
  if ( v7->m_queryMap.m_nCount > 0 )
  {
    OSuite::ZStringBuilder::Append(&v44, "?");
    _mm_store_si128((__m128i *)&v43.m_iterator.m_iterator.m_pList, (__m128i)0i64);
    v43.m_pMap = 0i64;
    v43.m_iterator.m_iterator.m_parents.m_pList = 0i64;
    v8 = OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
           (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&v7->m_queryMap,
           &result);
    v42 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
    v43.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    v43.m_pMap = v8->m_pMap;
    v43.m_iCurrentHash = v8->m_iCurrentHash;
    v43.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
      (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v43.m_iterator.m_iterator.vfptr,
      (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v8->m_iterator.m_iterator.vfptr);
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v43.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    v9 = (OSuite::ZString *)&v43.m_iterator.m_iterator.m_pElement[1].m_pLeft;
    v10 = OSuite::ZString::c_str((OSuite::ZString *)&v43.m_iterator.m_iterator.m_pElement[2]);
    v11 = OSuite::ZString::c_str(v9);
    for ( i = "%s=%s"; ; i = "&%s=%s" )
    {
      OSuite::ZStringBuilder::AppendFormat(&v44, i, v11, v10);
      OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&v43);
      if ( OSuite::ZString::IsNull((OSuite::ZString *)&v43.m_iterator.m_iterator) )
        break;
      v13 = (OSuite::ZString *)&v43.m_iterator.m_iterator.m_pElement[1].m_pLeft;
      v10 = OSuite::ZString::c_str((OSuite::ZString *)&v43.m_iterator.m_iterator.m_pElement[2]);
      v11 = OSuite::ZString::c_str(v13);
    }
    v43.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    v42 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
    v43.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v43.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    v43.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v43.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( v43.m_iterator.m_iterator.m_parents.m_pList )
      v43.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)v43.m_iterator.m_iterator.m_parents.m_pList,
        1u);
  }
  v14 = OSuite::ZStringBuilder::ToString(&v44, &paramValue);
  v15 = OSuite::ZString::c_str(v14);
  v16 = OSuite::ZWebServiceClient::Request<OSuite::ZOFeed>(v3, v15, v6, "GET");
  OSuite::ZString::~ZString(&paramValue);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v44);
  return v16;
}

// File Line: 379
// RVA: 0xECA2B0
OSuite::ZOEntry *__fastcall OSuite::ZWebServiceClient::CreateEntry(OSuite::ZWebServiceClient *this, const char *entitySetName)
{
  OSuite::ZOMetadata *v2; // rdi
  OSuite::ZOEntry *v3; // rbx
  OSuite::ZOEdmEntitySet *v4; // rsi
  OSuite::ZString setName; // [rsp+20h] [rbp-28h]

  v2 = this->m_pMetadata;
  v3 = 0i64;
  if ( v2 )
  {
    OSuite::ZString::ZString(&setName, entitySetName);
    v4 = OSuite::ZOMetadata::EntitySet(v2, &setName);
    OSuite::ZString::~ZString(&setName);
    if ( v4 )
      v3 = OSuite::ZOMetadata::CreateEntry(v2, v4);
  }
  return v3;
}

// File Line: 395
// RVA: 0xECC154
void __fastcall OSuite::ZWebServiceClient::ReleaseEntry(OSuite::ZWebServiceClient *this, OSuite::ZOEntry *pEntry)
{
  if ( pEntry )
    pEntry->vfptr->__vecDelDtor((OSuite::ZObject *)pEntry, 1u);
}

// File Line: 408
// RVA: 0xECAD78
OSuite::ZUrl *__fastcall OSuite::ZWebServiceClient::GetBaseUrl(OSuite::ZWebServiceClient *this)
{
  return &this->m_baseUrl;
}

// File Line: 413
// RVA: 0xECAD80
OSuite::ZString *__fastcall OSuite::ZWebServiceClient::GetRelativePath(OSuite::ZWebServiceClient *this, OSuite::ZString *result, OSuite::ZUrl *url)
{
  OSuite::ZString *v3; // rdi
  OSuite::ZUrl *v4; // rsi
  OSuite::ZString *v5; // rax
  bool v6; // bl
  unsigned __int64 v7; // rbx
  OSuite::ZString *v8; // rax
  OSuite::ZString v10; // [rsp+20h] [rbp-58h]
  OSuite::ZString resulta; // [rsp+38h] [rbp-40h]

  resulta.m_pString = 0i64;
  v3 = result;
  v4 = url;
  OSuite::ZUrl::ToString(&this->m_baseUrl, &resulta, 0);
  v5 = OSuite::ZUrl::ToString(v4, &v10, 0);
  v6 = OSuite::ZString::StartsWith(v5, &resulta) == 0;
  OSuite::ZString::~ZString(&v10);
  if ( v6 )
  {
    OSuite::ZString::ZString(v3, &customWorldMapCaption);
  }
  else
  {
    v7 = OSuite::ZString::Count(&resulta);
    v8 = OSuite::ZUrl::ToString(v4, &v10, 0);
    OSuite::ZString::Slice(v8, v3, v7);
    OSuite::ZString::~ZString(&v10);
  }
  OSuite::ZString::~ZString(&resulta);
  return v3;
}

// File Line: 423
// RVA: 0xECBAFC
char __fastcall OSuite::ZWebServiceClient::ProbeAvailability(OSuite::ZWebServiceClient *this, OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,char const *,void> *cb)
{
  char v2; // di
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,char const *,void> *v3; // rsi
  OSuite::ZWebServiceClient *v4; // r14
  __int64 v5; // rax
  OSuite::ZString *v6; // rax
  OSuite::ZString *v7; // rbx
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZHttpManager *v10; // rax
  OSuite::IHttpRequest *v11; // rax
  OSuite::IHttpRequest v12; // rbx
  __int64 v13; // rax
  OSuite::ZObjectVtbl *v14; // rbx
  __int64 v15; // rax
  void (__fastcall *v16)(OSuite::fastdelegate::detail::GenericClass *); // rax
  OSuite::ZObjectVtbl *v17; // rax
  OSuite::IHttpRequest *v18; // rcx
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
  OSuite::ZString v30; // [rsp+30h] [rbp-D0h]
  OSuite::ZString result; // [rsp+48h] [rbp-B8h]
  OSuite::ZString v32; // [rsp+60h] [rbp-A0h]
  int v33; // [rsp+78h] [rbp-88h]
  __int64 v34; // [rsp+80h] [rbp-80h]
  __int64 v35; // [rsp+88h] [rbp-78h]
  __int64 v36; // [rsp+90h] [rbp-70h]
  __int64 v37; // [rsp+98h] [rbp-68h]
  __int64 v38; // [rsp+A0h] [rbp-60h]
  __int64 v39; // [rsp+A8h] [rbp-58h]
  OSuite::ZWebServiceClient *v40; // [rsp+B0h] [rbp-50h]
  bool (__fastcall *v41)(OSuite::ZWebServiceClient *, OSuite::IHttpRequest *, OSuite::ZHttp::EError); // [rsp+B8h] [rbp-48h]
  char v42; // [rsp+C0h] [rbp-40h]
  OSuite::ZUrl v43; // [rsp+C8h] [rbp-38h]
  OSuite::ZUrl url; // [rsp+1A0h] [rbp+A0h]
  OSuite::SCallbackData v45; // [rsp+280h] [rbp+180h]

  v2 = 0;
  v3 = cb;
  v4 = this;
  v33 = 0;
  v5 = OSuite::ZDateTime::Current();
  if ( v3->m_Closure.m_pthis || v3->m_Closure.m_pFunction )
  {
    if ( !v4->m_pProbeRequest && v5 - v4->m_LastProbeTime >= 5 )
    {
      v4->m_LastProbeTime = v5;
      url.m_sProtocol.m_pString = 0i64;
      url.m_sHost.m_pString = 0i64;
      url.m_sFakeHost.m_pString = 0i64;
      url.m_sPath.m_pString = 0i64;
      url.m_urlParameters.m_parameters.m_pTop = 0i64;
      url.m_urlParameters.m_arrayParameters.m_pTop = 0i64;
      OSuite::ZString::ZString(&v32, OSuite::OS_GETSTATUS_PATH);
      v7 = v6;
      v8 = OSuite::ZUrl::ToString(&v4->m_baseUrl, &result, 0);
      v9 = OSuite::ZString::operator+(v8, &v30, v7);
      OSuite::ZUrl::Parse(&url, v9);
      OSuite::ZString::~ZString(&v30);
      OSuite::ZString::~ZString(&result);
      OSuite::ZString::~ZString(&v32);
      v10 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
      OSuite::ZHttpRequestManager::CreateHttpRequest(v10->m_httpRequestManager, &url, v4, 1, 30);
      v4->m_pProbeRequest = v11;
      v12.vfptr = v11->vfptr;
      OSuite::ZString::ZString(&v32, "application/json");
      v12.vfptr[36].__vecDelDtor((OSuite::ZObject *)&v4->m_pProbeRequest->vfptr, v13);
      v14 = v4->m_pProbeRequest->vfptr;
      OSuite::ZString::ZString(&v32, "GET");
      v14[44].__vecDelDtor((OSuite::ZObject *)&v4->m_pProbeRequest->vfptr, v15);
      v16 = v3->m_Closure.m_pFunction;
      v35 = 0i64;
      v4->m_clientProbeDelegate.m_Closure.m_pFunction = v16;
      v17 = (OSuite::ZObjectVtbl *)v3->m_Closure.m_pthis;
      v34 = 0i64;
      v4->m_clientProbeDelegate.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)v17;
      v18 = v4->m_pProbeRequest;
      v37 = 0i64;
      v36 = 0i64;
      v39 = 0i64;
      v38 = 0i64;
      v41 = OSuite::ZWebServiceClient::InternalProbeCallback;
      v40 = v4;
      v42 = 0;
      v18->vfptr[6].__vecDelDtor((OSuite::ZObject *)&v18->vfptr, (unsigned int)&v34);
      OSuite::ZUrl::~ZUrl(&url);
      return 1;
    }
    OSuite::SCallbackData::SCallbackData(&v45);
    v45.Status.eError = 11;
    v45.Status.nHttpStatus = 0;
    v45.eEvent = 5;
    OSuite::ZString::ZString(&result, OSuite::OS_GETSTATUS_PATH);
    v21 = v20;
    v22 = OSuite::ZUrl::ToString(&v4->m_baseUrl, &v30, 0);
    v23 = OSuite::ZString::operator+(v22, &v32, v21);
    v24 = OSuite::ZUrl::Parse(&v43, v23);
    OSuite::ZUrl::operator=(&v45.URL, v24);
    OSuite::ZUrl::~ZUrl(&v43);
    OSuite::ZString::~ZString(&v32);
    OSuite::ZString::~ZString(&v30);
    OSuite::ZString::~ZString(&result);
    v25 = (OSuite::ZInternalWebServiceProbeDelegate *)OSuite::ZObject::operator new(0x148ui64);
    v26 = v25;
    if ( v25 )
    {
      v25->m_delegate.m_Closure.m_pthis = 0i64;
      v25->m_sClientIP.m_pString = 0i64;
      OSuite::ZString::ZString(&v30, &customWorldMapCaption);
      result.vfptr = (OSuite::IHashableVtbl *)v3->m_Closure.m_pFunction;
      result.vfptr = (OSuite::ZObjectVtbl *)v3->m_Closure.m_pthis;
      v2 = 1;
      OSuite::ZInternalWebServiceProbeDelegate::ZInternalWebServiceProbeDelegate(
        v26,
        (OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,char const *,void> *)&result,
        &v45,
        &v30);
      v28 = v27;
    }
    else
    {
      v28 = 0i64;
    }
    v29 = OSuite::ZWorker::Instance();
    OSuite::ZWorker::AddCallback(v29, v28);
    if ( v2 & 1 )
      OSuite::ZString::~ZString(&v30);
    OSuite::SCallbackData::~SCallbackData(&v45);
  }
  return 0;
}

// File Line: 501
// RVA: 0xECB194
void __fastcall OSuite::ZWebServiceClient::InternalMetadataCallback(OSuite::ZWebServiceClient *this, OSuite::SCallbackData *pData)
{
  OSuite::SCallbackData *v2; // rsi
  OSuite::ZWebServiceClient *v3; // rdi
  OSuite::ZOMetadata *v4; // rax
  OSuite::ZString *v5; // rax
  const char *v6; // rax
  OSuite::ZString *v7; // rax
  const char *v8; // rax
  OSuite::ZOMetadata *v9; // rbx
  OSuite::ZOEdmClientConfiguration *v10; // rbx
  OSuite::ZString result; // [rsp+20h] [rbp-28h]

  v2 = pData;
  v3 = this;
  if ( this->m_eState != 3 )
  {
    if ( pData->Status.eError )
    {
      this->m_eState = 2;
    }
    else
    {
      v4 = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOMetadata>(
             this,
             OSuite::ZWebServiceClient::METADATA_PATH);
      v3->m_pMetadata = v4;
      if ( v4 )
      {
        v3->m_eState = 1;
        v5 = OSuite::ZUrl::ToString(&v3->m_baseUrl, &result, 0);
        v6 = OSuite::ZString::c_str(v5);
        v3->m_pMetricAppender = OSuite::ZMetricAppender::CreateAppender(v6, v3->m_pszPublicIpAddress, 0i64);
        OSuite::ZString::~ZString(&result);
        v7 = OSuite::ZUrl::ToString(&v3->m_baseUrl, &result, 0);
        v8 = OSuite::ZString::c_str(v7);
        v3->m_pUsageStatisticsMetricAppender = OSuite::ZMetricAppender::CreateAppender(
                                                 v8,
                                                 v3->m_pszPublicIpAddress,
                                                 0i64);
        OSuite::ZString::~ZString(&result);
        v3->m_pUsageStatisticsMetricAppender->m_pTransmitter->m_bUsageTracking = 0;
        OSuite::ZMetricAppender::SetDestinationTable(v3->m_pUsageStatisticsMetricAppender, "os_metrics");
        OSuitePrivate::ZPlayerConsumableData::SetConsumablesData(
          v3->m_pUsageTracker,
          v3->m_pUsageStatisticsMetricAppender);
        v9 = v3->m_pMetadata;
        if ( v9 )
        {
          v10 = v9->m_ClientConfiguration;
          if ( v10 )
          {
            v3->m_pMetricAppender->m_nTransmitMemoryThreshold = v10->m_nMetricsThreshold;
            OSuite::ZUsageTracker::SetEnabled(v3->m_pUsageTracker, v10->m_bUsageTrackingEnabled);
            OSuite::ZUsageTracker::Configure(
              v3->m_pUsageTracker,
              v10->m_nUsageTrackingSamplingInterval,
              v10->m_nUsageTrackingMetricsInterval);
          }
        }
      }
      else
      {
        v3->m_eState = 2;
      }
    }
    OSuite::ZWebServiceClient::InvokeExternalRequestCallback(v3, v2);
  }
}

// File Line: 550
// RVA: 0xECB838
void __fastcall OSuite::ZWebServiceClient::InternalRequestCallback(OSuite::ZWebServiceClient *this, OSuite::SCallbackData *pData)
{
  if ( this->m_eState != 3 )
    OSuite::ZWebServiceClient::InvokeExternalRequestCallback(this, pData);
}

// File Line: 559
// RVA: 0xECB2EC
bool __fastcall OSuite::ZWebServiceClient::InternalProbeCallback(OSuite::ZWebServiceClient *this, OSuite::IHttpRequest *pHttpRequest, OSuite::ZHttp::EError error)
{
  OSuite::ZHttp::EError v3; // ebx
  OSuite::IHttpRequest *v4; // rdi
  OSuite::ZWebServiceClient *v5; // rsi
  bool v6; // r15
  __int64 v7; // rax
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZUrl *v10; // rax
  __int64 v11; // rax
  OSuite::TList<OSuite::OSError> *v12; // rax
  OSuite::ZObjectVtbl *v13; // rax
  __int64 v14; // rax
  OSuite::IReader *v15; // rax
  char v16; // bl
  OSuite::ZJsonValue *v17; // rax
  bool v18; // r14
  OSuite::ZJsonValue *v19; // rax
  OSuite::ZJsonObject *v20; // rbx
  OSuite::ZJsonValue *v21; // rbx
  OSuite::ZHttp::EError v22; // eax
  OSuite::ZInternalWebServiceProbeDelegate *v23; // rax
  OSuite::ManagedCallback *v24; // rax
  OSuite::ManagedCallback *v25; // rbx
  OSuite::ZWorker *v26; // rax
  OSuite::ZHttpManager *v27; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-E0h]
  OSuite::ZString sName; // [rsp+38h] [rbp-C8h]
  int v31; // [rsp+50h] [rbp-B0h]
  OSuite::ZString v32; // [rsp+58h] [rbp-A8h]
  OSuite::ZString v33; // [rsp+70h] [rbp-90h]
  OSuite::ZUrl v34; // [rsp+88h] [rbp-78h]
  OSuite::ZString v35; // [rsp+160h] [rbp+60h]
  OSuite::ZJsonDocument v36; // [rsp+178h] [rbp+78h]
  OSuite::SCallbackData cbData; // [rsp+1B0h] [rbp+B0h]

  v31 = 0;
  v3 = error;
  v4 = pHttpRequest;
  v5 = this;
  if ( this->m_eState == 3 )
    return 0;
  v6 = error == 0;
  OSuite::SCallbackData::SCallbackData(&cbData);
  cbData.Status.eError = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v4->vfptr[28].__vecDelDtor)(v4);
  v7 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v4->vfptr[33].__vecDelDtor)(v4);
  cbData.Status.nHttpStatus = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 32i64))(v7);
  cbData.eEvent = 4 - (v3 != 0);
  v8 = OSuite::ZUrl::ToString(&v5->m_baseUrl, &result, 0);
  v9 = OSuite::ZString::operator+(v8, &sName, OSuite::OS_GETSTATUS_PATH);
  v10 = OSuite::ZUrl::Parse(&v34, v9);
  OSuite::ZUrl::operator=(&cbData.URL, v10);
  OSuite::ZUrl::~ZUrl(&v34);
  OSuite::ZString::~ZString(&sName);
  OSuite::ZString::~ZString(&result);
  v11 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v4->vfptr[33].__vecDelDtor)(v4);
  v12 = (OSuite::TList<OSuite::OSError> *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 96i64))(v11);
  OSuite::TList<OSuite::OSError>::operator=(&cbData.OSErrors, v12);
  v35.m_pString = 0i64;
  OSuite::ZString::ZString(&v35, "0.0.0.0");
  if ( v6 )
  {
    v13 = v4->vfptr;
    v36.m_Pairs.m_pLists = 0i64;
    v14 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v13[33].__vecDelDtor)(v4);
    v15 = (OSuite::IReader *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 64i64))(v14);
    OSuite::ZJsonDocument::ZJsonDocument(&v36, v15);
    if ( v36.m_bIsValid )
    {
      OSuite::ZString::ZString(&sName, "d");
      v16 = 1;
      v18 = 0;
      if ( OSuite::ZJsonObject::Value((OSuite::ZJsonObject *)&v36.vfptr, &sName) )
      {
        OSuite::ZString::ZString(&result, "d");
        v16 = 3;
        if ( OSuite::ZJsonObject::Value((OSuite::ZJsonObject *)&v36.vfptr, &result)->m_object )
        {
          OSuite::ZString::ZString(&v33, OSuite::OS_GETSTATUS_PATH);
          OSuite::ZString::ZString(&v32, "d");
          v16 = 15;
          v17 = OSuite::ZJsonObject::Value((OSuite::ZJsonObject *)&v36.vfptr, &v32);
          if ( OSuite::ZJsonObject::Value(v17->m_object, &v33) )
            v18 = 1;
        }
      }
      if ( v16 & 8 )
      {
        v16 &= 0xF7u;
        OSuite::ZString::~ZString(&v32);
      }
      if ( v16 & 4 )
      {
        v16 &= 0xFBu;
        OSuite::ZString::~ZString(&v33);
      }
      if ( v16 & 2 )
      {
        v16 &= 0xFDu;
        OSuite::ZString::~ZString(&result);
      }
      if ( v16 & 1 )
        OSuite::ZString::~ZString(&sName);
      if ( v18 )
      {
        OSuite::ZString::ZString(&result, OSuite::OS_GETSTATUS_PATH);
        OSuite::ZString::ZString(&sName, "d");
        v19 = OSuite::ZJsonObject::Value((OSuite::ZJsonObject *)&v36.vfptr, &sName);
        v20 = OSuite::ZJsonObject::Value(v19->m_object, &result)->m_object;
        OSuite::ZString::~ZString(&sName);
        OSuite::ZString::~ZString(&result);
        if ( v20 )
        {
          OSuite::ZString::ZString(&v33, "ClientIP");
          v21 = OSuite::ZJsonObject::Value(v20, &v33);
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
      v4->vfptr[40].__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 3u);
      v22 = ((unsigned int (__fastcall *)(OSuite::IHttpRequest *))v4->vfptr[28].__vecDelDtor)(v4);
      OSuite::ZHttpUtils::AnalyzeError(&cbData, v4, v22);
    }
    OSuite::ZJsonDocument::~ZJsonDocument(&v36);
  }
  if ( v5->m_clientProbeDelegate.m_Closure.m_pthis || v5->m_clientProbeDelegate.m_Closure.m_pFunction )
  {
    v23 = (OSuite::ZInternalWebServiceProbeDelegate *)OSuite::ZObject::operator new(0x148ui64);
    if ( v23 )
    {
      v23->m_delegate.m_Closure.m_pthis = 0i64;
      v23->m_sClientIP.m_pString = 0i64;
      v32.vfptr = (OSuite::IHashableVtbl *)v5->m_clientProbeDelegate.m_Closure.m_pFunction;
      v32.vfptr = (OSuite::ZObjectVtbl *)v5->m_clientProbeDelegate.m_Closure.m_pthis;
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
  v5->m_pProbeRequest = 0i64;
  v27 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::ZHttpRequestManager::ReleaseHttpRequest(v27->m_httpRequestManager, v4);
  OSuite::ZString::~ZString(&v35);
  OSuite::SCallbackData::~SCallbackData(&cbData);
  return v6;
}

// File Line: 620
// RVA: 0xECB84C
void __fastcall OSuite::ZWebServiceClient::InvokeExternalRequestCallback(OSuite::ZWebServiceClient *this, OSuite::SCallbackData *pData)
{
  OSuite::SCallbackData *v2; // r15
  OSuite::ZWebServiceClient *v3; // r14
  OSuite::ZString *v4; // rbx
  OSuite::ZString *v5; // rax
  OSuite::ZString *v6; // rax
  unsigned __int64 v7; // rbx
  OSuite::ZString *v8; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v9; // rdi
  OSuite::ZInternalWebServiceDelegate *v10; // rax
  OSuite::ManagedCallback *v11; // rax
  OSuite::ManagedCallback *v12; // rdi
  OSuite::ZWorker *v13; // rax
  OSuite::ZString v14; // [rsp+20h] [rbp-A9h]
  OSuite::ZString result; // [rsp+38h] [rbp-91h]
  OSuite::ZString key; // [rsp+50h] [rbp-79h]
  OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> >::ZIterator v17; // [rsp+70h] [rbp-59h]

  v2 = pData;
  v3 = this;
  v4 = OSuite::ZUrl::ToString(&this->m_baseUrl, &result, 0);
  v5 = OSuite::ZUrl::ToString(&v2->URL, &v14, 0);
  OSuite::ZString::StartsWith(v5, v4);
  OSuite::ZString::~ZString(&v14);
  OSuite::ZString::~ZString(&result);
  key.m_pString = 0i64;
  v6 = OSuite::ZUrl::ToString(&v3->m_baseUrl, &v14, 0);
  v7 = OSuite::ZString::Count(v6);
  v8 = OSuite::ZUrl::ToString(&v2->URL, &result, 0);
  OSuite::ZString::Slice(v8, &key, v7);
  OSuite::ZString::~ZString(&result);
  OSuite::ZString::~ZString(&v14);
  OSuite::ZMutex::Lock(&v3->m_requestDelegatesMutex);
  v17.m_pMap = 0i64;
  v17.m_iterator.m_iterator.m_pList = 0i64;
  v17.m_iterator.m_iterator.m_pElement = 0i64;
  v17.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::Find(
    &v3->m_clientRequestDelegates,
    &v17,
    &key);
  if ( !OSuite::ZString::IsNull((OSuite::ZString *)&v17.m_iterator.m_iterator) )
  {
    v9 = v17.m_iterator.m_iterator.m_pElement;
    if ( v17.m_iterator.m_iterator.m_pElement[2].vfptr || v17.m_iterator.m_iterator.m_pElement[2].m_pLeft )
    {
      v10 = (OSuite::ZInternalWebServiceDelegate *)OSuite::ZObject::operator new(0x138ui64);
      if ( v10 )
      {
        v10->m_delegate.m_Closure.m_pthis = 0i64;
        v10->m_pWebServiceClient = 0i64;
        v14.vfptr = (OSuite::IHashableVtbl *)v9[2].m_pLeft;
        v14.vfptr = v9[2].vfptr;
        OSuite::ZInternalWebServiceDelegate::ZInternalWebServiceDelegate(
          v10,
          v3,
          (OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *)&v14,
          v2);
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
  v17.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  v17.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  v17.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v17.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( v17.m_iterator.m_iterator.m_parents.m_pList )
    v17.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)v17.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZMutex::Unlock(&v3->m_requestDelegatesMutex);
  OSuite::ZString::~ZString(&key);
}

// File Line: 642
// RVA: 0xECB6F4
void __fastcall OSuite::ZWebServiceClient::InternalProbeResultCallback(OSuite::ZWebServiceClient *this, OSuite::SCallbackData *pData, const char *ipAddress)
{
  OSuite::ZWebServiceClient *v3; // rdi
  OSuite::ZString *v4; // rax
  OSuite::ZString *v5; // rax
  OSuite::ZUrl *v6; // rax
  OSuite::ZString sPublicIpAddress; // [rsp+30h] [rbp-D0h]
  OSuite::ZString httpMethod; // [rsp+48h] [rbp-B8h]
  OSuite::ZString format; // [rsp+60h] [rbp-A0h]
  OSuite::ZString v10; // [rsp+78h] [rbp-88h]
  OSuite::ZString result; // [rsp+90h] [rbp-70h]
  OSuite::ZUrl v12; // [rsp+A8h] [rbp-58h]

  v3 = this;
  if ( pData->Status.eError )
  {
    this->m_eState = 2;
    OSuite::ZWebServiceClient::InvokeExternalRequestCallback(this, pData);
    OSuite::ZMutex::Lock(&v3->m_requestDelegatesMutex);
    OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::Clear(&v3->m_clientRequestDelegates);
    OSuite::ZMutex::Unlock(&v3->m_requestDelegatesMutex);
  }
  else
  {
    OSuite::ZString::ZString(&sPublicIpAddress, ipAddress);
    OSuite::ZWebServiceClient::SetPublicIpAddress(v3, &sPublicIpAddress);
    OSuite::ZString::~ZString(&sPublicIpAddress);
    OSuite::ZString::ZString(&httpMethod, "GET");
    OSuite::ZString::ZString(&format, "application/json");
    sPublicIpAddress.vfptr = (OSuite::IHashableVtbl *)OSuite::ZWebServiceClient::InternalMetadataCallback;
    sPublicIpAddress.vfptr = (OSuite::ZObjectVtbl *)v3;
    v4 = OSuite::ZUrl::ToString(&v3->m_baseUrl, &result, 0);
    v5 = OSuite::ZString::operator+(v4, &v10, OSuite::ZWebServiceClient::METADATA_PATH);
    v6 = OSuite::ZUrl::Parse(&v12, v5);
    OSuite::ZAtomCache::Open<OSuite::ZOMetadata>(
      v3->m_pCache,
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
void __fastcall OSuite::ZWebServiceClient::ProcessPath(OSuite::ZWebServiceClient *this, OSuite::ZUrl *url, OSuite::ZString *path)
{
  OSuite::ZUrl *v3; // rdi
  OSuite::ZString *v4; // rbx
  OSuite::ZString *v5; // rax
  OSuite::ZUrl *v6; // rax
  OSuite::ZUrl *v7; // rax
  unsigned __int64 v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZString v10; // [rsp+20h] [rbp-E0h]
  OSuite::ZUrl v11; // [rsp+38h] [rbp-C8h]
  OSuite::ZString result; // [rsp+110h] [rbp+10h]
  OSuite::ZString v13; // [rsp+128h] [rbp+28h]

  result.m_pString = 0i64;
  v3 = url;
  v4 = path;
  OSuite::ZUrl::ToString(&this->m_baseUrl, &result, 0);
  if ( OSuite::ZString::StartsWith(v4, &result) )
  {
    v7 = OSuite::ZUrl::Parse(&v11, v4);
    OSuite::ZUrl::operator=(v3, v7);
    OSuite::ZUrl::~ZUrl(&v11);
  }
  else
  {
    v5 = OSuite::ZString::operator+(&result, &v10, v4);
    v6 = OSuite::ZUrl::Parse(&v11, v5);
    OSuite::ZUrl::operator=(v3, v6);
    OSuite::ZUrl::~ZUrl(&v11);
    OSuite::ZString::~ZString(&v10);
  }
  v13.m_pString = 0i64;
  OSuite::ZUrl::ToString(v3, &v13, 0);
  v8 = OSuite::ZString::Count(&result);
  v9 = OSuite::ZString::Slice(&v13, &v10, v8);
  OSuite::ZString::operator=(v4, v9);
  OSuite::ZString::~ZString(&v10);
  OSuite::ZString::~ZString(&v13);
  OSuite::ZString::~ZString(&result);
}

// File Line: 689
// RVA: 0xECC248
void __fastcall OSuite::ZWebServiceClient::SetPublicIpAddress(OSuite::ZWebServiceClient *this, OSuite::ZString *sPublicIpAddress)
{
  OSuite::ZString *v2; // rsi
  OSuite::ZWebServiceClient *v3; // rdi
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rbx
  char *v6; // rax
  size_t v7; // rbx
  const char *v8; // rax

  v2 = sPublicIpAddress;
  v3 = this;
  if ( !this->m_pszPublicIpAddress )
  {
    v4 = OSuite::ZString::Count(sPublicIpAddress);
    v5 = v4;
    v6 = (char *)OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, v4 + 1, 0i64);
    v3->m_pszPublicIpAddress = v6;
    memset(v6, 0, v5 + 1);
    v7 = OSuite::ZString::Count(v2);
    v8 = OSuite::ZString::c_str(v2);
    strncpy(v3->m_pszPublicIpAddress, v8, v7);
    v3->m_pszPublicIpAddress[OSuite::ZString::Count(v2)] = 0;
  }
}


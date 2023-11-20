// File Line: 20
// RVA: 0xEC2A50
void __fastcall OSuite::ZHttpTransmitter::ZHttpTransmitter(OSuite::ZHttpTransmitter *this, OSuite::ZString *sUrl)
{
  OSuite::ZString *v2; // rsi
  OSuite::ZHttpTransmitter *v3; // rdi
  OSuite::ZObject *v4; // rdx
  OSuite::IHttpRequest **v5; // rax
  bool v6; // al
  const char *v7; // r8
  OSuite::ZString *v8; // rax
  OSuite::ZUrl *v9; // rax
  OSuite::ZHttpManager *v10; // rax
  OSuite::IHttpRequest *v11; // rax
  OSuite::ZString result; // [rsp+30h] [rbp-F8h]
  OSuite::ZUrl v13; // [rsp+48h] [rbp-E0h]

  v2 = sUrl;
  v3 = this;
  OSuite::ITransmitter::ITransmitter((OSuite::ITransmitter *)&this->vfptr);
  v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpTransmitter::`vftable;
  OSuite::ZUrl::ZUrl(&v3->m_url);
  v3->m_nMaxBytesPerSecond = 0i64;
  v3->m_nRequestInProgress = 0;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v3->m_sentHttpRequest.vfptr, v4);
  v3->m_sentHttpRequest.m_pList = 0i64;
  v3->m_sentHttpRequest.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v3->m_sentHttpRequest.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v5 = (OSuite::IHttpRequest **)OSuite::ZObject::malloc((OSuite::ZObject *)&v3->m_sentHttpRequest.vfptr, 0x80ui64, 0i64);
  v3->m_sentHttpRequest.m_nTop = 0i64;
  v3->m_sentHttpRequest.m_pList = v5;
  v3->m_sentHttpRequest.m_nSize = 16i64;
  OSuite::ZMutex::ZMutex(&v3->m_mutex);
  if ( !OSuite::ZString::EndsWith(v2, "AddMetrics") )
  {
    v6 = OSuite::ZString::EndsWith(v2, "/");
    v7 = "AddMetrics";
    if ( !v6 )
      v7 = "/AddMetrics";
    v8 = OSuite::ZString::operator+(v2, &result, v7);
    v9 = OSuite::ZUrl::Parse(&v13, v8);
    OSuite::ZUrl::operator=(&v3->m_url, v9);
    OSuite::ZUrl::~ZUrl(&v13);
    OSuite::ZString::~ZString(&result);
  }
  v10 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::ZHttpRequestManager::CreateHttpRequest(v10->m_httpRequestManager, &v3->m_url, v3, 1, 30);
  v3->m_pHttpRequest = v11;
  *(_BYTE *)(((__int64 (__fastcall *)(OSuite::IHttpRequest *))v11->vfptr[31].__vecDelDtor)(v11) + 32) = 1;
}

// File Line: 40
// RVA: 0xEC2BAC
void __fastcall OSuite::ZHttpTransmitter::~ZHttpTransmitter(OSuite::ZHttpTransmitter *this)
{
  bool v1; // zf
  OSuite::ZHttpTransmitter *v2; // rdi
  OSuite::ZHttpManager *v3; // rax
  unsigned __int64 v4; // r14
  OSuite::ZListBase *v5; // rbx
  unsigned __int64 v6; // rbp
  unsigned __int64 v7; // rbx
  OSuite::ZHttpManager *v8; // rax
  OSuite::IHttpRequest **v9; // rax
  OSuite::IHttpRequest **v10; // rdx
  OSuite::ZListBase::ZListIteratorBase v11; // [rsp+20h] [rbp-38h]

  v1 = this->m_pHttpRequest == 0i64;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpTransmitter::`vftable;
  if ( !v1 )
  {
    v3 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpRequestManager::ShutdownHttpRequest(v3->m_httpRequestManager, v2->m_pHttpRequest);
    v2->m_pHttpRequest = 0i64;
  }
  v11.m_pListBase = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v11, (OSuite::ZListBase *)&v2->m_sentHttpRequest.vfptr);
  v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v11) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11.m_pListBase);
    v4 = v11.m_nIndex;
    v5 = v11.m_pListBase;
    v6 = v11.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v11.m_pListBase,
      v11.m_nIndex + 1);
    if ( v4 >= v5->m_nTop )
      v5->m_nTop = v6;
    v7 = v5[1].m_nSize;
    v8 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpRequestManager::ShutdownHttpRequest(v8->m_httpRequestManager, *(OSuite::IHttpRequest **)(v7 + 8 * v4));
    OSuite::ZListBase::ZListIteratorBase::Remove(&v11);
    --v2->m_nRequestInProgress;
  }
  OSuite::ZObject::free((OSuite::ZObject *)&v2->m_sentHttpRequest.vfptr, v2->m_sentHttpRequest.m_pList);
  v9 = (OSuite::IHttpRequest **)OSuite::ZObject::malloc((OSuite::ZObject *)&v2->m_sentHttpRequest.vfptr, 0x80ui64, 0i64);
  v2->m_sentHttpRequest.m_nTop = 0i64;
  v2->m_sentHttpRequest.m_pList = v9;
  v2->m_sentHttpRequest.m_nSize = 16i64;
  OSuite::ZMutex::~ZMutex(&v2->m_mutex);
  v10 = v2->m_sentHttpRequest.m_pList;
  v2->m_sentHttpRequest.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v2->m_sentHttpRequest.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free((OSuite::ZObject *)&v2->m_sentHttpRequest.vfptr, v10);
  OSuite::ZUrl::~ZUrl(&v2->m_url);
  OSuite::ITransmitter::~ITransmitter((OSuite::ITransmitter *)&v2->vfptr);
}

// File Line: 59
// RVA: 0xEC3104
bool __fastcall OSuite::ZHttpTransmitter::Transmit(OSuite::ZHttpTransmitter *this, OSuite::ZMetricAppender *appender)
{
  OSuite::ZHttpTransmitter *v2; // r14
  _QWORD *v3; // rax
  __int64 v4; // rax
  OSuite::IHttpRequest *v5; // rsi
  OSuite::ZHttpManager *v6; // rax
  OSuite::IHttpRequest *v7; // rax
  OSuite::ZObjectVtbl *v8; // rbx
  __int64 v9; // rax
  OSuite::ZObjectVtbl *v10; // rbx
  __int64 v11; // rax
  OSuite::ZObjectVtbl *v12; // rbx
  __int64 v13; // rax
  __int64 v14; // rax
  OSuite::ZObjectVtbl *v15; // rbx
  __int64 v16; // rax
  __int64 v17; // rdx
  OSuite::IHttpRequest v18; // rax
  __int64 v19; // rax
  OSuite::ZClock v21; // [rsp+30h] [rbp-B8h]
  unsigned __int64 clock; // [rsp+38h] [rbp-B0h]
  __int64 v23; // [rsp+40h] [rbp-A8h]
  __int64 v24; // [rsp+48h] [rbp-A0h]
  __int64 v25; // [rsp+50h] [rbp-98h]
  __int64 v26; // [rsp+58h] [rbp-90h]
  __int64 v27; // [rsp+60h] [rbp-88h]
  __int64 v28; // [rsp+68h] [rbp-80h]
  OSuite::ZString v29; // [rsp+70h] [rbp-78h]
  OSuite::ZUrl v30; // [rsp+88h] [rbp-60h]

  v2 = this;
  v3 = (_QWORD *)this->m_pHttpRequest->vfptr[31].__vecDelDtor(
                   (OSuite::ZObject *)this->m_pHttpRequest,
                   (unsigned int)appender);
  v4 = (*(__int64 (**)(void))(v3[1] + 56i64))();
  if ( v4 )
  {
    v30.m_sProtocol.m_pString = 0i64;
    v30.m_sHost.m_pString = 0i64;
    v30.m_sFakeHost.m_pString = 0i64;
    v30.m_sPath.m_pString = 0i64;
    v30.m_urlParameters.m_parameters.m_pTop = 0i64;
    v30.m_urlParameters.m_arrayParameters.m_pTop = 0i64;
    OSuite::ZUrl::ZUrl(&v30, &v2->m_url);
    v5 = v2->m_pHttpRequest;
    v6 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpRequestManager::CreateHttpRequest(v6->m_httpRequestManager, &v2->m_url, v2, 1, 30);
    v2->m_pHttpRequest = v7;
    *(_BYTE *)(((__int64 (__fastcall *)(OSuite::IHttpRequest *))v7->vfptr[31].__vecDelDtor)(v7) + 32) = 1;
    v5->vfptr[45].__vecDelDtor((OSuite::ZObject *)&v5->vfptr, (unsigned int)&v30);
    v8 = v5->vfptr;
    OSuite::ZString::ZString(&v29, "POST");
    v8[44].__vecDelDtor((OSuite::ZObject *)&v5->vfptr, v9);
    v10 = v5->vfptr;
    OSuite::ZString::ZString(&v29, "text/plain;charset=UTF-8");
    v10[41].__vecDelDtor((OSuite::ZObject *)&v5->vfptr, v11);
    v12 = v5->vfptr;
    OSuite::ZString::ZString(&v29, "*/*");
    v12[36].__vecDelDtor((OSuite::ZObject *)&v5->vfptr, v13);
    v14 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v5->vfptr[31].__vecDelDtor)(v5);
    v15 = v5->vfptr;
    v16 = (*(__int64 (**)(void))(*(_QWORD *)(v14 + 8) + 56i64))();
    v15[42].__vecDelDtor((OSuite::ZObject *)&v5->vfptr, v16);
    v5->vfptr[46].__vecDelDtor((OSuite::ZObject *)&v5->vfptr, v2->m_nMaxBytesPerSecond);
    LOBYTE(v17) = v2->m_bUsageTracking;
    v5->vfptr[39].__vecDelDtor((OSuite::ZObject *)&v5->vfptr, v17);
    ++v2->m_nRequestInProgress;
    OSuite::ZMutex::Lock(&v2->m_mutex);
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v2->m_sentHttpRequest,
      v2->m_sentHttpRequest.m_nTop + 1);
    v2->m_sentHttpRequest.m_pList[v2->m_sentHttpRequest.m_nTop++] = v5;
    OSuite::ZMutex::Unlock(&v2->m_mutex);
    v24 = 0i64;
    v29.vfptr = (OSuite::IHashableVtbl *)OSuite::ZHttpTransmitter::OnFinished;
    v18.vfptr = v5->vfptr;
    v23 = 0i64;
    v26 = 0i64;
    v25 = 0i64;
    v28 = 0i64;
    v27 = 0i64;
    v29.vfptr = (OSuite::ZObjectVtbl *)v2;
    LOBYTE(v28) = 0;
    v18.vfptr[6].__vecDelDtor((OSuite::ZObject *)&v5->vfptr, (unsigned int)&v23);
    v2->m_metricSerialized = 0i64;
    v19 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v5->vfptr[31].__vecDelDtor)(v5);
    v2->m_memorySerialized = (*(__int64 (**)(void))(*(_QWORD *)(v19 + 8) + 64i64))();
    clock = OSuite::ZClock::_GetClock();
    OSuite::ZClock::ZClock(&v21, &clock);
    v2->m_lastTransmitTime = v21;
    OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v21);
    OSuite::ZUrl::~ZUrl(&v30);
    LOBYTE(v4) = 1;
  }
  return v4;
}signed __int64)&v21);
    OSuite::ZUrl::~ZUrl(&v30);
    LOBYTE(v4) = 1;
  }
 

// File Line: 97
// RVA: 0xEC30FC
void __fastcall OSuite::ZHttpTransmitter::ThrottleBandwidth(OSuite::ZHttpTransmitter *this, unsigned __int64 nBytesPerSecond)
{
  this->m_nMaxBytesPerSecond = nBytesPerSecond;
}

// File Line: 102
// RVA: 0xEC2FC4
bool __fastcall OSuite::ZHttpTransmitter::Serialize(OSuite::ZHttpTransmitter *this, OSuite::ZMetricAppender *appender, OSuite::ZMetric *pMetric)
{
  OSuite::ZMetric *v3; // r15
  OSuite::ZMetricAppender *v4; // rbp
  OSuite::ZHttpTransmitter *v5; // r14
  __int64 v6; // rax
  __int64 v7; // rax
  OSuite::IHttpRequest *v8; // rbx
  unsigned __int64 v9; // rsi
  OSuite::ZMetricProperties *v10; // rdi
  OSuite::ZMemoryBufferChain *v11; // rax
  bool v12; // di
  __int64 v13; // rax
  OSuite::ZMetricProperties *v14; // rax
  const char *v15; // rbx
  OSuite::ZMetricProperties *v16; // rax
  bool end; // [rsp+30h] [rbp-38h]

  v3 = pMetric;
  v4 = appender;
  v5 = this;
  if ( pMetric
    || (v6 = ((__int64 (*)(void))this->m_pHttpRequest->vfptr[31].__vecDelDtor)(),
        (v7 = (*(__int64 (**)(void))(*(_QWORD *)(v6 + 8) + 56i64))()) != 0) )
  {
    v5->m_error = 0;
    v8 = v5->m_pHttpRequest;
    v9 = v4->m_nTransmitMemoryThreshold;
    end = 0;
    v10 = OSuite::ZMetricAppender::GetProperties(v4);
    v11 = (OSuite::ZMemoryBufferChain *)((__int64 (__fastcall *)(OSuite::IHttpRequest *))v8->vfptr[31].__vecDelDtor)(v8);
    v12 = OSuite::FSerialize(v11, v3, v10, v9, &end);
    v13 = ((__int64 (*)(void))v5->m_pHttpRequest->vfptr[31].__vecDelDtor)();
    v5->m_memorySerialized = (*(__int64 (**)(void))(*(_QWORD *)(v13 + 8) + 64i64))();
    if ( v12 )
    {
      ++v5->m_metricSerialized;
      if ( end )
      {
        v14 = OSuite::ZMetricAppender::GetProperties(v4);
        OSuite::ZMetricProperties::Invalidate(v14);
        v5->vfptr[1].__vecDelDtor((OSuite::ZObject *)&v5->vfptr, (unsigned int)v4);
        v15 = OSuitePrivate::Locale();
        v16 = OSuite::ZMetricAppender::GetProperties(v4);
        OSuite::ZMetricProperties::SetProperty(v16, OSuite::ZMetricAppender::RegionPropertyName, v15);
      }
    }
    else
    {
      v5->m_error = 6;
    }
    LOBYTE(v7) = v12;
  }
  return v7;
}

// File Line: 129
// RVA: 0xEC2F4C
void __fastcall OSuite::ZHttpTransmitter::Reset(OSuite::ZHttpTransmitter *this)
{
  OSuite::ZHttpTransmitter *v1; // rbx
  __int64 v2; // rax
  OSuite::IHttpRequest *v3; // rcx
  __int64 v4; // rax
  OSuite::ZClock v5; // [rsp+30h] [rbp+8h]
  unsigned __int64 clock; // [rsp+38h] [rbp+10h]

  v1 = this;
  v2 = ((__int64 (*)(void))this->m_pHttpRequest->vfptr[31].__vecDelDtor)();
  (*(void (**)(void))(*(_QWORD *)(v2 + 8) + 24i64))();
  v3 = v1->m_pHttpRequest;
  v1->m_metricSerialized = 0i64;
  v4 = ((__int64 (*)(void))v3->vfptr[31].__vecDelDtor)();
  v1->m_memorySerialized = (*(__int64 (**)(void))(*(_QWORD *)(v4 + 8) + 64i64))();
  clock = OSuite::ZClock::_GetClock();
  OSuite::ZClock::ZClock(&v5, &clock);
  v1->m_lastTransmitTime = v5;
  OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v5);
}

// File Line: 141
// RVA: 0xEC2E7C
bool __fastcall OSuite::ZHttpTransmitter::OnFinished(OSuite::ZHttpTransmitter *this, OSuite::IHttpRequest *pHttpRequest, OSuite::ZHttp::EError error)
{
  OSuite::ZHttp::EError v3; // er14
  OSuite::IHttpRequest *v4; // rbp
  OSuite::ZHttpTransmitter *v5; // rsi
  OSuite::ZError::EError v7; // eax
  unsigned __int64 v8; // rdx
  OSuite::IHttpRequest **v9; // rax
  OSuite::ZHttpManager *v10; // rax
  OSuite::ZError *v11; // rax
  OSuite::SHttpStatus result; // [rsp+20h] [rbp-28h]

  v3 = error;
  v4 = pHttpRequest;
  v5 = this;
  if ( !pHttpRequest )
    return 0;
  v7 = (unsigned int)OSuite::ZHttp::HttpToOsError(error);
  --v5->m_nRequestInProgress;
  v5->m_error = v7;
  OSuite::ZHttpUtils::GetHttpStatusFromRequest(&result, v4);
  OSuite::ZMutex::Lock(&v5->m_mutex);
  v8 = 0i64;
  if ( v5->m_sentHttpRequest.m_nTop > 0 )
  {
    v9 = v5->m_sentHttpRequest.m_pList;
    while ( *v9 != v4 )
    {
      ++v8;
      ++v9;
      if ( v8 >= v5->m_sentHttpRequest.m_nTop )
        goto LABEL_9;
    }
    v5->m_sentHttpRequest.vfptr[1].__vecDelDtor((OSuite::ZObject *)&v5->m_sentHttpRequest.vfptr, v8);
  }
LABEL_9:
  OSuite::ZMutex::Unlock(&v5->m_mutex);
  v10 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::ZHttpRequestManager::ReleaseHttpRequest(v10->m_httpRequestManager, v4);
  if ( v5->m_error )
  {
    v11 = OSuite::TSingleton<OSuite::ZError>::Object();
    OSuite::ZError::SetThreadLastError(v11, v5->m_error, 1);
  }
  return v3 != 0;
}


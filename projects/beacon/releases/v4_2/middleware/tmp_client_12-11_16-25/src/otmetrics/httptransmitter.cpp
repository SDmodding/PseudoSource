// File Line: 20
// RVA: 0xEC2A50
void __fastcall OSuite::ZHttpTransmitter::ZHttpTransmitter(OSuite::ZHttpTransmitter *this, OSuite::ZString *sUrl)
{
  OSuite::ZObject *v4; // rdx
  OSuite::IHttpRequest **v5; // rax
  bool v6; // al
  const char *v7; // r8
  OSuite::ZString *v8; // rax
  OSuite::ZUrl *v9; // rax
  OSuite::ZHttpManager *v10; // rax
  OSuite::IHttpRequest *v11; // rax
  OSuite::ZString result; // [rsp+30h] [rbp-F8h] BYREF
  OSuite::ZUrl v13; // [rsp+48h] [rbp-E0h] BYREF

  OSuite::ITransmitter::ITransmitter(this);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpTransmitter::`vftable;
  OSuite::ZUrl::ZUrl(&this->m_url);
  this->m_nMaxBytesPerSecond = 0i64;
  this->m_nRequestInProgress = 0;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_sentHttpRequest, v4);
  this->m_sentHttpRequest.m_pList = 0i64;
  this->m_sentHttpRequest.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_sentHttpRequest.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v5 = (OSuite::IHttpRequest **)OSuite::ZObject::malloc(&this->m_sentHttpRequest, 0x80ui64, 0i64);
  this->m_sentHttpRequest.m_nTop = 0i64;
  this->m_sentHttpRequest.m_pList = v5;
  this->m_sentHttpRequest.m_nSize = 16i64;
  OSuite::ZMutex::ZMutex(&this->m_mutex);
  if ( !OSuite::ZString::EndsWith(sUrl, "AddMetrics") )
  {
    v6 = OSuite::ZString::EndsWith(sUrl, "/");
    v7 = "AddMetrics";
    if ( !v6 )
      v7 = "/AddMetrics";
    v8 = OSuite::ZString::operator+(sUrl, &result, v7);
    v9 = OSuite::ZUrl::Parse(&v13, v8);
    OSuite::ZUrl::operator=(&this->m_url, v9);
    OSuite::ZUrl::~ZUrl(&v13);
    OSuite::ZString::~ZString(&result);
  }
  v10 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::ZHttpRequestManager::CreateHttpRequest(v10->m_httpRequestManager, &this->m_url, this, 1, 30);
  this->m_pHttpRequest = v11;
  *(_BYTE *)(((__int64 (__fastcall *)(OSuite::IHttpRequest *))v11->vfptr[31].__vecDelDtor)(v11) + 32) = 1;
}

// File Line: 40
// RVA: 0xEC2BAC
void __fastcall OSuite::ZHttpTransmitter::~ZHttpTransmitter(OSuite::ZHttpTransmitter *this)
{
  bool v1; // zf
  OSuite::ZHttpManager *v3; // rax
  unsigned __int64 m_nIndex; // r14
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v6; // rbp
  unsigned __int64 m_nSize; // rbx
  OSuite::ZHttpManager *v8; // rax
  OSuite::IHttpRequest **v9; // rax
  OSuite::IHttpRequest **m_pList; // rdx
  OSuite::ZListBase::ZListIteratorBase v11; // [rsp+20h] [rbp-38h] BYREF

  v1 = this->m_pHttpRequest == 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpTransmitter::`vftable;
  if ( !v1 )
  {
    v3 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpRequestManager::ShutdownHttpRequest(v3->m_httpRequestManager, this->m_pHttpRequest);
    this->m_pHttpRequest = 0i64;
  }
  v11.m_pListBase = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v11, &this->m_sentHttpRequest);
  v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v11) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11.m_pListBase);
    m_nIndex = v11.m_nIndex;
    m_pListBase = v11.m_pListBase;
    v6 = v11.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v11.m_pListBase,
      v11.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v6;
    m_nSize = m_pListBase[1].m_nSize;
    v8 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpRequestManager::ShutdownHttpRequest(
      v8->m_httpRequestManager,
      *(OSuite::IHttpRequest **)(m_nSize + 8 * m_nIndex));
    OSuite::ZListBase::ZListIteratorBase::Remove(&v11);
    --this->m_nRequestInProgress;
  }
  OSuite::ZObject::free(&this->m_sentHttpRequest, this->m_sentHttpRequest.m_pList);
  v9 = (OSuite::IHttpRequest **)OSuite::ZObject::malloc(&this->m_sentHttpRequest, 0x80ui64, 0i64);
  this->m_sentHttpRequest.m_nTop = 0i64;
  this->m_sentHttpRequest.m_pList = v9;
  this->m_sentHttpRequest.m_nSize = 16i64;
  OSuite::ZMutex::~ZMutex(&this->m_mutex);
  m_pList = this->m_sentHttpRequest.m_pList;
  this->m_sentHttpRequest.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_sentHttpRequest.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(&this->m_sentHttpRequest, m_pList);
  OSuite::ZUrl::~ZUrl(&this->m_url);
  OSuite::ITransmitter::~ITransmitter(this);
}

// File Line: 59
// RVA: 0xEC3104
bool __fastcall OSuite::ZHttpTransmitter::Transmit(OSuite::ZHttpTransmitter *this, OSuite::ZMetricAppender *appender)
{
  _QWORD *v3; // rax
  __int64 v4; // rax
  OSuite::IHttpRequest *m_pHttpRequest; // rsi
  OSuite::ZHttpManager *v6; // rax
  OSuite::IHttpRequest *v7; // rax
  OSuite::ZObjectVtbl *vfptr; // rbx
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
  OSuite::ZClock v21; // [rsp+30h] [rbp-B8h] BYREF
  unsigned __int64 clock; // [rsp+38h] [rbp-B0h] BYREF
  __int64 v23[6]; // [rsp+40h] [rbp-A8h] BYREF
  OSuite::ZString v24; // [rsp+70h] [rbp-78h] BYREF
  OSuite::ZUrl v25; // [rsp+88h] [rbp-60h] BYREF

  v3 = this->m_pHttpRequest->vfptr[31].__vecDelDtor(this->m_pHttpRequest, appender);
  v4 = (*(__int64 (__fastcall **)(_QWORD *))(v3[1] + 56i64))(v3 + 1);
  if ( v4 )
  {
    v25.m_sProtocol.m_pString = 0i64;
    v25.m_sHost.m_pString = 0i64;
    v25.m_sFakeHost.m_pString = 0i64;
    v25.m_sPath.m_pString = 0i64;
    v25.m_urlParameters.m_parameters.m_pTop = 0i64;
    v25.m_urlParameters.m_arrayParameters.m_pTop = 0i64;
    OSuite::ZUrl::ZUrl(&v25, &this->m_url);
    m_pHttpRequest = this->m_pHttpRequest;
    v6 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZHttpRequestManager::CreateHttpRequest(v6->m_httpRequestManager, &this->m_url, this, 1, 30);
    this->m_pHttpRequest = v7;
    *(_BYTE *)(((__int64 (__fastcall *)(OSuite::IHttpRequest *))v7->vfptr[31].__vecDelDtor)(v7) + 32) = 1;
    m_pHttpRequest->vfptr[45].__vecDelDtor(m_pHttpRequest, (unsigned int)&v25);
    vfptr = m_pHttpRequest->vfptr;
    OSuite::ZString::ZString(&v24, "POST");
    vfptr[44].__vecDelDtor(m_pHttpRequest, v9);
    v10 = m_pHttpRequest->vfptr;
    OSuite::ZString::ZString(&v24, "text/plain;charset=UTF-8");
    v10[41].__vecDelDtor(m_pHttpRequest, v11);
    v12 = m_pHttpRequest->vfptr;
    OSuite::ZString::ZString(&v24, "*/*");
    v12[36].__vecDelDtor(m_pHttpRequest, v13);
    v14 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))m_pHttpRequest->vfptr[31].__vecDelDtor)(m_pHttpRequest);
    v15 = m_pHttpRequest->vfptr;
    v16 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v14 + 8) + 56i64))(v14 + 8);
    v15[42].__vecDelDtor(m_pHttpRequest, v16);
    m_pHttpRequest->vfptr[46].__vecDelDtor(m_pHttpRequest, this->m_nMaxBytesPerSecond);
    LOBYTE(v17) = this->m_bUsageTracking;
    m_pHttpRequest->vfptr[39].__vecDelDtor(m_pHttpRequest, v17);
    ++this->m_nRequestInProgress;
    OSuite::ZMutex::Lock(&this->m_mutex);
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_sentHttpRequest,
      this->m_sentHttpRequest.m_nTop + 1);
    this->m_sentHttpRequest.m_pList[this->m_sentHttpRequest.m_nTop++] = m_pHttpRequest;
    OSuite::ZMutex::Unlock(&this->m_mutex);
    v24.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)OSuite::ZHttpTransmitter::OnFinished;
    v18.vfptr = m_pHttpRequest->vfptr;
    memset(v23, 0, sizeof(v23));
    v24.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)this;
    v18.vfptr[6].__vecDelDtor(m_pHttpRequest, (unsigned int)v23);
    this->m_metricSerialized = 0i64;
    v19 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))m_pHttpRequest->vfptr[31].__vecDelDtor)(m_pHttpRequest);
    this->m_memorySerialized = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v19 + 8) + 64i64))(v19 + 8);
    clock = OSuite::ZClock::_GetClock();
    OSuite::ZClock::ZClock(&v21, &clock);
    this->m_lastTransmitTime = v21;
    OSuite::ZOEdmBase::CleanTempData((int)&v21);
    OSuite::ZUrl::~ZUrl(&v25);
    LOBYTE(v4) = 1;
  }
  return v4;
}

// File Line: 97
// RVA: 0xEC30FC
void __fastcall OSuite::ZHttpTransmitter::ThrottleBandwidth(
        OSuite::ZHttpTransmitter *this,
        unsigned __int64 nBytesPerSecond)
{
  this->m_nMaxBytesPerSecond = nBytesPerSecond;
}

// File Line: 102
// RVA: 0xEC2FC4
bool __fastcall OSuite::ZHttpTransmitter::Serialize(
        OSuite::ZHttpTransmitter *this,
        OSuite::ZMetricAppender *appender,
        OSuite::ZMetric *pMetric)
{
  __int64 v6; // rax
  __int64 v7; // rax
  OSuite::IHttpRequest *m_pHttpRequest; // rbx
  unsigned __int64 m_nTransmitMemoryThreshold; // rsi
  OSuite::ZMetricProperties *Properties; // rdi
  OSuite::ZMemoryBufferChain *v11; // rax
  bool v12; // di
  __int64 v13; // rax
  OSuite::ZMetricProperties *v14; // rax
  const char *v15; // rbx
  OSuite::ZMetricProperties *v16; // rax
  bool end; // [rsp+30h] [rbp-38h] BYREF

  if ( pMetric
    || (v6 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))this->m_pHttpRequest->vfptr[31].__vecDelDtor)(this->m_pHttpRequest),
        (v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v6 + 8) + 56i64))(v6 + 8)) != 0) )
  {
    this->m_error = ZERROR_OK;
    m_pHttpRequest = this->m_pHttpRequest;
    m_nTransmitMemoryThreshold = appender->m_nTransmitMemoryThreshold;
    end = 0;
    Properties = OSuite::ZMetricAppender::GetProperties(appender);
    v11 = (OSuite::ZMemoryBufferChain *)((__int64 (__fastcall *)(OSuite::IHttpRequest *))m_pHttpRequest->vfptr[31].__vecDelDtor)(m_pHttpRequest);
    v12 = OSuite::FSerialize(v11, pMetric, Properties, m_nTransmitMemoryThreshold, &end);
    v13 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))this->m_pHttpRequest->vfptr[31].__vecDelDtor)(this->m_pHttpRequest);
    this->m_memorySerialized = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v13 + 8) + 64i64))(v13 + 8);
    if ( v12 )
    {
      ++this->m_metricSerialized;
      if ( end )
      {
        v14 = OSuite::ZMetricAppender::GetProperties(appender);
        OSuite::ZMetricProperties::Invalidate(v14);
        this->vfptr[1].__vecDelDtor(this, (unsigned int)appender);
        v15 = OSuitePrivate::Locale();
        v16 = OSuite::ZMetricAppender::GetProperties(appender);
        OSuite::ZMetricProperties::SetProperty(v16, OSuite::ZMetricAppender::RegionPropertyName, v15);
      }
    }
    else
    {
      this->m_error = ZERROR_SERIALIZATION_FAILED;
    }
    LOBYTE(v7) = v12;
  }
  return v7;
}

// File Line: 129
// RVA: 0xEC2F4C
void __fastcall OSuite::ZHttpTransmitter::Reset(OSuite::ZHttpTransmitter *this)
{
  __int64 v2; // rax
  OSuite::IHttpRequest *m_pHttpRequest; // rcx
  __int64 v4; // rax
  OSuite::ZClock v5; // [rsp+30h] [rbp+8h] BYREF
  unsigned __int64 clock; // [rsp+38h] [rbp+10h] BYREF

  v2 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))this->m_pHttpRequest->vfptr[31].__vecDelDtor)(this->m_pHttpRequest);
  (*(void (__fastcall **)(__int64))(*(_QWORD *)(v2 + 8) + 24i64))(v2 + 8);
  m_pHttpRequest = this->m_pHttpRequest;
  this->m_metricSerialized = 0i64;
  v4 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))m_pHttpRequest->vfptr[31].__vecDelDtor)(m_pHttpRequest);
  this->m_memorySerialized = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v4 + 8) + 64i64))(v4 + 8);
  clock = OSuite::ZClock::_GetClock();
  OSuite::ZClock::ZClock(&v5, &clock);
  this->m_lastTransmitTime = v5;
  OSuite::ZOEdmBase::CleanTempData((int)&v5);
}

// File Line: 141
// RVA: 0xEC2E7C
bool __fastcall OSuite::ZHttpTransmitter::OnFinished(
        OSuite::ZHttpTransmitter *this,
        OSuite::IHttpRequest *pHttpRequest,
        int error)
{
  OSuite::ZError::EError v7; // eax
  unsigned __int64 v8; // rdx
  OSuite::IHttpRequest **m_pList; // rax
  OSuite::ZHttpManager *v10; // rax
  OSuite::ZError *v11; // rax
  OSuite::SHttpStatus result; // [rsp+20h] [rbp-28h] BYREF

  if ( !pHttpRequest )
    return 0;
  v7 = (unsigned int)OSuite::ZHttp::HttpToOsError(error);
  --this->m_nRequestInProgress;
  this->m_error = v7;
  OSuite::ZHttpUtils::GetHttpStatusFromRequest(&result, pHttpRequest);
  OSuite::ZMutex::Lock(&this->m_mutex);
  v8 = 0i64;
  if ( this->m_sentHttpRequest.m_nTop )
  {
    m_pList = this->m_sentHttpRequest.m_pList;
    while ( *m_pList != pHttpRequest )
    {
      ++v8;
      ++m_pList;
      if ( v8 >= this->m_sentHttpRequest.m_nTop )
        goto LABEL_9;
    }
    this->m_sentHttpRequest.vfptr[1].__vecDelDtor(&this->m_sentHttpRequest, v8);
  }
LABEL_9:
  OSuite::ZMutex::Unlock(&this->m_mutex);
  v10 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::ZHttpRequestManager::ReleaseHttpRequest(v10->m_httpRequestManager, pHttpRequest);
  if ( this->m_error )
  {
    v11 = OSuite::TSingleton<OSuite::ZError>::Object();
    OSuite::ZError::SetThreadLastError(v11, this->m_error, 1);
  }
  return error != 0;
}


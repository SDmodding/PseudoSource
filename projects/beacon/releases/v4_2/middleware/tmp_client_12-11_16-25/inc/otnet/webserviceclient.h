// File Line: 168
// RVA: 0xEC927C
bool __fastcall OSuite::ZWebServiceClient::Request<OSuite::ZOEntry>(
        OSuite::ZWebServiceClient *this,
        const char *path,
        OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *cb,
        const char *httpMethod)
{
  OSuite::ZString patha; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::ZUrl url; // [rsp+40h] [rbp-C0h] BYREF

  patha.m_pString = 0i64;
  OSuite::ZString::ZString(&patha, path);
  url.m_sProtocol.m_pString = 0i64;
  url.m_sHost.m_pString = 0i64;
  url.m_sFakeHost.m_pString = 0i64;
  url.m_sPath.m_pString = 0i64;
  url.m_urlParameters.m_parameters.m_pTop = 0i64;
  url.m_urlParameters.m_arrayParameters.m_pTop = 0i64;
  OSuite::ZUrl::ZUrl(&url);
  OSuite::ZWebServiceClient::ProcessPath(this, &url, &patha);
  LOBYTE(this) = OSuite::ZWebServiceClient::Request<OSuite::ZOEntry>(this, &url, cb, httpMethod);
  OSuite::ZUrl::~ZUrl(&url);
  OSuite::ZString::~ZString(&patha);
  return (char)this;
}

// File Line: 184
// RVA: 0xEC9194
char __fastcall OSuite::ZWebServiceClient::Request<OSuite::ZOEntry>(
        OSuite::ZWebServiceClient *this,
        OSuite::ZUrl *url,
        OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *cb,
        const char *httpMethod)
{
  OSuite::ZMutex *p_m_requestDelegatesMutex; // rbx
  OSuite::ZString *RelativePath; // rax
  OSuite::ZAtomCache *m_pCache; // rcx
  OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> Callback; // [rsp+30h] [rbp-48h] BYREF
  OSuite::ZString format; // [rsp+40h] [rbp-38h] BYREF
  OSuite::ZString result; // [rsp+58h] [rbp-20h] BYREF

  p_m_requestDelegatesMutex = &this->m_requestDelegatesMutex;
  OSuite::ZMutex::Lock(&this->m_requestDelegatesMutex);
  RelativePath = OSuite::ZWebServiceClient::GetRelativePath(this, &result, url);
  OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::Insert(
    &this->m_clientRequestDelegates,
    RelativePath,
    cb);
  OSuite::ZString::~ZString(&result);
  OSuite::ZMutex::Unlock(p_m_requestDelegatesMutex);
  OSuite::ZString::ZString(&result, httpMethod);
  OSuite::ZString::ZString(&format, "application/json");
  m_pCache = this->m_pCache;
  Callback.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::ZWebServiceClient::InternalRequestCallback;
  Callback.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)this;
  OSuite::ZAtomCache::Open<OSuite::ZOEntry>(m_pCache, url, &Callback, &format, &result);
  OSuite::ZString::~ZString(&format);
  OSuite::ZString::~ZString(&result);
  return 1;
}

// File Line: 225
// RVA: 0xEC96F8
OSuite::ZOMetadata *__fastcall OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOMetadata>(
        OSuite::ZWebServiceClient *this,
        const char *path)
{
  OSuite::ZOMetadata *v4; // rbx
  OSuite::ZString patha; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::ZUrl url; // [rsp+40h] [rbp-C0h] BYREF

  url.m_sProtocol.m_pString = 0i64;
  url.m_sHost.m_pString = 0i64;
  url.m_sFakeHost.m_pString = 0i64;
  url.m_sPath.m_pString = 0i64;
  url.m_urlParameters.m_parameters.m_pTop = 0i64;
  url.m_urlParameters.m_arrayParameters.m_pTop = 0i64;
  OSuite::ZUrl::ZUrl(&url);
  patha.m_pString = 0i64;
  OSuite::ZString::ZString(&patha, path);
  OSuite::ZWebServiceClient::ProcessPath(this, &url, &patha);
  v4 = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOMetadata>(this, &url);
  OSuite::ZString::~ZString(&patha);
  OSuite::ZUrl::~ZUrl(&url);
  return v4;
}

// File Line: 243
// RVA: 0xEC9674
OSuite::ZOMetadata *__fastcall OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOMetadata>(
        OSuite::ZWebServiceClient *this,
        OSuite::ZUrl *url)
{
  OSuite::ZString *v4; // rbx
  OSuite::ZString *v5; // rax
  OSuite::ZString v7; // [rsp+20h] [rbp-38h] BYREF
  OSuite::ZString result; // [rsp+38h] [rbp-20h] BYREF

  v4 = OSuite::ZUrl::ToString(&this->m_baseUrl, &result, 0);
  v5 = OSuite::ZUrl::ToString(url, &v7, 0);
  LOBYTE(v4) = !OSuite::ZString::StartsWith(v5, v4);
  OSuite::ZString::~ZString(&v7);
  OSuite::ZString::~ZString(&result);
  if ( (_BYTE)v4 )
    return 0i64;
  else
    return OSuite::ZAtomCache::TryOpen<OSuite::ZOMetadata>(this->m_pCache, url, 0i64);
}


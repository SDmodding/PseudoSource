// File Line: 168
// RVA: 0xEC927C
bool __fastcall OSuite::ZWebServiceClient::Request<OSuite::ZOEntry>(OSuite::ZWebServiceClient *this, const char *path, OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *cb, const char *httpMethod)
{
  OSuite::ZWebServiceClient *v4; // rbx
  const char *v5; // rsi
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *v6; // rdi
  OSuite::ZString patha; // [rsp+20h] [rbp-E0h]
  OSuite::ZUrl url; // [rsp+40h] [rbp-C0h]

  patha.m_pString = 0i64;
  v4 = this;
  v5 = httpMethod;
  v6 = cb;
  OSuite::ZString::ZString(&patha, path);
  url.m_sProtocol.m_pString = 0i64;
  url.m_sHost.m_pString = 0i64;
  url.m_sFakeHost.m_pString = 0i64;
  url.m_sPath.m_pString = 0i64;
  url.m_urlParameters.m_parameters.m_pTop = 0i64;
  url.m_urlParameters.m_arrayParameters.m_pTop = 0i64;
  OSuite::ZUrl::ZUrl(&url);
  OSuite::ZWebServiceClient::ProcessPath(v4, &url, &patha);
  LOBYTE(v4) = OSuite::ZWebServiceClient::Request<OSuite::ZOEntry>(v4, &url, v6, v5);
  OSuite::ZUrl::~ZUrl(&url);
  OSuite::ZString::~ZString(&patha);
  return (char)v4;
}

// File Line: 184
// RVA: 0xEC9194
char __fastcall OSuite::ZWebServiceClient::Request<OSuite::ZOEntry>(OSuite::ZWebServiceClient *this, OSuite::ZUrl *url, OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *cb, const char *httpMethod)
{
  OSuite::ZMutex *v4; // rbx
  OSuite::ZWebServiceClient *v5; // r14
  const char *v6; // rsi
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *v7; // rdi
  OSuite::ZUrl *v8; // rbp
  OSuite::ZString *v9; // rax
  OSuite::ZAtomCache *v10; // rcx
  OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> Callback; // [rsp+30h] [rbp-48h]
  OSuite::ZString format; // [rsp+40h] [rbp-38h]
  OSuite::ZString result; // [rsp+58h] [rbp-20h]

  v4 = &this->m_requestDelegatesMutex;
  v5 = this;
  v6 = httpMethod;
  v7 = cb;
  v8 = url;
  OSuite::ZMutex::Lock(&this->m_requestDelegatesMutex);
  v9 = OSuite::ZWebServiceClient::GetRelativePath(v5, &result, v8);
  OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::Insert(
    &v5->m_clientRequestDelegates,
    v9,
    v7);
  OSuite::ZString::~ZString(&result);
  OSuite::ZMutex::Unlock(v4);
  OSuite::ZString::ZString(&result, v6);
  OSuite::ZString::ZString(&format, "application/json");
  v10 = v5->m_pCache;
  Callback.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::ZWebServiceClient::InternalRequestCallback;
  Callback.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)v5;
  OSuite::ZAtomCache::Open<OSuite::ZOEntry>(v10, v8, &Callback, &format, &result);
  OSuite::ZString::~ZString(&format);
  OSuite::ZString::~ZString(&result);
  return 1;
}

// File Line: 225
// RVA: 0xEC96F8
OSuite::ZOMetadata *__fastcall OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOMetadata>(OSuite::ZWebServiceClient *this, const char *path)
{
  OSuite::ZWebServiceClient *v2; // rdi
  const char *v3; // rbx
  OSuite::ZOMetadata *v4; // rbx
  OSuite::ZString patha; // [rsp+20h] [rbp-E0h]
  OSuite::ZUrl url; // [rsp+40h] [rbp-C0h]

  url.m_sProtocol.m_pString = 0i64;
  url.m_sHost.m_pString = 0i64;
  url.m_sFakeHost.m_pString = 0i64;
  url.m_sPath.m_pString = 0i64;
  url.m_urlParameters.m_parameters.m_pTop = 0i64;
  url.m_urlParameters.m_arrayParameters.m_pTop = 0i64;
  v2 = this;
  v3 = path;
  OSuite::ZUrl::ZUrl(&url);
  patha.m_pString = 0i64;
  OSuite::ZString::ZString(&patha, v3);
  OSuite::ZWebServiceClient::ProcessPath(v2, &url, &patha);
  v4 = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOMetadata>(v2, &url);
  OSuite::ZString::~ZString(&patha);
  OSuite::ZUrl::~ZUrl(&url);
  return v4;
}

// File Line: 243
// RVA: 0xEC9674
OSuite::ZOMetadata *__fastcall OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOMetadata>(OSuite::ZWebServiceClient *this, OSuite::ZUrl *url)
{
  OSuite::ZUrl *v2; // rdi
  OSuite::ZWebServiceClient *v3; // rsi
  OSuite::ZString *v4; // rbx
  OSuite::ZString *v5; // rax
  OSuite::ZOMetadata *v6; // rax
  OSuite::ZString v7; // [rsp+20h] [rbp-38h]
  OSuite::ZString result; // [rsp+38h] [rbp-20h]

  v2 = url;
  v3 = this;
  v4 = OSuite::ZUrl::ToString(&this->m_baseUrl, &result, 0);
  v5 = OSuite::ZUrl::ToString(v2, &v7, 0);
  LOBYTE(v4) = OSuite::ZString::StartsWith(v5, v4) == 0;
  OSuite::ZString::~ZString(&v7);
  OSuite::ZString::~ZString(&result);
  if ( (_BYTE)v4 )
    v6 = 0i64;
  else
    v6 = OSuite::ZAtomCache::TryOpen<OSuite::ZOMetadata>(v3->m_pCache, v2, 0i64);
  return v6;
}


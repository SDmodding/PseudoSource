// File Line: 243
// RVA: 0x427500
OSuite::ZOEntry *__fastcall OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOEntry>(OSuite::ZWebServiceClient *this, OSuite::ZUrl *url)
{
  OSuite::ZUrl *v2; // rdi
  OSuite::ZWebServiceClient *v3; // rsi
  OSuite::ZString *v4; // rbx
  OSuite::ZString *v5; // rax
  OSuite::ZOEntry *v6; // rax
  OSuite::ZString v7; // [rsp+28h] [rbp-40h]
  OSuite::ZString result; // [rsp+40h] [rbp-28h]

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
    v6 = OSuite::ZAtomCache::TryOpen<OSuite::ZOEntry>(v3->m_pCache, v2, 0i64);
  return v6;
}


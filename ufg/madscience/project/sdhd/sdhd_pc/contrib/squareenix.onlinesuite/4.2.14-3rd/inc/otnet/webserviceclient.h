// File Line: 243
// RVA: 0x427500
OSuite::ZOEntry *__fastcall OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOEntry>(
        OSuite::ZWebServiceClient *this,
        OSuite::ZUrl *url)
{
  OSuite::ZString *v4; // rbx
  OSuite::ZString *v5; // rax
  OSuite::ZString v7; // [rsp+28h] [rbp-40h] BYREF
  OSuite::ZString result; // [rsp+40h] [rbp-28h] BYREF

  v4 = OSuite::ZUrl::ToString(&this->m_baseUrl, &result, 0);
  v5 = OSuite::ZUrl::ToString(url, &v7, 0);
  LOBYTE(v4) = !OSuite::ZString::StartsWith(v5, v4);
  OSuite::ZString::~ZString(&v7);
  OSuite::ZString::~ZString(&result);
  if ( (_BYTE)v4 )
    return 0i64;
  else
    return OSuite::ZAtomCache::TryOpen<OSuite::ZOEntry>(this->m_pCache, url, 0i64);
}


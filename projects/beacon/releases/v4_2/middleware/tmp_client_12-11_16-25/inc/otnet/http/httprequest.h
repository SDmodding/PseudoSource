// File Line: 35
// RVA: 0xEDC31C
bool __fastcall OSuite::ZHttpRequest::IsConnected(OSuite::ZHttpRequest *this)
{
  return OSuite::ZHttpConnection::IsConnected(this->m_pHttpConnection);
}

// File Line: 36
// RVA: 0xEDC328
bool __fastcall OSuite::ZHttpRequest::IsConnecting(OSuite::ZHttpRequest *this)
{
  return OSuite::ZHttpConnection::IsConnecting(this->m_pHttpConnection);
}

// File Line: 37
// RVA: 0xEDC334
__int64 __fastcall OSuite::ZHttpRequest::ReadyToWrite(OSuite::ZHttpRequest *this)
{
  return ((__int64 (__fastcall *)(OSuite::ZHttpStreamWriter *))this->m_streamWriter.vfptr[4].__vecDelDtor)(&this->m_streamWriter);
}

// File Line: 38
// RVA: 0xEDCB9C
__int64 __fastcall OSuite::ZHttpRequest::WriterEof(OSuite::ZHttpRequest *this)
{
  return ((__int64 (__fastcall *)(OSuite::ZHttpStreamWriter *))this->m_streamWriter.vfptr[5].__vecDelDtor)(&this->m_streamWriter);
}

// File Line: 44
// RVA: 0xEDC1B8
OSuite::IHttpResponse *__fastcall OSuite::ZHttpRequest::GetResponse(OSuite::ZHttpRequest *this)
{
  __int64 v1; // rdx

  v1 = 0i64;
  if ( this != (OSuite::ZHttpRequest *)-568i64 )
    return &this->m_httpResponse.OSuite::IHttpResponse;
  return (OSuite::IHttpResponse *)v1;
}


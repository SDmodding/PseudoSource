// File Line: 43
// RVA: 0xEDFF00
OSuite::ZUrl *__fastcall OSuite::ZHttpResponse::GetRedirectedUrl(OSuite::ZHttpResponse *this)
{
  return (OSuite::ZUrl *)&this->m_streamReader.m_nChunkSize;
}


// File Line: 54
// RVA: 0xEDECD0
OSuite::ZString *__fastcall OSuite::ZHttpWriter::GetEncodingCharset(OSuite::ZHttpWriter *this, OSuite::ZString *result)
{
  OSuite::ZTextDecoder *m_pDecoder; // rcx
  char v4; // bl
  OSuite::ZString *v5; // rax
  OSuite::ZString v7; // [rsp+20h] [rbp-38h] BYREF
  OSuite::ZString resulta; // [rsp+38h] [rbp-20h] BYREF

  m_pDecoder = this->m_pDecoder;
  if ( m_pDecoder )
  {
    v4 = 1;
    v5 = OSuite::ZTextDecoder::Encoding(m_pDecoder, &resulta);
  }
  else
  {
    v4 = 2;
    OSuite::ZString::ZString(&v7);
  }
  OSuite::ZString::ZString(result, v5);
  if ( (v4 & 2) != 0 )
  {
    v4 &= ~2u;
    OSuite::ZString::~ZString(&v7);
  }
  if ( (v4 & 1) != 0 )
    OSuite::ZString::~ZString(&resulta);
  return result;
}

// File Line: 68
// RVA: 0xEDEF90
unsigned __int64 __fastcall OSuite::ZHttpWriter::ReadyToWrite(OSuite::ZHttpWriter *this)
{
  unsigned __int64 result; // rax
  unsigned __int64 m_nTotalLength; // rax

  if ( !this->m_bTransferChunked || (result = -1i64, this->m_nTotalLength != -1i64) )
  {
    m_nTotalLength = this->m_nTotalLength;
    if ( this->m_nBytesWritten > m_nTotalLength )
      return 0i64;
    else
      return m_nTotalLength - this->m_nBytesWritten;
  }
  return result;
}

// File Line: 75
// RVA: 0xEDECAC
bool __fastcall OSuite::ZHttpWriter::Eof(OSuite::ZHttpWriter *this)
{
  if ( this->m_bTransferChunked && this->m_nTotalLength == -1i64 )
    return this->m_bLastChunkSent;
  else
    return this->m_nBytesWritten >= this->m_nTotalLength;
}


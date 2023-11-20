// File Line: 54
// RVA: 0xEDECD0
OSuite::ZString *__fastcall OSuite::ZHttpWriter::GetEncodingCharset(OSuite::ZHttpWriter *this, OSuite::ZString *result)
{
  OSuite::ZTextDecoder *v2; // rcx
  OSuite::ZString *v3; // rdi
  char v4; // bl
  OSuite::ZString *v5; // rax
  OSuite::ZString v7; // [rsp+20h] [rbp-38h]
  OSuite::ZString resulta; // [rsp+38h] [rbp-20h]

  v2 = this->m_pDecoder;
  v3 = result;
  if ( v2 )
  {
    v4 = 1;
    v5 = OSuite::ZTextDecoder::Encoding(v2, &resulta);
  }
  else
  {
    v4 = 2;
    OSuite::ZString::ZString(&v7);
  }
  OSuite::ZString::ZString(v3, v5);
  if ( v4 & 2 )
  {
    v4 &= 0xFDu;
    OSuite::ZString::~ZString(&v7);
  }
  if ( v4 & 1 )
    OSuite::ZString::~ZString(&resulta);
  return v3;
}

// File Line: 68
// RVA: 0xEDEF90
unsigned __int64 __fastcall OSuite::ZHttpWriter::ReadyToWrite(OSuite::ZHttpWriter *this)
{
  unsigned __int64 result; // rax
  unsigned __int64 v2; // rax

  if ( !this->m_bTransferChunked || (result = -1i64, this->m_nTotalLength != -1i64) )
  {
    v2 = this->m_nTotalLength;
    if ( this->m_nBytesWritten > v2 )
      result = 0i64;
    else
      result = v2 - this->m_nBytesWritten;
  }
  return result;
}

// File Line: 75
// RVA: 0xEDECAC
bool __fastcall OSuite::ZHttpWriter::Eof(OSuite::ZHttpWriter *this)
{
  bool result; // al

  if ( this->m_bTransferChunked && this->m_nTotalLength == -1i64 )
    result = this->m_bLastChunkSent;
  else
    result = this->m_nBytesWritten >= this->m_nTotalLength;
  return result;
}


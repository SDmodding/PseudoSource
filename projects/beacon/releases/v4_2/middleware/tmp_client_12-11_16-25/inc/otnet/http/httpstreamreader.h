// File Line: 32
// RVA: 0xEE1E6C
OSuite::ZDateTime *__fastcall OSuite::ZHttpStreamReader::GetModificationDate(OSuite::ZHttpStreamReader *this)
{
  if ( !(`OSuite::ZHttpStreamReader::GetModificationDate::`2::`local static guard & 1) )
  {
    `OSuite::ZHttpStreamReader::GetModificationDate::`2::`local static guard |= 1u;
    OSuite::ZDateTime::ZDateTime(&`OSuite::ZHttpStreamReader::GetModificationDate::`2::foo);
    atexit(`OSuite::ZHttpStreamReader::GetModificationDate::`2::`dynamic atexit destructor for foo);
  }
  return &`OSuite::ZHttpStreamReader::GetModificationDate::`2::foo;
}

// File Line: 33
// RVA: 0xEE1EA8
OSuite::ZString *__fastcall OSuite::ZHttpStreamReader::GetName(OSuite::ZHttpStreamReader *this)
{
  if ( !(`OSuite::ZHttpStreamReader::GetName::`2::`local static guard & 1) )
  {
    `OSuite::ZHttpStreamReader::GetName::`2::foo.m_pString = 0i64;
    `OSuite::ZHttpStreamReader::GetName::`2::`local static guard |= 1u;
    OSuite::ZString::ZString(&`OSuite::ZHttpStreamReader::GetName::`2::foo, "ZHttpStreamReader");
    atexit(`OSuite::ZHttpStreamReader::GetName::`2::`dynamic atexit destructor for foo);
  }
  return &`OSuite::ZHttpStreamReader::GetName::`2::foo;
}

// File Line: 64
// RVA: 0xEE1F38
OSuite::ZHttpConnection *__fastcall OSuite::ZHttpStreamReader::ReadyToRead(OSuite::ZHttpStreamReader *this)
{
  OSuite::ZHttpConnection *result; // rax

  if ( WORD2(this->m_nContentLength) )
    return 0i64;
  result = (OSuite::ZHttpConnection *)this->m_nBytesRead;
  if ( result == (OSuite::ZHttpConnection *)-1i64 )
    return result;
  if ( result < this->m_httpConnection )
    return 0i64;
  result = (OSuite::ZHttpConnection *)((char *)result - (unsigned __int64)this->m_httpConnection);
  return result;
}

// File Line: 82
// RVA: 0xEE1DA0
bool __fastcall OSuite::ZHttpStreamReader::Eof(OSuite::ZHttpStreamReader *this)
{
  OSuite::ZHttpStreamReader *v1; // rdi
  OSuite::IReaderVtbl *v2; // rcx
  bool result; // al

  v1 = this;
  v2 = this->vfptr;
  if ( v2
    && OSuite::ZHttpConnection::Socket((OSuite::ZHttpConnection *)v2)
    && (OSuite::ZHttpConnection::Socket((OSuite::ZHttpConnection *)v1->vfptr)->m_state & 5) != 5
    || BYTE4(v1->m_nContentLength) && BYTE5(v1->m_nContentLength) )
  {
    result = 1;
  }
  else
  {
    result = v1->m_httpConnection >= (OSuite::ZHttpConnection *)v1->m_nBytesRead;
  }
  return result;
}


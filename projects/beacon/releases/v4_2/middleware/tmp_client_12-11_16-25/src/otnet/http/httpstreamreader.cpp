// File Line: 14
// RVA: 0xEE1D18
void __fastcall OSuite::ZHttpStreamReader::ZHttpStreamReader(OSuite::ZHttpStreamReader *this)
{
  this->m_nChunkSize = -1;
  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpStreamReader::`vftable{for `OSuite::ZObject};
  this->OSuite::IReader::vfptr = (OSuite::IReaderVtbl *)&OSuite::ZHttpStreamReader::`vftable{for `OSuite::IReader};
  this->m_httpConnection = 0i64;
  this->m_nBytesRead = 0i64;
  this->m_nContentLength = 0i64;
  *(_WORD *)&this->m_bTransferChunked = 0;
}

// File Line: 30
// RVA: 0xEE1D48
void __fastcall OSuite::ZHttpStreamReader::~ZHttpStreamReader(OSuite::ZHttpStreamReader *this)
{
  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpStreamReader::`vftable{for `OSuite::ZObject};
  this->OSuite::IReader::vfptr = (OSuite::IReaderVtbl *)&OSuite::ZHttpStreamReader::`vftable{for `OSuite::IReader};
}

// File Line: 35
// RVA: 0xEE1EF4
void __fastcall OSuite::ZHttpStreamReader::Init(
        OSuite::ZHttpStreamReader *this,
        OSuite::ZHttpConnection *httpConnection,
        unsigned __int64 nContentLength,
        bool bTransferChunked)
{
  this->m_nChunkSize = -1;
  this->m_nBytesRead = 0i64;
  this->m_httpConnection = httpConnection;
  this->m_nContentLength = nContentLength;
  this->m_bTransferChunked = bTransferChunked;
  this->m_bLastChunkReceive = 0;
  if ( bTransferChunked )
    OSuite::ZHttpStreamReader::ReceiveChunkSize(this);
}

// File Line: 53
// RVA: 0xEE1F20
unsigned __int64 __fastcall OSuite::ZHttpStreamReader::Read(
        OSuite::ZHttpStreamReader *this,
        void *pDest,
        unsigned __int64 nCount)
{
  return OSuite::ZHttpStreamReader::ReceiveBytes((OSuite::ZHttpStreamReader *)((char *)this - 8), pDest, nCount);
}

// File Line: 58
// RVA: 0xEE1F2C
int __fastcall OSuite::ZHttpStreamReader::ReadByte(OSuite::ZHttpStreamReader *this)
{
  return OSuite::ZHttpStreamReader::ReceiveByte((OSuite::ZHttpStreamReader *)((char *)this - 8));
}

// File Line: 63
// RVA: 0xEE1DFC
void __fastcall OSuite::ZHttpStreamReader::Flush(OSuite::ZHttpStreamReader *this)
{
  OSuite::ZObjectVtbl *i; // rax
  char pMem[256]; // [rsp+20h] [rbp-118h] BYREF

  for ( i = this->OSuite::ZObject::vfptr;
        !((unsigned __int8 (*)(void))i[10].__vecDelDtor)()
     && OSuite::ZHttpStreamReader::ReceiveBytes((OSuite::ZHttpStreamReader *)((char *)this - 8), pMem, 0x100ui64);
        i = this->OSuite::ZObject::vfptr )
  {
    ;
  }
}

// File Line: 74
// RVA: 0xEE2248
char __fastcall OSuite::ZHttpStreamReader::Skip(OSuite::ZHttpStreamReader *this, int nOffset)
{
  int v2; // ebx
  OSuite::ZHttpStreamReader *v4; // rdi
  unsigned __int64 v5; // r8
  unsigned __int64 v6; // rax
  char pMem[256]; // [rsp+20h] [rbp-118h] BYREF

  v2 = nOffset;
  if ( nOffset < 0 )
    return 0;
  if ( nOffset > 0 )
  {
    v4 = (OSuite::ZHttpStreamReader *)((char *)this - 8);
    while ( 1 )
    {
      v5 = v2;
      if ( (unsigned __int64)v2 >= 0x100 )
        v5 = 256i64;
      v6 = OSuite::ZHttpStreamReader::ReceiveBytes(v4, pMem, v5);
      if ( !v6 )
        break;
      v2 -= v6;
      if ( v2 <= 0 )
        return 1;
    }
    return 0;
  }
  return 1;
}

// File Line: 98
// RVA: 0xEE222C
bool __fastcall OSuite::ZHttpStreamReader::SetPosition(
        OSuite::ZHttpStreamReader *this,
        OSuite::ZHttpConnection *nPosition)
{
  if ( (unsigned __int64)nPosition > this->m_nBytesRead || nPosition < this->m_httpConnection )
    return 0;
  else
    return (bool)this->OSuite::ZObject::vfptr[4].__vecDelDtor(
                   this,
                   (unsigned int)((_DWORD)nPosition - LODWORD(this->m_httpConnection)));
}

// File Line: 121
// RVA: 0xEE1FB0
unsigned __int64 __fastcall OSuite::ZHttpStreamReader::ReceiveBytes(
        OSuite::ZHttpStreamReader *this,
        void *pMem,
        unsigned __int64 nLength)
{
  unsigned __int64 result; // rax

  if ( this->m_nContentLength != -1i64
    && (!(__int64)this->OSuite::IReader::vfptr->ReadyToRead(&this->OSuite::IReader) || !nLength) )
  {
    return 0i64;
  }
  result = OSuite::ZHttpStreamReader::ReceiveChunkedBuffer(this, pMem, nLength);
  if ( result )
  {
    this->m_nBytesRead += result;
    if ( this->m_bTransferChunked && this->m_bLastChunkReceive )
      this->m_nContentLength = this->m_nBytesRead;
  }
  return result;
}

// File Line: 144
// RVA: 0xEE1F60
int __fastcall OSuite::ZHttpStreamReader::ReceiveByte(OSuite::ZHttpStreamReader *this)
{
  int result; // eax

  if ( this->m_nContentLength != -1i64 && !(__int64)this->OSuite::IReader::vfptr->ReadyToRead(&this->OSuite::IReader) )
    return -1;
  result = OSuite::ZHttpStreamReader::ReceiveChunkedByte(this);
  if ( result != -1 )
  {
    ++this->m_nBytesRead;
    if ( this->m_bTransferChunked && this->m_bLastChunkReceive )
      this->m_nContentLength = this->m_nBytesRead;
  }
  return result;
}

// File Line: 161
// RVA: 0xEE20D8
__int64 __fastcall OSuite::ZHttpStreamReader::ReceiveChunkedBuffer(
        OSuite::ZHttpStreamReader *this,
        char *pMem,
        unsigned __int64 nLength)
{
  int m_nChunkSize; // ecx
  int v8; // eax
  unsigned __int64 v9; // rbx
  OSuite::ZSocket *v10; // rax
  __int64 v11; // rbx
  OSuite::ZSocket *v12; // rax
  OSuite::ZSocket *v13; // rax
  char pBuffer[8]; // [rsp+20h] [rbp-28h] BYREF

  if ( this->OSuite::IReader::vfptr->Eof(&this->OSuite::IReader) )
    return 0i64;
  if ( this->m_bTransferChunked )
  {
    OSuite::ZHttpStreamReader::ReceiveChunkSize(this);
    if ( this->m_bLastChunkReceive )
      return 0i64;
    m_nChunkSize = this->m_nChunkSize;
    if ( m_nChunkSize <= 0 )
      return 0i64;
    v8 = nLength;
    if ( (int)nLength > m_nChunkSize )
      v8 = this->m_nChunkSize;
    v9 = v8;
    v10 = OSuite::ZHttpConnection::Socket(this->m_httpConnection);
    v11 = OSuite::ZSocket::ReceiveBuffer(v10, pMem, v9);
    if ( !v11 && OSuite::ZHttpConnection::HasFatalError(this->m_httpConnection) )
      return 0i64;
    this->m_nChunkSize -= v11;
    nLength -= v11;
    if ( !this->m_nChunkSize )
    {
      v12 = OSuite::ZHttpConnection::Socket(this->m_httpConnection);
      OSuite::ZSocket::ReceiveBuffer(v12, pBuffer, 2ui64);
      this->m_nChunkSize = -1;
    }
  }
  else
  {
    v13 = OSuite::ZHttpConnection::Socket(this->m_httpConnection);
    v11 = OSuite::ZSocket::ReceiveBuffer(v13, pMem, nLength);
  }
  if ( v11 != nLength && OSuite::ZHttpConnection::HasFatalError(this->m_httpConnection) )
    OSuite::ZHttpConnection::Abort(this->m_httpConnection);
  return v11;
}

// File Line: 203
// RVA: 0xEE21E4
__int64 __fastcall OSuite::ZHttpStreamReader::ReceiveChunkedByte(OSuite::ZHttpStreamReader *this)
{
  char pMem[8]; // [rsp+20h] [rbp-18h] BYREF

  if ( OSuite::ZHttpStreamReader::ReceiveChunkedBuffer(this, pMem, 1ui64) == 1 )
    return (unsigned __int8)pMem[0];
  else
    return 0xFFFFFFFFi64;
}

// File Line: 214
// RVA: 0xEE2024
__int64 __fastcall OSuite::ZHttpStreamReader::ReceiveChunkSize(OSuite::ZHttpStreamReader *this)
{
  OSuite::ZSocket *v2; // rax
  int v3; // r9d
  int v4; // eax
  OSuite::ZSocket *v5; // rax
  char v7[4]; // [rsp+20h] [rbp-48h] BYREF
  OSuite::ZHttpParser pszString[5]; // [rsp+28h] [rbp-40h] BYREF

  if ( this->m_nChunkSize == -1 )
  {
    v2 = OSuite::ZHttpConnection::Socket(this->m_httpConnection);
    if ( OSuite::ZSocket::ReceiveString(v2, (char *)pszString, 0x28ui64) )
    {
      *(_DWORD *)v7 = 0;
      v4 = OSuite::ZHttpParser::parsebase<char>(pszString, v7, (int *)0x10, v3);
      this->m_nChunkSize = v4;
      if ( !v4 )
      {
        do
          v5 = OSuite::ZHttpConnection::Socket(this->m_httpConnection);
        while ( OSuite::ZSocket::ReceiveString(v5, (char *)pszString, 0x28ui64)
             && (LOBYTE(pszString[0].vfptr) != 10 || BYTE1(pszString[0].vfptr)) );
        this->m_bLastChunkReceive = 1;
      }
    }
  }
  return (unsigned int)this->m_nChunkSize;
}


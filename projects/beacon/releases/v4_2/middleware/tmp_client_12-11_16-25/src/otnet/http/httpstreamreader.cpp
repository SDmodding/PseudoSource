// File Line: 14
// RVA: 0xEE1D18
void __fastcall OSuite::ZHttpStreamReader::ZHttpStreamReader(OSuite::ZHttpStreamReader *this)
{
  this->m_nChunkSize = -1;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpStreamReader::`vftable{for `OSuite::ZObject};
  this->vfptr = (OSuite::IReaderVtbl *)&OSuite::ZHttpStreamReader::`vftable{for `OSuite::IReader};
  this->m_httpConnection = 0i64;
  this->m_nBytesRead = 0i64;
  this->m_nContentLength = 0i64;
  *(_WORD *)&this->m_bTransferChunked = 0;
}

// File Line: 30
// RVA: 0xEE1D48
void __fastcall OSuite::ZHttpStreamReader::~ZHttpStreamReader(OSuite::ZHttpStreamReader *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpStreamReader::`vftable{for `OSuite::ZObject};
  this->vfptr = (OSuite::IReaderVtbl *)&OSuite::ZHttpStreamReader::`vftable{for `OSuite::IReader};
}

// File Line: 35
// RVA: 0xEE1EF4
void __fastcall OSuite::ZHttpStreamReader::Init(OSuite::ZHttpStreamReader *this, OSuite::ZHttpConnection *httpConnection, unsigned __int64 nContentLength, bool bTransferChunked)
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
unsigned __int64 __fastcall OSuite::ZHttpStreamReader::Read(OSuite::ZHttpStreamReader *this, void *pDest, unsigned __int64 nCount)
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
  OSuite::ZObjectVtbl *v1; // rax
  OSuite::ZHttpStreamReader *i; // rbx
  char pMem; // [rsp+20h] [rbp-118h]

  v1 = this->vfptr;
  for ( i = this;
        !((unsigned __int8 (__fastcall *)(OSuite::ZHttpStreamReader *))v1[10].__vecDelDtor)(this)
     && OSuite::ZHttpStreamReader::ReceiveBytes((OSuite::ZHttpStreamReader *)((char *)i - 8), &pMem, 0x100ui64);
        this = i )
  {
    v1 = i->vfptr;
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
  char pMem; // [rsp+20h] [rbp-118h]

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
      v6 = OSuite::ZHttpStreamReader::ReceiveBytes(v4, &pMem, v5);
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
bool __fastcall OSuite::ZHttpStreamReader::SetPosition(OSuite::ZHttpStreamReader *this, unsigned __int64 nPosition)
{
  bool result; // al

  if ( nPosition > this->m_nBytesRead || (OSuite::ZHttpConnection *)nPosition < this->m_httpConnection )
    result = 0;
  else
    result = (__int64)this->vfptr[4].__vecDelDtor((OSuite::ZObject *)this, nPosition - LODWORD(this->m_httpConnection));
  return result;
}

// File Line: 121
// RVA: 0xEE1FB0
unsigned __int64 __fastcall OSuite::ZHttpStreamReader::ReceiveBytes(OSuite::ZHttpStreamReader *this, void *pMem, unsigned __int64 nLength)
{
  unsigned __int64 v3; // rdi
  void *v4; // rsi
  OSuite::ZHttpStreamReader *v5; // rbx
  unsigned __int64 result; // rax

  v3 = nLength;
  v4 = pMem;
  v5 = this;
  if ( this->m_nContentLength != -1i64 && (!((__int64 (*)(void))this->vfptr->ReadyToRead)() || !v3) )
    return 0i64;
  result = OSuite::ZHttpStreamReader::ReceiveChunkedBuffer(v5, v4, v3);
  if ( result )
  {
    v5->m_nBytesRead += result;
    if ( v5->m_bTransferChunked )
    {
      if ( v5->m_bLastChunkReceive )
        v5->m_nContentLength = v5->m_nBytesRead;
    }
  }
  return result;
}

// File Line: 144
// RVA: 0xEE1F60
int __fastcall OSuite::ZHttpStreamReader::ReceiveByte(OSuite::ZHttpStreamReader *this)
{
  OSuite::ZHttpStreamReader *v1; // rbx
  int result; // eax

  v1 = this;
  if ( this->m_nContentLength != -1i64 && !((__int64 (*)(void))this->vfptr->ReadyToRead)() )
    return -1;
  result = OSuite::ZHttpStreamReader::ReceiveChunkedByte(v1);
  if ( result != -1 )
  {
    ++v1->m_nBytesRead;
    if ( v1->m_bTransferChunked )
    {
      if ( v1->m_bLastChunkReceive )
        v1->m_nContentLength = v1->m_nBytesRead;
    }
  }
  return result;
}

// File Line: 161
// RVA: 0xEE20D8
__int64 __fastcall OSuite::ZHttpStreamReader::ReceiveChunkedBuffer(OSuite::ZHttpStreamReader *this, void *pMem, unsigned __int64 nLength)
{
  OSuite::ZHttpStreamReader *v3; // rdi
  unsigned __int64 v4; // rsi
  void *v5; // rbp
  signed int v7; // ecx
  int v8; // eax
  unsigned __int64 v9; // rbx
  OSuite::ZSocket *v10; // rax
  __int64 v11; // rbx
  OSuite::ZSocket *v12; // rax
  OSuite::ZSocket *v13; // rax
  char pBuffer; // [rsp+20h] [rbp-28h]

  v3 = this;
  v4 = nLength;
  v5 = pMem;
  if ( ((unsigned __int8 (*)(void))this->vfptr->Eof)() )
    return 0i64;
  if ( v3->m_bTransferChunked )
  {
    OSuite::ZHttpStreamReader::ReceiveChunkSize(v3);
    if ( v3->m_bLastChunkReceive )
      return 0i64;
    v7 = v3->m_nChunkSize;
    if ( v7 <= 0 )
      return 0i64;
    v8 = v4;
    if ( (signed int)v4 > v7 )
      v8 = v3->m_nChunkSize;
    v9 = v8;
    v10 = OSuite::ZHttpConnection::Socket(v3->m_httpConnection);
    v11 = OSuite::ZSocket::ReceiveBuffer(v10, v5, v9);
    if ( !v11 )
    {
      if ( OSuite::ZHttpConnection::HasFatalError(v3->m_httpConnection) )
        return 0i64;
    }
    v3->m_nChunkSize -= v11;
    v4 -= v11;
    if ( !v3->m_nChunkSize )
    {
      v12 = OSuite::ZHttpConnection::Socket(v3->m_httpConnection);
      OSuite::ZSocket::ReceiveBuffer(v12, &pBuffer, 2ui64);
      v3->m_nChunkSize = -1;
    }
  }
  else
  {
    v13 = OSuite::ZHttpConnection::Socket(v3->m_httpConnection);
    v11 = OSuite::ZSocket::ReceiveBuffer(v13, v5, v4);
  }
  if ( v11 != v4 )
  {
    if ( OSuite::ZHttpConnection::HasFatalError(v3->m_httpConnection) )
      OSuite::ZHttpConnection::Abort(v3->m_httpConnection);
  }
  return v11;
}

// File Line: 203
// RVA: 0xEE21E4
signed __int64 __fastcall OSuite::ZHttpStreamReader::ReceiveChunkedByte(OSuite::ZHttpStreamReader *this)
{
  signed __int64 result; // rax
  unsigned __int8 pMem; // [rsp+20h] [rbp-18h]

  if ( OSuite::ZHttpStreamReader::ReceiveChunkedBuffer(this, &pMem, 1ui64) == 1 )
    result = pMem;
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 214
// RVA: 0xEE2024
__int64 __fastcall OSuite::ZHttpStreamReader::ReceiveChunkSize(OSuite::ZHttpStreamReader *this)
{
  OSuite::ZHttpStreamReader *v1; // rbx
  OSuite::ZSocket *v2; // rax
  int v3; // er9
  int v4; // eax
  OSuite::ZSocket *v5; // rax
  char v7[4]; // [rsp+20h] [rbp-48h]
  char pszString; // [rsp+28h] [rbp-40h]
  char v9; // [rsp+29h] [rbp-3Fh]

  v1 = this;
  if ( this->m_nChunkSize == -1 )
  {
    v2 = OSuite::ZHttpConnection::Socket(this->m_httpConnection);
    if ( OSuite::ZSocket::ReceiveString(v2, &pszString, 0x28ui64) )
    {
      *(_DWORD *)v7 = 0;
      v4 = OSuite::ZHttpParser::parsebase<char>((OSuite::ZHttpParser *)&pszString, v7, (int *)0x10, v3);
      v1->m_nChunkSize = v4;
      if ( !v4 )
      {
        do
          v5 = OSuite::ZHttpConnection::Socket(v1->m_httpConnection);
        while ( OSuite::ZSocket::ReceiveString(v5, &pszString, 0x28ui64) && (pszString != 10 || v9) );
        v1->m_bLastChunkReceive = 1;
      }
    }
  }
  return (unsigned int)v1->m_nChunkSize;
}


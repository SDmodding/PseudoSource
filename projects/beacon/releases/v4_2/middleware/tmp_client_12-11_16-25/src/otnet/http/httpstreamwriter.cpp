// File Line: 13
// RVA: 0xEDF0BC
void __fastcall OSuite::ZHttpStreamWriter::ZHttpStreamWriter(OSuite::ZHttpStreamWriter *this)
{
  OSuite::ZHttpStreamWriter *v1; // rbx

  v1 = this;
  OSuite::ZHttpWriter::ZHttpWriter((OSuite::ZHttpWriter *)&this->vfptr);
  v1->m_httpConnection = 0i64;
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpStreamWriter::`vftable'{for `OSuite::ZObject'};
  v1->vfptr = (OSuite::IWriterVtbl *)&OSuite::ZHttpStreamWriter::`vftable'{for `OSuite::IWriter'};
}

// File Line: 24
// RVA: 0xEDF0F0
void __fastcall OSuite::ZHttpStreamWriter::~ZHttpStreamWriter(OSuite::ZHttpStreamWriter *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpStreamWriter::`vftable'{for `OSuite::ZObject'};
  this->vfptr = (OSuite::IWriterVtbl *)&OSuite::ZHttpStreamWriter::`vftable'{for `OSuite::IWriter'};
  OSuite::ZHttpWriter::~ZHttpWriter((OSuite::ZHttpWriter *)&this->vfptr);
}

// File Line: 28
// RVA: 0xEDF15C
void __fastcall OSuite::ZHttpStreamWriter::Init(OSuite::ZHttpStreamWriter *this, OSuite::ZHttpConnection *httpConnection)
{
  this->m_httpConnection = httpConnection;
  OSuite::ZHttpWriter::Init((OSuite::ZHttpWriter *)&this->vfptr);
}

// File Line: 36
// RVA: 0xEDF168
char __fastcall OSuite::ZHttpStreamWriter::InternalWriteChunk(OSuite::ZHttpStreamWriter *this, const void *pData, unsigned __int64 nLength)
{
  unsigned __int64 v3; // rdi
  const void *v4; // rsi
  OSuite::ZHttpStreamWriter *v5; // rbx
  OSuite::ZSocket *v6; // rax
  OSuite::ZSocket *v7; // rax
  char result; // al
  OSuite::ZSocket *v9; // rax

  v3 = nLength;
  v4 = pData;
  v5 = this;
  if ( this->m_bTransferChunked )
  {
    if ( (unsigned __int8)this->vfptr[7].__vecDelDtor((OSuite::ZObject *)this, nLength)
      && (v6 = OSuite::ZHttpConnection::Socket(v5->m_httpConnection), OSuite::ZSocket::SendBuffer(v6, v4, v3))
      && (v7 = OSuite::ZHttpConnection::Socket(v5->m_httpConnection), OSuite::ZSocket::SendBuffer(v7, "\r\n", 2ui64)) )
    {
      if ( ((__int64 (__fastcall *)(OSuite::ZHttpStreamWriter *))v5->vfptr[4].__vecDelDtor)(v5) )
        result = 1;
      else
        result = ((__int64 (__fastcall *)(OSuite::ZHttpStreamWriter *))v5->vfptr[1].__vecDelDtor)(v5);
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    v9 = OSuite::ZHttpConnection::Socket(this->m_httpConnection);
    result = OSuite::ZSocket::SendBuffer(v9, v4, v3);
  }
  return result;
}

// File Line: 56
// RVA: 0xEDF218
bool __fastcall OSuite::ZHttpStreamWriter::InternalWriteChunkLength(OSuite::ZHttpStreamWriter *this, unsigned __int64 nLength)
{
  OSuite::ZHttpStreamWriter *v2; // rdi
  unsigned __int64 v3; // rbx
  OSuite::ZSocket *v4; // rax
  _TBYTE Str; // [rsp+20h] [rbp-28h]
  int v7; // [rsp+2Ah] [rbp-1Eh]
  __int16 v8; // [rsp+2Eh] [rbp-1Ah]

  v2 = this;
  Str = 0.0;
  v7 = 0;
  v8 = 0;
  sprintf_s((char *)&Str, 0x10ui64, "%Iu\r\n", nLength, *(_QWORD *)&Str, HIWORD(Str));
  v3 = strlen((const char *)&Str);
  v4 = OSuite::ZHttpConnection::Socket(v2->m_httpConnection);
  return OSuite::ZSocket::SendBuffer(v4, &Str, v3) != 0;
}


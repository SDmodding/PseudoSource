// File Line: 13
// RVA: 0xEDF0BC
void __fastcall OSuite::ZHttpStreamWriter::ZHttpStreamWriter(OSuite::ZHttpStreamWriter *this)
{
  OSuite::ZHttpWriter::ZHttpWriter(this);
  this->m_httpConnection = 0i64;
  this->OSuite::ZHttpWriter::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpStreamWriter::`vftable{for `OSuite::ZObject};
  this->OSuite::ZHttpWriter::OSuite::IWriter::vfptr = (OSuite::IWriterVtbl *)&OSuite::ZHttpStreamWriter::`vftable{for `OSuite::IWriter};
}

// File Line: 24
// RVA: 0xEDF0F0
void __fastcall OSuite::ZHttpStreamWriter::~ZHttpStreamWriter(OSuite::ZHttpStreamWriter *this)
{
  this->OSuite::ZHttpWriter::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpStreamWriter::`vftable{for `OSuite::ZObject};
  this->OSuite::ZHttpWriter::OSuite::IWriter::vfptr = (OSuite::IWriterVtbl *)&OSuite::ZHttpStreamWriter::`vftable{for `OSuite::IWriter};
  OSuite::ZHttpWriter::~ZHttpWriter(this);
}

// File Line: 28
// RVA: 0xEDF15C
void __fastcall OSuite::ZHttpStreamWriter::Init(
        OSuite::ZHttpStreamWriter *this,
        OSuite::ZHttpConnection *httpConnection)
{
  this->m_httpConnection = httpConnection;
  OSuite::ZHttpWriter::Init(this);
}

// File Line: 36
// RVA: 0xEDF168
char __fastcall OSuite::ZHttpStreamWriter::InternalWriteChunk(
        OSuite::ZHttpStreamWriter *this,
        char *pData,
        unsigned __int64 nLength)
{
  OSuite::ZSocket *v6; // rax
  OSuite::ZSocket *v7; // rax
  OSuite::ZSocket *v9; // rax

  if ( this->m_bTransferChunked )
  {
    if ( this->OSuite::ZHttpWriter::OSuite::ZObject::vfptr[7].__vecDelDtor(this, nLength)
      && (v6 = OSuite::ZHttpConnection::Socket(this->m_httpConnection), OSuite::ZSocket::SendBuffer(v6, pData, nLength))
      && (v7 = OSuite::ZHttpConnection::Socket(this->m_httpConnection), OSuite::ZSocket::SendBuffer(v7, "\r\n", 2ui64)) )
    {
      if ( ((__int64 (__fastcall *)(OSuite::ZHttpStreamWriter *))this->OSuite::ZHttpWriter::OSuite::ZObject::vfptr[4].__vecDelDtor)(this) )
        return 1;
      else
        return ((__int64 (__fastcall *)(OSuite::ZHttpStreamWriter *))this->OSuite::ZHttpWriter::OSuite::ZObject::vfptr[1].__vecDelDtor)(this);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v9 = OSuite::ZHttpConnection::Socket(this->m_httpConnection);
    return OSuite::ZSocket::SendBuffer(v9, pData, nLength);
  }
}

// File Line: 56
// RVA: 0xEDF218
bool __fastcall OSuite::ZHttpStreamWriter::InternalWriteChunkLength(
        OSuite::ZHttpStreamWriter *this,
        unsigned __int64 nLength)
{
  unsigned __int64 v3; // rbx
  OSuite::ZSocket *v4; // rax
  char Str[2]; // [rsp+20h] [rbp-28h] BYREF
  __int64 v7; // [rsp+22h] [rbp-26h]
  int v8; // [rsp+2Ah] [rbp-1Eh]
  __int16 v9; // [rsp+2Eh] [rbp-1Ah]

  *(_WORD *)Str = 0;
  v7 = 0i64;
  v8 = 0;
  v9 = 0;
  sprintf_s(Str, 0x10ui64, "%Iu\r\n", nLength);
  v3 = strlen(Str);
  v4 = OSuite::ZHttpConnection::Socket(this->m_httpConnection);
  return OSuite::ZSocket::SendBuffer(v4, Str, v3) != 0;
}


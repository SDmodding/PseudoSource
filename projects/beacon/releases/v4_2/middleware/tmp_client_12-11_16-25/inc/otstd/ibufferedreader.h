// File Line: 33
// RVA: 0xEEBB28
__int64 __fastcall OSuite::IBufferedReader::ReadByte(OSuite::IBufferedReader *this)
{
  OSuite::IReaderVtbl *vfptr; // rax
  char v3[8]; // [rsp+20h] [rbp-18h] BYREF

  vfptr = this->vfptr;
  v3[0] = 0;
  if ( (*((__int64 (__fastcall **)(OSuite::IBufferedReader *, char *, __int64))&vfptr->__vecDelDtor + 1))(
         this,
         v3,
         1i64) == 1 )
    return (unsigned __int8)v3[0];
  else
    return 0xFFFFFFFFi64;
}

// File Line: 51
// RVA: 0xEEB8FC
OSuite::ZString *__fastcall OSuite::IBufferedReader::GetEncodingCharset(
        OSuite::IBufferedReader *this,
        OSuite::ZString *result)
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

// File Line: 61
// RVA: 0xEEBBC8
OSuite::ZString *__fastcall OSuite::IBufferedReader::ReadLine(OSuite::IBufferedReader *this, OSuite::ZString *result)
{
  int v4; // eax
  OSuite::ZString resulta; // [rsp+20h] [rbp-58h] BYREF
  OSuite::ZStringBuilder v7; // [rsp+38h] [rbp-40h] BYREF

  v7.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v7, (OSuite::ZObject *)0x28);
  while ( 1 )
  {
    v4 = ((__int64 (__fastcall *)(OSuite::IBufferedReader *))this->vfptr[1].Flush)(this);
    if ( v4 == -1 || v4 == 10 )
      break;
    if ( v4 != 13 )
      OSuite::ZStringBuilder::Append(&v7, v4);
  }
  OSuite::ZStringBuilder::ToString(&v7, &resulta);
  OSuite::ZString::ZString(result, &resulta);
  OSuite::ZString::~ZString(&resulta);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v7);
  return result;
}

// File Line: 86
// RVA: 0xEEBB74
__int64 __fastcall OSuite::IBufferedReader::ReadChar(OSuite::IBufferedReader *this)
{
  __int64 result; // rax
  __int64 v3; // rdx
  OSuite::ZTextDecoder *m_pDecoder; // rcx

  result = ((__int64 (__fastcall *)(OSuite::IBufferedReader *))this->vfptr->ReadByte)(this);
  if ( (_DWORD)result == -1 )
    return 0xFFFFFFFFi64;
  m_pDecoder = this->m_pDecoder;
  if ( m_pDecoder )
  {
    while ( 1 )
    {
      LOBYTE(v3) = result;
      OSuite::ZTextDecoder::Feed(m_pDecoder, v3);
      result = OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)this->m_pDecoder);
      if ( (_DWORD)result != -1 )
        break;
      LODWORD(result) = this->vfptr->ReadByte(this);
      if ( (_DWORD)result == -1 )
        return 0xFFFFFFFFi64;
      m_pDecoder = this->m_pDecoder;
    }
  }
  return result;
}


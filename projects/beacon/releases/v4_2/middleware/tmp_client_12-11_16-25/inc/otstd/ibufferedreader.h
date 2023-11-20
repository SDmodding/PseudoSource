// File Line: 33
// RVA: 0xEEBB28
signed __int64 __fastcall OSuite::IBufferedReader::ReadByte(OSuite::IBufferedReader *this)
{
  OSuite::IReaderVtbl *v1; // rax
  signed __int64 result; // rax
  unsigned __int8 v3; // [rsp+20h] [rbp-18h]

  v1 = this->vfptr;
  v3 = 0;
  if ( (*((__int64 (__fastcall **)(OSuite::IBufferedReader *, unsigned __int8 *, signed __int64))&v1->__vecDelDtor + 1))(
         this,
         &v3,
         1i64) == 1 )
    result = v3;
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 51
// RVA: 0xEEB8FC
OSuite::ZString *__fastcall OSuite::IBufferedReader::GetEncodingCharset(OSuite::IBufferedReader *this, OSuite::ZString *result)
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

// File Line: 61
// RVA: 0xEEBBC8
OSuite::ZString *__fastcall OSuite::IBufferedReader::ReadLine(OSuite::IBufferedReader *this, OSuite::ZString *result)
{
  OSuite::IBufferedReader *v2; // rbx
  OSuite::ZString *v3; // rdi
  int v4; // eax
  OSuite::ZString resulta; // [rsp+20h] [rbp-58h]
  OSuite::ZStringBuilder v7; // [rsp+38h] [rbp-40h]

  v7.m_Chars.m_pList = 0i64;
  v2 = this;
  v3 = result;
  OSuite::ZStringBuilder::ZStringBuilder(&v7, 0x28ui64);
  while ( 1 )
  {
    v4 = ((__int64 (__fastcall *)(OSuite::IBufferedReader *))v2->vfptr[1].Flush)(v2);
    if ( v4 == -1 || v4 == 10 )
      break;
    if ( v4 != 13 )
      OSuite::ZStringBuilder::Append(&v7, v4);
  }
  OSuite::ZStringBuilder::ToString(&v7, &resulta);
  OSuite::ZString::ZString(v3, &resulta);
  OSuite::ZString::~ZString(&resulta);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v7);
  return v3;
}

// File Line: 86
// RVA: 0xEEBB74
__int64 __fastcall OSuite::IBufferedReader::ReadChar(OSuite::IBufferedReader *this)
{
  OSuite::Statistics **v1; // rbx
  __int64 result; // rax
  __int64 v3; // rdx
  OSuite::ZTextDecoder *v4; // rcx

  v1 = (OSuite::Statistics **)this;
  result = ((__int64 (*)(void))this->vfptr->ReadByte)();
  if ( (_DWORD)result == -1 )
    return 0xFFFFFFFFi64;
  v4 = (OSuite::ZTextDecoder *)v1[1];
  if ( v4 )
  {
    while ( 1 )
    {
      LOBYTE(v3) = result;
      OSuite::ZTextDecoder::Feed(v4, v3);
      result = OSuitePrivate::ZEidosTransaction::GetState(v1[1]);
      if ( (_DWORD)result != -1 )
        break;
      LODWORD(result) = (*(__int64 (__fastcall **)(OSuite::Statistics **))&(*v1)->max)(v1);
      if ( (_DWORD)result == -1 )
        return 0xFFFFFFFFi64;
      v4 = (OSuite::ZTextDecoder *)v1[1];
    }
  }
  return result;
}


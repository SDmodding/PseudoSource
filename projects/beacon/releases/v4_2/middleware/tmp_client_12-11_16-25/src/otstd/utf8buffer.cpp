// File Line: 37
// RVA: 0xEE7BF4
void __fastcall OSuite::ZStringBuilder::ZStringBuilder(OSuite::ZStringBuilder *this, OSuite::ZObject *nSize)
{
  OSuite::TList<char> *p_m_Chars; // rbx

  p_m_Chars = &this->m_Chars;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZStringBuilder::`vftable;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_Chars, nSize);
  p_m_Chars->m_pList = 0i64;
  p_m_Chars->OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<unsigned char>::`vftable{for `OSuite::ZListBase};
  p_m_Chars->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<char>::`vftable{for `OSuite::IHashable};
  if ( nSize )
    p_m_Chars->m_pList = (char *)OSuite::ZObject::malloc(p_m_Chars, (unsigned __int64)nSize, 0i64);
  p_m_Chars->m_nTop = 0i64;
  p_m_Chars->m_nSize = (unsigned __int64)nSize;
}

// File Line: 68
// RVA: 0xEE7D58
char *__fastcall OSuite::ZUtf8Buffer::Buffer(OSuite::ZUtf8Buffer *this)
{
  char *result; // rax

  result = (char *)OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_Buffer);
  if ( result )
    return this->m_Buffer.m_pList;
  return result;
}

// File Line: 98
// RVA: 0xEE7D00
void __fastcall OSuite::ZUtf8Buffer::Append(OSuite::ZUtf8Buffer *this, char *pMemory, unsigned __int64 nSize)
{
  OSuite::TList<unsigned char> *p_m_Buffer; // rbx
  unsigned __int64 v5; // rdi

  p_m_Buffer = &this->m_Buffer;
  v5 = nSize;
  OSuite::TList<char>::Grow((OSuite::TList<char> *)&this->m_Buffer, nSize + this->m_Buffer.m_nTop);
  for ( ; v5; --v5 )
    p_m_Buffer->m_pList[p_m_Buffer->m_nTop++] = *pMemory++;
}

// File Line: 108
// RVA: 0xEE7CCC
void __fastcall OSuite::ZUtf8Buffer::Append(OSuite::ZUtf8Buffer *this, char *pszString)
{
  char *v2; // rbx

  if ( pszString )
  {
    v2 = pszString;
    do
    {
      if ( !*v2 )
        break;
      OSuite::ZUtf8Buffer::Append(this, *v2++);
    }
    while ( v2 );
  }
}

// File Line: 120
// RVA: 0xEE7C6C
void __fastcall OSuite::ZUtf8Buffer::Append(OSuite::ZUtf8Buffer *this, OSuite::ZString *sString)
{
  char *v3; // rax

  v3 = OSuite::ZString::c_str(sString);
  OSuite::ZUtf8Buffer::Append(this, v3);
}

// File Line: 130
// RVA: 0xEE7C90
void __fastcall OSuite::ZUtf8Buffer::Append(OSuite::ZUtf8Buffer *this, char ch)
{
  char pMemory[8]; // [rsp+20h] [rbp-18h] BYREF

  pMemory[0] = ch;
  OSuite::ZUtf8Buffer::Append(this, pMemory, 1ui64);
}


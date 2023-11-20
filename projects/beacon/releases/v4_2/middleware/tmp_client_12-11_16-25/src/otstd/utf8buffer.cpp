// File Line: 37
// RVA: 0xEE7BF4
void __fastcall OSuite::ZStringBuilder::ZStringBuilder(OSuite::ZStringBuilder *this, unsigned __int64 nSize)
{
  OSuite::ZObject *v2; // rbx
  unsigned __int64 v3; // rdi

  v2 = (OSuite::ZObject *)&this->m_Chars.vfptr;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZStringBuilder::`vftable;
  v3 = nSize;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(
    (OSuite::ZObject *)&this->m_Chars.vfptr,
    (OSuite::ZObject *)nSize);
  v2[4].vfptr = 0i64;
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<unsigned char>::`vftable{for `OSuite::ZListBase};
  v2[3].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<char>::`vftable{for `OSuite::IHashable};
  if ( v3 )
    v2[4].vfptr = (OSuite::ZObjectVtbl *)OSuite::ZObject::malloc(v2, v3, 0i64);
  v2[2].vfptr = 0i64;
  v2[1].vfptr = (OSuite::ZObjectVtbl *)v3;
}

// File Line: 68
// RVA: 0xEE7D58
char *__fastcall OSuite::ZUtf8Buffer::Buffer(OSuite::ZUtf8Buffer *this)
{
  OSuite::ZUtf8Buffer *v1; // rbx
  char *result; // rax

  v1 = this;
  result = (char *)OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_Buffer);
  if ( result )
    result = v1->m_Buffer.m_pList;
  return result;
}

// File Line: 98
// RVA: 0xEE7D00
void __fastcall OSuite::ZUtf8Buffer::Append(OSuite::ZUtf8Buffer *this, const void *pMemory, unsigned __int64 nSize)
{
  OSuite::TList<unsigned char> *v3; // rbx
  char *v4; // rsi
  unsigned __int64 v5; // rdi

  v3 = &this->m_Buffer;
  v4 = (char *)pMemory;
  v5 = nSize;
  OSuite::TList<char>::Grow((OSuite::TList<char> *)&this->m_Buffer, nSize + this->m_Buffer.m_nTop);
  for ( ; v5; --v5 )
    v3->m_pList[v3->m_nTop++] = *v4++;
}

// File Line: 108
// RVA: 0xEE7CCC
void __fastcall OSuite::ZUtf8Buffer::Append(OSuite::ZUtf8Buffer *this, const char *pszString)
{
  char *v2; // rbx
  OSuite::ZUtf8Buffer *v3; // rdi

  if ( pszString )
  {
    v2 = (char *)pszString;
    v3 = this;
    do
    {
      if ( !*v2 )
        break;
      OSuite::ZUtf8Buffer::Append(v3, *v2++);
    }
    while ( v2 );
  }
}

// File Line: 120
// RVA: 0xEE7C6C
void __fastcall OSuite::ZUtf8Buffer::Append(OSuite::ZUtf8Buffer *this, OSuite::ZString *sString)
{
  OSuite::ZUtf8Buffer *v2; // rbx
  char *v3; // rax

  v2 = this;
  v3 = OSuite::ZString::c_str(sString);
  OSuite::ZUtf8Buffer::Append(v2, v3);
}

// File Line: 130
// RVA: 0xEE7C90
void __fastcall OSuite::ZUtf8Buffer::Append(OSuite::ZUtf8Buffer *this, char ch)
{
  char pMemory; // [rsp+20h] [rbp-18h]

  pMemory = ch;
  OSuite::ZUtf8Buffer::Append(this, &pMemory, 1ui64);
}


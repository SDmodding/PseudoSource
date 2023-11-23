// File Line: 38
// RVA: 0xEE2AD8
void __fastcall OSuite::ZString::ZString(OSuite::ZString *this)
{
  this->m_pString = 0i64;
  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
  this->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
}

// File Line: 43
// RVA: 0xEE27EC
void __fastcall OSuite::ZString::ZString(OSuite::ZString *this, OSuite::ZRedBlackTreeBase *charList)
{
  char *m_pTop; // rdi
  unsigned __int64 v5; // rax

  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
  this->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
  m_pTop = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell(charList) )
    m_pTop = (char *)charList[1].m_pTop;
  v5 = OSuite::ZHttpStreamReader::Tell(charList);
  OSuite::ZString::InstantiateFrom(this, m_pTop, v5);
}

// File Line: 75
// RVA: 0xEE299C
void __fastcall OSuite::ZString::ZString(OSuite::ZString *this, const char *pszString)
{
  size_t v4; // rdi
  OSuite::ZString::InternalString *InternalString; // rax
  size_t v6; // rdx
  char v7; // al

  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
  this->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
  if ( pszString )
  {
    v4 = strlen(pszString);
    InternalString = OSuite::ZString::AllocateInternalString(v4 + 1);
    this->m_pString = InternalString;
    if ( InternalString )
    {
      v6 = 0i64;
      for ( InternalString->m_nLength = v4; v6 < v4; *((_BYTE *)&this->m_pString->m_nHash + v6 + 3) = v7 )
        v7 = pszString[v6++];
      this->m_pString->m_szString[v4] = 0;
      this->m_pString->m_nRefCount = 1;
      this->m_pString->m_nHash = 0;
    }
  }
  else
  {
    this->m_pString = 0i64;
  }
}

// File Line: 107
// RVA: 0xEE2A3C
void __fastcall OSuite::ZString::ZString(OSuite::ZString *this, const char *pszString, unsigned __int64 nLength)
{
  OSuite::ZString::InternalString *InternalString; // rax
  unsigned __int64 i; // rdx
  char v8; // al

  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
  this->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
  if ( pszString )
  {
    InternalString = OSuite::ZString::AllocateInternalString(nLength + 1);
    this->m_pString = InternalString;
    if ( InternalString )
    {
      for ( i = 0i64; i < nLength; *((_BYTE *)&this->m_pString->m_nHash + i + 3) = v8 )
        v8 = pszString[i++];
      this->m_pString->m_szString[nLength] = 0;
      this->m_pString->m_nLength = nLength;
      this->m_pString->m_nRefCount = 1;
      this->m_pString->m_nHash = 0;
    }
  }
  else
  {
    this->m_pString = 0i64;
  }
}

// File Line: 148
// RVA: 0xEE2854
void __fastcall OSuite::ZString::ZString(OSuite::ZString *this, int nNumber)
{
  unsigned __int64 v4; // rbx
  const char *v5; // rax
  OSuite::ZStringBuilder v6; // [rsp+20h] [rbp-48h] BYREF

  v6.m_Chars.m_pList = 0i64;
  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
  this->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
  OSuite::ZStringBuilder::ZStringBuilder(&v6, 0x10ui64);
  OSuite::ZStringBuilder::AppendInt(&v6, nNumber);
  v4 = OSuite::ZStringBuilder::Count(&v6);
  v5 = OSuite::ZStringBuilder::Buffer(&v6);
  OSuite::ZString::InstantiateFrom(this, v5, v4);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v6);
}

// File Line: 161
// RVA: 0xEE28F8
void __fastcall OSuite::ZString::ZString(OSuite::ZString *this, unsigned int nNumber)
{
  unsigned __int64 v4; // rbx
  const char *v5; // rax
  OSuite::ZStringBuilder v6; // [rsp+20h] [rbp-48h] BYREF

  v6.m_Chars.m_pList = 0i64;
  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
  this->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
  OSuite::ZStringBuilder::ZStringBuilder(&v6, 0x10ui64);
  OSuite::ZStringBuilder::AppendInt(&v6, nNumber);
  v4 = OSuite::ZStringBuilder::Count(&v6);
  v5 = OSuite::ZStringBuilder::Buffer(&v6);
  OSuite::ZString::InstantiateFrom(this, v5, v4);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v6);
}

// File Line: 174
// RVA: 0xEE2AF8
void __fastcall OSuite::ZString::ZString(OSuite::ZString *this, __int64 nNumber)
{
  unsigned __int64 v4; // rbx
  const char *v5; // rax
  OSuite::ZStringBuilder v6; // [rsp+20h] [rbp-48h] BYREF

  v6.m_Chars.m_pList = 0i64;
  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
  this->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
  OSuite::ZStringBuilder::ZStringBuilder(&v6, 0x18ui64);
  OSuite::ZStringBuilder::AppendInt(&v6, nNumber);
  v4 = OSuite::ZStringBuilder::Count(&v6);
  v5 = OSuite::ZStringBuilder::Buffer(&v6);
  OSuite::ZString::InstantiateFrom(this, v5, v4);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v6);
}

// File Line: 188
// RVA: 0xEE2B9C
void __fastcall OSuite::ZString::ZString(OSuite::ZString *this, unsigned __int64 nNumber)
{
  unsigned __int64 v4; // rbx
  const char *v5; // rax
  OSuite::ZStringBuilder v6; // [rsp+20h] [rbp-48h] BYREF

  v6.m_Chars.m_pList = 0i64;
  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
  this->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
  OSuite::ZStringBuilder::ZStringBuilder(&v6, 0x18ui64);
  OSuite::ZStringBuilder::AppendInt(&v6, nNumber);
  v4 = OSuite::ZStringBuilder::Count(&v6);
  v5 = OSuite::ZStringBuilder::Buffer(&v6);
  OSuite::ZString::InstantiateFrom(this, v5, v4);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v6);
}

// File Line: 220
// RVA: 0xEE2794
void __fastcall OSuite::ZString::ZString(OSuite::ZString *this, OSuite::ZString *that)
{
  OSuite::ZString::InternalString *m_pString; // rcx

  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
  this->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
  m_pString = that->m_pString;
  if ( m_pString )
  {
    OSuite::ZThread::AtomicAdd(&m_pString->m_nRefCount, 1);
    this->m_pString = that->m_pString;
  }
  else
  {
    this->m_pString = 0i64;
  }
}

// File Line: 239
// RVA: 0xEE2C40
void __fastcall OSuite::ZString::~ZString(OSuite::ZString *this)
{
  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
  this->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
  OSuite::ZString::DecreaseRefCount(this);
}

// File Line: 363
// RVA: 0xEE2D7C
__int64 __fastcall OSuite::ZString::operator bool(OSuite::ZString *this)
{
  OSuite::ZString::InternalString *m_pString; // rdx
  __int64 result; // rax

  m_pString = this->m_pString;
  result = 0i64;
  if ( m_pString )
  {
    if ( m_pString->m_nLength )
      return 1i64;
  }
  return result;
}

// File Line: 377
// RVA: 0xEE2C5C
OSuite::ZString *__fastcall OSuite::ZString::operator=(OSuite::ZString *this, OSuite::ZString *that)
{
  OSuite::ZString::InternalString *m_pString; // rcx

  if ( this != that )
  {
    m_pString = that->m_pString;
    if ( m_pString )
      OSuite::ZThread::AtomicAdd(&m_pString->m_nRefCount, 1);
    OSuite::ZString::DecreaseRefCount(this);
    this->m_pString = that->m_pString;
  }
  return this;
}

// File Line: 396
// RVA: 0xEE31B4
OSuite::IHashableVtbl *__fastcall OSuite::ZString::ComputeHash(OSuite::ZString *this)
{
  OSuite::IHashableVtbl *result; // rax
  char *pszString; // [rsp+30h] [rbp+8h] BYREF

  result = this->OSuite::IHashable::vfptr;
  if ( result )
  {
    if ( !LODWORD(result[1].__vecDelDtor) )
    {
      pszString = (char *)&result[1].__vecDelDtor + 4;
      LODWORD(this->OSuite::IHashable::vfptr[1].__vecDelDtor) = OSuite::FComputeHash<char const *>((const char *const *)&pszString) | 0x80000000;
    }
    return (OSuite::IHashableVtbl *)LODWORD(this->OSuite::IHashable::vfptr[1].__vecDelDtor);
  }
  return result;
}

// File Line: 417
// RVA: 0xEE2CA4
char __fastcall OSuite::ZString::operator==(OSuite::ZString *this, OSuite::ZString *that)
{
  char v2; // si
  unsigned int v5; // ebx
  OSuite::ZString::InternalString *m_pString; // rdx
  OSuite::ZString::InternalString *v7; // rcx

  v2 = 0;
  if ( this->m_pString )
    goto LABEL_12;
  if ( !that->m_pString )
    return 1;
  if ( this->m_pString )
  {
LABEL_12:
    if ( that->m_pString )
    {
      v5 = that->OSuite::IHashable::vfptr->ComputeHash(&that->OSuite::IHashable);
      if ( this->OSuite::IHashable::vfptr->ComputeHash(&this->OSuite::IHashable) == v5 )
      {
        m_pString = that->m_pString;
        v7 = this->m_pString;
        if ( v7->m_nLength == m_pString->m_nLength && !strcmp(v7->m_szString, m_pString->m_szString) )
          return 1;
      }
    }
  }
  return v2;
}

// File Line: 442
// RVA: 0xEE32E0
char __fastcall OSuite::ZString::EqualsCaseInsensitive(OSuite::ZString *this, const char *that)
{
  OSuite::ZString::InternalString *m_pString; // rax
  const char *v3; // r14
  OSuite::ZString::InternalString *v5; // r15
  char *m_szString; // r15
  char v7; // si
  char v8; // al
  int v9; // ebx
  int v10; // edi

  m_pString = this->m_pString;
  v3 = that;
  if ( !m_pString )
    return !that;
  if ( !that )
    return 0;
  v5 = this->m_pString;
  if ( m_pString->m_nLength != strlen(that) )
    return 0;
  m_szString = v5->m_szString;
  v7 = 1;
  v8 = *m_szString;
  if ( *m_szString )
  {
    do
    {
      if ( !*v3 )
        break;
      v9 = v8;
      v10 = tolower_0(*v3++);
      ++m_szString;
      if ( tolower_0(v9) != v10 )
        return 0;
      v8 = *m_szString;
    }
    while ( *m_szString );
    if ( *m_szString )
      return 0;
  }
  if ( *v3 )
    return 0;
  return v7;
}

// File Line: 472
// RVA: 0xEE2D40
char __fastcall OSuite::ZString::operator==(OSuite::ZString *this, const char *pszThat)
{
  OSuite::ZString::InternalString *m_pString; // rax
  char v3; // bl

  m_pString = this->m_pString;
  v3 = 0;
  if ( m_pString )
  {
    if ( pszThat )
      return strcmp(m_pString->m_szString, pszThat) == 0;
  }
  else if ( !pszThat )
  {
    return 1;
  }
  return v3;
}

// File Line: 483
// RVA: 0xEE30D4
bool __fastcall OSuite::ZString::operator<(OSuite::ZString *this, OSuite::ZString *that)
{
  OSuite::ZString::InternalString *m_pString; // rcx
  OSuite::ZString::InternalString *v4; // rdx

  m_pString = this->m_pString;
  if ( !m_pString )
    return that->m_pString != 0i64;
  v4 = that->m_pString;
  return v4 && strcmp(m_pString->m_szString, v4->m_szString) < 0;
}

// File Line: 570
// RVA: 0xEE2E98
OSuite::ZString *__fastcall OSuite::ZString::operator+(
        OSuite::ZString *this,
        OSuite::ZString *result,
        OSuite::ZString *that)
{
  OSuite::ZString::InternalString *m_pString; // rax
  unsigned __int64 m_nLength; // rcx
  OSuite::ZString::InternalString *v8; // rax
  unsigned __int64 v9; // rdx
  OSuite::ZString::InternalString *InternalString; // rax
  OSuite::ZString::InternalString *v11; // r14
  unsigned __int64 v12; // rdx
  OSuite::ZString *v13; // rdx

  m_pString = that->m_pString;
  if ( !m_pString )
    goto LABEL_8;
  m_nLength = m_pString->m_nLength;
  if ( !m_nLength )
    goto LABEL_8;
  v8 = this->m_pString;
  if ( !v8 || (v9 = v8->m_nLength) == 0 )
  {
    v13 = that;
LABEL_9:
    OSuite::ZString::ZString(result, v13);
    return result;
  }
  InternalString = OSuite::ZString::AllocateInternalString(v9 + m_nLength + 1);
  v11 = InternalString;
  if ( !InternalString )
  {
LABEL_8:
    v13 = this;
    goto LABEL_9;
  }
  memmove(InternalString->m_szString, this->m_pString->m_szString, this->m_pString->m_nLength);
  memmove(&v11->m_szString[this->m_pString->m_nLength], that->m_pString->m_szString, that->m_pString->m_nLength);
  v11->m_szString[this->m_pString->m_nLength + that->m_pString->m_nLength] = 0;
  v12 = this->m_pString->m_nLength + that->m_pString->m_nLength;
  v11->m_nHash = 0;
  v11->m_nRefCount = 1;
  v11->m_nLength = v12;
  result->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
  result->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
  result->m_pString = v11;
  return result;
}

// File Line: 606
// RVA: 0xEE2FB0
OSuite::ZString *__fastcall OSuite::ZString::operator+(
        OSuite::ZString *this,
        OSuite::ZString *result,
        const char *pszThat)
{
  OSuite::ZString::InternalString *m_pString; // rax
  size_t v7; // r15
  OSuite::ZString::InternalString *InternalString; // rax
  OSuite::ZString::InternalString *v9; // r14
  unsigned __int64 m_nLength; // rax
  OSuite::ZString *v11; // rdx

  if ( !pszThat || !*pszThat )
  {
    v11 = this;
    goto LABEL_10;
  }
  m_pString = this->m_pString;
  if ( !m_pString || !m_pString->m_nLength )
  {
    OSuite::ZString::ZString(result, pszThat);
    return result;
  }
  v7 = strlen(pszThat);
  InternalString = OSuite::ZString::AllocateInternalString(v7 + 1 + this->m_pString->m_nLength);
  v9 = InternalString;
  if ( !InternalString )
  {
    v11 = this;
LABEL_10:
    OSuite::ZString::ZString(result, v11);
    return result;
  }
  memmove(InternalString->m_szString, this->m_pString->m_szString, this->m_pString->m_nLength);
  memmove(&v9->m_szString[this->m_pString->m_nLength], pszThat, v7);
  v9->m_szString[this->m_pString->m_nLength + v7] = 0;
  m_nLength = this->m_pString->m_nLength;
  v9->m_nRefCount = 1;
  v9->m_nHash = 0;
  v9->m_nLength = v7 + m_nLength;
  result->m_pString = v9;
  result->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
  result->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
  return result;
}

// File Line: 756
// RVA: 0xEE3204
unsigned __int64 __fastcall OSuite::ZString::Count(OSuite::ZString *this)
{
  OSuite::ZString::InternalString *m_pString; // rdx
  unsigned __int64 result; // rax

  m_pString = this->m_pString;
  result = 0i64;
  if ( m_pString )
    return m_pString->m_nLength;
  return result;
}

// File Line: 765
// RVA: 0xEE324C
bool __fastcall OSuite::ZString::Empty(OSuite::ZString *this)
{
  OSuite::ZString::InternalString *m_pString; // rcx
  unsigned __int64 m_nLength; // rcx

  m_pString = this->m_pString;
  if ( m_pString )
    m_nLength = m_pString->m_nLength;
  else
    m_nLength = 0i64;
  return m_nLength == 0;
}

// File Line: 775
// RVA: 0xEE318C
char __fastcall OSuite::ZString::CharAt(OSuite::ZString *this, unsigned __int64 nIndex)
{
  OSuite::ZString::InternalString *m_pString; // rax
  unsigned __int64 m_nLength; // rcx

  m_pString = this->m_pString;
  if ( m_pString )
    m_nLength = m_pString->m_nLength;
  else
    m_nLength = 0i64;
  if ( nIndex < m_nLength && m_pString )
    return m_pString->m_szString[nIndex];
  else
    return -1;
}

// File Line: 786
// RVA: 0xEE33FC
__int64 __fastcall OSuite::ZString::IndexOf(OSuite::ZString *this, char ch, unsigned __int64 nStartFrom)
{
  OSuite::ZString::InternalString *m_pString; // r9
  __int64 m_nLength_low; // r10
  __int64 v5; // rax
  char *i; // rcx

  m_pString = this->m_pString;
  if ( !m_pString )
    return 0xFFFFFFFFi64;
  m_nLength_low = SLODWORD(m_pString->m_nLength);
  v5 = (int)nStartFrom;
  if ( (int)nStartFrom >= m_nLength_low )
    return 0xFFFFFFFFi64;
  for ( i = &m_pString->m_szString[(int)nStartFrom]; *i != ch; ++i )
  {
    ++v5;
    LODWORD(nStartFrom) = nStartFrom + 1;
    if ( v5 >= m_nLength_low )
      return 0xFFFFFFFFi64;
  }
  return (unsigned int)nStartFrom;
}

// File Line: 808
// RVA: 0xEE3398
__int64 __fastcall OSuite::ZString::IndexOf(
        OSuite::ZString *this,
        OSuite::ZString *InternalString,
        unsigned __int64 nStartFrom)
{
  OSuite::ZString::InternalString *m_pString; // r9
  OSuite::ZString::InternalString *v5; // rdx
  unsigned __int64 m_nLength; // rax
  unsigned __int64 v7; // rax
  char *v8; // rax

  m_pString = this->m_pString;
  if ( m_pString
    && ((v5 = InternalString->m_pString) == 0i64 ? (m_nLength = 0i64) : (m_nLength = v5->m_nLength),
        m_nLength
     && (!v5 ? (v7 = 0i64) : (v7 = v5->m_nLength),
         nStartFrom + v7 <= m_pString->m_nLength
      && (v8 = strstr(&m_pString->m_szString[nStartFrom], v5->m_szString)) != 0i64)) )
  {
    return (unsigned int)((_DWORD)v8 - LODWORD(this->m_pString) - 20);
  }
  else
  {
    return 0xFFFFFFFFi64;
  }
}

// File Line: 818
// RVA: 0xEE34B8
__int64 __fastcall OSuite::ZString::LastIndexOf(OSuite::ZString *this, char ch)
{
  OSuite::ZString::InternalString *m_pString; // r8
  __int64 result; // rax
  __int64 v4; // rcx
  char *i; // r9

  m_pString = this->m_pString;
  if ( !m_pString )
    return 0xFFFFFFFFi64;
  result = SLODWORD(m_pString->m_nLength);
  v4 = result;
  if ( (int)result < 0 )
    return 0xFFFFFFFFi64;
  for ( i = &m_pString->m_szString[result]; *i != ch; --i )
  {
    result = (unsigned int)(result - 1);
    if ( --v4 < 0 )
      return 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 838
// RVA: 0xEE37F8
OSuite::ZString *__fastcall OSuite::ZString::ToLower(OSuite::ZString *this, OSuite::ZString *result)
{
  OSuite::ZString::InternalString *m_pString; // rcx
  OSuite::ZString *v4; // rbx
  OSuite::ZString::InternalString *InternalString; // rax
  OSuite::ZString::InternalString *v6; // r14
  char v7; // bp
  char *m_szString; // r12
  char *v9; // rdi
  char v10; // r15
  char v11; // al
  bool v12; // zf
  signed __int64 v13; // rdi

  m_pString = this->m_pString;
  v4 = result;
  if ( m_pString )
  {
    InternalString = OSuite::ZString::AllocateInternalString(m_pString->m_nLength + 1);
    v6 = InternalString;
    if ( InternalString )
    {
      v7 = 0;
      m_szString = InternalString->m_szString;
      v9 = this->m_pString->m_szString;
      v10 = *v9;
      if ( *v9 )
      {
        do
        {
          ++v9;
          v11 = tolower_0(v10);
          *m_szString++ = v11;
          v12 = v10 == v11;
          v10 = *v9;
          if ( !v12 )
            v7 = 1;
        }
        while ( v10 );
        v4 = result;
        if ( v7 )
        {
          *m_szString = 0;
          v13 = v9 - (char *)this->m_pString;
          v6->m_nRefCount = 1;
          v6->m_nHash = 0;
          v6->m_nLength = v13 - 20;
          result->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
          result->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
          result->m_pString = v6;
          return v4;
        }
      }
      OSuite::ZObject::free(this, v6);
    }
    OSuite::ZString::ZString(v4, this);
    return v4;
  }
  result->m_pString = 0i64;
  result->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
  result->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
  return v4;
}

// File Line: 886
// RVA: 0xEE390C
OSuite::ZString *__fastcall OSuite::ZString::Trim(OSuite::ZString *this, OSuite::ZString *result)
{
  OSuite::ZString::InternalString *m_pString; // rsi
  const char *i; // rsi
  unsigned __int8 *v6; // rbx
  unsigned __int8 *v7; // r14

  m_pString = this->m_pString;
  if ( m_pString )
  {
    for ( i = m_pString->m_szString; *i && isspace(*(unsigned __int8 *)i); ++i )
      ;
    v6 = (unsigned __int8 *)&this->m_pString->m_nHash + this->m_pString->m_nLength + 3;
    v7 = v6;
    while ( v6 > (unsigned __int8 *)i && isspace(*v6) )
      --v6;
    if ( i == this->m_pString->m_szString && v6 == v7 )
      OSuite::ZString::ZString(result, this);
    else
      OSuite::ZString::ZString(result, i, v6 - (unsigned __int8 *)i + 1);
  }
  else
  {
    result->m_pString = 0i64;
    result->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
    result->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
  }
  return result;
}

// File Line: 920
// RVA: 0xEE3530
OSuite::ZString *__fastcall OSuite::ZString::Slice(
        OSuite::ZString *this,
        OSuite::ZString *result,
        unsigned __int64 nStart,
        unsigned __int64 nLength)
{
  OSuite::ZString::InternalString *m_pString; // rax

  m_pString = this->m_pString;
  if ( m_pString && nStart + nLength <= m_pString->m_nLength && nStart + nLength )
  {
    if ( nStart || nLength != m_pString->m_nLength )
      OSuite::ZString::ZString(result, &m_pString->m_szString[nStart], nLength);
    else
      OSuite::ZString::ZString(result, this);
  }
  else
  {
    result->m_pString = 0i64;
    result->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
    result->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
  }
  return result;
}

// File Line: 956
// RVA: 0xEE35A0
OSuite::ZString *__fastcall OSuite::ZString::Slice(
        OSuite::ZString *this,
        OSuite::ZString *result,
        unsigned __int64 nStart)
{
  OSuite::ZString::InternalString *m_pString; // r9

  m_pString = this->m_pString;
  if ( m_pString )
  {
    if ( nStart )
      OSuite::ZString::Slice(this, result, nStart, m_pString->m_nLength - nStart);
    else
      OSuite::ZString::ZString(result, this);
  }
  else
  {
    result->m_pString = 0i64;
    result->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
    result->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
  }
  return result;
}

// File Line: 973
// RVA: 0xEE39E0
char *__fastcall OSuite::ZString::c_str(OSuite::ZString *this)
{
  OSuite::ZString::InternalString *m_pString; // rdx
  char *result; // rax

  m_pString = this->m_pString;
  result = 0i64;
  if ( m_pString )
    return m_pString->m_szString;
  return result;
}

// File Line: 989
// RVA: 0xEE37B0
__int64 __fastcall OSuite::ZString::ToInt(OSuite::ZString *this)
{
  OSuite::ZString::InternalString *m_pString; // r8
  __int64 v2; // rdx
  char *m_szString; // r8
  char v4; // r9
  char v5; // al

  m_pString = this->m_pString;
  v2 = 0i64;
  if ( m_pString )
  {
    m_szString = m_pString->m_szString;
    v4 = 0;
    if ( *m_szString != 45 )
      goto LABEL_7;
    v4 = 1;
    while ( 1 )
    {
      ++m_szString;
LABEL_7:
      v5 = *m_szString;
      if ( *m_szString < 48 || v5 > 57 )
        break;
      v2 = v5 - 48 + 10 * v2;
    }
    if ( v4 )
      return -v2;
  }
  return v2;
}

// File Line: 1039
// RVA: 0xEE3778
bool __fastcall OSuite::ZString::StartsWith(OSuite::ZString *this, const char *pszStr)
{
  OSuite::ZString::InternalString *m_pString; // r8
  bool v3; // zf
  char *i; // r8

  m_pString = this->m_pString;
  if ( !m_pString )
    return pszStr == 0i64;
  v3 = pszStr == 0i64;
  if ( pszStr )
  {
    for ( i = m_pString->m_szString; *pszStr && *i && *pszStr == *i; ++i )
      ++pszStr;
    return *pszStr == 0;
  }
  return v3;
}

// File Line: 1056
// RVA: 0xEE3764
bool __fastcall OSuite::ZString::StartsWith(OSuite::ZString *this, OSuite::ZString *sStr)
{
  OSuite::ZString::InternalString *m_pString; // rax
  const char *m_szString; // rdx

  m_pString = sStr->m_pString;
  m_szString = 0i64;
  if ( m_pString )
    m_szString = m_pString->m_szString;
  return OSuite::ZString::StartsWith(this, m_szString);
}

// File Line: 1061
// RVA: 0xEE3268
bool __fastcall OSuite::ZString::EndsWith(OSuite::ZString *this, const char *pszStr)
{
  const char *v2; // rdi
  bool v4; // zf
  size_t v5; // rax
  OSuite::ZString::InternalString *m_pString; // rdx
  size_t v7; // rcx
  unsigned __int64 m_nLength; // rax
  char *i; // rcx

  v2 = pszStr;
  if ( !this->m_pString )
    return pszStr == 0i64;
  v4 = pszStr == 0i64;
  if ( pszStr )
  {
    v5 = strlen(pszStr);
    m_pString = this->m_pString;
    v7 = v5;
    m_nLength = m_pString->m_nLength;
    if ( v7 > m_nLength )
      return 0;
    for ( i = &m_pString->m_szString[m_nLength - v7]; *v2 && *i && *v2 == *i; ++i )
      ++v2;
    return *v2 == 0;
  }
  return v4;
}

// File Line: 1090
// RVA: 0xEE35F4
void __fastcall OSuite::ZString::Split(OSuite::ZString *this, OSuite::TList<OSuite::ZString> *pList, char nChar)
{
  OSuite::ZString::InternalString *m_pString; // rbx
  OSuite::ZString *m_pList; // rcx
  OSuite::ZString *v7; // rax
  int v8; // ebp
  char *v9; // rax
  char *v10; // rsi
  OSuite::ZString *v11; // rax
  OSuite::ZString *v12; // rbx
  OSuite::ZString that; // [rsp+20h] [rbp-38h] BYREF

  m_pString = this->m_pString;
  if ( m_pString )
    m_pString = (OSuite::ZString::InternalString *)((char *)m_pString + 20);
  if ( pList && m_pString )
  {
    m_pList = pList->m_pList;
    if ( m_pList )
    {
      if ( LODWORD(m_pList[-1].m_pString) )
        m_pList->OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 3u);
      else
        Illusion::ShaderParam::operator delete(&m_pList[-1].m_pString);
    }
    v7 = OSuite::TList<OSuite::ZString>::AllocList(pList, pList->m_pList, 0x10ui64);
    pList->m_nTop = 0i64;
    pList->m_nSize = 16i64;
    pList->m_pList = v7;
    if ( LOBYTE(m_pString->m_nRefCount) )
    {
      v8 = nChar;
      while ( 1 )
      {
        v9 = strchr((const char *)m_pString, v8);
        v10 = v9;
        if ( !v9 )
          break;
        OSuite::ZString::ZString(&that, (const char *)m_pString, v9 - (char *)m_pString);
        v12 = v11;
        OSuite::TList<OSuite::ZString>::Grow(pList, pList->m_nTop + 1);
        OSuite::ZString::operator=(&pList->m_pList[pList->m_nTop], v12);
        ++pList->m_nTop;
        that.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
        that.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
        OSuite::ZString::DecreaseRefCount(&that);
        m_pString = (OSuite::ZString::InternalString *)(v10 + 1);
        if ( !v10[1] )
          return;
      }
      OSuite::ZString::ZString(&that, (const char *)m_pString);
      OSuite::TList<OSuite::ZString>::Grow(pList, pList->m_nTop + 1);
      OSuite::ZString::operator=(&pList->m_pList[pList->m_nTop], &that);
      ++pList->m_nTop;
      that.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
      that.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
      OSuite::ZString::DecreaseRefCount(&that);
    }
  }
}

// File Line: 1113
// RVA: 0xEE34AC
_BOOL8 __fastcall OSuite::ZString::IsNull(OSuite::ZString *this)
{
  return this->m_pString == 0i64;
}

// File Line: 1148
// RVA: 0xEE34E8
__int64 __fastcall OSuite::ZString::ReplaceChar(
        OSuite::ZString *this,
        char oldCh,
        char newCh,
        unsigned __int64 nStartFrom,
        bool bAll)
{
  OSuite::ZString::InternalString *m_pString; // rax
  unsigned int v6; // r10d
  __int64 i; // r8

  m_pString = this->m_pString;
  v6 = -1;
  if ( m_pString && oldCh )
  {
    for ( i = (int)nStartFrom; (int)nStartFrom < SLODWORD(m_pString->m_nLength); ++i )
    {
      if ( m_pString->m_szString[i] == oldCh )
      {
        m_pString->m_szString[i] = newCh;
        v6 = nStartFrom;
        if ( !bAll || !newCh )
          break;
      }
      m_pString = this->m_pString;
      LODWORD(nStartFrom) = nStartFrom + 1;
    }
  }
  return v6;
}

// File Line: 1172
// RVA: 0xEE3434
void __fastcall OSuite::ZString::InstantiateFrom(OSuite::ZString *this, const char *pszString, size_t nLength)
{
  OSuite::ZString::InternalString *InternalString; // rax

  if ( pszString )
  {
    InternalString = OSuite::ZString::AllocateInternalString(nLength + 1);
    this->m_pString = InternalString;
    if ( InternalString )
    {
      memmove(InternalString->m_szString, pszString, nLength);
      this->m_pString->m_szString[nLength] = 0;
      this->m_pString->m_nLength = nLength;
      this->m_pString->m_nRefCount = 1;
      this->m_pString->m_nHash = 0;
    }
  }
  else
  {
    this->m_pString = 0i64;
  }
}

// File Line: 1192
// RVA: 0xEE3214
void __fastcall OSuite::ZString::DecreaseRefCount(OSuite::ZString *this)
{
  OSuite::ZString::InternalString *m_pString; // rcx

  m_pString = this->m_pString;
  if ( m_pString )
  {
    if ( OSuite::ZThread::AtomicAdd(&m_pString->m_nRefCount, -1) == 1 )
    {
      OSuite::ZObject::free(this, this->m_pString);
      this->m_pString = 0i64;
    }
  }
}

// File Line: 1218
// RVA: 0xEE3120
OSuite::ZString::InternalString *__fastcall OSuite::ZString::AllocateInternalString(unsigned __int64 length)
{
  char v2[32]; // [rsp+20h] [rbp-38h] BYREF

  strcpy(v2, "ZString::AllocateInternalString");
  return (OSuite::ZString::InternalString *)OSuite::ZObject::m_allocator->vfptr->malloc(
                                              OSuite::ZObject::m_allocator,
                                              length + 24,
                                              v2);
}

// File Line: 1227
// RVA: 0xEE2D94
OSuite::ZString *__fastcall OSuite::operator+(
        OSuite::ZString *result,
        const char *pszString1,
        OSuite::ZString *InternalString2)
{
  OSuite::ZString *v5; // rbx
  OSuite::ZString *v6; // rdx
  OSuite::ZString::InternalString *m_pString; // rax
  unsigned __int64 m_nLength; // rcx
  size_t v9; // r15
  size_t v10; // rbp
  OSuite::ZString::InternalString *InternalString; // rax
  OSuite::ZString::InternalString *v12; // r14

  v5 = result;
  if ( !pszString1 )
  {
    v6 = InternalString2;
LABEL_3:
    OSuite::ZString::ZString(result, v6);
    return v5;
  }
  m_pString = InternalString2->m_pString;
  if ( m_pString )
    m_nLength = m_pString->m_nLength;
  else
    m_nLength = 0i64;
  if ( !m_nLength )
  {
    OSuite::ZString::ZString(v5, pszString1);
    return v5;
  }
  v9 = strlen(pszString1);
  if ( !v9 )
  {
    v6 = InternalString2;
    result = v5;
    goto LABEL_3;
  }
  v10 = v9 + InternalString2->m_pString->m_nLength;
  InternalString = OSuite::ZString::AllocateInternalString(v10 + 1);
  v12 = InternalString;
  if ( InternalString )
  {
    memmove(InternalString->m_szString, pszString1, v9);
    memmove(&v12->m_szString[v9], InternalString2->m_pString->m_szString, InternalString2->m_pString->m_nLength);
    v12->m_szString[v10] = 0;
    v12->m_nHash = 0;
    v12->m_nLength = v10;
    v12->m_nRefCount = 1;
    v5->m_pString = v12;
  }
  else
  {
    v5->m_pString = 0i64;
  }
  v5->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable{for `OSuite::ZObject};
  v5->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable{for `OSuite::IHashable};
  return v5;
}


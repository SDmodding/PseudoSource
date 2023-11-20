// File Line: 38
// RVA: 0xEE2AD8
void __fastcall OSuite::ZString::ZString(OSuite::ZString *this)
{
  this->m_pString = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
  this->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
}

// File Line: 43
// RVA: 0xEE27EC
void __fastcall OSuite::ZString::ZString(OSuite::ZString *this, OSuite::TList<char> *charList)
{
  OSuite::ZString *v2; // rsi
  OSuite::ZRedBlackTreeBase *v3; // rbx
  const char *v4; // rdi
  unsigned __int64 v5; // rax

  v2 = this;
  v3 = (OSuite::ZRedBlackTreeBase *)charList;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
  this->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
  v4 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)charList) )
    v4 = (const char *)v3[1].m_pTop;
  v5 = OSuite::ZHttpStreamReader::Tell(v3);
  OSuite::ZString::InstantiateFrom(v2, v4, v5);
}

// File Line: 75
// RVA: 0xEE299C
void __fastcall OSuite::ZString::ZString(OSuite::ZString *this, const char *pszString)
{
  const char *v2; // rsi
  OSuite::ZString *v3; // rbx
  size_t v4; // rax
  unsigned __int64 v5; // rdi
  OSuite::ZString::InternalString *v6; // rax
  unsigned __int64 v7; // rdx
  char v8; // al

  v2 = pszString;
  v3 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
  this->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
  if ( pszString )
  {
    v4 = strlen(pszString);
    v5 = v4;
    v6 = OSuite::ZString::AllocateInternalString(v4 + 1);
    v3->m_pString = v6;
    if ( v6 )
    {
      v7 = 0i64;
      v6->m_nLength = v5;
      if ( v5 )
      {
        do
        {
          v8 = v2[v7++];
          *((_BYTE *)&v3->m_pString->m_nHash + v7 + 3) = v8;
        }
        while ( v7 < v5 );
      }
      v3->m_pString->m_szString[v5] = 0;
      v3->m_pString->m_nRefCount = 1;
      v3->m_pString->m_nHash = 0;
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
  unsigned __int64 v3; // rdi
  const char *v4; // rsi
  OSuite::ZString *v5; // rbx
  OSuite::ZString::InternalString *v6; // rax
  unsigned __int64 v7; // rdx
  char v8; // al

  v3 = nLength;
  v4 = pszString;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
  v5 = this;
  this->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
  if ( pszString )
  {
    v6 = OSuite::ZString::AllocateInternalString(nLength + 1);
    v5->m_pString = v6;
    if ( v6 )
    {
      v7 = 0i64;
      if ( v3 )
      {
        do
        {
          v8 = v4[v7++];
          *((_BYTE *)&v5->m_pString->m_nHash + v7 + 3) = v8;
        }
        while ( v7 < v3 );
      }
      v5->m_pString->m_szString[v3] = 0;
      v5->m_pString->m_nLength = v3;
      v5->m_pString->m_nRefCount = 1;
      v5->m_pString->m_nHash = 0;
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
  OSuite::ZString *v2; // rdi
  int v3; // ebx
  unsigned __int64 v4; // rbx
  const char *v5; // rax
  OSuite::ZStringBuilder v6; // [rsp+20h] [rbp-48h]

  v6.m_Chars.m_pList = 0i64;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
  v3 = nNumber;
  this->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
  OSuite::ZStringBuilder::ZStringBuilder(&v6, 0x10ui64);
  OSuite::ZStringBuilder::AppendInt(&v6, v3);
  v4 = OSuite::ZStringBuilder::Count(&v6);
  v5 = OSuite::ZStringBuilder::Buffer(&v6);
  OSuite::ZString::InstantiateFrom(v2, v5, v4);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v6);
}

// File Line: 161
// RVA: 0xEE28F8
void __fastcall OSuite::ZString::ZString(OSuite::ZString *this, unsigned int nNumber)
{
  OSuite::ZString *v2; // rdi
  unsigned int v3; // ebx
  unsigned __int64 v4; // rbx
  const char *v5; // rax
  OSuite::ZStringBuilder v6; // [rsp+20h] [rbp-48h]

  v6.m_Chars.m_pList = 0i64;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
  v3 = nNumber;
  this->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
  OSuite::ZStringBuilder::ZStringBuilder(&v6, 0x10ui64);
  OSuite::ZStringBuilder::AppendInt(&v6, v3);
  v4 = OSuite::ZStringBuilder::Count(&v6);
  v5 = OSuite::ZStringBuilder::Buffer(&v6);
  OSuite::ZString::InstantiateFrom(v2, v5, v4);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v6);
}

// File Line: 174
// RVA: 0xEE2AF8
void __fastcall OSuite::ZString::ZString(OSuite::ZString *this, __int64 nNumber)
{
  OSuite::ZString *v2; // rdi
  __int64 v3; // rbx
  unsigned __int64 v4; // rbx
  const char *v5; // rax
  OSuite::ZStringBuilder v6; // [rsp+20h] [rbp-48h]

  v6.m_Chars.m_pList = 0i64;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
  v3 = nNumber;
  this->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
  OSuite::ZStringBuilder::ZStringBuilder(&v6, 0x18ui64);
  OSuite::ZStringBuilder::AppendInt(&v6, v3);
  v4 = OSuite::ZStringBuilder::Count(&v6);
  v5 = OSuite::ZStringBuilder::Buffer(&v6);
  OSuite::ZString::InstantiateFrom(v2, v5, v4);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v6);
}

// File Line: 188
// RVA: 0xEE2B9C
void __fastcall OSuite::ZString::ZString(OSuite::ZString *this, unsigned __int64 nNumber)
{
  OSuite::ZString *v2; // rdi
  unsigned __int64 v3; // rbx
  unsigned __int64 v4; // rbx
  const char *v5; // rax
  OSuite::ZStringBuilder v6; // [rsp+20h] [rbp-48h]

  v6.m_Chars.m_pList = 0i64;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
  v3 = nNumber;
  this->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
  OSuite::ZStringBuilder::ZStringBuilder(&v6, 0x18ui64);
  OSuite::ZStringBuilder::AppendInt(&v6, v3);
  v4 = OSuite::ZStringBuilder::Count(&v6);
  v5 = OSuite::ZStringBuilder::Buffer(&v6);
  OSuite::ZString::InstantiateFrom(v2, v5, v4);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v6);
}

// File Line: 220
// RVA: 0xEE2794
void __fastcall OSuite::ZString::ZString(OSuite::ZString *this, OSuite::ZString *that)
{
  OSuite::ZString *v2; // rbx
  OSuite::ZString *v3; // rdi
  OSuite::ZString::InternalString *v4; // rcx

  v2 = this;
  v3 = that;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
  this->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
  v4 = that->m_pString;
  if ( v4 )
  {
    OSuite::ZThread::AtomicAdd(&v4->m_nRefCount, 1);
    v2->m_pString = v3->m_pString;
  }
  else
  {
    v2->m_pString = 0i64;
  }
}

// File Line: 239
// RVA: 0xEE2C40
void __fastcall OSuite::ZString::~ZString(OSuite::ZString *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
  this->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
  OSuite::ZString::DecreaseRefCount(this);
}

// File Line: 363
// RVA: 0xEE2D7C
signed __int64 __fastcall OSuite::ZString::operator bool(OSuite::ZString *this)
{
  OSuite::ZString::InternalString *v1; // rdx
  signed __int64 result; // rax

  v1 = this->m_pString;
  result = 0i64;
  if ( v1 )
  {
    if ( v1->m_nLength )
      result = 1i64;
  }
  return result;
}

// File Line: 377
// RVA: 0xEE2C5C
OSuite::ZString *__fastcall OSuite::ZString::operator=(OSuite::ZString *this, OSuite::ZString *that)
{
  OSuite::ZString *v2; // rdi
  OSuite::ZString *v3; // rbx
  OSuite::ZString::InternalString *v4; // rcx

  v2 = that;
  v3 = this;
  if ( this != that )
  {
    v4 = that->m_pString;
    if ( v4 )
      OSuite::ZThread::AtomicAdd(&v4->m_nRefCount, 1);
    OSuite::ZString::DecreaseRefCount(v3);
    v3->m_pString = v2->m_pString;
  }
  return v3;
}

// File Line: 396
// RVA: 0xEE31B4
OSuite::IHashableVtbl *__fastcall OSuite::ZString::ComputeHash(OSuite::ZString *this)
{
  OSuite::IHashableVtbl *result; // rax
  OSuite::ZString *v2; // rbx
  char *pszString; // [rsp+30h] [rbp+8h]

  result = this->vfptr;
  v2 = this;
  if ( result )
  {
    if ( !LODWORD(result[1].__vecDelDtor) )
    {
      if ( result )
        pszString = (char *)&result[1].__vecDelDtor + 4;
      else
        pszString = 0i64;
      LODWORD(this->vfptr[1].__vecDelDtor) = OSuite::FComputeHash<char const *>((const char *const *)&pszString) | 0x80000000;
    }
    result = (OSuite::IHashableVtbl *)LODWORD(v2->vfptr[1].__vecDelDtor);
  }
  return result;
}

// File Line: 417
// RVA: 0xEE2CA4
char __fastcall OSuite::ZString::operator==(OSuite::ZString *this, OSuite::ZString *that)
{
  char v2; // si
  OSuite::ZString *v3; // rbp
  OSuite::ZString *v4; // r14
  int v5; // ebx
  OSuite::ZString::InternalString *v6; // rdx
  OSuite::ZString::InternalString *v7; // rcx

  v2 = 0;
  v3 = that;
  v4 = this;
  if ( this->m_pString )
    goto LABEL_12;
  if ( !that->m_pString )
    return 1;
  if ( this->m_pString )
  {
LABEL_12:
    if ( that->m_pString )
    {
      v5 = ((__int64 (*)(void))that->vfptr->ComputeHash)();
      if ( v4->vfptr->ComputeHash((OSuite::IHashable *)&v4->vfptr) == v5 )
      {
        v6 = v3->m_pString;
        v7 = v4->m_pString;
        if ( v7->m_nLength == v6->m_nLength && !strcmp(v7->m_szString, v6->m_szString) )
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
  OSuite::ZString::InternalString *v2; // rax
  const char *v3; // r14
  OSuite::ZString::InternalString *v5; // r15
  char *v6; // r15
  char v7; // si
  char v8; // al
  int v9; // ebx
  int v10; // edi

  v2 = this->m_pString;
  v3 = that;
  if ( !v2 )
  {
    if ( !that )
      return 1;
    return 0;
  }
  if ( !that )
    return 0;
  v5 = this->m_pString;
  if ( v2->m_nLength != strlen(that) )
    return 0;
  v6 = v5->m_szString;
  v7 = 1;
  v8 = *v6;
  if ( *v6 )
  {
    do
    {
      if ( !*v3 )
        break;
      v9 = v8;
      v10 = tolower_0(*v3++);
      ++v6;
      if ( tolower_0(v9) != v10 )
        return 0;
      v8 = *v6;
    }
    while ( *v6 );
    if ( *v6 )
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
  OSuite::ZString::InternalString *v2; // rax
  char v3; // bl

  v2 = this->m_pString;
  v3 = 0;
  if ( !v2 )
    goto LABEL_10;
  if ( pszThat )
    return strcmp(v2->m_szString, pszThat) == 0;
  if ( !v2 )
  {
LABEL_10:
    if ( !pszThat )
      v3 = 1;
  }
  return v3;
}

// File Line: 483
// RVA: 0xEE30D4
bool __fastcall OSuite::ZString::operator<(OSuite::ZString *this, OSuite::ZString *that)
{
  OSuite::ZString::InternalString *v2; // rcx
  bool result; // al
  OSuite::ZString::InternalString *v4; // rdx

  v2 = this->m_pString;
  if ( !v2 )
    return that->m_pString != 0i64;
  v4 = that->m_pString;
  if ( v4 )
    result = strcmp(v2->m_szString, v4->m_szString) < 0;
  else
    result = 0;
  return result;
}

// File Line: 570
// RVA: 0xEE2E98
OSuite::ZString *__fastcall OSuite::ZString::operator+(OSuite::ZString *this, OSuite::ZString *result, OSuite::ZString *that)
{
  OSuite::ZString::InternalString *v3; // rax
  OSuite::ZString *v4; // rsi
  OSuite::ZString *v5; // rbx
  OSuite::ZString *v6; // rdi
  unsigned __int64 v7; // rcx
  OSuite::ZString::InternalString *v8; // rax
  unsigned __int64 v9; // rdx
  OSuite::ZString::InternalString *v10; // rax
  OSuite::ZString::InternalString *v11; // r14
  unsigned __int64 v12; // rdx
  OSuite::ZString *v13; // rdx

  v3 = that->m_pString;
  v4 = that;
  v5 = result;
  v6 = this;
  if ( !v3 )
    goto LABEL_13;
  v7 = v3->m_nLength;
  if ( !v7 )
    goto LABEL_13;
  v8 = v6->m_pString;
  if ( !v8 || (v9 = v8->m_nLength) == 0 )
  {
    v13 = that;
LABEL_9:
    OSuite::ZString::ZString(v5, v13);
    return v5;
  }
  v10 = OSuite::ZString::AllocateInternalString(v9 + v7 + 1);
  v11 = v10;
  if ( !v10 )
  {
LABEL_13:
    v13 = v6;
    goto LABEL_9;
  }
  memmove(v10->m_szString, v6->m_pString->m_szString, v6->m_pString->m_nLength);
  memmove(&v11->m_szString[v6->m_pString->m_nLength], v4->m_pString->m_szString, v4->m_pString->m_nLength);
  v11->m_szString[v6->m_pString->m_nLength + v4->m_pString->m_nLength] = 0;
  v12 = v6->m_pString->m_nLength + v4->m_pString->m_nLength;
  v11->m_nHash = 0;
  v11->m_nRefCount = 1;
  v11->m_nLength = v12;
  v5->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
  v5->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
  v5->m_pString = v11;
  return v5;
}

// File Line: 606
// RVA: 0xEE2FB0
OSuite::ZString *__fastcall OSuite::ZString::operator+(OSuite::ZString *this, OSuite::ZString *result, const char *pszThat)
{
  const char *v3; // rsi
  OSuite::ZString *v4; // rbx
  OSuite::ZString *v5; // rdi
  OSuite::ZString::InternalString *v6; // rax
  size_t v7; // rax
  size_t v8; // r15
  OSuite::ZString::InternalString *v9; // rax
  OSuite::ZString::InternalString *v10; // r14
  unsigned __int64 v11; // rax
  OSuite::ZString *v12; // rdx

  v3 = pszThat;
  v4 = result;
  v5 = this;
  if ( !pszThat || !*pszThat )
  {
    v12 = this;
    goto LABEL_10;
  }
  v6 = this->m_pString;
  if ( !v6 || !v6->m_nLength )
  {
    OSuite::ZString::ZString(result, pszThat);
    return v4;
  }
  v7 = strlen(pszThat);
  v8 = v7;
  v9 = OSuite::ZString::AllocateInternalString(v7 + 1 + v5->m_pString->m_nLength);
  v10 = v9;
  if ( !v9 )
  {
    v12 = v5;
LABEL_10:
    OSuite::ZString::ZString(v4, v12);
    return v4;
  }
  memmove(v9->m_szString, v5->m_pString->m_szString, v5->m_pString->m_nLength);
  memmove(&v10->m_szString[v5->m_pString->m_nLength], v3, v8);
  v10->m_szString[v5->m_pString->m_nLength + v8] = 0;
  v11 = v5->m_pString->m_nLength;
  v10->m_nRefCount = 1;
  v10->m_nHash = 0;
  v10->m_nLength = v8 + v11;
  v4->m_pString = v10;
  v4->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
  v4->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
  return v4;
}

// File Line: 756
// RVA: 0xEE3204
unsigned __int64 __fastcall OSuite::ZString::Count(OSuite::ZString *this)
{
  OSuite::ZString::InternalString *v1; // rdx
  unsigned __int64 result; // rax

  v1 = this->m_pString;
  result = 0i64;
  if ( v1 )
    result = v1->m_nLength;
  return result;
}

// File Line: 765
// RVA: 0xEE324C
bool __fastcall OSuite::ZString::Empty(OSuite::ZString *this)
{
  OSuite::ZString::InternalString *v1; // rcx
  unsigned __int64 v2; // rcx

  v1 = this->m_pString;
  if ( v1 )
    v2 = v1->m_nLength;
  else
    v2 = 0i64;
  return v2 == 0;
}

// File Line: 775
// RVA: 0xEE318C
char __fastcall OSuite::ZString::CharAt(OSuite::ZString *this, unsigned __int64 nIndex)
{
  OSuite::ZString::InternalString *v2; // rax
  unsigned __int64 v3; // rcx
  char v4; // cl

  v2 = this->m_pString;
  if ( v2 )
    v3 = v2->m_nLength;
  else
    v3 = 0i64;
  if ( nIndex < v3 && v2 )
    v4 = v2->m_szString[nIndex];
  else
    v4 = -1;
  return v4;
}

// File Line: 786
// RVA: 0xEE33FC
signed __int64 __fastcall OSuite::ZString::IndexOf(OSuite::ZString *this, char ch, unsigned __int64 nStartFrom)
{
  OSuite::ZString::InternalString *v3; // r9
  signed __int64 v4; // r10
  signed __int64 v5; // rax
  char *v6; // rcx

  v3 = this->m_pString;
  if ( !v3 )
    return 0xFFFFFFFFi64;
  v4 = SLODWORD(v3->m_nLength);
  v5 = (signed int)nStartFrom;
  if ( (signed int)nStartFrom >= v4 )
    return 0xFFFFFFFFi64;
  v6 = &v3->m_szString[(signed int)nStartFrom];
  while ( *v6 != ch )
  {
    ++v5;
    LODWORD(nStartFrom) = nStartFrom + 1;
    ++v6;
    if ( v5 >= v4 )
      return 0xFFFFFFFFi64;
  }
  return (unsigned int)nStartFrom;
}

// File Line: 808
// RVA: 0xEE3398
signed __int64 __fastcall OSuite::ZString::IndexOf(OSuite::ZString *this, OSuite::ZString *InternalString, unsigned __int64 nStartFrom)
{
  OSuite::ZString::InternalString *v3; // r9
  OSuite::ZString *v4; // rbx
  OSuite::ZString::InternalString *v5; // rdx
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rax
  char *v8; // rax
  signed __int64 result; // rax

  v3 = this->m_pString;
  v4 = this;
  if ( v3
    && ((v5 = InternalString->m_pString) == 0i64 ? (v6 = 0i64) : (v6 = v5->m_nLength),
        v6
     && (!v5 ? (v7 = 0i64) : (v7 = v5->m_nLength),
         nStartFrom + v7 <= v3->m_nLength && (v8 = strstr(&v3->m_szString[nStartFrom], v5->m_szString)) != 0i64)) )
  {
    result = (unsigned int)((_DWORD)v8 - LODWORD(v4->m_pString) - 20);
  }
  else
  {
    result = 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 818
// RVA: 0xEE34B8
signed __int64 __fastcall OSuite::ZString::LastIndexOf(OSuite::ZString *this, char ch)
{
  OSuite::ZString::InternalString *v2; // r8
  signed __int64 result; // rax
  signed __int64 v4; // rcx
  char *v5; // r9

  v2 = this->m_pString;
  if ( !v2 )
    return 0xFFFFFFFFi64;
  result = SLODWORD(v2->m_nLength);
  v4 = result;
  if ( (signed int)result < 0 )
    return 0xFFFFFFFFi64;
  v5 = &v2->m_szString[result];
  while ( *v5 != ch )
  {
    result = (unsigned int)(result - 1);
    --v5;
    if ( --v4 < 0 )
      return 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 838
// RVA: 0xEE37F8
OSuite::ZString *__fastcall OSuite::ZString::ToLower(OSuite::ZString *this, OSuite::ZString *result)
{
  OSuite::ZString *v2; // rsi
  OSuite::ZString::InternalString *v3; // rcx
  OSuite::ZString *v4; // rbx
  OSuite::ZString::InternalString *v5; // rax
  OSuite::ZString::InternalString *v6; // r14
  char v7; // bp
  char *v8; // r12
  char *v9; // rdi
  char v10; // r15
  char v11; // al
  bool v12; // zf
  signed __int64 v13; // rdi
  OSuite::ZString *v15; // [rsp+58h] [rbp+10h]

  v15 = result;
  v2 = this;
  v3 = this->m_pString;
  v4 = result;
  if ( v3 )
  {
    v5 = OSuite::ZString::AllocateInternalString(v3->m_nLength + 1);
    v6 = v5;
    if ( v5 )
    {
      v7 = 0;
      v8 = v5->m_szString;
      v9 = v2->m_pString->m_szString;
      v10 = *v9;
      if ( *v9 )
      {
        do
        {
          ++v9;
          v11 = tolower_0(v10);
          *v8++ = v11;
          v12 = v10 == v11;
          v10 = *v9;
          if ( !v12 )
            v7 = 1;
        }
        while ( v10 );
        v4 = v15;
        if ( v7 )
        {
          *v8 = 0;
          v13 = v9 - (char *)v2->m_pString;
          v6->m_nRefCount = 1;
          v6->m_nHash = 0;
          v6->m_nLength = v13 - 20;
          v15->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
          v15->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
          v15->m_pString = v6;
          return v4;
        }
      }
      OSuite::ZObject::free((OSuite::ZObject *)&v2->vfptr, v6);
    }
    OSuite::ZString::ZString(v4, v2);
    return v4;
  }
  result->m_pString = 0i64;
  result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
  result->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
  return v4;
}

// File Line: 886
// RVA: 0xEE390C
OSuite::ZString *__fastcall OSuite::ZString::Trim(OSuite::ZString *this, OSuite::ZString *result)
{
  OSuite::ZString::InternalString *v2; // rsi
  OSuite::ZString *v3; // rdi
  OSuite::ZString *v4; // rbp
  const char *i; // rsi
  OSuite::ZString::InternalString *v6; // rcx
  unsigned __int8 *v7; // rbx
  signed __int64 v8; // r14

  v2 = this->m_pString;
  v3 = result;
  v4 = this;
  if ( v2 )
  {
    for ( i = v2->m_szString; *i && isspace(*(unsigned __int8 *)i); ++i )
      ;
    v6 = v4->m_pString;
    v7 = (unsigned __int8 *)&v6->m_nHash + v6->m_nLength + 3;
    v8 = (signed __int64)&v6->m_nHash + v6->m_nLength + 3;
    while ( v7 > (unsigned __int8 *)i && isspace(*v7) )
      --v7;
    if ( i != v4->m_pString->m_szString || v7 != (unsigned __int8 *)v8 )
      OSuite::ZString::ZString(v3, i, v7 - (unsigned __int8 *)i + 1);
    else
      OSuite::ZString::ZString(v3, v4);
  }
  else
  {
    result->m_pString = 0i64;
    result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
    result->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
  }
  return v3;
}

// File Line: 920
// RVA: 0xEE3530
OSuite::ZString *__fastcall OSuite::ZString::Slice(OSuite::ZString *this, OSuite::ZString *result, unsigned __int64 nStart, unsigned __int64 nLength)
{
  OSuite::ZString::InternalString *v4; // rax
  OSuite::ZString *v5; // rbx

  v4 = this->m_pString;
  v5 = result;
  if ( v4 && nStart + nLength <= v4->m_nLength && nStart + nLength )
  {
    if ( nStart || nLength != v4->m_nLength )
      OSuite::ZString::ZString(result, &v4->m_szString[nStart], nLength);
    else
      OSuite::ZString::ZString(result, this);
  }
  else
  {
    result->m_pString = 0i64;
    result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
    result->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
  }
  return v5;
}

// File Line: 956
// RVA: 0xEE35A0
OSuite::ZString *__fastcall OSuite::ZString::Slice(OSuite::ZString *this, OSuite::ZString *result, unsigned __int64 nStart)
{
  OSuite::ZString::InternalString *v3; // r9
  OSuite::ZString *v4; // rbx

  v3 = this->m_pString;
  v4 = result;
  if ( v3 )
  {
    if ( nStart )
      OSuite::ZString::Slice(this, result, nStart, v3->m_nLength - nStart);
    else
      OSuite::ZString::ZString(result, this);
  }
  else
  {
    result->m_pString = 0i64;
    result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
    result->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
  }
  return v4;
}

// File Line: 973
// RVA: 0xEE39E0
char *__fastcall OSuite::ZString::c_str(OSuite::ZString *this)
{
  OSuite::ZString::InternalString *v1; // rdx
  char *result; // rax

  v1 = this->m_pString;
  result = 0i64;
  if ( v1 )
    result = v1->m_szString;
  return result;
}

// File Line: 989
// RVA: 0xEE37B0
__int64 __fastcall OSuite::ZString::ToInt(OSuite::ZString *this)
{
  OSuite::ZString::InternalString *v1; // r8
  signed __int64 v2; // rdx
  char *v3; // r8
  char v4; // r9
  char v5; // al

  v1 = this->m_pString;
  v2 = 0i64;
  if ( v1 )
  {
    v3 = v1->m_szString;
    v4 = 0;
    if ( *v3 != 45 )
      goto LABEL_7;
    v4 = 1;
    while ( 1 )
    {
      ++v3;
LABEL_7:
      v5 = *v3;
      if ( *v3 < 48 || v5 > 57 )
        break;
      v2 = v5 - 48 + 10 * v2;
    }
    if ( v4 )
      v2 = -v2;
  }
  return v2;
}

// File Line: 1039
// RVA: 0xEE3778
bool __fastcall OSuite::ZString::StartsWith(OSuite::ZString *this, const char *pszStr)
{
  OSuite::ZString::InternalString *v2; // r8
  bool v3; // zf
  char *i; // r8

  v2 = this->m_pString;
  if ( !v2 )
    return pszStr == 0i64;
  v3 = pszStr == 0i64;
  if ( pszStr )
  {
    for ( i = v2->m_szString; *pszStr && *i && *pszStr == *i; ++i )
      ++pszStr;
    v3 = *pszStr == 0;
  }
  return v3;
}

// File Line: 1056
// RVA: 0xEE3764
bool __fastcall OSuite::ZString::StartsWith(OSuite::ZString *this, OSuite::ZString *sStr)
{
  OSuite::ZString::InternalString *v2; // rax
  const char *v3; // rdx

  v2 = sStr->m_pString;
  v3 = 0i64;
  if ( v2 )
    v3 = v2->m_szString;
  return OSuite::ZString::StartsWith(this, v3);
}

// File Line: 1061
// RVA: 0xEE3268
bool __fastcall OSuite::ZString::EndsWith(OSuite::ZString *this, const char *pszStr)
{
  const char *v2; // rdi
  OSuite::ZString *v3; // rsi
  bool v4; // zf
  size_t v5; // rax
  OSuite::ZString::InternalString *v6; // rdx
  size_t v7; // rcx
  unsigned __int64 v8; // rax
  char *i; // rcx

  v2 = pszStr;
  v3 = this;
  if ( !this->m_pString )
    return pszStr == 0i64;
  v4 = pszStr == 0i64;
  if ( pszStr )
  {
    v5 = strlen(pszStr);
    v6 = v3->m_pString;
    v7 = v5;
    v8 = v6->m_nLength;
    if ( v7 > v8 )
      return 0;
    for ( i = &v6->m_szString[v8 - v7]; *v2 && *i && *v2 == *i; ++i )
      ++v2;
    v4 = *v2 == 0;
  }
  return v4;
}

// File Line: 1090
// RVA: 0xEE35F4
void __fastcall OSuite::ZString::Split(OSuite::ZString *this, OSuite::TList<OSuite::ZString> *pList, char nChar)
{
  OSuite::ZString::InternalString *v3; // rbx
  char v4; // si
  OSuite::TList<OSuite::ZString> *v5; // rdi
  OSuite::ZString *v6; // rcx
  OSuite::ZString *v7; // rax
  int v8; // ebp
  char *v9; // rax
  char *v10; // rsi
  OSuite::ZString *v11; // rax
  OSuite::ZString *v12; // rbx
  OSuite::ZString that; // [rsp+20h] [rbp-38h]

  v3 = this->m_pString;
  v4 = nChar;
  v5 = pList;
  if ( v3 )
    v3 = (OSuite::ZString::InternalString *)((char *)v3 + 20);
  if ( pList && v3 )
  {
    v6 = pList->m_pList;
    if ( v6 )
    {
      if ( LODWORD(v6[-1].m_pString) )
        v6->vfptr->__vecDelDtor((OSuite::ZObject *)&v6->vfptr, 3u);
      else
        Illusion::ShaderParam::operator delete(&v6[-1].m_pString);
    }
    v7 = OSuite::TList<OSuite::ZString>::AllocList(v5, (OSuite::ZObject *)&v5->m_pList->vfptr, 0x10ui64);
    v5->m_nTop = 0i64;
    v5->m_nSize = 16i64;
    v5->m_pList = v7;
    if ( LOBYTE(v3->m_nRefCount) )
    {
      v8 = v4;
      while ( 1 )
      {
        v9 = strchr((const char *)v3, v8);
        v10 = v9;
        if ( !v9 )
          break;
        OSuite::ZString::ZString(&that, (const char *)v3, v9 - (char *)v3);
        v12 = v11;
        OSuite::TList<OSuite::ZString>::Grow(v5, v5->m_nTop + 1);
        OSuite::ZString::operator=(&v5->m_pList[v5->m_nTop], v12);
        ++v5->m_nTop;
        that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
        that.vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
        OSuite::ZString::DecreaseRefCount(&that);
        v3 = (OSuite::ZString::InternalString *)(v10 + 1);
        if ( !v10[1] )
          return;
      }
      OSuite::ZString::ZString(&that, (const char *)v3);
      OSuite::TList<OSuite::ZString>::Grow(v5, v5->m_nTop + 1);
      OSuite::ZString::operator=(&v5->m_pList[v5->m_nTop], &that);
      ++v5->m_nTop;
      that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
      that.vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
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
__int64 __fastcall OSuite::ZString::ReplaceChar(OSuite::ZString *this, char oldCh, char newCh, unsigned __int64 nStartFrom, bool bAll)
{
  OSuite::ZString::InternalString *v5; // rax
  unsigned int v6; // er10
  char v7; // r11
  __int64 i; // r8

  v5 = this->m_pString;
  v6 = -1;
  v7 = newCh;
  if ( v5 && oldCh )
  {
    for ( i = (signed int)nStartFrom; (signed int)nStartFrom < SLODWORD(v5->m_nLength); ++i )
    {
      if ( v5->m_szString[i] == oldCh )
      {
        v5->m_szString[i] = v7;
        v6 = nStartFrom;
        if ( !bAll || !v7 )
          break;
      }
      v5 = this->m_pString;
      LODWORD(nStartFrom) = nStartFrom + 1;
    }
  }
  return v6;
}

// File Line: 1172
// RVA: 0xEE3434
void __fastcall OSuite::ZString::InstantiateFrom(OSuite::ZString *this, const char *pszString, unsigned __int64 nLength)
{
  unsigned __int64 v3; // rdi
  const char *v4; // rsi
  OSuite::ZString *v5; // rbx
  OSuite::ZString::InternalString *v6; // rax

  v3 = nLength;
  v4 = pszString;
  v5 = this;
  if ( pszString )
  {
    v6 = OSuite::ZString::AllocateInternalString(nLength + 1);
    v5->m_pString = v6;
    if ( v6 )
    {
      memmove(v6->m_szString, v4, v3);
      v5->m_pString->m_szString[v3] = 0;
      v5->m_pString->m_nLength = v3;
      v5->m_pString->m_nRefCount = 1;
      v5->m_pString->m_nHash = 0;
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
  OSuite::ZString *v1; // rbx
  OSuite::ZString::InternalString *v2; // rcx

  v1 = this;
  v2 = this->m_pString;
  if ( v2 )
  {
    if ( OSuite::ZThread::AtomicAdd(&v2->m_nRefCount, -1) == 1 )
    {
      OSuite::ZObject::free((OSuite::ZObject *)&v1->vfptr, v1->m_pString);
      v1->m_pString = 0i64;
    }
  }
}

// File Line: 1218
// RVA: 0xEE3120
OSuite::ZString::InternalString *__fastcall OSuite::ZString::AllocateInternalString(unsigned __int64 length)
{
  __int64 v2; // [rsp+20h] [rbp-38h]
  __int64 v3; // [rsp+28h] [rbp-30h]
  __int64 v4; // [rsp+30h] [rbp-28h]
  __int64 v5; // [rsp+38h] [rbp-20h]

  v2 = *(_QWORD *)aZstring;
  v3 = 8386093311352127802i64;
  v4 = 7020674649187830117i64;
  v5 = 29113321772045164i64;
  return (OSuite::ZString::InternalString *)OSuite::ZObject::m_allocator->vfptr->malloc(
                                              OSuite::ZObject::m_allocator,
                                              length + 24,
                                              (char *)&v2);
}

// File Line: 1227
// RVA: 0xEE2D94
OSuite::ZString *__fastcall OSuite::operator+(OSuite::ZString *result, const char *pszString1, OSuite::ZString *InternalString2)
{
  OSuite::ZString *v3; // rdi
  const char *v4; // rsi
  OSuite::ZString *v5; // rbx
  OSuite::ZString *v6; // rdx
  OSuite::ZString::InternalString *v7; // rax
  unsigned __int64 v8; // rcx
  size_t v9; // r15
  size_t v10; // rbp
  OSuite::ZString::InternalString *v11; // rax
  OSuite::ZString::InternalString *v12; // r14

  v3 = InternalString2;
  v4 = pszString1;
  v5 = result;
  if ( !pszString1 )
  {
    v6 = InternalString2;
LABEL_3:
    OSuite::ZString::ZString(result, v6);
    return v5;
  }
  v7 = InternalString2->m_pString;
  if ( v7 )
    v8 = v7->m_nLength;
  else
    v8 = 0i64;
  if ( !v8 )
  {
    OSuite::ZString::ZString(v5, pszString1);
    return v5;
  }
  v9 = strlen(pszString1);
  if ( !v9 )
  {
    v6 = v3;
    result = v5;
    goto LABEL_3;
  }
  v10 = v9 + v3->m_pString->m_nLength;
  v11 = OSuite::ZString::AllocateInternalString(v10 + 1);
  v12 = v11;
  if ( v11 )
  {
    memmove(v11->m_szString, v4, v9);
    memmove(&v12->m_szString[v9], v3->m_pString->m_szString, v3->m_pString->m_nLength);
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
  v5->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZString::`vftable'{for `OSuite::ZObject'};
  v5->vfptr = (OSuite::IHashableVtbl *)&OSuite::ZString::`vftable'{for `OSuite::IHashable'};
  return v5;
}


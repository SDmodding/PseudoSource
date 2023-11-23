// File Line: 14
// RVA: 0xC6C080
__int64 __fastcall tolower(char i)
{
  __int64 result; // rax

  result = (unsigned int)i;
  if ( (unsigned __int8)(i - 65) <= 0x19u )
    return (unsigned int)(result + 32);
  return result;
}

// File Line: 21
// RVA: 0xC6C0A0
__int64 __fastcall toupper(char i)
{
  __int64 result; // rax

  result = (unsigned int)i;
  if ( (unsigned __int8)(i - 97) <= 0x19u )
    return (unsigned int)(result - 32);
  return result;
}

// File Line: 38
// RVA: 0xC6A6C0
void __fastcall hkStringBuf::hkStringBuf(hkStringBuf *this, const char *s)
{
  unsigned int v4; // ebx

  this->m_string.m_size = 0;
  this->m_string.m_capacityAndFlags = -2147483520;
  this->m_string.m_data = this->m_string.m_storage;
  if ( s )
  {
    v4 = hkString::strLen(s);
    hkStringBuf::setLength(this, v4);
    hkString::memCpy(this->m_string.m_data, s, v4);
  }
  else
  {
    this->m_string.m_size = 1;
    this->m_string.m_storage[0] = 0;
  }
}

// File Line: 52
// RVA: 0xC6A750
void __fastcall hkStringBuf::hkStringBuf(hkStringBuf *this, hkStringPtr *s)
{
  this->m_string.m_size = 0;
  this->m_string.m_capacityAndFlags = -2147483520;
  this->m_string.m_data = this->m_string.m_storage;
  hkStringBuf::operator=(this, (const char *)((unsigned __int64)s->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
}

// File Line: 57
// RVA: 0xC6A790
void __fastcall hkStringBuf::hkStringBuf(
        hkStringBuf *this,
        const char *s0,
        const char *s1,
        const char *s2,
        const char *s3,
        const char *s4,
        const char *s5)
{
  this->m_string.m_size = 0;
  this->m_string.m_capacityAndFlags = -2147483520;
  this->m_string.m_data = this->m_string.m_storage;
  this->m_string.m_storage[0] = 0;
  ++this->m_string.m_size;
  hkStringBuf::appendJoin(this, s0, s1, s2, s3, s4, s5);
}

// File Line: 63
// RVA: 0xC6A7F0
void __fastcall hkStringBuf::hkStringBuf(hkStringBuf *this, const char *b, int len)
{
  __int64 v3; // rsi
  int v5; // edi
  int v7; // r9d
  hkResult result; // [rsp+50h] [rbp+18h] BYREF

  v3 = len;
  v5 = len + 1;
  this->m_string.m_size = 0;
  this->m_string.m_data = this->m_string.m_storage;
  this->m_string.m_capacityAndFlags = -2147483520;
  if ( len + 1 > 128 )
  {
    v7 = len + 1;
    if ( v5 < 256 )
      v7 = 256;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_string.m_data, v7, 1);
  }
  this->m_string.m_size = v5;
  this->m_string.m_data[v3] = 0;
  hkString::memCpy(this->m_string.m_data, b, v3);
}

// File Line: 69
// RVA: 0xC6A890
void __fastcall hkStringBuf::hkStringBuf(hkStringBuf *this, hkStringBuf *s)
{
  __int64 v4; // rcx
  char *m_data; // rax
  __int64 v6; // rdx
  char *v7; // r8
  char v8; // cl
  int m_size; // [rsp+30h] [rbp+8h] BYREF

  this->m_string.m_size = 0;
  this->m_string.m_capacityAndFlags = -2147483520;
  this->m_string.m_data = this->m_string.m_storage;
  if ( s->m_string.m_size > 128 )
  {
    m_size = s->m_string.m_size;
    this->m_string.m_data = (char *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                      &hkContainerTempAllocator::s_alloc,
                                      &m_size);
    this->m_string.m_capacityAndFlags = m_size;
  }
  v4 = s->m_string.m_size;
  m_data = this->m_string.m_data;
  this->m_string.m_size = v4;
  v6 = v4;
  if ( (int)v4 > 0 )
  {
    v7 = (char *)(s->m_string.m_data - m_data);
    do
    {
      v8 = (m_data++)[(_QWORD)v7];
      *(m_data - 1) = v8;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 74
// RVA: 0xC6A930
hkStringBuf *__fastcall hkStringBuf::operator=(hkStringBuf *this, hkStringBuf *s)
{
  __int64 v4; // rcx
  char *m_data; // rax
  __int64 v6; // rdx
  char *v7; // r8
  char v8; // cl
  int m_size; // [rsp+30h] [rbp+8h] BYREF

  if ( (this->m_string.m_capacityAndFlags & 0x3FFFFFFF) < s->m_string.m_size )
  {
    if ( this->m_string.m_capacityAndFlags >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, char *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        this->m_string.m_data);
    m_size = s->m_string.m_size;
    this->m_string.m_data = (char *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                      &hkContainerTempAllocator::s_alloc,
                                      &m_size);
    this->m_string.m_capacityAndFlags = m_size;
  }
  v4 = s->m_string.m_size;
  m_data = this->m_string.m_data;
  this->m_string.m_size = v4;
  v6 = v4;
  if ( (int)v4 > 0 )
  {
    v7 = (char *)(s->m_string.m_data - m_data);
    do
    {
      v8 = (m_data++)[(_QWORD)v7];
      *(m_data - 1) = v8;
      --v6;
    }
    while ( v6 );
  }
  return this;
}

// File Line: 80
// RVA: 0xC6A9E0
hkStringBuf *__fastcall hkStringBuf::operator=(hkStringBuf *this, const char *s)
{
  unsigned int v4; // ebx
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  if ( s )
  {
    v4 = hkString::strLen(s);
    hkStringBuf::setLength(this, v4);
    hkString::memCpy(this->m_string.m_data, s, v4);
    return this;
  }
  else
  {
    if ( (this->m_string.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_string.m_data, 1, 1);
    this->m_string.m_size = 1;
    *this->m_string.m_data = 0;
    return this;
  }
}

// File Line: 95
// RVA: 0xC6AA90
__int64 __fastcall hkStringBuf::indexOf(hkStringBuf *this, char c, int startIndex, int endIndex)
{
  __int64 v4; // r10
  int v5; // r8d
  __int64 v6; // rax
  char *m_data; // rcx

  v4 = startIndex;
  v5 = this->m_string.m_size - 1;
  v6 = v4;
  if ( endIndex < v5 )
    v5 = endIndex;
  if ( v4 >= v5 )
    return 0xFFFFFFFFi64;
  m_data = this->m_string.m_data;
  while ( m_data[v6] != c )
  {
    ++v6;
    LODWORD(v4) = v4 + 1;
    if ( v6 >= v5 )
      return 0xFFFFFFFFi64;
  }
  return (unsigned int)v4;
}

// File Line: 108
// RVA: 0xC6AAD0
__int64 __fastcall hkStringBuf::indexOf(hkStringBuf *this, const char *s, int startIndex, int endIndex)
{
  char *v5; // rax

  v5 = hkString::strStr(&this->m_string.m_data[startIndex], s);
  if ( v5 )
    return (unsigned int)((_DWORD)v5 - LODWORD(this->m_string.m_data));
  else
    return 0xFFFFFFFFi64;
}

// File Line: 118
// RVA: 0xC6AB00
__int64 __fastcall hkStringBuf::indexOfCase(hkStringBuf *this, char *needle)
{
  char *m_data; // r11
  unsigned int v3; // edi
  __int64 v4; // r10
  char v5; // al
  const char *v6; // r9
  char v7; // r8
  char v8; // cl

  m_data = this->m_string.m_data;
  v3 = 0;
  if ( !*this->m_string.m_data )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v4 = 0i64;
    if ( *needle )
    {
      v5 = *needle;
      v6 = needle;
      do
      {
        v7 = v6[m_data - needle];
        if ( (unsigned __int8)(v7 - 65) <= 0x19u )
          v7 += 32;
        v8 = v5;
        if ( (unsigned __int8)(v5 - 65) <= 0x19u )
          v8 = v5 + 32;
        if ( v7 != v8 )
          break;
        v5 = *++v6;
        ++v4;
      }
      while ( v5 );
    }
    if ( !needle[v4] )
      break;
    ++m_data;
    ++v3;
    if ( !*m_data )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 146
// RVA: 0xC6ABC0
__int64 __fastcall hkStringBuf::lastIndexOf(hkStringBuf *this, char c, int start, int end)
{
  unsigned int v4; // r9d
  __int64 v5; // rax
  char *m_data; // rcx

  if ( end > this->m_string.m_size - 1 )
    end = this->m_string.m_size - 1;
  v4 = end - 1;
  v5 = (int)v4;
  if ( (int)v4 < (__int64)start )
    return 0xFFFFFFFFi64;
  m_data = this->m_string.m_data;
  while ( m_data[v5] != c )
  {
    --v5;
    --v4;
    if ( v5 < start )
      return 0xFFFFFFFFi64;
  }
  return v4;
}

// File Line: 161
// RVA: 0xC6AC00
__int64 __fastcall hkStringBuf::lastIndexOf(hkStringBuf *this, const char *needle, int startIndex, int endIndex)
{
  char *v6; // rax
  unsigned int v7; // ebx

  v6 = hkString::strStr(this->m_string.m_data, needle);
  if ( !v6 )
    return 0xFFFFFFFFi64;
  do
  {
    v7 = (_DWORD)v6 - LODWORD(this->m_string.m_data);
    v6 = hkString::strStr(v6 + 1, needle);
  }
  while ( v6 );
  return v7;
}

// File Line: 175
// RVA: 0xC6AC70
__int64 __fastcall hkStringBuf::compareTo(hkStringBuf *this, const char *other)
{
  return hkString::strCmp(this->m_string.m_data, other);
}

// File Line: 180
// RVA: 0xC6AC80
__int64 __fastcall hkStringBuf::compareToIgnoreCase(hkStringBuf *this, const char *other)
{
  return hkString::strCasecmp(this->m_string.m_data, other);
}

// File Line: 185
// RVA: 0xC6AC90
hkBool *__fastcall hkStringBuf::operator<(hkStringBuf *this, hkBool *result, const char *other)
{
  result->m_bool = (int)hkString::strCmp(this->m_string.m_data, other) < 0;
  return result;
}

// File Line: 190
// RVA: 0xC6ACC0
_BOOL8 __fastcall hkStringBuf::operator==(hkStringBuf *this, const char *other)
{
  return (unsigned int)hkStringBuf::compareTo(this, other) == 0;
}

// File Line: 195
// RVA: 0xC6ACE0
__int64 __fastcall hkStringBuf::startsWith(hkStringBuf *this, const char *s)
{
  char *m_data; // rax
  unsigned int v3; // r10d
  int v4; // r9d
  const char *v5; // rcx

  m_data = this->m_string.m_data;
  v3 = 0;
  v4 = 0;
  if ( *this->m_string.m_data )
  {
    v5 = s;
    while ( *v5 )
    {
      if ( *m_data != *v5 )
        return 0i64;
      ++m_data;
      ++v4;
      ++v5;
      if ( !*m_data )
        break;
    }
  }
  LOBYTE(v3) = s[v4] == 0;
  return v3;
}

// File Line: 208
// RVA: 0xC6AD30
__int64 __fastcall hkStringBuf::startsWithCase(hkStringBuf *this, char *s)
{
  char *m_data; // r8
  char v4; // dl
  char v5; // al

  m_data = this->m_string.m_data;
  if ( *this->m_string.m_data )
  {
    while ( *s )
    {
      v4 = *m_data;
      if ( (unsigned __int8)(*m_data - 65) <= 0x19u )
        v4 += 32;
      v5 = *s;
      if ( (unsigned __int8)(*s - 65) <= 0x19u )
        v5 = *s + 32;
      if ( v4 != v5 )
        return 0i64;
      ++m_data;
      ++s;
      if ( !*m_data )
        return 1i64;
    }
  }
  return 1i64;
}

// File Line: 220
// RVA: 0xC6AD90
__int64 __fastcall hkStringBuf::endsWith(hkStringBuf *this, const char *s)
{
  int v4; // eax
  int m_size; // edx
  __int64 v6; // r9
  __int64 v8; // rax
  int v9; // edx

  v4 = hkString::strLen(s);
  m_size = this->m_string.m_size;
  v6 = v4;
  if ( v4 > m_size - 1 )
    return 0i64;
  v8 = 0i64;
  v9 = m_size - v6 - 1;
  if ( (int)v6 > 0 )
  {
    while ( this->m_string.m_data[v9 + v8] == s[v8] )
    {
      if ( ++v8 >= v6 )
        return 1i64;
    }
    return 0i64;
  }
  return 1i64;
}

// File Line: 239
// RVA: 0xC6AE00
__int64 __fastcall hkStringBuf::endsWithCase(hkStringBuf *this, const char *s)
{
  int v4; // eax
  int m_size; // r9d
  __int64 v7; // rcx
  __int64 v8; // rdx
  __int64 v9; // r9
  char *v10; // r10
  char v11; // dl
  char v12; // al

  v4 = hkString::strLen(s);
  m_size = this->m_string.m_size;
  if ( v4 > m_size - 1 )
    return 0i64;
  v7 = 0i64;
  v8 = m_size - v4 - 1;
  v9 = v4;
  if ( v4 > 0 )
  {
    v10 = &this->m_string.m_data[v8];
    while ( 1 )
    {
      v11 = v10[v7];
      if ( (unsigned __int8)(v11 - 65) <= 0x19u )
        v11 += 32;
      v12 = s[v7];
      if ( (unsigned __int8)(v12 - 65) <= 0x19u )
        v12 += 32;
      if ( v11 != v12 )
        break;
      if ( ++v7 >= v9 )
        return 1i64;
    }
    return 0i64;
  }
  return 1i64;
}

// File Line: 258
// RVA: 0xC6AEA0
__int64 __fastcall hkStringBuf::split(
        hkStringBuf *this,
        char sep,
        hkArray<char const *,hkContainerTempAllocator> *bits)
{
  char *m_data; // rdi
  unsigned int m_size; // edi
  int i; // edx
  int v9; // ebp
  const char *v10; // rdi

  m_data = this->m_string.m_data;
  if ( bits->m_size == (bits->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&bits->m_data, 8);
  bits->m_data[bits->m_size++] = m_data;
  m_size = bits->m_size;
  for ( i = hkStringBuf::indexOf(this, sep, 0, 0x7FFFFFFF); i >= 0; i = hkStringBuf::indexOf(this, sep, v9, 0x7FFFFFFF) )
  {
    v9 = i + 1;
    this->m_string.m_data[i] = 0;
    v10 = &this->m_string.m_data[i + 1];
    if ( bits->m_size == (bits->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&bits->m_data, 8);
    bits->m_data[bits->m_size++] = v10;
    m_size = bits->m_size;
  }
  return m_size;
}

// File Line: 279
// RVA: 0xC6AFB0
void __fastcall hkStringBuf::clear(hkStringBuf *this)
{
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  if ( (this->m_string.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_string.m_data, 1, 1);
  this->m_string.m_size = 1;
  *this->m_string.m_data = 0;
}

// File Line: 284
// RVA: 0xC6B010
void hkStringBuf::printf(hkStringBuf *this, const char *fmt, ...)
{
  int v3; // esi
  int v4; // eax
  __int64 v5; // rdi
  int v6; // esi
  int v7; // ecx
  int v8; // ecx
  int v9; // r9d
  char *m_data; // rax
  int v11; // edi
  int v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // r9d
  hkResult result; // [rsp+30h] [rbp-38h] BYREF
  hkResult v17; // [rsp+34h] [rbp-34h] BYREF
  va_list va; // [rsp+80h] [rbp+18h] BYREF

  va_start(va, fmt);
  while ( 1 )
  {
    while ( 1 )
    {
      v3 = this->m_string.m_capacityAndFlags & 0x3FFFFFFF;
      v4 = hkString::vsnprintf(this->m_string.m_data, v3, fmt, va);
      v5 = v4;
      if ( v4 >= 0 )
        break;
      v11 = 255;
      if ( 2 * v3 > 255 )
        v11 = 2 * v3;
      v12 = v11 + 1;
      v13 = this->m_string.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v13 >= v11 + 1 )
      {
        this->m_string.m_size = v12;
        this->m_string.m_data[v11] = 0;
        v17.m_enum = HK_SUCCESS;
      }
      else
      {
        v14 = 2 * v13;
        v15 = v11 + 1;
        if ( v12 < v14 )
          v15 = v14;
        hkArrayUtil::_reserve(&v17, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_string.m_data, v15, 1);
        this->m_string.m_size = v12;
        this->m_string.m_data[v11] = 0;
      }
    }
    if ( v4 < v3 )
      break;
    v6 = v4 + 1;
    v7 = this->m_string.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v7 >= v4 + 1 )
    {
      this->m_string.m_size = v6;
      m_data = this->m_string.m_data;
      result.m_enum = HK_SUCCESS;
      m_data[v5] = 0;
    }
    else
    {
      v8 = 2 * v7;
      v9 = v4 + 1;
      if ( v6 < v8 )
        v9 = v8;
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_string.m_data, v9, 1);
      this->m_string.m_size = v6;
      this->m_string.m_data[v5] = 0;
    }
  }
  hkStringBuf::setLength(this, v4);
}

// File Line: 314
// RVA: 0xC6B140
void hkStringBuf::appendPrintf(hkStringBuf *this, const char *fmt, ...)
{
  int v3; // edi
  int v4; // eax
  __int64 v5; // rbx
  bool v6; // cc
  int v7; // edi
  int v8; // r9d
  int v9; // ebx
  int v10; // r9d
  int v11; // r9d
  hkResult v12; // [rsp+30h] [rbp-79h] BYREF
  hkResult result; // [rsp+34h] [rbp-75h] BYREF
  char *buf; // [rsp+40h] [rbp-69h] BYREF
  int v15; // [rsp+48h] [rbp-61h]
  int v16; // [rsp+4Ch] [rbp-5Dh]
  char v17; // [rsp+50h] [rbp-59h] BYREF
  va_list hkargs; // [rsp+120h] [rbp+77h] BYREF

  va_start(hkargs, fmt);
  v16 = -2147483520;
  v15 = 1;
  v17 = 0;
  buf = &v17;
  while ( 1 )
  {
    while ( 1 )
    {
      v3 = v16 & 0x3FFFFFFF;
      v4 = hkString::vsnprintf(buf, v16 & 0x3FFFFFFF, fmt, hkargs);
      v5 = v4;
      if ( v4 >= 0 )
        break;
      v9 = 255;
      if ( 2 * v3 > 255 )
        v9 = 2 * v3;
      if ( (v16 & 0x3FFFFFFF) >= v9 + 1 )
      {
        v15 = v9 + 1;
        buf[v9] = 0;
        v12.m_enum = HK_SUCCESS;
      }
      else
      {
        v10 = v9 + 1;
        if ( v9 + 1 < 2 * (v16 & 0x3FFFFFFF) )
          v10 = 2 * (v16 & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&v12, &hkContainerTempAllocator::s_alloc, (const void **)&buf, v10, 1);
        v15 = v9 + 1;
        buf[v9] = 0;
      }
    }
    v6 = v4 < v3;
    v7 = v4 + 1;
    if ( v6 )
      break;
    if ( (v16 & 0x3FFFFFFF) >= v7 )
    {
      v15 = v4 + 1;
      result.m_enum = HK_SUCCESS;
      buf[v4] = 0;
    }
    else
    {
      v8 = v4 + 1;
      if ( v7 < 2 * (v16 & 0x3FFFFFFF) )
        v8 = 2 * (v16 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&buf, v8, 1);
      v15 = v5 + 1;
      buf[v5] = 0;
    }
  }
  if ( (v16 & 0x3FFFFFFF) < v7 )
  {
    v11 = v4 + 1;
    if ( v7 < 2 * (v16 & 0x3FFFFFFF) )
      v11 = 2 * (v16 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v12, &hkContainerTempAllocator::s_alloc, (const void **)&buf, v11, 1);
  }
  v15 = v5 + 1;
  buf[v5] = 0;
  hkStringBuf::append(this, buf, -1);
  v15 = 0;
  if ( v16 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, buf, v16 & 0x3FFFFFFF);
}

// File Line: 346
// RVA: 0xC6B310
hkStringBuf *__fastcall hkStringBuf::operator+=(hkStringBuf *this, const char *other)
{
  int numtoinsert; // eax

  if ( other )
  {
    numtoinsert = hkString::strLen(other);
    hkArrayBase<char>::_insertAt(
      &this->m_string,
      &hkContainerTempAllocator::s_alloc,
      this->m_string.m_size - 1,
      other,
      numtoinsert);
  }
  return this;
}

// File Line: 356
// RVA: 0xC6B360
hkStringBuf *__fastcall hkStringBuf::appendJoin(
        hkStringBuf *this,
        const char *s0,
        const char *s1,
        const char *s2,
        const char *s3,
        const char *s4,
        const char *s5)
{
  int m_size; // ebp
  __int64 v8; // rdi
  int v9; // ebp
  const char *v10; // rsi
  int v12; // r15d
  __int64 v13; // rbx
  const char *v14; // rax
  int v15; // eax
  int v16; // ebx
  int v17; // eax
  int v18; // eax
  int v19; // r9d
  unsigned int v20; // ebx
  int n[2]; // [rsp+30h] [rbp-68h]
  __int64 v24; // [rsp+38h] [rbp-60h]
  __int64 v25; // [rsp+40h] [rbp-58h]
  __int64 v26[7]; // [rsp+48h] [rbp-50h]

  m_size = this->m_string.m_size;
  v8 = 0i64;
  *(_QWORD *)n = 0i64;
  v24 = 0i64;
  v25 = 0i64;
  v9 = m_size - 1;
  v10 = s0;
  v26[3] = (__int64)s3;
  v26[4] = (__int64)s4;
  v26[0] = (__int64)s0;
  v26[1] = (__int64)s1;
  v26[2] = (__int64)s2;
  v26[6] = 0i64;
  v26[5] = (__int64)s5;
  v12 = v9;
  v13 = 0i64;
  if ( s0 )
  {
    v14 = s0;
    do
    {
      v15 = hkString::strLen(v14);
      n[v13++] = v15;
      v12 += v15;
      v14 = (const char *)v26[v13];
    }
    while ( v14 );
  }
  v16 = v12 + 1;
  v17 = this->m_string.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v17 < v12 + 1 )
  {
    v18 = 2 * v17;
    v19 = v12 + 1;
    if ( v16 < v18 )
      v19 = v18;
    hkArrayUtil::_reserve(
      (hkResult *)&s3,
      &hkContainerTempAllocator::s_alloc,
      (const void **)&this->m_string.m_data,
      v19,
      1);
  }
  this->m_string.m_size = v16;
  for ( this->m_string.m_data[v12] = 0; v10; v10 = (const char *)v26[v8] )
  {
    v20 = n[v8];
    hkString::memCpy(&this->m_string.m_data[v9], v10, v20);
    ++v8;
    v9 += v20;
  }
  return this;
}

// File Line: 377
// RVA: 0xC6B4A0
hkStringBuf *__fastcall hkStringBuf::setJoin(
        hkStringBuf *this,
        const char *s0,
        const char *s1,
        const char *s2,
        const char *s3,
        const char *s4,
        const char *s5)
{
  hkStringBuf::clear(this);
  hkStringBuf::appendJoin(this, s0, s1, s2, s3, s4, s5);
  return this;
}

// File Line: 384
// RVA: 0xC6B520
void __fastcall hkStringBuf::chompStart(hkStringBuf *this, int n)
{
  int m_size; // r9d
  int v3; // r8d
  int v4; // r9d
  char *m_data; // rax
  char *v6; // r8
  signed __int64 v7; // r8
  __int64 v8; // rdx
  char v9; // cl

  m_size = this->m_string.m_size;
  v3 = m_size - 1;
  if ( n < m_size - 1 )
    v3 = n;
  if ( v3 > 0 )
  {
    v4 = m_size - v3;
    this->m_string.m_size = v4;
    m_data = this->m_string.m_data;
    v6 = &this->m_string.m_data[v3];
    if ( v4 > 0 )
    {
      v7 = v6 - m_data;
      v8 = (unsigned int)v4;
      do
      {
        v9 = (m_data++)[v7];
        *(m_data - 1) = v9;
        --v8;
      }
      while ( v8 );
    }
  }
}

// File Line: 393
// RVA: 0xC6B570
void __fastcall hkStringBuf::chompEnd(hkStringBuf *this, int n)
{
  int v2; // edx

  if ( n > 0 )
  {
    v2 = this->m_string.m_size - n - 1;
    if ( v2 < 0 )
      v2 = 0;
    hkStringBuf::setLength(this, v2);
  }
}

// File Line: 401
// RVA: 0xC6B5A0
void __fastcall hkStringBuf::slice(hkStringBuf *this, int startOffset, int length)
{
  __int64 v3; // rsi
  int v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // r9d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  v3 = length;
  if ( startOffset )
    hkMemUtil::memMove(this->m_string.m_data, &this->m_string.m_data[startOffset], length);
  v5 = v3 + 1;
  v6 = this->m_string.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < (int)v3 + 1 )
  {
    v7 = 2 * v6;
    v8 = v3 + 1;
    if ( v5 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_string.m_data, v8, 1);
  }
  this->m_string.m_size = v5;
  this->m_string.m_data[v3] = 0;
}

// File Line: 412
// RVA: 0xC6B620
void __fastcall hkStringBuf::set(hkStringBuf *this, const char *s, int len)
{
  int v3; // ebx
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  hkResult result; // [rsp+50h] [rbp+18h] BYREF

  v3 = len;
  if ( len < 0 )
    v3 = hkString::strLen(s);
  v6 = v3 + 1;
  v7 = this->m_string.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v3 + 1 )
  {
    v8 = 2 * v7;
    v9 = v3 + 1;
    if ( v6 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_string.m_data, v9, 1);
  }
  this->m_string.m_size = v6;
  this->m_string.m_data[v3] = 0;
  hkMemUtil::memCpy(this->m_string.m_data, s, v3);
}

// File Line: 423
// RVA: 0xC6B6C0
void __fastcall hkStringBuf::append(hkStringBuf *this, const char *s, int len)
{
  int v3; // edi
  int v6; // ebx

  if ( s )
  {
    v3 = len;
    if ( len < 0 )
      v3 = hkString::strLen(s);
    v6 = this->m_string.m_size - 1;
    hkStringBuf::setLength(this, v6 + v3);
    hkMemUtil::memCpy(&this->m_string.m_data[v6], s, v3);
  }
}

// File Line: 439
// RVA: 0xC6B730
void __fastcall hkStringBuf::prepend(hkStringBuf *this, const char *s, int len)
{
  hkStringBuf::insert(this, 0, s, len);
}

// File Line: 444
// RVA: 0xC6B750
void __fastcall hkStringBuf::insert(hkStringBuf *this, int pos, const char *s, int len)
{
  int numtoinsert; // eax

  if ( s )
  {
    numtoinsert = len;
    if ( len < 0 )
      numtoinsert = hkString::strLen(s);
    hkArrayBase<char>::_insertAt(&this->m_string, &hkContainerTempAllocator::s_alloc, pos, s, numtoinsert);
  }
}

// File Line: 456
// RVA: 0xC6B7B0
void __fastcall hkStringBuf::pathBasename(hkStringBuf *this)
{
  int IndexOf; // ebx
  int v3; // eax

  IndexOf = hkStringBuf::lastIndexOf(this, 47, 0, 0x7FFFFFFF);
  v3 = hkStringBuf::lastIndexOf(this, 92, 0, 0x7FFFFFFF);
  if ( v3 > IndexOf )
    IndexOf = v3;
  if ( IndexOf >= 0 )
    hkStringBuf::chompStart(this, IndexOf + 1);
}

// File Line: 465
// RVA: 0xC6B810
void __fastcall hkStringBuf::pathDirname(hkStringBuf *this)
{
  int IndexOf; // edi
  int v3; // eax

  IndexOf = hkStringBuf::lastIndexOf(this, 47, 0, 0x7FFFFFFF);
  v3 = hkStringBuf::lastIndexOf(this, 92, 0, 0x7FFFFFFF);
  if ( v3 > IndexOf )
    IndexOf = v3;
  if ( IndexOf < 0 )
    hkStringBuf::clear(this);
  else
    hkStringBuf::slice(this, 0, IndexOf);
}

// File Line: 478
// RVA: 0xC6B880
void __fastcall hkStringBuf::pathNormalize(hkStringBuf *this)
{
  const char *v2; // r15
  int v3; // edi
  int v4; // esi
  __int64 v5; // rbx
  int v6; // ecx
  const char **v7; // r14
  int v8; // ecx
  const char **m_data; // r14
  int v10; // edi
  __int64 v11; // rbx
  _QWORD *array; // [rsp+18h] [rbp-79h] BYREF
  int v13; // [rsp+20h] [rbp-71h]
  int v14; // [rsp+24h] [rbp-6Dh]
  hkArray<char const *,hkContainerTempAllocator> bits; // [rsp+28h] [rbp-69h] BYREF
  hkStringBuf v16; // [rsp+38h] [rbp-59h] BYREF

  hkStringBuf::hkStringBuf(&v16, this);
  hkStringBuf::replace(&v16, 92, 47, REPLACE_ALL);
  v2 = "//";
  if ( !(unsigned int)hkStringBuf::startsWith(&v16, "//") )
  {
    v2 = &customCaption;
    if ( (unsigned int)hkStringBuf::startsWith(&v16, "/") )
      v2 = "/";
  }
  bits.m_data = 0i64;
  bits.m_size = 0;
  bits.m_capacityAndFlags = 0x80000000;
  hkStringBuf::split(&v16, 47, &bits);
  array = 0i64;
  v13 = 0;
  v14 = 0x80000000;
  v3 = 0;
  v4 = 0;
  if ( bits.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      if ( (unsigned int)hkString::strCmp("..", bits.m_data[v5]) )
      {
        if ( (unsigned int)hkString::strCmp(".", bits.m_data[v5]) )
        {
          v8 = v13;
          m_data = bits.m_data;
          ++v3;
          if ( v13 == (v14 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&array, 8);
            v8 = v13;
          }
          array[v8] = m_data[v5];
          goto LABEL_16;
        }
      }
      else
      {
        if ( !v3 )
        {
          v6 = v13;
          v7 = bits.m_data;
          if ( v13 == (v14 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&array, 8);
            v6 = v13;
          }
          array[v6] = v7[v5];
LABEL_16:
          ++v13;
          goto LABEL_17;
        }
        --v13;
        --v3;
      }
LABEL_17:
      ++v4;
      ++v5;
    }
    while ( v4 < bits.m_size );
  }
  hkStringBuf::operator=(this, v2);
  v10 = 0;
  if ( v13 > 0 )
  {
    v11 = 0i64;
    do
    {
      hkStringBuf::pathAppend(this, (const char *)array[v11], 0i64, 0i64);
      ++v10;
      ++v11;
    }
    while ( v10 < v13 );
  }
  v13 = 0;
  if ( v14 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 8 * v14);
  array = 0i64;
  v14 = 0x80000000;
  bits.m_size = 0;
  if ( bits.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      bits.m_data,
      8 * bits.m_capacityAndFlags);
  bits.m_data = 0i64;
  v16.m_string.m_size = 0;
  bits.m_capacityAndFlags = 0x80000000;
  if ( v16.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v16.m_string.m_data,
      v16.m_string.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 524
// RVA: 0xC6BB40
void __fastcall hkStringBuf::pathExtension(hkStringBuf *this)
{
  int IndexOf; // eax

  IndexOf = hkStringBuf::lastIndexOf(this, 46, 0, 0x7FFFFFFF);
  if ( IndexOf == -1 )
    hkStringBuf::clear(this);
  else
    hkStringBuf::chompStart(this, IndexOf);
}

// File Line: 537
// RVA: 0xC6BB80
hkStringBuf *__fastcall hkStringBuf::pathAppend(hkStringBuf *this, const char *p0, const char *p1, const char *p2)
{
  __int64 v4; // r14
  bool v5; // zf
  const char *v6; // rbx
  bool i; // bp
  int v9; // eax
  int v10; // edi
  __int64 v11; // rcx
  __int64 v13[4]; // [rsp+28h] [rbp-20h]

  v4 = 0i64;
  v5 = this->m_string.m_size-- == 1;
  v6 = p0;
  v13[0] = (__int64)p1;
  v13[2] = 0i64;
  v13[1] = (__int64)p2;
  for ( i = !v5 && this->m_string.m_data[this->m_string.m_size - 1] != 47; v6; ++v4 )
  {
    if ( *v6 )
    {
      for ( ; *v6 == 47; ++v6 )
        ;
      v9 = hkString::strLen(v6);
      v10 = v9;
      if ( v9 )
      {
        v11 = v9;
        do
        {
          if ( v6[v11 - 1] != 47 )
            break;
          --v10;
          --v11;
        }
        while ( v11 );
        if ( v10 && i )
        {
          if ( this->m_string.m_size == (this->m_string.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&this->m_string.m_data, 1);
          this->m_string.m_data[this->m_string.m_size++] = 47;
        }
        hkArrayBase<char>::_append(&this->m_string, &hkContainerTempAllocator::s_alloc, v6, v10);
      }
      i = 1;
    }
    v6 = (const char *)v13[v4];
  }
  if ( this->m_string.m_size == (this->m_string.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&this->m_string.m_data, 1);
  this->m_string.m_data[this->m_string.m_size++] = 0;
  return this;
}

// File Line: 572
// RVA: 0xC6BCE0
__int64 __fastcall hkStringBuf::replace(hkStringBuf *this, char from, char to, hkStringBuf::ReplaceType rt)
{
  unsigned int v4; // ebx
  int v5; // r11d
  __int64 i; // r10

  v4 = 0;
  v5 = 0;
  for ( i = 0i64; v5 < this->m_string.m_size - 1; ++i )
  {
    if ( this->m_string.m_data[i] == from )
    {
      this->m_string.m_data[i] = to;
      v4 = 1;
      if ( rt == REPLACE_ONE )
        break;
    }
    ++v5;
  }
  return v4;
}

// File Line: 590
// RVA: 0xC6BD30
__int64 __fastcall hkStringBuf::replace(
        hkStringBuf *this,
        const char *from,
        const char *to,
        hkStringBuf::ReplaceType rtype)
{
  hkResultEnum v8; // esi
  hkResultEnum v9; // eax
  __int64 v10; // r15
  int v11; // edi
  int v12; // ebx
  char *m_data; // rsi
  int v14; // ebp
  int v15; // r14d
  int v16; // eax
  hkResultEnum m_enum; // r8d
  __int64 v18; // rdi
  __int64 v19; // rbx
  __int64 v20; // r10
  int v21; // r9d
  char v22; // al
  __int64 v23; // rcx
  char v24; // al
  int v25; // eax
  char *v26; // rcx
  char *v27; // rdx
  __int64 v28; // rbx
  int v29; // r14d
  int v30; // eax
  int v31; // eax
  int v32; // r9d
  unsigned int v34; // [rsp+30h] [rbp-D8h]
  hkResult result; // [rsp+34h] [rbp-D4h] BYREF
  hkStringBuf v36; // [rsp+40h] [rbp-C8h] BYREF

  v8 = (unsigned int)hkString::strLen(from);
  result.m_enum = v8;
  v9 = (unsigned int)hkString::strLen(to);
  v34 = 0;
  v10 = v9;
  if ( v9 <= v8 )
  {
    m_data = this->m_string.m_data;
    v14 = 0;
    v15 = 0;
    v16 = hkStringBuf::indexOf(this, from, 0, 0x7FFFFFFF);
    m_enum = result.m_enum;
    v18 = 0i64;
    v19 = 0i64;
    v20 = result.m_enum;
    v21 = v16;
    if ( v16 != -1 )
    {
      do
      {
        if ( v18 < v21 )
        {
          v14 += v21 - v18;
          v15 += v21 - v18;
          do
          {
            v22 = m_data[v18++];
            m_data[v19++] = v22;
          }
          while ( v18 < v21 );
        }
        v23 = 0i64;
        if ( v10 > 0 )
        {
          v15 += v10;
          do
          {
            v24 = to[v23++];
            m_data[v19++] = v24;
          }
          while ( v23 < v10 );
        }
        v14 += m_enum;
        v18 += v20;
        if ( rtype == REPLACE_ONE )
          break;
        v25 = hkStringBuf::indexOf(this, from, v21 + m_enum, 0x7FFFFFFF);
        m_enum = result.m_enum;
        v20 = result.m_enum;
        v21 = v25;
      }
      while ( v25 != -1 );
    }
    if ( v14 < this->m_string.m_size - 1 )
    {
      v26 = &m_data[v15];
      v27 = &m_data[v14];
      do
      {
        ++v14;
        ++v15;
        *v26++ = *v27++;
      }
      while ( v14 < this->m_string.m_size - 1 );
    }
    v28 = v15;
    v29 = v15 + 1;
    m_data[v28] = 0;
    v30 = this->m_string.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v30 < v29 )
    {
      v31 = 2 * v30;
      v32 = v29;
      if ( v29 < v31 )
        v32 = v31;
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_string.m_data, v32, 1);
    }
    this->m_string.m_size = v29;
    this->m_string.m_data[v28] = 0;
  }
  else
  {
    hkStringBuf::hkStringBuf(&v36, this);
    hkStringBuf::clear(this);
    v11 = 0;
    v12 = hkStringBuf::indexOf(&v36, from, 0, 0x7FFFFFFF);
    if ( v12 >= 0 )
    {
      v34 = 1;
      do
      {
        hkStringBuf::append(this, &v36.m_string.m_data[v11], v12 - v11);
        hkStringBuf::append(this, to, v10);
        v11 = v12 + v8;
        if ( rtype == REPLACE_ONE )
          break;
        v12 = hkStringBuf::indexOf(&v36, from, v11, 0x7FFFFFFF);
      }
      while ( v12 >= 0 );
    }
    hkStringBuf::append(this, &v36.m_string.m_data[v11], v36.m_string.m_size - v11 - 1);
    v36.m_string.m_size = 0;
    if ( v36.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v36.m_string.m_data,
        v36.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  }
  return v34;
}

// File Line: 652
// RVA: 0xC6BFD0
void __fastcall hkStringBuf::lowerCase(hkStringBuf *this)
{
  int v1; // edx
  __int64 i; // r8
  char v3; // al

  v1 = 0;
  for ( i = 0i64; v1 < this->m_string.m_size - 1; ++i )
  {
    v3 = this->m_string.m_data[i];
    if ( (unsigned __int8)(v3 - 65) <= 0x19u )
      v3 += 32;
    this->m_string.m_data[i] = v3;
    ++v1;
  }
}

// File Line: 660
// RVA: 0xC6C020
void __fastcall hkStringBuf::upperCase(hkStringBuf *this)
{
  int v1; // edx
  __int64 i; // r8
  char v3; // al

  v1 = 0;
  for ( i = 0i64; v1 < this->m_string.m_size - 1; ++i )
  {
    v3 = this->m_string.m_data[i];
    if ( (unsigned __int8)(v3 - 97) <= 0x19u )
      v3 -= 32;
    this->m_string.m_data[i] = v3;
    ++v1;
  }
}

// File Line: 668
// RVA: 0xC6C070
hkStringBuf *__fastcall hkStringBuf::getArray(hkStringBuf *this)
{
  return this;
}


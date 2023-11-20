// File Line: 14
// RVA: 0xC6C080
__int64 __fastcall tolower(char i)
{
  __int64 result; // rax

  result = (unsigned int)i;
  if ( (unsigned __int8)(i - 65) <= 0x19u )
    result = (unsigned int)(result + 32);
  return result;
}

// File Line: 21
// RVA: 0xC6C0A0
__int64 __fastcall toupper(char i)
{
  __int64 result; // rax

  result = (unsigned int)i;
  if ( (unsigned __int8)(i - 97) <= 0x19u )
    result = (unsigned int)(result - 32);
  return result;
}

// File Line: 38
// RVA: 0xC6A6C0
void __fastcall hkStringBuf::hkStringBuf(hkStringBuf *this, const char *s)
{
  const char *v2; // rsi
  hkStringBuf *v3; // rdi
  int v4; // ebx

  v2 = s;
  v3 = this;
  this->m_string.m_size = 0;
  this->m_string.m_capacityAndFlags = -2147483520;
  this->m_string.m_data = this->m_string.m_storage;
  if ( s )
  {
    v4 = hkString::strLen(s);
    hkStringBuf::setLength(v3, v4);
    hkString::memCpy(v3->m_string.m_data, v2, v4);
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
  hkStringBuf::operator=(this, (const char *)((_QWORD)s->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
}

// File Line: 57
// RVA: 0xC6A790
void __fastcall hkStringBuf::hkStringBuf(hkStringBuf *this, const char *s0, const char *s1, const char *s2, const char *s3, const char *s4, const char *s5)
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
  const char *v4; // rbp
  int v5; // edi
  hkStringBuf *v6; // rbx
  int v7; // er9
  hkResult result; // [rsp+50h] [rbp+18h]

  v3 = len;
  v4 = b;
  v5 = len + 1;
  v6 = this;
  this->m_string.m_size = 0;
  this->m_string.m_data = this->m_string.m_storage;
  this->m_string.m_capacityAndFlags = -2147483520;
  if ( len + 1 > 128 )
  {
    v7 = len + 1;
    if ( v5 < 256 )
      v7 = 256;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, this, v7, 1);
  }
  v6->m_string.m_size = v5;
  v6->m_string.m_data[v3] = 0;
  hkString::memCpy(v6->m_string.m_data, v4, v3);
}

// File Line: 69
// RVA: 0xC6A890
void __fastcall hkStringBuf::hkStringBuf(hkStringBuf *this, hkStringBuf *s)
{
  hkStringBuf *v2; // rdi
  hkStringBuf *v3; // rbx
  __int64 v4; // rcx
  char *v5; // rax
  __int64 v6; // rdx
  char *v7; // r8
  char v8; // cl
  int v9; // [rsp+30h] [rbp+8h]

  this->m_string.m_size = 0;
  this->m_string.m_capacityAndFlags = -2147483520;
  this->m_string.m_data = this->m_string.m_storage;
  v2 = s;
  v3 = this;
  if ( s->m_string.m_size > 128 )
  {
    v9 = s->m_string.m_size;
    this->m_string.m_data = (char *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                      &v9);
    v3->m_string.m_capacityAndFlags = v9;
  }
  v4 = v2->m_string.m_size;
  v5 = v3->m_string.m_data;
  v3->m_string.m_size = v4;
  v6 = v4;
  if ( (signed int)v4 > 0 )
  {
    v7 = (char *)(v2->m_string.m_data - v5);
    do
    {
      v8 = (v5++)[(_QWORD)v7];
      *(v5 - 1) = v8;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 74
// RVA: 0xC6A930
hkStringBuf *__fastcall hkStringBuf::operator=(hkStringBuf *this, hkStringBuf *s)
{
  hkStringBuf *v2; // rdi
  hkStringBuf *v3; // rbx
  __int64 v4; // rcx
  char *v5; // rax
  __int64 v6; // rdx
  char *v7; // r8
  char v8; // cl
  int v10; // [rsp+30h] [rbp+8h]

  v2 = s;
  v3 = this;
  if ( (this->m_string.m_capacityAndFlags & 0x3FFFFFFF) < s->m_string.m_size )
  {
    if ( this->m_string.m_capacityAndFlags >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, char *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        this->m_string.m_data);
    v10 = v2->m_string.m_size;
    v3->m_string.m_data = (char *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                    &v10);
    v3->m_string.m_capacityAndFlags = v10;
  }
  v4 = v2->m_string.m_size;
  v5 = v3->m_string.m_data;
  v3->m_string.m_size = v4;
  v6 = v4;
  if ( (signed int)v4 > 0 )
  {
    v7 = (char *)(v2->m_string.m_data - v5);
    do
    {
      v8 = (v5++)[(_QWORD)v7];
      *(v5 - 1) = v8;
      --v6;
    }
    while ( v6 );
  }
  return v3;
}

// File Line: 80
// RVA: 0xC6A9E0
hkStringBuf *__fastcall hkStringBuf::operator=(hkStringBuf *this, const char *s)
{
  const char *v2; // rsi
  hkStringBuf *v3; // rdi
  int v4; // ebx
  hkStringBuf *v5; // rax
  int v6; // eax
  int v7; // eax
  int v8; // er9
  hkResult result; // [rsp+40h] [rbp+8h]

  v2 = s;
  v3 = this;
  if ( s )
  {
    v4 = hkString::strLen(s);
    hkStringBuf::setLength(v3, v4);
    hkString::memCpy(v3->m_string.m_data, v2, v4);
    v5 = v3;
  }
  else
  {
    v6 = this->m_string.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v6 < 1 )
    {
      v7 = 2 * v6;
      v8 = 1;
      if ( v7 > 1 )
        v8 = v7;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, this, v8, 1);
    }
    v3->m_string.m_size = 1;
    *v3->m_string.m_data = 0;
    v5 = v3;
  }
  return v5;
}

// File Line: 95
// RVA: 0xC6AA90
signed __int64 __fastcall hkStringBuf::indexOf(hkStringBuf *this, char c, int startIndex, int endIndex)
{
  signed __int64 v4; // r10
  int v5; // er8
  signed __int64 v6; // rax
  char *v7; // rcx

  v4 = startIndex;
  v5 = this->m_string.m_size - 1;
  v6 = v4;
  if ( endIndex < v5 )
    v5 = endIndex;
  if ( v4 >= v5 )
    return 0xFFFFFFFFi64;
  v7 = this->m_string.m_data;
  while ( v7[v6] != c )
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
signed __int64 __fastcall hkStringBuf::indexOf(hkStringBuf *this, const char *s, int startIndex, int endIndex)
{
  hkStringBuf *v4; // rbx
  char *v5; // rax
  signed __int64 result; // rax

  v4 = this;
  v5 = hkString::strStr(&this->m_string.m_data[startIndex], s);
  if ( v5 )
    result = (unsigned int)((_DWORD)v5 - LODWORD(v4->m_string.m_data));
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 118
// RVA: 0xC6AB00
signed __int64 __fastcall hkStringBuf::indexOfCase(hkStringBuf *this, const char *needle)
{
  char *v2; // r11
  unsigned int v3; // edi
  const char *v4; // rsi
  char v5; // bp
  signed __int64 v6; // r14
  __int64 v7; // r10
  char v8; // al
  const char *v9; // r9
  char v10; // dl
  char v11; // r8
  char v12; // cl

  v2 = this->m_string.m_data;
  v3 = 0;
  v4 = needle;
  if ( !*this->m_string.m_data )
    return 0xFFFFFFFFi64;
  v5 = *needle;
  v6 = -(signed __int64)needle;
  while ( 1 )
  {
    v7 = 0i64;
    if ( v5 )
    {
      v8 = v5;
      v9 = v4;
      do
      {
        v10 = v2[v6 + (_QWORD)v9];
        v11 = v10;
        if ( (unsigned __int8)(v10 - 65) <= 0x19u )
          v11 = v10 + 32;
        v12 = v8;
        if ( (unsigned __int8)(v8 - 65) <= 0x19u )
          v12 = v8 + 32;
        if ( v11 != v12 )
          break;
        v8 = (v9++)[1];
        ++v7;
      }
      while ( v8 );
    }
    if ( !v4[v7] )
      break;
    ++v2;
    ++v3;
    if ( !*v2 )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 146
// RVA: 0xC6ABC0
signed __int64 __fastcall hkStringBuf::lastIndexOf(hkStringBuf *this, char c, int start, int end)
{
  int v4; // er9
  signed __int64 v5; // rax
  char *v6; // rcx

  if ( end > this->m_string.m_size - 1 )
    end = this->m_string.m_size - 1;
  v4 = end - 1;
  v5 = v4;
  if ( v4 < (signed __int64)start )
    return 0xFFFFFFFFi64;
  v6 = this->m_string.m_data;
  while ( v6[v5] != c )
  {
    --v5;
    --v4;
    if ( v5 < start )
      return 0xFFFFFFFFi64;
  }
  return (unsigned int)v4;
}

// File Line: 161
// RVA: 0xC6AC00
signed __int64 __fastcall hkStringBuf::lastIndexOf(hkStringBuf *this, const char *needle, int startIndex, int endIndex)
{
  hkStringBuf *v4; // rsi
  const char *v5; // rdi
  char *v6; // rax
  unsigned int v7; // ebx

  v4 = this;
  v5 = needle;
  v6 = hkString::strStr(this->m_string.m_data, needle);
  if ( !v6 )
    return 0xFFFFFFFFi64;
  do
  {
    v7 = (_DWORD)v6 - LODWORD(v4->m_string.m_data);
    v6 = hkString::strStr(v6 + 1, v5);
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
signed __int64 __fastcall hkStringBuf::compareToIgnoreCase(hkStringBuf *this, const char *other)
{
  return hkString::strCasecmp(this->m_string.m_data, other);
}

// File Line: 185
// RVA: 0xC6AC90
hkBool *__fastcall hkStringBuf::operator<(hkStringBuf *this, hkBool *result, const char *other)
{
  hkBool *v3; // rbx

  v3 = result;
  result->m_bool = (signed int)hkString::strCmp(this->m_string.m_data, other) < 0;
  return v3;
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
  char *v2; // rax
  unsigned int v3; // er10
  int v4; // er9
  const char *v5; // rcx

  v2 = this->m_string.m_data;
  v3 = 0;
  v4 = 0;
  if ( *this->m_string.m_data )
  {
    v5 = s;
    while ( *v5 )
    {
      if ( *v2 != *v5 )
        return 0i64;
      ++v2;
      ++v4;
      ++v5;
      if ( !*v2 )
        break;
    }
  }
  LOBYTE(v3) = s[v4] == 0;
  return v3;
}

// File Line: 208
// RVA: 0xC6AD30
signed __int64 __fastcall hkStringBuf::startsWithCase(hkStringBuf *this, const char *s)
{
  char *v2; // r8
  const char *i; // r9
  char v4; // cl
  char v5; // dl
  char v6; // al

  v2 = this->m_string.m_data;
  for ( i = s; *v2; ++i )
  {
    v4 = *i;
    if ( !*i )
      break;
    v5 = *v2;
    if ( (unsigned __int8)(*v2 - 65) <= 0x19u )
      v5 += 32;
    v6 = *i;
    if ( (unsigned __int8)(v4 - 65) <= 0x19u )
      v6 = v4 + 32;
    if ( v5 != v6 )
      return 0i64;
    ++v2;
  }
  return 1i64;
}

// File Line: 220
// RVA: 0xC6AD90
signed __int64 __fastcall hkStringBuf::endsWith(hkStringBuf *this, const char *s)
{
  hkStringBuf *v2; // rdi
  const char *v3; // rbx
  int v4; // eax
  int v5; // edx
  __int64 v6; // r9
  __int64 v8; // rax
  int v9; // edx

  v2 = this;
  v3 = s;
  v4 = hkString::strLen(s);
  v5 = v2->m_string.m_size;
  v6 = v4;
  if ( v4 > v5 - 1 )
    return 0i64;
  v8 = 0i64;
  v9 = v5 - v6 - 1;
  if ( (signed int)v6 > 0 )
  {
    while ( v2->m_string.m_data[v9 + v8] == v3[v8] )
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
signed __int64 __fastcall hkStringBuf::endsWithCase(hkStringBuf *this, const char *s)
{
  hkStringBuf *v2; // rbx
  const char *v3; // rdi
  int v4; // eax
  int v5; // er9
  __int64 v7; // rcx
  __int64 v8; // rdx
  __int64 v9; // r9
  char *v10; // r10
  char v11; // dl
  char v12; // r8
  char v13; // al

  v2 = this;
  v3 = s;
  v4 = hkString::strLen(s);
  v5 = v2->m_string.m_size;
  if ( v4 > v5 - 1 )
    return 0i64;
  v7 = 0i64;
  v8 = v5 - v4 - 1;
  v9 = v4;
  if ( v4 > 0 )
  {
    v10 = &v2->m_string.m_data[v8];
    while ( 1 )
    {
      v11 = v10[v7];
      if ( (unsigned __int8)(v11 - 65) <= 0x19u )
        v11 += 32;
      v12 = v3[v7];
      v13 = v12;
      if ( (unsigned __int8)(v12 - 65) <= 0x19u )
        v13 = v12 + 32;
      if ( v11 != v13 )
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
__int64 __fastcall hkStringBuf::split(hkStringBuf *this, int sep, hkArray<char const *,hkContainerTempAllocator> *bits)
{
  char *v3; // rdi
  hkArray<char const *,hkContainerTempAllocator> *v4; // rbx
  char v5; // r14
  hkStringBuf *v6; // rsi
  unsigned int v7; // edi
  int i; // edx
  int v9; // ebp
  const char *v10; // rdi

  v3 = this->m_string.m_data;
  v4 = bits;
  v5 = sep;
  v6 = this;
  if ( bits->m_size == (bits->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, bits, 8);
  v4->m_data[v4->m_size++] = v3;
  v7 = v4->m_size;
  for ( i = hkStringBuf::indexOf(v6, v5, 0, 0x7FFFFFFF); i >= 0; i = hkStringBuf::indexOf(v6, v5, v9, 0x7FFFFFFF) )
  {
    v9 = i + 1;
    v6->m_string.m_data[i] = 0;
    v10 = &v6->m_string.m_data[i + 1];
    if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, 8);
    v4->m_data[v4->m_size++] = v10;
    v7 = v4->m_size;
  }
  return v7;
}

// File Line: 279
// RVA: 0xC6AFB0
void __fastcall hkStringBuf::clear(hkStringBuf *this)
{
  hkStringBuf *v1; // rbx
  int v2; // eax
  int v3; // eax
  int v4; // er9
  hkResult result; // [rsp+40h] [rbp+8h]

  v1 = this;
  v2 = this->m_string.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v2 < 1 )
  {
    v3 = 2 * v2;
    v4 = 1;
    if ( v3 > 1 )
      v4 = v3;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, this, v4, 1);
  }
  v1->m_string.m_size = 1;
  *v1->m_string.m_data = 0;
}

// File Line: 284
// RVA: 0xC6B010
void hkStringBuf::printf(hkStringBuf *this, const char *fmt, ...)
{
  hkStringBuf *v2; // rbx
  signed int v3; // esi
  int v4; // eax
  __int64 v5; // rdi
  int v6; // esi
  int v7; // ecx
  int v8; // ecx
  int v9; // er9
  char *v10; // rax
  int v11; // edi
  int v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // er9
  hkResult result; // [rsp+30h] [rbp-38h]
  hkResult v17; // [rsp+34h] [rbp-34h]
  char *fmta; // [rsp+78h] [rbp+10h]
  va_list va; // [rsp+80h] [rbp+18h]

  va_start(va, fmt);
  fmta = (char *)fmt;
  v2 = this;
  while ( 1 )
  {
    while ( 1 )
    {
      v3 = v2->m_string.m_capacityAndFlags & 0x3FFFFFFF;
      v4 = hkString::vsnprintf(v2->m_string.m_data, v3, fmta, va);
      v5 = v4;
      if ( v4 >= 0 )
        break;
      v11 = 255;
      if ( 2 * v3 > 255 )
        v11 = 2 * v3;
      v12 = v11 + 1;
      v13 = v2->m_string.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v13 >= v11 + 1 )
      {
        v2->m_string.m_size = v12;
        v2->m_string.m_data[v11] = 0;
        v17.m_enum = 0;
      }
      else
      {
        v14 = 2 * v13;
        v15 = v11 + 1;
        if ( v12 < v14 )
          v15 = v14;
        hkArrayUtil::_reserve(&v17, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v2, v15, 1);
        v2->m_string.m_size = v12;
        v2->m_string.m_data[v11] = 0;
      }
    }
    if ( (signed int)v5 < v3 )
      break;
    v6 = v5 + 1;
    v7 = v2->m_string.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v7 >= (signed int)v5 + 1 )
    {
      v2->m_string.m_size = v6;
      v10 = v2->m_string.m_data;
      result.m_enum = 0;
      v10[v5] = 0;
    }
    else
    {
      v8 = 2 * v7;
      v9 = v5 + 1;
      if ( v6 < v8 )
        v9 = v8;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v2, v9, 1);
      v2->m_string.m_size = v6;
      v2->m_string.m_data[v5] = 0;
    }
  }
  hkStringBuf::setLength(v2, v4);
}

// File Line: 314
// RVA: 0xC6B140
void hkStringBuf::appendPrintf(hkStringBuf *this, const char *fmt, ...)
{
  hkStringBuf *v2; // rsi
  int v3; // edi
  int v4; // eax
  __int64 v5; // rbx
  bool v6; // sf
  unsigned __int8 v7; // of
  int v8; // edi
  int v9; // er9
  int v10; // ebx
  int v11; // er9
  int v12; // er9
  hkResult v13; // [rsp+30h] [rbp-79h]
  hkResult result; // [rsp+34h] [rbp-75h]
  char *buf; // [rsp+40h] [rbp-69h]
  int v16; // [rsp+48h] [rbp-61h]
  int v17; // [rsp+4Ch] [rbp-5Dh]
  char v18; // [rsp+50h] [rbp-59h]
  char *fmta; // [rsp+118h] [rbp+6Fh]
  va_list hkargs; // [rsp+120h] [rbp+77h]

  va_start(hkargs, fmt);
  fmta = (char *)fmt;
  v2 = this;
  v17 = -2147483520;
  v16 = 1;
  v18 = 0;
  buf = &v18;
  while ( 1 )
  {
    while ( 1 )
    {
      v3 = v17 & 0x3FFFFFFF;
      v4 = hkString::vsnprintf(buf, v17 & 0x3FFFFFFF, fmta, hkargs);
      v5 = v4;
      if ( v4 >= 0 )
        break;
      v10 = 255;
      if ( 2 * v3 > 255 )
        v10 = 2 * v3;
      if ( (v17 & 0x3FFFFFFF) >= v10 + 1 )
      {
        v16 = v10 + 1;
        buf[v10] = 0;
        v13.m_enum = 0;
      }
      else
      {
        v11 = v10 + 1;
        if ( v10 + 1 < 2 * (v17 & 0x3FFFFFFF) )
          v11 = 2 * (v17 & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&v13, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &buf, v11, 1);
        v16 = v10 + 1;
        buf[v10] = 0;
      }
    }
    v7 = __OFSUB__((_DWORD)v5, v3);
    v6 = (signed int)v5 - v3 < 0;
    v8 = v5 + 1;
    if ( v6 ^ v7 )
      break;
    if ( (v17 & 0x3FFFFFFF) >= v8 )
    {
      v16 = v5 + 1;
      result.m_enum = 0;
      buf[v4] = 0;
    }
    else
    {
      v9 = v5 + 1;
      if ( v8 < 2 * (v17 & 0x3FFFFFFF) )
        v9 = 2 * (v17 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &buf, v9, 1);
      v16 = v5 + 1;
      buf[v5] = 0;
    }
  }
  if ( (v17 & 0x3FFFFFFF) < v8 )
  {
    v12 = v5 + 1;
    if ( v8 < 2 * (v17 & 0x3FFFFFFF) )
      v12 = 2 * (v17 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v13, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &buf, v12, 1);
  }
  v16 = v5 + 1;
  buf[v5] = 0;
  hkStringBuf::append(v2, buf, -1);
  v16 = 0;
  if ( v17 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      buf,
      v17 & 0x3FFFFFFF);
}

// File Line: 346
// RVA: 0xC6B310
hkStringBuf *__fastcall hkStringBuf::operator+=(hkStringBuf *this, const char *other)
{
  const char *v2; // rdi
  hkStringBuf *v3; // rbx
  int numtoinsert; // eax

  v2 = other;
  v3 = this;
  if ( other )
  {
    numtoinsert = hkString::strLen(other);
    hkArrayBase<char>::_insertAt(
      (hkArrayBase<char> *)&v3->m_string.m_data,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      v3->m_string.m_size - 1,
      v2,
      numtoinsert);
  }
  return v3;
}

// File Line: 356
// RVA: 0xC6B360
hkStringBuf *__fastcall hkStringBuf::appendJoin(hkStringBuf *this, const char *s0, const char *s1, const char *s2, const char *s3, const char *s4, const char *s5)
{
  int v7; // ebp
  __int64 v8; // rdi
  int v9; // ebp
  const char *v10; // rsi
  hkStringBuf *v11; // r14
  int v12; // er15
  __int64 v13; // rbx
  const char *v14; // rax
  int v15; // eax
  int v16; // ebx
  int v17; // eax
  int v18; // eax
  int v19; // er9
  int v20; // ebx
  int v22; // [rsp+2Ch] [rbp-6Ch]
  __int64 n; // [rsp+30h] [rbp-68h]
  __int64 v24; // [rsp+38h] [rbp-60h]
  __int64 v25; // [rsp+40h] [rbp-58h]
  const char *v26; // [rsp+48h] [rbp-50h]
  const char *v27; // [rsp+50h] [rbp-48h]
  const char *v28; // [rsp+58h] [rbp-40h]
  const char *v29; // [rsp+60h] [rbp-38h]
  unsigned __int128 v30; // [rsp+68h] [rbp-30h]
  __int64 v31; // [rsp+78h] [rbp-20h]

  v7 = this->m_string.m_size;
  v8 = 0i64;
  n = 0i64;
  v24 = 0i64;
  v25 = 0i64;
  v9 = v7 - 1;
  v10 = s0;
  v29 = s3;
  v11 = this;
  v30 = __PAIR__((unsigned __int64)s5, (unsigned __int64)s4);
  v26 = s0;
  v27 = s1;
  v28 = s2;
  v31 = 0i64;
  v12 = v9;
  v13 = 0i64;
  if ( s0 )
  {
    v14 = s0;
    do
    {
      v15 = hkString::strLen(v14);
      *(&v22 + ++v13) = v15;
      v12 += v15;
      v14 = (&v26)[v13];
    }
    while ( v14 );
  }
  v16 = v12 + 1;
  v17 = v11->m_string.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v17 < v12 + 1 )
  {
    v18 = 2 * v17;
    v19 = v12 + 1;
    if ( v16 < v18 )
      v19 = v18;
    hkArrayUtil::_reserve((hkResult *)&s3, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v11, v19, 1);
  }
  v11->m_string.m_size = v16;
  for ( v11->m_string.m_data[v12] = 0; v10; v10 = (&v26)[v8] )
  {
    v20 = *((_DWORD *)&n + v8);
    hkString::memCpy(&v11->m_string.m_data[v9], v10, *((_DWORD *)&n + v8++));
    v9 += v20;
  }
  return v11;
}

// File Line: 377
// RVA: 0xC6B4A0
hkStringBuf *__fastcall hkStringBuf::setJoin(hkStringBuf *this, const char *s0, const char *s1, const char *s2, const char *s3, const char *s4, const char *s5)
{
  const char *v7; // rbx
  const char *v8; // rdi
  const char *v9; // rsi
  hkStringBuf *v10; // rbp

  v7 = s2;
  v8 = s1;
  v9 = s0;
  v10 = this;
  hkStringBuf::clear(this);
  hkStringBuf::appendJoin(v10, v9, v8, v7, s3, s4, s5);
  return v10;
}

// File Line: 384
// RVA: 0xC6B520
void __fastcall hkStringBuf::chompStart(hkStringBuf *this, int n)
{
  int v2; // er9
  int v3; // er8
  int v4; // er9
  char *v5; // rax
  char *v6; // r8
  signed __int64 v7; // r8
  __int64 v8; // rdx
  char v9; // cl

  v2 = this->m_string.m_size;
  v3 = v2 - 1;
  if ( n < v2 - 1 )
    v3 = n;
  if ( v3 > 0 )
  {
    v4 = v2 - v3;
    this->m_string.m_size = v4;
    v5 = this->m_string.m_data;
    v6 = &this->m_string.m_data[v3];
    if ( v4 > 0 )
    {
      v7 = v6 - v5;
      v8 = (unsigned int)v4;
      do
      {
        v9 = (v5++)[v7];
        *(v5 - 1) = v9;
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
  hkStringBuf *v4; // rbx
  int v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // er9
  hkResult result; // [rsp+48h] [rbp+10h]

  v3 = length;
  v4 = this;
  if ( startOffset )
    hkMemUtil::memMove(this->m_string.m_data, &this->m_string.m_data[startOffset], length);
  v5 = v3 + 1;
  v6 = v4->m_string.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < (signed int)v3 + 1 )
  {
    v7 = 2 * v6;
    v8 = v3 + 1;
    if ( v5 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, v8, 1);
  }
  v4->m_string.m_size = v5;
  v4->m_string.m_data[v3] = 0;
}

// File Line: 412
// RVA: 0xC6B620
void __fastcall hkStringBuf::set(hkStringBuf *this, const char *s, int len)
{
  int v3; // ebx
  const char *v4; // rbp
  hkStringBuf *v5; // rdi
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // er9
  hkResult result; // [rsp+50h] [rbp+18h]

  v3 = len;
  v4 = s;
  v5 = this;
  if ( len < 0 )
    v3 = hkString::strLen(s);
  v6 = v3 + 1;
  v7 = v5->m_string.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v3 + 1 )
  {
    v8 = 2 * v7;
    v9 = v3 + 1;
    if ( v6 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, v9, 1);
  }
  v5->m_string.m_size = v6;
  v5->m_string.m_data[v3] = 0;
  hkMemUtil::memCpy(v5->m_string.m_data, v4, v3);
}

// File Line: 423
// RVA: 0xC6B6C0
void __fastcall hkStringBuf::append(hkStringBuf *this, const char *s, int len)
{
  int v3; // edi
  const char *v4; // rsi
  hkStringBuf *v5; // rbp
  int v6; // ebx

  if ( s )
  {
    v3 = len;
    v4 = s;
    v5 = this;
    if ( len < 0 )
      v3 = hkString::strLen(s);
    v6 = v5->m_string.m_size - 1;
    hkStringBuf::setLength(v5, v6 + v3);
    hkMemUtil::memCpy(&v5->m_string.m_data[v6], v4, v3);
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
  const char *v5; // rbx
  int v6; // edi
  hkStringBuf *v7; // rsi

  if ( s )
  {
    numtoinsert = len;
    v5 = s;
    v6 = pos;
    v7 = this;
    if ( len < 0 )
      numtoinsert = hkString::strLen(s);
    hkArrayBase<char>::_insertAt(
      (hkArrayBase<char> *)&v7->m_string.m_data,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      v6,
      v5,
      numtoinsert);
  }
}

// File Line: 456
// RVA: 0xC6B7B0
void __fastcall hkStringBuf::pathBasename(hkStringBuf *this)
{
  hkStringBuf *v1; // rdi
  int v2; // ebx
  int v3; // eax

  v1 = this;
  v2 = hkStringBuf::lastIndexOf(this, 47, 0, 0x7FFFFFFF);
  v3 = hkStringBuf::lastIndexOf(v1, 92, 0, 0x7FFFFFFF);
  if ( v3 > v2 )
    v2 = v3;
  if ( v2 >= 0 )
    hkStringBuf::chompStart(v1, v2 + 1);
}

// File Line: 465
// RVA: 0xC6B810
void __fastcall hkStringBuf::pathDirname(hkStringBuf *this)
{
  hkStringBuf *v1; // rbx
  int v2; // edi
  int v3; // eax

  v1 = this;
  v2 = hkStringBuf::lastIndexOf(this, 47, 0, 0x7FFFFFFF);
  v3 = hkStringBuf::lastIndexOf(v1, 92, 0, 0x7FFFFFFF);
  if ( v3 > v2 )
    v2 = v3;
  if ( v2 < 0 )
    hkStringBuf::clear(v1);
  else
    hkStringBuf::slice(v1, 0, v2);
}

// File Line: 478
// RVA: 0xC6B880
void __fastcall hkStringBuf::pathNormalize(hkStringBuf *this)
{
  hkStringBuf *v1; // r12
  const char *v2; // r15
  int v3; // edi
  int v4; // esi
  __int64 v5; // rbx
  int v6; // ecx
  const char **v7; // r14
  int v8; // ecx
  const char **v9; // r14
  int v10; // edi
  __int64 v11; // rbx
  _QWORD *array; // [rsp+18h] [rbp-79h]
  int v13; // [rsp+20h] [rbp-71h]
  int v14; // [rsp+24h] [rbp-6Dh]
  hkArray<char const *,hkContainerTempAllocator> bits; // [rsp+28h] [rbp-69h]
  hkStringBuf v16; // [rsp+38h] [rbp-59h]

  v1 = this;
  hkStringBuf::hkStringBuf(&v16, this);
  hkStringBuf::replace(&v16, 92, 47, REPLACE_ALL);
  v2 = "//";
  if ( !(unsigned int)hkStringBuf::startsWith(&v16, "//") )
  {
    v2 = &customWorldMapCaption;
    if ( (unsigned int)hkStringBuf::startsWith(&v16, "/") )
      v2 = "/";
  }
  bits.m_data = 0i64;
  bits.m_size = 0;
  bits.m_capacityAndFlags = 2147483648;
  hkStringBuf::split(&v16, 47, &bits);
  array = 0i64;
  v13 = 0;
  v14 = 2147483648;
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
          v9 = bits.m_data;
          ++v3;
          if ( v13 == (v14 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 8);
            v8 = v13;
          }
          array[v8] = v9[v5];
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
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 8);
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
  hkStringBuf::operator=(v1, v2);
  v10 = 0;
  if ( v13 > 0 )
  {
    v11 = 0i64;
    do
    {
      hkStringBuf::pathAppend(v1, (const char *)array[v11], 0i64, 0i64);
      ++v10;
      ++v11;
    }
    while ( v10 < v13 );
  }
  v13 = 0;
  if ( v14 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      8 * v14);
  array = 0i64;
  v14 = 2147483648;
  bits.m_size = 0;
  if ( bits.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      bits.m_data,
      8 * bits.m_capacityAndFlags);
  bits.m_data = 0i64;
  v16.m_string.m_size = 0;
  bits.m_capacityAndFlags = 2147483648;
  if ( v16.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v16.m_string.m_data,
      v16.m_string.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 524
// RVA: 0xC6BB40
void __fastcall hkStringBuf::pathExtension(hkStringBuf *this)
{
  hkStringBuf *v1; // rbx
  int v2; // eax

  v1 = this;
  v2 = hkStringBuf::lastIndexOf(this, 46, 0, 0x7FFFFFFF);
  if ( v2 == -1 )
    hkStringBuf::clear(v1);
  else
    hkStringBuf::chompStart(v1, v2);
}

// File Line: 537
// RVA: 0xC6BB80
hkStringBuf *__fastcall hkStringBuf::pathAppend(hkStringBuf *this, const char *p0, const char *p1, const char *p2)
{
  __int64 v4; // r14
  bool v5; // zf
  const char *v6; // rbx
  hkStringBuf *v7; // rsi
  bool i; // bp
  int v9; // eax
  int v10; // edi
  __int64 v11; // rcx
  const char *v13; // [rsp+28h] [rbp-20h]
  const char *v14; // [rsp+30h] [rbp-18h]
  __int64 v15; // [rsp+38h] [rbp-10h]

  v4 = 0i64;
  v5 = this->m_string.m_size-- == 1;
  v6 = p0;
  v7 = this;
  v13 = p1;
  v15 = 0i64;
  v14 = p2;
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
          if ( v7->m_string.m_size == (v7->m_string.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v7, 1);
          v7->m_string.m_data[v7->m_string.m_size++] = 47;
        }
        hkArrayBase<char>::_append(
          (hkArrayBase<char> *)&v7->m_string.m_data,
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
          v6,
          v10);
      }
      i = 1;
    }
    v6 = (&v13)[v4];
  }
  if ( v7->m_string.m_size == (v7->m_string.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v7, 1);
  v7->m_string.m_data[v7->m_string.m_size++] = 0;
  return v7;
}

// File Line: 572
// RVA: 0xC6BCE0
__int64 __fastcall hkStringBuf::replace(hkStringBuf *this, char from, char to, hkStringBuf::ReplaceType rt)
{
  unsigned int v4; // ebx
  int v5; // er11
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
__int64 __fastcall hkStringBuf::replace(hkStringBuf *this, const char *from, const char *to, hkStringBuf::ReplaceType rtype)
{
  hkStringBuf *v4; // r12
  hkStringBuf::ReplaceType v5; // er14
  const char *v6; // r13
  const char *v7; // rbp
  hkResultEnum v8; // esi
  hkResultEnum v9; // eax
  __int64 v10; // r15
  int v11; // edi
  int v12; // ebx
  char *v13; // rsi
  int v14; // ebp
  int v15; // er14
  int v16; // eax
  hkResultEnum v17; // er8
  signed __int64 v18; // rdi
  __int64 v19; // rbx
  __int64 v20; // r10
  int v21; // er9
  char v22; // al
  __int64 v23; // rcx
  char v24; // al
  int v25; // eax
  char *v26; // rcx
  char *v27; // rdx
  __int64 v28; // rbx
  int v29; // er14
  int v30; // eax
  int v31; // eax
  int v32; // er9
  unsigned int v34; // [rsp+30h] [rbp-D8h]
  hkResult result; // [rsp+34h] [rbp-D4h]
  hkStringBuf v36; // [rsp+40h] [rbp-C8h]
  char *s; // [rsp+118h] [rbp+10h]
  hkStringBuf::ReplaceType v38; // [rsp+128h] [rbp+20h]

  v38 = rtype;
  s = (char *)from;
  v4 = this;
  v5 = rtype;
  v6 = to;
  v7 = from;
  v8 = (unsigned int)hkString::strLen(from);
  result.m_enum = v8;
  v9 = (unsigned int)hkString::strLen(v6);
  v34 = 0;
  v10 = v9;
  if ( v9 <= v8 )
  {
    v13 = v4->m_string.m_data;
    v14 = 0;
    v15 = 0;
    v16 = hkStringBuf::indexOf(v4, s, 0, 0x7FFFFFFF);
    v17 = result.m_enum;
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
            v22 = v13[v18++];
            v13[++v19 - 1] = v22;
          }
          while ( v18 < v21 );
        }
        v23 = 0i64;
        if ( v10 > 0 )
        {
          v15 += v10;
          do
          {
            v24 = v6[v23++];
            v13[++v19 - 1] = v24;
          }
          while ( v23 < v10 );
        }
        v14 += v17;
        v18 += v20;
        if ( v38 == REPLACE_ONE )
          break;
        v25 = hkStringBuf::indexOf(v4, s, v21 + v17, 0x7FFFFFFF);
        v17 = result.m_enum;
        v20 = result.m_enum;
        v21 = v25;
      }
      while ( v25 != -1 );
    }
    if ( v14 < v4->m_string.m_size - 1 )
    {
      v26 = &v13[v15];
      v27 = &v13[v14];
      do
      {
        ++v14;
        ++v15;
        *v26++ = *v27++;
      }
      while ( v14 < v4->m_string.m_size - 1 );
    }
    v28 = v15;
    v29 = v15 + 1;
    v13[v28] = 0;
    v30 = v4->m_string.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v30 < v29 )
    {
      v31 = 2 * v30;
      v32 = v29;
      if ( v29 < v31 )
        v32 = v31;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, v32, 1);
    }
    v4->m_string.m_size = v29;
    v4->m_string.m_data[v28] = 0;
  }
  else
  {
    hkStringBuf::hkStringBuf(&v36, v4);
    hkStringBuf::clear(v4);
    v11 = 0;
    v12 = hkStringBuf::indexOf(&v36, v7, 0, 0x7FFFFFFF);
    if ( v12 >= 0 )
    {
      v34 = 1;
      do
      {
        hkStringBuf::append(v4, &v36.m_string.m_data[v11], v12 - v11);
        hkStringBuf::append(v4, v6, v10);
        v11 = v12 + v8;
        if ( v5 == REPLACE_ONE )
          break;
        v12 = hkStringBuf::indexOf(&v36, v7, v11, 0x7FFFFFFF);
      }
      while ( v12 >= 0 );
    }
    hkStringBuf::append(v4, &v36.m_string.m_data[v11], v36.m_string.m_size - v11 - 1);
    v36.m_string.m_size = 0;
    if ( v36.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
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
  hkStringBuf *v2; // r10
  __int64 i; // r8
  char v4; // cl
  char v5; // al

  v1 = 0;
  v2 = this;
  for ( i = 0i64; v1 < v2->m_string.m_size - 1; ++i )
  {
    v4 = v2->m_string.m_data[i];
    v5 = v4;
    if ( (unsigned __int8)(v4 - 65) <= 0x19u )
      v5 = v4 + 32;
    v2->m_string.m_data[i] = v5;
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


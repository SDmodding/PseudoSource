// File Line: 40
// RVA: 0xC5B5C0
__int64 __fastcall hkString::toUpper(int c)
{
  if ( (unsigned __int8)(c - 97) > 0x19u )
    return (unsigned __int8)c;
  else
    return (unsigned int)(c - 32);
}

// File Line: 46
// RVA: 0xC5B5E0
__int64 __fastcall hkString::toLower(int c)
{
  if ( (unsigned __int8)(c - 65) > 0x19u )
    return (unsigned __int8)c;
  else
    return (unsigned int)(c + 32);
}

// File Line: 54
// RVA: 0xC5B630
int __fastcall hkString::vsnprintf(char *buf, int len, const char *fmt, char *hkargs)
{
  return vsnprintf(buf, len, fmt, hkargs);
}

// File Line: 79
// RVA: 0xC5B600
int hkString::snprintf(char *buf, int len, const char *fmt, ...)
{
  va_list ap; // [rsp+48h] [rbp+20h] BYREF

  va_start(ap, fmt);
  return vsnprintf(buf, len, fmt, ap);
}

// File Line: 88
// RVA: 0xC5B640
int hkString::sprintf(char *buf, const char *fmt, ...)
{
  va_list ap; // [rsp+40h] [rbp+18h] BYREF

  va_start(ap, fmt);
  return vsprintf(buf, fmt, ap);
}

// File Line: 97
// RVA: 0xC5B670
__int64 __fastcall hkString::strCmp(const char *a, const char *b)
{
  __int64 v2; // rdx
  unsigned __int8 v3; // al

  v2 = b - a;
  while ( 1 )
  {
    v3 = *a;
    if ( *a != a[v2] )
      break;
    ++a;
    if ( !v3 )
      return 0i64;
  }
  return v3 < (unsigned int)a[v2] ? -1 : 1;
}

// File Line: 104
// RVA: 0xC5B6A0
int __fastcall hkString::strNcmp(const char *a, const char *b, unsigned int n)
{
  return strncmp(a, b, n);
}

// File Line: 111
// RVA: 0xC5B6B0
__int64 __fastcall hkString::strCasecmp(const char *a, const char *b)
{
  const char *v2; // rbx
  __int64 v3; // rsi
  int v4; // ecx
  char v5; // di
  char v6; // al

  v2 = b;
  v3 = a - b;
  while ( 1 )
  {
    v4 = (unsigned __int8)v2[v3];
    if ( !(_BYTE)v4 && !*v2 )
      return 0i64;
    v5 = hkString::toLower(v4);
    v6 = hkString::toLower(*(unsigned __int8 *)v2);
    if ( v5 < v6 )
      break;
    if ( v5 > v6 )
      return 1i64;
    ++v2;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 132
// RVA: 0xC5B730
__int64 __fastcall hkString::strNcasecmp(const char *a, __int64 b, int n)
{
  const char *v3; // rbx
  const char *v4; // rsi
  __int64 v5; // rbp
  __int64 v6; // r14
  int v7; // ecx
  char v8; // di
  char v9; // al

  v3 = (const char *)b;
  v4 = &a[-b];
  v5 = n;
  v6 = -b;
  while ( 1 )
  {
    v7 = (unsigned __int8)v3[(_QWORD)v4];
    if ( !(_BYTE)v7 && !*v3 )
      break;
    if ( (__int64)&v3[v6] >= v5 )
      break;
    v8 = hkString::toLower(v7);
    v9 = hkString::toLower(*(unsigned __int8 *)v3);
    if ( v8 < v9 )
      return 0xFFFFFFFFi64;
    if ( v8 > v9 )
      return 1i64;
    ++v3;
  }
  return 0i64;
}

// File Line: 155
// RVA: 0xC5B7C0
void __fastcall hkString::strCpy(char *dst, char *src)
{
  __int64 v2; // rcx
  char v3; // al

  v2 = dst - src;
  do
  {
    v3 = *src++;
    src[v2 - 1] = v3;
  }
  while ( v3 );
}

// File Line: 162
// RVA: 0xC5B7F0
void __fastcall hkString::strNcpy(char *dst, const char *src, unsigned int n)
{
  if ( n )
    strncpy(dst, src, n);
}

// File Line: 172
// RVA: 0xC5B810
__int64 __fastcall hkString::strLen(const char *src)
{
  __int64 result; // rax

  result = -1i64;
  do
    ++result;
  while ( src[result] );
  return result;
}

// File Line: 178
// RVA: 0xC5B830
void __fastcall hkString::strCat(char *dst, const char *src)
{
  char *v3; // rcx
  __int64 v5; // rdx
  char v6; // al

  v3 = dst - 1;
  while ( *++v3 != 0 )
    ;
  v5 = 0i64;
  do
  {
    v6 = src[v5++];
    v3[v5 - 1] = v6;
  }
  while ( v6 );
}

// File Line: 185
// RVA: 0xC5B870
void __fastcall hkString::strNcat(char *dst, const char *src, unsigned int n)
{
  if ( n )
    strncat(dst, src, n);
}

// File Line: 195
// RVA: 0xC5B890
unsigned int __fastcall hkString::atoi(const char *in, int base)
{
  return strtoul(in, 0i64, base);
}

// File Line: 200
// RVA: 0xC5B8A0
__int64 __fastcall hkString::atoll(const char *in, int base)
{
  return strtoi64(in, 0i64, base);
}

// File Line: 205
// RVA: 0xC5B8B0
unsigned __int64 __fastcall hkString::atoull(const char *in, int base)
{
  return strtoui64(in, 0i64, base);
}

// File Line: 210
// RVA: 0xC5B8C0
float __fastcall hkString::atof(const char *in)
{
  return strtod(in, 0i64);
}

// File Line: 215
// RVA: 0xC5B8E0
// attributes: thunk
char *__fastcall hkString::strStr(const char *haystack, const char *needle)
{
  return strstr(haystack, needle);
}

// File Line: 220
// RVA: 0xC5B9E0
// attributes: thunk
char *__fastcall hkString::strChr(const char *haystack, int needle)
{
  return strchr(haystack, needle);
}

// File Line: 225
// RVA: 0xC5B9F0
// attributes: thunk
char *__fastcall hkString::strRchr(const char *haystack, int needle)
{
  return strrchr(haystack, needle);
}

// File Line: 231
// RVA: 0xC5BC90
char *__fastcall hkString::strDup(char *src, hkMemoryAllocator *alloc)
{
  int v4; // eax
  char *v5; // rbx

  v4 = hkString::strLen(src);
  v5 = (char *)hkMemoryRouter::easyAlloc(alloc, v4 + 1);
  hkString::strCpy(v5, src);
  return v5;
}

// File Line: 239
// RVA: 0xC5BD50
void __fastcall hkString::strFree(char *s, hkMemoryAllocator *alloc)
{
  hkMemoryRouter::easyFree(alloc, s);
}

// File Line: 243
// RVA: 0xC5BD70
void __fastcall hkString::strFree(char *s)
{
  hkMemoryAllocator **Value; // rax

  Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkString::strFree(s, Value[11]);
}

// File Line: 248
// RVA: 0xC5BCE0
char *__fastcall hkString::strNdup(const char *src, int maxlen, hkMemoryAllocator *alloc)
{
  signed int v6; // esi
  char *v7; // rbx

  v6 = hkString::strLen(src);
  if ( v6 > maxlen )
    v6 = maxlen;
  v7 = (char *)hkMemoryRouter::easyAlloc(alloc, v6 + 1);
  hkString::strNcpy(v7, src, v6);
  v7[v6] = 0;
  return v7;
}

// File Line: 262
// RVA: 0xC5BDA0
char *__fastcall hkString::strDup(char *src)
{
  hkMemoryAllocator **Value; // rax

  Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return hkString::strDup(src, Value[11]);
}

// File Line: 267
// RVA: 0xC5BDD0
char *__fastcall hkString::strNdup(const char *src, int maxlen)
{
  hkMemoryAllocator **Value; // rax

  Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return hkString::strNdup(src, maxlen, Value[11]);
}

// File Line: 274
// RVA: 0xC5BE10
char *__fastcall hkString::strLwr(char *s)
{
  char *v2; // rbx
  char v3; // al

  if ( *s )
  {
    v2 = s;
    do
    {
      v3 = hkString::toLower((unsigned __int8)*v2++);
      *(v2 - 1) = v3;
    }
    while ( *v2 );
  }
  return s;
}

// File Line: 286
// RVA: 0xC5BE50
char *__fastcall hkString::strUpr(char *s)
{
  char *v2; // rbx
  char v3; // al

  if ( *s )
  {
    v2 = s;
    do
    {
      v3 = hkString::toUpper((unsigned __int8)*v2++);
      *(v2 - 1) = v3;
    }
    while ( *v2 );
  }
  return s;
}

// File Line: 321
// RVA: 0xC5BE90
void __fastcall hkString::memCpy(void *dst, const void *src, unsigned int n)
{
  memmove(dst, src, n);
}

// File Line: 326
// RVA: 0xC5BEA0
void __fastcall hkString::memMove(void *dst, const void *src, unsigned int n)
{
  memmove(dst, src, n);
}

// File Line: 331
// RVA: 0xC5BEB0
void __fastcall hkString::memSet(void *dst, int c, unsigned int n)
{
  memset(dst, c, n);
}

// File Line: 337
// RVA: 0xC5BEF0
int __fastcall hkString::memCmp(const void *buf1, const void *buf2, unsigned int n)
{
  return memcmp(buf1, buf2, n);
}

// File Line: 342
// RVA: 0xC5B8F0
hkBool *__fastcall hkString::findAllOccurrences(
        hkBool *result,
        const char *haystack,
        const char *needle,
        hkArray<int,hkContainerHeapAllocator> *indices,
        hkString::ReplaceType rtype)
{
  int v7; // r12d
  __int64 v9; // rbx
  char *v11; // rax
  char *v12; // r15
  int m_capacityAndFlags; // eax

  v7 = (int)haystack;
  v9 = -1i64;
  while ( needle[++v9] != 0 )
    ;
  v11 = hkString::strStr(haystack, needle);
  result->m_bool = 0;
  v12 = v11;
  if ( !v11 )
    return result;
  do
  {
    m_capacityAndFlags = indices->m_capacityAndFlags;
    result->m_bool = 1;
    if ( indices->m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&indices->m_data, 4);
    indices->m_data[indices->m_size++] = (_DWORD)v12 - v7;
    if ( rtype == REPLACE_ONE )
      break;
    v12 = hkString::strStr(&v12[v9], needle);
  }
  while ( v12 );
  return result;
}

// File Line: 358
// RVA: 0xC5BA00
hkBool *__fastcall hkString::beginsWith(hkBool *result, const char *a, const char *b)
{
  char v3; // al
  __int64 v4; // rdx

  v3 = *b;
  if ( *b )
  {
    v4 = a - b;
    while ( b[v4] == v3 )
    {
      v3 = *++b;
      if ( !v3 )
        goto LABEL_5;
    }
    result->m_bool = 0;
    return result;
  }
  else
  {
LABEL_5:
    result->m_bool = 1;
    return result;
  }
}

// File Line: 370
// RVA: 0xC5BA40
hkBool *__fastcall hkString::beginsWithCase(hkBool *result, const char *a, const char *b)
{
  const char *v3; // rbx
  __int64 v5; // rbp
  int v6; // edi

  v3 = b;
  if ( *b )
  {
    v5 = a - b;
    while ( 1 )
    {
      v6 = tolower_0(v3[v5]);
      if ( v6 != tolower_0(*v3) )
        break;
      if ( !*++v3 )
        goto LABEL_5;
    }
    result->m_bool = 0;
  }
  else
  {
LABEL_5:
    result->m_bool = 1;
  }
  return result;
}

// File Line: 382
// RVA: 0xC5BAB0
hkBool *__fastcall hkString::endsWith(hkBool *result, const char *a, const char *b)
{
  int v6; // esi
  int v7; // eax
  int v8; // esi
  const char *v9; // r8
  __int64 v10; // rcx

  v6 = hkString::strLen(a);
  v7 = hkString::strLen(b);
  if ( v6 >= v7 )
  {
    v8 = v6 - v7;
    if ( v7 <= 0 )
    {
LABEL_7:
      result->m_bool = 1;
      return result;
    }
    v9 = &a[v8 - (_QWORD)b];
    v10 = -(__int64)b;
    while ( b[(_QWORD)v9] == *b )
    {
      ++b;
      if ( (__int64)&b[v10] >= v7 )
        goto LABEL_7;
    }
  }
  result->m_bool = 0;
  return result;
}

// File Line: 402
// RVA: 0xC5BB40
hkBool *__fastcall hkString::endsWithCase(hkBool *result, const char *a, const char *b)
{
  int v6; // edi
  int v7; // eax
  int v9; // edi
  __int64 v10; // rbp
  const char *v11; // r15
  __int64 v12; // r14
  int v13; // edi

  v6 = hkString::strLen(a);
  v7 = hkString::strLen(b);
  if ( v6 >= v7 )
  {
    v9 = v6 - v7;
    v10 = v7;
    if ( v7 <= 0 )
    {
LABEL_7:
      result->m_bool = 1;
    }
    else
    {
      v11 = &a[v9 - (_QWORD)b];
      v12 = -(__int64)b;
      while ( 1 )
      {
        v13 = tolower_0(b[(_QWORD)v11]);
        if ( v13 != tolower_0(*b) )
          break;
        ++b;
        if ( (__int64)&b[v12] >= v10 )
          goto LABEL_7;
      }
      result->m_bool = 0;
    }
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 422
// RVA: 0xC5BC00
__int64 __fastcall hkString::lastIndexOf(const char *str, char c)
{
  char *v3; // rax

  v3 = hkString::strRchr(str, c);
  if ( v3 )
    return v3 - str;
  else
    return 0xFFFFFFFFi64;
}

// File Line: 431
// RVA: 0xC5BC30
__int64 __fastcall hkString::indexOf(__int64 str, char c, int startIndex, int endIndex)
{
  __int64 v4; // r10
  __int64 v5; // rax
  const char *v7; // rcx
  __int64 v8; // r8

  v4 = startIndex;
  v5 = 0i64;
  if ( (int)v4 <= 0 )
  {
LABEL_4:
    if ( v4 < endIndex )
    {
      v7 = (const char *)(str + v4);
      v8 = -str;
      while ( *v7 )
      {
        if ( *v7 == c )
          return (unsigned int)v4;
        ++v7;
        LODWORD(v4) = v4 + 1;
        if ( (__int64)&v7[v8] >= endIndex )
          return 0xFFFFFFFFi64;
      }
    }
  }
  else
  {
    while ( *(_BYTE *)(v5 + str) )
    {
      if ( ++v5 >= v4 )
        goto LABEL_4;
    }
  }
  return 0xFFFFFFFFi64;
}

// File Line: 451
// RVA: 0xC5BEC0
void __fastcall hkString::memClear128(char *dst, int numBytes)
{
  int i; // edx
  _OWORD *v3; // rax

  for ( i = (numBytes >> 4) - 1; i >= 0; *v3 = 0i64 )
  {
    v3 = dst;
    dst += 16;
    --i;
  }
}


// File Line: 17
// RVA: 0xC5C200
char *__fastcall strDup(const char *src)
{
  const char *v1; // rdi
  int v2; // ebx
  hkMemoryAllocator **v3; // rax
  char *v4; // rbx

  v1 = src;
  v2 = (unsigned __int64)hkString::strLen(src) + 1;
  v3 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (char *)hkMemoryRouter::easyAlloc(v3[11], v2);
  hkString::strCpy(v4, v1);
  return v4;
}

// File Line: 25
// RVA: 0xC5C250
char *__fastcall strNdup(const char *src, int maxlen)
{
  int v2; // ebx
  const char *v3; // rsi
  int v4; // edi
  hkMemoryAllocator **v5; // rax
  char *v6; // rbx

  v2 = maxlen;
  v3 = src;
  v4 = hkString::strLen(src);
  if ( v4 > v2 )
    v4 = v2;
  v5 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (char *)hkMemoryRouter::easyAlloc(v5[11], v4 + 1);
  hkString::strNcpy(v6, v3, v4);
  v6[v4] = 0;
  return v6;
}

// File Line: 39
// RVA: 0xC5C2C0
void __fastcall assign(const char **ptr, const char *src, int len)
{
  const char *v3; // rbx
  int v4; // ebp
  const char *v5; // rdi
  const char **v6; // rsi
  hkMemoryAllocator **v7; // rax

  v3 = *ptr;
  v4 = len;
  v5 = src;
  v6 = ptr;
  if ( (const char *)((unsigned __int64)*ptr & 0xFFFFFFFFFFFFFFFEui64) != src )
  {
    if ( (unsigned __int8)v3 & 1 )
    {
      v7 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      hkMemoryRouter::easyFree(v7[11], (void *)(v3 - 1));
    }
    if ( v5 )
    {
      if ( v4 == -1 )
        *v6 = strDup(v5) + 1;
      else
        *v6 = strNdup(v5, v4) + 1;
    }
    else
    {
      *v6 = 0i64;
    }
  }
}

// File Line: 65
// RVA: 0xC5BF00
void __fastcall hkStringPtr::hkStringPtr(hkStringPtr *this)
{
  this->m_stringAndFlag = 0i64;
}

// File Line: 70
// RVA: 0xC5BF20
void __fastcall hkStringPtr::hkStringPtr(hkStringPtr *this, const char *string)
{
  this->m_stringAndFlag = 0i64;
  assign(&this->m_stringAndFlag, string, -1);
}

// File Line: 76
// RVA: 0xC5BF50
void __fastcall hkStringPtr::hkStringPtr(hkStringPtr *this, const char *s, int len)
{
  this->m_stringAndFlag = 0i64;
  assign(&this->m_stringAndFlag, s, len);
}

// File Line: 82
// RVA: 0xC5BF80
void __fastcall hkStringPtr::hkStringPtr(hkStringPtr *this, hkStringPtr *strRef)
{
  this->m_stringAndFlag = 0i64;
  assign(&this->m_stringAndFlag, (const char *)((_QWORD)strRef->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64), -1);
}

// File Line: 87
// RVA: 0xC5BFB0
void __fastcall hkStringPtr::hkStringPtr(hkStringPtr *this, hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 91
// RVA: 0xC5BFC0
void __fastcall hkStringPtr::~hkStringPtr(hkStringPtr *this)
{
  assign(&this->m_stringAndFlag, 0i64, -1);
}

// File Line: 96
// RVA: 0xC5BFE0
hkStringPtr *__fastcall hkStringPtr::operator=(hkStringPtr *this, const char *string)
{
  hkStringPtr *v2; // rbx

  v2 = this;
  assign(&this->m_stringAndFlag, string, -1);
  return v2;
}

// File Line: 102
// RVA: 0xC5C010
hkStringPtr *__fastcall hkStringPtr::operator=(hkStringPtr *this, hkStringPtr *string)
{
  hkStringPtr *v2; // rbx

  v2 = this;
  assign(&this->m_stringAndFlag, (const char *)((_QWORD)string->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64), -1);
  return v2;
}

// File Line: 108
// RVA: 0xC5C040
__int64 __fastcall hkStringPtr::getLength(hkStringPtr *this)
{
  JUMPOUT((_QWORD)this->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64, 0i64, hkString::strLen);
  return 0i64;
}

// File Line: 114
// RVA: 0xC5C060
void hkStringPtr::printf(hkStringPtr *this, const char *fmt, ...)
{
  hkStringPtr *v2; // rdi
  int v3; // ebx
  int v4; // eax
  int v5; // er9
  int v6; // er9
  hkResult v7; // [rsp+30h] [rbp-148h]
  hkResult result; // [rsp+34h] [rbp-144h]
  char *buf; // [rsp+40h] [rbp-138h]
  int v10; // [rsp+48h] [rbp-130h]
  int v11; // [rsp+4Ch] [rbp-12Ch]
  char v12; // [rsp+50h] [rbp-128h]
  char *fmta; // [rsp+188h] [rbp+10h]
  va_list va; // [rsp+190h] [rbp+18h]

  va_start(va, fmt);
  fmta = (char *)fmt;
  v2 = this;
  v11 = -2147483393;
  buf = &v12;
  v10 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v3 = v11 & 0x3FFFFFFF;
      v4 = hkString::vsnprintf(buf, v11 & 0x3FFFFFFF, fmta, va);
      if ( v4 >= 0 )
        break;
      v6 = 2 * (v11 & 0x3FFFFFFF);
      if ( (v11 & 0x3FFFFFFF) >= v6 )
      {
        v7.m_enum = 0;
      }
      else
      {
        if ( v6 < 2 * (v11 & 0x3FFFFFFF) )
          v6 = 2 * (v11 & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&v7, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &buf, v6, 1);
      }
    }
    if ( v4 < v3 )
      break;
    v5 = v4 + 1;
    if ( (v11 & 0x3FFFFFFF) >= v4 + 1 )
    {
      result.m_enum = 0;
    }
    else
    {
      if ( v5 < 2 * (v11 & 0x3FFFFFFF) )
        v5 = 2 * (v11 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &buf, v5, 1);
    }
  }
  hkStringPtr::operator=(v2, buf);
  hkStringPtr::operator=(v2, buf);
  v10 = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      buf,
      v11 & 0x3FFFFFFF);
}

// File Line: 146
// RVA: 0xC5C1B0
void __fastcall hkStringPtr::set(hkStringPtr *this, const char *s, int len)
{
  assign(&this->m_stringAndFlag, s, len);
}

// File Line: 152
// RVA: 0xC5C1C0
void __fastcall hkStringPtr::setPointerAligned(hkStringPtr *this, const char *s)
{
  const char *v2; // rdi
  hkStringPtr *v3; // rbx

  v2 = s;
  v3 = this;
  if ( (const char *)((_QWORD)this->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) != s )
  {
    assign(&this->m_stringAndFlag, 0i64, -1);
    v3->m_stringAndFlag = v2;
  }
}


// File Line: 17
// RVA: 0xC5C200
char *__fastcall strDup(char *src)
{
  int v2; // ebx
  hkMemoryAllocator **Value; // rax
  char *v4; // rbx

  v2 = hkString::strLen(src) + 1;
  Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (char *)hkMemoryRouter::easyAlloc(Value[11], v2);
  hkString::strCpy(v4, src);
  return v4;
}

// File Line: 25
// RVA: 0xC5C250
char *__fastcall strNdup(const char *src, int maxlen)
{
  signed int v4; // edi
  hkMemoryAllocator **Value; // rax
  char *v6; // rbx

  v4 = hkString::strLen(src);
  if ( v4 > maxlen )
    v4 = maxlen;
  Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (char *)hkMemoryRouter::easyAlloc(Value[11], v4 + 1);
  hkString::strNcpy(v6, src, v4);
  v6[v4] = 0;
  return v6;
}

// File Line: 39
// RVA: 0xC5C2C0
void __fastcall assign(const char **ptr, char *src, int len)
{
  unsigned __int64 v3; // rbx
  hkMemoryAllocator **Value; // rax

  v3 = (unsigned __int64)*ptr;
  if ( (char *)((unsigned __int64)*ptr & 0xFFFFFFFFFFFFFFFEui64) != src )
  {
    if ( (v3 & 1) != 0 )
    {
      Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      hkMemoryRouter::easyFree(Value[11], (_DWORD *)(v3 - 1));
    }
    if ( src )
    {
      if ( len == -1 )
        *ptr = strDup(src) + 1;
      else
        *ptr = strNdup(src, len) + 1;
    }
    else
    {
      *ptr = 0i64;
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
  assign(&this->m_stringAndFlag, (const char *)((unsigned __int64)strRef->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64), -1);
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
  assign(&this->m_stringAndFlag, string, -1);
  return this;
}

// File Line: 102
// RVA: 0xC5C010
hkStringPtr *__fastcall hkStringPtr::operator=(hkStringPtr *this, hkStringPtr *string)
{
  assign(&this->m_stringAndFlag, (const char *)((unsigned __int64)string->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64), -1);
  return this;
}

// File Line: 108
// RVA: 0xC5C040
__int64 __fastcall hkStringPtr::getLength(hkStringPtr *this)
{
  const char *v1; // rcx

  v1 = (const char *)((unsigned __int64)this->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  if ( v1 )
    return hkString::strLen(v1);
  else
    return 0i64;
}

// File Line: 114
// RVA: 0xC5C060
void hkStringPtr::printf(hkStringPtr *this, const char *fmt, ...)
{
  int v3; // ebx
  int v4; // eax
  int v5; // r9d
  hkResult *p_result; // rcx
  hkResult v7; // [rsp+30h] [rbp-148h] BYREF
  hkResult result; // [rsp+34h] [rbp-144h] BYREF
  char *buf; // [rsp+40h] [rbp-138h] BYREF
  int v10; // [rsp+48h] [rbp-130h]
  int v11; // [rsp+4Ch] [rbp-12Ch]
  char v12; // [rsp+50h] [rbp-128h] BYREF
  va_list va; // [rsp+190h] [rbp+18h] BYREF

  va_start(va, fmt);
  v11 = -2147483393;
  buf = &v12;
  v10 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v3 = v11 & 0x3FFFFFFF;
      v4 = hkString::vsnprintf(buf, v11 & 0x3FFFFFFF, fmt, va);
      if ( v4 >= 0 )
        break;
      v5 = 2 * (v11 & 0x3FFFFFFF);
      if ( (v11 & 0x3FFFFFFF) < v5 )
      {
        p_result = &v7;
        goto LABEL_7;
      }
      v7.m_enum = HK_SUCCESS;
    }
    if ( v4 < v3 )
      break;
    v5 = v4 + 1;
    if ( (v11 & 0x3FFFFFFF) >= v4 + 1 )
    {
      result.m_enum = HK_SUCCESS;
    }
    else
    {
      p_result = &result;
      if ( v5 < 2 * (v11 & 0x3FFFFFFF) )
        v5 = 2 * (v11 & 0x3FFFFFFF);
LABEL_7:
      hkArrayUtil::_reserve(p_result, &hkContainerHeapAllocator::s_alloc, (const void **)&buf, v5, 1);
    }
  }
  hkStringPtr::operator=(this, buf);
  hkStringPtr::operator=(this, buf);
  v10 = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, buf, v11 & 0x3FFFFFFF);
}

// File Line: 146
// RVA: 0xC5C1B0
// attributes: thunk
void __fastcall hkStringPtr::set(hkStringPtr *this, const char *s, int len)
{
  assign(&this->m_stringAndFlag, s, len);
}

// File Line: 152
// RVA: 0xC5C1C0
void __fastcall hkStringPtr::setPointerAligned(hkStringPtr *this, const char *s)
{
  if ( (const char *)((unsigned __int64)this->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) != s )
  {
    assign(&this->m_stringAndFlag, 0i64, -1);
    this->m_stringAndFlag = s;
  }
}


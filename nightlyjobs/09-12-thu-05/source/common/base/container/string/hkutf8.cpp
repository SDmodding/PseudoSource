// File Line: 56
// RVA: 0xC83510
__int64 __fastcall hkUtf8::strLen(char *s)
{
  char v1; // dl
  __int64 result; // rax

  v1 = *s;
  for ( result = 0i64; v1; ++s )
  {
    if ( (v1 & 0xC0) != 0x80 )
      result = (unsigned int)(result + 1);
    v1 = s[1];
  }
  return result;
}

// File Line: 69
// RVA: 0xC83540
__int64 __fastcall hkUtf8::utf8FromWide(char *buf, wchar_t cp)
{
  if ( cp > 0x7Fu )
  {
    if ( cp > 0x7FFu )
    {
      *buf = (cp >> 12) | 0xE0;
      buf[2] = cp & 0x3F | 0x80;
      buf[1] = (cp >> 6) & 0x3F | 0x80;
      return 3i64;
    }
    else
    {
      *buf = (cp >> 6) | 0xC0;
      buf[1] = cp & 0x3F | 0x80;
      return 2i64;
    }
  }
  else
  {
    *buf = cp;
    return 1i64;
  }
}

// File Line: 114
// RVA: 0xC835A0
__int64 __fastcall hkUtf8::utf8FromWide(char *dst, int dstSize, const wchar_t *src, unsigned int srcCount)
{
  int v8; // edi
  __int64 v9; // rbx
  int v10; // eax
  int v11; // ebp
  __int64 v12; // rsi
  __int64 v13; // rdi
  char buf; // [rsp+58h] [rbp+10h] BYREF

  if ( dstSize )
    *dst = 0;
  v8 = 0;
  LODWORD(v9) = 0;
  if ( !*src )
    return 1i64;
  while ( (unsigned int)v9 < srcCount )
  {
    v10 = hkUtf8::utf8FromWide(&buf, src[(unsigned int)v9]);
    v11 = v10 + v8;
    if ( v10 + v8 < dstSize )
    {
      v12 = v8;
      v13 = v10;
      if ( v10 > 0 )
        memmove(&dst[v12], &buf, v10);
      dst[v13 + v12] = 0;
    }
    v9 = (unsigned int)(v9 + 1);
    v8 = v11;
    if ( !src[v9] )
      return (unsigned int)(v11 + 1);
  }
  return (unsigned int)(v8 + 1);
}

// File Line: 142
// RVA: 0xC83670
__int64 __fastcall hkUtf8::wideFromUtf8(wchar_t *dst, int dstCap, const char *src, int srcCount)
{
  __int64 v5; // r14
  int v6; // edi
  __int64 i; // rbx
  hkUtf8::Iterator v9; // [rsp+20h] [rbp-28h] BYREF

  v5 = dstCap;
  v9.m_utf8 = src;
  v6 = 0;
  v9.m_current = -1;
  for ( i = 0i64; hkUtf8::Iterator::advance(&v9, 0i64); ++i )
  {
    if ( i < v5 )
      dst[i] = v9.m_current;
    ++v6;
  }
  if ( v6 >= (int)v5 )
  {
    if ( (_DWORD)v5 )
      dst[v5 - 1] = 0;
  }
  else
  {
    dst[v6] = 0;
  }
  return (unsigned int)(v6 + 1);
}

// File Line: 171
// RVA: 0xC83AA0
char __fastcall hkUtf8::decodeLead_3_(char b, unsigned int *cp)
{
  if ( (b & 0xF0) != 0xE0 )
    return 0;
  *cp = b & 0xF;
  return 1;
}

// File Line: 188
// RVA: 0xC83920
char __fastcall hkUtf8::Iterator::advance(hkUtf8::Iterator *this, int *lenOut)
{
  const char *m_utf8; // rbx
  hkUtf8::Iterator *v4; // r10
  char v5; // cl
  unsigned int v6; // r8d
  int v7; // r9d
  char v8; // cl
  __int64 v9; // r11
  char v10; // cl
  char v11; // cl
  char v12; // cl
  __int64 v13; // rdx
  char v14; // cl
  unsigned int cp; // [rsp+30h] [rbp+8h] BYREF

  m_utf8 = this->m_utf8;
  v4 = this;
  if ( this->m_utf8 && (v5 = *m_utf8) != 0 )
  {
    v6 = 65533;
    v7 = 1;
    cp = 65533;
    if ( v5 < 0 )
    {
      if ( (v5 & 0xC0) == 0xC0 )
      {
        if ( hkUtf8::decodeLead_2_(v5, &cp) )
        {
          v7 = 2;
        }
        else if ( hkUtf8::decodeLead_3_(v8, &cp) )
        {
          v7 = 3;
        }
        else if ( hkUtf8::decodeLead_4_(v10, &cp) )
        {
          v7 = 4;
        }
        else if ( hkUtf8::decodeLead_5_(v11, &cp) )
        {
          v7 = 5;
        }
        else if ( hkUtf8::decodeLead_6_(v12, &cp) )
        {
          v7 = 6;
        }
        v6 = cp;
        v13 = v9;
        if ( v9 < v7 )
        {
          while ( 1 )
          {
            v14 = m_utf8[v13];
            if ( (v14 & 0xC0) != 0x80 )
              break;
            ++v13;
            LODWORD(v9) = v9 + 1;
            v6 = (v6 << 6) | v14 & 0x3F;
            if ( v13 >= v7 )
              goto LABEL_21;
          }
          v6 = 65533;
          v7 = v9;
        }
      }
    }
    else
    {
      v6 = (unsigned __int8)v5;
    }
LABEL_21:
    if ( lenOut )
      *lenOut = v7;
    v4->m_current = v6;
    v4->m_utf8 += v7;
    return 1;
  }
  else
  {
    v4->m_current = -1;
    return 0;
  }
}

// File Line: 253
// RVA: 0xC83720
void __fastcall hkUtf8::Utf8FromWide::Utf8FromWide(hkUtf8::Utf8FromWide *this, wchar_t *s)
{
  __int64 v2; // rbx
  wchar_t v5; // ax
  int v6; // ebp
  __int64 i; // rdi
  int v8; // ebp
  wchar_t v9; // ax
  char *j; // rdi
  __int64 v11; // rcx
  hkResult buf; // [rsp+50h] [rbp+8h] BYREF

  v2 = 0i64;
  this->m_utf8.m_capacityAndFlags = 0x80000000;
  this->m_utf8.m_data = 0i64;
  this->m_utf8.m_size = 0;
  if ( s )
  {
    v5 = *s;
    v6 = 0;
    for ( i = 0i64; v5; v5 = s[i] )
    {
      ++i;
      v6 += hkUtf8::utf8FromWide((char *)&buf, v5);
    }
    v8 = v6 + 1;
    if ( v8 > 0 )
      hkArrayUtil::_reserve(&buf, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_utf8.m_data, v8, 1);
    this->m_utf8.m_size = v8;
    v9 = *s;
    for ( j = this->m_utf8.m_data; v9; j += v11 )
    {
      ++v2;
      v11 = (int)hkUtf8::utf8FromWide(j, v9);
      v9 = s[v2];
    }
    *j = 0;
  }
}

// File Line: 277
// RVA: 0xC83800
void __fastcall hkUtf8::WideFromUtf8::WideFromUtf8(hkUtf8::WideFromUtf8 *this, char *s)
{
  int v4; // r9d
  wchar_t *v5; // rdx
  wchar_t *v6; // rdx
  hkUtf8::Iterator v7; // [rsp+30h] [rbp-18h] BYREF
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  this->m_wide.m_capacityAndFlags = 0x80000000;
  this->m_wide.m_data = 0i64;
  this->m_wide.m_size = 0;
  if ( s )
  {
    v4 = hkUtf8::strLen(s) + 1;
    if ( v4 > 0 )
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_wide.m_data, v4, 2);
    v7.m_utf8 = s;
    for ( v7.m_current = -1; hkUtf8::Iterator::advance(&v7, 0i64); ++this->m_wide.m_size )
    {
      if ( this->m_wide.m_size == (this->m_wide.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&this->m_wide.m_data, 2);
      v5 = &this->m_wide.m_data[this->m_wide.m_size];
      if ( v5 )
        *v5 = v7.m_current;
    }
    if ( this->m_wide.m_size == (this->m_wide.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&this->m_wide.m_data, 2);
    v6 = &this->m_wide.m_data[this->m_wide.m_size];
    if ( v6 )
      *v6 = 0;
  }
}


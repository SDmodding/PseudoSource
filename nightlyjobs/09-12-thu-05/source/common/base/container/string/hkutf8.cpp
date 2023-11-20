// File Line: 56
// RVA: 0xC83510
__int64 __fastcall hkUtf8::strLen(const char *s)
{
  char v1; // dl
  __int64 result; // rax

  v1 = *s;
  for ( result = 0i64; v1; ++s )
  {
    if ( (v1 & 0xC0) != -128 )
      result = (unsigned int)(result + 1);
    v1 = s[1];
  }
  return result;
}

// File Line: 69
// RVA: 0xC83540
signed __int64 __fastcall hkUtf8::utf8FromWide(char *buf, wchar_t cp)
{
  signed __int64 result; // rax

  if ( cp > 0x7Fu )
  {
    if ( cp > 0x7FFu )
    {
      *buf = (cp >> 12) | 0xE0;
      buf[2] = cp & 0x3F | 0x80;
      buf[1] = (cp >> 6) & 0x3F | 0x80;
      result = 3i64;
    }
    else
    {
      *buf = (cp >> 6) | 0xC0;
      buf[1] = cp & 0x3F | 0x80;
      result = 2i64;
    }
  }
  else
  {
    *buf = cp;
    result = 1i64;
  }
  return result;
}

// File Line: 114
// RVA: 0xC835A0
signed __int64 __fastcall hkUtf8::utf8FromWide(char *dst, int dstSize, const wchar_t *src, int srcCount)
{
  unsigned int v4; // er12
  const wchar_t *v5; // r14
  int v6; // er13
  char *v7; // r15
  int v8; // edi
  __int64 v9; // rbx
  int v10; // eax
  int v11; // ebp
  __int64 v12; // rsi
  __int64 v13; // rdi
  char buf; // [rsp+58h] [rbp+10h]

  v4 = srcCount;
  v5 = src;
  v6 = dstSize;
  v7 = dst;
  if ( dstSize )
    *dst = 0;
  v8 = 0;
  LODWORD(v9) = 0;
  if ( !*src )
    return 1i64;
  while ( (unsigned int)v9 < v4 )
  {
    v10 = hkUtf8::utf8FromWide(&buf, v5[(unsigned int)v9]);
    v11 = v10 + v8;
    if ( v10 + v8 < v6 )
    {
      v12 = v8;
      v13 = v10;
      if ( v10 > 0 )
        memmove(&v7[v12], &buf, v10);
      v7[v13 + v12] = 0;
    }
    v9 = (unsigned int)(v9 + 1);
    v8 = v11;
    if ( !v5[v9] )
      return (unsigned int)(v11 + 1);
  }
  return (unsigned int)(v8 + 1);
}

// File Line: 142
// RVA: 0xC83670
__int64 __fastcall hkUtf8::wideFromUtf8(wchar_t *dst, int dstCap, const char *src, int srcCount)
{
  wchar_t *v4; // rsi
  __int64 v5; // r14
  signed int v6; // edi
  __int64 i; // rbx
  hkUtf8::Iterator v9; // [rsp+20h] [rbp-28h]

  v4 = dst;
  v5 = dstCap;
  v9.m_utf8 = src;
  v6 = 0;
  v9.m_current = -1;
  for ( i = 0i64; hkUtf8::Iterator::advance(&v9, 0i64); ++i )
  {
    if ( i < v5 )
      v4[i] = v9.m_current;
    ++v6;
  }
  if ( v6 >= (signed int)v5 )
  {
    if ( (_DWORD)v5 )
      v4[v5 - 1] = 0;
  }
  else
  {
    v4[v6] = 0;
  }
  return (unsigned int)(v6 + 1);
}

// File Line: 171
// RVA: 0xC83AA0
char __fastcall hkUtf8::decodeLead_3_(char b, unsigned int *cp)
{
  if ( (b & 0xF0) != -32 )
    return 0;
  *cp = b & 0xF;
  return 1;
}

// File Line: 188
// RVA: 0xC83920
char __fastcall hkUtf8::Iterator::advance(hkUtf8::Iterator *this, int *lenOut)
{
  const char *v2; // rbx
  int *v3; // rsi
  hkUtf8::Iterator *v4; // r10
  unsigned __int8 v5; // cl
  signed int v6; // er8
  signed int v7; // er9
  char v8; // cl
  signed __int64 v9; // r11
  char v10; // cl
  char v11; // cl
  char v12; // cl
  signed __int64 v13; // rdx
  char v14; // cl
  char result; // al
  unsigned int cp; // [rsp+30h] [rbp+8h]

  v2 = this->m_utf8;
  v3 = lenOut;
  v4 = this;
  if ( this->m_utf8 && (v5 = *v2) != 0 )
  {
    v6 = 65533;
    v7 = 1;
    cp = 65533;
    if ( ~(v5 >> 7) & 1 )
    {
      v6 = v5;
    }
    else if ( (v5 & 0xC0) == -64 )
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
          v14 = v2[v13];
          if ( (v14 & 0xC0) != -128 )
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
LABEL_21:
    if ( v3 )
      *v3 = v7;
    v4->m_current = v6;
    v4->m_utf8 += v7;
    result = 1;
  }
  else
  {
    v4->m_current = -1;
    result = 0;
  }
  return result;
}

// File Line: 253
// RVA: 0xC83720
void __fastcall hkUtf8::Utf8FromWide::Utf8FromWide(hkUtf8::Utf8FromWide *this, const wchar_t *s)
{
  __int64 v2; // rbx
  const wchar_t *v3; // r14
  hkUtf8::Utf8FromWide *v4; // rsi
  wchar_t v5; // ax
  int v6; // ebp
  __int64 i; // rdi
  int v8; // ebp
  int v9; // er9
  wchar_t v10; // ax
  char *j; // rdi
  __int64 v12; // rcx
  char buf; // [rsp+50h] [rbp+8h]

  v2 = 0i64;
  v3 = s;
  v4 = this;
  this->m_utf8.m_capacityAndFlags = 2147483648;
  this->m_utf8.m_data = 0i64;
  this->m_utf8.m_size = 0;
  if ( s )
  {
    v5 = *s;
    v6 = 0;
    for ( i = 0i64; v5; v5 = v3[i] )
    {
      ++i;
      v6 += hkUtf8::utf8FromWide(&buf, v5);
    }
    v8 = v6 + 1;
    if ( v8 > 0 )
    {
      v9 = v8;
      if ( v8 < 0 )
        v9 = 0;
      hkArrayUtil::_reserve((hkResult *)&buf, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, v9, 1);
    }
    v4->m_utf8.m_size = v8;
    v10 = *v3;
    for ( j = v4->m_utf8.m_data; v10; j += v12 )
    {
      ++v2;
      v12 = (signed int)hkUtf8::utf8FromWide(j, v10);
      v10 = v3[v2];
    }
    *j = 0;
  }
}

// File Line: 277
// RVA: 0xC83800
void __fastcall hkUtf8::WideFromUtf8::WideFromUtf8(hkUtf8::WideFromUtf8 *this, const char *s)
{
  const char *v2; // rdi
  hkUtf8::WideFromUtf8 *v3; // rbx
  int v4; // er9
  wchar_t *v5; // rdx
  wchar_t *v6; // rdx
  hkUtf8::Iterator v7; // [rsp+30h] [rbp-18h]
  hkResult result; // [rsp+50h] [rbp+8h]

  v2 = s;
  v3 = this;
  this->m_wide.m_capacityAndFlags = 2147483648;
  this->m_wide.m_data = 0i64;
  this->m_wide.m_size = 0;
  if ( s )
  {
    v4 = (unsigned __int64)hkUtf8::strLen(s) + 1;
    if ( v4 > 0 )
    {
      if ( v4 < 0 )
        v4 = 0;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v3, v4, 2);
    }
    v7.m_utf8 = v2;
    for ( v7.m_current = -1; hkUtf8::Iterator::advance(&v7, 0i64); ++v3->m_wide.m_size )
    {
      if ( v3->m_wide.m_size == (v3->m_wide.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v3, 2);
      v5 = &v3->m_wide.m_data[v3->m_wide.m_size];
      if ( v5 )
        *v5 = v7.m_current;
    }
    if ( v3->m_wide.m_size == (v3->m_wide.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v3, 2);
    v6 = &v3->m_wide.m_data[v3->m_wide.m_size];
    if ( v6 )
      *v6 = 0;
  }
}


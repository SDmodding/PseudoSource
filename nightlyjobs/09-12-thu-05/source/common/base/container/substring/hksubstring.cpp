// File Line: 15
// RVA: 0x1300AA0
hkBool *__fastcall hkSubString::operator==(hkSubString *this, hkBool *result, hkSubString *rhs)
{
  const char *m_start; // r9
  const char *v4; // rax
  int v6; // r10d
  __int64 v7; // r9
  __int64 v8; // r8

  m_start = rhs->m_start;
  v4 = this->m_start;
  if ( this->m_start == rhs->m_start )
  {
    result->m_bool = this->m_end == rhs->m_end;
    return result;
  }
  v6 = LODWORD(this->m_end) - (_DWORD)v4;
  if ( v6 != LODWORD(rhs->m_end) - (_DWORD)m_start )
    goto LABEL_4;
  if ( v6 > 0 )
  {
    v7 = m_start - v4;
    v8 = -(__int64)v4;
    while ( *v4 == v4[v7] )
    {
      ++v4;
      if ( (__int64)&v4[v8] >= v6 )
        goto LABEL_9;
    }
LABEL_4:
    result->m_bool = 0;
    return result;
  }
LABEL_9:
  result->m_bool = 1;
  return result;
}

// File Line: 41
// RVA: 0x1300A50
hkBool *__fastcall hkSubString::operator==(hkSubString *this, hkBool *result, const char *rhs)
{
  const char *m_start; // rax
  const char *m_end; // r9
  bool v5; // zf

  m_start = this->m_start;
  m_end = this->m_end;
  v5 = this->m_start == m_end;
  if ( this->m_start >= m_end )
  {
LABEL_6:
    if ( !v5 || *rhs )
    {
      result->m_bool = 0;
      return result;
    }
    else
    {
      result->m_bool = 1;
      return result;
    }
  }
  else
  {
    while ( 1 )
    {
      if ( !*rhs )
      {
LABEL_5:
        v5 = m_start == m_end;
        goto LABEL_6;
      }
      if ( *m_start != *rhs )
        break;
      ++m_start;
      ++rhs;
      if ( m_start >= m_end )
        goto LABEL_5;
    }
    result->m_bool = 0;
    return result;
  }
}

// File Line: 55
// RVA: 0x1300970
unsigned int __fastcall hkSubString::getInt(hkSubString *this)
{
  signed int v2; // r8d
  char dst[40]; // [rsp+20h] [rbp-28h] BYREF

  v2 = LODWORD(this->m_end) - LODWORD(this->m_start);
  if ( v2 > 20 )
    return 0;
  hkString::strNcpy(dst, this->m_start, v2);
  dst[(unsigned __int64)(this->m_end - this->m_start)] = 0;
  return hkString::atoi(dst, 10);
}

// File Line: 71
// RVA: 0x1300B10
hkOstream *__fastcall operator<<(hkOstream *stream, hkSubString *text)
{
  hkOstream::write(stream, text->m_start, (unsigned int)(LODWORD(text->m_end) - LODWORD(text->m_start)));
  return stream;
}

// File Line: 77
// RVA: 0x1300B40
__int64 __fastcall hkSubString::calcHash(hkSubString *this)
{
  const char *m_start; // rdx
  const char *m_end; // r8
  __int64 result; // rax
  __int64 v4; // rcx

  m_start = this->m_start;
  m_end = this->m_end;
  result = 0i64;
  if ( this->m_start < m_end )
  {
    do
    {
      v4 = *m_start++;
      result = v4 + 31 * result;
    }
    while ( m_start < m_end );
  }
  return result;
}

// File Line: 90
// RVA: 0x1300940
void __fastcall hkSubString::operator=(hkSubString *this, const char *rhs)
{
  this->m_start = rhs;
  this->m_end = &this->m_start[(int)hkString::strLen(rhs)];
}

// File Line: 96
// RVA: 0x13009D0
__int64 __fastcall hkSubString::compareTo(hkSubString *this, hkSubString *rhs)
{
  const char *m_start; // rax
  int v3; // r11d
  int v4; // r10d
  const char *v5; // r8
  int v6; // ecx
  const char *v7; // rdx
  __int64 result; // rax
  unsigned int v9; // edx

  m_start = this->m_start;
  v3 = LODWORD(rhs->m_end) - LODWORD(rhs->m_start);
  v4 = LODWORD(this->m_end) - LODWORD(this->m_start);
  v5 = rhs->m_start;
  v6 = v3;
  if ( v4 < v3 )
    v6 = v4;
  v7 = &m_start[v6];
  if ( m_start >= v7 )
    goto LABEL_6;
  while ( *m_start == *v5 )
  {
    ++m_start;
    ++v5;
    if ( m_start >= v7 )
      goto LABEL_6;
  }
  if ( m_start >= v7 )
  {
LABEL_6:
    if ( v4 == v3 )
    {
      return 0i64;
    }
    else
    {
      result = 1i64;
      if ( v4 < v3 )
        return 0xFFFFFFFFi64;
    }
  }
  else
  {
    v9 = 1;
    if ( *m_start < *v5 )
      return (unsigned int)-1;
    return v9;
  }
  return result;
}


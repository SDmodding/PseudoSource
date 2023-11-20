// File Line: 15
// RVA: 0x1300AA0
hkBool *__fastcall hkSubString::operator==(hkSubString *this, hkBool *result, hkSubString *rhs)
{
  const char *v3; // r9
  const char *v4; // rax
  signed __int64 v6; // r10
  signed __int64 v7; // r9
  signed __int64 v8; // r8

  v3 = rhs->m_start;
  v4 = this->m_start;
  if ( this->m_start == rhs->m_start )
  {
    result->m_bool = this->m_end == rhs->m_end;
    return result;
  }
  LODWORD(v6) = LODWORD(this->m_end) - (_DWORD)v4;
  if ( (_DWORD)v6 != LODWORD(rhs->m_end) - (_DWORD)v3 )
    goto LABEL_4;
  v6 = (signed int)v6;
  if ( (signed int)v6 > 0i64 )
  {
    v7 = v3 - v4;
    v8 = -(signed __int64)v4;
    while ( *v4 == v4[v7] )
    {
      if ( (signed __int64)&(++v4)[v8] >= v6 )
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
  const char *v3; // rax
  const char *v4; // r9
  bool v5; // zf
  hkBool *v6; // rax

  v3 = this->m_start;
  v4 = this->m_end;
  v5 = this->m_start == v4;
  if ( this->m_start >= v4 )
  {
LABEL_6:
    if ( !v5 || *rhs )
    {
      result->m_bool = 0;
      v6 = result;
    }
    else
    {
      result->m_bool = 1;
      v6 = result;
    }
  }
  else
  {
    while ( 1 )
    {
      if ( !*rhs )
      {
LABEL_5:
        v5 = v3 == v4;
        goto LABEL_6;
      }
      if ( *v3 != *rhs )
        break;
      ++v3;
      ++rhs;
      if ( v3 >= v4 )
        goto LABEL_5;
    }
    result->m_bool = 0;
    v6 = result;
  }
  return v6;
}

// File Line: 55
// RVA: 0x1300970
unsigned int __fastcall hkSubString::getInt(hkSubString *this)
{
  hkSubString *v1; // rbx
  int v2; // er8
  char dst[40]; // [rsp+20h] [rbp-28h]

  v1 = this;
  v2 = LODWORD(this->m_end) - LODWORD(this->m_start);
  if ( v2 > 20 )
    return 0;
  hkString::strNcpy(dst, this->m_start, v2);
  dst[(unsigned __int64)(v1->m_end - v1->m_start)] = 0;
  return hkString::atoi(dst, 10);
}

// File Line: 71
// RVA: 0x1300B10
hkOstream *__fastcall operator<<(hkOstream *stream, hkSubString *text)
{
  hkOstream *v2; // rbx

  v2 = stream;
  hkOstream::write(stream, text->m_start, (unsigned int)(LODWORD(text->m_end) - LODWORD(text->m_start)));
  return v2;
}

// File Line: 77
// RVA: 0x1300B40
signed __int64 __fastcall hkSubString::calcHash(hkSubString *this)
{
  const char *v1; // rdx
  const char *v2; // r8
  signed __int64 result; // rax
  __int64 v4; // rcx

  v1 = this->m_start;
  v2 = this->m_end;
  result = 0i64;
  if ( this->m_start < v2 )
  {
    do
    {
      v4 = *v1++;
      result = v4 + 31 * result;
    }
    while ( v1 < v2 );
  }
  return result;
}

// File Line: 90
// RVA: 0x1300940
void __fastcall hkSubString::operator=(hkSubString *this, const char *rhs)
{
  this->m_start = rhs;
  this->m_end = &this->m_start[(signed int)hkString::strLen(rhs)];
}

// File Line: 96
// RVA: 0x13009D0
signed __int64 __fastcall hkSubString::compareTo(hkSubString *this, hkSubString *rhs)
{
  const char *v2; // rax
  int v3; // er11
  int v4; // er10
  const char *v5; // r8
  int v6; // ecx
  const char *v7; // rdx
  signed __int64 result; // rax
  unsigned int v9; // edx

  v2 = this->m_start;
  v3 = LODWORD(rhs->m_end) - LODWORD(rhs->m_start);
  v4 = LODWORD(this->m_end) - LODWORD(this->m_start);
  v5 = rhs->m_start;
  v6 = LODWORD(rhs->m_end) - LODWORD(rhs->m_start);
  if ( v4 < v3 )
    v6 = v4;
  v7 = &v2[v6];
  if ( v2 >= v7 )
    goto LABEL_6;
  while ( *v2 == *v5 )
  {
    ++v2;
    ++v5;
    if ( v2 >= v7 )
      goto LABEL_6;
  }
  if ( v2 >= v7 )
  {
LABEL_6:
    if ( v4 == v3 )
    {
      result = 0i64;
    }
    else
    {
      result = 1i64;
      if ( v4 < v3 )
        result = 0xFFFFFFFFi64;
    }
  }
  else
  {
    v9 = 1;
    if ( *v2 < *v5 )
      v9 = -1;
    result = v9;
  }
  return result;
}


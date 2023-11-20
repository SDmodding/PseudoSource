// File Line: 12
// RVA: 0xE384E0
hkResult *__fastcall hkxEnum::getNameOfValue(hkxEnum *this, hkResult *result, int val, const char **name)
{
  __int64 v4; // rbx
  int v5; // er11
  __int64 v6; // r10
  hkxEnum::Item *v7; // rcx
  hkxEnum::Item *v8; // rax
  hkResult *v9; // rax

  v4 = this->m_items.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( v4 <= 0 )
  {
LABEL_5:
    result->m_enum = 1;
    v9 = result;
  }
  else
  {
    v7 = this->m_items.m_data;
    v8 = v7;
    while ( v8->m_value != val )
    {
      ++v6;
      ++v5;
      ++v8;
      if ( v6 >= v4 )
        goto LABEL_5;
    }
    result->m_enum = 0;
    v9 = result;
    *name = (const char *)((_QWORD)v7[v5].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  }
  return v9;
}

// File Line: 25
// RVA: 0xE38550
hkResult *__fastcall hkxEnum::getValueOfName(hkxEnum *this, hkResult *result, const char *name, int *val)
{
  int v4; // ebx
  int *v5; // r15
  const char *v6; // rbp
  hkResult *v7; // r14
  hkxEnum *v8; // rsi
  __int64 v9; // rdi
  hkxEnum::Item *v11; // rax

  v4 = 0;
  v5 = val;
  v6 = name;
  v7 = result;
  v8 = this;
  if ( this->m_items.m_size <= 0 )
  {
LABEL_5:
    v7->m_enum = 1;
  }
  else
  {
    v9 = 0i64;
    while ( (unsigned int)hkString::strCasecmp(
                            v6,
                            (const char *)((_QWORD)v8->m_items.m_data[v9].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
    {
      ++v4;
      ++v9;
      if ( v4 >= v8->m_items.m_size )
        goto LABEL_5;
    }
    v11 = v8->m_items.m_data;
    v7->m_enum = 0;
    *v5 = v11[v4].m_value;
  }
  return v7;
}


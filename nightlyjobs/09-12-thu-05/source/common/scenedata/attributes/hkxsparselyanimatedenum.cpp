// File Line: 12
// RVA: 0xE384E0
hkResult *__fastcall hkxEnum::getNameOfValue(hkxEnum *this, hkResult *result, int val, const char **name)
{
  __int64 m_size; // rbx
  int v5; // r11d
  __int64 v6; // r10
  hkxEnum::Item *m_data; // rcx
  hkxEnum::Item *v8; // rax
  hkResult *v9; // rax

  m_size = this->m_items.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    result->m_enum = HK_FAILURE;
    return result;
  }
  else
  {
    m_data = this->m_items.m_data;
    v8 = m_data;
    while ( v8->m_value != val )
    {
      ++v6;
      ++v5;
      ++v8;
      if ( v6 >= m_size )
        goto LABEL_5;
    }
    result->m_enum = HK_SUCCESS;
    v9 = result;
    *name = (const char *)((unsigned __int64)m_data[v5].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  }
  return v9;
}

// File Line: 25
// RVA: 0xE38550
hkResult *__fastcall hkxEnum::getValueOfName(hkxEnum *this, hkResult *result, const char *name, int *val)
{
  int v4; // ebx
  __int64 v9; // rdi
  hkxEnum::Item *m_data; // rax

  v4 = 0;
  if ( this->m_items.m_size <= 0 )
  {
LABEL_5:
    result->m_enum = HK_FAILURE;
  }
  else
  {
    v9 = 0i64;
    while ( (unsigned int)hkString::strCasecmp(
                            name,
                            (const char *)((unsigned __int64)this->m_items.m_data[v9].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
    {
      ++v4;
      ++v9;
      if ( v4 >= this->m_items.m_size )
        goto LABEL_5;
    }
    m_data = this->m_items.m_data;
    result->m_enum = HK_SUCCESS;
    *val = m_data[v4].m_value;
  }
  return result;
}


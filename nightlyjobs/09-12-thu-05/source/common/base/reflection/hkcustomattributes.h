// File Line: 24
// RVA: 0xC62C10
hkVariant *__fastcall hkCustomAttributes::getAttribute(hkCustomAttributes *this, const char *id)
{
  int v2; // ebx
  const char *v3; // rbp
  hkCustomAttributes *v4; // rsi
  __int64 v5; // rdi

  v2 = 0;
  v3 = id;
  v4 = this;
  if ( this->m_numAttributes <= 0 )
    return 0i64;
  v5 = 0i64;
  while ( (unsigned int)hkString::strCmp(v4->m_attributes[v5].m_name, v3) )
  {
    ++v2;
    ++v5;
    if ( v2 >= v4->m_numAttributes )
      return 0i64;
  }
  return &v4->m_attributes[v2].m_value;
}


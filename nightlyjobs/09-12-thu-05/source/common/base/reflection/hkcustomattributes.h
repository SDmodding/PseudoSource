// File Line: 24
// RVA: 0xC62C10
hkVariant *__fastcall hkCustomAttributes::getAttribute(hkCustomAttributes *this, const char *id)
{
  int v2; // ebx
  __int64 i; // rdi

  v2 = 0;
  if ( this->m_numAttributes <= 0 )
    return 0i64;
  for ( i = 0i64; (unsigned int)hkString::strCmp(this->m_attributes[i].m_name, id); ++i )
  {
    if ( ++v2 >= this->m_numAttributes )
      return 0i64;
  }
  return &this->m_attributes[v2].m_value;
}


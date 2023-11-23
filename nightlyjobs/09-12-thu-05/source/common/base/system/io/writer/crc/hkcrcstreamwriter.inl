// File Line: 17
// RVA: 0xC447C0
__int64 __fastcall hkCrcStreamWriter<unsigned int,3988292384>::calcPermute(unsigned int p)
{
  unsigned int v1; // ecx
  unsigned int v2; // ecx
  unsigned int v3; // ecx
  unsigned int v4; // ecx
  unsigned int v5; // ecx
  unsigned int v6; // ecx
  unsigned int v7; // ecx

  if ( (p & 1) != 0 )
    v1 = (p >> 1) ^ 0xEDB88320;
  else
    v1 = p >> 1;
  if ( (v1 & 1) != 0 )
    v2 = (v1 >> 1) ^ 0xEDB88320;
  else
    v2 = v1 >> 1;
  if ( (v2 & 1) != 0 )
    v3 = (v2 >> 1) ^ 0xEDB88320;
  else
    v3 = v2 >> 1;
  if ( (v3 & 1) != 0 )
    v4 = (v3 >> 1) ^ 0xEDB88320;
  else
    v4 = v3 >> 1;
  if ( (v4 & 1) != 0 )
    v5 = (v4 >> 1) ^ 0xEDB88320;
  else
    v5 = v4 >> 1;
  if ( (v5 & 1) != 0 )
    v6 = (v5 >> 1) ^ 0xEDB88320;
  else
    v6 = v5 >> 1;
  if ( (v6 & 1) != 0 )
    v7 = (v6 >> 1) ^ 0xEDB88320;
  else
    v7 = v6 >> 1;
  if ( (v7 & 1) != 0 )
    return (v7 >> 1) ^ 0xEDB88320;
  else
    return v7 >> 1;
}

// File Line: 34
// RVA: 0xC62CA0
__int64 __fastcall hkCrcStreamWriter<unsigned int,3988292384>::write(
        hkCrcStreamWriter<unsigned int,3988292384> *this,
        _BYTE *ptr,
        unsigned int nbytes)
{
  unsigned int m_crc; // r9d
  __int64 i; // r10
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  __int64 result; // rax

  m_crc = this->m_crc;
  for ( i = 0i64; i < (int)nbytes; m_crc = v13 ^ (m_crc >> 8) )
  {
    v5 = (unsigned __int8)(m_crc ^ ptr[i]);
    if ( (v5 & 1) != 0 )
      v6 = (v5 >> 1) ^ 0xEDB88320;
    else
      v6 = v5 >> 1;
    if ( (v6 & 1) != 0 )
      v7 = (v6 >> 1) ^ 0xEDB88320;
    else
      v7 = v6 >> 1;
    if ( (v7 & 1) != 0 )
      v8 = (v7 >> 1) ^ 0xEDB88320;
    else
      v8 = v7 >> 1;
    if ( (v8 & 1) != 0 )
      v9 = (v8 >> 1) ^ 0xEDB88320;
    else
      v9 = v8 >> 1;
    if ( (v9 & 1) != 0 )
      v10 = (v9 >> 1) ^ 0xEDB88320;
    else
      v10 = v9 >> 1;
    if ( (v10 & 1) != 0 )
      v11 = (v10 >> 1) ^ 0xEDB88320;
    else
      v11 = v10 >> 1;
    if ( (v11 & 1) != 0 )
      v12 = (v11 >> 1) ^ 0xEDB88320;
    else
      v12 = v11 >> 1;
    if ( (v12 & 1) != 0 )
      v13 = (v12 >> 1) ^ 0xEDB88320;
    else
      v13 = v12 >> 1;
    ++i;
  }
  result = nbytes;
  this->m_crc = m_crc;
  return result;
}

// File Line: 48
// RVA: 0xC62C90
__int64 __fastcall hkCrcStreamWriter<unsigned int,3988292384>::getCrc(hkCrcStreamWriter<unsigned int,3988292384> *this)
{
  return ~this->m_crc;
}


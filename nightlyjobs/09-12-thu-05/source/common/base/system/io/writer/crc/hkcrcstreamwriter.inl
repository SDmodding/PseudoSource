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
  unsigned int v8; // ecx

  if ( p & 1 )
    v1 = (p >> 1) ^ 0xEDB88320;
  else
    v1 = p >> 1;
  if ( v1 & 1 )
    v2 = (v1 >> 1) ^ 0xEDB88320;
  else
    v2 = v1 >> 1;
  if ( v2 & 1 )
    v3 = (v2 >> 1) ^ 0xEDB88320;
  else
    v3 = v2 >> 1;
  if ( v3 & 1 )
    v4 = (v3 >> 1) ^ 0xEDB88320;
  else
    v4 = v3 >> 1;
  if ( v4 & 1 )
    v5 = (v4 >> 1) ^ 0xEDB88320;
  else
    v5 = v4 >> 1;
  if ( v5 & 1 )
    v6 = (v5 >> 1) ^ 0xEDB88320;
  else
    v6 = v5 >> 1;
  if ( v6 & 1 )
    v7 = (v6 >> 1) ^ 0xEDB88320;
  else
    v7 = v6 >> 1;
  if ( v7 & 1 )
    v8 = (v7 >> 1) ^ 0xEDB88320;
  else
    v8 = v7 >> 1;
  return v8;
}

// File Line: 34
// RVA: 0xC62CA0
__int64 __fastcall hkCrcStreamWriter<unsigned int,3988292384>::write(hkCrcStreamWriter<unsigned int,3988292384> *this, const void *ptr, int nbytes)
{
  unsigned int v3; // er9
  signed __int64 v4; // r10
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

  v3 = this->m_crc;
  v4 = 0i64;
  if ( nbytes > 0 )
  {
    do
    {
      v5 = (unsigned __int8)(v3 ^ *((_BYTE *)ptr + v4));
      if ( v5 & 1 )
        v6 = (v5 >> 1) ^ 0xEDB88320;
      else
        v6 = v5 >> 1;
      if ( v6 & 1 )
        v7 = (v6 >> 1) ^ 0xEDB88320;
      else
        v7 = v6 >> 1;
      if ( v7 & 1 )
        v8 = (v7 >> 1) ^ 0xEDB88320;
      else
        v8 = v7 >> 1;
      if ( v8 & 1 )
        v9 = (v8 >> 1) ^ 0xEDB88320;
      else
        v9 = v8 >> 1;
      if ( v9 & 1 )
        v10 = (v9 >> 1) ^ 0xEDB88320;
      else
        v10 = v9 >> 1;
      if ( v10 & 1 )
        v11 = (v10 >> 1) ^ 0xEDB88320;
      else
        v11 = v10 >> 1;
      if ( v11 & 1 )
        v12 = (v11 >> 1) ^ 0xEDB88320;
      else
        v12 = v11 >> 1;
      if ( v12 & 1 )
        v13 = (v12 >> 1) ^ 0xEDB88320;
      else
        v13 = v12 >> 1;
      ++v4;
      v3 = v13 ^ (v3 >> 8);
    }
    while ( v4 < nbytes );
  }
  result = (unsigned int)nbytes;
  this->m_crc = v3;
  return result;
}

// File Line: 48
// RVA: 0xC62C90
__int64 __fastcall hkCrcStreamWriter<unsigned int,3988292384>::getCrc(hkCrcStreamWriter<unsigned int,3988292384> *this)
{
  return ~this->m_crc;
}


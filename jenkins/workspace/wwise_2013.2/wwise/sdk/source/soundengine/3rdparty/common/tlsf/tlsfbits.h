// File Line: 148
// RVA: 0xAA15A0
__int64 __fastcall tlsf_ffs(unsigned int word)
{
  bool v1; // zf
  signed int v2; // eax
  int v3; // ecx
  bool v4; // sf
  __int64 result; // rax

  v1 = (word & -word) == 0;
  v2 = word & -word;
  v3 = 32;
  if ( v1 )
    v3 = 31;
  if ( (v2 & 0xFFFF0000) == 0 )
  {
    v2 <<= 16;
    v3 -= 16;
  }
  if ( (v2 & 0xFF000000) == 0 )
  {
    v2 <<= 8;
    v3 -= 8;
  }
  if ( (v2 & 0xF0000000) == 0 )
  {
    v2 *= 16;
    v3 -= 4;
  }
  if ( (v2 & 0xC0000000) == 0 )
  {
    v2 *= 4;
    v3 -= 2;
  }
  v4 = v2 < 0;
  result = (unsigned int)(v3 - 2);
  if ( v4 )
    return (unsigned int)(v3 - 1);
  return result;
}

// File Line: 162
// RVA: 0xAA1600
__int64 __fastcall tlsf_fls_sizet(unsigned __int64 size)
{
  int v1; // eax
  unsigned __int64 v2; // rdx

  v1 = 32;
  v2 = HIDWORD(size);
  if ( HIDWORD(size) )
  {
    if ( (size & 0xFFFF000000000000ui64) == 0 )
    {
      LODWORD(v2) = HIDWORD(size) << 16;
      v1 = 16;
    }
    if ( (v2 & 0xFF000000) == 0 )
    {
      LODWORD(v2) = (_DWORD)v2 << 8;
      v1 -= 8;
    }
    if ( (v2 & 0xF0000000) == 0 )
    {
      LODWORD(v2) = 16 * v2;
      v1 -= 4;
    }
    if ( (v2 & 0xC0000000) == 0 )
    {
      LODWORD(v2) = 4 * v2;
      v1 -= 2;
    }
    if ( (v2 & 0x80000000) == 0i64 )
      --v1;
    return (unsigned int)(v1 + 31);
  }
  else
  {
    if ( !(_DWORD)size )
      v1 = 31;
    if ( (size & 0xFFFF0000) == 0 )
    {
      LODWORD(size) = (_DWORD)size << 16;
      v1 -= 16;
    }
    if ( (size & 0xFF000000) == 0 )
    {
      LODWORD(size) = (_DWORD)size << 8;
      v1 -= 8;
    }
    if ( (size & 0xF0000000) == 0 )
    {
      LODWORD(size) = 16 * size;
      v1 -= 4;
    }
    if ( (size & 0xC0000000) == 0 )
    {
      LODWORD(size) = 4 * size;
      v1 -= 2;
    }
    if ( (size & 0x80000000) == 0i64 )
      --v1;
    return (unsigned int)(v1 - 1);
  }
}


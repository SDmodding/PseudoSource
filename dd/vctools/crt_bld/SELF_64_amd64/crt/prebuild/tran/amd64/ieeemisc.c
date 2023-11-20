// File Line: 32
// RVA: 0x12C065C
bool __fastcall isnan(long double x)
{
  return (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFui64) > 0x7FF0000000000000i64;
}

// File Line: 49
// RVA: 0x12C05AC
__int64 __fastcall fpclass(long double x)
{
  unsigned __int64 v2; // rax

  if ( *(_QWORD *)&x & 0xFFFFFFFFFFFFFi64 )
  {
    if ( (*(_QWORD *)&x & 0x7FF0000000000000i64) == 9218868437227405312i64 )
      return (unsigned int)((*(_QWORD *)&x & 0x8000000000000i64) != 0) + 1;
    v2 = *(_QWORD *)&x & 0x8000000000000000ui64;
    if ( !(*(_QWORD *)&x & 0x7FF0000000000000i64) )
      return x < 0.0 ? 16 : 128;
    return v2 != 0 ? 8 : 256;
  }
  if ( (*(_QWORD *)&x & 0x7FF0000000000000i64) == 9218868437227405312i64 )
    return x < 0.0 ? 4 : 512;
  v2 = *(_QWORD *)&x & 0x8000000000000000ui64;
  if ( *(_QWORD *)&x & 0x7FF0000000000000i64 )
    return v2 != 0 ? 8 : 256;
  return x < 0.0 ? 32 : 64;
}


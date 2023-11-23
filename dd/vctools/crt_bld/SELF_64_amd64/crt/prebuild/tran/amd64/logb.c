// File Line: 16
// RVA: 0x12C0B6C
long double __fastcall logb(long double x)
{
  __int64 v1; // rcx
  int v2; // edx
  unsigned __int64 i; // rax

  v1 = ((*(_QWORD *)&x >> 52) & 0x7FFi64) - 1023;
  if ( (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64) == 0 )
    return handle_error("_logb", 37, 0xFFF0000000000000ui64, 2, 4, 34, x, 0.0, 1);
  v2 = -1022;
  if ( v1 < -1022 )
  {
    for ( i = *(_QWORD *)&x & 0xFFFFFFFFFFFFFi64; i < 0x10000000000000i64; i *= 2i64 )
      --v2;
    return (double)v2;
  }
  else if ( v1 > 1023 )
  {
    if ( (*(_QWORD *)&x & 0xFFFFFFFFFFFFFi64) != 0 )
      return handle_error("_logb", 37, *(_QWORD *)&x | 0x8000000000000i64, 1, 0, 33, x, 0.0, 1);
  }
  else
  {
    return (double)(int)v1;
  }
  return x;
}


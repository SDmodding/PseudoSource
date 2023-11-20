// File Line: 16
// RVA: 0x12C0B6C
long double __fastcall logb(long double result)
{
  long double v1; // rax
  signed __int64 v2; // rcx
  signed int v3; // edx
  unsigned __int64 v4; // rax

  v1 = result;
  v2 = ((*(_QWORD *)&result >> 52) & 0x7FFi64) - 1023;
  if ( !(*(_QWORD *)&result & 0x7FFFFFFFFFFFFFFFi64) )
    return handle_error("_logb", 37, 0xFFF0000000000000ui64, 2, 4, 34, result, 0.0, 1);
  v3 = -1022;
  if ( v2 >= -1022 )
  {
    if ( v2 <= 1023 )
      return (double)(signed int)v2;
    goto LABEL_8;
  }
  if ( v2 > 1023 )
  {
LABEL_8:
    if ( *(_QWORD *)&v1 & 0xFFFFFFFFFFFFFi64 )
      result = handle_error("_logb", 37, *(_QWORD *)&result | 0x8000000000000i64, 1, 0, 33, result, 0.0, 1);
    return result;
  }
  v4 = *(_QWORD *)&v1 & 0xFFFFFFFFFFFFFi64;
  while ( v4 < 0x10000000000000i64 )
  {
    v4 *= 2i64;
    --v3;
  }
  return (double)v3;
}


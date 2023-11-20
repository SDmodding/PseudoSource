// File Line: 23
// RVA: 0x12BBE54
long double __fastcall sqrt(long double x)
{
  long double v1; // rcx
  bool v3; // zf

  v1 = x;
  if ( (*(_QWORD *)&x & 0x7FF0000000000000i64) == 9218868437227405312i64 )
  {
    if ( *(_QWORD *)&v1 & 0xFFFFFFFFFFFFFi64 )
      return handle_error("sqrt", 5, *(_QWORD *)&x | 0x8000000000000i64, 1, 0, 33, x, 0.0, 1);
    v3 = x >= 0.0;
  }
  else
  {
    if ( !(*(_QWORD *)&x & 0x8000000000000000ui64) )
      return sqrt(x);
    v3 = (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64) == 0;
  }
  if ( v3 )
    return sqrt(x);
  return handle_error("sqrt", 5, 0xFFF8000000000000ui64, 1, 8, 33, x, 0.0, 1);
}


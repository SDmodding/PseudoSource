// File Line: 23
// RVA: 0x12BBE54
long double __fastcall sqrt(long double x)
{
  bool v2; // zf

  if ( (*(_QWORD *)&x & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 )
  {
    if ( (*(_QWORD *)&x & 0x8000000000000000ui64) == 0 )
      return sqrt(x);
    v2 = (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64) == 0;
LABEL_6:
    if ( !v2 )
      return handle_error("sqrt", 5, 0xFFF8000000000000ui64, 1, 8, 33, x, 0.0, 1);
    return sqrt(x);
  }
  if ( (*(_QWORD *)&x & 0xFFFFFFFFFFFFFi64) == 0 )
  {
    v2 = x >= 0.0;
    goto LABEL_6;
  }
  return handle_error("sqrt", 5, *(_QWORD *)&x | 0x8000000000000i64, 1, 0, 33, x, 0.0, 1);
}


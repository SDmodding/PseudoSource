// File Line: 14
// RVA: 0x12BC1A8
double __fastcall floor(double x)
{
  long double v1; // rdx
  unsigned __int64 v2; // rax
  _BOOL8 v3; // r8
  double v4; // rax

  v1 = x;
  v2 = *(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64;
  v3 = *(_QWORD *)&x != (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64);
  if ( (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFui64) < 0x4340000000000000i64 )
  {
    if ( v2 >= 0x3FF0000000000000i64 )
    {
      *(_QWORD *)&v4 = *(_QWORD *)&x & ~((1i64 << (51 - (unsigned __int8)(*(_QWORD *)&x >> 52))) - 1);
      x = v4;
      if ( v3 && *(_QWORD *)&v4 != *(_QWORD *)&v1 )
        return v4 - 1.0;
    }
    else if ( v2 )
    {
      if ( *(_QWORD *)&x == (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64) )
        return 0.0;
      else
        return DOUBLE_N1_0;
    }
  }
  else if ( v2 > 0x7FF0000000000000i64 )
  {
    return handle_error("floor", 11, *(_QWORD *)&x | 0x8000000000000i64, 1, 0, 33, x, 0.0, 1);
  }
  return x;
}


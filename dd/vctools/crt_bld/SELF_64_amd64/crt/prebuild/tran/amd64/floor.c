// File Line: 14
// RVA: 0x12BC1A8
long double __fastcall floor(long double result)
{
  long double v1; // rdx
  unsigned __int64 v2; // rax
  _BOOL8 v3; // r8
  signed __int64 v4; // rax

  v1 = result;
  v2 = *(_QWORD *)&result & 0x7FFFFFFFFFFFFFFFi64;
  v3 = *(_QWORD *)&result != (*(_QWORD *)&result & 0x7FFFFFFFFFFFFFFFi64);
  if ( (*(_QWORD *)&result & 0x7FFFFFFFFFFFFFFFui64) < 0x4340000000000000i64 )
  {
    if ( v2 >= 0x3FF0000000000000i64 )
    {
      v4 = *(_QWORD *)&result & ~((1i64 << (51 - (unsigned __int8)(*(_QWORD *)&result >> 52))) - 1);
      *(_QWORD *)&result &= ~((1i64 << (51 - (unsigned __int8)(*(_QWORD *)&result >> 52))) - 1);
      if ( v3 && v4 != *(_QWORD *)&v1 )
        result = result - 1.0;
    }
    else if ( v2 )
    {
      if ( *(_QWORD *)&result != (*(_QWORD *)&result & 0x7FFFFFFFFFFFFFFFi64) )
        result = DOUBLE_N1_0;
      else
        result = 0.0;
    }
  }
  else if ( v2 > 0x7FF0000000000000i64 )
  {
    result = handle_error("floor", 11, *(_QWORD *)&result | 0x8000000000000i64, 1, 0, 33, result, 0.0, 1);
  }
  return result;
}


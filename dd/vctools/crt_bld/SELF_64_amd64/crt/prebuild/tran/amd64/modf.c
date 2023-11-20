// File Line: 7
// RVA: 0x12B88DC
double __fastcall modf(long double x, long double *iptr)
{
  double v2; // xmm1_8
  unsigned __int64 v3; // rax
  double result; // xmm0_8
  double v5; // xmm0_8

  v2 = x;
  v3 = *(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64;
  if ( (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFui64) < 0x4340000000000000i64 )
  {
    if ( v3 >= 0x3FF0000000000000i64 )
    {
      *(_QWORD *)&v5 = *(_QWORD *)&x & ~((1i64 << (51 - (unsigned __int8)(*(_QWORD *)&x >> 52))) - 1);
      v2 = v2 - v5;
    }
    else
    {
      *(_QWORD *)&v5 = *(_QWORD *)&x & 0x8000000000000000ui64;
    }
    *iptr = v5;
  }
  else
  {
    *iptr = x;
    if ( v3 <= 0x7FF0000000000000i64 )
    {
      *(_QWORD *)&result = *(_QWORD *)&x & 0x8000000000000000ui64;
      return result;
    }
    v2 = x + x;
  }
  return v2;
}


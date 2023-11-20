// File Line: 5
// RVA: 0x12D82C0
__int64 get_fpsr()
{
  return (unsigned int)_mm_getcsr();
}

// File Line: 18
// RVA: 0x12D82D0
void __fastcall set_fpsr(unsigned int a1)
{
  _mm_setcsr(a1);
}

// File Line: 27
// RVA: 0x12D82DA
void fclrf()
{
  _mm_setcsr(_mm_getcsr() & 0xFFFFFFC0);
}

// File Line: 42
// RVA: 0x12D82EE
double __fastcall frnd(double result)
{
  if ( result < 9.007199254740991e15 && result > -9.007199254740991e15 )
    result = (double)(signed int)result;
  return result;
}


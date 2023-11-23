// File Line: 72
// RVA: 0x12C6AAC
long double __fastcall sincos_special(long double x, char *name, int operation)
{
  __int64 v4; // r8
  __int64 v6; // [rsp+60h] [rbp+8h]

  v6 = *(_QWORD *)&x;
  v4 = *(_QWORD *)&x;
  if ( (*(_QWORD *)&x & 0x7FF0000000000000i64) == 0x7FF0000000000000i64 )
  {
    if ( (*(_QWORD *)&x & 0xFFFFFFFFFFFFFi64) != 0 )
    {
      if ( (*(_QWORD *)&x & 0x8000000000000i64) == 0 )
      {
        v4 = *(_QWORD *)&x | 0x8000000000000i64;
        v6 = *(_QWORD *)&x | 0x8000000000000i64;
      }
      handle_error(name, operation, v4, 1, 0, 33, x, 0.0, 1);
    }
    else
    {
      v6 = 0xFFF8000000000000ui64;
      handle_error(name, operation, 0xFFF8000000000000ui64, 1, 8, 33, x, 0.0, 1);
    }
  }
  return *(double *)&v6;
}

// File Line: 103
// RVA: 0x12C6B80
float __fastcall sincosf_special(float x, char *name, int operation)
{
  unsigned __int64 value; // [rsp+78h] [rbp+20h]

  value = LODWORD(x);
  if ( (LODWORD(x) & 0x7F800000) == 2139095040 )
  {
    if ( (LODWORD(x) & 0x7FFFFF) != 0 )
    {
      if ( (~(LODWORD(x) >> 22) & 1) == 0 )
      {
        handle_errorf(name, operation, LODWORD(x), 1, 0, 33, x, 0.0, 1);
        return *(float *)&value;
      }
      LODWORD(value) = LODWORD(x) | 0x400000;
    }
    else
    {
      LODWORD(value) = -4194304;
    }
    handle_errorf(name, operation, value, 1, 8, 33, x, 0.0, 1);
  }
  return *(float *)&value;
}

// File Line: 139
// RVA: 0x12C6C1C
double __fastcall sinf_special(float x)
{
  double result; // xmm0_8

  *(float *)&result = sincosf_special(x, "sinf", 30);
  return result;
}

// File Line: 144
// RVA: 0x12C6A98
long double __fastcall sin_special(long double x)
{
  return sincos_special(x, "sin", 0x1Eu);
}

// File Line: 149
// RVA: 0x12C6A84
double __fastcall cosf_special(float x)
{
  double result; // xmm0_8

  *(float *)&result = sincosf_special(x, "cosf", 0x12u);
  return result;
}

// File Line: 154
// RVA: 0x12C6A70
long double __fastcall cos_special(long double x)
{
  return sincos_special(x, "cos", 0x12u);
}


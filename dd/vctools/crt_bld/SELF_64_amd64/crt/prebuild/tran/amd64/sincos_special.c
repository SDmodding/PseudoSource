// File Line: 72
// RVA: 0x12C6AAC
double __fastcall sincos_special(long double x, char *name, unsigned int operation)
{
  int v3; // ecx
  long double v4; // r8
  double v6; // [rsp+60h] [rbp+8h]

  v6 = x;
  v3 = operation;
  v4 = x;
  if ( (*(_QWORD *)&x & 0x7FF0000000000000i64) == 9218868437227405312i64 )
  {
    if ( *(_QWORD *)&v4 & 0xFFFFFFFFFFFFFi64 )
    {
      if ( ~(*(_QWORD *)&x >> 51) & 1 )
      {
        *(_QWORD *)&v4 = *(_QWORD *)&x | 0x8000000000000i64;
        *(_QWORD *)&v6 = *(_QWORD *)&x | 0x8000000000000i64;
      }
      handle_error(name, v3, *(unsigned __int64 *)&v4, 1, 0, 33, x, 0.0, 1);
    }
    else
    {
      v6 = -2.696539702293474e308/*NaN*/;
      handle_error(name, v3, 0xFFF8000000000000ui64, 1, 8, 33, x, 0.0, 1);
    }
  }
  return v6;
}

// File Line: 103
// RVA: 0x12C6B80
float __fastcall sincosf_special(float x, char *name, unsigned int operation)
{
  unsigned __int64 value; // [rsp+78h] [rbp+20h]

  value = 0i64;
  *(float *)&value = x;
  if ( (LODWORD(x) & 0x7F800000) == 2139095040 )
  {
    if ( LODWORD(x) & 0x7FFFFF )
    {
      if ( !(~(LODWORD(x) >> 22) & 1) )
      {
        handle_errorf(name, operation, 0i64, 1, 0, 33, x, 0.0, 1);
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
void __fastcall sinf_special(float x)
{
  sincosf_special(x, "sinf", 0x1Eu);
}

// File Line: 144
// RVA: 0x12C6A98
void __fastcall sin_special(long double x)
{
  sincos_special(x, "sin", 0x1Eu);
}

// File Line: 149
// RVA: 0x12C6A84
void __fastcall cosf_special(float x)
{
  sincosf_special(x, "cosf", 0x12u);
}

// File Line: 154
// RVA: 0x12C6A70
void __fastcall cos_special(long double x)
{
  sincos_special(x, "cos", 0x12u);
}


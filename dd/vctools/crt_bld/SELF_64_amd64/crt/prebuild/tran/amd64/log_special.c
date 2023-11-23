// File Line: 82
// RVA: 0x12CABAC
float __fastcall logf_special_common(float x, float y, unsigned int code, int op, char *name)
{
  int v6; // r8d
  int v7; // r8d
  unsigned __int64 v8; // r8
  int v9; // r9d
  char *v10; // rcx

  v6 = code - 1;
  if ( !v6 )
  {
    v9 = 2;
    goto LABEL_7;
  }
  v7 = v6 - 1;
  if ( !v7 )
  {
    v9 = 1;
LABEL_7:
    v10 = name;
    v8 = LODWORD(y);
    goto LABEL_8;
  }
  if ( v7 == 1 )
  {
    v8 = LODWORD(y);
    v9 = 1;
    v10 = name;
LABEL_8:
    handle_errorf(v10, op, v8, v9);
  }
  return y;
}

// File Line: 123
// RVA: 0x12CAB8C
float __fastcall logf_special(float x, float y, unsigned int code)
{
  return logf_special_common(x, y, code, 0x1Au, "logf");
}

// File Line: 128
// RVA: 0x12CAA80
float __fastcall log10f_special(float x, float y, unsigned int code)
{
  return logf_special_common(x, y, code, 0x1Bu, "log10f");
}

// File Line: 133
// RVA: 0x12CAAC0
long double __fastcall log_special_common(long double x, long double y, unsigned int code, int op, char *name)
{
  int v6; // r8d
  int v7; // r8d
  int v8; // r9d

  v6 = code - 1;
  if ( !v6 )
  {
    v8 = 2;
    goto LABEL_7;
  }
  v7 = v6 - 1;
  if ( !v7 || v7 == 1 )
  {
    v8 = 1;
LABEL_7:
    handle_error(name, op, *(unsigned __int64 *)&y, v8);
  }
  return y;
}

// File Line: 162
// RVA: 0x12CAAA0
long double __fastcall log_special(long double x, long double y, unsigned int code)
{
  return log_special_common(x, y, code, 0x1Au, "log");
}

// File Line: 167
// RVA: 0x12CAA60
long double __fastcall log10_special(long double x, long double y, unsigned int code)
{
  return log_special_common(x, y, code, 0x1Bu, "log10");
}


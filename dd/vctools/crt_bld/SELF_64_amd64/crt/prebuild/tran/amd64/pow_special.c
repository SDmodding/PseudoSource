// File Line: 83
// RVA: 0x12C6D30
float __fastcall powf_special(float x, float y, float z, unsigned int code)
{
  int v4; // er9
  signed int flags; // [rsp+20h] [rbp-50h]
  int v7; // [rsp+28h] [rbp-48h]
  float arg1; // [rsp+30h] [rbp-40h]
  float arg2; // [rsp+38h] [rbp-38h]

  if ( code == 1 )
  {
    arg2 = y;
    arg1 = x;
    v7 = 0;
    v4 = 0;
    goto LABEL_12;
  }
  if ( code == 2 )
  {
    arg2 = y;
    arg1 = x;
    v7 = 34;
    v4 = 2;
    flags = 4;
    goto LABEL_13;
  }
  if ( code <= 2 )
    return z;
  if ( code <= 6 )
  {
    arg2 = y;
    arg1 = x;
    v7 = 33;
    v4 = 1;
LABEL_12:
    flags = 8;
    goto LABEL_13;
  }
  if ( code == 7 )
  {
    arg2 = y;
    arg1 = x;
    v7 = 34;
    v4 = 4;
    flags = 18;
    goto LABEL_13;
  }
  if ( code == 9 )
  {
    arg2 = y;
    arg1 = x;
    v7 = 34;
    v4 = 3;
    flags = 17;
LABEL_13:
    handle_errorf("powf", 29, LODWORD(z), v4, flags, v7, arg1, arg2, 2);
  }
  return z;
}

// File Line: 129
// RVA: 0x12C6C30
long double __fastcall pow_special(long double x, long double y, long double z, unsigned int code)
{
  int v4; // er9
  signed int flags; // [rsp+20h] [rbp-48h]
  signed int error; // [rsp+28h] [rbp-40h]
  long double arg1; // [rsp+30h] [rbp-38h]
  long double arg2; // [rsp+38h] [rbp-30h]

  if ( code == 2 )
  {
    arg2 = y;
    arg1 = x;
    error = 34;
    v4 = 2;
    flags = 4;
    goto LABEL_10;
  }
  if ( code > 2 )
  {
    if ( code <= 6 )
    {
      arg2 = y;
      arg1 = x;
      error = 33;
      v4 = 1;
      flags = 8;
      goto LABEL_10;
    }
    if ( code <= 8 )
    {
      arg2 = y;
      arg1 = x;
      error = 34;
      v4 = 4;
      flags = 18;
      goto LABEL_10;
    }
    if ( code == 9 )
    {
      arg2 = y;
      arg1 = x;
      error = 34;
      v4 = 3;
      flags = 17;
LABEL_10:
      handle_error("pow", 29, *(unsigned __int64 *)&z, v4, flags, error, arg1, arg2, 2);
      return z;
    }
  }
  return z;
}


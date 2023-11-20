// File Line: 80
// RVA: 0x12C9C68
float __fastcall expf_special(float x, float y, unsigned int code)
{
  unsigned int v3; // er8
  int v4; // er8
  int v5; // er9

  v3 = code - 1;
  if ( !v3 )
  {
    v5 = 1;
    goto LABEL_7;
  }
  v4 = v3 - 1;
  if ( !v4 )
  {
    v5 = 4;
    goto LABEL_7;
  }
  if ( v4 == 1 )
  {
    v5 = 3;
LABEL_7:
    handle_errorf("expf", 20, LODWORD(y), v5);
  }
  return y;
}

// File Line: 110
// RVA: 0x12C9B98
long double __fastcall exp_special(long double x, long double y, unsigned int code)
{
  unsigned int v3; // er8
  int v4; // er8
  int v5; // er9

  v3 = code - 1;
  if ( !v3 )
  {
    v5 = 1;
    goto LABEL_7;
  }
  v4 = v3 - 1;
  if ( !v4 )
  {
    v5 = 4;
    goto LABEL_7;
  }
  if ( v4 == 1 )
  {
    v5 = 3;
LABEL_7:
    handle_error("exp", 20, *(unsigned __int64 *)&y, v5);
  }
  return y;
}


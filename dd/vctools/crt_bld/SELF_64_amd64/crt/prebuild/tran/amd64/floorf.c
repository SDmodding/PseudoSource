// File Line: 18
// RVA: 0x12C1188
float __fastcall floorf(float x)
{
  float v1; // edx
  unsigned int v2; // eax
  BOOL v3; // r8d
  float v4; // eax

  v1 = x;
  v2 = LODWORD(x) & 0x7FFFFFFF;
  v3 = LODWORD(x) != (LODWORD(x) & 0x7FFFFFFF);
  if ( (LODWORD(x) & 0x7FFFFFFFu) < 0x4B800000 )
  {
    if ( v2 >= 0x3F800000 )
    {
      LODWORD(v4) = LODWORD(x) & ~((1 << (-106 - (LODWORD(x) >> 23))) - 1);
      x = v4;
      if ( v3 && LODWORD(v1) != LODWORD(v4) )
        return v4 - 1.0;
    }
    else if ( v2 )
    {
      if ( LODWORD(x) == (LODWORD(x) & 0x7FFFFFFF) )
        return 0.0;
      else
        return FLOAT_N1_0;
    }
  }
  else if ( v2 > 0x7F800000 )
  {
    return handle_errorf("floorf", 11, LODWORD(x) | 0x400000i64, 1, 0, 33, x, 0.0, 1);
  }
  return x;
}


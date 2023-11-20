// File Line: 18
// RVA: 0x12C1188
float __fastcall floorf(float result)
{
  float v1; // edx
  unsigned int v2; // eax
  BOOL v3; // er8
  int v4; // eax

  v1 = result;
  v2 = LODWORD(result) & 0x7FFFFFFF;
  v3 = LODWORD(result) != (LODWORD(result) & 0x7FFFFFFF);
  if ( (LODWORD(result) & 0x7FFFFFFFu) < 0x4B800000 )
  {
    if ( v2 >= 0x3F800000 )
    {
      v4 = LODWORD(result) & ~((1 << (-106 - (LODWORD(result) >> 23))) - 1);
      LODWORD(result) &= ~((1 << (-106 - (LODWORD(result) >> 23))) - 1);
      if ( v3 && LODWORD(v1) != v4 )
        result = result - 1.0;
    }
    else if ( v2 )
    {
      if ( LODWORD(result) != (LODWORD(result) & 0x7FFFFFFF) )
        result = FLOAT_N1_0;
      else
        result = 0.0;
    }
  }
  else if ( v2 > 0x7F800000 )
  {
    result = handle_errorf("floorf", 11, LODWORD(result) | 0x400000i64, 1, 0, 33, result, 0.0, 1);
  }
  return result;
}


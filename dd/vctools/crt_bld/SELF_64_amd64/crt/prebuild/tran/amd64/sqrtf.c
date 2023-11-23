// File Line: 28
// RVA: 0x12BC2A8
float __fastcall sqrtf(float x)
{
  bool v2; // zf

  if ( (LODWORD(x) & 0x7F800000) != 2139095040 )
  {
    if ( (LODWORD(x) & 0x80000000) == 0 )
      return fsqrt(x);
    v2 = (LODWORD(x) & 0x7FFFFFFF) == 0;
LABEL_6:
    if ( !v2 )
      return handle_errorf("sqrtf", 5, 0xFFC00000ui64, 1, 8, 33, x, 0.0, 1);
    return fsqrt(x);
  }
  if ( (LODWORD(x) & 0x7FFFFF) == 0 )
  {
    v2 = x >= 0.0;
    goto LABEL_6;
  }
  return handle_errorf("sqrtf", 5, LODWORD(x) | 0x400000i64, 1, 0, 33, x, 0.0, 1);
}


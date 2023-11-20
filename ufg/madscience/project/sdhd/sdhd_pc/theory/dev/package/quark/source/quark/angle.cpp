// File Line: 14
// RVA: 0x1819D0
__int64 __fastcall UFG::qAngleDiff(unsigned __int16 a, unsigned __int16 b)
{
  unsigned __int16 v2; // cx
  __int64 result; // rax
  int v4; // eax
  unsigned __int16 v5; // dx

  if ( a < b )
  {
    v5 = b - a;
    if ( v5 > 0x7FFFu )
      result = 0xFFFF - (unsigned int)v5;
    else
      result = (unsigned int)-(signed __int16)v5;
  }
  else
  {
    v2 = a - b;
    if ( v2 > 0x7FFFu )
    {
      HIWORD(v4) = -1;
      LOWORD(v4) = -1 - v2;
      result = (unsigned int)-v4;
    }
    else
    {
      result = v2;
    }
  }
  return result;
}


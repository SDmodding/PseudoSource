// File Line: 38
// RVA: 0x12D59D4
unsigned __int64 __fastcall strnlen(const char *str, unsigned __int64 maxsize)
{
  unsigned __int64 result; // rax

  for ( result = 0i64; result < maxsize; ++str )
  {
    if ( !*str )
      break;
    ++result;
  }
  return result;
}


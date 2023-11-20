// File Line: 38
// RVA: 0x12D59D4
unsigned __int64 __fastcall strnlen(const char *str, unsigned __int64 maxsize)
{
  unsigned __int64 result; // rax

  result = 0i64;
  if ( maxsize )
  {
    do
    {
      if ( !*str )
        break;
      ++result;
      ++str;
    }
    while ( result < maxsize );
  }
  return result;
}


// File Line: 49
// RVA: 0x12CEF04
signed __int64 __fastcall wcscmp(const wchar_t *src, const wchar_t *dst)
{
  int v2; // er8
  signed __int64 result; // rax
  signed __int64 v4; // rcx

  v2 = *dst;
  result = (unsigned int)*src - v2;
  if ( *src == v2 )
  {
    v4 = (char *)src - (char *)dst;
    do
    {
      if ( !(_WORD)v2 )
        break;
      ++dst;
      v2 = *dst;
      result = (unsigned int)*(const wchar_t *)((char *)dst + v4) - v2;
    }
    while ( *(const wchar_t *)((char *)dst + v4) == v2 );
  }
  if ( (signed int)result < 0 )
    return 0xFFFFFFFFi64;
  if ( (signed int)result > 0 )
    result = 1i64;
  return result;
}


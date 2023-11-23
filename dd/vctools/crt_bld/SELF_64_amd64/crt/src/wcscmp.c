// File Line: 49
// RVA: 0x12CEF04
__int64 __fastcall wcscmp(const wchar_t *src, const wchar_t *dst)
{
  int v2; // r8d
  __int64 result; // rax
  signed __int64 v4; // rcx

  v2 = *dst;
  result = (unsigned int)*src - v2;
  if ( !(_DWORD)result )
  {
    v4 = (char *)src - (char *)dst;
    do
    {
      if ( !(_WORD)v2 )
        break;
      v2 = *++dst;
      result = (unsigned int)*(const wchar_t *)((char *)dst + v4) - v2;
    }
    while ( !(_DWORD)result );
  }
  if ( (int)result < 0 )
    return 0xFFFFFFFFi64;
  if ( (int)result > 0 )
    return 1i64;
  return result;
}


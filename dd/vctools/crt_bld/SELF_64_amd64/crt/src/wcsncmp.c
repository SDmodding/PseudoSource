// File Line: 47
// RVA: 0x12C09D0
__int64 __fastcall wcsncmp(const wchar_t *first, const wchar_t *last, unsigned __int64 count)
{
  if ( !count )
    return 0i64;
  while ( --count && *first && *first == *last )
  {
    ++first;
    ++last;
  }
  return *first - (unsigned int)*last;
}


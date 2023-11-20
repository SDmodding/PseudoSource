// File Line: 38
// RVA: 0x12DAA78
unsigned __int64 __fastcall wcsnlen(const wchar_t *wcs, unsigned __int64 maxsize)
{
  unsigned __int64 result; // rax

  result = 0i64;
  if ( maxsize )
  {
    do
    {
      if ( !*wcs )
        break;
      ++result;
      ++wcs;
    }
    while ( result < maxsize );
  }
  return result;
}


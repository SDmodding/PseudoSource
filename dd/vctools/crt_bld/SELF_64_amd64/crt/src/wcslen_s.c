// File Line: 38
// RVA: 0x12DAA78
unsigned __int64 __fastcall wcsnlen(const wchar_t *wcs, unsigned __int64 maxsize)
{
  unsigned __int64 result; // rax

  for ( result = 0i64; result < maxsize; ++wcs )
  {
    if ( !*wcs )
      break;
    ++result;
  }
  return result;
}


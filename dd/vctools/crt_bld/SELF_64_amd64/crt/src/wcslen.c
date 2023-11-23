// File Line: 41
// RVA: 0x12CF978
__int64 __fastcall wcslen(const wchar_t *wcs)
{
  const wchar_t *v1; // rax

  v1 = wcs;
  while ( *v1++ )
    ;
  return v1 - wcs - 1;
}


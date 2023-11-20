// File Line: 41
// RVA: 0x12CF978
signed __int64 __fastcall wcslen(const wchar_t *wcs)
{
  const wchar_t *v1; // rax
  wchar_t v2; // dx

  v1 = wcs;
  do
  {
    v2 = *v1;
    ++v1;
  }
  while ( v2 );
  return v1 - wcs - 1;
}


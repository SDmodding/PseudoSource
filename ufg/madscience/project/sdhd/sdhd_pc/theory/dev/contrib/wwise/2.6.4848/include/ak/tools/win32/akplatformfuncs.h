// File Line: 379
// RVA: 0x14B820
void __fastcall AKPLATFORM::SafeStrCpy(wchar_t *in_pDest, const wchar_t *in_pSrc, unsigned __int64 in_uDestMaxNumChars)
{
  unsigned __int64 v4; // rbx
  __int64 v5; // rax
  __int64 v6; // rbx

  v4 = in_uDestMaxNumChars - 1;
  v5 = -1i64;
  do
    ++v5;
  while ( in_pSrc[v5] );
  if ( v4 >= v5 + 1 )
  {
    v6 = -1i64;
    do
      ++v6;
    while ( in_pSrc[v6] );
    v4 = v6 + 1;
  }
  wcsncpy_s(in_pDest, in_uDestMaxNumChars, in_pSrc, v4);
  in_pDest[v4] = 0;
}


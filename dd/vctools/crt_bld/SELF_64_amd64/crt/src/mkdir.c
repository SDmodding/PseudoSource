// File Line: 63
// RVA: 0x12BEA20
signed __int64 __fastcall wmkdir(const wchar_t *path)
{
  unsigned int v1; // eax

  if ( CreateDirectoryW(path, 0i64) )
    v1 = 0;
  else
    v1 = GetLastError();
  if ( !v1 )
    return 0i64;
  dosmaperr(v1);
  return 0xFFFFFFFFi64;
}


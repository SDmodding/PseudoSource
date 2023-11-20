// File Line: 66
// RVA: 0x12C2544
signed __int64 __fastcall wrmdir(const wchar_t *path)
{
  unsigned int v1; // eax

  if ( RemoveDirectoryW(path) )
    v1 = 0;
  else
    v1 = GetLastError();
  if ( !v1 )
    return 0i64;
  dosmaperr(v1);
  return 0xFFFFFFFFi64;
}


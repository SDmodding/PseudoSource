// File Line: 66
// RVA: 0x12C2544
__int64 __fastcall wrmdir(const wchar_t *path)
{
  unsigned int LastError; // eax

  if ( RemoveDirectoryW(path) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0i64;
  dosmaperr(LastError);
  return 0xFFFFFFFFi64;
}


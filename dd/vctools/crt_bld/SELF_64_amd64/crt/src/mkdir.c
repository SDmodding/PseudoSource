// File Line: 63
// RVA: 0x12BEA20
__int64 __fastcall wmkdir(const wchar_t *path)
{
  unsigned int LastError; // eax

  if ( CreateDirectoryW(path, 0i64) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0i64;
  dosmaperr(LastError);
  return 0xFFFFFFFFi64;
}


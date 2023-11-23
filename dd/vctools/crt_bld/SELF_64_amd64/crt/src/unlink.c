// File Line: 44
// RVA: 0x12BC38C
__int64 __fastcall remove(const char *path)
{
  unsigned __int16 *v1; // rbx
  unsigned int v3; // ebx
  unsigned __int16 *outPath; // [rsp+30h] [rbp+8h] BYREF

  v1 = 0i64;
  outPath = 0i64;
  if ( path )
  {
    if ( !(unsigned int)_copy_path_to_wide_string(path, &outPath) )
      return 0xFFFFFFFFi64;
    v1 = outPath;
  }
  v3 = wremove(v1);
  free(outPath);
  return v3;
}

// File Line: 67
// RVA: 0x12BD398
__int64 __fastcall wremove(const wchar_t *path)
{
  unsigned int LastError; // eax

  if ( DeleteFileW(path) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0i64;
  dosmaperr(LastError);
  return 0xFFFFFFFFi64;
}

// File Line: 89
// RVA: 0x12BD3C8
// attributes: thunk
__int64 __fastcall wunlink(const wchar_t *path)
{
  return wremove(path);
}


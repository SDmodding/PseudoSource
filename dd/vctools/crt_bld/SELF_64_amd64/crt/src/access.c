// File Line: 47
// RVA: 0x12BEA54
__int64 __fastcall waccess(const wchar_t *path, int amode)
{
  return (unsigned int)-(waccess_s(path, amode) != 0);
}

// File Line: 79
// RVA: 0x12D5BEC
__int64 __fastcall access_s(const char *path, int amode)
{
  unsigned __int16 *v2; // rbx
  unsigned int v5; // ebx
  unsigned __int16 *outPath; // [rsp+30h] [rbp+8h] BYREF

  v2 = 0i64;
  outPath = 0i64;
  if ( path )
  {
    if ( !(unsigned int)_copy_path_to_wide_string(path, &outPath) )
      return (unsigned int)*errno();
    v2 = outPath;
  }
  v5 = waccess_s(v2, amode);
  free(outPath);
  return v5;
}

// File Line: 103
// RVA: 0x12BEA68
__int64 __fastcall waccess_s(const wchar_t *path, int amode)
{
  char v2; // bl
  unsigned int LastError; // eax
  char FileInformation[40]; // [rsp+20h] [rbp-38h] BYREF

  v2 = amode;
  if ( !path || (amode & 0xFFFFFFF9) != 0 )
  {
    *_doserrno() = 0;
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22i64;
  }
  if ( !GetFileAttributesExW(path, GetFileExInfoStandard, FileInformation) )
  {
    LastError = GetLastError();
    dosmaperr(LastError);
    return (unsigned int)*errno();
  }
  if ( (FileInformation[0] & 0x10) == 0 && (FileInformation[0] & 1) != 0 && (v2 & 2) != 0 )
  {
    *_doserrno() = 5;
    *errno() = 13;
    return (unsigned int)*errno();
  }
  return 0i64;
}


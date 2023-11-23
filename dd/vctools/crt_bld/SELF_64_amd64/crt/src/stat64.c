// File Line: 116
// RVA: 0x12B9CB8
__int64 __fastcall wstat64(const wchar_t *name, _stat64 *buf)
{
  int v4; // r13d
  HANDLE FirstFile; // rsi
  unsigned __int16 *v6; // rsi
  int v7; // r15d
  const wchar_t *v8; // r14
  __int64 v9; // rax
  int v10; // r8d
  unsigned int v11; // ebx
  __int64 st_mtime; // rax
  __int64 v13; // rax
  unsigned __int16 v14; // ax
  __int64 v15; // rcx
  __int64 v16; // rcx
  __int64 result; // rax
  unsigned int v18; // eax
  unsigned int LastError; // eax
  int pfh; // [rsp+40h] [rbp-C0h] BYREF
  _FILETIME LocalFileTime; // [rsp+48h] [rbp-B8h] BYREF
  _SYSTEMTIME SystemTime; // [rsp+50h] [rbp-B0h] BYREF
  int FindFileData; // [rsp+60h] [rbp-A0h] BYREF
  FILETIME v24; // [rsp+64h] [rbp-9Ch] BYREF
  FILETIME v25; // [rsp+6Ch] [rbp-94h] BYREF
  FILETIME FileTime; // [rsp+74h] [rbp-8Ch] BYREF
  __int64 v27; // [rsp+7Ch] [rbp-84h]
  int v28; // [rsp+84h] [rbp-7Ch]
  __int16 v29; // [rsp+8Ch] [rbp-74h]
  unsigned __int16 UserBuf[264]; // [rsp+2B0h] [rbp+1B0h] BYREF

  if ( name && buf )
  {
    if ( wcspbrk(name, L"?*") )
    {
LABEL_5:
      *errno() = 2;
      *_doserrno() = 2;
      return 0xFFFFFFFFi64;
    }
    if ( name[1] == 58 )
    {
      if ( *name && !name[2] )
        goto LABEL_5;
      v4 = towlower(*name) - 96;
    }
    else
    {
      v4 = getdrive();
    }
    FirstFile = FindFirstFileExW(name, FindExInfoStandard, &FindFileData, FindExSearchNameMatch, 0i64, 0);
    if ( FirstFile == (HANDLE)-1i64 )
    {
      v6 = 0i64;
      if ( !wcspbrk(name, L"./\\") )
        goto LABEL_5;
      v7 = *errno();
      *errno() = 0;
      v8 = wfullpath(UserBuf, name, 0x104ui64);
      if ( v8 )
      {
        *errno() = v7;
      }
      else
      {
        if ( *errno() != 34 )
          goto LABEL_5;
        *errno() = v7;
        v6 = wfullpath(0i64, name, 0i64);
        v8 = v6;
      }
      if ( !v8 || wcslen(v8) != 3 && !IsRootUNCName(v8) || GetDriveTypeW(v8) <= 1 )
      {
        if ( v6 )
          free(v6);
        goto LABEL_5;
      }
      if ( v6 )
        free(v6);
      FindFileData = 16;
      v27 = 0i64;
      v29 = 0;
      v9 = _loctotime64_t(1980, 1, 1, 0, 0, 0, -1);
      buf->st_mtime = v9;
      buf->st_atime = v9;
      buf->st_ctime = v9;
LABEL_52:
      v14 = _wdtoxmode(FindFileData, name);
      v15 = (unsigned int)v27;
      *(_DWORD *)&buf->st_nlink = 1;
      buf->st_mode = v14;
      v16 = HIDWORD(v27) + (v15 << 32);
      buf->st_ino = 0;
      buf->st_dev = v4 - 1;
      buf->st_rdev = v4 - 1;
      result = 0i64;
      buf->st_size = v16;
      buf->st_gid = 0;
      return result;
    }
    if ( (FindFileData & 0x400) != 0 && v28 == -1610612724 )
    {
      pfh = -1;
      v10 = 0;
      if ( (FindFileData & 0x10) != 0 )
        v10 = 0x2000;
      if ( wsopen_s(&pfh, name, v10, 64, 0) || pfh == -1 )
        goto LABEL_5;
      v11 = fstat64(pfh, buf);
      close(pfh);
LABEL_54:
      FindClose(FirstFile);
      return v11;
    }
    if ( FileTime.dwLowDateTime || FileTime.dwHighDateTime )
    {
      if ( !FileTimeToLocalFileTime(&FileTime, &LocalFileTime) || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
      {
        LastError = GetLastError();
        dosmaperr(LastError);
        FindClose(FirstFile);
        return 0xFFFFFFFFi64;
      }
      buf->st_mtime = _loctotime64_t(
                        SystemTime.wYear,
                        SystemTime.wMonth,
                        SystemTime.wDay,
                        SystemTime.wHour,
                        SystemTime.wMinute,
                        SystemTime.wSecond,
                        -1);
    }
    else
    {
      buf->st_mtime = 0i64;
    }
    if ( v25.dwLowDateTime || v25.dwHighDateTime )
    {
      if ( !FileTimeToLocalFileTime(&v25, &LocalFileTime) || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
        goto LABEL_53;
      st_mtime = _loctotime64_t(
                   SystemTime.wYear,
                   SystemTime.wMonth,
                   SystemTime.wDay,
                   SystemTime.wHour,
                   SystemTime.wMinute,
                   SystemTime.wSecond,
                   -1);
    }
    else
    {
      st_mtime = buf->st_mtime;
    }
    buf->st_atime = st_mtime;
    if ( !v24.dwLowDateTime && !v24.dwHighDateTime )
    {
      v13 = buf->st_mtime;
LABEL_51:
      buf->st_ctime = v13;
      FindClose(FirstFile);
      goto LABEL_52;
    }
    if ( FileTimeToLocalFileTime(&v24, &LocalFileTime) && FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
    {
      v13 = _loctotime64_t(
              SystemTime.wYear,
              SystemTime.wMonth,
              SystemTime.wDay,
              SystemTime.wHour,
              SystemTime.wMinute,
              SystemTime.wSecond,
              -1);
      goto LABEL_51;
    }
LABEL_53:
    v18 = GetLastError();
    dosmaperr(v18);
    v11 = -1;
    goto LABEL_54;
  }
  *_doserrno() = 0;
  *errno() = 22;
  invalid_parameter_noinfo();
  return 0xFFFFFFFFi64;
}

// File Line: 343
// RVA: 0x12B9BFC
_BOOL8 __fastcall IsRootUNCName(const wchar_t *path)
{
  const wchar_t *v2; // rax
  wchar_t v3; // cx
  __int16 *v4; // rax
  __int16 v5; // cx

  if ( wcslen(path) < 5 || *path != 92 && *path != 47 )
    return 0i64;
  if ( path[1] != 92 && path[1] != 47 )
    return 0i64;
  if ( path[2] == 92 )
    return 0i64;
  if ( path[2] == 47 )
    return 0i64;
  v2 = path + 3;
  v3 = path[3];
  if ( !v3 )
    return 0i64;
  do
  {
    if ( v3 == 92 )
      break;
    if ( v3 == 47 )
      break;
    v3 = *++v2;
  }
  while ( *v2 );
  if ( !*v2 )
    return 0i64;
  v4 = (__int16 *)(v2 + 1);
  if ( !*v4 )
    return 0i64;
  v5 = *v4;
  if ( !*v4 )
    return 1i64;
  do
  {
    if ( v5 == 92 )
      break;
    if ( v5 == 47 )
      break;
    v5 = *++v4;
  }
  while ( *v4 );
  return !*v4 || !v4[1];
}


// File Line: 116
// RVA: 0x12B9CB8
signed __int64 __fastcall wstat64(const wchar_t *name, _stat64 *buf)
{
  _stat64 *v2; // rbx
  const wchar_t *v3; // rdi
  int v4; // er13
  HANDLE v5; // rsi
  unsigned __int16 *v6; // rsi
  int v7; // er15
  const wchar_t *v8; // r14
  __int64 v9; // rax
  int v10; // er8
  unsigned int v11; // ebx
  __int64 v12; // rax
  __int64 v13; // rax
  unsigned __int16 v14; // ax
  __int64 v15; // rcx
  __int64 v16; // rcx
  signed __int64 result; // rax
  unsigned int v18; // eax
  unsigned int v19; // eax
  int pfh; // [rsp+40h] [rbp-C0h]
  _FILETIME LocalFileTime; // [rsp+48h] [rbp-B8h]
  _SYSTEMTIME SystemTime; // [rsp+50h] [rbp-B0h]
  int FindFileData; // [rsp+60h] [rbp-A0h]
  FILETIME v24; // [rsp+64h] [rbp-9Ch]
  FILETIME v25; // [rsp+6Ch] [rbp-94h]
  FILETIME FileTime; // [rsp+74h] [rbp-8Ch]
  __int64 v27; // [rsp+7Ch] [rbp-84h]
  int v28; // [rsp+84h] [rbp-7Ch]
  __int16 v29; // [rsp+8Ch] [rbp-74h]
  unsigned __int16 UserBuf; // [rsp+2B0h] [rbp+1B0h]

  v2 = buf;
  v3 = name;
  if ( name && buf )
  {
    if ( wcspbrk(name, L"?*") )
    {
LABEL_5:
      *errno() = 2;
      *_doserrno() = 2;
      return 0xFFFFFFFFi64;
    }
    if ( v3[1] == 58 )
    {
      if ( *v3 && !v3[2] )
        goto LABEL_5;
      v4 = towlower(*v3) - 96;
    }
    else
    {
      v4 = getdrive();
    }
    v5 = FindFirstFileExW(v3, 0, &FindFileData, 0, 0i64, 0);
    if ( v5 == (HANDLE)-1i64 )
    {
      v6 = 0i64;
      if ( !wcspbrk(v3, L"./\\") )
        goto LABEL_5;
      v7 = *errno();
      *errno() = 0;
      v8 = wfullpath(&UserBuf, v3, 0x104ui64);
      if ( v8 )
      {
        *errno() = v7;
      }
      else
      {
        if ( *errno() != 34 )
          goto LABEL_5;
        *errno() = v7;
        v6 = wfullpath(0i64, v3, 0i64);
        v8 = v6;
      }
      if ( !v8 || wcslen(v8) != 3 && !(unsigned int)IsRootUNCName(v8) || GetDriveTypeW(v8) <= 1 )
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
      v2->st_mtime = v9;
      v2->st_atime = v9;
      v2->st_ctime = v9;
LABEL_52:
      v14 = _wdtoxmode(FindFileData, v3);
      v15 = (unsigned int)v27;
      *(_DWORD *)&v2->st_nlink = 1;
      v2->st_mode = v14;
      v16 = HIDWORD(v27) + (v15 << 32);
      v2->st_ino = 0;
      v2->st_dev = v4 - 1;
      v2->st_rdev = v4 - 1;
      result = 0i64;
      v2->st_size = v16;
      v2->st_gid = 0;
      return result;
    }
    if ( FindFileData & 0x400 && v28 == -1610612724 )
    {
      pfh = -1;
      v10 = 0;
      if ( FindFileData & 0x10 )
        v10 = 0x2000;
      if ( wsopen_s(&pfh, v3, v10, 64, 0) || pfh == -1 )
        goto LABEL_5;
      v11 = fstat64(pfh, v2);
      close(pfh);
LABEL_54:
      FindClose(v5);
      return v11;
    }
    if ( FileTime.dwLowDateTime || FileTime.dwHighDateTime )
    {
      if ( !FileTimeToLocalFileTime(&FileTime, &LocalFileTime) || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
      {
        v19 = GetLastError();
        dosmaperr(v19);
        FindClose(v5);
        return 0xFFFFFFFFi64;
      }
      v2->st_mtime = _loctotime64_t(
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
      v2->st_mtime = 0i64;
    }
    if ( v25.dwLowDateTime || v25.dwHighDateTime )
    {
      if ( !FileTimeToLocalFileTime(&v25, &LocalFileTime) || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
        goto LABEL_53;
      v12 = _loctotime64_t(
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
      v12 = v2->st_mtime;
    }
    v2->st_atime = v12;
    if ( !v24.dwLowDateTime && !v24.dwHighDateTime )
    {
      v13 = v2->st_mtime;
LABEL_51:
      v2->st_ctime = v13;
      FindClose(v5);
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
signed __int64 __fastcall IsRootUNCName(const wchar_t *path)
{
  const wchar_t *v1; // rbx
  wchar_t *v2; // rax
  wchar_t v3; // cx
  __int16 *v4; // rax
  __int16 v5; // cx
  signed __int64 result; // rax

  v1 = path;
  if ( wcslen(path) < 5 || *v1 != 92 && *v1 != 47 )
    goto LABEL_24;
  if ( v1[1] != 92 && v1[1] != 47 )
    goto LABEL_24;
  if ( v1[2] == 92 )
    goto LABEL_24;
  if ( v1[2] == 47 )
    goto LABEL_24;
  v2 = (wchar_t *)(v1 + 3);
  v3 = v1[3];
  if ( !v3 )
    goto LABEL_24;
  do
  {
    if ( v3 == 92 )
      break;
    if ( v3 == 47 )
      break;
    ++v2;
    v3 = *v2;
  }
  while ( *v2 );
  if ( !*v2 )
    goto LABEL_24;
  v4 = (__int16 *)(v2 + 1);
  if ( !*v4 )
    goto LABEL_24;
  v5 = *v4;
  if ( !*v4 )
    goto LABEL_25;
  do
  {
    if ( v5 == 92 )
      break;
    if ( v5 == 47 )
      break;
    ++v4;
    v5 = *v4;
  }
  while ( *v4 );
  if ( *v4 && v4[1] )
LABEL_24:
    result = 0i64;
  else
LABEL_25:
    result = 1i64;
  return result;
}


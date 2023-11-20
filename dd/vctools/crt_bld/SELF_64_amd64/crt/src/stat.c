// File Line: 67
// RVA: 0x12C3490
__int64 __fastcall _wdtoxmode(int attr, const wchar_t *name)
{
  __int16 v2; // ax
  const wchar_t *v3; // rcx
  signed __int16 v4; // bx
  unsigned __int16 v5; // bx
  const wchar_t *v6; // rax
  const wchar_t *v7; // rdi

  v2 = (unsigned __int8)attr;
  v3 = name;
  if ( name[1] == 58 )
    v3 = name + 2;
  if ( (*v3 == 92 || *v3 == 47) && !v3[1] || v2 & 0x10 || (v4 = -32768, !*v3) )
    v4 = 16448;
  v5 = ~(v2 << 7) & 0x80 | 0x100 | v4;
  v6 = wcsrchr(name, 0x2Eu);
  v7 = v6;
  if ( v6 && (!wcsicmp(v6, L".exe") || !wcsicmp(v7, L".cmd") || !wcsicmp(v7, L".bat") || !wcsicmp(v7, L".com")) )
    v5 |= 0x40u;
  return (unsigned __int16)((v5 >> 3) & 0x38 | v5) | (((v5 >> 3) & 0x38u | v5) >> 6) & 7;
}

// File Line: 178
// RVA: 0x12C3584
signed __int64 __fastcall wstat32(const wchar_t *name, _stat32 *buf)
{
  _stat32 *v2; // rdi
  const wchar_t *v3; // rsi
  unsigned int v4; // er15
  int v6; // er13
  unsigned int v7; // ebx
  HANDLE v8; // r14
  unsigned __int16 *v9; // r14
  int v10; // er12
  const wchar_t *v11; // r15
  int v12; // eax
  int v13; // er8
  int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  int pfh; // [rsp+40h] [rbp-C0h]
  _FILETIME LocalFileTime; // [rsp+48h] [rbp-B8h]
  _SYSTEMTIME SystemTime; // [rsp+50h] [rbp-B0h]
  int FindFileData; // [rsp+60h] [rbp-A0h]
  FILETIME v21; // [rsp+64h] [rbp-9Ch]
  FILETIME v22; // [rsp+6Ch] [rbp-94h]
  FILETIME FileTime; // [rsp+74h] [rbp-8Ch]
  __int64 v24; // [rsp+7Ch] [rbp-84h]
  int v25; // [rsp+84h] [rbp-7Ch]
  __int16 v26; // [rsp+8Ch] [rbp-74h]
  unsigned __int16 UserBuf; // [rsp+2B0h] [rbp+1B0h]

  v2 = buf;
  v3 = name;
  v4 = 0;
  if ( !name || !buf )
  {
    *_doserrno() = 0;
    *errno() = 22;
    invalid_parameter_noinfo();
    return -1i64;
  }
  if ( wcspbrk(name, L"?*") )
  {
LABEL_6:
    *errno() = 2;
    *_doserrno() = 2;
    return -1i64;
  }
  if ( v3[1] == 58 )
  {
    if ( *v3 && !v3[2] )
      goto LABEL_6;
    v6 = (unsigned __int16)towlower(*v3) - 96;
  }
  else
  {
    v6 = getdrive();
  }
  v7 = -1;
  v8 = FindFirstFileExW(v3, 0, &FindFileData, 0, 0i64, 0);
  if ( v8 == (HANDLE)-1i64 )
  {
    v9 = 0i64;
    if ( wcspbrk(v3, L"./\\") )
    {
      v10 = *errno();
      *errno() = 0;
      v11 = wfullpath(&UserBuf, v3, 0x104ui64);
      if ( v11 )
      {
        *errno() = v10;
LABEL_18:
        if ( v11 && (wcslen(v11) == 3 || (unsigned int)IsRootUNCName(v11)) && GetDriveTypeW(v11) > 1 )
        {
          if ( v9 )
            free(v9);
          FindFileData = 16;
          v24 = 0i64;
          v26 = 0;
          v12 = _loctotime32_t(1980, 1, 1, 0, 0, 0, -1);
          v4 = 0;
          v2->st_mtime = v12;
          v2->st_atime = v12;
          v2->st_ctime = v12;
          goto LABEL_54;
        }
        if ( v9 )
          free(v9);
        goto LABEL_27;
      }
      if ( *errno() == 34 )
      {
        *errno() = v10;
        v9 = wfullpath(0i64, v3, 0i64);
        v11 = v9;
        goto LABEL_18;
      }
    }
LABEL_27:
    *errno() = 2;
    *_doserrno() = 2;
    return v7;
  }
  if ( FindFileData & 0x400 && v25 == -1610612724 )
  {
    v13 = 0;
    if ( FindFileData & 0x10 )
      v13 = 0x2000;
    pfh = -1;
    if ( wsopen_s(&pfh, v3, v13, 64, 0) || pfh == -1 )
      goto LABEL_27;
    v7 = fstat32(pfh, v2);
    close(pfh);
LABEL_58:
    FindClose(v8);
    return v7;
  }
  if ( FileTime.dwLowDateTime || FileTime.dwHighDateTime )
  {
    if ( !FileTimeToLocalFileTime(&FileTime, &LocalFileTime) || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
      goto LABEL_57;
    v2->st_mtime = _loctotime32_t(
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
    v2->st_mtime = 0;
  }
  if ( v22.dwLowDateTime || v22.dwHighDateTime )
  {
    if ( !FileTimeToLocalFileTime(&v22, &LocalFileTime) || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
      goto LABEL_57;
    v14 = _loctotime32_t(
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
    v14 = v2->st_mtime;
  }
  v2->st_atime = v14;
  if ( v21.dwLowDateTime || v21.dwHighDateTime )
  {
    if ( FileTimeToLocalFileTime(&v21, &LocalFileTime) && FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
    {
      v15 = _loctotime32_t(
              SystemTime.wYear,
              SystemTime.wMonth,
              SystemTime.wDay,
              SystemTime.wHour,
              SystemTime.wMinute,
              SystemTime.wSecond,
              -1);
      goto LABEL_53;
    }
LABEL_57:
    v16 = GetLastError();
    dosmaperr(v16);
    goto LABEL_58;
  }
  v15 = v2->st_mtime;
LABEL_53:
  v2->st_ctime = v15;
  FindClose(v8);
LABEL_54:
  v2->st_mode = _wdtoxmode(FindFileData, v3);
  v2->st_nlink = 1;
  v2->st_size = HIDWORD(v24);
  if ( (_DWORD)v24 )
  {
    v4 = -1;
    *errno() = 132;
    v2->st_size = 0;
  }
  v2->st_ino = 0;
  *(_DWORD *)&v2->st_uid = 0;
  v2->st_dev = v6 - 1;
  v2->st_rdev = v6 - 1;
  return v4;
}


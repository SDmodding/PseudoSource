// File Line: 67
// RVA: 0x12C3490
__int64 __fastcall _wdtoxmode(unsigned __int8 attr, const __m128i *name)
{
  __int16 v2; // ax
  const __m128i *v3; // rcx
  __int16 v4; // bx
  unsigned __int16 v5; // bx
  const __m128i *v6; // rax
  const wchar_t *v7; // rdi

  v2 = attr;
  v3 = name;
  if ( name->m128i_i16[1] == 58 )
    v3 = (const __m128i *)&name->m128i_i8[4];
  if ( (v3->m128i_i16[0] == 92 || v3->m128i_i16[0] == 47) && !v3->m128i_i16[1]
    || (v2 & 0x10) != 0
    || (v4 = 0x8000, !v3->m128i_i16[0]) )
  {
    v4 = 16448;
  }
  v5 = ~(v2 << 7) & 0x80 | 0x100 | v4;
  v6 = wcsrchr(name, 0x2Eu);
  v7 = (const wchar_t *)v6;
  if ( v6
    && (!wcsicmp((const wchar_t *)v6, L".exe") || !wcsicmp(v7, L".cmd")
                                               || !wcsicmp(v7, L".bat")
                                               || !wcsicmp(v7, L".com")) )
  {
    v5 |= 0x40u;
  }
  return (v5 >> 3) & 0x38 | v5 | ((unsigned __int16)((v5 >> 3) & 0x38 | v5) >> 6) & 7u;
}

// File Line: 178
// RVA: 0x12C3584
__int64 __fastcall wstat32(const __m128i *name, _stat32 *buf)
{
  unsigned int v4; // r15d
  int v6; // r13d
  unsigned int v7; // ebx
  HANDLE FirstFile; // r14
  unsigned __int16 *v9; // r14
  int v10; // r12d
  const wchar_t *v11; // r15
  int v12; // eax
  int v13; // r8d
  int st_mtime; // eax
  int v15; // eax
  unsigned int LastError; // eax
  int pfh; // [rsp+40h] [rbp-C0h] BYREF
  _FILETIME LocalFileTime; // [rsp+48h] [rbp-B8h] BYREF
  _SYSTEMTIME SystemTime; // [rsp+50h] [rbp-B0h] BYREF
  int FindFileData; // [rsp+60h] [rbp-A0h] BYREF
  FILETIME v21; // [rsp+64h] [rbp-9Ch] BYREF
  FILETIME v22; // [rsp+6Ch] [rbp-94h] BYREF
  FILETIME FileTime; // [rsp+74h] [rbp-8Ch] BYREF
  __int64 v24; // [rsp+7Ch] [rbp-84h]
  int v25; // [rsp+84h] [rbp-7Ch]
  __int16 v26; // [rsp+8Ch] [rbp-74h]
  unsigned __int16 UserBuf[264]; // [rsp+2B0h] [rbp+1B0h] BYREF

  v4 = 0;
  if ( !name || !buf )
  {
    *_doserrno() = 0;
    *errno() = 22;
    invalid_parameter_noinfo();
    return -1i64;
  }
  if ( wcspbrk((const wchar_t *)name, L"?*") )
  {
LABEL_6:
    *errno() = 2;
    *_doserrno() = 2;
    return -1i64;
  }
  if ( name->m128i_i16[1] == 58 )
  {
    if ( name->m128i_i16[0] && !name->m128i_i16[2] )
      goto LABEL_6;
    v6 = (unsigned __int16)towlower(name->m128i_i16[0]) - 96;
  }
  else
  {
    v6 = getdrive();
  }
  v7 = -1;
  FirstFile = FindFirstFileExW((LPCWSTR)name, FindExInfoStandard, &FindFileData, FindExSearchNameMatch, 0i64, 0);
  if ( FirstFile == (HANDLE)-1i64 )
  {
    v9 = 0i64;
    if ( wcspbrk((const wchar_t *)name, L"./\\") )
    {
      v10 = *errno();
      *errno() = 0;
      v11 = wfullpath(UserBuf, (const wchar_t *)name, 0x104ui64);
      if ( v11 )
      {
        *errno() = v10;
LABEL_18:
        if ( v11 && (wcslen(v11) == 3 || IsRootUNCName(v11)) && GetDriveTypeW(v11) > 1 )
        {
          if ( v9 )
            free(v9);
          FindFileData = 16;
          v24 = 0i64;
          v26 = 0;
          v12 = _loctotime32_t(1980, 1, 1, 0, 0, 0, -1);
          v4 = 0;
          buf->st_mtime = v12;
          buf->st_atime = v12;
          buf->st_ctime = v12;
          goto LABEL_54;
        }
        if ( v9 )
          free(v9);
        goto LABEL_27;
      }
      if ( *errno() == 34 )
      {
        *errno() = v10;
        v9 = wfullpath(0i64, (const wchar_t *)name, 0i64);
        v11 = v9;
        goto LABEL_18;
      }
    }
LABEL_27:
    *errno() = 2;
    *_doserrno() = 2;
    return v7;
  }
  if ( (FindFileData & 0x400) != 0 && v25 == -1610612724 )
  {
    v13 = 0;
    if ( (FindFileData & 0x10) != 0 )
      v13 = 0x2000;
    pfh = -1;
    if ( wsopen_s(&pfh, (const wchar_t *)name, v13, 64, 0) || pfh == -1 )
      goto LABEL_27;
    v7 = fstat32(pfh, buf);
    close(pfh);
LABEL_58:
    FindClose(FirstFile);
    return v7;
  }
  if ( FileTime.dwLowDateTime || FileTime.dwHighDateTime )
  {
    if ( !FileTimeToLocalFileTime(&FileTime, &LocalFileTime) || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
      goto LABEL_57;
    buf->st_mtime = _loctotime32_t(
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
    buf->st_mtime = 0;
  }
  if ( v22.dwLowDateTime || v22.dwHighDateTime )
  {
    if ( !FileTimeToLocalFileTime(&v22, &LocalFileTime) || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
      goto LABEL_57;
    st_mtime = _loctotime32_t(
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
    LastError = GetLastError();
    dosmaperr(LastError);
    goto LABEL_58;
  }
  v15 = buf->st_mtime;
LABEL_53:
  buf->st_ctime = v15;
  FindClose(FirstFile);
LABEL_54:
  buf->st_mode = _wdtoxmode(FindFileData, name);
  buf->st_nlink = 1;
  buf->st_size = HIDWORD(v24);
  if ( (_DWORD)v24 )
  {
    v4 = -1;
    *errno() = 132;
    buf->st_size = 0;
  }
  buf->st_ino = 0;
  *(_DWORD *)&buf->st_uid = 0;
  buf->st_dev = v6 - 1;
  buf->st_rdev = v6 - 1;
  return v4;
}


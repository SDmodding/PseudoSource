// File Line: 82
// RVA: 0x12C2A24
signed __int64 __fastcall fstat64(int fildes, _stat64 *buf)
{
  _stat64 *v2; // rdi
  __int64 v3; // rsi
  unsigned int v4; // ebx
  __int64 v5; // r15
  __int64 v6; // r14
  ioinfo *v7; // rcx
  DWORD v8; // eax
  unsigned int v9; // eax
  signed __int16 v10; // cx
  unsigned __int16 v11; // ax
  unsigned __int16 v12; // ax
  __int64 v13; // rax
  __int64 v14; // rax
  _FILETIME LocalFileTime; // [rsp+40h] [rbp-88h]
  unsigned int TotalBytesAvail; // [rsp+48h] [rbp-80h]
  int v18; // [rsp+4Ch] [rbp-7Ch]
  _SYSTEMTIME SystemTime; // [rsp+50h] [rbp-78h]
  _BY_HANDLE_FILE_INFORMATION FileInformation; // [rsp+60h] [rbp-68h]

  v2 = buf;
  v3 = fildes;
  v18 = fildes;
  v4 = 0;
  if ( !buf )
  {
    *_doserrno() = 0;
    *errno() = 22;
LABEL_47:
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  memset(buf, 0, 0x38ui64);
  if ( (_DWORD)v3 != -2 )
  {
    if ( (signed int)ioinit() < 0 )
      return 0xFFFFFFFFi64;
    if ( (signed int)v3 < 0
      || (unsigned int)v3 >= nhandle
      || (v5 = v3 >> 5, v6 = v3 & 0x1F, !(_pioinfo[v3 >> 5][v6].osfile & 1)) )
    {
      *_doserrno() = 0;
      *errno() = 9;
      goto LABEL_47;
    }
    _lock_fhandle(v3);
    v7 = _pioinfo[v5];
    if ( !(v7[v6].osfile & 1) )
    {
LABEL_10:
      *errno() = 9;
LABEL_44:
      v4 = -1;
      goto $done_6;
    }
    v8 = GetFileType((HANDLE)v7[v6].osfhnd) & 0xFFFF7FFF;
    if ( v8 == 1 )
    {
      *(_DWORD *)&v2->st_ino = 0;
      *(_DWORD *)&v2->st_uid = 0;
      v2->st_nlink = 1;
      if ( GetFileInformationByHandle((HANDLE)_pioinfo[v5][v6].osfhnd, &FileInformation) )
      {
        v11 = v2->st_mode;
        if ( FileInformation.dwFileAttributes & 1 )
          v12 = v11 | 0x124;
        else
          v12 = v11 | 0x1B6;
        v2->st_mode = v12;
        if ( FileInformation.ftLastWriteTime.dwLowDateTime || FileInformation.ftLastWriteTime.dwHighDateTime )
        {
          if ( !FileTimeToLocalFileTime(&FileInformation.ftLastWriteTime, &LocalFileTime)
            || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
          {
            goto LABEL_44;
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
        if ( FileInformation.ftLastAccessTime.dwLowDateTime || FileInformation.ftLastAccessTime.dwHighDateTime )
        {
          if ( !FileTimeToLocalFileTime(&FileInformation.ftLastAccessTime, &LocalFileTime)
            || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
          {
            goto LABEL_44;
          }
          v13 = _loctotime64_t(
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
          v13 = v2->st_mtime;
        }
        v2->st_atime = v13;
        if ( FileInformation.ftCreationTime.dwLowDateTime || FileInformation.ftCreationTime.dwHighDateTime )
        {
          if ( !FileTimeToLocalFileTime(&FileInformation.ftCreationTime, &LocalFileTime)
            || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
          {
            goto LABEL_44;
          }
          v14 = _loctotime64_t(
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
        v2->st_ctime = v14;
        v2->st_size = FileInformation.nFileSizeLow + ((unsigned __int64)FileInformation.nFileSizeHigh << 32);
        v2->st_mode |= 0x8000u;
        v2->st_dev = 0;
        v2->st_rdev = 0;
$done_6:
        unlock_fhandle(v3);
        return v4;
      }
    }
    else
    {
      if ( v8 - 2 <= 1 )
      {
        v10 = 0x2000;
        if ( v8 != 2 )
          v10 = 4096;
        v2->st_mode = v10;
        v2->st_dev = v3;
        v2->st_rdev = v3;
        *(_DWORD *)&v2->st_nlink = 1;
        v2->st_ino = 0;
        v2->st_gid = 0;
        v2->st_ctime = 0i64;
        v2->st_mtime = 0i64;
        v2->st_atime = 0i64;
        if ( v8 != 2 && PeekNamedPipe((HANDLE)_pioinfo[v5][v6].osfhnd, 0i64, 0, 0i64, &TotalBytesAvail, 0i64) )
          v2->st_size = (signed int)TotalBytesAvail;
        else
          v2->st_size = 0i64;
        goto $done_6;
      }
      if ( !v8 )
        goto LABEL_10;
    }
    v9 = GetLastError();
    dosmaperr(v9);
    goto LABEL_44;
  }
  *_doserrno() = 0;
  *errno() = 9;
  return 0xFFFFFFFFi64;
}


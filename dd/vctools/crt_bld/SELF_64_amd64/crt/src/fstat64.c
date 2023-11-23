// File Line: 82
// RVA: 0x12C2A24
__int64 __fastcall fstat64(unsigned int fildes, _stat64 *buf)
{
  __int64 v3; // rsi
  unsigned int v4; // ebx
  __int64 v5; // r15
  __int64 v6; // r14
  ioinfo *v7; // rcx
  DWORD v8; // eax
  unsigned int LastError; // eax
  unsigned __int16 v10; // cx
  unsigned __int16 st_mode; // ax
  unsigned __int16 v12; // ax
  __int64 st_mtime; // rax
  __int64 v14; // rax
  _FILETIME LocalFileTime; // [rsp+40h] [rbp-88h] BYREF
  unsigned int TotalBytesAvail[2]; // [rsp+48h] [rbp-80h] BYREF
  _SYSTEMTIME SystemTime; // [rsp+50h] [rbp-78h] BYREF
  _BY_HANDLE_FILE_INFORMATION FileInformation; // [rsp+60h] [rbp-68h] BYREF

  v3 = (int)fildes;
  TotalBytesAvail[1] = fildes;
  v4 = 0;
  if ( !buf )
  {
    *_doserrno() = 0;
    *errno() = 22;
LABEL_47:
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  memset(buf, 0, sizeof(_stat64));
  if ( (_DWORD)v3 != -2 )
  {
    if ( (int)ioinit() < 0 )
      return 0xFFFFFFFFi64;
    if ( (int)v3 < 0
      || (unsigned int)v3 >= nhandle
      || (v5 = v3 >> 5, v6 = v3 & 0x1F, (_pioinfo[v3 >> 5][v6].osfile & 1) == 0) )
    {
      *_doserrno() = 0;
      *errno() = 9;
      goto LABEL_47;
    }
    _lock_fhandle(v3);
    v7 = _pioinfo[v5];
    if ( (v7[v6].osfile & 1) == 0 )
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
      *(_DWORD *)&buf->st_ino = 0;
      *(_DWORD *)&buf->st_uid = 0;
      buf->st_nlink = 1;
      if ( GetFileInformationByHandle((HANDLE)_pioinfo[v5][v6].osfhnd, &FileInformation) )
      {
        st_mode = buf->st_mode;
        if ( (FileInformation.dwFileAttributes & 1) != 0 )
          v12 = st_mode | 0x124;
        else
          v12 = st_mode | 0x1B6;
        buf->st_mode = v12;
        if ( FileInformation.ftLastWriteTime.dwLowDateTime || FileInformation.ftLastWriteTime.dwHighDateTime )
        {
          if ( !FileTimeToLocalFileTime(&FileInformation.ftLastWriteTime, &LocalFileTime)
            || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
          {
            goto LABEL_44;
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
        if ( FileInformation.ftLastAccessTime.dwLowDateTime || FileInformation.ftLastAccessTime.dwHighDateTime )
        {
          if ( !FileTimeToLocalFileTime(&FileInformation.ftLastAccessTime, &LocalFileTime)
            || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
          {
            goto LABEL_44;
          }
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
          v14 = buf->st_mtime;
        }
        buf->st_ctime = v14;
        buf->st_size = FileInformation.nFileSizeLow + ((unsigned __int64)FileInformation.nFileSizeHigh << 32);
        buf->st_mode |= 0x8000u;
        buf->st_dev = 0;
        buf->st_rdev = 0;
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
        buf->st_mode = v10;
        buf->st_dev = v3;
        buf->st_rdev = v3;
        *(_DWORD *)&buf->st_nlink = 1;
        buf->st_ino = 0;
        buf->st_gid = 0;
        buf->st_ctime = 0i64;
        buf->st_mtime = 0i64;
        buf->st_atime = 0i64;
        if ( v8 == 2 || !PeekNamedPipe((HANDLE)_pioinfo[v5][v6].osfhnd, 0i64, 0, 0i64, TotalBytesAvail, 0i64) )
          buf->st_size = 0i64;
        else
          buf->st_size = (int)TotalBytesAvail[0];
        goto $done_6;
      }
      if ( !v8 )
        goto LABEL_10;
    }
    LastError = GetLastError();
    dosmaperr(LastError);
    goto LABEL_44;
  }
  *_doserrno() = 0;
  *errno() = 9;
  return 0xFFFFFFFFi64;
}


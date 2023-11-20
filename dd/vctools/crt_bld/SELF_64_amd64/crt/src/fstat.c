// File Line: 71
// RVA: 0x12D73EC
signed __int64 __fastcall fstat32(int fildes, _stat32 *buf)
{
  _stat32 *v2; // rdi
  __int64 v3; // rsi
  unsigned int v4; // ebx
  __int64 v5; // r15
  __int64 v6; // r14
  ioinfo *v7; // rcx
  DWORD v8; // eax
  unsigned int v9; // eax
  signed __int16 v10; // cx
  BOOL v11; // eax
  unsigned __int16 v12; // ax
  unsigned __int16 v13; // ax
  int v14; // eax
  int v15; // eax
  _FILETIME LocalFileTime; // [rsp+40h] [rbp-88h]
  unsigned int TotalBytesAvail; // [rsp+48h] [rbp-80h]
  int v19; // [rsp+4Ch] [rbp-7Ch]
  _SYSTEMTIME SystemTime; // [rsp+50h] [rbp-78h]
  _BY_HANDLE_FILE_INFORMATION FileInformation; // [rsp+60h] [rbp-68h]

  v2 = buf;
  v3 = fildes;
  v19 = fildes;
  v4 = 0;
  if ( !buf )
  {
    *_doserrno() = 0;
    *errno() = 22;
LABEL_46:
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  memset(buf, 0, 0x24ui64);
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
      goto LABEL_46;
    }
    _lock_fhandle(v3);
    v7 = _pioinfo[v5];
    if ( !(v7[v6].osfile & 1) )
    {
LABEL_10:
      *errno() = 9;
LABEL_43:
      v4 = -1;
      goto $done_8;
    }
    v8 = GetFileType((HANDLE)v7[v6].osfhnd) & 0xFFFF7FFF;
    if ( v8 == 1 )
    {
      *(_DWORD *)&v2->st_ino = 0;
      *(_DWORD *)&v2->st_uid = 0;
      v2->st_nlink = 1;
      if ( GetFileInformationByHandle((HANDLE)_pioinfo[v5][v6].osfhnd, &FileInformation) )
      {
        v12 = v2->st_mode;
        if ( FileInformation.dwFileAttributes & 1 )
          v13 = v12 | 0x124;
        else
          v13 = v12 | 0x1B6;
        v2->st_mode = v13;
        if ( FileInformation.ftLastWriteTime.dwLowDateTime || FileInformation.ftLastWriteTime.dwHighDateTime )
        {
          if ( !FileTimeToLocalFileTime(&FileInformation.ftLastWriteTime, &LocalFileTime)
            || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
          {
            goto LABEL_43;
          }
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
        if ( FileInformation.ftLastAccessTime.dwLowDateTime || FileInformation.ftLastAccessTime.dwHighDateTime )
        {
          if ( !FileTimeToLocalFileTime(&FileInformation.ftLastAccessTime, &LocalFileTime)
            || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
          {
            goto LABEL_43;
          }
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
        if ( FileInformation.ftCreationTime.dwLowDateTime || FileInformation.ftCreationTime.dwHighDateTime )
        {
          if ( !FileTimeToLocalFileTime(&FileInformation.ftCreationTime, &LocalFileTime)
            || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
          {
            goto LABEL_43;
          }
          v15 = _loctotime32_t(
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
          v15 = v2->st_mtime;
        }
        v2->st_ctime = v15;
        v2->st_size = FileInformation.nFileSizeLow;
        v2->st_mode |= 0x8000u;
        v2->st_dev = 0;
        v2->st_rdev = 0;
$done_8:
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
        *(_QWORD *)&v2->st_mtime = 0i64;
        v2->st_atime = 0;
        if ( v8 == 2 )
        {
          v2->st_size = 0;
        }
        else
        {
          v11 = PeekNamedPipe((HANDLE)_pioinfo[v5][v6].osfhnd, 0i64, 0, 0i64, &TotalBytesAvail, 0i64);
          v2->st_size = v11 != 0 ? TotalBytesAvail : 0;
        }
        goto $done_8;
      }
      if ( !v8 )
        goto LABEL_10;
    }
    v9 = GetLastError();
    dosmaperr(v9);
    goto LABEL_43;
  }
  *_doserrno() = 0;
  *errno() = 9;
  return 0xFFFFFFFFi64;
}

// File Line: 268
// RVA: 0x14523D4
_fstat64$fin$0


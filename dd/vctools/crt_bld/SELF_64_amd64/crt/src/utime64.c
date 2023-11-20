// File Line: 52
// RVA: 0x12BDA00
signed __int64 __fastcall wutime64(const wchar_t *fname, __utimbuf64 *times)
{
  __utimbuf64 *v2; // rbx
  unsigned int v4; // ebx
  int v5; // edi
  int pfh; // [rsp+40h] [rbp+8h]

  v2 = times;
  if ( !fname )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  if ( wsopen_s(&pfh, fname, 32770, 64, 0) )
    return 0xFFFFFFFFi64;
  v4 = futime64(pfh, v2);
  if ( v4 == -1 )
    v5 = *errno();
  else
    v5 = pfh;
  close(pfh);
  if ( v4 == -1 )
    *errno() = v5;
  return v4;
}

// File Line: 111
// RVA: 0x12D56BC
signed __int64 __fastcall futime64(int fh, __utimbuf64 *times)
{
  __int64 v2; // rbx
  __utimbuf64 *v3; // rdi
  void *v4; // rax
  _FILETIME FileTime; // [rsp+20h] [rbp-29h]
  _FILETIME LastAccessTime; // [rsp+28h] [rbp-21h]
  _FILETIME LastWriteTime; // [rsp+30h] [rbp-19h]
  SYSTEMTIME SystemTime; // [rsp+38h] [rbp-11h]
  tm ptm; // [rsp+48h] [rbp-1h]
  __int64 v11; // [rsp+70h] [rbp+27h]
  __int64 timeptr; // [rsp+78h] [rbp+2Fh]

  v2 = fh;
  v3 = times;
  if ( fh == -2 )
  {
    *errno() = 9;
  }
  else if ( (signed int)ioinit() >= 0 )
  {
    if ( (signed int)v2 >= 0 && (unsigned int)v2 < nhandle && _pioinfo[v2 >> 5][v2 & 0x1F].osfile & 1 )
    {
      if ( !v3 )
      {
        time64(&timeptr);
        v3 = (__utimbuf64 *)&v11;
        v11 = timeptr;
      }
      if ( !localtime64_s(&ptm, &v3->modtime) )
      {
        SystemTime.wMilliseconds = 0;
        SystemTime.wYear = LOWORD(ptm.tm_year) + 1900;
        SystemTime.wMonth = LOWORD(ptm.tm_mon) + 1;
        SystemTime.wDay = ptm.tm_mday;
        SystemTime.wHour = ptm.tm_hour;
        SystemTime.wMinute = ptm.tm_min;
        SystemTime.wSecond = ptm.tm_sec;
        if ( SystemTimeToFileTime(&SystemTime, &FileTime) )
        {
          if ( LocalFileTimeToFileTime(&FileTime, &LastWriteTime) )
          {
            if ( !localtime64_s(&ptm, &v3->actime) )
            {
              SystemTime.wMilliseconds = 0;
              SystemTime.wYear = LOWORD(ptm.tm_year) + 1900;
              SystemTime.wMonth = LOWORD(ptm.tm_mon) + 1;
              SystemTime.wDay = ptm.tm_mday;
              SystemTime.wHour = ptm.tm_hour;
              SystemTime.wMinute = ptm.tm_min;
              SystemTime.wSecond = ptm.tm_sec;
              if ( SystemTimeToFileTime(&SystemTime, &FileTime) )
              {
                if ( LocalFileTimeToFileTime(&FileTime, &LastAccessTime) )
                {
                  v4 = (void *)get_osfhandle(v2);
                  if ( SetFileTime(v4, 0i64, &LastAccessTime, &LastWriteTime) )
                    return 0i64;
                }
              }
            }
          }
        }
      }
      *errno() = 22;
    }
    else
    {
      *errno() = 9;
      invalid_parameter_noinfo();
    }
  }
  return 0xFFFFFFFFi64;
}


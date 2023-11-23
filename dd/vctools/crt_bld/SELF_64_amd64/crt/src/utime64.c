// File Line: 52
// RVA: 0x12BDA00
__int64 __fastcall wutime64(const wchar_t *fname, __utimbuf64 *times)
{
  unsigned int v4; // ebx
  int v5; // edi
  int pfh; // [rsp+40h] [rbp+8h] BYREF

  if ( !fname )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  if ( wsopen_s(&pfh, fname, 32770, 64, 0) )
    return 0xFFFFFFFFi64;
  v4 = futime64(pfh, times);
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
__int64 __fastcall futime64(int fh, __utimbuf64 *times)
{
  __int64 v2; // rbx
  void *osfhandle; // rax
  _FILETIME FileTime; // [rsp+20h] [rbp-29h] BYREF
  _FILETIME LastAccessTime; // [rsp+28h] [rbp-21h] BYREF
  _FILETIME LastWriteTime; // [rsp+30h] [rbp-19h] BYREF
  SYSTEMTIME SystemTime; // [rsp+38h] [rbp-11h] BYREF
  tm ptm; // [rsp+48h] [rbp-1h] BYREF
  __int64 v11; // [rsp+70h] [rbp+27h] BYREF
  __int64 timeptr; // [rsp+78h] [rbp+2Fh] BYREF

  v2 = fh;
  if ( fh == -2 )
  {
    *errno() = 9;
  }
  else if ( (int)ioinit() >= 0 )
  {
    if ( (int)v2 >= 0 && (unsigned int)v2 < nhandle && (_pioinfo[v2 >> 5][v2 & 0x1F].osfile & 1) != 0 )
    {
      if ( !times )
      {
        time64(&timeptr);
        times = (__utimbuf64 *)&v11;
        v11 = timeptr;
      }
      if ( !localtime64_s(&ptm, &times->modtime) )
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
            if ( !localtime64_s(&ptm, &times->actime) )
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
                  osfhandle = (void *)get_osfhandle(v2);
                  if ( SetFileTime(osfhandle, 0i64, &LastAccessTime, &LastWriteTime) )
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


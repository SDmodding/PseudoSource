// File Line: 62
// RVA: 0x12BEB10
char *__fastcall getcwd(char *pnbuf, int maxlen)
{
  return getdcwd(0, pnbuf, maxlen);
}

// File Line: 147
// RVA: 0x12BE784
unsigned __int16 *__fastcall wgetdcwd(unsigned int drive, unsigned __int16 *pnbuf, int maxlen)
{
  int v5; // esi
  signed int v6; // ebp
  signed int FullPathNameW; // eax
  unsigned __int16 *v9; // rax
  signed int v10; // eax
  unsigned int LastError; // eax
  LPWSTR FilePart; // [rsp+20h] [rbp-48h] BYREF
  __int64 FileName; // [rsp+28h] [rbp-40h] BYREF

  v5 = drive;
  if ( !drive )
  {
    v5 = getdrive();
LABEL_6:
    if ( pnbuf )
    {
      if ( maxlen <= 0 )
      {
        *errno() = 22;
        goto LABEL_4;
      }
      v6 = maxlen;
      *pnbuf = 0;
    }
    else
    {
      v6 = 0;
    }
    if ( v5 )
    {
      wcscpy((wchar_t *)&FileName + 1, L":.");
      LOWORD(FileName) = v5 + 64;
    }
    else
    {
      wcscpy((wchar_t *)&FileName, L".");
    }
    FullPathNameW = GetFullPathNameW((LPCWSTR)&FileName, v6, pnbuf, &FilePart);
    if ( FullPathNameW )
    {
      if ( pnbuf )
      {
        if ( FullPathNameW >= v6 )
        {
          *errno() = 34;
          *pnbuf = 0;
          return 0i64;
        }
        return pnbuf;
      }
      if ( FullPathNameW > maxlen )
        maxlen = FullPathNameW;
      v9 = (unsigned __int16 *)calloc(maxlen, 2ui64);
      pnbuf = v9;
      if ( !v9 )
      {
        *errno() = 12;
        *_doserrno() = 8;
        return 0i64;
      }
      v10 = GetFullPathNameW((LPCWSTR)&FileName, maxlen, v9, &FilePart);
      if ( v10 && v10 < maxlen )
        return pnbuf;
    }
    LastError = GetLastError();
    dosmaperr(LastError);
    return 0i64;
  }
  if ( validdrive(drive) )
    goto LABEL_6;
  *_doserrno() = 15;
  *errno() = 13;
LABEL_4:
  invalid_parameter_noinfo();
  return 0i64;
}

// File Line: 258
// RVA: 0x12BEC50
__int64 __fastcall validdrive(unsigned int drive)
{
  unsigned int v2; // ebx
  wchar_t RootPathName; // [rsp+20h] [rbp-18h] BYREF
  int v4; // [rsp+22h] [rbp-16h]
  __int16 v5; // [rsp+26h] [rbp-12h]

  if ( drive <= 0x1A )
  {
    v2 = 0;
    if ( drive )
    {
      v4 = 6029370;
      v5 = 0;
      RootPathName = drive + 64;
      LOBYTE(v2) = GetDriveTypeW(&RootPathName) >= 2;
      return v2;
    }
    else
    {
      return 1i64;
    }
  }
  else
  {
    *_doserrno() = 15;
    *errno() = 13;
    invalid_parameter_noinfo();
    return 0i64;
  }
}


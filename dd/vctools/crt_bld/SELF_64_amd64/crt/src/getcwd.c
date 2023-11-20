// File Line: 62
// RVA: 0x12BEB10
char *__fastcall getcwd(char *pnbuf, int maxlen)
{
  return getdcwd(0, pnbuf, maxlen);
}

// File Line: 147
// RVA: 0x12BE784
unsigned __int16 *__fastcall wgetdcwd(int drive, unsigned __int16 *pnbuf, int maxlen)
{
  int v3; // edi
  unsigned __int16 *v4; // rbx
  int v5; // esi
  signed int v6; // ebp
  signed int v7; // eax
  wchar_t *v9; // rax
  signed int v10; // eax
  unsigned int v11; // eax
  LPWSTR FilePart; // [rsp+20h] [rbp-48h]
  char FileName[6]; // [rsp+28h] [rbp-40h]
  __int16 v14; // [rsp+2Eh] [rbp-3Ah]

  v3 = maxlen;
  v4 = pnbuf;
  v5 = drive;
  if ( !drive )
  {
    v5 = getdrive();
LABEL_6:
    if ( v4 )
    {
      if ( v3 <= 0 )
      {
        *errno() = 22;
        goto LABEL_4;
      }
      v6 = v3;
      *v4 = 0;
    }
    else
    {
      v6 = 0;
    }
    if ( v5 )
    {
      *(_DWORD *)&FileName[2] = 3014714;
      v14 = 0;
      *(_WORD *)FileName = v5 + 64;
    }
    else
    {
      *(_DWORD *)FileName = 46;
    }
    v7 = GetFullPathNameW((LPCWSTR)FileName, v6, v4, &FilePart);
    if ( v7 )
    {
      if ( v4 )
      {
        if ( v7 >= v6 )
        {
          *errno() = 34;
          *v4 = 0;
          return 0i64;
        }
        return v4;
      }
      if ( v7 > v3 )
        v3 = v7;
      v9 = (wchar_t *)calloc(v3, 2ui64);
      v4 = v9;
      if ( !v9 )
      {
        *errno() = 12;
        *_doserrno() = 8;
        return 0i64;
      }
      v10 = GetFullPathNameW((LPCWSTR)FileName, v3, v9, &FilePart);
      if ( v10 && v10 < v3 )
        return v4;
    }
    v11 = GetLastError();
    dosmaperr(v11);
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
signed __int64 __fastcall validdrive(unsigned int drive)
{
  signed __int64 result; // rax
  unsigned int v2; // ebx
  wchar_t RootPathName; // [rsp+20h] [rbp-18h]
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
      result = v2;
    }
    else
    {
      result = 1i64;
    }
  }
  else
  {
    *_doserrno() = 15;
    *errno() = 13;
    invalid_parameter_noinfo();
    result = 0i64;
  }
  return result;
}


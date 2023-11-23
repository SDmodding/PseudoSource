// File Line: 44
// RVA: 0x12BED54
__int64 __fastcall getdrive()
{
  wchar_t *v0; // rbx
  int v1; // ebp
  signed int CurrentDirectoryW; // eax
  DWORD v3; // edi
  DWORD v4; // esi
  wchar_t *v5; // rax
  unsigned int v6; // esi
  int v7; // eax
  wchar_t Buffer[264]; // [rsp+20h] [rbp-228h] BYREF

  v0 = Buffer;
  v1 = 0;
  CurrentDirectoryW = GetCurrentDirectoryW(0x105u, Buffer);
  v3 = CurrentDirectoryW;
  if ( CurrentDirectoryW > 260 )
  {
    v4 = CurrentDirectoryW + 1;
    v5 = (wchar_t *)calloc_crt(CurrentDirectoryW + 1, 2ui64);
    v0 = v5;
    if ( v5 )
    {
      v1 = 1;
      if ( v3 )
        v3 = GetCurrentDirectoryW(v4, v5);
    }
    else
    {
      v3 = 0;
      *errno() = 12;
    }
  }
  v6 = 0;
  if ( v3 )
  {
    if ( v0[1] == 58 )
    {
      v7 = *v0;
      if ( (unsigned __int16)(*v0 - 97) <= 0x19u )
        v7 -= 32;
      v6 = v7 - 64;
    }
  }
  else
  {
    *errno() = 12;
  }
  if ( v1 )
    free(v0);
  return v6;
}

// File Line: 107
// RVA: 0x12BECD0
__int64 __fastcall chdrive(int drive)
{
  unsigned int v2; // ebx
  unsigned int LastError; // eax
  wchar_t PathName; // [rsp+20h] [rbp-18h] BYREF
  int v5; // [rsp+22h] [rbp-16h]

  if ( (unsigned int)(drive - 1) <= 0x19 )
  {
    v5 = 58;
    v2 = 0;
    PathName = drive + 64;
    if ( !SetCurrentDirectoryW(&PathName) )
    {
      LastError = GetLastError();
      dosmaperr(LastError);
      return (unsigned int)-1;
    }
    return v2;
  }
  else
  {
    *_doserrno() = 15;
    *errno() = 13;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
}


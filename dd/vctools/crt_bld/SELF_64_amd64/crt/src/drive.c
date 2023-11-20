// File Line: 44
// RVA: 0x12BED54
__int64 __fastcall getdrive()
{
  wchar_t *v0; // rbx
  signed int v1; // ebp
  signed int v2; // eax
  DWORD v3; // edi
  DWORD v4; // esi
  wchar_t *v5; // rax
  unsigned int v6; // esi
  unsigned __int16 v7; // ax
  bool v8; // cf
  bool v9; // zf
  int v10; // eax
  wchar_t Buffer; // [rsp+20h] [rbp-228h]

  v0 = &Buffer;
  v1 = 0;
  v2 = GetCurrentDirectoryW(0x105u, &Buffer);
  v3 = v2;
  if ( v2 > 260 )
  {
    v4 = v2 + 1;
    v5 = (wchar_t *)calloc_crt(v2 + 1, 2ui64);
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
      v7 = *v0 - 97;
      v8 = v7 < 0x19u;
      v9 = v7 == 25;
      v10 = *v0;
      if ( v8 || v9 )
        v10 -= 32;
      v6 = v10 - 64;
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
signed __int64 __fastcall chdrive(int drive)
{
  signed __int64 result; // rax
  unsigned int v2; // ebx
  unsigned int v3; // eax
  wchar_t PathName; // [rsp+20h] [rbp-18h]
  int v5; // [rsp+22h] [rbp-16h]

  if ( (unsigned int)(drive - 1) <= 0x19 )
  {
    v5 = 58;
    v2 = 0;
    PathName = drive + 64;
    if ( !SetCurrentDirectoryW(&PathName) )
    {
      v3 = GetLastError();
      dosmaperr(v3);
      v2 = -1;
    }
    result = v2;
  }
  else
  {
    *_doserrno() = 15;
    *errno() = 13;
    invalid_parameter_noinfo();
    result = 0xFFFFFFFFi64;
  }
  return result;
}


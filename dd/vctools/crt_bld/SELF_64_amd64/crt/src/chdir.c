// File Line: 41
// RVA: 0x12BE8D4
__int64 __fastcall wchdir(const wchar_t *path)
{
  unsigned int v1; // esi
  wchar_t *v2; // rbx
  signed int v3; // er14
  signed int v4; // eax
  DWORD v5; // edi
  DWORD v6; // ebp
  wchar_t *v7; // rax
  unsigned __int16 v8; // ax
  unsigned int v9; // eax
  wchar_t Name; // [rsp+20h] [rbp-248h]
  unsigned __int16 v12; // [rsp+22h] [rbp-246h]
  int v13; // [rsp+24h] [rbp-244h]
  wchar_t Buffer; // [rsp+30h] [rbp-238h]

  v1 = -1;
  v2 = &Buffer;
  v3 = 0;
  if ( !path )
  {
    *_doserrno() = 0;
    *errno() = 22;
    invalid_parameter_noinfo();
    return v1;
  }
  if ( !SetCurrentDirectoryW(path) )
    goto LABEL_14;
  v4 = GetCurrentDirectoryW(0x105u, &Buffer);
  v5 = v4;
  if ( v4 > 260 )
  {
    v6 = v4 + 1;
    v7 = (wchar_t *)calloc_crt(v4 + 1, 2ui64);
    v2 = v7;
    if ( !v7 )
      goto LABEL_14;
    v3 = 1;
    if ( !v5 )
      goto LABEL_14;
    v5 = GetCurrentDirectoryW(v6, v7);
  }
  if ( v5 )
  {
    if ( ((v8 = *v2, *v2 == 92) || v8 == 47) && v8 == v2[1]
      || (Name = 61, v12 = towupper(*v2), v13 = 58, SetEnvironmentVariableW(&Name, v2)) )
    {
      v1 = 0;
      goto LABEL_15;
    }
  }
LABEL_14:
  v9 = GetLastError();
  dosmaperr(v9);
LABEL_15:
  if ( v3 )
    free(v2);
  return v1;
}


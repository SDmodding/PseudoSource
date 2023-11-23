// File Line: 70
// RVA: 0x1334518
__int64 __fastcall putenv(const char *option)
{
  lock(7);
  LODWORD(option) = putenv_helper(option, 0i64);
  unlock(7);
  return (unsigned int)option;
}

// File Line: 78
// RVA: 0x1452441
_putenv$fin$0

// File Line: 112
// RVA: 0x133454C
__int64 __fastcall putenv_helper(char *name, char *value)
{
  const char *v5; // rax
  size_t v6; // rbx
  char *v7; // rax
  char *v8; // r8
  unsigned __int64 v9; // rdx
  char *v10; // rcx
  unsigned __int64 v11; // r14
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rbx
  char *v14; // rax
  unsigned __int64 v15; // r14
  int cchWideChar; // r14d
  int v17; // eax
  void *lpWideCharStr; // rax
  __int64 v19; // rax
  void *pBlock; // [rsp+70h] [rbp+40h] BYREF
  char *poption; // [rsp+78h] [rbp+48h] BYREF

  poption = 0i64;
  if ( !_env_initialized )
    return 0xFFFFFFFFi64;
  if ( !name )
    goto LABEL_4;
  if ( value )
  {
    v11 = strnlen(name, 0x7FFFui64);
    v12 = strnlen(value, 0x7FFFui64);
    if ( v11 < 0x7FFF && v12 < 0x7FFF )
    {
      v13 = v11 + v12 + 2;
      v14 = (char *)calloc_crt(v13, 1ui64);
      poption = v14;
      if ( !v14 )
        return 0xFFFFFFFFi64;
      strcpy_s(v14, v13, name);
      poption[v11] = 61;
      v15 = v11 + 1;
      v8 = value;
      v10 = &poption[v15];
      v9 = v13 - v15;
      goto LABEL_15;
    }
LABEL_4:
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  v5 = mbschr(name, 0x3Du);
  if ( v5 && (v5 - name >= 0x7FFF || strnlen(v5 + 1, 0x7FFFui64) >= 0x7FFF) )
    goto LABEL_4;
  v6 = strlen(name);
  v7 = (char *)calloc_crt(v6 + 1, 1ui64);
  poption = v7;
  if ( !v7 )
    return 0xFFFFFFFFi64;
  v8 = name;
  v9 = v6 + 1;
  v10 = v7;
LABEL_15:
  strcpy_s(v10, v9, v8);
  if ( (unsigned int)_crtsetenv((const char **)&poption, 1) )
  {
    if ( poption )
      free(poption);
    return 0xFFFFFFFFi64;
  }
  if ( wenviron )
  {
    pBlock = 0i64;
    cchWideChar = MultiByteToWideChar(0, 0, name, -1, 0i64, 0);
    if ( !cchWideChar )
    {
LABEL_20:
      *errno() = 42;
      return 0xFFFFFFFFi64;
    }
    if ( value )
    {
      v17 = MultiByteToWideChar(0, 0, value, -1, 0i64, 0);
      if ( !v17 )
        goto LABEL_20;
      cchWideChar += v17 + 1;
    }
    lpWideCharStr = calloc_crt(cchWideChar, 2ui64);
    pBlock = lpWideCharStr;
    if ( !lpWideCharStr )
      return 0xFFFFFFFFi64;
    if ( !MultiByteToWideChar(0, 0, name, -1, (LPWSTR)lpWideCharStr, cchWideChar)
      || value
      && (v19 = wcslen((const wchar_t *)pBlock),
          *((_WORD *)pBlock + v19) = 61,
          !MultiByteToWideChar(0, 0, value, -1, (LPWSTR)pBlock + v19 + 1, cchWideChar - (v19 + 1))) )
    {
      free(pBlock);
      goto LABEL_20;
    }
    if ( _crtwsetenv((unsigned __int16 **)&pBlock, 0) )
    {
      if ( pBlock )
        free(pBlock);
      return 0xFFFFFFFFi64;
    }
  }
  return 0i64;
}


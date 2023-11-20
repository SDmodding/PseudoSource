// File Line: 70
// RVA: 0x1334518
__int64 __fastcall putenv(const char *option)
{
  const char *v1; // rbx

  v1 = option;
  lock(7);
  LODWORD(v1) = putenv_helper(v1, 0i64);
  unlock(7);
  return (unsigned int)v1;
}

// File Line: 78
// RVA: 0x1452441
_putenv$fin$0

// File Line: 112
// RVA: 0x133454C
signed __int64 __fastcall putenv_helper(const char *name, const char *value)
{
  const char *v2; // rsi
  const char *v3; // rdi
  const char *v5; // rax
  size_t v6; // rax
  size_t v7; // rbx
  char *v8; // rax
  const char *v9; // r8
  unsigned __int64 v10; // rdx
  char *v11; // rcx
  unsigned __int64 v12; // r14
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // rbx
  char *v15; // rax
  signed __int64 v16; // r14
  int cchWideChar; // er14
  int v18; // eax
  void *lpWideCharStr; // rax
  signed __int64 v20; // rax
  void *pBlock; // [rsp+70h] [rbp+40h]
  char *poption; // [rsp+78h] [rbp+48h]

  poption = 0i64;
  v2 = value;
  v3 = name;
  if ( !_env_initialized )
    return 0xFFFFFFFFi64;
  if ( !name )
    goto LABEL_4;
  if ( value )
  {
    v12 = strnlen(name, 0x7FFFui64);
    v13 = strnlen(v2, 0x7FFFui64);
    if ( v12 < 0x7FFF && v13 < 0x7FFF )
    {
      v14 = v12 + v13 + 2;
      v15 = (char *)calloc_crt(v12 + v13 + 2, 1ui64);
      poption = v15;
      if ( !v15 )
        return 0xFFFFFFFFi64;
      strcpy_s(v15, v14, v3);
      poption[v12] = 61;
      v16 = v12 + 1;
      v9 = v2;
      v11 = &poption[v16];
      v10 = v14 - v16;
      goto LABEL_15;
    }
LABEL_4:
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  v5 = mbschr(name, 0x3Du);
  if ( v5 && (v5 - v3 >= 0x7FFF || strnlen(v5 + 1, 0x7FFFui64) >= 0x7FFF) )
    goto LABEL_4;
  v6 = strlen(v3);
  v7 = v6;
  v8 = (char *)calloc_crt(v6 + 1, 1ui64);
  poption = v8;
  if ( !v8 )
    return 0xFFFFFFFFi64;
  v9 = v3;
  v10 = v7 + 1;
  v11 = v8;
LABEL_15:
  strcpy_s(v11, v10, v9);
  if ( (unsigned int)_crtsetenv(&poption, 1) )
  {
    if ( poption )
      free(poption);
    return 0xFFFFFFFFi64;
  }
  if ( wenviron )
  {
    pBlock = 0i64;
    cchWideChar = MultiByteToWideChar(0, 0, v3, -1, 0i64, 0);
    if ( !cchWideChar )
    {
LABEL_20:
      *errno() = 42;
      return 0xFFFFFFFFi64;
    }
    if ( v2 )
    {
      v18 = MultiByteToWideChar(0, 0, v2, -1, 0i64, 0);
      if ( !v18 )
        goto LABEL_20;
      cchWideChar += v18 + 1;
    }
    lpWideCharStr = calloc_crt(cchWideChar, 2ui64);
    pBlock = lpWideCharStr;
    if ( !lpWideCharStr )
      return 0xFFFFFFFFi64;
    if ( !MultiByteToWideChar(0, 0, v3, -1, (LPWSTR)lpWideCharStr, cchWideChar)
      || v2
      && (v20 = wcslen((const wchar_t *)pBlock),
          *((_WORD *)pBlock + v20) = 61,
          !MultiByteToWideChar(0, 0, v2, -1, (LPWSTR)pBlock + v20 + 1, cchWideChar - (v20 + 1))) )
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


// File Line: 77
// RVA: 0x12D1E68
__int64 __fastcall setenvp()
{
  char *v0; // rbx
  int v1; // edi
  char **v3; // rdi
  char *v4; // rbx
  int v5; // esi
  char *v6; // rax

  if ( !_mbctype_initialized )
    _initmbctable();
  v0 = aenvptr;
  v1 = 0;
  if ( !aenvptr )
    return 0xFFFFFFFFi64;
  while ( *v0 )
  {
    if ( *v0 != 61 )
      ++v1;
    v0 += strlen(v0) + 1;
  }
  v3 = (char **)calloc_crt(v1 + 1, 8ui64);
  environ = v3;
  if ( !v3 )
    return 0xFFFFFFFFi64;
  v4 = aenvptr;
  if ( *aenvptr )
  {
    while ( 1 )
    {
      v5 = strlen(v4) + 1;
      if ( *v4 != 61 )
      {
        v6 = (char *)calloc_crt(v5, 1ui64);
        *v3 = v6;
        if ( !v6 )
        {
          free(environ);
          environ = 0i64;
          return 0xFFFFFFFFi64;
        }
        if ( (unsigned int)strcpy_s(v6, v5, v4) )
        {
          invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
          JUMPOUT(0x1412D1F98i64);
        }
        ++v3;
      }
      v4 += v5;
      if ( !*v4 )
      {
        v4 = aenvptr;
        break;
      }
    }
  }
  free(v4);
  aenvptr = 0i64;
  *v3 = 0i64;
  _env_initialized = 1;
  return 0i64;
}


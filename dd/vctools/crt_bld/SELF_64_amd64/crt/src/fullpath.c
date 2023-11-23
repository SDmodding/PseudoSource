// File Line: 93
// RVA: 0x12BA524
char *__fastcall fullpath(char *UserBuf, const char *path, unsigned __int64 maxlen)
{
  unsigned __int64 v3; // rdi
  unsigned __int64 v6; // rax
  unsigned int LastError; // eax
  char *v9; // rbx
  DWORD FullPathNameA; // eax
  LPSTR FilePart; // [rsp+38h] [rbp+10h] BYREF

  v3 = maxlen;
  if ( !path || !*path )
    return getcwd(UserBuf, maxlen);
  if ( UserBuf )
  {
    if ( !maxlen )
    {
      *errno() = 22;
      invalid_parameter_noinfo();
      return 0i64;
    }
    v9 = UserBuf;
  }
  else
  {
    LODWORD(v6) = GetFullPathNameA(path, 0, 0i64, 0i64);
    if ( !(_DWORD)v6 )
    {
LABEL_5:
      LastError = GetLastError();
      dosmaperr(LastError);
      return 0i64;
    }
    v6 = (unsigned int)v6;
    if ( v3 > (unsigned int)v6 )
      v6 = v3;
    v3 = v6;
    v9 = (char *)calloc(v6, 1ui64);
    if ( !v9 )
    {
      *errno() = 12;
      return 0i64;
    }
  }
  FullPathNameA = GetFullPathNameA(path, v3, v9, &FilePart);
  if ( FullPathNameA >= v3 )
  {
    if ( !UserBuf )
      free(v9);
    *errno() = 34;
    return 0i64;
  }
  if ( !FullPathNameA )
  {
    if ( !UserBuf )
      free(v9);
    goto LABEL_5;
  }
  return v9;
}


// File Line: 75
// RVA: 0x12BDEC4
char *__fastcall getenv(const char *option)
{
  const char *v3; // rbx

  if ( option && strnlen(option, 0x7FFFui64) < 0x7FFF )
  {
    lock(7);
    v3 = getenv_helper_nolock(option);
    unlock(7);
    return (char *)v3;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0i64;
  }
}

// File Line: 95
// RVA: 0x12BDE20
const char *__fastcall getenv_helper_nolock(const char *option)
{
  const char **v1; // rbx
  unsigned __int64 v3; // rdi

  v1 = (const char **)environ;
  if ( _env_initialized )
  {
    if ( environ || wenviron && !_wtomb_environ() && (v1 = (const char **)environ) != 0i64 )
    {
      if ( option )
      {
        v3 = strlen(option);
        while ( *v1 )
        {
          if ( strlen(*v1) > v3 && (*v1)[v3] == 61 && !mbsnbicoll(*v1, option, v3) )
            return &(*v1)[v3 + 1];
          ++v1;
        }
      }
    }
  }
  return 0i64;
}

// File Line: 198
// RVA: 0x12BDF30
void __fastcall getenv_s(
        unsigned __int64 *pReturnValue,
        char *buffer,
        unsigned __int64 sizeInTChars,
        const char *varname)
{
  int v8; // eax
  const char *v9; // rax
  char *v10; // r14
  size_t v11; // rax

  lock(7);
  if ( !pReturnValue )
    goto LABEL_2;
  *pReturnValue = 0i64;
  if ( buffer )
  {
    if ( !sizeInTChars )
      goto LABEL_8;
LABEL_7:
    v8 = 1;
    goto LABEL_9;
  }
  if ( !sizeInTChars )
    goto LABEL_7;
LABEL_8:
  v8 = 0;
LABEL_9:
  if ( !v8 )
  {
LABEL_2:
    *errno() = 22;
    invalid_parameter_noinfo();
$LN8_204:
    unlock(7);
    return;
  }
  if ( buffer )
    *buffer = 0;
  v9 = getenv_helper_nolock(varname);
  v10 = (char *)v9;
  if ( !v9 )
    goto $LN8_204;
  v11 = strlen(v9) + 1;
  *pReturnValue = v11;
  if ( !sizeInTChars || v11 > sizeInTChars || !(unsigned int)strcpy_s(buffer, sizeInTChars, v10) )
    goto $LN8_204;
  invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
}

// File Line: 303
// RVA: 0x12BDD1C
void __fastcall dupenv_s(char **pBuffer, unsigned __int64 *pBufferSizeInTChars, const char *varname)
{
  const char *v6; // rax
  char *v7; // r15
  unsigned __int64 v8; // rsi
  char *v9; // rax

  lock(7);
  if ( !pBuffer )
    goto LABEL_2;
  *pBuffer = 0i64;
  if ( pBufferSizeInTChars )
    *pBufferSizeInTChars = 0i64;
  if ( !varname )
  {
LABEL_2:
    *errno() = 22;
    invalid_parameter_noinfo();
$LN8_203:
    unlock(7);
    return;
  }
  v6 = getenv_helper_nolock(varname);
  v7 = (char *)v6;
  if ( !v6 )
    goto $LN8_203;
  v8 = strlen(v6) + 1;
  v9 = (char *)calloc(v8, 1ui64);
  *pBuffer = v9;
  if ( !v9 )
  {
    *errno() = 12;
    errno();
    goto $LN8_203;
  }
  if ( !(unsigned int)strcpy_s(v9, v8, v7) )
  {
    if ( pBufferSizeInTChars )
      *pBufferSizeInTChars = v8;
    goto $LN8_203;
  }
  invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
}

// File Line: 314
// RVA: 0x1451E71
getenv_s$fin$0


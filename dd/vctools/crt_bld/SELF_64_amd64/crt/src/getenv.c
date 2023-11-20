// File Line: 75
// RVA: 0x12BDEC4
char *__fastcall getenv(const char *option)
{
  const char *v1; // rbx
  char *result; // rax
  char *v3; // rbx

  v1 = option;
  if ( option && strnlen(option, 0x7FFFui64) < 0x7FFF )
  {
    lock(7);
    v3 = (char *)getenv_helper_nolock(v1);
    unlock(7);
    result = v3;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 0i64;
  }
  return result;
}

// File Line: 95
// RVA: 0x12BDE20
const char *__fastcall getenv_helper_nolock(const char *option)
{
  const char **v1; // rbx
  const char *v2; // rsi
  unsigned __int64 v3; // rdi

  v1 = (const char **)environ;
  v2 = option;
  if ( _env_initialized )
  {
    if ( environ || wenviron && !_wtomb_environ() && (v1 = (const char **)environ) != 0i64 )
    {
      if ( v2 )
      {
        v3 = strlen(v2);
        while ( *v1 )
        {
          if ( strlen(*v1) > v3 && (*v1)[v3] == 61 && !mbsnbicoll(*v1, v2, v3) )
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
void __fastcall getenv_s(unsigned __int64 *pReturnValue, char *buffer, unsigned __int64 sizeInTChars, const char *varname)
{
  const char *v4; // r14
  unsigned __int64 v5; // rsi
  char *v6; // rdi
  unsigned __int64 *v7; // r15
  signed int v8; // eax
  const char *v9; // rax
  const char *v10; // r14
  size_t v11; // rax

  v4 = varname;
  v5 = sizeInTChars;
  v6 = buffer;
  v7 = pReturnValue;
  lock(7);
  if ( !v7 )
    goto LABEL_2;
  *v7 = 0i64;
  if ( !v6 )
    goto LABEL_20;
  if ( v5 )
  {
LABEL_7:
    v8 = 1;
    goto LABEL_9;
  }
  if ( !v6 )
  {
LABEL_20:
    if ( !v5 )
      goto LABEL_7;
  }
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
  if ( v6 )
    *v6 = 0;
  v9 = getenv_helper_nolock(v4);
  v10 = v9;
  if ( !v9 )
    goto $LN8_204;
  v11 = strlen(v9) + 1;
  *v7 = v11;
  if ( !v5 || v11 > v5 || !(unsigned int)strcpy_s(v6, v5, v10) )
    goto $LN8_204;
  invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
}

// File Line: 303
// RVA: 0x12BDD1C
void __fastcall dupenv_s(char **pBuffer, unsigned __int64 *pBufferSizeInTChars, const char *varname)
{
  const char *v3; // rsi
  unsigned __int64 *v4; // rdi
  char **v5; // r14
  const char *v6; // rax
  const char *v7; // r15
  size_t v8; // rax
  unsigned __int64 v9; // rsi
  char *v10; // rax
  int v11; // ebx

  v3 = varname;
  v4 = pBufferSizeInTChars;
  v5 = pBuffer;
  lock(7);
  if ( !v5 )
    goto LABEL_16;
  *v5 = 0i64;
  if ( v4 )
    *v4 = 0i64;
  if ( v3 == 0i64 )
  {
LABEL_16:
    *errno() = 22;
    invalid_parameter_noinfo();
$LN8_203:
    unlock(7);
    return;
  }
  v6 = getenv_helper_nolock(v3);
  v7 = v6;
  if ( !v6 )
    goto $LN8_203;
  v8 = strlen(v6);
  v9 = v8 + 1;
  v10 = (char *)calloc(v8 + 1, 1ui64);
  *v5 = v10;
  if ( !v10 )
  {
    *errno() = 12;
    v11 = *errno();
    goto $LN8_203;
  }
  if ( !(unsigned int)strcpy_s(v10, v9, v7) )
  {
    if ( v4 )
      *v4 = v9;
    goto $LN8_203;
  }
  invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
}

// File Line: 314
// RVA: 0x1451E71
getenv_s$fin$0


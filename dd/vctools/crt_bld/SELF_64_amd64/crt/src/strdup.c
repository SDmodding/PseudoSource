// File Line: 66
// RVA: 0x12D72E4
char *__fastcall strdup(const char *string)
{
  const char *v1; // rbx
  size_t v2; // rax
  size_t v3; // rsi
  char *v4; // rax
  char *v5; // rdi

  v1 = string;
  if ( !string )
    return 0i64;
  v2 = strlen(string);
  v3 = v2;
  v4 = (char *)malloc(v2 + 1);
  v5 = v4;
  if ( !v4 )
    return 0i64;
  if ( (unsigned int)strcpy_s(v4, v3 + 1, v1) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
    JUMPOUT(*(_QWORD *)_GSHandlerCheck_SEH);
  }
  return v5;
}


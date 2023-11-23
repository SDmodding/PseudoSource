// File Line: 66
// RVA: 0x12D72E4
char *__fastcall strdup(char *string)
{
  size_t v2; // rsi
  char *v3; // rax
  char *v4; // rdi

  if ( !string )
    return 0i64;
  v2 = strlen(string);
  v3 = (char *)malloc(v2 + 1);
  v4 = v3;
  if ( !v3 )
    return 0i64;
  if ( (unsigned int)strcpy_s(v3, v2 + 1, string) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
  }
  return v4;
}


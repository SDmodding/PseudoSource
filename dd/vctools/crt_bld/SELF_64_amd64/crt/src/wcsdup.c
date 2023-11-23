// File Line: 68
// RVA: 0x1334040
char *__fastcall wcsdup(const wchar_t *string)
{
  __int64 v2; // rsi
  char *v3; // rax
  char *v4; // rdi

  if ( !string )
    return 0i64;
  v2 = wcslen(string);
  v3 = (char *)calloc(v2 + 1, 2ui64);
  v4 = v3;
  if ( !v3 )
    return 0i64;
  if ( (unsigned int)wcscpy_s(v3, v2 + 1, string) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    JUMPOUT(0x1413340B4i64);
  }
  return v4;
}


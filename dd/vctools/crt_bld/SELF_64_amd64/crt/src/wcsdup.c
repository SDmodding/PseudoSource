// File Line: 68
// RVA: 0x1334040
unsigned __int16 *__fastcall wcsdup(const wchar_t *string)
{
  const wchar_t *v1; // rbx
  signed __int64 v2; // rax
  signed __int64 v3; // rsi
  unsigned __int16 *v4; // rax
  unsigned __int16 *v5; // rdi

  v1 = string;
  if ( !string )
    return 0i64;
  v2 = wcslen(string);
  v3 = v2;
  v4 = (unsigned __int16 *)calloc(v2 + 1, 2ui64);
  v5 = v4;
  if ( !v4 )
    return 0i64;
  if ( (unsigned int)wcscpy_s(v4, v3 + 1, v1) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    JUMPOUT(*(_QWORD *)&byte_1413340B4);
  }
  return v5;
}


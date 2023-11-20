// File Line: 40
// RVA: 0x12CF994
unsigned __int16 *__fastcall wcspbrk(const wchar_t *string, const wchar_t *control)
{
  const wchar_t *v2; // r9
  const wchar_t *v3; // r8
  wchar_t v4; // dx

  v2 = control;
  while ( 1 )
  {
    if ( !*string )
      return 0i64;
    v3 = v2;
    if ( *v2 )
      break;
LABEL_7:
    ++string;
  }
  v4 = *v2;
  while ( v4 != *string )
  {
    ++v3;
    v4 = *v3;
    if ( !*v3 )
      goto LABEL_7;
  }
  return (unsigned __int16 *)string;
}


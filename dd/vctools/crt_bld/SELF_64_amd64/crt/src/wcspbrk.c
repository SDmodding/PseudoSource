// File Line: 40
// RVA: 0x12CF994
unsigned __int16 *__fastcall wcspbrk(const wchar_t *string, const wchar_t *control)
{
  const wchar_t *v3; // r8
  wchar_t v4; // dx

  while ( 1 )
  {
    if ( !*string )
      return 0i64;
    v3 = control;
    if ( *control )
      break;
LABEL_6:
    ++string;
  }
  v4 = *control;
  while ( v4 != *string )
  {
    v4 = *++v3;
    if ( !*v3 )
      goto LABEL_6;
  }
  return (unsigned __int16 *)string;
}


// File Line: 13
// RVA: 0x12C0AAC
unsigned __int16 *__fastcall wcstok_s(unsigned __int16 *_String, const wchar_t *_Control, unsigned __int16 **_Context)
{
  unsigned __int16 **v3; // r10
  const wchar_t *v4; // r9
  unsigned __int16 *result; // rax
  const wchar_t *v6; // rdx
  wchar_t v7; // r8
  const wchar_t *v8; // rdx
  wchar_t v9; // r8

  v3 = _Context;
  v4 = _Control;
  if ( _Context && _Control && (_String || (_String = *_Context) != 0i64) )
  {
    while ( *_String )
    {
      v6 = v4;
      if ( *v4 )
      {
        v7 = *v4;
        do
        {
          if ( v7 == *_String )
            break;
          ++v6;
          v7 = *v6;
        }
        while ( *v6 );
      }
      if ( !*v6 )
        break;
      ++_String;
    }
    result = _String;
    while ( *_String )
    {
      v8 = v4;
      if ( *v4 )
      {
        v9 = *v4;
        do
        {
          if ( v9 == *_String )
            break;
          ++v8;
          v9 = *v8;
        }
        while ( *v8 );
      }
      if ( *v8 )
      {
        *_String = 0;
        ++_String;
        break;
      }
      ++_String;
    }
    *v3 = _String;
    if ( result == _String )
      result = 0i64;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 0i64;
  }
  return result;
}


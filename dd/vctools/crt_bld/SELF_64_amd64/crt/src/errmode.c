// File Line: 49
// RVA: 0x12D1FA4
__int64 __fastcall set_error_mode(int em)
{
  __int64 result; // rax

  if ( em >= 0 )
  {
    if ( em <= 2 )
    {
      result = (unsigned int)_error_mode;
      _error_mode = em;
      return result;
    }
    if ( em == 3 )
      return (unsigned int)_error_mode;
  }
  *errno() = 22;
  invalid_parameter_noinfo();
  return 0xFFFFFFFFi64;
}

// File Line: 93
// RVA: 0x12D1F9C
void __fastcall _set_app_type(int at)
{
  _app_type = at;
}


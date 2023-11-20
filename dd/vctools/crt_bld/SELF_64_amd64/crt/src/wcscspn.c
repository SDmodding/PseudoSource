// File Line: 44
// RVA: 0x12DAA38
signed __int64 __fastcall wcscspn(const wchar_t *string, const wchar_t *control)
{
  const wchar_t *v2; // r9
  const wchar_t *v3; // rax
  bool i; // zf
  const wchar_t *v5; // r8
  wchar_t v6; // dx

  v2 = control;
  v3 = string;
  for ( i = *string == 0; !i; i = *v3 == 0 )
  {
    v5 = v2;
    if ( *v2 )
    {
      v6 = *v2;
      while ( v6 != *v3 )
      {
        ++v5;
        v6 = *v5;
        if ( !*v5 )
          goto LABEL_7;
      }
      return v3 - string;
    }
LABEL_7:
    ++v3;
  }
  return v3 - string;
}


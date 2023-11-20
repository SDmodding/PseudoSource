// File Line: 51
// RVA: 0x12D5C4C
char *__fastcall mbsrchr_l(const char *str, unsigned int c, localeinfo_struct *plocinfo)
{
  const char *v3; // rbx
  int v4; // esi
  char *v5; // rdi
  __int64 v6; // rdx
  int v7; // ecx
  _LocaleUpdate v9; // [rsp+20h] [rbp-28h]

  v3 = str;
  v4 = c;
  v5 = 0i64;
  _LocaleUpdate::_LocaleUpdate(&v9, plocinfo);
  if ( v3 )
  {
    if ( v9.localeinfo.mbcinfo->ismbcodepage )
    {
      do
      {
        v6 = *(unsigned __int8 *)v3;
        v7 = *(unsigned __int8 *)v3;
        if ( v9.localeinfo.mbcinfo->mbctype[v6 + 1] & 4 )
        {
          LOBYTE(v6) = *++v3;
          if ( *v3 )
          {
            if ( v4 == ((unsigned __int8)v6 | (v7 << 8)) )
              v5 = (char *)(v3 - 1);
          }
          else if ( !v5 )
          {
            v5 = (char *)v3;
          }
        }
        else if ( v4 == (_DWORD)v6 )
        {
          v5 = (char *)v3;
        }
        ++v3;
      }
      while ( (_BYTE)v6 );
    }
    else
    {
      v5 = strrchr(v3, v4);
    }
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
  }
  if ( v9.updated )
    v9.ptd->_ownlocale &= 0xFFFFFFFD;
  return v5;
}

// File Line: 85
// RVA: 0x12D5C44
const char *__fastcall mbsrchr(const char *str, unsigned int c)
{
  return mbsrchr_l(str, c, 0i64);
}


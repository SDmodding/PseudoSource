// File Line: 51
// RVA: 0x12D5C4C
__m128i *__fastcall mbsrchr_l(__m128i *str, int c, localeinfo_struct *plocinfo)
{
  __m128i *v5; // rdi
  __int64 v6; // rdx
  int v7; // ecx
  _LocaleUpdate v9; // [rsp+20h] [rbp-28h] BYREF

  v5 = 0i64;
  _LocaleUpdate::_LocaleUpdate(&v9, plocinfo);
  if ( str )
  {
    if ( v9.localeinfo.mbcinfo->ismbcodepage )
    {
      do
      {
        v6 = (unsigned __int8)str->m128i_i8[0];
        v7 = (unsigned __int8)str->m128i_i8[0];
        if ( (v9.localeinfo.mbcinfo->mbctype[v6 + 1] & 4) != 0 )
        {
          str = (__m128i *)((char *)str + 1);
          LOBYTE(v6) = str->m128i_i8[0];
          if ( str->m128i_i8[0] )
          {
            if ( c == ((unsigned __int8)v6 | (v7 << 8)) )
              v5 = (__m128i *)((char *)str - 1);
          }
          else if ( !v5 )
          {
            v5 = str;
          }
        }
        else if ( c == (_DWORD)v6 )
        {
          v5 = str;
        }
        str = (__m128i *)((char *)str + 1);
      }
      while ( (_BYTE)v6 );
    }
    else
    {
      v5 = strrchr((unsigned __int64)str, c);
    }
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
  }
  if ( v9.updated )
    v9.ptd->_ownlocale &= ~2u;
  return v5;
}

// File Line: 85
// RVA: 0x12D5C44
const char *__fastcall mbsrchr(const char *str, unsigned int c)
{
  return mbsrchr_l(str, c, 0i64);
}


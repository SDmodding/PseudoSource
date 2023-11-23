// File Line: 57
// RVA: 0x12B386C
__int64 __fastcall gcvt_s(char *buf, unsigned __int64 sizeInChars, long double value, int ndec)
{
  unsigned __int64 v6; // rsi
  unsigned int v7; // edi
  int decpt; // edx
  int v9; // eax
  char i; // dl
  char v11; // al
  char *v12; // rbx
  char *v13; // rcx
  char v14; // al
  _CRT_DOUBLE x; // [rsp+30h] [rbp-88h] BYREF
  _LocaleUpdate v17; // [rsp+38h] [rbp-80h] BYREF
  _strflt flt; // [rsp+58h] [rbp-60h] BYREF
  char resultstr[24]; // [rsp+70h] [rbp-48h] BYREF

  x.x = value;
  v6 = ndec;
  _LocaleUpdate::_LocaleUpdate(&v17, 0i64);
  if ( buf && sizeInChars )
  {
    *buf = 0;
    if ( v6 < sizeInChars )
    {
      decpt = fltout2(x, &flt, resultstr, 0x16ui64)->decpt;
      if ( decpt - 1 < -1 || decpt - 1 > (int)v6 - 1 )
        v9 = cftoe(&x.x, buf, sizeInChars, v6 - 1, 0);
      else
        v9 = cftof(&x.x, buf, sizeInChars, v6 - decpt);
      v7 = v9;
      if ( v9 )
      {
        *errno() = v9;
      }
      else
      {
        for ( i = *buf; *buf; i = *++buf )
        {
          if ( i == *v17.localeinfo.locinfo->lconv->decimal_point )
            break;
        }
        v11 = *buf;
        v12 = buf + 1;
        if ( v11 )
        {
          while ( *v12 && *v12 != 101 )
            ++v12;
          v13 = v12;
          do
            --v12;
          while ( *v12 == 48 );
          do
          {
            v14 = *v13;
            ++v12;
            ++v13;
            *v12 = v14;
          }
          while ( v14 );
        }
      }
    }
    else
    {
      *errno() = 34;
      invalid_parameter_noinfo();
      v7 = 34;
    }
  }
  else
  {
    v7 = 22;
    *errno() = 22;
    invalid_parameter_noinfo();
  }
  if ( v17.updated )
    v17.ptd->_ownlocale &= ~2u;
  return v7;
}

// File Line: 159
// RVA: 0x12B3840
char *__fastcall gcvt(long double value, int ndec, char *buf)
{
  char *v3; // rbx

  v3 = buf;
  if ( gcvt_s(buf, 0xFFFFFFFFFFFFFFFFui64, value, ndec) )
    return 0i64;
  return v3;
}


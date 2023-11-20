// File Line: 57
// RVA: 0x12B386C
__int64 __fastcall gcvt_s(char *buf, unsigned __int64 sizeInChars, long double value, int ndec)
{
  char *v4; // rbx
  unsigned __int64 v5; // rbp
  unsigned __int64 v6; // rsi
  unsigned int v7; // edi
  int v8; // edx
  int v9; // eax
  char i; // dl
  char v11; // al
  char *v12; // rbx
  char *v13; // rcx
  char v14; // al
  _CRT_DOUBLE x; // [rsp+30h] [rbp-88h]
  _LocaleUpdate v17; // [rsp+38h] [rbp-80h]
  _strflt flt; // [rsp+58h] [rbp-60h]
  char resultstr; // [rsp+70h] [rbp-48h]

  v4 = buf;
  v5 = sizeInChars;
  x.x = value;
  v6 = ndec;
  _LocaleUpdate::_LocaleUpdate(&v17, 0i64);
  if ( v4 && v5 )
  {
    *v4 = 0;
    if ( v6 < v5 )
    {
      v8 = fltout2(x, &flt, &resultstr, 0x16ui64)->decpt;
      if ( v8 - 1 < -1 || v8 - 1 > (signed int)v6 - 1 )
        v9 = cftoe(&x.x, v4, v5, v6 - 1, 0);
      else
        v9 = cftof(&x.x, v4, v5, v6 - v8);
      v7 = v9;
      if ( v9 )
      {
        *errno() = v9;
      }
      else
      {
        for ( i = *v4; *v4; i = *++v4 )
        {
          if ( i == *v17.localeinfo.locinfo->lconv->decimal_point )
            break;
        }
        v11 = *v4;
        v12 = v4 + 1;
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
    v17.ptd->_ownlocale &= 0xFFFFFFFD;
  return v7;
}

// File Line: 159
// RVA: 0x12B3840
char *__fastcall gcvt(long double value, int ndec, char *buf)
{
  char *v3; // rbx

  v3 = buf;
  if ( gcvt_s(buf, 0xFFFFFFFFFFFFFFFFui64, value, ndec) )
    v3 = 0i64;
  return v3;
}


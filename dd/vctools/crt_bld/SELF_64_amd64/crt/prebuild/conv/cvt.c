// File Line: 127
// RVA: 0x12C6620
void __fastcall forcdecpt(char *buffer)
{
  forcdecpt_l(buffer, 0i64);
}

// File Line: 132
// RVA: 0x12C6628
void __fastcall forcdecpt_l(char *buffer, localeinfo_struct *_Locale)
{
  unsigned __int8 v3; // dl
  char *v4; // rbx
  unsigned __int8 v5; // al
  _LocaleUpdate v7; // [rsp+20h] [rbp-28h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v7, _Locale);
  if ( (unsigned int)tolower_0(*buffer) != 101 )
  {
    do
      ++buffer;
    while ( (unsigned int)isdigit((unsigned __int8)*buffer) );
  }
  if ( (unsigned int)tolower_0(*buffer) == 120 )
    buffer += 2;
  v3 = *buffer;
  *buffer = *v7.localeinfo.locinfo->lconv->decimal_point;
  v4 = buffer + 1;
  do
  {
    v5 = *v4;
    *v4 = v3;
    v3 = v5;
  }
  while ( *v4++ );
  if ( v7.updated )
    v7.ptd->_ownlocale &= ~2u;
}

// File Line: 193
// RVA: 0x12C6538
void __fastcall cropzeros(char *buf)
{
  cropzeros_l(buf, 0i64);
}

// File Line: 198
// RVA: 0x12C6540
void __fastcall cropzeros_l(char *buf, localeinfo_struct *_Locale)
{
  char i; // cl
  char v4; // al
  char *v5; // rbx
  char *v6; // rdx
  char v7; // al
  _LocaleUpdate v8; // [rsp+20h] [rbp-28h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v8, _Locale);
  for ( i = *buf; *buf; i = *++buf )
  {
    if ( i == *v8.localeinfo.locinfo->lconv->decimal_point )
      break;
  }
  v4 = *buf;
  v5 = buf + 1;
  if ( v4 )
  {
    while ( *v5 && ((*v5 - 69) & 0xDF) != 0 )
      ++v5;
    v6 = v5;
    do
      --v5;
    while ( *v5 == 48 );
    if ( *v5 == *v8.localeinfo.locinfo->lconv->decimal_point )
      --v5;
    do
    {
      v7 = *v6;
      ++v5;
      ++v6;
      *v5 = v7;
    }
    while ( v7 );
  }
  if ( v8.updated )
    v8.ptd->_ownlocale &= ~2u;
}

// File Line: 223
// RVA: 0x12C66A8
_BOOL8 __fastcall positive(long double *arg)
{
  return *arg >= 0.0;
}

// File Line: 229
// RVA: 0x12C65E0
void __fastcall fassign_l(int flag, _CRT_DOUBLE *argument, char *number, localeinfo_struct *plocinfo)
{
  _CRT_DOUBLE d; // [rsp+20h] [rbp-18h] BYREF
  _CRT_FLOAT v6; // [rsp+40h] [rbp+8h] BYREF

  if ( flag )
  {
    atodbl_l(&d, number, plocinfo);
    argument->x = d.x;
  }
  else
  {
    atoflt_l(&v6, number, plocinfo);
    LODWORD(argument->x) = v6;
  }
}

// File Line: 268
// RVA: 0x12C65D8
void __fastcall fassign(int flag, char *argument, char *number)
{
  fassign_l(flag, argument, number, 0i64);
}

// File Line: 300
// RVA: 0x12C5EC4
__int64 __fastcall cftoe2_l(
        char *buf,
        unsigned __int64 sizeInBytes,
        int ndec,
        int caps,
        _strflt *pflt,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  __int64 v10; // rsi
  int *v11; // rax
  unsigned int v12; // ebx
  int v13; // eax
  size_t v14; // rax
  char *v15; // rdx
  char *v16; // rbx
  unsigned __int64 v17; // rdx
  _BYTE *v18; // rcx
  int v19; // r8d
  _LocaleUpdate v21; // [rsp+30h] [rbp-38h] BYREF

  v10 = ndec;
  _LocaleUpdate::_LocaleUpdate(&v21, plocinfo);
  if ( !buf || !sizeInBytes )
  {
    v11 = errno();
    v12 = 22;
LABEL_8:
    *v11 = v12;
    invalid_parameter_noinfo();
    goto LABEL_33;
  }
  v13 = 0;
  if ( (int)v10 > 0 )
    v13 = v10;
  if ( sizeInBytes <= v13 + 9 )
  {
    v11 = errno();
    v12 = 34;
    goto LABEL_8;
  }
  if ( g_fmt && (int)v10 > 0 )
  {
    v14 = strlen(&buf[pflt->sign == 45]);
    memmove(&buf[(pflt->sign == 45) + ((int)v10 > 0)], &buf[pflt->sign == 45], v14 + 1);
  }
  v15 = buf;
  if ( pflt->sign == 45 )
  {
    *buf = 45;
    v15 = buf + 1;
  }
  if ( (int)v10 > 0 )
  {
    *v15 = v15[1];
    *++v15 = *v21.localeinfo.locinfo->lconv->decimal_point;
  }
  v16 = &v15[v10 + (g_fmt == 0)];
  v17 = sizeInBytes + buf - v16;
  if ( sizeInBytes == -1i64 )
    v17 = -1i64;
  if ( (unsigned int)strcpy_s(v16, v17, "e+000") )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    JUMPOUT(0x1412C60BCi64);
  }
  v18 = v16 + 2;
  if ( caps )
    *v16 = 69;
  if ( *pflt->mantissa != 48 )
  {
    v19 = pflt->decpt - 1;
    if ( v19 < 0 )
    {
      v19 = 1 - pflt->decpt;
      v16[1] = 45;
    }
    if ( v19 >= 100 )
    {
      v16[2] += v19 / 100;
      v19 %= 100;
    }
    if ( v19 >= 10 )
    {
      v16[3] += v19 / 10;
      v19 %= 10;
    }
    v16[4] += v19;
  }
  if ( (outputformat & 1) != 0 && *v18 == 48 )
    memmove(v18, v16 + 3, 3ui64);
  v12 = 0;
LABEL_33:
  if ( v21.updated )
    v21.ptd->_ownlocale &= ~2u;
  return v12;
}

// File Line: 412
// RVA: 0x12C60C0
int __fastcall cftoe_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned __int64 sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned __int64 v10; // rdx
  _strflt flt; // [rsp+40h] [rbp-68h] BYREF
  char resultstr[24]; // [rsp+58h] [rbp-50h] BYREF

  fltout2(*(_CRT_DOUBLE *)&pvalue->x, &flt, resultstr, 0x16ui64);
  if ( buf && sizeInBytes )
  {
    v10 = -1i64;
    if ( sizeInBytes != -1i64 )
      v10 = sizeInBytes - (flt.sign == 45) - (ndec > 0);
    result = fptostr(&buf[(flt.sign == 45) + (ndec > 0)], v10, ndec + 1, &flt);
    if ( result )
      *buf = 0;
    else
      return cftoe2_l(buf, sizeInBytes, ndec, caps, &flt, 0, plocinfo);
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

// File Line: 444
// RVA: 0x12C5EA8
int __fastcall cftoe(long double *pvalue, char *buf, unsigned __int64 sizeInBytes, int ndec, int caps)
{
  return cftoe_l(pvalue, buf, sizeInBytes, ndec, caps, 0i64);
}

// File Line: 473
// RVA: 0x12C5AF8
__int64 __fastcall cftoa_l(
        long double *pvalue,
        char *buf,
        unsigned __int64 sizeInBytes,
        unsigned int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  size_t v8; // rbx
  __int64 v10; // r12
  __int16 v11; // bp
  int *v12; // rax
  unsigned int v13; // ebx
  unsigned __int64 v14; // r8
  __m128i *v15; // rax
  char *v16; // rdi
  _BYTE *v17; // rdi
  int v18; // edx
  char *v19; // rdi
  char *v20; // r15
  char *v21; // rdi
  unsigned __int64 v22; // r8
  unsigned __int16 v23; // ax
  char *i; // rcx
  _BYTE *v25; // rdi
  __int64 v26; // rcx
  _BYTE *v27; // rdi
  _BYTE *v28; // r8
  _LocaleUpdate v30; // [rsp+30h] [rbp-48h] BYREF

  v8 = ndec;
  v10 = 1023i64;
  v11 = 48;
  _LocaleUpdate::_LocaleUpdate(&v30, plocinfo);
  if ( (v8 & 0x80000000) != 0i64 )
    v8 = 0i64;
  if ( !buf || !sizeInBytes )
  {
    v12 = errno();
    v13 = 22;
LABEL_8:
    *v12 = v13;
    invalid_parameter_noinfo();
    goto LABEL_58;
  }
  *buf = 0;
  if ( sizeInBytes <= (int)v8 + 11 )
  {
    v12 = errno();
    v13 = 34;
    goto LABEL_8;
  }
  if ( ((*(_QWORD *)pvalue >> 52) & 0x7FFi64) == 2047 )
  {
    v14 = sizeInBytes - 2;
    if ( sizeInBytes == -1i64 )
      v14 = -1i64;
    v13 = cftoe_l(pvalue, buf + 2, v14, v8, 0, 0i64);
    if ( v13 )
    {
      *buf = 0;
      goto LABEL_58;
    }
    if ( buf[2] == 45 )
      *buf++ = 45;
    *buf = 48;
    buf[1] = caps != 0 ? 88 : 120;
    v15 = strrchr((unsigned __int64)(buf + 2), 101);
    if ( v15 )
    {
      v15->m128i_i8[0] = caps != 0 ? 80 : 112;
      v15->m128i_i8[3] = 0;
    }
  }
  else
  {
    if ( *(__int64 *)pvalue < 0 )
      *buf++ = 45;
    *buf = 48;
    v16 = buf + 1;
    *v16 = caps != 0 ? 88 : 120;
    v17 = v16 + 1;
    v18 = caps != 0 ? 7 : 39;
    if ( (*(_QWORD *)pvalue & 0x7FF0000000000000i64) != 0 )
    {
      *v17 = 49;
      v19 = v17 + 1;
    }
    else
    {
      *v17 = 48;
      v19 = v17 + 1;
      v10 = (*(_QWORD *)pvalue & 0xFFFFFFFFFFFFFi64) != 0 ? 0x3FE : 0;
    }
    v20 = v19;
    v21 = v19 + 1;
    if ( (_DWORD)v8 )
      *v20 = *v30.localeinfo.locinfo->lconv->decimal_point;
    else
      *v20 = 0;
    if ( (*(_QWORD *)pvalue & 0xFFFFFFFFFFFFFi64) != 0 )
    {
      v22 = 0xF000000000000i64;
      do
      {
        if ( (int)v8 <= 0 )
          break;
        v23 = ((v22 & *(_QWORD *)pvalue & 0xFFFFFFFFFFFFFi64) >> v11) + 48;
        if ( v23 > 0x39u )
          LOBYTE(v23) = v18 + v23;
        *v21 = v23;
        v22 >>= 4;
        v8 = (unsigned int)(v8 - 1);
        ++v21;
        v11 -= 4;
      }
      while ( v11 >= 0 );
      if ( v11 >= 0 && (unsigned __int16)((v22 & *(_QWORD *)pvalue & 0xFFFFFFFFFFFFFi64) >> v11) > 8u )
      {
        for ( i = v21 - 1; ((*i - 70) & 0xDF) == 0; --i )
          *i = 48;
        if ( i == v20 )
        {
          ++*(i - 1);
        }
        else if ( *i == 57 )
        {
          *i = caps != 0 ? 65 : 97;
        }
        else
        {
          ++*i;
        }
      }
    }
    if ( (int)v8 > 0 )
    {
      LOBYTE(v18) = 48;
      memset(v21, v18, v8);
      v21 += v8;
    }
    if ( !*v20 )
      v21 = v20;
    *v21 = caps != 0 ? 80 : 112;
    v25 = v21 + 1;
    v26 = ((*(_QWORD *)pvalue >> 52) & 0x7FFi64) - v10;
    if ( v26 < 0 )
    {
      *v25 = 45;
      v27 = v25 + 1;
      v26 = -v26;
    }
    else
    {
      *v25 = 43;
      v27 = v25 + 1;
    }
    v28 = v27;
    *v27 = 48;
    if ( v26 >= 1000 && (*v27 = v26 / 1000 + 48, ++v27, v26 %= 1000i64, v27 != v28) || v26 >= 100 )
    {
      *v27++ = v26 / 100 + 48;
      v26 %= 100i64;
    }
    if ( v27 != v28 || v26 >= 10 )
    {
      *v27++ = v26 / 10 + 48;
      v26 %= 10i64;
    }
    *v27 = v26 + 48;
    v27[1] = 0;
  }
  v13 = 0;
LABEL_58:
  if ( v30.updated )
    v30.ptd->_ownlocale &= ~2u;
  return v13;
}

// File Line: 696
// RVA: 0x12C61CC
__int64 __fastcall cftof2_l(
        char *buf,
        unsigned __int64 sizeInBytes,
        int ndec,
        _strflt *pflt,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int v9; // ebx
  unsigned int v11; // ebx
  size_t v12; // rax
  char *v13; // rdi
  size_t v14; // rax
  int decpt; // ebx
  int v16; // ebx
  int v17; // eax
  size_t v18; // rax
  _LocaleUpdate v20; // [rsp+20h] [rbp-28h] BYREF

  v9 = pflt->decpt - 1;
  _LocaleUpdate::_LocaleUpdate(&v20, plocinfo);
  if ( buf && sizeInBytes )
  {
    if ( g_fmt && v9 == ndec )
      *(_WORD *)&buf[(pflt->sign == 45) + v9] = 48;
    if ( pflt->sign == 45 )
      *buf++ = 45;
    if ( pflt->decpt > 0 )
    {
      v13 = &buf[pflt->decpt];
    }
    else
    {
      v12 = strlen(buf);
      memmove(buf + 1, buf, v12 + 1);
      *buf = 48;
      v13 = buf + 1;
    }
    if ( ndec > 0 )
    {
      v14 = strlen(v13);
      memmove(v13 + 1, v13, v14 + 1);
      *v13 = *v20.localeinfo.locinfo->lconv->decimal_point;
      decpt = pflt->decpt;
      if ( decpt < 0 )
      {
        v16 = -decpt;
        if ( !g_fmt )
        {
          v17 = v16;
          v16 = ndec;
          if ( ndec >= v17 )
            v16 = v17;
        }
        if ( v16 )
        {
          v18 = strlen(v13 + 1);
          memmove(&v13[v16 + 1], v13 + 1, v18 + 1);
        }
        memset(v13 + 1, 48, v16);
      }
    }
    v11 = 0;
  }
  else
  {
    v11 = 22;
    *errno() = 22;
    invalid_parameter_noinfo();
  }
  if ( v20.updated )
    v20.ptd->_ownlocale &= ~2u;
  return v11;
}

// File Line: 798
// RVA: 0x12C6330
int __fastcall cftof_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned __int64 sizeInBytes,
        int ndec,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned __int64 v9; // rdx
  _strflt flt; // [rsp+30h] [rbp-68h] BYREF
  char resultstr[24]; // [rsp+48h] [rbp-50h] BYREF

  fltout2(*(_CRT_DOUBLE *)&pvalue->x, &flt, resultstr, 0x16ui64);
  if ( buf && sizeInBytes )
  {
    v9 = -1i64;
    if ( sizeInBytes != -1i64 )
      v9 = sizeInBytes - (flt.sign == 45);
    result = fptostr(&buf[flt.sign == 45], v9, ndec + flt.decpt, &flt);
    if ( result )
      *buf = 0;
    else
      return cftof2_l(buf, sizeInBytes, ndec, &flt, 0, plocinfo);
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

// File Line: 830
// RVA: 0x12C61B8
int __fastcall cftof(long double *pvalue, char *buf, unsigned __int64 sizeInBytes, int ndec)
{
  return cftof_l(pvalue, buf, sizeInBytes, ndec, 0i64);
}

// File Line: 861
// RVA: 0x12C6404
int __fastcall cftog_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned __int64 sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  int v10; // r14d
  _BOOL8 v11; // rax
  unsigned __int64 v12; // rdx
  char *v13; // rbx
  int v14; // eax
  _strflt flt; // [rsp+40h] [rbp-68h] BYREF
  char resultstr[24]; // [rsp+58h] [rbp-50h] BYREF

  fltout2(*(_CRT_DOUBLE *)&pvalue->x, &flt, resultstr, 0x16ui64);
  if ( buf && sizeInBytes )
  {
    v10 = flt.decpt - 1;
    v11 = flt.sign == 45;
    v12 = -1i64;
    v13 = &buf[v11];
    if ( sizeInBytes != -1i64 )
      v12 = sizeInBytes - v11;
    result = fptostr(&buf[v11], v12, ndec, &flt);
    if ( result )
    {
      *buf = 0;
    }
    else
    {
      v14 = flt.decpt - 1;
      if ( flt.decpt - 1 < -4 || v14 >= ndec )
      {
        return cftoe2_l(buf, sizeInBytes, ndec, caps, &flt, 1, plocinfo);
      }
      else
      {
        if ( v10 < v14 )
        {
          while ( *v13++ )
            ;
          *(v13 - 2) = 0;
        }
        return cftof2_l(buf, sizeInBytes, ndec, &flt, 1, plocinfo);
      }
    }
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

// File Line: 966
// RVA: 0x12C5A78
int __fastcall cfltcvt_l(
        long double *arg,
        char *buffer,
        unsigned __int64 sizeInBytes,
        int format,
        int precision,
        int caps,
        localeinfo_struct *plocinfo)
{
  if ( ((format - 69) & 0xFFFFFFDF) == 0 )
    return cftoe_l(arg, buffer, sizeInBytes, precision, caps, plocinfo);
  if ( format == 102 )
    return cftof_l(arg, buffer, sizeInBytes, precision, plocinfo);
  if ( ((format - 65) & 0xFFFFFFDF) != 0 )
    return cftog_l(arg, buffer, sizeInBytes, precision, caps, plocinfo);
  return cftoa_l(arg, buffer, sizeInBytes, precision, caps, plocinfo);
}

// File Line: 982
// RVA: 0x12C5A54
int __fastcall cfltcvt(
        long double *arg,
        char *buffer,
        unsigned __int64 sizeInBytes,
        int format,
        int precision,
        int caps)
{
  return cfltcvt_l(arg, buffer, sizeInBytes, format, precision, caps, 0i64);
}


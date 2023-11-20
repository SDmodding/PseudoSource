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
  char *v2; // rbx
  char v3; // dl
  char *v4; // rbx
  char v5; // al
  char v6; // al
  _LocaleUpdate v7; // [rsp+20h] [rbp-28h]

  v2 = buffer;
  _LocaleUpdate::_LocaleUpdate(&v7, _Locale);
  if ( (unsigned int)tolower_0(*v2) != 101 )
  {
    do
      ++v2;
    while ( (unsigned int)isdigit((unsigned __int8)*v2) );
  }
  if ( (unsigned int)tolower_0(*v2) == 120 )
    v2 += 2;
  v3 = *v2;
  *v2 = *v7.localeinfo.locinfo->lconv->decimal_point;
  v4 = v2 + 1;
  do
  {
    v5 = *v4;
    *v4 = v3;
    v3 = v5;
    v6 = *v4++;
  }
  while ( v6 );
  if ( v7.updated )
    v7.ptd->_ownlocale &= 0xFFFFFFFD;
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
  char *v2; // rbx
  char i; // cl
  char v4; // al
  char *v5; // rbx
  char *v6; // rdx
  char v7; // al
  _LocaleUpdate v8; // [rsp+20h] [rbp-28h]

  v2 = buf;
  _LocaleUpdate::_LocaleUpdate(&v8, _Locale);
  for ( i = *v2; *v2; i = *++v2 )
  {
    if ( i == *v8.localeinfo.locinfo->lconv->decimal_point )
      break;
  }
  v4 = *v2;
  v5 = v2 + 1;
  if ( v4 )
  {
    while ( *v5 && (*v5 - 69) & 0xDF )
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
    v8.ptd->_ownlocale &= 0xFFFFFFFD;
}

// File Line: 223
// RVA: 0x12C66A8
_BOOL8 __fastcall positive(long double *arg)
{
  return *arg >= 0.0;
}

// File Line: 229
// RVA: 0x12C65E0
void __fastcall fassign_l(int flag, char *argument, char *number, localeinfo_struct *plocinfo)
{
  char *v4; // rbx
  _CRT_DOUBLE d; // [rsp+20h] [rbp-18h]
  _CRT_FLOAT v6; // [rsp+40h] [rbp+8h]

  v4 = argument;
  if ( flag )
  {
    atodbl_l(&d, number, plocinfo);
    *(_CRT_DOUBLE *)v4 = d;
  }
  else
  {
    atoflt_l(&v6, number, plocinfo);
    *(_CRT_FLOAT *)v4 = v6;
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
__int64 __fastcall cftoe2_l(char *buf, unsigned __int64 sizeInBytes, int ndec, int caps, _strflt *pflt, char g_fmt, localeinfo_struct *plocinfo)
{
  unsigned __int64 v7; // r14
  char *v8; // rdi
  int v9; // er13
  __int64 v10; // rsi
  int *v11; // rax
  unsigned int v12; // ebx
  int v13; // eax
  char *v14; // rbx
  size_t v15; // rax
  char *v16; // rdx
  char *v17; // rbx
  char *v18; // rcx
  unsigned __int64 v19; // rdx
  _BYTE *v20; // rcx
  int v21; // er8
  __int64 v23; // [rsp+30h] [rbp-38h]
  __int64 v24; // [rsp+40h] [rbp-28h]
  char v25; // [rsp+48h] [rbp-20h]

  v7 = sizeInBytes;
  v8 = buf;
  v9 = caps;
  v10 = ndec;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v23, plocinfo);
  if ( !v8 || !v7 )
  {
    v11 = errno();
    v12 = 22;
LABEL_8:
    *v11 = v12;
    invalid_parameter_noinfo();
    goto LABEL_33;
  }
  v13 = 0;
  if ( (signed int)v10 > 0 )
    v13 = v10;
  if ( v7 <= v13 + 9 )
  {
    v11 = errno();
    v12 = 34;
    goto LABEL_8;
  }
  if ( g_fmt )
  {
    v14 = &v8[pflt->sign == 45];
    if ( (signed int)v10 > 0 )
    {
      v15 = strlen(&v8[pflt->sign == 45]);
      memmove(&v14[(signed int)v10 > 0], v14, v15 + 1);
    }
  }
  v16 = v8;
  if ( pflt->sign == 45 )
  {
    *v8 = 45;
    v16 = v8 + 1;
  }
  if ( (signed int)v10 > 0 )
  {
    *v16 = v16[1];
    *++v16 = ***(_BYTE ***)(v23 + 240);
  }
  v17 = &v16[v10 + (g_fmt == 0)];
  v18 = &v16[v10 + (g_fmt == 0)];
  v19 = v7 + v8 - v17;
  if ( v7 == -1i64 )
    v19 = -1i64;
  if ( (unsigned int)strcpy_s(v18, v19, "e+000") )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    JUMPOUT(*(_QWORD *)&byte_1412C60BC);
  }
  v20 = v17 + 2;
  if ( v9 )
    *v17 = 69;
  if ( *pflt->mantissa != 48 )
  {
    v21 = pflt->decpt - 1;
    if ( v21 < 0 )
    {
      v21 = 1 - pflt->decpt;
      v17[1] = 45;
    }
    if ( v21 >= 100 )
    {
      v17[2] += v21 / 100;
      v21 %= 100;
    }
    if ( v21 >= 10 )
    {
      v17[3] += v21 / 10;
      v21 %= 10;
    }
    v17[4] += v21;
  }
  if ( outputformat & 1 && *v20 == 48 )
    memmove(v20, v17 + 3, 3ui64);
  v12 = 0;
LABEL_33:
  if ( v25 )
    *(_DWORD *)(v24 + 200) &= 0xFFFFFFFD;
  return v12;
}

// File Line: 412
// RVA: 0x12C60C0
int __fastcall cftoe_l(long double *pvalue, char *buf, unsigned __int64 sizeInBytes, int ndec, int caps, localeinfo_struct *plocinfo)
{
  unsigned __int64 v6; // rbx
  char *v7; // rdi
  int v8; // esi
  int result; // eax
  unsigned __int64 v10; // rdx
  _strflt flt; // [rsp+40h] [rbp-68h]
  char resultstr; // [rsp+58h] [rbp-50h]

  v6 = sizeInBytes;
  v7 = buf;
  v8 = ndec;
  fltout2(*(_CRT_DOUBLE *)pvalue, &flt, &resultstr, 0x16ui64);
  if ( v7 && v6 )
  {
    v10 = -1i64;
    if ( v6 != -1i64 )
      v10 = v6 - (flt.sign == 45) - (v8 > 0);
    result = fptostr(&v7[(flt.sign == 45) + (v8 > 0)], v10, v8 + 1, &flt);
    if ( result )
      *v7 = 0;
    else
      result = cftoe2_l(v7, v6, v8, caps, &flt, 0, plocinfo);
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 22;
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
__int64 __fastcall cftoa_l(long double *pvalue, char *buf, unsigned __int64 sizeInBytes, int ndec, int caps, localeinfo_struct *plocinfo)
{
  char *v6; // rdi
  long double *v7; // r14
  size_t v8; // rbx
  unsigned __int64 v9; // rsi
  signed __int64 v10; // r12
  signed __int16 v11; // bp
  int *v12; // rax
  unsigned int v13; // ebx
  unsigned __int64 v14; // r8
  char *v15; // rax
  _BYTE *v16; // rdi
  _BYTE *v17; // rdi
  int v18; // edx
  signed __int64 v19; // rdi
  _BYTE *v20; // r15
  _BYTE *v21; // rdi
  unsigned __int64 v22; // r8
  unsigned __int16 v23; // ax
  _BYTE *i; // rcx
  _BYTE *v25; // rdi
  signed __int64 v26; // rcx
  _BYTE *v27; // rdi
  _BYTE *v28; // r8
  unsigned __int64 v29; // rdx
  unsigned __int64 v30; // rdx
  unsigned __int64 v31; // rdx
  __int64 v33; // [rsp+30h] [rbp-48h]
  __int64 v34; // [rsp+40h] [rbp-38h]
  char v35; // [rsp+48h] [rbp-30h]

  v6 = buf;
  v7 = pvalue;
  v8 = (unsigned int)ndec;
  v9 = sizeInBytes;
  v10 = 1023i64;
  v11 = 48;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v33, plocinfo);
  if ( (v8 & 0x80000000) != 0i64 )
    v8 = 0i64;
  if ( !v6 || !v9 )
  {
    v12 = errno();
    v13 = 22;
LABEL_8:
    *v12 = v13;
    invalid_parameter_noinfo();
    goto LABEL_58;
  }
  *v6 = 0;
  if ( v9 <= (signed int)v8 + 11 )
  {
    v12 = errno();
    v13 = 34;
    goto LABEL_8;
  }
  if ( ((*(_QWORD *)v7 >> 52) & 0x7FFi64) == 2047 )
  {
    v14 = v9 - 2;
    if ( v9 == -1i64 )
      v14 = -1i64;
    v13 = cftoe_l(v7, v6 + 2, v14, v8, 0, 0i64);
    if ( v13 )
    {
      *v6 = 0;
      goto LABEL_58;
    }
    if ( v6[2] == 45 )
      *v6++ = 45;
    *v6 = 48;
    v6[1] = caps != 0 ? 88 : 120;
    v15 = strrchr(v6 + 2, 101);
    if ( v15 )
    {
      *v15 = caps != 0 ? 80 : 112;
      v15[3] = 0;
    }
  }
  else
  {
    if ( *(_QWORD *)v7 < 0i64 )
      *v6++ = 45;
    *v6 = 48;
    v16 = v6 + 1;
    *v16 = caps != 0 ? 88 : 120;
    v17 = v16 + 1;
    v18 = caps != 0 ? 7 : 39;
    if ( *(_QWORD *)v7 & 0x7FF0000000000000i64 )
    {
      *v17 = 49;
      v19 = (signed __int64)(v17 + 1);
    }
    else
    {
      *v17 = 48;
      v19 = (signed __int64)(v17 + 1);
      v10 = (*(_QWORD *)v7 & 0xFFFFFFFFFFFFFi64) != 0 ? 0x3FE : 0;
    }
    v20 = (_BYTE *)v19;
    v21 = (_BYTE *)(v19 + 1);
    if ( (_DWORD)v8 )
      *v20 = ***(_BYTE ***)(v33 + 240);
    else
      *v20 = 0;
    if ( *(_QWORD *)v7 & 0xFFFFFFFFFFFFFi64 )
    {
      v22 = 4222124650659840i64;
      do
      {
        if ( (signed int)v8 <= 0 )
          break;
        v23 = ((v22 & *(_QWORD *)v7 & 0xFFFFFFFFFFFFFi64) >> v11) + 48;
        if ( v23 > 0x39u )
          LOBYTE(v23) = v18 + v23;
        *v21 = v23;
        v22 >>= 4;
        v8 = (unsigned int)(v8 - 1);
        ++v21;
        v11 -= 4;
      }
      while ( v11 >= 0 );
      if ( v11 >= 0 && (unsigned __int16)((v22 & *(_QWORD *)v7 & 0xFFFFFFFFFFFFFi64) >> v11) > 8u )
      {
        for ( i = v21 - 1; !((*i - 70) & 0xDF); --i )
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
    if ( (signed int)v8 > 0 )
    {
      LOBYTE(v18) = 48;
      memset(v21, v18, v8);
      v21 += v8;
    }
    if ( !*v20 )
      v21 = v20;
    *v21 = caps != 0 ? 80 : 112;
    v25 = v21 + 1;
    v26 = ((*(_QWORD *)v7 >> 52) & 0x7FFi64) - v10;
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
    if ( v26 >= 1000
      && (v29 = ((unsigned __int64)((unsigned __int128)(v26 * (signed __int128)2361183241434822607i64) >> 64) >> 63)
              + ((signed __int64)((unsigned __int128)(v26 * (signed __int128)2361183241434822607i64) >> 64) >> 7),
          *v27 = v29 + 48,
          ++v27,
          v26 += -1000i64 * v29,
          v27 != v28)
      || v26 >= 100 )
    {
      v30 = ((unsigned __int64)(v26 + ((unsigned __int128)(v26 * (signed __int128)-6640827866535438581i64) >> 64)) >> 63)
          + ((signed __int64)(v26 + ((unsigned __int128)(v26 * (signed __int128)-6640827866535438581i64) >> 64)) >> 6);
      *v27++ = v30 + 48;
      v26 += -100i64 * v30;
    }
    if ( v27 != v28 || v26 >= 10 )
    {
      v31 = ((unsigned __int64)((unsigned __int128)(v26 * (signed __int128)7378697629483820647i64) >> 64) >> 63)
          + ((signed __int64)((unsigned __int128)(v26 * (signed __int128)7378697629483820647i64) >> 64) >> 2);
      *v27++ = v31 + 48;
      LOBYTE(v26) = -10 * v31 + v26;
    }
    *v27 = v26 + 48;
    v27[1] = 0;
  }
  v13 = 0;
LABEL_58:
  if ( v35 )
    *(_DWORD *)(v34 + 200) &= 0xFFFFFFFD;
  return v13;
}

// File Line: 696
// RVA: 0x12C61CC
__int64 __fastcall cftof2_l(char *buf, unsigned __int64 sizeInBytes, int ndec, _strflt *pflt, char g_fmt, localeinfo_struct *plocinfo)
{
  unsigned __int64 v6; // rsi
  char *v7; // rdi
  _strflt *v8; // rbp
  int v9; // ebx
  int v10; // er14
  unsigned int v11; // ebx
  size_t v12; // rax
  char *v13; // rdi
  size_t v14; // rax
  int v15; // ebx
  int v16; // ebx
  int v17; // eax
  size_t v18; // rax
  __int64 v20; // [rsp+20h] [rbp-28h]
  __int64 v21; // [rsp+30h] [rbp-18h]
  char v22; // [rsp+38h] [rbp-10h]

  v6 = sizeInBytes;
  v7 = buf;
  v8 = pflt;
  v9 = pflt->decpt - 1;
  v10 = ndec;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v20, plocinfo);
  if ( v7 && v6 )
  {
    if ( g_fmt && v9 == v10 )
      *(_WORD *)&v7[(v8->sign == 45) + v9] = 48;
    if ( v8->sign == 45 )
      *v7++ = 45;
    if ( v8->decpt > 0 )
    {
      v13 = &v7[v8->decpt];
    }
    else
    {
      v12 = strlen(v7);
      memmove(v7 + 1, v7, v12 + 1);
      *v7 = 48;
      v13 = v7 + 1;
    }
    if ( v10 > 0 )
    {
      v14 = strlen(v13);
      memmove(v13 + 1, v13, v14 + 1);
      *v13 = ***(_BYTE ***)(v20 + 240);
      v15 = v8->decpt;
      if ( v15 < 0 )
      {
        v16 = -v15;
        if ( !g_fmt )
        {
          v17 = v16;
          v16 = v10;
          if ( v10 >= v17 )
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
  if ( v22 )
    *(_DWORD *)(v21 + 200) &= 0xFFFFFFFD;
  return v11;
}

// File Line: 798
// RVA: 0x12C6330
int __fastcall cftof_l(long double *pvalue, char *buf, unsigned __int64 sizeInBytes, int ndec, localeinfo_struct *plocinfo)
{
  unsigned __int64 v5; // rbx
  char *v6; // rdi
  int v7; // esi
  int result; // eax
  unsigned __int64 v9; // rdx
  _strflt flt; // [rsp+30h] [rbp-68h]
  char resultstr; // [rsp+48h] [rbp-50h]

  v5 = sizeInBytes;
  v6 = buf;
  v7 = ndec;
  fltout2(*(_CRT_DOUBLE *)pvalue, &flt, &resultstr, 0x16ui64);
  if ( v6 && v5 )
  {
    v9 = -1i64;
    if ( v5 != -1i64 )
      v9 = v5 - (flt.sign == 45);
    result = fptostr(&v6[flt.sign == 45], v9, v7 + flt.decpt, &flt);
    if ( result )
      *v6 = 0;
    else
      result = cftof2_l(v6, v5, v7, &flt, 0, plocinfo);
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 22;
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
int __fastcall cftog_l(long double *pvalue, char *buf, unsigned __int64 sizeInBytes, int ndec, int caps, localeinfo_struct *plocinfo)
{
  unsigned __int64 v6; // rdi
  char *v7; // rsi
  int v8; // ebp
  int result; // eax
  int v10; // er14
  _BOOL8 v11; // rax
  unsigned __int64 v12; // rdx
  char *v13; // rbx
  char v14; // al
  _strflt flt; // [rsp+40h] [rbp-68h]
  char resultstr; // [rsp+58h] [rbp-50h]

  v6 = sizeInBytes;
  v7 = buf;
  v8 = ndec;
  fltout2(*(_CRT_DOUBLE *)pvalue, &flt, &resultstr, 0x16ui64);
  if ( v7 && v6 )
  {
    v10 = flt.decpt - 1;
    v11 = flt.sign == 45;
    v12 = -1i64;
    v13 = &v7[v11];
    if ( v6 != -1i64 )
      v12 = v6 - v11;
    result = fptostr(&v7[v11], v12, v8, &flt);
    if ( result )
    {
      *v7 = 0;
    }
    else if ( flt.decpt - 1 < -4 || flt.decpt - 1 >= v8 )
    {
      result = cftoe2_l(v7, v6, v8, caps, &flt, 1, plocinfo);
    }
    else
    {
      if ( v10 < flt.decpt - 1 )
      {
        do
          v14 = *v13++;
        while ( v14 );
        *(v13 - 2) = 0;
      }
      result = cftof2_l(v7, v6, v8, &flt, 1, plocinfo);
    }
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 22;
  }
  return result;
}

// File Line: 966
// RVA: 0x12C5A78
int __fastcall cfltcvt_l(long double *arg, char *buffer, unsigned __int64 sizeInBytes, int format, int precision, int caps, localeinfo_struct *plocinfo)
{
  if ( !((format - 69) & 0xFFFFFFDF) )
    return cftoe_l(arg, buffer, sizeInBytes, precision, caps, plocinfo);
  if ( format == 102 )
    return cftof_l(arg, buffer, sizeInBytes, precision, plocinfo);
  if ( (format - 65) & 0xFFFFFFDF )
    return cftog_l(arg, buffer, sizeInBytes, precision, caps, plocinfo);
  return cftoa_l(arg, buffer, sizeInBytes, precision, caps, plocinfo);
}

// File Line: 982
// RVA: 0x12C5A54
int __fastcall cfltcvt(long double *arg, char *buffer, unsigned __int64 sizeInBytes, int format, int precision, int caps)
{
  return cfltcvt_l(arg, buffer, sizeInBytes, format, precision, caps, 0i64);
}


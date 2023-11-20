// File Line: 80
// RVA: 0x12B22C8
__int64 __fastcall strtoxl(localeinfo_struct *plocinfo, const char *nptr, const char **endptr, int ibase, int flags)
{
  const char *v5; // r12
  unsigned int v6; // er14
  const char **v7; // r15
  unsigned __int8 v8; // si
  threadlocaleinfostruct *v9; // r8
  unsigned int v10; // edi
  unsigned __int8 *i; // rbx
  int v12; // eax
  int v13; // ebp
  const unsigned __int16 *v14; // r10
  unsigned int v15; // er9
  unsigned int v16; // ecx
  int v17; // ecx
  signed __int64 v18; // rbx
  _LocaleUpdate v20; // [rsp+20h] [rbp-48h]

  v5 = nptr;
  v6 = ibase;
  v7 = endptr;
  _LocaleUpdate::_LocaleUpdate(&v20, plocinfo);
  if ( v7 )
    *v7 = v5;
  if ( !v5 || v6 && v6 - 2 > 0x22 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
LABEL_21:
    v10 = 0;
    goto LABEL_63;
  }
  v8 = *v5;
  v9 = v20.localeinfo.locinfo;
  v10 = 0;
  for ( i = (unsigned __int8 *)(v5 + 1); ; ++i )
  {
    if ( v9->mb_cur_max <= 1 )
    {
      v12 = v9->pctype[v8] & 8;
    }
    else
    {
      v12 = isctype_l(v8, 8, &v20.localeinfo);
      v9 = v20.localeinfo.locinfo;
    }
    if ( !v12 )
      break;
    v8 = *i;
  }
  v13 = flags;
  if ( v8 == 45 )
  {
    v13 = flags | 2;
LABEL_16:
    v8 = *i++;
    goto LABEL_17;
  }
  if ( v8 == 43 )
    goto LABEL_16;
  if ( !v6 )
    goto LABEL_68;
LABEL_17:
  if ( v6 - 2 > 0x22 )
  {
    if ( v7 )
      *v7 = v5;
    goto LABEL_21;
  }
  if ( v6 )
  {
    if ( v6 != 16 || v8 != 48 )
      goto LABEL_32;
  }
  else
  {
LABEL_68:
    if ( v8 != 48 )
    {
      v6 = 10;
      goto LABEL_32;
    }
    if ( (*i - 88) & 0xDF )
    {
      v6 = 8;
      goto LABEL_32;
    }
    v6 = 16;
  }
  if ( !((*i - 88) & 0xDF) )
  {
    v8 = i[1];
    i += 2;
  }
LABEL_32:
  v14 = v9->pctype;
  v15 = 0xFFFFFFFF / v6;
  while ( 1 )
  {
    if ( v14[v8] & 4 )
    {
      v16 = (char)v8 - 48;
    }
    else
    {
      if ( !(v14[v8] & 0x103) )
        break;
      v17 = (char)v8;
      if ( (unsigned __int8)(v8 - 97) <= 0x19u )
        v17 = (char)v8 - 32;
      v16 = v17 - 55;
    }
    if ( v16 >= v6 )
      break;
    v13 |= 8u;
    if ( v10 < v15 || v10 == v15 && v16 <= 0xFFFFFFFF % v6 )
    {
      v10 = v16 + v6 * v10;
    }
    else
    {
      v13 |= 4u;
      if ( !v7 )
        break;
    }
    v8 = *i++;
  }
  v18 = (signed __int64)(i - 1);
  if ( v13 & 8 )
  {
    if ( v13 & 4 || !(v13 & 1) && (v13 & 2 && v10 > 0x80000000 || !(v13 & 2) && v10 > 0x7FFFFFFF) )
    {
      *errno() = 34;
      if ( v13 & 1 )
        v10 = -1;
      else
        v10 = ((v13 & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( v7 )
      v18 = (signed __int64)v5;
    v10 = 0;
  }
  if ( v7 )
    *v7 = (const char *)v18;
  if ( v13 & 2 )
    v10 = -v10;
LABEL_63:
  if ( v20.updated )
    v20.ptd->_ownlocale &= 0xFFFFFFFD;
  return v10;
}

// File Line: 229
// RVA: 0x12B2504
__int64 __fastcall strtol(const char *nptr, char **endptr, int ibase)
{
  int v3; // er9
  char **v4; // r8
  const char *v5; // rdx
  localeinfo_struct *v6; // rcx

  v3 = ibase;
  v4 = endptr;
  v5 = nptr;
  if ( _locale_changed )
    v6 = 0i64;
  else
    v6 = &_initiallocalestructinfo;
  return strtoxl(v6, v5, (const char **)v4, v3, 0);
}

// File Line: 255
// RVA: 0x12B2534
__int64 __fastcall strtoul(const char *nptr, char **endptr, int ibase)
{
  int v3; // er9
  char **v4; // r8
  const char *v5; // rdx
  localeinfo_struct *v6; // rcx

  v3 = ibase;
  v4 = endptr;
  v5 = nptr;
  if ( _locale_changed )
    v6 = 0i64;
  else
    v6 = &_initiallocalestructinfo;
  return strtoxl(v6, v5, (const char **)v4, v3, 1);
}


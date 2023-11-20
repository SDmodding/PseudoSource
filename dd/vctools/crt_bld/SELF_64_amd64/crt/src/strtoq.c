// File Line: 83
// RVA: 0x12B8D98
unsigned __int64 __fastcall strtoxq(localeinfo_struct *plocinfo, const char *nptr, const char **endptr, int ibase, int flags)
{
  const char *v5; // r12
  int v6; // er14
  const char **v7; // r15
  unsigned __int64 v8; // rdi
  unsigned __int8 v9; // si
  threadlocaleinfostruct *v10; // r8
  unsigned __int8 *i; // rbx
  int v12; // eax
  int v13; // ebp
  const unsigned __int16 *v14; // r13
  unsigned __int64 v15; // r9
  unsigned int v16; // edx
  int v17; // edx
  signed __int64 v18; // rbx
  localeinfo_struct plocinfoa; // [rsp+20h] [rbp-48h]
  __int64 v21; // [rsp+30h] [rbp-38h]
  char v22; // [rsp+38h] [rbp-30h]

  v5 = nptr;
  v6 = ibase;
  v7 = endptr;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&plocinfoa, plocinfo);
  if ( v7 )
    *v7 = v5;
  if ( !v5 || v6 && (unsigned int)(v6 - 2) > 0x22 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    v8 = 0i64;
    goto LABEL_58;
  }
  v9 = *v5;
  v10 = plocinfoa.locinfo;
  v8 = 0i64;
  for ( i = (unsigned __int8 *)(v5 + 1); ; ++i )
  {
    if ( v10->mb_cur_max <= 1 )
    {
      v12 = v10->pctype[v9] & 8;
    }
    else
    {
      v12 = isctype_l(v9, 8, &plocinfoa);
      v10 = plocinfoa.locinfo;
    }
    if ( !v12 )
      break;
    v9 = *i;
  }
  v13 = flags;
  if ( v9 == 45 )
  {
    v13 = flags | 2;
  }
  else if ( v9 != 43 )
  {
    goto LABEL_17;
  }
  v9 = *i++;
LABEL_17:
  if ( !v6 )
  {
    if ( v9 != 48 )
    {
      v6 = 10;
      goto LABEL_27;
    }
    if ( (*i - 88) & 0xDF )
    {
      v6 = 8;
      goto LABEL_27;
    }
    v6 = 16;
  }
  if ( v6 == 16 && v9 == 48 && !((*i - 88) & 0xDF) )
  {
    v9 = i[1];
    i += 2;
  }
LABEL_27:
  v14 = v10->pctype;
  v15 = 0xFFFFFFFFFFFFFFFFui64 / v6;
  while ( 1 )
  {
    if ( v14[v9] & 4 )
    {
      v16 = (char)v9 - 48;
    }
    else
    {
      if ( !(v14[v9] & 0x103) )
        break;
      v17 = (char)v9;
      if ( (unsigned __int8)(v9 - 97) <= 0x19u )
        v17 = (char)v9 - 32;
      v16 = v17 - 55;
    }
    if ( v16 >= v6 )
      break;
    v13 |= 8u;
    if ( v8 < v15 || v8 == v15 && v16 <= 0xFFFFFFFFFFFFFFFFui64 % v6 )
    {
      v8 = v8 * v6 + v16;
    }
    else
    {
      v13 |= 4u;
      if ( !v7 )
        break;
    }
    v9 = *i++;
  }
  v18 = (signed __int64)(i - 1);
  if ( v13 & 8 )
  {
    if ( v13 & 4 || !(v13 & 1) && (v13 & 2 && v8 > 0x8000000000000000ui64 || !(v13 & 2) && v8 > 0x7FFFFFFFFFFFFFFFi64) )
    {
      *errno() = 34;
      if ( v13 & 1 )
        v8 = -1i64;
      else
        v8 = ((v13 & 2) != 0) + 0x7FFFFFFFFFFFFFFFi64;
    }
  }
  else
  {
    if ( v7 )
      v18 = (signed __int64)v5;
    v8 = 0i64;
  }
  if ( v7 )
    *v7 = (const char *)v18;
  if ( v13 & 2 )
    v8 = -(signed __int64)v8;
LABEL_58:
  if ( v22 )
    *(_DWORD *)(v21 + 200) &= 0xFFFFFFFD;
  return v8;
}

// File Line: 214
// RVA: 0x12B8FE8
unsigned __int64 __fastcall strtoi64(const char *nptr, char **endptr, int ibase)
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
  return strtoxq(v6, v5, (const char **)v4, v3, 0);
}

// File Line: 239
// RVA: 0x12B9018
unsigned __int64 __fastcall strtoui64(const char *nptr, char **endptr, int ibase)
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
  return strtoxq(v6, v5, (const char **)v4, v3, 1);
}


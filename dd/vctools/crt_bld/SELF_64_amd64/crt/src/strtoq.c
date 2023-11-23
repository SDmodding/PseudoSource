// File Line: 83
// RVA: 0x12B8D98
unsigned __int64 __fastcall strtoxq(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        unsigned int ibase,
        int flags)
{
  unsigned __int64 v8; // rdi
  unsigned __int8 v9; // si
  threadlocaleinfostruct *locinfo; // r8
  const char *i; // rbx
  int v12; // eax
  int v13; // ebp
  const unsigned __int16 *pctype; // r13
  unsigned __int64 v15; // r9
  unsigned int v16; // edx
  int v17; // edx
  const char *v18; // rbx
  _LocaleUpdate plocinfoa; // [rsp+20h] [rbp-48h] BYREF

  _LocaleUpdate::_LocaleUpdate(&plocinfoa, plocinfo);
  if ( endptr )
    *endptr = nptr;
  if ( !nptr || ibase && ibase - 2 > 0x22 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    v8 = 0i64;
    goto LABEL_58;
  }
  v9 = *nptr;
  locinfo = plocinfoa.localeinfo.locinfo;
  v8 = 0i64;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v12 = locinfo->pctype[v9] & 8;
    }
    else
    {
      v12 = isctype_l(v9, 8, &plocinfoa.localeinfo);
      locinfo = plocinfoa.localeinfo.locinfo;
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
  if ( !ibase )
  {
    if ( v9 != 48 )
    {
      ibase = 10;
      goto LABEL_27;
    }
    if ( ((*i - 88) & 0xDF) != 0 )
    {
      ibase = 8;
      goto LABEL_27;
    }
    ibase = 16;
  }
  if ( ibase == 16 && v9 == 48 && ((*i - 88) & 0xDF) == 0 )
  {
    v9 = i[1];
    i += 2;
  }
LABEL_27:
  pctype = locinfo->pctype;
  v15 = 0xFFFFFFFFFFFFFFFFui64 / (int)ibase;
  while ( 1 )
  {
    if ( (pctype[v9] & 4) != 0 )
    {
      v16 = (char)v9 - 48;
    }
    else
    {
      if ( (pctype[v9] & 0x103) == 0 )
        break;
      v17 = (char)v9;
      if ( (unsigned __int8)(v9 - 97) <= 0x19u )
        v17 = (char)v9 - 32;
      v16 = v17 - 55;
    }
    if ( v16 >= ibase )
      break;
    v13 |= 8u;
    if ( v8 < v15 || v8 == v15 && v16 <= 0xFFFFFFFFFFFFFFFFui64 % (int)ibase )
    {
      v8 = v8 * (int)ibase + v16;
    }
    else
    {
      v13 |= 4u;
      if ( !endptr )
        break;
    }
    v9 = *i++;
  }
  v18 = i - 1;
  if ( (v13 & 8) != 0 )
  {
    if ( (v13 & 4) != 0
      || (v13 & 1) == 0
      && ((v13 & 2) != 0 && v8 > 0x8000000000000000ui64 || (v13 & 2) == 0 && v8 > 0x7FFFFFFFFFFFFFFFi64) )
    {
      *errno() = 34;
      if ( (v13 & 1) != 0 )
        v8 = -1i64;
      else
        v8 = ((v13 & 2) != 0) + 0x7FFFFFFFFFFFFFFFi64;
    }
  }
  else
  {
    if ( endptr )
      v18 = nptr;
    v8 = 0i64;
  }
  if ( endptr )
    *endptr = v18;
  if ( (v13 & 2) != 0 )
    v8 = -(__int64)v8;
LABEL_58:
  if ( plocinfoa.updated )
    plocinfoa.ptd->_ownlocale &= ~2u;
  return v8;
}

// File Line: 214
// RVA: 0x12B8FE8
unsigned __int64 __fastcall strtoi64(const char *nptr, const char **endptr, unsigned int ibase)
{
  localeinfo_struct *v6; // rcx

  if ( _locale_changed )
    v6 = 0i64;
  else
    v6 = &_initiallocalestructinfo;
  return strtoxq(v6, nptr, endptr, ibase, 0);
}

// File Line: 239
// RVA: 0x12B9018
unsigned __int64 __fastcall strtoui64(const char *nptr, const char **endptr, unsigned int ibase)
{
  localeinfo_struct *v6; // rcx

  if ( _locale_changed )
    v6 = 0i64;
  else
    v6 = &_initiallocalestructinfo;
  return strtoxq(v6, nptr, endptr, ibase, 1);
}


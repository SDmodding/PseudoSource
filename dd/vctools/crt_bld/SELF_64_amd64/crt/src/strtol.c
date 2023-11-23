// File Line: 80
// RVA: 0x12B22C8
__int64 __fastcall strtoxl(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        unsigned int ibase,
        int flags)
{
  unsigned __int8 v8; // si
  threadlocaleinfostruct *locinfo; // r8
  unsigned int v10; // edi
  const char *i; // rbx
  int v12; // eax
  int v13; // ebp
  const unsigned __int16 *pctype; // r10
  unsigned int v15; // r9d
  unsigned int v16; // ecx
  int v17; // ecx
  const char *v18; // rbx
  _LocaleUpdate v20; // [rsp+20h] [rbp-48h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v20, plocinfo);
  if ( endptr )
    *endptr = nptr;
  if ( !nptr || ibase && ibase - 2 > 0x22 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
LABEL_21:
    v10 = 0;
    goto LABEL_63;
  }
  v8 = *nptr;
  locinfo = v20.localeinfo.locinfo;
  v10 = 0;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v12 = locinfo->pctype[v8] & 8;
    }
    else
    {
      v12 = isctype_l(v8, 8, &v20.localeinfo);
      locinfo = v20.localeinfo.locinfo;
    }
    if ( !v12 )
      break;
    v8 = *i;
  }
  v13 = flags;
  if ( v8 == 45 )
  {
    v13 = flags | 2;
  }
  else if ( v8 != 43 )
  {
    goto LABEL_17;
  }
  v8 = *i++;
LABEL_17:
  if ( !ibase )
  {
    if ( v8 != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( ((*i - 88) & 0xDF) != 0 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
    goto LABEL_30;
  }
  if ( ibase - 2 > 0x22 )
  {
    if ( endptr )
      *endptr = nptr;
    goto LABEL_21;
  }
  if ( ibase == 16 && v8 == 48 )
  {
LABEL_30:
    if ( ((*i - 88) & 0xDF) == 0 )
    {
      v8 = i[1];
      i += 2;
    }
  }
LABEL_32:
  pctype = locinfo->pctype;
  v15 = 0xFFFFFFFF / ibase;
  while ( 1 )
  {
    if ( (pctype[v8] & 4) != 0 )
    {
      v16 = (char)v8 - 48;
    }
    else
    {
      if ( (pctype[v8] & 0x103) == 0 )
        break;
      v17 = (char)v8;
      if ( (unsigned __int8)(v8 - 97) <= 0x19u )
        v17 = (char)v8 - 32;
      v16 = v17 - 55;
    }
    if ( v16 >= ibase )
      break;
    v13 |= 8u;
    if ( v10 < v15 || v10 == v15 && v16 <= 0xFFFFFFFF % ibase )
    {
      v10 = v16 + ibase * v10;
    }
    else
    {
      v13 |= 4u;
      if ( !endptr )
        break;
    }
    v8 = *i++;
  }
  v18 = i - 1;
  if ( (v13 & 8) != 0 )
  {
    if ( (v13 & 4) != 0 || (v13 & 1) == 0 && ((v13 & 2) != 0 && v10 > 0x80000000 || (v13 & 2) == 0 && v10 > 0x7FFFFFFF) )
    {
      *errno() = 34;
      if ( (v13 & 1) != 0 )
        v10 = -1;
      else
        v10 = ((v13 & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr )
      v18 = nptr;
    v10 = 0;
  }
  if ( endptr )
    *endptr = v18;
  if ( (v13 & 2) != 0 )
    v10 = -v10;
LABEL_63:
  if ( v20.updated )
    v20.ptd->_ownlocale &= ~2u;
  return v10;
}

// File Line: 229
// RVA: 0x12B2504
__int64 __fastcall strtol(const char *nptr, const char **endptr, unsigned int ibase)
{
  localeinfo_struct *v6; // rcx

  if ( _locale_changed )
    v6 = 0i64;
  else
    v6 = &_initiallocalestructinfo;
  return strtoxl(v6, nptr, endptr, ibase, 0);
}

// File Line: 255
// RVA: 0x12B2534
__int64 __fastcall strtoul(const char *nptr, const char **endptr, unsigned int ibase)
{
  localeinfo_struct *v6; // rcx

  if ( _locale_changed )
    v6 = 0i64;
  else
    v6 = &_initiallocalestructinfo;
  return strtoxl(v6, nptr, endptr, ibase, 1);
}


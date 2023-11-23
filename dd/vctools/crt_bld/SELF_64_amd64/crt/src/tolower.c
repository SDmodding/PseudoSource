// File Line: 70
// RVA: 0x12BB0A8
__int64 __fastcall tolower_l(int c, localeinfo_struct *plocinfo)
{
  __int64 v2; // rdi
  threadlocaleinfostruct *locinfo; // rdx
  int v4; // eax
  __int64 result; // rax
  int cchSrc; // ecx
  int *v7; // rax
  int v8; // eax
  bool v9; // zf
  _LocaleUpdate v10; // [rsp+50h] [rbp-20h] BYREF
  char SrcStr; // [rsp+80h] [rbp+10h] BYREF
  char v12; // [rsp+81h] [rbp+11h]
  char v13; // [rsp+82h] [rbp+12h]
  char DestStr; // [rsp+90h] [rbp+20h] BYREF
  unsigned __int8 v15; // [rsp+91h] [rbp+21h]

  v2 = c;
  _LocaleUpdate::_LocaleUpdate(&v10, plocinfo);
  if ( (unsigned int)v2 >= 0x100 )
  {
    if ( v10.localeinfo.locinfo->mb_cur_max > 1 && isleadbyte_l(BYTE1(v2), &v10.localeinfo) )
    {
      SrcStr = BYTE1(v2);
      v12 = v2;
      v13 = 0;
      cchSrc = 2;
    }
    else
    {
      v7 = errno();
      cchSrc = 1;
      *v7 = 42;
      SrcStr = v2;
      v12 = 0;
    }
    v8 = _crtLCMapStringA(
           &v10.localeinfo,
           v10.localeinfo.locinfo->locale_name[2],
           0x100u,
           &SrcStr,
           cchSrc,
           &DestStr,
           3,
           v10.localeinfo.locinfo->lc_codepage,
           1);
    if ( v8 )
    {
      v9 = v8 == 1;
      result = (unsigned __int8)DestStr;
      if ( !v9 )
        result = v15 | ((unsigned __int8)DestStr << 8);
      goto LABEL_17;
    }
  }
  else
  {
    locinfo = v10.localeinfo.locinfo;
    if ( v10.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = v10.localeinfo.locinfo->pctype[v2] & 1;
    }
    else
    {
      v4 = isctype_l(v2, 1, &v10.localeinfo);
      locinfo = v10.localeinfo.locinfo;
    }
    if ( v4 )
    {
      result = (unsigned __int8)locinfo->pclmap[v2];
LABEL_17:
      if ( v10.updated )
        v10.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( v10.updated )
    v10.ptd->_ownlocale &= ~2u;
  return (unsigned int)v2;
}

// File Line: 143
// RVA: 0x12BB1FC
__int64 __fastcall tolower_0(unsigned int c)
{
  if ( _locale_changed )
    return tolower_l(c, 0i64);
  if ( c - 65 <= 0x19 )
    c += 32;
  return c;
}


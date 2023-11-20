// File Line: 70
// RVA: 0x12BB0A8
__int64 __fastcall tolower_l(int c, localeinfo_struct *plocinfo)
{
  __int64 v2; // rdi
  threadlocaleinfostruct *v3; // rdx
  int v4; // eax
  __int64 result; // rax
  signed int v6; // er14
  int cchSrc; // ecx
  int *v8; // rax
  int v9; // eax
  bool v10; // zf
  _LocaleUpdate v11; // [rsp+50h] [rbp-20h]
  char SrcStr; // [rsp+80h] [rbp+10h]
  char v13; // [rsp+81h] [rbp+11h]
  char v14; // [rsp+82h] [rbp+12h]
  char DestStr; // [rsp+90h] [rbp+20h]
  unsigned __int8 v16; // [rsp+91h] [rbp+21h]

  v2 = c;
  _LocaleUpdate::_LocaleUpdate(&v11, plocinfo);
  if ( (unsigned int)v2 >= 0x100 )
  {
    if ( v11.localeinfo.locinfo->mb_cur_max > 1 && (v6 = (signed int)v2 >> 8, isleadbyte_l(BYTE1(v2), &v11.localeinfo)) )
    {
      SrcStr = v6;
      v13 = v2;
      v14 = 0;
      cchSrc = 2;
    }
    else
    {
      v8 = errno();
      cchSrc = 1;
      *v8 = 42;
      SrcStr = v2;
      v13 = 0;
    }
    v9 = _crtLCMapStringA(
           &v11.localeinfo,
           v11.localeinfo.locinfo->locale_name[2],
           0x100u,
           &SrcStr,
           cchSrc,
           &DestStr,
           3,
           v11.localeinfo.locinfo->lc_codepage,
           1);
    if ( v9 )
    {
      v10 = v9 == 1;
      result = (unsigned __int8)DestStr;
      if ( !v10 )
        result = (unsigned int)v16 | ((_DWORD)result << 8);
      goto LABEL_17;
    }
  }
  else
  {
    v3 = v11.localeinfo.locinfo;
    if ( v11.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = v11.localeinfo.locinfo->pctype[v2] & 1;
    }
    else
    {
      v4 = isctype_l(v2, 1, &v11.localeinfo);
      v3 = v11.localeinfo.locinfo;
    }
    if ( v4 )
    {
      result = (unsigned __int8)v3->pclmap[v2];
LABEL_17:
      if ( v11.updated )
        v11.ptd->_ownlocale &= 0xFFFFFFFD;
      return result;
    }
  }
  if ( v11.updated )
    v11.ptd->_ownlocale &= 0xFFFFFFFD;
  return (unsigned int)v2;
}

// File Line: 143
// RVA: 0x12BB1FC
__int64 __fastcall tolower_0(int c)
{
  if ( _locale_changed )
    return tolower_l(c, 0i64);
  if ( (unsigned int)(c - 65) <= 0x19 )
    c += 32;
  return (unsigned int)c;
}


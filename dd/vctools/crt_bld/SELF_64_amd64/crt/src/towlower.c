// File Line: 37
// RVA: 0x12C1450
__int64 __fastcall towlower_l(wchar_t c, localeinfo_struct *plocinfo)
{
  __int64 result; // rax
  threadlocaleinfostruct *locinfo; // rbx
  const wchar_t *v4; // rax
  wchar_t v5; // dx
  int v6; // eax
  _LocaleUpdate v7; // [rsp+30h] [rbp-20h] BYREF
  wchar_t SrcStr; // [rsp+60h] [rbp+10h] BYREF
  wchar_t DestStr; // [rsp+70h] [rbp+20h] BYREF

  SrcStr = c;
  result = 0xFFFFi64;
  if ( c != 0xFFFF )
  {
    _LocaleUpdate::_LocaleUpdate(&v7, plocinfo);
    locinfo = v7.localeinfo.locinfo;
    v4 = v7.localeinfo.locinfo->locale_name[2];
    if ( v4 )
    {
      if ( SrcStr >= 0x100u )
      {
        v6 = _crtLCMapStringW(v4, 0x100u, &SrcStr, 1, &DestStr, 1);
        v5 = SrcStr;
        if ( v6 )
          v5 = DestStr;
      }
      else if ( iswctype(SrcStr, 1u) )
      {
        v5 = (unsigned __int8)locinfo->pclmap[SrcStr];
      }
      else
      {
        v5 = SrcStr;
      }
    }
    else
    {
      v5 = SrcStr;
      if ( (unsigned __int16)(SrcStr - 65) <= 0x19u )
        v5 = SrcStr + 32;
    }
    if ( v7.updated )
      v7.ptd->_ownlocale &= ~2u;
    return v5;
  }
  return result;
}

// File Line: 94
// RVA: 0x12C151C
__int64 __fastcall towlower(wchar_t c)
{
  return towlower_l(c, 0i64);
}


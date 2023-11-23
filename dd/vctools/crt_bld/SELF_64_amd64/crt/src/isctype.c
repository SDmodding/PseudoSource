// File Line: 114
// RVA: 0x12C9ABC
__int64 __fastcall isctype_l(int c, unsigned int mask, localeinfo_struct *plocinfo)
{
  __int64 v3; // rdi
  int v5; // eax
  int v6; // r9d
  __int64 result; // rax
  _LocaleUpdate v8; // [rsp+40h] [rbp-20h] BYREF
  unsigned __int16 CharType; // [rsp+80h] [rbp+20h] BYREF
  char SrcStr; // [rsp+98h] [rbp+38h] BYREF
  char v11; // [rsp+99h] [rbp+39h]
  char v12; // [rsp+9Ah] [rbp+3Ah]

  v3 = c;
  _LocaleUpdate::_LocaleUpdate(&v8, plocinfo);
  if ( (unsigned int)(v3 + 1) <= 0x100 )
  {
    v5 = v8.localeinfo.locinfo->pctype[v3];
    goto LABEL_11;
  }
  if ( (unsigned int)isleadbyte_l(BYTE1(v3), &v8.localeinfo) )
  {
    SrcStr = BYTE1(v3);
    v11 = v3;
    v12 = 0;
    v6 = 2;
  }
  else
  {
    SrcStr = v3;
    v11 = 0;
    v6 = 1;
  }
  if ( _crtGetStringTypeA(&v8.localeinfo, 1u, &SrcStr, v6, &CharType, v8.localeinfo.locinfo->lc_codepage, 1) )
  {
    v5 = CharType;
LABEL_11:
    result = mask & v5;
    if ( v8.updated )
      v8.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( v8.updated )
    v8.ptd->_ownlocale &= ~2u;
  return 0i64;
}


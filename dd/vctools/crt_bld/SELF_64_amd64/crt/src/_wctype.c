// File Line: 55
// RVA: 0x12C1258
__int64 __fastcall isleadbyte_l(int c, localeinfo_struct *plocinfo)
{
  unsigned __int8 v2; // bl
  __int64 result; // rax
  _LocaleUpdate v4; // [rsp+20h] [rbp-28h]

  v2 = c;
  _LocaleUpdate::_LocaleUpdate(&v4, plocinfo);
  result = v4.localeinfo.locinfo->pctype[v2] & 0x8000;
  if ( v4.updated )
    v4.ptd->_ownlocale &= 0xFFFFFFFD;
  return result;
}

// File Line: 63
// RVA: 0x12C129C
__int64 __fastcall isleadbyte(int c)
{
  unsigned __int8 v1; // bl
  __int64 result; // rax
  _LocaleUpdate v3; // [rsp+20h] [rbp-28h]

  v1 = c;
  _LocaleUpdate::_LocaleUpdate(&v3, 0i64);
  result = v3.localeinfo.locinfo->pctype[v1] & 0x8000;
  if ( v3.updated )
    v3.ptd->_ownlocale &= 0xFFFFFFFD;
  return result;
}

// File Line: 78
// RVA: 0x12C12F0
int __fastcall iswalpha(unsigned __int16 c)
{
  return iswctype(c, 0x103u);
}

// File Line: 93
// RVA: 0x12C1360
int __fastcall iswupper(unsigned __int16 c)
{
  return iswctype(c, 1u);
}

// File Line: 108
// RVA: 0x12C1330
int __fastcall iswlower(unsigned __int16 c)
{
  return iswctype(c, 2u);
}

// File Line: 123
// RVA: 0x12C1318
int __fastcall iswdigit(unsigned __int16 c)
{
  return iswctype(c, 4u);
}

// File Line: 138
// RVA: 0x12C136C
int __fastcall iswxdigit(unsigned __int16 c)
{
  return iswctype(c, 0x80u);
}

// File Line: 153
// RVA: 0x12C1354
int __fastcall iswspace(unsigned __int16 c)
{
  return iswctype(c, 8u);
}

// File Line: 168
// RVA: 0x12C1348
int __fastcall iswpunct(unsigned __int16 c)
{
  return iswctype(c, 0x10u);
}

// File Line: 183
// RVA: 0x12C12E4
int __fastcall iswalnum(unsigned __int16 c)
{
  return iswctype(c, 0x107u);
}

// File Line: 198
// RVA: 0x12C133C
int __fastcall iswprint(unsigned __int16 c)
{
  return iswctype(c, 0x157u);
}

// File Line: 213
// RVA: 0x12C1324
int __fastcall iswgraph(unsigned __int16 c)
{
  return iswctype(c, 0x117u);
}

// File Line: 228
// RVA: 0x12C130C
int __fastcall iswcntrl(unsigned __int16 c)
{
  return iswctype(c, 0x20u);
}

// File Line: 235
// RVA: 0x12C12FC
_BOOL8 __fastcall iswascii(unsigned __int16 c)
{
  return c < 0x80u;
}


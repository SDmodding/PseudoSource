// File Line: 171
// RVA: 0x12D08C0
signed __int64 __fastcall ismbblead(unsigned int tst)
{
  return x_ismbbtype_l(0i64, tst, 0, 4);
}

// File Line: 213
// RVA: 0x12D0844
signed __int64 __fastcall x_ismbbtype_l(localeinfo_struct *plocinfo, unsigned int tst, int cmask, int kmask)
{
  unsigned __int8 v4; // bl
  unsigned __int8 v5; // di
  int v6; // esi
  signed __int64 result; // rax
  _LocaleUpdate v8; // [rsp+20h] [rbp-28h]

  v4 = tst;
  v5 = kmask;
  v6 = cmask;
  _LocaleUpdate::_LocaleUpdate(&v8, plocinfo);
  if ( v5 & v8.localeinfo.mbcinfo->mbctype[v4 + 1]
    || (!v6 ? (result = 0i64) : (result = (unsigned __int16)(v6 & v8.localeinfo.locinfo->pctype[v4])), (_DWORD)result) )
  {
    result = 1i64;
  }
  if ( v8.updated )
    v8.ptd->_ownlocale &= 0xFFFFFFFD;
  return result;
}


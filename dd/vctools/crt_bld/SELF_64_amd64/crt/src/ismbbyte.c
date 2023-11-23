// File Line: 171
// RVA: 0x12D08C0
__int64 __fastcall ismbblead(unsigned __int8 tst)
{
  return x_ismbbtype_l(0i64, tst, 0, 4u);
}

// File Line: 213
// RVA: 0x12D0844
__int64 __fastcall x_ismbbtype_l(localeinfo_struct *plocinfo, unsigned __int8 tst, int cmask, unsigned __int8 kmask)
{
  __int64 result; // rax
  _LocaleUpdate v8; // [rsp+20h] [rbp-28h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v8, plocinfo);
  if ( (kmask & v8.localeinfo.mbcinfo->mbctype[tst + 1]) != 0
    || (!cmask ? (result = 0i64) : (result = (unsigned __int16)(cmask & v8.localeinfo.locinfo->pctype[tst])),
        (_DWORD)result) )
  {
    result = 1i64;
  }
  if ( v8.updated )
    v8.ptd->_ownlocale &= ~2u;
  return result;
}


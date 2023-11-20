// File Line: 230
// RVA: 0x12B018C
void __fastcall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, localeinfo_struct *plocinfo)
{
  _LocaleUpdate *v2; // rbx
  _tiddata *v3; // rax
  threadlocaleinfostruct *v4; // rdx
  _tiddata *v5; // rcx
  int v6; // eax

  v2 = this;
  this->updated = 0;
  if ( plocinfo )
  {
    _mm_storeu_si128((__m128i *)this, *(__m128i *)plocinfo);
  }
  else
  {
    v3 = getptd();
    v2->ptd = v3;
    v4 = v3->ptlocinfo;
    v2->localeinfo.locinfo = v4;
    v2->localeinfo.mbcinfo = v3->ptmbcinfo;
    if ( v4 != _ptlocinfo && !(v3->_ownlocale & _globallocalestatus) )
      v2->localeinfo.locinfo = _updatetlocinfo();
    if ( v2->localeinfo.mbcinfo != _ptmbcinfo && !(v2->ptd->_ownlocale & _globallocalestatus) )
      v2->localeinfo.mbcinfo = _updatetmbcinfo();
    v5 = v2->ptd;
    v6 = v5->_ownlocale;
    if ( !(v6 & 2) )
    {
      v5->_ownlocale = v6 | 2;
      v2->updated = 1;
    }
  }
}


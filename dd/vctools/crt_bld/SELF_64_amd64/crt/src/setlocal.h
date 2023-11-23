// File Line: 230
// RVA: 0x12B018C
void __fastcall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, localeinfo_struct *plocinfo)
{
  _tiddata *v3; // rax
  threadlocaleinfostruct *ptlocinfo; // rdx
  _tiddata *ptd; // rcx
  int ownlocale; // eax

  this->updated = 0;
  if ( plocinfo )
  {
    this->localeinfo = *plocinfo;
  }
  else
  {
    v3 = getptd();
    this->ptd = v3;
    ptlocinfo = v3->ptlocinfo;
    this->localeinfo.locinfo = ptlocinfo;
    this->localeinfo.mbcinfo = v3->ptmbcinfo;
    if ( ptlocinfo != _ptlocinfo && (v3->_ownlocale & _globallocalestatus) == 0 )
      this->localeinfo.locinfo = _updatetlocinfo();
    if ( this->localeinfo.mbcinfo != _ptmbcinfo && (this->ptd->_ownlocale & _globallocalestatus) == 0 )
      this->localeinfo.mbcinfo = _updatetmbcinfo();
    ptd = this->ptd;
    ownlocale = ptd->_ownlocale;
    if ( (ownlocale & 2) == 0 )
    {
      ptd->_ownlocale = ownlocale | 2;
      this->updated = 1;
    }
  }
}


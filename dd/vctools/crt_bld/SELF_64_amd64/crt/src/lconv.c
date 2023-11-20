// File Line: 79
// RVA: 0x12B1290
lconv *__fastcall localeconv()
{
  _tiddata *v0; // rax

  v0 = getptd();
  if ( v0->ptlocinfo != _ptlocinfo && !(v0->_ownlocale & _globallocalestatus) )
    _updatetlocinfo();
  return _lconv;
}


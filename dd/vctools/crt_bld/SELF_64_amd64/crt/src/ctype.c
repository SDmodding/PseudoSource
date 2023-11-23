// File Line: 29
// RVA: 0x12D6470
const unsigned __int16 *__fastcall _pctype_func()
{
  _tiddata *v0; // rax
  threadlocaleinfostruct *ptlocinfo; // rcx

  v0 = getptd();
  ptlocinfo = v0->ptlocinfo;
  if ( ptlocinfo != _ptlocinfo && (v0->_ownlocale & _globallocalestatus) == 0 )
    ptlocinfo = _updatetlocinfo();
  return ptlocinfo->pctype;
}


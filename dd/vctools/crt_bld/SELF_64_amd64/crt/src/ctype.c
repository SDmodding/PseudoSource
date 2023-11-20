// File Line: 29
// RVA: 0x12D6470
const unsigned __int16 *__fastcall _pctype_func()
{
  _tiddata *v0; // rax
  threadlocaleinfostruct *v1; // rcx

  v0 = getptd();
  v1 = v0->ptlocinfo;
  if ( v1 != _ptlocinfo && !(v0->_ownlocale & _globallocalestatus) )
    v1 = _updatetlocinfo();
  return v1->pctype;
}


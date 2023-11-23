// File Line: 40
// RVA: 0x12DE214
void __fastcall std::ios_base::_Ios_base_dtor(std::ios_base *_This)
{
  unsigned __int64 Stdstr; // rax
  std::locale *Ploc; // rbx
  std::_Facet_base *v4; // rax

  Stdstr = _This->_Stdstr;
  if ( !Stdstr || (--stdopens[Stdstr], stdopens[Stdstr] <= 0) )
  {
    std::ios_base::_Tidy(_This);
    Ploc = _This->_Ploc;
    if ( Ploc )
    {
      if ( Ploc->_Ptr )
      {
        v4 = Ploc->_Ptr->vfptr->_Decref(Ploc->_Ptr);
        if ( v4 )
          v4->vfptr->__vecDelDtor(v4, 1u);
      }
      Illusion::ShaderParam::operator delete(Ploc);
    }
  }
}

// File Line: 75
// RVA: 0x12DE1A0
void __fastcall std::ios_base::_Addstd(std::ios_base *_This)
{
  unsigned __int64 Stdstr; // rcx
  std::ios_base *v3; // rax
  std::_Lockit v4; // [rsp+30h] [rbp+8h] BYREF

  std::_Lockit::_Lockit(&v4, 2);
  _This->_Stdstr = 1i64;
  do
  {
    Stdstr = _This->_Stdstr;
    v3 = stdstr[Stdstr];
    if ( !v3 )
      break;
    if ( v3 == _This )
      break;
    _This->_Stdstr = Stdstr + 1;
  }
  while ( Stdstr + 1 < 8 );
  stdstr[_This->_Stdstr] = _This;
  ++stdopens[_This->_Stdstr];
  std::_Lockit::~_Lockit(&v4);
}


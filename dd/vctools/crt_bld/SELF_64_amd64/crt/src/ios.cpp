// File Line: 40
// RVA: 0x12DE214
void __fastcall std::ios_base::_Ios_base_dtor(std::ios_base *_This)
{
  unsigned __int64 v1; // rax
  std::ios_base *v2; // rbx
  std::locale *v3; // rbx
  void (__fastcall ***v4)(_QWORD, signed __int64); // rax

  v1 = _This->_Stdstr;
  v2 = _This;
  if ( !v1 || (--stdopens[v1], stdopens[v1] <= 0) )
  {
    std::ios_base::_Tidy(_This);
    v3 = v2->_Ploc;
    if ( v3 )
    {
      if ( v3->_Ptr )
      {
        v4 = (void (__fastcall ***)(_QWORD, signed __int64))((__int64 (*)(void))v3->_Ptr->vfptr->_Decref)();
        if ( v4 )
          (**v4)(v4, 1i64);
      }
      Illusion::ShaderParam::operator delete(v3);
    }
  }
}

// File Line: 75
// RVA: 0x12DE1A0
void __fastcall std::ios_base::_Addstd(std::ios_base *_This)
{
  std::ios_base *v1; // rbx
  unsigned __int64 v2; // rcx
  std::ios_base *v3; // rax
  std::_Lockit v4; // [rsp+30h] [rbp+8h]

  v1 = _This;
  std::_Lockit::_Lockit(&v4, 2);
  v1->_Stdstr = 1i64;
  do
  {
    v2 = v1->_Stdstr;
    v3 = stdstr[v2];
    if ( !v3 )
      break;
    if ( v3 == v1 )
      break;
    v1->_Stdstr = v2 + 1;
  }
  while ( v2 + 1 < 8 );
  stdstr[v1->_Stdstr] = v1;
  ++stdopens[v1->_Stdstr];
  std::_Lockit::~_Lockit(&v4);
}


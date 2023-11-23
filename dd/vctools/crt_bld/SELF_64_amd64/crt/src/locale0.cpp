// File Line: 48
// RVA: 0x15DEECC
__int64 std::_dynamic_initializer_for___Fac_tidy_reg__()
{
  return atexit((int (__fastcall *)())std::_dynamic_atexit_destructor_for___Fac_tidy_reg__);
}

// File Line: 55
// RVA: 0x12DDDE4
void __fastcall std::_Facet_Register(std::_Facet_base *_This)
{
  std::_Fac_node *v2; // rax
  std::_Fac_node *v3; // rdx

  v2 = (std::_Fac_node *)AMemory::malloc_default(0x10ui64);
  if ( v2 )
  {
    v3 = Fac_head;
    v2->_Facptr = _This;
    v2->_Next = v3;
  }
  Fac_head = v2;
}

// File Line: 69
// RVA: 0x12DE060
void __fastcall Deletegloballocale(__int64 *ptr)
{
  __int64 v1; // rcx
  void (__fastcall ***v2)(_QWORD, __int64); // rax

  v1 = *ptr;
  if ( v1 )
  {
    v2 = (void (__fastcall ***)(_QWORD, __int64))(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v1 + 16i64))(v1);
    if ( v2 )
      (**v2)(v2, 1i64);
  }
}

// File Line: 78
// RVA: 0x12DE08C
void __fastcall tidy_global()
{
  std::_Lockit v0; // [rsp+30h] [rbp+8h] BYREF

  std::_Lockit::_Lockit(&v0, 0);
  Deletegloballocale((__int64 *)&global_locale);
  global_locale = 0i64;
  std::_Lockit::~_Lockit(&v0);
}

// File Line: 91
// RVA: 0x12DDE18
std::locale::_Locimp *__fastcall std::locale::_Getgloballocale()
{
  return global_locale;
}

// File Line: 96
// RVA: 0x12DE02C
void __fastcall std::locale::_Setgloballocale(std::locale::_Locimp *ptr)
{
  if ( !registered )
  {
    registered = 1;
    _Atexit(tidy_global);
  }
  global_locale = ptr;
}

// File Line: 113
// RVA: 0x15DEED8
__int64 std::_dynamic_initializer_for__classic_locale__()
{
  return atexit((int (__fastcall *)())std::_dynamic_atexit_destructor_for__classic_locale__);
}

// File Line: 145
// RVA: 0x12DDE20
std::locale::_Locimp *__fastcall std::locale::_Init(bool _Do_incref)
{
  std::locale::_Locimp *v2; // rbx
  std::_Lockit v4; // [rsp+40h] [rbp+8h] BYREF

  std::_Lockit::_Lockit(&v4, 0);
  v2 = global_locale;
  if ( !global_locale )
  {
    v2 = std::locale::_Locimp::_New_Locimp(0);
    std::locale::_Setgloballocale(v2);
    v2->_Catmask = 63;
    std::_Yarn<char>::operator=(&v2->_Name, "C");
    std::locale::_Locimp::_Clocptr = v2;
    v2->vfptr->_Incref(v2);
    classic_locale._Ptr = std::locale::_Locimp::_Clocptr;
  }
  if ( _Do_incref )
    v2->vfptr->_Incref(v2);
  std::_Lockit::~_Lockit(&v4);
  return v2;
}

// File Line: 172
// RVA: 0x12DDFC0
std::locale::_Locimp *__fastcall std::locale::_Locimp::_New_Locimp(char _Transparent)
{
  char *v2; // rax
  char *v3; // rbx

  v2 = AMemory::malloc_default(0x38ui64);
  v3 = v2;
  if ( !v2 )
    return 0i64;
  *((_DWORD *)v2 + 2) = 1;
  *((_QWORD *)v2 + 2) = 0i64;
  *((_QWORD *)v2 + 3) = 0i64;
  *((_DWORD *)v2 + 8) = 0;
  v2[36] = _Transparent;
  *(_QWORD *)v2 = &std::locale::_Locimp::`vftable;
  *((_QWORD *)v2 + 5) = 0i64;
  v2[48] = 0;
  std::_Yarn<char>::operator=((std::_Yarn<char> *)(v2 + 40), pattern);
  return (std::locale::_Locimp *)v3;
}

// File Line: 182
// RVA: 0x12DDEC0
void __fastcall std::locale::_Locimp::_Locimp_dtor(std::locale::_Locimp *_This)
{
  unsigned __int64 Facetcount; // rbx
  std::locale::facet *v3; // rcx
  std::_Facet_base *v4; // rax
  std::_Lockit v5; // [rsp+40h] [rbp+8h] BYREF

  std::_Lockit::_Lockit(&v5, 0);
  Facetcount = _This->_Facetcount;
  while ( Facetcount )
  {
    v3 = _This->_Facetvec[--Facetcount];
    if ( v3 )
    {
      v4 = v3->vfptr->_Decref(v3);
      if ( v4 )
        v4->vfptr->__vecDelDtor(v4, 1u);
    }
  }
  free(_This->_Facetvec);
  std::_Lockit::~_Lockit(&v5);
}

// File Line: 192
// RVA: 0x12DDF38
void __fastcall std::_Locinfo::_Locinfo_ctor(std::_Locinfo *pLocinfo, char *locname)
{
  char *v4; // rax

  v4 = setlocale(0, 0i64);
  if ( !v4 )
    v4 = &customCaption;
  std::_Yarn<char>::operator=(&pLocinfo->_Oldlocname, v4);
  if ( locname )
    locname = setlocale(0, locname);
  if ( !locname )
    locname = pattern;
  std::_Yarn<char>::operator=(&pLocinfo->_Newlocname, locname);
}

// File Line: 202
// RVA: 0x12DDFA4
void __fastcall std::_Locinfo::_Locinfo_dtor(std::_Locinfo *pLocinfo)
{
  char *Myptr; // rdx

  Myptr = pLocinfo->_Oldlocname._Myptr;
  if ( Myptr )
    setlocale(0, Myptr);
}


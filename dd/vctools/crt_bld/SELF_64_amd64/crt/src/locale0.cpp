// File Line: 48
// RVA: 0x15DEECC
__int64 std::_dynamic_initializer_for___Fac_tidy_reg__()
{
  return atexit((void (__fastcall *)())std::_dynamic_atexit_destructor_for___Fac_tidy_reg__);
}

// File Line: 55
// RVA: 0x12DDDE4
void __fastcall std::_Facet_Register(std::_Facet_base *_This)
{
  std::_Facet_base *v1; // rbx
  std::_Fac_node *v2; // rax
  std::_Fac_node *v3; // rdx

  v1 = _This;
  v2 = (std::_Fac_node *)AMemory::malloc_default(0x10ui64);
  if ( v2 )
  {
    v3 = Fac_head;
    v2->_Facptr = v1;
    v2->_Next = v3;
  }
  Fac_head = v2;
}

// File Line: 69
// RVA: 0x12DE060
void __fastcall Deletegloballocale(void *ptr)
{
  __int64 v1; // rcx
  void (__fastcall ***v2)(_QWORD, signed __int64); // rax

  v1 = *(_QWORD *)ptr;
  if ( v1 )
  {
    v2 = (void (__fastcall ***)(_QWORD, signed __int64))(*(__int64 (**)(void))(*(_QWORD *)v1 + 16i64))();
    if ( v2 )
      (**v2)(v2, 1i64);
  }
}

// File Line: 78
// RVA: 0x12DE08C
void __fastcall tidy_global()
{
  std::_Lockit v0; // [rsp+30h] [rbp+8h]

  std::_Lockit::_Lockit(&v0, 0);
  Deletegloballocale(&global_locale);
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
void __fastcall std::locale::_Setgloballocale(void *ptr)
{
  std::locale::_Locimp *v1; // rbx

  v1 = (std::locale::_Locimp *)ptr;
  if ( !registered )
  {
    registered = 1;
    _Atexit(tidy_global);
  }
  global_locale = v1;
}

// File Line: 113
// RVA: 0x15DEED8
__int64 std::_dynamic_initializer_for__classic_locale__()
{
  return atexit((void (__fastcall *)())std::_dynamic_atexit_destructor_for__classic_locale__);
}

// File Line: 145
// RVA: 0x12DDE20
std::locale::_Locimp *__fastcall std::locale::_Init(bool _Do_incref)
{
  bool v1; // di
  std::locale::_Locimp *v2; // rbx
  std::_Lockit v4; // [rsp+40h] [rbp+8h]

  v1 = _Do_incref;
  std::_Lockit::_Lockit(&v4, 0);
  v2 = global_locale;
  if ( !global_locale )
  {
    v2 = std::locale::_Locimp::_New_Locimp(0);
    std::locale::_Setgloballocale(v2);
    v2->_Catmask = 63;
    std::_Yarn<char>::operator=(&v2->_Name, "C");
    std::locale::_Locimp::_Clocptr = v2;
    v2->vfptr->_Incref((std::_Facet_base *)&v2->vfptr);
    classic_locale._Ptr = std::locale::_Locimp::_Clocptr;
  }
  if ( v1 )
    v2->vfptr->_Incref((std::_Facet_base *)&v2->vfptr);
  std::_Lockit::~_Lockit(&v4);
  return v2;
}

// File Line: 172
// RVA: 0x12DDFC0
std::locale::_Locimp *__fastcall std::locale::_Locimp::_New_Locimp(bool _Transparent)
{
  bool v1; // di
  char *v2; // rax
  char *v3; // rbx
  signed __int64 v4; // rcx

  v1 = _Transparent;
  v2 = AMemory::malloc_default(0x38ui64);
  v3 = v2;
  if ( !v2 )
    return 0i64;
  *((_DWORD *)v2 + 2) = 1;
  *((_QWORD *)v2 + 2) = 0i64;
  *((_QWORD *)v2 + 3) = 0i64;
  *((_DWORD *)v2 + 8) = 0;
  v4 = (signed __int64)(v2 + 40);
  v2[36] = v1;
  *(_QWORD *)v2 = &std::locale::_Locimp::`vftable';
  *(_QWORD *)v4 = 0i64;
  *(_BYTE *)(v4 + 8) = 0;
  std::_Yarn<char>::operator=((std::_Yarn<char> *)(v2 + 40), pattern);
  return (std::locale::_Locimp *)v3;
}

// File Line: 182
// RVA: 0x12DDEC0
void __fastcall std::locale::_Locimp::_Locimp_dtor(std::locale::_Locimp *_This)
{
  std::locale::_Locimp *v1; // rdi
  unsigned __int64 v2; // rbx
  std::locale::facet *v3; // rcx
  void (__fastcall ***v4)(_QWORD, signed __int64); // rax
  std::_Lockit v5; // [rsp+40h] [rbp+8h]

  v1 = _This;
  std::_Lockit::_Lockit(&v5, 0);
  v2 = v1->_Facetcount;
  while ( v2 )
  {
    v3 = v1->_Facetvec[--v2];
    if ( v3 )
    {
      v4 = (void (__fastcall ***)(_QWORD, signed __int64))((__int64 (__cdecl *)(std::locale::facet *))v3->vfptr->_Decref)(v3);
      if ( v4 )
        (**v4)(v4, 1i64);
    }
  }
  free(v1->_Facetvec);
  std::_Lockit::~_Lockit(&v5);
}

// File Line: 192
// RVA: 0x12DDF38
void __fastcall std::_Locinfo::_Locinfo_ctor(std::_Locinfo *pLocinfo, const char *locname)
{
  const char *v2; // rbx
  std::_Locinfo *v3; // rdi
  const char *v4; // rax
  const char *v5; // rax

  v2 = locname;
  v3 = pLocinfo;
  setlocale(0, 0i64);
  if ( !v4 )
    v4 = &customWorldMapCaption;
  std::_Yarn<char>::operator=(&v3->_Oldlocname, v4);
  if ( v2 )
  {
    setlocale(0, v2);
    v2 = v5;
  }
  if ( !v2 )
    v2 = pattern;
  std::_Yarn<char>::operator=(&v3->_Newlocname, v2);
}

// File Line: 202
// RVA: 0x12DDFA4
void __fastcall std::_Locinfo::_Locinfo_dtor(std::_Locinfo *pLocinfo)
{
  char *v1; // rdx

  v1 = pLocinfo->_Oldlocname._Myptr;
  if ( v1 )
    setlocale(0, v1);
}


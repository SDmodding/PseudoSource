// File Line: 96
// RVA: 0x12DE0E8
const char *__fastcall std::_Winerror_map(int _Errcode)
{
  std::_Win_errtab_t *v1; // rax

  v1 = Win_errtab;
  if ( !Win_errtab[0]._Name )
    return 0i64;
  while ( v1->_Errcode != _Errcode )
  {
    ++v1;
    if ( !v1->_Name )
      return 0i64;
  }
  return v1->_Name;
}

// File Line: 194
// RVA: 0x12DE0C0
const char *__fastcall std::_Syserror_map(int _Errcode)
{
  std::_Sys_errtab_t *v1; // rax

  v1 = Sys_errtab;
  if ( !Sys_errtab[0]._Name )
    return 0i64;
  while ( v1->_Errcode != _Errcode )
  {
    ++v1;
    if ( !v1->_Name )
      return 0i64;
  }
  return v1->_Name;
}


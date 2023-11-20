// File Line: 7
// RVA: 0x15DEF98
__int64 dynamic_initializer_for__initlocks__()
{
  std::_Init_locks::_Init_locks(&initlocks_0);
  return atexit(dynamic_atexit_destructor_for__initlocks__);
}

// File Line: 12
// RVA: 0x15DEF14
__int64 std::_dynamic_initializer_for__ferr__()
{
  _iobuf *v0; // rbx

  v0 = _iob_func() + 2;
  std::basic_streambuf<char,std::char_traits<char>>::basic_streambuf<char,std::char_traits<char>>((std::basic_streambuf<char,std::char_traits<char> > *)&ferr.vfptr);
  ferr.vfptr = (std::basic_streambuf<char,std::char_traits<char> >Vtbl *)&std::basic_filebuf<char,std::char_traits<char>>::`vftable;
  std::basic_filebuf<char,std::char_traits<char>>::_Init(&ferr, v0, 0);
  return atexit(std::_dynamic_atexit_destructor_for__ferr__);
}

// File Line: 16
// RVA: 0x15DEEE4
__int64 std::_dynamic_initializer_for__cerr__()
{
  std::basic_ostream<char,std::char_traits<char>>::basic_ostream<char,std::char_traits<char>>(
    &std::cerr,
    (std::basic_streambuf<char,std::char_traits<char> > *)&ferr.vfptr,
    0,
    1);
  return atexit(std::_dynamic_atexit_destructor_for__cerr__);
}

// File Line: 29
// RVA: 0x15DEF60
__int64 std::_dynamic_initializer_for__init_cerr__()
{
  __int64 result; // rax

  std::_Ptr_cerr = &std::cerr;
  *(_QWORD *)&std::cerr.gap0[*(signed int *)(*(_QWORD *)std::cerr.gap0 + 4i64) + 80] = std::_Ptr_cout;
  result = *(_QWORD *)std::cerr.gap0;
  *(_DWORD *)&std::cerr.gap0[*(signed int *)(*(_QWORD *)std::cerr.gap0 + 4i64) + 24] |= 2u;
  return result;
}


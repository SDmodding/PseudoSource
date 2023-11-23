// File Line: 14
// RVA: 0x15DEFC4
__int64 std::_dynamic_initializer_for__initlocks___0()
{
  std::_Init_locks::_Init_locks(&initlocks_1);
  return atexit((int (__fastcall *)())std::_dynamic_atexit_destructor_for__initlocks___0);
}

// File Line: 37
// RVA: 0x12DF1A0
void __fastcall _Atexit(void (__fastcall *pf)())
{
  if ( !atcount_cdecl )
    abort();
  --atcount_cdecl;
  atfuns_cdecl[atcount_cdecl] = (void (__fastcall *)())EncodePointer(pf);
}

// File Line: 57
// RVA: 0x15DEFB8
__int64 dynamic_initializer_for__init_atexit__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__init_atexit__);
}


// File Line: 24
// RVA: 0x15826B0
__int64 dynamic_initializer_for__VehAudSym_Global__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Global", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&VehAudSym_Global, v0);
  return atexit(dynamic_atexit_destructor_for__VehAudSym_Global__);
}

// File Line: 33
// RVA: 0x1585870
__int64 dynamic_initializer_for__veh_common_ai__()
{
  UFG::qWiseSymbol::create_from_string(&veh_common_ai, "veh_common_ai");
  return atexit(dynamic_atexit_destructor_for__veh_common_ai__);
}


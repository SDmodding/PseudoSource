// File Line: 15
// RVA: 0x1491B40
__int64 dynamic_initializer_for__gStaticSymbolUC_none__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("none", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gStaticSymbolUC_none, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gStaticSymbolUC_none__);
}


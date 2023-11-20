// File Line: 15
// RVA: 0x1491B40
__int64 dynamic_initializer_for__gStaticSymbolUC_none__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("none", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gStaticSymbolUC_none, v0);
  return atexit(dynamic_atexit_destructor_for__gStaticSymbolUC_none__);
}


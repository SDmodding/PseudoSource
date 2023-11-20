// File Line: 35
// RVA: 0x1560E50
__int64 UFG::_dynamic_initializer_for__UICreditsSymbol_heading__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("heading", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UICreditsSymbol_heading, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__UICreditsSymbol_heading__);
}


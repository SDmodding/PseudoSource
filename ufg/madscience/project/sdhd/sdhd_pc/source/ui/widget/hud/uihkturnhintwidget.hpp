// File Line: 27
// RVA: 0x145B510
__int64 UFG::_dynamic_initializer_for__UITurnHintIcon_NEXT_EXIT__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("NEXT_EXIT", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UITurnHintIcon_NEXT_EXIT, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__UITurnHintIcon_NEXT_EXIT__);
}


// File Line: 29
// RVA: 0x14DA510
__int64 dynamic_initializer_for__EncounterSym_threshold_level3__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("threshold_level3", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&EncounterSym_threshold_level3, v0);
  return atexit(dynamic_atexit_destructor_for__EncounterSym_threshold_level3__);
}


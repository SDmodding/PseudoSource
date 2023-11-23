// File Line: 29
// RVA: 0x14D2200
__int64 dynamic_initializer_for__CopSym_stimulus_vehicle_collision_cop__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("stimulus_vehicle_collision_cop", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&CopSym_stimulus_vehicle_collision_cop, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CopSym_stimulus_vehicle_collision_cop__);
}


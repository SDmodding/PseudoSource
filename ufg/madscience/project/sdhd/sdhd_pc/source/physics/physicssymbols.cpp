// File Line: 31
// RVA: 0x15185E0
__int64 dynamic_initializer_for__PhysicsSym_suspension_frontSpringLength__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("suspension_frontSpringLength", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&PhysicsSym_suspension_frontSpringLength, v0);
  return atexit(dynamic_atexit_destructor_for__PhysicsSym_suspension_frontSpringLength__);
}


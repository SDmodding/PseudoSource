// File Line: 22
// RVA: 0x1586F20
__int64 UFG::Editor::_dynamic_initializer_for__gsymDefaultComponentTurf__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default-component-Turf", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gsymDefaultComponentTurf, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymDefaultComponentTurf__);
}


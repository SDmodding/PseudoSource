// File Line: 28
// RVA: 0x14C0A80
__int64 dynamic_initializer_for__CAMERA_SYMBOL_DofNearBlur__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DofNearBlur", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&CAMERA_SYMBOL_DofNearBlur, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAMERA_SYMBOL_DofNearBlur__);
}


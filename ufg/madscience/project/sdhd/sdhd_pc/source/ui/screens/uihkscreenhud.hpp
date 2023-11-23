// File Line: 86
// RVA: 0x145B310
__int64 UFG::_dynamic_initializer_for__UIHudWidgetID_HUD_COMBAT_METER__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("HUD_COMBAT_METER", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UIHudWidgetID_HUD_COMBAT_METER, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__UIHudWidgetID_HUD_COMBAT_METER__);
}


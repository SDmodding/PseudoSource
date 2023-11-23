// File Line: 12
// RVA: 0x152CB70
__int64 UFG::_dynamic_initializer_for__qSymbolX_GameStatEventSymbol_FSR_Berserk__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("FSR_Berserk", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbolX_GameStatEventSymbol_FSR_Berserk, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbolX_GameStatEventSymbol_FSR_Berserk__);
}

// File Line: 22
// RVA: 0x152C0D0
__int64 UFG::_dynamic_initializer_for__gGameStatEventChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gGameStatEventChannel, "EVT_GameStat", "Sent to track as a game stat event");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gGameStatEventChannel__);
}


// File Line: 533
// RVA: 0x35AF60
signed __int64 __fastcall UFG::GetBattleTypeFromName(UFG::qSymbol *battle_type_name)
{
  UFG::qSymbol *v1; // rsi
  unsigned int v2; // edi
  const char **v3; // rbx
  UFG::qSymbol result; // [rsp+38h] [rbp+10h]

  v1 = battle_type_name;
  v2 = 0;
  v3 = UFG::BattleTypeNames;
  while ( UFG::qSymbol::create_from_string(&result, *v3)->mUID != v1->mUID )
  {
    ++v3;
    ++v2;
    if ( (signed __int64)v3 >= (signed __int64)UFG::GlobalCooldownNames )
      return 0xFFFFFFFFi64;
  }
  return v2;
}

// File Line: 630
// RVA: 0x14B30D0
void UFG::_dynamic_initializer_for__gTerrainTypeColours__()
{
  UFG::gTerrainTypeColours[0] = UFG::qColour::White;
  xmmword_1423BAD30 = (__int128)UFG::qColour::Green;
  xmmword_1423BAD40 = (__int128)UFG::qColour::Blue;
  xmmword_1423BAD50 = (__int128)UFG::qColour::Orange;
  xmmword_1423BAD60 = (__int128)UFG::qColour::Pink;
}

// File Line: 641
// RVA: 0x14B7370
__int64 UFG::_dynamic_initializer_for__qStaticSymbol_none__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("eMoveType_None", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::qStaticSymbol_none, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qStaticSymbol_none__);
}

// File Line: 642
// RVA: 0x14B73F0
__int64 UFG::_dynamic_initializer_for__qStaticSymbol_walk__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("eMoveType_Walk", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::qStaticSymbol_walk, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qStaticSymbol_walk__);
}

// File Line: 643
// RVA: 0x14B7330
__int64 UFG::_dynamic_initializer_for__qStaticSymbol_jog__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("eMoveType_Jog", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::qStaticSymbol_jog, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qStaticSymbol_jog__);
}

// File Line: 644
// RVA: 0x14B73B0
__int64 UFG::_dynamic_initializer_for__qStaticSymbol_run__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("eMoveType_Run", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::qStaticSymbol_run, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qStaticSymbol_run__);
}

// File Line: 646
// RVA: 0x14AF810
__int64 UFG::_dynamic_initializer_for__MoveTypeSymbols__()
{
  UFG::MoveTypeSymbols[0] = UFG::qStaticSymbol_none;
  dword_1423BB82C = UFG::qStaticSymbol_walk.mUID;
  dword_1423BB830 = UFG::qStaticSymbol_jog.mUID;
  dword_1423BB834 = UFG::qStaticSymbol_run.mUID;
  return atexit(UFG::_dynamic_atexit_destructor_for__MoveTypeSymbols__);
}


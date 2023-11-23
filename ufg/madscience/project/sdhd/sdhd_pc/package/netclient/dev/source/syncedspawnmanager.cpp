// File Line: 51
// RVA: 0x14671C0
__int64 dynamic_initializer_for__SyncedSpawnManager::mSyncedObjects__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SyncedSpawnManager::mSyncedObjects__);
}

// File Line: 322
// RVA: 0x1467670
__int64 dynamic_initializer_for__gRemotePlayerNames__()
{
  unsigned int v0; // eax
  unsigned int v1; // eax
  unsigned int v2; // eax

  v0 = UFG::qStringHash32("PlayerTwo_Havok", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol(&gRemotePlayerNames, v0);
  v1 = UFG::qStringHash32("PlayerThree_Havok", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol(&stru_1422554C4, v1);
  v2 = UFG::qStringHash32("PlayerFour_Havok", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol(&stru_1422554C8, v2);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gRemotePlayerNames__);
}


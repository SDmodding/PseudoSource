// File Line: 27
// RVA: 0x13F2F0
void __fastcall UFG::GameSetup::GameSetup(UFG::GameSetup *this)
{
  this->mMultiplayer = 0;
  this->vfptr = (UFG::GameSetupVtbl *)&UFG::GameSetup::`vftable;
  UFG::qStringCopy(this->mConfig, 0x7FFFFFFF, &customCaption, -1);
  UFG::qStringCopy(this->mLocationDir, 0x7FFFFFFF, &customCaption, -1);
  UFG::qSPrintf(this->mLocationDir, 32, "%s", &customCaption);
  UFG::qStringCopy(this->mDebugSaveGame, 0x7FFFFFFF, &customCaption, -1);
  UFG::qSPrintf(this->mDebugSaveGame, 32, "%s", &customCaption);
  UFG::qStringCopy(this->mProgressionFlowType, 0x7FFFFFFF, &customCaption, -1);
  UFG::qSPrintf(this->mProgressionFlowType, 32, "%s", &customCaption);
  UFG::qStringCopy(this->mInitMenu, 0x7FFFFFFF, &customCaption, -1);
  UFG::qSPrintf(this->mInitMenu, 32, "%s", "Splash");
}

// File Line: 44
// RVA: 0x13F450
void __fastcall UFG::GameSetup::LoadConfig(UFG::GameSetup *this, UFG::qString *config)
{
  UFG::qPropertySet *PropertySet; // rbx
  UFG::qPropertySet *v5; // rbx
  unsigned int v6; // ecx
  char *v7; // rbp
  char *v8; // rbp
  char *v9; // rbp
  char *v10; // rbp
  bool *v11; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h] BYREF
  UFG::qString *v13; // [rsp+58h] [rbp+10h]

  v13 = config;
  if ( (_S1_19 & 1) == 0 )
  {
    _S1_19 |= 1u;
    UFG::qSymbol::create_from_string(&propertySetSymbol, "config-GameSetup");
    atexit(UFG::GameSetup::LoadConfig_::_2_::_dynamic_atexit_destructor_for__propertySetSymbol__);
  }
  PropertySet = UFG::PropertySetManager::GetPropertySet(&propertySetSymbol);
  UFG::qSymbol::create_from_string(&result, config->mData);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(PropertySet, &result, DEPTH_RECURSE);
  v6 = _S1_19;
  if ( (_S1_19 & 2) == 0 )
  {
    _S1_19 |= 2u;
    UFG::qSymbol::create_from_string(&dir_symbol, "directory");
    atexit(UFG::GameSetup::LoadConfig_::_2_::_dynamic_atexit_destructor_for__dir_symbol__);
    v6 = _S1_19;
  }
  if ( (v6 & 4) == 0 )
  {
    _S1_19 = v6 | 4;
    UFG::qSymbol::create_from_string(&menu_symbol, "uiMenuInit");
    atexit(UFG::GameSetup::LoadConfig_::_2_::_dynamic_atexit_destructor_for__menu_symbol__);
    v6 = _S1_19;
  }
  if ( (v6 & 8) == 0 )
  {
    _S1_19 = v6 | 8;
    UFG::qSymbol::create_from_string(&prog_symbol, "progressionFlow");
    atexit(UFG::GameSetup::LoadConfig_::_2_::_dynamic_atexit_destructor_for__prog_symbol__);
    v6 = _S1_19;
  }
  if ( (v6 & 0x10) == 0 )
  {
    _S1_19 = v6 | 0x10;
    UFG::qSymbol::create_from_string(&dbsave_symbol, "debugSaveGame");
    atexit(UFG::GameSetup::LoadConfig_::_2_::_dynamic_atexit_destructor_for__dbsave_symbol__);
    v6 = _S1_19;
  }
  if ( (v6 & 0x20) == 0 )
  {
    _S1_19 = v6 | 0x20;
    UFG::qSymbol::create_from_string(&mp_symbol, "multiplayer");
    atexit(UFG::GameSetup::LoadConfig_::_2_::_dynamic_atexit_destructor_for__mp_symbol__);
    v6 = _S1_19;
  }
  if ( (v6 & 0x40) == 0 )
  {
    _S1_19 = v6 | 0x40;
    UFG::qSymbol::create_from_string(&ngm_symbol, "netGameMode");
    atexit(UFG::GameSetup::LoadConfig_::_2_::_dynamic_atexit_destructor_for__ngm_symbol__);
  }
  v7 = PropertyUtils::Get<char const *>(v5, &dir_symbol, DEPTH_RECURSE);
  UFG::qStringCopy(this->mLocationDir, 0x7FFFFFFF, &customCaption, -1);
  if ( v7 )
    UFG::qSPrintf(this->mLocationDir, 32, "%s", v7);
  v8 = PropertyUtils::Get<char const *>(v5, &menu_symbol, DEPTH_RECURSE);
  UFG::qStringCopy(this->mInitMenu, 0x7FFFFFFF, &customCaption, -1);
  if ( v8 )
    UFG::qSPrintf(this->mInitMenu, 32, "%s", v8);
  v9 = PropertyUtils::Get<char const *>(v5, &dbsave_symbol, DEPTH_RECURSE);
  UFG::qStringCopy(this->mDebugSaveGame, 0x7FFFFFFF, &customCaption, -1);
  if ( v9 )
    UFG::qSPrintf(this->mDebugSaveGame, 32, "%s", v9);
  v10 = PropertyUtils::Get<char const *>(v5, &prog_symbol, DEPTH_RECURSE);
  UFG::qStringCopy(this->mProgressionFlowType, 0x7FFFFFFF, &customCaption, -1);
  if ( v10 )
    UFG::qSPrintf(this->mProgressionFlowType, 32, "%s", v10);
  v11 = UFG::qPropertySet::Get<bool>(v5, &mp_symbol, DEPTH_RECURSE);
  if ( v11 )
    LOBYTE(v11) = *v11;
  this->mMultiplayer = (char)v11;
  UFG::qPropertySet::Get<long>(v5, &ngm_symbol, DEPTH_RECURSE);
  UFG::qString::~qString(config);
}

// File Line: 94
// RVA: 0x13F850
void __fastcall UFG::GameSetup::SetLocationDir(UFG::GameSetup *this, const char *loc_directory)
{
  char *mLocationDir; // rdi

  mLocationDir = this->mLocationDir;
  UFG::qStringCopy(this->mLocationDir, 0x7FFFFFFF, &customCaption, -1);
  if ( loc_directory )
    UFG::qSPrintf(mLocationDir, 32, "%s", loc_directory);
}

// File Line: 103
// RVA: 0x13F7B0
void __fastcall UFG::GameSetup::SetDebugSaveGame(UFG::GameSetup *this, const char *debugSaveGame)
{
  char *mDebugSaveGame; // rdi

  mDebugSaveGame = this->mDebugSaveGame;
  UFG::qStringCopy(this->mDebugSaveGame, 0x7FFFFFFF, &customCaption, -1);
  if ( debugSaveGame )
    UFG::qSPrintf(mDebugSaveGame, 32, "%s", debugSaveGame);
}

// File Line: 121
// RVA: 0x13F800
void __fastcall UFG::GameSetup::SetInitMenu(UFG::GameSetup *this, const char *initMenu)
{
  char *mInitMenu; // rdi

  mInitMenu = this->mInitMenu;
  UFG::qStringCopy(this->mInitMenu, 0x7FFFFFFF, &customCaption, -1);
  if ( initMenu )
    UFG::qSPrintf(mInitMenu, 32, "%s", initMenu);
}


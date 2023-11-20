// File Line: 27
// RVA: 0x13F2F0
void __fastcall UFG::GameSetup::GameSetup(UFG::GameSetup *this)
{
  UFG::GameSetup *v1; // rdi

  v1 = this;
  this->mMultiplayer = 0;
  this->vfptr = (UFG::GameSetupVtbl *)&UFG::GameSetup::`vftable;
  UFG::qStringCopy(this->mConfig, 0x7FFFFFFF, &customWorldMapCaption, -1);
  UFG::qStringCopy(v1->mLocationDir, 0x7FFFFFFF, &customWorldMapCaption, -1);
  UFG::qSPrintf(v1->mLocationDir, 32, "%s", &customWorldMapCaption);
  UFG::qStringCopy(v1->mDebugSaveGame, 0x7FFFFFFF, &customWorldMapCaption, -1);
  UFG::qSPrintf(v1->mDebugSaveGame, 32, "%s", &customWorldMapCaption);
  UFG::qStringCopy(v1->mProgressionFlowType, 0x7FFFFFFF, &customWorldMapCaption, -1);
  UFG::qSPrintf(v1->mProgressionFlowType, 32, "%s", &customWorldMapCaption);
  UFG::qStringCopy(v1->mInitMenu, 0x7FFFFFFF, &customWorldMapCaption, -1);
  UFG::qSPrintf(v1->mInitMenu, 32, "%s", "Splash");
}

// File Line: 44
// RVA: 0x13F450
void __fastcall UFG::GameSetup::LoadConfig(UFG::GameSetup *this, UFG::qString *config)
{
  UFG::qString *v2; // rdi
  UFG::GameSetup *v3; // rsi
  UFG::qPropertySet *v4; // rbx
  UFG::qPropertySet *v5; // rbx
  unsigned int v6; // ecx
  char *v7; // rbp
  char *v8; // rbp
  char *v9; // rbp
  char *v10; // rbp
  bool *v11; // rax
  signed __int64 v12; // [rsp+20h] [rbp-28h]
  UFG::qSymbol result; // [rsp+50h] [rbp+8h]
  UFG::qString *v14; // [rsp+58h] [rbp+10h]

  v14 = config;
  v12 = -2i64;
  v2 = config;
  v3 = this;
  if ( !(_S1_19 & 1) )
  {
    _S1_19 |= 1u;
    UFG::qSymbol::create_from_string(&propertySetSymbol, "config-GameSetup");
    atexit(UFG::GameSetup::LoadConfig_::_2_::_dynamic_atexit_destructor_for__propertySetSymbol__);
  }
  v4 = UFG::PropertySetManager::GetPropertySet(&propertySetSymbol);
  UFG::qSymbol::create_from_string(&result, v2->mData);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(v4, &result, DEPTH_RECURSE);
  v6 = _S1_19;
  if ( !(_S1_19 & 2) )
  {
    _S1_19 |= 2u;
    UFG::qSymbol::create_from_string(&dir_symbol, "directory");
    atexit(UFG::GameSetup::LoadConfig_::_2_::_dynamic_atexit_destructor_for__dir_symbol__);
    v6 = _S1_19;
  }
  if ( !(v6 & 4) )
  {
    _S1_19 = v6 | 4;
    UFG::qSymbol::create_from_string(&menu_symbol, "uiMenuInit");
    atexit(UFG::GameSetup::LoadConfig_::_2_::_dynamic_atexit_destructor_for__menu_symbol__);
    v6 = _S1_19;
  }
  if ( !(v6 & 8) )
  {
    _S1_19 = v6 | 8;
    UFG::qSymbol::create_from_string(&prog_symbol, "progressionFlow");
    atexit(UFG::GameSetup::LoadConfig_::_2_::_dynamic_atexit_destructor_for__prog_symbol__);
    v6 = _S1_19;
  }
  if ( !(v6 & 0x10) )
  {
    _S1_19 = v6 | 0x10;
    UFG::qSymbol::create_from_string(&dbsave_symbol, "debugSaveGame");
    atexit(UFG::GameSetup::LoadConfig_::_2_::_dynamic_atexit_destructor_for__dbsave_symbol__);
    v6 = _S1_19;
  }
  if ( !(v6 & 0x20) )
  {
    _S1_19 = v6 | 0x20;
    UFG::qSymbol::create_from_string(&mp_symbol, "multiplayer");
    atexit(UFG::GameSetup::LoadConfig_::_2_::_dynamic_atexit_destructor_for__mp_symbol__);
    v6 = _S1_19;
  }
  if ( !(v6 & 0x40) )
  {
    _S1_19 = v6 | 0x40;
    UFG::qSymbol::create_from_string(&ngm_symbol, "netGameMode");
    atexit(UFG::GameSetup::LoadConfig_::_2_::_dynamic_atexit_destructor_for__ngm_symbol__);
  }
  v7 = PropertyUtils::Get<char const *>(v5, &dir_symbol, DEPTH_RECURSE);
  UFG::qStringCopy(v3->mLocationDir, 0x7FFFFFFF, &customWorldMapCaption, -1);
  if ( v7 )
    UFG::qSPrintf(v3->mLocationDir, 32, "%s", v7, -2i64);
  v8 = PropertyUtils::Get<char const *>(v5, &menu_symbol, DEPTH_RECURSE);
  UFG::qStringCopy(v3->mInitMenu, 0x7FFFFFFF, &customWorldMapCaption, -1);
  if ( v8 )
    UFG::qSPrintf(v3->mInitMenu, 32, "%s", v8, v12);
  v9 = PropertyUtils::Get<char const *>(v5, &dbsave_symbol, DEPTH_RECURSE);
  UFG::qStringCopy(v3->mDebugSaveGame, 0x7FFFFFFF, &customWorldMapCaption, -1);
  if ( v9 )
    UFG::qSPrintf(v3->mDebugSaveGame, 32, "%s", v9, v12);
  v10 = PropertyUtils::Get<char const *>(v5, &prog_symbol, DEPTH_RECURSE);
  UFG::qStringCopy(v3->mProgressionFlowType, 0x7FFFFFFF, &customWorldMapCaption, -1);
  if ( v10 )
    UFG::qSPrintf(v3->mProgressionFlowType, 32, "%s", v10, v12);
  v11 = UFG::qPropertySet::Get<bool>(v5, &mp_symbol, DEPTH_RECURSE);
  if ( v11 )
    LOBYTE(v11) = *v11;
  v3->mMultiplayer = (char)v11;
  UFG::qPropertySet::Get<long>(v5, &ngm_symbol, DEPTH_RECURSE);
  UFG::qString::~qString(v2);
}

// File Line: 94
// RVA: 0x13F850
void __fastcall UFG::GameSetup::SetLocationDir(UFG::GameSetup *this, const char *const loc_directory)
{
  char *v2; // rdi
  const char *v3; // rbx

  v2 = this->mLocationDir;
  v3 = loc_directory;
  UFG::qStringCopy(this->mLocationDir, 0x7FFFFFFF, &customWorldMapCaption, -1);
  if ( v3 )
    UFG::qSPrintf(v2, 32, "%s", v3);
}

// File Line: 103
// RVA: 0x13F7B0
void __fastcall UFG::GameSetup::SetDebugSaveGame(UFG::GameSetup *this, const char *const debugSaveGame)
{
  char *v2; // rdi
  const char *v3; // rbx

  v2 = this->mDebugSaveGame;
  v3 = debugSaveGame;
  UFG::qStringCopy(this->mDebugSaveGame, 0x7FFFFFFF, &customWorldMapCaption, -1);
  if ( v3 )
    UFG::qSPrintf(v2, 32, "%s", v3);
}

// File Line: 121
// RVA: 0x13F800
void __fastcall UFG::GameSetup::SetInitMenu(UFG::GameSetup *this, const char *const initMenu)
{
  char *v2; // rdi
  const char *v3; // rbx

  v2 = this->mInitMenu;
  v3 = initMenu;
  UFG::qStringCopy(this->mInitMenu, 0x7FFFFFFF, &customWorldMapCaption, -1);
  if ( v3 )
    UFG::qSPrintf(v2, 32, "%s", v3);
}


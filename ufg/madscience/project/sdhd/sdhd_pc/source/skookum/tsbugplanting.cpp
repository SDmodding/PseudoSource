// File Line: 44
// RVA: 0x4CE870
void UFG::TSBugplanting::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("Bugplanting");
  SSClass::register_method_func(v0, "set_bugging_only", UFG::TSBugplanting::MthdC_set_bugging_only, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "is_switch_to_calibration",
    UFG::TSBugplanting::MthdC_is_switch_to_calibration,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "is_switch_to_screwing",
    UFG::TSBugplanting::MthdC_is_switch_to_screwing,
    1,
    rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "is_successful", UFG::TSBugplanting::MthdC_is_successful, 1, rebindc);
}

// File Line: 65
// RVA: 0x4ED4A0
void __fastcall UFG::TSBugplanting::MthdC_set_bugging_only(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenBugPlantingMinigame::mbBuggingOnly = 1;
}

// File Line: 71
// RVA: 0x4E9C70
void __fastcall UFG::TSBugplanting::MthdC_is_switch_to_calibration(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreen *Screen; // rax

  if ( ppResult )
  {
    Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "BugPlantingMinigame");
    if ( Screen )
      *ppResult = SSBoolean::pool_new((bool)Screen[1].mNext);
    else
      *ppResult = 0i64;
  }
}

// File Line: 82
// RVA: 0x4E9CC0
void __fastcall UFG::TSBugplanting::MthdC_is_switch_to_screwing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreen *Screen; // rax

  if ( ppResult )
  {
    Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "BugPlantingMinigame");
    if ( Screen )
      *ppResult = SSBoolean::pool_new(BYTE1(Screen[1].mNext));
    else
      *ppResult = 0i64;
  }
}

// File Line: 94
// RVA: 0x4E9B50
void __fastcall UFG::TSBugplanting::MthdC_is_successful(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(UFG::UIHKScreenBugPlantingMinigame::m_bWon);
}


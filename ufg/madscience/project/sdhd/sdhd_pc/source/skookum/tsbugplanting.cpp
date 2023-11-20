// File Line: 44
// RVA: 0x4CE870
void UFG::TSBugplanting::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("Bugplanting");
  SSClass::register_method_func(v0, "set_bugging_only", UFG::TSBugplanting::MthdC_set_bugging_only, 1, 0);
  SSClass::register_method_func(
    v0,
    "is_switch_to_calibration",
    UFG::TSBugplanting::MthdC_is_switch_to_calibration,
    1,
    0);
  SSClass::register_method_func(v0, "is_switch_to_screwing", UFG::TSBugplanting::MthdC_is_switch_to_screwing, 1, 0);
  SSClass::register_method_func(v0, "is_successful", UFG::TSBugplanting::MthdC_is_successful, 1, 0);
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
  SSInstance **v2; // rbx
  UFG::UIScreen *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "BugPlantingMinigame");
    if ( v3 )
      *v2 = (SSInstance *)SSBoolean::pool_new((bool)v3[1].mNext);
    else
      *v2 = 0i64;
  }
}

// File Line: 82
// RVA: 0x4E9CC0
void __fastcall UFG::TSBugplanting::MthdC_is_switch_to_screwing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIScreen *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "BugPlantingMinigame");
    if ( v3 )
      *v2 = (SSInstance *)SSBoolean::pool_new(BYTE1(v3[1].mNext));
    else
      *v2 = 0i64;
  }
}

// File Line: 94
// RVA: 0x4E9B50
void __fastcall UFG::TSBugplanting::MthdC_is_successful(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(UFG::UIHKScreenBugPlantingMinigame::m_bWon);
}


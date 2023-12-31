// File Line: 33
// RVA: 0x4D7DA0
void UFG::TSUI_HUD_Race::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("RaceHUD");
  SSClass::register_method_func(v0, "set_seconds", UFG::TSUI_HUD_Race::MthdC_set_seconds, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "set_timer", UFG::TSUI_HUD_Race::MthdC_set_timer, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "start_countdown", UFG::TSUI_HUD_Race::MthdC_start_countdown, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "set_player_position", UFG::TSUI_HUD_Race::MthdC_set_player_position, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "clear", UFG::TSUI_HUD_Race::MthdC_clear, 1, rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "minimap_set_route_visible",
    UFG::TSUI_HUD_Race::MthdC_minimap_set_route_visible,
    1,
    rebinde);
}

// File Line: 47
// RVA: 0x4EE9D0
void __fastcall UFG::TSUI_HUD_Race::MthdC_set_seconds(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  float v2; // xmm0_4

  if ( UFG::UIHKScreenHud::RaceTimer )
  {
    v2 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data * 1000.0;
    UFG::UIHKRaceTimerWidget::SetTime(
      UFG::UIHKScreenHud::RaceTimer,
      (int)v2 / 1000 / 60,
      (int)v2 / 1000 % 60,
      (int)v2 % 1000);
    UFG::UIHKRaceTimerWidget::SetVisible(UFG::UIHKScreenHud::RaceTimer, 1);
    UFG::UIHKRacePositionWidget::SetVisible((UFG::UIHKRacePositionWidget *)UFG::UIHKScreenHud::RacePercentage, 1);
  }
}

// File Line: 64
// RVA: 0x4EF350
void __fastcall UFG::TSUI_HUD_Race::MthdC_set_timer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( UFG::UIHKScreenHud::RaceTimer )
  {
    UFG::UIHKRaceTimerWidget::SetTime(
      UFG::UIHKScreenHud::RaceTimer,
      (*pScope->i_data.i_array_p)->i_data_p->i_user_data,
      *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64),
      *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64));
    UFG::UIHKRaceTimerWidget::SetVisible(UFG::UIHKScreenHud::RaceTimer, 1);
  }
}

// File Line: 78
// RVA: 0x4F2480
void __fastcall UFG::TSUI_HUD_Race::MthdC_start_countdown(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::allocator::free_link *v2; // rax
  UFG::UIScreenInvoke *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  UFG::ProgressionTracker *v5; // rax
  char *mText; // rbx
  int v7; // eax
  const char *v8; // rdx

  v2 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "TSUI_HUD_Race UIScreenInvoke", 0i64, 1u);
  v3 = (UFG::UIScreenInvoke *)v2;
  if ( v2 )
  {
    v4 = v2 + 1;
    v4->mNext = v4;
    v4[1].mNext = v4;
    v3->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable;
    UFG::qString::qString(&v3->command, &customCaption);
  }
  else
  {
    v3 = 0i64;
  }
  if ( v3 && UFG::UIHKScreenHud::RacePath )
  {
    UFG::qString::Set(&v3->command, "Race_StartCountdown");
    UFG::UIHKScreenGlobalOverlay::QueueInvoke(v3);
    v5 = UFG::ProgressionTracker::Instance();
    mText = UFG::ProgressionTracker::GetActiveMaster(v5)->mScriptClassName.mText;
    v7 = UFG::qStringCompare(mText, "RaceStartCase", -1);
    v8 = "R_NP_04";
    if ( v7 )
      v8 = mText;
    UFG::UITiledMapRaceSplines::SetLayerName(UFG::UIHKScreenHud::RacePath, v8);
  }
}

// File Line: 102
// RVA: 0x4EE720
void __fastcall UFG::TSUI_HUD_Race::MthdC_set_player_position(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  unsigned int i_user_data; // ebx

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = i_array_p[1]->i_data_p->i_user_data;
  if ( UFG::UIHKScreenHud::RacePosition )
  {
    UFG::UIHKRacePositionWidget::SetPlayerRank(UFG::UIHKScreenHud::RacePosition, (*i_array_p)->i_data_p->i_user_data);
    UFG::UIHKRacePositionWidget::SetNumRacers(UFG::UIHKScreenHud::RacePosition, i_user_data);
    UFG::UIHKRacePositionWidget::SetVisible(UFG::UIHKScreenHud::RacePosition, 1);
  }
}

// File Line: 116
// RVA: 0x4E4320
// attributes: thunk
void __fastcall UFG::TSUI_HUD_Race::MthdC_clear(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenHud::RaceClear();
}

// File Line: 122
// RVA: 0x4EB000
void __fastcall UFG::TSUI_HUD_Race::MthdC_minimap_set_route_visible(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UITiledMapWidget::gMinimapRaceRouteVisible = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}


// File Line: 33
// RVA: 0x4D7B10
void UFG::TSUI_HUD_HintText::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]
  ASymbol rebindg; // [rsp+20h] [rbp-18h]
  ASymbol rebindh; // [rsp+20h] [rbp-18h]
  ASymbol rebindi; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("HintText");
  SSClass::register_method_func(v0, "show_hint_text", UFG::TSUI_HUD_HintText::MthdC_show_hint_text, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "hide_hint_text", UFG::TSUI_HUD_HintText::MthdC_hide_hint_text, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "show_info_popup", UFG::TSUI_HUD_HintText::MthdC_show_info_popup, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "hide_info_popup", UFG::TSUI_HUD_HintText::MthdC_hide_info_popup, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "show_raid_start_popup",
    UFG::TSUI_HUD_HintText::MthdC_show_raid_start_popup,
    1,
    rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "show_racket_finished_popup",
    UFG::TSUI_HUD_HintText::MthdC_show_racket_finished_popup,
    1,
    rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "show_raid_info_popup",
    UFG::TSUI_HUD_HintText::MthdC_show_raid_info_popup,
    1,
    rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "show_raid_warning_popup",
    UFG::TSUI_HUD_HintText::MthdC_show_raid_warning_popup,
    1,
    rebindg);
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "show_raid_bonus_popup",
    UFG::TSUI_HUD_HintText::MthdC_show_raid_bonus_popup,
    1,
    rebindh);
  LOBYTE(rebindi.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "info_popup_show_hint_reminder",
    UFG::TSUI_HUD_HintText::MthdC_info_popup_show_hint_reminder,
    1,
    rebindi);
}

// File Line: 50
// RVA: 0x4F0450
void __fastcall UFG::TSUI_HUD_HintText::MthdC_show_hint_text(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx

  i_array_p = pScope->i_data.i_array_p;
  UFG::UIHKHintText::show(
    UFG::UIHKScreenHud::HintText,
    *(const char **)(*i_array_p)->i_data_p->i_user_data,
    *(float *)&i_array_p[1]->i_data_p->i_user_data,
    i_array_p[2]->i_data_p->i_user_data != 0,
    *(float *)&i_array_p[3]->i_data_p->i_user_data);
}

// File Line: 61
// RVA: 0x4E8ED0
void __fastcall UFG::TSUI_HUD_HintText::MthdC_hide_hint_text(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKHintText::hide(UFG::UIHKScreenHud::HintText);
}

// File Line: 67
// RVA: 0x4F0570
void __fastcall UFG::TSUI_HUD_HintText::MthdC_show_info_popup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKInfoPopupWidget::Show(
    UFG::UIHKScreenHud::InfoPopup,
    *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    (UFG::qSymbol *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64),
    *(float *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64),
    POSITION_DEFAULT);
}

// File Line: 77
// RVA: 0x4F0AA0
void __fastcall UFG::TSUI_HUD_HintText::MthdC_show_raid_start_popup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rdi
  float v4; // xmm6_4
  UFG::allocator::free_link *v5; // rbx
  UFG::UIHUDInfoFlasher *Instance; // rax

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v4 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
  if ( UFG::UIHUDInfoFlasher::getInstance() )
  {
    v5 = UFG::qMalloc(0x98ui64, UFG::gGlobalNewName, 0i64);
    if ( v5 )
    {
      UFG::InfoFlasherBase::InfoFlasherBase(
        (UFG::InfoFlasherBase *)v5,
        *(const char **)i_data_p->i_user_data,
        v4,
        0,
        3.0);
      v5->mNext = (UFG::allocator::free_link *)&UFG::InfoFlasherRaidStart::`vftable;
    }
    else
    {
      v5 = 0i64;
    }
    Instance = UFG::UIHUDInfoFlasher::getInstance();
    UFG::UIHUDInfoFlasher::show(Instance, (UFG::InfoFlasherBase *)v5);
  }
}

// File Line: 87
// RVA: 0x4F0880
void __fastcall UFG::TSUI_HUD_HintText::MthdC_show_racket_finished_popup(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rdi
  float v4; // xmm6_4
  UFG::allocator::free_link *v5; // rbx
  UFG::UIHUDInfoFlasher *Instance; // rax

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v4 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
  if ( UFG::UIHUDInfoFlasher::getInstance() )
  {
    v5 = UFG::qMalloc(0x98ui64, UFG::gGlobalNewName, 0i64);
    if ( v5 )
    {
      UFG::InfoFlasherBase::InfoFlasherBase(
        (UFG::InfoFlasherBase *)v5,
        *(const char **)i_data_p->i_user_data,
        v4,
        0,
        3.0);
      v5->mNext = (UFG::allocator::free_link *)&UFG::InfoFlasherRacketFinished::`vftable;
    }
    else
    {
      v5 = 0i64;
    }
    Instance = UFG::UIHUDInfoFlasher::getInstance();
    UFG::UIHUDInfoFlasher::show(Instance, (UFG::InfoFlasherBase *)v5);
  }
}

// File Line: 97
// RVA: 0x4F09E0
void __fastcall UFG::TSUI_HUD_HintText::MthdC_show_raid_info_popup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rbx
  float v4; // xmm6_4
  SSInstance *v5; // rdi
  SSInstance *v6; // rsi
  UFG::allocator::free_link *v7; // rax
  UFG::InfoFlasherBase *v8; // rax
  UFG::InfoFlasherBase *v9; // rbx
  UFG::UIHUDInfoFlasher *Instance; // rax

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v4 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
  v5 = i_array_p[2]->i_data_p;
  v6 = i_array_p[3]->i_data_p;
  if ( UFG::UIHUDInfoFlasher::getInstance() )
  {
    v7 = UFG::qMalloc(0xE8ui64, UFG::gGlobalNewName, 0i64);
    if ( v7 )
    {
      UFG::InfoFlasherRaidInfo::InfoFlasherRaidInfo(
        (UFG::InfoFlasherRaidInfo *)v7,
        *(const char **)i_data_p->i_user_data,
        v4,
        *(const char **)v5->i_user_data,
        *(const char **)v6->i_user_data);
      v9 = v8;
    }
    else
    {
      v9 = 0i64;
    }
    Instance = UFG::UIHUDInfoFlasher::getInstance();
    UFG::UIHUDInfoFlasher::show(Instance, v9);
  }
}

// File Line: 109
// RVA: 0x4F0930
void __fastcall UFG::TSUI_HUD_HintText::MthdC_show_raid_bonus_popup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rdi
  float v4; // xmm6_4
  UFG::allocator::free_link *v5; // rbx
  UFG::UIHUDInfoFlasher *Instance; // rax

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v4 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
  if ( UFG::UIHUDInfoFlasher::getInstance() )
  {
    v5 = UFG::qMalloc(0x98ui64, UFG::gGlobalNewName, 0i64);
    if ( v5 )
    {
      UFG::InfoFlasherBase::InfoFlasherBase(
        (UFG::InfoFlasherBase *)v5,
        *(const char **)i_data_p->i_user_data,
        v4,
        0,
        3.0);
      v5->mNext = (UFG::allocator::free_link *)&UFG::InfoFlasherRaidBonus::`vftable;
    }
    else
    {
      v5 = 0i64;
    }
    Instance = UFG::UIHUDInfoFlasher::getInstance();
    UFG::UIHUDInfoFlasher::show(Instance, (UFG::InfoFlasherBase *)v5);
  }
}

// File Line: 119
// RVA: 0x4F0B50
void __fastcall UFG::TSUI_HUD_HintText::MthdC_show_raid_warning_popup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rdi
  float v4; // xmm6_4
  UFG::allocator::free_link *v5; // rbx
  UFG::UIHUDInfoFlasher *Instance; // rax

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v4 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
  if ( UFG::UIHUDInfoFlasher::getInstance() )
  {
    v5 = UFG::qMalloc(0x98ui64, UFG::gGlobalNewName, 0i64);
    if ( v5 )
    {
      UFG::InfoFlasherBase::InfoFlasherBase(
        (UFG::InfoFlasherBase *)v5,
        *(const char **)i_data_p->i_user_data,
        v4,
        0,
        3.0);
      v5->mNext = (UFG::allocator::free_link *)&UFG::InfoFlasherRaidWarning::`vftable;
    }
    else
    {
      v5 = 0i64;
    }
    Instance = UFG::UIHUDInfoFlasher::getInstance();
    UFG::UIHUDInfoFlasher::show(Instance, (UFG::InfoFlasherBase *)v5);
  }
}

// File Line: 129
// RVA: 0x4E8FE0
void __fastcall UFG::TSUI_HUD_HintText::MthdC_hide_info_popup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKInfoPopupWidget::Hide(UFG::UIHKScreenHud::InfoPopup);
}

// File Line: 135
// RVA: 0x4E9120
void __fastcall UFG::TSUI_HUD_HintText::MthdC_info_popup_show_hint_reminder(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::UIHKInfoPopupWidget::ShowHintReminder(UFG::UIHKScreenHud::InfoPopup);
}


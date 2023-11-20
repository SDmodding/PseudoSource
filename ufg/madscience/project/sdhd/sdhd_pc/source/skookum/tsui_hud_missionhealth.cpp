// File Line: 32
// RVA: 0x4D7C60
void UFG::TSUI_HUD_MissionHealth::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("MissionHealth");
  SSClass::register_method_func(v0, "set_visible", UFG::TSUI_HUD_MissionHealth::MthdC_set_visible, 1, 0);
  SSClass::register_method_func(v0, "set_caption", UFG::TSUI_HUD_MissionHealth::MthdC_set_caption, 1, 0);
  SSClass::register_method_func(v0, "set_value", UFG::TSUI_HUD_MissionHealth::MthdC_set_value, 1, 0);
  SSClass::register_method_func(v0, "set_success", UFG::TSUI_HUD_MissionHealth::MthdC_set_success, 1, 0);
}

// File Line: 43
// RVA: 0x4EF4B0
void __fastcall UFG::TSUI_HUD_MissionHealth::MthdC_set_visible(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( UFG::UIHKScreenHud::MissionHealth )
    UFG::UIHKMissionHealthWidget::SetVisible(
      UFG::UIHKScreenHud::MissionHealth,
      (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 53
// RVA: 0x4ED4B0
void __fastcall UFG::TSUI_HUD_MissionHealth::MthdC_set_caption(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( UFG::UIHKScreenHud::MissionHealth )
    UFG::UIHKMissionHealthWidget::SetCaption(
      UFG::UIHKScreenHud::MissionHealth,
      *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 63
// RVA: 0x4EF400
void __fastcall UFG::TSUI_HUD_MissionHealth::MthdC_set_value(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( UFG::UIHKScreenHud::MissionHealth )
    UFG::UIHKMissionHealthWidget::SetHealth(
      UFG::UIHKScreenHud::MissionHealth,
      *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 73
// RVA: 0x4EF220
void __fastcall UFG::TSUI_HUD_MissionHealth::MthdC_set_success(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( UFG::UIHKScreenHud::MissionHealth )
    UFG::UIHKMissionHealthWidget::SetSuccess(
      UFG::UIHKScreenHud::MissionHealth,
      (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}


// File Line: 80
// RVA: 0x4D3B80
void UFG::TSHUD::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("HUD");
  SSClass::register_coroutine_func(v0, "_text_xy", UFG::TSHUD::Coro_text_xy, 0);
  SSClass::register_coroutine_func(v0, "_text_xyz", UFG::TSHUD::Coro_text_xyz, 0);
  SSClass::register_coroutine_func(v0, "_flash_mission_obj", UFG::TSHUD::Coro_flash_mission_obj, 0);
  SSClass::register_method_func(v0, "social_set_enabled", UFG::TSHUD::MthdC_social_set_enabled, 1, 0);
  SSClass::register_method_func(v0, "face_minigame_is_active", UFG::TSHUD::MthdC_face_minigame_is_active, 1, 0);
  SSClass::register_method_func(v0, "set_mission_progress", UFG::TSHUD::MthdC_set_mission_progress, 1, 0);
  SSClass::register_method_func(v0, "hide_mission_progress", UFG::TSHUD::MthdC_hide_mission_progress, 1, 0);
  SSClass::register_method_func(v0, "hide_objective", UFG::TSHUD::MthdC_hide_objective, 1, 0);
  SSClass::register_method_func(v0, "activate_shortcut_button", UFG::TSHUD::MthdC_activate_shortcut_button, 1, 0);
  SSClass::register_method_func(v0, "set_visible", UFG::TSHUD::MthdC_set_visible, 1, 0);
  SSClass::register_method_func(v0, "flash_inventory_icon", UFG::TSHUD::MthdC_flash_inventory_icon, 1, 0);
  SSClass::register_method_func(
    v0,
    "set_objective_distance_enabled",
    UFG::TSHUD::MthdC_set_objective_distance_enabled,
    1,
    0);
  SSClass::register_method_func(v0, "show_turn_hint", UFG::TSHUD::MthdC_show_turn_hint, 1, 0);
  SSClass::register_method_func(v0, "hide_turn_hint", UFG::TSHUD::MthdC_hide_turn_hint, 1, 0);
  SSClass::register_method_func(v0, "flash_upgrade_popup", UFG::TSHUD::MthdC_flash_upgrade_popup, 1, 0);
  SSClass::register_method_func(v0, "show_upgrade_popup", UFG::TSHUD::MthdC_show_upgrade_popup, 1, 0);
  SSClass::register_method_func(v0, "hide_upgrade_popup", UFG::TSHUD::MthdC_hide_upgrade_popup, 1, 0);
  SSClass::register_method_func(v0, "show_hud_timer", (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_, 1, 0);
  SSClass::register_method_func(v0, "hide_hud_timer", (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_, 1, 0);
  SSClass::register_method_func(v0, "unlock_loading_hint", UFG::TSHUD::MthdC_unlock_loading_hint, 1, 0);
  SSClass::register_method_func(v0, "show_tutorial_overlay", UFG::TSHUD::MthdC_show_tutorial_overlay, 1, 0);
  SSClass::register_method_func(v0, "hide_tutorial_overlay", UFG::TSHUD::MthdC_hide_tutorial_overlay, 1, 0);
  SSClass::register_method_func(v0, "set_widget_visible", UFG::TSHUD::MthdC_set_widget_visible, 1, 0);
  SSClass::register_method_func(v0, "set_widget_highlight", UFG::TSHUD::MthdC_set_widget_highlight, 1, 0);
  SSClass::register_method_func(v0, "load_tutorial_textures", UFG::TSHUD::MthdC_load_tutorial_textures, 1, 0);
  SSClass::register_method_func(v0, "unload_tutorial_textures", UFG::TSHUD::MthdC_unload_tutorial_textures, 1, 0);
  SSClass::register_method_func(
    v0,
    "are_tutorial_textures_loaded",
    UFG::TSHUD::MthdC_are_tutorial_textures_loaded,
    1,
    0);
  SSClass::register_method_func(v0, "show_tutorial_prompt", UFG::TSHUD::MthdC_show_tutorial_prompt, 1, 0);
  SSClass::register_method_func(v0, "hide_tutorial_prompt", UFG::TSUI_HUD_HintText::MthdC_hide_info_popup, 1, 0);
  SSClass::register_method_func(v0, "secondary_tutorial_show", UFG::TSHUD::MthdC_secondary_tutorial_show, 1, 0);
  SSClass::register_method_func(v0, "secondary_tutorial_hide", UFG::TSHUD::MthdC_secondary_tutorial_hide, 1, 0);
  SSClass::register_method_func(v0, "show_phone_trace_signal", UFG::TSHUD::MthdC_show_phone_trace_signal, 1, 0);
  SSClass::register_method_func(v0, "set_phone_trace_signal", UFG::TSHUD::MthdC_set_phone_trace_signal, 1, 0);
  SSClass::register_method_func(v0, "hide_phone_trace_signal", UFG::TSHUD::MthdC_hide_phone_trace_signal, 1, 0);
  SSClass::register_method_func(v0, "set_phone_trace_enabled", UFG::TSHUD::MthdC_set_phone_trace_enabled, 1, 0);
  SSClass::register_method_func(v0, "set_phone_trace_target", UFG::TSHUD::MthdC_set_phone_trace_target, 1, 0);
  SSClass::register_method_func(v0, "region_show", UFG::TSHUD::MthdC_region_show, 1, 0);
  SSClass::register_method_func(v0, "set_health_ui_state", UFG::TSHUD::MthdC_set_health_ui_state, 1, 0);
  SSClass::register_method_func(
    v0,
    "is_statgame_finalscore_active",
    UFG::TSHUD::MthdC_is_statgame_finalscore_active,
    1,
    0);
}

// File Line: 151
// RVA: 0x4DE430
bool __fastcall UFG::TSHUD::Coro_text_xy(SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v1; // rbx
  SSData **v2; // r8
  SSInstance *v3; // r14
  int v4; // er15
  int v5; // er12
  SSInstance *v6; // rsi
  SSInstance *v7; // rdi
  unsigned int v8; // er13
  unsigned __int64 v9; // rbp
  unsigned int v10; // ebx
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax
  Render::DebugDrawContext *v13; // rax
  __int64 v14; // r10
  float v15; // xmm1_4
  bool result; // al
  UFG::qColour colour; // [rsp+48h] [rbp-40h]

  v1 = pScope;
  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p;
  v4 = v2[1]->i_data_p->i_user_data;
  v5 = v2[2]->i_data_p->i_user_data;
  v6 = v2[3]->i_data_p;
  v7 = v2[4]->i_data_p;
  v8 = v2[5]->i_data_p->i_user_data;
  v9 = v2[6]->i_data_p->i_user_data;
  if ( !(_S13_5 & 1) )
  {
    _S13_5 |= 1u;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&sFont.mPrev);
    atexit(UFG::TSHUD::Coro_text_xy_::_2_::_dynamic_atexit_destructor_for__sFont__);
  }
  if ( !v1->i_update_count && !sFont.mNameUID )
  {
    v10 = UFG::qStringHash32(*(const char **)v7->i_user_data, 0xFFFFFFFF);
    v11 = `UFG::qGetResourceInventory<Render::Font>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Render::Font>'::`2'::result )
    {
      v12 = UFG::qResourceWarehouse::Instance();
      v11 = UFG::qResourceWarehouse::GetInventory(v12, 0x69FCCB4Cu);
      `UFG::qGetResourceInventory<Render::Font>'::`2'::result = v11;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&sFont.mPrev, 0x69FCCB4Cu, v10, v11);
  }
  v13 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v14 = *(_QWORD *)v3->i_user_data;
  *(_QWORD *)&colour.r = *(_QWORD *)v9;
  colour.b = *(float *)(v9 + 8);
  LODWORD(colour.a) = (_DWORD)FLOAT_1_0;
  Render::DebugDrawContext::DrawTextAligned(
    v13,
    v4,
    v5,
    v8,
    &sFont,
    &colour,
    "%s",
    v14,
    -2i64,
    *(_QWORD *)&colour.r,
    *(_QWORD *)&colour.b);
  v15 = *(float *)&v6->i_user_data;
  result = v15 <= 0.0;
  *(float *)&v6->i_user_data = v15 - SkookumScript::c_sim_delta;
  return result;
}

// File Line: 193
// RVA: 0x4DE5F0
bool __fastcall UFG::TSHUD::Coro_text_xyz(SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v1; // rbx
  SSData **v2; // r8
  SSInstance *v3; // r14
  UFG::qVector3 *v4; // r15
  SSInstance *v5; // rsi
  SSInstance *v6; // rdi
  unsigned int v7; // er12
  float *v8; // rbp
  unsigned int v9; // ebx
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  Render::DebugDrawContext *v12; // rax
  __int64 v13; // r10
  float v14; // xmm1_4
  bool result; // al
  UFG::qColour colour; // [rsp+48h] [rbp-30h]

  v1 = pScope;
  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p;
  v4 = (UFG::qVector3 *)v2[1]->i_data_p->i_user_data;
  v5 = v2[2]->i_data_p;
  v6 = v2[3]->i_data_p;
  v7 = v2[4]->i_data_p->i_user_data;
  v8 = (float *)v2[5]->i_data_p->i_user_data;
  if ( !(_S14_1 & 1) )
  {
    _S14_1 |= 1u;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&sFont_0.mPrev);
    atexit(UFG::TSHUD::Coro_text_xyz_::_2_::_dynamic_atexit_destructor_for__sFont__);
  }
  if ( !v1->i_update_count && !sFont_0.mNameUID )
  {
    v9 = UFG::qStringHash32(*(const char **)v6->i_user_data, 0xFFFFFFFF);
    v10 = `UFG::qGetResourceInventory<Render::Font>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Render::Font>'::`2'::result )
    {
      v11 = UFG::qResourceWarehouse::Instance();
      v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x69FCCB4Cu);
      `UFG::qGetResourceInventory<Render::Font>'::`2'::result = v10;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&sFont_0.mPrev, 0x69FCCB4Cu, v9, v10);
  }
  v12 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v13 = *(_QWORD *)v3->i_user_data;
  colour.r = *v8;
  colour.g = v8[1];
  colour.b = v8[2];
  LODWORD(colour.a) = (_DWORD)FLOAT_1_0;
  Render::DebugDrawContext::DrawTextAligned(v12, v4 + 20, v7, &sFont_0, &colour, "%s", v13);
  v14 = *(float *)&v5->i_user_data;
  result = v14 <= 0.0;
  *(float *)&v5->i_user_data = v14 - SkookumScript::c_sim_delta;
  return result;
}

// File Line: 230
// RVA: 0x4F1E60
void __fastcall UFG::TSHUD::MthdC_social_set_enabled(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( UFG::UIHKSocialActionManager::mThis )
    UFG::UIHKSocialActionManager::mThis->mSocialEnabled = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 240
// RVA: 0x4E5F60
void __fastcall UFG::TSHUD::MthdC_face_minigame_is_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
  {
    if ( UFG::UIHKSocialActionManager::mThis && UFG::UIHKSocialActionManager::SocialAction.mStartGame )
      *ppResult = (SSInstance *)SSBoolean::pool_new(1);
    else
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 254
// RVA: 0x4EF430
void __fastcall UFG::TSHUD::MthdC_set_visible(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenHud::SetVisible((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 265
// RVA: 0x4E6A30
void __fastcall UFG::TSHUD::MthdC_flash_inventory_icon(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::allocator::free_link *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rdi
  UFG::allocator::free_link *v5; // rax
  UFG::qString *v6; // rbx
  UFG::allocator::free_link *v7; // rax
  signed __int64 v8; // rbx
  __int64 v9; // rsi

  if ( LODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data) == qSymbol_watch.mUID )
  {
    v2 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x58ui64, "TSHUD UIScreenInvoke", 0i64, 1u);
    if ( v2 )
    {
      UFG::UIScreenInvokeValueArgs::UIScreenInvokeValueArgs((UFG::UIScreenInvokeValueArgs *)v2);
      v4 = v3;
    }
    else
    {
      v4 = 0i64;
    }
    if ( v4 )
    {
      v5 = UFG::qMalloc(0x30ui64, "TSHUD qString[]", 0i64);
      if ( v5 )
      {
        LODWORD(v5->mNext) = 1;
        v6 = (UFG::qString *)&v5[1];
        `eh vector constructor iterator'(&v5[1], 0x28ui64, 1, (void (__fastcall *)(void *))UFG::qString::qString);
      }
      else
      {
        v6 = 0i64;
      }
      *(_QWORD *)(v4 + 80) = v6;
      UFG::qString::Set(v6, "watch");
      UFG::qString::Set((UFG::qString *)(v4 + 24), "flashInventoryIcon");
      *(_DWORD *)(v4 + 72) = 1;
      v7 = UFG::qMalloc(0x38ui64, "TSHUD GFxValue[]", 0i64);
      if ( v7 )
      {
        LODWORD(v7->mNext) = 1;
        v8 = (signed __int64)&v7[1];
        `eh vector constructor iterator'(&v7[1], 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      }
      else
      {
        v8 = 0i64;
      }
      *(_QWORD *)(v4 + 64) = v8;
      v9 = *(_QWORD *)(*(_QWORD *)(v4 + 80) + 24i64);
      if ( (*(_DWORD *)(v8 + 24) >> 6) & 1 )
      {
        (*(void (__fastcall **)(_QWORD, signed __int64, _QWORD))(**(_QWORD **)(v8 + 16) + 16i64))(
          *(_QWORD *)(v8 + 16),
          v8,
          *(_QWORD *)(v8 + 32));
        *(_QWORD *)(v8 + 16) = 0i64;
      }
      *(_DWORD *)(v8 + 24) = 6;
      *(_QWORD *)(v8 + 32) = v9;
      UFG::UIHKScreenHud::QueueInvoke((UFG::UIScreenInvoke *)v4);
    }
  }
}

// File Line: 305
// RVA: 0x4DAC90
char __fastcall UFG::TSHUD::Coro_flash_mission_obj(SSInvokedCoroutine *pScope)
{
  UFG::UIHKObjectiveFlasherWidget::Show(
    *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    "mission",
    0);
  return 1;
}

// File Line: 317
// RVA: 0x4E8F10
void __fastcall UFG::TSHUD::MthdC_hide_objective(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKObjectiveFlasherWidget::Clear();
}

// File Line: 323
// RVA: 0x4EE4C0
void __fastcall UFG::TSHUD::MthdC_set_mission_progress(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  SSInstance *v3; // rbx
  unsigned int v4; // edi
  int v5; // eax
  UFG::UIHKMissionProgressSlotData::eState v6; // edx

  v2 = pScope->i_data.i_array_p;
  v3 = v2[1]->i_data_p;
  v4 = v2[2]->i_data_p->i_user_data;
  UFG::UIHKMissionProgressWidget::SetText(
    UFG::UIHKScreenHud::MissionProgress,
    *(const char **)(*v2)->i_data_p->i_user_data,
    v2[2]->i_data_p->i_user_data);
  UFG::UIHKRacePositionWidget::SetVisible((UFG::UIHKRacePositionWidget *)UFG::UIHKScreenHud::MissionProgress, 1);
  v5 = v3->i_user_data;
  if ( v5 == qSymbol_normal_15.mUID )
  {
    v6 = 1;
  }
  else if ( v5 == qSymbol_complete_15.mUID )
  {
    v6 = 5;
  }
  else if ( v5 == qSymbol_incomplete_15.mUID )
  {
    v6 = 4;
  }
  else
  {
    if ( v5 != qSymbol_danger_15.mUID )
      return;
    v6 = 2;
  }
  UFG::UIHKMissionProgressWidget::SetState(UFG::UIHKScreenHud::MissionProgress, v6, v4);
}

// File Line: 351
// RVA: 0x4E8EE0
void __fastcall UFG::TSHUD::MthdC_hide_mission_progress(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKMissionProgressWidget::Clear(UFG::UIHKScreenHud::MissionProgress);
  UFG::UIHKRacePositionWidget::SetVisible((UFG::UIHKRacePositionWidget *)UFG::UIHKScreenHud::MissionProgress, 0);
}

// File Line: 358
// RVA: 0x4E2C40
void __fastcall UFG::TSHUD::MthdC_activate_shortcut_button(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx

  v2 = pScope->i_data.i_array_p;
  if ( LODWORD((*v2)->i_data_p->i_user_data) == qSymbol_ShortcutButton_WorldMapTerritores_15.mUID )
    UFG::UIHKShortcutButtonWidget::Activate(
      UFG::UIHKScreenHud::ShortcutButton,
      TYPE_OCCLUSION,
      SELECT_BUTTON,
      *(const char **)v2[1]->i_data_p->i_user_data,
      *(float *)&v2[2]->i_data_p->i_user_data);
}

// File Line: 380
// RVA: 0x4EE570
void __fastcall UFG::TSHUD::MthdC_set_objective_distance_enabled(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // bl

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( UFG::UIHKScreenHud::getInstance() )
    UFG::UIHKObjectiveDistanceWidget::SetEnabled(UFG::UIHKScreenHud::ObjectiveDistance, v2);
}

// File Line: 391
// RVA: 0x4F0E50
void __fastcall UFG::TSHUD::MthdC_show_turn_hint(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rbx
  UFG::qSymbol icon; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v4; // [rsp+50h] [rbp+18h]

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( UFG::UIHKScreenHud::getInstance() )
  {
    v4 = &icon;
    icon.mUID = v2->i_user_data;
    UFG::UIHKTurnHintWidget::Show(UFG::UIHKScreenHud::TurnHint, (__int64)&icon);
  }
}

// File Line: 402
// RVA: 0x4E8F80
void __fastcall UFG::TSHUD::MthdC_hide_turn_hint(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( UFG::UIHKScreenHud::getInstance() )
    UFG::UIHKTurnHintWidget::Hide(UFG::UIHKScreenHud::TurnHint);
}

// File Line: 411
// RVA: 0x4F2B30
void __fastcall UFG::TSHUD::MthdC_unlock_loading_hint(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  __int64 v2; // rbx
  UFG::GameStatTracker *v3; // rax
  char dest; // [rsp+20h] [rbp-48h]
  UFG::qSymbol result; // [rsp+70h] [rbp+8h]

  v2 = LODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  UFG::qSPrintf(&dest, "%d", v2);
  UFG::qSymbol::create_from_string(&result, &dest);
  v3 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v3, UnlockedLoadingHints, &result, v2);
}

// File Line: 424
// RVA: 0x4F0EA0
void __fastcall UFG::TSHUD::MthdC_show_tutorial_overlay(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  const char *v3; // rdi
  const char *v4; // rbx
  UFG::UIHKScreenGlobalOverlay *v5; // rax

  v2 = pScope->i_data.i_array_p;
  v3 = *(const char **)v2[1]->i_data_p->i_user_data;
  v4 = *(const char **)(*v2)->i_data_p->i_user_data;
  v5 = UFG::UIHKScreenGlobalOverlay::getInstance();
  UFG::UIHKTutorialOverlay::show(&v5->TutorialOverlay, v4, v3);
}

// File Line: 434
// RVA: 0x4E8FB0
void __fastcall UFG::TSHUD::MthdC_hide_tutorial_overlay(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenGlobalOverlay *v2; // rax

  if ( UFG::UIHKScreenGlobalOverlay::hasInstance() )
  {
    v2 = UFG::UIHKScreenGlobalOverlay::getInstance();
    UFG::UIHKTutorialOverlay::hide(&v2->TutorialOverlay);
  }
}

// File Line: 443
// RVA: 0x4E6CE0
void __fastcall UFG::TSHUD::MthdC_flash_upgrade_popup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  SSInstance *v3; // rbx
  SSInstance *v4; // rdi

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p;
  v4 = v2[1]->i_data_p;
  if ( UFG::UIHKScreenHud::getInstance() )
  {
    if ( UFG::UIHKScreenHud::UpgradePopup )
      UFG::UIHKUpgradePopupWidget::Flash(
        UFG::UIHKScreenHud::UpgradePopup,
        *(const char **)v3->i_user_data,
        *(const char **)v4->i_user_data);
  }
}

// File Line: 457
// RVA: 0x4F0F10
void __fastcall UFG::TSHUD::MthdC_show_upgrade_popup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  SSInstance *v3; // rbx
  SSInstance *v4; // rdi

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p;
  v4 = v2[1]->i_data_p;
  if ( UFG::UIHKScreenHud::getInstance() )
  {
    if ( UFG::UIHKScreenHud::UpgradePopup )
      UFG::UIHKUpgradePopupWidget::Show(
        UFG::UIHKScreenHud::UpgradePopup,
        *(const char **)v3->i_user_data,
        *(const char **)v4->i_user_data);
  }
}

// File Line: 471
// RVA: 0x4E8FF0
void __fastcall UFG::TSHUD::MthdC_hide_upgrade_popup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( UFG::UIHKScreenHud::getInstance() )
  {
    if ( UFG::UIHKScreenHud::UpgradePopup )
      UFG::UIHKUpgradePopupWidget::Hide(UFG::UIHKScreenHud::UpgradePopup);
  }
}

// File Line: 505
// RVA: 0x4EF710
void __fastcall UFG::TSHUD::MthdC_set_widget_visible(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  SSInstance *v3; // r8
  UFG::qSymbol widget; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v5; // [rsp+50h] [rbp+18h]

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p;
  LOBYTE(v2) = v2[1]->i_data_p->i_user_data != 0;
  v5 = &widget;
  widget.mUID = v3->i_user_data;
  UFG::UIHKScreenHud::SetWidgetVisible((__int64)&widget, (bool)v2);
}

// File Line: 514
// RVA: 0x4EF6A0
void __fastcall UFG::TSHUD::MthdC_set_widget_highlight(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  SSInstance *v3; // rbx
  bool v4; // di
  UFG::UIHKScreenHud *v5; // rax
  UFG::qSymbol widget; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v7; // [rsp+50h] [rbp+18h]

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p;
  v4 = v2[1]->i_data_p->i_user_data != 0;
  v5 = UFG::UIHKScreenHud::getInstance();
  if ( v5 )
  {
    v7 = &widget;
    widget.mUID = v3->i_user_data;
    UFG::UIHKScreenHud::SetWidgetHighlight(v5, (__int64)&widget, v4);
  }
}

// File Line: 527
// RVA: 0x4EABB0
void __fastcall UFG::TSHUD::MthdC_load_tutorial_textures(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenHud *v2; // rax

  v2 = UFG::UIHKScreenHud::getInstance();
  if ( v2 )
    UFG::UIHKScreenHud::LoadTutorialHudTexturePack(v2);
}

// File Line: 538
// RVA: 0x4F2AC0
void __fastcall UFG::TSHUD::MthdC_unload_tutorial_textures(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenHud *v2; // rax

  v2 = UFG::UIHKScreenHud::getInstance();
  if ( v2 )
    UFG::UIHKScreenHud::UnloadTutorialHudTexturePack(v2);
}

// File Line: 549
// RVA: 0x4E3A00
void __fastcall UFG::TSHUD::MthdC_are_tutorial_textures_loaded(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx

  v2 = ppResult;
  if ( UFG::UIHKScreenHud::getInstance() )
    *v2 = (SSInstance *)SSBoolean::pool_new(UFG::UIHKScreenHud::mOnDemandTexturesLoaded);
}

// File Line: 562
// RVA: 0x4F0EF0
void __fastcall UFG::TSHUD::MthdC_show_tutorial_prompt(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKInfoPopupWidget::ShowTutorialPrompt(
    UFG::UIHKScreenHud::InfoPopup,
    *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 576
// RVA: 0x4ECD20
void __fastcall UFG::TSHUD::MthdC_secondary_tutorial_show(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKSecondaryTutorialWidget::Show(
    UFG::UIHKScreenHud::SecondaryTutorial,
    *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 584
// RVA: 0x4ECD10
void __fastcall UFG::TSHUD::MthdC_secondary_tutorial_hide(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKSecondaryTutorialWidget::Hide(UFG::UIHKScreenHud::SecondaryTutorial);
}

// File Line: 590
// RVA: 0x4F0730
void __fastcall UFG::TSHUD::MthdC_show_phone_trace_signal(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  int v3; // ebx
  int v4; // edi

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p->i_user_data;
  v4 = v2[1]->i_data_p->i_user_data;
  if ( UFG::UIHKScreenHud::getInstance() )
  {
    if ( UFG::UIHKScreenHud::TraceSignalBar )
      UFG::UIHKPhoneTraceSignalBarWidget::Show(UFG::UIHKScreenHud::TraceSignalBar, v3, v4);
  }
}

// File Line: 604
// RVA: 0x4EE690
void __fastcall UFG::TSHUD::MthdC_set_phone_trace_signal(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  int v3; // ebx
  int v4; // edi

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p->i_user_data;
  v4 = v2[1]->i_data_p->i_user_data;
  if ( UFG::UIHKScreenHud::getInstance() )
  {
    if ( UFG::UIHKScreenHud::TraceSignalBar )
      UFG::UIHKPhoneTraceSignalBarWidget::SetStrength(UFG::UIHKScreenHud::TraceSignalBar, v3, v4);
  }
}

// File Line: 618
// RVA: 0x4E8F20
void __fastcall UFG::TSHUD::MthdC_hide_phone_trace_signal(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( UFG::UIHKScreenHud::getInstance() )
  {
    if ( UFG::UIHKScreenHud::TraceSignalBar )
      UFG::UIHKPhoneTraceSignalBarWidget::Hide(UFG::UIHKScreenHud::TraceSignalBar);
  }
}

// File Line: 630
// RVA: 0x4EE650
void __fastcall UFG::TSHUD::MthdC_set_phone_trace_enabled(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenPhoneTraceMinigame::gPhoneTraceEnabled = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( UFG::UIHKScreenHud::getInstance() )
  {
    if ( UFG::UIHKScreenHud::TraceSignalBar )
      UFG::UIHKPhoneTraceSignalBarWidget::SetUpdate(UFG::UIHKScreenHud::TraceSignalBar);
  }
}

// File Line: 646
// RVA: 0x4EE6E0
void __fastcall UFG::TSHUD::MthdC_set_phone_trace_target(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStatTracker *v2; // rax
  UFG::qSymbol id; // [rsp+30h] [rbp+8h]

  id.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v2 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v2, TraceContact, &id);
}

// File Line: 655
// RVA: 0x4EC120
void __fastcall UFG::TSHUD::MthdC_region_show(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_REGION_SHOW_15,
    0xFFFFFFFF);
}

// File Line: 661
// RVA: 0x4EDF80
void __fastcall UFG::TSHUD::MthdC_set_health_ui_state(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // bl

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  UFG::WorldEffectsManager::Get();
  UFG::WorldEffectsManager::sDisableHealthUIs = v2 == 0;
}

// File Line: 670
// RVA: 0x4E9AA0
void __fastcall UFG::TSHUD::MthdC_is_statgame_finalscore_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIHKScreenHud *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::UIHKScreenHud::getInstance();
    if ( v3 && UFG::UIHKScreenHud::IsStatGameShowingFinalScore(v3) )
      *v2 = (SSInstance *)SSBoolean::pool_new(1);
    else
      *v2 = (SSInstance *)SSBoolean::pool_new(0);
  }
}


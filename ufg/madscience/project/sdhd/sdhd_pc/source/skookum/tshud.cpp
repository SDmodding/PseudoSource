// File Line: 80
// RVA: 0x4D3B80
void UFG::TSHUD::BindAtomics(void)
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
  ASymbol rebindj; // [rsp+20h] [rbp-18h]
  ASymbol rebindk; // [rsp+20h] [rbp-18h]
  ASymbol rebindl; // [rsp+20h] [rbp-18h]
  ASymbol rebindm; // [rsp+20h] [rbp-18h]
  ASymbol rebindn; // [rsp+20h] [rbp-18h]
  ASymbol rebindo; // [rsp+20h] [rbp-18h]
  ASymbol rebindp; // [rsp+20h] [rbp-18h]
  ASymbol rebindq; // [rsp+20h] [rbp-18h]
  ASymbol rebindr; // [rsp+20h] [rbp-18h]
  ASymbol rebinds; // [rsp+20h] [rbp-18h]
  ASymbol rebindt; // [rsp+20h] [rbp-18h]
  ASymbol rebindu; // [rsp+20h] [rbp-18h]
  ASymbol rebindv; // [rsp+20h] [rbp-18h]
  ASymbol rebindw; // [rsp+20h] [rbp-18h]
  ASymbol rebindx; // [rsp+20h] [rbp-18h]
  ASymbol rebindy; // [rsp+20h] [rbp-18h]
  ASymbol rebindz; // [rsp+20h] [rbp-18h]
  ASymbol rebindba; // [rsp+20h] [rbp-18h]
  ASymbol rebindbb; // [rsp+20h] [rbp-18h]
  ASymbol rebindbc; // [rsp+20h] [rbp-18h]
  ASymbol rebindbd; // [rsp+20h] [rbp-18h]
  ASymbol rebindbe; // [rsp+20h] [rbp-18h]
  ASymbol rebindbf; // [rsp+20h] [rbp-18h]
  ASymbol rebindbg; // [rsp+20h] [rbp-18h]
  ASymbol rebindbh; // [rsp+20h] [rbp-18h]
  ASymbol rebindbi; // [rsp+20h] [rbp-18h]

  v0 = SSBrain::get_class("HUD");
  SSClass::register_coroutine_func(v0, "_text_xy", UFG::TSHUD::Coro_text_xy, SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(v0, "_text_xyz", UFG::TSHUD::Coro_text_xyz, SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_flash_mission_obj",
    UFG::TSHUD::Coro_flash_mission_obj,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(v0, "social_set_enabled", UFG::TSHUD::MthdC_social_set_enabled, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "face_minigame_is_active", UFG::TSHUD::MthdC_face_minigame_is_active, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "set_mission_progress", UFG::TSHUD::MthdC_set_mission_progress, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "hide_mission_progress", UFG::TSHUD::MthdC_hide_mission_progress, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "hide_objective", UFG::TSHUD::MthdC_hide_objective, 1, rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(v0, "activate_shortcut_button", UFG::TSHUD::MthdC_activate_shortcut_button, 1, rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(v0, "set_visible", UFG::TSHUD::MthdC_set_visible, 1, rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(v0, "flash_inventory_icon", UFG::TSHUD::MthdC_flash_inventory_icon, 1, rebindg);
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_objective_distance_enabled",
    UFG::TSHUD::MthdC_set_objective_distance_enabled,
    1,
    rebindh);
  LOBYTE(rebindi.i_uid) = 0;
  SSClass::register_method_func(v0, "show_turn_hint", UFG::TSHUD::MthdC_show_turn_hint, 1, rebindi);
  LOBYTE(rebindj.i_uid) = 0;
  SSClass::register_method_func(v0, "hide_turn_hint", UFG::TSHUD::MthdC_hide_turn_hint, 1, rebindj);
  LOBYTE(rebindk.i_uid) = 0;
  SSClass::register_method_func(v0, "flash_upgrade_popup", UFG::TSHUD::MthdC_flash_upgrade_popup, 1, rebindk);
  LOBYTE(rebindl.i_uid) = 0;
  SSClass::register_method_func(v0, "show_upgrade_popup", UFG::TSHUD::MthdC_show_upgrade_popup, 1, rebindl);
  LOBYTE(rebindm.i_uid) = 0;
  SSClass::register_method_func(v0, "hide_upgrade_popup", UFG::TSHUD::MthdC_hide_upgrade_popup, 1, rebindm);
  LOBYTE(rebindn.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "show_hud_timer",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    rebindn);
  LOBYTE(rebindo.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "hide_hud_timer",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    rebindo);
  LOBYTE(rebindp.i_uid) = 0;
  SSClass::register_method_func(v0, "unlock_loading_hint", UFG::TSHUD::MthdC_unlock_loading_hint, 1, rebindp);
  LOBYTE(rebindq.i_uid) = 0;
  SSClass::register_method_func(v0, "show_tutorial_overlay", UFG::TSHUD::MthdC_show_tutorial_overlay, 1, rebindq);
  LOBYTE(rebindr.i_uid) = 0;
  SSClass::register_method_func(v0, "hide_tutorial_overlay", UFG::TSHUD::MthdC_hide_tutorial_overlay, 1, rebindr);
  LOBYTE(rebinds.i_uid) = 0;
  SSClass::register_method_func(v0, "set_widget_visible", UFG::TSHUD::MthdC_set_widget_visible, 1, rebinds);
  LOBYTE(rebindt.i_uid) = 0;
  SSClass::register_method_func(v0, "set_widget_highlight", UFG::TSHUD::MthdC_set_widget_highlight, 1, rebindt);
  LOBYTE(rebindu.i_uid) = 0;
  SSClass::register_method_func(v0, "load_tutorial_textures", UFG::TSHUD::MthdC_load_tutorial_textures, 1, rebindu);
  LOBYTE(rebindv.i_uid) = 0;
  SSClass::register_method_func(v0, "unload_tutorial_textures", UFG::TSHUD::MthdC_unload_tutorial_textures, 1, rebindv);
  LOBYTE(rebindw.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "are_tutorial_textures_loaded",
    UFG::TSHUD::MthdC_are_tutorial_textures_loaded,
    1,
    rebindw);
  LOBYTE(rebindx.i_uid) = 0;
  SSClass::register_method_func(v0, "show_tutorial_prompt", UFG::TSHUD::MthdC_show_tutorial_prompt, 1, rebindx);
  LOBYTE(rebindy.i_uid) = 0;
  SSClass::register_method_func(v0, "hide_tutorial_prompt", UFG::TSUI_HUD_HintText::MthdC_hide_info_popup, 1, rebindy);
  LOBYTE(rebindz.i_uid) = 0;
  SSClass::register_method_func(v0, "secondary_tutorial_show", UFG::TSHUD::MthdC_secondary_tutorial_show, 1, rebindz);
  LOBYTE(rebindba.i_uid) = 0;
  SSClass::register_method_func(v0, "secondary_tutorial_hide", UFG::TSHUD::MthdC_secondary_tutorial_hide, 1, rebindba);
  LOBYTE(rebindbb.i_uid) = 0;
  SSClass::register_method_func(v0, "show_phone_trace_signal", UFG::TSHUD::MthdC_show_phone_trace_signal, 1, rebindbb);
  LOBYTE(rebindbc.i_uid) = 0;
  SSClass::register_method_func(v0, "set_phone_trace_signal", UFG::TSHUD::MthdC_set_phone_trace_signal, 1, rebindbc);
  LOBYTE(rebindbd.i_uid) = 0;
  SSClass::register_method_func(v0, "hide_phone_trace_signal", UFG::TSHUD::MthdC_hide_phone_trace_signal, 1, rebindbd);
  LOBYTE(rebindbe.i_uid) = 0;
  SSClass::register_method_func(v0, "set_phone_trace_enabled", UFG::TSHUD::MthdC_set_phone_trace_enabled, 1, rebindbe);
  LOBYTE(rebindbf.i_uid) = 0;
  SSClass::register_method_func(v0, "set_phone_trace_target", UFG::TSHUD::MthdC_set_phone_trace_target, 1, rebindbf);
  LOBYTE(rebindbg.i_uid) = 0;
  SSClass::register_method_func(v0, "region_show", UFG::TSHUD::MthdC_region_show, 1, rebindbg);
  LOBYTE(rebindbh.i_uid) = 0;
  SSClass::register_method_func(v0, "set_health_ui_state", UFG::TSHUD::MthdC_set_health_ui_state, 1, rebindbh);
  LOBYTE(rebindbi.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "is_statgame_finalscore_active",
    UFG::TSHUD::MthdC_is_statgame_finalscore_active,
    1,
    rebindbi);
}

// File Line: 151
// RVA: 0x4DE430
bool __fastcall UFG::TSHUD::Coro_text_xy(SSInvokedCoroutine *pScope)
{
  SSData **i_array_p; // r8
  SSInstance *i_data_p; // r14
  int i_user_data; // r15d
  int v5; // r12d
  SSInstance *v6; // rsi
  SSInstance *v7; // rdi
  unsigned int v8; // r13d
  float *v9; // rbp
  unsigned int v10; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v12; // rax
  Render::DebugDrawContext *Context; // rax
  const char *v14; // r10
  float v15; // xmm1_4
  bool result; // al
  UFG::qColour colour; // [rsp+48h] [rbp-40h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  i_user_data = i_array_p[1]->i_data_p->i_user_data;
  v5 = i_array_p[2]->i_data_p->i_user_data;
  v6 = i_array_p[3]->i_data_p;
  v7 = i_array_p[4]->i_data_p;
  v8 = i_array_p[5]->i_data_p->i_user_data;
  v9 = (float *)i_array_p[6]->i_data_p->i_user_data;
  if ( (_S13_5 & 1) == 0 )
  {
    _S13_5 |= 1u;
    UFG::qResourceHandle::qResourceHandle(&sFont);
    atexit(UFG::TSHUD::Coro_text_xy_::_2_::_dynamic_atexit_destructor_for__sFont__);
  }
  if ( !pScope->i_update_count && !sFont.mNameUID )
  {
    v10 = UFG::qStringHash32(*(const char **)v7->i_user_data, 0xFFFFFFFF);
    Inventory = `UFG::qGetResourceInventory<Render::Font>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::Font>::`2::result )
    {
      v12 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v12, 0x69FCCB4Cu);
      `UFG::qGetResourceInventory<Render::Font>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&sFont, 0x69FCCB4Cu, v10, Inventory);
  }
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v14 = *(const char **)i_data_p->i_user_data;
  colour.r = *v9;
  colour.g = v9[1];
  colour.b = v9[2];
  LODWORD(colour.a) = (_DWORD)FLOAT_1_0;
  Render::DebugDrawContext::DrawTextAligned(Context, i_user_data, v5, v8, &sFont, &colour, "%s", v14);
  v15 = *(float *)&v6->i_user_data;
  result = v15 <= 0.0;
  *(float *)&v6->i_user_data = v15 - SkookumScript::c_sim_delta;
  return result;
}

// File Line: 193
// RVA: 0x4DE5F0
bool __fastcall UFG::TSHUD::Coro_text_xyz(SSInvokedCoroutine *pScope)
{
  SSData **i_array_p; // r8
  SSInstance *i_data_p; // r14
  UFG::qVector3 *i_user_data; // r15
  SSInstance *v5; // rsi
  SSInstance *v6; // rdi
  unsigned int v7; // r12d
  float *v8; // rbp
  unsigned int v9; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v11; // rax
  Render::DebugDrawContext *Context; // rax
  const char *v13; // r10
  float v14; // xmm1_4
  bool result; // al
  UFG::qColour colour; // [rsp+48h] [rbp-30h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  i_user_data = (UFG::qVector3 *)i_array_p[1]->i_data_p->i_user_data;
  v5 = i_array_p[2]->i_data_p;
  v6 = i_array_p[3]->i_data_p;
  v7 = i_array_p[4]->i_data_p->i_user_data;
  v8 = (float *)i_array_p[5]->i_data_p->i_user_data;
  if ( (_S14_1 & 1) == 0 )
  {
    _S14_1 |= 1u;
    UFG::qResourceHandle::qResourceHandle(&sFont_0);
    atexit(UFG::TSHUD::Coro_text_xyz_::_2_::_dynamic_atexit_destructor_for__sFont__);
  }
  if ( !pScope->i_update_count && !sFont_0.mNameUID )
  {
    v9 = UFG::qStringHash32(*(const char **)v6->i_user_data, 0xFFFFFFFF);
    Inventory = `UFG::qGetResourceInventory<Render::Font>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::Font>::`2::result )
    {
      v11 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v11, 0x69FCCB4Cu);
      `UFG::qGetResourceInventory<Render::Font>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&sFont_0, 0x69FCCB4Cu, v9, Inventory);
  }
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v13 = *(const char **)i_data_p->i_user_data;
  colour.r = *v8;
  colour.g = v8[1];
  colour.b = v8[2];
  LODWORD(colour.a) = (_DWORD)FLOAT_1_0;
  Render::DebugDrawContext::DrawTextAligned(Context, i_user_data + 20, v7, &sFont_0, &colour, "%s", v13);
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
      *ppResult = SSBoolean::pool_new(1);
    else
      *ppResult = SSBoolean::pool_new(0);
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
  UFG::allocator::free_link *v8; // rbx
  UFG::allocator::free_link *v9; // rsi

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
        `eh vector constructor iterator(&v5[1], 0x28ui64, 1, (void (__fastcall *)(void *))UFG::qString::qString);
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
        v8 = v7 + 1;
        `eh vector constructor iterator(&v7[1], 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      }
      else
      {
        v8 = 0i64;
      }
      *(_QWORD *)(v4 + 64) = v8;
      v9 = *(UFG::allocator::free_link **)(*(_QWORD *)(v4 + 80) + 24i64);
      if ( ((__int64)v8[3].mNext & 0x40) != 0 )
      {
        ((void (__fastcall *)(UFG::allocator::free_link *, UFG::allocator::free_link *, UFG::allocator::free_link *))v8[2].mNext->mNext[2].mNext)(
          v8[2].mNext,
          v8,
          v8[4].mNext);
        v8[2].mNext = 0i64;
      }
      LODWORD(v8[3].mNext) = 6;
      v8[4].mNext = v9;
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
// attributes: thunk
void __fastcall UFG::TSHUD::MthdC_hide_objective(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKObjectiveFlasherWidget::Clear();
}

// File Line: 323
// RVA: 0x4EE4C0
void __fastcall UFG::TSHUD::MthdC_set_mission_progress(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rbx
  unsigned int i_user_data; // edi
  int v5; // eax
  UFG::UIHKMissionProgressSlotData::eState v6; // edx

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = i_array_p[1]->i_data_p;
  i_user_data = i_array_p[2]->i_data_p->i_user_data;
  UFG::UIHKMissionProgressWidget::SetText(
    UFG::UIHKScreenHud::MissionProgress,
    *(const char **)(*i_array_p)->i_data_p->i_user_data,
    i_user_data);
  UFG::UIHKRacePositionWidget::SetVisible((UFG::UIHKRacePositionWidget *)UFG::UIHKScreenHud::MissionProgress, 1);
  v5 = i_data_p->i_user_data;
  if ( v5 == qSymbol_normal_15.mUID )
  {
    v6 = STATE_NORMAL;
  }
  else if ( v5 == qSymbol_complete_15.mUID )
  {
    v6 = STATE_ANIMATE_COMPLETE;
  }
  else if ( v5 == qSymbol_incomplete_15.mUID )
  {
    v6 = STATE_INCOMPLETE;
  }
  else
  {
    if ( v5 != qSymbol_danger_15.mUID )
      return;
    v6 = STATE_DANGER;
  }
  UFG::UIHKMissionProgressWidget::SetState(UFG::UIHKScreenHud::MissionProgress, v6, i_user_data);
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
  SSData **i_array_p; // rdx

  i_array_p = pScope->i_data.i_array_p;
  if ( LODWORD((*i_array_p)->i_data_p->i_user_data) == qSymbol_ShortcutButton_WorldMapTerritores_15.mUID )
    UFG::UIHKShortcutButtonWidget::Activate(
      UFG::UIHKScreenHud::ShortcutButton,
      TYPE_OCCLUSION,
      SELECT_BUTTON,
      *(const char **)i_array_p[1]->i_data_p->i_user_data,
      *(float *)&i_array_p[2]->i_data_p->i_user_data);
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
  SSInstance *i_data_p; // rbx
  UFG::qSymbol icon; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_icon; // [rsp+50h] [rbp+18h]

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( UFG::UIHKScreenHud::getInstance() )
  {
    p_icon = &icon;
    icon.mUID = i_data_p->i_user_data;
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
  __int64 i_user_data_low; // rbx
  UFG::GameStatTracker *v3; // rax
  char dest[72]; // [rsp+20h] [rbp-48h] BYREF
  UFG::qSymbol result; // [rsp+70h] [rbp+8h] BYREF

  i_user_data_low = LODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  UFG::qSPrintf(dest, "%d", i_user_data_low);
  UFG::qSymbol::create_from_string(&result, dest);
  v3 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v3, UnlockedLoadingHints, &result, i_user_data_low);
}

// File Line: 424
// RVA: 0x4F0EA0
void __fastcall UFG::TSHUD::MthdC_show_tutorial_overlay(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  const char *v3; // rdi
  const char *v4; // rbx
  UFG::UIHKScreenGlobalOverlay *Instance; // rax

  i_array_p = pScope->i_data.i_array_p;
  v3 = *(const char **)i_array_p[1]->i_data_p->i_user_data;
  v4 = *(const char **)(*i_array_p)->i_data_p->i_user_data;
  Instance = UFG::UIHKScreenGlobalOverlay::getInstance();
  UFG::UIHKTutorialOverlay::show(&Instance->TutorialOverlay, v4, v3);
}

// File Line: 434
// RVA: 0x4E8FB0
void __fastcall UFG::TSHUD::MthdC_hide_tutorial_overlay(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenGlobalOverlay *Instance; // rax

  if ( UFG::UIHKScreenGlobalOverlay::hasInstance() )
  {
    Instance = UFG::UIHKScreenGlobalOverlay::getInstance();
    UFG::UIHKTutorialOverlay::hide(&Instance->TutorialOverlay);
  }
}

// File Line: 443
// RVA: 0x4E6CE0
void __fastcall UFG::TSHUD::MthdC_flash_upgrade_popup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rbx
  SSInstance *v4; // rdi

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v4 = i_array_p[1]->i_data_p;
  if ( UFG::UIHKScreenHud::getInstance() )
  {
    if ( UFG::UIHKScreenHud::UpgradePopup )
      UFG::UIHKUpgradePopupWidget::Flash(
        UFG::UIHKScreenHud::UpgradePopup,
        *(const char **)i_data_p->i_user_data,
        *(const char **)v4->i_user_data);
  }
}

// File Line: 457
// RVA: 0x4F0F10
void __fastcall UFG::TSHUD::MthdC_show_upgrade_popup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rbx
  SSInstance *v4; // rdi

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v4 = i_array_p[1]->i_data_p;
  if ( UFG::UIHKScreenHud::getInstance() )
  {
    if ( UFG::UIHKScreenHud::UpgradePopup )
      UFG::UIHKUpgradePopupWidget::Show(
        UFG::UIHKScreenHud::UpgradePopup,
        *(const char **)i_data_p->i_user_data,
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
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // r8
  UFG::qSymbol widget; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_widget; // [rsp+50h] [rbp+18h]

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  LOBYTE(i_array_p) = i_array_p[1]->i_data_p->i_user_data != 0;
  p_widget = &widget;
  widget.mUID = i_data_p->i_user_data;
  UFG::UIHKScreenHud::SetWidgetVisible((__int64)&widget, (bool)i_array_p);
}

// File Line: 514
// RVA: 0x4EF6A0
void __fastcall UFG::TSHUD::MthdC_set_widget_highlight(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rbx
  bool v4; // di
  UFG::UIHKScreenHud *Instance; // rax
  UFG::qSymbol widget; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_widget; // [rsp+50h] [rbp+18h]

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v4 = i_array_p[1]->i_data_p->i_user_data != 0;
  Instance = UFG::UIHKScreenHud::getInstance();
  if ( Instance )
  {
    p_widget = &widget;
    widget.mUID = i_data_p->i_user_data;
    UFG::UIHKScreenHud::SetWidgetHighlight(Instance, (__int64)&widget, v4);
  }
}

// File Line: 527
// RVA: 0x4EABB0
void __fastcall UFG::TSHUD::MthdC_load_tutorial_textures(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenHud *Instance; // rax

  Instance = UFG::UIHKScreenHud::getInstance();
  if ( Instance )
    UFG::UIHKScreenHud::LoadTutorialHudTexturePack(Instance);
}

// File Line: 538
// RVA: 0x4F2AC0
void __fastcall UFG::TSHUD::MthdC_unload_tutorial_textures(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenHud *Instance; // rax

  Instance = UFG::UIHKScreenHud::getInstance();
  if ( Instance )
    UFG::UIHKScreenHud::UnloadTutorialHudTexturePack(Instance);
}

// File Line: 549
// RVA: 0x4E3A00
void __fastcall UFG::TSHUD::MthdC_are_tutorial_textures_loaded(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( UFG::UIHKScreenHud::getInstance() )
    *ppResult = SSBoolean::pool_new(UFG::UIHKScreenHud::mOnDemandTexturesLoaded);
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
  SSData **i_array_p; // r8
  int i_user_data; // ebx
  int v4; // edi

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (*i_array_p)->i_data_p->i_user_data;
  v4 = i_array_p[1]->i_data_p->i_user_data;
  if ( UFG::UIHKScreenHud::getInstance() )
  {
    if ( UFG::UIHKScreenHud::TraceSignalBar )
      UFG::UIHKPhoneTraceSignalBarWidget::Show(UFG::UIHKScreenHud::TraceSignalBar, i_user_data, v4);
  }
}

// File Line: 604
// RVA: 0x4EE690
void __fastcall UFG::TSHUD::MthdC_set_phone_trace_signal(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  int i_user_data; // ebx
  int v4; // edi

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (*i_array_p)->i_data_p->i_user_data;
  v4 = i_array_p[1]->i_data_p->i_user_data;
  if ( UFG::UIHKScreenHud::getInstance() )
  {
    if ( UFG::UIHKScreenHud::TraceSignalBar )
      UFG::UIHKPhoneTraceSignalBarWidget::SetStrength(UFG::UIHKScreenHud::TraceSignalBar, i_user_data, v4);
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
  UFG::qSymbol id; // [rsp+30h] [rbp+8h] BYREF

  id.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v2 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v2, TraceContact, &id);
}

// File Line: 655
// RVA: 0x4EC120
void __fastcall UFG::TSHUD::MthdC_region_show(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_REGION_SHOW_15, 0xFFFFFFFF);
}

// File Line: 661
// RVA: 0x4EDF80
void __fastcall UFG::TSHUD::MthdC_set_health_ui_state(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // bl

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  UFG::WorldEffectsManager::Get();
  UFG::WorldEffectsManager::sDisableHealthUIs = !v2;
}

// File Line: 670
// RVA: 0x4E9AA0
void __fastcall UFG::TSHUD::MthdC_is_statgame_finalscore_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenHud *Instance; // rax

  if ( ppResult )
  {
    Instance = UFG::UIHKScreenHud::getInstance();
    if ( Instance && UFG::UIHKScreenHud::IsStatGameShowingFinalScore(Instance) )
      *ppResult = SSBoolean::pool_new(1);
    else
      *ppResult = SSBoolean::pool_new(0);
  }
}


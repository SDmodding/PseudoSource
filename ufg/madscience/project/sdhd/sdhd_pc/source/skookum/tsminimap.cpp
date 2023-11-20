// File Line: 52
// RVA: 0x4D45B0
void UFG::TSMinimap::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("Minimap");
  SSClass::register_method_func(v0, "add_blip_xy", UFG::TSMinimap::MthdC_add_blip_xy, 1, 0);
  SSClass::register_method_func(v0, "remove_blip", UFG::TSMinimap::MthdC_remove_blip, 1, 0);
  SSClass::register_method_func(v0, "show_blip_range", UFG::TSMinimap::MthdC_show_blip_range, 1, 0);
  SSClass::register_method_func(v0, "show_blip_donut_range", UFG::TSMinimap::MthdC_show_blip_donut_range, 1, 0);
  SSClass::register_method_func(v0, "set_blip_range", UFG::TSMinimap::MthdC_set_blip_range, 1, 0);
  SSClass::register_method_func(v0, "hide_blip_range", UFG::TSMinimap::MthdC_hide_blip_range, 1, 0);
  SSClass::register_method_func(v0, "ping_blip", UFG::TSMinimap::MthdC_ping_blip, 1, 0);
  SSClass::register_method_func(v0, "stop_pinging", UFG::TSMinimap::MthdC_stop_pinging, 1, 0);
  SSClass::register_method_func(v0, "set_blip_type_visible", UFG::TSMinimap::MthdC_set_blip_type_visible, 1, 0);
  SSClass::register_method_func(v0, "get_zoom", UFG::TSMinimap::MthdC_get_zoom, 1, 0);
  SSClass::register_method_func(v0, "lock_zoom", UFG::TSMinimap::MthdC_lock_zoom, 1, 0);
  SSClass::register_method_func(v0, "unlock_zoom", UFG::TSMinimap::MthdC_unlock_zoom, 1, 0);
  SSClass::register_method_func(v0, "get_gps_path_length", UFG::TSMinimap::MthdC_get_gps_path_length, 1, 0);
  SSClass::register_method_func(v0, "set_gps_active", UFG::TSMinimap::MthdC_set_gps_active, 1, 0);
  SSClass::register_method_func(v0, "set_gps_visible", UFG::TSMinimap::MthdC_set_gps_visible, 1, 0);
  SSClass::register_method_func(v0, "ping", UFG::TSMinimap::MthdC_ping, 1, 0);
  SSClass::register_method_func(v0, "force_interior_map", UFG::TSMinimap::MthdC_force_interior_map, 1, 0);
  SSClass::register_method_func(v0, "set_gps_ignore_alley", UFG::TSMinimap::MthdC_set_gps_ignore_alley, 1, 0);
  SSClass::register_method_func(v0, "map_lines_add", UFG::TSMinimap::MthdC_map_lines_add, 1, 0);
  SSClass::register_method_func(v0, "map_lines_add_list", UFG::TSMinimap::MthdC_map_lines_add_list, 1, 0);
  SSClass::register_method_func(v0, "map_lines_add_strip", UFG::TSMinimap::MthdC_map_lines_add_strip, 1, 0);
  SSClass::register_method_func(v0, "map_lines_clear", UFG::TSMinimap::MthdC_map_lines_clear, 1, 0);
}

// File Line: 89
// RVA: 0x4E2D00
void __fastcall UFG::TSMinimap::MthdC_add_blip_xy(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIMapBlipManager *v2; // rbx
  SSInvokedMethod *v3; // rdi
  unsigned int v4; // edx
  SSInstance *v5; // rax
  SSClass *v6; // r8
  SSData **v7; // r8
  float *v8; // r11
  SSInstance *v9; // rdi
  SSInstance *v10; // rsi
  bool v11; // bp
  UFG::UIMapBlip *v12; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+18h]

  v2 = UFG::UIHKScreenHud::mIconManager;
  v3 = pScope;
  if ( UFG::UIHKScreenHud::mIconManager )
  {
    v4 = UFG::gNullQSymbol.mUID;
    v5 = (*pScope->i_data.i_array_p)->i_data_p;
    if ( v5 )
    {
      v6 = v5->i_class_p;
      if ( v6 == SSBrain::c_symbol_class_p )
      {
        v4 = v5->i_user_data;
      }
      else if ( v6 == SSBrain::c_string_class_p )
      {
        v4 = UFG::qSymbol::create_from_string(&result, *(const char **)v5->i_user_data)->mUID;
      }
    }
    v7 = v3->i_data.i_array_p;
    v9 = v7[5]->i_data_p;
    v10 = v7[6]->i_data_p;
    v11 = v7[4]->i_data_p->i_user_data != 0;
    if ( v4 != -1
      && v7[1]->i_data_p != (SSInstance *)-32i64
      && v7[2]->i_data_p != (SSInstance *)-32i64
      && v7[3]->i_data_p != (SSInstance *)-32i64 )
    {
      v8 = (float *)&v7[3]->i_data_p->i_user_data;
      v12 = UFG::UIMapBlipManager::CreateIcon(
              v2,
              v4,
              *(const char **)v7[1]->i_data_p->i_user_data,
              *(float *)&v7[2]->i_data_p->i_user_data,
              *v8,
              *v8);
      if ( v12 )
      {
        v12->mHasAltitude = 0;
        v12->mUseCustomFilterDistance = v11;
        v12->mCustomFilterDistance = *(float *)&v9->i_user_data;
        UFG::UIMapBlip::SetWorldMapCaption(v12, *(const char **)v10->i_user_data);
      }
    }
  }
}

// File Line: 143
// RVA: 0x4EC1B0
void __fastcall UFG::TSMinimap::MthdC_remove_blip(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( UFG::UIHKScreenHud::mIconManager )
    UFG::UIMapBlipManager::RemoveIcon(
      UFG::UIHKScreenHud::mIconManager,
      (*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 155
// RVA: 0x4E8A20
void __fastcall UFG::TSMinimap::MthdC_get_zoom(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  float v3; // xmm6_4
  UFG::UIHKScreenHud *v4; // rax

  v2 = ppResult;
  v3 = 0.0;
  v4 = UFG::UIHKScreenHud::getInstance();
  if ( v4 )
    v3 = UFG::UITiledMapWidget::GetZoom(&v4->Minimap);
  *v2 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v3));
}

// File Line: 169
// RVA: 0x4EAD40
void __fastcall UFG::TSMinimap::MthdC_lock_zoom(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( (*pScope->i_data.i_array_p)->i_data_p != (SSInstance *)-32i64 )
    UFG::UITiledMapZoomCalc::LockScale(*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 180
// RVA: 0x4F2BF0
void __fastcall UFG::TSMinimap::MthdC_unlock_zoom(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UITiledMapZoomCalc::UnlockScale();
}

// File Line: 186
// RVA: 0x4EFF10
void __fastcall UFG::TSMinimap::MthdC_show_blip_range(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSData *v3; // rax

  v2 = pScope->i_data.i_array_p;
  v3 = v2[2];
  if ( (*v2)->i_data_p != (SSInstance *)-32i64
    && v2[1]->i_data_p != (SSInstance *)-32i64
    && v3->i_data_p != (SSInstance *)-32i64 )
  {
    if ( UFG::UIHKScreenHud::mIconManager )
      UFG::UIMapBlipManager::AddIconRadius(
        UFG::UIHKScreenHud::mIconManager,
        (*v2)->i_data_p->i_user_data,
        *(float *)&v2[1]->i_data_p->i_user_data,
        v3->i_data_p->i_user_data,
        *(float *)&v2[3]->i_data_p->i_user_data);
  }
}

// File Line: 205
// RVA: 0x4EFE80
void __fastcall UFG::TSMinimap::MthdC_show_blip_donut_range(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  SSData *v3; // rax

  v2 = pScope->i_data.i_array_p;
  v3 = v2[4];
  if ( (*v2)->i_data_p != (SSInstance *)-32i64
    && v2[1]->i_data_p != (SSInstance *)-32i64
    && v2[2]->i_data_p != (SSInstance *)-32i64
    && v3->i_data_p != (SSInstance *)-32i64
    && v2[3]->i_data_p != (SSInstance *)-32i64 )
  {
    if ( UFG::UIHKScreenHud::mIconManager )
      UFG::UIMapBlipManager::AddIconDonutRadius(
        UFG::UIHKScreenHud::mIconManager,
        (*v2)->i_data_p->i_user_data,
        *(float *)&v2[1]->i_data_p->i_user_data,
        *(float *)&v2[2]->i_data_p->i_user_data,
        v2[3]->i_data_p->i_user_data,
        v3->i_data_p->i_user_data);
  }
}

// File Line: 226
// RVA: 0x4E8EA0
void __fastcall UFG::TSMinimap::MthdC_hide_blip_range(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( (*pScope->i_data.i_array_p)->i_data_p != (SSInstance *)-32i64 )
  {
    if ( UFG::UIHKScreenHud::mIconManager )
      UFG::UIMapBlipManager::RemoveIconRadius(
        UFG::UIHKScreenHud::mIconManager,
        (*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 242
// RVA: 0x4ED380
void __fastcall UFG::TSMinimap::MthdC_set_blip_range(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSData *v3; // rax

  v2 = pScope->i_data.i_array_p;
  v3 = v2[2];
  if ( (*v2)->i_data_p != (SSInstance *)-32i64
    && v2[1]->i_data_p != (SSInstance *)-32i64
    && v3->i_data_p != (SSInstance *)-32i64 )
  {
    if ( UFG::UIHKScreenHud::mIconManager )
      UFG::UIMapBlipManager::ChangeIconRadius(
        UFG::UIHKScreenHud::mIconManager,
        (*v2)->i_data_p->i_user_data,
        *(float *)&v2[1]->i_data_p->i_user_data,
        v3->i_data_p->i_user_data,
        *(float *)&v2[3]->i_data_p->i_user_data);
  }
}

// File Line: 261
// RVA: 0x4EB220
void __fastcall UFG::TSMinimap::MthdC_ping_blip(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rsi
  SSActor *v3; // rbx
  SSClass *v4; // rdi
  unsigned int v5; // edi
  UFG::SimObject *v6; // rcx
  UFG::HudComponent *v7; // rax
  UFG::BasePhysicsSystem *v8; // rbx
  unsigned int v9; // eax
  UFG::qBaseTreeRB *v10; // rax
  UFG::UIMapBlip *v11; // rbx

  v2 = pScope;
  v3 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !v3 )
    goto LABEL_6;
  v4 = v3->i_class_p;
  if ( !v4->vfptr->is_actor_class((SSClassDescBase *)&v4->vfptr) )
  {
    if ( v4 == SSBrain::c_symbol_class_p && LODWORD(v3->i_user_data) != -1 )
    {
      v3 = SSActor::find((ASymbol *)&v3->i_user_data);
      goto LABEL_7;
    }
LABEL_6:
    v3 = 0i64;
  }
LABEL_7:
  v5 = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64);
  if ( v3 )
  {
    v6 = *(UFG::SimObject **)&v3[1].i_icoroutines_to_update.i_count;
    if ( v6 )
    {
      v7 = (UFG::HudComponent *)UFG::SimObject::GetComponentOfType(v6, UFG::HudComponent::_TypeUID);
      v8 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
      if ( UFG::UIHKScreenHud::mIconManager )
      {
        if ( v7 )
        {
          v9 = UFG::HudComponent::GetBlipGuid(v7);
          v10 = UFG::BasePhysicsSystem::GetCollisionModel(v8, v9);
          v11 = (UFG::UIMapBlip *)v10;
          if ( v10 )
          {
            UFG::UIMapBlip::SetBlinkMaxTimes((UFG::UIMapBlip *)v10, v5);
            UFG::UIMapBlip::Blink(v11);
          }
        }
      }
    }
  }
}

// File Line: 292
// RVA: 0x4F2750
void __fastcall UFG::TSMinimap::MthdC_stop_pinging(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSActor *v2; // rbx
  SSClass *v3; // rdi
  UFG::SimObject *v4; // rcx
  UFG::HudComponent *v5; // rax
  UFG::BasePhysicsSystem *v6; // rbx
  unsigned int v7; // eax
  UFG::qBaseTreeRB *v8; // rax

  v2 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( v2 )
  {
    v3 = v2->i_class_p;
    if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSInstance **))v3->vfptr->is_actor_class)(v2->i_class_p, ppResult) )
    {
      if ( v3 != SSBrain::c_symbol_class_p || LODWORD(v2->i_user_data) == -1 )
        return;
      v2 = SSActor::find((ASymbol *)&v2->i_user_data);
    }
    if ( v2 )
    {
      v4 = *(UFG::SimObject **)&v2[1].i_icoroutines_to_update.i_count;
      if ( v4 )
      {
        v5 = (UFG::HudComponent *)UFG::SimObject::GetComponentOfType(v4, UFG::HudComponent::_TypeUID);
        v6 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
        if ( UFG::UIHKScreenHud::mIconManager )
        {
          if ( v5 )
          {
            v7 = UFG::HudComponent::GetBlipGuid(v5);
            v8 = UFG::BasePhysicsSystem::GetCollisionModel(v6, v7);
            if ( v8 )
              UFG::UIMapBlip::StopBlink((UFG::UIMapBlip *)v8);
          }
        }
      }
    }
  }
}

// File Line: 319
// RVA: 0x4ED3F0
void __fastcall UFG::TSMinimap::MthdC_set_blip_type_visible(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  bool v3; // bl
  UFG::UIMapBlipTypeManager *v4; // rax
  UFG::qSymbolUC result; // [rsp+30h] [rbp+8h]

  v2 = pScope->i_data.i_array_p;
  v3 = v2[1]->i_data_p->i_user_data != 0;
  UFG::qSymbolUC::create_from_string(&result, *(const char **)(*v2)->i_data_p->i_user_data);
  v4 = UFG::UIMapBlipTypeManager::getInstance();
  UFG::UIMapBlipTypeManager::GetType(v4, &result)->IsVisible = v3;
}

// File Line: 331
// RVA: 0x4E7940
void __fastcall UFG::TSMinimap::MthdC_get_gps_path_length(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  float v3; // xmm0_4

  v2 = ppResult;
  v3 = 0.0;
  if ( UFG::UIHKScreenHud::GPS )
    v3 = UFG::UITiledMapGPS::GetPathLength(UFG::UIHKScreenHud::GPS);
  *v2 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v3));
}

// File Line: 341
// RVA: 0x4EDEC0
void __fastcall UFG::TSMinimap::MthdC_set_gps_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  UFG::qVector3 *v3; // rbx

  v2 = pScope->i_data.i_array_p;
  v3 = (UFG::qVector3 *)v2[1]->i_data_p->i_user_data;
  UFG::UITiledMapGPS::SetActive(UFG::UIHKScreenHud::GPS, (*v2)->i_data_p->i_user_data != 0);
  if ( v3 && (-9999.0 != v3->x || -9999.0 != v3->y) )
  {
    UFG::UITiledMapWidget::SetGPSLineColor(&UFG::UITiledMapWidget::DefaultGPSLineColor);
    UFG::UITiledMapGPS::SetDestination(UFG::UIHKScreenHud::GPS, v3, 0);
  }
}

// File Line: 359
// RVA: 0x4EDF60
void __fastcall UFG::TSMinimap::MthdC_set_gps_visible(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UITiledMapGPS::SetVisible(UFG::UIHKScreenHud::GPS, (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 367
// RVA: 0x4EB210
void __fastcall UFG::TSMinimap::MthdC_ping(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenHud::PingMinimap();
}

// File Line: 373
// RVA: 0x4E6D40
void __fastcall UFG::TSMinimap::MthdC_force_interior_map(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UITiledMapTweakables::MinimapForceIndoors = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 381
// RVA: 0x4EADA0
void __fastcall UFG::TSMinimap::MthdC_map_lines_add(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  float *v3; // r8
  float *v4; // rax
  float v5; // xmm1_4
  float v6; // xmm0_4
  UFG::UIHKMapLine line; // [rsp+20h] [rbp-18h]

  v2 = pScope->i_data.i_array_p;
  v3 = (float *)(*v2)->i_data_p->i_user_data;
  v4 = (float *)v2[1]->i_data_p->i_user_data;
  if ( v3 )
  {
    if ( v4 )
    {
      v5 = v3[1];
      line.start.x = *v3;
      line.start.y = v5;
      v6 = v4[1];
      line.end.x = *v4;
      line.end.y = v6;
      UFG::UIMapLinesWidget::Add(UFG::UIHKScreenHud::MapLines, &line);
      UFG::UIMapLinesWidget::SetVisible(UFG::UIHKScreenHud::MapLines, 1);
    }
  }
}

// File Line: 397
// RVA: 0x4EAE20
void __fastcall UFG::TSMinimap::MthdC_map_lines_add_list(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned __int64 v2; // rcx
  _QWORD *v3; // rbx
  __int64 v4; // rdi
  float *v5; // rcx
  float *v6; // rdx
  float v7; // xmm1_4
  float v8; // xmm0_4
  UFG::UIHKMapLine line; // [rsp+20h] [rbp-18h]

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = *(_QWORD **)(v2 + 8);
  if ( *(_DWORD *)v2 != 1 )
  {
    v4 = ((unsigned int)(*(_DWORD *)v2 - 2) >> 1) + 1;
    do
    {
      v5 = *(float **)(*v3 + 32i64);
      v6 = *(float **)(v3[1] + 32i64);
      v7 = v5[1];
      line.start.x = *v5;
      line.start.y = v7;
      v8 = v6[1];
      line.end.x = *v6;
      line.end.y = v8;
      UFG::UIMapLinesWidget::Add(UFG::UIHKScreenHud::MapLines, &line);
      v3 += 2;
      --v4;
    }
    while ( v4 );
  }
  UFG::UIMapLinesWidget::SetVisible(UFG::UIHKScreenHud::MapLines, 1);
}

// File Line: 417
// RVA: 0x4EAEC0
void __fastcall UFG::TSMinimap::MthdC_map_lines_add_strip(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned __int64 v2; // rcx
  unsigned int v3; // edx
  __int64 v4; // rdi
  float *v5; // rbx
  signed __int64 v6; // rdi
  __int64 v7; // rsi
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  UFG::UIHKMapLine line; // [rsp+20h] [rbp-18h]

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = *(_DWORD *)v2;
  v4 = *(_QWORD *)(v2 + 8);
  if ( *(_DWORD *)v2 >= 1u )
  {
    v5 = *(float **)(*(_QWORD *)v4 + 32i64);
    if ( v3 > 1 )
    {
      v6 = v4 + 8;
      v7 = v3 - 1;
      do
      {
        v8 = *v5;
        v9 = v5[1];
        v5 = *(float **)(*(_QWORD *)v6 + 32i64);
        line.start.x = v8;
        line.start.y = v9;
        v10 = v5[1];
        line.end.x = *v5;
        line.end.y = v10;
        UFG::UIMapLinesWidget::Add(UFG::UIHKScreenHud::MapLines, &line);
        v6 += 8i64;
        --v7;
      }
      while ( v7 );
    }
    UFG::UIMapLinesWidget::SetVisible(UFG::UIHKScreenHud::MapLines, 1);
  }
}

// File Line: 441
// RVA: 0x4EAF70
void __fastcall UFG::TSMinimap::MthdC_map_lines_clear(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIMapLinesWidget::Clear(UFG::UIHKScreenHud::MapLines);
  UFG::UIMapLinesWidget::SetVisible(UFG::UIHKScreenHud::MapLines, 0);
}

// File Line: 447
// RVA: 0x4EDF40
void __fastcall UFG::TSMinimap::MthdC_set_gps_ignore_alley(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UITiledMapGPS::SetWayfinderIgnoreAlleys(
    UFG::UIHKScreenHud::GPS,
    (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}


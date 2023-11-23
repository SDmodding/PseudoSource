// File Line: 52
// RVA: 0x4D45B0
void UFG::TSMinimap::BindAtomics(void)
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

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("Minimap");
  SSClass::register_method_func(v0, "add_blip_xy", UFG::TSMinimap::MthdC_add_blip_xy, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "remove_blip", UFG::TSMinimap::MthdC_remove_blip, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "show_blip_range", UFG::TSMinimap::MthdC_show_blip_range, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "show_blip_donut_range", UFG::TSMinimap::MthdC_show_blip_donut_range, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "set_blip_range", UFG::TSMinimap::MthdC_set_blip_range, 1, rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(v0, "hide_blip_range", UFG::TSMinimap::MthdC_hide_blip_range, 1, rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(v0, "ping_blip", UFG::TSMinimap::MthdC_ping_blip, 1, rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(v0, "stop_pinging", UFG::TSMinimap::MthdC_stop_pinging, 1, rebindg);
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_func(v0, "set_blip_type_visible", UFG::TSMinimap::MthdC_set_blip_type_visible, 1, rebindh);
  LOBYTE(rebindi.i_uid) = 0;
  SSClass::register_method_func(v0, "get_zoom", UFG::TSMinimap::MthdC_get_zoom, 1, rebindi);
  LOBYTE(rebindj.i_uid) = 0;
  SSClass::register_method_func(v0, "lock_zoom", UFG::TSMinimap::MthdC_lock_zoom, 1, rebindj);
  LOBYTE(rebindk.i_uid) = 0;
  SSClass::register_method_func(v0, "unlock_zoom", UFG::TSMinimap::MthdC_unlock_zoom, 1, rebindk);
  LOBYTE(rebindl.i_uid) = 0;
  SSClass::register_method_func(v0, "get_gps_path_length", UFG::TSMinimap::MthdC_get_gps_path_length, 1, rebindl);
  LOBYTE(rebindm.i_uid) = 0;
  SSClass::register_method_func(v0, "set_gps_active", UFG::TSMinimap::MthdC_set_gps_active, 1, rebindm);
  LOBYTE(rebindn.i_uid) = 0;
  SSClass::register_method_func(v0, "set_gps_visible", UFG::TSMinimap::MthdC_set_gps_visible, 1, rebindn);
  LOBYTE(rebindo.i_uid) = 0;
  SSClass::register_method_func(v0, "ping", UFG::TSMinimap::MthdC_ping, 1, rebindo);
  LOBYTE(rebindp.i_uid) = 0;
  SSClass::register_method_func(v0, "force_interior_map", UFG::TSMinimap::MthdC_force_interior_map, 1, rebindp);
  LOBYTE(rebindq.i_uid) = 0;
  SSClass::register_method_func(v0, "set_gps_ignore_alley", UFG::TSMinimap::MthdC_set_gps_ignore_alley, 1, rebindq);
  LOBYTE(rebindr.i_uid) = 0;
  SSClass::register_method_func(v0, "map_lines_add", UFG::TSMinimap::MthdC_map_lines_add, 1, rebindr);
  LOBYTE(rebinds.i_uid) = 0;
  SSClass::register_method_func(v0, "map_lines_add_list", UFG::TSMinimap::MthdC_map_lines_add_list, 1, rebinds);
  LOBYTE(rebindt.i_uid) = 0;
  SSClass::register_method_func(v0, "map_lines_add_strip", UFG::TSMinimap::MthdC_map_lines_add_strip, 1, rebindt);
  LOBYTE(rebindu.i_uid) = 0;
  SSClass::register_method_func(v0, "map_lines_clear", UFG::TSMinimap::MthdC_map_lines_clear, 1, rebindu);
}

// File Line: 89
// RVA: 0x4E2D00
void __fastcall UFG::TSMinimap::MthdC_add_blip_xy(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIMapBlipManager *v2; // rbx
  unsigned int mUID; // edx
  SSInstance *i_data_p; // rax
  SSClass *i_class_p; // r8
  SSData **i_array_p; // r8
  SSInstance *v8; // rdi
  SSInstance *v9; // rsi
  bool v10; // bp
  UFG::UIMapBlip *Icon; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+18h] BYREF

  v2 = UFG::UIHKScreenHud::mIconManager;
  if ( UFG::UIHKScreenHud::mIconManager )
  {
    mUID = UFG::gNullQSymbol.mUID;
    i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
    if ( i_data_p )
    {
      i_class_p = i_data_p->i_class_p;
      if ( i_class_p == SSBrain::c_symbol_class_p )
      {
        mUID = i_data_p->i_user_data;
      }
      else if ( i_class_p == SSBrain::c_string_class_p )
      {
        mUID = UFG::qSymbol::create_from_string(&result, *(const char **)i_data_p->i_user_data)->mUID;
      }
    }
    i_array_p = pScope->i_data.i_array_p;
    v8 = i_array_p[5]->i_data_p;
    v9 = i_array_p[6]->i_data_p;
    v10 = i_array_p[4]->i_data_p->i_user_data != 0;
    if ( mUID != -1
      && i_array_p[1]->i_data_p != (SSInstance *)-32i64
      && i_array_p[2]->i_data_p != (SSInstance *)-32i64
      && i_array_p[3]->i_data_p != (SSInstance *)-32i64 )
    {
      Icon = UFG::UIMapBlipManager::CreateIcon(
               v2,
               mUID,
               *(const char **)i_array_p[1]->i_data_p->i_user_data,
               *(float *)&i_array_p[2]->i_data_p->i_user_data,
               *(float *)&i_array_p[3]->i_data_p->i_user_data);
      if ( Icon )
      {
        Icon->mHasAltitude = 0;
        Icon->mUseCustomFilterDistance = v10;
        Icon->mCustomFilterDistance = *(float *)&v8->i_user_data;
        UFG::UIMapBlip::SetWorldMapCaption(Icon, *(const char **)v9->i_user_data);
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
  float Zoom; // xmm6_4
  UFG::UIHKScreenHud *Instance; // rax

  Zoom = 0.0;
  Instance = UFG::UIHKScreenHud::getInstance();
  if ( Instance )
    Zoom = UFG::UITiledMapWidget::GetZoom(&Instance->Minimap);
  *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(Zoom));
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
// attributes: thunk
void __fastcall UFG::TSMinimap::MthdC_unlock_zoom(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UITiledMapZoomCalc::UnlockScale();
}

// File Line: 186
// RVA: 0x4EFF10
void __fastcall UFG::TSMinimap::MthdC_show_blip_range(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  SSData *v3; // rax

  i_array_p = pScope->i_data.i_array_p;
  v3 = i_array_p[2];
  if ( (*i_array_p)->i_data_p != (SSInstance *)-32i64
    && i_array_p[1]->i_data_p != (SSInstance *)-32i64
    && v3->i_data_p != (SSInstance *)-32i64 )
  {
    if ( UFG::UIHKScreenHud::mIconManager )
      UFG::UIMapBlipManager::AddIconRadius(
        UFG::UIHKScreenHud::mIconManager,
        (*i_array_p)->i_data_p->i_user_data,
        *(float *)&i_array_p[1]->i_data_p->i_user_data,
        v3->i_data_p->i_user_data,
        *(float *)&i_array_p[3]->i_data_p->i_user_data);
  }
}

// File Line: 205
// RVA: 0x4EFE80
void __fastcall UFG::TSMinimap::MthdC_show_blip_donut_range(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSData *v3; // rax

  i_array_p = pScope->i_data.i_array_p;
  v3 = i_array_p[4];
  if ( (*i_array_p)->i_data_p != (SSInstance *)-32i64
    && i_array_p[1]->i_data_p != (SSInstance *)-32i64
    && i_array_p[2]->i_data_p != (SSInstance *)-32i64
    && v3->i_data_p != (SSInstance *)-32i64
    && i_array_p[3]->i_data_p != (SSInstance *)-32i64 )
  {
    if ( UFG::UIHKScreenHud::mIconManager )
      UFG::UIMapBlipManager::AddIconDonutRadius(
        UFG::UIHKScreenHud::mIconManager,
        (*i_array_p)->i_data_p->i_user_data,
        *(float *)&i_array_p[1]->i_data_p->i_user_data,
        *(float *)&i_array_p[2]->i_data_p->i_user_data,
        i_array_p[3]->i_data_p->i_user_data,
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
  SSData **i_array_p; // r8
  SSData *v3; // rax

  i_array_p = pScope->i_data.i_array_p;
  v3 = i_array_p[2];
  if ( (*i_array_p)->i_data_p != (SSInstance *)-32i64
    && i_array_p[1]->i_data_p != (SSInstance *)-32i64
    && v3->i_data_p != (SSInstance *)-32i64 )
  {
    if ( UFG::UIHKScreenHud::mIconManager )
      UFG::UIMapBlipManager::ChangeIconRadius(
        UFG::UIHKScreenHud::mIconManager,
        (*i_array_p)->i_data_p->i_user_data,
        *(float *)&i_array_p[1]->i_data_p->i_user_data,
        v3->i_data_p->i_user_data,
        *(float *)&i_array_p[3]->i_data_p->i_user_data);
  }
}

// File Line: 261
// RVA: 0x4EB220
void __fastcall UFG::TSMinimap::MthdC_ping_blip(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rdi
  unsigned int v5; // edi
  UFG::SimObject *v6; // rcx
  UFG::HudComponent *ComponentOfType; // rax
  UFG::BasePhysicsSystem *v8; // rbx
  unsigned int BlipGuid; // eax
  UFG::qBaseTreeRB *CollisionModel; // rax
  UFG::UIMapBlip *v11; // rbx

  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_6;
  i_class_p = i_data_p->i_class_p;
  if ( !i_class_p->vfptr->is_actor_class(i_class_p) )
  {
    if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    {
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
      goto LABEL_7;
    }
LABEL_6:
    i_data_p = 0i64;
  }
LABEL_7:
  v5 = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64);
  if ( i_data_p )
  {
    v6 = *(UFG::SimObject **)&i_data_p[1].i_icoroutines_to_update.i_count;
    if ( v6 )
    {
      ComponentOfType = (UFG::HudComponent *)UFG::SimObject::GetComponentOfType(v6, UFG::HudComponent::_TypeUID);
      v8 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
      if ( UFG::UIHKScreenHud::mIconManager )
      {
        if ( ComponentOfType )
        {
          BlipGuid = UFG::HudComponent::GetBlipGuid(ComponentOfType);
          CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(v8, BlipGuid);
          v11 = (UFG::UIMapBlip *)CollisionModel;
          if ( CollisionModel )
          {
            UFG::UIMapBlip::SetBlinkMaxTimes((UFG::UIMapBlip *)CollisionModel, v5);
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
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rdi
  UFG::SimObject *v4; // rcx
  UFG::HudComponent *ComponentOfType; // rax
  UFG::BasePhysicsSystem *v6; // rbx
  unsigned int BlipGuid; // eax
  UFG::qBaseTreeRB *CollisionModel; // rax

  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( i_data_p )
  {
    i_class_p = i_data_p->i_class_p;
    if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSInstance **))i_class_p->vfptr->is_actor_class)(
            i_class_p,
            ppResult) )
    {
      if ( i_class_p != SSBrain::c_symbol_class_p || LODWORD(i_data_p->i_user_data) == -1 )
        return;
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
    }
    if ( i_data_p )
    {
      v4 = *(UFG::SimObject **)&i_data_p[1].i_icoroutines_to_update.i_count;
      if ( v4 )
      {
        ComponentOfType = (UFG::HudComponent *)UFG::SimObject::GetComponentOfType(v4, UFG::HudComponent::_TypeUID);
        v6 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
        if ( UFG::UIHKScreenHud::mIconManager )
        {
          if ( ComponentOfType )
          {
            BlipGuid = UFG::HudComponent::GetBlipGuid(ComponentOfType);
            CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(v6, BlipGuid);
            if ( CollisionModel )
              UFG::UIMapBlip::StopBlink((UFG::UIMapBlip *)CollisionModel);
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
  SSData **i_array_p; // rdx
  bool v3; // bl
  UFG::UIMapBlipTypeManager *Instance; // rax
  UFG::qSymbolUC result; // [rsp+30h] [rbp+8h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  v3 = i_array_p[1]->i_data_p->i_user_data != 0;
  UFG::qSymbolUC::create_from_string(&result, *(const char **)(*i_array_p)->i_data_p->i_user_data);
  Instance = UFG::UIMapBlipTypeManager::getInstance();
  UFG::UIMapBlipTypeManager::GetType(Instance, &result)->IsVisible = v3;
}

// File Line: 331
// RVA: 0x4E7940
void __fastcall UFG::TSMinimap::MthdC_get_gps_path_length(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  float PathLength; // xmm0_4

  PathLength = 0.0;
  if ( UFG::UIHKScreenHud::GPS )
    PathLength = UFG::UITiledMapGPS::GetPathLength(UFG::UIHKScreenHud::GPS);
  *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(PathLength));
}

// File Line: 341
// RVA: 0x4EDEC0
void __fastcall UFG::TSMinimap::MthdC_set_gps_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  UFG::qVector3 *i_user_data; // rbx

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (UFG::qVector3 *)i_array_p[1]->i_data_p->i_user_data;
  UFG::UITiledMapGPS::SetActive(UFG::UIHKScreenHud::GPS, (*i_array_p)->i_data_p->i_user_data != 0);
  if ( i_user_data && (-9999.0 != i_user_data->x || -9999.0 != i_user_data->y) )
  {
    UFG::UITiledMapWidget::SetGPSLineColor(&UFG::UITiledMapWidget::DefaultGPSLineColor);
    UFG::UITiledMapGPS::SetDestination(UFG::UIHKScreenHud::GPS, i_user_data, 0);
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
// attributes: thunk
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
  SSData **i_array_p; // rdx
  float *i_user_data; // r8
  float *v4; // rax
  float v5; // xmm1_4
  float v6; // xmm0_4
  UFG::UIHKMapLine line; // [rsp+20h] [rbp-18h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (float *)(*i_array_p)->i_data_p->i_user_data;
  v4 = (float *)i_array_p[1]->i_data_p->i_user_data;
  if ( i_user_data )
  {
    if ( v4 )
    {
      v5 = i_user_data[1];
      line.start.x = *i_user_data;
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
  unsigned __int64 i_user_data; // rcx
  _QWORD *v3; // rbx
  __int64 v4; // rdi
  float *v5; // rcx
  float *v6; // rdx
  float v7; // xmm1_4
  float v8; // xmm0_4
  UFG::UIHKMapLine line; // [rsp+20h] [rbp-18h] BYREF

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = *(_QWORD **)(i_user_data + 8);
  if ( *(_DWORD *)i_user_data != 1 )
  {
    v4 = ((unsigned int)(*(_DWORD *)i_user_data - 2) >> 1) + 1;
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
  unsigned __int64 i_user_data; // rcx
  unsigned int v3; // edx
  __int64 v4; // rdi
  float *v5; // rbx
  __int64 v6; // rdi
  __int64 v7; // rsi
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  UFG::UIHKMapLine line; // [rsp+20h] [rbp-18h] BYREF

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = *(_DWORD *)i_user_data;
  v4 = *(_QWORD *)(i_user_data + 8);
  if ( *(_DWORD *)i_user_data )
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


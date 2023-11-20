// File Line: 63
// RVA: 0x4D2D30
void UFG::TSDynamicEncounter::BindAtomics(void)
{
  UFG::SkookumMgr::mspDynamicEncounterClass = SSBrain::get_class("DynamicEncounter");
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    &ASymbolX_ctor,
    UFG::TSDynamicEncounter::Mthd_ctor,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    &ASymbolX_dtor,
    UFG::TSDynamicEncounter::Mthd_destructor,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "setup",
    UFG::TSDynamicEncounter::Mthd_setup,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "override_target",
    UFG::TSDynamicEncounter::Mthd_override_target,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "set_secondary_target",
    UFG::TSDynamicEncounter::Mthd_set_secondary_target,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "set_owner_gameslice",
    UFG::TSDynamicEncounter::Mthd_set_owner_gameslice,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "start",
    UFG::TSDynamicEncounter::Mthd_start,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "stop",
    UFG::TSDynamicEncounter::Mthd_stop,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "pause",
    UFG::TSDynamicEncounter::Mthd_pause,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "is_completed",
    UFG::TSDynamicEncounter::Mthd_is_completed,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "is_paused",
    UFG::TSDynamicEncounter::Mthd_is_paused,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "is_running",
    UFG::TSDynamicEncounter::Mthd_is_running,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "set_current_wave_type",
    UFG::TSDynamicEncounter::Mthd_set_current_wave_type,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "get_current_wave_type",
    UFG::TSDynamicEncounter::Mthd_get_current_wave_type,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "get_characters",
    UFG::TSDynamicEncounter::Mthd_get_characters,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "get_vehicles",
    UFG::TSDynamicEncounter::Mthd_get_vehicles,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "replenish",
    UFG::TSDynamicEncounter::Mthd_replenish,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "get_kill_count",
    UFG::TSDynamicEncounter::Mthd_get_kill_count,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "add_vehicle_and_occupants_into_system",
    UFG::TSDynamicEncounter::Mthd_add_vehicle_and_occupants_into_system,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "add_character_into_system",
    UFG::TSDynamicEncounter::Mthd_add_character_into_system,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "set_combat_region",
    UFG::TSDynamicEncounter::Mthd_set_combat_region,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "clear_combat_region",
    UFG::TSDynamicEncounter::Mthd_clear_combat_region,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "set_character_spawn_regions",
    UFG::TSDynamicEncounter::Mthd_set_character_spawn_regions,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "clear_character_spawn_regions",
    UFG::TSDynamicEncounter::Mthd_clear_character_spawn_regions,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "set_character_can_enter_exit_vehicle",
    UFG::TSDynamicEncounter::Mthd_set_character_can_enter_exit_vehicle,
    0);
}

// File Line: 104
// RVA: 0x4F7240
void __fastcall UFG::TSDynamicEncounter::Mthd_ctor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSActor *v2; // rbx
  unsigned __int64 v3; // rdi
  UFG::allocator::free_link *v4; // rax
  unsigned __int64 v5; // rax

  v2 = (SSActor *)pScope->i_scope_p.i_obj_p;
  v3 = 0i64;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = UFG::qMalloc(0xCB0ui64, "Skookum.DynamicEncounter", 0i64);
  if ( v4 )
  {
    UFG::ThugsEncounter::ThugsEncounter((UFG::ThugsEncounter *)v4);
    v3 = v5;
  }
  v2->i_user_data = v3;
  SSActor::enable_behavior(v2, 1);
}

// File Line: 117
// RVA: 0x4F7E50
void __fastcall UFG::TSDynamicEncounter::Mthd_destructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSObjectBaseVtbl *v3; // rcx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  if ( v3 )
    (*(void (__fastcall **)(SSObjectBaseVtbl *, signed __int64))v3->__vecDelDtor)(v3, 1i64);
}

// File Line: 125
// RVA: 0x50B4D0
void __fastcall UFG::TSDynamicEncounter::Mthd_setup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSData **v3; // rcx
  UFG::ThugsEncounter *v4; // rsi
  SSInstance *v5; // r14
  SSActor *v6; // rbx
  SSClass *v7; // rdi

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = pScope->i_data.i_array_p;
  v4 = (UFG::ThugsEncounter *)v2[2].vfptr;
  v5 = (*v3)->i_data_p;
  v6 = (SSActor *)v3[1]->i_data_p;
  if ( !v6 )
    goto LABEL_9;
  v7 = v6->i_class_p;
  if ( !v7->vfptr->is_actor_class((SSClassDescBase *)&v7->vfptr) )
  {
    if ( v7 == SSBrain::c_symbol_class_p && LODWORD(v6->i_user_data) != -1 )
    {
      v6 = SSActor::find((ASymbol *)&v6->i_user_data);
      goto LABEL_10;
    }
LABEL_9:
    v6 = 0i64;
  }
LABEL_10:
  UFG::ThugsEncounter::Cleanup(v4);
  v4->vfptr[5].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr, *(_QWORD *)v5->i_user_data);
  v4->vfptr[19].__vecDelDtor(
    (UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr,
    *(_QWORD *)&v6[1].i_icoroutines_to_update.i_count);
}

// File Line: 139
// RVA: 0x50BD20
void __fastcall UFG::TSDynamicEncounter::Mthd_start(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  SSInvokedMethod *v3; // rdi
  UFG::ThugsEncounter *v4; // rbx
  SSData **v5; // r8
  UFG::qSymbol firstWave; // [rsp+30h] [rbp+8h]

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = pScope;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = (UFG::ThugsEncounter *)v2[2].vfptr;
  v4->vfptr[1].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr, (unsigned int)ppResult);
  v5 = v3->i_data.i_array_p;
  firstWave.mUID = (*v5)->i_data_p->i_user_data;
  UFG::ThugsEncounter::Start(v4, &firstWave, v5[1]->i_data_p->i_user_data != 0);
}

// File Line: 153
// RVA: 0x50C0C0
void __fastcall UFG::TSDynamicEncounter::Mthd_stop(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  SSObjectBase *v3; // rcx
  SSObjectBase *v4; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  UFG::ThugsEncounter::Stop((UFG::ThugsEncounter *)v3[2].vfptr);
  v4 = v2->i_scope_p.i_obj_p;
  if ( !v4 || v2->i_scope_p.i_ptr_id != v4->i_ptr_id )
    v4 = 0i64;
  UFG::ThugsEncounter::Cleanup((UFG::ThugsEncounter *)v4[2].vfptr);
}

// File Line: 162
// RVA: 0x505BE0
void __fastcall UFG::TSDynamicEncounter::Mthd_pause(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  BYTE1(v2[2].vfptr[50].set_data_by_name) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 170
// RVA: 0x505AA0
void __fastcall UFG::TSDynamicEncounter::Mthd_override_target(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSObjectBaseVtbl *v3; // rdi
  SSActor *v4; // rbx
  SSClass *v5; // rsi
  UFG::SimObject *v6; // rsi
  unsigned int v7; // eax
  signed __int64 v8; // rbx
  __int64 v9; // rdi
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::TargetingSystemBaseComponent *v12; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  v4 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !v4 )
    goto LABEL_27;
  v5 = v4->i_class_p;
  if ( v5->vfptr->is_actor_class((SSClassDescBase *)&v5->vfptr) )
    goto LABEL_10;
  if ( v5 == SSBrain::c_symbol_class_p && LODWORD(v4->i_user_data) != -1 )
    v4 = SSActor::find((ASymbol *)&v4->i_user_data);
  else
LABEL_27:
    v4 = 0i64;
LABEL_10:
  v6 = *(UFG::SimObject **)&v4[1].i_icoroutines_to_update.i_count;
  (*((void (__fastcall **)(SSObjectBaseVtbl *, _QWORD))v3->__vecDelDtor + 19))(
    v3,
    *(_QWORD *)&v4[1].i_icoroutines_to_update.i_count);
  v7 = (unsigned int)v3[5].set_data_by_name;
  if ( v7 )
  {
    v8 = (signed __int64)&v3[5].get_scope_context;
    v9 = v7;
    do
    {
      v10 = *(UFG::SimObjectGame **)(*(_QWORD *)v8 + 40i64);
      if ( v10 )
      {
        v11 = v10->m_Flags;
        if ( (v11 >> 14) & 1 )
        {
          v12 = (UFG::TargetingSystemBaseComponent *)v10->m_Components.p[20].m_pComponent;
        }
        else if ( (v11 & 0x8000u) == 0 )
        {
          if ( (v11 >> 13) & 1 )
          {
            v12 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v10,
                                                         UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else if ( (v11 >> 12) & 1 )
          {
            v12 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v10,
                                                         UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v12 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v10->vfptr,
                                                         UFG::TargetingSystemBaseComponent::_TypeUID);
          }
        }
        else
        {
          v12 = (UFG::TargetingSystemBaseComponent *)v10->m_Components.p[20].m_pComponent;
        }
        if ( v12 )
          UFG::TargetingSystemBaseComponent::SetTarget(v12, eTARGET_TYPE_AI_OBJECTIVE, v6);
      }
      v8 += 8i64;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 197
// RVA: 0x50A3D0
void __fastcall UFG::TSDynamicEncounter::Mthd_set_secondary_target(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSObjectBaseVtbl *v3; // rsi
  SSActor *v4; // rbx
  SSClass *v5; // rdi

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  v4 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !v4 )
    goto LABEL_9;
  v5 = v4->i_class_p;
  if ( !v5->vfptr->is_actor_class((SSClassDescBase *)&v5->vfptr) )
  {
    if ( v5 == SSBrain::c_symbol_class_p && LODWORD(v4->i_user_data) != -1 )
    {
      v4 = SSActor::find((ASymbol *)&v4->i_user_data);
      goto LABEL_10;
    }
LABEL_9:
    v4 = 0i64;
  }
LABEL_10:
  (*((void (__fastcall **)(SSObjectBaseVtbl *, _QWORD))v3->__vecDelDtor + 22))(
    v3,
    *(_QWORD *)&v4[1].i_icoroutines_to_update.i_count);
}

// File Line: 208
// RVA: 0x5091C0
void __fastcall UFG::TSDynamicEncounter::Mthd_set_owner_gameslice(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  signed __int64 v3; // r8
  SSInstance *v4; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = 0i64;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( v4 )
    v3 = (signed __int64)&v4[-1].i_class_p;
  UFG::ThugsEncounter::SetOwnerGameSlice((UFG::ThugsEncounter *)v2[2].vfptr, *(UFG::GameSlice **)(v3 + 152));
}

// File Line: 219
// RVA: 0x501330
void __fastcall UFG::TSDynamicEncounter::Mthd_is_completed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *ppResult = (SSInstance *)SSBoolean::pool_new(BYTE3(v2[2].vfptr[50].set_data_by_name));
  }
}

// File Line: 230
// RVA: 0x5029B0
void __fastcall UFG::TSDynamicEncounter::Mthd_is_paused(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSObjectBaseVtbl *v3; // rax

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v3 = v2[2].vfptr;
    if ( !BYTE1(v3[50].set_data_by_name) && LOBYTE(v3[50].set_data_by_name) && BYTE2(v3[50].set_data_by_name) )
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
    else
      *ppResult = (SSInstance *)SSBoolean::pool_new(1);
  }
}

// File Line: 243
// RVA: 0x5030E0
void __fastcall UFG::TSDynamicEncounter::Mthd_is_running(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInvokedMethod *v3; // r9
  bool v4; // cl
  SSObjectBaseVtbl *v5; // rax

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = pScope;
    v4 = 0;
    if ( !v2 || v3->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v5 = v2[2].vfptr;
    if ( LOBYTE(v5[50].set_data_by_name) )
    {
      if ( !BYTE1(v5[50].set_data_by_name) )
        v4 = 1;
    }
    *ppResult = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 254
// RVA: 0x507CE0
void __fastcall UFG::TSDynamicEncounter::Mthd_set_current_wave_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  (*((void (__fastcall **)(SSObjectBaseVtbl *, unsigned __int64 *))v3[2].vfptr->__vecDelDtor + 25))(
    v3[2].vfptr,
    &(*v2->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 263
// RVA: 0x4FC380
void __fastcall UFG::TSDynamicEncounter::Mthd_get_current_wave_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx
  SSInstance **v4; // rbx
  ASymbol *v5; // rax

  if ( ppResult )
  {
    v2 = pScope;
    v3 = pScope->i_scope_p.i_obj_p;
    v4 = ppResult;
    if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v5 = (ASymbol *)(*((__int64 (**)(void))v3[2].vfptr->__vecDelDtor + 26))();
    *v4 = SSSymbol::as_instance(v5);
  }
}

// File Line: 275
// RVA: 0x4FBF80
void __fastcall UFG::TSDynamicEncounter::Mthd_get_characters(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // r14
  SSObjectBase *v3; // r8
  SSObjectBaseVtbl *v4; // rbx
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v5; // rax
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v6; // rsi
  unsigned int v7; // eax
  signed __int64 v8; // rbx
  __int64 v9; // rdi
  UFG::SimObject *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::TSActorComponent *v12; // rax
  UFG::TSActor *v13; // rax
  __int64 v14; // rax
  ARefCountMix<SSInstance> **v15; // rbx
  unsigned __int64 i; // rdi

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = v3[2].vfptr;
    v5 = (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v6 = v5;
    if ( v5 )
    {
      v5->i_count = 0;
      v5->i_array_p = 0i64;
      v5->i_size = 0;
      v5->i_array_p = (SSActor **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      v6 = 0i64;
    }
    v7 = (unsigned int)v4[5].set_data_by_name;
    if ( v7 )
    {
      v8 = (signed __int64)&v4[5].get_scope_context;
      v9 = v7;
      do
      {
        v10 = *(UFG::SimObject **)(*(_QWORD *)v8 + 40i64);
        if ( v10 )
        {
          v11 = v10->m_Flags;
          if ( (v11 >> 14) & 1 )
          {
            v12 = (UFG::TSActorComponent *)v10->m_Components.p[4].m_pComponent;
          }
          else if ( (v11 & 0x8000u) == 0 )
          {
            if ( (v11 >> 13) & 1 )
              v12 = (UFG::TSActorComponent *)v10->m_Components.p[3].m_pComponent;
            else
              v12 = (UFG::TSActorComponent *)((v11 >> 12) & 1 ? v10->m_Components.p[2].m_pComponent : UFG::SimObject::GetComponentOfType(v10, UFG::TSActorComponent::_TypeUID));
          }
          else
          {
            v12 = (UFG::TSActorComponent *)v10->m_Components.p[4].m_pComponent;
          }
          if ( v12 )
          {
            v13 = UFG::TSActorComponent::GetActor(v12);
            APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(v6, (SSActor *)&v13->vfptr);
          }
        }
        v8 += 8i64;
        --v9;
      }
      while ( v9 );
    }
    v14 = v6->i_count;
    if ( (_DWORD)v14 )
    {
      v15 = (ARefCountMix<SSInstance> **)v6->i_array_p;
      for ( i = (unsigned __int64)&v15[v14]; (unsigned __int64)v15 < i; ++v15 )
        UFG::PersistentData::MapFloat::Iterator::Next(*v15 + 4);
    }
    *v2 = SSList::as_instance((SSList *)v6);
  }
}

// File Line: 305
// RVA: 0x4FF3A0
void __fastcall UFG::TSDynamicEncounter::Mthd_get_vehicles(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // r14
  SSObjectBase *v3; // r8
  SSObjectBaseVtbl *v4; // rbx
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v5; // rax
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v6; // rsi
  unsigned int v7; // eax
  signed __int64 v8; // rbx
  __int64 v9; // rdi
  UFG::SimObject *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::TSActorComponent *v12; // rax
  UFG::TSActor *v13; // rax
  __int64 v14; // rax
  ARefCountMix<SSInstance> **v15; // rbx
  unsigned __int64 i; // rdi

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = v3[2].vfptr;
    v5 = (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v6 = v5;
    if ( v5 )
    {
      v5->i_count = 0;
      v5->i_array_p = 0i64;
      v5->i_size = 0;
      v5->i_array_p = (SSActor **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      v6 = 0i64;
    }
    v7 = (unsigned int)v4[9].get_scope_context;
    if ( v7 )
    {
      v8 = (signed __int64)&v4[9].get_topmost_scope;
      v9 = v7;
      do
      {
        v10 = *(UFG::SimObject **)(*(_QWORD *)v8 + 40i64);
        if ( v10 )
        {
          v11 = v10->m_Flags;
          if ( (v11 >> 14) & 1 )
          {
            v12 = (UFG::TSActorComponent *)v10->m_Components.p[4].m_pComponent;
          }
          else if ( (v11 & 0x8000u) == 0 )
          {
            if ( (v11 >> 13) & 1 )
              v12 = (UFG::TSActorComponent *)v10->m_Components.p[3].m_pComponent;
            else
              v12 = (UFG::TSActorComponent *)((v11 >> 12) & 1 ? v10->m_Components.p[2].m_pComponent : UFG::SimObject::GetComponentOfType(v10, UFG::TSActorComponent::_TypeUID));
          }
          else
          {
            v12 = (UFG::TSActorComponent *)v10->m_Components.p[4].m_pComponent;
          }
          if ( v12 )
          {
            v13 = UFG::TSActorComponent::GetActor(v12);
            APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(v6, (SSActor *)&v13->vfptr);
          }
        }
        v8 += 8i64;
        --v9;
      }
      while ( v9 );
    }
    v14 = v6->i_count;
    if ( (_DWORD)v14 )
    {
      v15 = (ARefCountMix<SSInstance> **)v6->i_array_p;
      for ( i = (unsigned __int64)&v15[v14]; (unsigned __int64)v15 < i; ++v15 )
        UFG::PersistentData::MapFloat::Iterator::Next(*v15 + 4);
    }
    *v2 = SSList::as_instance((SSList *)v6);
  }
}

// File Line: 332
// RVA: 0x5067D0
void __fastcall UFG::TSDynamicEncounter::Mthd_replenish(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  (*((void (**)(void))v3[2].vfptr->__vecDelDtor + 23))();
}

// File Line: 338
// RVA: 0x4FD490
void __fastcall UFG::TSDynamicEncounter::Mthd_get_kill_count(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx
  SSInstance **v4; // rbx
  unsigned int v5; // eax

  if ( ppResult )
  {
    v2 = pScope;
    v3 = pScope->i_scope_p.i_obj_p;
    v4 = ppResult;
    if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v5 = (*((__int64 (**)(void))v3[2].vfptr->__vecDelDtor + 31))();
    *v4 = SSInstance::pool_new(SSBrain::c_integer_class_p, v5);
  }
}

// File Line: 347
// RVA: 0x4F45E0
void __fastcall UFG::TSDynamicEncounter::Mthd_add_vehicle_and_occupants_into_system(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  unsigned int v3; // esi
  SSObjectBaseVtbl *v4; // r12
  SSActor *v5; // rdi
  SSClass *v6; // rbx
  UFG::SimObjectGame *v7; // rdi
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // rax
  UFG::VehicleOccupantComponent *v10; // rbp
  unsigned int v11; // er15
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *v12; // r14
  void *(__fastcall *v13)(SSObjectBase *, unsigned int); // rbx
  UFG::SimObject *v14; // rax
  __int64 v15; // rax
  UFG::EncounterUnitComponent *v16; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = 0;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = v2[2].vfptr;
  v5 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !v5 )
    goto LABEL_29;
  v6 = v5->i_class_p;
  if ( v6->vfptr->is_actor_class((SSClassDescBase *)&v6->vfptr) )
    goto LABEL_10;
  if ( v6 == SSBrain::c_symbol_class_p && LODWORD(v5->i_user_data) != -1 )
    v5 = SSActor::find((ASymbol *)&v5->i_user_data);
  else
LABEL_29:
    v5 = 0i64;
LABEL_10:
  v7 = *(UFG::SimObjectGame **)&v5[1].i_icoroutines_to_update.i_count;
  if ( !v7 )
    return;
  (*((void (__fastcall **)(SSObjectBaseVtbl *, UFG::SimObjectGame *))v4->__vecDelDtor + 27))(v4, v7);
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::VehicleOccupantComponent::_TypeUID);
LABEL_20:
    v10 = (UFG::VehicleOccupantComponent *)v9;
    goto LABEL_21;
  }
  if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
    {
      v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else if ( (v8 >> 12) & 1 )
    {
      v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
    }
    goto LABEL_20;
  }
  v10 = (UFG::VehicleOccupantComponent *)v7->m_Components.p[30].m_pComponent;
LABEL_21:
  if ( v10 )
  {
    v11 = UFG::VehicleOccupantComponent::GetNumberOfOccupants(v10);
    if ( v11 )
    {
      v12 = &v7->m_SafePointerList;
      do
      {
        v13 = v4->__vecDelDtor;
        v14 = UFG::VehicleOccupantComponent::GetOccupant(v10, v3, 0i64);
        v15 = (*((__int64 (__fastcall **)(SSObjectBaseVtbl *, UFG::SimObject *))v13 + 28))(v4, v14);
        v16 = (UFG::EncounterUnitComponent *)v15;
        v17 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v15 + 160);
        if ( *(_QWORD *)(v15 + 176) )
        {
          v18 = v17->mPrev;
          v19 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v15 + 168);
          v18->mNext = v19;
          v19->mPrev = v18;
          v17->mPrev = v17;
          *(_QWORD *)(v15 + 168) = v15 + 160;
        }
        *(_QWORD *)(v15 + 176) = v7;
        v20 = v12->mNode.mPrev;
        v20->mNext = v17;
        v17->mPrev = v20;
        v17->mNext = &v12->mNode;
        v12->mNode.mPrev = v17;
        UFG::EncounterUnitComponent::IncrementGroupVehicleUsageCount(v16);
        ++v3;
      }
      while ( v3 < v11 );
    }
  }
}

// File Line: 372
// RVA: 0x4F3C90
void __fastcall UFG::TSDynamicEncounter::Mthd_add_character_into_system(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSObjectBaseVtbl *v3; // rsi
  SSActor *v4; // rbx
  SSClass *v5; // rdi
  UFG::SimObject *v6; // rbx
  unsigned __int16 v7; // cx
  unsigned int v8; // edx
  UFG::SimObjectGame *v9; // rcx
  bool v10; // zf

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  v4 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !v4 )
    goto LABEL_21;
  v5 = v4->i_class_p;
  if ( v5->vfptr->is_actor_class((SSClassDescBase *)&v5->vfptr) )
    goto LABEL_10;
  if ( v5 == SSBrain::c_symbol_class_p && LODWORD(v4->i_user_data) != -1 )
    v4 = SSActor::find((ASymbol *)&v4->i_user_data);
  else
LABEL_21:
    v4 = 0i64;
LABEL_10:
  v6 = *(UFG::SimObject **)&v4[1].i_icoroutines_to_update.i_count;
  if ( !v6 )
    return;
  v7 = v6->m_Flags;
  if ( !((v7 >> 14) & 1) )
  {
    if ( (v7 & 0x8000u) != 0 || (v7 >> 13) & 1 )
    {
      v8 = UFG::CharacterOccupantComponent::_TypeUID;
      v9 = (UFG::SimObjectGame *)v6;
    }
    else
    {
      v8 = UFG::CharacterOccupantComponent::_TypeUID;
      v10 = ((v7 >> 12) & 1) == 0;
      v9 = (UFG::SimObjectGame *)v6;
      if ( v10 )
      {
        UFG::SimObject::GetComponentOfType(v6, UFG::CharacterOccupantComponent::_TypeUID);
        goto LABEL_18;
      }
    }
    UFG::SimObjectGame::GetComponentOfTypeHK(v9, v8);
  }
LABEL_18:
  (*((void (__fastcall **)(SSObjectBaseVtbl *, UFG::SimObject *))v3->__vecDelDtor + 28))(v3, v6);
}

// File Line: 388
// RVA: 0x507C20
void __fastcall UFG::TSDynamicEncounter::Mthd_set_combat_region(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  UFG::EncounterBase::SetCombatRegion(
    (UFG::EncounterBase *)v3[2].vfptr,
    (UFG::CombatRegion *)(*v2->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 396
// RVA: 0x4F6470
void __fastcall UFG::TSDynamicEncounter::Mthd_clear_combat_region(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  UFG::EncounterBase::SetCombatRegion((UFG::EncounterBase *)v3[2].vfptr, 0i64);
}

// File Line: 402
// RVA: 0x507920
void __fastcall UFG::TSDynamicEncounter::Mthd_set_character_spawn_regions(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  UFG::EncounterBase *v3; // rsi
  unsigned int *v4; // rcx
  __int64 v5; // rbx
  __int64 v6; // rdi

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (UFG::EncounterBase *)v2[2].vfptr;
  v4 = (unsigned int *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v5 = *((_QWORD *)v4 + 1);
  if ( *v4 )
  {
    v6 = *v4;
    do
    {
      UFG::EncounterBase::AddCharacterSpawnRegion(
        v3,
        *(UFG::RegionComponent **)(*(_QWORD *)(*(_QWORD *)v5 + 32i64) + 216i64));
      v5 += 8i64;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 418
// RVA: 0x4F6450
void __fastcall UFG::TSDynamicEncounter::Mthd_clear_character_spawn_regions(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  UFG::EncounterBase::ClearCharacterSpawnRegions((UFG::EncounterBase *)v3[2].vfptr);
}

// File Line: 424
// RVA: 0x5078E0
void __fastcall UFG::TSDynamicEncounter::Mthd_set_character_can_enter_exit_vehicle(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rax
  SSInvokedMethod *v3; // r8
  SSObjectBase *v4; // rcx

  v2 = pScope->i_data.i_array_p;
  v3 = pScope;
  v4 = pScope->i_scope_p.i_obj_p;
  if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
    v4 = 0i64;
  UFG::ThugsEncounter::SetCharacterCanEnterExitVehicle(
    (UFG::ThugsEncounter *)v4[2].vfptr,
    (*v2)->i_data_p->i_user_data != 0);
}


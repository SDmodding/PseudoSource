// File Line: 63
// RVA: 0x4D2D30
void UFG::TSDynamicEncounter::BindAtomics(void)
{
  UFG::SkookumMgr::mspDynamicEncounterClass = SSBrain::get_class("DynamicEncounter");
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    &ASymbolX_ctor,
    UFG::TSDynamicEncounter::Mthd_ctor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    &ASymbolX_dtor,
    UFG::TSDynamicEncounter::Mthd_destructor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "setup",
    UFG::TSDynamicEncounter::Mthd_setup,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "override_target",
    UFG::TSDynamicEncounter::Mthd_override_target,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "set_secondary_target",
    UFG::TSDynamicEncounter::Mthd_set_secondary_target,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "set_owner_gameslice",
    UFG::TSDynamicEncounter::Mthd_set_owner_gameslice,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "start",
    UFG::TSDynamicEncounter::Mthd_start,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "stop",
    UFG::TSDynamicEncounter::Mthd_stop,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "pause",
    UFG::TSDynamicEncounter::Mthd_pause,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "is_completed",
    UFG::TSDynamicEncounter::Mthd_is_completed,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "is_paused",
    UFG::TSDynamicEncounter::Mthd_is_paused,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "is_running",
    UFG::TSDynamicEncounter::Mthd_is_running,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "set_current_wave_type",
    UFG::TSDynamicEncounter::Mthd_set_current_wave_type,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "get_current_wave_type",
    UFG::TSDynamicEncounter::Mthd_get_current_wave_type,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "get_characters",
    UFG::TSDynamicEncounter::Mthd_get_characters,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "get_vehicles",
    UFG::TSDynamicEncounter::Mthd_get_vehicles,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "replenish",
    UFG::TSDynamicEncounter::Mthd_replenish,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "get_kill_count",
    UFG::TSDynamicEncounter::Mthd_get_kill_count,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "add_vehicle_and_occupants_into_system",
    UFG::TSDynamicEncounter::Mthd_add_vehicle_and_occupants_into_system,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "add_character_into_system",
    UFG::TSDynamicEncounter::Mthd_add_character_into_system,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "set_combat_region",
    UFG::TSDynamicEncounter::Mthd_set_combat_region,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "clear_combat_region",
    UFG::TSDynamicEncounter::Mthd_clear_combat_region,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "set_character_spawn_regions",
    UFG::TSDynamicEncounter::Mthd_set_character_spawn_regions,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "clear_character_spawn_regions",
    UFG::TSDynamicEncounter::Mthd_clear_character_spawn_regions,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspDynamicEncounterClass,
    "set_character_can_enter_exit_vehicle",
    UFG::TSDynamicEncounter::Mthd_set_character_can_enter_exit_vehicle,
    SSBindFlag_instance_no_rebind);
}

// File Line: 104
// RVA: 0x4F7240
void __fastcall UFG::TSDynamicEncounter::Mthd_ctor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSActor *i_obj_p; // rbx
  unsigned __int64 v3; // rdi
  UFG::allocator::free_link *v4; // rax
  unsigned __int64 v5; // rax

  i_obj_p = (SSActor *)pScope->i_scope_p.i_obj_p;
  v3 = 0i64;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  v4 = UFG::qMalloc(0xCB0ui64, "Skookum.DynamicEncounter", 0i64);
  if ( v4 )
  {
    UFG::ThugsEncounter::ThugsEncounter((UFG::ThugsEncounter *)v4);
    v3 = v5;
  }
  i_obj_p->i_user_data = v3;
  SSActor::enable_behavior(i_obj_p, 1);
}

// File Line: 117
// RVA: 0x4F7E50
void __fastcall UFG::TSDynamicEncounter::Mthd_destructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( vfptr )
    (*(void (__fastcall **)(SSObjectBaseVtbl *, __int64))vfptr->__vecDelDtor)(vfptr, 1i64);
}

// File Line: 125
// RVA: 0x50B4D0
void __fastcall UFG::TSDynamicEncounter::Mthd_setup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSData **i_array_p; // rcx
  UFG::ThugsEncounter *vfptr; // rsi
  SSInstance *i_data_p; // r14
  SSActor *v6; // rbx
  SSClass *i_class_p; // rdi

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = pScope->i_data.i_array_p;
  vfptr = (UFG::ThugsEncounter *)i_obj_p[2].vfptr;
  i_data_p = (*i_array_p)->i_data_p;
  v6 = (SSActor *)i_array_p[1]->i_data_p;
  if ( !v6 )
    goto LABEL_9;
  i_class_p = v6->i_class_p;
  if ( !i_class_p->vfptr->is_actor_class(i_class_p) )
  {
    if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(v6->i_user_data) != -1 )
    {
      v6 = SSActor::find((ASymbol *)&v6->i_user_data);
      goto LABEL_10;
    }
LABEL_9:
    v6 = 0i64;
  }
LABEL_10:
  UFG::ThugsEncounter::Cleanup(vfptr);
  vfptr->vfptr[5].__vecDelDtor(vfptr, *(_QWORD *)i_data_p->i_user_data);
  vfptr->vfptr[19].__vecDelDtor(vfptr, *(_QWORD *)&v6[1].i_icoroutines_to_update.i_count);
}

// File Line: 139
// RVA: 0x50BD20
void __fastcall UFG::TSDynamicEncounter::Mthd_start(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  UFG::ThugsEncounter *vfptr; // rbx
  SSData **i_array_p; // r8
  UFG::qSymbol firstWave; // [rsp+30h] [rbp+8h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::ThugsEncounter *)i_obj_p[2].vfptr;
  vfptr->vfptr[1].__vecDelDtor(vfptr, (unsigned int)ppResult);
  i_array_p = pScope->i_data.i_array_p;
  firstWave.mUID = (*i_array_p)->i_data_p->i_user_data;
  UFG::ThugsEncounter::Start(vfptr, &firstWave, i_array_p[1]->i_data_p->i_user_data != 0);
}

// File Line: 153
// RVA: 0x50C0C0
void __fastcall UFG::TSDynamicEncounter::Mthd_stop(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  SSObjectBase *v4; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  UFG::ThugsEncounter::Stop((UFG::ThugsEncounter *)i_obj_p[2].vfptr);
  v4 = pScope->i_scope_p.i_obj_p;
  if ( !v4 || pScope->i_scope_p.i_ptr_id != v4->i_ptr_id )
    v4 = 0i64;
  UFG::ThugsEncounter::Cleanup((UFG::ThugsEncounter *)v4[2].vfptr);
}

// File Line: 162
// RVA: 0x505BE0
void __fastcall UFG::TSDynamicEncounter::Mthd_pause(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  BYTE1(i_obj_p[2].vfptr[50].set_data_by_name) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 170
// RVA: 0x505AA0
void __fastcall UFG::TSDynamicEncounter::Mthd_override_target(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rdi
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rsi
  UFG::SimObject *v6; // rsi
  unsigned int set_data_by_name; // eax
  SSInvokedContextBase *(__fastcall **p_get_scope_context)(SSObjectBase *); // rbx
  __int64 v9; // rdi
  UFG::SimObjectGame *v10; // rcx
  __int16 m_Flags; // dx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_9;
  i_class_p = i_data_p->i_class_p;
  if ( i_class_p->vfptr->is_actor_class(i_class_p) )
    goto LABEL_10;
  if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
  else
LABEL_9:
    i_data_p = 0i64;
LABEL_10:
  v6 = *(UFG::SimObject **)&i_data_p[1].i_icoroutines_to_update.i_count;
  (*((void (__fastcall **)(SSObjectBaseVtbl *, UFG::SimObject *))vfptr->__vecDelDtor + 19))(vfptr, v6);
  set_data_by_name = (unsigned int)vfptr[5].set_data_by_name;
  if ( set_data_by_name )
  {
    p_get_scope_context = &vfptr[5].get_scope_context;
    v9 = set_data_by_name;
    do
    {
      v10 = (UFG::SimObjectGame *)*((_QWORD *)*p_get_scope_context + 5);
      if ( v10 )
      {
        m_Flags = v10->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::TargetingSystemBaseComponent *)v10->m_Components.p[20].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v10,
                                                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v10,
                                                                  UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          m_pComponent = (UFG::TargetingSystemBaseComponent *)v10->m_Components.p[20].m_pComponent;
        }
        if ( m_pComponent )
          UFG::TargetingSystemBaseComponent::SetTarget(m_pComponent, eTARGET_TYPE_AI_OBJECTIVE, v6);
      }
      ++p_get_scope_context;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 197
// RVA: 0x50A3D0
void __fastcall UFG::TSDynamicEncounter::Mthd_set_secondary_target(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rsi
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rdi

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_9;
  i_class_p = i_data_p->i_class_p;
  if ( !i_class_p->vfptr->is_actor_class(i_class_p) )
  {
    if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    {
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
      goto LABEL_10;
    }
LABEL_9:
    i_data_p = 0i64;
  }
LABEL_10:
  (*((void (__fastcall **)(SSObjectBaseVtbl *, _QWORD))vfptr->__vecDelDtor + 22))(
    vfptr,
    *(_QWORD *)&i_data_p[1].i_icoroutines_to_update.i_count);
}

// File Line: 208
// RVA: 0x5091C0
void __fastcall UFG::TSDynamicEncounter::Mthd_set_owner_gameslice(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  UFG::GameSlice **p_i_class_p; // r8
  SSInstance *i_data_p; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  p_i_class_p = 0i64;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( i_data_p )
    p_i_class_p = (UFG::GameSlice **)&i_data_p[-1].i_class_p;
  UFG::ThugsEncounter::SetOwnerGameSlice((UFG::ThugsEncounter *)i_obj_p[2].vfptr, p_i_class_p[19]);
}

// File Line: 219
// RVA: 0x501330
void __fastcall UFG::TSDynamicEncounter::Mthd_is_completed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = SSBoolean::pool_new(BYTE3(i_obj_p[2].vfptr[50].set_data_by_name));
  }
}

// File Line: 230
// RVA: 0x5029B0
void __fastcall UFG::TSDynamicEncounter::Mthd_is_paused(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    if ( !BYTE1(vfptr[50].set_data_by_name) && LOBYTE(vfptr[50].set_data_by_name) && BYTE2(vfptr[50].set_data_by_name) )
      *ppResult = SSBoolean::pool_new(0);
    else
      *ppResult = SSBoolean::pool_new(1);
  }
}

// File Line: 243
// RVA: 0x5030E0
void __fastcall UFG::TSDynamicEncounter::Mthd_is_running(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  bool v4; // cl
  SSObjectBaseVtbl *vfptr; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v4 = 0;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    if ( LOBYTE(vfptr[50].set_data_by_name) )
    {
      if ( !BYTE1(vfptr[50].set_data_by_name) )
        v4 = 1;
    }
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 254
// RVA: 0x507CE0
void __fastcall UFG::TSDynamicEncounter::Mthd_set_current_wave_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  (*((void (__fastcall **)(SSObjectBaseVtbl *, unsigned __int64 *))i_obj_p[2].vfptr->__vecDelDtor + 25))(
    i_obj_p[2].vfptr,
    &(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 263
// RVA: 0x4FC380
void __fastcall UFG::TSDynamicEncounter::Mthd_get_current_wave_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  ASymbol *v5; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v5 = (ASymbol *)(*((__int64 (__fastcall **)(SSObjectBaseVtbl *))i_obj_p[2].vfptr->__vecDelDtor + 26))(i_obj_p[2].vfptr);
    *ppResult = SSSymbol::as_instance(v5);
  }
}

// File Line: 275
// RVA: 0x4FBF80
void __fastcall UFG::TSDynamicEncounter::Mthd_get_characters(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rbx
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v5; // rax
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v6; // rsi
  unsigned int set_data_by_name; // eax
  SSInvokedContextBase *(__fastcall **p_get_scope_context)(SSObjectBase *); // rbx
  __int64 v9; // rdi
  UFG::SimObject *v10; // rcx
  __int16 m_Flags; // dx
  UFG::TSActorComponent *m_pComponent; // rax
  UFG::TSActor *Actor; // rax
  __int64 i_count; // rax
  ARefCountMix<SSInstance> **i_array_p; // rbx
  ARefCountMix<SSInstance> **i; // rdi

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
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
    set_data_by_name = (unsigned int)vfptr[5].set_data_by_name;
    if ( set_data_by_name )
    {
      p_get_scope_context = &vfptr[5].get_scope_context;
      v9 = set_data_by_name;
      do
      {
        v10 = (UFG::SimObject *)*((_QWORD *)*p_get_scope_context + 5);
        if ( v10 )
        {
          m_Flags = v10->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = (UFG::TSActorComponent *)v10->m_Components.p[4].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            if ( (m_Flags & 0x2000) != 0 )
              m_pComponent = (UFG::TSActorComponent *)v10->m_Components.p[3].m_pComponent;
            else
              m_pComponent = (UFG::TSActorComponent *)((m_Flags & 0x1000) != 0
                                                     ? v10->m_Components.p[2].m_pComponent
                                                     : UFG::SimObject::GetComponentOfType(
                                                         v10,
                                                         UFG::TSActorComponent::_TypeUID));
          }
          else
          {
            m_pComponent = (UFG::TSActorComponent *)v10->m_Components.p[4].m_pComponent;
          }
          if ( m_pComponent )
          {
            Actor = UFG::TSActorComponent::GetActor(m_pComponent);
            APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(v6, Actor);
          }
        }
        ++p_get_scope_context;
        --v9;
      }
      while ( v9 );
    }
    i_count = v6->i_count;
    if ( (_DWORD)i_count )
    {
      i_array_p = (ARefCountMix<SSInstance> **)v6->i_array_p;
      for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
        UFG::PersistentData::MapFloat::Iterator::Next(*i_array_p + 4);
    }
    *ppResult = SSList::as_instance((SSList *)v6);
  }
}

// File Line: 305
// RVA: 0x4FF3A0
void __fastcall UFG::TSDynamicEncounter::Mthd_get_vehicles(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rbx
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v5; // rax
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v6; // rsi
  unsigned int get_scope_context; // eax
  SSInstance *(__fastcall **p_get_topmost_scope)(SSObjectBase *); // rbx
  __int64 v9; // rdi
  UFG::SimObject *v10; // rcx
  __int16 m_Flags; // dx
  UFG::TSActorComponent *m_pComponent; // rax
  UFG::TSActor *Actor; // rax
  __int64 i_count; // rax
  ARefCountMix<SSInstance> **i_array_p; // rbx
  ARefCountMix<SSInstance> **i; // rdi

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
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
    get_scope_context = (unsigned int)vfptr[9].get_scope_context;
    if ( get_scope_context )
    {
      p_get_topmost_scope = &vfptr[9].get_topmost_scope;
      v9 = get_scope_context;
      do
      {
        v10 = (UFG::SimObject *)*((_QWORD *)*p_get_topmost_scope + 5);
        if ( v10 )
        {
          m_Flags = v10->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = (UFG::TSActorComponent *)v10->m_Components.p[4].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            if ( (m_Flags & 0x2000) != 0 )
              m_pComponent = (UFG::TSActorComponent *)v10->m_Components.p[3].m_pComponent;
            else
              m_pComponent = (UFG::TSActorComponent *)((m_Flags & 0x1000) != 0
                                                     ? v10->m_Components.p[2].m_pComponent
                                                     : UFG::SimObject::GetComponentOfType(
                                                         v10,
                                                         UFG::TSActorComponent::_TypeUID));
          }
          else
          {
            m_pComponent = (UFG::TSActorComponent *)v10->m_Components.p[4].m_pComponent;
          }
          if ( m_pComponent )
          {
            Actor = UFG::TSActorComponent::GetActor(m_pComponent);
            APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(v6, Actor);
          }
        }
        ++p_get_topmost_scope;
        --v9;
      }
      while ( v9 );
    }
    i_count = v6->i_count;
    if ( (_DWORD)i_count )
    {
      i_array_p = (ARefCountMix<SSInstance> **)v6->i_array_p;
      for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
        UFG::PersistentData::MapFloat::Iterator::Next(*i_array_p + 4);
    }
    *ppResult = SSList::as_instance((SSList *)v6);
  }
}

// File Line: 332
// RVA: 0x5067D0
void __fastcall UFG::TSDynamicEncounter::Mthd_replenish(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  (*((void (__fastcall **)(SSObjectBaseVtbl *))i_obj_p[2].vfptr->__vecDelDtor + 23))(i_obj_p[2].vfptr);
}

// File Line: 338
// RVA: 0x4FD490
void __fastcall UFG::TSDynamicEncounter::Mthd_get_kill_count(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  unsigned int v5; // eax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v5 = (*((__int64 (__fastcall **)(SSObjectBaseVtbl *))i_obj_p[2].vfptr->__vecDelDtor + 31))(i_obj_p[2].vfptr);
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, v5);
  }
}

// File Line: 347
// RVA: 0x4F45E0
void __fastcall UFG::TSDynamicEncounter::Mthd_add_vehicle_and_occupants_into_system(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  unsigned int v3; // esi
  SSObjectBaseVtbl *vfptr; // r12
  SSActor *i_data_p; // rdi
  SSClass *i_class_p; // rbx
  UFG::SimObjectGame *v7; // rdi
  __int16 m_Flags; // cx
  UFG::VehicleOccupantComponent *m_pComponent; // rbp
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int NumberOfOccupants; // r15d
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // r14
  void *(__fastcall *vecDelDtor)(SSObjectBase *, unsigned int); // rbx
  UFG::SimObject *Occupant; // rax
  __int64 v15; // rax
  UFG::EncounterUnitComponent *v16; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  v3 = 0;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_9;
  i_class_p = i_data_p->i_class_p;
  if ( i_class_p->vfptr->is_actor_class(i_class_p) )
    goto LABEL_10;
  if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
  else
LABEL_9:
    i_data_p = 0i64;
LABEL_10:
  v7 = *(UFG::SimObjectGame **)&i_data_p[1].i_icoroutines_to_update.i_count;
  if ( !v7 )
    return;
  (*((void (__fastcall **)(SSObjectBaseVtbl *, UFG::SimObjectGame *))vfptr->__vecDelDtor + 27))(vfptr, v7);
  m_Flags = v7->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_17;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0 )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(v7, UFG::VehicleOccupantComponent::_TypeUID);
      goto LABEL_19;
    }
LABEL_17:
    ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::VehicleOccupantComponent::_TypeUID);
LABEL_19:
    m_pComponent = (UFG::VehicleOccupantComponent *)ComponentOfType;
    goto LABEL_20;
  }
  m_pComponent = (UFG::VehicleOccupantComponent *)v7->m_Components.p[30].m_pComponent;
LABEL_20:
  if ( m_pComponent )
  {
    NumberOfOccupants = UFG::VehicleOccupantComponent::GetNumberOfOccupants(m_pComponent);
    if ( NumberOfOccupants )
    {
      p_m_SafePointerList = &v7->m_SafePointerList;
      do
      {
        vecDelDtor = vfptr->__vecDelDtor;
        Occupant = UFG::VehicleOccupantComponent::GetOccupant(m_pComponent, v3, 0i64);
        v15 = (*((__int64 (__fastcall **)(SSObjectBaseVtbl *, UFG::SimObject *))vecDelDtor + 28))(vfptr, Occupant);
        v16 = (UFG::EncounterUnitComponent *)v15;
        v17 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v15 + 160);
        if ( *(_QWORD *)(v15 + 176) )
        {
          mPrev = v17->mPrev;
          v19 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v15 + 168);
          mPrev->mNext = v19;
          v19->mPrev = mPrev;
          v17->mPrev = v17;
          *(_QWORD *)(v15 + 168) = v15 + 160;
        }
        *(_QWORD *)(v15 + 176) = v7;
        v20 = p_m_SafePointerList->mNode.mPrev;
        v20->mNext = v17;
        v17->mPrev = v20;
        v17->mNext = &p_m_SafePointerList->mNode;
        p_m_SafePointerList->mNode.mPrev = v17;
        UFG::EncounterUnitComponent::IncrementGroupVehicleUsageCount(v16);
        ++v3;
      }
      while ( v3 < NumberOfOccupants );
    }
  }
}

// File Line: 372
// RVA: 0x4F3C90
void __fastcall UFG::TSDynamicEncounter::Mthd_add_character_into_system(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rsi
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rdi
  UFG::SimObject *v6; // rbx
  __int16 m_Flags; // cx
  unsigned int v8; // edx
  UFG::SimObjectGame *v9; // rcx
  bool v10; // zf

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_9;
  i_class_p = i_data_p->i_class_p;
  if ( i_class_p->vfptr->is_actor_class(i_class_p) )
    goto LABEL_10;
  if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
  else
LABEL_9:
    i_data_p = 0i64;
LABEL_10:
  v6 = *(UFG::SimObject **)&i_data_p[1].i_icoroutines_to_update.i_count;
  if ( !v6 )
    return;
  m_Flags = v6->m_Flags;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
    {
      v8 = UFG::CharacterOccupantComponent::_TypeUID;
      v9 = (UFG::SimObjectGame *)v6;
    }
    else
    {
      v8 = UFG::CharacterOccupantComponent::_TypeUID;
      v10 = (m_Flags & 0x1000) == 0;
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
  (*((void (__fastcall **)(SSObjectBaseVtbl *, UFG::SimObject *))vfptr->__vecDelDtor + 28))(vfptr, v6);
}

// File Line: 388
// RVA: 0x507C20
void __fastcall UFG::TSDynamicEncounter::Mthd_set_combat_region(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  UFG::EncounterBase::SetCombatRegion(
    (UFG::EncounterBase *)i_obj_p[2].vfptr,
    (UFG::CombatRegion *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 396
// RVA: 0x4F6470
void __fastcall UFG::TSDynamicEncounter::Mthd_clear_combat_region(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  UFG::EncounterBase::SetCombatRegion((UFG::EncounterBase *)i_obj_p[2].vfptr, 0i64);
}

// File Line: 402
// RVA: 0x507920
void __fastcall UFG::TSDynamicEncounter::Mthd_set_character_spawn_regions(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  UFG::EncounterBase *vfptr; // rsi
  unsigned int *i_user_data; // rcx
  __int64 v5; // rbx
  __int64 v6; // rdi

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::EncounterBase *)i_obj_p[2].vfptr;
  i_user_data = (unsigned int *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v5 = *((_QWORD *)i_user_data + 1);
  if ( *i_user_data )
  {
    v6 = *i_user_data;
    do
    {
      UFG::EncounterBase::AddCharacterSpawnRegion(
        vfptr,
        *(UFG::RegionComponent **)(*(_QWORD *)(*(_QWORD *)v5 + 32i64) + 216i64));
      v5 += 8i64;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 418
// RVA: 0x4F6450
void __fastcall UFG::TSDynamicEncounter::Mthd_clear_character_spawn_regions(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  UFG::EncounterBase::ClearCharacterSpawnRegions((UFG::EncounterBase *)i_obj_p[2].vfptr);
}

// File Line: 424
// RVA: 0x5078E0
void __fastcall UFG::TSDynamicEncounter::Mthd_set_character_can_enter_exit_vehicle(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // rax
  SSObjectBase *i_obj_p; // rcx

  i_array_p = pScope->i_data.i_array_p;
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  UFG::ThugsEncounter::SetCharacterCanEnterExitVehicle(
    (UFG::ThugsEncounter *)i_obj_p[2].vfptr,
    (*i_array_p)->i_data_p->i_user_data != 0);
}


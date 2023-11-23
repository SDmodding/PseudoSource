// File Line: 62
// RVA: 0x4FC420
void __fastcall UFG::TSProp::Mthd_get_damage(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  float Damage; // xmm6_4
  UFG::SimObject *vfptr; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::StateMachineComponent *v7; // rcx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    Damage = 0.0;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (UFG::SimObject *)i_obj_p[13].vfptr;
    if ( vfptr )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(vfptr, UFG::RigidBodyComponent::_TypeUID);
      if ( ComponentOfType )
      {
        v7 = (UFG::StateMachineComponent *)ComponentOfType[6].vfptr;
        if ( v7 )
          Damage = UFG::StateMachineComponent::GetDamage(v7);
      }
    }
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(Damage));
  }
}

// File Line: 83
// RVA: 0x5011F0
void __fastcall UFG::TSProp::Mthd_is_collected(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  char v4; // di
  UFG::CollectibleComponent *CollectibleComponent; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v4 = 0;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    CollectibleComponent = UFG::CollectibleComponent::GetCollectibleComponent((UFG::SimObject *)i_obj_p[13].vfptr);
    if ( CollectibleComponent )
      v4 = ((__int64 (__fastcall *)(UFG::CollectibleComponent *))CollectibleComponent->vfptr[19].__vecDelDtor)(CollectibleComponent);
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 106
// RVA: 0x4D2CB0
void UFG::TSDoor::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("Door");
  SSClass::register_method_func(v0, "enable_lock_private", UFG::TSDoor::MthdC_enable_lock, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "is_opened_by_script_private", UFG::TSDoor::MthdC_is_opened_by_script, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "open_close_by_script_private", UFG::TSDoor::MthdC_open_close_by_script, 1, rebindb);
}

// File Line: 118
// RVA: 0x4E4FF0
void __fastcall UFG::TSDoor::MthdC_enable_lock(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  UFG::qSymbol *i_data_p; // rdi
  bool v4; // bl
  UFG::GameStatTracker *v5; // rax
  UFG::qBaseNodeRB *SimObject; // rax
  UFG::DoorComponent *ComponentOfType; // rax

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (UFG::qSymbol *)(*i_array_p)->i_data_p;
  v4 = i_array_p[1]->i_data_p->i_user_data != 0;
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v5, DoorStateLocked, i_data_p + 8, v4);
  SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, i_data_p + 8);
  if ( SimObject )
  {
    ComponentOfType = (UFG::DoorComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)SimObject,
                                              UFG::DoorComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::DoorComponent::UpdateLockedState(ComponentOfType);
  }
}

// File Line: 135
// RVA: 0x4E96A0
void __fastcall UFG::TSDoor::MthdC_is_opened_by_script(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rbx
  UFG::GameStatTracker *v4; // rax
  bool Stat; // al

  if ( ppResult )
  {
    i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
    v4 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v4, DoorOpenedByScript, (UFG::qSymbol *)&i_data_p->i_user_data);
    *ppResult = SSBoolean::pool_new(Stat);
  }
}

// File Line: 144
// RVA: 0x4EB070
void __fastcall UFG::TSDoor::MthdC_open_close_by_script(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  UFG::qSymbol *p_i_user_data; // rsi
  bool v5; // bl
  UFG::GameStatTracker *v6; // rax
  bool v7; // bl
  UFG::GameStatTracker *v8; // rax
  UFG::qBaseNodeRB *SimObject; // rax
  UFG::DoorComponent *ComponentOfType; // rax

  i_array_p = pScope->i_data.i_array_p;
  p_i_user_data = (UFG::qSymbol *)&(*i_array_p)->i_data_p->i_user_data;
  v5 = i_array_p[1]->i_data_p->i_user_data != 0;
  v6 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v6, DoorOpenedByScript, p_i_user_data, v5);
  v7 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64) != 0i64;
  v8 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v8, DoorStateIsLeft, p_i_user_data, v7);
  SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, p_i_user_data);
  if ( SimObject )
  {
    ComponentOfType = (UFG::DoorComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)SimObject,
                                              UFG::DoorComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::DoorComponent::UpdateOpenedState(ComponentOfType);
  }
}


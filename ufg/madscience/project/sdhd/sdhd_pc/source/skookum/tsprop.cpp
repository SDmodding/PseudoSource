// File Line: 62
// RVA: 0x4FC420
void __fastcall UFG::TSProp::Mthd_get_damage(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  float v4; // xmm6_4
  UFG::SimObject *v5; // rcx
  UFG::SimComponent *v6; // rax
  UFG::StateMachineComponent *v7; // rcx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    v4 = 0.0;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v5 = (UFG::SimObject *)v2[13].vfptr;
    if ( v5 )
    {
      v6 = UFG::SimObject::GetComponentOfType(v5, UFG::RigidBodyComponent::_TypeUID);
      if ( v6 )
      {
        v7 = (UFG::StateMachineComponent *)v6[6].vfptr;
        if ( v7 )
          v4 = UFG::StateMachineComponent::GetDamage(v7);
      }
    }
    *v3 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v4));
  }
}

// File Line: 83
// RVA: 0x5011F0
void __fastcall UFG::TSProp::Mthd_is_collected(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx
  char v4; // di
  SSInstance **v5; // rbx
  UFG::CollectibleComponent *v6; // rax

  if ( ppResult )
  {
    v2 = pScope;
    v3 = pScope->i_scope_p.i_obj_p;
    v4 = 0;
    v5 = ppResult;
    if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v6 = UFG::CollectibleComponent::GetCollectibleComponent((UFG::SimObject *)v3[13].vfptr);
    if ( v6 )
      v4 = ((__int64 (__fastcall *)(UFG::CollectibleComponent *))v6->vfptr[19].__vecDelDtor)(v6);
    *v5 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 106
// RVA: 0x4D2CB0
void UFG::TSDoor::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("Door");
  SSClass::register_method_func(v0, "enable_lock_private", UFG::TSDoor::MthdC_enable_lock, 1, 0);
  SSClass::register_method_func(v0, "is_opened_by_script_private", UFG::TSDoor::MthdC_is_opened_by_script, 1, 0);
  SSClass::register_method_func(v0, "open_close_by_script_private", UFG::TSDoor::MthdC_open_close_by_script, 1, 0);
}

// File Line: 118
// RVA: 0x4E4FF0
void __fastcall UFG::TSDoor::MthdC_enable_lock(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  UFG::qSymbol *v3; // rdi
  bool v4; // bl
  UFG::GameStatTracker *v5; // rax
  UFG::qBaseNodeRB *v6; // rax
  UFG::DoorComponent *v7; // rax

  v2 = pScope->i_data.i_array_p;
  v3 = (UFG::qSymbol *)(*v2)->i_data_p;
  v4 = v2[1]->i_data_p->i_user_data != 0;
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v5, DoorStateLocked, v3 + 8, v4);
  v6 = UFG::Simulation::GetSimObject(&UFG::gSim, v3 + 8);
  if ( v6 )
  {
    v7 = (UFG::DoorComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)v6, UFG::DoorComponent::_TypeUID);
    if ( v7 )
      UFG::DoorComponent::UpdateLockedState(v7);
  }
}

// File Line: 135
// RVA: 0x4E96A0
void __fastcall UFG::TSDoor::MthdC_is_opened_by_script(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  SSInstance *v3; // rbx
  UFG::GameStatTracker *v4; // rax
  bool v5; // al

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (*pScope->i_data.i_array_p)->i_data_p;
    v4 = UFG::GameStatTracker::Instance();
    v5 = UFG::GameStatTracker::GetStat(v4, DoorOpenedByScript, (UFG::qSymbol *)&v3->i_user_data);
    *v2 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 144
// RVA: 0x4EB070
void __fastcall UFG::TSDoor::MthdC_open_close_by_script(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  SSInvokedMethod *v3; // rdi
  UFG::qSymbol *v4; // rsi
  bool v5; // bl
  UFG::GameStatTracker *v6; // rax
  bool v7; // bl
  UFG::GameStatTracker *v8; // rax
  UFG::qBaseNodeRB *v9; // rax
  UFG::DoorComponent *v10; // rax

  v2 = pScope->i_data.i_array_p;
  v3 = pScope;
  v4 = (UFG::qSymbol *)&(*v2)->i_data_p->i_user_data;
  v5 = v2[1]->i_data_p->i_user_data != 0;
  v6 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v6, DoorOpenedByScript, v4, v5);
  v7 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 2) + 8i64) + 32i64) != 0i64;
  v8 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v8, DoorStateIsLeft, v4, v7);
  v9 = UFG::Simulation::GetSimObject(&UFG::gSim, v4);
  if ( v9 )
  {
    v10 = (UFG::DoorComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)v9, UFG::DoorComponent::_TypeUID);
    if ( v10 )
      UFG::DoorComponent::UpdateOpenedState(v10);
  }
}


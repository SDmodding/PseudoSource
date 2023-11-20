// File Line: 59
// RVA: 0x4D2900
void UFG::TSCollectible::BindAtomics(void)
{
  UFG::TSCollectible::mspCollectibleClass = SSBrain::get_class("Collectible");
  SSClass::register_method_func(UFG::TSCollectible::mspCollectibleClass, "collect", UFG::TSCollectible::Mthd_collect, 0);
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "is_collected",
    UFG::TSCollectible::Mthd_is_collected,
    0);
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "is_usable",
    UFG::TSCollectible::Mthd_is_usable,
    0);
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "is_locked",
    UFG::TSCollectible::Mthd_is_locked,
    0);
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "collect",
    UFG::TSCollectible::MthdC_collect,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "is_collected",
    UFG::TSCollectible::MthdC_is_collected,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "is_usable",
    UFG::TSCollectible::MthdC_is_usable,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "collect_by_type",
    UFG::TSCollectible::MthdC_collect_by_type,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "is_collected_by_type",
    UFG::TSCollectible::MthdC_is_collected_by_type,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "get_collected_count_by_type",
    UFG::TSCollectible::MthdC_get_collected_count_by_type,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "unlock_weapon_spawner",
    UFG::TSCollectible::MthdC_unlock_weapon_spawner,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "list_collect_of_type",
    UFG::TSCollectible::MthdC_list_collect_of_type,
    1,
    0);
}

// File Line: 83
// RVA: 0x501190
void __fastcall UFG::TSCollectible::Mthd_is_collected(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  UFG::CollectibleComponent *v4; // rax
  char v5; // al

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = UFG::CollectibleComponent::GetCollectibleComponent((UFG::SimObject *)v2[2].vfptr->set_data_by_name);
    if ( v4 )
    {
      v5 = ((__int64 (__fastcall *)(UFG::CollectibleComponent *))v4->vfptr[19].__vecDelDtor)(v4);
      *v3 = (SSInstance *)SSBoolean::pool_new(v5);
    }
  }
}

// File Line: 97
// RVA: 0x4F68C0
void __fastcall UFG::TSCollectible::Mthd_collect(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSInvokedMethod *v3; // rbx
  UFG::CollectibleComponent *v4; // rax
  SSData *v5; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = pScope;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = UFG::CollectibleComponent::GetCollectibleComponent((UFG::SimObject *)v2[2].vfptr->set_data_by_name);
  if ( v4 )
  {
    v5 = *v3->i_data.i_array_p;
    LOBYTE(v5) = v5->i_data_p->i_user_data != 0;
    v4->vfptr[24].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v4->vfptr, (unsigned int)v5);
  }
}

// File Line: 108
// RVA: 0x503B20
void __fastcall UFG::TSCollectible::Mthd_is_usable(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  UFG::CollectibleComponent *v4; // rax
  char v5; // al

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = UFG::CollectibleComponent::GetCollectibleComponent((UFG::SimObject *)v2[2].vfptr->set_data_by_name);
    if ( v4 )
    {
      v5 = ((__int64 (__fastcall *)(UFG::CollectibleComponent *))v4->vfptr[20].__vecDelDtor)(v4);
      *v3 = (SSInstance *)SSBoolean::pool_new(v5);
    }
  }
}

// File Line: 122
// RVA: 0x502610
void __fastcall UFG::TSCollectible::Mthd_is_locked(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  UFG::CollectibleComponent *v4; // rax
  char v5; // al

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = UFG::CollectibleComponent::GetCollectibleComponent((UFG::SimObject *)v2[2].vfptr->set_data_by_name);
    if ( v4 )
    {
      v5 = ((__int64 (__fastcall *)(UFG::CollectibleComponent *))v4->vfptr[21].__vecDelDtor)(v4);
      *v3 = (SSInstance *)SSBoolean::pool_new(v5);
    }
  }
}

// File Line: 136
// RVA: 0x4E93F0
void __fastcall UFG::TSCollectible::MthdC_is_collected(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::CollectibleComponent *v3; // rax
  char v4; // cl
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v3 = UFG::CollectibleComponent::GetCollectibleComponent(&name);
    v4 = 0;
    if ( v3 )
      v4 = ((__int64 (__fastcall *)(UFG::CollectibleComponent *))v3->vfptr[19].__vecDelDtor)(v3);
    *v2 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 152
// RVA: 0x4E46B0
void __fastcall UFG::TSCollectible::MthdC_collect(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::CollectibleComponent *v3; // rax
  __int64 v4; // rdx
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]

  v2 = pScope;
  name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::CollectibleComponent::GetCollectibleComponent(&name);
  if ( v3 )
  {
    v4 = *((_QWORD *)v2->i_data.i_array_p + 1);
    LOBYTE(v4) = *(_QWORD *)(*(_QWORD *)(v4 + 8) + 32i64) != 0i64;
    v3->vfptr[24].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v3->vfptr, v4);
  }
}

// File Line: 163
// RVA: 0x4E9440
void __fastcall UFG::TSCollectible::MthdC_is_collected_by_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSInstance **v3; // rdi
  UFG::GameStat::MapBoolStat v4; // ebx
  UFG::GameStat::MapInt32Stat v5; // ebx
  UFG::GameStatTracker *v6; // rax
  unsigned int v7; // eax
  UFG::GameStatTracker *v8; // rax
  bool v9; // al
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]
  UFG::qSymbol v11; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v2 = pScope->i_data.i_array_p;
    v3 = ppResult;
    name.mUID = (*v2)->i_data_p->i_user_data;
    v11.mUID = v2[1]->i_data_p->i_user_data;
    v4 = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(&name, 0);
    if ( v4 == 93 )
    {
      v5 = (unsigned int)UFG::GameStat::GetMapInt32StatEnum(&name, 0);
      v6 = UFG::GameStatTracker::Instance();
      v7 = UFG::GameStatTracker::GetStat(v6, v5, &v11);
      *v3 = SSInstance::pool_new(SSBrain::c_integer_class_p, v7);
    }
    else
    {
      v8 = UFG::GameStatTracker::Instance();
      v9 = UFG::GameStatTracker::GetStat(v8, v4, &v11);
      *v3 = (SSInstance *)SSBoolean::pool_new(v9);
    }
  }
}

// File Line: 184
// RVA: 0x4E7510
void __fastcall UFG::TSCollectible::MthdC_get_collected_count_by_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  UFG::GameStat::MapBoolStat v3; // ebx
  UFG::GameStat::MapInt32Stat v4; // ebx
  UFG::GameStatTracker *v5; // rax
  UFG::qArray<unsigned long,0> *v6; // rax
  unsigned int v7; // eax
  UFG::GameStatTracker *v8; // rax
  UFG::PersistentData::MapBool *v9; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v3 = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(&name, 0);
    if ( v3 == 93 )
    {
      v4 = (unsigned int)UFG::GameStat::GetMapInt32StatEnum(&name, 0);
      v5 = UFG::GameStatTracker::Instance();
      v6 = (UFG::qArray<unsigned long,0> *)UFG::GameStatTracker::GetMapInt(v5, v4);
      v7 = UFG::qSymbolUC::as_uint32(v6);
    }
    else
    {
      v8 = UFG::GameStatTracker::Instance();
      v9 = UFG::GameStatTracker::GetMapBool(v8, v3);
      v7 = UFG::PersistentData::MapBool::GetCount(v9);
    }
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, v7);
  }
}

// File Line: 206
// RVA: 0x4E4710
void __fastcall UFG::TSCollectible::MthdC_collect_by_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSInvokedMethod *v3; // rbx
  UFG::GameStat::MapBoolStat v4; // edi
  UFG::GameStat::MapInt32Stat v5; // edi
  __int64 v6; // rbx
  UFG::GameStatTracker *v7; // rax
  bool v8; // bl
  UFG::GameStatTracker *v9; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]
  UFG::qSymbol v11; // [rsp+40h] [rbp+18h]

  v2 = pScope->i_data.i_array_p;
  v3 = pScope;
  name.mUID = (*v2)->i_data_p->i_user_data;
  v11.mUID = v2[1]->i_data_p->i_user_data;
  v4 = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(&name, 0);
  if ( v4 == 93 )
  {
    v5 = (unsigned int)UFG::GameStat::GetMapInt32StatEnum(&name, 0);
    v6 = *(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 2) + 8i64);
    v7 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v7, v5, &v11, *(_DWORD *)(v6 + 32));
  }
  else
  {
    v8 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 2) + 8i64) + 32i64) != 0i64;
    v9 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v9, v4, &v11, v8);
  }
}

// File Line: 224
// RVA: 0x4E9D10
void __fastcall UFG::TSCollectible::MthdC_is_usable(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::CollectibleComponent *v3; // rax
  char v4; // cl
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v3 = UFG::CollectibleComponent::GetCollectibleComponent(&name);
    v4 = 0;
    if ( v3 )
      v4 = ((__int64 (__fastcall *)(UFG::CollectibleComponent *))v3->vfptr[20].__vecDelDtor)(v3);
    *v2 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 240
// RVA: 0x4F2B90
void __fastcall UFG::TSCollectible::MthdC_unlock_weapon_spawner(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStatTracker *v3; // rax
  UFG::PersistentData::MapBool *v4; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]

  v2 = pScope;
  name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::GameStatTracker::Instance();
  v4 = UFG::GameStatTracker::GetMapBool(v3, Collectible_WeaponSpawner);
  UFG::PersistentData::MapBool::SetStatus(
    v4,
    &name,
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
}

// File Line: 251
// RVA: 0x4EA760
void __fastcall UFG::TSCollectible::MthdC_list_collect_of_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // r14
  SSList *v3; // rdi
  UFG::GameStat::MapBoolStat v4; // ebx
  UFG::GameStatTracker *v5; // rax
  UFG::PersistentData::MapFloat *v6; // rax
  UFG::PersistentData::KeyValue *v7; // rax
  UFG::qBaseNodeRB *v8; // rax
  UFG::SimComponent *v9; // rax
  unsigned __int64 v10; // rbx
  int v11; // eax
  SSClass *v12; // rcx
  SSInstance *v13; // rax
  __int64 v14; // rax
  ARefCountMix<SSInstance> **v15; // rbx
  unsigned __int64 i; // rsi
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+28h] [rbp-30h]
  UFG::qSymbol name; // [rsp+68h] [rbp+10h]
  SSList *v19; // [rsp+70h] [rbp+18h]

  if ( ppResult )
  {
    v2 = ppResult;
    name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v3 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v19 = v3;
    if ( v3 )
    {
      v3->i_items.i_count = 0;
      v3->i_items.i_array_p = 0i64;
      v3->i_items.i_size = 0;
      v3->i_items.i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      v3 = 0i64;
    }
    v4 = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(&name, 0);
    if ( v4 )
    {
      v5 = UFG::GameStatTracker::Instance();
      v6 = (UFG::PersistentData::MapFloat *)UFG::GameStatTracker::GetMapBool(v5, v4);
      UFG::PersistentData::MapInt::GetIterator(v6, &result);
      while ( UFG::PersistentData::MapBool::Iterator::IsValid((UFG::PersistentData::MapBool::Iterator *)&result) )
      {
        v7 = UFG::PersistentData::MapBool::Iterator::GetName((UFG::PersistentData::MapBool::Iterator *)&result);
        v8 = UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)v7);
        if ( v8 )
        {
          v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v8, UFG::MarkerBase::_TypeUID);
          v10 = (unsigned __int64)v9;
          v11 = ((__int64 (__fastcall *)(UFG::SimComponent *))v9->vfptr[16].__vecDelDtor)(v9);
          if ( v11 == 4 )
          {
            v12 = UFG::TSTriggerRegion::mspTriggerRegionClass;
          }
          else if ( v11 == 8 )
          {
            v12 = UFG::TSSpawnPoint::mspSpawnPointClass;
          }
          else
          {
            v12 = UFG::TSInterestPoint::mspInterestPointClass;
            if ( v11 != 512 )
              v12 = UFG::TSMarker::mspMarkerClass;
          }
          v13 = SSInstance::pool_new(v12, v10);
          APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(&v3->i_items, v13);
        }
        UFG::PersistentData::MapFloat::Iterator::Next((ARefCountMix<SSInstance> *)&result);
      }
    }
    v14 = v3->i_items.i_count;
    if ( (_DWORD)v14 )
    {
      v15 = (ARefCountMix<SSInstance> **)v3->i_items.i_array_p;
      for ( i = (unsigned __int64)&v15[v14]; (unsigned __int64)v15 < i; ++v15 )
        UFG::PersistentData::MapFloat::Iterator::Next(*v15 + 4);
    }
    *v2 = SSList::as_instance(v3);
  }
}


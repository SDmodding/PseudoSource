// File Line: 59
// RVA: 0x4D2900
void UFG::TSCollectible::BindAtomics(void)
{
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]
  ASymbol rebindg; // [rsp+20h] [rbp-18h]

  UFG::TSCollectible::mspCollectibleClass = SSBrain::get_class("Collectible");
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "collect",
    UFG::TSCollectible::Mthd_collect,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "is_collected",
    UFG::TSCollectible::Mthd_is_collected,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "is_usable",
    UFG::TSCollectible::Mthd_is_usable,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "is_locked",
    UFG::TSCollectible::Mthd_is_locked,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "collect",
    UFG::TSCollectible::MthdC_collect,
    1,
    rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "is_collected",
    UFG::TSCollectible::MthdC_is_collected,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "is_usable",
    UFG::TSCollectible::MthdC_is_usable,
    1,
    rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "collect_by_type",
    UFG::TSCollectible::MthdC_collect_by_type,
    1,
    rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "is_collected_by_type",
    UFG::TSCollectible::MthdC_is_collected_by_type,
    1,
    rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "get_collected_count_by_type",
    UFG::TSCollectible::MthdC_get_collected_count_by_type,
    1,
    rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "unlock_weapon_spawner",
    UFG::TSCollectible::MthdC_unlock_weapon_spawner,
    1,
    rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSCollectible::mspCollectibleClass,
    "list_collect_of_type",
    UFG::TSCollectible::MthdC_list_collect_of_type,
    1,
    rebindg);
}

// File Line: 83
// RVA: 0x501190
void __fastcall UFG::TSCollectible::Mthd_is_collected(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  UFG::CollectibleComponent *CollectibleComponent; // rax
  char v5; // al

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    CollectibleComponent = UFG::CollectibleComponent::GetCollectibleComponent((UFG::SimObject *)i_obj_p[2].vfptr->set_data_by_name);
    if ( CollectibleComponent )
    {
      v5 = ((__int64 (__fastcall *)(UFG::CollectibleComponent *))CollectibleComponent->vfptr[19].__vecDelDtor)(CollectibleComponent);
      *ppResult = SSBoolean::pool_new(v5);
    }
  }
}

// File Line: 97
// RVA: 0x4F68C0
void __fastcall UFG::TSCollectible::Mthd_collect(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  UFG::CollectibleComponent *CollectibleComponent; // rax
  SSData *v5; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  CollectibleComponent = UFG::CollectibleComponent::GetCollectibleComponent((UFG::SimObject *)i_obj_p[2].vfptr->set_data_by_name);
  if ( CollectibleComponent )
  {
    v5 = *pScope->i_data.i_array_p;
    LOBYTE(v5) = v5->i_data_p->i_user_data != 0;
    CollectibleComponent->vfptr[24].__vecDelDtor(CollectibleComponent, (unsigned int)v5);
  }
}

// File Line: 108
// RVA: 0x503B20
void __fastcall UFG::TSCollectible::Mthd_is_usable(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  UFG::CollectibleComponent *CollectibleComponent; // rax
  char v5; // al

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    CollectibleComponent = UFG::CollectibleComponent::GetCollectibleComponent((UFG::SimObject *)i_obj_p[2].vfptr->set_data_by_name);
    if ( CollectibleComponent )
    {
      v5 = ((__int64 (__fastcall *)(UFG::CollectibleComponent *))CollectibleComponent->vfptr[20].__vecDelDtor)(CollectibleComponent);
      *ppResult = SSBoolean::pool_new(v5);
    }
  }
}

// File Line: 122
// RVA: 0x502610
void __fastcall UFG::TSCollectible::Mthd_is_locked(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  UFG::CollectibleComponent *CollectibleComponent; // rax
  char v5; // al

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    CollectibleComponent = UFG::CollectibleComponent::GetCollectibleComponent((UFG::SimObject *)i_obj_p[2].vfptr->set_data_by_name);
    if ( CollectibleComponent )
    {
      v5 = ((__int64 (__fastcall *)(UFG::CollectibleComponent *))CollectibleComponent->vfptr[21].__vecDelDtor)(CollectibleComponent);
      *ppResult = SSBoolean::pool_new(v5);
    }
  }
}

// File Line: 136
// RVA: 0x4E93F0
void __fastcall UFG::TSCollectible::MthdC_is_collected(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::CollectibleComponent *CollectibleComponent; // rax
  char v4; // cl
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF

  if ( ppResult )
  {
    name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    CollectibleComponent = UFG::CollectibleComponent::GetCollectibleComponent(&name);
    v4 = 0;
    if ( CollectibleComponent )
      v4 = ((__int64 (__fastcall *)(UFG::CollectibleComponent *))CollectibleComponent->vfptr[19].__vecDelDtor)(CollectibleComponent);
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 152
// RVA: 0x4E46B0
void __fastcall UFG::TSCollectible::MthdC_collect(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::CollectibleComponent *CollectibleComponent; // rax
  __int64 v4; // rdx
  UFG::qSymbol name; // [rsp+30h] [rbp+8h] BYREF

  name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  CollectibleComponent = UFG::CollectibleComponent::GetCollectibleComponent(&name);
  if ( CollectibleComponent )
  {
    v4 = *((_QWORD *)pScope->i_data.i_array_p + 1);
    LOBYTE(v4) = *(_QWORD *)(*(_QWORD *)(v4 + 8) + 32i64) != 0i64;
    CollectibleComponent->vfptr[24].__vecDelDtor(CollectibleComponent, v4);
  }
}

// File Line: 163
// RVA: 0x4E9440
void __fastcall UFG::TSCollectible::MthdC_is_collected_by_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  UFG::GameStat::MapBoolStat MapBoolStatEnum; // ebx
  UFG::GameStat::MapInt32Stat MapInt32StatEnum; // ebx
  UFG::GameStatTracker *v6; // rax
  unsigned int Stat; // eax
  UFG::GameStatTracker *v8; // rax
  bool v9; // al
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF
  UFG::qSymbol v11; // [rsp+40h] [rbp+18h] BYREF

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    name.mUID = (*i_array_p)->i_data_p->i_user_data;
    v11.mUID = i_array_p[1]->i_data_p->i_user_data;
    MapBoolStatEnum = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(&name, 0);
    if ( MapBoolStatEnum == Num_MapBool_Stats )
    {
      MapInt32StatEnum = (unsigned int)UFG::GameStat::GetMapInt32StatEnum(&name, 0);
      v6 = UFG::GameStatTracker::Instance();
      Stat = UFG::GameStatTracker::GetStat(v6, MapInt32StatEnum, &v11);
      *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, Stat);
    }
    else
    {
      v8 = UFG::GameStatTracker::Instance();
      v9 = UFG::GameStatTracker::GetStat(v8, MapBoolStatEnum, &v11);
      *ppResult = SSBoolean::pool_new(v9);
    }
  }
}

// File Line: 184
// RVA: 0x4E7510
void __fastcall UFG::TSCollectible::MthdC_get_collected_count_by_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStat::MapBoolStat MapBoolStatEnum; // ebx
  UFG::GameStat::MapInt32Stat MapInt32StatEnum; // ebx
  UFG::GameStatTracker *v5; // rax
  UFG::qArray<unsigned long,0> *MapInt; // rax
  unsigned int Count; // eax
  UFG::GameStatTracker *v8; // rax
  UFG::PersistentData::MapBool *MapBool; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF

  if ( ppResult )
  {
    name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    MapBoolStatEnum = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(&name, 0);
    if ( MapBoolStatEnum == Num_MapBool_Stats )
    {
      MapInt32StatEnum = (unsigned int)UFG::GameStat::GetMapInt32StatEnum(&name, 0);
      v5 = UFG::GameStatTracker::Instance();
      MapInt = (UFG::qArray<unsigned long,0> *)UFG::GameStatTracker::GetMapInt(v5, MapInt32StatEnum);
      Count = UFG::qSymbolUC::as_uint32(MapInt);
    }
    else
    {
      v8 = UFG::GameStatTracker::Instance();
      MapBool = UFG::GameStatTracker::GetMapBool(v8, MapBoolStatEnum);
      Count = UFG::PersistentData::MapBool::GetCount(MapBool);
    }
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, Count);
  }
}

// File Line: 206
// RVA: 0x4E4710
void __fastcall UFG::TSCollectible::MthdC_collect_by_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  UFG::GameStat::MapBoolStat MapBoolStatEnum; // edi
  UFG::GameStat::MapInt32Stat MapInt32StatEnum; // edi
  __int64 v6; // rbx
  UFG::GameStatTracker *v7; // rax
  bool v8; // bl
  UFG::GameStatTracker *v9; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h] BYREF
  UFG::qSymbol v11; // [rsp+40h] [rbp+18h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  name.mUID = (*i_array_p)->i_data_p->i_user_data;
  v11.mUID = i_array_p[1]->i_data_p->i_user_data;
  MapBoolStatEnum = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(&name, 0);
  if ( MapBoolStatEnum == Num_MapBool_Stats )
  {
    MapInt32StatEnum = (unsigned int)UFG::GameStat::GetMapInt32StatEnum(&name, 0);
    v6 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64);
    v7 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v7, MapInt32StatEnum, &v11, *(_DWORD *)(v6 + 32));
  }
  else
  {
    v8 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64) != 0i64;
    v9 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v9, MapBoolStatEnum, &v11, v8);
  }
}

// File Line: 224
// RVA: 0x4E9D10
void __fastcall UFG::TSCollectible::MthdC_is_usable(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::CollectibleComponent *CollectibleComponent; // rax
  char v4; // cl
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF

  if ( ppResult )
  {
    name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    CollectibleComponent = UFG::CollectibleComponent::GetCollectibleComponent(&name);
    v4 = 0;
    if ( CollectibleComponent )
      v4 = ((__int64 (__fastcall *)(UFG::CollectibleComponent *))CollectibleComponent->vfptr[20].__vecDelDtor)(CollectibleComponent);
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 240
// RVA: 0x4F2B90
void __fastcall UFG::TSCollectible::MthdC_unlock_weapon_spawner(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStatTracker *v3; // rax
  UFG::PersistentData::MapBool *MapBool; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h] BYREF

  name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::GameStatTracker::Instance();
  MapBool = UFG::GameStatTracker::GetMapBool(v3, Collectible_WeaponSpawner);
  UFG::PersistentData::MapBool::SetStatus(
    MapBool,
    &name,
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
}

// File Line: 251
// RVA: 0x4EA760
void __fastcall UFG::TSCollectible::MthdC_list_collect_of_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSList *v3; // rdi
  UFG::GameStat::MapBoolStat MapBoolStatEnum; // ebx
  UFG::GameStatTracker *v5; // rax
  UFG::PersistentData::MapFloat *MapBool; // rax
  UFG::PersistentData::KeyValue *v7; // rax
  UFG::qBaseNodeRB *SimObject; // rax
  UFG::SimComponent *ComponentOfType; // rbx
  int v10; // eax
  SSClass *v11; // rcx
  SSInstance *v12; // rax
  __int64 i_count; // rax
  ARefCountMix<SSInstance> **i_array_p; // rbx
  ARefCountMix<SSInstance> **i; // rsi
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+28h] [rbp-30h] BYREF
  UFG::qSymbol name; // [rsp+68h] [rbp+10h] BYREF
  SSList *v18; // [rsp+70h] [rbp+18h]

  if ( ppResult )
  {
    name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v3 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v18 = v3;
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
    MapBoolStatEnum = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(&name, 0);
    if ( MapBoolStatEnum )
    {
      v5 = UFG::GameStatTracker::Instance();
      MapBool = (UFG::PersistentData::MapFloat *)UFG::GameStatTracker::GetMapBool(v5, MapBoolStatEnum);
      UFG::PersistentData::MapInt::GetIterator(MapBool, &result);
      while ( UFG::PersistentData::MapBool::Iterator::IsValid((UFG::PersistentData::MapBool::Iterator *)&result) )
      {
        v7 = UFG::PersistentData::MapBool::Iterator::GetName((UFG::PersistentData::MapBool::Iterator *)&result);
        SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)v7);
        if ( SimObject )
        {
          ComponentOfType = UFG::SimObject::GetComponentOfType((UFG::SimObject *)SimObject, UFG::MarkerBase::_TypeUID);
          v10 = ((__int64 (__fastcall *)(UFG::SimComponent *))ComponentOfType->vfptr[16].__vecDelDtor)(ComponentOfType);
          if ( v10 == 4 )
          {
            v11 = UFG::TSTriggerRegion::mspTriggerRegionClass;
          }
          else if ( v10 == 8 )
          {
            v11 = UFG::TSSpawnPoint::mspSpawnPointClass;
          }
          else
          {
            v11 = UFG::TSInterestPoint::mspInterestPointClass;
            if ( v10 != 512 )
              v11 = UFG::TSMarker::mspMarkerClass;
          }
          v12 = SSInstance::pool_new(v11, (unsigned __int64)ComponentOfType);
          APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(&v3->i_items, v12);
        }
        UFG::PersistentData::MapFloat::Iterator::Next((ARefCountMix<SSInstance> *)&result);
      }
    }
    i_count = v3->i_items.i_count;
    if ( (_DWORD)i_count )
    {
      i_array_p = (ARefCountMix<SSInstance> **)v3->i_items.i_array_p;
      for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
        UFG::PersistentData::MapFloat::Iterator::Next(*i_array_p + 4);
    }
    *ppResult = SSList::as_instance(v3);
  }
}


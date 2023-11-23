// File Line: 155
// RVA: 0x4D53E0
void UFG::TSPropertySet::BindAtomics(void)
{
  UFG::SkookumMgr::mspPropertySetClass = SSBrain::get_class("PropertySet");
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    &ASymbolX_ctor,
    UFG::TSPropertySet::Mthd_ctor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "!new",
    UFG::TSPropertySet::Mthd_ctor_new,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    &ASymbolX_dtor,
    UFG::TSPropertySet::Mthd_dtor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_name",
    UFG::TSMarker::Mthd_get_name,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_parent_count",
    UFG::TSPropertySet::Mthd_get_parent_count,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "is_child_of",
    UFG::TSPropertySet::Mthd_is_child_of,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "is_type",
    UFG::TSPropertySet::Mthd_is_type,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "remove_parent",
    UFG::TSPropertySet::Mthd_remove_parent,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "remove_parents",
    UFG::TSPropertySet::Mthd_remove_parents,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_count_local",
    UFG::TSPropertySet::Mthd_get_property_count_local,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_scope",
    UFG::TSPropertySet::Mthd_get_property_scope,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "is_property_present",
    UFG::TSPropertySet::Mthd_is_property_present,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "append_property_boolean",
    UFG::TSPropertySet::Mthd_append_property_boolean,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "append_property_integer",
    UFG::TSPropertySet::Mthd_append_property_integer,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "append_property_real",
    UFG::TSPropertySet::Mthd_append_property_real,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "append_property_string",
    UFG::TSPropertySet::Mthd_append_property_string,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "append_property_symbol",
    UFG::TSPropertySet::Mthd_append_property_symbol,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "append_property_vector3",
    UFG::TSPropertySet::Mthd_append_property_vector3,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "append_property_set",
    UFG::TSPropertySet::Mthd_append_property_set,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_boolean",
    UFG::TSPropertySet::Mthd_get_property_boolean,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_integer",
    UFG::TSPropertySet::Mthd_get_property_integer,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_real",
    UFG::TSPropertySet::Mthd_get_property_real,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_string",
    UFG::TSPropertySet::Mthd_get_property_string,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_symbol",
    UFG::TSPropertySet::Mthd_get_property_symbol,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_vector3",
    UFG::TSPropertySet::Mthd_get_property_vector3,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_set",
    UFG::TSPropertySet::Mthd_get_property_set,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_list_count",
    UFG::TSPropertySet::Mthd_get_property_list_count,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_list_set",
    UFG::TSPropertySet::Mthd_get_property_list_set,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_list_symbol",
    UFG::TSPropertySet::Mthd_get_property_list_symbol,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_list_boolean",
    UFG::TSPropertySet::Mthd_get_property_list_boolean,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "is_symbol_in_list_property",
    UFG::TSPropertySet::Mthd_is_symbol_in_list_property,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "set_property_boolean",
    UFG::TSPropertySet::Mthd_set_property_boolean,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "set_property_integer",
    UFG::TSPropertySet::Mthd_set_property_integer,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "set_property_real",
    UFG::TSPropertySet::Mthd_set_property_real,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "set_property_string",
    UFG::TSPropertySet::Mthd_set_property_string,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "set_property_symbol",
    UFG::TSPropertySet::Mthd_set_property_symbol,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "set_property_vector3",
    UFG::TSPropertySet::Mthd_set_property_vector3,
    SSBindFlag_instance_no_rebind);
}

// File Line: 212
// RVA: 0x4F8880
void __fastcall UFG::TSPropertySet::Mthd_dtor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  UFG::qPropertySet::ReleaseRef((UFG::qPropertySet *)i_obj_p[2].vfptr);
}

// File Line: 222
// RVA: 0x4F72B0
void __fastcall UFG::TSPropertySet::Mthd_ctor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *v4; // rbx
  SSObjectBase *i_obj_p; // rdx

  PropertySet = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v4 = PropertySet;
  if ( PropertySet )
  {
    UFG::qPropertySet::AddRef(PropertySet);
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_obj_p[2].vfptr = (SSObjectBaseVtbl *)v4;
  }
}

// File Line: 239
// RVA: 0x4F7530
void __fastcall UFG::TSPropertySet::Mthd_ctor_new(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qPropertySet *ContainedPropertySet; // rax
  UFG::qPropertySet *v4; // rbx
  SSObjectBase *i_obj_p; // rdx

  ContainedPropertySet = UFG::PropertySetManager::CreateContainedPropertySet((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v4 = ContainedPropertySet;
  if ( ContainedPropertySet )
  {
    UFG::qPropertySet::AddRef(ContainedPropertySet);
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_obj_p[2].vfptr = (SSObjectBaseVtbl *)v4;
  }
}

// File Line: 272
// RVA: 0x4FDCA0
void __fastcall UFG::TSPropertySet::Mthd_get_parent_count(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  unsigned int v5; // eax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v5 = UFG::qPropertySet::NumParents((UFG::qPropertySet *)i_obj_p[2].vfptr);
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, v5);
  }
}

// File Line: 288
// RVA: 0x501020
void __fastcall UFG::TSPropertySet::Mthd_is_child_of(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rax
  SSObjectBase *i_obj_p; // rcx
  UFG::qPropertySet *ParentFromName; // rax

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    ParentFromName = UFG::qPropertySet::GetParentFromName(
                       (UFG::qPropertySet *)i_obj_p[2].vfptr,
                       (UFG::qArray<unsigned long,0> *)&(*i_array_p)->i_data_p->i_user_data,
                       DEPTH_RECURSE);
    *ppResult = SSBoolean::pool_new(ParentFromName != 0i64);
  }
}

// File Line: 303
// RVA: 0x503AA0
void __fastcall UFG::TSPropertySet::Mthd_is_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  UFG::qPropertySet *vfptr; // r9
  SSInstance *i_data_p; // rdx
  int i_user_data; // eax
  UFG::qArray<unsigned long,0> *p_i_user_data; // rdx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
    i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
    i_user_data = i_data_p->i_user_data;
    p_i_user_data = (UFG::qArray<unsigned long,0> *)&i_data_p->i_user_data;
    if ( vfptr->mName.mUID == i_user_data || UFG::qPropertySet::GetParentFromName(vfptr, p_i_user_data, DEPTH_RECURSE) )
      *ppResult = SSBoolean::pool_new(1);
    else
      *ppResult = SSBoolean::pool_new(0);
  }
}

// File Line: 322
// RVA: 0x5066F0
void __fastcall UFG::TSPropertySet::Mthd_remove_parent(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  UFG::qPropertySet::RemovePropertyByName(
    (UFG::qPropertySet *)i_obj_p[2].vfptr,
    (UFG::qArray<unsigned long,0> *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 334
// RVA: 0x506720
void __fastcall UFG::TSPropertySet::Mthd_remove_parents(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  UFG::qPropertySet::RemoveParentsAll((UFG::qPropertySet *)i_obj_p[2].vfptr);
}

// File Line: 356
// RVA: 0x4FE030
void __fastcall UFG::TSPropertySet::Mthd_get_property_count_local(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, HIWORD(i_obj_p[2].vfptr[1].is_actor));
  }
}

// File Line: 370
// RVA: 0x4FE4D0
void __fastcall UFG::TSPropertySet::Mthd_get_property_scope(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  UFG::qArray<unsigned long,0> *i_data_p; // r9
  int i_user_data; // eax
  BOOL v7; // r8d
  SSObjectBase *i_obj_p; // rcx
  UFG::qPropertySet *v9; // rax
  unsigned __int64 v10; // rdi

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = (UFG::qArray<unsigned long,0> *)(*i_array_p)->i_data_p;
    i_user_data = i_array_p[1]->i_data_p->i_user_data;
    v7 = i_user_data == qSymbol_topmost.mUID || i_user_data != qSymbol_local.mUID;
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v9 = UFG::qPropertySet::PropertyExists((UFG::qPropertySet *)i_obj_p[2].vfptr, i_data_p + 2, (UFG::qPropertyDepth)v7);
    v10 = (unsigned __int64)v9;
    if ( v9 )
    {
      UFG::qPropertySet::AddRef(v9);
      *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspPropertySetClass, v10);
    }
    else
    {
      *ppResult = SSBrain::c_nil_p;
    }
  }
}

// File Line: 398
// RVA: 0x503060
void __fastcall UFG::TSPropertySet::Mthd_is_property_present(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  UFG::qArray<unsigned long,0> *p_i_user_data; // rdx
  int i_user_data; // eax
  BOOL v7; // r8d
  SSObjectBase *i_obj_p; // rcx
  UFG::qPropertySet *v9; // rax

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    p_i_user_data = (UFG::qArray<unsigned long,0> *)&(*i_array_p)->i_data_p->i_user_data;
    i_user_data = i_array_p[1]->i_data_p->i_user_data;
    v7 = i_user_data == qSymbol_topmost.mUID || i_user_data != qSymbol_local.mUID;
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v9 = UFG::qPropertySet::PropertyExists(
           (UFG::qPropertySet *)i_obj_p[2].vfptr,
           p_i_user_data,
           (UFG::qPropertyDepth)v7);
    *ppResult = SSBoolean::pool_new(v9 != 0i64);
  }
}

// File Line: 418
// RVA: 0x4F4C10
void __fastcall UFG::TSPropertySet::Mthd_append_property_boolean(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  PropertyUtils::Set<bool>(
    (UFG::qPropertySet *)i_obj_p[2].vfptr,
    (UFG::qArray<unsigned long,0> *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
}

// File Line: 429
// RVA: 0x4F4C50
void __fastcall UFG::TSPropertySet::Mthd_append_property_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  PropertyUtils::Set<long>(
    (UFG::qPropertySet *)i_obj_p[2].vfptr,
    (UFG::qArray<unsigned long,0> *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
}

// File Line: 440
// RVA: 0x4F4C90
void __fastcall UFG::TSPropertySet::Mthd_append_property_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  PropertyUtils::Set<float>(
    (UFG::qPropertySet *)i_obj_p[2].vfptr,
    (UFG::qArray<unsigned long,0> *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    *(float *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
}

// File Line: 451
// RVA: 0x4F4D40
void __fastcall UFG::TSPropertySet::Mthd_append_property_string(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r9
  SSObjectBase *i_obj_p; // rcx

  i_array_p = pScope->i_data.i_array_p;
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  PropertyUtils::Set<char const *>(
    (UFG::qPropertySet *)i_obj_p[2].vfptr,
    (UFG::qArray<unsigned long,0> *)&(*i_array_p)->i_data_p->i_user_data,
    *(char **)i_array_p[1]->i_data_p->i_user_data);
}

// File Line: 465
// RVA: 0x4F4D90
void __fastcall UFG::TSPropertySet::Mthd_append_property_symbol(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  PropertyUtils::Set<UFG::qSymbol>(
    (UFG::qPropertySet *)i_obj_p[2].vfptr,
    (UFG::qArray<unsigned long,0> *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    (UFG::qSymbol *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
}

// File Line: 476
// RVA: 0x4F4DD0
void __fastcall UFG::TSPropertySet::Mthd_append_property_vector3(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  PropertyUtils::Set<UFG::qVector3>(
    (UFG::qPropertySet *)i_obj_p[2].vfptr,
    (UFG::qArray<unsigned long,0> *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    *(UFG::qVector3 **)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
}

// File Line: 496
// RVA: 0x4F4CD0
void __fastcall UFG::TSPropertySet::Mthd_append_property_set(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdi
  UFG::qPropertySet *vfptr; // rdi
  unsigned __int64 *p_i_user_data; // rbx
  UFG::qPropertySet *ContainedSet; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
  p_i_user_data = &(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::qPropertySet::RemovePropertyByName(vfptr, (UFG::qArray<unsigned long,0> *)p_i_user_data);
  ContainedSet = UFG::qPropertySet::CreateContainedSet((UFG::qSymbol *)p_i_user_data, "Skookum.embedded.props");
  PropertyUtils::Set<UFG::qPropertySet>(vfptr, (UFG::qArray<unsigned long,0> *)p_i_user_data, ContainedSet);
}

// File Line: 514
// RVA: 0x4FDF90
void __fastcall UFG::TSPropertySet::Mthd_get_property_boolean(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  UFG::qPropertyDepth v3; // r9d
  SSData **i_array_p; // rdx
  UFG::qPropertySet *vfptr; // r10
  int i_user_data; // eax
  bool *v8; // rax
  bool *v9; // rcx
  char v10; // [rsp+38h] [rbp+10h] BYREF
  UFG::qSymbol name; // [rsp+40h] [rbp+18h] BYREF

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v3 = DEPTH_LOCAL;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_array_p = pScope->i_data.i_array_p;
    vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
    name.mUID = (*i_array_p)->i_data_p->i_user_data;
    i_user_data = i_array_p[1]->i_data_p->i_user_data;
    if ( i_user_data == qSymbol_topmost.mUID )
      v3 = DEPTH_RECURSE;
    else
      LOBYTE(v3) = i_user_data != qSymbol_local.mUID;
    v8 = UFG::qPropertySet::GetWithSchema<bool>(vfptr, &name, v3);
    v9 = (bool *)&v10;
    v10 = 0;
    if ( v8 )
      v9 = v8;
    *ppResult = SSBoolean::pool_new(*v9);
  }
}

// File Line: 553
// RVA: 0x4FE070
void __fastcall UFG::TSPropertySet::Mthd_get_property_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSData **i_array_p; // rdx
  UFG::qPropertySet *vfptr; // rsi
  int i_user_data; // eax
  BOOL v7; // ebx
  int *v8; // rdx
  int *v9; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF
  int v11; // [rsp+40h] [rbp+18h] BYREF

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_array_p = pScope->i_data.i_array_p;
    vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
    name.mUID = (*i_array_p)->i_data_p->i_user_data;
    i_user_data = i_array_p[1]->i_data_p->i_user_data;
    v7 = i_user_data == qSymbol_topmost.mUID || i_user_data != qSymbol_local.mUID;
    v8 = UFG::qPropertySet::GetWithSchema<long>(vfptr, &name, (UFG::qPropertyDepth)v7);
    if ( !v8 )
      v8 = (int *)UFG::qPropertySet::GetWithSchema<unsigned long>(vfptr, &name, (UFG::qPropertyDepth)v7);
    v9 = &v11;
    if ( v8 )
      v9 = v8;
    v11 = 0;
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, (unsigned int)*v9);
  }
}

// File Line: 599
// RVA: 0x4FE420
void __fastcall UFG::TSPropertySet::Mthd_get_property_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  UFG::qPropertyDepth v3; // r9d
  SSData **i_array_p; // rdx
  UFG::qPropertySet *vfptr; // r10
  int i_user_data; // eax
  float *v8; // rax
  unsigned __int64 *p_user_data; // rcx
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF
  unsigned __int64 user_data; // [rsp+40h] [rbp+18h] BYREF

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v3 = DEPTH_LOCAL;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_array_p = pScope->i_data.i_array_p;
    vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
    name.mUID = (*i_array_p)->i_data_p->i_user_data;
    i_user_data = i_array_p[1]->i_data_p->i_user_data;
    if ( i_user_data == qSymbol_topmost.mUID )
      v3 = DEPTH_RECURSE;
    else
      LOBYTE(v3) = i_user_data != qSymbol_local.mUID;
    v8 = UFG::qPropertySet::GetWithSchema<float>(vfptr, &name, v3);
    p_user_data = &user_data;
    if ( v8 )
      p_user_data = (unsigned __int64 *)v8;
    LODWORD(user_data) = 0;
    LODWORD(user_data) = *(_DWORD *)p_user_data;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, (unsigned int)user_data);
  }
}

// File Line: 638
// RVA: 0x4FE620
void __fastcall UFG::TSPropertySet::Mthd_get_property_string(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  UFG::qPropertyDepth v4; // r9d
  UFG::qPropertySet *vfptr; // r10
  SSData **i_array_p; // rdx
  int i_user_data; // eax
  char *v8; // rax
  const char *v9; // rdx
  AString *v10; // rax
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v16; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  UFG::qSymbol name; // [rsp+48h] [rbp+10h] BYREF
  AString v19; // [rsp+50h] [rbp+18h] BYREF

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v4 = DEPTH_LOCAL;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
    i_array_p = pScope->i_data.i_array_p;
    name.mUID = (*i_array_p)->i_data_p->i_user_data;
    i_user_data = i_array_p[1]->i_data_p->i_user_data;
    if ( i_user_data == qSymbol_topmost.mUID )
      v4 = DEPTH_RECURSE;
    else
      LOBYTE(v4) = i_user_data != qSymbol_local.mUID;
    v8 = UFG::qPropertySet::GetWithSchema<char const *>(vfptr, &name, v4);
    v9 = &customCaption;
    if ( v8 )
      v9 = v8;
    AString::AString(&v19, v9, 0);
    *ppResult = SSString::as_instance(v10);
    i_str_ref_p = v19.i_str_ref_p;
    if ( v19.i_str_ref_p->i_ref_count-- == 1 )
    {
      if ( i_str_ref_p->i_deallocate )
        AMemory::c_free_func(i_str_ref_p->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)i_str_ref_p < i_objects_a
        || (v16 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
            p_i_exp_pool = &pool->i_pool,
            !v16) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
    }
  }
}

// File Line: 675
// RVA: 0x4FE720
void __fastcall UFG::TSPropertySet::Mthd_get_property_symbol(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r9
  UFG::qPropertyDepth v3; // r8d
  SSData **i_array_p; // rdx
  UFG::qPropertySet *vfptr; // r10
  int i_user_data; // eax
  ASymbol *null; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v3 = DEPTH_LOCAL;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_array_p = pScope->i_data.i_array_p;
    vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
    name.mUID = (*i_array_p)->i_data_p->i_user_data;
    i_user_data = i_array_p[1]->i_data_p->i_user_data;
    if ( i_user_data == qSymbol_topmost.mUID )
      v3 = DEPTH_RECURSE;
    else
      LOBYTE(v3) = i_user_data != qSymbol_local.mUID;
    null = (ASymbol *)UFG::qPropertySet::GetWithSchema<UFG::qSymbol>(vfptr, &name, v3);
    if ( !null )
      null = ASymbol::get_null();
    *ppResult = SSSymbol::as_instance(null);
  }
}

// File Line: 712
// RVA: 0x4FE7B0
void __fastcall UFG::TSPropertySet::Mthd_get_property_vector3(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r9
  int i_user_data; // eax
  BOOL v6; // r8d
  SSObjectBase *i_obj_p; // rcx
  UFG::qVector3 *v8; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    name.mUID = (*i_array_p)->i_data_p->i_user_data;
    i_user_data = i_array_p[1]->i_data_p->i_user_data;
    v6 = i_user_data == qSymbol_topmost.mUID || i_user_data != qSymbol_local.mUID;
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v8 = UFG::qPropertySet::GetWithSchema<UFG::qVector3>(
           (UFG::qPropertySet *)i_obj_p[2].vfptr,
           &name,
           (UFG::qPropertyDepth)v6);
    *ppResult = UFG::TSVector3::AsInstance(v8);
  }
}

// File Line: 726
// RVA: 0x503380
void __fastcall UFG::TSPropertySet::Mthd_is_symbol_in_list_property(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rax
  SSObjectBase *i_obj_p; // rcx
  bool v6; // r15
  unsigned int v7; // ebx
  UFG::qPropertyList *v8; // rax
  UFG::qPropertyList *v9; // rsi
  SSData **v10; // rcx
  unsigned int mNumElements; // edi
  SSInstance *i_data_p; // rbp

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v6 = 0;
    v7 = 0;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v8 = UFG::qPropertySet::GetWithSchema<UFG::qPropertyList>(
           (UFG::qPropertySet *)i_obj_p[2].vfptr,
           (UFG::qSymbol *)&i_array_p[1]->i_data_p->i_user_data,
           DEPTH_RECURSE);
    v9 = v8;
    if ( v8 )
    {
      v10 = pScope->i_data.i_array_p;
      mNumElements = v8->mNumElements;
      i_data_p = (*v10)->i_data_p;
      if ( mNumElements )
      {
        while ( LODWORD(i_data_p->i_user_data) != UFG::qPropertyList::Get<UFG::qSymbol>(v9, v7)->mUID )
        {
          if ( ++v7 >= mNumElements )
            goto LABEL_11;
        }
        v6 = 1;
      }
    }
LABEL_11:
    *ppResult = SSBoolean::pool_new(v6);
  }
}

// File Line: 769
// RVA: 0x4FE1F0
void __fastcall UFG::TSPropertySet::Mthd_get_property_list_count(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int mNumElements; // ebx
  SSData **i_array_p; // rdx
  UFG::qPropertySet *vfptr; // r9
  int i_user_data; // eax
  BOOL v8; // r8d
  UFG::qPropertyList *v9; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    mNumElements = 0;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_array_p = pScope->i_data.i_array_p;
    vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
    name.mUID = (*i_array_p)->i_data_p->i_user_data;
    i_user_data = i_array_p[1]->i_data_p->i_user_data;
    v8 = i_user_data == qSymbol_topmost.mUID || i_user_data != qSymbol_local.mUID;
    v9 = UFG::qPropertySet::GetWithSchema<UFG::qPropertyList>(vfptr, &name, (UFG::qPropertyDepth)v8);
    if ( v9 )
      mNumElements = v9->mNumElements;
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, mNumElements);
  }
}

// File Line: 804
// RVA: 0x4FE290
void __fastcall UFG::TSPropertySet::Mthd_get_property_list_set(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  UFG::qPropertySet *v3; // rbx
  SSData **i_array_p; // rdx
  UFG::qPropertySet *vfptr; // r9
  int i_user_data; // eax
  BOOL v9; // r8d
  UFG::qPropertyList *v10; // rax
  char *ValuePtr; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v3 = 0i64;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_array_p = pScope->i_data.i_array_p;
    vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
    name.mUID = (*i_array_p)->i_data_p->i_user_data;
    i_user_data = i_array_p[2]->i_data_p->i_user_data;
    v9 = i_user_data == qSymbol_topmost.mUID || i_user_data != qSymbol_local.mUID;
    v10 = UFG::qPropertySet::GetWithSchema<UFG::qPropertyList>(vfptr, &name, (UFG::qPropertyDepth)v9);
    if ( v10 )
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(
                   v10,
                   0x1Au,
                   *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
      if ( ValuePtr )
      {
        if ( *(_QWORD *)ValuePtr )
          v3 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
      }
      UFG::qPropertySet::AddRef(v3);
      *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspPropertySetClass, (unsigned __int64)v3);
    }
  }
}

// File Line: 832
// RVA: 0x4FE370
void __fastcall UFG::TSPropertySet::Mthd_get_property_list_symbol(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r9
  UFG::qPropertyDepth v3; // r8d
  SSData **i_array_p; // rdx
  UFG::qPropertySet *vfptr; // r10
  int i_user_data; // eax
  UFG::qPropertyList *v9; // rax
  ASymbol *v10; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v3 = DEPTH_LOCAL;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_array_p = pScope->i_data.i_array_p;
    vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
    name.mUID = (*i_array_p)->i_data_p->i_user_data;
    i_user_data = i_array_p[2]->i_data_p->i_user_data;
    if ( i_user_data == qSymbol_topmost.mUID )
      v3 = DEPTH_RECURSE;
    else
      LOBYTE(v3) = i_user_data != qSymbol_local.mUID;
    v9 = UFG::qPropertySet::GetWithSchema<UFG::qPropertyList>(vfptr, &name, v3);
    if ( v9 )
    {
      v10 = (ASymbol *)UFG::qPropertyList::Get<UFG::qSymbol>(
                         v9,
                         *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
      *ppResult = SSSymbol::as_instance(v10);
    }
  }
}

// File Line: 851
// RVA: 0x4FE140
void __fastcall UFG::TSPropertySet::Mthd_get_property_list_boolean(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r9
  UFG::qPropertyDepth v3; // r8d
  SSData **i_array_p; // rdx
  UFG::qPropertySet *vfptr; // r10
  int i_user_data; // eax
  UFG::qPropertyList *v9; // rax
  bool *v10; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v3 = DEPTH_LOCAL;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_array_p = pScope->i_data.i_array_p;
    vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
    name.mUID = (*i_array_p)->i_data_p->i_user_data;
    i_user_data = i_array_p[2]->i_data_p->i_user_data;
    if ( i_user_data == qSymbol_topmost.mUID )
      v3 = DEPTH_RECURSE;
    else
      LOBYTE(v3) = i_user_data != qSymbol_local.mUID;
    v9 = UFG::qPropertySet::GetWithSchema<UFG::qPropertyList>(vfptr, &name, v3);
    if ( v9 )
    {
      v10 = UFG::qPropertyList::Get<bool>(
              v9,
              *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
      *ppResult = SSBoolean::pool_new(*v10);
    }
  }
}

// File Line: 873
// RVA: 0x4FE580
void __fastcall UFG::TSPropertySet::Mthd_get_property_set(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r9
  int i_user_data; // eax
  BOOL v6; // r8d
  SSObjectBase *i_obj_p; // rcx
  UFG::qPropertySet *v8; // rbx
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    name.mUID = (*i_array_p)->i_data_p->i_user_data;
    i_user_data = i_array_p[1]->i_data_p->i_user_data;
    v6 = i_user_data == qSymbol_topmost.mUID || i_user_data != qSymbol_local.mUID;
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v8 = UFG::qPropertySet::GetWithSchema<UFG::qPropertySet>(
           (UFG::qPropertySet *)i_obj_p[2].vfptr,
           &name,
           (UFG::qPropertyDepth)v6);
    UFG::qPropertySet::AddRef(v8);
    *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspPropertySetClass, (unsigned __int64)v8);
  }
}

// File Line: 891
// RVA: 0x509FE0
void __fastcall UFG::TSPropertySet::Mthd_set_property_boolean(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  SSData **i_array_p; // r8
  UFG::qPropertySet *vfptr; // rcx
  UFG::qArray<unsigned long,0> name; // [rsp+30h] [rbp+8h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = pScope->i_data.i_array_p;
  vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
  name.size = (*i_array_p)->i_data_p->i_user_data;
  UFG::qPropertySet::Set<bool>(vfptr, &name, i_array_p[1]->i_data_p->i_user_data != 0);
}

// File Line: 905
// RVA: 0x50A040
void __fastcall UFG::TSPropertySet::Mthd_set_property_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  SSData **i_array_p; // r8
  UFG::qPropertySet *vfptr; // rcx
  UFG::qArray<unsigned long,0> name; // [rsp+30h] [rbp+8h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = pScope->i_data.i_array_p;
  vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
  name.size = (*i_array_p)->i_data_p->i_user_data;
  UFG::qPropertySet::Set<long>(vfptr, &name, i_array_p[1]->i_data_p->i_user_data);
}

// File Line: 919
// RVA: 0x50A090
void __fastcall UFG::TSPropertySet::Mthd_set_property_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  SSData **i_array_p; // r8
  UFG::qPropertySet *vfptr; // rcx
  UFG::qArray<unsigned long,0> name; // [rsp+30h] [rbp+8h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = pScope->i_data.i_array_p;
  vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
  name.size = (*i_array_p)->i_data_p->i_user_data;
  UFG::qPropertySet::Set<float>(vfptr, &name, *(float *)&i_array_p[1]->i_data_p->i_user_data);
}

// File Line: 933
// RVA: 0x50A0E0
void __fastcall UFG::TSPropertySet::Mthd_set_property_string(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r9
  SSObjectBase *i_obj_p; // rcx
  SSInstance *i_data_p; // r8
  UFG::qPropertySet *vfptr; // rcx
  UFG::qArray<unsigned long,0> name; // [rsp+30h] [rbp+8h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  i_obj_p = pScope->i_scope_p.i_obj_p;
  i_data_p = i_array_p[1]->i_data_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
  name.size = (*i_array_p)->i_data_p->i_user_data;
  UFG::qPropertySet::Set<char const *>(vfptr, &name, *(char **)i_data_p->i_user_data);
}

// File Line: 949
// RVA: 0x50A130
void __fastcall UFG::TSPropertySet::Mthd_set_property_symbol(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  SSData **i_array_p; // r8
  UFG::qPropertySet *vfptr; // rcx
  UFG::qSymbol v; // [rsp+30h] [rbp+8h] BYREF
  UFG::qArray<unsigned long,0> name; // [rsp+40h] [rbp+18h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = pScope->i_data.i_array_p;
  vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
  name.size = (*i_array_p)->i_data_p->i_user_data;
  v.mUID = i_array_p[1]->i_data_p->i_user_data;
  UFG::qPropertySet::Set<UFG::qSymbol>(vfptr, &name, &v);
}

// File Line: 964
// RVA: 0x50A190
void __fastcall UFG::TSPropertySet::Mthd_set_property_vector3(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  SSData **i_array_p; // r8
  UFG::qPropertySet *vfptr; // rcx
  UFG::qArray<unsigned long,0> name; // [rsp+30h] [rbp+8h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = pScope->i_data.i_array_p;
  vfptr = (UFG::qPropertySet *)i_obj_p[2].vfptr;
  name.size = (*i_array_p)->i_data_p->i_user_data;
  UFG::qPropertySet::Set<UFG::qVector3>(vfptr, &name, (UFG::qVector3 *)i_array_p[1]->i_data_p->i_user_data);
}


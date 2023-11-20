// File Line: 155
// RVA: 0x4D53E0
void UFG::TSPropertySet::BindAtomics(void)
{
  UFG::SkookumMgr::mspPropertySetClass = SSBrain::get_class("PropertySet");
  SSClass::register_method_func(UFG::SkookumMgr::mspPropertySetClass, &ASymbolX_ctor, UFG::TSPropertySet::Mthd_ctor, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspPropertySetClass, "!new", UFG::TSPropertySet::Mthd_ctor_new, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspPropertySetClass, &ASymbolX_dtor, UFG::TSPropertySet::Mthd_dtor, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspPropertySetClass, "get_name", UFG::TSMarker::Mthd_get_name, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_parent_count",
    UFG::TSPropertySet::Mthd_get_parent_count,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "is_child_of",
    UFG::TSPropertySet::Mthd_is_child_of,
    0);
  SSClass::register_method_func(UFG::SkookumMgr::mspPropertySetClass, "is_type", UFG::TSPropertySet::Mthd_is_type, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "remove_parent",
    UFG::TSPropertySet::Mthd_remove_parent,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "remove_parents",
    UFG::TSPropertySet::Mthd_remove_parents,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_count_local",
    UFG::TSPropertySet::Mthd_get_property_count_local,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_scope",
    UFG::TSPropertySet::Mthd_get_property_scope,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "is_property_present",
    UFG::TSPropertySet::Mthd_is_property_present,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "append_property_boolean",
    UFG::TSPropertySet::Mthd_append_property_boolean,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "append_property_integer",
    UFG::TSPropertySet::Mthd_append_property_integer,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "append_property_real",
    UFG::TSPropertySet::Mthd_append_property_real,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "append_property_string",
    UFG::TSPropertySet::Mthd_append_property_string,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "append_property_symbol",
    UFG::TSPropertySet::Mthd_append_property_symbol,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "append_property_vector3",
    UFG::TSPropertySet::Mthd_append_property_vector3,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "append_property_set",
    UFG::TSPropertySet::Mthd_append_property_set,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_boolean",
    UFG::TSPropertySet::Mthd_get_property_boolean,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_integer",
    UFG::TSPropertySet::Mthd_get_property_integer,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_real",
    UFG::TSPropertySet::Mthd_get_property_real,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_string",
    UFG::TSPropertySet::Mthd_get_property_string,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_symbol",
    UFG::TSPropertySet::Mthd_get_property_symbol,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_vector3",
    UFG::TSPropertySet::Mthd_get_property_vector3,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_set",
    UFG::TSPropertySet::Mthd_get_property_set,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_list_count",
    UFG::TSPropertySet::Mthd_get_property_list_count,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_list_set",
    UFG::TSPropertySet::Mthd_get_property_list_set,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_list_symbol",
    UFG::TSPropertySet::Mthd_get_property_list_symbol,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "get_property_list_boolean",
    UFG::TSPropertySet::Mthd_get_property_list_boolean,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "is_symbol_in_list_property",
    UFG::TSPropertySet::Mthd_is_symbol_in_list_property,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "set_property_boolean",
    UFG::TSPropertySet::Mthd_set_property_boolean,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "set_property_integer",
    UFG::TSPropertySet::Mthd_set_property_integer,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "set_property_real",
    UFG::TSPropertySet::Mthd_set_property_real,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "set_property_string",
    UFG::TSPropertySet::Mthd_set_property_string,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "set_property_symbol",
    UFG::TSPropertySet::Mthd_set_property_symbol,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspPropertySetClass,
    "set_property_vector3",
    UFG::TSPropertySet::Mthd_set_property_vector3,
    0);
}

// File Line: 212
// RVA: 0x4F8880
void __fastcall UFG::TSPropertySet::Mthd_dtor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  UFG::qPropertySet::ReleaseRef((UFG::qPropertySet *)v3[2].vfptr);
}

// File Line: 222
// RVA: 0x4F72B0
void __fastcall UFG::TSPropertySet::Mthd_ctor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  UFG::qPropertySet *v3; // rax
  UFG::qPropertySet *v4; // rbx
  SSObjectBase *v5; // rdx

  v2 = pScope;
  v3 = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v4 = v3;
  if ( v3 )
  {
    UFG::qPropertySet::AddRef(v3);
    v5 = v2->i_scope_p.i_obj_p;
    if ( !v5 || v2->i_scope_p.i_ptr_id != v5->i_ptr_id )
      v5 = 0i64;
    v5[2].vfptr = (SSObjectBaseVtbl *)v4;
  }
}

// File Line: 239
// RVA: 0x4F7530
void __fastcall UFG::TSPropertySet::Mthd_ctor_new(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  UFG::qPropertySet *v3; // rax
  UFG::qPropertySet *v4; // rbx
  SSObjectBase *v5; // rdx

  v2 = pScope;
  v3 = UFG::PropertySetManager::CreateContainedPropertySet((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v4 = v3;
  if ( v3 )
  {
    UFG::qPropertySet::AddRef(v3);
    v5 = v2->i_scope_p.i_obj_p;
    if ( !v5 || v2->i_scope_p.i_ptr_id != v5->i_ptr_id )
      v5 = 0i64;
    v5[2].vfptr = (SSObjectBaseVtbl *)v4;
  }
}

// File Line: 272
// RVA: 0x4FDCA0
void __fastcall UFG::TSPropertySet::Mthd_get_parent_count(SSInvokedMethod *pScope, SSInstance **ppResult)
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
    v5 = UFG::qPropertySet::NumParents((UFG::qPropertySet *)v3[2].vfptr);
    *v4 = SSInstance::pool_new(SSBrain::c_integer_class_p, v5);
  }
}

// File Line: 288
// RVA: 0x501020
void __fastcall UFG::TSPropertySet::Mthd_is_child_of(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rax
  SSInstance **v3; // rbx
  SSInvokedMethod *v4; // r9
  SSObjectBase *v5; // rcx
  UFG::qPropertySet *v6; // rax

  if ( ppResult )
  {
    v2 = pScope->i_data.i_array_p;
    v3 = ppResult;
    v4 = pScope;
    v5 = pScope->i_scope_p.i_obj_p;
    if ( !v5 || v4->i_scope_p.i_ptr_id != v5->i_ptr_id )
      v5 = 0i64;
    v6 = UFG::qPropertySet::GetParentFromName(
           (UFG::qPropertySet *)v5[2].vfptr,
           (UFG::qSymbol *)&(*v2)->i_data_p->i_user_data,
           DEPTH_RECURSE);
    *v3 = (SSInstance *)SSBoolean::pool_new(v6 != 0i64);
  }
}

// File Line: 303
// RVA: 0x503AA0
void __fastcall UFG::TSPropertySet::Mthd_is_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  UFG::qPropertySet *v4; // r9
  SSInstance *v5; // rdx
  int v6; // eax
  UFG::qSymbol *v7; // rdx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = (UFG::qPropertySet *)v2[2].vfptr;
    v5 = (*pScope->i_data.i_array_p)->i_data_p;
    v6 = v5->i_user_data;
    v7 = (UFG::qSymbol *)&v5->i_user_data;
    if ( v4->mName.mUID == v6 || UFG::qPropertySet::GetParentFromName(v4, v7, DEPTH_RECURSE) )
      *v3 = (SSInstance *)SSBoolean::pool_new(1);
    else
      *v3 = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 322
// RVA: 0x5066F0
void __fastcall UFG::TSPropertySet::Mthd_remove_parent(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  UFG::qPropertySet::RemovePropertyByName(
    (UFG::qPropertySet *)v3[2].vfptr,
    (UFG::qSymbol *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 334
// RVA: 0x506720
void __fastcall UFG::TSPropertySet::Mthd_remove_parents(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  UFG::qPropertySet::RemoveParentsAll((UFG::qPropertySet *)v3[2].vfptr);
}

// File Line: 356
// RVA: 0x4FE030
void __fastcall UFG::TSPropertySet::Mthd_get_property_count_local(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, HIWORD(v2[2].vfptr[1].is_actor));
  }
}

// File Line: 370
// RVA: 0x4FE4D0
void __fastcall UFG::TSPropertySet::Mthd_get_property_scope(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSInvokedMethod *v3; // rdx
  SSData **v4; // r8
  UFG::qSymbol *v5; // r9
  int v6; // eax
  BOOL v7; // er8
  SSObjectBase *v8; // rcx
  UFG::qPropertySet *v9; // rax
  unsigned __int64 v10; // rdi

  v2 = ppResult;
  v3 = pScope;
  if ( v2 )
  {
    v4 = pScope->i_data.i_array_p;
    v5 = (UFG::qSymbol *)(*v4)->i_data_p;
    v6 = v4[1]->i_data_p->i_user_data;
    if ( v6 == qSymbol_topmost.mUID )
      v7 = 1;
    else
      v7 = v6 != qSymbol_local.mUID;
    v8 = pScope->i_scope_p.i_obj_p;
    if ( !v8 || v3->i_scope_p.i_ptr_id != v8->i_ptr_id )
      v8 = 0i64;
    v9 = UFG::qPropertySet::PropertyExists((UFG::qPropertySet *)v8[2].vfptr, v5 + 8, (UFG::qPropertyDepth)v7);
    v10 = (unsigned __int64)v9;
    if ( v9 )
    {
      UFG::qPropertySet::AddRef(v9);
      *v2 = SSInstance::pool_new(UFG::SkookumMgr::mspPropertySetClass, v10);
    }
    else
    {
      *v2 = SSBrain::c_nil_p;
    }
  }
}

// File Line: 398
// RVA: 0x503060
void __fastcall UFG::TSPropertySet::Mthd_is_property_present(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSInstance **v3; // rbx
  SSInvokedMethod *v4; // r9
  UFG::qSymbol *v5; // rdx
  int v6; // eax
  BOOL v7; // er8
  SSObjectBase *v8; // rcx
  UFG::qPropertySet *v9; // rax

  if ( ppResult )
  {
    v2 = pScope->i_data.i_array_p;
    v3 = ppResult;
    v4 = pScope;
    v5 = (UFG::qSymbol *)&(*v2)->i_data_p->i_user_data;
    v6 = v2[1]->i_data_p->i_user_data;
    if ( v6 == qSymbol_topmost.mUID )
      v7 = 1;
    else
      v7 = v6 != qSymbol_local.mUID;
    v8 = pScope->i_scope_p.i_obj_p;
    if ( !v8 || v4->i_scope_p.i_ptr_id != v8->i_ptr_id )
      v8 = 0i64;
    v9 = UFG::qPropertySet::PropertyExists((UFG::qPropertySet *)v8[2].vfptr, v5, (UFG::qPropertyDepth)v7);
    *v3 = (SSInstance *)SSBoolean::pool_new(v9 != 0i64);
  }
}

// File Line: 418
// RVA: 0x4F4C10
void __fastcall UFG::TSPropertySet::Mthd_append_property_boolean(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r9
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  PropertyUtils::Set<bool>(
    (UFG::qPropertySet *)v3[2].vfptr,
    (UFG::qSymbol *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data,
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
}

// File Line: 429
// RVA: 0x4F4C50
void __fastcall UFG::TSPropertySet::Mthd_append_property_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  PropertyUtils::Set<long>(
    (UFG::qPropertySet *)v3[2].vfptr,
    (UFG::qSymbol *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data,
    *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64));
}

// File Line: 440
// RVA: 0x4F4C90
void __fastcall UFG::TSPropertySet::Mthd_append_property_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  PropertyUtils::Set<float>(
    (UFG::qPropertySet *)v3[2].vfptr,
    (UFG::qSymbol *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data,
    *(float *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64));
}

// File Line: 451
// RVA: 0x4F4D40
void __fastcall UFG::TSPropertySet::Mthd_append_property_string(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r9
  SSInvokedMethod *v3; // r8
  SSObjectBase *v4; // rcx

  v2 = pScope->i_data.i_array_p;
  v3 = pScope;
  v4 = pScope->i_scope_p.i_obj_p;
  if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
    v4 = 0i64;
  PropertyUtils::Set<char const *>(
    (UFG::qPropertySet *)v4[2].vfptr,
    (UFG::qSymbol *)&(*v2)->i_data_p->i_user_data,
    *(const char **)v2[1]->i_data_p->i_user_data);
}

// File Line: 465
// RVA: 0x4F4D90
void __fastcall UFG::TSPropertySet::Mthd_append_property_symbol(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  PropertyUtils::Set<UFG::qSymbol>(
    (UFG::qPropertySet *)v3[2].vfptr,
    (UFG::qSymbol *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data,
    (UFG::qSymbol *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64));
}

// File Line: 476
// RVA: 0x4F4DD0
void __fastcall UFG::TSPropertySet::Mthd_append_property_vector3(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  PropertyUtils::Set<UFG::qVector3>(
    (UFG::qPropertySet *)v3[2].vfptr,
    (UFG::qSymbol *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data,
    *(UFG::qVector3 **)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64));
}

// File Line: 496
// RVA: 0x4F4CD0
void __fastcall UFG::TSPropertySet::Mthd_append_property_set(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdi
  UFG::qPropertySet *v3; // rdi
  UFG::qSymbol *v4; // rbx
  UFG::qPropertySet *v5; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (UFG::qPropertySet *)v2[2].vfptr;
  v4 = (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::qPropertySet::RemovePropertyByName(v3, v4);
  v5 = UFG::qPropertySet::CreateContainedSet(v4, "Skookum.embedded.props");
  PropertyUtils::Set<UFG::qPropertySet>(v3, v4, v5);
}

// File Line: 514
// RVA: 0x4FDF90
void __fastcall UFG::TSPropertySet::Mthd_get_property_boolean(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  UFG::qPropertyDepth v3; // er9
  SSInstance **v4; // rbx
  SSData **v5; // rdx
  UFG::qPropertySet *v6; // r10
  int v7; // eax
  bool *v8; // rax
  bool *v9; // rcx
  char v10; // [rsp+38h] [rbp+10h]
  UFG::qSymbol name; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = 0;
    v4 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v5 = pScope->i_data.i_array_p;
    v6 = (UFG::qPropertySet *)v2[2].vfptr;
    name.mUID = (*v5)->i_data_p->i_user_data;
    v7 = v5[1]->i_data_p->i_user_data;
    if ( v7 == qSymbol_topmost.mUID )
      v3 = 1;
    else
      LOBYTE(v3) = v7 != qSymbol_local.mUID;
    v8 = UFG::qPropertySet::GetWithSchema<bool>(v6, &name, v3);
    v9 = (bool *)&v10;
    v10 = 0;
    if ( v8 )
      v9 = v8;
    *v4 = (SSInstance *)SSBoolean::pool_new(*v9);
  }
}

// File Line: 553
// RVA: 0x4FE070
void __fastcall UFG::TSPropertySet::Mthd_get_property_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rdi
  SSData **v4; // rdx
  UFG::qPropertySet *v5; // rsi
  int v6; // eax
  BOOL v7; // ebx
  int *v8; // rdx
  int *v9; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]
  int v11; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = pScope->i_data.i_array_p;
    v5 = (UFG::qPropertySet *)v2[2].vfptr;
    name.mUID = (*v4)->i_data_p->i_user_data;
    v6 = v4[1]->i_data_p->i_user_data;
    if ( v6 == qSymbol_topmost.mUID )
      v7 = 1;
    else
      v7 = v6 != qSymbol_local.mUID;
    v8 = UFG::qPropertySet::GetWithSchema<long>(v5, &name, (UFG::qPropertyDepth)v7);
    if ( !v8 )
      v8 = (int *)UFG::qPropertySet::GetWithSchema<unsigned long>(v5, &name, (UFG::qPropertyDepth)v7);
    v9 = &v11;
    if ( v8 )
      v9 = v8;
    v11 = 0;
    *v3 = SSInstance::pool_new(SSBrain::c_integer_class_p, (unsigned int)*v9);
  }
}

// File Line: 599
// RVA: 0x4FE420
void __fastcall UFG::TSPropertySet::Mthd_get_property_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  UFG::qPropertyDepth v3; // er9
  SSInstance **v4; // rbx
  SSData **v5; // rdx
  UFG::qPropertySet *v6; // r10
  int v7; // eax
  float *v8; // rax
  unsigned __int64 *v9; // rcx
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]
  unsigned __int64 user_data; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = 0;
    v4 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v5 = pScope->i_data.i_array_p;
    v6 = (UFG::qPropertySet *)v2[2].vfptr;
    name.mUID = (*v5)->i_data_p->i_user_data;
    v7 = v5[1]->i_data_p->i_user_data;
    if ( v7 == qSymbol_topmost.mUID )
      v3 = 1;
    else
      LOBYTE(v3) = v7 != qSymbol_local.mUID;
    v8 = UFG::qPropertySet::GetWithSchema<float>(v6, &name, v3);
    v9 = &user_data;
    if ( v8 )
      v9 = (unsigned __int64 *)v8;
    LODWORD(user_data) = 0;
    LODWORD(user_data) = *(_DWORD *)v9;
    *v4 = SSInstance::pool_new(SSBrain::c_real_class_p, (unsigned int)user_data);
  }
}

// File Line: 638
// RVA: 0x4FE620
void __fastcall UFG::TSPropertySet::Mthd_get_property_string(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // r8
  UFG::qPropertyDepth v4; // er9
  UFG::qPropertySet *v5; // r10
  SSData **v6; // rdx
  int v7; // eax
  char *v8; // rax
  const char *v9; // rdx
  AString *v10; // rax
  AStringRef *v11; // rbx
  bool v12; // zf
  AObjReusePool<AStringRef> *v13; // rax
  AObjBlock<AStringRef> *v14; // rcx
  unsigned __int64 v15; // rdx
  bool v16; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v17; // rcx
  UFG::qSymbol name; // [rsp+48h] [rbp+10h]
  AString v19; // [rsp+50h] [rbp+18h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope->i_scope_p.i_obj_p;
    v4 = 0;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v5 = (UFG::qPropertySet *)v3[2].vfptr;
    v6 = pScope->i_data.i_array_p;
    name.mUID = (*v6)->i_data_p->i_user_data;
    v7 = v6[1]->i_data_p->i_user_data;
    if ( v7 == qSymbol_topmost.mUID )
      v4 = 1;
    else
      LOBYTE(v4) = v7 != qSymbol_local.mUID;
    v8 = UFG::qPropertySet::GetWithSchema<char const *>(v5, &name, v4);
    v9 = &customWorldMapCaption;
    if ( v8 )
      v9 = v8;
    AString::AString(&v19, v9, 0);
    *v2 = SSString::as_instance(v10);
    v11 = v19.i_str_ref_p;
    v12 = v19.i_str_ref_p->i_ref_count == 1;
    --v11->i_ref_count;
    if ( v12 )
    {
      if ( v11->i_deallocate )
        AMemory::c_free_func(v11->i_cstr_p);
      v13 = AStringRef::get_pool();
      v14 = v13->i_block_p;
      v15 = (unsigned __int64)v14->i_objects_a;
      if ( (unsigned __int64)v11 < v15
        || (v16 = (unsigned __int64)v11 < v15 + 24i64 * v14->i_size, v17 = &v13->i_pool, !v16) )
      {
        v17 = &v13->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v17, v11);
    }
  }
}

// File Line: 675
// RVA: 0x4FE720
void __fastcall UFG::TSPropertySet::Mthd_get_property_symbol(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r9
  UFG::qPropertyDepth v3; // er8
  SSInstance **v4; // rbx
  SSData **v5; // rdx
  UFG::qPropertySet *v6; // r10
  int v7; // eax
  ASymbol *v8; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = 0;
    v4 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v5 = pScope->i_data.i_array_p;
    v6 = (UFG::qPropertySet *)v2[2].vfptr;
    name.mUID = (*v5)->i_data_p->i_user_data;
    v7 = v5[1]->i_data_p->i_user_data;
    if ( v7 == qSymbol_topmost.mUID )
      v3 = 1;
    else
      LOBYTE(v3) = v7 != qSymbol_local.mUID;
    v8 = (ASymbol *)UFG::qPropertySet::GetWithSchema<UFG::qSymbol>(v6, &name, v3);
    if ( !v8 )
      v8 = ASymbol::get_null();
    *v4 = SSSymbol::as_instance(v8);
  }
}

// File Line: 712
// RVA: 0x4FE7B0
void __fastcall UFG::TSPropertySet::Mthd_get_property_vector3(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r9
  SSInstance **v3; // rbx
  SSInvokedMethod *v4; // r10
  int v5; // eax
  BOOL v6; // er8
  SSObjectBase *v7; // rcx
  UFG::qVector3 *v8; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = pScope->i_data.i_array_p;
    v3 = ppResult;
    v4 = pScope;
    name.mUID = (*v2)->i_data_p->i_user_data;
    v5 = v2[1]->i_data_p->i_user_data;
    if ( v5 == qSymbol_topmost.mUID )
      v6 = 1;
    else
      v6 = v5 != qSymbol_local.mUID;
    v7 = pScope->i_scope_p.i_obj_p;
    if ( !v7 || v4->i_scope_p.i_ptr_id != v7->i_ptr_id )
      v7 = 0i64;
    v8 = UFG::qPropertySet::GetWithSchema<UFG::qVector3>(
           (UFG::qPropertySet *)v7[2].vfptr,
           &name,
           (UFG::qPropertyDepth)v6);
    *v3 = UFG::TSVector3::AsInstance(v8);
  }
}

// File Line: 726
// RVA: 0x503380
void __fastcall UFG::TSPropertySet::Mthd_is_symbol_in_list_property(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rax
  SSInstance **v3; // r14
  SSInvokedMethod *v4; // rdi
  SSObjectBase *v5; // rcx
  bool v6; // r15
  unsigned int v7; // ebx
  UFG::qPropertyList *v8; // rax
  UFG::qPropertyList *v9; // rsi
  SSData **v10; // rcx
  unsigned int v11; // edi
  SSInstance *v12; // rbp

  if ( ppResult )
  {
    v2 = pScope->i_data.i_array_p;
    v3 = ppResult;
    v4 = pScope;
    v5 = pScope->i_scope_p.i_obj_p;
    v6 = 0;
    v7 = 0;
    if ( !v5 || v4->i_scope_p.i_ptr_id != v5->i_ptr_id )
      v5 = 0i64;
    v8 = UFG::qPropertySet::GetWithSchema<UFG::qPropertyList>(
           (UFG::qPropertySet *)v5[2].vfptr,
           (UFG::qSymbol *)&v2[1]->i_data_p->i_user_data,
           DEPTH_RECURSE);
    v9 = v8;
    if ( v8 )
    {
      v10 = v4->i_data.i_array_p;
      v11 = v8->mNumElements;
      v12 = (*v10)->i_data_p;
      if ( v11 )
      {
        while ( LODWORD(v12->i_user_data) != UFG::qPropertyList::Get<UFG::qSymbol>(v9, v7)->mUID )
        {
          if ( ++v7 >= v11 )
            goto LABEL_11;
        }
        v6 = 1;
      }
    }
LABEL_11:
    *v3 = (SSInstance *)SSBoolean::pool_new(v6);
  }
}

// File Line: 769
// RVA: 0x4FE1F0
void __fastcall UFG::TSPropertySet::Mthd_get_property_list_count(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  unsigned int v3; // ebx
  SSInstance **v4; // rdi
  SSData **v5; // rdx
  UFG::qPropertySet *v6; // r9
  int v7; // eax
  BOOL v8; // er8
  UFG::qPropertyList *v9; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = 0;
    v4 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v5 = pScope->i_data.i_array_p;
    v6 = (UFG::qPropertySet *)v2[2].vfptr;
    name.mUID = (*v5)->i_data_p->i_user_data;
    v7 = v5[1]->i_data_p->i_user_data;
    if ( v7 == qSymbol_topmost.mUID )
      v8 = 1;
    else
      v8 = v7 != qSymbol_local.mUID;
    v9 = UFG::qPropertySet::GetWithSchema<UFG::qPropertyList>(v6, &name, (UFG::qPropertyDepth)v8);
    if ( v9 )
      v3 = v9->mNumElements;
    *v4 = SSInstance::pool_new(SSBrain::c_integer_class_p, v3);
  }
}

// File Line: 804
// RVA: 0x4FE290
void __fastcall UFG::TSPropertySet::Mthd_get_property_list_set(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  UFG::qPropertySet *v3; // rbx
  SSInstance **v4; // rsi
  SSInvokedMethod *v5; // rdi
  SSData **v6; // rdx
  UFG::qPropertySet *v7; // r9
  int v8; // eax
  BOOL v9; // er8
  UFG::qPropertyList *v10; // rax
  char *v11; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = 0i64;
    v4 = ppResult;
    v5 = pScope;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v6 = pScope->i_data.i_array_p;
    v7 = (UFG::qPropertySet *)v2[2].vfptr;
    name.mUID = (*v6)->i_data_p->i_user_data;
    v8 = v6[2]->i_data_p->i_user_data;
    if ( v8 == qSymbol_topmost.mUID )
      v9 = 1;
    else
      v9 = v8 != qSymbol_local.mUID;
    v10 = UFG::qPropertySet::GetWithSchema<UFG::qPropertyList>(v7, &name, (UFG::qPropertyDepth)v9);
    if ( v10 )
    {
      v11 = UFG::qPropertyList::GetValuePtr(
              v10,
              0x1Au,
              *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v5->i_data.i_array_p + 1) + 8i64) + 32i64));
      if ( v11 )
      {
        if ( *(_QWORD *)v11 )
          v3 = (UFG::qPropertySet *)&v11[*(_QWORD *)v11];
      }
      UFG::qPropertySet::AddRef(v3);
      *v4 = SSInstance::pool_new(UFG::SkookumMgr::mspPropertySetClass, (unsigned __int64)v3);
    }
  }
}

// File Line: 832
// RVA: 0x4FE370
void __fastcall UFG::TSPropertySet::Mthd_get_property_list_symbol(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r9
  UFG::qPropertyDepth v3; // er8
  SSInstance **v4; // rdi
  SSInvokedMethod *v5; // rbx
  SSData **v6; // rdx
  UFG::qPropertySet *v7; // r10
  int v8; // eax
  UFG::qPropertyList *v9; // rax
  ASymbol *v10; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = 0;
    v4 = ppResult;
    v5 = pScope;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v6 = pScope->i_data.i_array_p;
    v7 = (UFG::qPropertySet *)v2[2].vfptr;
    name.mUID = (*v6)->i_data_p->i_user_data;
    v8 = v6[2]->i_data_p->i_user_data;
    if ( v8 == qSymbol_topmost.mUID )
      v3 = 1;
    else
      LOBYTE(v3) = v8 != qSymbol_local.mUID;
    v9 = UFG::qPropertySet::GetWithSchema<UFG::qPropertyList>(v7, &name, v3);
    if ( v9 )
    {
      v10 = (ASymbol *)UFG::qPropertyList::Get<UFG::qSymbol>(
                         v9,
                         *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v5->i_data.i_array_p + 1) + 8i64) + 32i64));
      *v4 = SSSymbol::as_instance(v10);
    }
  }
}

// File Line: 851
// RVA: 0x4FE140
void __fastcall UFG::TSPropertySet::Mthd_get_property_list_boolean(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r9
  UFG::qPropertyDepth v3; // er8
  SSInstance **v4; // rdi
  SSInvokedMethod *v5; // rbx
  SSData **v6; // rdx
  UFG::qPropertySet *v7; // r10
  int v8; // eax
  UFG::qPropertyList *v9; // rax
  bool *v10; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = 0;
    v4 = ppResult;
    v5 = pScope;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v6 = pScope->i_data.i_array_p;
    v7 = (UFG::qPropertySet *)v2[2].vfptr;
    name.mUID = (*v6)->i_data_p->i_user_data;
    v8 = v6[2]->i_data_p->i_user_data;
    if ( v8 == qSymbol_topmost.mUID )
      v3 = 1;
    else
      LOBYTE(v3) = v8 != qSymbol_local.mUID;
    v9 = UFG::qPropertySet::GetWithSchema<UFG::qPropertyList>(v7, &name, v3);
    if ( v9 )
    {
      v10 = UFG::qPropertyList::Get<bool>(
              v9,
              *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v5->i_data.i_array_p + 1) + 8i64) + 32i64));
      *v4 = (SSInstance *)SSBoolean::pool_new(*v10);
    }
  }
}

// File Line: 873
// RVA: 0x4FE580
void __fastcall UFG::TSPropertySet::Mthd_get_property_set(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r9
  SSInstance **v3; // rdi
  SSInvokedMethod *v4; // r10
  int v5; // eax
  BOOL v6; // er8
  SSObjectBase *v7; // rcx
  UFG::qPropertySet *v8; // rbx
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = pScope->i_data.i_array_p;
    v3 = ppResult;
    v4 = pScope;
    name.mUID = (*v2)->i_data_p->i_user_data;
    v5 = v2[1]->i_data_p->i_user_data;
    if ( v5 == qSymbol_topmost.mUID )
      v6 = 1;
    else
      v6 = v5 != qSymbol_local.mUID;
    v7 = pScope->i_scope_p.i_obj_p;
    if ( !v7 || v4->i_scope_p.i_ptr_id != v7->i_ptr_id )
      v7 = 0i64;
    v8 = UFG::qPropertySet::GetWithSchema<UFG::qPropertySet>(
           (UFG::qPropertySet *)v7[2].vfptr,
           &name,
           (UFG::qPropertyDepth)v6);
    UFG::qPropertySet::AddRef(v8);
    *v3 = SSInstance::pool_new(UFG::SkookumMgr::mspPropertySetClass, (unsigned __int64)v8);
  }
}

// File Line: 891
// RVA: 0x509FE0
void __fastcall UFG::TSPropertySet::Mthd_set_property_boolean(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx
  SSData **v4; // r8
  UFG::qPropertySet *v5; // rcx
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = v2->i_data.i_array_p;
  v5 = (UFG::qPropertySet *)v3[2].vfptr;
  name.mUID = (*v4)->i_data_p->i_user_data;
  UFG::qPropertySet::Set<bool>(v5, &name, v4[1]->i_data_p->i_user_data != 0);
}

// File Line: 905
// RVA: 0x50A040
void __fastcall UFG::TSPropertySet::Mthd_set_property_integer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx
  SSData **v4; // r8
  UFG::qPropertySet *v5; // rcx
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = v2->i_data.i_array_p;
  v5 = (UFG::qPropertySet *)v3[2].vfptr;
  name.mUID = (*v4)->i_data_p->i_user_data;
  UFG::qPropertySet::Set<long>(v5, &name, v4[1]->i_data_p->i_user_data);
}

// File Line: 919
// RVA: 0x50A090
void __fastcall UFG::TSPropertySet::Mthd_set_property_real(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx
  SSData **v4; // r8
  UFG::qPropertySet *v5; // rcx
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = v2->i_data.i_array_p;
  v5 = (UFG::qPropertySet *)v3[2].vfptr;
  name.mUID = (*v4)->i_data_p->i_user_data;
  UFG::qPropertySet::Set<float>(v5, &name, *(float *)&v4[1]->i_data_p->i_user_data);
}

// File Line: 933
// RVA: 0x50A0E0
void __fastcall UFG::TSPropertySet::Mthd_set_property_string(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r9
  SSInvokedMethod *v3; // rdx
  SSObjectBase *v4; // rcx
  SSInstance *v5; // r8
  UFG::qPropertySet *v6; // rcx
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]

  v2 = pScope->i_data.i_array_p;
  v3 = pScope;
  v4 = pScope->i_scope_p.i_obj_p;
  v5 = v2[1]->i_data_p;
  if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
    v4 = 0i64;
  v6 = (UFG::qPropertySet *)v4[2].vfptr;
  name.mUID = (*v2)->i_data_p->i_user_data;
  UFG::qPropertySet::Set<char const *>(v6, &name, *(const char **)v5->i_user_data);
}

// File Line: 949
// RVA: 0x50A130
void __fastcall UFG::TSPropertySet::Mthd_set_property_symbol(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx
  SSData **v4; // r8
  UFG::qPropertySet *v5; // rcx
  UFG::qSymbol v; // [rsp+30h] [rbp+8h]
  UFG::qSymbol name; // [rsp+40h] [rbp+18h]

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = v2->i_data.i_array_p;
  v5 = (UFG::qPropertySet *)v3[2].vfptr;
  name.mUID = (*v4)->i_data_p->i_user_data;
  v.mUID = v4[1]->i_data_p->i_user_data;
  UFG::qPropertySet::Set<UFG::qSymbol>(v5, &name, &v);
}

// File Line: 964
// RVA: 0x50A190
void __fastcall UFG::TSPropertySet::Mthd_set_property_vector3(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx
  SSData **v4; // r8
  UFG::qPropertySet *v5; // rcx
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = v2->i_data.i_array_p;
  v5 = (UFG::qPropertySet *)v3[2].vfptr;
  name.mUID = (*v4)->i_data_p->i_user_data;
  UFG::qPropertySet::Set<UFG::qVector3>(v5, &name, (UFG::qVector3 *)v4[1]->i_data_p->i_user_data);
}


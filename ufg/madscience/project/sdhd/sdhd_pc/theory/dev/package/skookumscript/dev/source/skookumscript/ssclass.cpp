// File Line: 128
// RVA: 0x10EDB0
SSMetaClass *__fastcall SSMetaClass::as_finalized_generic(SSMetaClass *this, SSClassDescBase *scope_type)
{
  SSClass *i_class_info_p; // rax
  SSClassDescBase *v5; // rax

  i_class_info_p = this->i_class_info_p;
  if ( i_class_info_p == SSBrain::c_this_class_p )
    return scope_type->vfptr->get_metaclass(scope_type);
  if ( i_class_info_p != SSBrain::c_item_class_p )
    return this;
  if ( scope_type->vfptr->get_class_type(scope_type) != SSClassType_typed_class )
    return SSBrain::c_object_class_p->vfptr->get_metaclass(SSBrain::c_object_class_p);
  v5 = scope_type->vfptr->get_item_type(scope_type);
  return v5->vfptr->get_metaclass(v5);
}

// File Line: 163
// RVA: 0x115320
SSClass *__fastcall SSMetaClass::find_data_scope(SSMetaClass *this, ASymbol *name, __int64 check_path)
{
  return (SSClass *)((__int64 (__fastcall *)(SSClass *, ASymbol *, __int64))this->i_class_info_p->vfptr[1].as_unary_class)(
                      this->i_class_info_p,
                      name,
                      check_path);
}

// File Line: 177
// RVA: 0x114D70
SSMetaClass *__fastcall SSMetaClass::find_common_class(SSMetaClass *this, SSClass *cls)
{
  SSClass *i_class_info_p; // rdi
  SSClass *i_superclass_p; // rcx
  SSMetaClass *result; // rax

  i_class_info_p = this->i_class_info_p;
  do
  {
    if ( cls == i_class_info_p )
      break;
    i_superclass_p = i_class_info_p->i_superclass_p;
    if ( i_superclass_p )
    {
      if ( SSClass::is_class(i_superclass_p, cls) )
        break;
    }
    cls = cls->i_superclass_p;
  }
  while ( cls );
  result = (SSMetaClass *)SSBrain::c_object_class_p;
  if ( cls != SSBrain::c_object_class_p )
    return &cls->i_metaclass;
  return result;
}

// File Line: 194
// RVA: 0x114FD0
SSClass *__fastcall SSMetaClass::find_common_type(SSMetaClass *this, SSClass *cls)
{
  SSClass *v3; // rbx
  eSSClassType v4; // eax
  __int32 v5; // eax
  bool v6; // zf
  SSClassDescBaseVtbl *vfptr; // rax
  SSClass *i_class_info_p; // rdi
  SSClass *i_superclass_p; // rcx
  SSClass *result; // rax
  SSClassDescBaseVtbl *v11; // rdi
  __int64 v12; // rax
  SSClass *v13; // rdi
  SSClass *i_object_ids_p; // rbx
  SSClass *v15; // rcx

  v3 = cls;
  v4 = cls->vfptr->get_class_type(cls);
  if ( v4 == SSClassType_class )
  {
LABEL_5:
    i_class_info_p = this->i_class_info_p;
    do
    {
      if ( v3 == i_class_info_p )
        break;
      i_superclass_p = i_class_info_p->i_superclass_p;
      if ( i_superclass_p )
      {
        if ( SSClass::is_class(i_superclass_p, v3) )
          break;
      }
      v3 = v3->i_superclass_p;
    }
    while ( v3 );
    result = SSBrain::c_object_class_p;
    if ( v3 != SSBrain::c_object_class_p )
      return (SSClass *)&v3->i_metaclass;
    return result;
  }
  v5 = v4 - 1;
  if ( v5 )
  {
    v6 = v5 == 3;
    vfptr = v3->vfptr;
    if ( v6 )
    {
      v11 = this->SSClassUnaryBase::SSClassDescBase::vfptr;
      v12 = (__int64)vfptr->as_unary_class(v3);
      return (SSClass *)v11->find_common_type(this, (SSClassDescBase *)v12);
    }
    v3 = vfptr->get_key_class(v3);
    goto LABEL_5;
  }
  v13 = this->i_class_info_p;
  i_object_ids_p = (SSClass *)v3->i_object_ids_p;
  do
  {
    if ( i_object_ids_p == v13 )
      break;
    v15 = v13->i_superclass_p;
    if ( v15 )
    {
      if ( SSClass::is_class(v15, i_object_ids_p) )
        break;
    }
    i_object_ids_p = i_object_ids_p->i_superclass_p;
  }
  while ( i_object_ids_p );
  return (SSClass *)i_object_ids_p->vfptr->get_metaclass(i_object_ids_p);
}

// File Line: 229
// RVA: 0x117980
SSClassDescBaseVtbl *__fastcall SSMetaClass::get_data_type(SSMetaClass *this, ASymbol *data_name, eSSScope *scope_p)
{
  SSClassDescBaseVtbl *result; // rax

  result = (SSClassDescBaseVtbl *)APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
                                    (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&this->i_class_info_p->i_class_data_table,
                                    data_name);
  if ( result )
  {
    if ( scope_p )
      *scope_p = SSScope_class;
    return *(SSClassDescBaseVtbl **)result->gap8;
  }
  return result;
}

// File Line: 254
// RVA: 0x11E9E0
bool __fastcall SSMetaClass::is_class_type(SSMetaClass *this, SSClass *type_p)
{
  eSSClassType v4; // eax
  __int32 v5; // eax
  SSClass *i_object_ids_p; // rdx
  SSClass *i_class_info_p; // rax
  SSClass *i_superclass_p; // rcx

  v4 = type_p->vfptr->get_class_type(type_p);
  if ( v4 == SSClassType_class )
    return type_p == SSBrain::c_object_class_p || type_p == SSBrain::c_class_class_p;
  v5 = v4 - 1;
  if ( !v5 )
  {
    i_object_ids_p = (SSClass *)type_p->i_object_ids_p;
    if ( i_object_ids_p == SSBrain::c_object_class_p )
      return 1;
    i_class_info_p = this->i_class_info_p;
    if ( i_object_ids_p == i_class_info_p )
      return 1;
    i_superclass_p = i_class_info_p->i_superclass_p;
    if ( i_superclass_p )
    {
      if ( SSClass::is_class(i_superclass_p, i_object_ids_p) )
        return 1;
    }
    return 0;
  }
  return v5 == 3 && SSClassUnion::is_valid_param_for((SSClassUnion *)type_p, this);
}

// File Line: 291
// RVA: 0x11ED30
bool __fastcall SSMetaClass::is_generic(SSMetaClass *this)
{
  SSClass *i_class_info_p; // rax

  i_class_info_p = this->i_class_info_p;
  return i_class_info_p == SSBrain::c_this_class_p || i_class_info_p == SSBrain::c_item_class_p;
}

// File Line: 313
// RVA: 0x120060
void __fastcall SSMetaClass::method_invoke(
        SSMetaClass *this,
        SSMethodCall *mcall,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  unsigned __int64 i_scope_p; // rbx
  SSMethodBase *v10; // rdi
  SSClass *v11; // rcx
  SSQualifier *v12; // rdx
  SSMethodBase *class_method_inherited; // rax
  SSObjectBase *v14; // rdx
  SSInvokedMethod *v15; // rbx

  i_scope_p = (unsigned __int64)mcall->i_scope_p;
  if ( !i_scope_p )
    i_scope_p = this->i_user_data2;
  v10 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
          (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)(i_scope_p + 216),
          &mcall->i_name);
  if ( !v10 )
  {
    v11 = *(SSClass **)(i_scope_p + 16);
    v12 = &mcall->SSQualifier;
    if ( v11 )
      class_method_inherited = SSClass::get_class_method_inherited(v11, &v12->i_name);
    else
      class_method_inherited = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
                                 &SSBrain::c_object_class_p->i_methods,
                                 &v12->i_name);
    v10 = class_method_inherited;
  }
  if ( v10 )
  {
    v14 = 0i64;
    if ( this != (SSMetaClass *)8 )
      v14 = (SSObjectBase *)this;
    v15 = SSInvokedMethod::pool_new(caller_p, v14, v10);
    SSInvokedContextBase::data_append_args_exprs(v15, &mcall->i_arguments, v10, scope_p);
    ((void (__fastcall *)(SSMethodBase *, SSInvokedMethod *, SSInvokedBase *, SSInstance **))v10->vfptr[1].get_custom_expr)(
      v10,
      v15,
      caller_p,
      result_pp);
    SSInvokedContextBase::data_bind_return_args(v15, &mcall->i_return_args, v10);
    SSInvokedMethod::pool_delete(v15);
  }
  else if ( result_pp )
  {
    *result_pp = SSBrain::c_nil_p;
  }
}

// File Line: 393
// RVA: 0x11FD60
void __fastcall SSMetaClass::method_call(
        SSMetaClass *this,
        ASymbol *method_name,
        SSInstance **args_pp,
        unsigned int arg_count,
        SSInstance **result_pp,
        SSInvokedBase *caller_p)
{
  unsigned __int64 i_user_data2; // rdi
  SSMethodBase *v11; // rsi
  SSClass *v12; // rcx
  SSMethodBase *class_method_inherited; // rax
  SSObjectBase *v14; // rdx
  SSInvokedMethod *v15; // rdi

  i_user_data2 = this->i_user_data2;
  v11 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
          (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)(i_user_data2 + 216),
          method_name);
  if ( !v11 )
  {
    v12 = *(SSClass **)(i_user_data2 + 16);
    if ( v12 )
      class_method_inherited = SSClass::get_class_method_inherited(v12, method_name);
    else
      class_method_inherited = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
                                 &SSBrain::c_object_class_p->i_methods,
                                 method_name);
    v11 = class_method_inherited;
  }
  v14 = 0i64;
  if ( this != (SSMetaClass *)8 )
    v14 = (SSObjectBase *)this;
  v15 = SSInvokedMethod::pool_new(caller_p, v14, v11);
  SSInvokedContextBase::data_append_args(v15, args_pp, arg_count, v11);
  ((void (__fastcall *)(SSMethodBase *, SSInvokedMethod *, SSInvokedBase *, SSInstance **))v11->vfptr[1].get_custom_expr)(
    v11,
    v15,
    caller_p,
    result_pp);
  SSInvokedMethod::pool_delete(v15);
}

// File Line: 465
// RVA: 0x1178B0
SSInstance *__fastcall SSMetaClass::get_data_by_name(SSMetaClass *this, ASymbol *name)
{
  SSTypedName *v2; // rax

  v2 = APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)(this->i_user_data2 + 192),
         name);
  if ( v2 )
    return *(SSInstance **)&v2[1].i_name.i_uid;
  else
    return SSBrain::c_nil_p;
}

// File Line: 498
// RVA: 0x13C5D0
void __fastcall SSMetaClass::set_data_by_name(SSMetaClass *this, ASymbol *name, SSInstance *obj_p)
{
  SSTypedName *v4; // rax
  _DWORD *v5; // rcx
  SSTypedName *v6; // rdi

  v4 = APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)(this->i_user_data2 + 192),
         name);
  ++obj_p->i_ref_count;
  v5 = *(_DWORD **)&v4[1].i_name.i_uid;
  v6 = v4;
  if ( v5[4]-- == 1 )
  {
    v5[4] = 0x80000000;
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v5 + 112i64))(v5);
    *(_QWORD *)&v6[1].i_name.i_uid = obj_p;
  }
  else
  {
    *(_QWORD *)&v4[1].i_name.i_uid = obj_p;
  }
}

// File Line: 571
// RVA: 0x1043F0
void __fastcall SSClass::SSClass(SSClass *this, ASymbol *name, SSClass *superclass_p, unsigned int flags)
{
  SSClass *v4; // rax

  this->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassUnaryBase::`vftable;
  this->i_name = (ASymbol)name->i_uid;
  this->vfptr = (SSClassDescBaseVtbl *)&SSClass::`vftable;
  this->i_flags = flags;
  this->i_superclass_p = superclass_p;
  this->i_subclasses.i_count = 0;
  this->i_subclasses.i_array_p = 0i64;
  this->i_subclasses.i_size = 0;
  this->i_object_id_lookup_f = 0i64;
  this->i_object_ids_p = 0i64;
  this->i_data.i_count = 0;
  this->i_data.i_array_p = 0i64;
  this->i_data.i_size = 0;
  this->i_data_table.i_count = 0;
  this->i_data_table.i_array_p = 0i64;
  this->i_data_table.i_size = 0;
  this->i_methods.i_count = 0;
  this->i_methods.i_array_p = 0i64;
  this->i_methods.i_size = 0;
  this->i_destructor_p = 0i64;
  this->i_coroutines.i_count = 0;
  this->i_coroutines.i_array_p = 0i64;
  this->i_coroutines.i_size = 0;
  this->i_class_data.i_count = 0;
  this->i_class_data.i_array_p = 0i64;
  this->i_class_data.i_size = 0;
  this->i_class_data_table.i_count = 0;
  this->i_class_data_table.i_array_p = 0i64;
  this->i_class_data_table.i_size = 0;
  this->i_class_methods.i_count = 0;
  this->i_class_methods.i_array_p = 0i64;
  this->i_class_methods.i_size = 0;
  this->i_metaclass.vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
  this->i_metaclass.vfptr = (SSClassDescBaseVtbl *)&SSClassUnaryBase::`vftable;
  v4 = SSBrain::c_class_class_p;
  this->i_metaclass.vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
  this->i_metaclass.i_ref_count = 0;
  this->i_metaclass.vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable;
  this->i_metaclass.i_class_p = v4;
  this->i_metaclass.i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  this->i_metaclass.vfptr = (SSObjectBaseVtbl *)&SSInstanceUnreffed::`vftable;
  this->i_metaclass.i_ref_count = 1000000;
  this->i_metaclass.vfptr = (SSClassDescBaseVtbl *)&SSMetaClass::`vftable{for `SSClassUnaryBase};
  this->i_metaclass.vfptr = (SSObjectBaseVtbl *)&SSMetaClass::`vftable{for `SSInstanceUnreffed};
  this->i_metaclass.i_class_info_p = 0i64;
  this->i_metaclass.i_class_info_p = this;
  if ( superclass_p )
    APSorted<SSClass,ASymbol,ACompareLogical<ASymbol>>::append_absent(&superclass_p->i_subclasses, this, 0i64);
}

// File Line: 591
// RVA: 0x106BD0
void __fastcall SSClass::~SSClass(SSClass *this)
{
  this->vfptr = (SSClassDescBaseVtbl *)&SSClass::`vftable;
  SSClass::clear_members(this);
  this->i_metaclass.vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable;
  this->i_metaclass.i_ptr_id = 0;
  this->i_metaclass.vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
  this->i_metaclass.vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
  AMemory::c_free_func(this->i_class_methods.i_array_p);
  AMemory::c_free_func(this->i_class_data_table.i_array_p);
  AMemory::c_free_func(this->i_class_data.i_array_p);
  AMemory::c_free_func(this->i_coroutines.i_array_p);
  AMemory::c_free_func(this->i_methods.i_array_p);
  AMemory::c_free_func(this->i_data_table.i_array_p);
  AMemory::c_free_func(this->i_data.i_array_p);
  AMemory::c_free_func(this->i_subclasses.i_array_p);
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
}

// File Line: 600
// RVA: 0x112120
void __fastcall SSClass::clear_members(SSClass *this)
{
  APSortedLogical<SSTypedName,ASymbol> *p_i_data; // rcx
  SSMethodBase **i_array_p; // rbx
  __int64 i_count; // rax
  SSMethodBase **i; // rsi
  SSMethodBase **v6; // rbx
  __int64 v7; // rax
  SSMethodBase **j; // rsi
  SSCoroutineBase **v9; // rbx
  __int64 v10; // rax
  SSCoroutineBase **k; // rsi

  p_i_data = &this->i_data;
  p_i_data[1].i_count = 0;
  APSizedArrayBase<SSTypedName>::free_all(p_i_data);
  this->i_class_data_table.i_count = 0;
  SSTypedData::empty_table(&this->i_class_data);
  i_array_p = this->i_methods.i_array_p;
  i_count = this->i_methods.i_count;
  this->i_methods.i_count = 0;
  for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
  {
    if ( *i_array_p )
      (*i_array_p)->vfptr->__vecDelDtor(*i_array_p, 1u);
  }
  v6 = this->i_class_methods.i_array_p;
  v7 = this->i_class_methods.i_count;
  this->i_class_methods.i_count = 0;
  for ( j = &v6[v7]; v6 < j; ++v6 )
  {
    if ( *v6 )
      (*v6)->vfptr->__vecDelDtor(*v6, 1u);
  }
  v9 = this->i_coroutines.i_array_p;
  v10 = this->i_coroutines.i_count;
  this->i_coroutines.i_count = 0;
  for ( k = &v9[v10]; v9 < k; ++v9 )
  {
    if ( *v9 )
      (*v9)->vfptr->__vecDelDtor(*v9, 1u);
  }
  this->i_flags &= 0xFFFFFFF6;
  this->i_destructor_p = 0i64;
}

// File Line: 623
// RVA: 0x112220
void __fastcall SSClass::clear_members_compact(SSClass *this)
{
  APSortedLogical<SSTypedData,ASymbol> *p_i_class_data; // rsi
  SSMethodBase **i_array_p; // rbx
  SSMethodBase **v4; // rbp
  SSMethodBase **v5; // rbx
  SSMethodBase **v6; // rbp
  SSCoroutineBase **v7; // rbx
  SSCoroutineBase **v8; // rsi

  AMemory::c_free_func(this->i_data_table.i_array_p);
  this->i_data_table.i_array_p = 0i64;
  this->i_data_table.i_count = 0;
  this->i_data_table.i_size = 0;
  APSizedArrayBase<SSTypedName>::free_all(&this->i_data);
  AMemory::c_free_func(this->i_data.i_array_p);
  this->i_data.i_array_p = 0i64;
  this->i_data.i_count = 0;
  this->i_data.i_size = 0;
  AMemory::c_free_func(this->i_class_data_table.i_array_p);
  p_i_class_data = &this->i_class_data;
  this->i_class_data_table.i_array_p = 0i64;
  this->i_class_data_table.i_count = 0;
  this->i_class_data_table.i_size = 0;
  SSTypedData::empty_table(&this->i_class_data);
  AMemory::c_free_func(this->i_class_data.i_array_p);
  this->i_class_data.i_array_p = 0i64;
  this->i_class_data.i_count = 0;
  this->i_class_data.i_size = 0;
  i_array_p = this->i_methods.i_array_p;
  v4 = &i_array_p[this->i_methods.i_count];
  for ( this->i_methods.i_count = 0; i_array_p < v4; ++i_array_p )
  {
    if ( *i_array_p )
      (*i_array_p)->vfptr->__vecDelDtor(*i_array_p, 1u);
  }
  AMemory::c_free_func(this->i_class_data.i_array_p);
  this->i_class_data.i_array_p = 0i64;
  p_i_class_data->i_count = 0;
  this->i_class_data.i_size = 0;
  v5 = this->i_class_methods.i_array_p;
  v6 = &v5[this->i_class_methods.i_count];
  for ( this->i_class_methods.i_count = 0; v5 < v6; ++v5 )
  {
    if ( *v5 )
      (*v5)->vfptr->__vecDelDtor(*v5, 1u);
  }
  AMemory::c_free_func(this->i_class_data.i_array_p);
  this->i_class_data.i_array_p = 0i64;
  p_i_class_data->i_count = 0;
  this->i_class_data.i_size = 0;
  v7 = this->i_coroutines.i_array_p;
  v8 = &v7[this->i_coroutines.i_count];
  for ( this->i_coroutines.i_count = 0; v7 < v8; ++v7 )
  {
    if ( *v7 )
      (*v7)->vfptr->__vecDelDtor(*v7, 1u);
  }
  AMemory::c_free_func(this->i_coroutines.i_array_p);
  this->i_coroutines.i_array_p = 0i64;
  this->i_coroutines.i_count = 0;
  this->i_coroutines.i_size = 0;
  this->i_flags &= 0xFFFFFFF6;
  this->i_destructor_p = 0i64;
}

// File Line: 652
// RVA: 0x1179C0
SSClass *__fastcall SSClass::get_demand_loaded_root(SSClass *this)
{
  SSClass *i_superclass_p; // rcx
  SSClass *result; // rax

  i_superclass_p = this->i_superclass_p;
  if ( !i_superclass_p || (result = SSClass::get_demand_loaded_root(i_superclass_p)) == 0i64 )
  {
    result = 0i64;
    if ( (this->i_flags & 2) != 0 )
      return this;
  }
  return result;
}

// File Line: 670
// RVA: 0x13D2C0
void __fastcall SSClass::track_memory(SSClass *this, AMemoryStats *mem_stats_p, bool skip_demand_loaded)
{
  SSClass *i_superclass_p; // rcx
  bool v7; // r14
  SSMethodBase **i_array_p; // rbx
  SSMethodBase **i; // rbp
  SSMethodBase **v10; // rbx
  SSMethodBase **j; // rbp
  SSCoroutineBase **v12; // rbx
  SSCoroutineBase **k; // rdi

  v7 = 1;
  if ( (this->i_flags & 2) == 0 )
  {
    i_superclass_p = this->i_superclass_p;
    if ( !i_superclass_p || !SSClass::is_demand_loaded(i_superclass_p) )
      v7 = 0;
  }
  if ( skip_demand_loaded && v7 )
  {
    AMemoryStats::track_memory(
      mem_stats_p,
      "SSClass",
      0x130u,
      0,
      8 * this->i_subclasses.i_count + 8,
      8
    * (this->i_subclasses.i_size
     + this->i_data.i_size
     + this->i_data_table.i_size
     + this->i_methods.i_size
     + this->i_coroutines.i_size
     + this->i_class_data.i_size
     + this->i_class_data_table.i_size
     + this->i_class_methods.i_size)
    + 8,
      1u);
  }
  else
  {
    AMemoryStats::track_memory(
      mem_stats_p,
      "SSClass",
      0x130u,
      0,
      8
    * (this->i_class_data.i_count
     + this->i_coroutines.i_count
     + this->i_methods.i_count
     + this->i_data.i_count
     + this->i_class_methods.i_count
     + this->i_subclasses.i_count
     + this->i_data_table.i_count
     + this->i_class_data_table.i_count)
    + 8,
      8
    * (this->i_subclasses.i_size
     + this->i_data.i_size
     + this->i_data_table.i_size
     + this->i_methods.i_size
     + this->i_coroutines.i_size
     + this->i_class_data.i_size
     + this->i_class_data_table.i_size
     + this->i_class_methods.i_size)
    + 8,
      1u);
    if ( this->i_data.i_count )
      AMemoryStats::track_memory(mem_stats_p, "SSTypedName", 0x10u, 0, 0, 0, this->i_data.i_count);
    if ( this->i_class_data.i_count )
      AMemoryStats::track_memory(mem_stats_p, "SSTypedData", 0x18u, 0, 0, 0, this->i_class_data.i_count);
    i_array_p = this->i_methods.i_array_p;
    for ( i = &i_array_p[this->i_methods.i_count]; i_array_p < i; ++i_array_p )
    {
      if ( *i_array_p )
        ((void (__fastcall *)(SSMethodBase *, AMemoryStats *))(*i_array_p)->vfptr[1].get_invoke_type)(
          *i_array_p,
          mem_stats_p);
    }
    v10 = this->i_class_methods.i_array_p;
    for ( j = &v10[this->i_class_methods.i_count]; v10 < j; ++v10 )
    {
      if ( *v10 )
        ((void (__fastcall *)(SSMethodBase *, AMemoryStats *))(*v10)->vfptr[1].get_invoke_type)(*v10, mem_stats_p);
    }
    v12 = this->i_coroutines.i_array_p;
    for ( k = &v12[this->i_coroutines.i_count]; v12 < k; ++v12 )
    {
      if ( *v12 )
        ((void (__fastcall *)(SSCoroutineBase *, AMemoryStats *))(*v12)->vfptr[1].get_invoke_type)(*v12, mem_stats_p);
    }
  }
  if ( v7 )
    AMemoryStats::track_memory(mem_stats_p, "SSClass.demand", 0, 0, 0, 0, 1u);
}

// File Line: 780
// RVA: 0x13C750
void __fastcall SSClass::set_object_id_lookup_func(
        SSClass *this,
        SSInstance *(__fastcall *object_id_lookup_f)(SSObjectId *))
{
  unsigned int i_flags; // eax

  this->i_flags |= 0x10u;
  i_flags = this->i_flags;
  this->i_object_id_lookup_f = object_id_lookup_f;
  if ( (i_flags & 0xE0) == 0 )
    this->i_flags = i_flags & 0xFFFFFF1F | 0x20;
}

// File Line: 801
// RVA: 0x126BA0
SSInstance *__fastcall SSClass::object_id_lookup(SSClass *this, SSObjectId *obj_id_p)
{
  SSInstance *result; // rax

  result = (SSInstance *)this->i_object_id_lookup_f;
  if ( result )
    return (SSInstance *)((__int64 (__fastcall *)(SSObjectId *))result)(obj_id_p);
  return result;
}

// File Line: 1462
// RVA: 0x10FBC0
void __fastcall SSClass::assign_binary(SSClass *this, void **binary_pp, bool append_super_members)
{
  char v3; // r13
  void **v4; // rdi
  unsigned int v6; // r15d
  SSClass *i_superclass_p; // rax
  unsigned int i_count; // ebx
  BOOL v9; // esi
  APSortedLogical<SSTypedName,ASymbol> *p_i_data; // r12
  APSortedLogical<SSTypedName,ASymbol> *p_i_data_table; // r14
  SSClass *v12; // rbx
  unsigned int v13; // edi
  unsigned int v14; // eax
  _BOOL8 v15; // r13
  unsigned int i_uid; // ebx
  int v17; // ecx
  int v18; // ecx
  int v19; // ecx
  int v20; // ecx
  SSClass *v21; // rsi
  SSClass *v22; // rax
  ASymbol *v23; // rax
  SSClass *v24; // rax
  ASymbol *v25; // rax
  SSTypedName *v26; // rax
  SSTypedName *v27; // rdi
  SSClass **i_array_p; // rbx
  SSClass **i; // rsi
  void **v30; // r14
  unsigned int v31; // r12d
  SSClass *v32; // rbx
  SSClass *v33; // rax
  unsigned int v34; // edi
  APSortedLogical<SSTypedData,ASymbol> *p_i_class_data; // rsi
  unsigned int v36; // eax
  SSTypedData **v37; // rbx
  SSTypedData **v38; // rax
  APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol> > *p_i_class_data_table; // r15
  unsigned int v40; // eax
  SSTypedData **v41; // rbx
  SSTypedData **v42; // rax
  SSClass *v43; // rbx
  unsigned int v44; // edi
  unsigned int v45; // eax
  APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol> > *v46; // r13
  unsigned int v47; // ebx
  int v48; // ecx
  unsigned int *v49; // rdx
  int v50; // ecx
  int v51; // ecx
  int v52; // ecx
  SSTypedClass *v53; // rsi
  __int64 v54; // rcx
  ASymbol *v55; // rax
  SSClass **v56; // rdx
  SSClass **v57; // r9
  unsigned int v58; // r10d
  SSClass **v59; // rcx
  unsigned int v60; // r8d
  SSClass *v61; // rax
  SSClassDescBase *v62; // rdi
  ASymbol *v63; // rax
  SSClass **v64; // rdx
  SSClass **v65; // r9
  unsigned int v66; // r10d
  SSClass **v67; // rcx
  unsigned int v68; // r8d
  SSClass *v69; // rcx
  ASymbol *v70; // rax
  SSClass **v71; // rdx
  SSClass **v72; // r9
  unsigned int v73; // r10d
  SSClass **v74; // rcx
  unsigned int v75; // r8d
  SSTypedData *v76; // rax
  SSTypedData *v77; // rdi
  SSInstance *v78; // r14
  SSClass **v79; // rbx
  SSClass **j; // rsi
  const void **v81; // r12
  char *v82; // rax
  unsigned int v83; // r15d
  APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *p_i_methods; // rsi
  unsigned int v85; // ecx
  unsigned int v86; // eax
  SSMethodBase **v87; // rbx
  SSMethodBase **v88; // rax
  SSMethodBase *i_destructor_p; // r14
  int v90; // edi
  unsigned int v91; // ebx
  SSTypedData *v92; // rax
  SSMethodBase *v93; // r13
  SSParameters *v94; // r12
  SSParameterBase **v95; // r14
  SSParameterBase **v96; // rdi
  SSParameterBase **v97; // rsi
  SSTypedName **v98; // r15
  SSTypedName **v99; // rsi
  SSTypedName **v100; // r14
  SSTypedName *v101; // rdi
  SSClassDescBase *v102; // rcx
  SSParameters *v103; // rdi
  bool v104; // zf
  SSTypedData *v105; // rax
  SSParameters *v106; // r12
  SSParameterBase **v107; // r14
  SSParameterBase **v108; // rdi
  SSParameterBase **v109; // rsi
  SSTypedName **v110; // r15
  SSTypedName **v111; // rsi
  SSTypedName **v112; // r14
  SSTypedName *v113; // rdi
  SSClassDescBase *i_obj_p; // rcx
  SSParameters *v115; // rdi
  SSTypedData *v116; // rax
  SSParameters *v117; // r12
  SSParameterBase **v118; // r14
  SSParameterBase **v119; // rdi
  SSParameterBase **v120; // rsi
  SSTypedName **v121; // r15
  SSTypedName **v122; // rsi
  SSTypedName **v123; // r14
  SSTypedName *v124; // rdi
  SSClassDescBase *v125; // rcx
  SSParameters *v126; // rsi
  char *v127; // r12
  char *v128; // rdi
  char *v129; // r14
  SSClassDescBase *v130; // rcx
  eSSExprType v131; // ecx
  char *v132; // rax
  SSExpressionBase *v133; // rax
  SSClass *v134; // r15
  SSClass *v135; // rax
  char *v136; // rax
  unsigned int v137; // r14d
  APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *p_i_class_methods; // rsi
  unsigned int v139; // eax
  SSMethodBase **v140; // rbx
  SSMethodBase **v141; // rax
  int v142; // edi
  unsigned int v143; // ebx
  SSMethodBase *v144; // rax
  SSMethodBase *v145; // rdi
  SSParameters *v146; // rax
  SSParameters *v147; // rsi
  SSParameters *v148; // rbx
  SSMethodBase *v149; // rax
  SSParameters *v150; // rax
  SSParameters *v151; // rsi
  SSParameters *v152; // rbx
  SSMethodBase *v153; // rax
  SSParameters *v154; // r13
  SSParameterBase **v155; // r14
  SSParameterBase **v156; // rbx
  SSParameterBase **v157; // rsi
  SSTypedName **v158; // r15
  SSTypedName **v159; // rsi
  SSTypedName **v160; // r14
  SSTypedName *v161; // rbx
  SSClassDescBase *v162; // rcx
  SSParameters *v163; // rsi
  char *v164; // r12
  char *v165; // rbx
  char *v166; // r14
  SSClassDescBase *v167; // rcx
  eSSExprType v168; // ecx
  __int64 v169; // rax
  SSExpressionBase *v170; // rax
  unsigned int v171; // edi
  int v172; // ebx
  SSCoroutineBase *v173; // rax
  SSCoroutineBase *v174; // rbx
  SSCoroutineBase *v175; // rax
  SSCoroutineBase *v176; // rax
  eSSExprType v177; // ecx
  __int64 v178; // rax
  SSExpressionBase *v179; // rax
  _BOOL8 v180; // [rsp+20h] [rbp-E0h]
  SSParameters *v181; // [rsp+20h] [rbp-E0h]
  ASymbol v182[2]; // [rsp+28h] [rbp-D8h] BYREF
  void *p_i_return_params; // [rsp+30h] [rbp-D0h]
  ASymbol v184[2]; // [rsp+38h] [rbp-C8h] BYREF
  SSTypedData *v185; // [rsp+40h] [rbp-C0h]
  _DWORD *p_i_count; // [rsp+48h] [rbp-B8h]
  SSParameters v187; // [rsp+50h] [rbp-B0h] BYREF
  SSTypedClass tclass; // [rsp+80h] [rbp-80h] BYREF
  SSParameters params_p; // [rsp+A0h] [rbp-60h] BYREF
  SSParameters v190; // [rsp+D0h] [rbp-30h] BYREF
  __int64 v191; // [rsp+100h] [rbp+0h]
  SSClass *v192; // [rsp+160h] [rbp+60h] BYREF
  void **sym_binary_pp; // [rsp+168h] [rbp+68h]
  ASymbol name; // [rsp+170h] [rbp+70h] BYREF
  APSortedLogical<SSTypedData,ASymbol> *result; // [rsp+178h] [rbp+78h] BYREF

  LOBYTE(name.i_uid) = append_super_members;
  sym_binary_pp = binary_pp;
  v192 = this;
  v191 = -2i64;
  v3 = append_super_members;
  v4 = binary_pp;
  v6 = *(unsigned __int16 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 2;
  i_superclass_p = this->i_superclass_p;
  if ( i_superclass_p )
    i_count = i_superclass_p->i_data_table.i_count;
  else
    i_count = 0;
  v9 = append_super_members;
  p_i_data = &this->i_data;
  APSizedArrayBase<SSTypedName>::ensure_size(&this->i_data, v6);
  p_i_data_table = &this->i_data_table;
  APSizedArrayBase<SSTypedName>::ensure_size(p_i_data_table, i_count + v6);
  if ( v3 && i_count )
  {
    v12 = v192->i_superclass_p;
    v13 = v12->i_data_table.i_count;
    APSizedArrayBase<SSTypedName>::ensure_size(p_i_data_table, v13 + p_i_data_table->i_count);
    memmove(&p_i_data_table->i_array_p[p_i_data_table->i_count], v12->i_data_table.i_array_p, 8i64 * v13);
    p_i_data_table->i_count += v13;
    v14 = p_i_data_table->i_count;
    if ( p_i_data_table->i_count != v13 && v14 > 1 )
      qsort(p_i_data_table->i_array_p, v14, 8ui64, APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::sort_compare);
    v4 = sym_binary_pp;
  }
  v180 = v9;
  if ( v6 )
  {
    v15 = v9;
    while ( 1 )
    {
      i_uid = ASymbol::create_from_binary((ASymbol *)&result, (const void **)v4)->i_uid;
      v17 = *(unsigned __int8 *)*v4;
      *v4 = (char *)*v4 + 1;
      if ( !v17 )
      {
        v25 = ASymbol::create_from_binary(v182, (const void **)v4);
        v22 = SSBrain::get_class(v25);
        goto LABEL_23;
      }
      v18 = v17 - 1;
      if ( !v18 )
      {
        v23 = ASymbol::create_from_binary(v184, (const void **)v4);
        v24 = SSBrain::get_class(v23);
        v22 = (SSClass *)v24->vfptr->get_metaclass(v24);
        goto LABEL_23;
      }
      v19 = v18 - 1;
      if ( !v19 )
      {
        v22 = (SSClass *)SSTypedClass::from_binary_ref((const void **)v4);
        goto LABEL_23;
      }
      v20 = v19 - 1;
      if ( !v20 )
        break;
      if ( v20 == 1 )
      {
        v22 = (SSClass *)SSClassUnion::from_binary_ref((const void **)v4);
LABEL_23:
        v21 = v22;
        goto LABEL_24;
      }
      v21 = 0i64;
LABEL_24:
      v26 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
      v27 = v26;
      v185 = (SSTypedData *)v26;
      if ( v26 )
      {
        v26->i_name.i_uid = i_uid;
        v26->i_type_p.i_obj_p = v21;
        if ( v21 )
          (*(void (__fastcall **)(SSClass *))v21->vfptr->gap8)(v21);
      }
      else
      {
        v27 = 0i64;
      }
      APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(p_i_data, v27, 0i64);
      APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(p_i_data_table, v27, 0i64);
      if ( !v15 )
      {
        i_array_p = v192->i_subclasses.i_array_p;
        for ( i = &i_array_p[v192->i_subclasses.i_count]; i_array_p < i; ++i_array_p )
          SSClass::recurse_instance_data(*i_array_p, v27);
      }
      --v6;
      v4 = sym_binary_pp;
      if ( !v6 )
      {
        v3 = name.i_uid;
        goto LABEL_34;
      }
    }
    v22 = (SSClass *)SSInvokableClass::from_binary_ref((const void **)v4);
    goto LABEL_23;
  }
LABEL_34:
  v30 = sym_binary_pp;
  v31 = *(unsigned __int16 *)*sym_binary_pp;
  *sym_binary_pp = (char *)*sym_binary_pp + 2;
  v32 = v192;
  v33 = v192->i_superclass_p;
  if ( v33 )
    v34 = v33->i_class_data_table.i_count;
  else
    v34 = 0;
  p_i_class_data = &v192->i_class_data;
  result = &v192->i_class_data;
  if ( v192->i_class_data.i_size < v31 )
  {
    v36 = AMemory::c_req_byte_size_func(8 * v31) >> 3;
    v32->i_class_data.i_size = v36;
    if ( p_i_class_data->i_count )
    {
      v37 = v32->i_class_data.i_array_p;
      v38 = APArrayBase<SSTypedData>::alloc_array(v36);
      p_i_class_data->i_array_p = v38;
      memmove(v38, v37, 8i64 * p_i_class_data->i_count);
      AMemory::c_free_func(v37);
      v32 = v192;
    }
    else
    {
      AMemory::c_free_func(v32->i_class_data.i_array_p);
      v32->i_class_data.i_array_p = APArrayBase<SSTypedData>::alloc_array(v32->i_class_data.i_size);
    }
  }
  p_i_class_data_table = &v32->i_class_data_table;
  if ( v32->i_class_data_table.i_size < v34 + v31 )
  {
    v40 = AMemory::c_req_byte_size_func(8 * (v34 + v31)) >> 3;
    v32->i_class_data_table.i_size = v40;
    if ( p_i_class_data_table->i_count )
    {
      v41 = v32->i_class_data_table.i_array_p;
      v42 = APArrayBase<SSTypedData>::alloc_array(v40);
      p_i_class_data_table->i_array_p = v42;
      memmove(v42, v41, 8i64 * p_i_class_data_table->i_count);
      AMemory::c_free_func(v41);
      v32 = v192;
    }
    else
    {
      AMemory::c_free_func(v32->i_class_data_table.i_array_p);
      v32->i_class_data_table.i_array_p = APArrayBase<SSTypedData>::alloc_array(v32->i_class_data_table.i_size);
    }
  }
  if ( v3 )
  {
    if ( v34 )
    {
      v43 = v32->i_superclass_p;
      v44 = v43->i_class_data_table.i_count;
      APSizedArrayBase<SSTypedData>::ensure_size(p_i_class_data_table, v44 + p_i_class_data_table->i_count);
      memmove(
        &p_i_class_data_table->i_array_p[p_i_class_data_table->i_count],
        v43->i_class_data_table.i_array_p,
        8i64 * v44);
      p_i_class_data_table->i_count += v44;
      v45 = p_i_class_data_table->i_count;
      if ( p_i_class_data_table->i_count != v44 && v45 > 1 )
        qsort(
          p_i_class_data_table->i_array_p,
          v45,
          8ui64,
          APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::sort_compare);
    }
  }
  if ( v31 )
  {
    v46 = result;
    while ( 1 )
    {
      v47 = ASymbol::create_from_binary(&name, (const void **)v30)->i_uid;
      v48 = *(unsigned __int8 *)*v30;
      v49 = (unsigned int *)((char *)*v30 + 1);
      *v30 = v49;
      if ( !v48 )
        break;
      v50 = v48 - 1;
      if ( !v50 )
      {
        v63 = ASymbol::create_from_binary(v182, (const void **)v30);
        if ( SSBrain::c_classes.i_count )
        {
          v64 = SSBrain::c_classes.i_array_p;
          v65 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1];
          v66 = v63->i_uid;
          while ( 1 )
          {
            while ( 1 )
            {
              v67 = &v64[((char *)v65 - (char *)v64) >> 4];
              v68 = (*v67)->i_name.i_uid;
              if ( v66 >= v68 )
                break;
              if ( v64 == v67 )
                goto LABEL_81;
              v65 = v67 - 1;
            }
            if ( v66 == v68 )
              break;
            if ( v65 == v67 )
              goto LABEL_81;
            v64 = v67 + 1;
          }
          v69 = *v67;
        }
        else
        {
LABEL_81:
          v69 = 0i64;
        }
        v53 = (SSTypedClass *)v69->vfptr->get_metaclass(v69);
        goto LABEL_93;
      }
      v51 = v50 - 1;
      if ( !v51 )
      {
        if ( SSClassDescBase::c_compounds_use_ref )
        {
          v54 = *v49;
          *v30 = v49 + 1;
          v53 = SSTypedClass::c_typed_classes.i_array_p[v54];
        }
        else
        {
          tclass.i_ref_count = 0;
          tclass.vfptr = (SSClassDescBaseVtbl *)&SSTypedClass::`vftable;
          tclass.i_item_type_p = 0i64;
          v55 = ASymbol::create_from_binary((ASymbol *)&result, (const void **)v30);
          if ( SSBrain::c_classes.i_count )
          {
            v56 = SSBrain::c_classes.i_array_p;
            v57 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1];
            v58 = v55->i_uid;
            while ( 1 )
            {
              while ( 1 )
              {
                v59 = &v56[((char *)v57 - (char *)v56) >> 4];
                v60 = (*v59)->i_name.i_uid;
                if ( v58 >= v60 )
                  break;
                if ( v56 == v59 )
                  goto LABEL_70;
                v57 = v59 - 1;
              }
              if ( v58 == v60 )
                break;
              if ( v57 == v59 )
                goto LABEL_70;
              v56 = v59 + 1;
            }
            v61 = *v59;
          }
          else
          {
LABEL_70:
            v61 = 0i64;
          }
          tclass.i_class_p = v61;
          v62 = SSClassDescBase::from_binary_ref_typed((const void **)v30);
          (*(void (__fastcall **)(SSClassDescBase *))v62->vfptr->gap8)(v62);
          tclass.i_item_type_p = v62;
          v53 = SSTypedClass::get_or_create(&tclass);
          tclass.vfptr = (SSClassDescBaseVtbl *)&SSTypedClass::`vftable;
          v62->vfptr->dereference_delay(v62);
          tclass.i_item_type_p = 0i64;
          tclass.vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
        }
        goto LABEL_93;
      }
      v52 = v51 - 1;
      if ( v52 )
      {
        if ( v52 != 1 )
          goto LABEL_92;
        v53 = (SSTypedClass *)SSClassUnion::from_binary_ref((const void **)v30);
      }
      else
      {
        v53 = (SSTypedClass *)SSInvokableClass::from_binary_ref((const void **)v30);
      }
LABEL_93:
      v76 = (SSTypedData *)AMemory::c_malloc_func(0x18ui64, "SSTypedData");
      v77 = v76;
      v185 = v76;
      if ( v76 )
      {
        v78 = SSBrain::c_nil_p;
        v76->i_name.i_uid = v47;
        v76->i_type_p.i_obj_p = v53;
        if ( v53 )
          (*(void (__fastcall **)(SSTypedClass *))v53->vfptr->gap8)(v53);
        v77->i_data_p = v78;
        v30 = sym_binary_pp;
      }
      else
      {
        v77 = 0i64;
      }
      APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol>>::append(v46, v77, 0i64);
      APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol>>::append(p_i_class_data_table, v77, 0i64);
      if ( !v180 )
      {
        v79 = v192->i_subclasses.i_array_p;
        for ( j = &v79[v192->i_subclasses.i_count]; v79 < j; ++v79 )
          SSClass::recurse_class_data(*v79, v77);
      }
      if ( !--v31 )
        goto LABEL_102;
    }
    v70 = ASymbol::create_from_binary(v184, (const void **)v30);
    if ( SSBrain::c_classes.i_count )
    {
      v71 = SSBrain::c_classes.i_array_p;
      v72 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1];
      v73 = v70->i_uid;
      while ( 1 )
      {
        while ( 1 )
        {
          v74 = &v71[((char *)v72 - (char *)v71) >> 4];
          v75 = (*v74)->i_name.i_uid;
          if ( v73 >= v75 )
            break;
          if ( v71 == v74 )
            goto LABEL_92;
          v72 = v74 - 1;
        }
        if ( v73 == v75 )
          break;
        if ( v72 == v74 )
          goto LABEL_92;
        v71 = v74 + 1;
      }
      v53 = (SSTypedClass *)*v74;
      goto LABEL_93;
    }
LABEL_92:
    v53 = 0i64;
    goto LABEL_93;
  }
LABEL_102:
  v81 = (const void **)sym_binary_pp;
  v82 = (char *)*sym_binary_pp;
  name.i_uid = *(_DWORD *)*sym_binary_pp;
  v83 = name.i_uid;
  *sym_binary_pp = v82 + 4;
  p_i_methods = &v192->i_methods;
  *(_QWORD *)&v184[0].i_uid = &v192->i_methods;
  v85 = v83 + v192->i_methods.i_count;
  if ( v192->i_methods.i_size < v85 )
  {
    v86 = AMemory::c_req_byte_size_func(8 * v85) >> 3;
    p_i_methods->i_size = v86;
    if ( p_i_methods->i_count )
    {
      v87 = p_i_methods->i_array_p;
      v88 = APArrayBase<SSMethodBase>::alloc_array(v86);
      p_i_methods->i_array_p = v88;
      memmove(v88, v87, 8i64 * p_i_methods->i_count);
      AMemory::c_free_func(v87);
    }
    else
    {
      AMemory::c_free_func(p_i_methods->i_array_p);
      p_i_methods->i_array_p = APArrayBase<SSMethodBase>::alloc_array(p_i_methods->i_size);
    }
  }
  i_destructor_p = 0i64;
  *(_QWORD *)&v182[0].i_uid = 0i64;
  if ( !v83 )
    goto LABEL_189;
  do
  {
    v90 = *(unsigned __int8 *)*v81;
    *v81 = (char *)*v81 + 1;
    v91 = ASymbol::create_from_binary((ASymbol *)&result, v81)->i_uid;
    if ( v90 )
    {
      if ( v90 == 2 )
      {
        v105 = (SSTypedData *)AMemory::c_malloc_func(0x30ui64, "SSMethodMthd");
        v93 = (SSMethodBase *)v105;
        v185 = v105;
        if ( v105 )
        {
          LODWORD(v105->i_type_p.i_obj_p) = v91;
          v105->i_data_p = (SSInstance *)v192;
          *(_QWORD *)&v105->i_name.i_uid = &SSInvokableBase::`vftable;
          *(_QWORD *)&v105[1].i_name.i_uid = 0i64;
          *(_QWORD *)&v105->i_name.i_uid = &SSMethodBase::`vftable;
          SSParameters::SSParameters(&v190, v81);
          v106 = SSParameters::get_or_create(&v190);
          v107 = v190.i_params.i_array_p;
          v108 = v190.i_params.i_array_p;
          v109 = &v190.i_params.i_array_p[v190.i_params.i_count];
          v190.i_params.i_array_p = 0i64;
          for ( v190.i_params.i_count = 0; v108 < v109; ++v108 )
          {
            if ( *v108 )
              (*v108)->vfptr->__vecDelDtor(*v108, 1u);
          }
          AMemory::c_free_func(v107);
          v110 = v190.i_return_params.i_array_p;
          v111 = v190.i_return_params.i_array_p;
          v112 = &v190.i_return_params.i_array_p[v190.i_return_params.i_count];
          v190.i_return_params.i_array_p = 0i64;
          for ( v190.i_return_params.i_count = 0; v111 < v112; ++v111 )
          {
            v113 = *v111;
            if ( *v111 )
            {
              i_obj_p = v113->i_type_p.i_obj_p;
              if ( i_obj_p )
                (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
              AMemory::c_free_func(v113);
            }
          }
          AMemory::c_free_func(v110);
          if ( v190.i_result_type_p.i_obj_p )
            (*(void (__fastcall **)(SSClassDescBase *))&v190.i_result_type_p.i_obj_p->vfptr->gap8[8])(v190.i_result_type_p.i_obj_p);
          AMemory::c_free_func(v190.i_return_params.i_array_p);
          AMemory::c_free_func(v190.i_params.i_array_p);
          if ( v93->i_params_p.i_obj_p != v106 )
          {
            if ( v106 )
              ++v106->i_ref_count;
            v115 = v93->i_params_p.i_obj_p;
            if ( v115 )
            {
              v104 = v115->i_ref_count-- == 1;
              if ( v104 )
              {
                v115->i_ref_count = 0x80000000;
                SSParameters::~SSParameters(v115);
                AMemory::c_free_func(v115);
              }
            }
            v93->i_params_p.i_obj_p = v106;
          }
          v93->vfptr = (SSInvokableBaseVtbl *)&SSMethodMthd::`vftable;
          tclass.i_ref_count = 0;
          v93[1].vfptr = 0i64;
          *(_QWORD *)&v93[1].i_name.i_uid = *(_QWORD *)&tclass.i_ref_count;
          v81 = (const void **)sym_binary_pp;
          p_i_methods = *(APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > **)&v184[0].i_uid;
          i_destructor_p = *(SSMethodBase **)&v182[0].i_uid;
          v83 = name.i_uid;
        }
        else
        {
          v93 = 0i64;
        }
      }
      else
      {
        v92 = (SSTypedData *)AMemory::c_malloc_func(0x28ui64, "SSMethodFunc");
        v93 = (SSMethodBase *)v92;
        v185 = v92;
        if ( v92 )
        {
          LODWORD(v92->i_type_p.i_obj_p) = v91;
          v92->i_data_p = (SSInstance *)v192;
          *(_QWORD *)&v92->i_name.i_uid = &SSInvokableBase::`vftable;
          *(_QWORD *)&v92[1].i_name.i_uid = 0i64;
          *(_QWORD *)&v92->i_name.i_uid = &SSMethodBase::`vftable;
          SSParameters::SSParameters(&params_p, v81);
          v94 = SSParameters::get_or_create(&params_p);
          v95 = params_p.i_params.i_array_p;
          v96 = params_p.i_params.i_array_p;
          v97 = &params_p.i_params.i_array_p[params_p.i_params.i_count];
          params_p.i_params.i_array_p = 0i64;
          for ( params_p.i_params.i_count = 0; v96 < v97; ++v96 )
          {
            if ( *v96 )
              (*v96)->vfptr->__vecDelDtor(*v96, 1u);
          }
          AMemory::c_free_func(v95);
          v98 = params_p.i_return_params.i_array_p;
          v99 = params_p.i_return_params.i_array_p;
          v100 = &params_p.i_return_params.i_array_p[params_p.i_return_params.i_count];
          params_p.i_return_params.i_array_p = 0i64;
          for ( params_p.i_return_params.i_count = 0; v99 < v100; ++v99 )
          {
            v101 = *v99;
            if ( *v99 )
            {
              v102 = v101->i_type_p.i_obj_p;
              if ( v102 )
                (*(void (__fastcall **)(SSClassDescBase *))&v102->vfptr->gap8[8])(v102);
              AMemory::c_free_func(v101);
            }
          }
          AMemory::c_free_func(v98);
          if ( params_p.i_result_type_p.i_obj_p )
            (*(void (__fastcall **)(SSClassDescBase *))&params_p.i_result_type_p.i_obj_p->vfptr->gap8[8])(params_p.i_result_type_p.i_obj_p);
          AMemory::c_free_func(params_p.i_return_params.i_array_p);
          AMemory::c_free_func(params_p.i_params.i_array_p);
          if ( v93->i_params_p.i_obj_p != v94 )
          {
            if ( v94 )
              ++v94->i_ref_count;
            v103 = v93->i_params_p.i_obj_p;
            if ( v103 )
            {
              v104 = v103->i_ref_count-- == 1;
              if ( v104 )
              {
                v103->i_ref_count = 0x80000000;
                SSParameters::~SSParameters(v103);
                AMemory::c_free_func(v103);
              }
            }
            v93->i_params_p.i_obj_p = v94;
          }
          v93->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
          v93[1].vfptr = 0i64;
          v81 = (const void **)sym_binary_pp;
          p_i_methods = *(APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > **)&v184[0].i_uid;
          i_destructor_p = *(SSMethodBase **)&v182[0].i_uid;
          v83 = name.i_uid;
        }
        else
        {
          v93 = 0i64;
        }
      }
    }
    else
    {
      v116 = (SSTypedData *)AMemory::c_malloc_func(0x28ui64, "SSMethod");
      v93 = (SSMethodBase *)v116;
      v185 = v116;
      if ( v116 )
      {
        LODWORD(v116->i_type_p.i_obj_p) = v91;
        v116->i_data_p = (SSInstance *)v192;
        *(_QWORD *)&v116->i_name.i_uid = &SSInvokableBase::`vftable;
        *(_QWORD *)&v116[1].i_name.i_uid = 0i64;
        *(_QWORD *)&v116->i_name.i_uid = &SSMethodBase::`vftable;
        SSParameters::SSParameters(&v187, v81);
        v117 = SSParameters::get_or_create(&v187);
        v181 = v117;
        v118 = v187.i_params.i_array_p;
        v119 = v187.i_params.i_array_p;
        v120 = &v187.i_params.i_array_p[v187.i_params.i_count];
        v187.i_params.i_array_p = 0i64;
        for ( v187.i_params.i_count = 0; v119 < v120; ++v119 )
        {
          if ( *v119 )
            (*v119)->vfptr->__vecDelDtor(*v119, 1u);
        }
        AMemory::c_free_func(v118);
        v121 = v187.i_return_params.i_array_p;
        v122 = v187.i_return_params.i_array_p;
        v123 = &v187.i_return_params.i_array_p[v187.i_return_params.i_count];
        v187.i_return_params.i_array_p = 0i64;
        for ( v187.i_return_params.i_count = 0; v122 < v123; ++v122 )
        {
          v124 = *v122;
          p_i_return_params = v124;
          if ( v124 )
          {
            v125 = v124->i_type_p.i_obj_p;
            if ( v125 )
              (*(void (__fastcall **)(SSClassDescBase *))&v125->vfptr->gap8[8])(v125);
            AMemory::c_free_func(v124);
          }
        }
        AMemory::c_free_func(v121);
        if ( v187.i_result_type_p.i_obj_p )
          (*(void (__fastcall **)(SSClassDescBase *))&v187.i_result_type_p.i_obj_p->vfptr->gap8[8])(v187.i_result_type_p.i_obj_p);
        p_i_return_params = &v187.i_return_params;
        AMemory::c_free_func(v187.i_return_params.i_array_p);
        p_i_return_params = &v187.i_params;
        AMemory::c_free_func(v187.i_params.i_array_p);
        if ( v93->i_params_p.i_obj_p != v117 )
        {
          if ( v117 )
            ++v117->i_ref_count;
          v126 = v93->i_params_p.i_obj_p;
          if ( v126 )
          {
            v104 = v126->i_ref_count-- == 1;
            if ( v104 )
            {
              v126->i_ref_count = 0x80000000;
              p_i_return_params = v126;
              v127 = (char *)v126->i_params.i_array_p;
              v128 = v127;
              v129 = &v127[8 * v126->i_params.i_count];
              v126->i_params.i_array_p = 0i64;
              v126->i_params.i_count = 0;
              if ( v127 < v129 )
              {
                do
                {
                  if ( *(_QWORD *)v128 )
                    (***(void (__fastcall ****)(_QWORD, __int64))v128)(*(_QWORD *)v128, 1i64);
                  v128 += 8;
                }
                while ( v128 < v129 );
              }
              AMemory::c_free_func(v127);
              APCompactArrayBase<SSTypedName>::free_all(&v126->i_return_params);
              v130 = v126->i_result_type_p.i_obj_p;
              if ( v130 )
                (*(void (__fastcall **)(SSClassDescBase *))&v130->vfptr->gap8[8])(v130);
              p_i_count = &v126->i_return_params.i_count;
              AMemory::c_free_func(v126->i_return_params.i_array_p);
              p_i_count = &v126->i_params.i_count;
              AMemory::c_free_func(v126->i_params.i_array_p);
              AMemory::c_free_func(v126);
              v117 = v181;
            }
          }
          v93->i_params_p.i_obj_p = v117;
        }
        v93->vfptr = (SSInvokableBaseVtbl *)&SSMethod::`vftable;
        v81 = (const void **)sym_binary_pp;
        v131 = *(unsigned __int8 *)*sym_binary_pp;
        v132 = (char *)*sym_binary_pp + 1;
        *sym_binary_pp = v132;
        if ( v131 )
        {
          *v81 = v132 + 2;
          v133 = SSExpressionBase::from_binary_new(v131, v81);
        }
        else
        {
          v133 = 0i64;
        }
        v93[1].vfptr = (SSInvokableBaseVtbl *)v133;
        p_i_methods = *(APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > **)&v184[0].i_uid;
        i_destructor_p = *(SSMethodBase **)&v182[0].i_uid;
        v83 = name.i_uid;
      }
      else
      {
        v93 = 0i64;
      }
    }
    APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::append(p_i_methods, v93, 0i64);
    if ( v91 == ASymbolX_dtor.i_uid )
      i_destructor_p = v93;
    *(_QWORD *)&v182[0].i_uid = i_destructor_p;
    name.i_uid = --v83;
  }
  while ( v83 );
  if ( i_destructor_p )
  {
    v134 = v192;
  }
  else
  {
LABEL_189:
    v134 = v192;
    v135 = v192->i_superclass_p;
    if ( v135 )
      i_destructor_p = v135->i_destructor_p;
    else
      i_destructor_p = 0i64;
  }
  v134->i_destructor_p = i_destructor_p;
  v136 = (char *)*v81;
  name.i_uid = *(_DWORD *)*v81;
  v137 = name.i_uid;
  *v81 = v136 + 4;
  p_i_class_methods = &v134->i_class_methods;
  *(_QWORD *)&v182[0].i_uid = &v134->i_class_methods;
  if ( v134->i_class_methods.i_size < v137 )
  {
    v139 = AMemory::c_req_byte_size_func(8 * v137) >> 3;
    v134->i_class_methods.i_size = v139;
    if ( p_i_class_methods->i_count )
    {
      v140 = v134->i_class_methods.i_array_p;
      v141 = APArrayBase<SSMethodBase>::alloc_array(v139);
      v134->i_class_methods.i_array_p = v141;
      memmove(v141, v140, 8i64 * p_i_class_methods->i_count);
      AMemory::c_free_func(v140);
    }
    else
    {
      AMemory::c_free_func(v134->i_class_methods.i_array_p);
      v134->i_class_methods.i_array_p = APArrayBase<SSMethodBase>::alloc_array(v134->i_class_methods.i_size);
    }
  }
  for ( ; v137; name.i_uid = v137 )
  {
    v142 = *(unsigned __int8 *)*v81;
    *v81 = (char *)*v81 + 1;
    v143 = ASymbol::create_from_binary((ASymbol *)&result, v81)->i_uid;
    if ( v142 )
    {
      if ( v142 == 2 )
      {
        v149 = (SSMethodBase *)AMemory::c_malloc_func(0x30ui64, "SSMethodMthd");
        v145 = v149;
        p_i_count = v149;
        if ( v149 )
        {
          v149->i_name.i_uid = v143;
          v149->i_scope_p = v134;
          v149->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
          v149->i_params_p.i_obj_p = 0i64;
          v149->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
          v150 = SSParameters::get_or_create(v81);
          v151 = v150;
          if ( v145->i_params_p.i_obj_p != v150 )
          {
            if ( v150 )
              ++v150->i_ref_count;
            v152 = v145->i_params_p.i_obj_p;
            if ( v152 )
            {
              v104 = v152->i_ref_count-- == 1;
              if ( v104 )
              {
                v152->i_ref_count = 0x80000000;
                SSParameters::~SSParameters(v152);
                AMemory::c_free_func(v152);
              }
            }
            v145->i_params_p.i_obj_p = v151;
          }
          v145->vfptr = (SSInvokableBaseVtbl *)&SSMethodMthd::`vftable;
          tclass.i_ref_count = 0;
          v145[1].vfptr = 0i64;
          *(_QWORD *)&v145[1].i_name.i_uid = *(_QWORD *)&tclass.i_ref_count;
          p_i_class_methods = *(APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > **)&v182[0].i_uid;
        }
        else
        {
          v145 = 0i64;
        }
      }
      else
      {
        v144 = (SSMethodBase *)AMemory::c_malloc_func(0x28ui64, "SSMethodFunc");
        v145 = v144;
        p_i_count = v144;
        if ( v144 )
        {
          v144->i_name.i_uid = v143;
          v144->i_scope_p = v134;
          v144->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
          v144->i_params_p.i_obj_p = 0i64;
          v144->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
          v146 = SSParameters::get_or_create(v81);
          v147 = v146;
          if ( v145->i_params_p.i_obj_p != v146 )
          {
            if ( v146 )
              ++v146->i_ref_count;
            v148 = v145->i_params_p.i_obj_p;
            if ( v148 )
            {
              v104 = v148->i_ref_count-- == 1;
              if ( v104 )
              {
                v148->i_ref_count = 0x80000000;
                SSParameters::~SSParameters(v148);
                AMemory::c_free_func(v148);
              }
            }
            v145->i_params_p.i_obj_p = v147;
          }
          v145->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
          v145[1].vfptr = 0i64;
          p_i_class_methods = *(APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > **)&v182[0].i_uid;
        }
        else
        {
          v145 = 0i64;
        }
      }
    }
    else
    {
      v153 = (SSMethodBase *)AMemory::c_malloc_func(0x28ui64, "SSMethod");
      v145 = v153;
      p_i_count = v153;
      if ( v153 )
      {
        v153->i_name.i_uid = v143;
        v153->i_scope_p = v134;
        v153->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
        v153->i_params_p.i_obj_p = 0i64;
        v153->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
        SSParameters::SSParameters(&v187, v81);
        v154 = SSParameters::get_or_create(&v187);
        v155 = v187.i_params.i_array_p;
        v156 = v187.i_params.i_array_p;
        v157 = &v187.i_params.i_array_p[v187.i_params.i_count];
        v187.i_params.i_array_p = 0i64;
        for ( v187.i_params.i_count = 0; v156 < v157; ++v156 )
        {
          if ( *v156 )
            (*v156)->vfptr->__vecDelDtor(*v156, 1u);
        }
        AMemory::c_free_func(v155);
        v158 = v187.i_return_params.i_array_p;
        v159 = v187.i_return_params.i_array_p;
        v160 = &v187.i_return_params.i_array_p[v187.i_return_params.i_count];
        v187.i_return_params.i_array_p = 0i64;
        for ( v187.i_return_params.i_count = 0; v159 < v160; ++v159 )
        {
          v161 = *v159;
          p_i_return_params = v161;
          if ( v161 )
          {
            v162 = v161->i_type_p.i_obj_p;
            if ( v162 )
              (*(void (__fastcall **)(SSClassDescBase *))&v162->vfptr->gap8[8])(v162);
            AMemory::c_free_func(v161);
          }
        }
        AMemory::c_free_func(v158);
        if ( v187.i_result_type_p.i_obj_p )
          (*(void (__fastcall **)(SSClassDescBase *))&v187.i_result_type_p.i_obj_p->vfptr->gap8[8])(v187.i_result_type_p.i_obj_p);
        p_i_return_params = &v187.i_return_params;
        AMemory::c_free_func(v187.i_return_params.i_array_p);
        p_i_return_params = &v187.i_params;
        AMemory::c_free_func(v187.i_params.i_array_p);
        if ( v145->i_params_p.i_obj_p != v154 )
        {
          if ( v154 )
            ++v154->i_ref_count;
          v163 = v145->i_params_p.i_obj_p;
          if ( v163 )
          {
            v104 = v163->i_ref_count-- == 1;
            if ( v104 )
            {
              v163->i_ref_count = 0x80000000;
              p_i_return_params = v163;
              v164 = (char *)v163->i_params.i_array_p;
              v165 = v164;
              v166 = &v164[8 * v163->i_params.i_count];
              v163->i_params.i_array_p = 0i64;
              v163->i_params.i_count = 0;
              if ( v164 < v166 )
              {
                do
                {
                  if ( *(_QWORD *)v165 )
                    (***(void (__fastcall ****)(_QWORD, __int64))v165)(*(_QWORD *)v165, 1i64);
                  v165 += 8;
                }
                while ( v165 < v166 );
              }
              AMemory::c_free_func(v164);
              APCompactArrayBase<SSTypedName>::free_all(&v163->i_return_params);
              v167 = v163->i_result_type_p.i_obj_p;
              if ( v167 )
                (*(void (__fastcall **)(SSClassDescBase *))&v167->vfptr->gap8[8])(v167);
              v185 = (SSTypedData *)&v163->i_return_params;
              AMemory::c_free_func(v163->i_return_params.i_array_p);
              p_i_return_params = &v163->i_params;
              AMemory::c_free_func(v163->i_params.i_array_p);
              AMemory::c_free_func(v163);
              v81 = (const void **)sym_binary_pp;
            }
          }
          v145->i_params_p.i_obj_p = v154;
        }
        v145->vfptr = (SSInvokableBaseVtbl *)&SSMethod::`vftable;
        v168 = *(unsigned __int8 *)*v81;
        v169 = (__int64)*v81 + 1;
        *v81 = (const void *)v169;
        if ( v168 )
        {
          *v81 = (const void *)(v169 + 2);
          v170 = SSExpressionBase::from_binary_new(v168, v81);
        }
        else
        {
          v170 = 0i64;
        }
        v145[1].vfptr = (SSInvokableBaseVtbl *)v170;
        p_i_class_methods = *(APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > **)&v182[0].i_uid;
        v137 = name.i_uid;
        v134 = v192;
      }
      else
      {
        v145 = 0i64;
      }
    }
    APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::append(p_i_class_methods, v145, 0i64);
    --v137;
  }
  v171 = *(_DWORD *)*v81;
  *v81 = (char *)*v81 + 4;
  if ( v134->i_coroutines.i_size < v171 )
  {
    v134->i_coroutines.i_size = AMemory::c_req_byte_size_func(8 * v171) >> 3;
    AMemory::c_free_func(v134->i_coroutines.i_array_p);
    v134->i_coroutines.i_array_p = APArrayBase<SSCoroutineBase>::alloc_array(v134->i_coroutines.i_size);
  }
  for ( v134->i_coroutines.i_count = 0; v171; --v171 )
  {
    v172 = *(unsigned __int8 *)*v81;
    *v81 = (char *)*v81 + 1;
    name.i_uid = ASymbol::create_from_binary((ASymbol *)&v192, v81)->i_uid;
    if ( v172 == 3 )
    {
      v176 = (SSCoroutineBase *)AMemory::c_malloc_func(0x28ui64, "SSCoroutine");
      v174 = v176;
      sym_binary_pp = (void **)&v176->vfptr;
      if ( v176 )
      {
        SSCoroutineBase::SSCoroutineBase(v176, &name, v134, v81);
        v174->vfptr = (SSInvokableBaseVtbl *)&SSCoroutine::`vftable;
        v177 = *(unsigned __int8 *)*v81;
        v178 = (__int64)*v81 + 1;
        *v81 = (const void *)v178;
        if ( v177 )
        {
          *v81 = (const void *)(v178 + 2);
          v179 = SSExpressionBase::from_binary_new(v177, v81);
        }
        else
        {
          v179 = 0i64;
        }
        v174[1].vfptr = (SSInvokableBaseVtbl *)v179;
      }
      else
      {
        v174 = 0i64;
      }
    }
    else if ( v172 == 5 )
    {
      v175 = (SSCoroutineBase *)AMemory::c_malloc_func(0x30ui64, "SSCoroutineMthd");
      v174 = v175;
      sym_binary_pp = (void **)&v175->vfptr;
      if ( v175 )
      {
        SSCoroutineBase::SSCoroutineBase(v175, &name, v134, v81);
        v174->vfptr = (SSInvokableBaseVtbl *)&SSCoroutineMthd::`vftable;
        tclass.i_ref_count = 0;
        v174[1].vfptr = 0i64;
        *(_QWORD *)&v174[1].i_name.i_uid = *(_QWORD *)&tclass.i_ref_count;
      }
      else
      {
        v174 = 0i64;
      }
    }
    else
    {
      v173 = (SSCoroutineBase *)AMemory::c_malloc_func(0x28ui64, "SSCoroutineFunc");
      v174 = v173;
      sym_binary_pp = (void **)&v173->vfptr;
      if ( v173 )
      {
        SSCoroutineBase::SSCoroutineBase(v173, &name, v134, v81);
        v174->vfptr = (SSInvokableBaseVtbl *)&SSCoroutineFunc::`vftable;
        v174[1].vfptr = 0i64;
      }
      else
      {
        v174 = 0i64;
      }
    }
    APSorted<SSCoroutineBase,ASymbol,ACompareLogical<ASymbol>>::append(&v134->i_coroutines, v174, 0i64);
  }
  v134->i_flags &= ~8u;
  v134->i_flags |= 1u;
}bol>>::append(&v134->i_coroutines, v174, 0i64);
  }
  v134->i_flags &= ~8u;
  v134->i_flags |= 1u;
}

// File Line: 1749
// RVA: 0x116350
void __fastcall SSClass::from_binary_group(const void **binary_pp)
{
  int v2; // edi
  ASymbol *v3; // rax
  __int64 v4; // r8
  SSClass **i_array_p; // rdx
  unsigned int i_uid; // r10d
  SSClass **v7; // r9
  SSClass **v8; // rax
  SSClass *v9; // rcx
  ASymbol result; // [rsp+30h] [rbp+8h] BYREF

  v2 = *(_DWORD *)*binary_pp;
  for ( *binary_pp = (char *)*binary_pp + 4; v2; --v2 )
  {
    v3 = ASymbol::create_from_binary(&result, binary_pp);
    if ( SSBrain::c_classes.i_count )
    {
      i_array_p = SSBrain::c_classes.i_array_p;
      i_uid = v3->i_uid;
      v7 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1];
      while ( 1 )
      {
        while ( 1 )
        {
          v8 = &i_array_p[((char *)v7 - (char *)i_array_p) >> 4];
          v4 = (*v8)->i_name.i_uid;
          if ( i_uid >= (unsigned int)v4 )
            break;
          if ( i_array_p == v8 )
            goto LABEL_11;
          v7 = v8 - 1;
        }
        v4 = i_uid != (_DWORD)v4;
        if ( !v4 )
          break;
        if ( v7 == v8 )
          goto LABEL_11;
        i_array_p = v8 + 1;
      }
      v9 = *v8;
    }
    else
    {
LABEL_11:
      v9 = 0i64;
    }
    LOBYTE(v4) = 1;
    ((void (__fastcall *)(SSClass *, const void **, __int64))v9->vfptr[1].is_generic)(v9, binary_pp, v4);
  }
}

// File Line: 2055
// RVA: 0x11EC60
bool __fastcall SSClass::is_generic(SSClass *this)
{
  return this == SSBrain::c_this_class_p || this == SSBrain::c_item_class_p;
}

// File Line: 2069
// RVA: 0x10E9F0
SSClass *__fastcall SSClass::as_finalized_generic(SSClass *this, SSClassDescBase *scope_type)
{
  SSClassDescBase *v2; // rbx

  v2 = scope_type;
  if ( this == SSBrain::c_this_class_p )
  {
    if ( scope_type->vfptr->is_metaclass(scope_type) )
      return v2->vfptr->get_key_class(v2);
    return (SSClass *)v2;
  }
  else if ( this == SSBrain::c_item_class_p )
  {
    if ( scope_type->vfptr->get_class_type(scope_type) == SSClassType_typed_class )
      return (SSClass *)v2->vfptr->get_item_type(v2);
    else
      return SSBrain::c_object_class_p;
  }
  else
  {
    return this;
  }
}

// File Line: 2095
// RVA: 0x114DD0
SSClass *__fastcall SSClass::find_common_type(SSClass *this, SSClass *cls)
{
  SSClass *v3; // rbp
  SSClass *v5; // rdi
  int v6; // eax
  SSClassDescBaseVtbl *vfptr; // rdi
  SSClassUnaryBase *v8; // rax
  SSClass *result; // rax
  SSClass *i_object_ids_p; // rdi
  SSClass *i_superclass_p; // rcx
  SSClass *v12; // rcx

  v3 = 0i64;
  v5 = 0i64;
  v6 = cls->vfptr->get_class_type(cls);
  if ( !v6 )
  {
    v5 = cls;
    goto LABEL_18;
  }
  if ( v6 == 1 )
  {
    i_object_ids_p = (SSClass *)cls->i_object_ids_p;
    while ( this != i_object_ids_p )
    {
      i_superclass_p = i_object_ids_p->i_superclass_p;
      if ( i_superclass_p )
      {
        if ( SSClass::is_class(i_superclass_p, this) )
          break;
      }
      this = this->i_superclass_p;
      if ( !this )
        goto LABEL_15;
    }
    v3 = this;
LABEL_15:
    result = SSBrain::c_object_class_p;
    if ( v3 != SSBrain::c_object_class_p )
      return (SSClass *)&v3->i_metaclass;
  }
  else
  {
    if ( v6 <= 1 )
      goto LABEL_18;
    if ( v6 <= 3 )
    {
      v5 = cls->vfptr->get_key_class(cls);
      goto LABEL_18;
    }
    if ( v6 == 4 )
    {
      vfptr = this->vfptr;
      v8 = cls->vfptr->as_unary_class(cls);
      return (SSClass *)vfptr->find_common_type(this, v8);
    }
    else
    {
LABEL_18:
      while ( v5 != this )
      {
        v12 = this->i_superclass_p;
        if ( v12 )
        {
          if ( SSClass::is_class(v12, v5) )
            break;
        }
        v5 = v5->i_superclass_p;
        if ( !v5 )
          return v3;
      }
      return v5;
    }
  }
  return result;
}

// File Line: 2129
// RVA: 0x1178E0
SSClassDescBaseVtbl *__fastcall SSClass::get_data_type(SSClass *this, ASymbol *data_name, eSSScope *scope_p)
{
  SSTypedName *v6; // rax
  SSClassDescBaseVtbl *result; // rax

  v6 = APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(&this->i_data_table, data_name);
  if ( v6 )
  {
    if ( scope_p )
      *scope_p = SSScope_instance;
    return (SSClassDescBaseVtbl *)v6->i_type_p.i_obj_p;
  }
  else
  {
    result = (SSClassDescBaseVtbl *)APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
                                      (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&this->i_class_data_table,
                                      data_name);
    if ( result )
    {
      if ( scope_p )
        *scope_p = SSScope_class;
      return *(SSClassDescBaseVtbl **)result->gap8;
    }
  }
  return result;
}

// File Line: 2175
// RVA: 0x118150
SSMethodBase *__fastcall SSClass::get_method_inherited_receiver(
        SSClass *this,
        ASymbol *method_name,
        SSInstanceUnreffed **receiver_pp,
        SSInvokedBase *caller_p)
{
  SSMethodBase *instance_method_inherited; // r9
  SSClass *i_superclass_p; // rcx
  SSClass *v9; // rcx
  SSMethodBase *class_method_inherited; // rax
  SSInstanceUnreffed *v11; // rbx

  instance_method_inherited = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
                                &this->i_methods,
                                method_name);
  if ( !instance_method_inherited )
  {
    i_superclass_p = this->i_superclass_p;
    if ( i_superclass_p )
      instance_method_inherited = SSClass::get_instance_method_inherited(i_superclass_p, method_name);
  }
  if ( instance_method_inherited )
    return instance_method_inherited;
  instance_method_inherited = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
                                &this->i_class_methods,
                                method_name);
  if ( !instance_method_inherited )
  {
    v9 = this->i_superclass_p;
    if ( v9 )
      class_method_inherited = SSClass::get_class_method_inherited(v9, method_name);
    else
      class_method_inherited = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
                                 &SSBrain::c_object_class_p->i_methods,
                                 method_name);
    instance_method_inherited = class_method_inherited;
  }
  if ( instance_method_inherited )
  {
    if ( this == (SSClass *)-240i64 )
      v11 = 0i64;
    else
      v11 = &this->i_metaclass.SSInstanceUnreffed;
    *receiver_pp = v11;
    return instance_method_inherited;
  }
  return 0i64;
}

// File Line: 2457
// RVA: 0x11E7F0
bool __fastcall SSClass::is_class_type(SSClass *this, SSClass *type_p)
{
  eSSClassType v4; // eax
  __int32 v5; // eax
  __int32 v6; // eax
  SSClass *v8; // rdx
  SSClass *v9; // rcx
  SSClass *i_superclass_p; // rcx

  v4 = type_p->vfptr->get_class_type(type_p);
  if ( v4 == SSClassType_class )
  {
    if ( type_p == SSBrain::c_object_class_p )
      return 1;
    if ( type_p == this )
      return 1;
    i_superclass_p = this->i_superclass_p;
    if ( i_superclass_p )
    {
      if ( SSClass::is_class(i_superclass_p, type_p) )
        return 1;
    }
    return 0;
  }
  v5 = v4 - 1;
  if ( !v5 )
    return this == SSBrain::c_class_class_p && (SSClass *)type_p->i_object_ids_p == SSBrain::c_object_class_p;
  v6 = v5 - 1;
  if ( !v6 )
  {
    if ( *(SSClass **)&type_p->i_subclasses.i_count == SSBrain::c_object_class_p )
    {
      v8 = type_p->i_superclass_p;
      if ( v8 == this )
        return 1;
      v9 = this->i_superclass_p;
      if ( v9 )
      {
        if ( SSClass::is_class(v9, v8) )
          return 1;
      }
    }
    return 0;
  }
  return v6 == 2 && SSClassUnion::is_valid_param_for((SSClassUnion *)type_p, this);
}

// File Line: 2551
// RVA: 0x13B840
void __fastcall SSClass::register_method_func(
        SSClass *this,
        ASymbol *method_name,
        void (__fastcall *atomic_f)(SSInvokedMethod *, SSInstance **),
        eSSBindFlag flags)
{
  APSortedLogical<SSMethodBase,ASymbol> *p_i_class_methods; // rcx
  SSMethodBase *v7; // rax
  SSMethodFunc *v8; // rbx
  SSClass *i_scope_p; // r15
  SSParameters *i_obj_p; // rdi
  SSParameters *v11; // rsi
  bool v12; // zf

  if ( (flags & 1) != 0 )
    p_i_class_methods = &this->i_class_methods;
  else
    p_i_class_methods = &this->i_methods;
  v7 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(p_i_class_methods, method_name);
  v8 = (SSMethodFunc *)v7;
  if ( v7 )
  {
    if ( v7->vfptr->get_invoke_type(v7) == SSInvokable_method_func )
    {
      v8->i_atomic_f = atomic_f;
    }
    else
    {
      i_scope_p = v8->i_scope_p;
      i_obj_p = v8->i_params_p.i_obj_p;
      if ( i_obj_p )
        ++i_obj_p->i_ref_count;
      v11 = v8->i_params_p.i_obj_p;
      if ( v11 )
      {
        v12 = v11->i_ref_count-- == 1;
        if ( v12 )
        {
          v11->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v11);
          AMemory::c_free_func(v11);
        }
        v8->i_params_p.i_obj_p = 0i64;
      }
      SSMethodFunc::SSMethodFunc(v8, method_name, i_scope_p, i_obj_p, atomic_f);
      if ( i_obj_p )
      {
        v12 = i_obj_p->i_ref_count-- == 1;
        if ( v12 )
        {
          i_obj_p->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(i_obj_p);
          AMemory::c_free_func(i_obj_p);
        }
      }
    }
  }
}

// File Line: 2635
// RVA: 0x13B960
void __fastcall SSClass::register_method_func(
        SSClass *this,
        const char *method_name_p,
        void (__fastcall *atomic_f)(SSInvokedMethod *, SSInstance **),
        eSSBindFlag flags)
{
  ASymbol *v7; // rax
  ASymbol result; // [rsp+20h] [rbp-18h] BYREF

  v7 = ASymbol::create(&result, method_name_p, 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(this, v7, atomic_f, flags);
}

// File Line: 2658
// RVA: 0x13B940
void __fastcall SSClass::register_method_func(
        SSClass *this,
        ASymbol *method_name,
        void (__fastcall *atomic_f)(SSInvokedMethod *, SSInstance **),
        bool class_scope_b,
        bool rebind)
{
  SSClass::register_method_func(this, method_name, atomic_f, (eSSBindFlag)((rebind ? 2 : 0) | class_scope_b));
}

// File Line: 2682
// RVA: 0x13B9B0
void __fastcall SSClass::register_method_func(
        SSClass *this,
        const char *method_name_p,
        void (__fastcall *atomic_f)(SSInvokedMethod *, SSInstance **),
        bool class_scope_b,
        ASymbol rebind)
{
  bool v6; // cf
  int v8; // ebx
  ASymbol *v9; // rax

  v6 = LOBYTE(rebind.i_uid) != 0;
  LOBYTE(rebind.i_uid) = -LOBYTE(rebind.i_uid);
  v8 = (v6 ? 2 : 0) | class_scope_b;
  v9 = ASymbol::create(&rebind, method_name_p, 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(this, v9, atomic_f, (eSSBindFlag)v8);
}

// File Line: 2705
// RVA: 0x13BA10
void __fastcall SSClass::register_method_mthd(
        SSClass *this,
        ASymbol *method_name,
        SSInvokableBaseVtbl **atomic_m,
        eSSBindFlag flags)
{
  unsigned int i_count; // eax
  SSMethodBase *v6; // r9
  SSMethodBase **i_array_p; // rbx
  unsigned int i_uid; // r11d
  SSMethodBase **v9; // r10
  SSMethodBase **i; // rdx
  SSMethodBase **v11; // rcx
  unsigned int v12; // r8d
  _BOOL8 v13; // rax
  _BOOL8 v14; // r8
  unsigned int v15; // eax
  unsigned int v16; // r11d
  SSMethodBase **v17; // r10
  SSMethodBase **j; // rdx
  unsigned int v19; // r8d
  _BOOL8 v20; // rax
  _BOOL8 v21; // r8

  if ( (flags & 1) != 0 )
  {
    i_count = this->i_class_methods.i_count;
    v6 = 0i64;
    if ( i_count )
    {
      i_array_p = this->i_class_methods.i_array_p;
      i_uid = method_name->i_uid;
      v9 = &i_array_p[i_count - 1];
      for ( i = i_array_p; ; i = v11 + 1 )
      {
        while ( 1 )
        {
          v11 = &i[((char *)v9 - (char *)i) >> 4];
          v12 = (*v11)->i_name.i_uid;
          if ( i_uid >= v12 )
          {
            v13 = i_uid == v12;
            v14 = i_uid != v12;
            if ( 1 - v13 >= 0 )
              break;
          }
          if ( i == v11 )
            goto LABEL_21;
          v9 = v11 - 1;
        }
        if ( v14 <= 0 )
          goto LABEL_20;
        if ( v9 == v11 )
          break;
      }
    }
  }
  else
  {
    v15 = this->i_methods.i_count;
    v6 = 0i64;
    if ( v15 )
    {
      i_array_p = this->i_methods.i_array_p;
      v16 = method_name->i_uid;
      v17 = &i_array_p[v15 - 1];
      for ( j = i_array_p; ; j = v11 + 1 )
      {
        while ( 1 )
        {
          v11 = &j[((char *)v17 - (char *)j) >> 4];
          v19 = (*v11)->i_name.i_uid;
          if ( v16 >= v19 )
          {
            v20 = v16 == v19;
            v21 = v16 != v19;
            if ( 1 - v20 >= 0 )
              break;
          }
          if ( j == v11 )
            goto LABEL_21;
          v17 = v11 - 1;
        }
        if ( v21 <= 0 )
          break;
        if ( v17 == v11 )
          goto LABEL_21;
      }
LABEL_20:
      v6 = i_array_p[(unsigned int)(v11 - i_array_p)];
    }
  }
LABEL_21:
  if ( v6 )
  {
    v6[1].vfptr = *atomic_m;
    *(_QWORD *)&v6[1].i_name.i_uid = atomic_m[1];
  }
}

// File Line: 2774
// RVA: 0x13BB20
void __fastcall SSClass::register_method_mthd(
        SSClass *this,
        const char *method_name_p,
        void (__fastcall *atomic_m)(SSInstance *this, SSInvokedMethod *, SSInstance **),
        eSSBindFlag flags)
{
  ASymbol *v6; // rax
  __int128 v7; // [rsp+20h] [rbp-18h] BYREF
  ASymbol result; // [rsp+50h] [rbp+18h] BYREF

  v7 = *(_OWORD *)atomic_m;
  v6 = ASymbol::create(&result, method_name_p, 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_mthd(this, v6, (SSInvokableBaseVtbl **)&v7, flags);
}

// File Line: 2821
// RVA: 0x13BB70
void __fastcall SSClass::register_method_mthd(
        SSClass *this,
        const char *method_name_p,
        void (__fastcall *atomic_m)(SSInstance *this, SSInvokedMethod *, SSInstance **),
        bool class_scope_b,
        ASymbol rebind)
{
  __int128 v5; // xmm0
  bool v6; // cf
  int v8; // ebx
  ASymbol *v9; // rax
  __int128 v10; // [rsp+20h] [rbp-18h] BYREF

  v5 = *(_OWORD *)atomic_m;
  v6 = LOBYTE(rebind.i_uid) != 0;
  LOBYTE(rebind.i_uid) = -LOBYTE(rebind.i_uid);
  v10 = v5;
  v8 = (v6 ? 2 : 0) | class_scope_b;
  v9 = ASymbol::create(&rebind, method_name_p, 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_mthd(this, v9, (SSInvokableBaseVtbl **)&v10, (eSSBindFlag)v8);
}

// File Line: 2836
// RVA: 0x10DE40
void __fastcall SSClass::append_coroutine(SSClass *this, SSCoroutineBase *coroutine_p)
{
  SSCoroutineBase *appended; // rax

  coroutine_p->i_scope_p = this;
  appended = APSorted<SSCoroutineBase,ASymbol,ACompareLogical<ASymbol>>::append_replace(
               &this->i_coroutines,
               coroutine_p,
               0i64);
  if ( appended )
    appended->vfptr->__vecDelDtor(appended, 1u);
}

// File Line: 2863
// RVA: 0x13B6B0
void __fastcall SSClass::register_coroutine_func(
        SSClass *this,
        ASymbol *coroutine_name,
        bool (__fastcall *update_f)(SSInvokedCoroutine *),
        eSSBindFlag flags)
{
  SSMethodBase *v6; // rax
  SSCoroutineFunc *v7; // rdi
  SSClass *i_scope_p; // r14
  SSParameters *i_obj_p; // rbx
  SSParameters *v10; // rsi
  bool v11; // zf

  v6 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_coroutines,
         coroutine_name);
  v7 = (SSCoroutineFunc *)v6;
  if ( v6 )
  {
    if ( v6->vfptr->get_invoke_type(v6) == SSInvokable_coroutine_func )
    {
      v7->i_update_f = update_f;
    }
    else
    {
      i_scope_p = v7->i_scope_p;
      i_obj_p = v7->i_params_p.i_obj_p;
      if ( i_obj_p )
        ++i_obj_p->i_ref_count;
      v10 = v7->i_params_p.i_obj_p;
      if ( v10 )
      {
        v11 = v10->i_ref_count-- == 1;
        if ( v11 )
        {
          v10->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v10);
          AMemory::c_free_func(v10);
        }
        v7->i_params_p.i_obj_p = 0i64;
      }
      SSCoroutineFunc::SSCoroutineFunc(v7, coroutine_name, i_scope_p, i_obj_p, update_f);
      if ( i_obj_p )
      {
        v11 = i_obj_p->i_ref_count-- == 1;
        if ( v11 )
        {
          i_obj_p->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(i_obj_p);
          AMemory::c_free_func(i_obj_p);
        }
      }
    }
  }
}

// File Line: 2932
// RVA: 0x13B7A0
void __fastcall SSClass::register_coroutine_func(
        SSClass *this,
        const char *coroutine_name_p,
        bool (__fastcall *update_f)(SSInvokedCoroutine *),
        eSSBindFlag flags)
{
  ASymbol *v7; // rax
  ASymbol result; // [rsp+20h] [rbp-18h] BYREF

  v7 = ASymbol::create(&result, coroutine_name_p, 0xFFFFFFFF, ATerm_long);
  SSClass::register_coroutine_func(this, v7, update_f, flags);
}

// File Line: 3013
// RVA: 0x13B7F0
void __fastcall SSClass::register_coroutine_mthd(
        SSClass *this,
        const char *coroutine_name_p,
        bool (__fastcall *update_m)(SSInstance *this, SSInvokedCoroutine *),
        eSSBindFlag flags)
{
  ASymbol *v5; // rax
  SSMethodBase *v6; // rax
  __int128 v7; // [rsp+20h] [rbp-18h]
  ASymbol result; // [rsp+40h] [rbp+8h] BYREF

  v7 = *(_OWORD *)update_m;
  v5 = ASymbol::create(&result, coroutine_name_p, 0xFFFFFFFF, ATerm_long);
  v6 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_coroutines,
         v5);
  if ( v6 )
    *(_OWORD *)&v6[1].vfptr = v7;
}

// File Line: 3101
// RVA: 0x10DFC0
SSTypedName *__fastcall SSClass::append_instance_data(
        SSClass *this,
        ASymbol *name,
        SSClassDescBase *type_p,
        SSClass::eSubclass subclasses)
{
  SSTypedName *v8; // rdi
  SSClass **i_array_p; // rbx
  SSClass **i; // rsi

  v8 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
  if ( v8 )
  {
    v8->i_name = (ASymbol)name->i_uid;
    v8->i_type_p.i_obj_p = type_p;
    if ( type_p )
      (*(void (__fastcall **)(SSClassDescBase *))type_p->vfptr->gap8)(type_p);
  }
  else
  {
    v8 = 0i64;
  }
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(&this->i_data, v8, 0i64);
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(&this->i_data_table, v8, 0i64);
  if ( subclasses == Subclass_recurse )
  {
    i_array_p = this->i_subclasses.i_array_p;
    for ( i = &i_array_p[this->i_subclasses.i_count]; i_array_p < i; ++i_array_p )
      SSClass::recurse_instance_data(*i_array_p, v8);
  }
  return v8;
}

// File Line: 3131
// RVA: 0x10DD60
SSTypedData *__fastcall SSClass::append_class_data(
        SSClass *this,
        ASymbol *name,
        SSClassDescBase *type_p,
        SSClass::eSubclass subclasses)
{
  SSTypedData *v8; // rdi
  SSInstance *v9; // rbp
  SSClass **i_array_p; // rbx
  SSClass **i; // rsi

  v8 = (SSTypedData *)AMemory::c_malloc_func(0x18ui64, "SSTypedData");
  if ( v8 )
  {
    v9 = SSBrain::c_nil_p;
    v8->i_name = (ASymbol)name->i_uid;
    v8->i_type_p.i_obj_p = type_p;
    if ( type_p )
      (*(void (__fastcall **)(SSClassDescBase *))type_p->vfptr->gap8)(type_p);
    v8->i_data_p = v9;
  }
  else
  {
    v8 = 0i64;
  }
  APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol>>::append(&this->i_class_data, v8, 0i64);
  APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol>>::append(&this->i_class_data_table, v8, 0i64);
  if ( subclasses == Subclass_recurse )
  {
    i_array_p = this->i_subclasses.i_array_p;
    for ( i = &i_array_p[this->i_subclasses.i_count]; i_array_p < i; ++i_array_p )
      SSClass::recurse_class_data(*i_array_p, v8);
  }
  return v8;
}

// File Line: 3167
// RVA: 0x1151A0
SSClass *__fastcall SSClass::find_data_scope(SSClass *this, ASymbol *name, SSClassUnaryBase::ePath check_path)
{
  unsigned int i_count; // eax
  char v4; // bl
  SSTypedName **i_array_p; // r9
  unsigned int i_uid; // r10d
  SSTypedName **v9; // r8
  SSTypedName **v10; // rcx
  unsigned int v11; // edx
  unsigned int v12; // eax
  SSTypedData **v13; // rdx
  unsigned int v14; // r10d
  SSTypedData **v15; // r9
  SSTypedData **v16; // rcx
  unsigned int v17; // r8d
  SSClass *result; // rax
  SSClass *i_superclass_p; // rcx
  SSClass **v20; // rbx
  SSClass **v21; // rdi

  i_count = this->i_data.i_count;
  v4 = check_path;
  if ( i_count )
  {
    i_array_p = this->i_data.i_array_p;
    i_uid = name->i_uid;
    v9 = &i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v10 = &i_array_p[((char *)v9 - (char *)i_array_p) >> 4];
        v11 = (*v10)->i_name.i_uid;
        if ( i_uid >= v11 )
          break;
        if ( i_array_p == v10 )
          goto LABEL_9;
        v9 = v10 - 1;
      }
      if ( i_uid == v11 )
        return this;
      if ( v9 == v10 )
        goto LABEL_9;
      i_array_p = v10 + 1;
    }
  }
  else
  {
LABEL_9:
    v12 = this->i_class_data.i_count;
    if ( v12 )
    {
      v13 = this->i_class_data.i_array_p;
      v14 = name->i_uid;
      v15 = &v13[v12 - 1];
      while ( 1 )
      {
        while ( 1 )
        {
          v16 = &v13[((char *)v15 - (char *)v13) >> 4];
          v17 = (*v16)->i_name.i_uid;
          if ( v14 >= v17 )
            break;
          if ( v13 == v16 )
            goto LABEL_18;
          v15 = v16 - 1;
        }
        if ( v14 == v17 )
          return this;
        if ( v15 == v16 )
          break;
        v13 = v16 + 1;
      }
    }
LABEL_18:
    i_superclass_p = this->i_superclass_p;
    if ( !i_superclass_p
      || (v4 & 1) == 0
      || (result = (SSClass *)((__int64 (__fastcall *)(SSClass *, ASymbol *, __int64))i_superclass_p->vfptr[1].as_unary_class)(
                                i_superclass_p,
                                name,
                                1i64)) == 0i64 )
    {
      if ( (v4 & 2) != 0 && (v20 = this->i_subclasses.i_array_p, v21 = &v20[this->i_subclasses.i_count], v20 < v21) )
      {
        while ( 1 )
        {
          result = (SSClass *)((__int64 (__fastcall *)(SSClass *, ASymbol *, __int64))(*v20)->vfptr[1].as_unary_class)(
                                *v20,
                                name,
                                2i64);
          if ( result )
            break;
          if ( ++v20 >= v21 )
            return 0i64;
        }
      }
      else
      {
        return 0i64;
      }
    }
  }
  return result;
}

// File Line: 3215
// RVA: 0x131FD0
void __fastcall SSClass::recurse_instance_data(SSClass *this, SSTypedName *typed_p)
{
  SSClass **i_array_p; // rbx
  SSClass **i; // rdi

  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(&this->i_data_table, typed_p, 0i64);
  i_array_p = this->i_subclasses.i_array_p;
  for ( i = &i_array_p[this->i_subclasses.i_count]; i_array_p < i; ++i_array_p )
    SSClass::recurse_instance_data(*i_array_p, typed_p);
}

// File Line: 3236
// RVA: 0x131ED0
void __fastcall SSClass::recurse_class_data(SSClass *this, SSTypedData *data_p)
{
  SSClass **i_array_p; // rbx
  SSClass **i; // rdi

  APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol>>::append(&this->i_class_data_table, data_p, 0i64);
  i_array_p = this->i_subclasses.i_array_p;
  for ( i = &i_array_p[this->i_subclasses.i_count]; i_array_p < i; ++i_array_p )
    SSClass::recurse_class_data(*i_array_p, data_p);
}

// File Line: 3287
// RVA: 0x131DA0
void __fastcall SSClass::recurse_class_ctor(SSClass *this, SSInvokedMethod *imethod_p)
{
  __int64 i_count; // rax
  SSMethodBase **i_array_p; // r8
  SSMethodBase **v6; // r10
  unsigned int i_ptr_id; // r11d
  SSMethodBase **v8; // rdx
  unsigned int i_uid; // r9d
  SSMethodBase *v10; // rcx
  SSInstanceUnreffed *v11; // rax
  SSClass **v12; // rbx
  SSClass **i; // rsi

  if ( (this->i_flags & 1) != 0 )
  {
    i_count = this->i_class_methods.i_count;
    if ( (_DWORD)i_count )
    {
      i_array_p = this->i_class_methods.i_array_p;
      v6 = &i_array_p[i_count - 1];
      i_ptr_id = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v8 = &i_array_p[((char *)v6 - (char *)i_array_p) >> 4];
          i_uid = (*v8)->i_name.i_uid;
          if ( ASymbolX_ctor.i_uid >= i_uid )
            break;
          if ( i_array_p == v8 )
            goto LABEL_16;
          v6 = v8 - 1;
        }
        if ( ASymbolX_ctor.i_uid == i_uid )
          break;
        if ( v6 == v8 )
          goto LABEL_16;
        i_array_p = v8 + 1;
      }
      v10 = *v8;
      if ( *v8 )
      {
        v11 = &this->i_metaclass.SSInstanceUnreffed;
        if ( this == (SSClass *)-240i64 )
          v11 = 0i64;
        imethod_p->i_scope_p.i_obj_p = v11;
        if ( v11 )
          i_ptr_id = v11->i_ptr_id;
        imethod_p->i_scope_p.i_ptr_id = i_ptr_id;
        imethod_p->i_method_p = v10;
        ((void (__fastcall *)(SSMethodBase *, SSInvokedMethod *, _QWORD, _QWORD))v10->vfptr[1].get_custom_expr)(
          v10,
          imethod_p,
          0i64,
          0i64);
      }
    }
LABEL_16:
    v12 = this->i_subclasses.i_array_p;
    for ( i = &v12[this->i_subclasses.i_count]; v12 < i; ++v12 )
    {
      imethod_p->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
      ((void (__fastcall *)(SSClass *, SSInvokedMethod *))(*v12)->vfptr[1].get_key_class_name)(*v12, imethod_p);
    }
  }
}

// File Line: 3323
// RVA: 0x131F30
void __fastcall SSClass::recurse_class_dtor(SSClass *this)
{
  __int64 i_count; // rax
  SSClass **i_array_p; // rbx
  SSClass **i; // rsi
  SSTypedData **v5; // rbx
  SSTypedData **j; // rdi
  SSInstance *i_data_p; // rcx
  __int64 v9; // rcx

  if ( (this->i_flags & 1) != 0 )
  {
    i_count = this->i_subclasses.i_count;
    if ( (_DWORD)i_count )
    {
      i_array_p = this->i_subclasses.i_array_p;
      for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
        SSClass::recurse_class_dtor(*i_array_p);
    }
    v5 = this->i_class_data.i_array_p;
    for ( j = &v5[this->i_class_data.i_count]; v5 < j; *(_QWORD *)(v9 + 16) = SSBrain::c_nil_p )
    {
      i_data_p = (*v5)->i_data_p;
      if ( i_data_p->i_ref_count-- == 1 )
      {
        i_data_p->i_ref_count = 0x80000000;
        i_data_p->vfptr[1].get_scope_context(i_data_p);
      }
      v9 = (__int64)*v5++;
    }
  }
}

// File Line: 3352
// RVA: 0x13C630
void __fastcall SSClass::set_destructor(SSClass *this, SSMethodBase *destructor_p)
{
  SSMethodBase *i_destructor_p; // rax
  SSClass *i_scope_p; // rdx
  SSClass *v6; // rax
  SSClass *i_superclass_p; // rcx
  __int64 i_count; // rax
  SSClass **i_array_p; // rbx
  SSClass **i; // rsi

  i_destructor_p = this->i_destructor_p;
  if ( !i_destructor_p
    || (i_scope_p = i_destructor_p->i_scope_p, v6 = destructor_p->i_scope_p, i_scope_p == v6)
    || (i_superclass_p = v6->i_superclass_p) != 0i64 && SSClass::is_class(i_superclass_p, i_scope_p) )
  {
    i_count = this->i_subclasses.i_count;
    i_array_p = this->i_subclasses.i_array_p;
    this->i_destructor_p = destructor_p;
    for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
      SSClass::set_destructor(*i_array_p, destructor_p);
  }
}

// File Line: 3374
// RVA: 0x11E0E0
void __fastcall SSClass::invoke_class_ctor_recurse(SSClass *this)
{
  AObjReusePool<SSInvokedMethod> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v4; // eax
  __int64 v5; // rcx
  SSInvokedMethod **i_array_p; // rax
  SSInvokedMethod *v7; // rbx
  unsigned int v8; // eax

  pool = SSInvokedMethod::get_pool();
  if ( pool->i_pool.i_count )
  {
    v8 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v8;
    v5 = v8;
    i_array_p = pool->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !pool->i_exp_pool.i_count )
    AObjReusePool<SSInvokedMethod>::append_block(pool, pool->i_expand_size);
  i_count = pool->i_exp_pool.i_count;
  if ( i_count )
  {
    v4 = i_count - 1;
    pool->i_exp_pool.i_count = v4;
    v5 = v4;
    i_array_p = pool->i_exp_pool.i_array_p;
LABEL_8:
    v7 = i_array_p[v5];
    goto LABEL_9;
  }
  v7 = 0i64;
LABEL_9:
  v7->i_caller_p.i_obj_p = 0i64;
  v7->i_caller_p.i_ptr_id = 0;
  v7->i_scope_p.i_obj_p = 0i64;
  v7->i_scope_p.i_ptr_id = 0;
  v7->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  v7->i_method_p = 0i64;
  ((void (__fastcall *)(SSClass *, SSInvokedMethod *))this->vfptr[1].get_key_class_name)(this, v7);
  SSInvokedMethod::pool_delete(v7);
}

// File Line: 3406
// RVA: 0x113AA0
void __fastcall SSClass::demand_unload_recurse(SSClass *this)
{
  __int64 i_count; // rax
  SSClass **i_array_p; // rbx
  SSClass **i; // rdi

  i_count = this->i_subclasses.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = this->i_subclasses.i_array_p;
    for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
      SSClass::demand_unload_recurse(*i_array_p);
  }
  ((void (__fastcall *)(SSClass *))this->vfptr[1].is_class_type)(this);
}

// File Line: 3426
// RVA: 0x113A70
char __fastcall SSClass::demand_unload(SSClass *this)
{
  if ( (this->i_flags & 3) != 3 || (this->i_flags & 4) != 0 )
    return 0;
  SSClass::demand_unload_recurse(this);
  return 1;
}

// File Line: 3516
// RVA: 0x1461590
__int64 dynamic_initializer_for__SSClassUnion::c_shared_unions__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SSClassUnion::c_shared_unions__);
}

// File Line: 3531
// RVA: 0x112580
int __fastcall SSClassUnion::compare(SSClassUnion *this, SSClassUnion *class_union)
{
  int result; // eax
  __int64 i_count; // r8
  unsigned int v4; // r9d
  SSClassDescBase **i_array_p; // rbx
  SSClassDescBase **v6; // rsi
  SSClassDescBase **v7; // rdi

  if ( this == class_union )
    return 0;
  i_count = this->i_union.i_count;
  v4 = class_union->i_union.i_count;
  if ( (_DWORD)i_count == v4 )
  {
    i_array_p = this->i_union.i_array_p;
    v6 = &i_array_p[i_count];
    v7 = class_union->i_union.i_array_p;
    if ( i_array_p >= v6 )
    {
      return 0;
    }
    else
    {
      while ( 1 )
      {
        result = SSClassDescBase::compare(*i_array_p, *v7);
        if ( result )
          break;
        ++i_array_p;
        ++v7;
        if ( i_array_p >= v6 )
          return 0;
      }
    }
  }
  else
  {
    result = 1;
    if ( (unsigned int)i_count < v4 )
      return -1;
  }
  return result;
}

// File Line: 3580
// RVA: 0x11F930
void __fastcall SSClassUnion::merge_class(SSClassUnion *this, SSClassUnaryBase *new_class)
{
  SSClassDescBase **i_array_p; // rbx
  SSClassDescBase **v5; // rbp
  __int64 v6; // rsi
  SSClassUnaryBase **v7; // rax
  SSClassUnaryBase *v8; // rbx

  if ( this->i_common_class_p )
  {
    i_array_p = this->i_union.i_array_p;
    v5 = &i_array_p[this->i_union.i_count];
    if ( i_array_p >= v5 )
    {
LABEL_10:
      (*(void (__fastcall **)(SSClassUnaryBase *))new_class->vfptr->gap8)(new_class);
      APSorted<SSClassUnaryBase,SSClassUnaryBase,SSClassUnaryBase>::append(&this->i_union, new_class, 0i64);
      v8 = new_class->vfptr->find_common_type(new_class, this->i_common_class_p);
      (*(void (__fastcall **)(SSClassUnaryBase *))v8->vfptr->gap8)(v8);
      this->i_common_class_p->vfptr->dereference_delay(this->i_common_class_p);
      this->i_common_class_p = v8;
    }
    else
    {
      v6 = 0i64;
      while ( !new_class->vfptr->is_class_type(new_class, *i_array_p) )
      {
        if ( (*i_array_p)->vfptr->is_class_type(*i_array_p, new_class) )
        {
          v7 = this->i_union.i_array_p;
          memmove(
            &v7[(unsigned int)(v6 >> 3)],
            &v7[(unsigned int)(v6 >> 3) + 1],
            8i64 * (--this->i_union.i_count - (unsigned int)(v6 >> 3)));
          --v5;
        }
        else
        {
          ++i_array_p;
          v6 += 8i64;
        }
        if ( i_array_p >= v5 )
          goto LABEL_10;
      }
    }
  }
  else
  {
    (*(void (__fastcall **)(SSClassUnaryBase *))new_class->vfptr->gap8)(new_class);
    (*(void (__fastcall **)(SSClassUnaryBase *))new_class->vfptr->gap8)(new_class);
    APSorted<SSClassUnaryBase,SSClassUnaryBase,SSClassUnaryBase>::append(&this->i_union, new_class, 0i64);
    this->i_common_class_p = new_class;
  }
}

// File Line: 3645
// RVA: 0x11F890
void __fastcall SSClassUnion::merge_class(SSClassUnion *this, SSClassUnion *new_class)
{
  SSClassUnaryBase **i_array_p; // rbx
  SSClassUnaryBase **i; // rsi

  if ( new_class->vfptr->get_class_type(new_class) == SSClassType_class_union )
  {
    if ( new_class->i_common_class_p )
    {
      if ( this->i_common_class_p )
      {
        i_array_p = new_class->i_union.i_array_p;
        for ( i = &i_array_p[new_class->i_union.i_count]; i_array_p < i; ++i_array_p )
          SSClassUnion::merge_class(this, *i_array_p);
      }
      else
      {
        SSClassUnion::operator=(this, new_class);
      }
    }
  }
  else
  {
    SSClassUnion::merge_class(this, (SSClassUnaryBase *)new_class);
  }
}

// File Line: 3805
// RVA: 0x110FA0
void __fastcall SSClassUnion::assign_binary(SSClassUnion *this, const void **binary_pp)
{
  eSSClassType v4; // ecx
  SSClassDescBase *v5; // rax
  SSClassUnaryBase *v6; // rsi
  SSClassUnaryBase *i_common_class_p; // rcx
  __int64 v8; // rsi
  unsigned int v9; // eax
  SSClassUnaryBase **i_array_p; // rcx
  SSClassUnaryBase **i; // r14
  eSSClassType v12; // ecx
  SSClassDescBase *v13; // rbx

  v4 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  v5 = SSClassDescBase::from_binary_ref(v4, binary_pp);
  v6 = (SSClassUnaryBase *)v5;
  if ( v5 )
    (*(void (__fastcall **)(SSClassDescBase *))v5->vfptr->gap8)(v5);
  i_common_class_p = this->i_common_class_p;
  if ( i_common_class_p )
    i_common_class_p->vfptr->dereference_delay(i_common_class_p);
  this->i_common_class_p = v6;
  v8 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  if ( this->i_union.i_size < (unsigned int)v8 )
  {
    v9 = AMemory::c_req_byte_size_func(8 * v8);
    i_array_p = this->i_union.i_array_p;
    this->i_union.i_size = v9 >> 3;
    AMemory::c_free_func(i_array_p);
    this->i_union.i_array_p = APArrayBase<SSClassUnaryBase>::alloc_array(this->i_union.i_size);
  }
  memset(this->i_union.i_array_p, 0, 8 * v8);
  this->i_union.i_count = v8;
  for ( i = this->i_union.i_array_p; (_DWORD)v8; LODWORD(v8) = v8 - 1 )
  {
    v12 = *(unsigned __int8 *)*binary_pp;
    *binary_pp = (char *)*binary_pp + 1;
    v13 = SSClassDescBase::from_binary_ref(v12, binary_pp);
    (*(void (__fastcall **)(SSClassDescBase *))v13->vfptr->gap8)(v13);
    *i++ = (SSClassUnaryBase *)v13;
  }
}

// File Line: 3890
// RVA: 0x11EC80
char __fastcall SSClassUnion::is_generic(SSClassUnion *this)
{
  SSClassUnaryBase **i_array_p; // rbx
  SSClassUnaryBase **v2; // rdi

  i_array_p = this->i_union.i_array_p;
  v2 = &i_array_p[this->i_union.i_count];
  if ( i_array_p >= v2 )
    return 0;
  while ( !(*i_array_p)->vfptr->is_generic(*i_array_p) )
  {
    if ( ++i_array_p >= v2 )
      return 0;
  }
  return 1;
}

// File Line: 3916
// RVA: 0x10EA60
SSClassUnion *__fastcall SSClassUnion::as_finalized_generic(SSClassUnion *this, SSClassDescBase *scope_type)
{
  SSClassDescBase *v2; // rbx
  SSClassUnion *v3; // r13
  SSClassUnaryBase **i_array_p; // r15
  char v5; // r14
  SSClassUnaryBase **v6; // r13
  SSClassUnion *v7; // r12
  SSClassUnion *v8; // rdi
  SSClassUnaryBase **v9; // rbx
  SSClassUnaryBase **i; // rsi
  SSClassUnaryBase *i_common_class_p; // rsi
  __int64 *v12; // rbx
  SSClassUnaryBase **v13; // rdi
  __int64 *v15; // rbx
  SSClassUnaryBase **v16; // rdi
  SSClassUnion class_union; // [rsp+28h] [rbp-38h] BYREF

  v2 = scope_type;
  v3 = this;
  if ( !this->vfptr->is_generic(this) )
    return v3;
  class_union.i_ref_count = 0;
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
  class_union.i_common_class_p = 0i64;
  class_union.i_union.i_count = 0;
  class_union.i_union.i_array_p = 0i64;
  class_union.i_union.i_size = 0;
  i_array_p = v3->i_union.i_array_p;
  v5 = 0;
  if ( i_array_p >= &i_array_p[v3->i_union.i_count] )
    goto LABEL_26;
  v6 = &i_array_p[v3->i_union.i_count];
  do
  {
    v7 = (SSClassUnion *)*i_array_p;
    v8 = (SSClassUnion *)(*i_array_p)->vfptr->as_finalized_generic(*i_array_p, v2);
    if ( v8->vfptr->get_class_type(v8) == SSClassType_class_union )
    {
      if ( v8->i_common_class_p )
      {
        if ( class_union.i_common_class_p )
        {
          v9 = v8->i_union.i_array_p;
          for ( i = &v9[v8->i_union.i_count]; v9 < i; ++v9 )
            SSClassUnion::merge_class(&class_union, *v9);
          v2 = scope_type;
        }
        else
        {
          SSClassUnion::operator=(&class_union, v8);
        }
      }
    }
    else
    {
      SSClassUnion::merge_class(&class_union, (SSClassUnaryBase *)v8);
    }
    if ( v7 != v8 )
      v5 = 1;
    ++i_array_p;
  }
  while ( i_array_p < v6 );
  v3 = this;
  if ( !v5 )
  {
LABEL_26:
    class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
    if ( class_union.i_common_class_p )
      class_union.i_common_class_p->vfptr->dereference_delay(class_union.i_common_class_p);
    if ( class_union.i_union.i_count )
    {
      v15 = (__int64 *)class_union.i_union.i_array_p;
      v16 = &class_union.i_union.i_array_p[class_union.i_union.i_count];
      if ( class_union.i_union.i_array_p < v16 )
      {
        do
           SSClassDescBase::`vcall{24,{flat}}(*v15++);
        while ( v15 < (__int64 *)v16 );
      }
    }
    AMemory::c_free_func(class_union.i_union.i_array_p);
    class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
    return v3;
  }
  if ( class_union.i_union.i_count > 1 )
    i_common_class_p = (SSClassUnaryBase *)SSClassUnion::get_or_create(&class_union);
  else
    i_common_class_p = class_union.i_common_class_p;
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
  if ( class_union.i_common_class_p )
    class_union.i_common_class_p->vfptr->dereference_delay(class_union.i_common_class_p);
  if ( class_union.i_union.i_count )
  {
    v12 = (__int64 *)class_union.i_union.i_array_p;
    v13 = &class_union.i_union.i_array_p[class_union.i_union.i_count];
    if ( class_union.i_union.i_array_p < v13 )
    {
      do
         SSClassDescBase::`vcall{24,{flat}}(*v12++);
      while ( v12 < (__int64 *)v13 );
    }
  }
  AMemory::c_free_func(class_union.i_union.i_array_p);
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
  return (SSClassUnion *)i_common_class_p;
}

// File Line: 3958
// RVA: 0x114EC0
hkDataWorld *__fastcall ArrayOfTuplesImplementation::View::getWorld(ArrayOfTuplesImplementation::View *this)
{
  return (hkDataWorld *)((__int64 (__fastcall *)(ArrayOfTuplesImplementation *))this->m_owner->vfptr[7].__vecDelDtor)(this->m_owner);
}

// File Line: 4003
// RVA: 0x11E760
char __fastcall SSClassUnion::is_class_maybe(SSClassUnion *this, SSClassDescBase *type_p)
{
  SSClassUnaryBase **i_array_p; // rbx
  SSClassUnaryBase **v4; // rdi

  i_array_p = this->i_union.i_array_p;
  v4 = &i_array_p[this->i_union.i_count];
  if ( i_array_p >= v4 )
    return 0;
  while ( !(*i_array_p)->vfptr->is_class_type(*i_array_p, type_p) )
  {
    if ( ++i_array_p >= v4 )
      return 0;
  }
  return 1;
}

// File Line: 4025
// RVA: 0x11F790
char __fastcall SSClassUnion::is_valid_param_for(SSClassUnion *this, SSClassDescBase *arg_type_p)
{
  SSClassDescBase **i_array_p; // rbx
  SSClassDescBase **v4; // rdi

  i_array_p = this->i_union.i_array_p;
  v4 = &i_array_p[this->i_union.i_count];
  if ( i_array_p >= v4 )
    return 0;
  while ( !arg_type_p->vfptr->is_class_type(arg_type_p, *i_array_p) )
  {
    if ( ++i_array_p >= v4 )
      return 0;
  }
  return 1;
}

// File Line: 4049
// RVA: 0x11E8D0
char __fastcall SSClassUnion::is_class_type(SSClassUnion *this, SSClassDescBase *type_p)
{
  SSClassUnaryBase **i_array_p; // rbx
  SSClassUnaryBase **v4; // rdi

  i_array_p = this->i_union.i_array_p;
  v4 = &i_array_p[this->i_union.i_count];
  if ( i_array_p >= v4 )
    return 1;
  while ( (*i_array_p)->vfptr->is_class_type(*i_array_p, type_p) )
  {
    if ( ++i_array_p >= v4 )
      return 1;
  }
  return 0;
}

// File Line: 4077
// RVA: 0x117B40
SSClassUnaryBase *__fastcall SSClassUnion::get_merge(SSClassUnion *class1, SSClassUnion *class2)
{
  SSClassUnaryBase **i_array_p; // rbx
  SSClassUnaryBase **i; // rsi
  SSClassUnaryBase *i_common_class_p; // r15
  __int64 *v7; // rbx
  SSClassUnaryBase **v8; // rsi
  SSClassUnion class_union; // [rsp+28h] [rbp-38h] BYREF

  class_union.i_ref_count = 0;
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
  class_union.i_common_class_p = 0i64;
  class_union.i_union.i_count = 0;
  class_union.i_union.i_array_p = 0i64;
  class_union.i_union.i_size = 0;
  if ( class1->vfptr->get_class_type(class1) == SSClassType_class_union )
  {
    if ( class1->i_common_class_p )
      SSClassUnion::operator=(&class_union, class1);
  }
  else
  {
    SSClassUnion::merge_class(&class_union, (SSClassUnaryBase *)class1);
  }
  (*(void (__fastcall **)(SSClassUnion *))class1->vfptr->gap8)(class1);
  (*(void (__fastcall **)(SSClassUnion *))class2->vfptr->gap8)(class2);
  if ( class2->vfptr->get_class_type(class2) == SSClassType_class_union )
  {
    if ( class2->i_common_class_p )
    {
      if ( class_union.i_common_class_p )
      {
        i_array_p = class2->i_union.i_array_p;
        for ( i = &i_array_p[class2->i_union.i_count]; i_array_p < i; ++i_array_p )
          SSClassUnion::merge_class(&class_union, *i_array_p);
      }
      else
      {
        SSClassUnion::operator=(&class_union, class2);
      }
    }
  }
  else
  {
    SSClassUnion::merge_class(&class_union, (SSClassUnaryBase *)class2);
  }
  if ( class_union.i_union.i_count > 1 )
    i_common_class_p = (SSClassUnaryBase *)SSClassUnion::get_or_create(&class_union);
  else
    i_common_class_p = class_union.i_common_class_p;
  if ( class_union.i_union.i_count )
  {
    v7 = (__int64 *)class_union.i_union.i_array_p;
    v8 = &class_union.i_union.i_array_p[class_union.i_union.i_count];
    if ( class_union.i_union.i_array_p < v8 )
    {
      do
         SSClassDescBase::`vcall{24,{flat}}(*v7++);
      while ( v7 < (__int64 *)v8 );
    }
  }
  class_union.i_union.i_count = 0;
  if ( class_union.i_common_class_p )
    class_union.i_common_class_p->vfptr->dereference_delay(class_union.i_common_class_p);
  class_union.i_common_class_p = 0i64;
  class1->vfptr->dereference_delay(class1);
  class2->vfptr->dereference_delay(class2);
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
  AMemory::c_free_func(class_union.i_union.i_array_p);
  return i_common_class_p;
}

// File Line: 4115
// RVA: 0x117CE0
SSClass *__fastcall SSClassUnion::get_merge(APArrayBase<SSClassDescBase> *classes, __int64 object_on_empty_b)
{
  __int64 i_count; // r8
  SSClassDescBase **i_array_p; // rsi
  SSClassDescBase **v5; // r13
  SSClassUnaryBase *v6; // rbx
  SSClassUnaryBase **v7; // r15
  SSClassUnion **v8; // rsi
  SSClassUnion *v9; // rdi
  SSClassUnaryBase **v10; // rbx
  SSClassUnaryBase **i; // rdi
  SSClassUnaryBase *i_common_class_p; // rsi
  __int64 *v13; // rbx
  SSClassUnaryBase **v14; // rdi
  __int64 v15; // rax
  __int64 *v16; // rbx
  __int64 *j; // rdi
  __int64 v19; // r14
  SSClassUnion class_union; // [rsp+28h] [rbp-38h] BYREF

  i_count = classes->i_count;
  switch ( (_DWORD)i_count )
  {
    case 0:
      v19 = 0i64;
      if ( (_BYTE)object_on_empty_b )
        return SSBrain::c_object_class_p;
      return (SSClass *)v19;
    case 1:
      return (SSClass *)*classes->i_array_p;
    case 2:
      return (SSClass *)SSClassUnion::get_merge(
                          *(SSClassUnion **)classes->i_array_p,
                          *((SSClassUnion **)classes->i_array_p + 1));
  }
  i_array_p = classes->i_array_p;
  v5 = &i_array_p[i_count];
  v6 = (SSClassUnaryBase *)*i_array_p;
  class_union.i_ref_count = 0;
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
  class_union.i_common_class_p = 0i64;
  class_union.i_union.i_count = 0;
  v7 = 0i64;
  class_union.i_union.i_array_p = 0i64;
  class_union.i_union.i_size = 0;
  if ( ((unsigned int (__fastcall *)(SSClassUnaryBase *, __int64))v6->vfptr->get_class_type)(v6, object_on_empty_b) != 4 )
  {
    SSClassUnion::merge_class(&class_union, v6);
LABEL_8:
    v7 = class_union.i_union.i_array_p;
    goto LABEL_9;
  }
  if ( v6[2].vfptr )
  {
    SSClassUnion::operator=(&class_union, (SSClassUnion *)v6);
    goto LABEL_8;
  }
LABEL_9:
  (*(void (__fastcall **)(SSClassDescBase *))(*i_array_p)->vfptr->gap8)(*i_array_p);
  v8 = (SSClassUnion **)(i_array_p + 1);
  if ( v8 < v5 )
  {
    do
    {
      (*(void (__fastcall **)(SSClassUnion *))(*v8)->vfptr->gap8)(*v8);
      v9 = *v8;
      if ( (*v8)->vfptr->get_class_type(*v8) == SSClassType_class_union )
      {
        if ( v9->i_common_class_p )
        {
          if ( class_union.i_common_class_p )
          {
            v10 = v9->i_union.i_array_p;
            for ( i = &v10[v9->i_union.i_count]; v10 < i; ++v10 )
              SSClassUnion::merge_class(&class_union, *v10);
          }
          else
          {
            SSClassUnion::operator=(&class_union, v9);
          }
        }
      }
      else
      {
        SSClassUnion::merge_class(&class_union, (SSClassUnaryBase *)v9);
      }
      ++v8;
    }
    while ( v8 < v5 );
    v7 = class_union.i_union.i_array_p;
  }
  if ( class_union.i_union.i_count > 1 )
  {
    i_common_class_p = (SSClassUnaryBase *)SSClassUnion::get_or_create(&class_union);
    v7 = class_union.i_union.i_array_p;
  }
  else
  {
    i_common_class_p = class_union.i_common_class_p;
  }
  if ( class_union.i_union.i_count )
  {
    v13 = (__int64 *)v7;
    v14 = &v7[class_union.i_union.i_count];
    if ( v7 < v14 )
    {
      do
         SSClassDescBase::`vcall{24,{flat}}(*v13++);
      while ( v13 < (__int64 *)v14 );
    }
  }
  class_union.i_union.i_count = 0;
  if ( class_union.i_common_class_p )
    class_union.i_common_class_p->vfptr->dereference_delay(class_union.i_common_class_p);
  class_union.i_common_class_p = 0i64;
  v15 = classes->i_count;
  if ( (_DWORD)v15 )
  {
    v16 = (__int64 *)classes->i_array_p;
    for ( j = &v16[v15]; v16 < j; ++v16 )
       SSClassDescBase::`vcall{24,{flat}}(*v16);
  }
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
  AMemory::c_free_func(v7);
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
  return (SSClass *)i_common_class_p;
}

// File Line: 4175
// RVA: 0x119010
SSClassUnion *__fastcall SSClassUnion::get_reduced(SSClassUnion *class_union, SSClassUnaryBase *class_to_remove)
{
  unsigned int i_count; // eax
  SSClassUnaryBase **i_array_p; // rdi
  SSClassDescBase **v6; // rsi
  SSClassDescBase **v7; // rbx
  int v8; // eax
  __int64 v9; // rbx
  SSClassDescBase **v10; // rsi
  unsigned int v11; // edi
  __int64 v12; // rdx
  SSClass *merge; // rbx
  APArrayBase<SSClassDescBase> classes; // [rsp+28h] [rbp-20h] BYREF
  unsigned int v16; // [rsp+38h] [rbp-10h]

  i_count = class_union->i_union.i_count;
  if ( !i_count )
    return class_union;
  i_array_p = class_union->i_union.i_array_p;
  v6 = &i_array_p[i_count - 1];
  while ( 1 )
  {
    while ( 1 )
    {
      v7 = &i_array_p[((char *)v6 - (char *)i_array_p) >> 4];
      v8 = SSClassDescBase::compare(class_to_remove, *v7);
      if ( v8 >= 0 )
        break;
      if ( i_array_p == v7 )
        return class_union;
      v6 = v7 - 1;
    }
    if ( v8 <= 0 )
      break;
    if ( v6 == v7 )
      return class_union;
    i_array_p = (SSClassUnaryBase **)(v7 + 1);
  }
  v9 = (SSClassUnaryBase **)v7 - class_union->i_union.i_array_p;
  v10 = APArrayBase<SSClassUnaryBase>::alloc_array(class_union->i_union.i_count);
  v11 = class_union->i_union.i_count;
  classes.i_count = v11;
  classes.i_array_p = v10;
  v16 = v11;
  memmove(v10, class_union->i_union.i_array_p, 8i64 * v11);
  classes.i_count = v11 - 1;
  memmove(&v10[(unsigned int)v9], &v10[(unsigned int)v9 + 1], 8i64 * (v11 - 1 - (unsigned int)v9));
  LOBYTE(v12) = 1;
  merge = SSClassUnion::get_merge(&classes, v12);
  AMemory::c_free_func(v10);
  return (SSClassUnion *)merge;
}


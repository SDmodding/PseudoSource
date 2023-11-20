// File Line: 128
// RVA: 0x10EDB0
SSMetaClass *__fastcall SSMetaClass::as_finalized_generic(SSMetaClass *this, SSClassDescBase *scope_type)
{
  SSClass *v2; // rax
  SSClassDescBase *v3; // rbx
  __int64 v5; // rax

  v2 = this->i_class_info_p;
  v3 = scope_type;
  if ( v2 == SSBrain::c_this_class_p )
    return (SSMetaClass *)scope_type->vfptr->get_metaclass(scope_type);
  if ( v2 != SSBrain::c_item_class_p )
    return this;
  if ( scope_type->vfptr->get_class_type(scope_type) != 2 )
    return (SSMetaClass *)((__int64 (*)(void))SSBrain::c_object_class_p->vfptr->get_metaclass)();
  v5 = (__int64)v3->vfptr->get_item_type(v3);
  return (SSMetaClass *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v5 + 136i64))(v5);
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
SSClass *__fastcall SSMetaClass::find_common_class(SSMetaClass *this, SSClass *cls)
{
  SSClass *v2; // rdi
  SSClass *v3; // rbx
  SSClass *v4; // rcx
  SSClass *result; // rax

  v2 = this->i_class_info_p;
  v3 = cls;
  do
  {
    if ( v3 == v2 )
      break;
    v4 = v2->i_superclass_p;
    if ( v4 )
    {
      if ( SSClass::is_class(v4, v3) )
        break;
    }
    v3 = v3->i_superclass_p;
  }
  while ( v3 );
  result = SSBrain::c_object_class_p;
  if ( v3 != SSBrain::c_object_class_p )
    result = (SSClass *)((char *)v3 + 240);
  return result;
}

// File Line: 194
// RVA: 0x114FD0
SSClass *__fastcall SSMetaClass::find_common_type(SSMetaClass *this, SSClassDescBase *cls)
{
  SSMetaClass *v2; // rsi
  SSClass *v3; // rbx
  eSSClassType v4; // eax
  int v5; // eax
  bool v6; // zf
  SSClassDescBaseVtbl *v7; // rax
  SSClass *v8; // rdi
  SSClass *v9; // rcx
  SSClass *result; // rax
  SSClassDescBaseVtbl *v11; // rdi
  __int64 v12; // rax
  SSClass *v13; // rdi
  SSClass *v14; // rbx
  SSClass *v15; // rcx

  v2 = this;
  v3 = (SSClass *)cls;
  v4 = (unsigned int)cls->vfptr->get_class_type(cls);
  if ( v4 == SSClassType_class )
  {
LABEL_5:
    v8 = v2->i_class_info_p;
    do
    {
      if ( v3 == v8 )
        break;
      v9 = v8->i_superclass_p;
      if ( v9 )
      {
        if ( SSClass::is_class(v9, v3) )
          break;
      }
      v3 = v3->i_superclass_p;
    }
    while ( v3 );
    result = SSBrain::c_object_class_p;
    if ( v3 != SSBrain::c_object_class_p )
      result = (SSClass *)((char *)v3 + 240);
    return result;
  }
  v5 = v4 - 1;
  if ( v5 )
  {
    v6 = v5 == 3;
    v7 = v3->vfptr;
    if ( v6 )
    {
      v11 = v2->vfptr;
      v12 = (__int64)v7->as_unary_class((SSClassDescBase *)&v3->vfptr);
      return (SSClass *)v11->find_common_type((SSClassDescBase *)&v2->vfptr, (SSClassDescBase *)v12);
    }
    v3 = v7->get_key_class((SSClassDescBase *)&v3->vfptr);
    goto LABEL_5;
  }
  v13 = v2->i_class_info_p;
  v14 = (SSClass *)v3->i_object_ids_p;
  do
  {
    if ( v14 == v13 )
      break;
    v15 = v13->i_superclass_p;
    if ( v15 )
    {
      if ( SSClass::is_class(v15, v14) )
        break;
    }
    v14 = v14->i_superclass_p;
  }
  while ( v14 );
  return (SSClass *)v14->vfptr->get_metaclass((SSClassDescBase *)&v14->vfptr);
}

// File Line: 229
// RVA: 0x117980
SSClassDescBaseVtbl *__fastcall SSMetaClass::get_data_type(SSMetaClass *this, ASymbol *data_name, eSSScope *scope_p)
{
  eSSScope *v3; // rbx
  SSClassDescBaseVtbl *result; // rax

  v3 = scope_p;
  result = (SSClassDescBaseVtbl *)APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
                                    (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&this->i_class_info_p->i_class_data_table,
                                    data_name);
  if ( result )
  {
    if ( v3 )
      *v3 = 1;
    result = *(SSClassDescBaseVtbl **)result->gap8;
  }
  return result;
}

// File Line: 254
// RVA: 0x11E9E0
bool __fastcall SSMetaClass::is_class_type(SSMetaClass *this, SSClassDescBase *type_p)
{
  SSMetaClass *v2; // rdi
  SSClass *v3; // rbx
  eSSClassType v4; // eax
  int v5; // eax
  bool result; // al
  SSClass *v7; // rdx
  SSClass *v8; // rax
  SSClass *v9; // rcx

  v2 = this;
  v3 = (SSClass *)type_p;
  v4 = (unsigned int)type_p->vfptr->get_class_type(type_p);
  if ( v4 == SSClassType_class )
  {
    if ( v3 == SSBrain::c_object_class_p || v3 == SSBrain::c_class_class_p )
      return 1;
    return 0;
  }
  v5 = v4 - 1;
  if ( !v5 )
  {
    v7 = (SSClass *)v3->i_object_ids_p;
    if ( v7 == SSBrain::c_object_class_p )
      return 1;
    v8 = v2->i_class_info_p;
    if ( v7 == v8 )
      return 1;
    v9 = v8->i_superclass_p;
    if ( v9 )
    {
      if ( SSClass::is_class(v9, v7) )
        return 1;
    }
    return 0;
  }
  if ( v5 == 3 )
    result = SSClassUnion::is_valid_param_for((SSClassUnion *)v3, (SSClassDescBase *)&v2->vfptr);
  else
    result = 0;
  return result;
}

// File Line: 291
// RVA: 0x11ED30
bool __fastcall SSMetaClass::is_generic(SSMetaClass *this)
{
  SSClass *v1; // rax

  v1 = this->i_class_info_p;
  return v1 == SSBrain::c_this_class_p || v1 == SSBrain::c_item_class_p;
}

// File Line: 313
// RVA: 0x120060
void __fastcall SSMetaClass::method_invoke(SSMetaClass *this, SSMethodCall *mcall, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  unsigned __int64 v5; // rbx
  SSInvokedBase *v6; // r15
  SSObjectBase *v7; // r12
  SSMethodCall *v8; // rbp
  SSMetaClass *v9; // r14
  SSMethodBase *v10; // rdi
  SSClass *v11; // rcx
  ASymbol *v12; // rdx
  SSMethodBase *v13; // rax
  SSObjectBase *v14; // rdx
  SSInvokedMethod *v15; // rbx

  v5 = (unsigned __int64)mcall->i_scope_p;
  v6 = caller_p;
  v7 = scope_p;
  v8 = mcall;
  v9 = this;
  if ( !v5 )
    v5 = this->i_user_data2;
  v10 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
          (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)(v5 + 216),
          &mcall->i_name);
  if ( !v10 )
  {
    v11 = *(SSClass **)(v5 + 16);
    v12 = &v8->i_name;
    if ( v11 )
      v13 = SSClass::get_class_method_inherited(v11, v12);
    else
      v13 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
              (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&SSBrain::c_object_class_p->i_methods.i_count,
              v12);
    v10 = v13;
  }
  if ( v10 )
  {
    v14 = 0i64;
    if ( v9 != (SSMetaClass *)8 )
      v14 = (SSObjectBase *)v9;
    v15 = SSInvokedMethod::pool_new(v6, v14, v10);
    SSInvokedContextBase::data_append_args_exprs(
      (SSInvokedContextBase *)&v15->vfptr,
      (APArrayBase<SSExpressionBase> *)&v8->i_arguments.i_count,
      (SSInvokableBase *)&v10->vfptr,
      v7);
    ((void (__fastcall *)(SSMethodBase *, SSInvokedMethod *, SSInvokedBase *, SSInstance **))v10->vfptr[1].get_custom_expr)(
      v10,
      v15,
      v6,
      result_pp);
    SSInvokedContextBase::data_bind_return_args(
      (SSInvokedContextBase *)&v15->vfptr,
      (APArrayBase<SSIdentifier> *)&v8->i_return_args.i_count,
      (SSInvokableBase *)&v10->vfptr);
    SSInvokedMethod::pool_delete(v15);
  }
  else if ( result_pp )
  {
    *result_pp = SSBrain::c_nil_p;
  }
}

// File Line: 393
// RVA: 0x11FD60
void __fastcall SSMetaClass::method_call(SSMetaClass *this, ASymbol *method_name, SSInstance **args_pp, unsigned int arg_count, SSInstance **result_pp, SSInvokedBase *caller_p)
{
  unsigned __int64 v6; // rdi
  SSMetaClass *v7; // rbp
  unsigned int v8; // er14
  SSInstance **v9; // r15
  ASymbol *v10; // rbx
  SSMethodBase *v11; // rsi
  SSClass *v12; // rcx
  SSMethodBase *v13; // rax
  SSObjectBase *v14; // rdx
  SSInvokedMethod *v15; // rdi

  v6 = this->i_user_data2;
  v7 = this;
  v8 = arg_count;
  v9 = args_pp;
  v10 = method_name;
  v11 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
          (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)(v6 + 216),
          method_name);
  if ( !v11 )
  {
    v12 = *(SSClass **)(v6 + 16);
    if ( v12 )
      v13 = SSClass::get_class_method_inherited(v12, v10);
    else
      v13 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
              (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&SSBrain::c_object_class_p->i_methods.i_count,
              v10);
    v11 = v13;
  }
  v14 = 0i64;
  if ( v7 != (SSMetaClass *)8 )
    v14 = (SSObjectBase *)v7;
  v15 = SSInvokedMethod::pool_new(caller_p, v14, v11);
  SSInvokedContextBase::data_append_args((SSInvokedContextBase *)&v15->vfptr, v9, v8, (SSInvokableBase *)&v11->vfptr);
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
  SSInstance *result; // rax

  v2 = APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)(this->i_user_data2 + 192),
         name);
  if ( v2 )
    result = *(SSInstance **)&v2[1].i_name.i_uid;
  else
    result = SSBrain::c_nil_p;
  return result;
}

// File Line: 498
// RVA: 0x13C5D0
void __fastcall SSMetaClass::set_data_by_name(SSMetaClass *this, ASymbol *name, SSInstance *obj_p)
{
  SSInstance *v3; // rbx
  SSTypedName *v4; // rax
  _DWORD *v5; // rcx
  SSTypedName *v6; // rdi
  bool v7; // zf

  v3 = obj_p;
  v4 = APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)(this->i_user_data2 + 192),
         name);
  ++v3->i_ref_count;
  v5 = *(_DWORD **)&v4[1].i_name.i_uid;
  v6 = v4;
  v7 = v5[4]-- == 1;
  if ( v7 )
  {
    v5[4] = 2147483648;
    (*(void (**)(void))(*(_QWORD *)v5 + 112i64))();
    *(_QWORD *)&v6[1].i_name.i_uid = v3;
  }
  else
  {
    *(_QWORD *)&v4[1].i_name.i_uid = v3;
  }
}

// File Line: 571
// RVA: 0x1043F0
void __fastcall SSClass::SSClass(SSClass *this, ASymbol *name, SSClass *superclass_p, unsigned int flags)
{
  SSClass *v4; // rax
  APSortedLogical<SSClass,ASymbol> *v5; // [rsp+48h] [rbp+10h]
  APSortedLogical<SSTypedName,ASymbol> *v6; // [rsp+48h] [rbp+10h]
  APSortedLogical<SSTypedName,ASymbol> *v7; // [rsp+48h] [rbp+10h]
  APSortedLogical<SSMethodBase,ASymbol> *v8; // [rsp+48h] [rbp+10h]
  APSortedLogical<SSCoroutineBase,ASymbol> *v9; // [rsp+48h] [rbp+10h]
  APSortedLogical<SSTypedData,ASymbol> *v10; // [rsp+48h] [rbp+10h]
  APSortedLogical<SSTypedData,ASymbol> *v11; // [rsp+48h] [rbp+10h]
  APSortedLogical<SSMethodBase,ASymbol> *v12; // [rsp+48h] [rbp+10h]
  SSMetaClass *v13; // [rsp+48h] [rbp+10h]
  SSInstanceUnreffed *v14; // [rsp+50h] [rbp+18h]

  this->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable';
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassUnaryBase::`vftable';
  this->i_name = (ASymbol)name->i_uid;
  this->vfptr = (SSClassDescBaseVtbl *)&SSClass::`vftable';
  this->i_flags = flags;
  this->i_superclass_p = superclass_p;
  v5 = &this->i_subclasses;
  v5->i_count = 0;
  v5->i_array_p = 0i64;
  v5->i_size = 0;
  this->i_object_id_lookup_f = 0i64;
  this->i_object_ids_p = 0i64;
  v6 = &this->i_data;
  v6->i_count = 0;
  v6->i_array_p = 0i64;
  v6->i_size = 0;
  v7 = &this->i_data_table;
  v7->i_count = 0;
  v7->i_array_p = 0i64;
  v7->i_size = 0;
  v8 = &this->i_methods;
  v8->i_count = 0;
  v8->i_array_p = 0i64;
  v8->i_size = 0;
  this->i_destructor_p = 0i64;
  v9 = &this->i_coroutines;
  v9->i_count = 0;
  v9->i_array_p = 0i64;
  v9->i_size = 0;
  v10 = &this->i_class_data;
  v10->i_count = 0;
  v10->i_array_p = 0i64;
  v10->i_size = 0;
  v11 = &this->i_class_data_table;
  v11->i_count = 0;
  v11->i_array_p = 0i64;
  v11->i_size = 0;
  v12 = &this->i_class_methods;
  v12->i_count = 0;
  v12->i_array_p = 0i64;
  v12->i_size = 0;
  v13 = &this->i_metaclass;
  v13->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable';
  v13->vfptr = (SSClassDescBaseVtbl *)&SSClassUnaryBase::`vftable';
  v4 = SSBrain::c_class_class_p;
  v14 = (SSInstanceUnreffed *)&this->i_metaclass.vfptr;
  v14->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable';
  v13->i_ref_count = 0;
  v14->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable';
  v13->i_class_p = v4;
  v13->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  v14->vfptr = (SSObjectBaseVtbl *)&SSInstanceUnreffed::`vftable';
  v13->i_ref_count = 1000000;
  v13->vfptr = (SSClassDescBaseVtbl *)&SSMetaClass::`vftable'{for `SSClassUnaryBase'};
  v14->vfptr = (SSObjectBaseVtbl *)&SSMetaClass::`vftable'{for `SSInstanceUnreffed'};
  this->i_metaclass.i_class_info_p = 0i64;
  this->i_metaclass.i_class_info_p = this;
  if ( superclass_p )
    APSorted<SSClass,ASymbol,ACompareLogical<ASymbol>>::append_absent(
      (APSorted<SSClass,ASymbol,ACompareLogical<ASymbol> > *)&superclass_p->i_subclasses.i_count,
      this,
      0i64);
}

// File Line: 591
// RVA: 0x106BD0
void __fastcall SSClass::~SSClass(SSClass *this)
{
  SSClass *v1; // rbx
  signed __int64 v2; // rcx
  SSInstanceUnreffed *v3; // [rsp+50h] [rbp+18h]

  v1 = this;
  this->vfptr = (SSClassDescBaseVtbl *)&SSClass::`vftable';
  SSClass::clear_members(this);
  v2 = (signed __int64)&v1->i_metaclass;
  v3 = (SSInstanceUnreffed *)&v1->i_metaclass.vfptr;
  v3->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable';
  *(_DWORD *)(v2 + 16) = 0;
  v3->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable';
  *(_QWORD *)v2 = &SSClassDescBase::`vftable';
  AMemory::c_free_func(v1->i_class_methods.i_array_p);
  AMemory::c_free_func(v1->i_class_data_table.i_array_p);
  AMemory::c_free_func(v1->i_class_data.i_array_p);
  AMemory::c_free_func(v1->i_coroutines.i_array_p);
  AMemory::c_free_func(v1->i_methods.i_array_p);
  AMemory::c_free_func(v1->i_data_table.i_array_p);
  AMemory::c_free_func(v1->i_data.i_array_p);
  AMemory::c_free_func(v1->i_subclasses.i_array_p);
  v1->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable';
}

// File Line: 600
// RVA: 0x112120
void __fastcall SSClass::clear_members(SSClass *this)
{
  SSClass *v1; // rdi
  APSizedArrayBase<SSTypedName> *v2; // rcx
  SSMethodBase **v3; // rbx
  __int64 v4; // rax
  unsigned __int64 i; // rsi
  SSMethodBase **v6; // rbx
  __int64 v7; // rax
  unsigned __int64 j; // rsi
  SSCoroutineBase **v9; // rbx
  __int64 v10; // rax
  unsigned __int64 k; // rsi

  v1 = this;
  v2 = (APSizedArrayBase<SSTypedName> *)&this->i_data.i_count;
  v2[1].i_count = 0;
  APSizedArrayBase<SSTypedName>::free_all(v2);
  v1->i_class_data_table.i_count = 0;
  SSTypedData::empty_table(&v1->i_class_data);
  v3 = v1->i_methods.i_array_p;
  v4 = v1->i_methods.i_count;
  v1->i_methods.i_count = 0;
  for ( i = (unsigned __int64)&v3[v4]; (unsigned __int64)v3 < i; ++v3 )
  {
    if ( *v3 )
      (*v3)->vfptr->__vecDelDtor((SSInvokableBase *)&(*v3)->vfptr, 1u);
  }
  v6 = v1->i_class_methods.i_array_p;
  v7 = v1->i_class_methods.i_count;
  v1->i_class_methods.i_count = 0;
  for ( j = (unsigned __int64)&v6[v7]; (unsigned __int64)v6 < j; ++v6 )
  {
    if ( *v6 )
      (*v6)->vfptr->__vecDelDtor((SSInvokableBase *)&(*v6)->vfptr, 1u);
  }
  v9 = v1->i_coroutines.i_array_p;
  v10 = v1->i_coroutines.i_count;
  v1->i_coroutines.i_count = 0;
  for ( k = (unsigned __int64)&v9[v10]; (unsigned __int64)v9 < k; ++v9 )
  {
    if ( *v9 )
      (*v9)->vfptr->__vecDelDtor((SSInvokableBase *)&(*v9)->vfptr, 1u);
  }
  v1->i_flags &= 0xFFFFFFF6;
  v1->i_destructor_p = 0i64;
}

// File Line: 623
// RVA: 0x112220
void __fastcall SSClass::clear_members_compact(SSClass *this)
{
  SSClass *v1; // rdi
  APSortedLogical<SSTypedData,ASymbol> *v2; // rsi
  SSMethodBase **v3; // rbx
  unsigned __int64 v4; // rbp
  SSMethodBase **v5; // rbx
  unsigned __int64 v6; // rbp
  SSCoroutineBase **v7; // rbx
  unsigned __int64 v8; // rsi

  v1 = this;
  AMemory::c_free_func(this->i_data_table.i_array_p);
  v1->i_data_table.i_array_p = 0i64;
  v1->i_data_table.i_count = 0;
  v1->i_data_table.i_size = 0;
  APSizedArrayBase<SSTypedName>::free_all((APSizedArrayBase<SSTypedName> *)&v1->i_data.i_count);
  AMemory::c_free_func(v1->i_data.i_array_p);
  v1->i_data.i_array_p = 0i64;
  v1->i_data.i_count = 0;
  v1->i_data.i_size = 0;
  AMemory::c_free_func(v1->i_class_data_table.i_array_p);
  v2 = &v1->i_class_data;
  v1->i_class_data_table.i_array_p = 0i64;
  v1->i_class_data_table.i_count = 0;
  v1->i_class_data_table.i_size = 0;
  SSTypedData::empty_table(&v1->i_class_data);
  AMemory::c_free_func(v1->i_class_data.i_array_p);
  v1->i_class_data.i_array_p = 0i64;
  v1->i_class_data.i_count = 0;
  v1->i_class_data.i_size = 0;
  v3 = v1->i_methods.i_array_p;
  v4 = (unsigned __int64)&v3[v1->i_methods.i_count];
  for ( v1->i_methods.i_count = 0; (unsigned __int64)v3 < v4; ++v3 )
  {
    if ( *v3 )
      (*v3)->vfptr->__vecDelDtor((SSInvokableBase *)&(*v3)->vfptr, 1u);
  }
  AMemory::c_free_func(v1->i_class_data.i_array_p);
  v1->i_class_data.i_array_p = 0i64;
  v2->i_count = 0;
  v1->i_class_data.i_size = 0;
  v5 = v1->i_class_methods.i_array_p;
  v6 = (unsigned __int64)&v5[v1->i_class_methods.i_count];
  for ( v1->i_class_methods.i_count = 0; (unsigned __int64)v5 < v6; ++v5 )
  {
    if ( *v5 )
      (*v5)->vfptr->__vecDelDtor((SSInvokableBase *)&(*v5)->vfptr, 1u);
  }
  AMemory::c_free_func(v1->i_class_data.i_array_p);
  v1->i_class_data.i_array_p = 0i64;
  v2->i_count = 0;
  v1->i_class_data.i_size = 0;
  v7 = v1->i_coroutines.i_array_p;
  v8 = (unsigned __int64)&v7[v1->i_coroutines.i_count];
  for ( v1->i_coroutines.i_count = 0; (unsigned __int64)v7 < v8; ++v7 )
  {
    if ( *v7 )
      (*v7)->vfptr->__vecDelDtor((SSInvokableBase *)&(*v7)->vfptr, 1u);
  }
  AMemory::c_free_func(v1->i_coroutines.i_array_p);
  v1->i_coroutines.i_array_p = 0i64;
  v1->i_coroutines.i_count = 0;
  v1->i_coroutines.i_size = 0;
  v1->i_flags &= 0xFFFFFFF6;
  v1->i_destructor_p = 0i64;
}

// File Line: 652
// RVA: 0x1179C0
SSClass *__fastcall SSClass::get_demand_loaded_root(SSClass *this)
{
  SSClass *v1; // rbx
  SSClass *v2; // rcx
  SSClass *result; // rax

  v1 = this;
  v2 = this->i_superclass_p;
  if ( !v2 || (result = SSClass::get_demand_loaded_root(v2)) == 0i64 )
  {
    result = 0i64;
    if ( (v1->i_flags >> 1) & 1 )
      result = v1;
  }
  return result;
}

// File Line: 670
// RVA: 0x13D2C0
void __fastcall SSClass::track_memory(SSClass *this, AMemoryStats *mem_stats_p, bool skip_demand_loaded)
{
  SSClass *v3; // rdi
  bool v4; // bl
  AMemoryStats *v5; // rsi
  SSClass *v6; // rcx
  bool v7; // r14
  SSMethodBase **v8; // rbx
  unsigned __int64 i; // rbp
  SSMethodBase **v10; // rbx
  unsigned __int64 j; // rbp
  SSCoroutineBase **v12; // rbx
  unsigned __int64 k; // rdi

  v3 = this;
  v4 = skip_demand_loaded;
  v5 = mem_stats_p;
  v7 = 1;
  if ( !(this->i_flags & 2) )
  {
    v6 = this->i_superclass_p;
    if ( !v6 || !SSClass::is_demand_loaded(v6) )
      v7 = 0;
  }
  if ( v4 && v7 )
  {
    AMemoryStats::track_memory(
      v5,
      "SSClass",
      0x130u,
      0,
      8 * v3->i_subclasses.i_count + 8,
      8
    * (v3->i_subclasses.i_size
     + v3->i_data.i_size
     + v3->i_data_table.i_size
     + v3->i_methods.i_size
     + v3->i_coroutines.i_size
     + v3->i_class_data.i_size
     + v3->i_class_data_table.i_size
     + v3->i_class_methods.i_size)
    + 8,
      1u);
  }
  else
  {
    AMemoryStats::track_memory(
      v5,
      "SSClass",
      0x130u,
      0,
      8
    * (v3->i_class_data.i_count
     + v3->i_coroutines.i_count
     + v3->i_methods.i_count
     + v3->i_data.i_count
     + v3->i_class_methods.i_count
     + v3->i_subclasses.i_count
     + v3->i_data_table.i_count
     + v3->i_class_data_table.i_count)
    + 8,
      8
    * (v3->i_subclasses.i_size
     + v3->i_data.i_size
     + v3->i_data_table.i_size
     + v3->i_methods.i_size
     + v3->i_coroutines.i_size
     + v3->i_class_data.i_size
     + v3->i_class_data_table.i_size
     + v3->i_class_methods.i_size)
    + 8,
      1u);
    if ( v3->i_data.i_count )
      AMemoryStats::track_memory(v5, "SSTypedName", 0x10u, 0, 0, 0, v3->i_data.i_count);
    if ( v3->i_class_data.i_count )
      AMemoryStats::track_memory(v5, "SSTypedData", 0x18u, 0, 0, 0, v3->i_class_data.i_count);
    v8 = v3->i_methods.i_array_p;
    for ( i = (unsigned __int64)&v8[v3->i_methods.i_count]; (unsigned __int64)v8 < i; ++v8 )
    {
      if ( *v8 )
        ((void (__fastcall *)(SSMethodBase *, AMemoryStats *))(*v8)->vfptr[1].get_invoke_type)(*v8, v5);
    }
    v10 = v3->i_class_methods.i_array_p;
    for ( j = (unsigned __int64)&v10[v3->i_class_methods.i_count]; (unsigned __int64)v10 < j; ++v10 )
    {
      if ( *v10 )
        ((void (__fastcall *)(SSMethodBase *, AMemoryStats *))(*v10)->vfptr[1].get_invoke_type)(*v10, v5);
    }
    v12 = v3->i_coroutines.i_array_p;
    for ( k = (unsigned __int64)&v12[v3->i_coroutines.i_count]; (unsigned __int64)v12 < k; ++v12 )
    {
      if ( *v12 )
        ((void (__fastcall *)(SSCoroutineBase *, AMemoryStats *))(*v12)->vfptr[1].get_invoke_type)(*v12, v5);
    }
  }
  if ( v7 )
    AMemoryStats::track_memory(v5, "SSClass.demand", 0, 0, 0, 0, 1u);
}

// File Line: 780
// RVA: 0x13C750
void __fastcall SSClass::set_object_id_lookup_func(SSClass *this, SSInstance *(__fastcall *object_id_lookup_f)(SSObjectId *))
{
  unsigned int v2; // eax

  this->i_flags |= 0x10u;
  v2 = this->i_flags;
  this->i_object_id_lookup_f = object_id_lookup_f;
  if ( !(v2 & 0xE0) )
    this->i_flags = v2 & 0xFFFFFF3F | 0x20;
}

// File Line: 801
// RVA: 0x126BA0
SSInstance *__fastcall SSClass::object_id_lookup(SSClass *this, SSObjectId *obj_id_p)
{
  SSInstance *result; // rax

  result = (SSInstance *)this->i_object_id_lookup_f;
  if ( result )
    result = (SSInstance *)((__int64 (__fastcall *)(SSObjectId *))result)(obj_id_p);
  return result;
}

// File Line: 1462
// RVA: 0x10FBC0
void __fastcall SSClass::assign_binary(SSClass *this, const void **binary_pp, bool append_super_members)
{
  char v3; // r13
  const void **v4; // rdi
  SSClass *v5; // r14
  unsigned int v6; // er15
  SSClass *v7; // rax
  unsigned int v8; // ebx
  BOOL v9; // esi
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *v10; // r12
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *v11; // r14
  SSClass *v12; // rbx
  unsigned int v13; // edi
  unsigned int v14; // eax
  _BOOL8 v15; // r13
  unsigned int v16; // ebx
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
  SSClass **v28; // rbx
  unsigned __int64 i; // rsi
  void **v30; // r14
  unsigned int v31; // er12
  SSClass *v32; // rbx
  SSClass *v33; // rax
  unsigned int v34; // edi
  APSortedLogical<SSTypedData,ASymbol> *v35; // rsi
  unsigned int v36; // eax
  SSTypedData **v37; // rbx
  SSTypedData **v38; // rax
  APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol> > *v39; // r15
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
  unsigned int v58; // er10
  signed __int64 v59; // rcx
  unsigned int v60; // er8
  _BOOL8 v61; // rax
  _BOOL8 v62; // r8
  SSClass *v63; // rax
  SSClassDescBase *v64; // rdi
  ASymbol *v65; // rax
  SSClass **v66; // rdx
  SSClass **v67; // r9
  unsigned int v68; // er10
  signed __int64 v69; // rcx
  unsigned int v70; // er8
  _BOOL8 v71; // r8
  __int64 v72; // rcx
  ASymbol *v73; // rax
  SSClass **v74; // rdx
  SSClass **v75; // r9
  unsigned int v76; // er10
  signed __int64 v77; // rcx
  unsigned int v78; // er8
  _BOOL8 v79; // r8
  SSTypedData *v80; // rax
  SSTypedData *v81; // rdi
  SSInstance *v82; // r14
  SSClass **v83; // rbx
  unsigned __int64 j; // rsi
  const void **v85; // r12
  char *v86; // rax
  unsigned int v87; // er15
  APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *v88; // rsi
  unsigned int v89; // ecx
  unsigned int v90; // eax
  SSMethodBase **v91; // rbx
  SSMethodBase **v92; // rax
  SSMethodBase *v93; // r14
  int v94; // edi
  unsigned int v95; // ebx
  SSTypedData *v96; // rax
  SSMethodBase *v97; // r13
  SSParameters *v98; // r12
  SSParameterBase **v99; // r14
  SSParameterBase **v100; // rdi
  SSParameterBase **v101; // rsi
  SSTypedName **v102; // r15
  SSTypedName **v103; // rsi
  SSTypedName **v104; // r14
  SSTypedName *v105; // rdi
  SSClassDescBase *v106; // rcx
  SSParameters *v107; // rdi
  bool v108; // zf
  SSTypedData *v109; // rax
  SSParameters *v110; // r12
  SSParameterBase **v111; // r14
  SSParameterBase **v112; // rdi
  SSParameterBase **v113; // rsi
  SSTypedName **v114; // r15
  SSTypedName **v115; // rsi
  SSTypedName **v116; // r14
  SSTypedName *v117; // rdi
  SSClassDescBase *v118; // rcx
  SSParameters *v119; // rdi
  SSTypedData *v120; // rax
  SSParameters *v121; // r12
  SSParameterBase **v122; // r14
  SSParameterBase **v123; // rdi
  SSParameterBase **v124; // rsi
  SSTypedName **v125; // r15
  SSTypedName **v126; // rsi
  SSTypedName **v127; // r14
  SSTypedName *v128; // rdi
  SSClassDescBase *v129; // rcx
  SSParameters *v130; // rsi
  signed __int64 v131; // r15
  SSParameterBase **v132; // r12
  SSParameterBase **v133; // rdi
  unsigned __int64 v134; // r14
  SSClassDescBase *v135; // rcx
  eSSExprType v136; // ecx
  char *v137; // rax
  SSExpressionBase *v138; // rax
  SSClass *v139; // r15
  SSClass *v140; // rax
  char *v141; // rax
  unsigned int v142; // er14
  APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *v143; // rsi
  unsigned int v144; // eax
  SSMethodBase **v145; // rbx
  SSMethodBase **v146; // rax
  int v147; // edi
  unsigned int v148; // ebx
  SSMethodBase *v149; // rax
  SSMethodBase *v150; // rdi
  SSParameters *v151; // rax
  SSParameters *v152; // rsi
  SSParameters *v153; // rbx
  SSMethodBase *v154; // rax
  SSParameters *v155; // rax
  SSParameters *v156; // rsi
  SSParameters *v157; // rbx
  SSMethodBase *v158; // rax
  SSParameters *v159; // r13
  SSParameterBase **v160; // r14
  SSParameterBase **v161; // rbx
  SSParameterBase **v162; // rsi
  SSTypedName **v163; // r15
  SSTypedName **v164; // rsi
  SSTypedName **v165; // r14
  SSTypedName *v166; // rbx
  SSClassDescBase *v167; // rcx
  SSParameters *v168; // rsi
  signed __int64 v169; // r15
  SSParameterBase **v170; // r12
  SSParameterBase **v171; // rbx
  unsigned __int64 v172; // r14
  SSClassDescBase *v173; // rcx
  eSSExprType v174; // ecx
  signed __int64 v175; // rax
  SSExpressionBase *v176; // rax
  unsigned int v177; // edi
  int v178; // ebx
  SSCoroutineBase *v179; // rax
  SSCoroutineBase *v180; // rbx
  SSCoroutineBase *v181; // rax
  SSCoroutineBase *v182; // rax
  eSSExprType v183; // ecx
  signed __int64 v184; // rax
  SSExpressionBase *v185; // rax
  _BOOL8 v186; // [rsp+20h] [rbp-E0h]
  SSParameters *v187; // [rsp+20h] [rbp-E0h]
  ASymbol v188[2]; // [rsp+28h] [rbp-D8h]
  void *v189; // [rsp+30h] [rbp-D0h]
  ASymbol v190[2]; // [rsp+38h] [rbp-C8h]
  SSTypedData *v191; // [rsp+40h] [rbp-C0h]
  _DWORD *v192; // [rsp+48h] [rbp-B8h]
  SSParameters v193; // [rsp+50h] [rbp-B0h]
  SSTypedClass tclass; // [rsp+80h] [rbp-80h]
  SSParameters params_p; // [rsp+A0h] [rbp-60h]
  SSParameters v196; // [rsp+D0h] [rbp-30h]
  __int64 v197; // [rsp+100h] [rbp+0h]
  SSClass *v198; // [rsp+160h] [rbp+60h]
  void **sym_binary_pp; // [rsp+168h] [rbp+68h]
  ASymbol name; // [rsp+170h] [rbp+70h]
  ASymbol result; // [rsp+178h] [rbp+78h]

  LOBYTE(name.i_uid) = append_super_members;
  sym_binary_pp = (void **)binary_pp;
  v198 = this;
  v197 = -2i64;
  v3 = append_super_members;
  v4 = binary_pp;
  v5 = this;
  v6 = *(unsigned __int16 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 2;
  v7 = this->i_superclass_p;
  if ( v7 )
    v8 = v7->i_data_table.i_count;
  else
    v8 = 0;
  v9 = append_super_members != 0;
  v10 = (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&this->i_data.i_count;
  APSizedArrayBase<SSTypedName>::ensure_size((APSizedArrayBase<SSTypedName> *)&this->i_data.i_count, v6);
  v11 = (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&v5->i_data_table.i_count;
  APSizedArrayBase<SSTypedName>::ensure_size((APSizedArrayBase<SSTypedName> *)&v11->i_count, v8 + v6);
  if ( v3 && v8 )
  {
    v12 = v198->i_superclass_p;
    v13 = v12->i_data_table.i_count;
    APSizedArrayBase<SSTypedName>::ensure_size((APSizedArrayBase<SSTypedName> *)&v11->i_count, v13 + v11->i_count);
    memmove(&v11->i_array_p[v11->i_count], v12->i_data_table.i_array_p, 8i64 * v13);
    v11->i_count += v13;
    v14 = v11->i_count;
    if ( v11->i_count != v13 && v14 > 1 )
      qsort(v11->i_array_p, v14, 8ui64, APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::sort_compare);
    v4 = (const void **)sym_binary_pp;
  }
  v186 = v9;
  if ( v6 )
  {
    v15 = v9;
    while ( 1 )
    {
      v16 = ASymbol::create_from_binary(&result, v4)->i_uid;
      v17 = *(unsigned __int8 *)*v4;
      *v4 = (char *)*v4 + 1;
      if ( !v17 )
      {
        v25 = ASymbol::create_from_binary(v188, v4);
        v22 = SSBrain::get_class(v25);
        goto LABEL_23;
      }
      v18 = v17 - 1;
      if ( !v18 )
      {
        v23 = ASymbol::create_from_binary(v190, v4);
        v24 = SSBrain::get_class(v23);
        v22 = (SSClass *)v24->vfptr->get_metaclass((SSClassDescBase *)&v24->vfptr);
        goto LABEL_23;
      }
      v19 = v18 - 1;
      if ( !v19 )
      {
        v22 = (SSClass *)SSTypedClass::from_binary_ref(v4);
        goto LABEL_23;
      }
      v20 = v19 - 1;
      if ( !v20 )
        break;
      if ( v20 == 1 )
      {
        v22 = (SSClass *)SSClassUnion::from_binary_ref(v4);
LABEL_23:
        v21 = v22;
        goto LABEL_24;
      }
      v21 = 0i64;
LABEL_24:
      v26 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
      v27 = v26;
      v191 = (SSTypedData *)v26;
      if ( v26 )
      {
        v26->i_name.i_uid = v16;
        v26->i_type_p.i_obj_p = (SSClassDescBase *)&v21->vfptr;
        if ( v21 )
          (*(void (__fastcall **)(SSClass *))v21->vfptr->gap8)(v21);
      }
      else
      {
        v27 = 0i64;
      }
      APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(v10, v27, 0i64);
      APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(v11, v27, 0i64);
      if ( !v15 )
      {
        v28 = v198->i_subclasses.i_array_p;
        for ( i = (unsigned __int64)&v28[v198->i_subclasses.i_count]; (unsigned __int64)v28 < i; ++v28 )
          SSClass::recurse_instance_data(*v28, v27);
      }
      --v6;
      v4 = (const void **)sym_binary_pp;
      if ( !v6 )
      {
        v3 = name.i_uid;
        goto LABEL_34;
      }
    }
    v22 = (SSClass *)SSInvokableClass::from_binary_ref(v4);
    goto LABEL_23;
  }
LABEL_34:
  v30 = sym_binary_pp;
  v31 = *(unsigned __int16 *)*sym_binary_pp;
  *sym_binary_pp = (char *)*sym_binary_pp + 2;
  v32 = v198;
  v33 = v198->i_superclass_p;
  if ( v33 )
    v34 = v33->i_class_data_table.i_count;
  else
    v34 = 0;
  v35 = &v198->i_class_data;
  *(_QWORD *)&result.i_uid = (char *)v198 + 168;
  if ( v198->i_class_data.i_size < v31 )
  {
    v36 = AMemory::c_req_byte_size_func(8 * v31) >> 3;
    v32->i_class_data.i_size = v36;
    if ( v35->i_count )
    {
      v37 = v32->i_class_data.i_array_p;
      v38 = APArrayBase<SSTypedData>::alloc_array(v36);
      v35->i_array_p = v38;
      memmove(v38, v37, 8i64 * v35->i_count);
      AMemory::c_free_func(v37);
      v32 = v198;
    }
    else
    {
      AMemory::c_free_func(v32->i_class_data.i_array_p);
      v32->i_class_data.i_array_p = APArrayBase<SSTypedData>::alloc_array(v32->i_class_data.i_size);
    }
  }
  v39 = (APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol> > *)&v32->i_class_data_table.i_count;
  if ( v32->i_class_data_table.i_size < v34 + v31 )
  {
    v40 = AMemory::c_req_byte_size_func(8 * (v34 + v31)) >> 3;
    v32->i_class_data_table.i_size = v40;
    if ( v39->i_count )
    {
      v41 = v32->i_class_data_table.i_array_p;
      v42 = APArrayBase<SSTypedData>::alloc_array(v40);
      v39->i_array_p = v42;
      memmove(v42, v41, 8i64 * v39->i_count);
      AMemory::c_free_func(v41);
      v32 = v198;
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
      APSizedArrayBase<SSTypedData>::ensure_size((APSizedArrayBase<SSTypedData> *)&v39->i_count, v44 + v39->i_count);
      memmove(&v39->i_array_p[v39->i_count], v43->i_class_data_table.i_array_p, 8i64 * v44);
      v39->i_count += v44;
      v45 = v39->i_count;
      if ( v39->i_count != v44 && v45 > 1 )
        qsort(v39->i_array_p, v45, 8ui64, APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::sort_compare);
    }
  }
  if ( v31 )
  {
    v46 = *(APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol> > **)&result.i_uid;
    do
    {
      v47 = ASymbol::create_from_binary(&name, (const void **)v30)->i_uid;
      v48 = *(unsigned __int8 *)*v30;
      v49 = (unsigned int *)((char *)*v30 + 1);
      *v30 = v49;
      if ( v48 )
      {
        v50 = v48 - 1;
        if ( !v50 )
        {
          v65 = ASymbol::create_from_binary(v188, (const void **)v30);
          if ( SSBrain::c_classes.i_count )
          {
            v66 = SSBrain::c_classes.i_array_p;
            v67 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1i64];
            v68 = v65->i_uid;
            while ( 1 )
            {
              v69 = (signed __int64)&v66[((char *)v67 - (char *)v66) >> 4];
              v70 = *(_DWORD *)(*(_QWORD *)v69 + 8i64);
              if ( v68 < v70 )
                goto LABEL_281;
              v71 = v68 != v70;
              if ( !v71 )
              {
                v72 = *(_QWORD *)v69;
                goto LABEL_84;
              }
              if ( v71 < 0 )
              {
LABEL_281:
                if ( v66 == (SSClass **)v69 )
                  break;
                v67 = (SSClass **)(v69 - 8);
              }
              else
              {
                if ( v67 == (SSClass **)v69 )
                  break;
                v66 = (SSClass **)(v69 + 8);
              }
            }
          }
          v72 = 0i64;
LABEL_84:
          v53 = (SSTypedClass *)(*(__int64 (**)(void))(*(_QWORD *)v72 + 136i64))();
          goto LABEL_96;
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
            tclass.vfptr = (SSClassDescBaseVtbl *)&SSTypedClass::`vftable';
            tclass.i_item_type_p = 0i64;
            v55 = ASymbol::create_from_binary(&result, (const void **)v30);
            if ( SSBrain::c_classes.i_count )
            {
              v56 = SSBrain::c_classes.i_array_p;
              v57 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1i64];
              v58 = v55->i_uid;
              while ( 1 )
              {
                v59 = (signed __int64)&v56[((char *)v57 - (char *)v56) >> 4];
                v60 = *(_DWORD *)(*(_QWORD *)v59 + 8i64);
                if ( v58 < v60 )
                  goto LABEL_282;
                v61 = v58 == v60;
                v62 = v58 != v60;
                if ( v61 == 1 )
                {
                  v63 = *(SSClass **)v59;
                  goto LABEL_72;
                }
                if ( v62 < 0 )
                {
LABEL_282:
                  if ( v56 == (SSClass **)v59 )
                    break;
                  v57 = (SSClass **)(v59 - 8);
                }
                else
                {
                  if ( v57 == (SSClass **)v59 )
                    break;
                  v56 = (SSClass **)(v59 + 8);
                }
              }
            }
            v63 = 0i64;
LABEL_72:
            tclass.i_class_p = v63;
            v64 = SSClassDescBase::from_binary_ref_typed((const void **)v30);
            (*(void (__fastcall **)(SSClassDescBase *))v64->vfptr->gap8)(v64);
            tclass.i_item_type_p = v64;
            v53 = SSTypedClass::get_or_create(&tclass);
            tclass.vfptr = (SSClassDescBaseVtbl *)&SSTypedClass::`vftable';
            v64->vfptr->dereference_delay(v64);
            tclass.i_item_type_p = 0i64;
            tclass.vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable';
          }
          goto LABEL_96;
        }
        v52 = v51 - 1;
        if ( !v52 )
        {
          v53 = (SSTypedClass *)SSInvokableClass::from_binary_ref((const void **)v30);
          goto LABEL_96;
        }
        if ( v52 == 1 )
        {
          v53 = (SSTypedClass *)SSClassUnion::from_binary_ref((const void **)v30);
          goto LABEL_96;
        }
      }
      else
      {
        v73 = ASymbol::create_from_binary(v190, (const void **)v30);
        if ( SSBrain::c_classes.i_count )
        {
          v74 = SSBrain::c_classes.i_array_p;
          v75 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1i64];
          v76 = v73->i_uid;
          while ( 1 )
          {
            v77 = (signed __int64)&v74[((char *)v75 - (char *)v74) >> 4];
            v78 = *(_DWORD *)(*(_QWORD *)v77 + 8i64);
            if ( v76 < v78 )
              goto LABEL_283;
            v79 = v76 != v78;
            if ( !v79 )
            {
              v53 = *(SSTypedClass **)v77;
              goto LABEL_96;
            }
            if ( v79 < 0 )
            {
LABEL_283:
              if ( v74 == (SSClass **)v77 )
                break;
              v75 = (SSClass **)(v77 - 8);
            }
            else
            {
              if ( v75 == (SSClass **)v77 )
                break;
              v74 = (SSClass **)(v77 + 8);
            }
          }
        }
      }
      v53 = 0i64;
LABEL_96:
      v80 = (SSTypedData *)AMemory::c_malloc_func(0x18ui64, "SSTypedData");
      v81 = v80;
      v191 = v80;
      if ( v80 )
      {
        v82 = SSBrain::c_nil_p;
        v80->i_name.i_uid = v47;
        v80->i_type_p.i_obj_p = (SSClassDescBase *)&v53->vfptr;
        if ( v53 )
          (*(void (__fastcall **)(SSTypedClass *))v53->vfptr->gap8)(v53);
        v81->i_data_p = v82;
        v30 = sym_binary_pp;
      }
      else
      {
        v81 = 0i64;
      }
      APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol>>::append(v46, v81, 0i64);
      APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol>>::append(v39, v81, 0i64);
      if ( !v186 )
      {
        v83 = v198->i_subclasses.i_array_p;
        for ( j = (unsigned __int64)&v83[v198->i_subclasses.i_count]; (unsigned __int64)v83 < j; ++v83 )
          SSClass::recurse_class_data(*v83, v81);
      }
      --v31;
    }
    while ( v31 );
  }
  v85 = (const void **)sym_binary_pp;
  v86 = (char *)*sym_binary_pp;
  name.i_uid = *(_DWORD *)*sym_binary_pp;
  v87 = name.i_uid;
  *sym_binary_pp = v86 + 4;
  v88 = (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&v198->i_methods.i_count;
  *(_QWORD *)&v190[0].i_uid = (char *)v198 + 112;
  v89 = v87 + v198->i_methods.i_count;
  if ( v198->i_methods.i_size < v89 )
  {
    v90 = AMemory::c_req_byte_size_func(8 * v89) >> 3;
    v88->i_size = v90;
    if ( v88->i_count )
    {
      v91 = v88->i_array_p;
      v92 = APArrayBase<SSMethodBase>::alloc_array(v90);
      v88->i_array_p = v92;
      memmove(v92, v91, 8i64 * v88->i_count);
      AMemory::c_free_func(v91);
    }
    else
    {
      AMemory::c_free_func(v88->i_array_p);
      v88->i_array_p = APArrayBase<SSMethodBase>::alloc_array(v88->i_size);
    }
  }
  v93 = 0i64;
  *(_QWORD *)&v188[0].i_uid = 0i64;
  if ( !v87 )
    goto LABEL_284;
  do
  {
    v94 = *(unsigned __int8 *)*v85;
    *v85 = (char *)*v85 + 1;
    v95 = ASymbol::create_from_binary(&result, v85)->i_uid;
    if ( v94 )
    {
      if ( v94 == 2 )
      {
        v109 = (SSTypedData *)AMemory::c_malloc_func(0x30ui64, "SSMethodMthd");
        v97 = (SSMethodBase *)v109;
        v191 = v109;
        if ( v109 )
        {
          LODWORD(v109->i_type_p.i_obj_p) = v95;
          v109->i_data_p = (SSInstance *)v198;
          *(_QWORD *)&v109->i_name.i_uid = &SSInvokableBase::`vftable';
          *(_QWORD *)&v109[1].i_name.i_uid = 0i64;
          *(_QWORD *)&v109->i_name.i_uid = &SSMethodBase::`vftable';
          SSParameters::SSParameters(&v196, v85);
          v110 = SSParameters::get_or_create(&v196);
          v111 = v196.i_params.i_array_p;
          v112 = v196.i_params.i_array_p;
          v113 = &v196.i_params.i_array_p[v196.i_params.i_count];
          v196.i_params.i_array_p = 0i64;
          for ( v196.i_params.i_count = 0; v112 < v113; ++v112 )
          {
            if ( *v112 )
              (*v112)->vfptr->__vecDelDtor(*v112, 1u);
          }
          AMemory::c_free_func(v111);
          v114 = v196.i_return_params.i_array_p;
          v115 = v196.i_return_params.i_array_p;
          v116 = &v196.i_return_params.i_array_p[v196.i_return_params.i_count];
          v196.i_return_params.i_array_p = 0i64;
          for ( v196.i_return_params.i_count = 0; v115 < v116; ++v115 )
          {
            v117 = *v115;
            if ( *v115 )
            {
              v118 = v117->i_type_p.i_obj_p;
              if ( v118 )
                (*(void (__cdecl **)(SSClassDescBase *))&v118->vfptr->gap8[8])(v118);
              AMemory::c_free_func(v117);
            }
          }
          AMemory::c_free_func(v114);
          if ( v196.i_result_type_p.i_obj_p )
            (*(void (**)(void))&v196.i_result_type_p.i_obj_p->vfptr->gap8[8])();
          AMemory::c_free_func(v196.i_return_params.i_array_p);
          AMemory::c_free_func(v196.i_params.i_array_p);
          if ( v97->i_params_p.i_obj_p != v110 )
          {
            if ( v110 )
              ++v110->i_ref_count;
            v119 = v97->i_params_p.i_obj_p;
            if ( v119 )
            {
              v108 = v119->i_ref_count-- == 1;
              if ( v108 )
              {
                v119->i_ref_count = 2147483648;
                SSParameters::~SSParameters(v119);
                AMemory::c_free_func(v119);
              }
            }
            v97->i_params_p.i_obj_p = v110;
          }
          v97->vfptr = (SSInvokableBaseVtbl *)&SSMethodMthd::`vftable';
          tclass.i_ref_count = 0;
          v97[1].vfptr = 0i64;
          *(_QWORD *)&v97[1].i_name.i_uid = *(_QWORD *)&tclass.i_ref_count;
          v85 = (const void **)sym_binary_pp;
          v88 = *(APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > **)&v190[0].i_uid;
          v93 = *(SSMethodBase **)&v188[0].i_uid;
          v87 = name.i_uid;
        }
        else
        {
          v97 = 0i64;
        }
      }
      else
      {
        v96 = (SSTypedData *)AMemory::c_malloc_func(0x28ui64, "SSMethodFunc");
        v97 = (SSMethodBase *)v96;
        v191 = v96;
        if ( v96 )
        {
          LODWORD(v96->i_type_p.i_obj_p) = v95;
          v96->i_data_p = (SSInstance *)v198;
          *(_QWORD *)&v96->i_name.i_uid = &SSInvokableBase::`vftable';
          *(_QWORD *)&v96[1].i_name.i_uid = 0i64;
          *(_QWORD *)&v96->i_name.i_uid = &SSMethodBase::`vftable';
          SSParameters::SSParameters(&params_p, v85);
          v98 = SSParameters::get_or_create(&params_p);
          v99 = params_p.i_params.i_array_p;
          v100 = params_p.i_params.i_array_p;
          v101 = &params_p.i_params.i_array_p[params_p.i_params.i_count];
          params_p.i_params.i_array_p = 0i64;
          for ( params_p.i_params.i_count = 0; v100 < v101; ++v100 )
          {
            if ( *v100 )
              (*v100)->vfptr->__vecDelDtor(*v100, 1u);
          }
          AMemory::c_free_func(v99);
          v102 = params_p.i_return_params.i_array_p;
          v103 = params_p.i_return_params.i_array_p;
          v104 = &params_p.i_return_params.i_array_p[params_p.i_return_params.i_count];
          params_p.i_return_params.i_array_p = 0i64;
          for ( params_p.i_return_params.i_count = 0; v103 < v104; ++v103 )
          {
            v105 = *v103;
            if ( *v103 )
            {
              v106 = v105->i_type_p.i_obj_p;
              if ( v106 )
                (*(void (__cdecl **)(SSClassDescBase *))&v106->vfptr->gap8[8])(v106);
              AMemory::c_free_func(v105);
            }
          }
          AMemory::c_free_func(v102);
          if ( params_p.i_result_type_p.i_obj_p )
            (*(void (**)(void))&params_p.i_result_type_p.i_obj_p->vfptr->gap8[8])();
          AMemory::c_free_func(params_p.i_return_params.i_array_p);
          AMemory::c_free_func(params_p.i_params.i_array_p);
          if ( v97->i_params_p.i_obj_p != v98 )
          {
            if ( v98 )
              ++v98->i_ref_count;
            v107 = v97->i_params_p.i_obj_p;
            if ( v107 )
            {
              v108 = v107->i_ref_count-- == 1;
              if ( v108 )
              {
                v107->i_ref_count = 2147483648;
                SSParameters::~SSParameters(v107);
                AMemory::c_free_func(v107);
              }
            }
            v97->i_params_p.i_obj_p = v98;
          }
          v97->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable';
          v97[1].vfptr = 0i64;
          v85 = (const void **)sym_binary_pp;
          v88 = *(APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > **)&v190[0].i_uid;
          v93 = *(SSMethodBase **)&v188[0].i_uid;
          v87 = name.i_uid;
        }
        else
        {
          v97 = 0i64;
        }
      }
    }
    else
    {
      v120 = (SSTypedData *)AMemory::c_malloc_func(0x28ui64, "SSMethod");
      v97 = (SSMethodBase *)v120;
      v191 = v120;
      if ( v120 )
      {
        LODWORD(v120->i_type_p.i_obj_p) = v95;
        v120->i_data_p = (SSInstance *)v198;
        *(_QWORD *)&v120->i_name.i_uid = &SSInvokableBase::`vftable';
        *(_QWORD *)&v120[1].i_name.i_uid = 0i64;
        *(_QWORD *)&v120->i_name.i_uid = &SSMethodBase::`vftable';
        SSParameters::SSParameters(&v193, v85);
        v121 = SSParameters::get_or_create(&v193);
        v187 = v121;
        v122 = v193.i_params.i_array_p;
        v123 = v193.i_params.i_array_p;
        v124 = &v193.i_params.i_array_p[v193.i_params.i_count];
        v193.i_params.i_array_p = 0i64;
        for ( v193.i_params.i_count = 0; v123 < v124; ++v123 )
        {
          if ( *v123 )
            (*v123)->vfptr->__vecDelDtor(*v123, 1u);
        }
        AMemory::c_free_func(v122);
        v125 = v193.i_return_params.i_array_p;
        v126 = v193.i_return_params.i_array_p;
        v127 = &v193.i_return_params.i_array_p[v193.i_return_params.i_count];
        v193.i_return_params.i_array_p = 0i64;
        for ( v193.i_return_params.i_count = 0; v126 < v127; ++v126 )
        {
          v128 = *v126;
          v189 = v128;
          if ( v128 )
          {
            v129 = v128->i_type_p.i_obj_p;
            if ( v129 )
              (*(void (**)(void))&v129->vfptr->gap8[8])();
            AMemory::c_free_func(v128);
          }
        }
        AMemory::c_free_func(v125);
        if ( v193.i_result_type_p.i_obj_p )
          (*(void (**)(void))&v193.i_result_type_p.i_obj_p->vfptr->gap8[8])();
        v189 = &v193.i_return_params;
        AMemory::c_free_func(v193.i_return_params.i_array_p);
        v189 = &v193.i_params;
        AMemory::c_free_func(v193.i_params.i_array_p);
        if ( v97->i_params_p.i_obj_p != v121 )
        {
          if ( v121 )
            ++v121->i_ref_count;
          v130 = v97->i_params_p.i_obj_p;
          if ( v130 )
          {
            v108 = v130->i_ref_count-- == 1;
            if ( v108 )
            {
              v130->i_ref_count = 2147483648;
              v189 = v130;
              v131 = (signed __int64)&v130->i_params;
              v132 = v130->i_params.i_array_p;
              v133 = v132;
              v134 = (unsigned __int64)&v132[v130->i_params.i_count];
              *(_QWORD *)(v131 + 8) = 0i64;
              *(_DWORD *)v131 = 0;
              if ( (unsigned __int64)v132 < v134 )
              {
                do
                {
                  if ( *v133 )
                    (*v133)->vfptr->__vecDelDtor(*v133, 1u);
                  ++v133;
                }
                while ( (unsigned __int64)v133 < v134 );
              }
              AMemory::c_free_func(v132);
              APCompactArrayBase<SSTypedName>::free_all((APCompactArrayBase<SSTypedName> *)&v130->i_return_params.i_count);
              v135 = v130->i_result_type_p.i_obj_p;
              if ( v135 )
                (*(void (**)(void))&v135->vfptr->gap8[8])();
              v192 = &v130->i_return_params.i_count;
              AMemory::c_free_func(v130->i_return_params.i_array_p);
              v192 = &v130->i_params.i_count;
              AMemory::c_free_func(v130->i_params.i_array_p);
              AMemory::c_free_func(v130);
              v121 = v187;
            }
          }
          v97->i_params_p.i_obj_p = v121;
        }
        v97->vfptr = (SSInvokableBaseVtbl *)&SSMethod::`vftable';
        v85 = (const void **)sym_binary_pp;
        v136 = *(unsigned __int8 *)*sym_binary_pp;
        v137 = (char *)*sym_binary_pp + 1;
        *sym_binary_pp = v137;
        if ( v136 )
        {
          *v85 = v137 + 2;
          v138 = SSExpressionBase::from_binary_new(v136, v85);
        }
        else
        {
          v138 = 0i64;
        }
        v97[1].vfptr = (SSInvokableBaseVtbl *)v138;
        v88 = *(APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > **)&v190[0].i_uid;
        v93 = *(SSMethodBase **)&v188[0].i_uid;
        v87 = name.i_uid;
      }
      else
      {
        v97 = 0i64;
      }
    }
    APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::append(v88, v97, 0i64);
    if ( v95 == ASymbolX_dtor.i_uid )
      v93 = v97;
    *(_QWORD *)&v188[0].i_uid = v93;
    name.i_uid = --v87;
  }
  while ( v87 );
  if ( v93 )
  {
    v139 = v198;
  }
  else
  {
LABEL_284:
    v139 = v198;
    v140 = v198->i_superclass_p;
    if ( v140 )
      v93 = v140->i_destructor_p;
    else
      v93 = 0i64;
  }
  v139->i_destructor_p = v93;
  v141 = (char *)*v85;
  name.i_uid = *(_DWORD *)*v85;
  v142 = name.i_uid;
  *v85 = v141 + 4;
  v143 = (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&v139->i_class_methods.i_count;
  *(_QWORD *)&v188[0].i_uid = (char *)v139 + 216;
  if ( v139->i_class_methods.i_size < v142 )
  {
    v144 = AMemory::c_req_byte_size_func(8 * v142) >> 3;
    v139->i_class_methods.i_size = v144;
    if ( v143->i_count )
    {
      v145 = v139->i_class_methods.i_array_p;
      v146 = APArrayBase<SSMethodBase>::alloc_array(v144);
      v139->i_class_methods.i_array_p = v146;
      memmove(v146, v145, 8i64 * v143->i_count);
      AMemory::c_free_func(v145);
    }
    else
    {
      AMemory::c_free_func(v139->i_class_methods.i_array_p);
      v139->i_class_methods.i_array_p = APArrayBase<SSMethodBase>::alloc_array(v139->i_class_methods.i_size);
    }
  }
  for ( ; v142; name.i_uid = v142 )
  {
    v147 = *(unsigned __int8 *)*v85;
    *v85 = (char *)*v85 + 1;
    v148 = ASymbol::create_from_binary(&result, v85)->i_uid;
    if ( v147 )
    {
      if ( v147 == 2 )
      {
        v154 = (SSMethodBase *)AMemory::c_malloc_func(0x30ui64, "SSMethodMthd");
        v150 = v154;
        v192 = v154;
        if ( v154 )
        {
          v154->i_name.i_uid = v148;
          v154->i_scope_p = v139;
          v154->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable';
          v154->i_params_p.i_obj_p = 0i64;
          v154->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable';
          v155 = SSParameters::get_or_create(v85);
          v156 = v155;
          if ( v150->i_params_p.i_obj_p != v155 )
          {
            if ( v155 )
              ++v155->i_ref_count;
            v157 = v150->i_params_p.i_obj_p;
            if ( v157 )
            {
              v108 = v157->i_ref_count-- == 1;
              if ( v108 )
              {
                v157->i_ref_count = 2147483648;
                SSParameters::~SSParameters(v157);
                AMemory::c_free_func(v157);
              }
            }
            v150->i_params_p.i_obj_p = v156;
          }
          v150->vfptr = (SSInvokableBaseVtbl *)&SSMethodMthd::`vftable';
          tclass.i_ref_count = 0;
          v150[1].vfptr = 0i64;
          *(_QWORD *)&v150[1].i_name.i_uid = *(_QWORD *)&tclass.i_ref_count;
          v143 = *(APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > **)&v188[0].i_uid;
        }
        else
        {
          v150 = 0i64;
        }
      }
      else
      {
        v149 = (SSMethodBase *)AMemory::c_malloc_func(0x28ui64, "SSMethodFunc");
        v150 = v149;
        v192 = v149;
        if ( v149 )
        {
          v149->i_name.i_uid = v148;
          v149->i_scope_p = v139;
          v149->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable';
          v149->i_params_p.i_obj_p = 0i64;
          v149->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable';
          v151 = SSParameters::get_or_create(v85);
          v152 = v151;
          if ( v150->i_params_p.i_obj_p != v151 )
          {
            if ( v151 )
              ++v151->i_ref_count;
            v153 = v150->i_params_p.i_obj_p;
            if ( v153 )
            {
              v108 = v153->i_ref_count-- == 1;
              if ( v108 )
              {
                v153->i_ref_count = 2147483648;
                SSParameters::~SSParameters(v153);
                AMemory::c_free_func(v153);
              }
            }
            v150->i_params_p.i_obj_p = v152;
          }
          v150->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable';
          v150[1].vfptr = 0i64;
          v143 = *(APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > **)&v188[0].i_uid;
        }
        else
        {
          v150 = 0i64;
        }
      }
    }
    else
    {
      v158 = (SSMethodBase *)AMemory::c_malloc_func(0x28ui64, "SSMethod");
      v150 = v158;
      v192 = v158;
      if ( v158 )
      {
        v158->i_name.i_uid = v148;
        v158->i_scope_p = v139;
        v158->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable';
        v158->i_params_p.i_obj_p = 0i64;
        v158->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable';
        SSParameters::SSParameters(&v193, v85);
        v159 = SSParameters::get_or_create(&v193);
        v160 = v193.i_params.i_array_p;
        v161 = v193.i_params.i_array_p;
        v162 = &v193.i_params.i_array_p[v193.i_params.i_count];
        v193.i_params.i_array_p = 0i64;
        for ( v193.i_params.i_count = 0; v161 < v162; ++v161 )
        {
          if ( *v161 )
            (*v161)->vfptr->__vecDelDtor(*v161, 1u);
        }
        AMemory::c_free_func(v160);
        v163 = v193.i_return_params.i_array_p;
        v164 = v193.i_return_params.i_array_p;
        v165 = &v193.i_return_params.i_array_p[v193.i_return_params.i_count];
        v193.i_return_params.i_array_p = 0i64;
        for ( v193.i_return_params.i_count = 0; v164 < v165; ++v164 )
        {
          v166 = *v164;
          v189 = v166;
          if ( v166 )
          {
            v167 = v166->i_type_p.i_obj_p;
            if ( v167 )
              (*(void (**)(void))&v167->vfptr->gap8[8])();
            AMemory::c_free_func(v166);
          }
        }
        AMemory::c_free_func(v163);
        if ( v193.i_result_type_p.i_obj_p )
          (*(void (**)(void))&v193.i_result_type_p.i_obj_p->vfptr->gap8[8])();
        v189 = &v193.i_return_params;
        AMemory::c_free_func(v193.i_return_params.i_array_p);
        v189 = &v193.i_params;
        AMemory::c_free_func(v193.i_params.i_array_p);
        if ( v150->i_params_p.i_obj_p != v159 )
        {
          if ( v159 )
            ++v159->i_ref_count;
          v168 = v150->i_params_p.i_obj_p;
          if ( v168 )
          {
            v108 = v168->i_ref_count-- == 1;
            if ( v108 )
            {
              v168->i_ref_count = 2147483648;
              v189 = v168;
              v169 = (signed __int64)&v168->i_params;
              v170 = v168->i_params.i_array_p;
              v171 = v170;
              v172 = (unsigned __int64)&v170[v168->i_params.i_count];
              *(_QWORD *)(v169 + 8) = 0i64;
              *(_DWORD *)v169 = 0;
              if ( (unsigned __int64)v170 < v172 )
              {
                do
                {
                  if ( *v171 )
                    (*v171)->vfptr->__vecDelDtor(*v171, 1u);
                  ++v171;
                }
                while ( (unsigned __int64)v171 < v172 );
              }
              AMemory::c_free_func(v170);
              APCompactArrayBase<SSTypedName>::free_all((APCompactArrayBase<SSTypedName> *)&v168->i_return_params.i_count);
              v173 = v168->i_result_type_p.i_obj_p;
              if ( v173 )
                (*(void (**)(void))&v173->vfptr->gap8[8])();
              v191 = (SSTypedData *)&v168->i_return_params;
              AMemory::c_free_func(v168->i_return_params.i_array_p);
              v189 = &v168->i_params;
              AMemory::c_free_func(v168->i_params.i_array_p);
              AMemory::c_free_func(v168);
              v85 = (const void **)sym_binary_pp;
            }
          }
          v150->i_params_p.i_obj_p = v159;
        }
        v150->vfptr = (SSInvokableBaseVtbl *)&SSMethod::`vftable';
        v174 = *(unsigned __int8 *)*v85;
        v175 = (signed __int64)*v85 + 1;
        *v85 = (const void *)v175;
        if ( v174 )
        {
          *v85 = (const void *)(v175 + 2);
          v176 = SSExpressionBase::from_binary_new(v174, v85);
        }
        else
        {
          v176 = 0i64;
        }
        v150[1].vfptr = (SSInvokableBaseVtbl *)v176;
        v143 = *(APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > **)&v188[0].i_uid;
        v142 = name.i_uid;
        v139 = v198;
      }
      else
      {
        v150 = 0i64;
      }
    }
    APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::append(v143, v150, 0i64);
    --v142;
  }
  v177 = *(_DWORD *)*v85;
  *v85 = (char *)*v85 + 4;
  if ( v139->i_coroutines.i_size < v177 )
  {
    v139->i_coroutines.i_size = AMemory::c_req_byte_size_func(8 * v177) >> 3;
    AMemory::c_free_func(v139->i_coroutines.i_array_p);
    v139->i_coroutines.i_array_p = APArrayBase<SSCoroutineBase>::alloc_array(v139->i_coroutines.i_size);
  }
  for ( v139->i_coroutines.i_count = 0; v177; --v177 )
  {
    v178 = *(unsigned __int8 *)*v85;
    *v85 = (char *)*v85 + 1;
    name.i_uid = ASymbol::create_from_binary((ASymbol *)&v198, v85)->i_uid;
    if ( v178 == 3 )
    {
      v182 = (SSCoroutineBase *)AMemory::c_malloc_func(0x28ui64, "SSCoroutine");
      v180 = v182;
      sym_binary_pp = (void **)&v182->vfptr;
      if ( v182 )
      {
        SSCoroutineBase::SSCoroutineBase(v182, &name, v139, v85);
        v180->vfptr = (SSInvokableBaseVtbl *)&SSCoroutine::`vftable';
        v183 = *(unsigned __int8 *)*v85;
        v184 = (signed __int64)*v85 + 1;
        *v85 = (const void *)v184;
        if ( v183 )
        {
          *v85 = (const void *)(v184 + 2);
          v185 = SSExpressionBase::from_binary_new(v183, v85);
        }
        else
        {
          v185 = 0i64;
        }
        v180[1].vfptr = (SSInvokableBaseVtbl *)v185;
      }
      else
      {
        v180 = 0i64;
      }
    }
    else if ( v178 == 5 )
    {
      v181 = (SSCoroutineBase *)AMemory::c_malloc_func(0x30ui64, "SSCoroutineMthd");
      v180 = v181;
      sym_binary_pp = (void **)&v181->vfptr;
      if ( v181 )
      {
        SSCoroutineBase::SSCoroutineBase(v181, &name, v139, v85);
        v180->vfptr = (SSInvokableBaseVtbl *)&SSCoroutineMthd::`vftable';
        tclass.i_ref_count = 0;
        v180[1].vfptr = 0i64;
        *(_QWORD *)&v180[1].i_name.i_uid = *(_QWORD *)&tclass.i_ref_count;
      }
      else
      {
        v180 = 0i64;
      }
    }
    else
    {
      v179 = (SSCoroutineBase *)AMemory::c_malloc_func(0x28ui64, "SSCoroutineFunc");
      v180 = v179;
      sym_binary_pp = (void **)&v179->vfptr;
      if ( v179 )
      {
        SSCoroutineBase::SSCoroutineBase(v179, &name, v139, v85);
        v180->vfptr = (SSInvokableBaseVtbl *)&SSCoroutineFunc::`vftable';
        v180[1].vfptr = 0i64;
      }
      else
      {
        v180 = 0i64;
      }
    }
    APSorted<SSCoroutineBase,ASymbol,ACompareLogical<ASymbol>>::append(
      (APSorted<SSCoroutineBase,ASymbol,ACompareLogical<ASymbol> > *)&v139->i_coroutines.i_count,
      v180,
      0i64);
  }
  v139->i_flags &= 0xFFFFFFF7;
  v139->i_flags |= 1u;
})&v139->i_coroutines.i_count,
      v180,
      0i64);
  }
  v139->i_flags &= 0xFFFFFFF7;
  v139->i_flags |= 1u;
}

// File Line: 1749
// RVA: 0x116350
void __fastcall SSClass::from_binary_group(const void **binary_pp)
{
  const void **v1; // rbx
  int v2; // edi
  ASymbol *v3; // rax
  __int64 v4; // r8
  SSClass **v5; // rdx
  unsigned int v6; // er10
  SSClass **v7; // r9
  signed __int64 v8; // rax
  __int64 v9; // rcx
  ASymbol result; // [rsp+30h] [rbp+8h]

  v1 = binary_pp;
  v2 = *(_DWORD *)*binary_pp;
  for ( *binary_pp = (char *)*binary_pp + 4; v2; --v2 )
  {
    v3 = ASymbol::create_from_binary(&result, v1);
    if ( SSBrain::c_classes.i_count )
    {
      v5 = SSBrain::c_classes.i_array_p;
      v6 = v3->i_uid;
      v7 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1i64];
      while ( 1 )
      {
        v8 = (signed __int64)&v5[((char *)v7 - (char *)v5) >> 4];
        v4 = *(unsigned int *)(*(_QWORD *)v8 + 8i64);
        if ( v6 < (unsigned int)v4 )
          goto LABEL_16;
        v4 = v6 != (_DWORD)v4;
        if ( !v4 )
        {
          v9 = *(_QWORD *)v8;
          goto LABEL_13;
        }
        if ( v4 < 0 )
        {
LABEL_16:
          if ( v5 == (SSClass **)v8 )
            break;
          v7 = (SSClass **)(v8 - 8);
        }
        else
        {
          if ( v7 == (SSClass **)v8 )
            break;
          v5 = (SSClass **)(v8 + 8);
        }
      }
    }
    v9 = 0i64;
LABEL_13:
    LOBYTE(v4) = 1;
    (*(void (__fastcall **)(__int64, const void **, __int64))(*(_QWORD *)v9 + 272i64))(v9, v1, v4);
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
  SSClass *result; // rax

  v2 = scope_type;
  if ( this == SSBrain::c_this_class_p )
  {
    if ( scope_type->vfptr->is_metaclass(scope_type) )
      v2 = (SSClassDescBase *)v2->vfptr->get_key_class(v2);
    result = (SSClass *)v2;
  }
  else if ( this == SSBrain::c_item_class_p )
  {
    if ( scope_type->vfptr->get_class_type(scope_type) == 2 )
      result = (SSClass *)v2->vfptr->get_item_type(v2);
    else
      result = SSBrain::c_object_class_p;
  }
  else
  {
    result = this;
  }
  return result;
}

// File Line: 2095
// RVA: 0x114DD0
SSClass *__fastcall SSClass::find_common_type(SSClass *this, SSClassDescBase *cls)
{
  SSClass *v2; // rbx
  SSClass *v3; // rbp
  SSClassDescBase *v4; // rsi
  SSClass *v5; // rdi
  eSSClassType v6; // eax
  SSClassDescBaseVtbl *v7; // rdi
  __int64 v8; // rax
  SSClass *result; // rax
  SSClass *v10; // rdi
  SSClass *v11; // rcx
  SSClass *v12; // rcx

  v2 = this;
  v3 = 0i64;
  v4 = cls;
  v5 = 0i64;
  v6 = (unsigned int)cls->vfptr->get_class_type(cls);
  if ( v6 == SSClassType_class )
  {
    v5 = (SSClass *)v4;
    goto LABEL_18;
  }
  if ( v6 == 1 )
  {
    v10 = (SSClass *)v4[7].vfptr;
    while ( v2 != v10 )
    {
      v11 = v10->i_superclass_p;
      if ( v11 )
      {
        if ( SSClass::is_class(v11, v2) )
          break;
      }
      v2 = v2->i_superclass_p;
      if ( !v2 )
        goto LABEL_15;
    }
    v3 = v2;
LABEL_15:
    result = SSBrain::c_object_class_p;
    if ( v3 != SSBrain::c_object_class_p )
      result = (SSClass *)((char *)v3 + 240);
  }
  else
  {
    if ( (signed int)v6 <= 1 )
      goto LABEL_18;
    if ( (signed int)v6 <= 3 )
    {
      v5 = v4->vfptr->get_key_class(v4);
      goto LABEL_18;
    }
    if ( v6 != 4 )
    {
LABEL_18:
      while ( v5 != v2 )
      {
        v12 = v2->i_superclass_p;
        if ( v12 )
        {
          if ( SSClass::is_class(v12, v5) )
            break;
        }
        v5 = v5->i_superclass_p;
        if ( !v5 )
          goto LABEL_24;
      }
      v3 = v5;
LABEL_24:
      result = v3;
    }
    else
    {
      v7 = v2->vfptr;
      v8 = (__int64)v4->vfptr->as_unary_class(v4);
      result = (SSClass *)v7->find_common_type((SSClassDescBase *)&v2->vfptr, (SSClassDescBase *)v8);
    }
  }
  return result;
}

// File Line: 2129
// RVA: 0x1178E0
SSClassDescBaseVtbl *__fastcall SSClass::get_data_type(SSClass *this, ASymbol *data_name, eSSScope *scope_p)
{
  SSClass *v3; // rsi
  eSSScope *v4; // rbx
  ASymbol *v5; // rdi
  SSTypedName *v6; // rax
  SSClassDescBaseVtbl *result; // rax

  v3 = this;
  v4 = scope_p;
  v5 = data_name;
  v6 = APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&this->i_data_table.i_count,
         data_name);
  if ( v6 )
  {
    if ( v4 )
      *v4 = 2;
    result = (SSClassDescBaseVtbl *)v6->i_type_p.i_obj_p;
  }
  else
  {
    result = (SSClassDescBaseVtbl *)APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
                                      (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&v3->i_class_data_table,
                                      v5);
    if ( result )
    {
      if ( v4 )
        *v4 = 1;
      result = *(SSClassDescBaseVtbl **)result->gap8;
    }
  }
  return result;
}

// File Line: 2175
// RVA: 0x118150
SSMethodBase *__fastcall SSClass::get_method_inherited_receiver(SSClass *this, ASymbol *method_name, SSInstance **receiver_pp, SSInvokedBase *caller_p)
{
  SSClass *v4; // rbx
  SSInstance **v5; // rsi
  ASymbol *v6; // rdi
  SSMethodBase *v7; // r9
  SSClass *v8; // rcx
  SSClass *v9; // rcx
  SSMethodBase *v10; // rax
  signed __int64 v11; // rbx

  v4 = this;
  v5 = receiver_pp;
  v6 = method_name;
  v7 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_methods.i_count,
         method_name);
  if ( !v7 )
  {
    v8 = v4->i_superclass_p;
    if ( v8 )
      v7 = SSClass::get_instance_method_inherited(v8, v6);
  }
  if ( v7 )
    return v7;
  v7 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&v4->i_class_methods.i_count,
         v6);
  if ( !v7 )
  {
    v9 = v4->i_superclass_p;
    if ( v9 )
      v10 = SSClass::get_class_method_inherited(v9, v6);
    else
      v10 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
              (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&SSBrain::c_object_class_p->i_methods.i_count,
              v6);
    v7 = v10;
  }
  if ( v7 )
  {
    if ( v4 == (SSClass *)-240i64 )
      v11 = 0i64;
    else
      v11 = (signed __int64)&v4->i_metaclass.vfptr;
    *v5 = (SSInstance *)v11;
    return v7;
  }
  return 0i64;
}

// File Line: 2457
// RVA: 0x11E7F0
bool __fastcall SSClass::is_class_type(SSClass *this, SSClassDescBase *type_p)
{
  SSClass *v2; // rdi
  SSClassDescBase *v3; // rbx
  eSSClassType v4; // eax
  int v5; // eax
  int v6; // eax
  bool result; // al
  SSClass *v8; // rdx
  SSClass *v9; // rcx
  SSClass *v10; // rcx

  v2 = this;
  v3 = type_p;
  v4 = (unsigned int)type_p->vfptr->get_class_type(type_p);
  if ( v4 == SSClassType_class )
  {
    if ( v3 == (SSClassDescBase *)SSBrain::c_object_class_p )
      return 1;
    if ( v3 == (SSClassDescBase *)v2 )
      return 1;
    v10 = v2->i_superclass_p;
    if ( v10 )
    {
      if ( SSClass::is_class(v10, (SSClass *)v3) )
        return 1;
    }
    return 0;
  }
  v5 = v4 - 1;
  if ( !v5 )
  {
    if ( v2 == SSBrain::c_class_class_p && (SSClass *)v3[7].vfptr == SSBrain::c_object_class_p )
      return 1;
    return 0;
  }
  v6 = v5 - 1;
  if ( !v6 )
  {
    if ( (SSClass *)v3[3].vfptr == SSBrain::c_object_class_p )
    {
      v8 = (SSClass *)v3[2].vfptr;
      if ( v8 == v2 )
        return 1;
      v9 = v2->i_superclass_p;
      if ( v9 )
      {
        if ( SSClass::is_class(v9, v8) )
          return 1;
      }
    }
    return 0;
  }
  if ( v6 == 2 )
    result = SSClassUnion::is_valid_param_for((SSClassUnion *)v3, (SSClassDescBase *)&v2->vfptr);
  else
    result = 0;
  return result;
}

// File Line: 2551
// RVA: 0x13B840
void __fastcall SSClass::register_method_func(SSClass *this, ASymbol *method_name, void (__fastcall *atomic_f)(SSInvokedMethod *, SSInstance **), eSSBindFlag flags)
{
  void (__fastcall *v4)(SSInvokedMethod *, SSInstance **); // r14
  ASymbol *v5; // rbp
  APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *v6; // rcx
  SSMethodBase *v7; // rax
  SSMethodFunc *v8; // rbx
  SSClass *v9; // r15
  SSParameters *v10; // rdi
  SSParameters *v11; // rsi
  bool v12; // zf

  v4 = atomic_f;
  v5 = method_name;
  if ( flags & 1 )
    v6 = (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_class_methods.i_count;
  else
    v6 = (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_methods.i_count;
  v7 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(v6, method_name);
  v8 = (SSMethodFunc *)v7;
  if ( v7 )
  {
    if ( v7->vfptr->get_invoke_type((SSInvokableBase *)&v7->vfptr) == 1 )
    {
      v8->i_atomic_f = v4;
    }
    else
    {
      v9 = v8->i_scope_p;
      v10 = v8->i_params_p.i_obj_p;
      if ( v10 )
        ++v10->i_ref_count;
      v11 = v8->i_params_p.i_obj_p;
      if ( v11 )
      {
        v12 = v11->i_ref_count-- == 1;
        if ( v12 )
        {
          v11->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v11);
          AMemory::c_free_func(v11);
        }
        v8->i_params_p.i_obj_p = 0i64;
      }
      SSMethodFunc::SSMethodFunc(v8, v5, v9, v10, v4);
      if ( v10 )
      {
        v12 = v10->i_ref_count-- == 1;
        if ( v12 )
        {
          v10->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v10);
          AMemory::c_free_func(v10);
        }
      }
    }
  }
}

// File Line: 2635
// RVA: 0x13B960
void __fastcall SSClass::register_method_func(SSClass *this, const char *method_name_p, void (__fastcall *atomic_f)(SSInvokedMethod *, SSInstance **), eSSBindFlag flags)
{
  SSClass *v4; // rbx
  eSSBindFlag v5; // edi
  void (__fastcall *v6)(SSInvokedMethod *, SSInstance **); // rsi
  ASymbol *v7; // rax
  ASymbol result; // [rsp+20h] [rbp-18h]

  v4 = this;
  v5 = flags;
  v6 = atomic_f;
  v7 = ASymbol::create(&result, method_name_p, 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v4, v7, v6, v5);
}

// File Line: 2658
// RVA: 0x13B940
void __fastcall SSClass::register_method_func(SSClass *this, ASymbol *method_name, void (__fastcall *atomic_f)(SSInvokedMethod *, SSInstance **), bool class_scope_b, bool rebind)
{
  SSClass::register_method_func(
    this,
    method_name,
    atomic_f,
    (eSSBindFlag)((rebind != 0 ? 2 : 0) | (class_scope_b != 0)));
}

// File Line: 2682
// RVA: 0x13B9B0
void __fastcall SSClass::register_method_func(SSClass *this, const char *method_name_p, void (__fastcall *atomic_f)(SSInvokedMethod *, SSInstance **), bool class_scope_b, bool rebind)
{
  SSClass *v5; // rdi
  bool v6; // cf
  void (__fastcall *v7)(SSInvokedMethod *, SSInstance **); // rsi
  int v8; // ebx
  ASymbol *v9; // rax

  v5 = this;
  v6 = rebind != 0;
  rebind = -rebind;
  v7 = atomic_f;
  v8 = (v6 ? 2 : 0) | (class_scope_b != 0);
  v9 = ASymbol::create((ASymbol *)&rebind, method_name_p, 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v5, v9, v7, (eSSBindFlag)v8);
}

// File Line: 2705
// RVA: 0x13BA10
void __fastcall SSClass::register_method_mthd(SSClass *this, ASymbol *method_name, void (__fastcall *atomic_m)(SSInstance *this, SSInvokedMethod *, SSInstance **), eSSBindFlag flags)
{
  void (__fastcall *v4)(SSInstance *, SSInvokedMethod *, SSInstance **); // rdi
  unsigned int v5; // eax
  SSMethodBase *v6; // r9
  SSMethodBase **v7; // rbx
  unsigned int v8; // er11
  signed __int64 v9; // r10
  SSMethodBase **i; // rdx
  signed __int64 v11; // rcx
  unsigned int v12; // er8
  _BOOL8 v13; // rax
  _BOOL8 v14; // r8
  unsigned int v15; // eax
  unsigned int v16; // er11
  signed __int64 v17; // r10
  SSMethodBase **j; // rdx
  unsigned int v19; // er8
  _BOOL8 v20; // rax
  _BOOL8 v21; // r8

  v4 = atomic_m;
  if ( flags & 1 )
  {
    v5 = this->i_class_methods.i_count;
    v6 = 0i64;
    if ( v5 )
    {
      v7 = this->i_class_methods.i_array_p;
      v8 = method_name->i_uid;
      v9 = (signed __int64)&v7[v5 - 1];
      for ( i = this->i_class_methods.i_array_p; ; i = (SSMethodBase **)(v11 + 8) )
      {
        while ( 1 )
        {
          v11 = (signed __int64)&i[(v9 - (signed __int64)i) >> 4];
          v12 = *(_DWORD *)(*(_QWORD *)v11 + 8i64);
          if ( v8 >= v12 )
          {
            v13 = v8 == v12;
            v14 = v8 != v12;
            if ( 1 - v13 >= 0 )
              break;
          }
          if ( i == (SSMethodBase **)v11 )
            goto LABEL_21;
          v9 = v11 - 8;
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
      v7 = this->i_methods.i_array_p;
      v16 = method_name->i_uid;
      v17 = (signed __int64)&v7[v15 - 1];
      for ( j = this->i_methods.i_array_p; ; j = (SSMethodBase **)(v11 + 8) )
      {
        while ( 1 )
        {
          v11 = (signed __int64)&j[(v17 - (signed __int64)j) >> 4];
          v19 = *(_DWORD *)(*(_QWORD *)v11 + 8i64);
          if ( v16 >= v19 )
          {
            v20 = v16 == v19;
            v21 = v16 != v19;
            if ( 1 - v20 >= 0 )
              break;
          }
          if ( j == (SSMethodBase **)v11 )
            goto LABEL_21;
          v17 = v11 - 8;
        }
        if ( v21 <= 0 )
          break;
        if ( v17 == v11 )
          goto LABEL_21;
      }
LABEL_20:
      v6 = v7[(unsigned int)((v11 - (signed __int64)v7) >> 3)];
    }
  }
LABEL_21:
  if ( v6 )
  {
    v6[1].vfptr = *(SSInvokableBaseVtbl **)v4;
    *(_QWORD *)&v6[1].i_name.i_uid = *((_QWORD *)v4 + 1);
  }
}

// File Line: 2774
// RVA: 0x13BB20
void __fastcall SSClass::register_method_mthd(SSClass *this, const char *method_name_p, void (__fastcall *atomic_m)(SSInstance *this, SSInvokedMethod *, SSInstance **), eSSBindFlag flags)
{
  SSClass *v4; // rbx
  eSSBindFlag v5; // edi
  ASymbol *v6; // rax
  __int128 v7; // [rsp+20h] [rbp-18h]
  ASymbol result; // [rsp+50h] [rbp+18h]

  v4 = this;
  v5 = flags;
  v7 = *(_OWORD *)atomic_m;
  v6 = ASymbol::create(&result, method_name_p, 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_mthd(v4, v6, (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v7, v5);
}

// File Line: 2821
// RVA: 0x13BB70
void __fastcall SSClass::register_method_mthd(SSClass *this, const char *method_name_p, void (__fastcall *atomic_m)(SSInstance *this, SSInvokedMethod *, SSInstance **), bool class_scope_b, bool rebind)
{
  __int128 v5; // xmm0
  bool v6; // cf
  SSClass *v7; // rdi
  int v8; // ebx
  ASymbol *v9; // rax
  __int128 v10; // [rsp+20h] [rbp-18h]

  v5 = *(_OWORD *)atomic_m;
  v6 = rebind != 0;
  rebind = -rebind;
  v7 = this;
  v10 = v5;
  v8 = (v6 ? 2 : 0) | (class_scope_b != 0);
  v9 = ASymbol::create((ASymbol *)&rebind, method_name_p, 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_mthd(
    v7,
    v9,
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    (eSSBindFlag)v8);
}

// File Line: 2836
// RVA: 0x10DE40
void __fastcall SSClass::append_coroutine(SSClass *this, SSCoroutineBase *coroutine_p)
{
  SSCoroutineBase *v2; // rax

  coroutine_p->i_scope_p = this;
  v2 = APSorted<SSCoroutineBase,ASymbol,ACompareLogical<ASymbol>>::append_replace(
         (APSorted<SSCoroutineBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_coroutines.i_count,
         coroutine_p,
         0i64);
  if ( v2 )
    v2->vfptr->__vecDelDtor((SSInvokableBase *)&v2->vfptr, 1u);
}

// File Line: 2863
// RVA: 0x13B6B0
void __fastcall SSClass::register_coroutine_func(SSClass *this, ASymbol *coroutine_name, bool (__fastcall *update_f)(SSInvokedCoroutine *), eSSBindFlag flags)
{
  bool (__fastcall *v4)(SSInvokedCoroutine *); // rbp
  ASymbol *v5; // r15
  SSMethodBase *v6; // rax
  SSCoroutineFunc *v7; // rdi
  SSClass *v8; // r14
  SSParameters *v9; // rbx
  SSParameters *v10; // rsi
  bool v11; // zf

  v4 = update_f;
  v5 = coroutine_name;
  v6 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_coroutines,
         coroutine_name);
  v7 = (SSCoroutineFunc *)v6;
  if ( v6 )
  {
    if ( v6->vfptr->get_invoke_type((SSInvokableBase *)&v6->vfptr) == 4 )
    {
      v7->i_update_f = v4;
    }
    else
    {
      v8 = v7->i_scope_p;
      v9 = v7->i_params_p.i_obj_p;
      if ( v9 )
        ++v9->i_ref_count;
      v10 = v7->i_params_p.i_obj_p;
      if ( v10 )
      {
        v11 = v10->i_ref_count-- == 1;
        if ( v11 )
        {
          v10->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v10);
          AMemory::c_free_func(v10);
        }
        v7->i_params_p.i_obj_p = 0i64;
      }
      SSCoroutineFunc::SSCoroutineFunc(v7, v5, v8, v9, v4);
      if ( v9 )
      {
        v11 = v9->i_ref_count-- == 1;
        if ( v11 )
        {
          v9->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v9);
          AMemory::c_free_func(v9);
        }
      }
    }
  }
}

// File Line: 2932
// RVA: 0x13B7A0
void __fastcall SSClass::register_coroutine_func(SSClass *this, const char *coroutine_name_p, bool (__fastcall *update_f)(SSInvokedCoroutine *), eSSBindFlag flags)
{
  SSClass *v4; // rbx
  eSSBindFlag v5; // edi
  bool (__fastcall *v6)(SSInvokedCoroutine *); // rsi
  ASymbol *v7; // rax
  ASymbol result; // [rsp+20h] [rbp-18h]

  v4 = this;
  v5 = flags;
  v6 = update_f;
  v7 = ASymbol::create(&result, coroutine_name_p, 0xFFFFFFFF, ATerm_long);
  SSClass::register_coroutine_func(v4, v7, v6, v5);
}

// File Line: 3013
// RVA: 0x13B7F0
void __fastcall SSClass::register_coroutine_mthd(SSClass *this, const char *coroutine_name_p, bool (__fastcall *update_m)(SSInstance *this, SSInvokedCoroutine *), eSSBindFlag flags)
{
  SSClass *v4; // rbx
  ASymbol *v5; // rax
  SSMethodBase *v6; // rax
  __int128 v7; // [rsp+20h] [rbp-18h]
  ASymbol result; // [rsp+40h] [rbp+8h]

  v4 = this;
  v7 = *(_OWORD *)update_m;
  v5 = ASymbol::create(&result, coroutine_name_p, 0xFFFFFFFF, ATerm_long);
  v6 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&v4->i_coroutines,
         v5);
  if ( v6 )
    *(_OWORD *)&v6[1].vfptr = v7;
}

// File Line: 3101
// RVA: 0x10DFC0
SSTypedName *__fastcall SSClass::append_instance_data(SSClass *this, ASymbol *name, SSClassDescBase *type_p, SSClass::eSubclass subclasses)
{
  SSClass::eSubclass v4; // ebp
  SSClassDescBase *v5; // rbx
  ASymbol *v6; // r14
  SSClass *v7; // rsi
  SSTypedName *v8; // rdi
  SSClass **v9; // rbx
  unsigned __int64 i; // rsi

  v4 = subclasses;
  v5 = type_p;
  v6 = name;
  v7 = this;
  v8 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
  if ( v8 )
  {
    v8->i_name = (ASymbol)v6->i_uid;
    v8->i_type_p.i_obj_p = v5;
    if ( v5 )
      (*(void (__fastcall **)(SSClassDescBase *))v5->vfptr->gap8)(v5);
  }
  else
  {
    v8 = 0i64;
  }
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(
    (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&v7->i_data.i_count,
    v8,
    0i64);
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(
    (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&v7->i_data_table.i_count,
    v8,
    0i64);
  if ( v4 == Subclass_recurse )
  {
    v9 = v7->i_subclasses.i_array_p;
    for ( i = (unsigned __int64)&v9[v7->i_subclasses.i_count]; (unsigned __int64)v9 < i; ++v9 )
      SSClass::recurse_instance_data(*v9, v8);
  }
  return v8;
}

// File Line: 3131
// RVA: 0x10DD60
SSTypedData *__fastcall SSClass::append_class_data(SSClass *this, ASymbol *name, SSClassDescBase *type_p, SSClass::eSubclass subclasses)
{
  SSClass::eSubclass v4; // er15
  SSClassDescBase *v5; // rbx
  ASymbol *v6; // r14
  SSClass *v7; // rsi
  SSTypedData *v8; // rdi
  SSInstance *v9; // rbp
  SSClass **v10; // rbx
  unsigned __int64 i; // rsi

  v4 = subclasses;
  v5 = type_p;
  v6 = name;
  v7 = this;
  v8 = (SSTypedData *)AMemory::c_malloc_func(0x18ui64, "SSTypedData");
  if ( v8 )
  {
    v9 = SSBrain::c_nil_p;
    v8->i_name = (ASymbol)v6->i_uid;
    v8->i_type_p.i_obj_p = v5;
    if ( v5 )
      (*(void (__fastcall **)(SSClassDescBase *))v5->vfptr->gap8)(v5);
    v8->i_data_p = v9;
  }
  else
  {
    v8 = 0i64;
  }
  APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol>>::append(
    (APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol> > *)&v7->i_class_data.i_count,
    v8,
    0i64);
  APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol>>::append(
    (APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol> > *)&v7->i_class_data_table.i_count,
    v8,
    0i64);
  if ( v4 == Subclass_recurse )
  {
    v10 = v7->i_subclasses.i_array_p;
    for ( i = (unsigned __int64)&v10[v7->i_subclasses.i_count]; (unsigned __int64)v10 < i; ++v10 )
      SSClass::recurse_class_data(*v10, v8);
  }
  return v8;
}

// File Line: 3167
// RVA: 0x1151A0
SSClass *__fastcall SSClass::find_data_scope(SSClass *this, ASymbol *name, SSClassUnaryBase::ePath check_path)
{
  unsigned int v3; // eax
  char v4; // bl
  ASymbol *v5; // rsi
  SSClass *v6; // rdi
  SSTypedName **v7; // r9
  unsigned int v8; // er10
  signed __int64 v9; // r8
  SSTypedName **v10; // rcx
  unsigned int v11; // edx
  _BOOL8 v12; // rdx
  unsigned int v13; // eax
  signed __int64 v14; // rdx
  unsigned int v15; // er10
  signed __int64 v16; // r9
  unsigned int **v17; // rcx
  unsigned int v18; // er8
  _BOOL8 v19; // r8
  SSClass *result; // rax
  SSClass *v21; // rcx
  SSClass **v22; // rbx
  unsigned __int64 v23; // rdi

  v3 = this->i_data.i_count;
  v4 = check_path;
  v5 = name;
  v6 = this;
  if ( v3 )
  {
    v7 = this->i_data.i_array_p;
    v8 = name->i_uid;
    v9 = (signed __int64)&v7[v3 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v10 = &v7[(v9 - (signed __int64)v7) >> 4];
        v11 = (*v10)->i_name.i_uid;
        if ( v8 >= v11 )
        {
          v12 = v8 != v11;
          if ( v12 >= 0 )
            break;
        }
        if ( v7 == v10 )
          goto LABEL_10;
        v9 = (signed __int64)(v10 - 1);
      }
      if ( v12 <= 0 )
        break;
      if ( (SSTypedName **)v9 == v10 )
        goto LABEL_10;
      v7 = v10 + 1;
    }
LABEL_19:
    result = v6;
  }
  else
  {
LABEL_10:
    v13 = v6->i_class_data.i_count;
    if ( v13 )
    {
      v14 = (signed __int64)v6->i_class_data.i_array_p;
      v15 = v5->i_uid;
      v16 = v14 + 8i64 * (v13 - 1);
      while ( 1 )
      {
        while ( 1 )
        {
          v17 = (unsigned int **)(v14 + 8 * ((v16 - v14) >> 4));
          v18 = **v17;
          if ( v15 >= v18 )
          {
            v19 = v15 != v18;
            if ( v19 >= 0 )
              break;
          }
          if ( (unsigned int **)v14 == v17 )
            goto LABEL_20;
          v16 = (signed __int64)(v17 - 1);
        }
        if ( v19 <= 0 )
          goto LABEL_19;
        if ( (unsigned int **)v16 == v17 )
          break;
        v14 = (signed __int64)(v17 + 1);
      }
    }
LABEL_20:
    v21 = v6->i_superclass_p;
    if ( !v21
      || !(v4 & 1)
      || (result = (SSClass *)((__int64 (__fastcall *)(SSClass *, ASymbol *, signed __int64))v21->vfptr[1].as_unary_class)(
                                v21,
                                v5,
                                1i64)) == 0i64 )
    {
      if ( v4 & 2
        && (v22 = v6->i_subclasses.i_array_p,
            v23 = (unsigned __int64)&v22[v6->i_subclasses.i_count],
            (unsigned __int64)v22 < v23) )
      {
        while ( 1 )
        {
          result = (SSClass *)((__int64 (__fastcall *)(SSClass *, ASymbol *, signed __int64))(*v22)->vfptr[1].as_unary_class)(
                                *v22,
                                v5,
                                2i64);
          if ( result )
            break;
          ++v22;
          if ( (unsigned __int64)v22 >= v23 )
            goto LABEL_27;
        }
      }
      else
      {
LABEL_27:
        result = 0i64;
      }
    }
  }
  return result;
}

// File Line: 3215
// RVA: 0x131FD0
void __fastcall SSClass::recurse_instance_data(SSClass *this, SSTypedName *typed_p)
{
  SSClass *v2; // rdi
  SSTypedName *v3; // rsi
  SSClass **v4; // rbx
  unsigned __int64 i; // rdi

  v2 = this;
  v3 = typed_p;
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(
    (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&this->i_data_table.i_count,
    typed_p,
    0i64);
  v4 = v2->i_subclasses.i_array_p;
  for ( i = (unsigned __int64)&v4[v2->i_subclasses.i_count]; (unsigned __int64)v4 < i; ++v4 )
    SSClass::recurse_instance_data(*v4, v3);
}

// File Line: 3236
// RVA: 0x131ED0
void __fastcall SSClass::recurse_class_data(SSClass *this, SSTypedData *data_p)
{
  SSClass *v2; // rdi
  SSTypedData *v3; // rsi
  SSClass **v4; // rbx
  unsigned __int64 i; // rdi

  v2 = this;
  v3 = data_p;
  APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol>>::append(
    (APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol> > *)&this->i_class_data_table.i_count,
    data_p,
    0i64);
  v4 = v2->i_subclasses.i_array_p;
  for ( i = (unsigned __int64)&v4[v2->i_subclasses.i_count]; (unsigned __int64)v4 < i; ++v4 )
    SSClass::recurse_class_data(*v4, v3);
}

// File Line: 3287
// RVA: 0x131DA0
void __fastcall SSClass::recurse_class_ctor(SSClass *this, SSInvokedMethod *imethod_p)
{
  SSInvokedMethod *v2; // rdi
  SSClass *v3; // rsi
  __int64 v4; // rax
  SSMethodBase **v5; // r8
  signed __int64 v6; // r10
  unsigned int v7; // er11
  signed __int64 v8; // rdx
  unsigned int v9; // er9
  _BOOL8 v10; // rcx
  _BOOL8 v11; // r9
  SSMethodBase *v12; // rcx
  signed __int64 v13; // rax
  SSClass **v14; // rbx
  unsigned __int64 i; // rsi

  v2 = imethod_p;
  v3 = this;
  if ( !(this->i_flags & 1) )
    return;
  v4 = this->i_class_methods.i_count;
  if ( !(_DWORD)v4 )
    goto LABEL_17;
  v5 = this->i_class_methods.i_array_p;
  v6 = (signed __int64)&v5[v4 - 1];
  v7 = 0;
  while ( 1 )
  {
    v8 = (signed __int64)&v5[(v6 - (signed __int64)v5) >> 4];
    v9 = *(_DWORD *)(*(_QWORD *)v8 + 8i64);
    if ( ASymbolX_ctor.i_uid < v9 )
      goto LABEL_9;
    v10 = ASymbolX_ctor.i_uid == v9;
    v11 = ASymbolX_ctor.i_uid != v9;
    if ( v10 == 1 )
      break;
    if ( v11 < 0 )
    {
LABEL_9:
      if ( v5 == (SSMethodBase **)v8 )
        goto LABEL_17;
      v6 = v8 - 8;
    }
    else
    {
      if ( v6 == v8 )
        goto LABEL_17;
      v5 = (SSMethodBase **)(v8 + 8);
    }
  }
  v12 = *(SSMethodBase **)v8;
  if ( *(_QWORD *)v8 )
  {
    v13 = (signed __int64)&v3->i_metaclass.vfptr;
    if ( v3 == (SSClass *)-240i64 )
      v13 = 0i64;
    v2->i_scope_p.i_obj_p = (SSObjectBase *)v13;
    if ( v13 )
      v7 = *(_DWORD *)(v13 + 8);
    v2->i_scope_p.i_ptr_id = v7;
    v2->i_method_p = v12;
    ((void (__fastcall *)(SSMethodBase *, SSInvokedMethod *, _QWORD, _QWORD))v12->vfptr[1].get_custom_expr)(
      v12,
      v2,
      0i64,
      0i64);
  }
LABEL_17:
  v14 = v3->i_subclasses.i_array_p;
  for ( i = (unsigned __int64)&v14[v3->i_subclasses.i_count]; (unsigned __int64)v14 < i; ++v14 )
  {
    v2->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
    ((void (__fastcall *)(SSClass *, SSInvokedMethod *))(*v14)->vfptr[1].get_key_class_name)(*v14, v2);
  }
}

// File Line: 3323
// RVA: 0x131F30
void __fastcall SSClass::recurse_class_dtor(SSClass *this)
{
  SSClass *v1; // rdi
  __int64 v2; // rax
  SSClass **v3; // rbx
  unsigned __int64 i; // rsi
  SSTypedData **v5; // rbx
  unsigned __int64 j; // rdi
  SSInstance *v7; // rcx
  bool v8; // zf
  SSTypedData *v9; // rcx

  v1 = this;
  if ( this->i_flags & 1 )
  {
    v2 = this->i_subclasses.i_count;
    if ( (_DWORD)v2 )
    {
      v3 = this->i_subclasses.i_array_p;
      for ( i = (unsigned __int64)&v3[v2]; (unsigned __int64)v3 < i; ++v3 )
        SSClass::recurse_class_dtor(*v3);
    }
    v5 = v1->i_class_data.i_array_p;
    for ( j = (unsigned __int64)&v5[v1->i_class_data.i_count]; (unsigned __int64)v5 < j; v9->i_data_p = SSBrain::c_nil_p )
    {
      v7 = (*v5)->i_data_p;
      v8 = v7->i_ref_count-- == 1;
      if ( v8 )
      {
        v7->i_ref_count = 2147483648;
        ((void (*)(void))v7->vfptr[1].get_scope_context)();
      }
      v9 = *v5;
      ++v5;
    }
  }
}

// File Line: 3352
// RVA: 0x13C630
void __fastcall SSClass::set_destructor(SSClass *this, SSMethodBase *destructor_p)
{
  SSMethodBase *v2; // rax
  SSMethodBase *v3; // rdi
  SSClass *v4; // rsi
  SSClass *v5; // rdx
  SSClass *v6; // rax
  SSClass *v7; // rcx
  __int64 v8; // rax
  SSClass **v9; // rbx
  unsigned __int64 i; // rsi

  v2 = this->i_destructor_p;
  v3 = destructor_p;
  v4 = this;
  if ( !v2
    || (v5 = v2->i_scope_p, v6 = v3->i_scope_p, v5 == v6)
    || (v7 = v6->i_superclass_p) != 0i64 && SSClass::is_class(v7, v5) )
  {
    v8 = v4->i_subclasses.i_count;
    v9 = v4->i_subclasses.i_array_p;
    v4->i_destructor_p = v3;
    for ( i = (unsigned __int64)&v9[v8]; (unsigned __int64)v9 < i; ++v9 )
      SSClass::set_destructor(*v9, v3);
  }
}

// File Line: 3374
// RVA: 0x11E0E0
void __fastcall SSClass::invoke_class_ctor_recurse(SSClass *this)
{
  SSClass *v1; // rdi
  AObjReusePool<SSInvokedMethod> *v2; // rax
  AObjReusePool<SSInvokedMethod> *v3; // rbx
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  __int64 v7; // rcx
  SSInvokedMethod **v8; // rax
  SSInvokedMethod *v9; // rbx
  unsigned int v10; // eax

  v1 = this;
  v2 = SSInvokedMethod::get_pool();
  v3 = v2;
  v4 = v2->i_pool.i_count;
  if ( v4 )
  {
    v10 = v4 - 1;
    v3->i_pool.i_count = v10;
    v7 = v10;
    v8 = v3->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !v3->i_exp_pool.i_count )
    AObjReusePool<SSInvokedMethod>::append_block(v3, v3->i_expand_size);
  v5 = v3->i_exp_pool.i_count;
  if ( v5 )
  {
    v6 = v5 - 1;
    v3->i_exp_pool.i_count = v6;
    v7 = v6;
    v8 = v3->i_exp_pool.i_array_p;
LABEL_8:
    v9 = v8[v7];
    goto LABEL_9;
  }
  v9 = 0i64;
LABEL_9:
  v9->i_caller_p.i_obj_p = 0i64;
  v9->i_caller_p.i_ptr_id = 0;
  v9->i_scope_p.i_obj_p = 0i64;
  v9->i_scope_p.i_ptr_id = 0;
  v9->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  v9->i_method_p = 0i64;
  ((void (__fastcall *)(SSClass *, SSInvokedMethod *))v1->vfptr[1].get_key_class_name)(v1, v9);
  SSInvokedMethod::pool_delete(v9);
}

// File Line: 3406
// RVA: 0x113AA0
void __fastcall SSClass::demand_unload_recurse(SSClass *this)
{
  __int64 v1; // rax
  SSClass *v2; // rsi
  SSClass **v3; // rbx
  unsigned __int64 i; // rdi

  v1 = this->i_subclasses.i_count;
  v2 = this;
  if ( (_DWORD)v1 )
  {
    v3 = this->i_subclasses.i_array_p;
    for ( i = (unsigned __int64)&v3[v1]; (unsigned __int64)v3 < i; ++v3 )
      SSClass::demand_unload_recurse(*v3);
  }
  ((void (__fastcall *)(SSClass *))v2->vfptr[1].is_class_type)(v2);
}

// File Line: 3426
// RVA: 0x113A70
char __fastcall SSClass::demand_unload(SSClass *this)
{
  if ( (this->i_flags & 3) != 3 || (this->i_flags >> 2) & 1 )
    return 0;
  SSClass::demand_unload_recurse(this);
  return 1;
}

// File Line: 3516
// RVA: 0x1461590
__int64 dynamic_initializer_for__SSClassUnion::c_shared_unions__()
{
  return atexit(dynamic_atexit_destructor_for__SSClassUnion::c_shared_unions__);
}

// File Line: 3531
// RVA: 0x112580
signed int __fastcall SSClassUnion::compare(SSClassUnion *this, SSClassUnion *class_union)
{
  signed int result; // eax
  __int64 v3; // r8
  unsigned int v4; // er9
  SSClassDescBase **v5; // rbx
  unsigned __int64 v6; // rsi
  SSClassDescBase **v7; // rdi

  if ( this == class_union )
    return 0;
  v3 = this->i_union.i_count;
  v4 = class_union->i_union.i_count;
  if ( (_DWORD)v3 == v4 )
  {
    v5 = (SSClassDescBase **)this->i_union.i_array_p;
    v6 = (unsigned __int64)&v5[v3];
    v7 = (SSClassDescBase **)class_union->i_union.i_array_p;
    if ( (unsigned __int64)v5 >= v6 )
    {
LABEL_10:
      result = 0;
    }
    else
    {
      while ( 1 )
      {
        result = SSClassDescBase::compare(*v5, *v7, (__int64)v5);
        if ( result )
          break;
        ++v5;
        ++v7;
        if ( (unsigned __int64)v5 >= v6 )
          goto LABEL_10;
      }
    }
  }
  else
  {
    result = 1;
    if ( (unsigned int)v3 < v4 )
      result = -1;
  }
  return result;
}

// File Line: 3580
// RVA: 0x11F930
void __fastcall SSClassUnion::merge_class(SSClassUnion *this, SSClassUnaryBase *new_class)
{
  SSClassUnaryBase *v2; // rdi
  SSClassUnion *v3; // r15
  SSClassUnaryBase **v4; // rbx
  unsigned __int64 v5; // rbp
  __int64 v6; // rsi
  SSClassUnaryBase **v7; // rax
  signed __int64 v8; // rcx
  __int64 v9; // rbx

  v2 = new_class;
  v3 = this;
  if ( this->i_common_class_p )
  {
    v4 = this->i_union.i_array_p;
    v5 = (unsigned __int64)&v4[this->i_union.i_count];
    if ( (unsigned __int64)v4 >= v5 )
    {
LABEL_10:
      (*(void (__fastcall **)(SSClassUnaryBase *))v2->vfptr->gap8)(v2);
      APSorted<SSClassUnaryBase,SSClassUnaryBase,SSClassUnaryBase>::append(&v3->i_union, v2, 0i64);
      v9 = (__int64)v2->vfptr->find_common_type(
                      (SSClassDescBase *)&v2->vfptr,
                      (SSClassDescBase *)&v3->i_common_class_p->vfptr);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 8i64))(v9);
      ((void (*)(void))v3->i_common_class_p->vfptr->dereference_delay)();
      v3->i_common_class_p = (SSClassUnaryBase *)v9;
    }
    else
    {
      v6 = 0i64;
      while ( !v2->vfptr->is_class_type((SSClassDescBase *)&v2->vfptr, (SSClassDescBase *)&(*v4)->vfptr) )
      {
        if ( (*v4)->vfptr->is_class_type((SSClassDescBase *)&(*v4)->vfptr, (SSClassDescBase *)&v2->vfptr) )
        {
          v7 = v3->i_union.i_array_p;
          --v3->i_union.i_count;
          v8 = (signed __int64)&v7[(unsigned int)(v6 >> 3)];
          memmove((void *)v8, (const void *)(v8 + 8), 8i64 * (v3->i_union.i_count - (unsigned int)(v6 >> 3)));
          v5 -= 8i64;
        }
        else
        {
          ++v4;
          v6 += 8i64;
        }
        if ( (unsigned __int64)v4 >= v5 )
          goto LABEL_10;
      }
    }
  }
  else
  {
    (*(void (__fastcall **)(SSClassUnaryBase *))new_class->vfptr->gap8)(new_class);
    (*(void (__fastcall **)(SSClassUnaryBase *))v2->vfptr->gap8)(v2);
    APSorted<SSClassUnaryBase,SSClassUnaryBase,SSClassUnaryBase>::append(&v3->i_union, v2, 0i64);
    v3->i_common_class_p = v2;
  }
}

// File Line: 3645
// RVA: 0x11F890
void __fastcall SSClassUnion::merge_class(SSClassUnion *this, SSClassDescBase *new_class)
{
  SSClassUnion *v2; // rdi
  SSClassUnion *v3; // rsi
  SSClassUnaryBase **v4; // rbx
  unsigned __int64 i; // rsi

  v2 = this;
  v3 = (SSClassUnion *)new_class;
  if ( new_class->vfptr->get_class_type(new_class) == 4 )
  {
    if ( v3->i_common_class_p )
    {
      if ( v2->i_common_class_p )
      {
        v4 = v3->i_union.i_array_p;
        for ( i = (unsigned __int64)&v4[v3->i_union.i_count]; (unsigned __int64)v4 < i; ++v4 )
          SSClassUnion::merge_class(v2, *v4);
      }
      else
      {
        SSClassUnion::operator=(v2, v3);
      }
    }
  }
  else
  {
    SSClassUnion::merge_class(v2, (SSClassUnaryBase *)v3);
  }
}

// File Line: 3805
// RVA: 0x110FA0
void __fastcall SSClassUnion::assign_binary(SSClassUnion *this, const void **binary_pp)
{
  SSClassUnion *v2; // rbx
  const void **v3; // rdi
  eSSClassType v4; // ecx
  SSClassDescBase *v5; // rax
  SSClassUnaryBase *v6; // rsi
  SSClassUnaryBase *v7; // rcx
  __int64 v8; // rsi
  unsigned int v9; // eax
  SSClassUnaryBase **v10; // rcx
  _QWORD *i; // r14
  eSSClassType v12; // ecx
  SSClassDescBase *v13; // rbx

  v2 = this;
  v3 = binary_pp;
  v4 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  v5 = SSClassDescBase::from_binary_ref(v4, binary_pp);
  v6 = (SSClassUnaryBase *)v5;
  if ( v5 )
    (*(void (__fastcall **)(SSClassDescBase *))v5->vfptr->gap8)(v5);
  v7 = v2->i_common_class_p;
  if ( v7 )
    ((void (*)(void))v7->vfptr->dereference_delay)();
  v2->i_common_class_p = v6;
  v8 = *(unsigned __int8 *)*v3;
  *v3 = (char *)*v3 + 1;
  if ( v2->i_union.i_size < (unsigned int)v8 )
  {
    v9 = AMemory::c_req_byte_size_func(8 * v8);
    v10 = v2->i_union.i_array_p;
    v2->i_union.i_size = v9 >> 3;
    AMemory::c_free_func(v10);
    v2->i_union.i_array_p = APArrayBase<SSClassUnaryBase>::alloc_array(v2->i_union.i_size);
  }
  memset(v2->i_union.i_array_p, 0, 8 * v8);
  v2->i_union.i_count = v8;
  for ( i = v2->i_union.i_array_p; (_DWORD)v8; LODWORD(v8) = v8 - 1 )
  {
    v12 = *(unsigned __int8 *)*v3;
    *v3 = (char *)*v3 + 1;
    v13 = SSClassDescBase::from_binary_ref(v12, v3);
    (*(void (__fastcall **)(SSClassDescBase *))v13->vfptr->gap8)(v13);
    *i = v13;
    ++i;
  }
}

// File Line: 3890
// RVA: 0x11EC80
char __fastcall SSClassUnion::is_generic(SSClassUnion *this)
{
  SSClassUnaryBase **v1; // rbx
  unsigned __int64 v2; // rdi

  v1 = this->i_union.i_array_p;
  v2 = (unsigned __int64)&v1[this->i_union.i_count];
  if ( (unsigned __int64)v1 >= v2 )
    return 0;
  while ( !((unsigned __int8 (*)(void))(*v1)->vfptr->is_generic)() )
  {
    ++v1;
    if ( (unsigned __int64)v1 >= v2 )
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
  SSClassUnaryBase **v4; // r15
  char v5; // r14
  unsigned __int64 v6; // r13
  SSClassUnion *v7; // r12
  SSClassUnion *v8; // rdi
  SSClassUnaryBase **v9; // rbx
  unsigned __int64 i; // rsi
  SSClassUnaryBase *v11; // rsi
  __int64 *v12; // rbx
  SSClassUnaryBase **v13; // rdi
  __int64 *v15; // rbx
  SSClassUnaryBase **v16; // rdi
  SSClassUnion class_union; // [rsp+28h] [rbp-38h]
  SSClassUnion *v18; // [rsp+A0h] [rbp+40h]
  SSClassDescBase *v19; // [rsp+A8h] [rbp+48h]

  v19 = scope_type;
  v18 = this;
  v2 = scope_type;
  v3 = this;
  if ( !((unsigned __int8 (__cdecl *)(SSClassUnion *))this->vfptr->is_generic)(this) )
    return v3;
  class_union.i_ref_count = 0;
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
  class_union.i_common_class_p = 0i64;
  class_union.i_union.i_count = 0;
  class_union.i_union.i_array_p = 0i64;
  class_union.i_union.i_size = 0;
  v4 = v3->i_union.i_array_p;
  v5 = 0;
  if ( v4 >= &v4[v3->i_union.i_count] )
    goto LABEL_35;
  v6 = (unsigned __int64)&v4[v3->i_union.i_count];
  do
  {
    v7 = (SSClassUnion *)*v4;
    v8 = (SSClassUnion *)(*v4)->vfptr->as_finalized_generic((SSClassDescBase *)&(*v4)->vfptr, v2);
    if ( v8->vfptr->get_class_type((SSClassDescBase *)&v8->vfptr) == 4 )
    {
      if ( v8->i_common_class_p )
      {
        if ( class_union.i_common_class_p )
        {
          v9 = v8->i_union.i_array_p;
          for ( i = (unsigned __int64)&v9[v8->i_union.i_count]; (unsigned __int64)v9 < i; ++v9 )
            SSClassUnion::merge_class(&class_union, *v9);
          v2 = v19;
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
    ++v4;
  }
  while ( (unsigned __int64)v4 < v6 );
  v3 = v18;
  if ( !v5 )
  {
LABEL_35:
    class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
    if ( class_union.i_common_class_p )
      ((void (*)(void))class_union.i_common_class_p->vfptr->dereference_delay)();
    if ( class_union.i_union.i_count )
    {
      v15 = (__int64 *)class_union.i_union.i_array_p;
      v16 = &class_union.i_union.i_array_p[class_union.i_union.i_count];
      if ( class_union.i_union.i_array_p < v16 )
      {
        do
        {
           SSClassDescBase::`vcall'{24,{flat}}(*v15);
          ++v15;
        }
        while ( v15 < (__int64 *)v16 );
      }
    }
    AMemory::c_free_func(class_union.i_union.i_array_p);
    class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable';
    return v3;
  }
  if ( class_union.i_union.i_count > 1 )
    v11 = (SSClassUnaryBase *)SSClassUnion::get_or_create(&class_union);
  else
    v11 = class_union.i_common_class_p;
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
  if ( class_union.i_common_class_p )
    ((void (*)(void))class_union.i_common_class_p->vfptr->dereference_delay)();
  if ( class_union.i_union.i_count )
  {
    v12 = (__int64 *)class_union.i_union.i_array_p;
    v13 = &class_union.i_union.i_array_p[class_union.i_union.i_count];
    if ( class_union.i_union.i_array_p < v13 )
    {
      do
      {
         SSClassDescBase::`vcall'{24,{flat}}(*v12);
        ++v12;
      }
      while ( v12 < (__int64 *)v13 );
    }
  }
  AMemory::c_free_func(class_union.i_union.i_array_p);
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable';
  return (SSClassUnion *)v11;
}

// File Line: 3958
// RVA: 0x114EC0
hkDataWorld *__fastcall ArrayOfTuplesImplementation::View::getWorld(ArrayOfTuplesImplementation::View *this)
{
  return (hkDataWorld *)((__int64 (*)(void))this->m_owner->vfptr[7].__vecDelDtor)();
}

// File Line: 4003
// RVA: 0x11E760
char __fastcall SSClassUnion::is_class_maybe(SSClassUnion *this, SSClassDescBase *type_p)
{
  SSClassUnaryBase **v2; // rbx
  SSClassDescBase *v3; // rsi
  unsigned __int64 v4; // rdi

  v2 = this->i_union.i_array_p;
  v3 = type_p;
  v4 = (unsigned __int64)&v2[this->i_union.i_count];
  if ( (unsigned __int64)v2 >= v4 )
    return 0;
  while ( !(*v2)->vfptr->is_class_type((SSClassDescBase *)&(*v2)->vfptr, v3) )
  {
    ++v2;
    if ( (unsigned __int64)v2 >= v4 )
      return 0;
  }
  return 1;
}

// File Line: 4025
// RVA: 0x11F790
char __fastcall SSClassUnion::is_valid_param_for(SSClassUnion *this, SSClassDescBase *arg_type_p)
{
  SSClassUnaryBase **v2; // rbx
  SSClassDescBase *v3; // rsi
  unsigned __int64 v4; // rdi

  v2 = this->i_union.i_array_p;
  v3 = arg_type_p;
  v4 = (unsigned __int64)&v2[this->i_union.i_count];
  if ( (unsigned __int64)v2 >= v4 )
    return 0;
  while ( !v3->vfptr->is_class_type(v3, (SSClassDescBase *)&(*v2)->vfptr) )
  {
    ++v2;
    if ( (unsigned __int64)v2 >= v4 )
      return 0;
  }
  return 1;
}

// File Line: 4049
// RVA: 0x11E8D0
char __fastcall SSClassUnion::is_class_type(SSClassUnion *this, SSClassDescBase *type_p)
{
  SSClassUnaryBase **v2; // rbx
  SSClassDescBase *v3; // rsi
  unsigned __int64 v4; // rdi

  v2 = this->i_union.i_array_p;
  v3 = type_p;
  v4 = (unsigned __int64)&v2[this->i_union.i_count];
  if ( (unsigned __int64)v2 >= v4 )
    return 1;
  while ( (*v2)->vfptr->is_class_type((SSClassDescBase *)&(*v2)->vfptr, v3) )
  {
    ++v2;
    if ( (unsigned __int64)v2 >= v4 )
      return 1;
  }
  return 0;
}

// File Line: 4077
// RVA: 0x117B40
SSClassUnaryBase *__fastcall SSClassUnion::get_merge(SSClassDescBase *class1, SSClassDescBase *class2, __int64 a3)
{
  SSClassUnion *v3; // rdi
  SSClassUnion *v4; // r14
  __int64 v5; // rdx
  __int64 v6; // r8
  SSClassUnaryBase **v7; // rbx
  unsigned __int64 i; // rsi
  SSClassUnaryBase *v9; // r15
  __int64 *v10; // rbx
  SSClassUnaryBase **v11; // rsi
  SSClassUnion class_union; // [rsp+28h] [rbp-38h]

  v3 = (SSClassUnion *)class2;
  v4 = (SSClassUnion *)class1;
  class_union.i_ref_count = 0;
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
  class_union.i_common_class_p = 0i64;
  class_union.i_union.i_count = 0;
  class_union.i_union.i_array_p = 0i64;
  class_union.i_union.i_size = 0;
  if ( ((unsigned int (__cdecl *)(SSClassDescBase *, SSClassDescBase *, __int64))class1->vfptr->get_class_type)(
         class1,
         class2,
         a3) == 4 )
  {
    if ( v4->i_common_class_p )
      SSClassUnion::operator=(&class_union, v4);
  }
  else
  {
    SSClassUnion::merge_class(&class_union, (SSClassUnaryBase *)v4);
  }
  (*(void (__fastcall **)(SSClassUnion *))v4->vfptr->gap8)(v4);
  (*(void (__fastcall **)(SSClassUnion *))v3->vfptr->gap8)(v3);
  if ( v3->vfptr->get_class_type((SSClassDescBase *)&v3->vfptr) == 4 )
  {
    if ( v3->i_common_class_p )
    {
      if ( class_union.i_common_class_p )
      {
        v7 = v3->i_union.i_array_p;
        for ( i = (unsigned __int64)&v7[v3->i_union.i_count]; (unsigned __int64)v7 < i; ++v7 )
          SSClassUnion::merge_class(&class_union, *v7);
      }
      else
      {
        SSClassUnion::operator=(&class_union, v3);
      }
    }
  }
  else
  {
    SSClassUnion::merge_class(&class_union, (SSClassUnaryBase *)v3);
  }
  if ( class_union.i_union.i_count > 1 )
    v9 = (SSClassUnaryBase *)SSClassUnion::get_or_create(&class_union);
  else
    v9 = class_union.i_common_class_p;
  if ( class_union.i_union.i_count )
  {
    v10 = (__int64 *)class_union.i_union.i_array_p;
    v11 = &class_union.i_union.i_array_p[class_union.i_union.i_count];
    if ( class_union.i_union.i_array_p < v11 )
    {
      do
      {
         SSClassDescBase::`vcall'{24,{flat}}(*v10);
        ++v10;
      }
      while ( v10 < (__int64 *)v11 );
    }
  }
  class_union.i_union.i_count = 0;
  if ( class_union.i_common_class_p )
    ((void (__cdecl *)(SSClassUnaryBase *, __int64, __int64))class_union.i_common_class_p->vfptr->dereference_delay)(
      class_union.i_common_class_p,
      v5,
      v6);
  class_union.i_common_class_p = 0i64;
  v4->vfptr->dereference_delay((SSClassDescBase *)&v4->vfptr);
  v3->vfptr->dereference_delay((SSClassDescBase *)&v3->vfptr);
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
  AMemory::c_free_func(class_union.i_union.i_array_p);
  return v9;
}

// File Line: 4115
// RVA: 0x117CE0
SSClassUnaryBase *__fastcall SSClassUnion::get_merge(APArrayBase<SSClassDescBase> *classes, __int64 object_on_empty_b)
{
  APArrayBase<SSClassDescBase> *v2; // r12
  __int64 v3; // r8
  SSClassDescBase **v4; // rsi
  unsigned __int64 v5; // r13
  SSClassUnion *v6; // rbx
  SSClassUnaryBase **v7; // r15
  __int64 v8; // rdx
  __int64 v9; // r8
  __int64 v10; // rdx
  __int64 v11; // r8
  SSClassUnion **v12; // rsi
  SSClassUnion *v13; // rdi
  SSClassUnaryBase **v14; // rbx
  unsigned __int64 i; // rdi
  SSClassUnaryBase *v16; // rsi
  __int64 *v17; // rbx
  unsigned __int64 v18; // rdi
  __int64 v19; // rax
  __int64 *v20; // rbx
  unsigned __int64 j; // rdi
  SSClassDescBase *v23; // r14
  SSClassDescBase *v24; // rdx
  SSClass *v25; // r14
  SSClassUnion class_union; // [rsp+28h] [rbp-38h]

  v2 = classes;
  v3 = classes->i_count;
  if ( !(_DWORD)v3 )
  {
    v25 = 0i64;
    if ( (_BYTE)object_on_empty_b )
      v25 = SSBrain::c_object_class_p;
    return (SSClassUnaryBase *)v25;
  }
  if ( (_DWORD)v3 == 1 )
    return (SSClassUnaryBase *)*classes->i_array_p;
  if ( (_DWORD)v3 != 2 )
  {
    v4 = classes->i_array_p;
    v5 = (unsigned __int64)&v4[v3];
    v6 = (SSClassUnion *)*v4;
    class_union.i_ref_count = 0;
    class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
    class_union.i_common_class_p = 0i64;
    class_union.i_union.i_count = 0;
    v7 = 0i64;
    class_union.i_union.i_array_p = 0i64;
    class_union.i_union.i_size = 0;
    if ( ((unsigned int (__fastcall *)(SSClassUnion *, __int64))v6->vfptr->get_class_type)(v6, object_on_empty_b) == 4 )
    {
      if ( !v6->i_common_class_p )
      {
LABEL_9:
        (*(void (__cdecl **)(SSClassDescBase *, __int64, __int64))(*v4)->vfptr->gap8)(*v4, v8, v9);
        v12 = (SSClassUnion **)(v4 + 1);
        if ( (unsigned __int64)v12 < v5 )
        {
          do
          {
            (*(void (__cdecl **)(SSClassUnion *, __int64, __int64))(*v12)->vfptr->gap8)(*v12, v10, v11);
            v13 = *v12;
            if ( (*v12)->vfptr->get_class_type((SSClassDescBase *)*v12) == 4 )
            {
              if ( v13->i_common_class_p )
              {
                if ( class_union.i_common_class_p )
                {
                  v14 = v13->i_union.i_array_p;
                  for ( i = (unsigned __int64)&v14[v13->i_union.i_count]; (unsigned __int64)v14 < i; ++v14 )
                    SSClassUnion::merge_class(&class_union, *v14);
                }
                else
                {
                  SSClassUnion::operator=(&class_union, v13);
                }
              }
            }
            else
            {
              SSClassUnion::merge_class(&class_union, (SSClassUnaryBase *)v13);
            }
            ++v12;
          }
          while ( (unsigned __int64)v12 < v5 );
          v7 = class_union.i_union.i_array_p;
        }
        if ( class_union.i_union.i_count > 1 )
        {
          v16 = (SSClassUnaryBase *)SSClassUnion::get_or_create(&class_union);
          v7 = class_union.i_union.i_array_p;
        }
        else
        {
          v16 = class_union.i_common_class_p;
        }
        if ( class_union.i_union.i_count )
        {
          v17 = (__int64 *)v7;
          v18 = (unsigned __int64)&v7[class_union.i_union.i_count];
          if ( (unsigned __int64)v7 < v18 )
          {
            do
            {
               SSClassDescBase::`vcall'{24,{flat}}(*v17);
              ++v17;
            }
            while ( (unsigned __int64)v17 < v18 );
          }
        }
        class_union.i_union.i_count = 0;
        if ( class_union.i_common_class_p )
          ((void (__cdecl *)(SSClassUnaryBase *, __int64, __int64))class_union.i_common_class_p->vfptr->dereference_delay)(
            class_union.i_common_class_p,
            v10,
            v11);
        class_union.i_common_class_p = 0i64;
        v19 = v2->i_count;
        if ( (_DWORD)v19 )
        {
          v20 = (__int64 *)v2->i_array_p;
          for ( j = (unsigned __int64)&v20[v19]; (unsigned __int64)v20 < j; ++v20 )
             SSClassDescBase::`vcall'{24,{flat}}(*v20);
        }
        class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
        AMemory::c_free_func(v7);
        class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable';
        return v16;
      }
      SSClassUnion::operator=(&class_union, v6);
    }
    else
    {
      SSClassUnion::merge_class(&class_union, (SSClassUnaryBase *)v6);
    }
    v7 = class_union.i_union.i_array_p;
    goto LABEL_9;
  }
  v23 = 0i64;
  if ( (_DWORD)v3 )
    v24 = classes->i_array_p[(unsigned int)(v3 - 1)];
  else
    v24 = 0i64;
  if ( (_DWORD)v3 )
    v23 = *classes->i_array_p;
  return SSClassUnion::get_merge(v23, v24, v3);
}

// File Line: 4175
// RVA: 0x119010
SSClassUnion *__fastcall SSClassUnion::get_reduced(SSClassUnion *class_union, SSClassUnaryBase *class_to_remove)
{
  SSClassUnaryBase *v2; // r14
  SSClassUnion *v3; // rbp
  unsigned int v4; // eax
  SSClassUnaryBase **v5; // rdi
  signed __int64 v6; // rsi
  SSClassDescBase **v7; // rbx
  signed int v8; // eax
  signed __int64 v9; // rbx
  SSClassDescBase **v10; // rax
  SSClassDescBase **v11; // rsi
  unsigned int v12; // edi
  __int64 v13; // rdx
  SSClassUnaryBase *v14; // rbx
  APArrayBase<SSClassDescBase> classes; // [rsp+28h] [rbp-20h]
  unsigned int v17; // [rsp+38h] [rbp-10h]

  v2 = class_to_remove;
  v3 = class_union;
  v4 = class_union->i_union.i_count;
  if ( !v4 )
    return v3;
  v5 = class_union->i_union.i_array_p;
  v6 = (signed __int64)&v5[v4 - 1];
  while ( 1 )
  {
    while ( 1 )
    {
      v7 = (SSClassDescBase **)&v5[(v6 - (signed __int64)v5) >> 4];
      v8 = SSClassDescBase::compare((SSClassDescBase *)&v2->vfptr, *v7, (__int64)v7);
      if ( v8 >= 0 )
        break;
      if ( v5 == (SSClassUnaryBase **)v7 )
        return v3;
      v6 = (signed __int64)(v7 - 1);
    }
    if ( v8 <= 0 )
      break;
    if ( (SSClassDescBase **)v6 == v7 )
      return v3;
    v5 = (SSClassUnaryBase **)(v7 + 1);
  }
  v9 = ((char *)v7 - (char *)v3->i_union.i_array_p) >> 3;
  v10 = (SSClassDescBase **)APArrayBase<SSClassUnaryBase>::alloc_array(v3->i_union.i_count);
  v11 = v10;
  v12 = v3->i_union.i_count;
  classes.i_count = v12;
  classes.i_array_p = v10;
  v17 = v12;
  memmove(v10, v3->i_union.i_array_p, 8i64 * v12);
  classes.i_count = v12 - 1;
  memmove(&v11[(unsigned int)v9], &v11[(unsigned int)v9 + 1], 8i64 * (v12 - 1 - (unsigned int)v9));
  LOBYTE(v13) = 1;
  v14 = SSClassUnion::get_merge(&classes, v13);
  AMemory::c_free_func(v11);
  return (SSClassUnion *)v14;
}


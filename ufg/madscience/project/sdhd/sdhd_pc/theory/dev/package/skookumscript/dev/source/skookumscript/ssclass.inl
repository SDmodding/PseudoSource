// File Line: 62
// RVA: 0x117B30
ANamed *__fastcall SSMetaClass::get_key_class_name(SSMetaClass *this)
{
  return &this->i_class_info_p->ANamed;
}

// File Line: 83
// RVA: 0x117FC0
SSMethodBase *__fastcall SSMetaClass::get_method(SSMetaClass *this, ASymbol *method_name)
{
  return APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
           &this->i_class_info_p->i_class_methods,
           method_name);
}

// File Line: 94
// RVA: 0x118060
SSMethodBase *__fastcall SSMetaClass::get_method_inherited(SSMetaClass *this, ASymbol *method_name)
{
  SSClass *i_class_info_p; // rdi
  SSMethodBase *result; // rax
  SSClass *i_superclass_p; // rcx

  i_class_info_p = this->i_class_info_p;
  result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(&i_class_info_p->i_class_methods, method_name);
  if ( !result )
  {
    i_superclass_p = i_class_info_p->i_superclass_p;
    if ( i_superclass_p )
      return SSClass::get_class_method_inherited(i_superclass_p, method_name);
    else
      return APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
               &SSBrain::c_object_class_p->i_methods,
               method_name);
  }
  return result;
}

// File Line: 109
// RVA: 0x10E190
void __fastcall SSMetaClass::append_method(SSMetaClass *this, SSMethodBase *method_p)
{
  SSClass *i_class_info_p; // rcx
  SSMethodBase *appended; // rax

  i_class_info_p = this->i_class_info_p;
  method_p->i_scope_p = i_class_info_p;
  appended = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::append_replace(
               &i_class_info_p->i_class_methods,
               method_p,
               0i64);
  if ( appended )
    appended->vfptr->__vecDelDtor(appended, 1u);
}

// File Line: 131
// RVA: 0x11F200
bool __fastcall SSMetaClass::is_method_valid(SSMetaClass *this, ASymbol *method_name)
{
  return APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
           &this->i_class_info_p->i_class_methods,
           method_name) != 0i64;
}

// File Line: 142
// RVA: 0x11F0F0
bool __fastcall SSMetaClass::is_method_inherited_valid(SSMetaClass *this, ASymbol *method_name)
{
  SSClass *i_class_info_p; // rdi
  SSMethodBase *v4; // rcx
  SSClass *i_superclass_p; // rcx
  SSMethodBase *class_method_inherited; // rax

  i_class_info_p = this->i_class_info_p;
  v4 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(&i_class_info_p->i_class_methods, method_name);
  if ( !v4 )
  {
    i_superclass_p = i_class_info_p->i_superclass_p;
    if ( i_superclass_p )
      class_method_inherited = SSClass::get_class_method_inherited(i_superclass_p, method_name);
    else
      class_method_inherited = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
                                 &SSBrain::c_object_class_p->i_methods,
                                 method_name);
    v4 = class_method_inherited;
  }
  return v4 != 0i64;
}

// File Line: 157
// RVA: 0x10DE90
void __fastcall SSMetaClass::append_coroutine(SSMetaClass *this, SSCoroutineBase *coroutine_p)
{
  AErrMsg *v2; // rax
  AErrMsg err_msg; // [rsp+40h] [rbp-78h] BYREF
  AErrMsg v4; // [rsp+78h] [rbp-40h] BYREF
  eAErrAction action_p; // [rsp+D0h] [rbp+18h] BYREF

  if ( `SSMetaClass::append_coroutine::`3::_test )
  {
    AErrMsg::AErrMsg(&err_msg, "Class coroutines not yet implemented!", AErrLevel_error, 0i64, 0i64);
    AErrMsg::AErrMsg(
      &v4,
      &err_msg,
      0i64,
      "void __cdecl SSMetaClass::append_coroutine(class SSCoroutineBase *)",
      "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\package\\skookumscript\\dev\\source\\skookumscript\\ssclass.inl",
      0xA0u,
      1u);
    if ( ADebug::resolve_error(v2, &action_p, &`SSMetaClass::append_coroutine::`3::_test) )
      __debugbreak();
    if ( action_p != AErrAction_ignore )
      __debugbreak();
  }
}

// File Line: 179
// RVA: 0x10DF50
SSTypedData *__fastcall SSMetaClass::append_data_member(SSMetaClass *this, ASymbol *name, SSClassDescBase *type_p)
{
  return SSClass::append_class_data(this->i_class_info_p, name, type_p, Subclass_recurse);
}

// File Line: 282
// RVA: 0x114D20
SSClass *__fastcall SSClass::find_common_class(SSClass *this, SSClass *cls)
{
  SSClass *i_superclass_p; // rcx

  while ( cls != this )
  {
    i_superclass_p = this->i_superclass_p;
    if ( i_superclass_p )
    {
      if ( SSClass::is_class(i_superclass_p, cls) )
        break;
    }
    cls = cls->i_superclass_p;
    if ( !cls )
      return 0i64;
  }
  return cls;
}

// File Line: 308
// RVA: 0x11E730
bool __fastcall SSClass::is_class(SSClass *this, SSClass *cls)
{
  SSClass *i_superclass_p; // rcx
  bool result; // al

  result = 1;
  if ( cls != this )
  {
    i_superclass_p = this->i_superclass_p;
    if ( !i_superclass_p || !SSClass::is_class(i_superclass_p, cls) )
      return 0;
  }
  return result;
}

// File Line: 320
// RVA: 0x11F380
bool __fastcall SSClass::is_subclass(SSClass *this, SSClass *superclass)
{
  SSClass *i_superclass_p; // rcx

  i_superclass_p = this->i_superclass_p;
  return i_superclass_p == superclass || i_superclass_p && SSClass::is_subclass(i_superclass_p, superclass);
}

// File Line: 336
// RVA: 0x11F3B0
bool __fastcall SSClass::is_superclass(SSClass *this, SSClass *subclass)
{
  SSClass *i_superclass_p; // rdx

  i_superclass_p = subclass->i_superclass_p;
  return i_superclass_p == this || i_superclass_p && SSClass::is_superclass(this, i_superclass_p);
}

// File Line: 352
// RVA: 0x11F310
bool __fastcall SSClass::is_scope_qualifier(SSClass *this, SSClassDescBase *recv_type_p)
{
  SSClass *vfptr; // rax
  SSClass *i_superclass_p; // rcx

  if ( !recv_type_p )
    return 1;
  if ( recv_type_p->vfptr->get_class_type(recv_type_p) != SSClassType_metaclass )
    return recv_type_p->vfptr->is_class_type(recv_type_p, this);
  vfptr = (SSClass *)recv_type_p[7].vfptr;
  if ( this == vfptr )
    return 1;
  i_superclass_p = vfptr->i_superclass_p;
  if ( !i_superclass_p )
    return 0;
  return SSClass::is_class(i_superclass_p, this);
}

// File Line: 383
// RVA: 0x117660
SSMethodBase *__fastcall SSClass::get_coroutine_inherited(SSClass *this, ASymbol *coroutine_name)
{
  SSMethodBase *result; // rax
  SSClass *i_superclass_p; // rcx

  result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
             (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_coroutines,
             coroutine_name);
  if ( !result )
  {
    i_superclass_p = this->i_superclass_p;
    if ( i_superclass_p )
      return (SSMethodBase *)i_superclass_p->vfptr->get_coroutine_inherited(i_superclass_p, coroutine_name);
    else
      return 0i64;
  }
  return result;
}

// File Line: 416
// RVA: 0x11EB40
bool __fastcall SSClass::is_coroutine_registered(SSClass *this, ASymbol *coroutine_name)
{
  SSMethodBase *v2; // rax

  v2 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_coroutines,
         coroutine_name);
  return v2 && !v2->vfptr->is_placeholder(v2);
}

// File Line: 430
// RVA: 0x126960
SSDataInstance *__fastcall SSClass::new_instance(SSClass *this)
{
  if ( this->i_data.i_count )
    return SSDataInstance::pool_new(this);
  else
    return (SSDataInstance *)SSInstance::pool_new(this);
}

// File Line: 478
// RVA: 0x117AB0
SSClass *__fastcall SSClass::get_item_type(SSClass *this)
{
  SSClass *result; // rax

  result = 0i64;
  if ( this == SSBrain::c_list_class_p )
    return SSBrain::c_object_class_p;
  return result;
}

// File Line: 491
// RVA: 0x117F70
SSMethodBase *__fastcall SSClass::get_method(SSClass *this, ASymbol *method_name)
{
  SSMethodBase *result; // rax

  result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(&this->i_methods, method_name);
  if ( !result )
    return APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(&this->i_class_methods, method_name);
  return result;
}

// File Line: 507
// RVA: 0x117A30
SSMethodBase *__fastcall SSClass::get_instance_method_inherited(SSClass *this, ASymbol *method_name)
{
  SSMethodBase *result; // rax
  SSClass *i_superclass_p; // rcx

  result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(&this->i_methods, method_name);
  if ( !result )
  {
    i_superclass_p = this->i_superclass_p;
    if ( i_superclass_p )
      return SSClass::get_instance_method_inherited(i_superclass_p, method_name);
  }
  return result;
}

// File Line: 524
// RVA: 0x117600
SSMethodBase *__fastcall SSClass::get_class_method_inherited(SSClass *this, ASymbol *method_name)
{
  SSClass *v2; // rdi
  ASymbol *v3; // rbx
  SSMethodBase *result; // rax

  while ( 1 )
  {
    v2 = this;
    v3 = method_name;
    result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(&this->i_class_methods, method_name);
    if ( result )
      break;
    this = v2->i_superclass_p;
    method_name = v3;
    if ( !this )
      return APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(&SSBrain::c_object_class_p->i_methods, v3);
  }
  return result;
}

// File Line: 543
// RVA: 0x117FD0
SSMethodBase *__fastcall SSClass::get_method_inherited(SSClass *this, ASymbol *method_name)
{
  SSMethodBase *result; // rax
  SSClass *i_superclass_p; // rcx
  SSClass *v6; // rcx

  result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(&this->i_methods, method_name);
  if ( !result )
  {
    i_superclass_p = this->i_superclass_p;
    if ( i_superclass_p )
      result = SSClass::get_instance_method_inherited(i_superclass_p, method_name);
    if ( !result )
    {
      result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(&this->i_class_methods, method_name);
      if ( !result )
      {
        v6 = this->i_superclass_p;
        if ( v6 )
          return SSClass::get_class_method_inherited(v6, method_name);
        else
          return APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
                   &SSBrain::c_object_class_p->i_methods,
                   method_name);
      }
    }
  }
  return result;
}

// File Line: 568
// RVA: 0x11F150
bool __fastcall SSClass::is_method_registered(SSClass *this, ASymbol *method_name)
{
  SSMethodBase *v2; // rax

  v2 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(&this->i_methods, method_name);
  return v2 && !v2->vfptr->is_placeholder(v2);
}

// File Line: 582
// RVA: 0x11F1B0
bool __fastcall SSClass::is_method_valid(SSClass *this, ASymbol *method_name)
{
  SSMethodBase *v4; // rax

  if ( APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(&this->i_methods, method_name)
    || (v4 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(&this->i_class_methods, method_name)) != 0i64 )
  {
    LOBYTE(v4) = 1;
  }
  return (char)v4;
}

// File Line: 594
// RVA: 0x11F050
bool __fastcall SSClass::is_method_inherited_valid(SSClass *this, ASymbol *method_name)
{
  SSMethodBase *instance_method_inherited; // rax
  SSClass *i_superclass_p; // rcx
  SSClass *v6; // rcx
  SSMethodBase *class_method_inherited; // rax

  instance_method_inherited = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
                                &this->i_methods,
                                method_name);
  if ( instance_method_inherited )
    goto LABEL_10;
  i_superclass_p = this->i_superclass_p;
  if ( i_superclass_p )
    instance_method_inherited = SSClass::get_instance_method_inherited(i_superclass_p, method_name);
  if ( instance_method_inherited
    || APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(&this->i_class_methods, method_name)
    || ((v6 = this->i_superclass_p) == 0i64
      ? (class_method_inherited = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
                                    &SSBrain::c_object_class_p->i_methods,
                                    method_name))
      : (class_method_inherited = SSClass::get_class_method_inherited(v6, method_name)),
        class_method_inherited) )
  {
LABEL_10:
    LOBYTE(class_method_inherited) = 1;
  }
  return (char)class_method_inherited;
}

// File Line: 610
// RVA: 0x10E110
void __fastcall SSClass::append_method(SSClass *this, SSMethodBase *method_p)
{
  SSMethodBase *appended; // rbx

  method_p->i_scope_p = this;
  appended = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::append_replace(&this->i_methods, method_p, 0i64);
  if ( method_p->i_name.i_uid == ASymbolX_dtor.i_uid )
    SSClass::set_destructor(this, method_p);
  if ( appended )
    appended->vfptr->__vecDelDtor(appended, 1u);
}

// File Line: 630
// RVA: 0x10DF30
SSTypedName *__fastcall SSClass::append_data_member(SSClass *this, ASymbol *name, SSClassDescBase *type_p)
{
  return SSClass::append_instance_data(this, name, type_p, Subclass_recurse);
}

// File Line: 646
// RVA: 0x104590
void __fastcall SSClassUnion::SSClassUnion(SSClassUnion *this, SSClassUnion *class_union)
{
  SSClassUnaryBase **v4; // rax
  unsigned int i_count; // ecx
  SSClassUnaryBase *i_common_class_p; // rcx
  __int64 v7; // rax
  SSClassUnaryBase **i_array_p; // rbx
  SSClassUnaryBase **i; // rsi

  this->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
  this->i_ref_count = 0;
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
  this->i_common_class_p = class_union->i_common_class_p;
  v4 = APArrayBase<SSClassUnaryBase>::alloc_array(class_union->i_union.i_count);
  i_count = class_union->i_union.i_count;
  this->i_union.i_count = i_count;
  this->i_union.i_array_p = v4;
  this->i_union.i_size = i_count;
  memmove(v4, class_union->i_union.i_array_p, 8i64 * i_count);
  i_common_class_p = this->i_common_class_p;
  if ( i_common_class_p )
    (*(void (__fastcall **)(SSClassUnaryBase *))i_common_class_p->vfptr->gap8)(i_common_class_p);
  v7 = this->i_union.i_count;
  if ( (_DWORD)v7 )
  {
    i_array_p = this->i_union.i_array_p;
    for ( i = &i_array_p[v7]; i_array_p < i; ++i_array_p )
       SSClassDescBase::`vcall{8,{flat}}(*i_array_p);
  }
}

// File Line: 660
// RVA: 0x106D20
void __fastcall SSClassUnion::~SSClassUnion(SSClassUnion *this)
{
  SSClassUnaryBase *i_common_class_p; // rcx
  __int64 i_count; // rax
  SSClassUnaryBase **i_array_p; // rbx
  SSClassUnaryBase **i; // rsi

  this->vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
  i_common_class_p = this->i_common_class_p;
  if ( i_common_class_p )
    i_common_class_p->vfptr->dereference_delay(i_common_class_p);
  i_count = this->i_union.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = this->i_union.i_array_p;
    for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
       SSClassDescBase::`vcall{24,{flat}}(*i_array_p);
  }
  AMemory::c_free_func(this->i_union.i_array_p);
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
}

// File Line: 674
// RVA: 0x107B20
SSClassUnion *__fastcall SSClassUnion::operator=(SSClassUnion *this, SSClassUnion *class_union)
{
  SSClassUnaryBase *i_common_class_p; // rbx
  SSClassUnaryBase *v5; // rcx
  __int64 i_count; // rax
  SSClassUnaryBase **i_array_p; // rbx
  SSClassUnaryBase **i; // rsi
  __int64 v9; // rax
  SSClassUnaryBase **v10; // rbx
  SSClassUnaryBase **j; // rsi
  unsigned int v12; // eax
  unsigned int v13; // eax

  i_common_class_p = class_union->i_common_class_p;
  if ( i_common_class_p )
    (*(void (__fastcall **)(SSClassUnaryBase *))i_common_class_p->vfptr->gap8)(class_union->i_common_class_p);
  v5 = this->i_common_class_p;
  if ( v5 )
    v5->vfptr->dereference_delay(v5);
  this->i_common_class_p = i_common_class_p;
  i_count = class_union->i_union.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = class_union->i_union.i_array_p;
    for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
       SSClassDescBase::`vcall{8,{flat}}(*i_array_p);
  }
  v9 = this->i_union.i_count;
  if ( (_DWORD)v9 )
  {
    v10 = this->i_union.i_array_p;
    for ( j = &v10[v9]; v10 < j; ++v10 )
       SSClassDescBase::`vcall{24,{flat}}(*v10);
  }
  v12 = class_union->i_union.i_count;
  this->i_union.i_count = v12;
  if ( v12 > this->i_union.i_size )
  {
    AMemory::c_free_func(this->i_union.i_array_p);
    v13 = AMemory::c_req_byte_size_func(8 * this->i_union.i_count);
    this->i_union.i_size = v13 >> 3;
    this->i_union.i_array_p = APArrayBase<SSClassUnaryBase>::alloc_array(v13 >> 3);
  }
  memmove(this->i_union.i_array_p, class_union->i_union.i_array_p, 8i64 * this->i_union.i_count);
  return this;
}

// File Line: 718
// RVA: 0x116A80
SSClassUnion *__fastcall SSClassUnion::from_binary_ref(const void **binary_pp)
{
  __int64 v1; // rdx
  SSClassUnion *v3; // rbp
  SSClassUnaryBase **i_array_p; // rsi
  __int64 *v5; // rbx
  SSClassUnaryBase **v6; // rdi
  SSClassUnion class_union; // [rsp+28h] [rbp-40h] BYREF

  if ( SSClassDescBase::c_compounds_use_ref )
  {
    v1 = *(unsigned int *)*binary_pp;
    *binary_pp = (char *)*binary_pp + 4;
    return SSClassUnion::c_shared_unions.i_array_p[v1];
  }
  else
  {
    class_union.i_ref_count = 0;
    class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
    class_union.i_common_class_p = 0i64;
    class_union.i_union.i_count = 0;
    class_union.i_union.i_array_p = 0i64;
    class_union.i_union.i_size = 0;
    SSClassUnion::assign_binary(&class_union, binary_pp);
    v3 = SSClassUnion::get_or_create(&class_union);
    class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
    if ( class_union.i_common_class_p )
      class_union.i_common_class_p->vfptr->dereference_delay(class_union.i_common_class_p);
    i_array_p = class_union.i_union.i_array_p;
    if ( class_union.i_union.i_count )
    {
      v5 = (__int64 *)class_union.i_union.i_array_p;
      v6 = &class_union.i_union.i_array_p[class_union.i_union.i_count];
      if ( class_union.i_union.i_array_p < v6 )
      {
        do
           SSClassDescBase::`vcall{24,{flat}}(*v5++);
        while ( v5 < (__int64 *)v6 );
      }
    }
    AMemory::c_free_func(i_array_p);
    return v3;
  }
}

// File Line: 758
// RVA: 0x118260
SSClassUnion *__fastcall SSClassUnion::get_or_create(SSClassUnion *class_union)
{
  SSClassUnion *v2; // rbx
  SSClassUnion *result; // rax
  SSClassUnion *v4; // rax
  SSClassUnion *v5; // rax
  unsigned int find_pos_p; // [rsp+58h] [rbp+10h] BYREF
  SSClassUnion *v7; // [rsp+60h] [rbp+18h]

  v2 = 0i64;
  if ( APSorted<SSClassUnion,SSClassUnion,ACompareLogical<SSClassUnion>>::find(
         &SSClassUnion::c_shared_unions,
         class_union,
         0,
         &find_pos_p,
         0,
         0xFFFFFFFF) )
  {
    result = SSClassUnion::c_shared_unions.i_array_p[find_pos_p];
  }
  else
  {
    result = 0i64;
  }
  if ( !result )
  {
    v4 = (SSClassUnion *)AMemory::c_malloc_func(0x30ui64, "SSClassUnion");
    v7 = v4;
    if ( v4 )
    {
      SSClassUnion::SSClassUnion(v4, class_union);
      v2 = v5;
    }
    APSizedArrayBase<SSClassUnion>::insert(&SSClassUnion::c_shared_unions, v2, find_pos_p);
    return v2;
  }
  return result;
}

// File Line: 791
// RVA: 0x117970
SSClassDescBase *__fastcall SSClassUnion::get_data_type(
        SSContextClassBase *this,
        ASymbol *data_name,
        eSSScope *scope_p)
{
  return this->i_class_p->vfptr->get_data_type(this->i_class_p, data_name, scope_p);
}

// File Line: 812
// RVA: 0x117B10
ASymbol *__fastcall SSClassUnion::get_key_class_name(SSClassUnion *this)
{
  return this->i_common_class_p->vfptr->get_key_class_name(this->i_common_class_p);
}

// File Line: 822
// RVA: 0x117F50
SSMetaClass *__fastcall Scaleform::DelegatedFile::ChangeSize(SSClassUnion *this)
{
  return this->i_common_class_p->vfptr->get_metaclass(this->i_common_class_p);
}

// File Line: 834
// RVA: 0x117FB0
SSMethodBase *__fastcall SSClassUnion::get_method(SSContextClassBase *this, ASymbol *method_name)
{
  return this->i_class_p->vfptr->get_method(this->i_class_p, method_name);
}

// File Line: 846
// RVA: 0x118050
SSMethodBase *__fastcall SSContextClassBase::get_method_inherited(SSContextClassBase *this, ASymbol *method_name)
{
  return this->i_class_p->vfptr->get_method_inherited(this->i_class_p, method_name);
}

// File Line: 858
// RVA: 0x1176B0
SSCoroutineBase *__fastcall SSClassUnion::get_coroutine_inherited(SSContextClassBase *this, ASymbol *coroutine_name)
{
  return this->i_class_p->vfptr->get_coroutine_inherited(this->i_class_p, coroutine_name);
}

// File Line: 870
// RVA: 0x11E6E0
__int64 __fastcall Scaleform::Render::WrapperImageSource::Decode(SSClassUnion *this)
{
  return ((__int64 (__fastcall *)(SSClassUnaryBase *))this->i_common_class_p->vfptr->is_actor_class)(this->i_common_class_p);
}

// File Line: 891
// RVA: 0x11F0E0
__int64 __fastcall SSContextClassBase::is_method_inherited_valid(SSContextClassBase *this, ASymbol *method_name)
{
  return ((__int64 (__fastcall *)(SSClass *, ASymbol *))this->i_class_p->vfptr->is_method_inherited_valid)(
           this->i_class_p,
           method_name);
}

// File Line: 903
// RVA: 0x113B20
void __fastcall SSClassUnion::dereference(SSClassUnion *this)
{
  if ( this->i_ref_count-- == 1 )
  {
    this->i_ref_count = 0x80000000;
    SSClassUnion::on_no_references(this);
  }
}

// File Line: 914
// RVA: 0x113B60
void __fastcall SSClassUnion::dereference_delay(SSContextClassBase *this)
{
  --this->i_ref_count;
}

// File Line: 936
// RVA: 0x126BC0
void __fastcall SSClassUnion::on_no_references(SSClassUnion *this)
{
  SSClassUnion **v1; // rcx
  SSClassUnion *v2; // rbx
  unsigned int find_pos_p; // [rsp+48h] [rbp+10h] BYREF

  if ( APSorted<SSClassUnion,SSClassUnion,ACompareLogical<SSClassUnion>>::find(
         &SSClassUnion::c_shared_unions,
         this,
         0,
         &find_pos_p,
         0,
         0xFFFFFFFF) )
  {
    v1 = &SSClassUnion::c_shared_unions.i_array_p[find_pos_p];
    v2 = *v1;
    memmove(v1, v1 + 1, 8i64 * (--SSClassUnion::c_shared_unions.i_count - find_pos_p));
    if ( v2 )
      v2->vfptr->__vecDelDtor(v2, 1u);
  }
}


// File Line: 62
// RVA: 0x117B30
ASymbol *__fastcall SSMetaClass::get_key_class_name(SSMetaClass *this)
{
  return &this->i_class_info_p->i_name;
}

// File Line: 83
// RVA: 0x117FC0
SSMethodBase *__fastcall SSMetaClass::get_method(SSMetaClass *this, ASymbol *method_name)
{
  return APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
           (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_class_info_p->i_class_methods.i_count,
           method_name);
}

// File Line: 94
// RVA: 0x118060
SSMethodBase *__fastcall SSMetaClass::get_method_inherited(SSMetaClass *this, ASymbol *method_name)
{
  SSClass *v2; // rdi
  ASymbol *v3; // rbx
  SSMethodBase *result; // rax
  SSClass *v5; // rcx

  v2 = this->i_class_info_p;
  v3 = method_name;
  result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
             (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&v2->i_class_methods.i_count,
             method_name);
  if ( !result )
  {
    v5 = v2->i_superclass_p;
    if ( v5 )
      result = SSClass::get_class_method_inherited(v5, v3);
    else
      result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
                 (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&SSBrain::c_object_class_p->i_methods.i_count,
                 v3);
  }
  return result;
}

// File Line: 109
// RVA: 0x10E190
void __fastcall SSMetaClass::append_method(SSMetaClass *this, SSMethodBase *method_p)
{
  SSClass *v2; // rcx
  SSMethodBase *v3; // rax

  v2 = this->i_class_info_p;
  method_p->i_scope_p = v2;
  v3 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::append_replace(
         (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&v2->i_class_methods.i_count,
         method_p,
         0i64);
  if ( v3 )
    v3->vfptr->__vecDelDtor((SSInvokableBase *)&v3->vfptr, 1u);
}

// File Line: 131
// RVA: 0x11F200
bool __fastcall SSMetaClass::is_method_valid(SSMetaClass *this, ASymbol *method_name)
{
  return APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
           (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_class_info_p->i_class_methods.i_count,
           method_name) != 0i64;
}

// File Line: 142
// RVA: 0x11F0F0
bool __fastcall SSMetaClass::is_method_inherited_valid(SSMetaClass *this, ASymbol *method_name)
{
  SSClass *v2; // rdi
  ASymbol *v3; // rbx
  SSMethodBase *v4; // rcx
  SSClass *v5; // rcx
  SSMethodBase *v6; // rax

  v2 = this->i_class_info_p;
  v3 = method_name;
  v4 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&v2->i_class_methods.i_count,
         method_name);
  if ( !v4 )
  {
    v5 = v2->i_superclass_p;
    if ( v5 )
      v6 = SSClass::get_class_method_inherited(v5, v3);
    else
      v6 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
             (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&SSBrain::c_object_class_p->i_methods.i_count,
             v3);
    v4 = v6;
  }
  return v4 != 0i64;
}

// File Line: 157
// RVA: 0x10DE90
void __fastcall SSMetaClass::append_coroutine(SSMetaClass *this, SSCoroutineBase *coroutine_p)
{
  AErrMsg *v2; // rax
  AErrMsg err_msg; // [rsp+40h] [rbp-78h]
  AErrMsg v4; // [rsp+78h] [rbp-40h]
  eAErrAction action_p; // [rsp+D0h] [rbp+18h]

  if ( `SSMetaClass::append_coroutine'::`3'::_test )
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
    if ( ADebug::resolve_error(v2, &action_p, &`SSMetaClass::append_coroutine'::`3'::_test) )
      __debugbreak();
    if ( action_p != 3 )
      __debugbreak();
  }
}

// File Line: 179
// RVA: 0x10DF50
SSTypedData *__fastcall SSMetaClass::append_data_member(SSMetaClass *this, ASymbol *name, SSClassDescBase *type_p)
{
  return SSClass::append_class_data(this->i_class_info_p, name, type_p, 0);
}

// File Line: 282
// RVA: 0x114D20
SSClass *__fastcall SSClass::find_common_class(SSClass *this, SSClass *cls)
{
  SSClass *v2; // rbx
  SSClass *v3; // rdi
  SSClass *v4; // rcx

  v2 = cls;
  v3 = this;
  while ( v2 != v3 )
  {
    v4 = v3->i_superclass_p;
    if ( v4 )
    {
      if ( SSClass::is_class(v4, v2) )
        break;
    }
    v2 = v2->i_superclass_p;
    if ( !v2 )
      return 0i64;
  }
  return v2;
}

// File Line: 308
// RVA: 0x11E730
bool __fastcall SSClass::is_class(SSClass *this, SSClass *cls)
{
  SSClass *v2; // rcx
  bool result; // al

  result = 1;
  if ( cls != this )
  {
    v2 = this->i_superclass_p;
    if ( !v2 || !SSClass::is_class(v2, cls) )
      result = 0;
  }
  return result;
}

// File Line: 320
// RVA: 0x11F380
bool __fastcall SSClass::is_subclass(SSClass *this, SSClass *superclass)
{
  SSClass *v2; // rcx

  v2 = this->i_superclass_p;
  return v2 == superclass || v2 && SSClass::is_subclass(v2, superclass);
}

// File Line: 336
// RVA: 0x11F3B0
bool __fastcall SSClass::is_superclass(SSClass *this, SSClass *subclass)
{
  SSClass *v2; // rdx

  v2 = subclass->i_superclass_p;
  return v2 == this || v2 && SSClass::is_superclass(this, v2);
}

// File Line: 352
// RVA: 0x11F310
char __fastcall SSClass::is_scope_qualifier(SSClass *this, SSClassDescBase *recv_type_p)
{
  SSClassDescBase *v2; // rbx
  SSClass *v3; // rdi
  SSClass *v4; // rax
  SSClass *v5; // rcx
  bool v6; // al

  v2 = recv_type_p;
  v3 = this;
  if ( !recv_type_p )
    return 1;
  if ( recv_type_p->vfptr->get_class_type(recv_type_p) == 1 )
  {
    v4 = (SSClass *)v2[7].vfptr;
    if ( v3 == v4 )
      return 1;
    v5 = v4->i_superclass_p;
    if ( !v5 )
      return 0;
    v6 = SSClass::is_class(v5, v3);
  }
  else
  {
    v6 = v2->vfptr->is_class_type(v2, (SSClassDescBase *)&v3->vfptr);
  }
  if ( !v6 )
    return 0;
  return 1;
}

// File Line: 383
// RVA: 0x117660
SSMethodBase *__fastcall SSClass::get_coroutine_inherited(SSClass *this, ASymbol *coroutine_name)
{
  SSClass *v2; // rbx
  ASymbol *v3; // rdi
  SSMethodBase *result; // rax
  SSClass *v5; // rcx

  v2 = this;
  v3 = coroutine_name;
  result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
             (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_coroutines,
             coroutine_name);
  if ( !result )
  {
    v5 = v2->i_superclass_p;
    if ( v5 )
      result = (SSMethodBase *)v5->vfptr->get_coroutine_inherited((SSClassDescBase *)&v5->vfptr, v3);
    else
      result = 0i64;
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
  return v2 && !v2->vfptr->is_placeholder((SSInvokableBase *)&v2->vfptr);
}

// File Line: 430
// RVA: 0x126960
SSInstance *__fastcall SSClass::new_instance(SSClass *this)
{
  JUMPOUT(this->i_data.i_count, 0, SSDataInstance::pool_new);
  return SSInstance::pool_new(this);
}

// File Line: 478
// RVA: 0x117AB0
SSClass *__fastcall SSClass::get_item_type(SSClass *this)
{
  SSClass *result; // rax

  result = 0i64;
  if ( this == SSBrain::c_list_class_p )
    result = SSBrain::c_object_class_p;
  return result;
}

// File Line: 491
// RVA: 0x117F70
SSMethodBase *__fastcall SSClass::get_method(SSClass *this, ASymbol *method_name)
{
  SSClass *v2; // rdi
  ASymbol *v3; // rbx
  SSMethodBase *result; // rax

  v2 = this;
  v3 = method_name;
  result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
             (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_methods.i_count,
             method_name);
  if ( !result )
    result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
               (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&v2->i_class_methods.i_count,
               v3);
  return result;
}

// File Line: 507
// RVA: 0x117A30
SSMethodBase *__fastcall SSClass::get_instance_method_inherited(SSClass *this, ASymbol *method_name)
{
  SSClass *v2; // rbx
  ASymbol *v3; // rdi
  SSMethodBase *result; // rax
  SSClass *v5; // rcx

  v2 = this;
  v3 = method_name;
  result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
             (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_methods.i_count,
             method_name);
  if ( !result )
  {
    v5 = v2->i_superclass_p;
    if ( v5 )
      result = SSClass::get_instance_method_inherited(v5, v3);
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
    result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
               (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_class_methods.i_count,
               method_name);
    if ( result )
      break;
    this = v2->i_superclass_p;
    method_name = v3;
    if ( !this )
      return APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
               (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&SSBrain::c_object_class_p->i_methods.i_count,
               v3);
  }
  return result;
}

// File Line: 543
// RVA: 0x117FD0
SSMethodBase *__fastcall SSClass::get_method_inherited(SSClass *this, ASymbol *method_name)
{
  SSClass *v2; // rdi
  ASymbol *v3; // rbx
  SSMethodBase *result; // rax
  SSClass *v5; // rcx
  SSClass *v6; // rcx

  v2 = this;
  v3 = method_name;
  result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
             (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_methods.i_count,
             method_name);
  if ( !result )
  {
    v5 = v2->i_superclass_p;
    if ( v5 )
      result = SSClass::get_instance_method_inherited(v5, v3);
    if ( !result )
    {
      result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
                 (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&v2->i_class_methods.i_count,
                 v3);
      if ( !result )
      {
        v6 = v2->i_superclass_p;
        if ( v6 )
          result = SSClass::get_class_method_inherited(v6, v3);
        else
          result = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
                     (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&SSBrain::c_object_class_p->i_methods.i_count,
                     v3);
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

  v2 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_methods.i_count,
         method_name);
  return v2 && !v2->vfptr->is_placeholder((SSInvokableBase *)&v2->vfptr);
}

// File Line: 582
// RVA: 0x11F1B0
bool __fastcall SSClass::is_method_valid(SSClass *this, ASymbol *method_name)
{
  SSClass *v2; // rdi
  ASymbol *v3; // rbx
  SSMethodBase *v4; // rax

  v2 = this;
  v3 = method_name;
  if ( APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_methods.i_count,
         method_name)
    || (v4 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
               (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&v2->i_class_methods.i_count,
               v3)) != 0i64 )
  {
    LOBYTE(v4) = 1;
  }
  return (char)v4;
}

// File Line: 594
// RVA: 0x11F050
bool __fastcall SSClass::is_method_inherited_valid(SSClass *this, ASymbol *method_name)
{
  SSClass *v2; // rdi
  ASymbol *v3; // rbx
  SSMethodBase *v4; // rax
  SSClass *v5; // rcx
  SSClass *v6; // rcx
  SSMethodBase *v7; // rax

  v2 = this;
  v3 = method_name;
  v4 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_methods.i_count,
         method_name);
  if ( v4 )
    goto LABEL_14;
  v5 = v2->i_superclass_p;
  if ( v5 )
    v4 = SSClass::get_instance_method_inherited(v5, v3);
  if ( v4
    || APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&v2->i_class_methods.i_count,
         v3)
    || ((v6 = v2->i_superclass_p) == 0i64 ? (v7 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
                                                    (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&SSBrain::c_object_class_p->i_methods.i_count,
                                                    v3)) : (v7 = SSClass::get_class_method_inherited(v6, v3)),
        v7) )
  {
LABEL_14:
    LOBYTE(v7) = 1;
  }
  return (char)v7;
}

// File Line: 610
// RVA: 0x10E110
void __fastcall SSClass::append_method(SSClass *this, SSMethodBase *method_p)
{
  SSClass *v2; // rsi
  SSMethodBase *v3; // rdi
  SSMethodBase *v4; // rbx

  v2 = this;
  method_p->i_scope_p = this;
  v3 = method_p;
  v4 = APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::append_replace(
         (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_methods.i_count,
         method_p,
         0i64);
  if ( v3->i_name.i_uid == ASymbolX_dtor.i_uid )
    SSClass::set_destructor(v2, v3);
  if ( v4 )
    v4->vfptr->__vecDelDtor((SSInvokableBase *)&v4->vfptr, 1u);
}

// File Line: 630
// RVA: 0x10DF30
SSTypedName *__fastcall SSClass::append_data_member(SSClass *this, ASymbol *name, SSClassDescBase *type_p)
{
  return SSClass::append_instance_data(this, name, type_p, 0);
}

// File Line: 646
// RVA: 0x104590
void __fastcall SSClassUnion::SSClassUnion(SSClassUnion *this, SSClassUnion *class_union)
{
  SSClassUnion *v2; // rbx
  SSClassUnion *v3; // rdi
  SSClassUnaryBase **v4; // rax
  unsigned int v5; // ecx
  SSClassUnaryBase *v6; // rcx
  __int64 v7; // rax
  SSClassUnaryBase **v8; // rbx
  unsigned __int64 i; // rsi

  v2 = class_union;
  v3 = this;
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable';
  this->i_ref_count = 0;
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
  this->i_common_class_p = class_union->i_common_class_p;
  v4 = APArrayBase<SSClassUnaryBase>::alloc_array(class_union->i_union.i_count);
  v5 = v2->i_union.i_count;
  v3->i_union.i_count = v5;
  v3->i_union.i_array_p = v4;
  v3->i_union.i_size = v5;
  memmove(v4, v2->i_union.i_array_p, 8i64 * v5);
  v6 = v3->i_common_class_p;
  if ( v6 )
    (*(void (__cdecl **)(SSClassUnaryBase *))v6->vfptr->gap8)(v6);
  v7 = v3->i_union.i_count;
  if ( (_DWORD)v7 )
  {
    v8 = v3->i_union.i_array_p;
    for ( i = (unsigned __int64)&v8[v7]; (unsigned __int64)v8 < i; ++v8 )
       SSClassDescBase::`vcall'{8,{flat}}(*v8);
  }
}

// File Line: 660
// RVA: 0x106D20
void __fastcall SSClassUnion::~SSClassUnion(SSClassUnion *this)
{
  SSClassUnion *v1; // rdi
  SSClassUnaryBase *v2; // rcx
  __int64 v3; // rax
  SSClassUnaryBase **v4; // rbx
  unsigned __int64 i; // rsi

  v1 = this;
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
  v2 = this->i_common_class_p;
  if ( v2 )
    ((void (__cdecl *)(SSClassUnaryBase *))v2->vfptr->dereference_delay)(v2);
  v3 = v1->i_union.i_count;
  if ( (_DWORD)v3 )
  {
    v4 = v1->i_union.i_array_p;
    for ( i = (unsigned __int64)&v4[v3]; (unsigned __int64)v4 < i; ++v4 )
       SSClassDescBase::`vcall'{24,{flat}}(*v4);
  }
  AMemory::c_free_func(v1->i_union.i_array_p);
  v1->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable';
}

// File Line: 674
// RVA: 0x107B20
SSClassUnion *__fastcall SSClassUnion::operator=(SSClassUnion *this, SSClassUnion *class_union)
{
  SSClassUnaryBase *v2; // rbx
  SSClassUnion *v3; // rbp
  SSClassUnion *v4; // rdi
  SSClassUnaryBase *v5; // rcx
  __int64 v6; // rax
  SSClassUnaryBase **v7; // rbx
  unsigned __int64 i; // rsi
  __int64 v9; // rax
  SSClassUnaryBase **v10; // rbx
  unsigned __int64 j; // rsi
  unsigned int v12; // eax
  unsigned int v13; // eax

  v2 = class_union->i_common_class_p;
  v3 = class_union;
  v4 = this;
  if ( v2 )
    (*(void (__fastcall **)(SSClassUnaryBase *))v2->vfptr->gap8)(class_union->i_common_class_p);
  v5 = v4->i_common_class_p;
  if ( v5 )
    ((void (*)(void))v5->vfptr->dereference_delay)();
  v4->i_common_class_p = v2;
  v6 = v3->i_union.i_count;
  if ( (_DWORD)v6 )
  {
    v7 = v3->i_union.i_array_p;
    for ( i = (unsigned __int64)&v7[v6]; (unsigned __int64)v7 < i; ++v7 )
       SSClassDescBase::`vcall'{8,{flat}}(*v7);
  }
  v9 = v4->i_union.i_count;
  if ( (_DWORD)v9 )
  {
    v10 = v4->i_union.i_array_p;
    for ( j = (unsigned __int64)&v10[v9]; (unsigned __int64)v10 < j; ++v10 )
       SSClassDescBase::`vcall'{24,{flat}}(*v10);
  }
  v12 = v3->i_union.i_count;
  v4->i_union.i_count = v12;
  if ( v12 > v4->i_union.i_size )
  {
    AMemory::c_free_func(v4->i_union.i_array_p);
    v13 = AMemory::c_req_byte_size_func(8 * v4->i_union.i_count) >> 3;
    v4->i_union.i_size = v13;
    v4->i_union.i_array_p = APArrayBase<SSClassUnaryBase>::alloc_array(v13);
  }
  memmove(v4->i_union.i_array_p, v3->i_union.i_array_p, 8i64 * v4->i_union.i_count);
  return v4;
}

// File Line: 718
// RVA: 0x116A80
SSClassUnion *__fastcall SSClassUnion::from_binary_ref(const void **binary_pp)
{
  __int64 v1; // rdx
  SSClassUnion *result; // rax
  SSClassUnion *v3; // rbp
  __int64 v4; // r8
  SSClassUnaryBase **v5; // rsi
  __int64 *v6; // rbx
  SSClassUnaryBase **v7; // rdi
  SSClassUnion class_union; // [rsp+28h] [rbp-40h]

  if ( SSClassDescBase::c_compounds_use_ref )
  {
    v1 = *(unsigned int *)*binary_pp;
    *binary_pp = (char *)*binary_pp + 4;
    result = SSClassUnion::c_shared_unions.i_array_p[v1];
  }
  else
  {
    class_union.i_ref_count = 0;
    class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
    class_union.i_common_class_p = 0i64;
    class_union.i_union.i_count = 0;
    class_union.i_union.i_array_p = 0i64;
    class_union.i_union.i_size = 0;
    SSClassUnion::assign_binary(&class_union, binary_pp);
    v3 = SSClassUnion::get_or_create(&class_union);
    class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
    if ( class_union.i_common_class_p )
      ((void (__cdecl *)(SSClassUnaryBase *, SSClassDescBaseVtbl *, __int64))class_union.i_common_class_p->vfptr->dereference_delay)(
        class_union.i_common_class_p,
        class_union.i_common_class_p->vfptr,
        v4);
    v5 = class_union.i_union.i_array_p;
    if ( class_union.i_union.i_count )
    {
      v6 = (__int64 *)class_union.i_union.i_array_p;
      v7 = &class_union.i_union.i_array_p[class_union.i_union.i_count];
      if ( class_union.i_union.i_array_p < v7 )
      {
        do
        {
           SSClassDescBase::`vcall'{24,{flat}}(*v6);
          ++v6;
        }
        while ( v6 < (__int64 *)v7 );
      }
    }
    AMemory::c_free_func(v5);
    result = v3;
  }
  return result;
}

// File Line: 758
// RVA: 0x118260
SSClassUnion *__fastcall SSClassUnion::get_or_create(SSClassUnion *class_union)
{
  SSClassUnion *v1; // rsi
  SSClassUnion *v2; // rbx
  SSClassUnion *result; // rax
  SSClassUnion *v4; // rax
  SSClassUnion *v5; // rax
  unsigned int find_pos_p; // [rsp+58h] [rbp+10h]
  SSClassUnion *v7; // [rsp+60h] [rbp+18h]

  v1 = class_union;
  v2 = 0i64;
  if ( APSorted<SSClassUnion,SSClassUnion,ACompareLogical<SSClassUnion>>::find(
         (APSorted<SSClassUnion,SSClassUnion,ACompareLogical<SSClassUnion> > *)&SSClassUnion::c_shared_unions.i_count,
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
      SSClassUnion::SSClassUnion(v4, v1);
      v2 = v5;
    }
    APSizedArrayBase<SSClassUnion>::insert(
      (APSizedArrayBase<SSClassUnion> *)&SSClassUnion::c_shared_unions.i_count,
      v2,
      find_pos_p);
    result = v2;
  }
  return result;
}

// File Line: 791
// RVA: 0x117970
SSClassDescBase *__fastcall SSClassUnion::get_data_type(SSContextClassBase *this, ASymbol *data_name, eSSScope *scope_p)
{
  return (SSClassDescBase *)this->i_class_p->vfptr->get_data_type(
                              (SSClassDescBase *)this->i_class_p,
                              data_name,
                              scope_p);
}

// File Line: 812
// RVA: 0x117B10
ASymbol *__fastcall SSClassUnion::get_key_class_name(SSClassUnion *this)
{
  return (ASymbol *)((__int64 (*)(void))this->i_common_class_p->vfptr->get_key_class_name)();
}

// File Line: 822
// RVA: 0x117F50
SSMetaClass *__fastcall Scaleform::DelegatedFile::ChangeSize(SSClassUnion *this)
{
  return (SSMetaClass *)((__int64 (*)(void))this->i_common_class_p->vfptr->get_metaclass)();
}

// File Line: 834
// RVA: 0x117FB0
SSMethodBase *__fastcall SSClassUnion::get_method(SSContextClassBase *this, ASymbol *method_name)
{
  return (SSMethodBase *)this->i_class_p->vfptr->get_method((SSClassDescBase *)this->i_class_p, method_name);
}

// File Line: 846
// RVA: 0x118050
SSMethodBase *__fastcall SSContextClassBase::get_method_inherited(SSContextClassBase *this, ASymbol *method_name)
{
  return (SSMethodBase *)this->i_class_p->vfptr->get_method_inherited((SSClassDescBase *)this->i_class_p, method_name);
}

// File Line: 858
// RVA: 0x1176B0
SSCoroutineBase *__fastcall SSClassUnion::get_coroutine_inherited(SSContextClassBase *this, ASymbol *coroutine_name)
{
  return (SSCoroutineBase *)this->i_class_p->vfptr->get_coroutine_inherited(
                              (SSClassDescBase *)this->i_class_p,
                              coroutine_name);
}

// File Line: 870
// RVA: 0x11E6E0
__int64 __fastcall Scaleform::Render::WrapperImageSource::Decode(SSClassUnion *this)
{
  return ((__int64 (*)(void))this->i_common_class_p->vfptr->is_actor_class)();
}

// File Line: 891
// RVA: 0x11F0E0
__int64 __fastcall SSContextClassBase::is_method_inherited_valid(SSContextClassBase *this, ASymbol *method_name)
{
  return this->i_class_p->vfptr->is_method_inherited_valid((SSClassDescBase *)this->i_class_p, method_name);
}

// File Line: 903
// RVA: 0x113B20
void __fastcall SSClassUnion::dereference(SSClassUnion *this)
{
  bool v1; // zf

  v1 = this->i_ref_count-- == 1;
  if ( v1 )
  {
    this->i_ref_count = 2147483648;
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
  unsigned int find_pos_p; // [rsp+48h] [rbp+10h]

  if ( APSorted<SSClassUnion,SSClassUnion,ACompareLogical<SSClassUnion>>::find(
         (APSorted<SSClassUnion,SSClassUnion,ACompareLogical<SSClassUnion> > *)&SSClassUnion::c_shared_unions.i_count,
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
      v2->vfptr->__vecDelDtor((SSClassDescBase *)&v2->vfptr, 1u);
  }
}


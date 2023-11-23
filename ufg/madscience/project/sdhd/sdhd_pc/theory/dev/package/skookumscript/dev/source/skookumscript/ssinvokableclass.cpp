// File Line: 31
// RVA: 0x1461550
__int64 dynamic_initializer_for__SSInvokableClass::c_shared_classes__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SSInvokableClass::c_shared_classes__);
}

// File Line: 129
// RVA: 0x111330
void __fastcall SSInvokableClass::assign_binary(SSInvokableClass *this, const void **binary_pp)
{
  ASymbol *v4; // rax
  SSParameters *v5; // rdi
  SSParameters *i_obj_p; // rbx
  SSParameters params_p; // [rsp+28h] [rbp-40h] BYREF
  ASymbol v9; // [rsp+70h] [rbp+8h] BYREF

  v4 = ASymbol::create_from_binary(&v9, binary_pp);
  this->i_class_p = SSBrain::get_class(v4);
  SSParameters::SSParameters(&params_p, binary_pp);
  v5 = SSParameters::get_or_create(&params_p);
  SSParameters::~SSParameters(&params_p);
  if ( this->i_params_p.i_obj_p != v5 )
  {
    if ( v5 )
      ++v5->i_ref_count;
    i_obj_p = this->i_params_p.i_obj_p;
    if ( i_obj_p )
    {
      if ( i_obj_p->i_ref_count-- == 1 )
      {
        i_obj_p->i_ref_count = 0x80000000;
        SSParameters::~SSParameters(i_obj_p);
        AMemory::c_free_func(i_obj_p);
      }
    }
    this->i_params_p.i_obj_p = v5;
  }
  this->i_invoke_type = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
}

// File Line: 163
// RVA: 0x116B80
SSInvokableClass *__fastcall SSInvokableClass::from_binary_ref(const void **binary_pp)
{
  __int64 v1; // rdx
  SSInvokableClass *v3; // rdi
  SSParameters *i_obj_p; // rbx
  bool v5; // zf
  SSInvokableClass iclass; // [rsp+28h] [rbp-30h] BYREF

  if ( SSClassDescBase::c_compounds_use_ref )
  {
    v1 = *(unsigned int *)*binary_pp;
    *binary_pp = (char *)*binary_pp + 4;
    return SSInvokableClass::c_shared_classes.i_array_p[v1];
  }
  else
  {
    iclass.i_ref_count = 0;
    iclass.vfptr = (SSClassDescBaseVtbl *)&SSInvokableClass::`vftable;
    iclass.i_params_p.i_obj_p = 0i64;
    SSInvokableClass::assign_binary(&iclass, binary_pp);
    v3 = SSInvokableClass::get_or_create(&iclass);
    iclass.vfptr = (SSClassDescBaseVtbl *)&SSInvokableClass::`vftable;
    i_obj_p = iclass.i_params_p.i_obj_p;
    if ( iclass.i_params_p.i_obj_p )
    {
      v5 = iclass.i_params_p.i_obj_p->i_ref_count-- == 1;
      if ( v5 )
      {
        i_obj_p->i_ref_count = 0x80000000;
        SSParameters::~SSParameters(i_obj_p);
        AMemory::c_free_func(i_obj_p);
      }
      i_obj_p = 0i64;
      iclass.i_params_p.i_obj_p = 0i64;
    }
    if ( i_obj_p )
    {
      v5 = i_obj_p->i_ref_count-- == 1;
      if ( v5 )
      {
        i_obj_p->i_ref_count = 0x80000000;
        SSParameters::~SSParameters(i_obj_p);
        AMemory::c_free_func(i_obj_p);
      }
    }
    return v3;
  }
}

// File Line: 247
// RVA: 0x11ED20
bool __fastcall SSInvokableClass::is_generic(SSInvokableClass *this)
{
  return SSParameters::is_generic(this->i_params_p.i_obj_p);
}

// File Line: 260
// RVA: 0x10ED60
SSInvokableClass *__fastcall SSInvokableClass::as_finalized_generic(
        SSInvokableClass *this,
        SSClassDescBase *scope_type)
{
  SSParameters *i_obj_p; // rbx
  SSParameters *v4; // rax

  i_obj_p = this->i_params_p.i_obj_p;
  v4 = SSParameters::as_finalized_generic(i_obj_p, scope_type);
  if ( v4 == i_obj_p )
    return this;
  else
    return SSInvokableClass::get_or_create(this->i_class_p, v4, this->i_invoke_type);
}

// File Line: 278
// RVA: 0x114ED0
SSMetaClass *__fastcall SSInvokableClass::find_common_type(SSInvokableClass *this, SSMetaClass *cls)
{
  __int64 v3; // rbp
  SSClass *v5; // rbx
  eSSClassType v6; // eax
  __int32 v7; // eax
  __int32 v8; // eax
  __int32 v9; // eax
  SSClassDescBaseVtbl *vfptr; // rbx
  SSClassUnaryBase *v11; // rax
  SSClass *common_class; // rbx
  __int32 v14; // ebp
  SSClass *i_class_p; // rdi
  SSClass *i_superclass_p; // rcx

  v3 = 0i64;
  v5 = 0i64;
  v6 = cls->SSClassUnaryBase::SSClassDescBase::vfptr->get_class_type(cls);
  if ( v6 )
  {
    v7 = v6 - 1;
    if ( !v7 )
      return SSMetaClass::find_common_class(cls, this->i_class_p);
    v8 = v7 - 1;
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( !v9 )
      {
        common_class = SSClass::find_common_class(this->i_class_p, *(SSClass **)&cls->i_ptr_id);
        v14 = this->i_invoke_type & (__int64)cls->i_class_p;
        if ( v14 && SSParameters::operator==(this->i_params_p.i_obj_p, *(SSParameters **)&cls->i_ref_count) )
          return (SSMetaClass *)SSInvokableClass::get_or_create(
                                  common_class,
                                  this->i_params_p.i_obj_p,
                                  (eSSInvokeTime)v14);
        else
          return (SSMetaClass *)common_class;
      }
      if ( v9 == 1 )
      {
        vfptr = this->vfptr;
        v11 = cls->SSClassUnaryBase::SSClassDescBase::vfptr->as_unary_class(cls);
        return (SSMetaClass *)vfptr->find_common_type(this, v11);
      }
    }
    else
    {
      v5 = cls->SSClassUnaryBase::SSClassDescBase::vfptr->get_key_class(cls);
    }
  }
  else
  {
    v5 = (SSClass *)cls;
  }
  i_class_p = this->i_class_p;
  while ( v5 != i_class_p )
  {
    i_superclass_p = i_class_p->i_superclass_p;
    if ( i_superclass_p )
    {
      if ( SSClass::is_class(i_superclass_p, v5) )
        break;
    }
    v5 = v5->i_superclass_p;
    if ( !v5 )
      return (SSMetaClass *)v3;
  }
  return (SSMetaClass *)v5;
}

// File Line: 331
// RVA: 0x11E930
bool __fastcall SSInvokableClass::is_class_type(SSInvokableClass *this, SSClass *type_p)
{
  eSSClassType v4; // eax
  __int32 v5; // eax
  SSClass *i_class_p; // rax
  SSClass *i_superclass_p; // rcx

  v4 = type_p->vfptr->get_class_type(type_p);
  if ( v4 == SSClassType_class )
  {
    if ( type_p == SSBrain::c_object_class_p )
      return 1;
    i_class_p = this->i_class_p;
    if ( type_p == i_class_p )
      return 1;
    i_superclass_p = i_class_p->i_superclass_p;
    if ( i_superclass_p )
      return SSClass::is_class(i_superclass_p, type_p);
    return 0;
  }
  v5 = v4 - 3;
  if ( !v5 )
  {
    if ( this == (SSInvokableClass *)type_p )
      return 1;
    if ( ((__int64)type_p->i_subclasses.i_array_p & this->i_invoke_type) != 0 )
      return SSParameters::is_valid_arg_to(this->i_params_p.i_obj_p, *(SSParameters **)&type_p->i_subclasses.i_count);
    return 0;
  }
  return v5 == 1 && SSClassUnion::is_valid_param_for((SSClassUnion *)type_p, this);
}


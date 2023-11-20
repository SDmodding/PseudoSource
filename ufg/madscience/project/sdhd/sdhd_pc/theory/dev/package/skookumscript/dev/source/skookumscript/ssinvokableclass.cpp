// File Line: 31
// RVA: 0x1461550
__int64 dynamic_initializer_for__SSInvokableClass::c_shared_classes__()
{
  return atexit(dynamic_atexit_destructor_for__SSInvokableClass::c_shared_classes__);
}

// File Line: 129
// RVA: 0x111330
void __fastcall SSInvokableClass::assign_binary(SSInvokableClass *this, const void **binary_pp)
{
  const void **v2; // r14
  SSInvokableClass *v3; // rsi
  ASymbol *v4; // rax
  SSParameters *v5; // rdi
  SSParameters *v6; // rbx
  bool v7; // zf
  SSParameters params_p; // [rsp+28h] [rbp-40h]
  __int64 v9; // [rsp+70h] [rbp+8h]

  v2 = binary_pp;
  v3 = this;
  v4 = ASymbol::create_from_binary((ASymbol *)&v9, binary_pp);
  v3->i_class_p = SSBrain::get_class(v4);
  SSParameters::SSParameters(&params_p, v2);
  v5 = SSParameters::get_or_create(&params_p);
  SSParameters::~SSParameters(&params_p);
  if ( v3->i_params_p.i_obj_p != v5 )
  {
    if ( v5 )
      ++v5->i_ref_count;
    v6 = v3->i_params_p.i_obj_p;
    if ( v6 )
    {
      v7 = v6->i_ref_count-- == 1;
      if ( v7 )
      {
        v6->i_ref_count = 2147483648;
        SSParameters::~SSParameters(v6);
        AMemory::c_free_func(v6);
      }
    }
    v3->i_params_p.i_obj_p = v5;
  }
  v3->i_invoke_type = *(unsigned __int8 *)*v2;
  *v2 = (char *)*v2 + 1;
}

// File Line: 163
// RVA: 0x116B80
SSInvokableClass *__fastcall SSInvokableClass::from_binary_ref(const void **binary_pp)
{
  __int64 v1; // rdx
  SSInvokableClass *result; // rax
  SSInvokableClass *v3; // rdi
  SSParameters *v4; // rbx
  bool v5; // zf
  SSInvokableClass iclass; // [rsp+28h] [rbp-30h]

  if ( SSClassDescBase::c_compounds_use_ref )
  {
    v1 = *(unsigned int *)*binary_pp;
    *binary_pp = (char *)*binary_pp + 4;
    result = SSInvokableClass::c_shared_classes.i_array_p[v1];
  }
  else
  {
    iclass.i_ref_count = 0;
    iclass.vfptr = (SSClassDescBaseVtbl *)&SSInvokableClass::`vftable';
    iclass.i_params_p.i_obj_p = 0i64;
    SSInvokableClass::assign_binary(&iclass, binary_pp);
    v3 = SSInvokableClass::get_or_create(&iclass);
    iclass.vfptr = (SSClassDescBaseVtbl *)&SSInvokableClass::`vftable';
    v4 = iclass.i_params_p.i_obj_p;
    if ( iclass.i_params_p.i_obj_p )
    {
      v5 = iclass.i_params_p.i_obj_p->i_ref_count-- == 1;
      if ( v5 )
      {
        v4->i_ref_count = 2147483648;
        SSParameters::~SSParameters(v4);
        AMemory::c_free_func(v4);
      }
      v4 = 0i64;
      iclass.i_params_p.i_obj_p = 0i64;
    }
    if ( v4 )
    {
      v5 = v4->i_ref_count-- == 1;
      if ( v5 )
      {
        v4->i_ref_count = 2147483648;
        SSParameters::~SSParameters(v4);
        AMemory::c_free_func(v4);
      }
    }
    result = v3;
  }
  return result;
}

// File Line: 247
// RVA: 0x11ED20
bool __fastcall SSInvokableClass::is_generic(SSInvokableClass *this)
{
  return SSParameters::is_generic(this->i_params_p.i_obj_p);
}

// File Line: 260
// RVA: 0x10ED60
SSInvokableClass *__fastcall SSInvokableClass::as_finalized_generic(SSInvokableClass *this, SSClassDescBase *scope_type)
{
  SSParameters *v2; // rbx
  SSInvokableClass *v3; // rdi
  SSParameters *v4; // rax
  SSInvokableClass *result; // rax

  v2 = this->i_params_p.i_obj_p;
  v3 = this;
  v4 = SSParameters::as_finalized_generic(this->i_params_p.i_obj_p, scope_type);
  if ( v4 == v2 )
    result = v3;
  else
    result = SSInvokableClass::get_or_create(v3->i_class_p, v4, v3->i_invoke_type);
  return result;
}

// File Line: 278
// RVA: 0x114ED0
SSClass *__fastcall SSInvokableClass::find_common_type(SSInvokableClass *this, SSClassDescBase *cls)
{
  SSInvokableClass *v2; // rsi
  __int64 v3; // rbp
  SSClassDescBase *v4; // rdi
  SSClass *v5; // rbx
  eSSClassType v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  SSClassDescBaseVtbl *v10; // rbx
  __int64 v11; // rax
  SSClass *result; // rax
  SSClass *v13; // rbx
  int v14; // ebp
  SSClass *v15; // rdi
  SSClass *v16; // rcx

  v2 = this;
  v3 = 0i64;
  v4 = cls;
  v5 = 0i64;
  v6 = (unsigned int)cls->vfptr->get_class_type(cls);
  if ( v6 )
  {
    v7 = v6 - 1;
    if ( !v7 )
      return SSMetaClass::find_common_class((SSMetaClass *)v4, v2->i_class_p);
    v8 = v7 - 1;
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( !v9 )
      {
        v13 = SSClass::find_common_class(v2->i_class_p, (SSClass *)v4[2].vfptr);
        v14 = v2->i_invoke_type & (_QWORD)v4[4].vfptr;
        if ( v14 && SSParameters::operator==(v2->i_params_p.i_obj_p, (SSParameters *)v4[3].vfptr) )
          result = (SSClass *)SSInvokableClass::get_or_create(v13, v2->i_params_p.i_obj_p, (eSSInvokeTime)v14);
        else
          result = v13;
        return result;
      }
      if ( v9 == 1 )
      {
        v10 = v2->vfptr;
        v11 = (__int64)v4->vfptr->as_unary_class(v4);
        return (SSClass *)v10->find_common_type((SSClassDescBase *)&v2->vfptr, (SSClassDescBase *)v11);
      }
    }
    else
    {
      v5 = v4->vfptr->get_key_class(v4);
    }
  }
  else
  {
    v5 = (SSClass *)v4;
  }
  v15 = v2->i_class_p;
  while ( v5 != v15 )
  {
    v16 = v15->i_superclass_p;
    if ( v16 )
    {
      if ( SSClass::is_class(v16, v5) )
        break;
    }
    v5 = v5->i_superclass_p;
    if ( !v5 )
      return (SSClass *)v3;
  }
  return v5;
}

// File Line: 331
// RVA: 0x11E930
bool __fastcall SSInvokableClass::is_class_type(SSInvokableClass *this, SSClassDescBase *type_p)
{
  SSInvokableClass *v2; // rdi
  SSClassDescBase *v3; // rbx
  eSSClassType v4; // eax
  int v5; // eax
  bool result; // al
  bool v7; // al
  SSClass *v8; // rax
  SSClass *v9; // rcx

  v2 = this;
  v3 = type_p;
  v4 = (unsigned int)type_p->vfptr->get_class_type(type_p);
  if ( v4 == SSClassType_class )
  {
    if ( v3 == (SSClassDescBase *)SSBrain::c_object_class_p )
      return 1;
    v8 = v2->i_class_p;
    if ( v3 == (SSClassDescBase *)v8 )
      return 1;
    v9 = v8->i_superclass_p;
    if ( v9 )
    {
      v7 = SSClass::is_class(v9, (SSClass *)v3);
LABEL_13:
      if ( !v7 )
        return 0;
      return 1;
    }
    return 0;
  }
  v5 = v4 - 3;
  if ( !v5 )
  {
    if ( v2 == (SSInvokableClass *)v3 )
      return 1;
    if ( (_QWORD)v3[4].vfptr & v2->i_invoke_type )
    {
      v7 = SSParameters::is_valid_arg_to(v2->i_params_p.i_obj_p, (SSParameters *)v3[3].vfptr);
      goto LABEL_13;
    }
    return 0;
  }
  if ( v5 == 1 )
    result = SSClassUnion::is_valid_param_for((SSClassUnion *)v3, (SSClassDescBase *)&v2->vfptr);
  else
    result = 0;
  return result;
}


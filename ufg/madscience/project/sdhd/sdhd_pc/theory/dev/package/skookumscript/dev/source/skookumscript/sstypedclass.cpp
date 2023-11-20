// File Line: 30
// RVA: 0x14615B0
__int64 dynamic_initializer_for__SSTypedClass::c_typed_classes__()
{
  return atexit(dynamic_atexit_destructor_for__SSTypedClass::c_typed_classes__);
}

// File Line: 179
// RVA: 0x11EE00
__int64 __fastcall SSTypedClass::is_generic(SSTypedClass *this)
{
  return ((__int64 (*)(void))this->i_item_type_p->vfptr->is_generic)();
}

// File Line: 192
// RVA: 0x10F040
SSTypedClass *__fastcall SSTypedClass::as_finalized_generic(SSTypedClass *this, SSClassDescBase *scope_type)
{
  SSClassDescBase *v2; // rbx
  SSTypedClass *v3; // rdi
  SSClassDescBase *v4; // rax
  SSTypedClass *result; // rax

  v2 = this->i_item_type_p;
  v3 = this;
  v4 = v2->vfptr->as_finalized_generic(this->i_item_type_p, scope_type);
  if ( v4 == v2 )
    result = v3;
  else
    result = SSTypedClass::get_or_create(v3->i_class_p, v4);
  return result;
}

// File Line: 210
// RVA: 0x1150C0
SSClass *__fastcall SSTypedClass::find_common_type(SSTypedClass *this, SSClassDescBase *cls)
{
  SSTypedClass *v2; // rsi
  __int64 v3; // rbp
  SSClassDescBase *v4; // rdi
  SSClass *v5; // rbx
  eSSClassType v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  SSClassDescBaseVtbl *v10; // rbx
  __int64 v11; // rax
  SSClassDescBase *v13; // rbx
  SSClass *v14; // rax
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
    if ( !v8 )
    {
      v13 = (SSClassDescBase *)v2->i_item_type_p->vfptr->find_common_type(
                                 v2->i_item_type_p,
                                 (SSClassDescBase *)v4[3].vfptr);
      v14 = SSClass::find_common_class(v2->i_class_p, (SSClass *)v4[2].vfptr);
      return (SSClass *)SSTypedClass::get_or_create(v14, v13);
    }
    v9 = v8 - 1;
    if ( v9 )
    {
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

// File Line: 273
// RVA: 0x11EA80
bool __fastcall SSTypedClass::is_class_type(SSTypedClass *this, SSClassDescBase *type_p)
{
  SSTypedClass *v2; // rdi
  SSClassDescBase *v3; // rbx
  eSSClassType v4; // eax
  bool result; // al
  SSClass *v6; // rdx
  SSClass *v7; // rax
  SSClass *v8; // rcx
  SSClass *v9; // rax
  SSClass *v10; // rcx

  v2 = this;
  v3 = type_p;
  v4 = (unsigned int)type_p->vfptr->get_class_type(type_p);
  switch ( v4 )
  {
    case 0:
      if ( v3 == (SSClassDescBase *)SSBrain::c_object_class_p )
        return 1;
      v9 = v2->i_class_p;
      if ( v3 == (SSClassDescBase *)v9 )
        return 1;
      v10 = v9->i_superclass_p;
      if ( v10 )
      {
        if ( SSClass::is_class(v10, (SSClass *)v3) )
          return 1;
      }
      return 0;
    case 2:
      v6 = (SSClass *)v3[2].vfptr;
      v7 = v2->i_class_p;
      if ( v6 == v7 || (v8 = v7->i_superclass_p) != 0i64 && SSClass::is_class(v8, v6) )
      {
        if ( v2->i_item_type_p->vfptr->is_class_type(v2->i_item_type_p, (SSClassDescBase *)v3[3].vfptr) )
          return 1;
      }
      return 0;
    case 4:
      result = SSClassUnion::is_valid_param_for((SSClassUnion *)v3, (SSClassDescBase *)&v2->vfptr);
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


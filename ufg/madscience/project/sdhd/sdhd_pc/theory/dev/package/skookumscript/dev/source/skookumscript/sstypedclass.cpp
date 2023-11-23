// File Line: 30
// RVA: 0x14615B0
__int64 dynamic_initializer_for__SSTypedClass::c_typed_classes__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SSTypedClass::c_typed_classes__);
}

// File Line: 179
// RVA: 0x11EE00
__int64 __fastcall SSTypedClass::is_generic(SSTypedClass *this)
{
  return ((__int64 (__fastcall *)(SSClassDescBase *))this->i_item_type_p->vfptr->is_generic)(this->i_item_type_p);
}

// File Line: 192
// RVA: 0x10F040
SSTypedClass *__fastcall SSTypedClass::as_finalized_generic(SSTypedClass *this, SSClassDescBase *scope_type)
{
  SSClassDescBase *i_item_type_p; // rbx
  SSClassDescBase *v4; // rax

  i_item_type_p = this->i_item_type_p;
  v4 = i_item_type_p->vfptr->as_finalized_generic(i_item_type_p, scope_type);
  if ( v4 == i_item_type_p )
    return this;
  else
    return SSTypedClass::get_or_create(this->i_class_p, v4);
}

// File Line: 210
// RVA: 0x1150C0
SSMetaClass *__fastcall SSTypedClass::find_common_type(SSTypedClass *this, SSMetaClass *cls)
{
  __int64 v3; // rbp
  SSClass *v5; // rbx
  eSSClassType v6; // eax
  __int32 v7; // eax
  __int32 v8; // eax
  __int32 v9; // eax
  SSClassDescBaseVtbl *vfptr; // rbx
  SSClassUnaryBase *v11; // rax
  SSClassUnaryBase *v13; // rbx
  SSClass *common_class; // rax
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
    if ( !v8 )
    {
      v13 = this->i_item_type_p->vfptr->find_common_type(this->i_item_type_p, *(_QWORD *)&cls->i_ref_count);
      common_class = SSClass::find_common_class(this->i_class_p, *(SSClass **)&cls->i_ptr_id);
      return (SSMetaClass *)SSTypedClass::get_or_create(common_class, v13);
    }
    v9 = v8 - 1;
    if ( v9 )
    {
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

// File Line: 273
// RVA: 0x11EA80
bool __fastcall SSTypedClass::is_class_type(SSTypedClass *this, SSClass *type_p)
{
  eSSClassType v4; // eax
  SSClass *v6; // rdx
  SSClass *v7; // rax
  SSClass *v8; // rcx
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
    {
      if ( SSClass::is_class(i_superclass_p, type_p) )
        return 1;
    }
    return 0;
  }
  if ( v4 == SSClassType_typed_class )
  {
    v6 = type_p->i_superclass_p;
    v7 = this->i_class_p;
    if ( (v6 == v7 || (v8 = v7->i_superclass_p) != 0i64 && SSClass::is_class(v8, v6))
      && this->i_item_type_p->vfptr->is_class_type(
           this->i_item_type_p,
           *(SSClassDescBase **)&type_p->i_subclasses.i_count) )
    {
      return 1;
    }
    return 0;
  }
  return v4 == SSClassType_class_union && SSClassUnion::is_valid_param_for((SSClassUnion *)type_p, this);
}


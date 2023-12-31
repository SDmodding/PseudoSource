// File Line: 71
// RVA: 0x116C90
SSTypedClass *__fastcall SSTypedClass::from_binary_ref(const void **binary_pp)
{
  __int64 v1; // rdx
  SSTypedClass *v3; // rax
  SSTypedClass *v4; // rbx
  SSTypedClass v5; // [rsp+28h] [rbp-30h] BYREF

  if ( SSClassDescBase::c_compounds_use_ref )
  {
    v1 = *(unsigned int *)*binary_pp;
    *binary_pp = (char *)*binary_pp + 4;
    return SSTypedClass::c_typed_classes.i_array_p[v1];
  }
  else
  {
    SSTypedClass::SSTypedClass(&v5, binary_pp);
    v4 = SSTypedClass::get_or_create(v3);
    v5.vfptr = (SSClassDescBaseVtbl *)&SSTypedClass::`vftable;
    if ( v5.i_item_type_p )
    {
      v5.i_item_type_p->vfptr->dereference_delay(v5.i_item_type_p);
      v5.i_item_type_p = 0i64;
    }
    return v4;
  }
}

// File Line: 142
// RVA: 0x111EF0
void __fastcall SSTypedClass::clear(SSTypedClass *this)
{
  SSClassDescBase *i_item_type_p; // rcx

  i_item_type_p = this->i_item_type_p;
  if ( i_item_type_p )
  {
    i_item_type_p->vfptr->dereference_delay(i_item_type_p);
    this->i_item_type_p = 0i64;
  }
}

// File Line: 158
// RVA: 0x126D40
void __fastcall SSTypedClass::on_no_references(SSTypedClass *this)
{
  SSTypedClass **i_array_p; // rdi
  SSTypedClass **v3; // rsi
  SSTypedClass **v4; // rbx
  __int64 v5; // rax
  __int64 v6; // rbx
  SSTypedClass **v7; // rcx
  SSTypedClass *v8; // rdi

  if ( SSTypedClass::c_typed_classes.i_count )
  {
    i_array_p = SSTypedClass::c_typed_classes.i_array_p;
    v3 = &SSTypedClass::c_typed_classes.i_array_p[SSTypedClass::c_typed_classes.i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v4 = &i_array_p[((char *)v3 - (char *)i_array_p) >> 4];
        v5 = ACompareLogical<SSTypedClass>::comparison(this, *v4);
        if ( v5 >= 0 )
          break;
        if ( i_array_p == v4 )
          return;
        v3 = v4 - 1;
      }
      if ( v5 <= 0 )
        break;
      if ( v3 == v4 )
        return;
      i_array_p = v4 + 1;
    }
    v6 = v4 - SSTypedClass::c_typed_classes.i_array_p;
    v7 = &SSTypedClass::c_typed_classes.i_array_p[(unsigned int)v6];
    v8 = *v7;
    memmove(v7, v7 + 1, 8i64 * (unsigned int)(--SSTypedClass::c_typed_classes.i_count - v6));
    if ( v8 )
      v8->vfptr->__vecDelDtor(v8, 1u);
  }
}

// File Line: 170
// RVA: 0x118730
SSTypedClass *__fastcall SSTypedClass::get_or_create(SSTypedClass *tclass)
{
  SSTypedClass *v2; // rbp
  SSTypedClass **i_array_p; // rsi
  SSTypedClass **v4; // rdi
  SSTypedClass **v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rbx
  SSTypedClass *result; // rax
  SSTypedClass *v9; // rax
  SSTypedClass *v10; // rax

  v2 = 0i64;
  if ( SSTypedClass::c_typed_classes.i_count )
  {
    i_array_p = SSTypedClass::c_typed_classes.i_array_p;
    v4 = &SSTypedClass::c_typed_classes.i_array_p[SSTypedClass::c_typed_classes.i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v5 = &i_array_p[((char *)v4 - (char *)i_array_p) >> 4];
        v6 = ACompareLogical<SSTypedClass>::comparison(tclass, *v5);
        if ( v6 >= 0 )
          break;
        if ( i_array_p == v5 )
        {
          v7 = v5 - SSTypedClass::c_typed_classes.i_array_p;
          goto LABEL_13;
        }
        v4 = v5 - 1;
      }
      if ( v6 <= 0 )
        break;
      if ( v4 == v5 )
      {
        v7 = ((char *)v4 - (char *)SSTypedClass::c_typed_classes.i_array_p + 8) >> 3;
        goto LABEL_13;
      }
      i_array_p = v5 + 1;
    }
    v7 = v5 - SSTypedClass::c_typed_classes.i_array_p;
    result = SSTypedClass::c_typed_classes.i_array_p[(unsigned int)v7];
  }
  else
  {
    LODWORD(v7) = 0;
LABEL_13:
    result = 0i64;
  }
  if ( !result )
  {
    v9 = (SSTypedClass *)AMemory::c_malloc_func(0x20ui64, "SSTypedClass");
    if ( v9 )
    {
      SSTypedClass::SSTypedClass(v9, tclass);
      v2 = v10;
    }
    APSizedArrayBase<SSTypedClass>::insert(&SSTypedClass::c_typed_classes, v2, v7);
    return v2;
  }
  return result;
}

// File Line: 195
// RVA: 0x118840
SSTypedClass *__fastcall SSTypedClass::get_or_create(SSClass *class_p, SSClassDescBase *item_type_p)
{
  SSTypedClass *v4; // rbx
  SSTypedClass tclass; // [rsp+28h] [rbp-30h] BYREF

  (*(void (__fastcall **)(SSClassDescBase *))item_type_p->vfptr->gap8)(item_type_p);
  tclass.i_ref_count = 0;
  tclass.i_class_p = class_p;
  tclass.vfptr = (SSClassDescBaseVtbl *)&SSTypedClass::`vftable;
  tclass.i_item_type_p = item_type_p;
  (*(void (__fastcall **)(SSClassDescBase *))item_type_p->vfptr->gap8)(item_type_p);
  v4 = SSTypedClass::get_or_create(&tclass);
  tclass.vfptr = (SSClassDescBaseVtbl *)&SSTypedClass::`vftable;
  item_type_p->vfptr->dereference_delay(item_type_p);
  tclass.i_item_type_p = 0i64;
  tclass.vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
  item_type_p->vfptr->dereference_delay(item_type_p);
  return v4;
}


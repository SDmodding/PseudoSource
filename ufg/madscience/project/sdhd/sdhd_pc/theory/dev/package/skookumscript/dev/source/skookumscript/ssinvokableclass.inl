// File Line: 138
// RVA: 0x126C70
void __fastcall SSInvokableClass::on_no_references(SSInvokableClass *this)
{
  SSInvokableClass **i_array_p; // rdi
  SSInvokableClass **v3; // rsi
  SSInvokableClass **v4; // rbx
  __int64 v5; // rax
  __int64 v6; // rbx
  SSInvokableClass **v7; // rcx
  SSInvokableClass *v8; // rdi

  if ( SSInvokableClass::c_shared_classes.i_count )
  {
    i_array_p = SSInvokableClass::c_shared_classes.i_array_p;
    v3 = &SSInvokableClass::c_shared_classes.i_array_p[SSInvokableClass::c_shared_classes.i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v4 = &i_array_p[((char *)v3 - (char *)i_array_p) >> 4];
        v5 = ACompareLogical<SSInvokableClass>::comparison(this, *v4);
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
    v6 = v4 - SSInvokableClass::c_shared_classes.i_array_p;
    v7 = &SSInvokableClass::c_shared_classes.i_array_p[(unsigned int)v6];
    v8 = *v7;
    memmove(v7, v7 + 1, 8i64 * (unsigned int)(--SSInvokableClass::c_shared_classes.i_count - v6));
    if ( v8 )
      v8->vfptr->__vecDelDtor(v8, 1u);
  }
}

// File Line: 159
// RVA: 0x118310
SSInvokableClass *__fastcall SSInvokableClass::get_or_create(SSInvokableClass *iclass)
{
  SSInvokableClass *v2; // r14
  SSInvokableClass **i_array_p; // rsi
  SSInvokableClass **v4; // rdi
  SSInvokableClass **v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rbx
  SSInvokableClass *result; // rax
  SSInvokableClass *v9; // rax
  SSInvokableClass *v10; // rax

  v2 = 0i64;
  if ( !SSInvokableClass::c_shared_classes.i_count )
  {
    LODWORD(v7) = 0;
LABEL_14:
    v9 = (SSInvokableClass *)AMemory::c_malloc_func(0x28ui64, "SSInvokableClass");
    if ( v9 )
    {
      SSInvokableClass::SSInvokableClass(v9, iclass);
      v2 = v10;
    }
    (*(void (__fastcall **)(SSInvokableClass *))v2->vfptr->gap8)(v2);
    APSizedArrayBase<SSInvokableClass>::insert(&SSInvokableClass::c_shared_classes, v2, v7);
    return v2;
  }
  i_array_p = SSInvokableClass::c_shared_classes.i_array_p;
  v4 = &SSInvokableClass::c_shared_classes.i_array_p[SSInvokableClass::c_shared_classes.i_count - 1];
  while ( 1 )
  {
    while ( 1 )
    {
      v5 = &i_array_p[((char *)v4 - (char *)i_array_p) >> 4];
      v6 = ACompareLogical<SSInvokableClass>::comparison(iclass, *v5);
      if ( v6 >= 0 )
        break;
      if ( i_array_p == v5 )
      {
        v7 = v5 - SSInvokableClass::c_shared_classes.i_array_p;
        goto LABEL_14;
      }
      v4 = v5 - 1;
    }
    if ( v6 <= 0 )
      break;
    if ( v4 == v5 )
    {
      v7 = ((char *)v4 - (char *)SSInvokableClass::c_shared_classes.i_array_p + 8) >> 3;
      goto LABEL_14;
    }
    i_array_p = v5 + 1;
  }
  v7 = v5 - SSInvokableClass::c_shared_classes.i_array_p;
  result = SSInvokableClass::c_shared_classes.i_array_p[(unsigned int)v7];
  if ( !result )
    goto LABEL_14;
  return result;
}

// File Line: 193
// RVA: 0x118420
SSInvokableClass *__fastcall SSInvokableClass::get_or_create(
        SSClass *class_p,
        SSParameters *params_p,
        eSSInvokeTime invoke_type)
{
  SSInvokableClass *v3; // rdi
  SSParameters *i_obj_p; // rbx
  bool v5; // zf
  SSInvokableClass iclass; // [rsp+28h] [rbp-30h] BYREF

  iclass.i_ref_count = 0;
  iclass.i_class_p = class_p;
  iclass.vfptr = (SSClassDescBaseVtbl *)&SSInvokableClass::`vftable;
  iclass.i_params_p.i_obj_p = params_p;
  if ( params_p )
    ++params_p->i_ref_count;
  iclass.i_invoke_type = invoke_type;
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


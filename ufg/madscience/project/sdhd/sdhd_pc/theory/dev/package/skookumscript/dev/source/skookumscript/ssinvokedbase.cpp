// File Line: 59
// RVA: 0x119E70
SSInvokedContextBase *__fastcall SSInvokedBase::get_scope_context(SSInvokedBase *this)
{
  SSInvokedBase *v1; // rdx
  SSObjectBase *v2; // rcx
  SSInvokedContextBase *result; // rax

  v1 = this;
  v2 = this->i_scope_p.i_obj_p;
  if ( v2 && v1->i_scope_p.i_ptr_id == v2->i_ptr_id )
    result = (SSInvokedContextBase *)((__int64 (*)(void))v2->vfptr->get_scope_context)();
  else
    result = 0i64;
  return result;
}

// File Line: 72
// RVA: 0x1174D0
SSInvokedContextBase *__fastcall SSInvokedBase::get_caller_context(SSInvokedBase *this)
{
  SSInvokedBase *v1; // rdx
  SSInvokedBase *v2; // rcx
  SSInvokedContextBase *result; // rax

  v1 = this;
  v2 = this->i_caller_p.i_obj_p;
  if ( v2 && v1->i_caller_p.i_ptr_id == v2->i_ptr_id )
    result = (SSInvokedContextBase *)((__int64 (*)(void))v2->vfptr[1].__vecDelDtor)();
  else
    result = 0i64;
  return result;
}

// File Line: 137
// RVA: 0x117830
SSInstance *__fastcall SSInvokedBase::get_data_by_name(SSInvokedBase *this, ASymbol *name)
{
  SSInvokedBase *v2; // r8
  SSObjectBase *v3; // rcx

  v2 = this;
  v3 = this->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  return (SSInstance *)v3->vfptr->get_data_by_name(v3, name);
}

// File Line: 156
// RVA: 0x13C520
void __fastcall SSInvokedBase::set_data_by_name(SSInvokedBase *this, ASymbol *name, SSInstance *obj_p)
{
  SSInvokedBase *v3; // r9
  SSObjectBase *v4; // rcx

  v3 = this;
  v4 = this->i_scope_p.i_obj_p;
  if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
    v4 = 0i64;
  v4->vfptr->set_data_by_name(v4, name, obj_p);
}

// File Line: 169
// RVA: 0x119FC0
SSInstance *__fastcall SSInvokedBase::get_topmost_scope(SSInvokedBase *this)
{
  SSInvokedBase *v1; // rdx
  SSObjectBase *v2; // rcx
  SSInstance *result; // rax

  v1 = this;
  v2 = this->i_scope_p.i_obj_p;
  if ( v2 && v1->i_scope_p.i_ptr_id == v2->i_ptr_id )
    result = (SSInstance *)((__int64 (*)(void))v2->vfptr->get_topmost_scope)();
  else
    result = SSBrain::c_nil_p;
  return result;
}

// File Line: 185
// RVA: 0x1096D0
void __fastcall SSInvokedBase::abort_subcalls(SSInvokedBase *this, eSSNotify notify_caller)
{
  unsigned int v2; // eax
  eSSNotify v3; // ebp
  SSInvokedBase *v4; // rsi
  AList<SSInvokedBase,SSInvokedBase> *v5; // rbx
  signed int i; // edi
  AListNode<SSInvokedBase,SSInvokedBase> *v7; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v8; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v9; // rax
  unsigned int v10; // eax
  SSInvokedBase *v11; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v12; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v13; // rsi
  AListNode<SSInvokedBase,SSInvokedBase> *v14; // rax

  v2 = this->i_ptr_id;
  v3 = notify_caller;
  v4 = this;
  if ( v2 && v2 <= SSObjectBase::c_ptr_id_prev )
  {
    v5 = &this->i_calls;
    for ( i = this->i_pending_count; (AList<SSInvokedBase,SSInvokedBase> *)v5->i_sentinel.i_next_p != v5; --i )
    {
      v7 = v5->i_sentinel.i_next_p;
      v8 = v5->i_sentinel.i_next_p->i_next_p;
      v9 = v5->i_sentinel.i_next_p->i_prev_p;
      v8->i_prev_p = v9;
      v9->i_next_p = v8;
      v7->i_prev_p = v7;
      v7->i_next_p = v7;
      v10 = (unsigned int)v7[-1].i_prev_p;
      if ( v10 && v10 <= SSObjectBase::c_ptr_id_prev )
        ((void (__fastcall *)(AListNode<SSInvokedBase,SSInvokedBase> **, _QWORD, signed __int64))v7[-1].i_next_p[5].i_prev_p)(
          &v7[-1].i_next_p,
          0i64,
          1i64);
    }
    if ( i <= 0 )
    {
      v4->i_pending_count = 0;
      if ( v3 )
      {
        v11 = v4->i_caller_p.i_obj_p;
        if ( v11 )
        {
          if ( v4->i_caller_p.i_ptr_id == v11->i_ptr_id )
          {
            v12 = v4->i_next_p;
            v13 = (AListNode<SSInvokedBase,SSInvokedBase> *)&v4->i_next_p;
            if ( v12 != v13 )
            {
              v14 = v13->i_prev_p;
              v12->i_prev_p = v14;
              v14->i_next_p = v12;
              v13->i_prev_p = v13;
              v13->i_next_p = v13;
            }
            LOBYTE(v12) = v3 == 3;
            v11->vfptr[1].get_data_by_name((SSObjectBase *)&v11->vfptr, (ASymbol *)v12);
          }
        }
      }
    }
    else
    {
      v4->i_pending_count = i;
    }
  }
}

// File Line: 263
// RVA: 0x113B70
void __fastcall SSInvokedBase::detach_subcalls(SSInvokedBase *this, eSSNotify notify_caller)
{
  signed int v2; // er11
  AList<SSInvokedBase,SSInvokedBase> *v3; // r10
  eSSNotify i; // ebx
  AListNode<SSInvokedBase,SSInvokedBase> *v5; // r9
  AListNode<SSInvokedBase,SSInvokedBase> *v6; // r8
  AListNode<SSInvokedBase,SSInvokedBase> *v7; // rax
  SSInvokedBase *v8; // r8
  AListNode<SSInvokedBase,SSInvokedBase> *v9; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v10; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v11; // rax

  v2 = this->i_pending_count;
  v3 = &this->i_calls;
  for ( i = notify_caller; (AList<SSInvokedBase,SSInvokedBase> *)v3->i_sentinel.i_next_p != v3; LODWORD(v5[2].i_prev_p) = 0 )
  {
    v5 = v3->i_sentinel.i_next_p;
    --v2;
    v6 = v3->i_sentinel.i_next_p->i_next_p;
    v7 = v3->i_sentinel.i_next_p->i_prev_p;
    v6->i_prev_p = v7;
    v7->i_next_p = v6;
    v5->i_prev_p = v5;
    v5->i_next_p = v5;
    v5[2].i_next_p = 0i64;
  }
  if ( v2 <= 0 )
  {
    this->i_pending_count = 0;
    if ( notify_caller )
    {
      v8 = this->i_caller_p.i_obj_p;
      if ( v8 )
      {
        if ( this->i_caller_p.i_ptr_id == v8->i_ptr_id )
        {
          v9 = (AListNode<SSInvokedBase,SSInvokedBase> *)&this->i_next_p;
          v10 = this->i_next_p;
          if ( v10 != v9 )
          {
            v11 = v9->i_prev_p;
            v10->i_prev_p = v11;
            v11->i_next_p = v10;
            v9->i_prev_p = v9;
            v9->i_next_p = v9;
          }
          LOBYTE(v9) = i == 3;
          v8->vfptr[1].get_data_by_name((SSObjectBase *)&v8->vfptr, (ASymbol *)v9);
        }
      }
    }
  }
  else
  {
    this->i_pending_count = v2;
  }
}

// File Line: 411
// RVA: 0x1358B0
void SSInvokedBase::register_atomic(void)
{
  SSClass *v0; // rbx
  ASymbol *v1; // rax
  SSClass *v2; // rbx
  ASymbol *v3; // rax
  SSClass *v4; // rbx
  ASymbol *v5; // rax
  SSClass *v6; // rbx
  ASymbol *v7; // rax
  SSClass *v8; // rbx
  ASymbol *v9; // rax
  SSClass *v10; // rbx
  ASymbol *v11; // rax
  SSClass *v12; // rbx
  ASymbol *v13; // rax
  __int64 v14; // rax
  SSMethodBase **v15; // r8
  signed __int64 v16; // r10
  signed __int64 v17; // rcx
  unsigned int v18; // er9
  _BOOL8 v19; // r9
  __int64 v20; // rbx
  __int64 v21; // rbp
  SSParameters *v22; // rdi
  SSParameters *v23; // rsi
  bool v24; // zf
  __int64 v25; // rax
  SSMethodBase **v26; // r8
  signed __int64 v27; // r10
  signed __int64 v28; // rdx
  unsigned int v29; // er9
  _BOOL8 v30; // r9
  __int64 v31; // rbx
  __int64 v32; // rbp
  SSParameters *v33; // rdi
  SSParameters *v34; // rsi
  SSClass *v35; // rbx
  ASymbol *v36; // rax
  SSClass *v37; // rbx
  ASymbol *v38; // rax
  SSClass *v39; // rbx
  ASymbol *v40; // rax
  ASymbol result; // [rsp+70h] [rbp+8h]
  SSParameters *v42; // [rsp+78h] [rbp+10h]
  __int64 v43; // [rsp+80h] [rbp+18h]

  v0 = SSBrain::c_invoked_base_class_p;
  v1 = ASymbol::create(&result, "abort", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v0, v1, SSInvokedBase::mthd_abort, 0);
  v2 = SSBrain::c_invoked_base_class_p;
  v3 = ASymbol::create(&result, "abort_subcalls", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v2, v3, SSInvokedBase::mthd_abort_subcalls, 0);
  v4 = SSBrain::c_invoked_base_class_p;
  v5 = ASymbol::create(&result, "detach", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v4, v5, SSInvokedBase::mthd_detach, 0);
  v6 = SSBrain::c_invoked_base_class_p;
  v7 = ASymbol::create(&result, "detach_subcalls", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v6, v7, SSInvokedBase::mthd_detach_subcalls, 0);
  v8 = SSBrain::c_invoked_base_class_p;
  v9 = ASymbol::create(&result, "get_data_by_name", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v8, v9, SSInvokedBase::mthd_get_data_by_name, 0);
  v10 = SSBrain::c_invoked_base_class_p;
  v11 = ASymbol::create(&result, "get_pending_count", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v10, v11, SSInvokedBase::mthd_get_pending_count, 0);
  v12 = SSBrain::c_invoked_base_class_p;
  v13 = ASymbol::create(&result, "is_valid", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v12, v13, SSInvokedBase::mthd_is_valid, 0);
  v14 = SSBrain::c_invoked_base_class_p->i_methods.i_count;
  if ( (_DWORD)v14 )
  {
    v15 = SSBrain::c_invoked_base_class_p->i_methods.i_array_p;
    v16 = (signed __int64)&v15[v14 - 1];
    while ( 1 )
    {
      v17 = (signed __int64)&v15[(v16 - (signed __int64)v15) >> 4];
      v18 = *(_DWORD *)(*(_QWORD *)v17 + 8i64);
      if ( ASymbol_equals.i_uid < v18 )
        goto LABEL_54;
      v19 = ASymbol_equals.i_uid != v18;
      if ( !v19 )
      {
        v20 = *(_QWORD *)v17;
        goto LABEL_12;
      }
      if ( v19 < 0 )
      {
LABEL_54:
        if ( v15 == (SSMethodBase **)v17 )
          break;
        v16 = v17 - 8;
      }
      else
      {
        if ( v16 == v17 )
          break;
        v15 = (SSMethodBase **)(v17 + 8);
      }
    }
  }
  v20 = 0i64;
LABEL_12:
  *(_QWORD *)&result.i_uid = v20;
  if ( v20 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v20 + 16i64))(v20) == 1 )
    {
      *(_QWORD *)(v20 + 32) = SSInvokedBase::mthd_op_equals;
    }
    else
    {
      v21 = *(_QWORD *)(v20 + 16);
      v22 = *(SSParameters **)(v20 + 24);
      v42 = v22;
      if ( v22 )
        ++v22->i_ref_count;
      v23 = *(SSParameters **)(v20 + 24);
      if ( v23 )
      {
        v24 = v23->i_ref_count-- == 1;
        if ( v24 )
        {
          v23->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v23);
          AMemory::c_free_func(v23);
        }
        *(_QWORD *)(v20 + 24) = 0i64;
      }
      v43 = v20;
      *(ASymbol *)(v20 + 8) = ASymbol_equals;
      *(_QWORD *)(v20 + 16) = v21;
      *(_QWORD *)v20 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v20 + 24) = v22;
      if ( v22 )
        ++v22->i_ref_count;
      *(_QWORD *)v20 = &SSMethodBase::`vftable;
      *(_QWORD *)v20 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v20 + 32) = SSInvokedBase::mthd_op_equals;
      if ( v22 )
      {
        v24 = v22->i_ref_count-- == 1;
        if ( v24 )
        {
          v22->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v22);
          AMemory::c_free_func(v22);
        }
      }
    }
  }
  v25 = SSBrain::c_invoked_base_class_p->i_methods.i_count;
  if ( (_DWORD)v25 )
  {
    v26 = SSBrain::c_invoked_base_class_p->i_methods.i_array_p;
    v27 = (signed __int64)&v26[v25 - 1];
    while ( 1 )
    {
      v28 = (signed __int64)&v26[(v27 - (signed __int64)v26) >> 4];
      v29 = *(_DWORD *)(*(_QWORD *)v28 + 8i64);
      if ( ASymbol_not_equal.i_uid < v29 )
        goto LABEL_55;
      v30 = ASymbol_not_equal.i_uid != v29;
      if ( !v30 )
      {
        v31 = *(_QWORD *)v28;
        goto LABEL_37;
      }
      if ( v30 < 0 )
      {
LABEL_55:
        if ( v26 == (SSMethodBase **)v28 )
          break;
        v27 = v28 - 8;
      }
      else
      {
        if ( v27 == v28 )
          break;
        v26 = (SSMethodBase **)(v28 + 8);
      }
    }
  }
  v31 = 0i64;
LABEL_37:
  *(_QWORD *)&result.i_uid = v31;
  if ( v31 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v31 + 16i64))(v31) == 1 )
    {
      *(_QWORD *)(v31 + 32) = SSInvokedBase::mthd_op_not_equal;
    }
    else
    {
      v32 = *(_QWORD *)(v31 + 16);
      v33 = *(SSParameters **)(v31 + 24);
      v42 = v33;
      if ( v33 )
        ++v33->i_ref_count;
      v34 = *(SSParameters **)(v31 + 24);
      if ( v34 )
      {
        v24 = v34->i_ref_count-- == 1;
        if ( v24 )
        {
          v34->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v34);
          AMemory::c_free_func(v34);
        }
        *(_QWORD *)(v31 + 24) = 0i64;
      }
      v43 = v31;
      *(ASymbol *)(v31 + 8) = ASymbol_not_equal;
      *(_QWORD *)(v31 + 16) = v32;
      *(_QWORD *)v31 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v31 + 24) = v33;
      if ( v33 )
        ++v33->i_ref_count;
      *(_QWORD *)v31 = &SSMethodBase::`vftable;
      *(_QWORD *)v31 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v31 + 32) = SSInvokedBase::mthd_op_not_equal;
      if ( v33 )
      {
        v24 = v33->i_ref_count-- == 1;
        if ( v24 )
        {
          v33->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v33);
          AMemory::c_free_func(v33);
        }
      }
    }
  }
  v35 = SSBrain::c_invoked_base_class_p;
  v36 = ASymbol::create(&result, "pending_decrement", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v35, v36, SSInvokedBase::mthd_pending_decrement, 0);
  v37 = SSBrain::c_invoked_base_class_p;
  v38 = ASymbol::create(&result, "pending_increment", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v37, v38, SSInvokedBase::mthd_pending_increment, 0);
  v39 = SSBrain::c_invoked_base_class_p;
  v40 = ASymbol::create(&result, "set_data_by_name", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v39, v40, SSInvokedBase::mthd_set_data_by_name, 0);
}

// File Line: 435
// RVA: 0x120840
void __fastcall SSInvokedBase::mthd_abort(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdx
  __int64 v3; // r8
  SSInvokedMethod *v4; // r9
  SSObjectBaseVtbl *v5; // rcx
  SSData **v6; // r9
  signed __int64 v7; // rdx

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = 0i64;
  v4 = scope_p;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v5 = v2[2].vfptr;
  if ( v5 && v2[2].i_ptr_id == LODWORD(v5->get_obj_type) )
  {
    v6 = v4->i_data.i_array_p;
    v7 = 1i64;
    if ( (*v6)->i_data_p->i_user_data )
      v7 = 3i64;
    LOBYTE(v3) = v6[1]->i_data_p->i_user_data != 0;
    (*((void (__fastcall **)(SSObjectBaseVtbl *, signed __int64, __int64))v5->__vecDelDtor + 11))(v5, v7, v3);
  }
}

// File Line: 455
// RVA: 0x1208B0
void __fastcall SSInvokedBase::mthd_abort_subcalls(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdx
  SSInvokedMethod *v3; // r8
  SSInvokedBase *v4; // rcx
  eSSNotify v5; // edx

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = scope_p;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = (SSInvokedBase *)v2[2].vfptr;
  if ( v4 && v2[2].i_ptr_id == v4->i_ptr_id )
  {
    v5 = 1;
    if ( (*v3->i_data.i_array_p)->i_data_p->i_user_data )
      v5 = 3;
    SSInvokedBase::abort_subcalls(v4, v5);
  }
}

// File Line: 474
// RVA: 0x122150
void __fastcall SSInvokedBase::mthd_detach(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8
  SSObjectBaseVtbl *v3; // rdx
  signed int v4; // er9
  SSInvokedContextBase *(__fastcall *v5)(SSObjectBase *); // rcx
  bool (__fastcall *v6)(SSObjectBase *); // r8
  bool (__fastcall **v7)(SSObjectBase *); // rdx
  bool (__fastcall **v8)(SSObjectBase *); // rax

  v2 = scope_p->i_scope_p.i_obj_p;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  if ( v3 && v2[2].i_ptr_id == LODWORD(v3->get_obj_type) )
  {
    v4 = 1;
    if ( (*scope_p->i_data.i_array_p)->i_data_p->i_user_data > 0 )
      v4 = 3;
    v5 = v3->get_scope_context;
    if ( !v5 || LODWORD(v3->get_topmost_scope) != *((_DWORD *)v5 + 2) )
      v5 = 0i64;
    v3->get_scope_context = 0i64;
    LODWORD(v3->get_topmost_scope) = 0;
    if ( v5 && v4 )
    {
      v6 = v3->is_actor;
      v7 = &v3->is_actor;
      if ( (char *)v6 != (char *)v7 )
      {
        v8 = (bool (__fastcall **)(SSObjectBase *))v7[1];
        *((_QWORD *)v6 + 1) = v8;
        *v8 = v6;
        v7[1] = (bool (__fastcall *)(SSObjectBase *))v7;
        *v7 = (bool (__fastcall *)(SSObjectBase *))v7;
      }
      LOBYTE(v7) = v4 == 3;
      (*(void (__fastcall **)(SSInvokedContextBase *(__fastcall *)(SSObjectBase *), bool (__fastcall **)(SSObjectBase *)))(*(_QWORD *)v5 + 96i64))(
        v5,
        v7);
    }
  }
}

// File Line: 493
// RVA: 0x1221F0
void __fastcall SSInvokedBase::mthd_detach_subcalls(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdx
  SSInvokedMethod *v3; // r8
  SSInvokedBase *v4; // rcx
  eSSNotify v5; // edx

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = scope_p;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = (SSInvokedBase *)v2[2].vfptr;
  if ( v4 && v2[2].i_ptr_id == v4->i_ptr_id )
  {
    v5 = 1;
    if ( (*v3->i_data.i_array_p)->i_data_p->i_user_data )
      v5 = 3;
    SSInvokedBase::detach_subcalls(v4, v5);
  }
}

// File Line: 512
// RVA: 0x122610
void __fastcall SSInvokedBase::mthd_get_data_by_name(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8
  __int64 v3; // r9
  SSInstance **v4; // rdi
  SSInvokedMethod *v5; // rbx
  SSObjectBaseVtbl *v6; // rcx
  bool v7; // al
  SSInstance *v8; // rcx

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = 0i64;
  v4 = result_pp;
  v5 = scope_p;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v6 = v2[2].vfptr;
  if ( !v6 || v2[2].i_ptr_id != LODWORD(v6->get_obj_type) )
    v6 = 0i64;
  v7 = 0;
  if ( v6 )
  {
    v3 = (*((__int64 (__fastcall **)(SSObjectBaseVtbl *, unsigned __int64 *, SSObjectBase *, _QWORD))v6->__vecDelDtor + 4))(
           v6,
           &(*v5->i_data.i_array_p)->i_data_p->i_user_data,
           v2,
           0i64);
    v7 = v3 != 0;
  }
  if ( v4 )
  {
    v8 = SSBrain::c_nil_p;
    if ( v7 )
      v8 = (SSInstance *)v3;
    *v4 = v8;
    ++v8->i_ref_count;
  }
  *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v5->i_data.i_array_p + 1) + 8i64) + 32i64) = v7;
}

// File Line: 542
// RVA: 0x1228D0
void __fastcall SSInvokedBase::mthd_get_pending_count(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8
  unsigned int v3; // er9
  SSObjectBaseVtbl *v4; // rcx

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    v3 = 0;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    if ( v4 )
    {
      if ( v2[2].i_ptr_id == LODWORD(v4->get_obj_type) )
        v3 = (unsigned int)v4[1].is_actor;
    }
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, v3);
  }
}

// File Line: 561
// RVA: 0x122E40
void __fastcall SSInvokedBase::mthd_is_valid(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8
  SSObjectBaseVtbl *v3; // rcx

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v3 = v2[2].vfptr;
    if ( !v3 || v2[2].i_ptr_id != LODWORD(v3->get_obj_type) )
      v3 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new(v3 != 0i64);
  }
}

// File Line: 580
// RVA: 0x123C50
void __fastcall SSInvokedBase::mthd_op_equals(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new(*(_QWORD *)&v2[2].i_ptr_id == (*scope_p->i_data.i_array_p)->i_data_p->i_user_data2);
  }
}

// File Line: 598
// RVA: 0x124680
void __fastcall SSInvokedBase::mthd_op_not_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new(*(_QWORD *)&v2[2].i_ptr_id != (*scope_p->i_data.i_array_p)->i_data_p->i_user_data2);
  }
}

// File Line: 616
// RVA: 0x124A50
void __fastcall SSInvokedBase::mthd_pending_decrement(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdx
  SSInvokedMethod *v3; // r9
  SSObjectBaseVtbl *v4; // rcx
  SSData *v5; // rdx

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = scope_p;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = v2[2].vfptr;
  if ( v4 )
  {
    if ( v2[2].i_ptr_id == LODWORD(v4->get_obj_type) )
    {
      v5 = *v3->i_data.i_array_p;
      LOBYTE(v5) = v5->i_data_p->i_user_data != 0;
      (*((void (__fastcall **)(SSObjectBaseVtbl *, SSData *))v4->__vecDelDtor + 12))(v4, v5);
    }
  }
}

// File Line: 634
// RVA: 0x124AA0
void __fastcall SSInvokedBase::mthd_pending_increment(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdx
  SSObjectBaseVtbl *v3; // r8
  int v4; // ecx

  v2 = scope_p->i_scope_p.i_obj_p;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  if ( v3 && v2[2].i_ptr_id == LODWORD(v3->get_obj_type) )
  {
    v4 = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    if ( v4 < 0 )
      v4 = 0;
    LODWORD(v3[1].is_actor) += v4;
  }
}

// File Line: 652
// RVA: 0x1256B0
void __fastcall SSInvokedBase::mthd_set_data_by_name(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdx
  SSInvokedMethod *v3; // r8
  SSObjectBaseVtbl *v4; // rcx

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = scope_p;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = v2[2].vfptr;
  if ( v4 )
  {
    if ( v2[2].i_ptr_id == LODWORD(v4->get_obj_type) )
      (*((void (__fastcall **)(SSObjectBaseVtbl *, unsigned __int64 *, _QWORD))v4->__vecDelDtor + 5))(
        v4,
        &(*v3->i_data.i_array_p)->i_data_p->i_user_data,
        *(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 1) + 8i64));
  }
}

// File Line: 679
// RVA: 0x109620
void __fastcall SSInvokedExpression::abort_invoke(SSInvokedExpression *this, eSSNotify notify_caller, eSSNotifyChild notify_child)
{
  unsigned int v3; // eax
  eSSNotifyChild v4; // esi
  eSSNotify v5; // edi
  SSInvokedExpression *v6; // rbx

  v3 = this->i_ptr_id;
  v4 = notify_child;
  v5 = notify_caller;
  v6 = this;
  if ( v3 && v3 <= SSObjectBase::c_ptr_id_prev )
  {
    this->i_expr_p->vfptr->invoke_exit(this->i_expr_p, this, 0i64);
    v6->i_pending_count = 0;
    if ( v4 == 1 )
      SSInvokedBase::abort_subcalls((SSInvokedBase *)&v6->vfptr, v5);
    else
      SSInvokedBase::detach_subcalls((SSInvokedBase *)&v6->vfptr, v5);
    SSInvokedExpression::pool_delete(v6);
  }
}

// File Line: 707
// RVA: 0x1304C0
void __fastcall SSInvokedExpression::pending_return(SSInvokedExpression *this, bool completed)
{
  unsigned int v2; // eax

  v2 = this->i_ptr_id;
  if ( v2 && v2 <= SSObjectBase::c_ptr_id_prev )
  {
    --this->i_pending_count;
    if ( completed )
    {
      if ( !this->i_pending_count )
      {
        ++this->i_index;
        this->i_expr_p->vfptr->invoke_iterate(this->i_expr_p, this, 0i64);
      }
    }
    else
    {
      ((void (__fastcall *)(SSInvokedExpression *, signed __int64, signed __int64, SSInvokedExpression *))this->vfptr[1].as_instance)(
        this,
        1i64,
        1i64,
        this);
    }
  }
}

// File Line: 774
// RVA: 0x118E10
AObjReusePool<SSInvokedExpression> *__fastcall SSInvokedExpression::get_pool()
{
  unsigned int v0; // edi
  unsigned int v1; // ebx
  SSInvokedExpression **v2; // rax

  if ( _S6_3 & 1 )
    return &s_pool_2;
  _S6_3 |= 1u;
  v0 = Skookum::get_lib_vals()->i_pool_incr_iexpr;
  v1 = Skookum::get_lib_vals()->i_pool_init_iexpr;
  s_pool_2.i_pool.i_count = 0;
  *(_QWORD *)&dword_142175C28 = 0i64;
  unk_142175C30 = 0;
  if ( v1 )
  {
    unk_142175C30 = v1;
    v2 = APArrayBase<SSInvokedExpression>::alloc_array(v1);
  }
  else
  {
    unk_142175C30 = 0;
    v2 = (SSInvokedExpression **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  *(_QWORD *)&dword_142175C28 = v2;
  qword_142175C38 = 0i64;
  unk_142175C40 = 0;
  qword_142175C48 = 0i64;
  unk_142175C50 = 0;
  stru_142175C58.i_count = 0;
  stru_142175C58.i_array_p = 0i64;
  stru_142175C58.i_size = 0;
  unk_142175C70 = v0;
  AObjReusePool<SSInvokedExpression>::append_block(&s_pool_2, v1);
  atexit(SSInvokedExpression::get_pool_::_2_::_dynamic_atexit_destructor_for__s_pool__);
  return &s_pool_2;
}

// File Line: 790
// RVA: 0x130900
void __fastcall SSInvokedExpression::pool_delete(SSInvokedExpression *iexpr_p)
{
  unsigned int v1; // eax
  SSInvokedExpression *v2; // rbx
  AListNode<SSInvokedBase,SSInvokedBase> *v3; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v4; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v5; // r8
  AObjReusePool<SSInvokedExpression> *v6; // rax
  AObjBlock<SSInvokedExpression> *v7; // rcx
  unsigned __int64 v8; // rdx
  bool v9; // cf
  APArray<SSInvokedExpression,SSInvokedExpression,ACompareAddress<SSInvokedExpression> > *v10; // rcx

  v1 = iexpr_p->i_ptr_id;
  v2 = iexpr_p;
  if ( v1 && v1 <= SSObjectBase::c_ptr_id_prev )
  {
    v3 = iexpr_p->i_next_p;
    v4 = iexpr_p->i_prev_p;
    v5 = (AListNode<SSInvokedBase,SSInvokedBase> *)&iexpr_p->i_next_p;
    v3->i_prev_p = v4;
    v4->i_next_p = v3;
    v5->i_prev_p = v5;
    v5->i_next_p = v5;
    iexpr_p->i_ptr_id = 0;
    v6 = SSInvokedExpression::get_pool();
    v7 = v6->i_block_p;
    v8 = (unsigned __int64)v7->i_objects_a;
    if ( (unsigned __int64)v2 < v8 || (v9 = (unsigned __int64)v2 < v8 + 112i64 * v7->i_size, v10 = &v6->i_pool, !v9) )
      v10 = &v6->i_exp_pool;
    APArray<SSInvokedExpression,SSInvokedExpression,ACompareAddress<SSInvokedExpression>>::append(v10, v2);
  }
}

// File Line: 857
// RVA: 0x112F70
void __fastcall SSInvokedContextBase::data_append_args(SSInvokedContextBase *this, SSInstance **arguments_pp, unsigned int arg_count, SSInvokableBase *invokable_params)
{
  __int64 v4; // rdi
  SSInstance **v5; // r15
  SSInvokedContextBase *v6; // rsi
  SSParameters *v7; // rbp
  __int64 v8; // rbx
  unsigned int v9; // er12
  char *v10; // r14
  int v11; // er13
  unsigned __int64 v12; // rcx
  SSParameterBase **v13; // rbp
  SSParameterBase *v14; // r12
  SSInstance *v15; // rdi
  eSSParameter v16; // eax
  int v17; // eax
  _QWORD *v18; // rbx
  SSInvokedBase *v19; // rbx
  __int64 v20; // rax
  AObjReusePool<SSData> *v21; // rax
  AObjReusePool<SSData> *v22; // rbx
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // eax
  __int64 v26; // rcx
  SSData **v27; // rax
  SSData *v28; // rdx
  unsigned int v29; // eax
  char *v30; // rdi
  unsigned __int64 v31; // rbp
  signed __int64 v32; // r14
  unsigned int *v33; // rsi
  AObjReusePool<SSData> *v34; // rax
  AObjReusePool<SSData> *v35; // rbx
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // eax
  __int64 v39; // rcx
  SSData **v40; // rax
  SSData *v41; // rdx
  unsigned int v42; // eax
  SSInstance *v43; // [rsp+20h] [rbp-68h]
  unsigned __int64 v44; // [rsp+28h] [rbp-60h]
  SSInstance **v45; // [rsp+30h] [rbp-58h]
  __int64 v46; // [rsp+38h] [rbp-50h]
  _QWORD *v47; // [rsp+40h] [rbp-48h]
  unsigned int v48; // [rsp+90h] [rbp+8h]
  SSParameters *v49; // [rsp+A8h] [rbp+20h]

  v46 = -2i64;
  v4 = arg_count;
  v5 = arguments_pp;
  v6 = this;
  v7 = invokable_params->i_params_p.i_obj_p;
  v49 = v7;
  v8 = v7->i_params.i_count;
  v9 = v7->i_return_params.i_count;
  v48 = v9;
  if ( this->i_data.i_size < v9 + (unsigned int)v8 )
  {
    this->i_data.i_size = AMemory::c_req_byte_size_func(8 * (v9 + v8)) >> 3;
    AMemory::c_free_func(v6->i_data.i_array_p);
    v6->i_data.i_array_p = APArrayBase<SSData>::alloc_array(v6->i_data.i_size);
  }
  v6->i_data.i_count = 0;
  v10 = (char *)v6->i_data.i_array_p;
  v11 = 0;
  if ( !(_DWORD)v8 )
    goto LABEL_30;
  v12 = (unsigned __int64)&v5[v4];
  v45 = &v5[v4];
  v13 = v7->i_params.i_array_p;
  v44 = (unsigned __int64)&v13[v8];
  if ( (unsigned __int64)v13 >= v44 )
    goto LABEL_29;
  do
  {
    v14 = *v13;
    v15 = 0i64;
    if ( (unsigned __int64)v5 >= v12 || (v15 = *v5, ++v5, !v15) )
    {
      v16 = (unsigned int)v14->vfptr->get_kind(*v13);
      if ( v16 )
      {
        v17 = v16 - 1;
        if ( v17 )
        {
          if ( v17 == 2 )
          {
            v18 = AMemory::c_malloc_func(0x18ui64, "SSList");
            v47 = v18;
            if ( v18 )
            {
              *(_DWORD *)v18 = 0;
              v18[1] = 0i64;
              *((_DWORD *)v18 + 4) = 0;
              v18[1] = AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
            }
            else
            {
              v18 = 0i64;
            }
            v15 = SSInstance::pool_new(SSBrain::c_list_class_p, (unsigned __int64)v18);
          }
        }
        else
        {
          v19 = v6->i_caller_p.i_obj_p;
          if ( !v19 || v6->i_caller_p.i_ptr_id != v19->i_ptr_id )
            v19 = 0i64;
          v20 = (__int64)v14->vfptr->get_default_expr(v14);
          (*(void (__fastcall **)(__int64, SSInvokedContextBase *, SSInvokedBase *, SSInstance **))(*(_QWORD *)v20
                                                                                                  + 32i64))(
            v20,
            v6,
            v19,
            &v43);
          v15 = v43;
        }
      }
      else
      {
        v15 = SSBrain::c_nil_p;
      }
    }
    v21 = SSData::get_pool();
    v22 = v21;
    v23 = v21->i_pool.i_count;
    if ( v23 )
    {
      v29 = v23 - 1;
      v22->i_pool.i_count = v29;
      v26 = v29;
      v27 = v22->i_pool.i_array_p;
    }
    else
    {
      if ( !v22->i_exp_pool.i_count )
        AObjReusePool<SSData>::append_block(v22, v22->i_expand_size);
      v24 = v22->i_exp_pool.i_count;
      if ( !v24 )
      {
        v28 = 0i64;
        goto LABEL_27;
      }
      v25 = v24 - 1;
      v22->i_exp_pool.i_count = v25;
      v26 = v25;
      v27 = v22->i_exp_pool.i_array_p;
    }
    v28 = v27[v26];
LABEL_27:
    v28->i_name.i_uid = v14->i_name.i_uid;
    v28->i_data_p = v15;
    *(_QWORD *)v10 = v28;
    v6->i_data.i_count = ++v11;
    v10 += 8;
    ++v13;
    v12 = (unsigned __int64)v45;
  }
  while ( (unsigned __int64)v13 < v44 );
  v9 = v48;
LABEL_29:
  v7 = v49;
LABEL_30:
  if ( v9 )
  {
    v30 = (char *)v7->i_return_params.i_array_p;
    v31 = (unsigned __int64)&v30[8 * v9];
    v6->i_data.i_count = v9 + v11;
    if ( (unsigned __int64)v30 < v31 )
    {
      v32 = v10 - v30;
      while ( 1 )
      {
        v33 = *(unsigned int **)v30;
        v34 = SSData::get_pool();
        v35 = v34;
        v36 = v34->i_pool.i_count;
        if ( v36 )
          break;
        if ( !v35->i_exp_pool.i_count )
          AObjReusePool<SSData>::append_block(v35, v35->i_expand_size);
        v37 = v35->i_exp_pool.i_count;
        if ( v37 )
        {
          v38 = v37 - 1;
          v35->i_exp_pool.i_count = v38;
          v39 = v38;
          v40 = v35->i_exp_pool.i_array_p;
LABEL_40:
          v41 = v40[v39];
          goto LABEL_41;
        }
        v41 = 0i64;
LABEL_41:
        v41->i_name.i_uid = *v33;
        v41->i_data_p = SSBrain::c_nil_p;
        *(_QWORD *)&v30[v32] = v41;
        v30 += 8;
        if ( (unsigned __int64)v30 >= v31 )
          return;
      }
      v42 = v36 - 1;
      v35->i_pool.i_count = v42;
      v39 = v42;
      v40 = v35->i_pool.i_array_p;
      goto LABEL_40;
    }
  }
}

// File Line: 990
// RVA: 0x113210
void __fastcall SSInvokedContextBase::data_append_args_exprs(SSInvokedContextBase *this, APArrayBase<SSExpressionBase> *args, SSInvokableBase *invokable_params, SSObjectBase *arg_scope_p)
{
  APArrayBase<SSExpressionBase> *v4; // rsi
  SSInvokedContextBase *v5; // r13
  SSParameters *v6; // rbp
  __int64 v7; // rbx
  unsigned int v8; // er15
  char *v9; // r14
  int v10; // ecx
  SSInstance *v11; // rdi
  SSInvokedBase *v12; // r12
  SSExpressionBase **v13; // r15
  unsigned __int64 v14; // rdx
  SSParameterBase **v15; // rbp
  SSExpressionBase *v16; // rbx
  SSParameterBase *v17; // rsi
  eSSParameter v18; // eax
  int v19; // eax
  _QWORD *v20; // rbx
  __int64 v21; // rax
  AObjReusePool<SSData> *v22; // rax
  AObjReusePool<SSData> *v23; // rbx
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // eax
  __int64 v27; // rcx
  SSData **v28; // rax
  SSData *v29; // rdx
  unsigned int v30; // eax
  char *v31; // rdi
  unsigned __int64 v32; // rbp
  signed __int64 v33; // r14
  unsigned int *v34; // rsi
  AObjReusePool<SSData> *v35; // rax
  AObjReusePool<SSData> *v36; // rbx
  unsigned int v37; // eax
  unsigned int v38; // eax
  unsigned int v39; // eax
  __int64 v40; // rcx
  SSData **v41; // rax
  SSData *v42; // rdx
  unsigned int v43; // eax
  SSParameters *v44; // [rsp+20h] [rbp-88h]
  SSInstance *v45; // [rsp+28h] [rbp-80h]
  unsigned __int64 v46; // [rsp+30h] [rbp-78h]
  SSInstance *v47; // [rsp+38h] [rbp-70h]
  SSExpressionBase **v48; // [rsp+40h] [rbp-68h]
  SSInstance *v49; // [rsp+48h] [rbp-60h]
  SSInstance *v50; // [rsp+50h] [rbp-58h]
  __int64 v51; // [rsp+58h] [rbp-50h]
  _QWORD *v52; // [rsp+60h] [rbp-48h]
  int v53; // [rsp+B0h] [rbp+8h]
  unsigned int v54; // [rsp+C0h] [rbp+18h]
  SSObjectBase *v55; // [rsp+C8h] [rbp+20h]

  v55 = arg_scope_p;
  v51 = -2i64;
  v4 = args;
  v5 = this;
  v6 = invokable_params->i_params_p.i_obj_p;
  v44 = v6;
  v7 = v6->i_params.i_count;
  v8 = v6->i_return_params.i_count;
  v54 = v8;
  if ( this->i_data.i_size < v8 + (unsigned int)v7 )
  {
    this->i_data.i_size = AMemory::c_req_byte_size_func(8 * (v8 + v7)) >> 3;
    AMemory::c_free_func(v5->i_data.i_array_p);
    v5->i_data.i_array_p = APArrayBase<SSData>::alloc_array(v5->i_data.i_size);
  }
  v5->i_data.i_count = 0;
  v9 = (char *)v5->i_data.i_array_p;
  v10 = 0;
  v53 = 0;
  if ( (_DWORD)v7 )
  {
    v11 = 0i64;
    v12 = v5->i_caller_p.i_obj_p;
    if ( !v12 || v5->i_caller_p.i_ptr_id != v12->i_ptr_id )
      v12 = 0i64;
    v13 = v4->i_array_p;
    v14 = (unsigned __int64)&v13[v4->i_count];
    v48 = &v13[v4->i_count];
    v15 = v6->i_params.i_array_p;
    v46 = (unsigned __int64)&v15[v7];
    if ( (unsigned __int64)v15 < v46 )
    {
      while ( 1 )
      {
        v16 = 0i64;
        if ( (unsigned __int64)v13 < v14 )
        {
          v16 = *v13;
          ++v13;
        }
        v17 = *v15;
        v18 = (unsigned int)(*v15)->vfptr->get_kind(*v15);
        if ( v18 )
        {
          v19 = v18 - 1;
          if ( v19 )
          {
            if ( v19 == 2 )
            {
              if ( v16 )
              {
                v16->vfptr->invoke(v16, v55, v12, &v49);
                v11 = v49;
              }
              else
              {
                v20 = AMemory::c_malloc_func(0x18ui64, "SSList");
                v52 = v20;
                if ( v20 )
                {
                  *(_DWORD *)v20 = 0;
                  v20[1] = 0i64;
                  *((_DWORD *)v20 + 4) = 0;
                  v20[1] = AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
                }
                else
                {
                  v20 = 0i64;
                }
                v11 = SSInstance::pool_new(SSBrain::c_list_class_p, (unsigned __int64)v20);
              }
            }
          }
          else if ( v16 )
          {
            v16->vfptr->invoke(v16, v55, v12, &v47);
            v11 = v47;
          }
          else
          {
            v21 = (__int64)v17->vfptr->get_default_expr(v17);
            (*(void (__fastcall **)(__int64, SSInvokedContextBase *, SSInvokedBase *, SSInstance **))(*(_QWORD *)v21 + 32i64))(
              v21,
              v5,
              v12,
              &v50);
            v11 = v50;
          }
        }
        else
        {
          v16->vfptr->invoke(v16, v55, v12, &v45);
          v11 = v45;
        }
        v22 = SSData::get_pool();
        v23 = v22;
        v24 = v22->i_pool.i_count;
        if ( v24 )
          break;
        if ( !v23->i_exp_pool.i_count )
          AObjReusePool<SSData>::append_block(v23, v23->i_expand_size);
        v25 = v23->i_exp_pool.i_count;
        if ( v25 )
        {
          v26 = v25 - 1;
          v23->i_exp_pool.i_count = v26;
          v27 = v26;
          v28 = v23->i_exp_pool.i_array_p;
LABEL_30:
          v29 = v28[v27];
          goto LABEL_31;
        }
        v29 = 0i64;
LABEL_31:
        v29->i_name.i_uid = v17->i_name.i_uid;
        v29->i_data_p = v11;
        *(_QWORD *)v9 = v29;
        v10 = v53 + 1;
        v53 = v10;
        v5->i_data.i_count = v10;
        v9 += 8;
        ++v15;
        v14 = (unsigned __int64)v48;
        if ( (unsigned __int64)v15 >= v46 )
          goto LABEL_32;
      }
      v30 = v24 - 1;
      v23->i_pool.i_count = v30;
      v27 = v30;
      v28 = v23->i_pool.i_array_p;
      goto LABEL_30;
    }
LABEL_32:
    v6 = v44;
    v8 = v54;
  }
  if ( v8 )
  {
    v31 = (char *)v6->i_return_params.i_array_p;
    v32 = (unsigned __int64)&v31[8 * v8];
    v5->i_data.i_count = v10 + v8;
    if ( (unsigned __int64)v31 < v32 )
    {
      v33 = v9 - v31;
      while ( 1 )
      {
        v34 = *(unsigned int **)v31;
        v35 = SSData::get_pool();
        v36 = v35;
        v37 = v35->i_pool.i_count;
        if ( v37 )
          break;
        if ( !v36->i_exp_pool.i_count )
          AObjReusePool<SSData>::append_block(v36, v36->i_expand_size);
        v38 = v36->i_exp_pool.i_count;
        if ( v38 )
        {
          v39 = v38 - 1;
          v36->i_exp_pool.i_count = v39;
          v40 = v39;
          v41 = v36->i_exp_pool.i_array_p;
LABEL_43:
          v42 = v41[v40];
          goto LABEL_44;
        }
        v42 = 0i64;
LABEL_44:
        v42->i_name.i_uid = *v34;
        v42->i_data_p = SSBrain::c_nil_p;
        *(_QWORD *)&v31[v33] = v42;
        v31 += 8;
        if ( (unsigned __int64)v31 >= v32 )
          return;
      }
      v43 = v37 - 1;
      v36->i_pool.i_count = v43;
      v40 = v43;
      v41 = v36->i_pool.i_array_p;
      goto LABEL_43;
    }
  }
}

// File Line: 1105
// RVA: 0x113540
void __fastcall SSInvokedContextBase::data_append_vars(SSInvokedContextBase *this, AVCompactArrayBase<ASymbol> *var_names)
{
  __int64 v2; // r8
  ASymbol *v3; // rsi
  APArrayLogical<SSData,ASymbol> *v4; // rdi
  unsigned __int64 v5; // r15
  AObjReusePool<SSData> *v6; // rax
  AObjReusePool<SSData> *v7; // rbx
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  __int64 v11; // rcx
  SSData **v12; // rax
  SSData *v13; // rbx
  unsigned int v14; // eax
  __int64 v15; // rbp
  SSData **v16; // r14
  unsigned __int64 v17; // rax
  SSData **v18; // rax

  v2 = var_names->i_count;
  v3 = var_names->i_array_p;
  v4 = &this->i_data;
  v5 = (unsigned __int64)&v3[v2];
  APSizedArrayBase<SSData>::ensure_size((APSizedArrayBase<SSData> *)&this->i_data.i_count, v2 + this->i_data.i_count);
  if ( (unsigned __int64)v3 < v5 )
  {
    while ( 1 )
    {
      v6 = SSData::get_pool();
      v7 = v6;
      v8 = v6->i_pool.i_count;
      if ( v8 )
        break;
      if ( !v7->i_exp_pool.i_count )
        AObjReusePool<SSData>::append_block(v7, v7->i_expand_size);
      v9 = v7->i_exp_pool.i_count;
      if ( v9 )
      {
        v10 = v9 - 1;
        v7->i_exp_pool.i_count = v10;
        v11 = v10;
        v12 = v7->i_exp_pool.i_array_p;
LABEL_9:
        v13 = v12[v11];
        goto LABEL_10;
      }
      v13 = 0i64;
LABEL_10:
      v13->i_name = (ASymbol)v3->i_uid;
      v13->i_data_p = SSBrain::c_nil_p;
      v15 = v4->i_count;
      if ( v4->i_size < (unsigned int)(v15 + 1) )
      {
        v16 = v4->i_array_p;
        if ( (_DWORD)v15 == -1 )
          LODWORD(v17) = 0;
        else
          v17 = (unsigned __int64)AMemory::c_req_byte_size_func(32 * (((unsigned int)v15 >> 2) + 1)) >> 3;
        v4->i_size = v17;
        v18 = APArrayBase<SSData>::alloc_array(v17);
        v4->i_array_p = v18;
        memmove(v18, v16, 8 * v15);
        AMemory::c_free_func(v16);
      }
      ++v3;
      v4->i_array_p[v15] = v13;
      ++v4->i_count;
      if ( (unsigned __int64)v3 >= v5 )
        return;
    }
    v14 = v8 - 1;
    v7->i_pool.i_count = v14;
    v11 = v14;
    v12 = v7->i_pool.i_array_p;
    goto LABEL_9;
  }
}

// File Line: 1133
// RVA: 0x113660
void __fastcall SSInvokedContextBase::data_bind_return_args(SSInvokedContextBase *this, APArrayBase<SSIdentifier> *return_args, SSInvokableBase *invokable_params)
{
  SSInvokedContextBase *v3; // r9
  __int64 v4; // rcx
  SSObjectBase *v5; // rax
  SSIdentifier **v6; // rbx
  SSInvokedBase *v7; // rsi
  unsigned __int64 v8; // rbp
  signed __int64 i; // rdi
  _QWORD v10[2]; // [rsp+20h] [rbp-18h]

  v3 = this;
  v4 = return_args->i_count;
  if ( (_DWORD)v4 )
  {
    v5 = v3->i_scope_p.i_obj_p;
    if ( v5 )
    {
      if ( v3->i_scope_p.i_ptr_id == v5->i_ptr_id )
      {
        v6 = return_args->i_array_p;
        v7 = v3->i_caller_p.i_obj_p;
        v8 = (unsigned __int64)&v6[v4];
        if ( !v7 || v3->i_caller_p.i_ptr_id != v7->i_ptr_id )
          v7 = 0i64;
        for ( i = (signed __int64)&v3->i_data.i_array_p[invokable_params->i_params_p.i_obj_p->i_params.i_count];
              (unsigned __int64)v6 < v8;
              i += 8i64 )
        {
          if ( *v6 )
          {
            LOBYTE(v10[0]) = 0;
            (*((void (__fastcall **)(SSIdentifier *, _QWORD, SSInvokedBase *, SSInvokedBase *, _QWORD))&(*v6)->vfptr[1].__vecDelDtor
             + 1))(
              *v6,
              *(_QWORD *)(*(_QWORD *)i + 8i64),
              v7,
              v7,
              v10[0]);
          }
          ++v6;
        }
      }
    }
  }
}

// File Line: 1181
// RVA: 0x113720
void __fastcall SSInvokedContextBase::data_remove_vars(SSInvokedContextBase *this, AVCompactArrayBase<ASymbol> *var_names, SSInstance *delay_collect_p)
{
  SSInstance *v3; // rbp
  SSInvokedContextBase *v4; // rsi
  ASymbol *v5; // rdi
  unsigned __int64 v6; // r14
  unsigned int v7; // eax
  unsigned int v8; // edx
  SSData **v9; // r10
  __int64 v10; // r11
  unsigned __int64 v11; // r8
  SSData **v12; // rax
  signed __int64 v13; // rax
  SSData *v14; // rbx
  SSInstance *v15; // rcx
  bool v16; // zf
  AObjReusePool<SSData> *v17; // rax
  AObjBlock<SSData> *v18; // rcx
  unsigned __int64 v19; // rdx
  bool v20; // cf
  APArray<SSData,ASymbol,ACompareLogical<ASymbol> > *v21; // rcx

  v3 = delay_collect_p;
  v4 = this;
  if ( delay_collect_p )
    ++delay_collect_p->i_ref_count;
  v5 = var_names->i_array_p;
  v6 = (unsigned __int64)&v5[var_names->i_count];
  if ( (unsigned __int64)v5 >= v6 )
    goto LABEL_19;
  do
  {
    v7 = v4->i_data.i_count;
    v8 = 0;
    if ( !v7 )
      goto LABEL_18;
    v9 = v4->i_data.i_array_p;
    v10 = v7 - 1;
    v11 = (unsigned __int64)&v9[v10];
    v12 = v4->i_data.i_array_p;
    if ( (unsigned __int64)v9 > v11 )
      goto LABEL_18;
    while ( v5->i_uid != (*v12)->i_name.i_uid )
    {
LABEL_9:
      ++v12;
      if ( (unsigned __int64)v12 > v11 )
        goto LABEL_18;
    }
    if ( v8 >= 2 )
    {
      --v8;
      goto LABEL_9;
    }
    v13 = v12 - v9;
    v14 = v9[(unsigned int)v13];
    v4->i_data.i_count = v10;
    memmove(&v9[(unsigned int)v13], &v9[(unsigned int)(v13 + 1)], 8i64 * (unsigned int)(v10 - v13));
    if ( v14 )
    {
      v15 = v14->i_data_p;
      v16 = v15->i_ref_count-- == 1;
      if ( v16 )
      {
        v15->i_ref_count = 2147483648;
        ((void (*)(void))v15->vfptr[1].get_scope_context)();
      }
      v17 = SSData::get_pool();
      v18 = v17->i_block_p;
      v19 = (unsigned __int64)v18->i_objects_a;
      if ( (unsigned __int64)v14 < v19
        || (v20 = (unsigned __int64)v14 < v19 + 16i64 * v18->i_size,
            v21 = (APArray<SSData,ASymbol,ACompareLogical<ASymbol> > *)v17,
            !v20) )
      {
        v21 = (APArray<SSData,ASymbol,ACompareLogical<ASymbol> > *)&v17->i_exp_pool;
      }
      APArray<SSData,ASymbol,ACompareLogical<ASymbol>>::append(v21, v14);
    }
LABEL_18:
    ++v5;
  }
  while ( (unsigned __int64)v5 < v6 );
LABEL_19:
  if ( v3 )
    --v3->i_ref_count;
}

// File Line: 1277
// RVA: 0x117850
SSInstance *__fastcall SSInvokedContextBase::get_data_by_name(SSInvokedContextBase *this, ASymbol *name)
{
  __int64 v2; // rax
  SSInvokedContextBase *v3; // r11
  SSData **v4; // r8
  unsigned __int64 v5; // r9
  SSData *v6; // rax
  SSObjectBase *v7; // rcx

  v2 = this->i_data.i_count;
  v3 = this;
  if ( (_DWORD)v2 )
  {
    v4 = this->i_data.i_array_p;
    v5 = (unsigned __int64)&v4[v2];
    if ( (unsigned __int64)v4 < v5 )
    {
      while ( 1 )
      {
        v6 = *v4;
        if ( name->i_uid == (*v4)->i_name.i_uid )
          break;
        ++v4;
        if ( (unsigned __int64)v4 >= v5 )
          goto LABEL_5;
      }
      if ( v6 )
        return v6->i_data_p;
    }
  }
LABEL_5:
  v7 = this->i_scope_p.i_obj_p;
  if ( !v7 || v3->i_scope_p.i_ptr_id != v7->i_ptr_id )
    v7 = 0i64;
  return (SSInstance *)v7->vfptr->get_data_by_name(v7, name);
}

// File Line: 1321
// RVA: 0x13C540
void __fastcall SSInvokedContextBase::set_data_by_name(SSInvokedContextBase *this, ASymbol *name, SSInstance *obj_p)
{
  __int64 v3; // rax
  SSInstance *v4; // rdi
  SSInvokedContextBase *v5; // r11
  SSData **v6; // r9
  unsigned __int64 v7; // r10
  SSData *v8; // rax
  SSObjectBase *v9; // rcx
  SSData *v10; // rbx
  SSInstance *v11; // rcx
  bool v12; // zf

  v3 = this->i_data.i_count;
  v4 = obj_p;
  v5 = this;
  if ( !(_DWORD)v3 )
    goto LABEL_5;
  v6 = this->i_data.i_array_p;
  v7 = (unsigned __int64)&v6[v3];
  if ( (unsigned __int64)v6 >= v7 )
    goto LABEL_5;
  while ( 1 )
  {
    v8 = *v6;
    if ( name->i_uid == (*v6)->i_name.i_uid )
      break;
    ++v6;
    if ( (unsigned __int64)v6 >= v7 )
      goto LABEL_5;
  }
  v10 = *v6;
  if ( v8 )
  {
    ++obj_p->i_ref_count;
    v11 = v8->i_data_p;
    v12 = v11->i_ref_count-- == 1;
    if ( v12 )
    {
      v11->i_ref_count = 2147483648;
      ((void (*)(void))v11->vfptr[1].get_scope_context)();
    }
    v10->i_data_p = v4;
  }
  else
  {
LABEL_5:
    v9 = this->i_scope_p.i_obj_p;
    if ( !v9 || v5->i_scope_p.i_ptr_id != v9->i_ptr_id )
      v9 = 0i64;
    v9->vfptr->set_data_by_name(v9, name, obj_p);
  }
}


// File Line: 59
// RVA: 0x119E70
SSInvokedContextBase *__fastcall SSInvokedBase::get_scope_context(SSInvokedBase *this)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = this->i_scope_p.i_obj_p;
  if ( i_obj_p && this->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    return i_obj_p->vfptr->get_scope_context(i_obj_p);
  else
    return 0i64;
}

// File Line: 72
// RVA: 0x1174D0
SSInvokedContextBase *__fastcall SSInvokedBase::get_caller_context(SSInvokedBase *this)
{
  SSInvokedBase *i_obj_p; // rcx

  i_obj_p = this->i_caller_p.i_obj_p;
  if ( i_obj_p && this->i_caller_p.i_ptr_id == i_obj_p->i_ptr_id )
    return (SSInvokedContextBase *)((__int64 (__fastcall *)(SSInvokedBase *))i_obj_p->vfptr[1].__vecDelDtor)(i_obj_p);
  else
    return 0i64;
}

// File Line: 137
// RVA: 0x117830
SSInstance *__fastcall SSInvokedBase::get_data_by_name(SSInvokedBase *this, ASymbol *name)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = this->i_scope_p.i_obj_p;
  if ( !i_obj_p || this->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  return i_obj_p->vfptr->get_data_by_name(i_obj_p, name);
}

// File Line: 156
// RVA: 0x13C520
void __fastcall SSInvokedBase::set_data_by_name(SSInvokedBase *this, ASymbol *name, SSInstance *obj_p)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = this->i_scope_p.i_obj_p;
  if ( !i_obj_p || this->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_obj_p->vfptr->set_data_by_name(i_obj_p, name, obj_p);
}

// File Line: 169
// RVA: 0x119FC0
SSInstance *__fastcall SSInvokedBase::get_topmost_scope(SSInvokedBase *this)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = this->i_scope_p.i_obj_p;
  if ( i_obj_p && this->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    return i_obj_p->vfptr->get_topmost_scope(i_obj_p);
  else
    return SSBrain::c_nil_p;
}

// File Line: 185
// RVA: 0x1096D0
void __fastcall SSInvokedBase::abort_subcalls(SSInvokedBase *this, eSSNotify notify_caller)
{
  unsigned int i_ptr_id; // eax
  AList<SSInvokedBase,SSInvokedBase> *p_i_calls; // rbx
  int i; // edi
  AListNode<SSInvokedBase,SSInvokedBase> *i_next_p; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v8; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax
  unsigned int v10; // eax
  SSInvokedBase *i_obj_p; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v12; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v13; // rsi
  AListNode<SSInvokedBase,SSInvokedBase> *v14; // rax

  i_ptr_id = this->i_ptr_id;
  if ( i_ptr_id && i_ptr_id <= SSObjectBase::c_ptr_id_prev )
  {
    p_i_calls = &this->i_calls;
    for ( i = this->i_pending_count; (AList<SSInvokedBase,SSInvokedBase> *)p_i_calls->i_sentinel.i_next_p != p_i_calls; --i )
    {
      i_next_p = p_i_calls->i_sentinel.i_next_p;
      v8 = p_i_calls->i_sentinel.i_next_p->i_next_p;
      i_prev_p = p_i_calls->i_sentinel.i_next_p->i_prev_p;
      v8->i_prev_p = i_prev_p;
      i_prev_p->i_next_p = v8;
      i_next_p->i_prev_p = i_next_p;
      i_next_p->i_next_p = i_next_p;
      v10 = (unsigned int)i_next_p[-1].i_prev_p;
      if ( v10 && v10 <= SSObjectBase::c_ptr_id_prev )
        ((void (__fastcall *)(AListNode<SSInvokedBase,SSInvokedBase> **, _QWORD, __int64))i_next_p[-1].i_next_p[5].i_prev_p)(
          &i_next_p[-1].i_next_p,
          0i64,
          1i64);
    }
    if ( i <= 0 )
    {
      this->i_pending_count = 0;
      if ( notify_caller )
      {
        i_obj_p = this->i_caller_p.i_obj_p;
        if ( i_obj_p )
        {
          if ( this->i_caller_p.i_ptr_id == i_obj_p->i_ptr_id )
          {
            v12 = this->i_next_p;
            v13 = &this->AListNode<SSInvokedBase,SSInvokedBase>;
            if ( v12 != v13 )
            {
              v14 = v13->i_prev_p;
              v12->i_prev_p = v14;
              v14->i_next_p = v12;
              v13->i_prev_p = v13;
              v13->i_next_p = v13;
            }
            LOBYTE(v12) = notify_caller == SSNotify_success;
            i_obj_p->vfptr[1].get_data_by_name(i_obj_p, (ASymbol *)v12);
          }
        }
      }
    }
    else
    {
      this->i_pending_count = i;
    }
  }
}

// File Line: 263
// RVA: 0x113B70
void __fastcall SSInvokedBase::detach_subcalls(SSInvokedBase *this, eSSNotify notify_caller)
{
  int i_pending_count; // r11d
  AList<SSInvokedBase,SSInvokedBase> *i; // r10
  AListNode<SSInvokedBase,SSInvokedBase> *i_next_p; // r9
  AListNode<SSInvokedBase,SSInvokedBase> *v6; // r8
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax
  SSInvokedBase *i_obj_p; // r8
  AListNode<SSInvokedBase,SSInvokedBase> *v9; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v10; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v11; // rax

  i_pending_count = this->i_pending_count;
  for ( i = &this->i_calls;
        (AList<SSInvokedBase,SSInvokedBase> *)i->i_sentinel.i_next_p != i;
        LODWORD(i_next_p[2].i_prev_p) = 0 )
  {
    i_next_p = i->i_sentinel.i_next_p;
    --i_pending_count;
    v6 = i->i_sentinel.i_next_p->i_next_p;
    i_prev_p = i->i_sentinel.i_next_p->i_prev_p;
    v6->i_prev_p = i_prev_p;
    i_prev_p->i_next_p = v6;
    i_next_p->i_prev_p = i_next_p;
    i_next_p->i_next_p = i_next_p;
    i_next_p[2].i_next_p = 0i64;
  }
  if ( i_pending_count <= 0 )
  {
    this->i_pending_count = 0;
    if ( notify_caller )
    {
      i_obj_p = this->i_caller_p.i_obj_p;
      if ( i_obj_p )
      {
        if ( this->i_caller_p.i_ptr_id == i_obj_p->i_ptr_id )
        {
          v9 = &this->AListNode<SSInvokedBase,SSInvokedBase>;
          v10 = this->i_next_p;
          if ( v10 != v9 )
          {
            v11 = v9->i_prev_p;
            v10->i_prev_p = v11;
            v11->i_next_p = v10;
            v9->i_prev_p = v9;
            v9->i_next_p = v9;
          }
          LOBYTE(v9) = notify_caller == SSNotify_success;
          i_obj_p->vfptr[1].get_data_by_name(i_obj_p, (ASymbol *)v9);
        }
      }
    }
  }
  else
  {
    this->i_pending_count = i_pending_count;
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
  __int64 i_count; // rax
  SSMethodBase **i_array_p; // r8
  SSMethodBase **v16; // r10
  SSMethodBase **v17; // rcx
  unsigned int i_uid; // r9d
  __int64 v19; // rbx
  __int64 v20; // rbp
  SSParameters *v21; // rdi
  SSParameters *v22; // rsi
  bool v23; // zf
  __int64 v24; // rax
  SSMethodBase **v25; // r8
  SSMethodBase **v26; // r10
  SSMethodBase **v27; // rdx
  unsigned int v28; // r9d
  __int64 v29; // rbx
  __int64 v30; // rbp
  SSParameters *v31; // rdi
  SSParameters *v32; // rsi
  SSClass *v33; // rbx
  ASymbol *v34; // rax
  SSClass *v35; // rbx
  ASymbol *v36; // rax
  SSClass *v37; // rbx
  ASymbol *v38; // rax
  __int64 result; // [rsp+70h] [rbp+8h] BYREF
  SSParameters *v40; // [rsp+78h] [rbp+10h]
  __int64 v41; // [rsp+80h] [rbp+18h]

  v0 = SSBrain::c_invoked_base_class_p;
  v1 = ASymbol::create((ASymbol *)&result, "abort", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v0, v1, SSInvokedBase::mthd_abort, SSBindFlag_instance_no_rebind);
  v2 = SSBrain::c_invoked_base_class_p;
  v3 = ASymbol::create((ASymbol *)&result, "abort_subcalls", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v2, v3, SSInvokedBase::mthd_abort_subcalls, SSBindFlag_instance_no_rebind);
  v4 = SSBrain::c_invoked_base_class_p;
  v5 = ASymbol::create((ASymbol *)&result, "detach", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v4, v5, SSInvokedBase::mthd_detach, SSBindFlag_instance_no_rebind);
  v6 = SSBrain::c_invoked_base_class_p;
  v7 = ASymbol::create((ASymbol *)&result, "detach_subcalls", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v6, v7, SSInvokedBase::mthd_detach_subcalls, SSBindFlag_instance_no_rebind);
  v8 = SSBrain::c_invoked_base_class_p;
  v9 = ASymbol::create((ASymbol *)&result, "get_data_by_name", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v8, v9, SSInvokedBase::mthd_get_data_by_name, SSBindFlag_instance_no_rebind);
  v10 = SSBrain::c_invoked_base_class_p;
  v11 = ASymbol::create((ASymbol *)&result, "get_pending_count", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v10, v11, SSInvokedBase::mthd_get_pending_count, SSBindFlag_instance_no_rebind);
  v12 = SSBrain::c_invoked_base_class_p;
  v13 = ASymbol::create((ASymbol *)&result, "is_valid", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v12, v13, SSInvokedBase::mthd_is_valid, SSBindFlag_instance_no_rebind);
  i_count = SSBrain::c_invoked_base_class_p->i_methods.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = SSBrain::c_invoked_base_class_p->i_methods.i_array_p;
    v16 = &i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v17 = &i_array_p[((char *)v16 - (char *)i_array_p) >> 4];
        i_uid = (*v17)->i_name.i_uid;
        if ( ASymbol_equals.i_uid >= i_uid )
          break;
        if ( i_array_p == v17 )
          goto LABEL_10;
        v16 = v17 - 1;
      }
      if ( ASymbol_equals.i_uid == i_uid )
        break;
      if ( v16 == v17 )
        goto LABEL_10;
      i_array_p = v17 + 1;
    }
    v19 = (__int64)*v17;
  }
  else
  {
LABEL_10:
    v19 = 0i64;
  }
  result = v19;
  if ( v19 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v19 + 16i64))(v19) == 1 )
    {
      *(_QWORD *)(v19 + 32) = SSInvokedBase::mthd_op_equals;
    }
    else
    {
      v20 = *(_QWORD *)(v19 + 16);
      v21 = *(SSParameters **)(v19 + 24);
      v40 = v21;
      if ( v21 )
        ++v21->i_ref_count;
      v22 = *(SSParameters **)(v19 + 24);
      if ( v22 )
      {
        v23 = v22->i_ref_count-- == 1;
        if ( v23 )
        {
          v22->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v22);
          AMemory::c_free_func(v22);
        }
        *(_QWORD *)(v19 + 24) = 0i64;
      }
      v41 = v19;
      *(ASymbol *)(v19 + 8) = ASymbol_equals;
      *(_QWORD *)(v19 + 16) = v20;
      *(_QWORD *)v19 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v19 + 24) = v21;
      if ( v21 )
        ++v21->i_ref_count;
      *(_QWORD *)v19 = &SSMethodBase::`vftable;
      *(_QWORD *)v19 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v19 + 32) = SSInvokedBase::mthd_op_equals;
      if ( v21 )
      {
        v23 = v21->i_ref_count-- == 1;
        if ( v23 )
        {
          v21->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v21);
          AMemory::c_free_func(v21);
        }
      }
    }
  }
  v24 = SSBrain::c_invoked_base_class_p->i_methods.i_count;
  if ( (_DWORD)v24 )
  {
    v25 = SSBrain::c_invoked_base_class_p->i_methods.i_array_p;
    v26 = &v25[v24 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v27 = &v25[((char *)v26 - (char *)v25) >> 4];
        v28 = (*v27)->i_name.i_uid;
        if ( ASymbol_not_equal.i_uid >= v28 )
          break;
        if ( v25 == v27 )
          goto LABEL_34;
        v26 = v27 - 1;
      }
      if ( ASymbol_not_equal.i_uid == v28 )
        break;
      if ( v26 == v27 )
        goto LABEL_34;
      v25 = v27 + 1;
    }
    v29 = (__int64)*v27;
  }
  else
  {
LABEL_34:
    v29 = 0i64;
  }
  result = v29;
  if ( v29 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v29 + 16i64))(v29) == 1 )
    {
      *(_QWORD *)(v29 + 32) = SSInvokedBase::mthd_op_not_equal;
    }
    else
    {
      v30 = *(_QWORD *)(v29 + 16);
      v31 = *(SSParameters **)(v29 + 24);
      v40 = v31;
      if ( v31 )
        ++v31->i_ref_count;
      v32 = *(SSParameters **)(v29 + 24);
      if ( v32 )
      {
        v23 = v32->i_ref_count-- == 1;
        if ( v23 )
        {
          v32->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v32);
          AMemory::c_free_func(v32);
        }
        *(_QWORD *)(v29 + 24) = 0i64;
      }
      v41 = v29;
      *(ASymbol *)(v29 + 8) = ASymbol_not_equal;
      *(_QWORD *)(v29 + 16) = v30;
      *(_QWORD *)v29 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v29 + 24) = v31;
      if ( v31 )
        ++v31->i_ref_count;
      *(_QWORD *)v29 = &SSMethodBase::`vftable;
      *(_QWORD *)v29 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v29 + 32) = SSInvokedBase::mthd_op_not_equal;
      if ( v31 )
      {
        v23 = v31->i_ref_count-- == 1;
        if ( v23 )
        {
          v31->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v31);
          AMemory::c_free_func(v31);
        }
      }
    }
  }
  v33 = SSBrain::c_invoked_base_class_p;
  v34 = ASymbol::create((ASymbol *)&result, "pending_decrement", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v33, v34, SSInvokedBase::mthd_pending_decrement, SSBindFlag_instance_no_rebind);
  v35 = SSBrain::c_invoked_base_class_p;
  v36 = ASymbol::create((ASymbol *)&result, "pending_increment", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v35, v36, SSInvokedBase::mthd_pending_increment, SSBindFlag_instance_no_rebind);
  v37 = SSBrain::c_invoked_base_class_p;
  v38 = ASymbol::create((ASymbol *)&result, "set_data_by_name", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v37, v38, SSInvokedBase::mthd_set_data_by_name, SSBindFlag_instance_no_rebind);
}

// File Line: 435
// RVA: 0x120840
void __fastcall SSInvokedBase::mthd_abort(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdx
  __int64 v3; // r8
  SSObjectBaseVtbl *vfptr; // rcx
  SSData **i_array_p; // r9
  __int64 v7; // rdx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  v3 = 0i64;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( vfptr && i_obj_p[2].i_ptr_id == LODWORD(vfptr->get_obj_type) )
  {
    i_array_p = scope_p->i_data.i_array_p;
    v7 = 1i64;
    if ( (*i_array_p)->i_data_p->i_user_data )
      v7 = 3i64;
    LOBYTE(v3) = i_array_p[1]->i_data_p->i_user_data != 0;
    (*((void (__fastcall **)(SSObjectBaseVtbl *, __int64, __int64))vfptr->__vecDelDtor + 11))(vfptr, v7, v3);
  }
}

// File Line: 455
// RVA: 0x1208B0
void __fastcall SSInvokedBase::mthd_abort_subcalls(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdx
  SSInvokedBase *vfptr; // rcx
  eSSNotify v5; // edx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (SSInvokedBase *)i_obj_p[2].vfptr;
  if ( vfptr && i_obj_p[2].i_ptr_id == vfptr->i_ptr_id )
  {
    v5 = SSNotify_fail;
    if ( (*scope_p->i_data.i_array_p)->i_data_p->i_user_data )
      v5 = SSNotify_success;
    SSInvokedBase::abort_subcalls(vfptr, v5);
  }
}

// File Line: 474
// RVA: 0x122150
void __fastcall SSInvokedBase::mthd_detach(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rdx
  int v4; // r9d
  SSInvokedContextBase *(__fastcall *get_scope_context)(SSObjectBase *); // rcx
  bool (__fastcall *is_actor)(SSObjectBase *); // r8
  bool (__fastcall **p_is_actor)(SSObjectBase *); // rdx
  bool (__fastcall **v8)(SSObjectBase *); // rax

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( vfptr && i_obj_p[2].i_ptr_id == LODWORD(vfptr->get_obj_type) )
  {
    v4 = 1;
    if ( (*scope_p->i_data.i_array_p)->i_data_p->i_user_data )
      v4 = 3;
    get_scope_context = vfptr->get_scope_context;
    if ( !get_scope_context || LODWORD(vfptr->get_topmost_scope) != *((_DWORD *)get_scope_context + 2) )
      get_scope_context = 0i64;
    vfptr->get_scope_context = 0i64;
    LODWORD(vfptr->get_topmost_scope) = 0;
    if ( get_scope_context )
    {
      is_actor = vfptr->is_actor;
      p_is_actor = &vfptr->is_actor;
      if ( (char *)is_actor != (char *)p_is_actor )
      {
        v8 = (bool (__fastcall **)(SSObjectBase *))p_is_actor[1];
        *((_QWORD *)is_actor + 1) = v8;
        *v8 = is_actor;
        p_is_actor[1] = (bool (__fastcall *)(SSObjectBase *))p_is_actor;
        *p_is_actor = (bool (__fastcall *)(SSObjectBase *))p_is_actor;
      }
      LOBYTE(p_is_actor) = v4 == 3;
      (*(void (__fastcall **)(SSInvokedContextBase *(__fastcall *)(SSObjectBase *), bool (__fastcall **)(SSObjectBase *)))(*(_QWORD *)get_scope_context + 96i64))(
        get_scope_context,
        p_is_actor);
    }
  }
}

// File Line: 493
// RVA: 0x1221F0
void __fastcall SSInvokedBase::mthd_detach_subcalls(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdx
  SSInvokedBase *vfptr; // rcx
  eSSNotify v5; // edx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (SSInvokedBase *)i_obj_p[2].vfptr;
  if ( vfptr && i_obj_p[2].i_ptr_id == vfptr->i_ptr_id )
  {
    v5 = SSNotify_fail;
    if ( (*scope_p->i_data.i_array_p)->i_data_p->i_user_data )
      v5 = SSNotify_success;
    SSInvokedBase::detach_subcalls(vfptr, v5);
  }
}

// File Line: 512
// RVA: 0x122610
void __fastcall SSInvokedBase::mthd_get_data_by_name(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  __int64 v3; // r9
  SSObjectBaseVtbl *vfptr; // rcx
  bool v7; // al
  SSInstance *v8; // rcx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  v3 = 0i64;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( !vfptr || i_obj_p[2].i_ptr_id != LODWORD(vfptr->get_obj_type) )
    vfptr = 0i64;
  v7 = 0;
  if ( vfptr )
  {
    v3 = (*((__int64 (__fastcall **)(SSObjectBaseVtbl *, unsigned __int64 *, SSObjectBase *, _QWORD))vfptr->__vecDelDtor
          + 4))(
           vfptr,
           &(*scope_p->i_data.i_array_p)->i_data_p->i_user_data,
           i_obj_p,
           0i64);
    v7 = v3 != 0;
  }
  if ( result_pp )
  {
    v8 = SSBrain::c_nil_p;
    if ( v7 )
      v8 = (SSInstance *)v3;
    *result_pp = v8;
    ++v8->i_ref_count;
  }
  *(_QWORD *)(*(_QWORD *)(*((_QWORD *)scope_p->i_data.i_array_p + 1) + 8i64) + 32i64) = v7;
}

// File Line: 542
// RVA: 0x1228D0
void __fastcall SSInvokedBase::mthd_get_pending_count(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int is_actor; // r9d
  SSObjectBaseVtbl *vfptr; // rcx

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    is_actor = 0;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    if ( vfptr )
    {
      if ( i_obj_p[2].i_ptr_id == LODWORD(vfptr->get_obj_type) )
        is_actor = (unsigned int)vfptr[1].is_actor;
    }
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, is_actor);
  }
}

// File Line: 561
// RVA: 0x122E40
void __fastcall SSInvokedBase::mthd_is_valid(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rcx

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    if ( !vfptr || i_obj_p[2].i_ptr_id != LODWORD(vfptr->get_obj_type) )
      vfptr = 0i64;
    *result_pp = SSBoolean::pool_new(vfptr != 0i64);
  }
}

// File Line: 580
// RVA: 0x123C50
void __fastcall SSInvokedBase::mthd_op_equals(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(*(_QWORD *)&i_obj_p[2].i_ptr_id == (*scope_p->i_data.i_array_p)->i_data_p->i_user_data2);
  }
}

// File Line: 598
// RVA: 0x124680
void __fastcall SSInvokedBase::mthd_op_not_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(*(_QWORD *)&i_obj_p[2].i_ptr_id != (*scope_p->i_data.i_array_p)->i_data_p->i_user_data2);
  }
}

// File Line: 616
// RVA: 0x124A50
void __fastcall SSInvokedBase::mthd_pending_decrement(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rcx
  SSData *v5; // rdx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( vfptr )
  {
    if ( i_obj_p[2].i_ptr_id == LODWORD(vfptr->get_obj_type) )
    {
      v5 = *scope_p->i_data.i_array_p;
      LOBYTE(v5) = v5->i_data_p->i_user_data != 0;
      (*((void (__fastcall **)(SSObjectBaseVtbl *, SSData *))vfptr->__vecDelDtor + 12))(vfptr, v5);
    }
  }
}

// File Line: 634
// RVA: 0x124AA0
void __fastcall SSInvokedBase::mthd_pending_increment(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // r8
  int i_user_data; // ecx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( vfptr && i_obj_p[2].i_ptr_id == LODWORD(vfptr->get_obj_type) )
  {
    i_user_data = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    if ( i_user_data < 0 )
      i_user_data = 0;
    LODWORD(vfptr[1].is_actor) += i_user_data;
  }
}

// File Line: 652
// RVA: 0x1256B0
void __fastcall SSInvokedBase::mthd_set_data_by_name(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rcx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( vfptr )
  {
    if ( i_obj_p[2].i_ptr_id == LODWORD(vfptr->get_obj_type) )
      (*((void (__fastcall **)(SSObjectBaseVtbl *, unsigned __int64 *, _QWORD))vfptr->__vecDelDtor + 5))(
        vfptr,
        &(*scope_p->i_data.i_array_p)->i_data_p->i_user_data,
        *(_QWORD *)(*((_QWORD *)scope_p->i_data.i_array_p + 1) + 8i64));
  }
}

// File Line: 679
// RVA: 0x109620
void __fastcall SSInvokedExpression::abort_invoke(
        SSInvokedExpression *this,
        eSSNotify notify_caller,
        eSSNotifyChild notify_child)
{
  unsigned int i_ptr_id; // eax

  i_ptr_id = this->i_ptr_id;
  if ( i_ptr_id && i_ptr_id <= SSObjectBase::c_ptr_id_prev )
  {
    this->i_expr_p->vfptr->invoke_exit(this->i_expr_p, this, 0i64);
    this->i_pending_count = 0;
    if ( notify_child == SSNotifyChild_abort )
      SSInvokedBase::abort_subcalls(this, notify_caller);
    else
      SSInvokedBase::detach_subcalls(this, notify_caller);
    SSInvokedExpression::pool_delete(this);
  }
}

// File Line: 707
// RVA: 0x1304C0
void __fastcall SSInvokedExpression::pending_return(SSInvokedExpression *this, bool completed)
{
  unsigned int i_ptr_id; // eax

  i_ptr_id = this->i_ptr_id;
  if ( i_ptr_id && i_ptr_id <= SSObjectBase::c_ptr_id_prev )
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
      ((void (__fastcall *)(SSInvokedExpression *, __int64, __int64, SSInvokedExpression *))this->vfptr[1].as_instance)(
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
  unsigned int i_pool_incr_iexpr; // edi
  unsigned int i_pool_init_iexpr; // ebx
  SSInvokedExpression **v2; // rax

  if ( (_S6_3 & 1) != 0 )
    return &s_pool_2;
  _S6_3 |= 1u;
  i_pool_incr_iexpr = Skookum::get_lib_vals()->i_pool_incr_iexpr;
  i_pool_init_iexpr = Skookum::get_lib_vals()->i_pool_init_iexpr;
  s_pool_2.i_pool.i_count = 0;
  unk_142175C28 = 0i64;
  unk_142175C30 = 0;
  if ( i_pool_init_iexpr )
  {
    unk_142175C30 = i_pool_init_iexpr;
    v2 = APArrayBase<SSInvokedExpression>::alloc_array(i_pool_init_iexpr);
  }
  else
  {
    unk_142175C30 = 0;
    v2 = (SSInvokedExpression **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  unk_142175C28 = v2;
  qword_142175C38 = 0i64;
  unk_142175C40 = 0;
  qword_142175C48 = 0i64;
  unk_142175C50 = 0;
  stru_142175C58.i_count = 0;
  stru_142175C58.i_array_p = 0i64;
  stru_142175C58.i_size = 0;
  unk_142175C70 = i_pool_incr_iexpr;
  AObjReusePool<SSInvokedExpression>::append_block(&s_pool_2, i_pool_init_iexpr);
  atexit(SSInvokedExpression::get_pool_::_2_::_dynamic_atexit_destructor_for__s_pool__);
  return &s_pool_2;
}

// File Line: 790
// RVA: 0x130900
void __fastcall SSInvokedExpression::pool_delete(SSInvokedExpression *iexpr_p)
{
  unsigned int i_ptr_id; // eax
  AListNode<SSInvokedBase,SSInvokedBase> *i_next_p; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax
  AObjReusePool<SSInvokedExpression> *pool; // rax
  AObjBlock<SSInvokedExpression> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v8; // cf
  APArray<SSInvokedExpression,SSInvokedExpression,ACompareAddress<SSInvokedExpression> > *p_i_exp_pool; // rcx

  i_ptr_id = iexpr_p->i_ptr_id;
  if ( i_ptr_id && i_ptr_id <= SSObjectBase::c_ptr_id_prev )
  {
    i_next_p = iexpr_p->i_next_p;
    i_prev_p = iexpr_p->i_prev_p;
    i_next_p->i_prev_p = i_prev_p;
    i_prev_p->i_next_p = i_next_p;
    iexpr_p->i_prev_p = &iexpr_p->AListNode<SSInvokedBase,SSInvokedBase>;
    iexpr_p->i_next_p = &iexpr_p->AListNode<SSInvokedBase,SSInvokedBase>;
    iexpr_p->i_ptr_id = 0;
    pool = SSInvokedExpression::get_pool();
    i_block_p = pool->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)iexpr_p < i_objects_a
      || (v8 = (unsigned __int64)iexpr_p < i_objects_a + 112i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v8) )
    {
      p_i_exp_pool = &pool->i_exp_pool;
    }
    APArray<SSInvokedExpression,SSInvokedExpression,ACompareAddress<SSInvokedExpression>>::append(p_i_exp_pool, iexpr_p);
  }
}

// File Line: 857
// RVA: 0x112F70
void __fastcall SSInvokedContextBase::data_append_args(
        SSInvokedContextBase *this,
        SSInstance **arguments_pp,
        unsigned int arg_count,
        SSInvokableBase *invokable_params)
{
  __int64 v4; // rdi
  SSParameters *i_obj_p; // rbp
  __int64 i_count; // rbx
  unsigned int v9; // r12d
  SSData **i_array_p; // r14
  int v11; // r13d
  SSInstance **v12; // rcx
  SSParameterBase **v13; // rbp
  SSParameterBase *v14; // r12
  SSInstance *v15; // rdi
  eSSParameter v16; // eax
  int v17; // eax
  _QWORD *v18; // rbx
  SSInvokedBase *v19; // rbx
  __int64 v20; // rax
  AObjReusePool<SSData> *pool; // rbx
  unsigned int v22; // eax
  unsigned int v23; // eax
  __int64 v24; // rcx
  SSData **v25; // rax
  SSData *v26; // rdx
  unsigned int v27; // eax
  char *v28; // rdi
  char *v29; // rbp
  signed __int64 v30; // r14
  unsigned int *v31; // rsi
  AObjReusePool<SSData> *v32; // rbx
  unsigned int v33; // eax
  unsigned int v34; // eax
  __int64 v35; // rcx
  SSData **v36; // rax
  SSData *v37; // rdx
  unsigned int v38; // eax
  SSInstance *v39; // [rsp+20h] [rbp-68h] BYREF
  unsigned __int64 v40; // [rsp+28h] [rbp-60h]
  SSInstance **v41; // [rsp+30h] [rbp-58h]
  __int64 v42; // [rsp+38h] [rbp-50h]
  _QWORD *v43; // [rsp+40h] [rbp-48h]
  unsigned int v44; // [rsp+90h] [rbp+8h]
  SSParameters *v45; // [rsp+A8h] [rbp+20h]

  v42 = -2i64;
  v4 = arg_count;
  i_obj_p = invokable_params->i_params_p.i_obj_p;
  v45 = i_obj_p;
  i_count = i_obj_p->i_params.i_count;
  v9 = i_obj_p->i_return_params.i_count;
  v44 = v9;
  if ( this->i_data.i_size < v9 + (unsigned int)i_count )
  {
    this->i_data.i_size = AMemory::c_req_byte_size_func(8 * (v9 + i_count)) >> 3;
    AMemory::c_free_func(this->i_data.i_array_p);
    this->i_data.i_array_p = APArrayBase<SSData>::alloc_array(this->i_data.i_size);
  }
  this->i_data.i_count = 0;
  i_array_p = this->i_data.i_array_p;
  v11 = 0;
  if ( !(_DWORD)i_count )
    goto LABEL_30;
  v12 = &arguments_pp[v4];
  v41 = v12;
  v13 = i_obj_p->i_params.i_array_p;
  v40 = (unsigned __int64)&v13[i_count];
  if ( (unsigned __int64)v13 >= v40 )
    goto LABEL_29;
  do
  {
    v14 = *v13;
    v15 = 0i64;
    if ( arguments_pp >= v12 || (v15 = *arguments_pp, ++arguments_pp, !v15) )
    {
      v16 = v14->vfptr->get_kind(*v13);
      if ( v16 )
      {
        v17 = v16 - 1;
        if ( v17 )
        {
          if ( v17 == 2 )
          {
            v18 = AMemory::c_malloc_func(0x18ui64, "SSList");
            v43 = v18;
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
          v19 = this->i_caller_p.i_obj_p;
          if ( !v19 || this->i_caller_p.i_ptr_id != v19->i_ptr_id )
            v19 = 0i64;
          v20 = (__int64)v14->vfptr->get_default_expr(v14);
          (*(void (__fastcall **)(__int64, SSInvokedContextBase *, SSInvokedBase *, SSInstance **))(*(_QWORD *)v20
                                                                                                  + 32i64))(
            v20,
            this,
            v19,
            &v39);
          v15 = v39;
        }
      }
      else
      {
        v15 = SSBrain::c_nil_p;
      }
    }
    pool = SSData::get_pool();
    if ( pool->i_pool.i_count )
    {
      v27 = pool->i_pool.i_count - 1;
      pool->i_pool.i_count = v27;
      v24 = v27;
      v25 = pool->i_pool.i_array_p;
    }
    else
    {
      if ( !pool->i_exp_pool.i_count )
        AObjReusePool<SSData>::append_block(pool, pool->i_expand_size);
      v22 = pool->i_exp_pool.i_count;
      if ( !v22 )
      {
        v26 = 0i64;
        goto LABEL_27;
      }
      v23 = v22 - 1;
      pool->i_exp_pool.i_count = v23;
      v24 = v23;
      v25 = pool->i_exp_pool.i_array_p;
    }
    v26 = v25[v24];
LABEL_27:
    v26->i_name.i_uid = v14->i_name.i_uid;
    v26->i_data_p = v15;
    *i_array_p = v26;
    this->i_data.i_count = ++v11;
    ++i_array_p;
    ++v13;
    v12 = v41;
  }
  while ( (unsigned __int64)v13 < v40 );
  v9 = v44;
LABEL_29:
  i_obj_p = v45;
LABEL_30:
  if ( v9 )
  {
    v28 = (char *)i_obj_p->i_return_params.i_array_p;
    v29 = &v28[8 * v9];
    this->i_data.i_count = v9 + v11;
    if ( v28 < v29 )
    {
      v30 = (char *)i_array_p - v28;
      while ( 1 )
      {
        v31 = *(unsigned int **)v28;
        v32 = SSData::get_pool();
        if ( v32->i_pool.i_count )
          break;
        if ( !v32->i_exp_pool.i_count )
          AObjReusePool<SSData>::append_block(v32, v32->i_expand_size);
        v33 = v32->i_exp_pool.i_count;
        if ( v33 )
        {
          v34 = v33 - 1;
          v32->i_exp_pool.i_count = v34;
          v35 = v34;
          v36 = v32->i_exp_pool.i_array_p;
LABEL_40:
          v37 = v36[v35];
          goto LABEL_41;
        }
        v37 = 0i64;
LABEL_41:
        v37->i_name.i_uid = *v31;
        v37->i_data_p = SSBrain::c_nil_p;
        *(_QWORD *)&v28[v30] = v37;
        v28 += 8;
        if ( v28 >= v29 )
          return;
      }
      v38 = v32->i_pool.i_count - 1;
      v32->i_pool.i_count = v38;
      v35 = v38;
      v36 = v32->i_pool.i_array_p;
      goto LABEL_40;
    }
  }
}

// File Line: 990
// RVA: 0x113210
void __fastcall SSInvokedContextBase::data_append_args_exprs(
        SSInvokedContextBase *this,
        APArrayBase<SSExpressionBase> *args,
        SSInvokableBase *invokable_params,
        SSObjectBase *arg_scope_p)
{
  SSParameters *i_obj_p; // rbp
  __int64 i_count; // rbx
  unsigned int v8; // r15d
  SSData **i_array_p; // r14
  unsigned int v10; // ecx
  SSInstance *v11; // rdi
  SSInvokedBase *v12; // r12
  SSExpressionBase **v13; // r15
  unsigned __int64 v14; // rdx
  SSParameterBase **v15; // rbp
  __int64 v16; // rbx
  SSParameterBase *v17; // rsi
  eSSParameter v18; // eax
  __int32 v19; // eax
  _QWORD *v20; // rbx
  __int64 v21; // rax
  AObjReusePool<SSData> *pool; // rbx
  unsigned int v23; // eax
  unsigned int v24; // eax
  __int64 v25; // rcx
  SSData **v26; // rax
  SSData *v27; // rdx
  unsigned int v28; // eax
  char *v29; // rdi
  char *v30; // rbp
  signed __int64 v31; // r14
  unsigned int *v32; // rsi
  AObjReusePool<SSData> *v33; // rbx
  unsigned int v34; // eax
  unsigned int v35; // eax
  __int64 v36; // rcx
  SSData **v37; // rax
  SSData *v38; // rdx
  unsigned int v39; // eax
  SSParameters *v40; // [rsp+20h] [rbp-88h]
  SSInstance *v41; // [rsp+28h] [rbp-80h] BYREF
  unsigned __int64 v42; // [rsp+30h] [rbp-78h]
  SSInstance *v43; // [rsp+38h] [rbp-70h] BYREF
  unsigned __int64 v44; // [rsp+40h] [rbp-68h]
  SSInstance *v45; // [rsp+48h] [rbp-60h] BYREF
  __int64 v46[11]; // [rsp+50h] [rbp-58h] BYREF
  unsigned int v47; // [rsp+B0h] [rbp+8h]
  unsigned int v48; // [rsp+C0h] [rbp+18h]

  v46[1] = -2i64;
  i_obj_p = invokable_params->i_params_p.i_obj_p;
  v40 = i_obj_p;
  i_count = i_obj_p->i_params.i_count;
  v8 = i_obj_p->i_return_params.i_count;
  v48 = v8;
  if ( this->i_data.i_size < v8 + (unsigned int)i_count )
  {
    this->i_data.i_size = AMemory::c_req_byte_size_func(8 * (v8 + i_count)) >> 3;
    AMemory::c_free_func(this->i_data.i_array_p);
    this->i_data.i_array_p = APArrayBase<SSData>::alloc_array(this->i_data.i_size);
  }
  this->i_data.i_count = 0;
  i_array_p = this->i_data.i_array_p;
  v10 = 0;
  v47 = 0;
  if ( (_DWORD)i_count )
  {
    v11 = 0i64;
    v12 = this->i_caller_p.i_obj_p;
    if ( !v12 || this->i_caller_p.i_ptr_id != v12->i_ptr_id )
      v12 = 0i64;
    v13 = args->i_array_p;
    v14 = (unsigned __int64)&v13[args->i_count];
    v44 = v14;
    v15 = i_obj_p->i_params.i_array_p;
    v42 = (unsigned __int64)&v15[i_count];
    if ( (unsigned __int64)v15 < v42 )
    {
      while ( 1 )
      {
        v16 = 0i64;
        if ( (unsigned __int64)v13 < v14 )
          v16 = (__int64)*v13++;
        v17 = *v15;
        v18 = (*v15)->vfptr->get_kind(*v15);
        if ( v18 )
        {
          v19 = v18 - 1;
          if ( v19 )
          {
            if ( v19 == 2 )
            {
              if ( v16 )
              {
                (*(void (__fastcall **)(__int64, SSObjectBase *, SSInvokedBase *, SSInstance **))(*(_QWORD *)v16 + 32i64))(
                  v16,
                  arg_scope_p,
                  v12,
                  &v45);
                v11 = v45;
              }
              else
              {
                v20 = AMemory::c_malloc_func(0x18ui64, "SSList");
                v46[2] = (__int64)v20;
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
            (*(void (__fastcall **)(__int64, SSObjectBase *, SSInvokedBase *, SSInstance **))(*(_QWORD *)v16 + 32i64))(
              v16,
              arg_scope_p,
              v12,
              &v43);
            v11 = v43;
          }
          else
          {
            v21 = (__int64)v17->vfptr->get_default_expr(v17);
            (*(void (__fastcall **)(__int64, SSInvokedContextBase *, SSInvokedBase *, __int64 *))(*(_QWORD *)v21 + 32i64))(
              v21,
              this,
              v12,
              v46);
            v11 = (SSInstance *)v46[0];
          }
        }
        else
        {
          (*(void (__fastcall **)(__int64, SSObjectBase *, SSInvokedBase *, SSInstance **))(*(_QWORD *)v16 + 32i64))(
            v16,
            arg_scope_p,
            v12,
            &v41);
          v11 = v41;
        }
        pool = SSData::get_pool();
        if ( pool->i_pool.i_count )
          break;
        if ( !pool->i_exp_pool.i_count )
          AObjReusePool<SSData>::append_block(pool, pool->i_expand_size);
        v23 = pool->i_exp_pool.i_count;
        if ( v23 )
        {
          v24 = v23 - 1;
          pool->i_exp_pool.i_count = v24;
          v25 = v24;
          v26 = pool->i_exp_pool.i_array_p;
LABEL_30:
          v27 = v26[v25];
          goto LABEL_31;
        }
        v27 = 0i64;
LABEL_31:
        v27->i_name.i_uid = v17->i_name.i_uid;
        v27->i_data_p = v11;
        *i_array_p = v27;
        v10 = v47 + 1;
        v47 = v10;
        this->i_data.i_count = v10;
        ++i_array_p;
        ++v15;
        v14 = v44;
        if ( (unsigned __int64)v15 >= v42 )
          goto LABEL_32;
      }
      v28 = pool->i_pool.i_count - 1;
      pool->i_pool.i_count = v28;
      v25 = v28;
      v26 = pool->i_pool.i_array_p;
      goto LABEL_30;
    }
LABEL_32:
    i_obj_p = v40;
    v8 = v48;
  }
  if ( v8 )
  {
    v29 = (char *)i_obj_p->i_return_params.i_array_p;
    v30 = &v29[8 * v8];
    this->i_data.i_count = v10 + v8;
    if ( v29 < v30 )
    {
      v31 = (char *)i_array_p - v29;
      while ( 1 )
      {
        v32 = *(unsigned int **)v29;
        v33 = SSData::get_pool();
        if ( v33->i_pool.i_count )
          break;
        if ( !v33->i_exp_pool.i_count )
          AObjReusePool<SSData>::append_block(v33, v33->i_expand_size);
        v34 = v33->i_exp_pool.i_count;
        if ( v34 )
        {
          v35 = v34 - 1;
          v33->i_exp_pool.i_count = v35;
          v36 = v35;
          v37 = v33->i_exp_pool.i_array_p;
LABEL_43:
          v38 = v37[v36];
          goto LABEL_44;
        }
        v38 = 0i64;
LABEL_44:
        v38->i_name.i_uid = *v32;
        v38->i_data_p = SSBrain::c_nil_p;
        *(_QWORD *)&v29[v31] = v38;
        v29 += 8;
        if ( v29 >= v30 )
          return;
      }
      v39 = v33->i_pool.i_count - 1;
      v33->i_pool.i_count = v39;
      v36 = v39;
      v37 = v33->i_pool.i_array_p;
      goto LABEL_43;
    }
  }
}

// File Line: 1105
// RVA: 0x113540
void __fastcall SSInvokedContextBase::data_append_vars(
        SSInvokedContextBase *this,
        AVCompactArrayBase<ASymbol> *var_names)
{
  __int64 i_count; // r8
  ASymbol *i_array_p; // rsi
  APArrayLogical<SSData,ASymbol> *p_i_data; // rdi
  ASymbol *v5; // r15
  AObjReusePool<SSData> *pool; // rbx
  unsigned int v7; // eax
  unsigned int v8; // eax
  __int64 v9; // rcx
  SSData **v10; // rax
  SSData *v11; // rbx
  unsigned int v12; // eax
  __int64 v13; // rbp
  SSData **v14; // r14
  unsigned __int64 v15; // rax
  SSData **v16; // rax

  i_count = var_names->i_count;
  i_array_p = var_names->i_array_p;
  p_i_data = &this->i_data;
  v5 = &i_array_p[i_count];
  APSizedArrayBase<SSData>::ensure_size(&this->i_data, i_count + this->i_data.i_count);
  if ( i_array_p < v5 )
  {
    while ( 1 )
    {
      pool = SSData::get_pool();
      if ( pool->i_pool.i_count )
        break;
      if ( !pool->i_exp_pool.i_count )
        AObjReusePool<SSData>::append_block(pool, pool->i_expand_size);
      v7 = pool->i_exp_pool.i_count;
      if ( v7 )
      {
        v8 = v7 - 1;
        pool->i_exp_pool.i_count = v8;
        v9 = v8;
        v10 = pool->i_exp_pool.i_array_p;
LABEL_9:
        v11 = v10[v9];
        goto LABEL_10;
      }
      v11 = 0i64;
LABEL_10:
      v11->i_name = (ASymbol)i_array_p->i_uid;
      v11->i_data_p = SSBrain::c_nil_p;
      v13 = p_i_data->i_count;
      if ( p_i_data->i_size < (unsigned int)(v13 + 1) )
      {
        v14 = p_i_data->i_array_p;
        if ( (_DWORD)v13 == -1 )
          LODWORD(v15) = 0;
        else
          v15 = (unsigned __int64)AMemory::c_req_byte_size_func(32 * (((unsigned int)v13 >> 2) + 1)) >> 3;
        p_i_data->i_size = v15;
        v16 = APArrayBase<SSData>::alloc_array(v15);
        p_i_data->i_array_p = v16;
        memmove(v16, v14, 8 * v13);
        AMemory::c_free_func(v14);
      }
      ++i_array_p;
      p_i_data->i_array_p[v13] = v11;
      ++p_i_data->i_count;
      if ( i_array_p >= v5 )
        return;
    }
    v12 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v12;
    v9 = v12;
    v10 = pool->i_pool.i_array_p;
    goto LABEL_9;
  }
}

// File Line: 1133
// RVA: 0x113660
void __fastcall SSInvokedContextBase::data_bind_return_args(
        SSInvokedContextBase *this,
        APArrayBase<SSIdentifier> *return_args,
        SSInvokableBase *invokable_params)
{
  __int64 i_count; // rcx
  SSObjectBase *i_obj_p; // rax
  SSIdentifier **i_array_p; // rbx
  SSInvokedBase *v7; // rsi
  SSIdentifier **v8; // rbp
  SSData **i; // rdi
  int v10; // [rsp+20h] [rbp-18h]

  i_count = return_args->i_count;
  if ( (_DWORD)i_count )
  {
    i_obj_p = this->i_scope_p.i_obj_p;
    if ( i_obj_p )
    {
      if ( this->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      {
        i_array_p = return_args->i_array_p;
        v7 = this->i_caller_p.i_obj_p;
        v8 = &i_array_p[i_count];
        if ( !v7 || this->i_caller_p.i_ptr_id != v7->i_ptr_id )
          v7 = 0i64;
        for ( i = &this->i_data.i_array_p[invokable_params->i_params_p.i_obj_p->i_params.i_count]; i_array_p < v8; ++i )
        {
          if ( *i_array_p )
          {
            LOBYTE(v10) = 0;
            (*((void (__fastcall **)(SSIdentifier *, SSInstance *, SSInvokedBase *, SSInvokedBase *, int))&(*i_array_p)->vfptr[1].__vecDelDtor
             + 1))(
              *i_array_p,
              (*i)->i_data_p,
              v7,
              v7,
              v10);
          }
          ++i_array_p;
        }
      }
    }
  }
}

// File Line: 1181
// RVA: 0x113720
void __fastcall SSInvokedContextBase::data_remove_vars(
        SSInvokedContextBase *this,
        AVCompactArrayBase<ASymbol> *var_names,
        SSInstance *delay_collect_p)
{
  ASymbol *i_array_p; // rdi
  ASymbol *i; // r14
  unsigned int i_count; // eax
  SSData **v8; // r10
  __int64 v9; // r11
  SSData **v10; // r8
  char *v11; // rax
  __int64 v12; // rax
  SSData *v13; // rbx
  SSInstance *i_data_p; // rcx
  AObjReusePool<SSData> *pool; // rax
  AObjBlock<SSData> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v19; // cf
  APArray<SSData,ASymbol,ACompareLogical<ASymbol> > *p_i_exp_pool; // rcx

  if ( delay_collect_p )
    ++delay_collect_p->i_ref_count;
  i_array_p = var_names->i_array_p;
  for ( i = &i_array_p[var_names->i_count]; i_array_p < i; ++i_array_p )
  {
    i_count = this->i_data.i_count;
    if ( i_count )
    {
      v8 = this->i_data.i_array_p;
      v9 = i_count - 1;
      v10 = &v8[v9];
      v11 = (char *)v8;
      if ( v8 <= v10 )
      {
        while ( i_array_p->i_uid != **(_DWORD **)v11 )
        {
          v11 += 8;
          if ( v11 > (char *)v10 )
            goto LABEL_16;
        }
        v12 = (v11 - (char *)v8) >> 3;
        v13 = v8[(unsigned int)v12];
        this->i_data.i_count = v9;
        memmove(&v8[(unsigned int)v12], &v8[(unsigned int)(v12 + 1)], 8i64 * (unsigned int)(v9 - v12));
        if ( v13 )
        {
          i_data_p = v13->i_data_p;
          if ( i_data_p->i_ref_count-- == 1 )
          {
            i_data_p->i_ref_count = 0x80000000;
            i_data_p->vfptr[1].get_scope_context(i_data_p);
          }
          pool = SSData::get_pool();
          i_block_p = pool->i_block_p;
          i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
          if ( (unsigned __int64)v13 < i_objects_a
            || (v19 = (unsigned __int64)v13 < i_objects_a + 16i64 * i_block_p->i_size,
                p_i_exp_pool = (APArray<SSData,ASymbol,ACompareLogical<ASymbol> > *)pool,
                !v19) )
          {
            p_i_exp_pool = (APArray<SSData,ASymbol,ACompareLogical<ASymbol> > *)&pool->i_exp_pool;
          }
          APArray<SSData,ASymbol,ACompareLogical<ASymbol>>::append(p_i_exp_pool, v13);
        }
      }
    }
LABEL_16:
    ;
  }
  if ( delay_collect_p )
    --delay_collect_p->i_ref_count;
}

// File Line: 1277
// RVA: 0x117850
SSInstance *__fastcall SSInvokedContextBase::get_data_by_name(SSInvokedContextBase *this, ASymbol *name)
{
  __int64 i_count; // rax
  SSData **i_array_p; // r8
  SSData **v5; // r9
  SSData *v6; // rax
  SSObjectBase *i_obj_p; // rcx

  i_count = this->i_data.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = this->i_data.i_array_p;
    v5 = &i_array_p[i_count];
    if ( i_array_p < v5 )
    {
      while ( 1 )
      {
        v6 = *i_array_p;
        if ( name->i_uid == (*i_array_p)->i_name.i_uid )
          break;
        if ( ++i_array_p >= v5 )
          goto LABEL_5;
      }
      if ( v6 )
        return v6->i_data_p;
    }
  }
LABEL_5:
  i_obj_p = this->i_scope_p.i_obj_p;
  if ( !i_obj_p || this->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  return i_obj_p->vfptr->get_data_by_name(i_obj_p, name);
}

// File Line: 1321
// RVA: 0x13C540
void __fastcall SSInvokedContextBase::set_data_by_name(SSInvokedContextBase *this, ASymbol *name, SSInstance *obj_p)
{
  __int64 i_count; // rax
  SSData **i_array_p; // r9
  SSData **v7; // r10
  SSData *v8; // rax
  SSObjectBase *i_obj_p; // rcx
  SSData *v10; // rbx
  SSInstance *i_data_p; // rcx

  i_count = this->i_data.i_count;
  if ( !(_DWORD)i_count )
    goto LABEL_5;
  i_array_p = this->i_data.i_array_p;
  v7 = &i_array_p[i_count];
  if ( i_array_p >= v7 )
    goto LABEL_5;
  while ( 1 )
  {
    v8 = *i_array_p;
    if ( name->i_uid == (*i_array_p)->i_name.i_uid )
      break;
    if ( ++i_array_p >= v7 )
      goto LABEL_5;
  }
  v10 = *i_array_p;
  if ( v8 )
  {
    ++obj_p->i_ref_count;
    i_data_p = v8->i_data_p;
    if ( i_data_p->i_ref_count-- == 1 )
    {
      i_data_p->i_ref_count = 0x80000000;
      i_data_p->vfptr[1].get_scope_context(i_data_p);
    }
    v10->i_data_p = obj_p;
  }
  else
  {
LABEL_5:
    i_obj_p = this->i_scope_p.i_obj_p;
    if ( !i_obj_p || this->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_obj_p->vfptr->set_data_by_name(i_obj_p, name, obj_p);
  }
}


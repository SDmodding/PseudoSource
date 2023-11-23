// File Line: 63
// RVA: 0x130B30
SSClosure *__fastcall SSClosure::pool_new(SSClosureInfoBase *closure_info_p, SSInstance *receiver_p)
{
  __int64 i_count; // rax
  SSInstance *v5; // r8
  AObjReusePool<SSInstance> *pool; // rbx
  unsigned int v7; // eax
  unsigned int v8; // eax
  __int64 v9; // rcx
  SSInstance **i_array_p; // rax
  unsigned int v11; // eax
  SSClass *v12; // rax

  i_count = closure_info_p->i_captured.i_count;
  if ( (_DWORD)i_count )
  {
    v5 = (SSInstance *)AMemory::c_malloc_func(8 * i_count + 48, "SSClosure");
    goto LABEL_11;
  }
  pool = SSInstance::get_pool();
  if ( pool->i_pool.i_count )
  {
    v11 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v11;
    v9 = v11;
    i_array_p = pool->i_pool.i_array_p;
    goto LABEL_9;
  }
  if ( !pool->i_exp_pool.i_count )
    AObjReusePool<SSInstance>::append_block(pool, pool->i_expand_size);
  v7 = pool->i_exp_pool.i_count;
  if ( v7 )
  {
    v8 = v7 - 1;
    pool->i_exp_pool.i_count = v8;
    v9 = v8;
    i_array_p = pool->i_exp_pool.i_array_p;
LABEL_9:
    v5 = i_array_p[v9];
    goto LABEL_11;
  }
  v5 = 0i64;
LABEL_11:
  if ( v5 )
  {
    v12 = SSBrain::c_closure_class_p;
    v5->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
    v5->i_ref_count = 0;
    v5->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable;
    v5->i_class_p = v12;
    v5->i_user_data = (unsigned __int64)closure_info_p;
    v5->i_user_data2 = (unsigned __int64)receiver_p;
    v5->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
    v5->vfptr = (SSObjectBaseVtbl *)&SSClosure::`vftable;
    ++closure_info_p->i_ref_count;
    ++receiver_p->i_ref_count;
  }
  v5->i_ref_count = 1;
  return (SSClosure *)v5;
}

// File Line: 91
// RVA: 0x130670
void __fastcall SSClosure::pool_delete(SSClosure *this)
{
  __int64 v2; // rsi
  _DWORD *i_user_data2; // rcx
  bool v4; // zf
  _DWORD *v5; // rax
  SSClosure *v6; // rbx
  SSClosure *v7; // rsi
  SSObjectBaseVtbl *vfptr; // rcx
  AObjReusePool<SSInstance> *pool; // rax
  AObjBlock<SSInstance> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // r8
  unsigned __int64 v12; // rdx
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *p_i_exp_pool; // rcx

  v2 = *(unsigned int *)(this->i_user_data + 16);
  i_user_data2 = (_DWORD *)this->i_user_data2;
  v4 = i_user_data2[4]-- == 1;
  if ( v4 )
  {
    i_user_data2[4] = 0x80000000;
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)i_user_data2 + 112i64))(i_user_data2);
  }
  v5 = (_DWORD *)(this->i_user_data + 8);
  v4 = (*v5)-- == 1;
  if ( v4 )
  {
    *v5 = 0x80000000;
    if ( v5 )
    {
      if ( v5 != (_DWORD *)8 )
        (**((void (__fastcall ***)(__int64, __int64))v5 - 1))((__int64)(v5 - 2), 1i64);
    }
  }
  this->i_ptr_id = 0;
  if ( (_DWORD)v2 )
  {
    v6 = this + 1;
    v7 = (SSClosure *)((char *)this + 8 * v2 + 48);
    if ( &this[1] < v7 )
    {
      do
      {
        vfptr = v6->vfptr;
        v4 = LODWORD(v6->vfptr->is_actor)-- == 1;
        if ( v4 )
        {
          LODWORD(vfptr->is_actor) = 0x80000000;
          (*((void (__fastcall **)(SSObjectBaseVtbl *))vfptr->__vecDelDtor + 14))(vfptr);
        }
        v6 = (SSClosure *)((char *)v6 + 8);
      }
      while ( v6 < v7 );
    }
    AMemory::c_free_func(this);
  }
  else
  {
    pool = SSInstance::get_pool();
    i_block_p = pool->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)this < i_objects_a
      || (v12 = i_objects_a + 48i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, (unsigned __int64)this >= v12) )
    {
      p_i_exp_pool = &pool->i_exp_pool;
    }
    APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(p_i_exp_pool, this);
    this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
    this->i_ref_count = 0;
    this->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable;
  }
}

// File Line: 226
// RVA: 0x1176F0
SSInstance *__fastcall SSClosure::get_data_by_name(SSClosure *this, ASymbol *name)
{
  unsigned __int64 i_user_data; // r8
  int v3; // eax
  unsigned int *v4; // rbx
  unsigned int i_uid; // r10d
  unsigned int *v6; // r9
  unsigned int *i; // r8
  unsigned int *v8; // rax

  i_user_data = this->i_user_data;
  v3 = *(_DWORD *)(i_user_data + 16);
  if ( !v3 )
    return (SSInstance *)(*(__int64 (__fastcall **)(unsigned __int64, ASymbol *))(*(_QWORD *)this->i_user_data2 + 32i64))(
                           this->i_user_data2,
                           name);
  v4 = *(unsigned int **)(i_user_data + 24);
  i_uid = name->i_uid;
  v6 = &v4[v3 - 1];
  for ( i = v4; ; i = v8 + 1 )
  {
    while ( 1 )
    {
      v8 = &i[((char *)v6 - (char *)i) >> 3];
      if ( i_uid >= *v8 )
        break;
      if ( i == v8 )
        return (SSInstance *)(*(__int64 (__fastcall **)(unsigned __int64, ASymbol *))(*(_QWORD *)this->i_user_data2
                                                                                    + 32i64))(
                               this->i_user_data2,
                               name);
      v6 = v8 - 1;
    }
    if ( i_uid == *v8 )
      break;
    if ( v6 == v8 )
      return (SSInstance *)(*(__int64 (__fastcall **)(unsigned __int64, ASymbol *))(*(_QWORD *)this->i_user_data2 + 32i64))(
                             this->i_user_data2,
                             name);
  }
  return (SSInstance *)*((_QWORD *)&this[1].vfptr + (unsigned int)(v8 - v4));
}

// File Line: 252
// RVA: 0x13C380
void __fastcall SSClosure::set_data_by_name(SSClosure *this, ASymbol *name, SSObjectBaseVtbl *obj_p)
{
  unsigned __int64 i_user_data; // r9
  int v5; // eax
  unsigned int *v7; // rsi
  unsigned int i_uid; // r10d
  unsigned int *v9; // r8
  unsigned int *i; // r9
  unsigned int *v11; // rcx
  __int64 v12; // rax
  _DWORD *v13; // rcx
  bool v14; // zf
  SSObjectBaseVtbl **v15; // rbx

  i_user_data = this->i_user_data;
  v5 = *(_DWORD *)(i_user_data + 16);
  if ( v5 )
  {
    v7 = *(unsigned int **)(i_user_data + 24);
    i_uid = name->i_uid;
    v9 = &v7[v5 - 1];
    for ( i = v7; ; i = v11 + 1 )
    {
      while ( 1 )
      {
        v11 = &i[((char *)v9 - (char *)i) >> 3];
        if ( i_uid >= *v11 )
          break;
        if ( i == v11 )
          goto LABEL_12;
        v9 = v11 - 1;
      }
      if ( i_uid == *v11 )
        break;
      if ( v9 == v11 )
        goto LABEL_12;
    }
    ++LODWORD(obj_p->is_actor);
    v12 = (unsigned int)(v11 - v7);
    v13 = (_DWORD *)*((_QWORD *)&this[1].vfptr + v12);
    v14 = v13[4]-- == 1;
    v15 = &this->vfptr + v12;
    if ( v14 )
    {
      v13[4] = 0x80000000;
      (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v13 + 112i64))(v13);
    }
    v15[6] = obj_p;
  }
  else
  {
LABEL_12:
    (*(void (__fastcall **)(unsigned __int64, ASymbol *, SSObjectBaseVtbl *))(*(_QWORD *)this->i_user_data2 + 40i64))(
      this->i_user_data2,
      name,
      obj_p);
  }
}

// File Line: 291
// RVA: 0x1201F0
void __fastcall SSClosure::mthd_String(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  unsigned int v3; // eax
  AStringRef *v4; // rbx
  SSInstance *v5; // rax
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // r8
  bool v10; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx

  if ( result_pp )
  {
    v3 = AMemory::c_req_byte_size_func(0xFu);
    v4 = AStringRef::pool_new("Closure object", 0xEu, v3, 1u, 0, 1);
    v5 = SSInstance::pool_new(SSBrain::c_string_class_p);
    if ( v5 != (SSInstance *)-32i64 )
    {
      v5->i_user_data = (unsigned __int64)v4;
      ++v4->i_ref_count;
    }
    *result_pp = v5;
    if ( v4->i_ref_count-- == 1 )
    {
      if ( v4->i_deallocate )
        AMemory::c_free_func(v4->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)v4 < i_objects_a
        || (v10 = (unsigned __int64)v4 < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v10) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, v4);
    }
  }
}

// File Line: 315
// RVA: 0x13B030
void SSClosure::register_bindings(void)
{
  __int64 i_count; // rax
  SSMethodBase **i_array_p; // r8
  SSMethodBase **v2; // r10
  SSMethodBase **v3; // rdx
  unsigned int i_uid; // r9d
  SSMethodBase *v5; // rbx
  SSClass *i_scope_p; // rbp
  SSParameters *i_obj_p; // rdi
  SSParameters *v8; // rsi
  bool v9; // zf

  i_count = SSBrain::c_closure_class_p->i_methods.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = SSBrain::c_closure_class_p->i_methods.i_array_p;
    v2 = &i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v3 = &i_array_p[((char *)v2 - (char *)i_array_p) >> 4];
        i_uid = (*v3)->i_name.i_uid;
        if ( ASymbol_String.i_uid >= i_uid )
          break;
        if ( i_array_p == v3 )
          goto LABEL_10;
        v2 = v3 - 1;
      }
      if ( ASymbol_String.i_uid == i_uid )
        break;
      if ( v2 == v3 )
        goto LABEL_10;
      i_array_p = v3 + 1;
    }
    v5 = *v3;
  }
  else
  {
LABEL_10:
    v5 = 0i64;
  }
  if ( v5 )
  {
    if ( v5->vfptr->get_invoke_type(v5) == SSInvokable_method_func )
    {
      v5[1].vfptr = (SSInvokableBaseVtbl *)SSClosure::mthd_String;
    }
    else
    {
      i_scope_p = v5->i_scope_p;
      i_obj_p = v5->i_params_p.i_obj_p;
      if ( i_obj_p )
        ++i_obj_p->i_ref_count;
      v8 = v5->i_params_p.i_obj_p;
      if ( v8 )
      {
        v9 = v8->i_ref_count-- == 1;
        if ( v9 )
        {
          v8->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v8);
          AMemory::c_free_func(v8);
        }
        v5->i_params_p.i_obj_p = 0i64;
      }
      v5->i_name = ASymbol_String;
      v5->i_scope_p = i_scope_p;
      v5->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v5->i_params_p.i_obj_p = i_obj_p;
      if ( i_obj_p )
        ++i_obj_p->i_ref_count;
      v5->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v5->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v5[1].vfptr = (SSInvokableBaseVtbl *)SSClosure::mthd_String;
      if ( i_obj_p )
      {
        v9 = i_obj_p->i_ref_count-- == 1;
        if ( v9 )
        {
          i_obj_p->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(i_obj_p);
          AMemory::c_free_func(i_obj_p);
        }
      }
    }
  }
}


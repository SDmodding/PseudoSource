// File Line: 63
// RVA: 0x130B30
SSInstance *__fastcall SSClosure::pool_new(SSClosureInfoBase *closure_info_p, SSInstance *receiver_p)
{
  SSInstance *v2; // rsi
  SSClosureInfoBase *v3; // rdi
  __int64 v4; // rax
  SSInstance *v5; // r8
  AObjReusePool<SSInstance> *v6; // rax
  AObjReusePool<SSInstance> *v7; // rbx
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  __int64 v11; // rcx
  SSInstance **v12; // rax
  unsigned int v13; // eax
  SSClass *v14; // rax

  v2 = receiver_p;
  v3 = closure_info_p;
  v4 = closure_info_p->i_captured.i_count;
  if ( (_DWORD)v4 )
  {
    v5 = (SSInstance *)AMemory::c_malloc_func(8 * v4 + 48, "SSClosure");
    goto LABEL_11;
  }
  v6 = SSInstance::get_pool();
  v7 = v6;
  v8 = v6->i_pool.i_count;
  if ( v8 )
  {
    v13 = v8 - 1;
    v7->i_pool.i_count = v13;
    v11 = v13;
    v12 = v7->i_pool.i_array_p;
    goto LABEL_9;
  }
  if ( !v7->i_exp_pool.i_count )
    AObjReusePool<SSInstance>::append_block(v7, v7->i_expand_size);
  v9 = v7->i_exp_pool.i_count;
  if ( v9 )
  {
    v10 = v9 - 1;
    v7->i_exp_pool.i_count = v10;
    v11 = v10;
    v12 = v7->i_exp_pool.i_array_p;
LABEL_9:
    v5 = v12[v11];
    goto LABEL_11;
  }
  v5 = 0i64;
LABEL_11:
  if ( v5 )
  {
    v14 = SSBrain::c_closure_class_p;
    v5->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
    v5->i_ref_count = 0;
    v5->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable;
    v5->i_class_p = v14;
    v5->i_user_data = (unsigned __int64)v3;
    v5->i_user_data2 = (unsigned __int64)v2;
    v5->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
    v5->vfptr = (SSObjectBaseVtbl *)&SSClosure::`vftable;
    ++v3->i_ref_count;
    ++v2->i_ref_count;
  }
  v5->i_ref_count = 1;
  return v5;
}

// File Line: 91
// RVA: 0x130670
void __fastcall SSClosure::pool_delete(SSClosure *this)
{
  SSClosure *v1; // rdi
  __int64 v2; // rsi
  _DWORD *v3; // rcx
  bool v4; // zf
  void (__fastcall ***v5)(signed __int64, signed __int64); // rax
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rsi
  _DWORD *v8; // rcx
  AObjReusePool<SSInstance> *v9; // rax
  AObjBlock<SSInstance> *v10; // rcx
  unsigned __int64 v11; // r8
  unsigned __int64 v12; // rdx
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v13; // rcx

  v1 = this;
  v2 = *(unsigned int *)(this->i_user_data + 16);
  v3 = (_DWORD *)this->i_user_data2;
  v4 = v3[4]-- == 1;
  if ( v4 )
  {
    v3[4] = 2147483648;
    (*(void (__cdecl **)(_DWORD *))(*(_QWORD *)v3 + 112i64))(v3);
  }
  v5 = (void (__fastcall ***)(signed __int64, signed __int64))(v1->i_user_data + 8);
  v4 = (*(_DWORD *)v5)-- == 1;
  if ( v4 )
  {
    *(_DWORD *)v5 = 2147483648;
    if ( v5 )
    {
      if ( v5 != (void (__fastcall ***)(signed __int64, signed __int64))8 )
        (**(v5 - 1))((signed __int64)(v5 - 1), 1i64);
    }
  }
  v1->i_ptr_id = 0;
  if ( (_DWORD)v2 )
  {
    v6 = (unsigned __int64)&v1[1];
    v7 = (unsigned __int64)&v1[1] + 8 * v2;
    if ( (unsigned __int64)&v1[1] < v7 )
    {
      do
      {
        v8 = *(_DWORD **)v6;
        v4 = *(_DWORD *)(*(_QWORD *)v6 + 16i64) == 1;
        --v8[4];
        if ( v4 )
        {
          v8[4] = 2147483648;
          (*(void (__cdecl **)(_DWORD *))(*(_QWORD *)v8 + 112i64))(v8);
        }
        v6 += 8i64;
      }
      while ( v6 < v7 );
    }
    AMemory::c_free_func(v1);
  }
  else
  {
    v9 = SSInstance::get_pool();
    v10 = v9->i_block_p;
    v11 = (unsigned __int64)v10->i_objects_a;
    if ( (unsigned __int64)v1 < v11 || (v12 = v11 + 48i64 * v10->i_size, v13 = &v9->i_pool, (unsigned __int64)v1 >= v12) )
      v13 = &v9->i_exp_pool;
    APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(v13, (SSInstance *)&v1->vfptr);
    v1->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
    v1->i_ref_count = 0;
    v1->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable;
  }
}

// File Line: 226
// RVA: 0x1176F0
SSInstance *__fastcall SSClosure::get_data_by_name(SSClosure *this, ASymbol *name)
{
  unsigned __int64 v2; // r8
  int v3; // eax
  __int64 v4; // rbx
  unsigned int v5; // er10
  signed __int64 v6; // r9
  signed __int64 i; // r8
  unsigned int *v8; // rax

  v2 = this->i_user_data;
  v3 = *(_DWORD *)(v2 + 16);
  if ( !v3 )
    return (SSInstance *)(*(__int64 (__fastcall **)(unsigned __int64, ASymbol *))(*(_QWORD *)this->i_user_data2 + 32i64))(
                           this->i_user_data2,
                           name);
  v4 = *(_QWORD *)(v2 + 24);
  v5 = name->i_uid;
  v6 = v4 + 4i64 * (unsigned int)(v3 - 1);
  for ( i = *(_QWORD *)(v2 + 24); ; i = (signed __int64)(v8 + 1) )
  {
    while ( 1 )
    {
      v8 = (unsigned int *)(i + 4 * ((v6 - i) >> 3));
      if ( v5 >= *v8 )
        break;
      if ( (unsigned int *)i == v8 )
        return (SSInstance *)(*(__int64 (__fastcall **)(unsigned __int64, ASymbol *))(*(_QWORD *)this->i_user_data2
                                                                                    + 32i64))(
                               this->i_user_data2,
                               name);
      v6 = (signed __int64)(v8 - 1);
    }
    if ( (v5 != *v8) <= 0i64 )
      break;
    if ( (unsigned int *)v6 == v8 )
      return (SSInstance *)(*(__int64 (__fastcall **)(unsigned __int64, ASymbol *))(*(_QWORD *)this->i_user_data2 + 32i64))(
                             this->i_user_data2,
                             name);
  }
  return (SSInstance *)*((_QWORD *)&this[1].vfptr + (unsigned int)(((signed __int64)v8 - v4) >> 2));
}

// File Line: 252
// RVA: 0x13C380
void __fastcall SSClosure::set_data_by_name(SSClosure *this, ASymbol *name, SSInstance *obj_p)
{
  unsigned __int64 v3; // r9
  SSInstance *v4; // rdi
  int v5; // eax
  SSClosure *v6; // r11
  __int64 v7; // rsi
  unsigned int v8; // er10
  signed __int64 v9; // r8
  signed __int64 i; // r9
  unsigned int *v11; // rcx
  __int64 v12; // rax
  _DWORD *v13; // rcx
  bool v14; // zf
  signed __int64 v15; // rbx

  v3 = this->i_user_data;
  v4 = obj_p;
  v5 = *(_DWORD *)(v3 + 16);
  v6 = this;
  if ( v5 )
  {
    v7 = *(_QWORD *)(v3 + 24);
    v8 = name->i_uid;
    v9 = v7 + 4i64 * (unsigned int)(v5 - 1);
    for ( i = *(_QWORD *)(v3 + 24); ; i = (signed __int64)(v11 + 1) )
    {
      while ( 1 )
      {
        v11 = (unsigned int *)(i + 4 * ((v9 - i) >> 3));
        if ( v8 >= *v11 )
          break;
        if ( (unsigned int *)i == v11 )
          goto LABEL_12;
        v9 = (signed __int64)(v11 - 1);
      }
      if ( (v8 != *v11) <= 0i64 )
        break;
      if ( (unsigned int *)v9 == v11 )
        goto LABEL_12;
    }
    ++v4->i_ref_count;
    v12 = (unsigned int)(((signed __int64)v11 - v7) >> 2);
    v13 = (_DWORD *)*((_QWORD *)&v6[1].vfptr + v12);
    v14 = v13[4]-- == 1;
    v15 = (signed __int64)v6 + 8 * v12;
    if ( v14 )
    {
      v13[4] = 2147483648;
      (*(void (**)(void))(*(_QWORD *)v13 + 112i64))();
    }
    *(_QWORD *)(v15 + 48) = v4;
  }
  else
  {
LABEL_12:
    (*(void (__fastcall **)(unsigned __int64, ASymbol *, SSInstance *))(*(_QWORD *)v6->i_user_data2 + 40i64))(
      v6->i_user_data2,
      name,
      v4);
  }
}

// File Line: 291
// RVA: 0x1201F0
void __fastcall SSClosure::mthd_String(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rdi
  unsigned int v3; // eax
  AStringRef *v4; // rbx
  SSInstance *v5; // rax
  bool v6; // zf
  AObjReusePool<AStringRef> *v7; // rax
  AObjBlock<AStringRef> *v8; // rcx
  unsigned __int64 v9; // r8
  bool v10; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v11; // rcx

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = AMemory::c_req_byte_size_func(0xFu);
    v4 = AStringRef::pool_new("Closure object", 0xEu, v3, 1u, 0, 1);
    v5 = SSInstance::pool_new(SSBrain::c_string_class_p);
    if ( v5 != (SSInstance *)-32i64 )
    {
      v5->i_user_data = (unsigned __int64)v4;
      ++v4->i_ref_count;
    }
    *v2 = v5;
    v6 = v4->i_ref_count-- == 1;
    if ( v6 )
    {
      if ( v4->i_deallocate )
        AMemory::c_free_func(v4->i_cstr_p);
      v7 = AStringRef::get_pool();
      v8 = v7->i_block_p;
      v9 = (unsigned __int64)v8->i_objects_a;
      if ( (unsigned __int64)v4 < v9 || (v10 = (unsigned __int64)v4 < v9 + 24i64 * v8->i_size, v11 = &v7->i_pool, !v10) )
        v11 = &v7->i_exp_pool;
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v11, v4);
    }
  }
}

// File Line: 315
// RVA: 0x13B030
void SSClosure::register_bindings(void)
{
  __int64 v0; // rax
  SSMethodBase **v1; // r8
  signed __int64 v2; // r10
  signed __int64 v3; // rdx
  unsigned int v4; // er9
  _BOOL8 v5; // r9
  __int64 v6; // rbx
  __int64 v7; // rbp
  SSParameters *v8; // rdi
  SSParameters *v9; // rsi
  bool v10; // zf

  v0 = SSBrain::c_closure_class_p->i_methods.i_count;
  if ( (_DWORD)v0 )
  {
    v1 = SSBrain::c_closure_class_p->i_methods.i_array_p;
    v2 = (signed __int64)&v1[v0 - 1];
    while ( 1 )
    {
      v3 = (signed __int64)&v1[(v2 - (signed __int64)v1) >> 4];
      v4 = *(_DWORD *)(*(_QWORD *)v3 + 8i64);
      if ( ASymbol_String.i_uid < v4 )
        goto LABEL_28;
      v5 = ASymbol_String.i_uid != v4;
      if ( !v5 )
      {
        v6 = *(_QWORD *)v3;
        goto LABEL_12;
      }
      if ( v5 < 0 )
      {
LABEL_28:
        if ( v1 == (SSMethodBase **)v3 )
          break;
        v2 = v3 - 8;
      }
      else
      {
        if ( v2 == v3 )
          break;
        v1 = (SSMethodBase **)(v3 + 8);
      }
    }
  }
  v6 = 0i64;
LABEL_12:
  if ( v6 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v6 + 16i64))(v6) == 1 )
    {
      *(_QWORD *)(v6 + 32) = SSClosure::mthd_String;
    }
    else
    {
      v7 = *(_QWORD *)(v6 + 16);
      v8 = *(SSParameters **)(v6 + 24);
      if ( v8 )
        ++v8->i_ref_count;
      v9 = *(SSParameters **)(v6 + 24);
      if ( v9 )
      {
        v10 = v9->i_ref_count-- == 1;
        if ( v10 )
        {
          v9->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v9);
          AMemory::c_free_func(v9);
        }
        *(_QWORD *)(v6 + 24) = 0i64;
      }
      *(ASymbol *)(v6 + 8) = ASymbol_String;
      *(_QWORD *)(v6 + 16) = v7;
      *(_QWORD *)v6 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v6 + 24) = v8;
      if ( v8 )
        ++v8->i_ref_count;
      *(_QWORD *)v6 = &SSMethodBase::`vftable;
      *(_QWORD *)v6 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v6 + 32) = SSClosure::mthd_String;
      if ( v8 )
      {
        v10 = v8->i_ref_count-- == 1;
        if ( v10 )
        {
          v8->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v8);
          AMemory::c_free_func(v8);
        }
      }
    }
  }
}


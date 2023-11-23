// File Line: 54
// RVA: 0x1071E0
void __fastcall SSInvokeBase::~SSInvokeBase(SSInvokeBase *this)
{
  this->vfptr = (SSInvokeBaseVtbl *)&SSInvokeBase::`vftable;
  APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)&this->i_arguments);
  APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)&this->i_return_args);
  AMemory::c_free_func(this->i_return_args.i_array_p);
  AMemory::c_free_func(this->i_arguments.i_array_p);
}

// File Line: 200
// RVA: 0x1113F0
void __fastcall SSInvokeBase::assign_binary(SSInvokeBase *this, const void **binary_pp)
{
  ASymbol *v4; // rax
  unsigned __int8 v5; // bp
  SSExpressionBase **i_array_p; // rcx
  SSExpressionBase **v7; // rdi
  SSExpressionBase **i; // rbp
  char *v9; // rax
  eSSExprType v10; // ecx
  SSExpressionBase *v11; // rax
  unsigned __int8 v12; // bp
  SSIdentifier **v13; // rcx
  SSIdentifier **v14; // rdi
  SSIdentifier **j; // rsi
  char *v16; // rax
  eSSExprType v17; // ecx
  SSExpressionBase *v18; // rax
  ASymbol result; // [rsp+30h] [rbp+8h] BYREF

  this->i_name = (ASymbol)ASymbol::create_from_binary(&result, binary_pp)->i_uid;
  v4 = ASymbol::create_from_binary(&result, binary_pp);
  this->i_scope_p = SSBrain::get_class(v4);
  v5 = *(_BYTE *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  if ( v5 )
  {
    if ( this->i_arguments.i_count != v5 )
    {
      i_array_p = this->i_arguments.i_array_p;
      this->i_arguments.i_count = v5;
      if ( i_array_p )
        AMemory::c_free_func(i_array_p);
      this->i_arguments.i_array_p = APArrayBase<SSExpressionBase>::alloc_array(v5);
    }
    v7 = this->i_arguments.i_array_p;
    for ( i = &v7[v5]; v7 < i; ++v7 )
    {
      v9 = (char *)*binary_pp + 1;
      v10 = *(unsigned __int8 *)*binary_pp;
      *binary_pp = v9;
      if ( v10 )
      {
        *binary_pp = v9 + 2;
        v11 = SSExpressionBase::from_binary_new(v10, binary_pp);
      }
      else
      {
        v11 = 0i64;
      }
      *v7 = v11;
    }
  }
  v12 = *(_BYTE *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  if ( v12 )
  {
    if ( this->i_return_args.i_count != v12 )
    {
      v13 = this->i_return_args.i_array_p;
      this->i_return_args.i_count = v12;
      if ( v13 )
        AMemory::c_free_func(v13);
      this->i_return_args.i_array_p = APArrayBase<SSIdentifier>::alloc_array(v12);
    }
    v14 = this->i_return_args.i_array_p;
    for ( j = &v14[v12]; v14 < j; ++v14 )
    {
      v16 = (char *)*binary_pp + 1;
      v17 = *(unsigned __int8 *)*binary_pp;
      *binary_pp = v16;
      if ( v17 )
      {
        *binary_pp = v16 + 2;
        v18 = SSExpressionBase::from_binary_new(v17, binary_pp);
      }
      else
      {
        v18 = 0i64;
      }
      *v14 = (SSIdentifier *)v18;
    }
  }
}

// File Line: 261
// RVA: 0x116D40
void __fastcall SSInvokeBase::from_binary_typed_new(const void **binary_pp)
{
  int v2; // edx
  int v3; // edx
  SSCoroutineCall *v4; // rax
  SSMethodCall *v5; // rax

  v2 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  v3 = v2 - 1;
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      v4 = (SSCoroutineCall *)AMemory::c_malloc_func(0x38ui64, "SSCoroutineCall");
      if ( v4 )
        SSCoroutineCall::SSCoroutineCall(v4, binary_pp);
    }
  }
  else
  {
    v5 = (SSMethodCall *)AMemory::c_malloc_func(0x38ui64, "SSMethodCall");
    if ( v5 )
      SSMethodCall::SSMethodCall(v5, binary_pp);
  }
}

// File Line: 486
// RVA: 0x1070A0
void __fastcall SSInvocation::~SSInvocation(SSInvocation *this)
{
  SSExpressionBase *i_receiver_p; // rcx
  SSInvokeBase *i_call_p; // rcx

  this->vfptr = (SSExpressionBaseVtbl *)&SSInvocation::`vftable;
  i_receiver_p = this->i_receiver_p;
  if ( i_receiver_p )
    i_receiver_p->vfptr->__vecDelDtor(i_receiver_p, 1u);
  i_call_p = this->i_call_p;
  if ( i_call_p )
    i_call_p->vfptr->__vecDelDtor(i_call_p, 1u);
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
}

// File Line: 665
// RVA: 0x11D360
SSInvokedBase *__fastcall SSInvocation::invoke(
        SSInvocation *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSExpressionBase *i_receiver_p; // rcx
  SSInstance *v9; // rbx
  SSInvokedBase *v10; // rdi
  SSInstance *v13; // [rsp+50h] [rbp+8h] BYREF

  i_receiver_p = this->i_receiver_p;
  if ( i_receiver_p )
  {
    i_receiver_p->vfptr->invoke(i_receiver_p, scope_p, caller_p, &v13);
    v9 = v13;
  }
  else
  {
    v9 = scope_p->vfptr->get_topmost_scope(scope_p);
  }
  if ( v9 )
  {
    v10 = this->i_call_p->vfptr->invoke_call(this->i_call_p, v9, scope_p, caller_p, result_pp);
    if ( this->i_receiver_p )
    {
      if ( v9->i_ref_count-- == 1 )
      {
        v9->i_ref_count = 0x80000000;
        v9->vfptr[1].get_scope_context(v9);
      }
    }
    return v10;
  }
  else
  {
    if ( result_pp )
      *result_pp = SSBrain::c_nil_p;
    return 0i64;
  }
}

// File Line: 720
// RVA: 0x11EF90
bool __fastcall SSInvocation::is_immediate(SSInvocation *this, unsigned int *durational_idx_p)
{
  return ((unsigned int (__fastcall *)(SSInvokeBase *, unsigned int *))this->i_call_p->vfptr->get_invoke_type)(
           this->i_call_p,
           durational_idx_p) == 1;
}

// File Line: 747
// RVA: 0x126B20
void __fastcall SSInvokeCascade::null_receiver(SSInvokeClosureBase *this, SSExpressionBase *receiver_p)
{
  SSExpressionBase *i_receiver_p; // rcx

  i_receiver_p = this->i_receiver_p;
  if ( i_receiver_p )
  {
    if ( i_receiver_p == receiver_p )
      this->i_receiver_p = 0i64;
    else
      ((void (__fastcall *)(SSExpressionBase *))i_receiver_p->vfptr->null_receiver)(i_receiver_p);
  }
}

// File Line: 767
// RVA: 0x13DEC0
void __fastcall SSInvocation::track_memory(SSInvocation *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase *i_receiver_p; // rcx

  AMemoryStats::track_memory(mem_stats_p, "SSInvocation", 0x18u, 8u, 0, 0, 1u);
  i_receiver_p = this->i_receiver_p;
  if ( i_receiver_p )
    i_receiver_p->vfptr->track_memory(i_receiver_p, mem_stats_p);
  this->i_call_p->vfptr->track_memory(this->i_call_p, mem_stats_p);
}

// File Line: 838
// RVA: 0x11D760
SSInvokedExpression *__fastcall SSInvokeSync::invoke(
        SSInvokeSync *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSInstance *v8; // rbx
  SSInvokedBase *v9; // rax
  bool v10; // zf
  SSInvokedBase *v11; // rdi
  unsigned int *i_user_data; // r15
  __int64 v14; // rbp
  char v15; // r14
  SSInvokedExpression *v16; // rax
  SSInstance **v17; // rdi
  SSInvokedExpression *v18; // rsi
  SSInstance **i; // rbp
  SSInvokedBase *v20; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v21; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax
  SSInstance *v23; // [rsp+60h] [rbp+8h] BYREF

  this->i_receiver_p->SSInvocation::vfptr->invoke(this->i_receiver_p, scope_p, caller_p, &v23);
  v8 = v23;
  if ( !v23 || v23 == SSBrain::c_nil_p )
  {
    if ( result_pp )
      *result_pp = SSBrain::c_nil_p;
    return 0i64;
  }
  else
  {
    if ( v23->i_class_p == SSBrain::c_list_class_p )
    {
      i_user_data = (unsigned int *)v23->i_user_data;
      v14 = *i_user_data;
      if ( result_pp )
      {
        ++v23->i_ref_count;
        *result_pp = v8;
      }
      if ( (_DWORD)v14 )
      {
        v15 = 1;
        v16 = SSInvokedExpression::pool_new(this, caller_p, scope_p);
        v17 = (SSInstance **)*((_QWORD *)i_user_data + 1);
        v18 = v16;
        for ( i = &v17[v14]; v17 < i; ++v17 )
        {
          v20 = this->i_call_p->SSInvocation::vfptr->invoke_call(this->i_call_p, *v17, scope_p, v18, 0i64);
          if ( v20 )
          {
            v21 = &v20->AListNode<SSInvokedBase,SSInvokedBase>;
            i_prev_p = v18->i_calls.i_sentinel.i_prev_p;
            v18->i_calls.i_sentinel.i_prev_p = v21;
            i_prev_p->i_next_p = v21;
            v21->i_prev_p = i_prev_p;
            v21->i_next_p = &v18->i_calls.i_sentinel;
            ++v18->i_pending_count;
            v15 = 0;
          }
        }
        v10 = v8->i_ref_count-- == 1;
        if ( v10 )
        {
          v8->i_ref_count = 0x80000000;
          v8->vfptr[1].get_scope_context(v8);
        }
        if ( !v15 )
          return v18;
        SSInvokedExpression::pool_delete(v18);
      }
      else
      {
        v10 = v8->i_ref_count-- == 1;
        if ( v10 )
        {
          v8->i_ref_count = 0x80000000;
          v8->vfptr[1].get_scope_context(v8);
        }
      }
      return 0i64;
    }
    v9 = this->i_call_p->SSInvocation::vfptr->invoke_call(this->i_call_p, v23, scope_p, caller_p, result_pp);
    v10 = v8->i_ref_count-- == 1;
    v11 = v9;
    if ( v10 )
    {
      v8->i_ref_count = 0x80000000;
      v8->vfptr[1].get_scope_context(v8);
    }
    return (SSInvokedExpression *)v11;
  }
}

// File Line: 954
// RVA: 0x13E150
void __fastcall SSInvokeSync::track_memory(SSInvokeSync *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase *i_receiver_p; // rcx

  AMemoryStats::track_memory(mem_stats_p, "SSInvokeSync", 0x18u, 8u, 0, 0, 1u);
  i_receiver_p = this->i_receiver_p;
  if ( i_receiver_p )
    i_receiver_p->vfptr->track_memory(i_receiver_p, mem_stats_p);
  this->i_call_p->SSInvocation::vfptr->track_memory(this->i_call_p, mem_stats_p);
}

// File Line: 1025
// RVA: 0x11D5A0
SSInvokedExpression *__fastcall SSInvokeRace::invoke(
        SSInvokeRace *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSInstance *v8; // rbx
  SSInvokedBase *v9; // rax
  bool v10; // zf
  SSInvokedBase *v11; // rdi
  unsigned int *i_user_data; // rsi
  __int64 v14; // rbp
  char v15; // r12
  SSInvokedExpression *v16; // rax
  SSInstance **v17; // rsi
  SSInvokedExpression *v18; // rdi
  SSInstance **v19; // rbp
  SSInvokedBase *v20; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v21; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax
  unsigned __int64 i_pending_count; // rax
  SSInstance *v24; // [rsp+60h] [rbp+8h] BYREF

  this->i_receiver_p->SSInvocation::vfptr->invoke(this->i_receiver_p, scope_p, caller_p, &v24);
  v8 = v24;
  if ( !v24 || v24 == SSBrain::c_nil_p )
  {
    if ( result_pp )
      *result_pp = SSBrain::c_nil_p;
    return 0i64;
  }
  else
  {
    if ( v24->i_class_p == SSBrain::c_list_class_p )
    {
      i_user_data = (unsigned int *)v24->i_user_data;
      v14 = *i_user_data;
      if ( result_pp )
      {
        ++v24->i_ref_count;
        *result_pp = v8;
      }
      if ( (_DWORD)v14 )
      {
        v15 = 0;
        v16 = SSInvokedExpression::pool_new(this, caller_p, scope_p);
        v17 = (SSInstance **)*((_QWORD *)i_user_data + 1);
        v18 = v16;
        v19 = &v17[v14];
        if ( v17 < v19 )
        {
          while ( 1 )
          {
            v20 = this->i_call_p->SSInvocation::vfptr->invoke_call(this->i_call_p, *v17, scope_p, v18, 0i64);
            if ( !v20 )
              break;
            v21 = &v20->AListNode<SSInvokedBase,SSInvokedBase>;
            i_prev_p = v18->i_calls.i_sentinel.i_prev_p;
            v18->i_calls.i_sentinel.i_prev_p = v21;
            i_prev_p->i_next_p = v21;
            ++v17;
            v21->i_prev_p = i_prev_p;
            v21->i_next_p = &v18->i_calls.i_sentinel;
            ++v18->i_pending_count;
            if ( v17 >= v19 )
              goto LABEL_18;
          }
          v15 = 1;
        }
LABEL_18:
        v10 = v8->i_ref_count-- == 1;
        if ( v10 )
        {
          v8->i_ref_count = 0x80000000;
          v8->vfptr[1].get_scope_context(v8);
        }
        if ( !v15 )
        {
          i_pending_count = v18->i_pending_count;
          v18->i_pending_count = 1;
          v18->i_data = i_pending_count;
          return v18;
        }
        SSInvokedBase::abort_subcalls(v18, SSNotify_ignore);
        SSInvokedExpression::pool_delete(v18);
      }
      else
      {
        v10 = v8->i_ref_count-- == 1;
        if ( v10 )
        {
          v8->i_ref_count = 0x80000000;
          v8->vfptr[1].get_scope_context(v8);
        }
      }
      return 0i64;
    }
    v9 = this->i_call_p->SSInvocation::vfptr->invoke_call(this->i_call_p, v24, scope_p, caller_p, result_pp);
    v10 = v8->i_ref_count-- == 1;
    v11 = v9;
    if ( v10 )
    {
      v8->i_ref_count = 0x80000000;
      v8->vfptr[1].get_scope_context(v8);
    }
    return (SSInvokedExpression *)v11;
  }
}

// File Line: 1184
// RVA: 0x13E0E0
void __fastcall SSInvokeRace::track_memory(SSInvokeRace *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase *i_receiver_p; // rcx

  AMemoryStats::track_memory(mem_stats_p, "SSInvokeRace", 0x18u, 8u, 0, 0, 1u);
  i_receiver_p = this->i_receiver_p;
  if ( i_receiver_p )
    i_receiver_p->vfptr->track_memory(i_receiver_p, mem_stats_p);
  this->i_call_p->SSInvocation::vfptr->track_memory(this->i_call_p, mem_stats_p);
}

// File Line: 1227
// RVA: 0x105430
void __fastcall SSInvokeCascade::SSInvokeCascade(SSInvokeCascade *this, const void **binary_pp)
{
  APArrayFree<SSInvokeBase,SSInvokeBase,ACompareAddress<SSInvokeBase> > *p_i_invoke_calls; // rdi
  eSSExprType v5; // ecx
  char *v6; // rax
  SSExpressionBase *v7; // rax
  unsigned int v8; // r15d
  int v9; // ecx
  int v10; // ecx
  SSInvokeBase *v11; // rbx
  __int64 i_count; // rbp
  SSInvokeBase **i_array_p; // r14
  unsigned __int64 v14; // rax
  SSInvokeBase **v15; // rax

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSInvokeCascade::`vftable;
  p_i_invoke_calls = &this->i_invoke_calls;
  this->i_invoke_calls.i_count = 0;
  this->i_invoke_calls.i_array_p = 0i64;
  this->i_invoke_calls.i_size = 0;
  v5 = *(unsigned __int8 *)*binary_pp;
  v6 = (char *)*binary_pp + 1;
  *binary_pp = v6;
  if ( v5 )
  {
    *binary_pp = v6 + 2;
    v7 = SSExpressionBase::from_binary_new(v5, binary_pp);
  }
  else
  {
    v7 = 0i64;
  }
  this->i_receiver_p = v7;
  v8 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  if ( p_i_invoke_calls->i_size < v8 )
  {
    p_i_invoke_calls->i_size = AMemory::c_req_byte_size_func(8 * v8) >> 3;
    AMemory::c_free_func(p_i_invoke_calls->i_array_p);
    p_i_invoke_calls->i_array_p = APArrayBase<SSInvokeBase>::alloc_array(p_i_invoke_calls->i_size);
  }
  for ( p_i_invoke_calls->i_count = 0; v8; --v8 )
  {
    v9 = *(unsigned __int8 *)*binary_pp;
    *binary_pp = (char *)*binary_pp + 1;
    v10 = v9 - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
      {
        v11 = (SSInvokeBase *)AMemory::c_malloc_func(0x38ui64, "SSCoroutineCall");
        if ( v11 )
        {
          v11->i_name = (ASymbol)ASymbol::get_null()->i_uid;
          v11->i_scope_p = 0i64;
          v11->vfptr = (SSInvokeBaseVtbl *)&SSInvokeBase::`vftable;
          v11->i_arguments.i_count = 0;
          v11->i_arguments.i_array_p = 0i64;
          v11->i_return_args.i_count = 0;
          v11->i_return_args.i_array_p = 0i64;
          v11->vfptr = (SSInvokeBaseVtbl *)&SSCoroutineCall::`vftable;
          SSInvokeBase::assign_binary(v11, binary_pp);
        }
        else
        {
          v11 = 0i64;
        }
      }
      else
      {
        v11 = 0i64;
      }
    }
    else
    {
      v11 = (SSInvokeBase *)AMemory::c_malloc_func(0x38ui64, "SSMethodCall");
      if ( v11 )
      {
        v11->i_name = (ASymbol)ASymbol::get_null()->i_uid;
        v11->i_scope_p = 0i64;
        v11->vfptr = (SSInvokeBaseVtbl *)&SSInvokeBase::`vftable;
        v11->i_arguments.i_count = 0;
        v11->i_arguments.i_array_p = 0i64;
        v11->i_return_args.i_count = 0;
        v11->i_return_args.i_array_p = 0i64;
        v11->vfptr = (SSInvokeBaseVtbl *)&SSMethodCall::`vftable;
        SSInvokeBase::assign_binary(v11, binary_pp);
      }
      else
      {
        v11 = 0i64;
      }
    }
    i_count = p_i_invoke_calls->i_count;
    if ( p_i_invoke_calls->i_size < (unsigned int)(i_count + 1) )
    {
      i_array_p = p_i_invoke_calls->i_array_p;
      if ( (_DWORD)i_count == -1 )
        LODWORD(v14) = 0;
      else
        v14 = (unsigned __int64)AMemory::c_req_byte_size_func(8 * (i_count & 0xFFFFFFFC) + 32) >> 3;
      p_i_invoke_calls->i_size = v14;
      v15 = APArrayBase<SSInvokeBase>::alloc_array(v14);
      p_i_invoke_calls->i_array_p = v15;
      memmove(v15, i_array_p, 8 * i_count);
      AMemory::c_free_func(i_array_p);
    }
    p_i_invoke_calls->i_array_p[i_count] = v11;
    ++p_i_invoke_calls->i_count;
  }
}

// File Line: 1494
// RVA: 0x11E440
char __fastcall SSInvokeCascade::invoke_iterate(
        SSInvokeCascade *this,
        SSInvokedExpression *iexpr_p,
        SSInstance **result_pp)
{
  unsigned int i_index; // edx
  SSObjectBase *i_obj_p; // rbp
  unsigned __int64 i_data; // r12
  bool v8; // r13
  AListNode<SSInvokedBase,SSInvokedBase> *v9; // rdi
  SSInvokeBase **i_array_p; // r15
  unsigned int v11; // esi
  SSInvokeBase *v12; // rcx
  __int64 v13; // rax
  bool v14; // si
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax
  SSInvokedBase *v17; // rdi
  _DWORD *v18; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_next_p; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v21; // rax

  i_index = iexpr_p->i_index;
  i_obj_p = iexpr_p->i_scope_p.i_obj_p;
  i_data = iexpr_p->i_data;
  v8 = i_index == 0;
  v9 = 0i64;
  if ( !i_obj_p || iexpr_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = this->i_invoke_calls.i_array_p;
  v11 = this->i_invoke_calls.i_count - 1;
  if ( i_index < v11 )
  {
    do
    {
      v12 = i_array_p[iexpr_p->i_index];
      v9 = (AListNode<SSInvokedBase,SSInvokedBase> *)v12->vfptr->invoke_call(
                                                       v12,
                                                       (SSInstance *)i_data,
                                                       i_obj_p,
                                                       iexpr_p,
                                                       0i64);
      if ( v9 )
        break;
      ++iexpr_p->i_index;
    }
    while ( iexpr_p->i_index < v11 );
  }
  v13 = iexpr_p->i_index;
  v14 = (_DWORD)v13 == v11;
  if ( v14 )
    v9 = (AListNode<SSInvokedBase,SSInvokedBase> *)i_array_p[v13]->vfptr->invoke_call(
                                                     i_array_p[v13],
                                                     (SSInstance *)i_data,
                                                     i_obj_p,
                                                     iexpr_p,
                                                     result_pp);
  if ( v9 )
  {
    if ( result_pp )
    {
      if ( !v14 )
        *result_pp = (SSInstance *)((__int64 (__fastcall *)(AListNode<SSInvokedBase,SSInvokedBase> *))v9->i_next_p[1].i_prev_p)(v9);
    }
    i_prev_p = iexpr_p->i_calls.i_sentinel.i_prev_p;
    iexpr_p->i_calls.i_sentinel.i_prev_p = v9 + 1;
    i_prev_p->i_next_p = v9 + 1;
    v9[1].i_prev_p = i_prev_p;
    v9[1].i_next_p = &iexpr_p->i_calls.i_sentinel;
    ++iexpr_p->i_pending_count;
    return 0;
  }
  else
  {
    v17 = iexpr_p->i_caller_p.i_obj_p;
    if ( !v17 || iexpr_p->i_caller_p.i_ptr_id != v17->i_ptr_id )
      v17 = 0i64;
    v18 = (_DWORD *)iexpr_p->i_data;
    if ( v18 )
    {
      iexpr_p->i_data = 0i64;
      if ( v18[4]-- == 1 )
      {
        v18[4] = 0x80000000;
        (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v18 + 112i64))(v18);
      }
    }
    if ( !v8 && v17 && v17->i_pending_count )
    {
      i_next_p = iexpr_p->i_next_p;
      if ( i_next_p != &iexpr_p->AListNode<SSInvokedBase,SSInvokedBase> )
      {
        v21 = iexpr_p->i_prev_p;
        i_next_p->i_prev_p = v21;
        v21->i_next_p = i_next_p;
        iexpr_p->i_prev_p = &iexpr_p->AListNode<SSInvokedBase,SSInvokedBase>;
        iexpr_p->i_next_p = &iexpr_p->AListNode<SSInvokedBase,SSInvokedBase>;
      }
      LOBYTE(i_next_p) = 1;
      v17->vfptr[1].get_data_by_name(v17, (ASymbol *)i_next_p);
    }
    SSInvokedExpression::pool_delete(iexpr_p);
    return 1;
  }
}

// File Line: 1594
// RVA: 0x11D410
SSInvokedExpression *__fastcall SSInvokeCascade::invoke(
        SSInvokeCascade *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSInvokedExpression *v8; // rax
  SSExpressionBase *i_receiver_p; // rcx
  SSInvokedExpression *v10; // rbx
  SSInstance *v11; // rax
  SSInstance *v13; // [rsp+40h] [rbp+8h] BYREF

  v8 = SSInvokedExpression::pool_new(this, caller_p, scope_p);
  i_receiver_p = this->i_receiver_p;
  v10 = v8;
  if ( i_receiver_p )
  {
    i_receiver_p->vfptr->invoke(i_receiver_p, scope_p, caller_p, &v13);
    v11 = v13;
  }
  else
  {
    v11 = scope_p->vfptr->get_topmost_scope(scope_p);
    ++v11->i_ref_count;
  }
  v10->i_data = (unsigned __int64)v11;
  if ( this->vfptr->invoke_iterate(this, v10, result_pp) )
    return 0i64;
  return v10;
}

// File Line: 1650
// RVA: 0x11EFB0
char __fastcall SSInvokeCascade::is_immediate(SSInvokeCascade *this, unsigned int *durational_idx_p)
{
  SSInvokeBase **i_array_p; // rbx
  SSInvokeBase **v3; // rdi

  i_array_p = this->i_invoke_calls.i_array_p;
  v3 = &i_array_p[this->i_invoke_calls.i_count];
  if ( i_array_p >= v3 )
    return 1;
  while ( ((unsigned int (__fastcall *)(SSInvokeBase *, unsigned int *))(*i_array_p)->vfptr->get_invoke_type)(
            *i_array_p,
            durational_idx_p) == 1 )
  {
    if ( ++i_array_p >= v3 )
      return 1;
  }
  return 0;
}

// File Line: 1690
// RVA: 0x11E240
void __fastcall SSInvokeCascade::invoke_exit(
        SSInvokeCascade *this,
        SSInvokedExpression *iexpr_p,
        SSInvokedExpression *sub_exit_p)
{
  iexpr_p->i_index = this->i_invoke_calls.i_count;
}

// File Line: 1727
// RVA: 0x13DF30
void __fastcall SSInvokeCascade::track_memory(SSInvokeCascade *this, AMemoryStats *mem_stats_p)
{
  SSInvokeBase **i_array_p; // rbx
  SSInvokeBase **i; // rdi
  SSExpressionBase *i_receiver_p; // rcx

  i_array_p = this->i_invoke_calls.i_array_p;
  for ( i = &i_array_p[this->i_invoke_calls.i_count]; i_array_p < i; ++i_array_p )
  {
    if ( *i_array_p )
      (*i_array_p)->vfptr->track_memory(*i_array_p, mem_stats_p);
  }
  AMemoryStats::track_memory(
    mem_stats_p,
    "SSInvokeCascade",
    0x28u,
    8u,
    8 * this->i_invoke_calls.i_count,
    8 * this->i_invoke_calls.i_size,
    1u);
  i_receiver_p = this->i_receiver_p;
  if ( i_receiver_p )
    i_receiver_p->vfptr->track_memory(i_receiver_p, mem_stats_p);
}

// File Line: 1770
// RVA: 0x1052C0
void __fastcall SSInstantiate::SSInstantiate(SSInstantiate *this, const void **binary_pp)
{
  ASymbol *v4; // rax
  SSMethodCall *v5; // rax
  SSMethodCall *result; // [rsp+50h] [rbp+18h] BYREF

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSInstantiate::`vftable;
  v4 = ASymbol::create_from_binary((ASymbol *)&result, binary_pp);
  this->i_class_p = SSBrain::get_class(v4);
  v5 = (SSMethodCall *)AMemory::c_malloc_func(0x38ui64, "SSMethodCall");
  result = v5;
  if ( v5 )
    SSMethodCall::SSMethodCall(v5, binary_pp);
  this->i_ctor_p = v5;
}

// File Line: 1938
// RVA: 0x11D2C0
SSInvokedBase *__fastcall SSInstantiate::invoke(
        SSInstantiate *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSInstance *v8; // r14

  v8 = (SSInstance *)this->i_class_p->vfptr[1].get_key_class(this->i_class_p);
  this->i_ctor_p->vfptr->invoke_call(this->i_ctor_p, v8, scope_p, caller_p, 0i64);
  if ( result_pp )
  {
    *result_pp = v8;
  }
  else if ( v8->i_ref_count-- == 1 )
  {
    v8->i_ref_count = 0x80000000;
    v8->vfptr[1].get_scope_context(v8);
  }
  return 0i64;
}

// File Line: 1973
// RVA: 0x13DE60
void __fastcall SSInstantiate::track_memory(SSInstantiate *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats::track_memory(mem_stats_p, "SSInstantiate", 0x18u, 8u, 0, 0, 1u);
  this->i_ctor_p->vfptr->track_memory(this->i_ctor_p, mem_stats_p);
}


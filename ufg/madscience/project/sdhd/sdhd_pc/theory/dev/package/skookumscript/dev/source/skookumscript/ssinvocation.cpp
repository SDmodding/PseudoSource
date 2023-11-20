// File Line: 54
// RVA: 0x1071E0
void __fastcall SSInvokeBase::~SSInvokeBase(SSInvokeBase *this)
{
  SSInvokeBase *v1; // rbx

  v1 = this;
  this->vfptr = (SSInvokeBaseVtbl *)&SSInvokeBase::`vftable;
  APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)&this->i_arguments);
  APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)&v1->i_return_args);
  AMemory::c_free_func(v1->i_return_args.i_array_p);
  AMemory::c_free_func(v1->i_arguments.i_array_p);
}

// File Line: 200
// RVA: 0x1113F0
void __fastcall SSInvokeBase::assign_binary(SSInvokeBase *this, const void **binary_pp)
{
  SSInvokeBase *v2; // rsi
  const void **v3; // rbx
  ASymbol *v4; // rax
  unsigned __int8 v5; // bp
  SSExpressionBase **v6; // rcx
  SSExpressionBase **v7; // rdi
  unsigned __int64 i; // rbp
  signed __int64 v9; // rax
  eSSExprType v10; // ecx
  SSExpressionBase *v11; // rax
  unsigned __int8 v12; // bp
  SSIdentifier **v13; // rcx
  _QWORD *v14; // rdi
  unsigned __int64 j; // rsi
  signed __int64 v16; // rax
  eSSExprType v17; // ecx
  SSExpressionBase *v18; // rax
  ASymbol result; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = binary_pp;
  this->i_name = (ASymbol)ASymbol::create_from_binary(&result, binary_pp)->i_uid;
  v4 = ASymbol::create_from_binary(&result, v3);
  v2->i_scope_p = SSBrain::get_class(v4);
  v5 = *(_BYTE *)*v3;
  *v3 = (char *)*v3 + 1;
  if ( v5 )
  {
    if ( v2->i_arguments.i_count != v5 )
    {
      v6 = v2->i_arguments.i_array_p;
      v2->i_arguments.i_count = v5;
      if ( v6 )
        AMemory::c_free_func(v6);
      v2->i_arguments.i_array_p = APArrayBase<SSExpressionBase>::alloc_array(v5);
    }
    v7 = v2->i_arguments.i_array_p;
    for ( i = (unsigned __int64)&v7[v5]; (unsigned __int64)v7 < i; ++v7 )
    {
      v9 = (signed __int64)*v3 + 1;
      v10 = *(unsigned __int8 *)*v3;
      *v3 = (const void *)v9;
      if ( v10 )
      {
        *v3 = (const void *)(v9 + 2);
        v11 = SSExpressionBase::from_binary_new(v10, v3);
      }
      else
      {
        v11 = 0i64;
      }
      *v7 = v11;
    }
  }
  v12 = *(_BYTE *)*v3;
  *v3 = (char *)*v3 + 1;
  if ( v12 )
  {
    if ( v2->i_return_args.i_count != v12 )
    {
      v13 = v2->i_return_args.i_array_p;
      v2->i_return_args.i_count = v12;
      if ( v13 )
        AMemory::c_free_func(v13);
      v2->i_return_args.i_array_p = APArrayBase<SSIdentifier>::alloc_array(v12);
    }
    v14 = v2->i_return_args.i_array_p;
    for ( j = (unsigned __int64)&v14[v12]; (unsigned __int64)v14 < j; ++v14 )
    {
      v16 = (signed __int64)*v3 + 1;
      v17 = *(unsigned __int8 *)*v3;
      *v3 = (const void *)v16;
      if ( v17 )
      {
        *v3 = (const void *)(v16 + 2);
        v18 = SSExpressionBase::from_binary_new(v17, v3);
      }
      else
      {
        v18 = 0i64;
      }
      *v14 = v18;
    }
  }
}

// File Line: 261
// RVA: 0x116D40
void __fastcall SSInvokeBase::from_binary_typed_new(const void **binary_pp)
{
  const void **v1; // rbx
  int v2; // edx
  int v3; // edx
  SSCoroutineCall *v4; // rax
  SSMethodCall *v5; // rax

  v1 = binary_pp;
  v2 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  v3 = v2 - 1;
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      v4 = (SSCoroutineCall *)AMemory::c_malloc_func(0x38ui64, "SSCoroutineCall");
      if ( v4 )
        SSCoroutineCall::SSCoroutineCall(v4, v1);
    }
  }
  else
  {
    v5 = (SSMethodCall *)AMemory::c_malloc_func(0x38ui64, "SSMethodCall");
    if ( v5 )
      SSMethodCall::SSMethodCall(v5, v1);
  }
}

// File Line: 486
// RVA: 0x1070A0
void __fastcall SSInvocation::~SSInvocation(SSInvocation *this)
{
  SSInvocation *v1; // rbx
  SSExpressionBase *v2; // rcx
  SSInvokeBase *v3; // rcx

  v1 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSInvocation::`vftable;
  v2 = this->i_receiver_p;
  if ( v2 )
    v2->vfptr->__vecDelDtor(v2, 1u);
  v3 = v1->i_call_p;
  if ( v3 )
    v3->vfptr->__vecDelDtor(v3, 1u);
  v1->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
}

// File Line: 665
// RVA: 0x11D360
SSInvokedBase *__fastcall SSInvocation::invoke(SSInvocation *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSInvocation *v4; // rbp
  SSExpressionBase *v5; // rcx
  SSInstance **v6; // rdi
  SSInvokedBase *v7; // r14
  SSObjectBase *v8; // rsi
  SSInstance *v9; // rbx
  SSInvokedBase *v10; // rdi
  bool v11; // zf
  SSInvokedBase *result; // rax
  SSInstance *v13; // [rsp+50h] [rbp+8h]

  v4 = this;
  v5 = this->i_receiver_p;
  v6 = result_pp;
  v7 = caller_p;
  v8 = scope_p;
  if ( v5 )
  {
    v5->vfptr->invoke(v5, scope_p, caller_p, &v13);
    v9 = v13;
  }
  else
  {
    v9 = scope_p->vfptr->get_topmost_scope(scope_p);
  }
  if ( v9 )
  {
    v10 = v4->i_call_p->vfptr->invoke_call(v4->i_call_p, v9, v8, v7, v6);
    if ( v4->i_receiver_p )
    {
      v11 = v9->i_ref_count-- == 1;
      if ( v11 )
      {
        v9->i_ref_count = 2147483648;
        v9->vfptr[1].get_scope_context((SSObjectBase *)&v9->vfptr);
      }
    }
    result = v10;
  }
  else
  {
    if ( v6 )
      *v6 = SSBrain::c_nil_p;
    result = 0i64;
  }
  return result;
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
  SSInvokeClosureBase *v2; // rax
  SSExpressionBase *v3; // rcx

  v2 = this;
  v3 = this->i_receiver_p;
  if ( v3 )
  {
    if ( v3 == receiver_p )
      v2->i_receiver_p = 0i64;
    else
      ((void (*)(void))v3->vfptr->null_receiver)();
  }
}

// File Line: 767
// RVA: 0x13DEC0
void __fastcall SSInvocation::track_memory(SSInvocation *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rbx
  SSInvocation *v3; // rdi
  SSExpressionBase *v4; // rcx

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSInvocation", 0x18u, 8u, 0, 0, 1u);
  v4 = v3->i_receiver_p;
  if ( v4 )
    v4->vfptr->track_memory(v4, v2);
  v3->i_call_p->vfptr->track_memory(v3->i_call_p, v2);
}

// File Line: 838
// RVA: 0x11D760
SSInvokedExpression *__fastcall SSInvokeSync::invoke(SSInvokeSync *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSInvokeSync *v4; // r13
  SSInstance **v5; // rdi
  SSInvokedBase *v6; // rsi
  SSObjectBase *v7; // r12
  SSInstance *v8; // rbx
  __int64 v9; // rax
  bool v10; // zf
  SSInvokedBase *v11; // rdi
  SSInvokedExpression *result; // rax
  unsigned int *v13; // r15
  __int64 v14; // rbp
  char v15; // r14
  SSInvokedExpression *v16; // rax
  SSInstance **v17; // rdi
  SSInvokedExpression *v18; // rsi
  unsigned __int64 i; // rbp
  __int64 v20; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v21; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v22; // rax
  SSInstance *v23; // [rsp+60h] [rbp+8h]

  v4 = this;
  v5 = result_pp;
  v6 = caller_p;
  v7 = scope_p;
  this->i_receiver_p->vfptr->invoke(this->i_receiver_p, scope_p, caller_p, &v23);
  v8 = v23;
  if ( v23 && v23 != SSBrain::c_nil_p )
  {
    if ( v23->i_class_p == SSBrain::c_list_class_p )
    {
      v13 = (unsigned int *)v23->i_user_data;
      v14 = *v13;
      if ( v5 )
      {
        ++v23->i_ref_count;
        *v5 = v8;
      }
      if ( (_DWORD)v14 )
      {
        v15 = 1;
        v16 = SSInvokedExpression::pool_new((SSExpressionBase *)&v4->vfptr, v6, v7);
        v17 = (SSInstance **)*((_QWORD *)v13 + 1);
        v18 = v16;
        for ( i = (unsigned __int64)&v17[v14]; (unsigned __int64)v17 < i; ++v17 )
        {
          v20 = (__int64)v4->i_call_p->vfptr->invoke_call(v4->i_call_p, *v17, v7, (SSInvokedBase *)&v18->vfptr, 0i64);
          if ( v20 )
          {
            v21 = (AListNode<SSInvokedBase,SSInvokedBase> *)(v20 + 16);
            v22 = v18->i_calls.i_sentinel.i_prev_p;
            v18->i_calls.i_sentinel.i_prev_p = v21;
            v22->i_next_p = v21;
            v21->i_prev_p = v22;
            v21->i_next_p = &v18->i_calls.i_sentinel;
            ++v18->i_pending_count;
            v15 = 0;
          }
        }
        v10 = v8->i_ref_count-- == 1;
        if ( v10 )
        {
          v8->i_ref_count = 2147483648;
          v8->vfptr[1].get_scope_context((SSObjectBase *)&v8->vfptr);
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
          v8->i_ref_count = 2147483648;
          v8->vfptr[1].get_scope_context((SSObjectBase *)&v8->vfptr);
        }
      }
      return 0i64;
    }
    v9 = (__int64)v4->i_call_p->vfptr->invoke_call(v4->i_call_p, v23, v7, v6, v5);
    v10 = v8->i_ref_count-- == 1;
    v11 = (SSInvokedBase *)v9;
    if ( v10 )
    {
      v8->i_ref_count = 2147483648;
      v8->vfptr[1].get_scope_context((SSObjectBase *)&v8->vfptr);
    }
    result = (SSInvokedExpression *)v11;
  }
  else
  {
    if ( v5 )
      *v5 = SSBrain::c_nil_p;
    result = 0i64;
  }
  return result;
}

// File Line: 954
// RVA: 0x13E150
void __fastcall SSInvokeSync::track_memory(SSInvokeSync *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rbx
  SSInvokeSync *v3; // rdi
  SSExpressionBase *v4; // rcx

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSInvokeSync", 0x18u, 8u, 0, 0, 1u);
  v4 = v3->i_receiver_p;
  if ( v4 )
    v4->vfptr->track_memory(v4, v2);
  v3->i_call_p->vfptr->track_memory(v3->i_call_p, v2);
}

// File Line: 1025
// RVA: 0x11D5A0
SSInvokedExpression *__fastcall SSInvokeRace::invoke(SSInvokeRace *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSInvokeRace *v4; // r15
  SSInstance **v5; // rdi
  SSInvokedBase *v6; // r13
  SSObjectBase *v7; // r14
  SSInstance *v8; // rbx
  __int64 v9; // rax
  bool v10; // zf
  SSInvokedBase *v11; // rdi
  SSInvokedExpression *result; // rax
  unsigned int *v13; // rsi
  __int64 v14; // rbp
  char v15; // r12
  SSInvokedExpression *v16; // rax
  SSInstance **v17; // rsi
  SSInvokedExpression *v18; // rdi
  unsigned __int64 v19; // rbp
  __int64 v20; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v21; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v22; // rax
  unsigned __int64 v23; // rax
  SSInstance *v24; // [rsp+60h] [rbp+8h]

  v4 = this;
  v5 = result_pp;
  v6 = caller_p;
  v7 = scope_p;
  this->i_receiver_p->vfptr->invoke(this->i_receiver_p, scope_p, caller_p, &v24);
  v8 = v24;
  if ( v24 && v24 != SSBrain::c_nil_p )
  {
    if ( v24->i_class_p == SSBrain::c_list_class_p )
    {
      v13 = (unsigned int *)v24->i_user_data;
      v14 = *v13;
      if ( v5 )
      {
        ++v24->i_ref_count;
        *v5 = v8;
      }
      if ( (_DWORD)v14 )
      {
        v15 = 0;
        v16 = SSInvokedExpression::pool_new((SSExpressionBase *)&v4->vfptr, v6, v7);
        v17 = (SSInstance **)*((_QWORD *)v13 + 1);
        v18 = v16;
        v19 = (unsigned __int64)&v17[v14];
        if ( (unsigned __int64)v17 < v19 )
        {
          while ( 1 )
          {
            v20 = (__int64)v4->i_call_p->vfptr->invoke_call(v4->i_call_p, *v17, v7, (SSInvokedBase *)&v18->vfptr, 0i64);
            if ( !v20 )
              break;
            v21 = (AListNode<SSInvokedBase,SSInvokedBase> *)(v20 + 16);
            v22 = v18->i_calls.i_sentinel.i_prev_p;
            v18->i_calls.i_sentinel.i_prev_p = v21;
            v22->i_next_p = v21;
            ++v17;
            v21->i_prev_p = v22;
            v21->i_next_p = &v18->i_calls.i_sentinel;
            ++v18->i_pending_count;
            if ( (unsigned __int64)v17 >= v19 )
              goto LABEL_19;
          }
          v15 = 1;
        }
LABEL_19:
        v10 = v8->i_ref_count-- == 1;
        if ( v10 )
        {
          v8->i_ref_count = 2147483648;
          v8->vfptr[1].get_scope_context((SSObjectBase *)&v8->vfptr);
        }
        if ( !v15 )
        {
          v23 = v18->i_pending_count;
          v18->i_pending_count = 1;
          v18->i_data = v23;
          return v18;
        }
        SSInvokedBase::abort_subcalls((SSInvokedBase *)&v18->vfptr, 0);
        SSInvokedExpression::pool_delete(v18);
      }
      else
      {
        v10 = v8->i_ref_count-- == 1;
        if ( v10 )
        {
          v8->i_ref_count = 2147483648;
          v8->vfptr[1].get_scope_context((SSObjectBase *)&v8->vfptr);
        }
      }
      return 0i64;
    }
    v9 = (__int64)v4->i_call_p->vfptr->invoke_call(v4->i_call_p, v24, v7, v6, v5);
    v10 = v8->i_ref_count-- == 1;
    v11 = (SSInvokedBase *)v9;
    if ( v10 )
    {
      v8->i_ref_count = 2147483648;
      v8->vfptr[1].get_scope_context((SSObjectBase *)&v8->vfptr);
    }
    result = (SSInvokedExpression *)v11;
  }
  else
  {
    if ( v5 )
      *v5 = SSBrain::c_nil_p;
    result = 0i64;
  }
  return result;
}

// File Line: 1184
// RVA: 0x13E0E0
void __fastcall SSInvokeRace::track_memory(SSInvokeRace *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rbx
  SSInvokeRace *v3; // rdi
  SSExpressionBase *v4; // rcx

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSInvokeRace", 0x18u, 8u, 0, 0, 1u);
  v4 = v3->i_receiver_p;
  if ( v4 )
    v4->vfptr->track_memory(v4, v2);
  v3->i_call_p->vfptr->track_memory(v3->i_call_p, v2);
}

// File Line: 1227
// RVA: 0x105430
void __fastcall SSInvokeCascade::SSInvokeCascade(SSInvokeCascade *this, const void **binary_pp)
{
  const void **v2; // rsi
  SSInvokeCascade *v3; // r12
  APArrayFree<SSInvokeBase,SSInvokeBase,ACompareAddress<SSInvokeBase> > *v4; // rdi
  eSSExprType v5; // ecx
  char *v6; // rax
  SSExpressionBase *v7; // rax
  unsigned int v8; // er15
  int v9; // ecx
  int v10; // ecx
  SSInvokeBase *v11; // rbx
  __int64 v12; // rbp
  SSInvokeBase **v13; // r14
  unsigned __int64 v14; // rax
  SSInvokeBase **v15; // rax

  v2 = binary_pp;
  v3 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSInvokeCascade::`vftable;
  v4 = &this->i_invoke_calls;
  v4->i_count = 0;
  v4->i_array_p = 0i64;
  v4->i_size = 0;
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
  v3->i_receiver_p = v7;
  v8 = *(unsigned __int8 *)*v2;
  *v2 = (char *)*v2 + 1;
  if ( v4->i_size < v8 )
  {
    v4->i_size = AMemory::c_req_byte_size_func(8 * v8) >> 3;
    AMemory::c_free_func(v4->i_array_p);
    v4->i_array_p = APArrayBase<SSInvokeBase>::alloc_array(v4->i_size);
  }
  for ( v4->i_count = 0; v8; --v8 )
  {
    v9 = *(unsigned __int8 *)*v2;
    *v2 = (char *)*v2 + 1;
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
          SSInvokeBase::assign_binary(v11, v2);
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
        SSInvokeBase::assign_binary(v11, v2);
      }
      else
      {
        v11 = 0i64;
      }
    }
    v12 = v4->i_count;
    if ( v4->i_size < (unsigned int)(v12 + 1) )
    {
      v13 = v4->i_array_p;
      if ( (_DWORD)v12 == -1 )
        LODWORD(v14) = 0;
      else
        v14 = (unsigned __int64)AMemory::c_req_byte_size_func(8 * (v12 & 0xFFFFFFFC) + 32) >> 3;
      v4->i_size = v14;
      v15 = APArrayBase<SSInvokeBase>::alloc_array(v14);
      v4->i_array_p = v15;
      memmove(v15, v13, 8 * v12);
      AMemory::c_free_func(v13);
    }
    v4->i_array_p[v12] = v11;
    ++v4->i_count;
  }
}

// File Line: 1494
// RVA: 0x11E440
char __fastcall SSInvokeCascade::invoke_iterate(SSInvokeCascade *this, SSInvokedExpression *iexpr_p, SSInstance **result_pp)
{
  SSInvokedExpression *v3; // rbx
  unsigned int v4; // edx
  SSInstance **v5; // r14
  SSObjectBase *v6; // rbp
  SSInstance *v7; // r12
  bool v8; // r13
  __int64 v9; // rdi
  SSInvokeBase **v10; // r15
  unsigned int v11; // esi
  SSInvokeBase *v12; // rcx
  __int64 v13; // rax
  bool v14; // si
  AListNode<SSInvokedBase,SSInvokedBase> *v15; // rax
  _QWORD *v16; // rcx
  char result; // al
  SSInvokedBase *v18; // rdi
  _DWORD *v19; // rcx
  bool v20; // zf
  AListNode<SSInvokedBase,SSInvokedBase> *v21; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v22; // rax

  v3 = iexpr_p;
  v4 = iexpr_p->i_index;
  v5 = result_pp;
  v6 = v3->i_scope_p.i_obj_p;
  v7 = (SSInstance *)v3->i_data;
  v8 = v4 == 0;
  v9 = 0i64;
  if ( !v6 || v3->i_scope_p.i_ptr_id != v6->i_ptr_id )
    v6 = 0i64;
  v10 = this->i_invoke_calls.i_array_p;
  v11 = this->i_invoke_calls.i_count - 1;
  if ( v4 < v11 )
  {
    do
    {
      v12 = v10[v3->i_index];
      v9 = (__int64)v12->vfptr->invoke_call(v12, v7, v6, (SSInvokedBase *)&v3->vfptr, 0i64);
      if ( v9 )
        break;
      ++v3->i_index;
    }
    while ( v3->i_index < v11 );
  }
  v13 = v3->i_index;
  v14 = (_DWORD)v13 == v11;
  if ( v14 )
    v9 = (__int64)v10[v13]->vfptr->invoke_call(v10[v13], v7, v6, (SSInvokedBase *)&v3->vfptr, v5);
  if ( v9 )
  {
    if ( v5 )
    {
      if ( !v14 )
        *v5 = (SSInstance *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 24i64))(v9);
    }
    v15 = v3->i_calls.i_sentinel.i_prev_p;
    v16 = (_QWORD *)(v9 + 16);
    v3->i_calls.i_sentinel.i_prev_p = (AListNode<SSInvokedBase,SSInvokedBase> *)(v9 + 16);
    v15->i_next_p = (AListNode<SSInvokedBase,SSInvokedBase> *)(v9 + 16);
    v16[1] = v15;
    *v16 = (char *)v3 + 64;
    ++v3->i_pending_count;
    result = 0;
  }
  else
  {
    v18 = v3->i_caller_p.i_obj_p;
    if ( !v18 || v3->i_caller_p.i_ptr_id != v18->i_ptr_id )
      v18 = 0i64;
    v19 = (_DWORD *)v3->i_data;
    if ( v19 )
    {
      v3->i_data = 0i64;
      v20 = v19[4]-- == 1;
      if ( v20 )
      {
        v19[4] = 2147483648;
        (*(void (**)(void))(*(_QWORD *)v19 + 112i64))();
      }
    }
    if ( !v8 && v18 && v18->i_pending_count )
    {
      v21 = v3->i_next_p;
      if ( v21 != (AListNode<SSInvokedBase,SSInvokedBase> *)&v3->i_next_p )
      {
        v22 = v3->i_prev_p;
        v21->i_prev_p = v22;
        v22->i_next_p = v21;
        v3->i_prev_p = (AListNode<SSInvokedBase,SSInvokedBase> *)&v3->i_next_p;
        v3->i_next_p = (AListNode<SSInvokedBase,SSInvokedBase> *)&v3->i_next_p;
      }
      LOBYTE(v21) = 1;
      v18->vfptr[1].get_data_by_name((SSObjectBase *)&v18->vfptr, (ASymbol *)v21);
    }
    SSInvokedExpression::pool_delete(v3);
    result = 1;
  }
  return result;
}

// File Line: 1594
// RVA: 0x11D410
SSInvokedExpression *__fastcall SSInvokeCascade::invoke(SSInvokeCascade *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSInvokedBase *v4; // rbp
  SSObjectBase *v5; // rdi
  SSInstance **v6; // r14
  SSInvokeCascade *v7; // rsi
  SSInvokedExpression *v8; // rax
  SSExpressionBase *v9; // rcx
  SSInvokedExpression *v10; // rbx
  __int64 v11; // rax
  __int64 v13; // [rsp+40h] [rbp+8h]

  v4 = caller_p;
  v5 = scope_p;
  v6 = result_pp;
  v7 = this;
  v8 = SSInvokedExpression::pool_new((SSExpressionBase *)&this->vfptr, caller_p, scope_p);
  v9 = v7->i_receiver_p;
  v10 = v8;
  if ( v9 )
  {
    v9->vfptr->invoke(v9, v5, v4, (SSInstance **)&v13);
    v11 = v13;
  }
  else
  {
    v11 = (__int64)v5->vfptr->get_topmost_scope(v5);
    ++*(_DWORD *)(v11 + 16);
  }
  v10->i_data = v11;
  if ( v7->vfptr->invoke_iterate((SSExpressionBase *)&v7->vfptr, v10, v6) )
    v10 = 0i64;
  return v10;
}

// File Line: 1650
// RVA: 0x11EFB0
char __fastcall SSInvokeCascade::is_immediate(SSInvokeCascade *this, unsigned int *durational_idx_p)
{
  SSInvokeBase **v2; // rbx
  unsigned __int64 v3; // rdi

  v2 = this->i_invoke_calls.i_array_p;
  v3 = (unsigned __int64)&v2[this->i_invoke_calls.i_count];
  if ( (unsigned __int64)v2 >= v3 )
    return 1;
  while ( ((unsigned int (__fastcall *)(SSInvokeBase *, unsigned int *))(*v2)->vfptr->get_invoke_type)(
            *v2,
            durational_idx_p) == 1 )
  {
    ++v2;
    if ( (unsigned __int64)v2 >= v3 )
      return 1;
  }
  return 0;
}

// File Line: 1690
// RVA: 0x11E240
void __fastcall SSInvokeCascade::invoke_exit(SSInvokeCascade *this, SSInvokedExpression *iexpr_p, SSInvokedExpression *sub_exit_p)
{
  iexpr_p->i_index = this->i_invoke_calls.i_count;
}

// File Line: 1727
// RVA: 0x13DF30
void __fastcall SSInvokeCascade::track_memory(SSInvokeCascade *this, AMemoryStats *mem_stats_p)
{
  SSInvokeBase **v2; // rbx
  AMemoryStats *v3; // rsi
  unsigned __int64 v4; // rdi
  SSInvokeCascade *i; // rbp
  SSExpressionBase *v6; // rcx

  v2 = this->i_invoke_calls.i_array_p;
  v3 = mem_stats_p;
  v4 = (unsigned __int64)&v2[this->i_invoke_calls.i_count];
  for ( i = this; (unsigned __int64)v2 < v4; ++v2 )
  {
    if ( *v2 )
      (*v2)->vfptr->track_memory(*v2, v3);
  }
  AMemoryStats::track_memory(
    v3,
    "SSInvokeCascade",
    0x28u,
    8u,
    8 * i->i_invoke_calls.i_count,
    8 * i->i_invoke_calls.i_size,
    1u);
  v6 = i->i_receiver_p;
  if ( v6 )
    v6->vfptr->track_memory(v6, v3);
}

// File Line: 1770
// RVA: 0x1052C0
void __fastcall SSInstantiate::SSInstantiate(SSInstantiate *this, const void **binary_pp)
{
  const void **v2; // rdi
  SSInstantiate *v3; // rbx
  ASymbol *v4; // rax
  SSMethodCall *v5; // rax
  ASymbol result; // [rsp+50h] [rbp+18h]

  v2 = binary_pp;
  v3 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSInstantiate::`vftable;
  v4 = ASymbol::create_from_binary(&result, binary_pp);
  v3->i_class_p = SSBrain::get_class(v4);
  v5 = (SSMethodCall *)AMemory::c_malloc_func(0x38ui64, "SSMethodCall");
  *(_QWORD *)&result.i_uid = v5;
  if ( v5 )
    SSMethodCall::SSMethodCall(v5, v2);
  v3->i_ctor_p = v5;
}

// File Line: 1938
// RVA: 0x11D2C0
SSInvokedBase *__fastcall SSInstantiate::invoke(SSInstantiate *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSInstantiate *v4; // rbx
  SSInstance **v5; // r15
  SSInvokedBase *v6; // rdi
  SSObjectBase *v7; // rsi
  SSInstance *v8; // r14
  bool v9; // zf

  v4 = this;
  v5 = result_pp;
  v6 = caller_p;
  v7 = scope_p;
  v8 = (SSInstance *)((__int64 (*)(void))this->i_class_p->vfptr[1].get_key_class)();
  v4->i_ctor_p->vfptr->invoke_call((SSInvokeBase *)&v4->i_ctor_p->vfptr, v8, v7, v6, 0i64);
  if ( v5 )
  {
    *v5 = v8;
  }
  else
  {
    v9 = v8->i_ref_count-- == 1;
    if ( v9 )
    {
      v8->i_ref_count = 2147483648;
      v8->vfptr[1].get_scope_context((SSObjectBase *)&v8->vfptr);
    }
  }
  return 0i64;
}

// File Line: 1973
// RVA: 0x13DE60
void __fastcall SSInstantiate::track_memory(SSInstantiate *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rdi
  SSInstantiate *v3; // rbx

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSInstantiate", 0x18u, 8u, 0, 0, 1u);
  v3->i_ctor_p->vfptr->track_memory((SSInvokeBase *)&v3->i_ctor_p->vfptr, v2);
}


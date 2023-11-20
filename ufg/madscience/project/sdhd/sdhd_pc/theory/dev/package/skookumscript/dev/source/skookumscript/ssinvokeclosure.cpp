// File Line: 42
// RVA: 0x107230
void __fastcall SSInvokeClosureBase::~SSInvokeClosureBase(SSInvokeClosureBase *this)
{
  SSInvokeClosureBase *v1; // rbx
  SSExpressionBase *v2; // rcx

  v1 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSInvokeClosureBase::`vftable';
  v2 = this->i_receiver_p;
  if ( v2 )
    v2->vfptr->__vecDelDtor(v2, 1u);
  APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)&v1->i_arguments);
  APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)&v1->i_return_args);
  AMemory::c_free_func(v1->i_return_args.i_array_p);
  AMemory::c_free_func(v1->i_arguments.i_array_p);
  v1->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
}

// File Line: 68
// RVA: 0x105680
void __fastcall SSInvokeClosureBase::SSInvokeClosureBase(SSInvokeClosureBase *this, const void **binary_pp)
{
  const void **v2; // rbx
  SSInvokeClosureBase *v3; // rsi
  eSSExprType v4; // ecx
  char *v5; // rax
  SSExpressionBase *v6; // rax
  unsigned __int8 v7; // bp
  SSExpressionBase **v8; // rcx
  SSExpressionBase **v9; // rdi
  unsigned __int64 i; // rbp
  eSSExprType v11; // ecx
  signed __int64 v12; // rax
  SSExpressionBase *v13; // rax
  unsigned __int8 v14; // bp
  SSIdentifier **v15; // rcx
  _QWORD *v16; // rdi
  unsigned __int64 j; // rbp
  eSSExprType v18; // ecx
  signed __int64 v19; // rax
  SSExpressionBase *v20; // rax

  v2 = binary_pp;
  v3 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSInvokeClosureBase::`vftable';
  this->i_arguments.i_count = 0;
  this->i_arguments.i_array_p = 0i64;
  this->i_return_args.i_count = 0;
  this->i_return_args.i_array_p = 0i64;
  v4 = *(unsigned __int8 *)*binary_pp;
  v5 = (char *)*binary_pp + 1;
  *binary_pp = v5;
  if ( v4 )
  {
    *binary_pp = v5 + 2;
    v6 = SSExpressionBase::from_binary_new(v4, binary_pp);
  }
  else
  {
    v6 = 0i64;
  }
  v3->i_receiver_p = v6;
  v7 = *(_BYTE *)*v2;
  *v2 = (char *)*v2 + 1;
  if ( v7 )
  {
    if ( v3->i_arguments.i_count != v7 )
    {
      v3->i_arguments.i_count = v7;
      v8 = v3->i_arguments.i_array_p;
      if ( v8 )
        AMemory::c_free_func(v8);
      v3->i_arguments.i_array_p = APArrayBase<SSExpressionBase>::alloc_array(v7);
    }
    v9 = v3->i_arguments.i_array_p;
    for ( i = (unsigned __int64)&v9[v7]; (unsigned __int64)v9 < i; ++v9 )
    {
      v11 = *(unsigned __int8 *)*v2;
      v12 = (signed __int64)*v2 + 1;
      *v2 = (const void *)v12;
      if ( v11 )
      {
        *v2 = (const void *)(v12 + 2);
        v13 = SSExpressionBase::from_binary_new(v11, v2);
      }
      else
      {
        v13 = 0i64;
      }
      *v9 = v13;
    }
  }
  v14 = *(_BYTE *)*v2;
  *v2 = (char *)*v2 + 1;
  if ( v14 )
  {
    if ( v3->i_return_args.i_count != v14 )
    {
      v3->i_return_args.i_count = v14;
      v15 = v3->i_return_args.i_array_p;
      if ( v15 )
        AMemory::c_free_func(v15);
      v3->i_return_args.i_array_p = APArrayBase<SSIdentifier>::alloc_array(v14);
    }
    v16 = v3->i_return_args.i_array_p;
    for ( j = (unsigned __int64)&v16[v14]; (unsigned __int64)v16 < j; ++v16 )
    {
      v18 = *(unsigned __int8 *)*v2;
      v19 = (signed __int64)*v2 + 1;
      *v2 = (const void *)v19;
      if ( v18 )
      {
        *v2 = (const void *)(v19 + 2);
        v20 = SSExpressionBase::from_binary_new(v18, v2);
      }
      else
      {
        v20 = 0i64;
      }
      *v16 = v20;
    }
  }
}

// File Line: 444
// RVA: 0x13DFE0
void __fastcall SSInvokeClosureBase::track_memory(SSInvokeClosureBase *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase **v2; // rbx
  AMemoryStats *v3; // rsi
  unsigned __int64 v4; // rdi
  SSInvokeClosureBase *i; // r14
  SSIdentifier **v6; // rbx
  unsigned __int64 v7; // rdi
  int j; // ebp
  unsigned int v9; // edx
  unsigned int size_dynamic; // ebx
  unsigned int size_dynamic_needed; // edi
  eSSExprType v12; // eax
  const char *v13; // rdx
  SSExpressionBase *v14; // rcx

  v2 = this->i_arguments.i_array_p;
  v3 = mem_stats_p;
  v4 = (unsigned __int64)&v2[this->i_arguments.i_count];
  for ( i = this; (unsigned __int64)v2 < v4; ++v2 )
  {
    if ( *v2 )
      (*v2)->vfptr->track_memory(*v2, v3);
  }
  v6 = i->i_return_args.i_array_p;
  v7 = (unsigned __int64)&v6[i->i_return_args.i_count];
  for ( j = 8 * i->i_arguments.i_count; (unsigned __int64)v6 < v7; ++v6 )
  {
    if ( *v6 )
      (*v6)->vfptr->track_memory((SSExpressionBase *)&(*v6)->vfptr, v3);
  }
  v9 = i->i_return_args.i_count;
  size_dynamic = j + 8 * v9;
  size_dynamic_needed = 8 * (v9 + i->i_arguments.i_count);
  v12 = (unsigned int)i->vfptr->get_type((SSExpressionBase *)&i->vfptr);
  v13 = "SSInvokeClosureCoroutine";
  if ( v12 == 22 )
    v13 = "SSInvokeClosureMethod";
  AMemoryStats::track_memory(v3, v13, 0x28u, 8u, size_dynamic_needed, size_dynamic, 1u);
  v14 = i->i_receiver_p;
  if ( v14 )
    v14->vfptr->track_memory(v14, v3);
}

// File Line: 603
// RVA: 0x11D4A0
SSInvokedBase *__fastcall SSInvokeClosureCoroutine::invoke(SSInvokeClosureMethod *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSInvokeClosureMethod *v4; // r15
  SSExpressionBase *v5; // rcx
  SSInstance **v6; // r13
  SSInvokedBase *v7; // r14
  SSObjectBase *v8; // rsi
  SSInstance *v9; // rdi
  SSInvokableBase *v10; // rbx
  SSInvokableBase *v11; // rbp
  SSMethodBase *v12; // r8
  SSInvokedMethod *v13; // rax
  SSInvokedMethod *v14; // r12
  bool v15; // zf
  SSObjectBase *scope_pa; // [rsp+50h] [rbp+8h]

  v4 = this;
  v5 = this->i_receiver_p;
  v6 = result_pp;
  v7 = caller_p;
  v8 = scope_p;
  if ( v5 )
  {
    v5->vfptr->invoke(v5, scope_p, caller_p, (SSInstance **)&scope_pa);
    v9 = (SSInstance *)scope_pa;
  }
  else
  {
    v9 = scope_p->vfptr->get_topmost_scope(scope_p);
  }
  v10 = (SSInvokableBase *)v9->i_user_data;
  v11 = 0i64;
  v12 = (SSMethodBase *)&v10[1];
  if ( !v10 )
    v12 = 0i64;
  v13 = SSInvokedMethod::pool_new(v7, (SSObjectBase *)&v9->vfptr, v12);
  v14 = v13;
  if ( v10 )
    v11 = v10 + 1;
  SSInvokedContextBase::data_append_args_exprs(
    (SSInvokedContextBase *)&v13->vfptr,
    (APArrayBase<SSExpressionBase> *)&v4->i_arguments.i_count,
    v11,
    v8);
  ((void (__fastcall *)(SSInvokableBase *, SSInvokedMethod *, SSInvokedBase *, SSInstance **))v10[1].vfptr[1].get_custom_expr)(
    &v10[1],
    v14,
    v7,
    v6);
  SSInvokedContextBase::data_bind_return_args(
    (SSInvokedContextBase *)&v14->vfptr,
    (APArrayBase<SSIdentifier> *)&v4->i_return_args.i_count,
    v10 + 1);
  SSInvokedMethod::pool_delete(v14);
  if ( v4->i_receiver_p )
  {
    v15 = v9->i_ref_count-- == 1;
    if ( v15 )
    {
      v9->i_ref_count = 2147483648;
      v9->vfptr[1].get_scope_context((SSObjectBase *)&v9->vfptr);
    }
  }
  return 0i64;
}


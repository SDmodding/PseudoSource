// File Line: 42
// RVA: 0x107230
void __fastcall SSInvokeClosureBase::~SSInvokeClosureBase(SSInvokeClosureBase *this)
{
  SSExpressionBase *i_receiver_p; // rcx

  this->vfptr = (SSExpressionBaseVtbl *)&SSInvokeClosureBase::`vftable;
  i_receiver_p = this->i_receiver_p;
  if ( i_receiver_p )
    i_receiver_p->vfptr->__vecDelDtor(i_receiver_p, 1u);
  APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)&this->i_arguments);
  APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)&this->i_return_args);
  AMemory::c_free_func(this->i_return_args.i_array_p);
  AMemory::c_free_func(this->i_arguments.i_array_p);
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
}

// File Line: 68
// RVA: 0x105680
void __fastcall SSInvokeClosureBase::SSInvokeClosureBase(SSInvokeClosureBase *this, const void **binary_pp)
{
  eSSExprType v4; // ecx
  char *v5; // rax
  SSExpressionBase *v6; // rax
  unsigned __int8 v7; // bp
  SSExpressionBase **i_array_p; // rcx
  SSExpressionBase **v9; // rdi
  SSExpressionBase **i; // rbp
  eSSExprType v11; // ecx
  char *v12; // rax
  SSExpressionBase *v13; // rax
  unsigned __int8 v14; // bp
  SSIdentifier **v15; // rcx
  SSIdentifier **v16; // rdi
  SSIdentifier **j; // rbp
  eSSExprType v18; // ecx
  char *v19; // rax
  SSExpressionBase *v20; // rax

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSInvokeClosureBase::`vftable;
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
  this->i_receiver_p = v6;
  v7 = *(_BYTE *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  if ( v7 )
  {
    if ( this->i_arguments.i_count != v7 )
    {
      this->i_arguments.i_count = v7;
      i_array_p = this->i_arguments.i_array_p;
      if ( i_array_p )
        AMemory::c_free_func(i_array_p);
      this->i_arguments.i_array_p = APArrayBase<SSExpressionBase>::alloc_array(v7);
    }
    v9 = this->i_arguments.i_array_p;
    for ( i = &v9[v7]; v9 < i; ++v9 )
    {
      v11 = *(unsigned __int8 *)*binary_pp;
      v12 = (char *)*binary_pp + 1;
      *binary_pp = v12;
      if ( v11 )
      {
        *binary_pp = v12 + 2;
        v13 = SSExpressionBase::from_binary_new(v11, binary_pp);
      }
      else
      {
        v13 = 0i64;
      }
      *v9 = v13;
    }
  }
  v14 = *(_BYTE *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  if ( v14 )
  {
    if ( this->i_return_args.i_count != v14 )
    {
      this->i_return_args.i_count = v14;
      v15 = this->i_return_args.i_array_p;
      if ( v15 )
        AMemory::c_free_func(v15);
      this->i_return_args.i_array_p = APArrayBase<SSIdentifier>::alloc_array(v14);
    }
    v16 = this->i_return_args.i_array_p;
    for ( j = &v16[v14]; v16 < j; ++v16 )
    {
      v18 = *(unsigned __int8 *)*binary_pp;
      v19 = (char *)*binary_pp + 1;
      *binary_pp = v19;
      if ( v18 )
      {
        *binary_pp = v19 + 2;
        v20 = SSExpressionBase::from_binary_new(v18, binary_pp);
      }
      else
      {
        v20 = 0i64;
      }
      *v16 = (SSIdentifier *)v20;
    }
  }
}

// File Line: 444
// RVA: 0x13DFE0
void __fastcall SSInvokeClosureBase::track_memory(SSInvokeClosureBase *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase **i_array_p; // rbx
  SSExpressionBase **i; // rdi
  SSIdentifier **v6; // rbx
  SSIdentifier **v7; // rdi
  unsigned int j; // ebp
  unsigned int i_count; // edx
  unsigned int size_dynamic; // ebx
  unsigned int size_dynamic_needed; // edi
  eSSExprType v12; // eax
  const char *v13; // rdx
  SSExpressionBase *i_receiver_p; // rcx

  i_array_p = this->i_arguments.i_array_p;
  for ( i = &i_array_p[this->i_arguments.i_count]; i_array_p < i; ++i_array_p )
  {
    if ( *i_array_p )
      (*i_array_p)->vfptr->track_memory(*i_array_p, mem_stats_p);
  }
  v6 = this->i_return_args.i_array_p;
  v7 = &v6[this->i_return_args.i_count];
  for ( j = 8 * this->i_arguments.i_count; v6 < v7; ++v6 )
  {
    if ( *v6 )
      (*v6)->vfptr->track_memory(*v6, mem_stats_p);
  }
  i_count = this->i_return_args.i_count;
  size_dynamic = j + 8 * i_count;
  size_dynamic_needed = 8 * (i_count + this->i_arguments.i_count);
  v12 = this->vfptr->get_type(this);
  v13 = "SSInvokeClosureCoroutine";
  if ( v12 == SSExprType_invoke_closure_method )
    v13 = "SSInvokeClosureMethod";
  AMemoryStats::track_memory(mem_stats_p, v13, 0x28u, 8u, size_dynamic_needed, size_dynamic, 1u);
  i_receiver_p = this->i_receiver_p;
  if ( i_receiver_p )
    i_receiver_p->vfptr->track_memory(i_receiver_p, mem_stats_p);
}

// File Line: 603
// RVA: 0x11D4A0
SSInvokedBase *__fastcall SSInvokeClosureCoroutine::invoke(
        SSInvokeClosureMethod *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSExpressionBase *i_receiver_p; // rcx
  SSInstance *v9; // rdi
  SSInvokableBase *i_user_data; // rbx
  SSInvokableBase *v11; // rbp
  SSMethodBase *v12; // r8
  SSInvokedMethod *v13; // rax
  SSInvokedMethod *v14; // r12
  SSObjectBase *scope_pa; // [rsp+50h] [rbp+8h] BYREF

  i_receiver_p = this->i_receiver_p;
  if ( i_receiver_p )
  {
    i_receiver_p->vfptr->invoke(i_receiver_p, scope_p, caller_p, (SSInstance **)&scope_pa);
    v9 = (SSInstance *)scope_pa;
  }
  else
  {
    v9 = scope_p->vfptr->get_topmost_scope(scope_p);
  }
  i_user_data = (SSInvokableBase *)v9->i_user_data;
  v11 = 0i64;
  v12 = (SSMethodBase *)&i_user_data[1];
  if ( !i_user_data )
    v12 = 0i64;
  v13 = SSInvokedMethod::pool_new(caller_p, v9, v12);
  v14 = v13;
  if ( i_user_data )
    v11 = i_user_data + 1;
  SSInvokedContextBase::data_append_args_exprs(v13, &this->i_arguments, v11, scope_p);
  ((void (__fastcall *)(SSInvokableBase *, SSInvokedMethod *, SSInvokedBase *, SSInstance **))i_user_data[1].vfptr[1].get_custom_expr)(
    &i_user_data[1],
    v14,
    caller_p,
    result_pp);
  SSInvokedContextBase::data_bind_return_args(v14, &this->i_return_args, i_user_data + 1);
  SSInvokedMethod::pool_delete(v14);
  if ( this->i_receiver_p )
  {
    if ( v9->i_ref_count-- == 1 )
    {
      v9->i_ref_count = 0x80000000;
      v9->vfptr[1].get_scope_context(v9);
    }
  }
  return 0i64;
}


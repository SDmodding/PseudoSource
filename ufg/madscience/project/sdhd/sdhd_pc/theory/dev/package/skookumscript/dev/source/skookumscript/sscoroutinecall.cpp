// File Line: 75
// RVA: 0x11E020
SSInvokedCoroutine *__fastcall SSCoroutineCall::invoke_call(SSCoroutineCall *this, SSInstance *receiver_p, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSObjectBase *v5; // rdi
  SSCoroutineCall *v6; // rbx
  SSInvokedCoroutine *v7; // rsi

  v5 = scope_p;
  v6 = this;
  v7 = SSInvokedCoroutine::pool_new(this, 0.0, caller_p, receiver_p, 0i64);
  SSInvokedContextBase::data_append_args_exprs(
    (SSInvokedContextBase *)&v7->vfptr,
    (APArrayBase<SSExpressionBase> *)&v6->i_arguments.i_count,
    (SSInvokableBase *)&v7->i_coroutine_p->vfptr,
    v5);
  if ( result_pp )
    *result_pp = v7->vfptr->as_instance((SSObjectBase *)&v7->vfptr);
  if ( SSInvokedCoroutine::on_update(v7) )
    v7 = 0i64;
  return v7;
}

// File Line: 111
// RVA: 0x13DAA0
void __fastcall SSCoroutineCall::track_memory(SSCoroutineCall *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase **v2; // rbx
  AMemoryStats *v3; // rsi
  unsigned __int64 v4; // rdi
  SSCoroutineCall *i; // rbp
  SSIdentifier **v6; // rbx
  unsigned __int64 v7; // rdi
  int j; // er14

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
  AMemoryStats::track_memory(
    v3,
    "SSCoroutineCall",
    0x38u,
    0,
    8 * (i->i_return_args.i_count + i->i_arguments.i_count),
    j + 8 * i->i_return_args.i_count,
    1u);
}


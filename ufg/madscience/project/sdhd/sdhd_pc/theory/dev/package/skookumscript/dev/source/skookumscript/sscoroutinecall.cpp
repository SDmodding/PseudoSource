// File Line: 75
// RVA: 0x11E020
SSInvokedCoroutine *__fastcall SSCoroutineCall::invoke_call(
        SSCoroutineCall *this,
        SSInstance *receiver_p,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSInvokedCoroutine *v7; // rsi

  v7 = SSInvokedCoroutine::pool_new(this, 0.0, caller_p, receiver_p, 0i64);
  SSInvokedContextBase::data_append_args_exprs(v7, &this->i_arguments, v7->i_coroutine_p, scope_p);
  if ( result_pp )
    *result_pp = v7->vfptr->as_instance(v7);
  if ( SSInvokedCoroutine::on_update(v7) )
    return 0i64;
  return v7;
}

// File Line: 111
// RVA: 0x13DAA0
void __fastcall SSCoroutineCall::track_memory(SSCoroutineCall *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase **i_array_p; // rbx
  SSExpressionBase **i; // rdi
  SSIdentifier **v6; // rbx
  SSIdentifier **v7; // rdi
  unsigned int j; // r14d

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
  AMemoryStats::track_memory(
    mem_stats_p,
    "SSCoroutineCall",
    0x38u,
    0,
    8 * (this->i_return_args.i_count + this->i_arguments.i_count),
    j + 8 * this->i_return_args.i_count,
    1u);
}


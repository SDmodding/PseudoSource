// File Line: 65
// RVA: 0x11E0B0
SSInvokedBase *__fastcall SSMethodCall::invoke_call(
        SSMethodCall *this,
        SSInstance *receiver_p,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  ((void (__fastcall *)(SSInstance *, SSMethodCall *, SSObjectBase *, SSInvokedBase *, SSInstance **))receiver_p->vfptr[1].get_data_by_name)(
    receiver_p,
    this,
    scope_p,
    caller_p,
    result_pp);
  return 0i64;
}

// File Line: 79
// RVA: 0x13E550
void __fastcall SSMethodCall::track_memory(SSMethodCall *this, AMemoryStats *mem_stats_p)
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
    "SSMethodCall",
    0x38u,
    0,
    8 * (this->i_return_args.i_count + this->i_arguments.i_count),
    j + 8 * this->i_return_args.i_count,
    1u);
}


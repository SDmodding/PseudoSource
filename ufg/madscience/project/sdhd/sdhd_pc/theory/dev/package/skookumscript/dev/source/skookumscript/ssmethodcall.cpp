// File Line: 65
// RVA: 0x11E0B0
SSInvokedBase *__fastcall SSMethodCall::invoke_call(SSMethodCall *this, SSInstance *receiver_p, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
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
  SSExpressionBase **v2; // rbx
  AMemoryStats *v3; // rsi
  unsigned __int64 v4; // rdi
  SSMethodCall *i; // rbp
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
    "SSMethodCall",
    0x38u,
    0,
    8 * (i->i_return_args.i_count + i->i_arguments.i_count),
    j + 8 * i->i_return_args.i_count,
    1u);
}


// File Line: 104
// RVA: 0x1307D0
void __fastcall SSInvokedCoroutine::pool_delete(SSInvokedCoroutine *icoroutine_p)
{
  unsigned int v1; // eax
  SSInvokedCoroutine *v2; // rdi
  SSActor *v3; // rbx
  AList<SSInvokedBase,SSInvokedBase> *v4; // rdx
  AList<SSInvokedBase,SSInvokedBase> *v5; // rcx
  AList<SSInvokedBase,SSInvokedBase> *v6; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v7; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v8; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v9; // rdx
  SSObjectBase *v10; // rcx
  bool v11; // zf
  AObjReusePool<SSInvokedCoroutine> *v12; // rax
  AObjBlock<SSInvokedCoroutine> *v13; // rcx
  unsigned __int64 v14; // rdx
  bool v15; // cf
  APArray<SSInvokedCoroutine,SSInvokedCoroutine,ACompareAddress<SSInvokedCoroutine> > *v16; // rcx

  v1 = icoroutine_p->i_ptr_id;
  v2 = icoroutine_p;
  if ( v1 && v1 <= SSObjectBase::c_ptr_id_prev )
  {
    if ( icoroutine_p->i_flags & 3 )
    {
      v3 = icoroutine_p->i_updater_p.i_obj_p;
      if ( v3 )
      {
        if ( icoroutine_p->i_updater_p.i_ptr_id == v3->i_ptr_id )
        {
          SSActor::coroutine_track_updating_stop(icoroutine_p->i_updater_p.i_obj_p, icoroutine_p);
          SSActor::coroutine_track_pending_stop(v3, v2);
        }
      }
    }
    SSData::empty_table((APSortedLogical<SSData,ASymbol> *)&v2->i_data);
    AMemory::c_free_func(v2->i_data.i_array_p);
    v4 = &v2->i_calls;
    v2->i_data.i_array_p = 0i64;
    v2->i_data.i_count = 0;
    v2->i_data.i_size = 0;
    v5 = (AList<SSInvokedBase,SSInvokedBase> *)v2->i_calls.i_sentinel.i_next_p;
    if ( v5 != &v2->i_calls )
    {
      do
      {
        v6 = v5;
        v5 = (AList<SSInvokedBase,SSInvokedBase> *)v5->i_sentinel.i_next_p;
        v6->i_sentinel.i_next_p = &v6->i_sentinel;
        v6->i_sentinel.i_prev_p = &v6->i_sentinel;
      }
      while ( v5 != v4 );
      v4->i_sentinel.i_next_p = &v4->i_sentinel;
      v2->i_calls.i_sentinel.i_prev_p = &v2->i_calls.i_sentinel;
    }
    v7 = v2->i_next_p;
    v8 = v2->i_prev_p;
    v9 = (AListNode<SSInvokedBase,SSInvokedBase> *)&v2->i_next_p;
    v7->i_prev_p = v8;
    v8->i_next_p = v7;
    v9->i_prev_p = v9;
    v9->i_next_p = v9;
    v2->i_ptr_id = 0;
    v10 = v2->i_scope_p.i_obj_p;
    if ( v10 )
    {
      if ( v2->i_scope_p.i_ptr_id == v10->i_ptr_id )
      {
        v11 = LODWORD(v10[1].vfptr)-- == 1;
        if ( v11 )
        {
          LODWORD(v10[1].vfptr) = 2147483648;
          ((void (*)(void))v10->vfptr[1].get_scope_context)();
        }
      }
    }
    v12 = SSInvokedCoroutine::get_pool();
    v13 = v12->i_block_p;
    v14 = (unsigned __int64)v13->i_objects_a;
    if ( (unsigned __int64)v2 < v14
      || (v15 = (unsigned __int64)v2 < v14 + 168i64 * v13->i_size, v16 = &v12->i_pool, !v15) )
    {
      v16 = &v12->i_exp_pool;
    }
    APArray<SSInvokedCoroutine,SSInvokedCoroutine,ACompareAddress<SSInvokedCoroutine>>::append(v16, v2);
  }
}


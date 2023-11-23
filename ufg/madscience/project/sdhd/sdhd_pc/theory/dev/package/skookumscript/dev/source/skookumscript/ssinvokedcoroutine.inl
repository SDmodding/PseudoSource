// File Line: 104
// RVA: 0x1307D0
void __fastcall SSInvokedCoroutine::pool_delete(SSInvokedCoroutine *icoroutine_p)
{
  unsigned int i_ptr_id; // eax
  SSActor *i_obj_p; // rbx
  AList<SSInvokedBase,SSInvokedBase> *p_i_calls; // rdx
  SSInvokedCoroutine *i_next_p; // rcx
  SSInvokedCoroutine *v6; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v7; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax
  SSObjectBase *v9; // rcx
  AObjReusePool<SSInvokedCoroutine> *pool; // rax
  AObjBlock<SSInvokedCoroutine> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v14; // cf
  APArray<SSInvokedCoroutine,SSInvokedCoroutine,ACompareAddress<SSInvokedCoroutine> > *p_i_exp_pool; // rcx

  i_ptr_id = icoroutine_p->i_ptr_id;
  if ( i_ptr_id && i_ptr_id <= SSObjectBase::c_ptr_id_prev )
  {
    if ( (icoroutine_p->i_flags & 3) != 0 )
    {
      i_obj_p = icoroutine_p->i_updater_p.i_obj_p;
      if ( i_obj_p )
      {
        if ( icoroutine_p->i_updater_p.i_ptr_id == i_obj_p->i_ptr_id )
        {
          SSActor::coroutine_track_updating_stop(icoroutine_p->i_updater_p.i_obj_p, icoroutine_p);
          SSActor::coroutine_track_pending_stop(i_obj_p, icoroutine_p);
        }
      }
    }
    SSData::empty_table((APSortedLogical<SSData,ASymbol> *)&icoroutine_p->i_data);
    AMemory::c_free_func(icoroutine_p->i_data.i_array_p);
    p_i_calls = &icoroutine_p->i_calls;
    icoroutine_p->i_data.i_array_p = 0i64;
    icoroutine_p->i_data.i_count = 0;
    icoroutine_p->i_data.i_size = 0;
    i_next_p = (SSInvokedCoroutine *)icoroutine_p->i_calls.i_sentinel.SSInvokedContextBase::SSInvokedBase::i_next_p;
    if ( i_next_p != (SSInvokedCoroutine *)&icoroutine_p->i_calls )
    {
      do
      {
        v6 = i_next_p;
        i_next_p = (SSInvokedCoroutine *)i_next_p->vfptr;
        v6->vfptr = (SSObjectBaseVtbl *)v6;
        *(_QWORD *)&v6->i_ptr_id = v6;
      }
      while ( i_next_p != (SSInvokedCoroutine *)p_i_calls );
      p_i_calls->i_sentinel.i_next_p = &p_i_calls->i_sentinel;
      icoroutine_p->i_calls.i_sentinel.i_prev_p = &icoroutine_p->i_calls.i_sentinel;
    }
    v7 = icoroutine_p->i_next_p;
    i_prev_p = icoroutine_p->i_prev_p;
    v7->i_prev_p = i_prev_p;
    i_prev_p->i_next_p = v7;
    icoroutine_p->i_prev_p = &icoroutine_p->AListNode<SSInvokedBase,SSInvokedBase>;
    icoroutine_p->i_next_p = &icoroutine_p->AListNode<SSInvokedBase,SSInvokedBase>;
    icoroutine_p->i_ptr_id = 0;
    v9 = icoroutine_p->i_scope_p.i_obj_p;
    if ( v9 )
    {
      if ( icoroutine_p->i_scope_p.i_ptr_id == v9->i_ptr_id && LODWORD(v9[1].vfptr)-- == 1 )
      {
        LODWORD(v9[1].vfptr) = 0x80000000;
        v9->vfptr[1].get_scope_context(v9);
      }
    }
    pool = SSInvokedCoroutine::get_pool();
    i_block_p = pool->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)icoroutine_p < i_objects_a
      || (v14 = (unsigned __int64)icoroutine_p < i_objects_a + 168i64 * i_block_p->i_size,
          p_i_exp_pool = &pool->i_pool,
          !v14) )
    {
      p_i_exp_pool = &pool->i_exp_pool;
    }
    APArray<SSInvokedCoroutine,SSInvokedCoroutine,ACompareAddress<SSInvokedCoroutine>>::append(
      p_i_exp_pool,
      icoroutine_p);
  }
}


// File Line: 44
// RVA: 0x131090
SSInvokedMethod *__fastcall SSInvokedMethod::pool_new(
        SSInvokedBase *caller_p,
        SSObjectBase *scope_p,
        SSMethodBase *method_p)
{
  unsigned int v6; // edi
  AObjReusePool<SSInvokedMethod> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v9; // eax
  __int64 v10; // rcx
  SSInvokedMethod **i_array_p; // rax
  SSInvokedMethod *result; // rax
  unsigned int v13; // eax
  unsigned int i_ptr_id; // ecx

  v6 = 0;
  pool = SSInvokedMethod::get_pool();
  if ( pool->i_pool.i_count )
  {
    v13 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v13;
    v10 = v13;
    i_array_p = pool->i_pool.i_array_p;
  }
  else
  {
    if ( !pool->i_exp_pool.i_count )
      AObjReusePool<SSInvokedMethod>::append_block(pool, pool->i_expand_size);
    i_count = pool->i_exp_pool.i_count;
    if ( !i_count )
    {
      result = 0i64;
      goto LABEL_9;
    }
    v9 = i_count - 1;
    pool->i_exp_pool.i_count = v9;
    v10 = v9;
    i_array_p = pool->i_exp_pool.i_array_p;
  }
  result = i_array_p[v10];
LABEL_9:
  result->i_caller_p.i_obj_p = caller_p;
  if ( caller_p )
    i_ptr_id = caller_p->i_ptr_id;
  else
    i_ptr_id = 0;
  result->i_caller_p.i_ptr_id = i_ptr_id;
  result->i_scope_p.i_obj_p = scope_p;
  if ( scope_p )
    v6 = scope_p->i_ptr_id;
  result->i_scope_p.i_ptr_id = v6;
  result->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  result->i_method_p = method_p;
  return result;
}

// File Line: 64
// RVA: 0x130980
void __fastcall SSInvokedMethod::pool_delete(SSInvokedMethod *imethod_p)
{
  AList<SSInvokedBase,SSInvokedBase> *p_i_calls; // rdx
  SSInvokedMethod *i_next_p; // rax
  SSInvokedMethod *v4; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v5; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax
  AObjReusePool<SSInvokedMethod> *pool; // rax
  AObjBlock<SSInvokedMethod> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v10; // cf
  APArray<SSInvokedMethod,SSInvokedMethod,ACompareAddress<SSInvokedMethod> > *p_i_exp_pool; // rcx

  SSData::empty_table((APSortedLogical<SSData,ASymbol> *)&imethod_p->i_data);
  AMemory::c_free_func(imethod_p->i_data.i_array_p);
  p_i_calls = &imethod_p->i_calls;
  imethod_p->i_data.i_array_p = 0i64;
  imethod_p->i_data.i_count = 0;
  imethod_p->i_data.i_size = 0;
  i_next_p = (SSInvokedMethod *)imethod_p->i_calls.i_sentinel.SSInvokedContextBase::SSInvokedBase::i_next_p;
  if ( i_next_p != (SSInvokedMethod *)&imethod_p->i_calls )
  {
    do
    {
      v4 = i_next_p;
      i_next_p = (SSInvokedMethod *)i_next_p->vfptr;
      v4->vfptr = (SSObjectBaseVtbl *)v4;
      *(_QWORD *)&v4->i_ptr_id = v4;
    }
    while ( i_next_p != (SSInvokedMethod *)p_i_calls );
    p_i_calls->i_sentinel.i_next_p = &p_i_calls->i_sentinel;
    imethod_p->i_calls.i_sentinel.i_prev_p = &imethod_p->i_calls.i_sentinel;
  }
  v5 = imethod_p->i_next_p;
  i_prev_p = imethod_p->i_prev_p;
  v5->i_prev_p = i_prev_p;
  i_prev_p->i_next_p = v5;
  imethod_p->i_prev_p = &imethod_p->AListNode<SSInvokedBase,SSInvokedBase>;
  imethod_p->i_next_p = &imethod_p->AListNode<SSInvokedBase,SSInvokedBase>;
  imethod_p->i_ptr_id = 0;
  pool = SSInvokedMethod::get_pool();
  i_block_p = pool->i_block_p;
  i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
  if ( (unsigned __int64)imethod_p < i_objects_a
    || (v10 = (unsigned __int64)imethod_p < i_objects_a + 120i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v10) )
  {
    p_i_exp_pool = &pool->i_exp_pool;
  }
  APArray<SSInvokedMethod,SSInvokedMethod,ACompareAddress<SSInvokedMethod>>::append(p_i_exp_pool, imethod_p);
}

// File Line: 136
// RVA: 0x4CBD60
void __fastcall SSIExternalMethodCallWrapper::~SSIExternalMethodCallWrapper(SSIExternalMethodCallWrapper *this)
{
  bool *i_finished_p; // rax
  SSMethodBase *i_method_p; // rcx

  this->vfptr = (SSObjectBaseVtbl *)&SSIExternalMethodCallWrapper::`vftable;
  i_finished_p = this->i_finished_p;
  if ( i_finished_p )
    *i_finished_p = 1;
  this->i_method_p[1].vfptr = 0i64;
  i_method_p = this->i_method_p;
  if ( i_method_p )
    i_method_p->vfptr->__vecDelDtor(i_method_p, 1u);
  AMemory::c_free_func(this->i_data.i_array_p);
  SSInvokedBase::~SSInvokedBase(this);
}


// File Line: 44
// RVA: 0x131090
SSInvokedMethod *__fastcall SSInvokedMethod::pool_new(SSInvokedBase *caller_p, SSObjectBase *scope_p, SSMethodBase *method_p)
{
  SSMethodBase *v3; // r14
  SSObjectBase *v4; // rbp
  SSInvokedBase *v5; // rsi
  AObjReusePool<SSInvokedMethod> *v6; // rax
  unsigned int v7; // edi
  AObjReusePool<SSInvokedMethod> *v8; // rbx
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  __int64 v12; // rcx
  SSInvokedMethod **v13; // rax
  SSInvokedMethod *result; // rax
  unsigned int v15; // eax
  unsigned int v16; // ecx

  v3 = method_p;
  v4 = scope_p;
  v5 = caller_p;
  v6 = SSInvokedMethod::get_pool();
  v7 = 0;
  v8 = v6;
  v9 = v6->i_pool.i_count;
  if ( v9 )
  {
    v15 = v9 - 1;
    v8->i_pool.i_count = v15;
    v12 = v15;
    v13 = v8->i_pool.i_array_p;
  }
  else
  {
    if ( !v8->i_exp_pool.i_count )
      AObjReusePool<SSInvokedMethod>::append_block(v8, v8->i_expand_size);
    v10 = v8->i_exp_pool.i_count;
    if ( !v10 )
    {
      result = 0i64;
      goto LABEL_9;
    }
    v11 = v10 - 1;
    v8->i_exp_pool.i_count = v11;
    v12 = v11;
    v13 = v8->i_exp_pool.i_array_p;
  }
  result = v13[v12];
LABEL_9:
  result->i_caller_p.i_obj_p = v5;
  if ( v5 )
    v16 = v5->i_ptr_id;
  else
    v16 = 0;
  result->i_caller_p.i_ptr_id = v16;
  result->i_scope_p.i_obj_p = v4;
  if ( v4 )
    v7 = v4->i_ptr_id;
  result->i_scope_p.i_ptr_id = v7;
  result->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  result->i_method_p = v3;
  return result;
}

// File Line: 64
// RVA: 0x130980
void __fastcall SSInvokedMethod::pool_delete(SSInvokedMethod *imethod_p)
{
  SSInvokedMethod *v1; // rdi
  AList<SSInvokedBase,SSInvokedBase> *v2; // rdx
  AList<SSInvokedBase,SSInvokedBase> *v3; // rax
  AList<SSInvokedBase,SSInvokedBase> *v4; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v5; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v6; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v7; // rdx
  AObjReusePool<SSInvokedMethod> *v8; // rax
  AObjBlock<SSInvokedMethod> *v9; // rcx
  unsigned __int64 v10; // rdx
  bool v11; // cf
  APArray<SSInvokedMethod,SSInvokedMethod,ACompareAddress<SSInvokedMethod> > *v12; // rcx

  v1 = imethod_p;
  SSData::empty_table((APSortedLogical<SSData,ASymbol> *)&imethod_p->i_data);
  AMemory::c_free_func(v1->i_data.i_array_p);
  v2 = &v1->i_calls;
  v1->i_data.i_array_p = 0i64;
  v1->i_data.i_count = 0;
  v1->i_data.i_size = 0;
  v3 = (AList<SSInvokedBase,SSInvokedBase> *)v1->i_calls.i_sentinel.i_next_p;
  if ( v3 != &v1->i_calls )
  {
    do
    {
      v4 = v3;
      v3 = (AList<SSInvokedBase,SSInvokedBase> *)v3->i_sentinel.i_next_p;
      v4->i_sentinel.i_next_p = &v4->i_sentinel;
      v4->i_sentinel.i_prev_p = &v4->i_sentinel;
    }
    while ( v3 != v2 );
    v2->i_sentinel.i_next_p = &v2->i_sentinel;
    v1->i_calls.i_sentinel.i_prev_p = &v1->i_calls.i_sentinel;
  }
  v5 = v1->i_next_p;
  v6 = v1->i_prev_p;
  v7 = (AListNode<SSInvokedBase,SSInvokedBase> *)&v1->i_next_p;
  v5->i_prev_p = v6;
  v6->i_next_p = v5;
  v7->i_prev_p = v7;
  v7->i_next_p = v7;
  v1->i_ptr_id = 0;
  v8 = SSInvokedMethod::get_pool();
  v9 = v8->i_block_p;
  v10 = (unsigned __int64)v9->i_objects_a;
  if ( (unsigned __int64)v1 < v10 || (v11 = (unsigned __int64)v1 < v10 + 120i64 * v9->i_size, v12 = &v8->i_pool, !v11) )
    v12 = &v8->i_exp_pool;
  APArray<SSInvokedMethod,SSInvokedMethod,ACompareAddress<SSInvokedMethod>>::append(v12, v1);
}

// File Line: 136
// RVA: 0x4CBD60
void __fastcall SSIExternalMethodCallWrapper::~SSIExternalMethodCallWrapper(SSIExternalMethodCallWrapper *this)
{
  SSIExternalMethodCallWrapper *v1; // rbx
  bool *v2; // rax
  SSMethodBase *v3; // rcx

  v1 = this;
  this->vfptr = (SSObjectBaseVtbl *)&SSIExternalMethodCallWrapper::`vftable';
  v2 = this->i_finished_p;
  if ( v2 )
    *v2 = 1;
  this->i_method_p[1].vfptr = 0i64;
  v3 = this->i_method_p;
  if ( v3 )
    v3->vfptr->__vecDelDtor((SSInvokableBase *)&v3->vfptr, 1u);
  AMemory::c_free_func(v1->i_data.i_array_p);
  SSInvokedBase::~SSInvokedBase((SSInvokedBase *)&v1->vfptr);
}

